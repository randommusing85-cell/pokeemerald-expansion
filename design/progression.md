# Progression

## Route order

Our world (prologue) → Hamakaze → Route 1 → Shimotsuki (gym 1) → the lake path → Route 2's
mountain pass → the hot-spring town (gym 2) → ... → gym 4 → tournament →
gyms 5-8 → Pokémon League (Minato's plan interrupts the Elite Four) → door mountain.

## Badges and gates

| Badge | Leader | Unlocks | Gate the player passes after |
| --- | --- | --- | --- |
| 1 | Fuyumi (Ice), Shimotsuki | Hoarfrost Badge; Fuyumi also gives TM07 Hail. `TODO(design)`: what it unlocks | `TODO(design)` |
| 2 | `TODO(design)` (Fighting), the hot-spring town | `TODO(design)` | `TODO(design)` |
| 3-8 | `TODO(design)` | | |

Every gate is enforced by a flag or var; list it in the location doc that checks it.

## Level curve

| Point in game | Wild levels | Trainer levels | Gym ace |
| --- | --- | --- | --- |
| Route 1 | 2-5 | 5-8 | |
| Gym 1 | | 9-11 | 13-14 (Bergmite) |
| Route 2 (the pass) | 10-15 | 12-17 | |
| Gym 2 | | 17-19 | about 21 |

All levels are proposed defaults; adjust after playtesting.

- **Starters' first evolution is about Lv 18** (not 16), so the first milestone only needs
  their first stage.

## Items and HMs / field moves

- **Journal** (key item): from the start of Act 1. Tabs for the story, research and missions
  (see the game bible's Mechanics). Its pages go blank near the end and refill in the
  epilogue.
- **No PokéNav.** The journal takes its place in the start menu; letters replace Match Call.
- **Town Map:** its own key item, Haru's first quest reward.
- **Vs. Seeker** for trainer rematches (`I_VS_SEEKER_CHARGING`).
- No contests or ribbons.
- `TODO(design)`: field moves and other key items.
- **Field moves without HMs:** `TODO(design)`: which key item or Pokémon does them.
- **TMs are reusable.**
- **DexNav** is on, for searching and chaining wild Pokémon.

## Difficulty

- **Side-quest rewards** are items, TMs, keepsakes, lore, money and battle items; never Rare
  Candies or EXP, so the level caps hold.

- **Normal and Hard** modes, chosen at the start.
- **Soft level caps** tied to the next gym or boss (EXP drops above the cap).
  `TODO(design)`: is optional side content balanced to the caps?
- **Optional Nuzlocke mode** with standard rules, framed to fit the world: a fainted Pokémon
  "goes home to rest", gone from the run but not dead (the player's party never dies).
