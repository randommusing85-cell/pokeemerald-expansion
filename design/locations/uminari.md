# Uminari

- **Map(s):** made in Porymap (placeholder constants `MAP_UMINARI`, `MAP_UMINARI_GYM`,
  `MAP_UMINARI_POKEMON_CENTER_1F`). The gym's inside reuses Sootopolis's gym layout. Vanilla
  layouts can stand in.
- **Type:** town
- **Connects to:** Route 8 ([route-8.md](route-8.md)) up to Hoshimi; Route 9 ([route-9.md](route-9.md))
  inland to Kawara.

Decided in [brainstorm-gyms-7-8.md](../brainstorm-gyms-7-8.md). Uminari (海鳴り, "the rumble of the sea").

## Purpose

Gym 7 (Water), on the door mountain's peninsula: a tuna port on a rough strait (like Ōma). Its
leader openly sides with Minato: "good people can want opposite things", made concrete before the
end.

## Look

A tuna port at a cape: boats, a rough grey strait, wind. `TODO(design)`: tilesets, music.

## Story beats here

- **Gym 7: Ushio** (潮, "tide"), a grizzled woman who runs the tuna boats: blunt, proud of the port,
  quietly convinced. She lost her husband to the strait and won't lose her town to the fading, so
  she sides with Minato: saving this world is worth draining others. Decent, sure, on the other
  side. Two of her tuna-boat crew, then Ushio. Winning gives the Tide Badge and TM03 Water Pulse.
  `TODO(design)`: her lines (her reason).

## Trainers

| Trainer | Class | Team (levels) | Notes |
| --- | --- | --- | --- |
| Tuna-boat crew 1 | `TODO(design)` | Water Pokémon, Lv 47-49 | Names `TODO(design)` |
| Tuna-boat crew 2 | `TODO(design)` | Water Pokémon, Lv 47-49 | |
| Ushio | Leader | Sharpedo Lv 48, Wailord Lv 48, Kingdra Lv 50 | The strait's big fish. `TODO(design)`: movesets, item |

The gym is Sootopolis's layout (its ice floor read as slick, icy decks).

## Flags and vars

| Name | Set when | Checked by |
| --- | --- | --- |
| `FLAG_BADGE07_GET` | He beats Ushio | The badge |
| `TODO` (`FLAG_VISITED_UMINARI`) | Entering the town | Fast travel (a region-map spot too) |

## Screenshot check

`TODO` once the maps exist.
