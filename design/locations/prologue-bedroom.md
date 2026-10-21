# Prologue: his bedroom

- **Map:** `MAP_EIEN_PROLOGUE_BEDROOM` (`EienPrologueBedroom`, appended to `gMapGroup_Eien`).
- **Layout:** `LAYOUT_EIEN_PROLOGUE_BEDROOM`, 9x8, an independent copy of the existing
  Brendan bedroom interior with the stairs replaced by solid wall/floor-shadow tiles.
- **Type:** interior; no outdoor connections or exits. No New Game routing change yet.

## Purpose and scope

Shows who he is before Eien: a Pokémon fan at home, playing a Pokémon game.
Prologue beat 1 in [story-outline.md](../story-outline.md).

The user authorized Codex to create Porymap-compatible maps on 2026-10-21. This first pass
supplies the bedroom and event anchor without inventing the accident or dialogue. Porymap's
GUI is not installed in the build environment; files use its normal JSON/binary formats.
The map is a development destination until the opening scene is implemented.

## Look

Existing `gTileset_Building` + `gTileset_BrendansMaysHouse`; no new art. Bed, rug, desk/PC,
console and TV are existing interior tiles. No vanilla bedroom NPCs, item balls, secret-base
objects, clock tutorial or decoration callbacks. Former stairs are sealed so there is no
accidental path into Hoenn. Background events override TV/region-map interactions and
Secret Base decoration bookkeeping on the reused furnishings. Music is silent (`MUS_NONE`) until the scene treatment is settled.

The accident remains text on a black screen, then Palkia appears using an existing sprite.
That sequence and its transition are not implemented in this map-only change.

## Coordinates and event handoff

Coordinates are zero-based Porymap tiles.

| Element | Position (x,y) | Status |
| --- | --- | --- |
| Player entry | (3,3), warp 0 | Clear floor south of the console; intended facing north for the future opening |
| Console | (3,1), approached from (3,2) facing north | Background event calls `EienPrologueBedroom_EventScript_Game`; intentionally no-op until Claude supplies text/trigger |
| Accident | Black screen | `TODO(design)`: what happens exactly and the dialogue |
| Palkia | Scene staging TBD | `TODO(design)`: lines, appearance and transition; no object placed prematurely |

Warp 0 is an arrival anchor on ordinary floor, self-referencing this map; stepping on it
is not a doorway or automatic teleport. Use the debug menu to enter/leave during testing.
No story flags/vars are allocated or changed. The map does not grant a party, journal or follower.
Its engine metadata uses `REGION_HOENN` / `MAPSEC_SPECIAL_AREA` with the name popup disabled;
this is not an assignment of the bedroom to the story's Hoenn geography or a fly destination.

## Next: Claude + Codex

- Claude: exact console interaction, accident text, Palkia scene and handoff to Hamakaze.
- Codex: implement the settled sequence, add any named story state, and connect New Game
  with correct initialization. Do not replace the unresolved prologue with an invented plot.
- Porymap: open the repository, then `gMapGroup_Eien` → `EienPrologueBedroom`. Edit this
  independent layout, not the vanilla bedroom. Keep/update the coordinates above with edits.

## Screenshot check

Build and emulator check passed (2026-10-21). Run:

```sh
make -j$(nproc)
python3 tools/mgba_harness/run.py tests/screens/eien_prologue_bedroom.txt
```

Inspected the four-shot sheet in `build/harness/eien_prologue_bedroom/_sheet.png`: furnished
bedroom with a clean sealed upper wall, console approach, blocked wall, and Hamakaze arrival.
Saved views: [room](../art/prologue_bedroom/room.png), [console](../art/prologue_bedroom/console.png).
The fixture asserts entry/console/wall coordinates, unchanged story state, TV interaction
returning input, and no Secret Base bookkeeping even with a seeded debug-save context.
It then debug-warps to Hamakaze and checks the existing arrival scene still reaches
`STORY_ARRIVED`. Harness offsets are documented in the fixture for the default Emerald build.
This verifies the map foundation, not the unresolved prologue or a normal fresh-start journey.
Opening/saving in Porymap's GUI has not been tested in this environment.
