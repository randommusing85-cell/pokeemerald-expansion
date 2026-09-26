#!/usr/bin/env python3
"""Placeholder palettes for the Eien forms: the original species' palettes, recolored to hint
at the new typing (design/variants.md). The forms reuse the original sprites until their own
art is drawn; only these palettes differ.

Writes graphics/pokemon/eien/<species>/normal.pal and shiny.pal from graphics/pokemon/<species>/,
for species that don't have chosen art yet (convert_art.py). LOOKS is also used by
convert_art.py to recolor the placeholder back sprites.
Rerunning always gives the same result.
  tools/eien_species/placeholder_palettes.py
"""

import colorsys
import os

REPO = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))

# species: (hue shift in turns, saturation factor, lightness shift)
LOOKS = {
    "torchic": (0.58, 0.55, 0.06),    # orange to a pale blue-violet ghost flame
    "bulbasaur": (0.12, 0.75, 0.05),  # green-teal to a cool aurora teal
    "froakie": (-0.03, 0.45, 0.12),   # blue to a pale icy blue
    "poochyena": (0.08, 0.35, 0.02),  # grey-black to a warm stone grey
}


def read_jasc(path):
    words = open(path).read().split()[3:]
    return [tuple(int(v) for v in words[i * 3:i * 3 + 3]) for i in range(len(words) // 3)]


def write_jasc(path, palette):
    os.makedirs(os.path.dirname(path), exist_ok=True)
    with open(path, "w", newline="\r\n") as f:
        f.write(f"JASC-PAL\n0100\n{len(palette)}\n" + "".join(f"{r} {g} {b}\n" for r, g, b in palette))


def shift(color, hue, sat, light):
    h, l, s = colorsys.rgb_to_hls(*(c / 255 for c in color))
    r, g, b = colorsys.hls_to_rgb((h + hue) % 1, min(1, max(0, l + light)), min(1, s * sat))
    return tuple(round(c * 255) for c in (r, g, b))


def main():
    from convert_art import PICKS  # species with chosen art get their palettes from there

    for species, look in LOOKS.items():
        if species in PICKS:
            continue
        for name in ("normal.pal", "shiny.pal"):
            palette = read_jasc(os.path.join(REPO, "graphics/pokemon", species, name))
            # Index 0 is transparency: keep it.
            out = [palette[0]] + [shift(c, *look) for c in palette[1:]]
            write_jasc(os.path.join(REPO, "graphics/pokemon/eien", species, name), out)
        print(f"{species}: graphics/pokemon/eien/{species}/normal.pal, shiny.pal")


if __name__ == "__main__":
    main()
