#!/usr/bin/env python3
"""Party-menu icons for the Eien forms, and the Eien icon palette (icon palette 6).

The six vanilla icon palettes have no teal, violet or warm ash, so the starters' icons share a
seventh palette built from their AI drafts (design/art/eien_starters_drafts.md, "Icons"):

  graphics/pokemon/icon_palettes/pal6.pal    15 colors clustered from the drafts below
  graphics/pokemon/eien/<species>/icon.png   32x64 (two frames), indexed with its palette

Drafts are the raw model output (design/art/eien_<species>/icon_drafts/raw/): a 32x64 strip in
the middle of a 64-cell grid, sampled like the other sprites. A draft whose frame 2 came out
wrong gets frame 1 moved down 1px instead (the hop the original icons use). Species with a
ready indexed icon in one of the vanilla palettes (ICON_READY) are copied as they are.
  tools/eien_species/make_icons.py
"""

import os
import sys

from PIL import Image

HERE = os.path.dirname(os.path.abspath(__file__))
REPO = os.path.dirname(os.path.dirname(HERE))
sys.path.insert(0, os.path.join(REPO, "tools", "sprite_prep"))
import sprite_prep  # noqa: E402

EIEN_ICON_PALETTE = 6
# species: (raw draft, make frame 2 from frame 1)
ICON_PICKS = {
    "torchic": ("icon_gemini3pro_a.png", False),
    "bulbasaur": ("icon_gemini3pro_c.png", True),
    "froakie": ("icon_gemini3pro_a.png", False),
}
# species: (indexed icon in design/art/eien_<species>/icon_drafts/, vanilla icon palette)
ICON_READY = {
    "poochyena": ("icon_gemini3pro_a.png", 5),
}


def sample_strip(path):
    """The 32x64 strip (two 32x32 frames) as RGBA, background transparent."""
    grid = sprite_prep.sample_grid(path, 64).crop((16, 0, 48, 64))
    frames = []
    for top in (0, 32):
        frame = grid.crop((0, top, 32, top + 32))
        bg = sprite_prep.background_mask(frame)
        rgba = frame.convert("RGBA")
        for x, y in bg:
            rgba.putpixel((x, y), (0, 0, 0, 0))
        frames.append(rgba)
    return frames


def main():
    strips = {}
    for species, (draft, hop) in ICON_PICKS.items():
        f1, f2 = sample_strip(os.path.join(REPO, "design", "art", f"eien_{species}", "icon_drafts", "raw", draft))
        if hop:
            f2 = Image.new("RGBA", (32, 32))
            f2.paste(f1.crop((0, 0, 32, 31)), (0, 1))
        strips[species] = (f1, f2)

    palette = sprite_prep.build_palette([f for pair in strips.values() for f in pair], 15)
    sprite_prep.write_jasc(os.path.join(REPO, "graphics", "pokemon", "icon_palettes", f"pal{EIEN_ICON_PALETTE}.pal"), palette)
    for species, (f1, f2) in strips.items():
        icon = Image.new("P", (32, 64))
        icon.putpalette([c for rgb in palette for c in rgb] + [0] * (768 - 3 * len(palette)))
        icon.paste(sprite_prep.index(f1, palette), (0, 0))
        icon.paste(sprite_prep.index(f2, palette), (0, 32))
        path = os.path.join(REPO, "graphics", "pokemon", "eien", species, "icon.png")
        icon.save(path)
        problems = sprite_prep.check(path, (32, 64))
        if problems:
            raise SystemExit(f"{species}/icon.png: {', '.join(problems)}")
        print(f"{species}: {ICON_PICKS[species][0]} -> icon.png (icon palette {EIEN_ICON_PALETTE})")

    for species, (draft, pal) in ICON_READY.items():
        icon = Image.open(os.path.join(REPO, "design", "art", f"eien_{species}", "icon_drafts", draft))
        icon.save(os.path.join(REPO, "graphics", "pokemon", "eien", species, "icon.png"))
        print(f"{species}: {draft} -> icon.png (icon palette {pal})")


if __name__ == "__main__":
    main()
