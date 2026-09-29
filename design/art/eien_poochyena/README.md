# Sprite test: Eien Poochyena

A test of the sprite workflow on one variant (Rock/Dark shrine guardian dog). The front
sprite is now Eien Poochyena's in the game (`tools/eien_species/convert_art.py`); its back,
icon and shiny there are placeholders, not the ones from this test.

## How it was made

1. The real Poochyena sprites, enlarged 8x, were given to Google Gemini image models with a
   design brief (weathered sandstone komainu, spiral mane, red cloth bib, moss, faint violet
   cracks; same pose; Gen 3 pixel style).
2. `tools/sprite_prep/sprite_prep.py` sampled the drafts back to a 64x64 grid, removed the
   background, cut them to one shared 16-color palette, made a shiny palette and an icon,
   and checked the GBA limits.
3. The files were swapped in for Poochyena in a throwaway checkout and screenshotted in a
   debug battle (`battle_normal.png`, `battle_shiny.png`, `party_icon.png`).

## Findings

- **Front sprite:** good enough to use after light cleanup. Gemini 3 Pro kept the pose and
  pixel grid well (`drafts/front_gemini3pro.png`); Gemini 3.1 Flash was close.
- **Back sprite:** weaker. The model drew a side view, larger than a back sprite should be,
  instead of the over-the-shoulder view. Expect to redraw or heavily fix back sprites.
- **Palette:** the converter merges similar colors first so small accents (eyes, bib, cracks)
  survive. The shiny is an automatic hue shift that keeps reds; hand-pick shinies later.
- **Icon:** automatic 64-to-32 downscaling is muddy. Icons need drawing by hand (or their own
  generation pass), in one of the 6 shared icon palettes.
- **Animation:** frame 2 is frame 1 raised 1px, a placeholder. Real idle frames need drawing.
- **Cost:** about 2 minutes of generation and 1 second of conversion per draft; the manual
  part is the back sprite, the icon, and cleanup.
