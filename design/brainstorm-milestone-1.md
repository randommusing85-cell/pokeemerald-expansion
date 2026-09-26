# Brainstorm: first milestone (prologue through gym 1)

Working notes (see `.claude/skills/brainstorm/SKILL.md`). Firm decisions move into the
design docs: `README.md` milestone, `progression.md`, `characters.md`, `story-outline.md`,
and a location doc per map.

**Promoted:** the decisions below are now in `README.md` (milestone), `game-bible.md`,
`characters.md`, `story-outline.md`, `progression.md`, `variants.md` and `locations/`.
Those docs are the source of truth; this file is the record of how we got there.

## Decided (from the story docs)

- Scope: prologue in our world → hometown (wakes in Eien, Celebi, Kashiwagi household,
  Haru, journal) → meet Akira → route 1 → first town and gym 1 (Fuyumi, Ice).
- Hero: player-named, fixed male; mostly silent; inner thoughts show his game knowledge.
- Celebi follows him on the map (not in the party) and can't battle.

## Decided (this brainstorm)

- **Prologue:** a small bedroom map in our world built from existing indoor tiles; he's
  playing a Pokémon game. The accident happens in text on a black screen, then Palkia.
- **First Pokémon:** Professor Kashiwagi offers three starters (Fire/Water/Grass) and he
  picks one; as a fan he recognizes them.
- **Gym 1 fairness:** route 1 always has a Pokémon that's good against Ice (e.g. Rock or
  Fighting near the mountain path), and Fuyumi's team is small (2 Pokémon), bulky rather
  than hard-hitting.
- **Fuyumi:** a stern veteran in the gym, softer at home with Akira.
- **Slice ending:** just after gym 1, Nami's first meeting (she helps him when he's lost).
- **Snow look:** find a community snow tileset now; credit it in `asset-credits.md`.
- **Town names:** hometown **Hamakaze** ("sea wind"), first town **Shimotsuki** ("frost month").
- **Regional variants:** Eien has its own variants of some existing Pokémon (not all), which
  can have different types.
- **Shinies are rare**, and both original Pokémon and the variants have shiny forms.
- **Variant count:** a handful for the whole game (5-10), 1-2 in the first milestone.
  (Now in tension with the starter choice; see below.)
- **Variant theme:** mostly "touched by the fading" (Pokémon living where the worlds are thin
  have shifted, toward Ghost/Psychic/Dark), with some adapted to the cold (Ice/Water).
- **Starters:** Eien variants of **Torchic, Bulbasaur and Froakie**.
- **Route 1's anti-Ice Pokémon** is an Eien variant with a Rock or Fighting type.
- **Shiny odds:** 1 in 4,096 (`SHINY_ODDS 16`). The Shiny Charm is a post-game reward.
- **Fuyumi's team:** Spheal and Bergmite (ace).
- **Variant budget:** the 9 starter variants are separate from the 5-10 other variants
  (about 15-19 in total).
- **Starter variant types:** Torchic line Fire/Ghost, Bulbasaur line **Grass/Psychic**,
  Froakie line Water/Ice. (Grass/Water was dropped: it beat both other starters and neither
  beat it back.) This restores the starter cycle; the route 1 Poochyena covers Bulbasaur's
  Ice weakness at gym 1.
- **Starter evolution:** first evolution raised to about Lv 18, so the milestone only needs
  the first stage of each.
- **Route 1 variant:** Poochyena, Rock/Dark, a shrine guardian dog (komainu) touched by the
  fading.
- **Starters in the story:** Akira takes the one strong against the player's; Haru takes the
  third (so Haru can be a tag-battle partner later).
- **Gym 1 moves:** each of Fuyumi's Pokémon carries one move that hits the Ice-resistant
  starters (e.g. a Water move on Spheal for Torchic). Exact moves to be checked against
  learnsets.
- **Variant naming:** "Eien Poochyena" (region name as the form label, like "Hisuian");
  some final forms may get their own names if the design calls for it.
- **Route 1:** coast near Hamakaze, turning into snowy fields, then a small shrine before
  Shimotsuki. Eien Poochyena is common (about 20%). 3-4 trainers.
- **Journal, first page:** a note to himself: "My name is ___. I'm from ___. If I start
  forgetting, read this." Mirrors the blank pages at the end.
- **Akira:** met at Kashiwagi's lab, battle right after picking starters. A second meeting
  in Shimotsuki, where he shows the player his mother's gym.

## Proposed defaults (not asked; change if wrong)

- **Celebi follower** uses the engine's follower NPC system (`include/follower_npc.h`) with
  Celebi's existing overworld sprite. No engine changes needed.
- **Level curve:** route 1 wild Pokémon Lv 2-5; route trainers Lv 5-8; gym trainers Lv 9-11;
  Fuyumi's ace about Lv 13-14.
- **Palkia** has an overworld sprite in the engine already (`graphics/pokemon/palkia/`).

## Leaning

**Overworld sprites (proposed, awaiting the user's pick).** From the FRLG-style NPC megapack
(`tools/fetch_assets.py frlg_npc_megapack`); ids refer to the numbered contact sheet, file names
are the pack's. Main characters avoid canon faces and trainer-class sprites used by generic
trainers.

| Character | Pick | Alternative | Credit (from the pack's readme) |
| --- | --- | --- | --- |
| Haru | HGSS `NPC_YoungMan` | RSE `trainer_ACETRAINER_M` | HGSS-in-FR style: Delta231, Mimi, M.vit, Kimoras |
| Akira | FRLG `trainer_BIRDKEEPER` | HGSS `trainer_YOUNGSTER` | Bird Keeper: Spherical Ice |
| Nami | FRLG `trainer_YOUNGCOUPLE_F` (red hair) | HGSS `NPC_YoungWoman` | Young Couple: Kalarie |
| Prof. Kashiwagi | HGSS `NPC_MidageWoman` | RSE `trainer_REPORTER_F` | HGSS set as above |
| Her husband | HGSS `NPC_Shopkeeper` (apron) | HGSS `NPC_MidageMan` | HGSS set as above |
| Fuyumi | HGSS `trainer_ACETRAINER_F` (hair bun) | RSE `trainer_EXPERT_F` | HGSS set as above |
| Hamakaze folk | HGSS `trainer_FISHERMAN`, `trainer_SAILOR`, RSE `Hoenn NPC 06`, `trainer_SCHOOLBOY` | | HGSS set; RSE-style: Poffin_Case |
| Shimotsuki folk | DPPt `trainer_ACETRAINERSNOW_M`, `trainer_WORKER`, RSE `trainer_POKEFAN_M`, DPPt `trainer_SOCIALITE` | | DPPt set: `TODO` (not named in the readme) |

- **Player:** keep the engine's Brendan for now: it has every sheet the player needs (walk,
  run, bike, surf, fishing, field moves). `TODO(design)`: a custom look for the isekai hero.
- **Nurse and Mart clerk:** the engine's own Emerald sprites.
- **Celebi:** the engine's Pokémon overworld sprite (`OBJ_EVENT_GFX_SPECIES(CELEBI)`).
- No female lab-coat sprite exists in the pack; the professor pick is a mother figure.

## Open questions

1. Fakemon: none, a few, or later.
2. How sprites for variants (and any fakemon) get made. Tested on Eien Poochyena
   (`design/art/eien_poochyena/README.md`): AI front sprites work after light cleanup; back
   sprites and icons need hand work.
3. Eien Poochyena's final look (the test design is a proposal).

## Gaps and tensions

- **Sprites are the milestone's biggest art cost:** 4 variant Pokémon, each needing a front
  sprite (two animation frames), back sprite, icon, and normal + shiny palettes within GBA
  limits (16 colors per palette including transparency).
- **The milestone needs 4 new variant sprite sets:** the three starters' first stages and
  Eien Poochyena, each with a shiny palette.
- **Ice as gym 1.** Grass starters are weak to Ice; Fire, Fighting, Rock and Steel beat it.
  The starter trio and route 1's wild Pokémon decide whether gym 1 is fair for every pick.
- **No snow tileset in the engine.** Vanilla Emerald and FRLG have no snowy overworld tiles
  (only ice cave floors). A snow-country look needs a community tileset (credited in
  `asset-credits.md`) or custom art.
- **Variant art cost.** Each variant needs a new front sprite, back sprite, icon and shiny
  palette, plus species data (types, stats, moves, evolutions, dex entry). That's close to
  the art cost of a fakemon.
- **Shiny odds today:** `SHINY_ODDS 8` in `include/constants/pokemon.h`, i.e. 1 in 8,192
  (the Gen 3 rate). Modern games use 1 in 4,096.
- **Grass/Flying starters** take 4x damage from Ice; avoid one if gym 1 is Ice.
- **Celebi can't battle**, so he needs a battling Pokémon before the first trainer fight.

## Parked ideas

_(none yet)_

## Rejected

_(none yet)_
