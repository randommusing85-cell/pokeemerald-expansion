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

## Icons

**Proposals only, not decided design.** These are draft party-menu icons for the four Eien
forms. Nothing in `graphics/` or `src/` was changed. Contact sheet:
[`eien_icons_contact_sheet.png`](eien_icons_contact_sheet.png). Each row shows the original
icon, then each converted draft, with frame 1 and frame 2 at x4 and the chosen icon palette
under each.

- **Icon style:** `P_GBA_STYLE_SPECIES_ICONS` is FALSE, so the inputs are the modern `icon.png`
  files in their `iconPalIndex` palettes: Torchic pal0, Bulbasaur pal4, Froakie pal0,
  Poochyena pal2.
- **Method:** an edit, like the backs. Each call sent two images:
  - Image 1: the original 32x64 icon strip, centred on a white 64x64 canvas, 8x. The canvas is
    square because the models return square images.
  - Image 2: the Eien front frame 1, 8x.

  Drafts: `icon_gemini3pro_a` (`gemini-3-pro-image`) and `icon_gemini31flash_b`
  (`gemini-3.1-flash-image`). Bulbasaur also has a retry pair, `_c` (Pro) and `_d` (Flash),
  with an extra size instruction.
- **Prompt:**
  > Image 1 is the original party-menu icon of {name}: two 32x32 pixel animation frames stacked
  > vertically (frame 1 on top, frame 2 below), a 32x64 strip placed in the middle of a white
  > 64x64 canvas and enlarged 8x. Image 2 is the front sprite of a regional variant, Eien
  > {name}, enlarged 8x; use it as the design reference. Repaint image 1 as the same regional
  > variant as image 2. Keep image 1's exact layout: the same 32x64 strip in the same place on
  > the canvas, both frames, and in each frame the exact same pose, size and position on its
  > 32x32 grid. Change colours and details, not the silhouettes; do not zoom, enlarge or redraw
  > the layout. Key features to keep readable at 32x32: {notes} Style: chunky, readable
  > Pokemon party icon pixel art (crisp square pixels, no anti-aliasing, no blur), dark
  > outline, few colours. Everything outside the sprites is plain flat pure white, no text.
  > Output a square image.

  The Bulbasaur retry added: "IMPORTANT: image 2 is only a colour/design reference; do not
  copy its size or pose. In image 1 each Bulbasaur is small, about 20 pixels wide and 19
  pixels tall inside its 32x32 frame [...]; keep both frames exactly that small".
- **Conversion:**
  - `sprite_prep.sample_grid` (64 grid), then crop the middle 32 columns to get the 32x64
    strip.
  - Background removed with `background_mask`, over the whole strip and per frame.
  - Indexed with each of the 6 icon palettes by nearest colour, keeping the palette with the
    lowest total error. One palette covers both frames.
  - Output: `eien_<species>/icon_drafts/<draft>.png` (32x64 indexed, index 0 transparent),
    raw model output in `icon_drafts/raw/`. All pass the size and colour checks.

| Species | Draft | Palette | Notes |
|---|---|---|---|
| Torchic | `icon_gemini3pro_a` | pal0 | **Pick.** Both frames keep the original pose and position. Grey "ash" body and grey tuft; a speck of teal on the belly. The cream turns grey (pal0 has no cream) and the lantern glow is 1-2 pixels, so it reads as a grey Torchic more than a lantern chick. |
| Torchic | `icon_gemini31flash_b` | pal2 | The model painted the body near-black, and frame 2 is shrunk. Off-design. |
| Bulbasaur | `icon_gemini3pro_c_hop_pal4` / `_pal3` | pal4 / pal3 | **Pick (made by hand from a model frame).** Frame 1 of `_c`, with frame 2 made by moving it down 1px. The original Bulbasaur icon's frame 2 is the same 1px hop. Pose and size are right. See the palette problem below. |
| Bulbasaur | `icon_gemini3pro_a`, `icon_gemini31flash_b`, `icon_gemini3pro_c`, `icon_gemini31flash_d` | pal3 | Frame 1 is fine in `_b`, `_c` and `_d`, but every draft redrew frame 2 as a big copy of the Eien front, and `_a` did it in both frames. The size instruction in the retry didn't fix frame 2. |
| Froakie | `icon_gemini3pro_a` | pal0 | **Pick.** Both frames keep the pose, yellow eyes and white scarf. But pal0 is Froakie's own palette and the changes are small, so it's hard to tell apart from vanilla Froakie; the ice crystals don't show at this size. |
| Froakie | `icon_gemini31flash_b` | pal4 | Paler icy body with navy feet, closer to the front, but frame 2's pose and outline drifted and are noisy. |
| Poochyena | `icon_gemini3pro_a` | pal5 | **Pick.** Both frames match the original's pose. Tan sandstone body, green moss and red bib all survive pal5 and read clearly. The best icon of the set. |
| Poochyena | `icon_gemini31flash_b` | pal4 | Frame 1 OK but darker; frame 2 redrawn as a big copy of the front. |

**Palette problem:** none of the 6 shared icon palettes has a cool teal-green or a violet. The
Bulbasaur aurora bulb and body snap to pal3/pal4 blues and greys, and lose the green-violet
look. Torchic's cream becomes grey. Options: hand-map the bulb to pal4's green (156,205,74) and
pink-violet (246,148,246); or accept a "blue Bulbasaur" icon. Adding a 7th icon palette would
be an engine change, so it's not proposed here.

**Findings:** Gemini 3 Pro kept both frames for Torchic, Froakie and Poochyena. Gemini 3.1 Flash
redrew frame 2 bigger for two species. That's the reverse of the backs, where Flash kept the
pose better. Frame 2 is the weak point: the models tend to paste the reference front into it.

## Frame 2 (idle)

**Proposals only, not decided design.** These are drafts for the second front animation frame,
to replace the placeholder (frame 1 raised 1px) in
`graphics/pokemon/eien/<species>/anim_front.png`. Nothing in `graphics/` was changed.

**Review files:**
- Contact sheet [`eien_frame2_contact_sheet.png`](eien_frame2_contact_sheet.png): original
  f1, original f2, Eien f1, then the drafts, each labelled with how many pixels differ from
  Eien f1 and where.
- A looping preview per draft, `eien_<species>/frame2_drafts/<draft>_anim.gif`: f1/f2 at 400ms,
  x3, green background.

**Method:** an edit. Each call sent two images:
- Image 1: the original species' frames 1 and 2 side by side, in `normal.pal`, 8x
  (1024x512).
- Image 2: Eien frame 1, 8x.

**Drafts:**
- Round 1: `frame2_gemini3pro_a` (`gemini-3-pro-image`) and `frame2_gemini31flash_b`
  (`gemini-3.1-flash-image`).
- Round 2, retried after round 1 barely moved anything: `_c` (Pro) and `_d` (Flash), with the
  motion described explicitly.
- Two 502 "upstream request failed" errors on Torchic; one retry fixed round 1. Torchic's Flash
  `_d` failed twice and doesn't exist.

**Conversion:** `sample_grid` (64), `background_mask`, then `sprite_prep.index` with the
form's existing `normal.pal`. Front, frame 2 and back all share one palette. Output:
`eien_<species>/frame2_drafts/<draft>.png` (64x64 indexed), raw model output in
`frame2_drafts/raw/`.

**Prompt (round 1):**
> Image 1 shows the original {name}'s two idle animation frames side by side (frame 1 left,
> frame 2 right), 64x64 pixel art each, enlarged 8x; note exactly what changes from frame 1 to
> frame 2. Image 2 is a regional variant's frame 1 (Eien {name}), 64x64 enlarged 8x. Draw the
> regional variant's frame 2: identical to image 2 in design, colours, size, outline and
> position, changing ONLY what changes between the two frames in image 1 (the same small
> motion). Same canvas framing as image 2: a single 64x64 sprite enlarged 8x, not zoomed or
> moved. Pixel art with crisp square pixels, no anti-aliasing, no blur. Plain flat pure white
> background, nothing else, no text. Output a square image.

**Round 2 change:** "(the same small motion)" became "(the same motion)", followed by a
description of the original's motion and its size. For example, Poochyena: "lowers its head
and opens its mouth in a snarl, the body and tail shift. About 770 pixels change; it is a
clear pose change". Then: "Make the regional variant move the same way and by the same amount,
keeping all its own design details [...] on the moved parts."

**Key finding:** the original frame 2s aren't small tweaks. 529-850 pixels change: Torchic
leans, Bulbasaur rears up, Froakie shifts into a hop, Poochyena lowers its head. The models
either copied frame 1 with a tiny local change (5-150 px in round 1) or matched the motion but
redrew the design (Bulbasaur `_d` and `_c`). No draft matches both the motion and the design.

| Species | Draft | Differs | Notes |
|---|---|---|---|
| Torchic | `frame2_gemini3pro_c` | 240 px | **Pick.** A slight lean and a leg change across the whole height, with the design unchanged. Much less motion than the original's lean. |
| Torchic | `frame2_gemini31flash_b` | 122 px | Small leg and feet shuffle only. |
| Torchic | `frame2_gemini3pro_a` | 30 px | Feet only; almost a still. |
| Bulbasaur | `frame2_gemini31flash_b` | 26 px | **Pick (safe).** Mouth opens, nothing else. The design is exactly frame 1. It gives only the mouth part of the original's rear-up, but it reads as a real "breath/roar" in the GIF. |
| Bulbasaur | `frame2_gemini31flash_d` | 836 px | Matches the rear-up motion and size of the original (850 px), but redraws the design: a bigger violet bulb and a different body shade. Useful as a pose reference for a hand redraw. |
| Bulbasaur | `frame2_gemini3pro_c` | 1180 px | Mouth open, but redrawn bigger (zoomed), so it jumps in size. Not usable. |
| Bulbasaur | `frame2_gemini3pro_a` | 75 px | Feet shuffle only. |
| Froakie | `frame2_gemini3pro_c` | 264 px | **Pick.** The legs shift into a wider, lower hop stance with the upper body and design unchanged. Less motion than the original, but it reads. |
| Froakie | `frame2_gemini31flash_d` | 181 px | Similar wide-leg stance; also reasonable. |
| Froakie | `frame2_gemini3pro_a` / `frame2_gemini31flash_b` | 80 / 33 px | Feet only. |
| Poochyena | `frame2_gemini3pro_c` | 139 px | **Pick.** Head and snout lower and the mouth opens into a snarl, which is the original's motion in miniature. The design is otherwise identical. |
| Poochyena | `frame2_gemini3pro_a` | 150 px | Tail/back change only, not the original's head motion. |
| Poochyena | `frame2_gemini31flash_d` / `frame2_gemini31flash_b` | 34 / 5 px | Mouth only / effectively a copy of frame 1. |

**Recommendation:** the picks are usable as placeholders better than the 1px raise, but a
full-size motion like the originals needs hand work. Start from the pick and move parts by
hand, using Bulbasaur `_d` as a pose guide.
