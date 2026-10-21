# Evolved Eien starters: AI draft front sprites

Front drafts for the six evolved forms in `variants.md` ("Evolved stages").

**Picked and in the game:** Eien Combusken `gemini3pro_a`, Eien Ivysaur `gemini3pro_b`, Eien
Frogadier `gemini3pro_a`, with their idle frames, backs, shinies and icons (below). The finals'
drafts were concept checks; the finals are now picked and in the game too: Eien Blaziken
`gemini3pro_r2_b` (round 2, below), Eien Venusaur `gemini31flash_a`, Eien Greninja `gemini3pro_a`
("The finals' other sprites", below).

Contact sheet: [`eien_evolved_contact_sheet.png`](eien_evolved_contact_sheet.png) (vanilla first,
then each converted draft, at 2x).

## How they were made

`tools/eien_species/evolved_drafts.py`: each draft got two references enlarged 8x, frame 1 of
the vanilla front (pose, framing, silhouette) and frame 1 of the Eien first stage's front (colors
and materials), plus the brief from `variants.md`. Models `gemini-3-pro-image` and
`gemini-3.1-flash-image`, two tries each. One call per draft, no cherry-picking; one Blaziken call
(3.1 Flash a) returned text and no image, so Blaziken has three. The output was sampled to 64x64,
its white background removed and cut to 15 colors (`tools/sprite_prep`). Raw output is in
`eien_<species>/drafts/raw/`, the GBA-ready sprites and palettes in `eien_<species>/drafts/converted/`.

## Notes per draft (and a suggested pick)

### Eien Combusken (Nebuta dancer)

| Draft | Notes |
| --- | --- |
| `gemini3pro_a` | **Suggested.** Cream lantern-paper body, a violet ghost-flame crest and chest flame. The best contrast at 1x and still clearly Combusken. |
| `gemini3pro_b` | Grey-tan and darker legs; the paper idea is faint, a bit washed out. |
| `gemini31flash_a` | Pale lavender all over; reads as a ghost, not as lantern paper. |
| `gemini31flash_b` | Cream with red painted festival markings: the most Nebuta-like, but low contrast. |

### Eien Ivysaur (aurora bud)

| Draft | Notes |
| --- | --- |
| `gemini3pro_a` | Pink-violet half-open bud with an aurora inside; warm, strong read. |
| `gemini3pro_b` | **Suggested.** Teal and violet translucent petals, closest to Eien Bulbasaur's colors. |
| `gemini31flash_a` | Red petals: reads too close to vanilla Ivysaur. |
| `gemini31flash_b` | Pale translucent bud, faint aurora; low contrast. |

### Eien Frogadier (snow scout)

| Draft | Notes |
| --- | --- |
| `gemini3pro_a` | **Suggested.** Straw cape and snowshoes both clear, navy and ice colors like Eien Froakie. |
| `gemini3pro_b` | The cape reads more like a backpack. |
| `gemini31flash_a` | Cape and snowshoes, clean and readable; close second. |
| `gemini31flash_b` | Pale cape, low contrast. |

### Eien Blaziken (Nebuta warrior float), front-only concept check

| Draft | Notes |
| --- | --- |
| `gemini3pro_a` | Pale body with violet flame legs; the float idea is weak. |
| `gemini3pro_b` | **Suggested.** Paper-lantern panels lit by blue flames from inside: the clearest "float". |
| `gemini31flash_b` | Grey and ghostly; little paper or float. |

### Eien Blaziken, round 2 (the paper lantern float)

The first concepts read as a ghost-flame fighter, not a float (`brainstorm-eien-starters-finals.md`),
so Blaziken was re-drafted with `tools/eien_species/final_redrafts.py`: a stronger brief (white
washi paper over a visible dark frame, lit from inside by a pale blue-violet flame, a painted
warrior face in black, red and blue) and the picked Eien Combusken front as the colour reference.
Contact sheet: [`eien_blaziken_r2_contact_sheet.png`](eien_blaziken_r2_contact_sheet.png).

| Draft | Notes |
| --- | --- |
| `gemini3pro_r2_a` | Blue-white paper with dark frame lines across the body and a red and black painted face: the frame shows most, but it's cool, more ghost than lantern. |
| `gemini3pro_r2_b` | **Suggested.** Warm cream paper glowing as if lit from inside, a painted face, blue ghost flames at the wrists and legs: the clearest lit lantern float. |
| `gemini31flash_r2_a` | Grey-white with a blue-painted face mask; the frame lines are faint. |
| `gemini31flash_r2_b` | Peach paper and a red-painted face; soft and low in contrast at 1x. |

### Eien Venusaur (aurora streaming up), front-only concept check

| Draft | Notes |
| --- | --- |
| `gemini3pro_a` | Strong aurora, but it's cut off at the top of the 64x64 frame. |
| `gemini3pro_b` | Translucent open flower and a tall aurora; also cut at the top. |
| `gemini31flash_a` | **Suggested.** The flower open with a smaller aurora that fits the frame. |
| `gemini31flash_b` | Big aurora, cut at the top. |

### Eien Greninja (snow-pass guardian), front-only concept check

| Draft | Notes |
| --- | --- |
| `gemini3pro_a` | **Suggested.** Straw hat and cape, frost scarf, alert pose. |
| `gemini3pro_b` | Hat and cape, a looser silhouette. |
| `gemini31flash_a` | Cape and frost, no hat; reads as Frogadier grown up. |
| `gemini31flash_b` | A big hat that dominates the sprite. |

## The rest of the middle stages' sprites

Made with `tools/eien_species/stage_drafts.py` (back, frame2, icon): the vanilla sprite for
framing and motion plus the picked front, two models, two tries each. Contact sheets:
`eien_back_drafts_contact_sheet.png`, `eien_frame2_drafts_contact_sheet.png`,
`eien_icon_drafts_contact_sheet.png` (all three in `eien_middle_stage_drafts_contact_sheet.png`).

| | Combusken | Ivysaur | Frogadier |
| --- | --- | --- | --- |
| Back (picked) | `31flash_b`, the only one near the vanilla over-the-shoulder view (the others redrew it as a small full body) | `31flash_a`, the bud fills the frame like the vanilla back | `3pro_a`, big straw cape, close framing |
| Idle frame (picked) | `3pro_a`, arms spread like vanilla's motion | `31flash_a`, keeps the aurora bud | `3pro_a` |
| Shiny (default) | night lantern | twilight | midnight |
| Icon | the vanilla icon recolored into the Eien icon palette: the drafts lost the tiny two-frame layout and were noisy at 1x | same | same |

In-game shots in each `eien_<species>/` folder: `evolution.png`, `evolution_move.png`,
`party_icon.png`, `battle_back.png`. Credited in `design/asset-credits.md`.

## The finals' other sprites

Made like the middle stages' (`stage_drafts.py`), contact sheets
`eien_finals_back_contact_sheet.png`, `eien_finals_frame2_contact_sheet.png`,
`eien_finals_icon_contact_sheet.png`. In-game shots: `eien_blaziken/summary.png`,
`eien_blaziken/battle_back.png`, `eien_blaziken/party_icon.png` (all three icons),
`eien_venusaur/summary.png`, `eien_greninja/summary.png`.

| | Blaziken | Venusaur | Greninja |
| --- | --- | --- | --- |
| Back (picked) | `31flash_a`, vanilla's over-the-shoulder framing with a ghost flame at the wrist | none: the drafts redrew a full body filling the frame, so it keeps the placeholder (the vanilla back recolored from the front) | `3pro_a`, the straw cape and hat from behind |
| Idle frame (picked) | `3pro_a` | `3pro_b` | `3pro_a` |
| Shiny | night lantern (violet ghost flames) | twilight (purple body, gold-green aurora) | midnight (a dark navy body) |
| Icon | the vanilla icons recolored into the Eien icon palette, like the middle stages' (the drafts filled the whole 32x32 cell and were noisy) | same | same |

The frames are vanilla's, except Venusaur's front, whose aurora reaches the top of the frame
(Y offset 0). The overworld (follower) sprites are still vanilla's.
