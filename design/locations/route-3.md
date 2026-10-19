# Route 3 (placeholder name): the gorge road to the coast

- **Map(s):** two new maps, made in Porymap: the gorge (placeholder constant
  `MAP_EIEN_ROUTE3`) and the Eien Survey's cave, an old mine tunnel (placeholder
  `MAP_EIEN_ROUTE3_CAVE`, cave tileset).
- **Type:** route
- **Connects to:** west: Yunotaki's east exit ([yunotaki.md](yunotaki.md)). East: the cave, whose
  exit leads to Isaribi, the gym 3 port town ([isaribi.md](isaribi.md)).

Decided in [brainstorm-route-3.md](../brainstorm-route-3.md).

## Purpose

The road down from the mountains to the Sea of Japan coast, after gym 2. A quieter route: Yuki's
cameo, the Eien Survey seen again (helpful and organised), and the first sight of the door
mountain. The next Eien variant, Eien Wooper (Ground/Steel), lives here: the answer to gym 3, which is
Electric.

## Look

A river gorge running down toward the sea: rope bridges, snow melting into streams, the road
broken by the thaw. The cave is an old mine tunnel the Survey cleared, hung with lamps. Music
(vanilla placeholders): Route 120's track on the gorge, a cave theme in the tunnel.

## Story beats here

Act 1 beat 8 in [story-outline.md](../story-outline.md), between gym 2 and gym 3. In order, west to
east:

1. **The gorge:** the road is washed out by the thaw. Trainers along the gorge and its bridges.
2. **Yuki's cameo** ([side-quests.md](../side-quests.md), step 0), midway: a League-sponsored
   Ace Trainer heading for the tournament blocks a rope bridge, a few levels above the curve
   (about Lv 25). He battles them, win or lose. Then Yuki arrives, beats them easily, battles
   him briefly, and says she'll see him at the tournament.
3. **The Survey's way round:** the broken road ends at an old mine tunnel the Eien Survey has
   cleared and lit. A member at the entrance: "It's safe. We checked." A sign: "Route kept open
   by the Eien Survey." Hinata isn't here (saved for later).
4. **The cave's exit:** the first view after the dark: the coast below, and the door mountain
   smoking on the horizon. No scene, just the view (and maybe a line from him).
5. Isaribi (gym 3).

## NPCs and events

| NPC / event | Where | Visible when | Says / does |
| --- | --- | --- | --- |
| The Ace Trainer | a rope bridge, midway | until Yuki's scene | Blocks the bridge; battles him (see Trainers) |
| Yuki | the same bridge | after his battle with the Ace Trainer | Beats the Ace Trainer, battles him briefly, "see you at the tournament". Starts her chain. `TODO(design)`: her sprite, team and lines |
| Eien Survey member | the cave entrance | always | "It's safe. We checked." Also says they found the Wooper "in the old seams" when they cleared it (a hint at its evolution; `TODO(design)`: the line) |
| Survey sign | the cave entrance | always | "Route kept open by the Eien Survey." |
| The view | the cave's exit | always | The coast and the door mountain (`TODO(design)`: whether he says anything) |

## Trainers

Lv 18-23 (default). Names are placeholders when built (`TODO(design)`).

| Trainer | Class | Notes |
| --- | --- | --- |
| Matagi | `TODO(design)` (a new class, or a vanilla stand-in) | One of Tohoku's traditional mountain hunters |
| Raftsman | `TODO(design)` | Works the river |
| Hiker | Hiker | |
| Pilgrim | Pilgrim | Heading down from Yunotaki's falls |
| Engineer | `TODO(design)` | Fixing the telegraph line along the gorge; previews gym 3's Electric |
| The Ace Trainer | Ace Trainer (vanilla class) | League-sponsored, arrogant, heading for the tournament. About Lv 25. Yuki's scene follows |

`TODO(design)`: teams.

## Wild Pokémon

Lv 15-20 (default). `TODO(design)`: the other species' exact rates. Eien Wooper is the same
by day and night.

| Area | Pokémon |
| --- | --- |
| The gorge | Eien Wooper (10%, in the grass by the river), Psyduck, Marill, Lotad, Taillow, Shinx (near the telegraph line: an Electric preview before gym 3) |
| The cave | Eien Wooper (30%, in the muddy pools), Zubat, Geodude, Roggenrola |

Eien Wooper's design is in [variants.md](../variants.md) ([brainstorm-eien-wooper.md](../brainstorm-eien-wooper.md)).
It evolves into Eien Quagsire only in the cave (Lv 20+), so the cave is where its line is
finished before gym 3.

## Items

| Item | Where | Hidden? |
| --- | --- | --- |
| Super Potion | the gorge | No |
| Great Ball | the gorge | No |
| Magnet | the gorge | No |
| TM Mud-Slap | `TODO(design)`: where | No |
| Max Repel | the cave | Yes |

## Flags and vars

| Name | Set when | Checked by |
| --- | --- | --- |
| `TODO` | Yuki's scene | Her chain (`side-quests.md`) |
| `TODO` (a journal-note flag) | An Eien Wooper reaches Lv 20 outside the cave | Its research entry's note |

## Screenshot check

`TODO` once the maps exist.
