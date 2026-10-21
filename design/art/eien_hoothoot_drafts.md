# Eien Hoothoot and Eien Noctowl: AI draft front sprites

Front drafts for the two Ghost/Flying forms in `variants.md` (a half-faded owl whose wings and
tail fade into mist; a Noctowl whose faded wings hang behind it in long veils, like a shroud).
Nothing here is picked yet; the game uses the vanilla sprites in placeholder mist palettes.

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
