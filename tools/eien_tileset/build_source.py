#!/usr/bin/env python3
"""Assemble Porytiles source layers for Eien's secondary tilesets from community packs.

Reads the packs downloaded by tools/fetch_assets.py (build/community_assets/), cuts out the
pieces listed in TILESETS, and writes bottom/middle/top.png (dual layer: bottom + middle)
into tilesets_src/<name>/. Compile them with tools/eien_tileset/compile.sh.

Every piece keeps its layout, so buildings stay paintable as one block in Porymap.
RPG Maker "unused" marker cells (red X) and empty cells are dropped. Cells with
transparency (trees, props, eaves) get plain snow underneath so they sit on snow wherever
they're placed. Layers (dual-layer mode, inferred by Porytiles from which PNGs have content):
  normal:  snow on bottom.png, piece on middle.png (both drawn below the player)
  covered: snow on middle.png, piece on top.png (piece drawn above the player), used for the
           upper rows of tall pieces (tree tops, the pagoda spire) so the player can walk
           behind them
Door cells listed in DOORS get a door behavior in attributes.csv; animated ones are listed in
doors.json for tools/eien_tileset/make_doors.py.

  tools/eien_tileset/build_source.py            # all tilesets
  tools/eien_tileset/build_source.py --stats    # print tile/palette estimates only
"""

import argparse
import glob
import json
import os
import sys

from PIL import Image

REPO = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
PACKS = os.path.join(REPO, "build", "community_assets")
OUT = os.path.join(REPO, "tilesets_src")
WIDTH = 8  # metatiles per row, as Porymap shows them


def cinna():
    im = Image.open(os.path.join(PACKS, "cinna_snow", "SnowTileset", "CustomTilesetSnow.png")).convert("RGBA")
    return im.resize((im.width // 2, im.height // 2), Image.NEAREST)  # the sheet is an exact 2x


def johto():
    return Image.open(os.path.join(PACKS, "johto", "tileset.png")).convert("RGBA")


def ekat(name):
    return Image.open(glob.glob(os.path.join(PACKS, "ekat_tiles", "**", name + ".png"), recursive=True)[0]).convert("RGBA")


# Pieces: (sheet, first column, first row, columns, rows[, options]) in 16px metatile units.
# options: {"cover": (band, n)} splits the piece into bands of `band` rows (one object per
# band, e.g. a 3-row tree) and puts the top `n` rows of each band on the covered layer.
SOURCES = {"cinna": cinna, "johto": johto, "beach": lambda: ekat("Beach Houses")}
BASE_SNOW = ("cinna", 0, 29)  # plain snow under every see-through cell

GROUND = [
    ("cinna", 0, 23, 8, 2),    # snow tufts, small plants
    ("cinna", 0, 28, 8, 3),    # snow ground and patches
    ("cinna", 0, 31, 6, 6, {"cover": (3, 2)}),  # pines, snowy pines (3 rows tall)
]
TILESETS = {
    # Shimotsuki: snowy inland town with the first gym.
    "eien_town": GROUND + [
        ("cinna", 0, 104, 8, 3),   # small house, shop
        ("cinna", 0, 112, 5, 4),   # Pokémon Center
        ("cinna", 0, 116, 4, 4),   # Mart
        ("cinna", 0, 121, 8, 7),   # Gym
    ],
    # Hamakaze: coastal hometown.
    "eien_coast": GROUND + [
        ("beach", 0, 0, 5, 11),    # Ekat: two-story beach house
        ("johto", 26, 2, 5, 4),    # Johto: small Japanese wooden house
        ("cinna", 0, 108, 8, 3),   # small house, shop (Kashiwagi house / lab)
    ],
    # Route 1 and its shrine.
    "eien_shrine": GROUND + [
        ("cinna", 0, 0, 8, 12),    # rocky snow cliffs and ledges
        ("johto", 21, 7, 7, 14, {"cover": (14, 11)}),  # Johto: five-story pagoda
    ],
}

# Door cells: (sheet, column, row, animation). animation is "auto" to pick the closest door
# in the snow pack's Doors sheets (opens with an animation), or None for a door without one
# (MB_NON_ANIMATED_DOOR: still warps, no animation).
DOORS = {
    "eien_town": [
        ("cinna", 2, 106, "auto"),   # pink house
        ("cinna", 6, 106, "auto"),   # green shop
        ("cinna", 2, 115, None),     # Pokémon Center (sliding glass)
        ("cinna", 2, 119, None),     # Mart (sliding glass)
        ("cinna", 3, 125, None),     # Gym (glass double door)
    ],
    "eien_coast": [
        ("cinna", 1, 110, "auto"),   # blue house
        ("cinna", 5, 110, "auto"),   # yellow shop
        ("beach", 1, 8, None),       # beach house, ground floor
        ("johto", 27, 5, None),      # Japanese wooden house
    ],
    "eien_shrine": [],
}
DOOR_SHEETS = ("DoorsSnow", "DoorsSnow2")  # columns are door styles; rows closed, opening x2, open


def door_styles():
    """{"DoorsSnow:0": [closed, open1, open2, open3], ...} at 1x (the sheets are 2x)."""
    styles = {}
    for name in DOOR_SHEETS:
        im = Image.open(os.path.join(PACKS, "cinna_snow", "SnowTileset", "Doors", name + ".png")).convert("RGBA")
        im = im.resize((im.width // 2, im.height // 2), Image.NEAREST)
        for c in range(im.width // 16):
            frames = [im.crop((c * 16, r * 16, c * 16 + 16, r * 16 + 16)) for r in range(4)]
            if frames[0].getextrema()[3][1]:
                styles[f"{name}:{c}"] = frames
    return styles


def closest_style(cell, styles):
    def diff(a, b):
        return sum(1 for x, y in zip(a.getdata(), b.getdata()) if (x[3] > 0) != (y[3] > 0) or (x[3] and x[:3] != y[:3]))
    return min(styles, key=lambda k: diff(cell, styles[k][0]))


def is_marker(cell):
    """RPG Maker's red-X 'unused' cells: mostly white with bright red lines."""
    px = list(cell.getdata())
    red = sum(1 for r, g, b, a in px if a and r > 200 and g < 80 and b < 80)
    white = sum(1 for r, g, b, a in px if a and r > 230 and g > 230 and b > 230)
    return red >= 16 and red + white >= 0.8 * len(px)


def cells(sheets, piece):
    """Returns the piece's cells (None where dropped), with each cell's source position."""
    sheet, col, row, cols, rows = piece[:5]
    im = sheets[sheet]
    grid = []
    for r in range(rows):
        line = []
        for c in range(cols):
            box = ((col + c) * 16, (row + r) * 16, (col + c + 1) * 16, (row + r + 1) * 16)
            cell = im.crop(box)
            empty = cell.getextrema()[3][1] == 0
            line.append(None if empty or is_marker(cell) else (cell, (sheet, col + c, row + r), r))
        grid.append(line)
    while grid and all(c is None for c in grid[-1]):  # trim empty rows
        grid.pop()
    while grid and all(c is None for c in grid[0]):
        grid.pop(0)
    return grid


def place(grids):
    """Pack pieces into an 8-wide sheet, left to right, each piece keeping its shape."""
    placed, x, y, row_h = [], 0, 0, 0
    for grid in grids:
        w = max(len(line) for line in grid)
        if x + w > WIDTH:
            x, y, row_h = 0, y + row_h, 0
        placed.append((grid, x, y))
        x += w
        row_h = max(row_h, len(grid))
    return placed, y + row_h


def merge_colors(counts, budget):
    """Merge the two closest colors until `budget` remain. Returns {color: merged color}.
    Unlike median cut this keeps rare accents (a red sign, a door) that are far from the rest."""
    centre = {c: c for c in counts}
    weight = dict(counts)
    members = {c: [c] for c in counts}
    while len(members) > budget:
        keys = list(members)
        best = None
        for i, a in enumerate(keys):
            ca = centre[a]
            for b in keys[i + 1:]:
                cb = centre[b]
                d = (ca[0] - cb[0]) ** 2 + (ca[1] - cb[1]) ** 2 + (ca[2] - cb[2]) ** 2
                if best is None or d < best[0]:
                    best = (d, a, b)
        _, a, b = best
        wa, wb = weight[a], weight[b]
        centre[a] = tuple((x * wa + y * wb) / (wa + wb) for x, y in zip(centre[a], centre[b]))
        weight[a] = wa + wb
        members[a] += members.pop(b)
        del weight[b], centre[b]
    return {m: tuple(int(round(v)) & 0xF8 for v in centre[k]) for k, ms in members.items() for m in ms}


def snap(p):
    return tuple(v & 0xF8 for v in p[:3])  # GBA colors are 5 bits per channel


def reduce_colors(layers, palettes=7, per_palette=15, rounds=12):
    """Palette-aware reduction: group the 8x8 tiles into `palettes` families by color
    (k-means on each tile's average color), then cut each family to `per_palette` colors.
    Every tile then fits one palette, so a packing always exists."""
    tiles = []
    for layer in layers:
        for ty in range(0, layer.height, 8):
            for tx in range(0, layer.width, 8):
                px = [snap(p) for p in layer.crop((tx, ty, tx + 8, ty + 8)).getdata() if p[3]]
                if px:
                    mean = tuple(sum(c[i] for c in px) / len(px) for i in range(3))
                    tiles.append((layer, tx, ty, px, mean))
    # k-means on mean colors, seeded by spreading picks across the sorted means
    order = sorted(range(len(tiles)), key=lambda i: sum(tiles[i][4]))
    centres = [tiles[order[int(k * (len(order) - 1) / max(1, palettes - 1))]][4] for k in range(palettes)]
    group = [0] * len(tiles)
    for _ in range(rounds):
        for i, t in enumerate(tiles):
            group[i] = min(range(palettes), key=lambda k: sum((a - b) ** 2 for a, b in zip(t[4], centres[k])))
        for k in range(palettes):
            ms = [tiles[i][4] for i in range(len(tiles)) if group[i] == k]
            if ms:
                centres[k] = tuple(sum(m[j] for m in ms) / len(ms) for j in range(3))
    for k in range(palettes):
        idx = [i for i in range(len(tiles)) if group[i] == k]
        counts = {}
        for i in idx:
            for c in tiles[i][3]:
                counts[c] = counts.get(c, 0) + 1
        mapping = merge_colors(counts, per_palette)
        for i in idx:
            layer, tx, ty = tiles[i][:3]
            t = layer.crop((tx, ty, tx + 8, ty + 8))
            t.putdata([mapping[snap(p)] + (255,) if p[3] else (0, 0, 0, 0) for p in t.getdata()])
            layer.paste(t, (tx, ty))


def build(name, pieces, stats_only):
    sheets = {k: f() for k, f in SOURCES.items()}
    snow = sheets[BASE_SNOW[0]].crop((BASE_SNOW[1] * 16, BASE_SNOW[2] * 16, BASE_SNOW[1] * 16 + 16, BASE_SNOW[2] * 16 + 16))
    grids = [(cells(sheets, p), p[5] if len(p) > 5 else {}) for p in pieces]
    grids = [(g, o) for g, o in grids if g]
    placed, height = place([g for g, _ in grids])
    bottom, middle, top = (Image.new("RGBA", (WIDTH * 16, height * 16)) for _ in range(3))
    ids = {}  # source position -> metatile id (local: row-major over the 8-wide sheet)
    count = 0
    for (grid, x, y), (_, options) in zip(placed, grids):
        band, covered_rows = options.get("cover", (1, 0))
        for r, line in enumerate(grid):
            for c, item in enumerate(line):
                if item is None:
                    continue
                cell, source, piece_row = item
                count += 1
                ids[source] = (y + r) * WIDTH + x + c
                pos = ((x + c) * 16, (y + r) * 16)
                see_through = cell.getextrema()[3][0] < 255
                if see_through and piece_row % band < covered_rows:  # covered: drawn over the player
                    middle.paste(snow, pos)
                    top.paste(cell, pos)
                elif see_through:  # normal: snow below, piece above, both under the player
                    bottom.paste(snow, pos)
                    middle.paste(cell, pos)
                else:
                    bottom.paste(cell, pos)

    styles = door_styles()
    doors = []
    for sheet, col, row, anim in DOORS[name]:
        if (sheet, col, row) not in ids:
            sys.exit(f"{name}: door {(sheet, col, row)} is not in any piece")
        cell = sheets[sheet].crop((col * 16, row * 16, col * 16 + 16, row * 16 + 16))
        style = closest_style(cell, styles) if anim == "auto" else anim
        doors.append({"id": ids[(sheet, col, row)], "source": [sheet, col, row], "style": style})

    if not stats_only:
        reduce_colors((bottom, middle, top))

    # Estimates: unique 8x8 tiles (flips count as the same) and colors, per layer.
    tiles = set()
    colors = set()
    for layer in (bottom, middle, top):
        for ty in range(0, layer.height, 8):
            for tx in range(0, layer.width, 8):
                t = layer.crop((tx, ty, tx + 8, ty + 8))
                if t.getextrema()[3][1] == 0:
                    continue
                data = tuple(t.getdata())
                variants = [data, tuple(t.transpose(Image.FLIP_LEFT_RIGHT).getdata()),
                            tuple(t.transpose(Image.FLIP_TOP_BOTTOM).getdata()),
                            tuple(t.transpose(Image.ROTATE_180).getdata())]
                tiles.add(min(variants))
                colors.update(p[:3] for p in data if p[3])
    print(f"{name}: {count} metatiles (limit 512), ~{len(tiles)} unique tiles (limit 512), "
          f"{len(colors)} colors (limit 7 palettes x 15 = 105, less when tiles can't share)")
    if stats_only:
        return
    dest = os.path.join(OUT, name)
    os.makedirs(dest, exist_ok=True)
    bottom.save(os.path.join(dest, "bottom.png"))
    middle.save(os.path.join(dest, "middle.png"))
    top.save(os.path.join(dest, "top.png"))
    with open(os.path.join(dest, "attributes.csv"), "w") as f:
        f.write("id,behavior\n")
        for d in sorted(doors, key=lambda d: d["id"]):
            f.write(f"{d['id']},{'MB_ANIMATED_DOOR' if d['style'] else 'MB_NON_ANIMATED_DOOR'}\n")
    with open(os.path.join(dest, "doors.json"), "w") as f:
        json.dump([d for d in doors if d["style"]], f, indent=2)
    for d in doors:
        print(f"  door {d['source']} -> metatile {512 + d['id']:#05x} ({d['style'] or 'no animation'})")
    print(f"  wrote {os.path.relpath(dest, REPO)}/{{bottom,middle,top}}.png ({bottom.width}x{bottom.height}), attributes.csv, doors.json")


def main():
    parser = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    parser.add_argument("names", nargs="*", default=list(TILESETS))
    parser.add_argument("--stats", action="store_true")
    args = parser.parse_args()
    if not os.path.isdir(PACKS):
        sys.exit("run tools/fetch_assets.py first")
    for name in args.names:
        build(name, TILESETS[name], args.stats)


if __name__ == "__main__":
    main()
