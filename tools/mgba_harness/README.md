# mgba-harness

A headless screenshot and state-check harness for this ROM. It boots `pokeemerald.gba` in libmgba with no window, plays a plain-text input script, and writes PNG screenshots, a contact sheet and memory checks. A typical script runs in about a second.

It lets you (or Claude Code) check a change without opening an emulator: build, warp to the map, take a screenshot, look at it.

## Setup

Debian/Ubuntu:

```sh
sudo apt install libmgba-dev libpng-dev gcc-arm-none-eabi binutils-arm-none-eabi
make -j$(nproc)                      # build the ROM (debug menu needs a non-release build)
make -C tools/mgba_harness           # optional; run.py builds the harness when needed
```

## Running

```sh
tools/mgba_harness/run.py tools/mgba_harness/scripts/example_warp.txt
```

Output goes to `build/harness/<script name>/`:

- `NAME.png` for each `shot NAME` (240×160)
- `_sheet.png`, all shots of the run tiled four per row in script order
- `_resolved.txt`, the script after includes, `warp` and `@symbols` are expanded (harness errors cite its line numbers; each line ends with its source `file:line`)

| Option | Meaning |
| --- | --- |
| `--save FILE` | boot with this battery save (read-only; the file is never modified) |
| `--out DIR` | screenshot directory |
| `--baseline DIR` | compare every shot to `DIR/NAME.png`; exit 4 if any differ or are missing |
| `--update-baseline` | copy this run's shots into `--baseline` instead of comparing |
| `--rtc UNIX` | real-time clock start (default: 2000-01-01 12:00 UTC, i.e. daytime) |
| `--rom`, `--elf` | alternative ROM / ELF for symbols |

Exit codes: 0 ok, 1 I/O or emulator error, 2 script syntax error, 3 failed `assert`/`wait_until`, 4 baseline mismatch.

Runs are deterministic: the same ROM, save, script and `--rtc` produce identical pixels. The clock is fixed, not the host's, so day/night tinting and time-based events do not drift between runs.

## Script language

One command per line; `#` starts a comment. KEYS is `A B SELECT START RIGHT LEFT UP DOWN R L`, combined with `+` (`R+START`).

| Command | Effect |
| --- | --- |
| `wait N` | run N frames (60 per second) |
| `press KEYS [COUNT]` | tap COUNT times: hold 4 frames, release 12 |
| `hold KEYS N` | hold for N frames (walking: 16 frames per tile) |
| `shot NAME` | screenshot |
| `savestate PATH` / `loadstate PATH` | emulator save states |
| `writesave PATH` | export the battery save (after saving in-game) |
| `read8/16/32 ADDR [LABEL]` | print memory |
| `write8/16/32 ADDR VALUE` | poke memory |
| `assert8/16/32 ADDR VALUE [MSG]` | stop with exit 3 if different |
| `wait_until8/16/32 ADDR VALUE MAXFRAMES` | run until equal, exit 3 on timeout |
| `include PATH` | inline another script (path relative to this one) |
| `warp MAP_CONSTANT [WARP_ID]` | warp through the debug menu, then assert the player arrived |

Addresses can be numbers, `@gSymbol` or `@gSymbol+0x10` (resolved from `pokeemerald.elf`), or `[PTR]+OFFSET` to follow a pointer when the command runs. Save blocks move around in memory, so reach them through their pointers:

```
assert8 [@gSaveBlock1Ptr]+4 0             # location.mapGroup
assert8 [@gSaveBlock1Ptr]+5 10            # location.mapNum
wait_until32 @gMain+4 @CB2_Overworld+1 600  # field is running (+1: Thumb pointer)
```

## Bundled scripts

- `scripts/new_game.txt`: power on and start a new game (boy, name "Aaaaaaa"), ending in the parked truck where the debug menu works. About 6,700 frames, well under a second.
- `scripts/continue.txt`: power on and CONTINUE from `--save`, ending in the overworld.
- `scripts/example_warp.txt`: new game, then warp and screenshot three towns.

A scene check usually looks like this:

```
include ../../tools/mgba_harness/scripts/new_game.txt
warp MAP_COALVEIL_TOWN 0 # your map constant, from include/constants/map_groups.h
hold UP 32
press A              # talk to the NPC
wait 30
shot npc_line1
```

The bundled scripts use exact frame counts for the stock intro. If you change the title screen or intro, re-derive the counts by adding `shot`s and checking `_sheet.png`. `warp` needs the player free to move in the overworld (no open text box, no running cutscene); if it isn't, the arrival assert fails instead of taking a wrong screenshot.

## Regression baselines

```sh
tools/mgba_harness/run.py tests/screens/town.txt --baseline tests/screens/town --update-baseline   # record
tools/mgba_harness/run.py tests/screens/town.txt --baseline tests/screens/town                     # check
```

Commit the baseline PNGs next to the script. Intended changes to a map or palette show up as diffs; re-record after checking them.

## Notes

- `mgba/flags.h` must be included before the other mGBA headers (`harness.c` does this). Without it, `struct mCore` is compiled with the wrong layout and calls such as `savedataClone` go to the wrong function.
- Pixel output is mGBA's software renderer. It matches mGBA desktop, not necessarily other emulators or hardware.
