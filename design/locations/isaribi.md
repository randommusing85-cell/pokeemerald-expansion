# Isaribi

- **Map(s):** made in Porymap (placeholder constants `MAP_ISARIBI`, `MAP_ISARIBI_GYM`,
  `MAP_ISARIBI_POKEMON_CENTER_1F`, `MAP_ISARIBI_MART`, `MAP_ISARIBI_BOATHOUSE`,
  `MAP_ISARIBI_FISHING_SHOP`). The gym's inside reuses Mauville's gym layout.
- **Type:** town
- **Connects to:** west/up: Route 3's cave exit ([route-3.md](route-3.md)). `TODO(design)`: where the
  road goes next (toward gym 4).

Decided in [brainstorm-port-gym-3.md](../brainstorm-port-gym-3.md). Isaribi (漁火, "fishing
fires"): the lamps of the night squid boats strung across the dark sea.

## Purpose

Gym 3 (Electric), on the Sea of Japan coast at the foot of Route 3's gorge. The first coastal town
since Hamakaze, and Nami's battle. Eien Wooper (Ground), caught on Route 3, is the answer.

## Look

A fishing port: a harbour market with drying racks, wooden boats, the squid-boat pier, and a
lighthouse (not enterable). **By day** a snow-and-thunder storm rolls in off the sea (the coast's
yuki-okoshi, "snow-waking thunder"); **at night** the squid boats light up across the water, seen
from the pier. `TODO(design)`: tilesets, music.

## Story beats here

Act 1 beat 8 in [story-outline.md](../story-outline.md).

- **Gym 3: Akari** (灯, "lamp, light"). She runs the squid-boat fleet; her Electric Pokémon light its
  lamps. Practical, loud, well loved: the first leader with a big, warm personality. The gym
  reuses Mauville's switch-and-barrier puzzle, read as lamps switching on. Winning gives the
  Lantern Badge (after chōchin, 提灯, paper lanterns, a nod to the Torchic line) and TM34 Shock
  Wave.
- **Akira** watches from the gym's stands; no battle. One line afterwards about the tournament
  (`TODO(design)`: the line). His evolved starter first shows at the tournament.
- **Nami** battles him on the pier after gym 3, her Lapras in the water behind her. Her optional
  warm scene ("the coast with her Lapras, after they battle", [side-quests.md](../side-quests.md))
  follows there; at night, with the squid boats lit.

## NPCs and events

| NPC / event | Where | Visible when | Says / does |
| --- | --- | --- | --- |
| Akari | the gym | always | See above |
| Akira | the gym's stands | after he arrives, around gym 3 | One line about the tournament; no battle |
| Nami | the pier | after gym 3 | Battles him (`TODO(design)`: her team at this point) |
| Fleet crew | the boathouse | always | Talk about Akari. `TODO(design)`: lines |
| Fishing-gear shop | its own building | always | Sells the Good Rod: Spheal, held back at Lake Usurai, becomes catchable (`TODO(design)`: the Good Rod's tables) |
| Market stalls | the harbour | always | `TODO(design)` |

## Trainers

| Trainer | Class | Team (levels) | Notes |
| --- | --- | --- | --- |
| Squid-boat fisher | `TODO(design)` | Chinchou, Mareep or Pikachu, Lv 22-25 (default) | Akari's crew. Name `TODO(design)` |
| Deckhand | `TODO(design)` | the same pool | Akari's crew. Name `TODO(design)` |
| Akari | Leader | Magneton Lv 24 (Flash Cannon), Luxio Lv 24 (Ice Fang), Lanturn Lv 27 (its Water moves) | Each covers a different answer to Electric: Flash Cannon hits Rock, Ice Fang hits Ground and Grass, Lanturn's Water hits Ground and Rock. `TODO(design)`: full movesets, item |

## Flags and vars

| Name | Set when | Checked by |
| --- | --- | --- |
| `FLAG_BADGE03_GET` | He beats Akari | The badge |
| `TODO` | Nami's battle; her warm scene | Her scenes |

## Screenshot check

`TODO` once the maps exist.
