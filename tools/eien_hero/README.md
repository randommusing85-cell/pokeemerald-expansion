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

- **Walking, running, Mach Bike and Acro Bike (54 frames):** heads drawn by hand, pixel by
  pixel (`OW_HEADS`), one per facing. Each frame's cap is found by a row only the cap has (the
  brim facing down, the back edge facing up, the peak facing left; `ANCHORS`), and the head is
  placed at that offset, so leaning, wheelie and hop frames get it too. Running and biking,
  the cap sits lower than walking, so the fringe covers the forehead there.
- **Battle front and back (4 frames):** heads from AI drafts (`ai_drafts/`, Gemini 3 Pro image
  edits of the enlarged sprites), snapped to the pixel grid and merged only around the old cap.
  The hoodie's red panels become grey; the Poké Ball stays red and white.

Still Brendan's cap: surfing, fishing, field moves, underwater, watering and decorating
sheets (the cap reads as dark hair there, from the recolor). To redraw one, copy its vanilla
sheet into `vanilla/` and add it to `OW_SHEETS`; frames whose cap no anchor matches stop the
script with the frame number.
