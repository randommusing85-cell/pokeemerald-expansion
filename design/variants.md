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

**Built:** the finals (`SPECIES_BLAZIKEN_EIEN`, `_VENUSAUR_EIEN`, `_GRENINJA_EIEN`), evolving from
the middle stages at Lv 36, with their sprites ([art/eien_evolved_drafts.md](art/eien_evolved_drafts.md));
draft dex entries `TODO(design)`. Before that, the middle stages' species data (`SPECIES_COMBUSKEN_EIEN`, `_IVYSAUR_EIEN`,
`_FROGADIER_EIEN`): stats, types, abilities, learnsets, draft dex entries, and the first stages'
Lv 18 evolutions (tests in `test/eien_journal.c`), with their sprites.

- **Middle-stage sprites:** picked AI drafts ([art/eien_evolved_drafts.md](art/eien_evolved_drafts.md)):
  fronts Combusken `3pro_a`, Ivysaur `3pro_b`, Frogadier `3pro_a`; idle frames `3pro_a` /
  `31flash_a` / `3pro_a`; backs `31flash_b` / `31flash_a` / `3pro_a`
  (`tools/eien_species/stage_drafts.py`). Shinies carry the first stages' themes (night lantern,
  twilight, midnight; `shiny_drafts.py`). Icons are the vanilla icons recolored into the Eien icon
  palette (`make_icons.py`), since the icon drafts came out noisy. Checked in game: evolution,
  party icon, battle back (shots in `art/eien_combusken/`, `eien_ivysaur/`, `eien_frogadier/`).
- **Finals:** built with picked AI art (see above); the first front-only concept drafts are in the same contact sheet (`art/eien_evolved_contact_sheet.png`).
  Decided for the build in [brainstorm-eien-starters-finals.md](brainstorm-eien-starters-finals.md):
  - **Art:** Eien Venusaur and Eien Greninja are picked from those concepts. Eien Blaziken gets a
    re-draft with a stronger brief: a paper lantern body over a visible frame, lit from inside,
    with a painted warrior face.
  - **Build:** data and art together, as with Eien Hoothoot.
  - **Signature moves:** an existing rare move each, learned at Lv 42 (not by TM): Eien Blaziken
    Infernal Parade (a festival float's procession), Eien Venusaur Lumina Crash, Eien Greninja
    Triple Axel.
  - **Names:** "Eien" plus the vanilla name, like every other variant; own names stay open.
  - **Akira:** at the tournament his starter is still the middle stage. The hero first sees an
    Eien final in their Route 5 goodbye battle (about Lv 36).

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
- **Art:** the middle stages and the finals in full (done).
- **Dex entries (drafts, `TODO(design)`):** Eien Combusken (category Festival) dances in front of
  the lantern floats, paper feathers glowing; Eien Ivysaur (Aurora Bud) turns its half-open bud
  to the sky; Eien Frogadier (Snow Scout) walks the drifts in its straw cape and vanishes when
  travelers look back. The text is in `src/data/pokemon/species_info/eien_families.h`.
- `TODO(design)`: the finals' dex entries (drafted at build time); final-form names if a design
  earns one.

## Others

| Pokémon | Eien type | Idea | Where first |
| --- | --- | --- | --- |
| Poochyena | Rock/Dark | A stone shrine guardian dog (komainu), touched by the fading. Beats the Ice gym. | Route 1 (common, ~20%) |
| Hoothoot | Ghost/Flying | A half-faded owl of the night pass: its wings and tail fade into mist, only the face and glowing eyes are solid. Touched by the fading. Immune to Fighting moves; beats the Fighting gym. | Route 2's upper map, the vents near Yunotaki (10% by day, 30% at night) |
| Ledyba | Bug/Fire | Ember fireflies (*hotaru*) of the summer rice paddies: glowing ember spots, an abdomen lit like a coal. Not touched by the fading: in the orchard thinning they keep glowing while the trees grey around them. The answer to gym 4 (Grass) | Route 4 ([route-4.md](locations/route-4.md)), the plain |
| Wooper | Ground/Steel | A mine Wooper of the old tunnel's pools: its skin crusted with iron and copper ore, its gills glinting metal frills. Adapted to the mine, not touched by the fading. Immune to Electric; the answer to gym 3 | Route 3 ([route-3.md](locations/route-3.md)): the gorge's grass 10%, the cave 30% |

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
  upper map only): an evolution entry with both the time (`IF_TIME`) and map conditions.
  Like Eien Wooper's, the entry waits until `MAP_EIEN_ROUTE2_UPPER` exists (Porymap); until
  then it doesn't evolve, and the journal's note covers it. Until the pass maps are built it
  isn't caught anywhere (species data only, tested through the debug menu). The
  journal notes one that reaches Lv 20 without evolving, like Eien Poochyena's note (it needs
  its own flag; each species has its own research page, so it doesn't crowd Poochyena's). The roadside tablet on the pass
  can hint at the rule (`TODO(design)`: its text).
- **Eien Noctowl:** 90 / 50 / 46 / 110 / 76 / 80 (100 / 50 / 50 / 86 / 96 / 70), 452: the same
  shift. Same abilities. Learns Hex on evolving. Look: shrouded, the faded wings stretched into
  long trailing veils that drift behind it like a funeral shroud.
- **Research:** seen / battled / caught, like Eien Poochyena's: an entry on the professor's
  list (side-quests E2), shown once the hero has gym 1's badge.
- **Shiny:** aurora mist, green-violet instead of grey, for both stages.
- **Sprites:** picked AI drafts ([art/eien_hoothoot_drafts.md](art/eien_hoothoot_drafts.md)),
  from one round with three mist treatments: both picks are the pale solid mist (lavender mist
  wings, no outline, around a solid face with icy glowing eyes; Eien Noctowl's veils hang down
  both sides to its feet). With idle frames, backs, icons (vanilla icon palette 2) and aurora
  shinies (green mist on a violet-grey body). `TODO(design)`: both dex entries (drafts in
  `eien_families.h`) and the research tier lines (drafts in `src/data/eien_journal.h`).
- **Built:** `SPECIES_HOOTHOOT_EIEN` / `SPECIES_NOCTOWL_EIEN`; tests in `test/eien_journal.c` and
  `test/battle/eien_research.c`.
  `TODO(design)`: both dex entries (drafted at build time).

Decided in [brainstorm-eien-hoothoot.md](brainstorm-eien-hoothoot.md); the build in
[brainstorm-eien-hoothoot-build.md](brainstorm-eien-hoothoot-build.md).

- **Eien Wooper** (built, without its evolution: see below): 55 / 45 / 55 / 15 / 35 / 5 (55 / 45 / 45 / 25 / 25 /
  15), 210: balanced bulk. Abilities Sturdy / Heavy Metal / Unaware (hidden). New moves:
  Mud-Slap (1, replacing Water Gun), Metal Claw (16, replacing Slam); Mud Shot (8) as vanilla;
  otherwise vanilla. Against Akari: Lanturn's Water hits it 2x, Ice Fang is neutral, Flash
  Cannon is resisted.
- **Evolves** into Eien Quagsire by leveling up to 20+ in the mine tunnel only
  (`MAP_EIEN_ROUTE3_CAVE`, an `IF_IN_MAP` entry). `TODO`: the entry is added once the map exists
  (Porymap); until then Eien Wooper doesn't evolve. The journal notes one that reaches Lv 20
  outside the tunnel, like Eien Poochyena's note (`FLAG_JOURNAL_WOOPER_NO_EVO`). A Survey member at the tunnel
  says they found them "in the old seams" when they cleared it: a hint at the rule, and at
  what the Survey digs for (`TODO(design)`: that payoff).
- **Eien Quagsire:** 95 / 85 / 95 / 55 / 75 / 25 (95 / 85 / 85 / 65 / 65 / 35), 430: the same
  shift. Same abilities. Learns Iron Head on evolving. Look: smooth polished metal, like a Nanbu
  *tetsubin* (the cast-iron kettle of Iwate's ironware craft), with Quagsire's goofy face kept.
- **Research:** seen / battled / caught, like the others (`QUEST_RESEARCH_WOOPER`; tiers are
  tracked from the start), on the professor's list (side-quests E2), shown once the hero has
  gym 2's badge. `TODO(design)`: the tier lines (drafts in `src/data/eien_journal.h`).
- **Shiny:** gold ore, a gleaming gold crust instead of iron and copper; Eien Quagsire a gilded
  kettle.
- **Sprites:** picked AI drafts ([art/eien_wooper_drafts.md](art/eien_wooper_drafts.md)): Eien
  Wooper dark wet slate with copper flecks and iron fins, Eien Quagsire a near-black hobnailed
  tetsubin; with idle frames, backs, icons (vanilla icon palette 3) and gold shinies (a gold
  crust; a gilded kettle). `TODO(design)`: both dex entries,
  categories ("Ore Fish" is a placeholder) and sizes (vanilla's for now; drafts in
  `eien_families.h`).
- **Built:** `SPECIES_WOOPER_EIEN` / `SPECIES_QUAGSIRE_EIEN` (`eien_families.h`, learnsets and
  palettes in `eien_forms_data.h`); tests in `test/eien_journal.c` and
  `test/battle/eien_research.c`.

Decided in [brainstorm-eien-wooper.md](brainstorm-eien-wooper.md).

- **Eien Ledyba** (designed, not built): 40 / 20 / 30 / 70 / 50 / 55 (40 / 20 / 30 / 40 / 80 /
  55), 265: a special attacker. Abilities Flame Body / Swarm / Illuminate (hidden; in Gen 9 it
  stops accuracy drops and ignores evasion). New moves: Ember (1, replacing Tackle),
  Will-O-Wisp (12, replacing Safeguard), Flame Wheel (15, replacing Mach Punch); otherwise
  vanilla.
- **Evolves** into Eien Ledian by leveling up to 18+ while it's raining (`IF_WEATHER`; Route 4
  gets rain some of the time, `TODO(design)`: how). The journal notes one that reaches Lv 18
  without evolving (its own flag).
- **Eien Ledian:** 55 / 35 / 50 / 95 / 80 / 75 (55 / 35 / 50 / 55 / 110 / 85), 390. The same
  abilities. Look: its light brightens into a lantern-like glow on its back (a firefly, not the
  paper lanterns of Torchic's line).
- **Research:** seen / battled / caught on the professor's list (side-quests E2), shown after
  gym 3's badge.
- **Shiny:** a real firefly's pale green light instead of ember orange, for both stages.
- **Sprites:** AI drafts through `tools/eien_species/`. `TODO(design)`: both dex entries
  (drafted at build time).
- **Variants still to come (r1 4b):** one for each remaining gym a variant answers well, about
  three more after Eien Ledyba, plus Trubbish's split (within the planned 5-10).

Decided in [brainstorm-eien-variant-4.md](brainstorm-eien-variant-4.md).

### Planned: Trubbish's split

Later in the game, Trubbish branches at Garbodor's level (Lv 36): leveling up while holding
**Fresh Water** evolves it into a new Pokémon instead of Garbodor, and the Fresh Water is used
up (like vanilla held-item evolutions). Fresh Water can be held (it's in the Items pocket), and
the engine's `IF_HOLD_ITEM` condition on a level-up evolution supports it, with no engine
change. Unlike the variants, the new Pokémon is a new species, not a regional form.
`TODO(design)`: where Trubbish is found (a later act); the new Pokémon itself (name, type,
look, stats; its own brainstorm). Noted in [brainstorm-eien-wooper.md](brainstorm-eien-wooper.md).

### Shrine areas

A **shrine area** is a shrine's grounds on their own small map; never a whole route or town,
and not the mountain. So far: the Route 1 shrine and Kaede's shrine in Shimotsuki. Every
shrine area is also a thin place (the mountain is a thin place but not a shrine area).
Each shrine map gets its own evolution entry (`IF_IN_MAP`), with no engine change. The
thin-place effect now keeps its own list of maps (`src/eien_places.c`); the shrine maps go in
both. Built for the Route 1 shrine (`MAP_EIEN_ROUTE1_SHRINE`) and Kaede's shrine
(`MAP_SHIMOTSUKI_KAEDE_SHRINE`). Decided in [brainstorm-shrine-areas.md](brainstorm-shrine-areas.md).

`TODO(design)`: how many shrines the whole game has, and where.
