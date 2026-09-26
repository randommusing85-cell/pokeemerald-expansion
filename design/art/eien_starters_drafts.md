# Eien starters: AI draft front sprites

**Proposals only, not decided design.** None of these species exist in code, and nothing here
changes the game. They are drafts for review, made the same way as the
[Eien Poochyena test](eien_poochyena/README.md).

Contact sheet: [`eien_starters_contact_sheet.png`](eien_starters_contact_sheet.png)
(original, then each converted draft, all at 3x).

## How they were made

- **Input:** frame 1 of `graphics/pokemon/<species>/anim_front.png`, colored with `normal.pal`,
  background white, enlarged 8x (512x512) with nearest neighbour.
- **Models:** `gemini-3-pro-image` (drafts `*_gemini3pro_a/b`) and `gemini-3.1-flash-image`
  (drafts `*_gemini31flash_a`), `generateContent` with the image plus the text brief, 1:1 output
  (1024x1024). One call per draft, no retries or cherry-picking; every call succeeded.
- **Prompt** (same for all, with the species brief filled in):
  > This image is the original 64x64 front battle sprite of {name}, enlarged 8x. Redraw it as a
  > regional variant called Eien {name} for a Pokemon fan game. {brief} Keep exactly the same
  > pose, the same framing, size and position in the frame, and the same silhouette, so it is
  > still clearly {name}. Style: Gen 4/5 Pokemon battle sprite pixel art drawn on a 64x64 pixel
  > grid and enlarged 8x (crisp square pixels, no anti-aliasing, no gradients or blur), dark
  > outline, limited palette of at most 15 colors. Plain flat pure white background, nothing
  > else in the image, no text. Output a square image.

  The briefs were the Fire/Ghost shrine-lantern chick, the Grass/Psychic "fading bloom" and the
  Water/Ice snow ninja, as given in the request.
- **Conversion:** `tools/sprite_prep/sprite_prep.py --front <draft> --back <draft>` (the tool
  requires a back; the draft was passed twice and the back output thrown away). It samples the
  64x64 grid, removes the white background, fits the sprite in 56px and cuts to 15 colors plus
  transparency. `converted/<draft>.png` is frame 1 of its `anim_front.png` (64x64, indexed,
  index 0 transparent) and `converted/<draft>.pal` is its JASC palette. All passed the tool's
  GBA checks (size, 16 colors, 15-bit color).
- **Not done:** back sprites, shiny palettes, icons, animation frames, in-game screenshots.

## Notes per draft

### Eien Torchic (`eien_torchic/`)

| Draft | Notes |
|---|---|
| `front_gemini31flash_a` | **Best balance.** Torchic pose and stance kept; cream/ash body, a small lantern-frame chest with a teal flame inside, teal wisps for tuft and tail. The lantern reads only faintly at 64x64. Head tuft shape is gone (replaced by a wisp). Palette OK. |
| `front_gemini3pro_a` | Most literal: the body *is* a stone tōrō with legs and a beak, with blue flame inside. Strong idea and very readable, but it no longer reads as Torchic; more like a new Pokémon. |
| `front_gemini3pro_b` | Cleanest Torchic silhouette and crisp outline, violet wisps at head and tail. Missing the lantern body and chest glow, so it's mostly a recolor. Good base to paint the chest lantern onto. |

### Eien Bulbasaur (`eien_bulbasaur/`)

| Draft | Notes |
|---|---|
| `front_gemini31flash_a` | Pale cool body, calm half-closed eyes, bulb drawn as a translucent outline with violet/teal inside: the most "between worlds" look. The pale bulb edge is thin and partly lost against a light background. |
| `front_gemini3pro_a` | **Strongest.** Pose kept exactly, darker outline gives the best 64x64 readability, and the bulb has a clear green-to-violet aurora. Bulb is less translucent than the brief. |
| `front_gemini3pro_b` | Softest, most pastel; nice lavender eye lids. Low contrast body with a weak outline, so it reads washed-out at 1x. |

All three lost Bulbasaur's open mouth and red eyes, as the brief asked (calm eyes).

### Eien Froakie (`eien_froakie/`)

| Draft | Notes |
|---|---|
| `front_gemini31flash_a` | Pose kept, crystal frubbles, but the eyes lost Froakie's yellow and the whole sprite is pale-on-pale with little navy; weakest read at 64x64. |
| `front_gemini3pro_a` | **Strongest.** Same crouch and framing as the original, yellow eyes kept, ice-crystal scarf around the neck, navy accents. Crystals spread wide and are a bit busy. |
| `front_gemini3pro_b` | Most characterful (determined ninja face, navy hands and feet, frosted scarf), but the model zoomed in: it fills the whole frame and the converter had to scale it down to 56px, and the pose changed (upright, feet planted). Would need redrawing to the right size. |

## General findings

- Gemini 3 Pro held the pixel grid and outlines better; 3.1 Flash was a little softer and paler.
- The pale designs (ghost, ice) sit near the white background the converter keys out. No
  holes showed up here, but check highlights when cleaning up.
- Each draft has its own palette; a final sprite needs one palette shared with its back sprite
  and a hand-picked shiny.
