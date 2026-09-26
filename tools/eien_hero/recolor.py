#!/usr/bin/env python3
"""Recolor the player (Brendan's sprites) into Eien's hero: dark hair, grey hoodie, jeans.

Every player sprite shares two palettes: one for all overworld sheets (walking, running,
bikes, surfing, fishing, field moves, underwater, watering, decorating) and one for the battle
front and back sprites. Recoloring them changes the hero everywhere at once; the pixels stay
Brendan's. Writes:

  graphics/object_events/palettes/brendan.pal             overworld
  graphics/object_events/palettes/brendan_reflection.pal  water reflection (same offsets as vanilla)
  graphics/trainers/palettes/brendan.pal                  battle front and back
  graphics/pokenav/region_map/brendan_icon.png            region map head (palette only)

The vanilla palettes are kept below, so rerunning always gives the same result.
  tools/eien_hero/recolor.py
"""

import os

from PIL import Image

REPO = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))

# Vanilla Emerald palettes (index 0 is transparency).
VANILLA_OW = [(115, 197, 164), (255, 213, 180), (255, 197, 148), (222, 148, 115), (123, 65, 65), (57, 74, 123),
              (41, 57, 98), (24, 41, 82), (16, 32, 57), (222, 230, 238), (115, 205, 115), (74, 148, 82),
              (255, 98, 90), (197, 65, 65), (255, 255, 255), (0, 0, 0)]
VANILLA_OW_REFLECTION = [(148, 230, 230), (255, 238, 213), (255, 213, 213), (238, 180, 180), (172, 156, 164),
                         (164, 164, 180), (106, 123, 148), (106, 123, 148), (123, 131, 131), (238, 238, 255),
                         (164, 246, 156), (123, 205, 123), (255, 156, 156), (230, 123, 139), (255, 255, 255),
                         (106, 115, 106)]
VANILLA_TRAINER = [(115, 197, 164), (255, 222, 205), (222, 164, 148), (205, 131, 115), (123, 90, 82), (98, 123, 156),
                   (74, 90, 131), (49, 65, 106), (24, 41, 82), (222, 230, 238), (139, 222, 115), (98, 156, 90),
                   (255, 98, 90), (197, 65, 65), (255, 255, 255), (0, 0, 0)]


def hexes(*values):
    return [tuple(int(v[i:i + 2], 16) for i in (0, 2, 4)) for v in values]


# Look A (design/characters.md): palette indices -> new colors, lightest first.
LOOK = {
    (9, 14): hexes("5a4a42", "3a2e2a"),                        # Brendan's white cap -> dark hair
    (4,): hexes("2a211e"),                                     # hair under the cap
    (12, 13): hexes("b8bcc4", "8a8e98"),                       # red shirt panels -> grey hoodie
    (10, 11): hexes("6a6e78", "4a4e58"),                       # green headband and strap -> grey
    (5, 6, 7, 8): hexes("4a6aa4", "3a5890", "2c4678", "1e3060"),  # navy outfit -> denim blue
}


def recolor(base):
    """Apply LOOK: within each group, the original lightest index gets the new lightest color."""
    out = list(base)
    for indices, colors in LOOK.items():
        for rank, i in enumerate(sorted(indices, key=lambda i: -sum(base[i]))):
            out[i] = colors[min(rank, len(colors) - 1)]
    return out


def write_jasc(path, palette):
    with open(os.path.join(REPO, path), "w", newline="\r\n") as f:
        f.write("JASC-PAL\n0100\n16\n" + "".join(f"{r} {g} {b}\n" for r, g, b in palette))


def main():
    ow = recolor(VANILLA_OW)
    trainer = recolor(VANILLA_TRAINER)
    # Reflection: keep vanilla's per-color offset from the overworld palette.
    reflection = [tuple(max(0, min(255, n + (r - o))) for n, r, o in zip(new, refl, old))
                  for new, refl, old in zip(ow, VANILLA_OW_REFLECTION, VANILLA_OW)]
    reflection[0] = VANILLA_OW_REFLECTION[0]
    write_jasc("graphics/object_events/palettes/brendan.pal", ow)
    write_jasc("graphics/object_events/palettes/brendan_reflection.pal", reflection)
    write_jasc("graphics/trainers/palettes/brendan.pal", trainer)
    icon_path = os.path.join(REPO, "graphics/pokenav/region_map/brendan_icon.png")
    icon = Image.open(icon_path)
    icon.putpalette([c for rgb in ow for c in rgb] + icon.getpalette()[48:])
    icon.save(icon_path)
    print("recolored the player: overworld, reflection, battle and region map palettes")


if __name__ == "__main__":
    main()
