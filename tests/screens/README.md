# Eien scene checks

Build a debug ROM, then run from the repository root:

```sh
make -j$(nproc)
python3 tools/mgba_harness/run.py tests/screens/eien_arrival.txt
```

In the managed workspace, first run `source /workspace/toolchains/activate.sh`.
Other systems need the compiler and libmgba/libpng development packages described in
`tools/mgba_harness/README.md`.

## Arrival and household

`eien_arrival.txt` starts a fresh game, debug-warps to Hamakaze's beach, advances the
existing arrival scene, visits the Kashiwagi household, opens the journal, and revisits
both maps. It checks story values, journal receipt/cover flags, the follower's active
state and Celebi's hint script. Successful subsequent warps check that scenes return input.
It never writes story state or flags to force success. B advances dialogue without
starting new conversations when the scene ends.

Inspect `build/harness/eien_arrival/_sheet.png` after a run: arrival dialogue, Celebi,
household dialogue, journal menu/cover, and Celebi following after walking on the return
visit. A delayed follower appearance immediately after a debug warp is not a loss of
the follower; the check walks before checking the active state and final screenshot.

This is a smoke check, not the complete milestone playthrough. It uses debug warps between
scenes and does not verify normal prologue entry, route traversal, starters/battles,
whiteout or battery-save/reload. There is no pixel baseline yet; screenshots require
visual review. The existing intro helper and scene timing assume default text speed.

## Memory-layout assumptions

The harness follows save-block pointers because their addresses change. These offsets
match the current debug build; update the check deliberately if the save layout changes:

| Address | Meaning |
| --- | --- |
| `gSaveBlock1Ptr + 0x1438` | `vars[VAR_EIEN_STORY - VARS_START]`: vars at 0x139C, var 0x404E, base 0x4000 |
| `gSaveBlock1Ptr + 0x1274` | flags at 0x1270, byte containing journal flags 0x20 and 0x21; expected 1 before opening, 3 afterward in this fresh save |
| `gSaveBlock3Ptr + 0` | follower control byte; expected 1 when idle (inProgress set, transient movement bits cleared) |
| `gSaveBlock3Ptr + 0xC` | follower script pointer; compare to the ELF symbol for Celebi's hint script |

Sources: `include/global.h`, `include/constants/vars.h`, `include/constants/flags.h`,
`include/constants/eien_story.h`. The current configuration places NPCfollower at the
start of SaveBlock3. Enabling fake RTC changes that assumption. SaveBlock1's historical
offset comments can become stale; verify compiled offsets when changing configuration
(for example, disassemble `GetVarPointer` and `GetFollowerNPCScriptPointer`). Do not
weaken an assertion just to make a changed build pass.
