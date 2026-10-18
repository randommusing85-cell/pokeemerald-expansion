# Regional variants

Eien has its own variants of some existing Pokémon. Named like official regional forms:
**"Eien Poochyena"**. A final form may get its own name when the design calls for it.

- **Theme:** mostly Pokémon *touched by the fading*: living where the worlds are thin has
  shifted them toward Ghost, Psychic or Dark. Some are *adapted to the cold* (Ice, Water).
- **Budget:** the 9 starter variants, plus 5-10 others for the whole game.
- **Shinies:** every variant has a shiny palette. Shiny odds are 1 in 4,096 for all Pokémon
  (`SHINY_ODDS 16`); the Shiny Charm is a post-game reward.
- **Art:** each variant needs a front sprite (2 frames), back sprite, icon, and normal + shiny
  palettes. Workflow and findings: [art/eien_poochyena/README.md](art/eien_poochyena/README.md).

## How they're built

Regional forms of the existing species (like Alolan Rattata): the same dex number, their own
form entry (`SPECIES_TORCHIC_EIEN`, ...). Stats keep the original's total, redistributed to
fit the new typing. Abilities are existing ones that fit the theme; starters keep their pinch
ability as the main one. Starters evolve by level and keep their Eien typing; other variants
evolve by an Eien method (a shrine area, an aurora night, a thin place). Decided in
[brainstorm-eien-species.md](brainstorm-eien-species.md).

## Starters

Given by Professor Kashiwagi in Hamakaze. First evolution at about Lv 18 (not 16).

| Line | Eien type | Idea |
| --- | --- | --- |
| Torchic | Fire/Ghost | A shrine-lantern bird, touched by the fading |
| Bulbasaur | Grass/Psychic | A fading bloom: its bulb is partly translucent and glows faintly like the aurora, as if it's between worlds |
| Froakie | Water/Ice | A snow ninja, adapted to the cold; its frubbles are frost. The one starter the hero doesn't recognize (Gen 6) |

Each beats one other, like the classic starter cycle: Torchic beats Bulbasaur, Bulbasaur
beats Froakie, Froakie beats Torchic. (Grass/Water was tried for Bulbasaur and dropped: it
beat both others and neither beat it back.)

| Player picks | Akira takes (strong against it) | Haru takes |
| --- | --- | --- |
| Torchic | Froakie | Bulbasaur |
| Bulbasaur | Torchic | Froakie |
| Froakie | Bulbasaur | Torchic |

### First stages

Stats are HP / Atk / Def / SpA / SpD / Spe (the original in brackets).

| Form | Stats (total) | Abilities (hidden last) | New early moves |
| --- | --- | --- | --- |
| Eien Torchic | 45 / 45 / 40 / 80 / 50 / 50 (45 / 60 / 40 / 70 / 50 / 45), 310 | Blaze / Cursed Body | Astonish (5), Will-O-Wisp (14) |
| Eien Bulbasaur | 45 / 40 / 49 / 75 / 70 / 39 (45 / 49 / 49 / 65 / 65 / 45), 318 | Overgrow / Forewarn | Confusion (7; Vine Whip moves later) |
| Eien Froakie | 41 / 56 / 40 / 62 / 54 / 61 (41 / 56 / 40 / 62 / 44 / 71), 314 | Torrent / Snow Cloak | Powder Snow (5), Ice Shard (15) |

Otherwise they keep the original learnset.

**Sprites:** the fronts are the chosen AI drafts (`design/art/eien_starters_drafts.md`, round 2,
`front_gemini3pro_r2_b` for all three), converted by `tools/eien_species/convert_art.py`.
The backs are AI drafts too (`back_gemini31flash_b`, an edit of each original back with the
Eien front as reference). The icons are AI drafts as well; the starters' use an Eien icon palette
(icon palette 6, added because the six vanilla ones have no teal, violet or warm ash).
Shinies are deliberate recolors (`tools/eien_species/shiny_drafts.py`): Torchic "night
lantern" (slate body, violet flame), Bulbasaur "twilight" (purple body, gold bulb), Froakie
"midnight" (dark navy body, white frost scarf). The idle frame (front frame 2) is an AI draft
too; its motion is smaller than the original species' (a lean, a crouch, a mouth opening), so
hand animation can improve it later.

`TODO(design)`: dex entries (drafts are in the code).

### Evolved stages

Decided in [brainstorm-eien-starters-evolved.md](brainstorm-eien-starters-evolved.md). The
three lines diverge: Torchic's goes toward the dead and ritual (Ghost), Bulbasaur's toward the
sky and the aurora (Psychic), Froakie's deeper into the cold, with a touch of Tohoku festival
and folklore. All evolve at **Lv 18 and Lv 36** and keep their Eien typing. Names are "Eien"
plus the vanilla name for now.

**Built so far:** the middle stages' species data (`SPECIES_COMBUSKEN_EIEN`, `_IVYSAUR_EIEN`,
`_FROGADIER_EIEN`): stats, types, abilities, learnsets, draft dex entries, and the first stages'
Lv 18 evolutions (tests in `test/eien_journal.c`), with their sprites. The finals aren't built:
the middle stages don't evolve further yet.

- **Middle-stage sprites:** picked AI drafts ([art/eien_evolved_drafts.md](art/eien_evolved_drafts.md)):
  fronts Combusken `3pro_a`, Ivysaur `3pro_b`, Frogadier `3pro_a`; idle frames `3pro_a` /
  `31flash_a` / `3pro_a`; backs `31flash_b` / `31flash_a` / `3pro_a`
  (`tools/eien_species/stage_drafts.py`). Shinies carry the first stages' themes (night lantern,
  twilight, midnight; `shiny_drafts.py`). Icons are the vanilla icons recolored into the Eien icon
  palette (`make_icons.py`), since the icon drafts came out noisy. Checked in game: evolution,
  party icon, battle back (shots in `art/eien_combusken/`, `eien_ivysaur/`, `eien_frogadier/`).
- **Finals:** front-only concept drafts in the same contact sheet (`art/eien_evolved_contact_sheet.png`).

| Form | Look | Stats (total) | Evolution move |
| --- | --- | --- | --- |
| Eien Combusken | A leaping Nebuta festival dancer with lantern-paper feathers | 60 / 70 / 60 / 95 / 60 / 60 (405) | Fiery Dance |
| Eien Blaziken | The Nebuta warrior float itself: glowing from inside, painted face, a towering fighter | 80 / 105 / 70 / 120 / 70 / 85 (530) | Shadow Ball |
| Eien Ivysaur | The bud half-opens; a small aurora swirls inside its translucent petals | 60 / 53 / 63 / 90 / 85 / 54 (405) | Psybeam |
| Eien Venusaur | The flower fully open, the aurora streaming up from it into the sky | 80 / 73 / 83 / 110 / 105 / 74 (525) | Psychic |
| Eien Frogadier | A snow scout in a straw snow cape and snowshoes, scouting the drifts | 54 / 63 / 52 / 83 / 66 / 87 (405) | Icy Wind |
| Eien Greninja | A lone mountain guardian of the snow passes | 72 / 95 / 67 / 103 / 81 / 112 (530) | Freeze-Dry |

- **Stats:** each first stage's shift carried up its line (vanilla Combusken 60 / 85 / 60 / 85
  / 60 / 55, Blaziken 80 / 120 / 70 / 110 / 70 / 80, Ivysaur 60 / 62 / 63 / 80 / 80 / 60,
  Venusaur 80 / 82 / 83 / 100 / 100 / 80, Frogadier 54 / 63 / 52 / 83 / 56 / 97, Greninja 72 /
  95 / 67 / 103 / 71 / 122).
- **Abilities:** the pinch ability plus the first stage's hidden one (Blaze / Cursed Body,
  Overgrow / Forewarn, Torrent / Snow Cloak).
- **Learnsets:** the first stages' new moves carry on; otherwise vanilla.
- **Shinies:** the first stages' themes carried up (night lantern, twilight, midnight).
- **Art:** the middle stages in full (done); the finals as front-only drafts to check the
  concepts, full art later.
- **Dex entries (drafts, `TODO(design)`):** Eien Combusken (category Festival) dances in front of
  the lantern floats, paper feathers glowing; Eien Ivysaur (Aurora Bud) turns its half-open bud
  to the sky; Eien Frogadier (Snow Scout) walks the drifts in its straw cape and vanishes when
  travelers look back. The text is in `src/data/pokemon/species_info/eien_families.h`.
- `TODO(design)`: the finals' dex entries; final-form names if a design earns one; a signature move per
  final stage (parked).

## Others

| Pokémon | Eien type | Idea | Where first |
| --- | --- | --- | --- |
| Poochyena | Rock/Dark | A stone shrine guardian dog (komainu), touched by the fading. Beats the Ice gym. | Route 1 (common, ~20%) |
| Hoothoot | Ghost/Flying | A half-faded owl of the night pass: its wings and tail fade into mist, only the face and glowing eyes are solid. Touched by the fading. Immune to Fighting moves; beats the Fighting gym. | Route 2's mountain pass, grass near the town end (about 10% by day, 30% at night) |

- **Eien Poochyena:** 35 / 55 / 50 / 25 / 30 / 25 (35 / 55 / 35 / 30 / 30 / 35), 220.
  Abilities Intimidate / Sturdy / Stakeout (hidden). New early moves: Rock Throw (7), Rock
  Tomb (16); otherwise the original learnset.
- **Evolves** into Eien Mightyena (Rock/Dark) by leveling up to 18+ in a shrine area (a Rare
  Candy used there counts). The first chance is Kaede's shrine in Shimotsuki, right after
  gym 1. Before that, the Route 1 shrine's tablet hints at the rule, and the journal notes
  it: when he opens the journal with an Eien Poochyena of Lv 18+ in his party, its research
  entry says it didn't evolve. Built: the entry gets "Lv 18, and it didn't evolve." below its
  tiers, kept from then on (`FLAG_JOURNAL_POOCHYENA_NO_EVO`, set by `UpdateJournalNotes` in
  `src/eien_journal.c`; tests in `test/eien_journal.c`; shot in
  `art/journal_poochyena_note.png`). The research page is full with it: a lore tier for Eien
  Poochyena will need the page to scroll or the notes to shrink.

- **Sprite:** the front is the sprite test's draft ([art/eien_poochyena/](art/eien_poochyena/README.md)),
  converted by `tools/eien_species/convert_art.py`; the back is an AI draft like the
  starters'; its icon is an AI draft in the vanilla icon palette 5; its shiny is "obsidian"
  (black stone, bright violet cracks); its idle frame is a small snarl (AI draft).

- **Eien Mightyena:** 70 / 90 / 90 / 50 / 60 / 60 (70 / 90 / 70 / 60 / 60 / 70), 420: the same
  shift as Eien Poochyena. Abilities Intimidate / Sturdy / Stakeout (hidden). Learns Rock Slide
  on evolving; Rock Throw (7) and Rock Tomb (16) carry over; otherwise vanilla Mightyena's
  learnset. The name stays "Eien Mightyena".
- **Its sprite:** the "komainu" front draft (roaring, carved spiral mane and tail, red bib;
  [art/eien_mightyena/](art/eien_mightyena/README.md)). Its back is an AI draft (3.1 Flash b); its idle
  frame is a howl, like vanilla Mightyena's (AI draft). Its shiny is "obsidian", like Eien
  Poochyena's (black stone, bright violet cracks). Its icon is an AI draft in the vanilla
  icon palette 5, like Eien Poochyena's.

- **Wild Eien Mightyena** appear only on aurora nights at thin places: the stone dogs wake
  under the aurora ([side-quests.md](side-quests.md), Kaede step 2 and E3).

`TODO(design)`: Eien Mightyena's dex entry (a draft is in the code).

- **Eien Hoothoot** (designed, not built): 50 / 30 / 26 / 60 / 36 / 60 (60 / 30 / 30 / 36 / 56 /
  50), 262: a fast special attacker. Abilities Insomnia / Frisk / Cursed Body (hidden). New
  moves: Astonish (1), Gust (6, replacing Echoed Voice), Ominous Wind (15, replacing Defog);
  otherwise vanilla (Confusion 9, Reflect 12, Air Slash 18).
- **Evolves** into Eien Noctowl by leveling up to 20+ at night on its home pass (Route 2's
  mountain pass): an evolution entry with both the time (`IF_TIME`) and map conditions. The
  journal notes one that reaches Lv 20 without evolving, like Eien Poochyena's note (it needs
  its own flag, and the research page may need to scroll). The roadside tablet on the pass
  can hint at the rule (`TODO(design)`: its text).
- **Eien Noctowl:** 90 / 50 / 46 / 110 / 76 / 80 (100 / 50 / 50 / 86 / 96 / 70), 452: the same
  shift. Same abilities. Learns Hex on evolving. Look: shrouded, the faded wings stretched into
  long trailing veils that drift behind it like a funeral shroud.
- **Research:** seen / battled / caught, like Eien Poochyena's (side-quests E2).
- **Shiny:** aurora mist, green-violet instead of grey, for both stages.
- **Sprites:** AI drafts through `tools/eien_species/`, like Eien Poochyena's.
  `TODO(design)`: both dex entries (drafted at build time).

Decided in [brainstorm-eien-hoothoot.md](brainstorm-eien-hoothoot.md).

### Shrine areas

A **shrine area** is a shrine's grounds on their own small map; never a whole route or town,
and not the mountain. So far: the Route 1 shrine and Kaede's shrine in Shimotsuki. Every
shrine area is also a thin place (the mountain is a thin place but not a shrine area).
Each shrine map gets its own evolution entry (`IF_IN_MAP`), with no engine change. The
thin-place effect now keeps its own list of maps (`src/eien_places.c`); the shrine maps go in
both. Built for the Route 1 shrine (`MAP_EIEN_ROUTE1_SHRINE`) and Kaede's shrine
(`MAP_SHIMOTSUKI_KAEDE_SHRINE`). Decided in [brainstorm-shrine-areas.md](brainstorm-shrine-areas.md).

`TODO(design)`: how many shrines the whole game has, and where.
