# Route 2: the mountain pass

- **Map(s):** a new route map north of Lake Usurai, made in Porymap (placeholder constant
  `MAP_EIEN_ROUTE2_PASS`); the roadside shrine is its own small map (placeholder
  `MAP_EIEN_ROUTE2_SHRINE`). The lake map keeps its constant `MAP_EIEN_ROUTE2`
  but is named LAKE USURAI on screen ([shimotsuki.md](shimotsuki.md)). This map takes the
  "ROUTE 2" region-map section when it's built.
- **Type:** route
- **Connects to:** south: Lake Usurai, joined at its north-east by the path round the lake's
  east side (reachable on foot any time; the far shore is only reached through Nami's scene).
  North: Yunotaki ([yunotaki.md](yunotaki.md)).

Decided in [brainstorm-route-2.md](../brainstorm-route-2.md). Named in [brainstorm-names.md](../brainstorm-names.md): routes are numbered, landmarks named.

## Purpose

The climb from Shimotsuki's snow country to Yunotaki and gym 2. The fading shows
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
   People in field gear (the Eien Survey) rope it off and warn others away, as if they've seen it before. One of
   them, a young researcher named Hinata, stays and chats with him, fascinated by Celebi. He only learns
   later who they were.
4. **A quieter stretch:** the side path to the roadside shrine and its tablet; the Hoothoot
   grass, eerie at night.
5. **Nami** is seen far off crossing the lake on Lapras (no words). `TODO(design)`: from where
   on the route (the lake is south of it).
6. Yunotaki.

## NPCs and events

| NPC / event | Where | Visible when | Says / does |
| --- | --- | --- | --- |
| Haru | near the start | once, after gym 1 | Takes his map notes back, gives the Town Map |
| The thinning patch | midway, main path | first time | The fading's first appearance (see above) |
| The Eien Survey (field gear) | at the patch | the scene | Rope off the patch, warn people away |
| Hinata (young woman, researcher) | at the patch | the scene | Friendly, curious about Celebi. Returns at the tournament, clearly on the other side |
| Roadside tablet | the roadside shrine | always | About thin places (direction: "where the snow stops, the gate is near"). `TODO(design)`: the text; a bit in `QUEST_KAEDE_TABLETS` |

## Trainers

A mix of locals at their jobs and pilgrims climbing to Yunotaki's falls to train (Fighting-leaning,
previewing the gym). Lv 12-17 (default). `TODO(design)`: count, teams, names (placeholders
when built).

| Trainer | Class | Team (levels) | Notes |
| --- | --- | --- | --- |
| Woodcutter | `TODO(design)` | | Local |
| Inn porter | `TODO(design)` | | Local, carrying baskets up to the inn |
| Charcoal burner | `TODO(design)` | | Local |
| Pilgrims | `TODO(design)` | | Headed to the falls; previews the Fighting gym |

## Wild Pokémon

Lv 10-15 (default). Eien Hoothoot in the grass near the town end, the route's one notable
Pokémon: about 10% by day, 30% at night ([variants.md](../variants.md)). It evolves here: Lv 20+
at night on this route. `TODO(design)`: the rest of the tables.

## Items

`TODO(design)`.

## Flags and vars

| Name | Set when | Checked by |
| --- | --- | --- |
| `TODO` | Haru's handover; the patch scene; the tablet | |

## Screenshot check

`TODO` once the map exists.
