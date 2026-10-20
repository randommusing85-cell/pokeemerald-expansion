# Hoshimi

- **Map(s):** made in Porymap (placeholder constants `MAP_HOSHIMI`, `MAP_HOSHIMI_STATION` and its
  archive, `MAP_HOSHIMI_GYM`, `MAP_HOSHIMI_POKEMON_CENTER_1F`). The gym's inside reuses Mossdeep's
  gym layout. Vanilla layouts can stand in.
- **Type:** town (the League's research station and the hamlet around it)
- **Connects to:** Route 7 ([route-7.md](route-7.md)) down to Minori. `TODO(design)`: onward, toward
  gyms 7-8.

Decided in [brainstorm-gym-6.md](../brainstorm-gym-6.md). Hoshimi (星見, "star-viewing").

## Purpose

Gym 6 (Psychic) and Act 3's turn: the League's research station, an observatory where its
scientists study the aurora and the fading. Where the truth is kept, and where he learns it.

## Look

Observatory domes on a windswept plateau, instruments and long-exposure aurora photographs, an
archive. `TODO(design)`: tilesets, music.

## Story beats here

Act 3 beats 3-4 in [story-outline.md](../story-outline.md).

1. **The records:** Ren, who has just quit the League, gets him into the station's archive (Ren's
   step 2, [side-quests.md](../side-quests.md)). They read it together: the cycle and the League's
   cover-up from the League's side, and Tokoyo's plan (drain other worlds, his own included) as
   the League understands it. `TODO(design)`: what the records say, in what form.
2. **Gym 6: Tsukiko** (月子, "moon child"), the station's head scientist: an older woman, an
   astronomer, precise and tired, with decades of aurora readings. She hid the truth because
   panic would have killed more people than the fading. He challenges her knowing what she hid;
   afterwards she answers for it: she's opening the records now because the fading is speeding
   up. Someone who changes her mind (the villains never do). Two station researchers, then
   Tsukiko. Winning gives the Aurora Badge and TM29 Psychic.
3. **Nami, on the road out:** she knew he'd find out and came to tell him herself that she chooses
   her world over his. `TODO(design)`: the scene, her lines.
4. **Haru's letter** calls him home: his mother is close to a breakthrough. A scene takes him to
   Hamakaze ([hamakaze.md](hamakaze.md)).

## NPCs and events

| NPC / event | Where | Visible when | Says / does |
| --- | --- | --- | --- |
| Ren | the station | Act 3, before gym 6 | His step 2: gets him into the archive |
| The archive | the station | Ren's step 2 | The records (`TODO(design)`) |
| Tsukiko | the gym | always | See above (`TODO(design)`: lines) |
| Nami | the road out | after gym 6 | Her choice |

## Trainers

| Trainer | Class | Team (levels) | Notes |
| --- | --- | --- | --- |
| Station researcher 1 | `TODO(design)` | Psychic Pokémon, Lv 41-43 | Names `TODO(design)` |
| Station researcher 2 | `TODO(design)` | Psychic Pokémon, Lv 41-43 | |
| Tsukiko | Leader | Solrock Lv 42, Lunatone Lv 42, Xatu Lv 45 | Sky-watchers: the sun and moon pair, and Xatu (in the games it watches the sun and is said to see past and future). `TODO(design)`: movesets, item |

The gym is Mossdeep's layout (spin tiles, switches).

## Flags and vars

| Name | Set when | Checked by |
| --- | --- | --- |
| `FLAG_BADGE06_GET` | He beats Tsukiko | The badge; Nami on the road out |
| `TODO` | Ren's step 2 (the records read) | Opens gym 6's challenge in story order |

## Screenshot check

`TODO` once the maps exist.
