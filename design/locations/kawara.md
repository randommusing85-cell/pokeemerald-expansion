# Kawara

- **Map(s):** made in Porymap (placeholder constants `MAP_KAWARA`, `MAP_KAWARA_TEMPLE`,
  `MAP_KAWARA_GYM`, `MAP_KAWARA_POKEMON_CENTER_1F`, `MAP_KAWARA_TETSU_HUT`). The gym's inside
  reuses Petalburg's gym layout. Vanilla layouts can stand in.
- **Type:** town
- **Connects to:** Route 9 ([route-9.md](route-9.md)) down to Uminari. Beyond: the caldera lake, the
  League and the door mountain (Act 4).

Decided in [brainstorm-gyms-7-8.md](../brainstorm-gyms-7-8.md). Kawara (河原, "riverbed"), after Osorezan's riverbed of souls, where stones are
stacked for the dead.

## Purpose

Gym 8 (Ghost), the last gym: the temple town at the door mountain's foot, where the *itako* (saved
for the mountain) pay off. Tetsu's hut, the gate to the climb.

## Look

A temple town of stacked stones, grave tablets and pinwheels, sulphur and steam, at the foot of
the smoking door mountain. Across the caldera lake (like Usori lake at Osorezan), the League: a
white building on the far shore, the door mountain beside it. `TODO(design)`: tilesets, music.

## Story beats here

- **Tetsu's hut** (his step 2, [side-quests.md](../side-quests.md)), at the town's edge under the
  mountain: he teaches the old paths and gives the climbing gear (shortcuts only, never a gate).
  The gate to the climb in Act 4.
- **Gym 8: Tome** (留, "to stay": she stays for the dead), an old blind *itako*, as they
  traditionally are: she speaks for the dead at the mountain's festival; quiet, unhurried, kind.
  On no side; she knows the old tales are true. She knew Kaede's grandmother Chiyo (an old tie
  between the two keepers of the tales), and she has "heard of him from the dead" (a hint only).
  Two temple attendants, then Tome. Winning gives the Bell Badge and TM30 Shadow Ball.
  `TODO(design)`: her lines.
- **The view:** from the town, the League and the door mountain side by side across the lake.

## Trainers

| Trainer | Class | Team (levels) | Notes |
| --- | --- | --- | --- |
| Temple attendant 1 | `TODO(design)` | Ghost Pokémon, Lv 51-53 | Names `TODO(design)` |
| Temple attendant 2 | `TODO(design)` | Ghost Pokémon, Lv 51-53 | |
| Tome | Leader | Banette Lv 52, Dusknoir Lv 53, Chandelure Lv 55 | A temple of the dead: dolls left at the temple, a guide of the dead, lanterns for the dead. `TODO(design)`: movesets, item |

The gym is Petalburg's layout (its rooms as the temple's halls).

## Flags and vars

| Name | Set when | Checked by |
| --- | --- | --- |
| `FLAG_BADGE08_GET` | He beats Tome | The badge; the League (Act 4) |
| `TODO` (`FLAG_VISITED_KAWARA`) | Entering the town | Fast travel (a region-map spot too) |
| `TODO` | Tetsu's step 2 | The climbing gear |

## Screenshot check

`TODO` once the maps exist.
