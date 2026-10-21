#!/usr/bin/env python3
"""Shiny palette drafts for the Eien forms: a few deliberate recolors per form, for review.

Each concept recolors groups of palette indices (body, glow, accents): the group's colors get a
new hue and saturation while keeping their own lightness, so shading survives. Writes
design/art/eien_<species>/shiny_drafts/<concept>.pal and a contact sheet,
design/art/eien_shiny_contact_sheet.png (normal, then each concept; front and back).
  tools/eien_species/shiny_drafts.py
"""

import colorsys
import os
import sys

from PIL import Image, ImageDraw

HERE = os.path.dirname(os.path.abspath(__file__))
REPO = os.path.dirname(os.path.dirname(HERE))
sys.path.insert(0, os.path.join(REPO, "tools", "sprite_prep"))
import sprite_prep  # noqa: E402

# species: {concept: [(indices, hue in degrees, saturation, lightness shift)]}
CONCEPTS = {
    "torchic": {
        # the lantern flame burns warm, like the original Torchic's colors
        "ember": [((6, 7, 8, 11), 30, 0.85, 0.0)],
        # a lantern at night: slate body, violet flame
        "night_lantern": [((5, 9, 10, 12, 13, 14), 225, 0.18, -0.12), ((6, 7, 8, 11), 285, 0.7, 0.0)],
        # rice-paper lantern: warm peach body, red flame
        "paper_lantern": [((5, 9, 10, 12, 13, 14), 25, 0.45, 0.04), ((6, 7, 8, 11), 355, 0.75, -0.05)],
    },
    "bulbasaur": {
        # a rare red aurora in the bulb
        "red_aurora": [((5, 8, 9, 11, 12, 13), 340, 0.65, 0.0)],
        # twilight: lavender body, golden-green bulb
        "twilight": [((2, 3, 4, 6, 7, 10), 265, 0.35, 0.0), ((5, 8, 9, 11, 12, 13), 70, 0.6, 0.0)],
        # faded: pale mint body, blue bulb
        "faded": [((2, 3, 4, 6, 7, 10), 150, 0.25, 0.08), ((5, 8, 9, 11, 12, 13), 215, 0.6, 0.0)],
    },
    "froakie": {
        # pink snow
        "pink_snow": [((5, 6, 7, 8, 10, 12), 330, 0.55, 0.0), ((1, 2, 4), 300, 0.45, 0.0)],
        # midnight: a dark body with a white frost scarf
        "midnight": [((5, 6, 7, 8, 10), 228, 0.55, -0.3)],
        # golden ice: cream body, red eyes
        "golden_ice": [((5, 6, 7, 8, 10, 12), 45, 0.55, 0.0), ((11, 13, 14), 355, 0.75, -0.1)],
    },
    "poochyena": {
        # granite: grey stone, purple bib
        "granite": [((2, 10, 14), 220, 0.08, 0.0), ((3, 7, 12), 280, 0.55, 0.0)],
        # jade: green jade stone, gold bib
        "jade": [((2, 10, 14), 150, 0.35, 0.0), ((3, 7, 12), 45, 0.75, 0.05)],
        # obsidian: black glassy stone, bright violet cracks
        "obsidian": [((2, 10, 14), 250, 0.12, -0.35), ((5, 8, 9, 11, 13), 280, 0.9, 0.05)],
    },
    "mightyena": {
        # obsidian, like Eien Poochyena's shiny: black glassy stone, bright violet cracks
        "obsidian": [((6, 9, 12), 250, 0.12, -0.35), ((2, 4), 250, 0.12, -0.08), ((8, 11), 280, 0.9, 0.05)],
        # jade: green jade stone, gold bib
        "jade": [((6, 9, 12), 150, 0.35, 0.0), ((2, 4), 160, 0.3, 0.0), ((3, 7, 10), 45, 0.75, 0.05)],
        # moonstone: pale white stone, indigo bib, violet cracks
        "moonstone": [((6, 9, 12), 220, 0.12, 0.18), ((2, 4), 230, 0.15, 0.05), ((3, 7, 10), 245, 0.55, 0.0)],
    },
    # the middle stages carry their first stage's shiny up the line, plus one alternative each
    "combusken": {
        "night_lantern": [((5, 7, 11, 13, 14), 225, 0.18, -0.12), ((4, 6, 8, 9, 12), 285, 0.7, 0.0)],
        "paper_lantern": [((5, 7, 11, 13, 14), 25, 0.45, 0.04), ((4, 6, 8, 9, 12), 355, 0.75, -0.05)],
    },
    "ivysaur": {
        "twilight": [((2, 3, 6, 8, 11), 265, 0.35, 0.0), ((4, 5, 7, 9, 10, 12, 13), 70, 0.6, 0.0)],
        "red_aurora": [((4, 5, 7, 9, 12, 13), 340, 0.65, 0.0)],
    },
    "frogadier": {
        "midnight": [((3, 4, 5, 7, 10), 228, 0.55, -0.3)],
        "golden_ice": [((3, 4, 5, 7, 10), 45, 0.55, 0.0)],
    },
    # the finals carry their line's shiny theme (night lantern, twilight, midnight)
    "blaziken": {
        "night_lantern": [((5, 7, 10, 13, 14), 225, 0.18, -0.12), ((2, 4, 8, 11), 285, 0.7, 0.0)],
    },
    "venusaur": {
        "twilight": [((2, 3, 6, 9), 265, 0.35, 0.0), ((5, 8, 10, 11), 70, 0.6, 0.0)],
    },
    "greninja": {
        "midnight": [((3, 5, 6, 8, 10), 228, 0.55, -0.3)],
    },
    "wooper": {
        # gold ore (variants.md): the copper flecks turn bright gold on the dark slate body
        "gold_flecks": [((4, 5, 8, 9, 12, 13, 15), 46, 0.85, 0.05)],
        # a gold crust all over: dark gold body, bright gold flecks, pale gold fins
        "gold_crust": [((2, 3, 7), 40, 0.45, 0.12), ((4, 5, 8, 9, 12, 13, 15), 48, 0.9, 0.08),
                       ((6, 10, 11), 50, 0.4, 0.05)],
    },
    "quagsire": {
        # a gilded kettle (variants.md): the whole body gold, the outline kept dark
        "gilded": [((3, 4, 7, 8, 11, 12, 13, 14, 15), 44, 0.7, 0.18), ((5, 6, 9, 10), 38, 0.6, 0.12)],
        # gold leaf on iron: the highlights and hobnails gold, the body iron
        "gold_leaf": [((12, 13, 14, 15), 46, 0.85, 0.08), ((9, 10), 44, 0.6, 0.05)],
    },
    "hoothoot": {
        # aurora mist (variants.md): green mist wings, violet where the mist meets the body
        "aurora": [((11, 12, 13), 150, 0.5, 0.0), ((10,), 280, 0.3, 0.0)],
        # the same mist on a violet-grey body
        "aurora_dusk": [((11, 12, 13), 150, 0.5, 0.0), ((10,), 280, 0.3, 0.0),
                        ((3, 4, 5, 6, 7, 8, 9), 275, 0.22, 0.0)],
    },
    "noctowl": {
        # aurora mist: veils green at the hems, violet near the body
        "aurora": [((12, 13), 150, 0.5, 0.0), ((10, 11), 278, 0.35, 0.0)],
        "aurora_dusk": [((12, 13), 150, 0.5, 0.0), ((10, 11), 278, 0.35, 0.0),
                        ((3, 4, 5, 6, 7, 8, 9), 275, 0.22, 0.0)],
    },
}


def recolor(palette, rules):
    out = list(palette)
    for indices, hue, sat, light in rules:
        for i in indices:
            _, l, _ = colorsys.rgb_to_hls(*(c / 255 for c in palette[i]))
            rgb = colorsys.hls_to_rgb(hue / 360, min(1, max(0, l + light)), sat)
            out[i] = sprite_prep.snap(tuple(round(c * 255) for c in rgb))
    return out


def render(img, palette, scale=2):
    rgba = Image.new("RGBA", img.size, (0, 0, 0, 0))
    rgba.putdata([(*palette[p], 255) if p else (0, 0, 0, 0) for p in sprite_prep.pixels(img)])
    return rgba.resize((img.width * scale, img.height * scale), Image.NEAREST)


def main():
    cell_w, cell_h, label_w = 2 * 128 + 8, 128 + 16, 80
    width = label_w + cell_w * (1 + max(len(c) for c in CONCEPTS.values()))
    sheet = Image.new("RGB", (width, 20 + cell_h * len(CONCEPTS)), (236, 236, 232))
    draw = ImageDraw.Draw(sheet)
    draw.text((6, 4), "Eien shiny palette drafts (PROPOSALS). Normal, then each concept; front and back.", fill=(20, 20, 20))
    for row, (species, concepts) in enumerate(CONCEPTS.items()):
        base = os.path.join(REPO, "graphics", "pokemon", "eien", species)
        normal = sprite_prep.read_jasc(os.path.join(base, "normal.pal"))
        front = Image.open(os.path.join(base, "anim_front.png")).crop((0, 0, 64, 64))
        back = Image.open(os.path.join(base, "back.png"))
        out_dir = os.path.join(REPO, "design", "art", f"eien_{species}", "shiny_drafts")
        os.makedirs(out_dir, exist_ok=True)
        y = 20 + row * cell_h
        draw.text((6, y + 56), species, fill=(20, 20, 20))
        for col, (name, palette) in enumerate([("normal", normal)] + [(n, recolor(normal, r)) for n, r in concepts.items()]):
            if name != "normal":
                sprite_prep.write_jasc(os.path.join(out_dir, f"{name}.pal"), palette)
            x = label_w + col * cell_w
            sheet.paste((152, 208, 160), (x, y, x + cell_w - 8, y + 128))
            for k, img in enumerate((front, back)):
                rendered = render(img, palette)
                sheet.paste(rendered, (x + k * 128, y), rendered)
            draw.text((x, y + 129), name, fill=(20, 20, 20))
    sheet.save(os.path.join(REPO, "design", "art", "eien_shiny_contact_sheet.png"))
    print("design/art/eien_shiny_contact_sheet.png")


if __name__ == "__main__":
    main()
