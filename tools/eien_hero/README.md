# Eien's hero

`recolor.py` gives the player (Brendan's sprites) the hero's look: dark hair, a grey hoodie and
jeans (look A in `design/characters.md`). It rewrites the palettes every player sprite uses, so
every sheet changes at once and stays consistent; Brendan's pixels are untouched.

| File | Covers |
| --- | --- |
| `graphics/object_events/palettes/brendan.pal` | all overworld sheets: walking, running, bikes, surfing, fishing, field moves, underwater, watering, decorating |
| `graphics/object_events/palettes/brendan_reflection.pal` | the reflection in water |
| `graphics/trainers/palettes/brendan.pal` | battle front and back sprites, trainer card |
| `graphics/pokenav/region_map/brendan_icon.png` | the head icon on the region map (palette only) |

Rerun after an upstream merge that touches these files. The colors are the `LOOK` table.

Not recolored (separate art, only seen in places we'll replace or don't use yet): the Emerald
intro movie (`graphics/intro/scene_2/brendan*.png`), the ORAS dowsing effect, and Battle Frontier
transitions.

## New hairstyle

`redraw_hair.py` replaces Brendan's cap with short messy dark hair and a side fringe on the
most-seen sprites; run it after `recolor.py`. It reads the untouched originals in `vanilla/`.

- **Walking (9 frames):** heads drawn by hand, pixel by pixel (`OW_HEADS`), one per facing.
- **Battle front and back (4 frames):** heads from AI drafts (`ai_drafts/`, Gemini 3 Pro image
  edits of the enlarged sprites), snapped to the pixel grid and merged only around the old cap.
  The hoodie's red panels become grey; the Poké Ball stays red and white.

Still Brendan's cap: running, bikes, surfing, fishing, field moves, underwater, watering and
decorating sheets (the cap reads as dark hair there, from the recolor). Their heads can be
redrawn the same way as the walking frames.
