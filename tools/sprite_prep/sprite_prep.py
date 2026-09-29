#!/usr/bin/env python3
"""Turn upscaled pixel-art drafts (e.g. AI output) into GBA-ready Pokémon sprite files.

Input drafts are pixel art drawn on a 64x64 grid and enlarged (any scale), on a plain,
near-white background. Output, in --out:

  anim_front.png  64x128 indexed, 2 frames (frame 2 is frame 1 raised 1px: a placeholder)
  back.png        64x64 indexed
  normal.pal      JASC palette shared by front and back (index 0 = transparent)
  shiny.pal       normal.pal with a hue shift (colors near --keep-hue are left alone)
  icon.png        32x64 indexed, 2 frames, colored with the best-matching icon palette
  preview.png     4x preview: front, back, shiny front, icon

Every file is checked against the GBA limits (size, 16 colors, 15-bit color).

  tools/sprite_prep/sprite_prep.py --front front.png --back back.png --out build/sprite_test
"""

import argparse
import colorsys
import os
import sys

from PIL import Image

REPO = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
TRANSPARENT = (152, 208, 160)  # the usual key color in this repo's sprite palettes
BG_THRESHOLD = 225


def pixels(img):
    return list(getattr(img, "get_flattened_data", img.getdata)())


def sample_grid(path, grid):
    """Read one color per grid cell (median of the cell's middle), so AA blur is ignored."""
    src = Image.open(path).convert("RGB")
    cell_w, cell_h = src.width / grid, src.height / grid
    out = Image.new("RGB", (grid, grid))
    for gy in range(grid):
        for gx in range(grid):
            x0, y0 = int((gx + 0.25) * cell_w), int((gy + 0.25) * cell_h)
            x1, y1 = max(x0 + 1, int((gx + 0.75) * cell_w)), max(y0 + 1, int((gy + 0.75) * cell_h))
            cell = pixels(src.crop((x0, y0, x1, y1)))
            out.putpixel((gx, gy), tuple(sorted(p[c] for p in cell)[len(cell) // 2] for c in range(3)))
    return out


def background_mask(img):
    """Near-white cells connected to the border are background (keeps white fangs and eye shine)."""
    w, h = img.size
    bg = set()
    stack = [(x, y) for x in range(w) for y in (0, h - 1)] + [(x, y) for y in range(h) for x in (0, w - 1)]
    while stack:
        x, y = stack.pop()
        if (x, y) in bg or not (0 <= x < w and 0 <= y < h):
            continue
        if min(img.getpixel((x, y))) < BG_THRESHOLD:
            continue
        bg.add((x, y))
        stack += [(x + 1, y), (x - 1, y), (x, y + 1), (x, y - 1)]
    return bg


def fit(img, bg, box):
    """Scale the sprite down (nearest neighbor) if its bounding box is larger than box x box."""
    w, h = img.size
    xs = [x for x in range(w) for y in range(h) if (x, y) not in bg]
    ys = [y for x in range(w) for y in range(h) if (x, y) not in bg]
    left, right, top, bottom = min(xs), max(xs) + 1, min(ys), max(ys) + 1
    size = max(right - left, bottom - top)
    rgba = Image.new("RGBA", (w, h))
    for y in range(h):
        for x in range(w):
            rgba.putpixel((x, y), (0, 0, 0, 0) if (x, y) in bg else img.getpixel((x, y)) + (255,))
    if size <= box:
        return rgba, False
    crop = rgba.crop((left, top, right, bottom))
    scale = box / size
    crop = crop.resize((max(1, round(crop.width * scale)), max(1, round(crop.height * scale))), Image.NEAREST)
    out = Image.new("RGBA", (w, h))
    out.paste(crop, ((w - crop.width) // 2, h - crop.height - (h - box) // 2))  # centered, bottom-aligned in the box
    return out, True


def snap(color):
    return tuple(c & 0xF8 for c in color)  # GBA colors are 5 bits per channel


def build_palette(images, colors):
    """Merge the two most similar colors until `colors` remain. Unlike median cut this keeps
    small accents (eyes, a red bib) that are rare but far from every other color."""
    counts = {}
    for im in images:
        for p in pixels(im):
            if p[3]:
                counts[snap(p[:3])] = counts.get(snap(p[:3]), 0) + 1
    clusters = [[c, n] for c, n in counts.items()]
    while len(clusters) > colors:
        best = None
        for i in range(len(clusters)):
            for j in range(i + 1, len(clusters)):
                d = sum((a - b) ** 2 for a, b in zip(clusters[i][0], clusters[j][0]))
                if best is None or d < best[0]:
                    best = (d, i, j)
        _, i, j = best
        (ci, ni), (cj, nj) = clusters[i], clusters[j]
        clusters[i] = [tuple((a * ni + b * nj) / (ni + nj) for a, b in zip(ci, cj)), ni + nj]
        del clusters[j]
    return [TRANSPARENT] + sorted({snap(tuple(round(v) for v in c)) for c, _ in clusters})


def nearest(color, palette, start=1):
    return min(range(start, len(palette)), key=lambda i: sum((a - b) ** 2 for a, b in zip(color, palette[i])))


def index(img, palette):
    out = Image.new("P", img.size)
    out.putpalette([c for rgb in palette for c in rgb] + [0] * (768 - 3 * len(palette)))
    out.putdata([nearest(p[:3], palette) if p[3] else 0 for p in pixels(img)])
    return out


def stack_frames(frame, raise_px=1):
    """Two frames stacked vertically; frame 2 is frame 1 raised by raise_px (placeholder animation)."""
    w, h = frame.size
    out = Image.new("P", (w, h * 2))
    out.putpalette(frame.getpalette())
    out.paste(frame, (0, 0))
    out.paste(frame.crop((0, raise_px, w, h)), (0, h))
    return out


def shiny_palette(palette, hue_shift, keep_hue, keep_width=0.08):
    out = [palette[0]]
    for rgb in palette[1:]:
        h, s, v = colorsys.rgb_to_hsv(*(c / 255 for c in rgb))
        near_keep = min(abs(h - keep_hue), 1 - abs(h - keep_hue)) < keep_width
        if s > 0.12 and not near_keep:
            h = (h + hue_shift) % 1.0
        out.append(snap(tuple(round(c * 255) for c in colorsys.hsv_to_rgb(h, s, v))))
    return out


def read_jasc(path):
    lines = open(path).read().split()
    count = int(lines[2])
    return [tuple(int(v) for v in lines[3 + i * 3: 6 + i * 3]) for i in range(count)]


def write_jasc(path, palette):
    padded = palette + [(0, 0, 0)] * (16 - len(palette))
    with open(path, "w", newline="\r\n") as f:
        f.write("JASC-PAL\n0100\n16\n" + "".join(f"{r} {g} {b}\n" for r, g, b in padded))


def make_icon(front_rgba):
    """32x32 icon from the front sprite, colored with whichever icon palette fits best."""
    small = front_rgba.resize((32, 32), Image.BOX)
    colors = [(p[:3] if p[3] > 127 else None) for p in pixels(small)]
    best = None
    for n in range(6):
        pal = read_jasc(os.path.join(REPO, "graphics", "pokemon", "icon_palettes", f"pal{n}.pal"))
        err = sum(min(sum((a - b) ** 2 for a, b in zip(p, c)) for c in pal[1:]) for p in colors if p)
        if best is None or err < best[0]:
            best = (err, n, pal)
    _, n, pal = best
    icon = Image.new("P", (32, 32))
    icon.putpalette([c for rgb in pal for c in rgb] + [0] * (768 - 3 * len(pal)))
    icon.putdata([nearest(p, pal) if p else 0 for p in colors])
    return stack_frames(icon), n


def check(path, size, max_colors=16):
    im = Image.open(path)
    problems = []
    if im.size != size:
        problems.append(f"size {im.size}, expected {size}")
    if im.mode != "P":
        problems.append(f"mode {im.mode}, expected indexed (P)")
    elif max(pixels(im)) >= max_colors:
        problems.append(f"uses palette index {max(pixels(im))}, limit {max_colors - 1}")
    return problems


def main():
    parser = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    parser.add_argument("--front", required=True)
    parser.add_argument("--back", required=True)
    parser.add_argument("--out", required=True)
    parser.add_argument("--grid", type=int, default=64, help="pixel grid the drafts were drawn on")
    parser.add_argument("--front-box", type=int, default=56, help="max sprite size in the front frame")
    parser.add_argument("--back-box", type=int, default=56, help="max sprite size in the back frame")
    parser.add_argument("--shiny-hue", type=float, default=0.55, help="hue rotation for shiny, 0-1")
    parser.add_argument("--keep-hue", type=float, default=0.0, help="hue left unchanged in shiny (0 = red)")
    args = parser.parse_args()
    os.makedirs(args.out, exist_ok=True)

    sprites = {}
    for name, path, box in (("front", args.front, args.front_box), ("back", args.back, args.back_box)):
        grid = sample_grid(path, args.grid)
        sprites[name], scaled = fit(grid, background_mask(grid), box)
        if scaled:
            print(f"{name}: larger than {box}px, scaled down (check it for lost detail)")

    palette = build_palette(sprites.values(), 15)
    front = index(sprites["front"], palette)
    stack_frames(front).save(os.path.join(args.out, "anim_front.png"))
    index(sprites["back"], palette).save(os.path.join(args.out, "back.png"))
    write_jasc(os.path.join(args.out, "normal.pal"), palette)
    shiny = shiny_palette(palette, args.shiny_hue, args.keep_hue)
    write_jasc(os.path.join(args.out, "shiny.pal"), shiny)
    icon, icon_pal = make_icon(sprites["front"])
    icon.save(os.path.join(args.out, "icon.png"))

    preview = Image.new("RGB", (64 * 3 + 32, 64), TRANSPARENT)
    shiny_front = front.copy()
    shiny_front.putpalette([c for rgb in shiny for c in rgb] + [0] * (768 - 3 * len(shiny)))
    for i, im in enumerate((front, Image.open(os.path.join(args.out, "back.png")), shiny_front)):
        preview.paste(im.convert("RGB"), (i * 64, 0))
    preview.paste(icon.crop((0, 0, 32, 32)).convert("RGB"), (192, 16))
    preview.resize((preview.width * 4, preview.height * 4), Image.NEAREST).save(os.path.join(args.out, "preview.png"))

    problems = []
    for name, size in (("anim_front.png", (64, 128)), ("back.png", (64, 64)), ("icon.png", (32, 64))):
        problems += [f"{name}: {p}" for p in check(os.path.join(args.out, name), size)]
    print(f"palette: {len(palette)} colors (index 0 transparent); icon palette: {icon_pal}")
    for p in problems:
        print("PROBLEM", p)
    sys.exit(1 if problems else 0)


if __name__ == "__main__":
    main()
