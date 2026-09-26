# Eien tilesets

Three secondary tilesets built from community art (credits in `design/asset-credits.md`):

| Tileset | For | Contents |
| --- | --- | --- |
| `gTileset_EienTown` | Shimotsuki | snow ground, pines, a house and shop, Pokémon Center, Mart, Gym |
| `gTileset_EienCoast` | Hamakaze | snow ground, pines, Ekat's beach house, a Johto wooden house, small houses |
| `gTileset_EienShrine` | Route 1 | snow ground, pines, rocky snow cliffs and ledges, the Johto pagoda |

Pair each with `gTileset_General` as the primary. They are self-contained (compiled against an
empty primary), so they never reference General's tiles or palettes.

## Rebuilding

1. `tools/fetch_assets.py cinna_snow johto ekat_tiles` downloads the source packs.
2. `tools/eien_tileset/build_source.py` cuts the pieces listed in `TILESETS`, reduces colors
   (tiles are grouped into 7 color families, each cut to one 15-color palette), and writes
   `tilesets_src/<name>/{bottom,middle,top}.png`. Edit those PNGs by hand if you like;
   rerunning the script overwrites them.
3. `PORYTILES=/path/to/porytiles tools/eien_tileset/compile.sh eien_town eien_coast eien_shrine`
   compiles into `data/tilesets/secondary/<name>/`, then runs `make_doors.py`, which writes the
   door animations (`graphics/door_anims/eien/`) and `src/data/field_door_eien.h`
   (included by `src/field_door.c`).
4. `make`.

Porytiles 1.x (the `legacy` driver in the Porytiles repo) builds on Linux with clang and
libc++ (`apt install clang libc++-dev libc++abi-dev doxygen`), then
`cmake -S . -B build -DCMAKE_BUILD_TYPE=Release` and
`cmake --build build --target LegacyDriver` (binary: `build/legacy/tools/driver/porytiles-legacy`).

## Limits and known gaps

- Metatile ids follow the source sheet order, starting at 512. Adding pieces to `TILESETS`
  shifts later ids, which would scramble maps already painted with them: add new pieces at
  the end.
- Each tileset: at most 512 metatiles, 512 tiles, 7 palettes (checked by `--stats` and Porytiles).
- Collision is painted per map in Porymap.

## Layers

The top rows of tall pieces (the pines' top two rows, the pagoda above its base) are drawn
above the player, so the player can walk behind them; everything else is below the player.
Set per piece with the `cover` option in `TILESETS`. For the effect, paint those blocks as
passable in Porymap; tree trunks and buildings stay impassable.

## Doors

Listed in `DOORS` in `build_source.py`. A door only warps if the map has a warp event on it.

| Tileset | Metatile | Door | Behavior |
| --- | --- | --- | --- |
| `gTileset_EienTown` | `0x26A` | pink house | animated |
| `gTileset_EienTown` | `0x26E` | green shop | animated |
| `gTileset_EienTown` | `0x28A` | Pokémon Center | no animation |
| `gTileset_EienTown` | `0x2AA` | Mart | no animation |
| `gTileset_EienTown` | `0x2D3` | Gym | no animation |
| `gTileset_EienCoast` | `0x299` | beach house | no animation |
| `gTileset_EienCoast` | `0x2C9` | Japanese wooden house | no animation |
| `gTileset_EienCoast` | `0x2E1` | blue house | animated |
| `gTileset_EienCoast` | `0x2E5` | yellow shop | animated |

Animated doors use the snow pack's door frames (`Doors/DoorsSnow*.png`), colored with the door
metatile's own palettes. The Pokémon Center, Mart and Gym have sliding glass doors the pack has
no frames for; they warp without an animation. `build_source.py` prints the current ids.
