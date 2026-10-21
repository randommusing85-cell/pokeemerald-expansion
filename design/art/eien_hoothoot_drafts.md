# Eien Hoothoot and Eien Noctowl: AI draft front sprites

Front drafts for the two Ghost/Flying forms in `variants.md` (a half-faded owl whose wings and
tail fade into mist; a Noctowl whose faded wings hang behind it in long veils, like a shroud).
**Picked and in the game:** Eien Hoothoot `gemini3pro_a`, Eien Noctowl `gemini3pro_a`, with their
idle frames, backs, icons and aurora shinies (below). In-game shots: `eien_hoothoot/summary.png`,
`eien_hoothoot/battle_back.png`, `eien_hoothoot/party_icon.png`, `eien_noctowl/summary.png`.

Contact sheets (vanilla first, then each converted draft, at 2x):
[`eien_hoothoot_contact_sheet.png`](eien_hoothoot_contact_sheet.png),
[`eien_noctowl_contact_sheet.png`](eien_noctowl_contact_sheet.png).

## How they were made

`tools/eien_species/variant_drafts.py`, as for Eien Wooper: frame 1 of the vanilla front enlarged
8x, the shared brief from `variants.md` and one concept, on `gemini-3-pro-image` and
`gemini-3.1-flash-image`, one call each, no cherry-picking. The three concepts are the three mist
treatments from `brainstorm-eien-hoothoot-build.md`: **a** pale solid mist (no outline), **b**
dithered mist (a checker of mist and background), **c** evaporating mist (fading to loose pixels).

## Eien Hoothoot

| Draft | Concept | Notes |
| --- | --- | --- |
| `gemini3pro_a` | a, pale solid | **Suggested.** Pale lavender mist wings spread wide, icy glowing eyes, misty feet. Clean at 1x; the faded wings read clearly against the solid, outlined face. |
| `gemini31flash_a` | a, pale solid | A pale belly and small wings; closer to vanilla, less faded. |
| `gemini3pro_b` | b, dithered | The body tapers into a ghost's mist tail instead of feet, with dithered wing tips. The most ghostly, but it loses Hoothoot's feet. A strong alternative. |
| `gemini31flash_b` | b, dithered | The wings are checkerboard blocks; they read as boxes, not mist. |
| `gemini3pro_c` | c, evaporating | Yellow eyes, loose pixels around the ears and wings. Noisy at 1x. |
| `gemini31flash_c` | c, evaporating | Barely changed from vanilla's shape; little mist. |

## Eien Noctowl

| Draft | Concept | Notes |
| --- | --- | --- |
| `gemini3pro_a` | a, pale solid | **Suggested.** Pale lavender veils hanging down both sides to its feet: the clearest shroud, still a clear Noctowl. Pairs with Hoothoot `gemini3pro_a`. |
| `gemini31flash_a` | a, pale solid | Dark outlined veils with a black bar across: reads as a cape, not mist. |
| `gemini3pro_b` | b, dithered | Huge wings to the frame's edges with dithered hems. Dramatic, but it fills the whole frame and gets busy. |
| `gemini31flash_b` | b, dithered | See-through dithered veils; subtle, a little faint at 1x. |
| `gemini3pro_c` | c, evaporating | Wings spread in an arc like a bat's; less owl, the head half hidden. |
| `gemini31flash_c` | c, evaporating | Veils whose hems fade into loose pixels. A good alternative to 3 Pro a, pairing with Hoothoot c's idea. |

## Notes

- Hoothoot's drafts keep vanilla's framing. Noctowl's are much wider than vanilla (whose front is
  only 40 wide): the veils take up most of the 64x64 frame, so the picked one needs
  `frontPicSize` 64x64 (and its back and Y offset checked) instead of vanilla's 40x64.
- After a pick: frame 2, back, icon and the aurora-mist shiny (green-violet), as for the other
  forms (`stage_drafts.py`, `shiny_drafts.py`, `make_icons.py`), then credit in
  `asset-credits.md`.

## After the pick

- **Fronts:** both converted cleanly (the drafts kept the 64x64 grid). Hoothoot's mist wings
  make it wider than vanilla (`frontPicSize` 56x40); Noctowl's veils fill the frame
  (`frontPicSize` 64x64 instead of vanilla's 40x64). Both forms' sizes and offsets no longer
  switch with `P_GBA_STYLE_SPECIES_GFX`, as for Eien Wooper and Quagsire.
- **Backs** (`stage_drafts.py back`,
  [`eien_hoothoot_back_contact_sheet.png`](eien_hoothoot_back_contact_sheet.png)): Hoothoot
  `gemini3pro_a`, Noctowl `gemini3pro_a`. All four Hoothoot backs came out as side views rather
  than vanilla's from-behind view (the same weakness the Poochyena test found); `gemini3pro_a` is
  the clearest. Neither back shows much mist; a hand pass could add it.
- **Idle frames** ([`eien_hoothoot_frame2_contact_sheet.png`](eien_hoothoot_frame2_contact_sheet.png)):
  Hoothoot `gemini3pro_b` (mist wings raised, like vanilla's flap), Noctowl `gemini31flash_b`
  (Noctowl's 3 Pro a call returned no image).
- **Icons** ([`eien_hoothoot_icon_contact_sheet.png`](eien_hoothoot_icon_contact_sheet.png)):
  Hoothoot `gemini31flash_a`, Noctowl `gemini3pro_a`, indexed with vanilla icon palette 2 (greys
  and violet, closer than the Eien palette's warm greys). Frame 2 is frame 1 moved down 1px. Two
  drafts (Hoothoot 3 Pro a, Noctowl 3 Pro b) drew a box around the icon and were skipped.
  Noctowl's icon is busy at 32x32; a hand pass could simplify the veils.
- **Shinies** (`shiny_drafts.py`, in `eien_shiny_contact_sheet.png`): `aurora_dusk` for both
  (green mist on a violet-grey body) over `aurora` (green mist only), which was too faint on
  Hoothoot to read as shiny.
- The overworld (follower) sprites are still vanilla's, like the other Eien forms'.
