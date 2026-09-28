# Shimotsuki

- **Map(s):** `MAP_...` `TODO`: town, gym, Pokémon Center, Mart, Kaede's shrine (its own small map)
- **Type:** town
- **Connects to:** Route 1. `TODO(design)`: the way on, where Nami is met.

## Purpose

The first gym town. Akira shows him his mother's gym; he earns the first badge. Kaede's
shrine is here: the first place Eien Poochyena can evolve (a shrine area, reachable right
after gym 1, about when it reaches Lv 18), and where Kaede's quest chain starts.

## Look

A snowy inland town ("frost month"). Tilesets: `gTileset_General` + `gTileset_EienTown`
(houses, Pokémon Center, Mart, Gym). `TODO(design)`: landmarks, music.

## Story beats here

Act 1 beats 5-6 in [story-outline.md](../story-outline.md). The first milestone ends just
after gym 1, when Nami helps him.

## NPCs and events

| NPC / event | Position (x,y) | Visible when | Says / does |
| --- | --- | --- | --- |
| Akira | `TODO` | arriving | Shows him his mother's gym |
| Nami | past the town `TODO` | after gym 1 | Helps him when he's lost or Celebi is struggling |
| Kaede | her shrine `TODO` | after gym 1 (`TODO(design)`: in the first milestone or not) | Starts her tablet quest ([side-quests.md](../side-quests.md)) |

## Trainers

| Trainer | Class | Team (levels) | Notes |
| --- | --- | --- | --- |
| Gym trainers | `TODO` | Lv 9-11 | `TODO(design)` |
| Fuyumi | Leader | Spheal, Bergmite (ace, Lv 13-14) | Stern veteran. Each Pokémon carries one move for the Ice-resistant starters (`TODO`: check learnsets) |

## Flags and vars

| Name | Set when | Checked by |
| --- | --- | --- |
| `VAR_EIEN_STORY` = `STORY_SHIMOTSUKI` | Akira shows him the gym | The journal |
| `VAR_EIEN_STORY` = `STORY_BADGE_1` | He beats Fuyumi | The journal |
| `QUEST_AKIRA_PRACTICE` (quest table) | Akira asks for a practice battle after gym 1 | The journal; closes at the tournament |

## Screenshot check

`TODO` once the maps exist.
