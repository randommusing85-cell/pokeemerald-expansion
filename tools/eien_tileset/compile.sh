#!/bin/sh
# Compile tilesets_src/<name> into data/tilesets/secondary/<name> with Porytiles 1.x.
# The empty primary makes the secondary self-contained: it never references the real
# primary's tiles or palettes, so it works with gTileset_General unchanged.
#   PORYTILES=/path/to/porytiles tools/eien_tileset/compile.sh eien_town eien_coast eien_shrine
set -e
cd "$(dirname "$0")/../.."
PORYTILES=${PORYTILES:-porytiles}
EMPTY=tools/eien_tileset/empty_primary
for name in "$@"; do
    "$PORYTILES" compile-secondary -dual-layer -o "data/tilesets/secondary/$name" \
        "tilesets_src/$name" "$EMPTY" include/constants/metatile_behaviors.h
    # The engine's palette table has 16 entries; Porytiles writes 00-12. Pad with blanks.
    for i in 13 14 15; do
        pal="data/tilesets/secondary/$name/palettes/$i.pal"
        [ -f "$pal" ] || { printf 'JASC-PAL\r\n0100\r\n16\r\n'; for c in $(seq 16); do printf '0 0 0\r\n'; done; } > "$pal"
    done
    echo "$name: compiled to data/tilesets/secondary/$name"
done
