# Progression

## Route order

Our world (prologue) → Hamakaze → Route 1 → Shimotsuki (gym 1) → ... → gym 4 → tournament →
gyms 5-8 → Pokémon League (Minato's plan interrupts the Elite Four) → door mountain.

## Badges and gates

| Badge | Leader | Unlocks | Gate the player passes after |
| --- | --- | --- | --- |
| 1 | Fuyumi (Ice), Shimotsuki | `TODO(design)` | `TODO(design)` |
| 2-8 | `TODO(design)` | | |

Every gate is enforced by a flag or var; list it in the location doc that checks it.

## Level curve

| Point in game | Wild levels | Trainer levels | Gym ace |
| --- | --- | --- | --- |
| Route 1 | 2-5 | 5-8 | |
| Gym 1 | | 9-11 | 13-14 (Bergmite) |

Route 1 and gym 1 levels are proposed defaults; adjust after playtesting.

- **Starters' first evolution is about Lv 18** (not 16), so the first milestone only needs
  their first stage.

## Items and HMs / field moves

- **Journal** (key item): from the start of Act 1. Tabs for the story, research and missions
  (see the game bible's Mechanics). Its pages go blank near the end and refill in the
  epilogue.
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
