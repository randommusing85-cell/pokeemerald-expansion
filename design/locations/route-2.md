# Route 2: the mountain pass

- **Map(s):** two new route maps north of Lake Usurai, made in Porymap: a lower snowy forest
  and an upper stretch of steam vents and rock (placeholder constants `MAP_EIEN_ROUTE2_LOWER`
  and `MAP_EIEN_ROUTE2_UPPER`), each with its own wild tables; the roadside shrine is its own
  small map (placeholder `MAP_EIEN_ROUTE2_SHRINE`). The lake map keeps its constant `MAP_EIEN_ROUTE2`
  but is named LAKE USURAI on screen ([shimotsuki.md](shimotsuki.md)). The two pass maps take
  the "ROUTE 2" region-map section when they're built.
- **Type:** route
- **Connects to:** south: Lake Usurai, joined at its north-east by the path round the lake's
  east side (reachable on foot any time; the far shore is only reached through Nami's scene).
  North: Yunotaki ([yunotaki.md](yunotaki.md)).

Decided in [brainstorm-route-2.md](../brainstorm-route-2.md). Named in [brainstorm-names.md](../brainstorm-names.md): routes are numbered, landmarks named.
Trainers, wild tables, items and music decided in
[brainstorm-route-2-trainers-wild.md](../brainstorm-route-2-trainers-wild.md).

## Purpose

The climb from Shimotsuki's snow country to Yunotaki and gym 2. The fading shows
itself for the first time, and the villains appear, helping. The next Eien variant, Eien
Hoothoot, lives here: the answer to the Fighting gym, as Eien Poochyena answered the Ice gym.

## Look

Snowy forest at the lake end, climbing to steam vents and bare rock near the town. Snow
weather. A small optional roadside shrine off a side path. `TODO(design)`: tilesets (the
steam vents and rock may need new tiles). Music (vanilla placeholders): Route 119's forest
track on the lower map, Mt. Chimney's ascent on the upper map; the patch scene plays silence.

## Story beats here

Act 1 beat 7 in [story-outline.md](../story-outline.md). In order, south to north:

1. **Haru catches up** near the start, for his map notes, and gives him the Town Map. This
   closes Haru's step 1 ([side-quests.md](../side-quests.md)).
2. **Lower map trainers:** the woodcutter, the porter, the first pilgrim.
3. **The thinning patch** (at the end of the lower map, on the main path; an unavoidable scene as he passes, then he
   walks around it): the snow stops falling, colours drain, Celebi reacts, Pokémon flee it.
   People in field gear (the Eien Survey) rope it off and warn others away, as if they've seen it before. One of
   them, a young researcher named Hinata, stays and chats with him, fascinated by Celebi. He only learns
   later who they were. The grass around the patch is empty: Pokémon flee it.
4. **The upper map, a quieter stretch** by the vents: the charcoal burner at his kiln, the
   second pilgrim and the pilgrim pair; the side path to the roadside shrine and its tablet;
   the Hoothoot grass, eerie at night.
5. **Nami** is seen far off crossing the lake on Lapras (no words). `TODO(design)`: from where
   on the route (the lake is south of it).
6. Yunotaki.

## NPCs and events

| NPC / event | Where | Visible when | Says / does |
| --- | --- | --- | --- |
| Haru | near the start | once, after gym 1 | Takes his map notes back, gives the Town Map. No battle |
| The thinning patch | end of the lower map, main path | first time | The fading's first appearance (see above) |
| The Eien Survey (field gear) | at the patch | the scene | Rope off the patch, warn people away |
| Hinata (young woman, researcher) | at the patch | the scene | Friendly, curious about Celebi. Returns at the tournament, clearly on the other side |
| Roadside tablet | the roadside shrine | always | About thin places (direction: "where the snow stops, the gate is near"). `TODO(design)`: the text; a bit in `QUEST_KAEDE_TABLETS` |

## Trainers

Six trainers: locals at their jobs and pilgrims climbing to Yunotaki's falls to train
(Fighting-leaning, previewing the gym), Lv 12-17. Four new classes: WOODCUTTER, PORTER,
CHARCOALER and PILGRIM (shared with gym 2). Gym 2's Pokémon (Meditite, Throh, Sawk) stay
unique to the gym and the wild. Vanilla level-up moves. Names are placeholders when built
(`TODO(design)`), and so are their lines. No spare trainer slots: these reuse vanilla Hoenn
slots (`include/constants/opponents.h`).

| Map | Trainer (placeholder name) | Class | Team (levels) | Notes |
| --- | --- | --- | --- | --- |
| Lower | Woodcutter (TAKESHI) | Woodcutter | Pineco Lv 12, Timburr Lv 13 | Local |
| Lower | Inn porter (JIRO) | Porter | Machop Lv 14 | Local, carrying baskets up to the inn |
| Lower | Pilgrim 1 (KOJI) | Pilgrim | Tyrogue Lv 14 | Sets up the Fighting theme early |
| Upper | Charcoal burner (SABURO) | Charcoaler | Slugma Lv 15, Hoothoot Lv 15 | By the vents (his kiln needs the heat). He works the kilns through the night: the owls up here look see-through at night. Sets up Eien Hoothoot |
| Upper | Pilgrim 2 (MIKA) | Pilgrim | Mankey Lv 15, Machop Lv 16 | |
| Upper | Pilgrim pair (RYO & YUI) | Pilgrim (double battle) | Mankey Lv 16, Makuhita Lv 17 | Fighting double play before Throh and Sawk |

**Built** (not yet placed: the maps don't exist): the classes (`TRAINER_CLASS_WOODCUTTER` /
`_PORTER` / `_CHARCOALER` / `_PILGRIM`, `include/constants/trainers.h`, names in
`src/battle_main.c`) and the trainers `TRAINER_EIEN_ROUTE2_WOODCUTTER`, `_PORTER`,
`_PILGRIM_1`, `_CHARCOALER`, `_PILGRIM_2`, `_PILGRIM_PAIR` (the double battle: place it with
`trainerbattle_double`). They take vanilla ANDREW, MARCOS (Route 103), HUEY, EDMOND (Route
109), BRENT and DONALD (Route 119). Battle pics reuse vanilla ones for now: Hiker
(woodcutter), Ruin Maniac (porter, a big pack), Kindler (charcoal burner), Black Belt
(pilgrim 1, the pair) and Battle Girl (pilgrim 2). Overworld sprites: `TODO(design)`.

## Wild Pokémon

Day and night tables on each map (`OW_TIME_OF_DAY_ENCOUNTERS`; morning and evening use the day
table). Eien Hoothoot is only on the upper map, the route's one notable Pokémon
([variants.md](../variants.md)); it evolves at Lv 20+ at night on the upper map only. Rates
will land near these numbers on the GBA's fixed slots.

| Map | Day | Night |
| --- | --- | --- |
| Lower (Lv 10-13) | Snorunt 30%, Swinub 30%, Pineco 25%, Starly 15% | Snorunt 35%, Swinub 30%, Pineco 25%, Sneasel 10% (no Starly; it roosts) |
| Upper (Lv 12-15) | Geodude 30%, Numel 30%, Meditite 20%, Eien Hoothoot 10%, Machop 10% | Eien Hoothoot 30%, Geodude 25%, Numel 25%, Meditite 20% |

The grass around the thinning patch is empty.

## Items

| Item | Where | Hidden? |
| --- | --- | --- |
| Super Potion | Lower map | No |
| Great Ball | Lower map | No |
| Charcoal | Upper map | No |
| Revive | Upper map | No |
| Burn Heal | Upper map, by the vents | Yes |

## Flags and vars

| Name | Set when | Checked by |
| --- | --- | --- |
| `TODO` | Haru's handover; the patch scene; the tablet | |

## Screenshot check

`TODO` once the maps exist. Checked so far: a debug battle against the charcoal burner
("CHARCOALER SABURO", Slugma Lv 15) and the pilgrim pair as a double battle (Mankey Lv 16,
Makuhita Lv 17): `design/art/route2/trainer_battles.png`.
