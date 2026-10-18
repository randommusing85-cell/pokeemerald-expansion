# Shimotsuki

- **Map(s):** `MAP_SHIMOTSUKI` (town), `MAP_SHIMOTSUKI_GYM`, `MAP_SHIMOTSUKI_POKEMON_CENTER_1F`,
  `MAP_SHIMOTSUKI_MART`, `MAP_SHIMOTSUKI_KAEDE_SHRINE` (its own small map). Placeholder layouts;
  see **Maps** below.
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
(houses, Pokémon Center, Mart, Gym). Music (placeholders): Lavaridge's theme for the town, the
gym theme in the gym. `TODO(design)`: landmarks, the real tracks.

## Story beats here

Act 1 beats 5-6 in [story-outline.md](../story-outline.md).

1. **Akira shows the gym:** Akira waits at the south entrance. He walks him to the gym door
   and points out the Pokémon Center on the way. This sets `STORY_SHIMOTSUKI`; the gym is shut
   until then (the scene is unavoidable on entering).
2. **Gym 1:** two gym trainers, a gym guide, then Fuyumi. Winning gives the badge and TM07 Hail
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
| Locals | around town | always | A snow shoveller, a kid by the gym, an older person by the Pokémon Center. Plain lines; one sets up Fuyumi's softer side ("She makes the best stew in town") |
| Kaede (cameo) | her shrine | first milestone | Sweeping. "If you're here to pray, the box is on the left. If not, you're in the way." |
| Kaede's grandmother | her shrine | always | Small talk about the old days. `TODO(design)`: repeating the evolution rule waits for milestone 2 |
| Kaede | her shrine | after gym 1, second milestone | First meeting: reading the shrine's tablet; asks about the Route 1 tablet; explains the stone dogs grow at their post. Starts her tablet quest ([side-quests.md](../side-quests.md)) |
| Kaede, aurora night | her shrine | Act 3, her quest step 2 | The stone dogs wake under the aurora; a wild double battle beside her; Froslass joins her ([side-quests.md](../side-quests.md)) |
| Closed gym | the gym door | Act 3, after Fuyumi's death | A sign on the closed gym; Kaede says one plain line about the gym being dark now; a townsperson line or two |

## Trainers

Names are placeholders (`TODO(design)`).

| Trainer | Class | Team (levels) | Notes |
| --- | --- | --- | --- |
| Gym trainer 1 | `TODO(design)` | Snover Lv 9 | A short line about the cold |
| Gym trainer 2 | `TODO(design)` | Snorunt Lv 10 | A short line about the cold |
| Fuyumi | Leader | Spheal Lv 13 (Water Gun, Powder Snow, Defense Curl, Rollout), Bergmite Lv 14 (Rock Tomb, Powder Snow, Curse, Harden) | Stern veteran. Water Gun covers Eien Torchic; Rock Tomb covers Eien Torchic and Froakie; Eien Poochyena resists Rock Tomb. Badge and TM07 Hail |
| Akira (practice) | Rival | His starter Lv 14 (the one strong against the player's), Starly Lv 11 | Optional; one trainer entry per starter he took |

The gym's and Akira's trainer entries reuse vanilla Hoenn trainer slots Eien never reaches
(noted in `include/constants/opponents.h`), since only 2 spare slots were left.

## Flags and vars

| Name | Set when | Checked by |
| --- | --- | --- |
| `VAR_EIEN_STORY` = `STORY_SHIMOTSUKI` | Akira shows him the gym | The journal |
| `VAR_EIEN_STORY` = `STORY_BADGE_1` | He beats Fuyumi | The journal |
| `FLAG_BADGE01_GET` | He beats Fuyumi | The badge (vanilla's first-badge flag, same meaning) |
| `QUEST_AKIRA_PRACTICE` (quest table) | Opened and done in the practice battle after gym 1 | The journal; closes at the tournament |
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

## Screenshot check

`TODO` once the maps exist.
