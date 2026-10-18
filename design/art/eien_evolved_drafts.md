# Evolved Eien starters: AI draft front sprites

**Proposals only, not decided.** Front drafts for the six evolved forms in `variants.md`
("Evolved stages"). The middle stages are in the game with placeholder sprites (the vanilla ones
recolored) until a draft is picked; the finals aren't built.

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

## After a pick

For each picked middle stage: `convert_art.py` (front, palette), then frame 2, back, icon and
shiny drafts as for the first stages, and a credit in `design/asset-credits.md`. The finals stay
concept drafts until they're built.
