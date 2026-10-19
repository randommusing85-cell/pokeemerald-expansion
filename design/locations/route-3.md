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
2. **Yuki's cameo** ([side-quests.md](../side-quests.md), step 0), midway: KAITO, a
   League-sponsored Ace Trainer heading for the tournament, blocks a rope bridge (Lv 24-25).
   He battles KAITO, win or lose. Then Yuki arrives, beats KAITO easily in a short scripted
   scene, battles him briefly (Absol alone, Lv 22), and says she'll see him at the tournament.
3. **The Survey's way round:** the broken road ends at an old mine tunnel the Eien Survey has
   cleared and lit. A member at the entrance: "It's safe. We checked." A sign: "Route kept open
   by the Eien Survey." Hinata isn't here (saved for later).
4. **The cave's exit:** the first view after the dark: the coast below, and the door mountain
   smoking on the horizon. No scene, just the view (and maybe a line from him).
5. Isaribi (gym 3).

## NPCs and events

| NPC / event | Where | Visible when | Says / does |
| --- | --- | --- | --- |
| KAITO, the Ace Trainer | a rope bridge, midway | until Yuki's scene | Blocks the bridge; battles him (see Trainers) |
| Yuki | the same bridge | after his battle with KAITO | Beats KAITO in a short scripted scene (her Absol moves, his Machoke falls, an emote, two text boxes; KAITO walks off). Then: "You didn't lose by much. I'd have lost to him, last year." (`TODO(design)`: a variant if he won). Battles him with Absol alone, Lv 22, and shows she held back (her others are tired). "See you at the tournament." Starts her chain ([characters.md](../characters.md)). Sprite `TODO` (AI drafts); class `TODO(design)` at build |
| Eien Survey member | the cave entrance | always | "It's safe. We checked." Also says they found the Wooper "in the old seams" when they cleared it (a hint at its evolution; `TODO(design)`: the line) |
| Survey sign | the cave entrance | always | "Route kept open by the Eien Survey." |
| The view | the cave's exit | always | The coast and the door mountain (`TODO(design)`: whether he says anything) |

## Trainers

Lv 18-23; the Ace Trainer 24-25. Decided in
[brainstorm-route-3-trainers.md](../brainstorm-route-3-trainers.md). The teams stay in character,
but a few carry Water and Fighting moves, so Eien Wooper (Ground/Steel) isn't a free win. Six
trainers, no double battle. Names are placeholders (`TODO(design)`).

| Trainer | Class | Team (levels) | Notes |
| --- | --- | --- | --- |
| ISAMU | Matagi (new class) | Herdier Lv 20, Teddiursa Lv 19 | One of Tohoku's traditional mountain hunters: his hunting dog, and a bear cub he raised |
| SHIGERU | Raftsman (new class) | Psyduck Lv 20 (Water Gun), Lotad Lv 20 | Works the river; the river's own Pokémon |
| NOBORU | Hiker | Geodude Lv 20, Timburr Lv 21 | |
| AYAME | Pilgrim | Meditite Lv 21, Makuhita Lv 20 | Heading down from Yunotaki's falls |
| KENTA | Engineer (FRLG's `TRAINER_CLASS_ENGINEER_FRLG`) | Shinx Lv 21, Magnemite Lv 22 | Fixing the telegraph line along the gorge; previews Akari's Luxio and Magneton |
| KAITO | Ace Trainer (vanilla class) | Kirlia Lv 24, Staravia Lv 24, Machoke Lv 25 | League-sponsored, boastful, heading for the tournament. Machoke tests Eien Wooper. Draft line: "The League covers my travel. You're paying for yours, I guess." Yuki (unsponsored) then beats him easily, so her team must look clearly stronger |

Moves are each Pokémon's level-up moves at its level unless noted. **Sprites** (vanilla
stand-ins): the Matagi a Hiker or Ruin Maniac, the Raftsman a Fisherman, the Engineer FRLG's
Engineer, KAITO a vanilla Ace Trainer (male); AYAME uses `OBJ_EVENT_GFX_EIEN_PILGRIM_F` /
`TRAINER_PIC_EIEN_PILGRIM_F`. No spare trainer slots: these alias unreachable vanilla Hoenn
trainers, like Route 2's. `TODO(design)`: lines (drafted at build time).

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
