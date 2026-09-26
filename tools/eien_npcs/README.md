# Eien overworld characters

`convert.py` turns sheets from the FRLG-style NPC megapack into engine overworld sprites and
registers them, so they show up in Porymap as `OBJ_EVENT_GFX_EIEN_<NAME>`.

1. `tools/fetch_assets.py frlg_npc_megapack` downloads the pack into `build/community_assets/`.
2. `tools/eien_npcs/convert.py` writes `graphics/object_events/pics/people/eien/*.png` and
   `graphics/object_events/palettes/eien_npc_*.pal`, and rewrites the blocks marked
   `Eien NPCs BEGIN ... END` in:
   `include/constants/event_objects.h`, `src/data/object_events/object_event_graphics.h`,
   `object_event_pic_tables.h`, `object_event_graphics_info.h`,
   `object_event_graphics_info_pointers.h` and `src/event_object_movement.c`.
3. `make`.

To add a character, add a line to `CHARACTERS` (constant name, file name, sheet in the pack,
credit) and rerun. Credit the sprite's artist in `design/asset-credits.md`.

## How it converts

- The pack's sheets are RPG Maker character sheets at 2x (4 directions x 4 frames of 32x48).
  They're halved to 16x24 and placed in 16x32 frames with the feet on the same row as Emerald's
  own sprites, in the engine's order: face S, N, W, then two walking frames each for S, N, W.
  Walking east uses the west frames mirrored.
- The characters share 4 palettes (`OBJ_EVENT_PAL_TAG_EIEN_NPC_1..4`), like Emerald's 4 NPC
  palettes, so a busy map doesn't run out of sprite palette slots. Sprites with similar colors
  are grouped together; each group is cut to 15 colors.

## Characters

| Constant | Who | Sheet |
| --- | --- | --- |
| `OBJ_EVENT_GFX_EIEN_HARU` | Haru | HGSS `NPC_YoungMan` |
| `OBJ_EVENT_GFX_EIEN_AKIRA` | Akira | FRLG `trainer_BIRDKEEPER` |
| `OBJ_EVENT_GFX_EIEN_NAMI` | Nami | FRLG `trainer_YOUNGCOUPLE_F` |
| `OBJ_EVENT_GFX_EIEN_KASHIWAGI` | Professor Kashiwagi | HGSS `NPC_MidageWoman` |
| `OBJ_EVENT_GFX_EIEN_KASHIWAGI_HUSBAND` | her husband | HGSS `NPC_Shopkeeper` |
| `OBJ_EVENT_GFX_EIEN_FUYUMI` | Fuyumi | HGSS `trainer_ACETRAINER_F` |
| `OBJ_EVENT_GFX_EIEN_FISHERMAN` | Hamakaze | HGSS `trainer_FISHERMAN` |
| `OBJ_EVENT_GFX_EIEN_SAILOR` | Hamakaze | HGSS `trainer_SAILOR` |
| `OBJ_EVENT_GFX_EIEN_VILLAGE_WOMAN` | Hamakaze | RSE `Hoenn NPC 06` |
| `OBJ_EVENT_GFX_EIEN_SCHOOLBOY` | Hamakaze | RSE `trainer_SCHOOLBOY` |
| `OBJ_EVENT_GFX_EIEN_SNOW_TRAINER` | Shimotsuki | DPPt `trainer_ACETRAINERSNOW_M` |
| `OBJ_EVENT_GFX_EIEN_WORKER` | Shimotsuki | DPPt `trainer_WORKER` |
| `OBJ_EVENT_GFX_EIEN_POKEFAN_M` | Shimotsuki | RSE `trainer_POKEFAN_M` |
| `OBJ_EVENT_GFX_EIEN_SOCIALITE` | Shimotsuki | DPPt `trainer_SOCIALITE` |
