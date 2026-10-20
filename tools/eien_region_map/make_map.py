#!/usr/bin/env python3
"""Draws the placeholder Eien region map (design/brainstorm-region-map.md) for the Town Map.

Writes graphics/pokenav/region_map/map.png (the 8bpp tileset, in the vanilla map's palette) and
map.bin (the 64x64 affine tilemap, one byte per tile), and the Eien sections' cells in
src/data/region_map/region_map_layout.h and region_map_sections.json. Each map cell is one 8x8
tile, at tile (x + 1, y + 2). Snow land, grey peaks, road bands that join their neighbours, and
the vanilla town dots, sea and deep-water tiles (from vanilla_map.png, a copy of the vanilla
tileset, since map.png is overwritten). A placeholder: AI-drafted art comes later.
  python3 tools/eien_region_map/make_map.py
"""
import json
import os
import re
from PIL import Image

REPO = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
GFX = REPO + '/graphics/pokenav/region_map/'
LAYOUT_H = REPO + '/src/data/region_map/region_map_layout.h'
SECTIONS = REPO + '/src/data/region_map/region_map_sections.json'

MAP_W, MAP_H = 28, 15
OFF_X, OFF_Y = 1, 2  # MAPCURSOR_X_MIN, MAPCURSOR_Y_MIN

# The sketch (design/brainstorm-region-map.md). ~ sea, . land, ^ mountains, = route, o lake,
# r the line only Kumo travels (dashed), * surf spot; letters are places (see RED / BLUE).
SKETCH = """\
~~~~~~~~~~~~~~~~~~~~~~~~~~~~
~~~~~~~~~~~~~~~~~~~~~~~~~~~~
~~~~~~~~~~*~~~~~~~~~==U...~~
~~.......I..........=.=...~~
~~.Y==========Crrr..=.=T..~~
~~.=.^^^^^^^^^^..r..=.WooL~~
~~.=.^^^^^^^^^^..r..=.....~~
~~.=.^^^^^^^^^^..rO==.....~~
~~.=.^^^^^^^^^^...=..~~~~~~~
~~.u..............=..~~~~~~~
~~.S=====K==M======..~~~~~~~
~~.=.................~~~~~~~
~~.=.................~~~~~~~
~~.H.................~~~~~~~
~~~~~~*~~~~~~~~~~~~~~~~~~~~~"""
# Red dots: towns with a gym, and the League. Blue: the rest. (u: Lake Usurai, drawn as a lake.)
RED = set('SYICKOUWL')
BLUE = set('HMT')
ROAD_LIKE = set('=r') | RED | BLUE

# Places that exist in the game: section, cells (x, y, width, height). Others are drawn, not named.
EIEN_SECTIONS = {
    'MAPSEC_HAMAKAZE': (3, 13, 1, 1),
    'MAPSEC_EIEN_ROUTE1': (3, 11, 1, 2),
    'MAPSEC_SHIMOTSUKI': (3, 10, 1, 1),
    'MAPSEC_EIEN_ROUTE2': (3, 9, 1, 1),  # Lake Usurai
    'MAPSEC_YUNOTAKI': (3, 4, 1, 1),
}

# Colours in the vanilla map palette (PNG indices)
SEA_A, SEA_B = 113, 114
DEEP_A, DEEP_B = 116, 117
WHITE, LIGHT_GREY, DARK_GREY = 129, 139, 140
ROAD = 133
BLACK = 128


def vanilla_tile(src, i):
    return [[src.getpixel(((i % 16) * 8 + x, (i // 16) * 8 + y)) for x in range(8)] for y in range(8)]


def solid(c):
    return [[c] * 8 for _ in range(8)]


def snow():
    t = solid(WHITE)
    for x, y in ((1, 2), (5, 1), (3, 5), (6, 6), (0, 7)):
        t[y][x] = LIGHT_GREY
    return t


def peak():
    t = snow()
    for y in range(2, 8):
        half = y - 1
        for x in range(4 - half, 4 + half):
            if 0 <= x < 8:
                t[y][x] = DARK_GREY if x < 4 else LIGHT_GREY
    t[2][3] = t[2][4] = WHITE  # snow on the summit
    return t


def road(n, e, s, w):
    """A road band (cols/rows 2-5) from the centre toward each connected side, on snow."""
    t = snow()
    def fill(x0, x1, y0, y1):
        for y in range(y0, y1):
            for x in range(x0, x1):
                t[y][x] = ROAD
    fill(2, 6, 2, 6)
    if n: fill(2, 6, 0, 2)
    if s: fill(2, 6, 6, 8)
    if w: fill(0, 2, 2, 6)
    if e: fill(6, 8, 2, 6)
    return t


def dashed(n, e, s, w):
    """The ring's line (travelled only by Kumo): the road band in dashes."""
    t = road(n, e, s, w)
    for y in range(8):
        for x in range(8):
            if t[y][x] == ROAD and ((x + y) // 2) % 2:
                t[y][x] = WHITE
    return t


def islet():
    """A snowy rock in the sea."""
    t = [[SEA_A if y % 2 == 0 else SEA_B for _ in range(8)] for y in range(8)]
    for y, (x0, x1) in ((3, (3, 5)), (4, (2, 6)), (5, (2, 6))):
        for x in range(x0, x1):
            t[y][x] = WHITE
    t[5][2] = t[5][3] = DARK_GREY
    return t


def main():
    src = Image.open(os.path.dirname(os.path.abspath(__file__)) + '/vanilla_map.png')
    palette = src.getpalette()
    rows = SKETCH.split('\n')
    assert len(rows) == MAP_H and all(len(r) == MAP_W for r in rows), 'sketch size'

    tiles = []      # tile pixel grids
    index = {}      # key -> tile id
    def tile_id(key, make):
        if key not in index:
            index[key] = len(tiles)
            tiles.append(make())
        return index[key]

    sea = tile_id('sea', lambda: vanilla_tile(src, 0))
    def cell(x, y):
        if 0 <= x < MAP_W and 0 <= y < MAP_H:
            return rows[y][x]
        return '~'
    def conn(x, y):
        return cell(x, y) in ROAD_LIKE or cell(x, y) == 'u'

    tilemap = bytearray([sea] * (64 * 64))
    for y in range(MAP_H):
        for x in range(MAP_W):
            c = rows[y][x]
            if c == '~':
                t = sea
            elif c == '.':
                t = tile_id('snow', snow)
            elif c == '^':
                t = tile_id('peak', peak)
            elif c in ('o', 'u'):
                t = tile_id('deep', lambda: vanilla_tile(src, 77))
            elif c == '*':
                t = tile_id('islet', islet)
            elif c == '=':
                key = (conn(x, y - 1), conn(x + 1, y), conn(x, y + 1), conn(x - 1, y))
                t = tile_id(('road',) + key, lambda k=key: road(*k))
            elif c == 'r':
                key = (conn(x, y - 1), conn(x + 1, y), conn(x, y + 1), conn(x - 1, y))
                t = tile_id(('dashed',) + key, lambda k=key: dashed(*k))
            elif c in RED:
                t = tile_id('red', lambda: vanilla_tile(src, 20))
            elif c in BLUE:
                t = tile_id('blue', lambda: vanilla_tile(src, 13))
            else:
                raise SystemExit(f'unknown cell {c!r} at {x},{y}')
            tilemap[(y + OFF_Y) * 64 + x + OFF_X] = t

    # The tileset image: 16 tiles a row, 15 rows (the build takes the first 233)
    out = Image.new('P', (128, 120), BLACK)
    out.putpalette(palette)
    for i, t in enumerate(tiles):
        for y in range(8):
            for x in range(8):
                out.putpixel(((i % 16) * 8 + x, (i // 16) * 8 + y), t[y][x])
    out.save(GFX + 'map.png')
    open(GFX + 'map.bin', 'wb').write(bytes(tilemap))

    # Sections: Eien's places at their cells; every other cell has none
    grid = [['MAPSEC_NONE'] * MAP_W for _ in range(MAP_H)]
    for sec, (x, y, w, h) in EIEN_SECTIONS.items():
        for yy in range(y, y + h):
            for xx in range(x, x + w):
                grid[yy][xx] = sec
    text = open(LAYOUT_H).read()
    body = ',\n'.join('    {' + ', '.join(r) + '}' for r in grid)
    text = re.sub(r'(sRegionMap_MapSectionLayout\[MAP_HEIGHT\]\[MAP_WIDTH\] = \{\n)(.*?)(\n\};)',
                  lambda m: m.group(1) + body + ',' + m.group(3), text, count=1, flags=re.S)
    text = re.sub(r'// Eien: placeholder spots.*?squares\.\n',
                  '// Eien: the Eien region map (design/brainstorm-region-map.md), written by\n'
                  '// tools/eien_region_map/make_map.py. Only places that exist have sections.\n',
                  text, count=1, flags=re.S)
    open(LAYOUT_H, 'w').write(text)

    data = json.load(open(SECTIONS))
    for s in data['map_sections']:
        if s['id'] in EIEN_SECTIONS:
            s['x'], s['y'], s['width'], s['height'] = EIEN_SECTIONS[s['id']]
    with open(SECTIONS, 'w') as f:
        json.dump(data, f, indent=2, ensure_ascii=False)
        f.write('\n')
    print(f'{len(tiles)} tiles')


if __name__ == '__main__':
    main()
