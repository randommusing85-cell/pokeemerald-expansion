#!/usr/bin/env python3
"""Build door animations for the Eien tilesets (run after compile.sh).

For every door in tilesets_src/<name>/doors.json, gets three opening frames, colors each 8x8
tile with the palette that tile uses in the compiled door metatile, and writes:

  graphics/door_anims/eien/<name>_<metatile>.png   3 frames of 16x16 (opening, opening, open)
  src/data/field_door_eien.h                       tiles, palettes and the table entries,
                                                   included by src/field_door.c

Frames come from the snow pack's Doors sheets (build/community_assets/, see
tools/fetch_assets.py) for hinged doors, or are drawn here for "slide" doors: the closed door
is rendered from the compiled tileset, and the left and right halves of its glass slide apart
over a dark interior.
"""

import json
import os
import struct
import sys

from PIL import Image

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import build_source  # noqa: E402  (door_styles, TILESETS, REPO)

REPO = build_source.REPO
SYMBOLS = {"eien_town": "EienTown", "eien_coast": "EienCoast", "eien_shrine": "EienShrine"}
HEADER = os.path.join(REPO, "src", "data", "field_door_eien.h")
OUT_DIR = os.path.join(REPO, "graphics", "door_anims", "eien")


def read_palettes(path):
    pals = {}
    for i in range(16):
        words = open(os.path.join(path, "palettes", f"{i:02d}.pal")).read().split()[3:]
        pals[i] = [tuple(int(v) for v in words[j * 3:j * 3 + 3]) for j in range(16)]
    return pals


SLIDE_GLASS = (1, 1, 14, 12)   # glass area of the sliding doors in the cell: x0, y0, x1, y1
SLIDE_STEPS = (2, 4, 7)        # how far each half has slid, per frame


def render_metatile(compiled, local, pals):
    """The door metatile's first layer as the game draws it (RGB, 16x16)."""
    tiles = Image.open(os.path.join(compiled, "tiles.png"))
    raw = open(os.path.join(compiled, "metatiles.bin"), "rb").read()
    entries = struct.unpack(f"<{len(raw) // 2}H", raw)
    cell = Image.new("RGB", (16, 16))
    for q in range(4):
        e = entries[local * 8 + q]
        t, hflip, vflip, pal = (e & 0x3FF) - 512, (e >> 10) & 1, (e >> 11) & 1, e >> 12
        tx, ty = (t % (tiles.width // 8)) * 8, (t // (tiles.width // 8)) * 8
        for y in range(8):
            for x in range(8):
                i = tiles.getpixel((tx + (7 - x if hflip else x), ty + (7 - y if vflip else y)))
                cell.putpixel(((q % 2) * 8 + x, (q // 2) * 8 + y), pals[pal][i])
    return cell


def slide_frames(closed):
    """Sliding glass doors: each half slides outward behind the wall, showing the interior.
    The doorway is drawn in the door frame's outline color: it reads as dark, and every palette
    the door uses already has it, so all four tiles match."""
    x0, y0, x1, y1 = SLIDE_GLASS
    mid = (x0 + x1 + 1) // 2  # first column of the right half
    dark = closed.getpixel((0, 0))  # the door frame's outline color
    frames = []
    for step in SLIDE_STEPS:
        f = closed.copy()
        for y in range(y0, y1 + 1):
            for x in range(x0, mid):  # left half slides left
                f.putpixel((x, y), closed.getpixel((x + step, y)) if x + step < mid else dark)
            for x in range(mid, x1 + 1):  # right half slides right
                f.putpixel((x, y), closed.getpixel((x - step, y)) if x - step >= mid else dark)
        frames.append(f.convert("RGBA"))
    return frames


def nearest(color, palette):
    return min(range(1, 16), key=lambda i: sum((a - b) ** 2 for a, b in zip(color, palette[i])))


def main():
    styles = build_source.door_styles()
    os.makedirs(OUT_DIR, exist_ok=True)
    decls, entries = [], []
    for name, symbol in SYMBOLS.items():
        doors = json.load(open(os.path.join(REPO, "tilesets_src", name, "doors.json")))
        if not doors:
            continue
        compiled = os.path.join(REPO, "data", "tilesets", "secondary", name)
        pals = read_palettes(compiled)
        raw = open(os.path.join(compiled, "metatiles.bin"), "rb").read()
        metatiles = struct.unpack(f"<{len(raw) // 2}H", raw)
        for door in doors:
            local = door["id"]
            # The door art is on the metatile's first layer; its 4 tiles are TL, TR, BL, BR.
            pal_nums = [metatiles[local * 8 + q] >> 12 for q in range(4)]
            if door["style"] == "slide":
                frames = slide_frames(render_metatile(compiled, local, pals))
            else:
                frames = styles[door["style"]][1:4]
            out = Image.new("P", (16, 48))
            out.putpalette([c for rgb in pals[pal_nums[0]] for c in rgb] + [0] * (768 - 48))
            for f, frame in enumerate(frames):
                for q in range(4):
                    qx, qy = (q % 2) * 8, (q // 2) * 8
                    pal = pals[pal_nums[q]]
                    for y in range(8):
                        for x in range(8):
                            p = frame.getpixel((qx + x, qy + y))
                            out.putpixel((qx + x, f * 16 + qy + y), nearest(p[:3], pal) if p[3] else 0)
            metatile = 512 + local
            png = f"{name}_{metatile:03x}.png"
            out.save(os.path.join(OUT_DIR, png))
            ident = f"{symbol}_{metatile:03X}"
            decls.append(f'static const u8 sDoorAnimTiles_{ident}[] = INCGFX_U8("graphics/door_anims/eien/{png}", ".4bpp");\n'
                         f'static const u8 sDoorAnimPalettes_{ident}[] = {{{", ".join(map(str, pal_nums * 2))}}};\n')
            sound = "DOOR_SOUND_SLIDING" if door["style"] == "slide" else "DOOR_SOUND_NORMAL"
            entries.append(f"    {{ .metatileNum = 0x{metatile:03X}, .tileset = &gTileset_{symbol}, .sound = {sound}, "
                           f".size = DOOR_SIZE_1x1, .tiles = sDoorAnimTiles_{ident}, .palettes = sDoorAnimPalettes_{ident} }}, \\\n")
            print(f"{name}: door 0x{metatile:03X} ({door['style']}) palettes {pal_nums} -> graphics/door_anims/eien/{png}")

    externs = "".join(f"extern const struct Tileset gTileset_{s};\n" for s in SYMBOLS.values())
    with open(HEADER, "w") as f:
        f.write("// Generated by tools/eien_tileset/make_doors.py; do not edit by hand.\n"
                "// Door animations for the Eien tilesets, used by src/field_door.c.\n\n"
                + externs + "\n" + "\n".join(decls)
                + "\n#define EIEN_DOOR_ANIM_GRAPHICS \\\n" + "".join(entries) + "\n")
    print(f"wrote {os.path.relpath(HEADER, REPO)}")


if __name__ == "__main__":
    main()
