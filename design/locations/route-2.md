# Route 2 (placeholder name): the mountain pass

- **Map(s):** a new route map north of the lake path, made in Porymap (placeholder constant
  `MAP_EIEN_ROUTE2_PASS`); the roadside shrine is its own small map (placeholder
  `MAP_EIEN_ROUTE2_SHRINE`). The lake path itself stays `MAP_EIEN_ROUTE2`
  ([shimotsuki.md](shimotsuki.md)).
- **Type:** route
- **Connects to:** south: the lake path, joined at its north-east by the path round the lake's
  east side (reachable on foot any time; the far shore is only reached through Nami's scene).
  North: the hot-spring town ([onsen-town.md](onsen-town.md)).

Decided in [brainstorm-route-2.md](../brainstorm-route-2.md). `TODO(design)`: the route's name.

## Purpose

The climb from Shimotsuki's snow country to the hot-spring town and gym 2. The fading shows
itself for the first time, and the villains appear, helping. The next Eien variant, Eien
Hoothoot, lives here: the answer to the Fighting gym, as Eien Poochyena answered the Ice gym.

## Look

Snowy forest at the lake end, climbing to steam vents and bare rock near the town. Snow
weather. A small optional roadside shrine off a side path. `TODO(design)`: tilesets (the
steam vents and rock may need new tiles), music.

## Story beats here

Act 1 beat 7 in [story-outline.md](../story-outline.md). In order, south to north:

1. **Haru catches up** near the start, for his map notes, and gives him the Town Map. This
   closes Haru's step 1 ([side-quests.md](../side-quests.md)).
2. **Trainers** along the climb.
3. **The thinning patch** (midway, on the main path; an unavoidable scene as he passes, then he
   walks around it): the snow stops falling, colours drain, Celebi reacts, Pokémon flee it.
   People in field gear rope it off and warn others away, as if they've seen it before. One of
   them, a young researcher, stays and chats with him, fascinated by Celebi. He only learns
   later who they were.
4. **A quieter stretch:** the side path to the roadside shrine and its tablet; the Hoothoot
   grass, eerie at night.
5. **Nami** is seen far off crossing the lake on Lapras (no words). `TODO(design)`: from where
   on the route (the lake is south of it).
6. The hot-spring town.

## NPCs and events

| NPC / event | Where | Visible when | Says / does |
| --- | --- | --- | --- |
| Haru | near the start | once, after gym 1 | Takes his map notes back, gives the Town Map |
| The thinning patch | midway, main path | first time | The fading's first appearance (see above) |
| Faction members (field gear) | at the patch | the scene | Rope off the patch, warn people away |
| The young researcher (placeholder name) | at the patch | the scene | Friendly, curious about Celebi. Returns at the tournament, clearly on the other side |
| Roadside tablet | the roadside shrine | always | About thin places (direction: "where the snow stops, the gate is near"). `TODO(design)`: the text; a bit in `QUEST_KAEDE_TABLETS` |

## Trainers

A mix of locals at their jobs and pilgrims climbing to the falls to train (Fighting-leaning,
previewing the gym). Lv 12-17 (default). `TODO(design)`: count, teams, names.

| Trainer | Class | Team (levels) | Notes |
| --- | --- | --- | --- |
| Woodcutter | `TODO(design)` | | Local |
| Inn porter | `TODO(design)` | | Local, carrying baskets up to the inn |
| Charcoal burner | `TODO(design)` | | Local |
| Pilgrims | `TODO(design)` | | Headed to the falls; previews the Fighting gym |

## Wild Pokémon

Lv 10-15 (default). Eien Hoothoot in the grass near the town end, more common at night, the
route's one notable Pokémon. `TODO(design)`: the rest of the tables.

## Items

`TODO(design)`.

## Flags and vars

| Name | Set when | Checked by |
| --- | --- | --- |
| `TODO` | Haru's handover; the patch scene; the tablet | |

## Screenshot check

`TODO` once the map exists.
