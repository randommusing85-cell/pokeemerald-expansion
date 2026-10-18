# Route 1

- **Map(s):** `MAP_EIEN_ROUTE1` (placeholder layout); the shrine is its own small map,
  `MAP_EIEN_ROUTE1_SHRINE`, entered from a short side path near the Shimotsuki end (a warp; see
  **Maps** below)
- **Type:** route
- **Connects to:** Hamakaze to the south, Shimotsuki to the north (a warp: the north edge is
  north-arrow snow, x 10-13 at row 0, since the town uses a different secondary tileset).

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
`TODO(design)`: the real tracks. `TODO(art)`: torii and komainu tiles (the torii is two wooden
poles, the komainu are Poochyena objects in vanilla Poochyena's overworld colors).

## Story beats here

Act 1 beat 4 in [story-outline.md](../story-outline.md). `VAR_EIEN_STORY` becomes
`STORY_ROUTE_1` the first time he steps onto the route.

## Trainers

Locals at their jobs. Levels rise toward Shimotsuki. Generic trainer sprites. Names are
placeholders (`TODO(design)`).

| Where | Class | Team | Note |
| --- | --- | --- | --- |
| The coast | Fisherman (SHIN) | Magikarp Lv 5, Wingull Lv 5 | |
| The fields | Hiker (GORO) | Machop Lv 7 | Shows the second answer to Ice |
| The shrine | Lass (EMI) | Zigzagoon Lv 7, Starly Lv 7 | Visiting the shrine |
| Near Shimotsuki | Youngster (RIKU, the kid) | Eien Poochyena Lv 8, Snover Lv 7 | "Rock beats Ice. I caught it for Fuyumi." His Poochyena counts as "battled" for the research |

Trainer ids `TRAINER_EIEN_ROUTE1_FISHERMAN` / `_HIKER` / `_LASS` / `_YOUNGSTER` (858-861).
Shimotsuki took the last 2 spare slots and reuses vanilla ones past that (`opponents.h`).

## Wild Pokémon

Lv 2-5. Two tables on the route: morning, day and evening share one, night has its own (the
stone dogs stir after dark). Needs `OW_TIME_OF_DAY_ENCOUNTERS`. Rates are fitted to the GBA's
fixed land slots, so they land near these numbers.

| Area | Day (morning, day, evening) | Night |
| --- | --- | --- |
| Route grass | Eien Poochyena 15%, Starly 25%, Bidoof 20%, Zigzagoon 15%, Wingull 10%, Machop 10%, Snover 5% | Eien Poochyena 30%, Zigzagoon 20%, Bidoof 15%, Snover 15%, Machop 10%, Wingull 10%; no Starly (it roosts) |
| Shrine grass (Lv 3-5) | Eien Poochyena 50%, Shuppet 5%, Starly 10%, Bidoof 11%, Zigzagoon 11%, Snover 5%, Machop 4%, Wingull 4% | Eien Poochyena 60%, Shuppet 25%, Zigzagoon 6%, Bidoof 4%, Snover 4%, Machop 1% |

These are the slot sums in `src/data/wild_encounters.json` (`gEienRoute1`, `gEienRoute1_Night`,
`gEienRoute1_Shrine`, `gEienRoute1_Shrine_Night`); morning and evening use the day table.
Eien Poochyena evolves into Eien Mightyena at Lv 18 in the shrine (its `IF_IN_MAP` entry).

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
| `QUEST_HARU_MAP` step bits (`HARU_MAP_COAST` / `_FIELDS` / `_SHRINE`) | Opened by Haru at Hamakaze's north exit. The coast and the fields are noted when he walks into them, the shrine when he examines the torii. `TODO(design)`: handing the map back to Haru (the Town Map reward) | The journal's Missions tab |
| `QUEST_KAEDE_TABLETS` bit `TABLET_ROUTE1_SHRINE` | He reads the Route 1 shrine's tablet | The journal's lore page; Kaede's step 1 |
| `FLAG_ITEM_EIEN_ROUTE1_POTION` / `_POKE_BALL` / `_ICE_HEAL`, `FLAG_HIDDEN_ITEM_EIEN_ROUTE1_X_DEFENSE` | Items picked up | The item balls / hidden item |

## Maps

- **Route:** a 24x40 placeholder layout (`data/layouts/EienRoute1/`, `gTileset_General` +
  `gTileset_EienCoast`). It connects to Hamakaze at the bottom (Hamakaze's north gap, x 10-13).
  The coast (sea and sand on the west) runs from the bottom up to a neck of trees at rows
  21-23; the fields above it; a tree line along the top with a gap for Shimotsuki. The coast
  and fields notes are coord events in the two necks (rows 38 and 22). The grass is metatile
  0x206 (a snow-buried plant), given `MB_TALL_GRASS` in the tileset tool.
- **Shrine:** a 16x20 placeholder (`data/layouts/EienRoute1_Shrine/`, `gTileset_EienShrine`):
  the Johto pagoda at the back (not enterable), the torii poles at the west entrance, the
  komainu either side of the path, the tablet (a signpost tile) and a grass patch.
- **Why a warp, not a connection:** the two maps use different secondary tilesets, and the GBA
  draws the strip of a connected map with the current map's tiles, which garbles it. So the
  route's east edge (rows 4-5) and the shrine's west edge (rows 15-16) are arrow-warp snow
  tiles (0x211 east, 0x212 west) with warp events between them.
- Battles here have snow weather, like Hamakaze (both maps use `WEATHER_SNOW`).

## Screenshot check

Played through with the mGBA harness (new game, Hamakaze, the lab, then on foot): shots in
`design/art/route1/`.
- `1_research_poke_balls.png`: the professor gives five Poké Balls with the research.
- `2_haru_map.png`: Haru at Hamakaze's north exit.
- `3_fields.png`: the fields, the second note.
- `4_shrine_torii.png`: the torii notes the shrine ("That's all three for Haru").
- `5_tablet.png`: the tablet.
- `6_journal_haru_map.png`, `7_journal_lore.png`: the mission's three entries; the lore page.
- `8_kid_intro.png`, `9_kid_battle.png`: the kid and his Eien Poochyena.
- `10_shrine_thin_place.png`: a wild battle in the shrine grass opens with the thin-place
  message.
- `layout.png`, `shrine_layout.png`: the layouts.
