# Route 1

- **Map(s):** `MAP_EIEN_ROUTE1` (placeholder layout); the shrine is its own small map,
  `MAP_EIEN_ROUTE1_SHRINE`, entered from a short side path near the Shimotsuki end
- **Type:** route
- **Connects to:** Hamakaze to the south, Shimotsuki to the north (no connection until
  Shimotsuki exists).

Decided in [brainstorm-route-1.md](../brainstorm-route-1.md).

## Purpose

The first route. Gives every starter a way to handle the Ice gym (Eien Poochyena, and Machop
as a backup).

## Look

A straight route north from Hamakaze: the coast along one side first, then snowy fields. Near
the Shimotsuki end a short side path leads to the shrine: optional, but easy to see. The
shrine map: a torii, komainu statues, a tablet, and a patch of grass. It's a shrine area and a
thin place ([variants.md](../variants.md), "Shrine areas"), so every battle there has the
thin-place effect.
Tilesets: `gTileset_General` + `gTileset_EienCoast` (the route), `gTileset_EienShrine` (the
shrine). The layouts are hand-made placeholders; redraw them in Porymap any time.

Music (placeholders): the route uses Route 101's theme, the shrine Mt. Pyre's.
`TODO(design)`: the real tracks.

## Story beats here

Act 1 beat 4 in [story-outline.md](../story-outline.md). `VAR_EIEN_STORY` becomes
`STORY_ROUTE_1` the first time he steps onto the route.

## Trainers

Locals at their jobs. Levels rise toward Shimotsuki. Generic trainer sprites. Names are
placeholders (`TODO(design)`).

| Where | Class | Team | Note |
| --- | --- | --- | --- |
| The coast | Fisherman | Magikarp Lv 5, Wingull Lv 5 | |
| The fields | Hiker | Machop Lv 7 | Shows the second answer to Ice |
| The shrine | Lass | Zigzagoon Lv 7, Starly Lv 7 | Visiting the shrine |
| Near Shimotsuki | Youngster (the kid) | Eien Poochyena Lv 8, Snover Lv 7 | "Rock beats Ice. I caught it for Fuyumi." His Poochyena counts as "battled" for the research |

## Wild Pokémon

Lv 2-5. Two tables on the route: morning, day and evening share one, night has its own (the
stone dogs stir after dark). Needs `OW_TIME_OF_DAY_ENCOUNTERS`. Rates are fitted to the GBA's
fixed land slots, so they land near these numbers.

| Area | Day (morning, day, evening) | Night |
| --- | --- | --- |
| Route grass | Eien Poochyena 15%, Starly 25%, Bidoof 20%, Zigzagoon 15%, Wingull 15%, Machop 5-10%, Snover 5% | Eien Poochyena 30%, Zigzagoon 20%, Bidoof 15%, Snover 15%, Machop 10%, Wingull 10%; no Starly (it roosts) |
| Shrine grass | Eien Poochyena 50%, Shuppet 5%, the route's commons for the rest | Eien Poochyena 60%, Shuppet 25%, commons for the rest |

## Items

| Item | Where | Hidden? |
| --- | --- | --- |
| Potion | The coast | No |
| Poké Ball | The fields | No |
| Ice Heal | Near the shrine path | No |
| X Defense | The fields | Yes |

## Shrine tablet

He can read it before Kaede asks for rubbings. Reading it adds a lore page to the journal and
counts toward her tablet quest once it starts.

> The dogs keep the gate. They grow at the gate, and nowhere else.

Then his thought: "In the games, Poochyena just evolves at 18. …Does it say something else
here?"

Stored as a step bit of `QUEST_KAEDE_TABLETS` (one bit per tablet; side-quests E7). Reading a
tablet sets its bit while the quest is still hidden; Kaede's step 1 opens the quest, and the
tablets read before then already count. The journal's lore page is keyed to the bit.

## Flags and vars

| Name | Set when | Checked by |
| --- | --- | --- |
| `VAR_EIEN_STORY` = `STORY_ROUTE_1` | He first steps onto Route 1 | The journal |
| `QUEST_RESEARCH_POOCHYENA` (quest table; step bits: seen, battled, caught) | Opened by the professor in her lab after Akira's battle (she gives Poké Balls). Bits: **seen** when one appears in a battle, **battled** when one faints or is caught, **caught** when he catches one. These definitions are defaults; change them if wanted | The journal's Research and Missions tabs |
| `QUEST_HARU_MAP` step 1-3 | Opened by Haru at Hamakaze's north exit. Each place adds a step: the coast and the fields when he walks into them, the shrine when he examines the torii | The journal |
| `QUEST_KAEDE_TABLETS` bit 0 | He reads the Route 1 shrine's tablet | The journal's lore page; Kaede's step 1 |

## Screenshot check

`TODO` once the map exists.
