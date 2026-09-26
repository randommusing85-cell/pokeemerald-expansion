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

The shape is still Brendan's (the spiky cap now reads as dark hair). A true redesign would mean
redrawing the most-seen frames by hand (walking, running, battle sprites).
