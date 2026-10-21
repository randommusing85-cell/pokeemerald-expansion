# Eien Stantler and Eien Wyrdeer: AI draft front sprites

Front drafts for the two Dark/Ghost forms in `variants.md` (a faded Japanese serow: a shaggy
dark-grey coat, a pale face mask, hollow grey antler orbs; Eien Wyrdeer the old serow, frosted,
with antlers like dead winter wood and a mist beard).

**Picked and in the game:** Eien Stantler `gemini3pro_a`, Eien Wyrdeer `gemini3pro_a`, with their
idle frames, backs, icons and winter-coat shinies (below). In-game shots: `eien_stantler/summary.png`,
`eien_stantler/battle_back.png`, `eien_stantler/party_icon.png`, `eien_wyrdeer/summary.png`.

Contact sheets (vanilla first, then each converted draft, at 2x):
[`eien_stantler_contact_sheet.png`](eien_stantler_contact_sheet.png),
[`eien_wyrdeer_contact_sheet.png`](eien_wyrdeer_contact_sheet.png).

## How they were made

`tools/eien_species/variant_drafts.py`, as for the other variants: frame 1 of the vanilla front
enlarged 8x (Wyrdeer has only one frame, `front.png`), the shared brief and one concept, on
`gemini-3-pro-image` and `gemini-3.1-flash-image`, one call each, no cherry-picking. The concepts:
**a** a charcoal coat with a cream face mask and flat grey hollow orbs, **b** a blue-grey coat
with see-through grey orbs, **c** a dark grey-brown coat with black void orbs rimmed in violet.

## Eien Stantler

| Draft | Concept | Notes |
| --- | --- | --- |
| `gemini3pro_a` | a, charcoal | **Suggested.** A charcoal coat, a cream face mask and grey hollow orbs: the clearest serow, and the hollow orbs read at 1x. |
| `gemini31flash_a` | a, charcoal | Close to 3 Pro a, with a cream tail. |
| `gemini3pro_b` | b, blue-grey | A softer blue-grey with a grey mask; the orbs look see-through. Calmer, less "faded". |
| `gemini31flash_b` | b, blue-grey | Kept vanilla's gold antlers: off-brief. |
| `gemini3pro_c` | c, void orbs | Dark brown with black orbs rimmed in violet: eerie, a strong alternative. |
| `gemini31flash_c` | c, void orbs | Grey-brown with black orbs; flatter. |

## Eien Wyrdeer

| Draft | Concept | Notes |
| --- | --- | --- |
| `gemini3pro_a` | a, charcoal | **Suggested.** A charcoal coat speckled with frost, a cream mask, a long grey beard and hollow orbs: pairs with Stantler 3 Pro a. |
| `gemini31flash_a` | a, charcoal | Close to 3 Pro a. |
| `gemini3pro_b` | b, blue-grey | Pale blue-grey and ghostly, with a mist beard: the most "faded" Wyrdeer. |
| `gemini31flash_b` | b, blue-grey | Wild mist all over; busy. |
| `gemini3pro_c` | c, void orbs | Dark brown with frost and a white, skull-like mask: eerie; pairs with Stantler 3 Pro c. |
| `gemini31flash_c` | c, void orbs | Grey with a skull-like mask; flatter. |

## Notes

- All twelve kept the pose and framing. Wyrdeer's vanilla front has a single frame; the Eien
  form gets an idle frame drafted like the others'.
- Pairs: Stantler 3 Pro a with Wyrdeer 3 Pro a (charcoal and cream), or Stantler 3 Pro c with
  Wyrdeer 3 Pro c (dark brown with void orbs; the skull-like mask may read more Ghost than serow).
- After a pick: frame 2, back, icon and the snow-white winter shiny, as for the other forms, then
  credit in `asset-credits.md`.

## After the pick

- **Fronts:** both converted cleanly and keep vanilla's framing. Eien Wyrdeer gets two frames
  (vanilla Wyrdeer has one) and Stantler's front animation. Sizes and offsets are fixed (the
  non-GBA-style ones), as for the other forms.
- **Backs** (`stage_drafts.py back`,
  [`eien_stantler_back_contact_sheet.png`](eien_stantler_back_contact_sheet.png)): `gemini3pro_a`
  for both (Wyrdeer 3 Pro b put a snowflake on its back and was skipped).
- **Idle frames** ([`eien_stantler_frame2_contact_sheet.png`](eien_stantler_frame2_contact_sheet.png)):
  `gemini3pro_a` for both.
- **Icons** ([`eien_stantler_icon_contact_sheet.png`](eien_stantler_icon_contact_sheet.png)):
  `gemini3pro_a` for both, kept in the Eien icon palette (its dark greys and white suit them);
  frame 2 is frame 1 moved down 1px.
- **Shinies** (`shiny_drafts.py`): `winter_coat`, the dark coat turned snow-white with a cold
  tint; the mask and antlers kept.
- The overworld (follower) sprites are still vanilla's (the Minori glimpse needs one: `TODO`).
