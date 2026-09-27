# Drafts: Eien Mightyena

**Picked:** `front_gemini3pro_c` (komainu). It's in the game (`tools/eien_species/convert_art.py`);
in-game shots: `summary.png`, `battle_back.png`.

Front sprite drafts for Eien Mightyena, the evolution of Eien Poochyena (`variants.md`). Nothing
here is decided. Contact sheet: [../eien_mightyena_contact_sheet.png](../eien_mightyena_contact_sheet.png).

## How they were made

Vanilla Mightyena's front and Eien Poochyena's front, enlarged 8x, were given to Gemini 3 Pro
Image and Gemini 3.1 Flash Image. The model was asked to redraw Mightyena as Eien Poochyena's
evolution: same colors and materials, same pose and framing, Gen 4/5 pixel style. Each draft was
sampled to 64x64, its background removed and cut to 15 colors (`tools/sprite_prep`).
`drafts/raw/` has the model output and `converted/` has the GBA-ready sprites and palettes.

## Concepts

- **a, grown:** Eien Poochyena grown up: sandstone, a bigger spiral mane, the red bib now
  larger and frayed, moss, faint violet cracks.
- **b, shrine rope:** an older granite statue. The bib becomes a straw shrine rope
  (shimenawa) with white paper streamers, and violet light leaks from the cracks.
- **c, komainu:** closest to a real komainu statue: an open roaring mouth, a carved spiral
  mane and tail tuft, the red bib.

## Notes

- All six kept the pose and framing and fit 64x64 without scaling.
- The white mark on the front leg comes from Eien Poochyena's sprite.
- Frame 2, back, icon and shiny come after a pick, as for the other forms.

## Back sprite drafts

**Picked:** `back_gemini31flash_b`, in the game.

Contact sheet: [../eien_mightyena_back_contact_sheet.png](../eien_mightyena_back_contact_sheet.png).
Made like the other forms' backs: vanilla Mightyena's back and the picked front, enlarged 8x, went
to Gemini 3 Pro Image and 3.1 Flash Image, two tries each. The results were then indexed with the
form's palette (`back_drafts/`; raw output in `back_drafts/raw/`).

- **3.1 Flash b:** closest to the vanilla back's silhouette (a close shoulder view). It has the
  spiral mane, the bib's knot, moss and violet cracks. The best fit.
- **3.1 Flash a:** a big spiral tail fills the lower half. It reads well but changes the
  silhouette.
- **3 Pro a:** redrawn as a smaller full-body view, the framing problem the Poochyena test found.
- **3 Pro b:** washed-out pink; its colors snap badly to the palette.

## Frame 2 (idle) drafts

**Picked:** `frame2_gemini31flash_a`, in the game (checked on the summary screen).

Contact sheet: [../eien_mightyena_frame2_contact_sheet.png](../eien_mightyena_frame2_contact_sheet.png);
animated previews are the `frame2_drafts/*_anim.gif` files. Made like the other forms' idle frames:
the model saw vanilla Mightyena's two frames and the Eien front, and was asked to redraw the same
motion (a howl: head up and back, mouth open, tail lowered; about 1,000 pixels change). The results
were indexed with the form's palette. All four keep the legs still.

- **3.1 Flash a (889 px):** the full motion. The head goes up and the spiral tail drops, like
  the vanilla frame. The best match.
- **3 Pro a (779 px):** a clean howl with fangs, but the tail stays put.
- **3 Pro b (680 px):** like Pro a, with a smaller head move.
- **3.1 Flash b (372 px):** the head lifts only a little.

## Shiny palette drafts

**Picked:** `obsidian`, in the game (`shiny_game.png`: summary and battle).

Made by `tools/eien_species/shiny_drafts.py` like the other forms' shinies. Each concept recolors
groups of palette slots (stone 6/9/12 and its shading 2/4, bib 3/7/10, cracks 8/11), keeping each
color's lightness so the shading survives. The drafts are `shiny_drafts/*.pal`.
[shiny_line.png](shiny_line.png) shows Eien Poochyena's row above Eien Mightyena's; the full sheet is
[../eien_shiny_contact_sheet.png](../eien_shiny_contact_sheet.png).

- **obsidian:** black glassy stone and bright violet cracks. The moss and red bib stay. It matches
  Eien Poochyena's chosen shiny, so the line shines the same way. The best fit.
- **jade:** green jade stone and a gold bib, like Poochyena's "jade" draft.
- **moonstone:** pale white-grey stone and an indigo bib. The violet cracks are faint on it.

## Icon drafts

**Picked:** `icon_gemini3pro_a`, in the game (`party_icon.png`), via `tools/eien_species/make_icons.py`.

Contact sheet: [../eien_mightyena_icon_contact_sheet.png](../eien_mightyena_icon_contact_sheet.png).
Made like Eien Poochyena's icon: the model saw vanilla Mightyena's icon strip (32x64, two frames)
and the Eien front and repainted the icon; each draft was sampled back to 32x64. All four are
indexed with vanilla icon palette 5, the same palette as Eien Poochyena's icon, so the line
matches. Palette 5's darkest color is a dark grey, so the outlines are softer than in the drafts,
as on Poochyena's icon. (A best-fit search picked the Eien palette 6 for three drafts, but it
turns the sandstone grey.)

- **3 Pro a:** tan like Poochyena's icon, with the spiral tail, red bib and violet cracks. Frame
  2 moves about as much as vanilla's (216 px vs 201). The best fit.
- **3 Pro b:** a darker brown with a busy, noisy pattern.
- **3.1 Flash a, b:** frame 1 is fine, but frame 2 is redrawn larger and messy.
