---
name: screenshot
description: Boot the built ROM headlessly and screenshot a map, scene or menu to check a change visually. Use after editing maps, tilesets, palettes, sprites, event scripts or dialogue, or when asked to "check how X looks", instead of assuming the change is right.
---

# Screenshot the running game

The harness lives in `tools/mgba_harness/`; its README has the full command reference.

1. Build the ROM with `make -j$(nproc)`. Fix build errors first.
2. Write a scene script under `build/harness_scripts/`. Those are throwaway; use `tests/screens/` if it should be kept as a regression check. Usually:
   ```
   include ../../tools/mgba_harness/scripts/new_game.txt
   warp MAP_THE_MAP [WARP_ID]
   hold RIGHT 32        # 16 frames per tile
   press A              # interact
   wait 30
   shot scene_1
   ```
   Map constants are in `include/constants/map_groups.h`; warp IDs index the map's `warp_events` in `data/maps/<Map>/map.json`.
3. Run `tools/mgba_harness/run.py build/harness_scripts/<name>.txt`.
4. Read `build/harness/<name>/_sheet.png` (all shots in order) and check it against what the change was meant to do: tiles, palette, NPC placement, dialogue text and line breaks. Read an individual `NAME.png` for detail.
5. If a shot shows the wrong moment (text still printing, fade in progress), adjust the `wait`s and rerun. Runs take about a second, so iterate rather than guess.

Non-zero exit: 3 means an assert or wait_until failed (a `warp` that did not arrive usually means a text box or cutscene was active); 4 means baseline differences. Say which check failed; never loosen or delete an assert or baseline to get a pass.

Report what the screenshots show, and attach the sheet path so the user can look too. The harness cannot judge whether something feels right; that is still the user's playtest.
