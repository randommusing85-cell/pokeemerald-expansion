# What's left to build (handoff)

State at the end of the previous chat. The milestone checklist in [README.md](README.md) is the
source of truth; this file groups what's left by what blocks it. Open design questions are
marked `TODO(design)` in the docs (`grep -rF 'TODO(design)' design`, about 90).

## 1. Blocked on maps (the user makes them in Porymap)

Hamakaze exists (a hand-made placeholder layout, see below); the rest don't yet. Each map
unlocks its scripting, which the location docs already describe. Maps needed for the first
milestone (prologue through gym 1):

| Map | Doc | Then build |
| --- | --- | --- |
| Prologue bedroom | [prologue-bedroom.md](locations/prologue-bedroom.md) | The accident, Palkia |
| Hamakaze (+ Kashiwagi house, lab) | [hamakaze.md](locations/hamakaze.md) | **Built** on a placeholder layout (redraw it in Porymap any time), with the research and Haru's map quest. Still to do: a new game starting here (or in the prologue) |
| Route 1 + its shrine | [route-1.md](locations/route-1.md) | **Built** on placeholder layouts: trainers, day/night wild tables, items, Haru's notes, the tablet, the warp north to Shimotsuki. Still to do: real music |
| Shimotsuki (+ gym, Pokémon Center, Mart), Kaede's shrine, Lake Usurai | [shimotsuki.md](locations/shimotsuki.md) | **Built** on placeholder layouts: Akira shows the gym, gym 1 with badge and TM07, Akira's practice (`QUEST_AKIRA_PRACTICE`), Kaede's cameo and her grandmother, Nami's meeting and the end-of-milestone message. Since then: the Hoarfrost Badge, Kaede's shrine wild table (Eien Poochyena, Duskull), the ICE FISHER and SHOVELER classes. Still to do: the tablet text, real music, an ice-rim tile for the lake |

| Route 2's mountain pass + roadside shrine | [route-2.md](locations/route-2.md) | Designed (brainstorm-route-2.md, brainstorm-route-2-trainers-wild.md): two maps, six trainers, wild tables, items. The four classes, the six trainers and Tomo's Old Rod are built. Needs the two maps (Porymap), Eien Hoothoot, the trainers' overworld sprites and lines; the lake's fishing table |
| Yunotaki (+ gym 2, Pokémon Center, Mart, inn) | [yunotaki.md](locations/yunotaki.md) | Designed (brainstorm-gym-2.md); needs maps, Ibuki's sprites, the Pilgrim class |

Open gaps found while building Shimotsuki:

- **White-out before the first Pokémon Center:** fixed; he wakes at the Kashiwagi house and her
  husband heals the team (`HEAL_LOCATION_HAMAKAZE`).
- **Trainer slots:** none spare now. Further trainers reuse vanilla Hoenn slots Eien never
  reaches, aliased in `include/constants/opponents.h` (four so far).

## 2. Buildable now, without maps

- **Battle sprites for Haru and Nami** (later): make them like Akira's and Fuyumi's with
  `tools/eien_npcs/trainer_pic_drafts.py` (add an entry to its `CHARACTERS`).
- **Journal note for the aurora**: the journal explains the aurora the first time he meets it
  (`game-bible.md`, Eien weather and terrain). Text `TODO(design)`.
- **Kaede as a battle partner** (Act 3): her `PARTNER_` entry in
  `src/data/battle_partners.party` once her aurora-night levels are decided; her scene swaps
  Celebi's follower slot for hers and back.

## 3. Design still open (the big ones)

- **Story:** Act 2 and Act 3 locations and most beats (`story-outline.md`); the faction's
  look (named: the Eien Survey, true name Tokoyo); Tetsu's and Ren's placement.
- **Progression:** gym leaders 2-8, the level curve past gym 1, badge gates, field moves
  without HMs (`progression.md`).
- **Species:** the evolved starters and Eien Hoothoot are designed (`variants.md`), not built; more Eien variants (5-10 total planned);
  Eien Mightyena's dex entry.
- **Quests:** point thresholds, the letter trigger rule, remaining chains' details
  (`side-quests.md`).
- **Kaede:** the tale's text (the stone dogs on aurora nights), her finale lines, her letters,
  whether the League cares about her tales, the charm item.
- **Weather and terrain:** exact battle messages; the aurora night palette (needs a map);
  how often aurora nights come back (`AURORA_NIGHT_CHANCE`, 1 in 4 for now).
- **Nami's** aurora-night warm scene: a different night from Kaede's, or linked.

## 4. Done so far (for orientation)

- Hero: male only, new hairstyle on every sprite (`tools/eien_hero/`).
- Tilesets: snow/coast/shrine/town, credited; doors and tree-top layering.
- Quest table in the save file with script commands (`src/eien_quests.c`, tests in
  `test/eien_quests.c`); journal screen with three tabs (`src/eien_journal.c`).
- Species: Eien Torchic, Bulbasaur, Froakie, Poochyena, Mightyena with full art
  (`tools/eien_species/`, `design/art/eien_*`); icon palette 6 for the starters.
- NPC overworld sprites incl. Kaede and her grandmother (`tools/eien_npcs/`); battle sprites
  for Kaede (front and back) and her grandmother.
- Thin-place battle effect (`STARTING_STATUS_THIN_PLACE`, `src/eien_places.c`, tests in
  `test/battle/starting_status/eien_thin_place.c`).
- Aurora nights: the map weather `WEATHER_AURORA` (a pulsing night tint) and its battle effect
  `STARTING_STATUS_AURORA` (Rainbow for both sides), `src/eien_aurora.c`, flags
  `FLAG_AURORA_TONIGHT` / `FLAG_AURORA_NIGHTS`, tests in
  `test/battle/starting_status/eien_aurora.c`. Still to do once maps exist: Kaede's step-2 script
  sets `FLAG_AURORA_TONIGHT`, then clears it and sets `FLAG_AURORA_NIGHTS` after the battle
  (the flag alone would force an aurora every night); the aurora-only wild Eien Mightyena at
  thin places.
- Journal note for Eien Poochyena at Lv 18+ that didn't evolve (`FLAG_JOURNAL_POOCHYENA_NO_EVO`,
  `UpdateJournalNotes`, tests in `test/eien_journal.c`). The research page is now full; a lore
  tier will need scrolling.
- Battle sprites for Akira and Fuyumi (`TRAINER_PIC_EIEN_AKIRA`, `TRAINER_PIC_EIEN_FUYUMI`,
  AI drafts via `tools/eien_npcs/trainer_pic_drafts.py`, notes in `design/art/eien_akira/`
  and `design/art/eien_fuyumi/`).
- Follower NPCs switched on (`include/config/follower_npc.h`): Celebi can follow the hero, and
  a follower with a battle partner joins wild battles as a double (checked with the debug
  menu's Steven follower on Route 101, `design/art/follower_partner_wild_battle.png`).
- Hamakaze, the Kashiwagi house and the lab, with the first three story beats scripted
  (waking and Celebi, taken in and the journal, starters and Akira's battle); shots in
  `design/art/hamakaze/`. Fixed an engine check along the way: an early rival battle with
  `RIVAL_BATTLE_HEAL_AFTER` no longer turns on the FRLG tutorial (and Emerald's Lv 2
  Zigzagoon) in `src/battle_setup.c`.
- Shimotsuki (town, gym, Pokémon Center, Mart, Kaede's shrine) and the lake path on
  placeholder layouts: the first milestone's story plays through to `STORY_MET_NAMI`; shots in
  `design/art/shimotsuki/`. Kaede's shrine is a thin place with Eien Poochyena's second
  evolution entry.
- Route 1 and its shrine on placeholder layouts: four trainers, day/night wild tables
  (`OW_TIME_OF_DAY_ENCOUNTERS`), items, Haru's map quest and the professor's research (given in
  Hamakaze), the tablet's lore page (`QUEST_KAEDE_TABLETS`), research tiers set by battles
  (`UpdateResearchAfterBattle`), Eien Poochyena's shrine evolution; shots in
  `design/art/route1/`.
- Full test suite: 5,421 passed, 0 failed at the handoff.

## Working notes for the next chat

- Build `make -j$(nproc)`; tests `make check -j$(nproc)` (about 20 minutes; run in the
  background). A single group: `make check TESTS="Thin place"`.
- Screenshots: `tools/mgba_harness/run.py <script>` (`.claude/skills/screenshot/SKILL.md`).
  Scripts used last chat live in `build/harness_scripts/` (not committed; `build/` is local).
- Debug menu tricks: the species giver takes digits ones-first; "Start Debug Battle" is
  Party (2 down) → 11th item; a tag battle is Utilities → "Steven Multi" (needs a party:
  Party → Set Party first). Swap a pic temporarily in `src/data/debug_trainers.party` or
  `src/data/battle_partners.party` to test a sprite, then restore it.
- AI art drafts go through the Gemini proxy (`generativelanguage.googleapis.com`, models
  `gemini-3-pro-image`, `gemini-3.1-flash-image`); every AI-assisted asset is listed in
  `asset-credits.md`.
- Adding NPCs to `tools/eien_npcs/convert.py` regroups the shared palettes; compare the
  other NPCs' colors before committing.
