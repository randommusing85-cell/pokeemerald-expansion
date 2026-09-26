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
   compiles into `data/tilesets/secondary/<name>/`.
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
- All metatiles use the normal layer (both layers below the player) and the default
  behavior. Doors don't animate or warp yet, and tree tops don't cover the player.
  Collision is painted per map in Porymap.
