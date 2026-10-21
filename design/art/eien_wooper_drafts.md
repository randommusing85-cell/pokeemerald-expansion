# Eien Wooper and Eien Quagsire: AI draft front sprites

Front drafts for the two Ground/Steel forms in `variants.md` (a mine Wooper crusted with iron and
copper ore; a Quagsire like a polished Nanbu *tetsubin* kettle).

**Picked and in the game:** Eien Wooper `gemini3pro_b`, Eien Quagsire `gemini3pro_a`, with their
idle frames, backs, icons and gold shinies (below). In-game shots: `eien_wooper/summary.png`,
`eien_wooper/battle_back.png`, `eien_wooper/party_icon.png`, `eien_quagsire/summary.png`.

Contact sheets (vanilla first, then each converted draft, at 2x):
[`eien_wooper_contact_sheet.png`](eien_wooper_contact_sheet.png),
[`eien_quagsire_contact_sheet.png`](eien_quagsire_contact_sheet.png).

## How they were made

`tools/eien_species/variant_drafts.py`: each draft got frame 1 of the vanilla front enlarged 8x
(pose, framing, silhouette), the shared brief from `variants.md` and one concept. There's no Eien
first stage to copy colors from, so each concept names its own materials. Models
`gemini-3-pro-image` and `gemini-3.1-flash-image`, one call per concept and model, no
cherry-picking. The output was sampled to 64x64, its white background removed and cut to 15
colors (`tools/sprite_prep`). Raw output is in `eien_<species>/drafts/raw/`, the GBA-ready
sprites and palettes in `eien_<species>/drafts/converted/`.

## Eien Wooper

| Draft | Concept | Notes |
| --- | --- | --- |
| `gemini3pro_a` | a, patchy crust | Iron grey with rust and copper patches, copper frill gills. Clear, warm; the closest to the brief's "iron and copper". |
| `gemini31flash_a` | a, patchy crust | Almost the same as 3 Pro a, slightly flatter shading. |
| `gemini3pro_b` | b, wet slate | **Suggested.** Dark blue-grey with bright copper flecks, iron fins with copper tips. Reads as Steel at 1x and pairs with a dark iron Quagsire. |
| `gemini31flash_b` | b, wet slate | Like 3 Pro b with more copper on the gills. |
| `gemini3pro_c` | c, raw ore | Lumpy brown ore over a pale grey belly, copper frills. Reads more as rock than metal. |
| `gemini31flash_c` | c, raw ore | Brown with silver frills; the metal frills read best here, the body least. |

## Eien Quagsire

| Draft | Concept | Notes |
| --- | --- | --- |
| `gemini3pro_a` | a, classic tetsubin | **Suggested.** Near-black iron covered in hobnail (arare) bumps: the most clearly a tetsubin, face kept. |
| `gemini31flash_a` | a, classic tetsubin | Same idea, browner and lower contrast. |
| `gemini3pro_b` | b, rusted kettle | Plain rust-brown with a lighter belly; the hobnails are faint. Reads as clay more than iron. |
| `gemini31flash_b` | b, rusted kettle | Rust with hobnails, a cream belly and orange ore patches on the tail; busy. |
| `gemini3pro_c` | c, polished iron | Smooth dark iron with a strong shine and thin copper veins: the "polished" look, and the copper ties it to Eien Wooper b. A strong alternative to 3 Pro a. |
| `gemini31flash_c` | c, polished iron | Glossy grey, almost chrome; loses the cast-iron feel. |

## Notes

- All twelve kept the pose and framing and fit 64x64 without scaling.
- Wooper's drafts have a pocket of white between the body and the tail that the background
  removal can't reach (it only clears background touching the edge). It's invisible on the white
  contact sheet (`gemini3pro_a`, `gemini31flash_a` and `gemini31flash_b`; the picked
  `gemini3pro_b` doesn't have one).
- Pairing: Wooper b with Quagsire a or c keeps the dark iron and copper line; Wooper c pairs
  with Quagsire b (brown ore to rust).
- After a pick: frame 2, back, icon and the gold shiny, as for the other forms
  (`stage_drafts.py`, `shiny_drafts.py`, `make_icons.py`), then credit in `asset-credits.md`.

## After the pick

- **Front conversion:** Wooper's draft was drawn on a finer grid than 64x64, and the normal
  conversion lost its smile and outline. Its front was re-sampled at 128x128 and folded 2x2 (a
  block with two or more near-black pixels stays black, otherwise its most common color), and the
  smile redrawn by hand (`eien_wooper/converted/front_gemini3pro_b.png`). Quagsire's normal
  conversion was kept.
- **Backs** (`stage_drafts.py back`, contact sheet
  [`eien_wooper_back_contact_sheet.png`](eien_wooper_back_contact_sheet.png)): Wooper
  `gemini3pro_b` (slate with copper flecks), Quagsire `gemini3pro_b` (hobnails down its back).
- **Idle frames** ([`eien_wooper_frame2_contact_sheet.png`](eien_wooper_frame2_contact_sheet.png)):
  Wooper `gemini31flash_a` (mouth open, like vanilla's frame 2), Quagsire `gemini3pro_a` (arms
  folded, mouth open).
- **Icons** ([`eien_wooper_icon_contact_sheet.png`](eien_wooper_icon_contact_sheet.png), previewed
  in the Eien icon palette): the Eien palette has no dark slate or copper, so both were indexed
  with vanilla icon palette 3 instead (dark blue, greys, copper): Wooper `gemini3pro_b`, Quagsire
  `gemini31flash_b` with frame 2 as frame 1 moved down 1px (`make_icons.py`, `ICON_READY`).
- **Shinies** (`shiny_drafts.py`, in `eien_shiny_contact_sheet.png`): Wooper `gold_crust` (a gold
  crust all over, as `variants.md` says) over `gold_flecks`; Quagsire `gilded` (the gilded kettle)
  over `gold_leaf`.
- The overworld (follower) sprites are still vanilla's, like the other Eien forms'.
