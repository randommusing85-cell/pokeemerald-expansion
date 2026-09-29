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
| Hamakaze (+ Kashiwagi house, lab) | [hamakaze.md](locations/hamakaze.md) | **Built** on a placeholder layout (redraw it in Porymap any time). Still to do: Haru's quest step 1 (`QUEST_HARU_MAP`, when he asks is `TODO(design)`); the connection north to Route 1; a new game starting here (or in the prologue) |
| Route 1 | [route-1.md](locations/route-1.md) | Trainers (Lv 5-8), wild table (Eien Poochyena ~20%), the professor's Poochyena research (`QUEST_RESEARCH_POOCHYENA`) |
| Route 1 shrine (own small map) | [route-1.md](locations/route-1.md) | Torii, komainu, the tablet (lore page; counts for Kaede's quest), grass with more Eien Poochyena |
| Shimotsuki (+ gym, Pokémon Center, Mart) | [shimotsuki.md](locations/shimotsuki.md) | Akira shows the gym; gym 1 (Fuyumi: Spheal, Bergmite Lv 13-14); Akira's quest step 1 (`QUEST_AKIRA_PRACTICE`); Nami's first meeting just after gym 1 (end of the slice) |
| Kaede's shrine in Shimotsuki (own small map) | [shimotsuki.md](locations/shimotsuki.md) | Kaede's cameo (sweeping, one blunt line); her grandmother |

Once the shrine maps exist, also:

- **Eien Poochyena's evolution** into Eien Mightyena: one `EVO_LEVEL` 18 entry with
  `IF_IN_MAP` per shrine map, in `src/data/pokemon/species_info/eien_families.h`
  (`variants.md`, "Shrine areas").
- **Thin-place list**: add the shrine maps (and later the door mountain) to `sThinPlaceMaps`
  in `src/eien_places.c`.
- Fill each map's `MAP_...` constant into its location doc.

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
  name and look; Tetsu's and Ren's placement.
- **Progression:** gym leaders 2-8, the level curve past gym 1, badge gates, field moves
  without HMs (`progression.md`).
- **Species:** evolved forms of the three starters; more Eien variants (5-10 total planned);
  Eien Mightyena's dex entry.
- **Quests:** point thresholds, the letter trigger rule, remaining chains' details
  (`side-quests.md`).
- **Kaede:** the tale's text (the stone dogs on aurora nights), her finale lines, her letters,
  whether the League cares about her tales, the grandmother's name, the charm item.
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
- Full test suite: 5,407 passed, 0 failed at the handoff.

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
