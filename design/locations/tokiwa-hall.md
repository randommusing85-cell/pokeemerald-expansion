# Tokiwa Hall (the Pokémon League)

- **Map(s):** made in Porymap (placeholder constants `MAP_TOKIWA_HALL` (entrance, Pokémon Center),
  four Elite Four rooms, `MAP_TOKIWA_HALL_CHAMPION`). Vanilla Ever Grande League layouts can stand
  in.
- **Type:** dungeon (the League)
- **Connects to:** Kawara across the caldera lake ([kawara.md](kawara.md)); the lake path up
  Tobira-yama ([tobira-yama.md](tobira-yama.md)).

Decided in [brainstorm-act-4.md](../brainstorm-act-4.md). Tokiwa (常盤, "evergreen, unchanging"): quietly ironic, since the League hides that
everything ends. (Also Viridian City's Japanese name, 常磐; kept as picked.)

## Purpose

Act 4's start: the League's run, interrupted. A white building on the far shore of the caldera
lake, the door mountain beside it, seen from Kawara. The Bell Badge opens it.

## Story beats here

Act 4 beats 1-2 in [story-outline.md](../story-outline.md).

1. **The Elite Four:** three new members (Dark, a quiet judge-like figure; Steel, an old
   armour-smith; Dragon, a young woman from the League's founding family), then **Ibuki**, back at
   the League he walked away from because it needs him now.
2. **The door opens** after the fourth: a thinning spreads from the mountain across the caldera
   into the hall (`WEATHER_THINNING`); the hall goes grey; the Elite Four stop. The Dragon member
   holds the hall so he can go.
3. **Seiji's door:** the Champion's battle becomes his confession (he ordered the cover-up). He joins
   him. The hero never becomes Champion.

## Trainers

| Trainer | Team (levels) | Notes |
| --- | --- | --- |
| Elite Four (Dark, Steel, Dragon) | Lv 56-59 | Names, teams `TODO(design)` |
| Ibuki | his team grown, ace Lv 60 | `TODO(design)`: team |
| Seiji | no battle here | Fights beside the hero against Minato (`TODO(design)`: his team) |

## Flags and vars

| Name | Set when | Checked by |
| --- | --- | --- |
| `FLAG_BADGE08_GET` | Gym 8 | Opens the League |
| `TODO` | The door opens | Act 4's story step |

## Screenshot check

`TODO` once the maps exist.
