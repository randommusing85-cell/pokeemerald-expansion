# Hanashiro

- **Map(s):** made in Porymap (placeholder constants `MAP_HANASHIRO`, `MAP_HANASHIRO_GYM`,
  `MAP_HANASHIRO_POKEMON_CENTER_1F`, `MAP_HANASHIRO_MART`; the castle and its grounds for Act 2).
  The gym's inside reuses Fortree's gym layout. Vanilla layouts can stand in.
- **Type:** town
- **Connects to:** west: Route 4 ([route-4.md](route-4.md)). `TODO(design)`: onward (Act 3).

Decided in [brainstorm-route-4-gym-4.md](../brainstorm-route-4-gym-4.md). Hanashiro (花城, "flower castle").

## Purpose

Gym 4 (Grass), the last of Act 1, and the tournament's host: Act 2 is held in the castle
grounds, so the disaster that kills Fuyumi and Hashimoto happens in a town the player knows.

## Look

A castle town like Hirosaki: castle walls, cherry trees, moss gardens, and Aomori's apple
orchards around it. `TODO(design)`: tilesets, music.

## Story beats here

Act 1 beat 9 and Act 2 in [story-outline.md](../story-outline.md).

- **Yuki's heal-and-chat** (her step 0b, [side-quests.md](../side-quests.md)) at the Pokémon
  Center: she teases him about the bridge. No battle.
- **Gym 4: Mamoru** (守, "to protect"), the castle's head gardener. He keeps the cherry trees and
  moss gardens; quiet and exact; he watches the trees for the fading. Two apprentice
  gardeners, then Mamoru. Winning gives the Blossom Badge and TM19 Giga Drain. After the badge he
  talks about Route 4's orchard (`TODO(design)`: the lines).
- **The tournament** (Act 2), two days in the castle grounds: the beats are in
  [story-outline.md](../story-outline.md) (Act 2), decided in
  [brainstorm-tournament.md](../brainstorm-tournament.md). Day 1: round 1 (KAITO), the chain
  steps, a night at the inn. Day 2: Yuki, Nami's semi-final, the disaster (Tokoyo's thinning
  under the castle), Fuyumi's and Hashimoto's deaths at the stands, Minato's "We are Tokoyo."
  The League names Akira the winner. Mamoru survives, shaken; he helps with the aftermath and
  turns up once in Act 3.
- **The tournament's maps:** the castle grounds (the stands, the fields), the passage under the
  castle (the thinning), the inn. Made in Porymap; vanilla layouts can stand in.

## NPCs and events

| NPC / event | Where | Visible when | Says / does |
| --- | --- | --- | --- |
| Mamoru | the gym | always | See above |
| KAITO, Yuki, Nami | the tournament fields | Act 2 | His three matches (see Trainers) |
| Hinata | the grounds | the disaster | In Tokoyo's gear, leads the crowd out |
| Minato | the stands | after the disaster | "We are Tokoyo." |
| Yuki | the Pokémon Center | once, before gym 4 (`TODO(design)`: the trigger) | Teases him about the bridge |

## Trainers

| Trainer | Class | Team (levels) | Notes |
| --- | --- | --- | --- |
| Apprentice gardener 1 | `TODO(design)` | Grass Pokémon, Lv 27-29 | Names `TODO(design)` |
| Apprentice gardener 2 | `TODO(design)` | Grass Pokémon, Lv 27-29 | |
| Mamoru | Leader | Cherrim Lv 29, Dipplin Lv 30, Appletun Lv 32 | The town's two faces: blossoms and apples. Appletun is Grass/Dragon, so Ice answers it (a nod to Fuyumi's gym). `TODO(design)`: movesets, item |

The gym is Fortree's layout: its turnstiles read as orchard gates.

**The tournament** (Act 2):

| Trainer | Team (levels) | Notes |
| --- | --- | --- |
| KAITO | His Route 3 team grown, about Lv 30 (three or four Pokémon) | Round 1, day 1 |
| Yuki | Absol and her team, about Lv 32 (three or four) | Round 2, day 2. `TODO(design)`: the rest of her team |
| Nami | Lapras and her team, about Lv 34 (three or four) | The semi-final; broken off. `TODO(design)`: her team |
| Tokoyo members (2 + the Route 4 member) | Lv 30-33 | During the disaster. `TODO(design)`: teams |
| Akira | His evolved starter and team | Wins his semi-final on the next field (seen, not fought). `TODO(design)`: his opponent (a League trainer; Ren is a possible tie-in) |

## Flags and vars

| Name | Set when | Checked by |
| --- | --- | --- |
| `FLAG_BADGE04_GET` | He beats Mamoru | The badge |
| `TODO` | Yuki's chat | Runs it once |
| `STORY_*` steps (`include/constants/eien_story.h`) | The tournament's beats | The tournament's scenes |

## Screenshot check

`TODO` once the maps exist.
