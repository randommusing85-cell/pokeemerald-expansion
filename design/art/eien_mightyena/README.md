# Drafts: Eien Mightyena

**Picked:** `front_gemini3pro_c` (komainu). It's in the game (`tools/eien_species/convert_art.py`);
in-game shots: `summary.png`, `battle_back.png` (placeholder back).

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

## Back sprite drafts (proposals)

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
