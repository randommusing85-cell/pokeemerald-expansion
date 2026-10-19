# Kanaya

- **Map(s):** made in Porymap (placeholder constants `MAP_KANAYA`, `MAP_KANAYA_GYM`,
  `MAP_KANAYA_POKEMON_CENTER_1F`, `MAP_KANAYA_MART`, `MAP_KANAYA_MINE`). The gym's inside reuses
  Lavaridge's gym layout. Vanilla layouts can stand in.
- **Type:** town
- **Connects to:** west: Route 5 ([route-5.md](route-5.md)). East: Route 6, a short route to
  Minori, Yuki's village ([route-6.md](route-6.md), [minori.md](minori.md)), then toward gym 6.

Decided in [brainstorm-act-3-gym-5.md](../brainstorm-act-3-gym-5.md). Kanaya (金屋, "metalworkers' quarter").

## Purpose

Gym 5 (Fire), Act 3's first gym: an ironworks town like Morioka's Nanbu ironware. The first
leader after the League's lie believes it, which makes the cover-up feel bigger than a few people.

## Look

Forges, cast-iron kettles, smoke, an old mine above the town. `TODO(design)`: tilesets, music.

## Story beats here

Act 3 in [story-outline.md](../story-outline.md).

- **Ren** (his step 1, [side-quests.md](../side-quests.md)) is here to challenge the gym. He's
  uneasy about the League's story and asks the hero what he saw. He quits either way. A believer
  (Takumi) and a doubter in one town.
- **The old mine:** fresh Eien Survey digging in a closed-off seam, the "old seams" Route 3's
  Survey member mentioned. What they dig for stays `TODO(design)`: a clue, not an answer.
- **Gym 5: Takumi** (匠, "craftsman"), the young heir of a foundry family. Loyal to the League
  because the League made his family's name; he repeats the "accident" line and believes it.
  Decent while being wrong. Two foundry workers, then Takumi. Winning gives the Forge Badge and
  TM35 Flamethrower.
- After the badge, **Yuki's letter** asks for help in her hometown (her step 2).

## NPCs and events

| NPC / event | Where | Visible when | Says / does |
| --- | --- | --- | --- |
| Takumi | the gym | always | See above (`TODO(design)`: lines) |
| Ren | the town | Act 3, before gym 5 | His step 1 |
| League official | the town | Act 3 | Repeats the "accident" story |
| The sealed seam | the mine | always | Fresh digging (`TODO(design)`) |

## Trainers

| Trainer | Class | Team (levels) | Notes |
| --- | --- | --- | --- |
| Foundry worker 1 | `TODO(design)` | Fire / Steel Pokémon, Lv 34-36 | Names `TODO(design)` |
| Foundry worker 2 | `TODO(design)` | Fire / Steel Pokémon, Lv 34-36 | |
| Takumi | Leader | Magcargo Lv 35, Bronzong Lv 36 (a cast-metal bell from the forge), Coalossal Lv 38 (Rock/Fire, from the mine) | `TODO(design)`: movesets, item |

The gym is Lavaridge's layout: its sand holes read as steam vents.

## Flags and vars

| Name | Set when | Checked by |
| --- | --- | --- |
| `FLAG_BADGE05_GET` | He beats Takumi | The badge; Yuki's letter |
| `TODO` | Ren's step 1 | His chain |

## Screenshot check

`TODO` once the maps exist.
