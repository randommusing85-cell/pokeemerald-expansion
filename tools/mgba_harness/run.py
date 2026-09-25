#!/usr/bin/env python3
"""Run an mgba-harness script against the built ROM.

Adds three things on top of the C harness:
  * `include PATH` lines, resolved relative to the including script
  * `@gSymbol` / `@gSymbol+0x10` address tokens, resolved from the ROM's ELF
  * `warp MAP_CONSTANT [WARP_ID]`, expanded into debug-menu input
    (Utilities > Warp to map warp); needs a non-release build, standing in the overworld

Examples:
  tools/mgba_harness/run.py tools/mgba_harness/scripts/title_screen.txt
  tools/mgba_harness/run.py my_scene.txt --save my.sav --out shots/scene
  tools/mgba_harness/run.py my_scene.txt --baseline tests/screens/scene
  tools/mgba_harness/run.py my_scene.txt --baseline tests/screens/scene --update-baseline
"""

import argparse
import os
import re
import shutil
import subprocess
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
REPO = os.path.dirname(os.path.dirname(HERE))
HARNESS = os.path.join(HERE, "mgba-harness")
MAP_RE = re.compile(r"^\s*(MAP_\w+)\s*=\s*\((\d+)\s*\|\s*\((\d+)\s*<<\s*8\)\)", re.M)
SYMBOL_RE = re.compile(r"@([A-Za-z_]\w*)((?:\+|-)(?:0x[0-9A-Fa-f]+|\d+))?")


def build_harness():
    source = os.path.join(HERE, "harness.c")
    if os.path.exists(HARNESS) and os.path.getmtime(HARNESS) >= os.path.getmtime(source):
        return
    subprocess.run(["make", "-s", "-C", HERE], check=True)


def load_symbols(elf):
    nm = shutil.which("arm-none-eabi-nm") or shutil.which("nm")
    if not nm:
        sys.exit("run.py: arm-none-eabi-nm not found; needed to resolve @symbols")
    out = subprocess.run([nm, elf], check=True, capture_output=True, text=True).stdout
    symbols = {}
    for line in out.splitlines():
        parts = line.split()
        if len(parts) == 3:
            symbols[parts[2]] = int(parts[0], 16)
    return symbols


def load_maps():
    header = os.path.join(REPO, "include", "constants", "map_groups.h")
    if not os.path.exists(header):
        sys.exit(f"run.py: {header} not found; build the ROM first to use warp")
    with open(header) as f:
        return {name: (int(group), int(num)) for name, num, group in MAP_RE.findall(f.read())}


def digit_input(value):
    """Key presses that set a debug-menu number field (starting at 0, ones digit) to value."""
    lines = []
    digits = [int(d) for d in str(value)][::-1]
    for place, digit in enumerate(digits):
        if place:
            lines.append("press RIGHT")
        if digit:
            lines.append(f"press UP {digit}")
    lines.extend(["press LEFT"] * (len(digits) - 1))
    return lines + ["press A", "wait 10"]


def warp_input(words, where, maps):
    if len(words) not in (2, 3):
        sys.exit(f"{where}: usage: warp MAP_CONSTANT [WARP_ID]")
    if words[1] not in maps:
        sys.exit(f"{where}: unknown map {words[1]}")
    group, num = maps[words[1]]
    warp = int(words[2], 0) if len(words) == 3 else 0
    lines = [f"# warp {words[1]} (group {group}, map {num}, warp {warp})",
             "press R+START", "wait 20",   # debug menu opens on Utilities
             "press A", "wait 10",         # Utilities
             "press DOWN", "press A", "wait 10"]  # Warp to map warp
    for value in (group, num, warp):
        lines.extend(digit_input(value))
    # Fail fast if the menu input went astray: check gSaveBlock1Ptr->location.mapGroup/mapNum.
    return lines + ["wait 180",
                    f"assert8 [@gSaveBlock1Ptr]+4 {group} warp {words[1]}: map group",
                    f"assert8 [@gSaveBlock1Ptr]+5 {num} warp {words[1]}: map num"]


def expand(path, seen=(), maps=None):
    path = os.path.abspath(path)
    if path in seen:
        sys.exit(f"run.py: include cycle at {path}")
    lines = []
    with open(path) as f:
        for number, line in enumerate(f, 1):
            words = line.split("#", 1)[0].split()
            if words[:1] == ["include"]:
                if len(words) != 2:
                    sys.exit(f"{path}:{number}: include needs exactly one path")
                target = os.path.join(os.path.dirname(path), words[1])
                lines.extend(expand(target, seen + (path,), maps))
            elif words[:1] == ["warp"]:
                if maps is None:
                    maps = load_maps()
                lines.extend((path, number, l) for l in warp_input(words, f"{path}:{number}", maps))
            else:
                lines.append((path, number, line.rstrip("\n")))
    return lines


def resolve_symbols(lines, elf):
    symbols = None
    resolved = []
    for path, number, line in lines:
        code, sep, comment = line.partition("#")
        if "@" in code:
            if symbols is None:
                if not os.path.exists(elf):
                    sys.exit(f"run.py: {elf} not found; build the ROM first to resolve @symbols")
                symbols = load_symbols(elf)

            def lookup(match):
                name, offset = match.group(1), match.group(2)
                if name not in symbols:
                    sys.exit(f"{path}:{number}: unknown symbol {name}")
                return f"0x{symbols[name] + (int(offset, 0) if offset else 0):08X}"

            code = SYMBOL_RE.sub(lookup, code)
        # Keep the origin so harness errors in _resolved.txt can be traced to the source script.
        resolved.append(f"{code.rstrip()}  # {os.path.relpath(path)}:{number}{'  ' + comment.strip() if sep else ''}"
                        if code.strip() else line)
    return resolved


def main():
    parser = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    parser.add_argument("script")
    parser.add_argument("--rom", default=os.path.join(REPO, "pokeemerald.gba"))
    parser.add_argument("--elf", help="ELF for @symbols (default: ROM path with .elf)")
    parser.add_argument("--save", help="battery save to boot with (read-only)")
    parser.add_argument("--out", help="screenshot directory (default: build/harness/<script name>)")
    parser.add_argument("--baseline", help="compare screenshots with this directory")
    parser.add_argument("--update-baseline", action="store_true", help="copy this run's screenshots into --baseline")
    parser.add_argument("--rtc", help="fixed RTC start as a unix timestamp")
    parser.add_argument("-q", "--quiet", action="store_true")
    args = parser.parse_args()

    if args.update_baseline and not args.baseline:
        parser.error("--update-baseline needs --baseline")
    if not os.path.exists(args.rom):
        sys.exit(f"run.py: {args.rom} not found; run `make` first")

    name = os.path.splitext(os.path.basename(args.script))[0]
    out = args.out or os.path.join(REPO, "build", "harness", name)
    os.makedirs(out, exist_ok=True)
    for old in os.listdir(out):
        if old.endswith(".png"):
            os.remove(os.path.join(out, old))

    build_harness()
    elf = args.elf or os.path.splitext(args.rom)[0] + ".elf"
    resolved = os.path.join(out, "_resolved.txt")
    with open(resolved, "w") as f:
        f.write("\n".join(resolve_symbols(expand(args.script), elf)) + "\n")

    cmd = [HARNESS, "-o", out, "-g", os.path.join(out, "_sheet.png")]
    if args.save:
        cmd += ["-s", args.save]
    if args.rtc:
        cmd += ["-t", args.rtc]
    if args.baseline and not args.update_baseline:
        cmd += ["-b", args.baseline]
    if args.quiet:
        cmd.append("-q")
    result = subprocess.run(cmd + [args.rom, resolved])

    if args.update_baseline and result.returncode == 0:
        os.makedirs(args.baseline, exist_ok=True)
        for shot in sorted(os.listdir(out)):
            if shot.endswith(".png") and not shot.startswith("_"):
                shutil.copy2(os.path.join(out, shot), os.path.join(args.baseline, shot))
                print(f"baseline {shot}: updated")
    sys.exit(result.returncode)


if __name__ == "__main__":
    main()
