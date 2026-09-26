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

## Round 2

**Still proposals, not decided design.** Round-1 files are kept; round 2 adds `*_r2_a`,
`*_r2_b` (Gemini 3 Pro image) and `*_r2_c` (Gemini 3.1 Flash image) per species, in the same
`drafts/` and `converted/` folders. Contact sheet:
[`eien_starters_contact_sheet_r2.png`](eien_starters_contact_sheet_r2.png).

Same method and conversion as round 1 (one call per draft, no retries, all succeeded, all pass
the GBA checks). Prompt changes:

- The framing sentence now reads: "Keep the exact canvas framing and sprite size of the input:
  the sprite must occupy the same area of the square, at the same scale and position, with the
  same pose and outline, so it is still clearly {name}. Do not zoom in or enlarge it. Change
  colours and details, not the silhouette."
- Briefs, steered from round 1:
  - Torchic: keep its own three-feather head tuft as feathers (not flames), proportions, outline
    and pose; muted ash-grey/cream feathers; a small lantern-like glowing window on the
    chest/belly with a pale teal / blue-violet flame; optionally a faint flicker at the tail tip.
  - Bulbasaur: strong dark outline like the original, same pose and size; bulb partly
    translucent with a green/teal/violet aurora glow, readable at 64x64; slightly cooler
    blue-green body; calm half-closed eyes.
  - Froakie: same size, crouch and framing, inside the same bounds; yellow eyes, sharper ninja
    expression; frubbles as a frost/ice-crystal scarf; paler icy body with navy accents.

The framing instruction worked: every round-2 draft kept the original's size and position.

### Eien Torchic

| Draft | Notes |
|---|---|
| `front_gemini3pro_r2_a` | Torchic outline and tuft kept. Cool grey body with cream tuft and chest, a small lantern window with a teal flame, a violet flicker at the tail. The pale, pupil-less eyes are the eeriest look of the three. Grey legs are dark and a bit heavy. |
| `front_gemini3pro_r2_b` | **Pick.** The closest to the brief. It is exactly Torchic's shape, the warm ash/cream reads as "muted Torchic" rather than a different bird, the lantern window on the belly is clear at 64x64, and there's a faint tail flicker. Cute rather than eerie. |
| `front_gemini31flash_r2_c` | Tuft kept, lantern window clear, but it added a pale wisp beside the tuft (against the brief) and the palette is darker and muddier. |

### Eien Bulbasaur

| Draft | Notes |
|---|---|
| `front_gemini3pro_r2_a` | Strong outline, vivid aurora bulb, but it grew extra leaves at the sides of the bulb, which makes it read like Ivysaur and widens the silhouette. |
| `front_gemini3pro_r2_b` | **Pick.** Same pose, size and strong outline as the original. The bulb has a clear green-teal-violet aurora that reads at 64x64, the violet half-closed eyes are calm, and the body is cool blue-green. It shows the translucency least, so hand-painting a few see-through pixels might help. |
| `front_gemini31flash_r2_c` | Most literally translucent (a netted, glassy bulb) but it added a brown stem tip, and the darker, greyer body with pale spots is less appealing. |

### Eien Froakie

| Draft | Notes |
|---|---|
| `front_gemini3pro_r2_a` | Right size and crouch, yellow eyes, sharp expression, crystal scarf. Very pale overall; navy only around the eyes and mouth. |
| `front_gemini3pro_r2_b` | **Pick.** Same as r2_a but with navy hands and feet, which ground it and add contrast, giving the "hint of navy". The crystal scarf is tidy and the ninja glare is clear at 64x64. |
| `front_gemini31flash_r2_c` | Pose and eyes OK, but the frubbles came out as scattered ice specks and stray pixels, noisy at 64x64. |

## Back sprites

**Proposals only, not decided design.** These are draft back sprites for the four Eien forms, to
go with the fronts now in `graphics/pokemon/eien/<species>/`. Nothing in `graphics/` was
changed. Contact sheet: [`eien_backs_contact_sheet.png`](eien_backs_contact_sheet.png). Each
row shows the Eien front, the current placeholder back, then the drafts. The grey line under
each back is its bounding box, to compare size and position with the original back.

- **Method:** an edit, not a from-scratch draw, because the Poochyena test got a side view that
  way. Each call sent two images:
  - Image 1: the original `graphics/pokemon/<species>/back.png` in its `normal.pal` colours,
    8x.
  - Image 2: Eien front frame 1 in its colours, 8x.

  One call per draft, `back_gemini3pro_a` (`gemini-3-pro-image`) and `back_gemini31flash_b`
  (`gemini-3.1-flash-image`), no retries. All 8 calls succeeded.
- **Prompt:**
  > Image 1 is the original back battle sprite of {name} (seen from behind and slightly above,
  > as the player's Pokemon in battle), 64x64 pixel art enlarged 8x. Image 2 is the front
  > sprite of a regional variant, Eien {name}, enlarged 8x; use it as the design reference.
  > Repaint image 1 so it shows the same regional variant as image 2: same design details and
  > colours as the front, but keep image 1's exact pose, silhouette, size and position on the
  > canvas. It must stay a back view seen from behind; do not turn it into a side or front
  > view, and do not zoom in or enlarge it. Change colours and details, not the silhouette.
  > Species notes: {notes} Style: Gen 4/5 Pokemon battle sprite pixel art on a 64x64 pixel
  > grid enlarged 8x (crisp square pixels, no anti-aliasing, no blur), dark outline, limited
  > palette. Plain flat pure white background, nothing else, no text. Output a square image.

  The notes per species were the ones given in the request: ash/cream feathers with a tail
  flicker; the aurora bulb; the ice scarf with navy accents; sandstone with a spiral mane,
  moss, a bib knot and violet cracks.
- **Conversion:**
  - `sprite_prep.sample_grid` (64 grid), then `background_mask` and `fit`. Box 64, so nothing
    was rescaled.
  - Then `sprite_prep.index` with the form's **existing**
    `graphics/pokemon/eien/<species>/normal.pal`, nearest colour. No new palette, so front
    and back share one.
  - Output: `eien_<species>/back_drafts/<draft>.png` (64x64 indexed, index 0 transparent),
    with the raw model output in `back_drafts/raw/`.
  - All pass the tool's size and colour checks.
  - Mean snap distance per sprite pixel (RGB) was about 7-10, and about 13-19 for Bulbasaur,
    whose bulb violets are only partly in the front palette.

| Species | Draft | Notes |
|---|---|---|
| Torchic | `back_gemini31flash_b` | **Pick.** Pose, silhouette and box identical to the original back (15,9)-(48,54). Ash/cream body, feather tuft kept as feathers, a pale teal/violet flicker at the tail. Snaps cleanly (err 6.9). Plain from behind, as expected with the lantern on the belly. |
| Torchic | `back_gemini3pro_a` | Same exact pose and box, same colours. Also has the flicker, plus a stray light-blue block at the lower right (probably the belly window peeking round); reads as an artefact. |
| Bulbasaur | `back_gemini31flash_b` | **Pick.** Exact original pose and box (6,15)-(57,51), cropped at the bottom like the original. Big bulb with a green-teal-violet swirl and strong dark outline, clearly the same form as the front. The palette snap flattens the raw's smooth gradient into bands of the front's teals and violets; still reads. |
| Bulbasaur | `back_gemini3pro_a` | Nice aurora bulb, but it redrew the pose: a smaller full body with legs, box (11,15)-(57,55). Not the back pose. |
| Froakie | `back_gemini31flash_b` | **Pick, with fixes.** Original pose and box. The ice-crystal scarf is clearly visible from behind. But the lower body turned pale white-blue instead of the original's darker back, so there are almost no navy accents. Paint some navy back in. |
| Froakie | `back_gemini3pro_a` | Better colours (navy shading and feet, scarf), but it grew legs and feet under the body and runs to y=61, taller than the original (to y=57). Pose not kept. |
| Poochyena | `back_gemini31flash_b` | **Pick.** Keeps the original's pose and box (4,13)-(62,53) exactly. Sandstone body, moss along the back, red bib knot at the neck, faint violet cracks. No clear spiral mane from this angle. Snaps well (err 8.4). |
| Poochyena | `back_gemini3pro_a` | Failed the brief: it redrew the Eien front as a side view (spiral tail, full legs), the same failure as the earlier from-scratch test. Good design, wrong view. |

**Findings:** the two-image edit fixed the side-view problem for Gemini 3.1 Flash, which held
the exact pose in all four. Gemini 3 Pro kept Torchic's pose but redrew the pose for Bulbasaur,
Froakie and Poochyena. That's the opposite of the fronts, where Pro was stronger. Converting
with the front palette worked with no extra colours needed; the main loss is gradient detail
(Bulbasaur's bulb).
