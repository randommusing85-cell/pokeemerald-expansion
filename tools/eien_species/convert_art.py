#!/usr/bin/env python3
"""Turn the chosen draft front sprites into the Eien forms' sprites (design/variants.md).

For each species in PICKS:
  graphics/pokemon/eien/<species>/anim_front.png  the chosen front (design/art/eien_<species>/
                                                  converted/), 2 frames; frame 2 is frame 1
                                                  raised 1px (placeholder animation)
  graphics/pokemon/eien/<species>/normal.pal      the draft's 16 colors, shared by front and back
  graphics/pokemon/eien/<species>/shiny.pal       an automatic hue shift (placeholder)
  graphics/pokemon/eien/<species>/back.png        placeholder: the original back sprite, each
                                                  color replaced by the draft color covering the
                                                  same pixels on the front
Icons stay the originals for now. Species not in PICKS keep their placeholder palettes
(placeholder_palettes.py).
  tools/eien_species/convert_art.py
"""

import colorsys
import math
import os
import sys

from PIL import Image

HERE = os.path.dirname(os.path.abspath(__file__))
REPO = os.path.dirname(os.path.dirname(HERE))
sys.path.insert(0, os.path.join(REPO, "tools", "sprite_prep"))
sys.path.insert(0, HERE)
import sprite_prep  # noqa: E402
from placeholder_palettes import LOOKS, shift  # noqa: E402

# species: (chosen front sprite, its palette) in design/art/eien_<species>/converted/
# (design/art/eien_starters_drafts.md, design/art/eien_poochyena/README.md)
PICKS = {
    "torchic": ("front_gemini3pro_r2_b.png", "front_gemini3pro_r2_b.pal"),
    "bulbasaur": ("front_gemini3pro_r2_b.png", "front_gemini3pro_r2_b.pal"),
    "froakie": ("front_gemini3pro_r2_b.png", "front_gemini3pro_r2_b.pal"),
    "poochyena": ("anim_front.png", "normal.pal"),  # the sprite test's front
}
SHINY_HUE = 0.5


def lightness(rgb):
    return colorsys.rgb_to_hls(*(c / 255 for c in rgb))[1]


def main():
    for species, (front_file, palette_file) in PICKS.items():
        art = os.path.join(REPO, "design", "art", f"eien_{species}", "converted")
        out = os.path.join(REPO, "graphics", "pokemon", "eien", species)
        os.makedirs(out, exist_ok=True)

        front = Image.open(os.path.join(art, front_file)).crop((0, 0, 64, 64))  # frame 1
        palette = sprite_prep.read_jasc(os.path.join(art, palette_file))
        palette = palette + [(0, 0, 0)] * (16 - len(palette))
        front.putpalette([c for rgb in palette for c in rgb] + [0] * (768 - 48))
        sprite_prep.stack_frames(front).save(os.path.join(out, "anim_front.png"))

        # Back: the original back sprite, each original color replaced by the draft color that
        # covers the same pixels on the front (the drafts keep the original's framing). Colors
        # the fronts don't share fall back to the placeholder recolor snapped to the palette.
        back = Image.open(os.path.join(REPO, "graphics", "pokemon", species, "back.png"))
        old = sprite_prep.read_jasc(os.path.join(REPO, "graphics", "pokemon", species, "normal.pal"))
        original_front = Image.open(os.path.join(REPO, "graphics", "pokemon", species, "anim_front.png")).crop((0, 0, 64, 64))
        votes = {}
        for a, b in zip(original_front.getdata(), front.getdata()):
            if a and b:
                votes.setdefault(a, {}).setdefault(b, 0)
                votes[a][b] += 1
        remap = [0]
        for i, color in enumerate(old[1:], start=1):
            if i in votes:
                # Prefer candidates about as light as the original color: outlines drawn over a
                # white area shouldn't turn it dark.
                remap.append(max(votes[i], key=lambda j: votes[i][j] * math.exp(-abs(lightness(palette[j]) - lightness(color)) / 0.25)))
            else:
                remap.append(sprite_prep.nearest(shift(color, *LOOKS[species]), palette))
        new_back = Image.new("P", back.size)
        new_back.putpalette([c for rgb in palette for c in rgb] + [0] * (768 - 48))
        new_back.putdata([remap[i] if i < len(remap) else 0 for i in back.getdata()])
        new_back.save(os.path.join(out, "back.png"))

        sprite_prep.write_jasc(os.path.join(out, "normal.pal"), palette)
        sprite_prep.write_jasc(os.path.join(out, "shiny.pal"), sprite_prep.shiny_palette(palette, SHINY_HUE, 0.0))
        for name, size in (("anim_front.png", (64, 128)), ("back.png", (64, 64))):
            problems = sprite_prep.check(os.path.join(out, name), size)
            if problems:
                raise SystemExit(f"{species}/{name}: {', '.join(problems)}")
        print(f"{species}: {front_file} -> graphics/pokemon/eien/{species}/")


if __name__ == "__main__":
    main()
