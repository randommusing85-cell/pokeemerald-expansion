# Progression

## Route order

Our world (prologue) → Hamakaze → Route 1 → Shimotsuki (gym 1) → Lake Usurai → Route 2 (the
mountain pass) → Yunotaki (gym 2) → Route 3 (the gorge) → Isaribi (gym 3, Electric) → Route 4 (the rice plain) → Hanashiro (gym 4, Grass) → the tournament (Hanashiro's castle grounds) → Shimotsuki (the funeral) → Route 5 (the beech forest) → Kanaya (gym 5, Fire) → Route 6 → Minori (Yuki's village) → Route 7 (the plateau) → Hoshimi (gym 6, Psychic) → Hamakaze (the lab) → Shimotsuki (fast travel from here) → Route 8 → Uminari (gym 7, Water) → Route 9 → Kawara (gym 8, Ghost) →
gyms 5-8 → Tokiwa Hall, the League (the door opens after the fourth Elite Four member) → Tobira-yama, the door mountain → the goodbye night across Eien → home.

## Badges and gates

| Badge | Leader | Unlocks | Gate the player passes after |
| --- | --- | --- | --- |
| 1 | Fuyumi (Ice), Shimotsuki | Hoarfrost Badge; Fuyumi also gives TM07 Hail. `TODO(design)`: what it unlocks | `TODO(design)` |
| 2 | Ibuki (Fighting), Yunotaki | Misogi Badge; Ibuki also gives TM31 Brick Break. `TODO(design)`: what it unlocks | `TODO(design)` |
| 3 | Akari (Electric), Isaribi | Lantern Badge; Akari also gives TM34 Shock Wave. `TODO(design)`: what it unlocks | `TODO(design)` |
| 4 | Mamoru (Grass), Hanashiro | Blossom Badge; Mamoru also gives TM19 Giga Drain. `TODO(design)`: what it unlocks | `TODO(design)` |
| 5 | Takumi (Fire), Kanaya | Forge Badge; Takumi also gives TM35 Flamethrower. `TODO(design)`: what it unlocks | `TODO(design)` |
| 6 | Tsukiko (Psychic), Hoshimi | Aurora Badge; Tsukiko also gives TM29 Psychic. `TODO(design)`: what it unlocks | `TODO(design)` |
| 7 | Ushio (Water), Uminari | Tide Badge; Ushio also gives TM03 Water Pulse. `TODO(design)`: what it unlocks | `TODO(design)` |
| 8 | Tome (Ghost), Kawara | Bell Badge; Tome also gives TM30 Shadow Ball. Opens the League | `TODO(design)` |

Every gate is enforced by a flag or var; list it in the location doc that checks it.

## Level curve

| Point in game | Wild levels | Trainer levels | Gym ace |
| --- | --- | --- | --- |
| Route 1 | 2-5 | 5-8 | |
| Gym 1 | | 9-11 | 13-14 (Bergmite) |
| Route 2 (the pass) | 10-13 lower map, 12-15 upper map | 12-17 | |
| Gym 2 | | 17-19 (Akira 17-18) | 21 (Medicham) |
| Route 3 (the gorge, the cave) | 15-20 | 18-23 (the bridge Ace Trainer about 25) | |
| Gym 3 | | 22-25 | 27 (Lanturn) |
| Route 4 (the rice plain) | 22-27 | 24-28 | |
| Gym 4 | | 27-29 | 32 (Appletun) |
| The tournament (Hanashiro) | | KAITO ~30, Yuki ~32, Nami ~34; Tokoyo members 30-33 | |
| Route 5 (the beech forest) | 30-35 | 32-36 (Akira ~36) | |
| Gym 5 | | 34-36 | 38 (Coalossal) |
| Route 6, Minori | 34-38 | 35-38; the Tokoyo pair 37-40 | |
| Route 7 (the plateau) | 38-42 | 40-43 | |
| Gym 6 | | 41-43 | 45 (Xatu) |
| Route 8 | 44-47 | 46-48 | |
| Gym 7 | | 47-49 | 50 (Kingdra) |
| Route 9 | 48-51 | 50-52 | |
| Gym 8 | | 51-53 | 55 (Chandelure) |
| Tokiwa Hall (Elite Four) | | 56-60 (Ibuki's ace 60) | |
| Tobira-yama | | Kaede's tag foes 58, Nami 60, Akira 61, Minato 63 (with Seiji beside him) | |

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
- **Field moves: no HMs** (decided in [brainstorm-fast-travel.md](brainstorm-fast-travel.md)). The only field ability is **Surf**: any
  Water-type in the party lets him surf (no move needed; the vanilla surf blob sprite; Celebi
  follows over water). It unlocks after gym 3: Akari tells him ("Got a Water-type? Then you've
  got a boat."), and the journal records it. No Cut, Strength, Rock Smash, Waterfall, Dive or
  Flash: the world is gated by story and scenes. Tetsu's **climbing gear** (a key item, his
  step 2) opens shortcuts near the door mountain, never gates. **Built:** `MonCanSurf`
  (`src/field_player_avatar.c`) replaces "knows Surf" in `PartyHasMonWithSurf` and in
  `checkfieldmove FIELD_MOVE_SURF`; Surf unlocks with `FLAG_BADGE03_GET` (`src/field_move.c`); the
  message is "{STR_VAR_1} takes you out on the water." Shots in `art/fast_travel/` (a Squirtle
  that doesn't know Surf, on Lake Usurai; no prompt without badge 3 or a Water-type).
- **Fast travel:** in Act 3, after the professor's death, Haru gives him his mother's **Altaria,
  Kumo** (雲, "cloud", her nickname for it),
  which carries him: he flies from the Town Map with R to any town whose Pokémon Center he has
  visited (the engine's `OW_FLAG_POKE_RIDER`, set to a renamed spare flag; not from caves or
  indoors). Altaria takes no party slot; Celebi comes along. No fast travel before then: story
  scenes move him (the funeral takes him from Hanashiro to Shimotsuki; Haru's letter from
  Hoshimi to Hamakaze).
  **Built:** `FLAG_RECEIVED_PROFESSOR_ALTARIA` (was `FLAG_UNUSED_0x02D`) is `OW_FLAG_POKE_RIDER`;
  towns become destinations through `FLAG_VISITED_HAMAKAZE` / `_SHIMOTSUKI` / `_YUNOTAKI` (were
  `FLAG_UNUSED_0x881`-`0x883`, set by each town's map script; new towns need one each, plus a
  `GetMapsecType` case and a `sMapHealLocations` entry in `src/region_map.c`). Altaria sits in
  the lab (`LOCALID_LAB_ALTARIA`, hidden once given). The gift scene isn't built (the lab
  disaster brainstorm); the debug menu's Script 4 sets the flag. **Placeholder map:** the Town
  Map is still Hoenn's art, so Eien's places borrow Hoenn squares (Hamakaze on Littleroot's,
  Route 1 on Route 101's, Shimotsuki on Oldale's, Lake Usurai on Route 103's, Yunotaki on
  Lavaridge's; `src/data/region_map/region_map_layout.h` and the sections' x/y) until the Eien
  region map is built (designed in [brainstorm-region-map.md](brainstorm-region-map.md): Hamakaze moves
  to (3,13), Shimotsuki to (3,10), Yunotaki to (3,4); the title and "{REGION}" become EIEN).
- `TODO(design)`: other key items.
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
