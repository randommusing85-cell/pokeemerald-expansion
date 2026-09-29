# Route 1

- **Map(s):** `MAP_...` `TODO`; the shrine is its own small map (`MAP_...` `TODO`), entered
  from the route
- **Type:** route
- **Connects to:** Hamakaze, Shimotsuki. `TODO(design)`: directions.

## Purpose

The first route. Gives every starter a way to handle the Ice gym (Eien Poochyena).

## Look

Coast near Hamakaze, turning into snowy fields, then a small shrine before Shimotsuki. The
shrine map: a torii, komainu statues, a tablet, and a patch of grass. It's a shrine area
and a thin place ([variants.md](../variants.md), "Shrine areas").
Tilesets: `gTileset_General` + `gTileset_EienShrine` (snow cliffs, ledges, the pagoda).

## Story beats here

Act 1 beat 4 in [story-outline.md](../story-outline.md).

## Trainers

3-4 trainers, Lv 5-8. `TODO(design)`: classes and teams.

## Wild Pokémon

Lv 2-5. `TODO(design)`: exact species and rates.

| Area | Species (levels, rate) |
| --- | --- |
| Grass | Eien Poochyena (~20%); coastal and snowy-field species `TODO(design)` |
| Shrine grass | Eien Poochyena, more often than on the route (`TODO(design)`: rate) |

## Items

| Item | Position | Hidden? |
| --- | --- | --- |
| `TODO` | | |

## Shrine tablet

He can read it before Kaede asks for rubbings. It adds a lore page to the journal and counts
toward her tablet quest once it starts. Its text hints that the stone dogs grow at their
post (Eien Poochyena evolves in a shrine area). `TODO(design)`: the text, how "read" is
stored.

## Flags and vars

| Name | Set when | Checked by |
| --- | --- | --- |
| `VAR_EIEN_STORY` = `STORY_ROUTE_1` | He first steps onto Route 1 | The journal |
| `QUEST_RESEARCH_POOCHYENA` (quest table; step bits: seen, battled, caught) | The professor asks him (`TODO(design)`: where); each bit when he sees, battles, catches one | The journal's Research and Missions tabs |
| `QUEST_HARU_MAP` step 1-3 | He notes each of the coast, the fields, the shrine | The journal |

## Screenshot check

`TODO` once the map exists.
