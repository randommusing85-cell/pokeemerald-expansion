# Shimotsuki

- **Map(s):** `MAP_SHIMOTSUKI` (town), `MAP_SHIMOTSUKI_GYM`, `MAP_SHIMOTSUKI_POKEMON_CENTER_1F`,
  `MAP_SHIMOTSUKI_MART`, `MAP_SHIMOTSUKI_KAEDE_SHRINE` (its own small map), and the lake path
  `MAP_EIEN_ROUTE2`. Placeholder layouts; see **Maps** below.
- **Type:** town
- **Connects to:** Route 1 to the south; the lake path (`MAP_EIEN_ROUTE2`, a placeholder name)
  to the north, where Nami is met.

Decided in [brainstorm-shimotsuki.md](../brainstorm-shimotsuki.md).

## Purpose

The first gym town. Akira shows him his mother's gym; he earns the first badge. Kaede's
shrine is here: a shrine area, where Eien Poochyena can evolve, and where Kaede's quest chain
starts in the second milestone.

## Look

A snowy inland town ("frost month"). Tilesets: `gTileset_General` + `gTileset_EienTown`
(houses, Pokémon Center, Mart, Gym). Music (placeholders): Lavaridge's theme for the town (in
this engine Lavaridge's map plays `MUS_OLDALE`), the gym theme in the gym, Mt. Pyre's at Kaede's
shrine (like Route 1's shrine), Route 101's on the lake path. `TODO(design)`: landmarks, the real
tracks, and a quiet track for Nami's scene (it plays the lake path's music for now).

## Story beats here

Act 1 beats 5-6 in [story-outline.md](../story-outline.md).

1. **Akira shows the gym:** Akira waits at the south entrance. He walks him to the gym door
   and points out the Pokémon Center on the way. This sets `STORY_SHIMOTSUKI`; the gym is shut
   until then (the scene is unavoidable on entering).
2. **Gym 1:** two gym trainers, a gym guide, then Fuyumi. Winning gives the Hoarfrost Badge and
   TM07 Hail
   and sets `STORY_BADGE_1`.
3. **Akira's practice battle** (his step 1, optional): at the town's north edge on his way out,
   only if you talk to him.
4. **Nami** (beat 6, the lake path north of town): see `MAP_EIEN_ROUTE2` below. The end of the
   first milestone.

## NPCs and events

| NPC / event | Where | Visible when | Says / does |
| --- | --- | --- | --- |
| Akira | the south entrance, then the gym door | arriving (`STORY_ROUTE_1`) | Walks him to the gym, points out the Pokémon Center |
| Akira | the north edge | after gym 1, until his battle | Practice battle if talked to; afterwards a short line about watching League matches with his mum |
| Gym guide | inside the gym door | always | Explains Ice; points at Route 1's Eien Poochyena |
| Locals | around town | always | A snow shoveller, a kid by the gym, an older person by the Pokémon Center. Plain lines; the kid sets up Fuyumi's softer side ("She makes the best stew in town"), the older person points east to the shrine |
| Kaede (cameo) | her shrine | first milestone | Sweeping. "If you're here to pray, the box is on the left. If not, you're in the way." |
| Kaede's grandmother | her shrine | always | Small talk about the old days. `TODO(design)`: repeating the evolution rule waits for milestone 2 |
| Kaede | her shrine | after gym 1, second milestone | First meeting: reading the shrine's tablet; asks about the Route 1 tablet; explains the stone dogs grow at their post. Starts her tablet quest ([side-quests.md](../side-quests.md)) |
| Kaede, aurora night | her shrine | Act 3, her quest step 2 | The stone dogs wake under the aurora; a wild double battle beside her; Froslass joins her ([side-quests.md](../side-quests.md)) |
| Closed gym | the gym door | Act 3, after Fuyumi's death | A sign on the closed gym; Kaede says one plain line about the gym being dark now; a townsperson line or two |

## Trainers

The gym trainers are locals at their jobs, like Route 1's: two new trainer classes, ICE FISHER
and SHOVELER (`TRAINER_CLASS_ICE_FISHER` / `_SHOVELER` in `include/constants/trainers.h`;
"SNOW SHOVELER" didn't fit the 12-letter class name). Their names are placeholders
(`TODO(design)`). Both use the snow trainer overworld sprite (`OBJ_EVENT_GFX_EIEN_SNOW_TRAINER`);
their battle pics reuse the Fisherman and Picnicker for now.

| Trainer | Class | Team (levels) | Notes |
| --- | --- | --- | --- |
| Gym trainer 1 (TOMO) | Ice Fisher | Snover Lv 9 | A short line about the cold |
| Gym trainer 2 (SAYA) | Shoveler | Snorunt Lv 10 | A short line about the cold |
| Fuyumi | Leader | Spheal Lv 13 (Water Gun, Powder Snow, Defense Curl, Rollout), Bergmite Lv 14 (Rock Tomb, Powder Snow, Curse, Harden) | Stern veteran. Water Gun covers Eien Torchic; Rock Tomb covers Eien Torchic and Froakie; Eien Poochyena resists Rock Tomb. The Hoarfrost Badge and TM07 Hail |
| Akira (practice) | Rival | His starter Lv 14 (the one strong against the player's), Starly Lv 11 | Optional; one trainer entry per starter he took |

Trainer ids: `TRAINER_EIEN_FUYUMI` (863) and `TRAINER_EIEN_AKIRA_PRACTICE_FROAKIE` (862) take the
last 2 spare slots. The others reuse vanilla Hoenn slots Eien never reaches (no rematches, used
only by their own vanilla map), aliased in `include/constants/opponents.h`:
`TRAINER_EIEN_SHIMOTSUKI_GYM_1` / `_GYM_2` (Allen, Tiana: Route 102) and
`TRAINER_EIEN_AKIRA_PRACTICE_TORCHIC` / `_BULBASAUR` (Rick: Route 102, Darian: Route 104). Their
blocks in `src/data/trainers.party` are replaced. Further trainers will need the same.

## Flags and vars

| Name | Set when | Checked by |
| --- | --- | --- |
| `VAR_EIEN_STORY` = `STORY_SHIMOTSUKI` | Akira shows him the gym | The journal |
| `VAR_EIEN_STORY` = `STORY_BADGE_1` | He beats Fuyumi | The journal |
| `FLAG_BADGE01_GET` | He beats Fuyumi | The badge (vanilla's first-badge flag, same meaning) |
| `FLAG_RECEIVED_TM_HAIL_EIEN` | Fuyumi gives TM07 | Her script (a full bag retries the TM when he talks to her again) |
| `QUEST_AKIRA_PRACTICE` (quest table) | Opened when he talks to Akira after gym 1, done when he wins | The journal; Akira's object (hidden once done); closes at the tournament |
| `VAR_EIEN_AKIRA_STARTER` | The lab: the species of the starter Akira took | Which practice-battle entry he uses (and his later battles) |
| `VAR_EIEN_SCENE` = 1 | Nami's scene, across the warp to the far shore; back to 0 at its end | The lake path's frame script (a scene that crosses a warp) |
| `VAR_EIEN_STORY` = `STORY_MET_NAMI` | Nami leaves the far shore | The journal; the end of the first milestone |
| `FLAG_AURORA_TONIGHT` | Kaede says come back tonight (Act 3, her step 2); cleared after the aurora-night battle | `IsAuroraNight` (`src/eien_aurora.c`): the aurora weather and its battle effect |
| `FLAG_AURORA_NIGHTS` | The end of Kaede's step 2 | `IsAuroraNight`: aurora nights come back at random from then on |

## The lake path (`MAP_EIEN_ROUTE2`, placeholder name)

A small map just north of Shimotsuki: a snowy path ending at a frozen lake. It becomes the
start of the next route later (`TODO(design)`: its name and the rest of the route).

- **Nami's meeting:** Celebi flickers and drops at the lake's edge. Nami arrives on Lapras: "It's
  cold. Get on." A fade, then the far shore at a small shelter, where Celebi recovers. She says
  a little (her name, that she's heading the same way) and leaves. No battle. Sets
  `STORY_MET_NAMI`, then a short end-of-milestone message. Music placeholder: a quiet track.
  Her lines are drafts (`TODO(design)`).
- The fading's first appearance; not explained.
- The lake is frozen at the edges with open dark water in the middle, which Lapras swims. On
  the map it's plain water for now (`TODO(art)`: an ice-rim tile). Before gym 1 the path is open
  but nothing happens there.

## Maps

All placeholders, hand-made; redraw them in Porymap any time.

- **Town:** 24x26 (`data/layouts/Shimotsuki/`, `gTileset_General` + `gTileset_EienTown`). The gym
  at the top middle (door 11,7), two houses beside it (not enterable), the Pokémon Center
  (door 5,15) and Mart (door 19,15) below, a town sign (14,22). The north gap (x 16-19) is a
  connection to the lake path, beside the gym rather than above it. The south edge (x 10-13,
  row 25) is south-arrow snow: Route 1's north arrows and the town's south arrows are warps
  (different secondary tilesets, the same reason as Route 1's shrine), each side landing on the
  other's middle tile. The east edge at rows 18-19 is east-arrow snow to Kaede's shrine.
- **Gym:** vanilla Rustboro gym layout (`LAYOUT_RUSTBORO_CITY_GYM`), Ice only in the text.
  Fuyumi at the back, the two trainers on the way, the guide by the door, two statue signs.
- **Pokémon Center and Mart:** vanilla layouts. The Center sets the respawn
  (`HEAL_LOCATION_SHIMOTSUKI`, outside its door); it has no 2F, so its stairs go nowhere.
- **Kaede's shrine:** shares Route 1's shrine layout (`LAYOUT_EIEN_ROUTE1_SHRINE`); its west
  arrows lead back to the town's east edge. Kaede sweeps (walking in place) on the path; her
  grandmother stands by the grass. Its tablet stays "too worn to read" until Kaede reads it to
  him in milestone 2; its text is about the stone dogs on aurora nights, setting up her step 2
  (`TODO(design)`: the text itself, and its bit in `QUEST_KAEDE_TABLETS`).
- **Lake path:** 24x22 (`data/layouts/EienRoute2/`, town tileset), connected below the town.
  The lake fills the middle-west (rows 6-13); the shelter (a house, not enterable) on the far
  shore; a path round the east side back to the town. Nami's trigger is row 16.

## Wild Pokémon

Kaede's shrine grass, Lv 9-12, so an Eien Poochyena can reach Lv 18 by battling there. Rates are
the slot sums in `src/data/wild_encounters.json` (`gShimotsuki_KaedeShrine`, `_Night`); morning and
evening use the day table.

| Area | Day | Night |
| --- | --- | --- |
| Kaede's shrine grass | Eien Poochyena 90%, Duskull 10% | Eien Poochyena 60%, Duskull 40% |

The Mart's stock is a placeholder (Poké Ball, Potion, Antidote, Paralyze Heal, Awakening,
Ice Heal, Escape Rope; `TODO(design)`).

## Screenshot check

Played through with the mGBA harness (from the lab, warped to Route 1's north end, then on
foot); shots in `design/art/shimotsuki/`.
- `1_akira_welcome.png`, `2_akira_center.png`, `3_akira_gym.png`: Akira meets him at the south
  edge, points out the Pokémon Center, and walks him to the gym door.
- `4_gym_trainer.png`: the first gym trainer spots him.
- `5_fuyumi.png`: Fuyumi's intro. `6_badge.png`, `7_tm_hail.png`: the badge, then TM07. For
  these two, Fuyumi's team was lowered to Lv 2 in a local build so the harness could win; the
  committed team is as in the table above.
- `8_pokemon_center.png`, `9_mart.png`: the nurse and the Mart.
- `10_kaede.png`, `11_grandmother.png`: Kaede's line and her grandmother at the shrine.
- `12_akira_practice.png`: Akira at the north edge after the badge (the story var set to
  `STORY_BADGE_1` in the harness); talking starts the battle.
- `13_lake_path.png` to `17_milestone_end.png`: the lake path, Celebi flickering out, Nami on
  Lapras ("It's cold. Get on."), the far shore where Celebi comes back, and the end message.
- After rounds 3-4: `18_ice_fisher.png` (the new class), `19_shrine_wild.png` and
  `20_shrine_thin_place.png` (a wild Eien Poochyena in Kaede's shrine grass, with the thin-place
  message), `21_lake_line.png` (his line at the lake), `22_whiteout_home.png` and
  `23_husband_heals.png` (a white-out before Shimotsuki: back home, healed). `6_badge.png` now
  shows the Hoarfrost Badge.
- `layout.png`, `lake_path_layout.png`: the layouts.
