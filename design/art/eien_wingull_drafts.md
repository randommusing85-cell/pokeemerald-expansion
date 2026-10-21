# Eien Wingull and Eien Pelipper: AI draft front sprites

Front drafts for the two Electric/Flying forms in `variants.md` (storm gulls of the sea cliffs:
white with storm-grey wings and lightning-streaked wingtips; Eien Pelipper's big bill holds a
crackling thundercloud instead of water).

**Picked and in the game:** Eien Wingull `gemini3pro_a`, Eien Pelipper `gemini3pro_a`, with their
idle frames, backs, icons and night-storm shinies (below). In-game shots: `eien_wingull/summary.png`,
`eien_wingull/battle_back.png`, `eien_wingull/party_icon.png`, `eien_pelipper/summary.png`.

Contact sheets (vanilla first, then each converted draft, at 2x):
[`eien_wingull_contact_sheet.png`](eien_wingull_contact_sheet.png),
[`eien_pelipper_contact_sheet.png`](eien_pelipper_contact_sheet.png).

## How they were made

`tools/eien_species/variant_drafts.py`, as for the other variants: frame 1 of the vanilla front
enlarged 8x, the shared brief and one concept, on `gemini-3-pro-image` and
`gemini-3.1-flash-image`, one call each, no cherry-picking. The concepts: **a** slate wings with
yellow zigzag streaks, **b** dark storm-grey wings with small sparks, **c** blue-grey wings
fading to near-black tips with thin lightning lines.

## Eien Wingull

| Draft | Concept | Notes |
| --- | --- | --- |
| `gemini3pro_a` | a, zigzag streaks | **Suggested.** Slate wings with clear yellow zigzags at the tips and a yellow beak: reads as a storm gull at 1x, still clearly Wingull. |
| `gemini31flash_a` | a, zigzag streaks | Yellow bolt shapes on the wings; close to 3 Pro a, a bit blockier. |
| `gemini3pro_b` | b, sparks | Dark wings with sparks, some drawn as loose pixels outside the body. |
| `gemini31flash_b` | b, sparks | Dark wings with yellow edge sparks; clean. |
| `gemini3pro_c` | c, black tips | Near-black wingtips with lightning lines and sparks; the busiest. |
| `gemini31flash_c` | c, black tips | Blue-grey wings with thin yellow lines; subtle at 1x. |

## Eien Pelipper

| Draft | Concept | Notes |
| --- | --- | --- |
| `gemini3pro_a` | a, cloud pouch | **Suggested.** Pelipper's yellow bill kept, its pouch a dark thundercloud with sparks, grey wings with yellow streaks: pairs with Wingull 3 Pro a. |
| `gemini31flash_a` | a, cloud pouch | A dark cloud pouch with yellow lines and darker wings. |
| `gemini3pro_b` | b, bolt pouch | A dark blue-grey pouch with a big yellow bolt across it and dark wings: the boldest read. A strong alternative. |
| `gemini31flash_b` | b, bolt pouch | A dark pouch with a yellow bolt and grey wings; clean, a little plain. |
| `gemini3pro_c` | c, glowing pouch | A pale pouch with lightning glowing inside a grey cloud; one foot came out blue. |
| `gemini31flash_c` | c, glowing pouch | A yellow glowing pouch around a grey cloud; light and low in contrast. |

## Notes

- All twelve kept the pose and framing.
- Pairs: Wingull 3 Pro a with Pelipper 3 Pro a (the yellow bill kept) or 3 Pro b (the bold
  bolt).
- After a pick: frame 2, back, icon and the night-storm shiny (a dark body with violet
  lightning), as for the other forms, then credit in `asset-credits.md`.

## After the pick

- **Fronts:** both converted cleanly and keep vanilla's framing. Sizes and offsets are fixed (the
  non-GBA-style ones), as for the other forms.
- **Backs** (`stage_drafts.py back`,
  [`eien_wingull_back_contact_sheet.png`](eien_wingull_back_contact_sheet.png)): Wingull
  `gemini3pro_b` (slate wings with yellow tips, like its front; 3 Pro a came out white),
  Pelipper `gemini31flash_b` (vanilla's back pose with the big pale wing; 3 Pro b turned to face
  forward and 3 Pro a gave it a brown chest).
- **Idle frames** ([`eien_wingull_frame2_contact_sheet.png`](eien_wingull_frame2_contact_sheet.png)):
  Wingull `gemini3pro_b` (3 Pro a curled into a ball), Pelipper `gemini3pro_a`.
- **Icons** ([`eien_wingull_icon_contact_sheet.png`](eien_wingull_icon_contact_sheet.png)): the
  drafts were noisy, so frame 1 of Wingull `gemini3pro_a` and Pelipper `gemini31flash_b` was
  indexed with only the greys, white and yellows of vanilla icon palettes 0 and 2, stray pixels
  removed; frame 2 is frame 1 moved down 1px.
- **Shinies** (`shiny_drafts.py`): `night_storm`, the white body turned dark slate and the
  lightning violet. Eien Wingull's beak shares the lightning's yellows and turns violet too;
  Eien Pelipper's bill stays yellow.
- The overworld (follower) sprites are still vanilla's (the Route 8 flock needs one: `TODO`).
