#!/usr/bin/env python3
"""Redraw the hero's head: short messy dark hair with a side fringe instead of Brendan's cap.

Works on palette indices (the colors come from recolor.py). Reads the vanilla sprites kept in
tools/eien_hero/vanilla/ and writes the files below.

Overworld sheets (walking, running, bikes, surfing, fishing): heads drawn by hand below (OW_HEADS), placed on
each frame where its cap is found (ANCHORS); hair uses 14 (light), 9 (mid), 4 (dark).
Battle sprites: the hoodie's red panels move to the strap greys (10-11) except the Poké Ball,
pixels of 9 (now hair) move to 10, and the head comes from an AI draft
(tools/eien_hero/ai_drafts/, Gemini 3 Pro image edit of the enlarged sprite): the draft is
snapped back to the pixel grid, aligned on the unchanged body, and used only around the old cap
and where it drew hair, limited to hair, skin and outline colors. Hair uses 9 and 4.

  graphics/object_events/pics/people/brendan/{walking,running,mach_bike,acro_bike,surfing,fishing}.png
  graphics/trainers/front_pics/brendan.png                 (battle front)
  graphics/trainers/back_pics/brendan.png                  (battle back, 4 frames)
  tools/eien_hero/redraw_hair.py
"""

import os
import re

from PIL import Image

HERE = os.path.dirname(os.path.abspath(__file__))
REPO = os.path.dirname(os.path.dirname(HERE))
KEY = {".": 0, "a": 1, "b": 2, "c": 3, "d": 4, "e": 5, "f": 6, "g": 7, "h": 8, "i": 9,
       "j": 10, "k": 11, "l": 12, "m": 13, "n": 14, "o": 15}

# Overworld heads, one per facing, drawn on 16x32 frames. Rows listed replace the cap
# (rows 10-17 are cleared first; the new hair starts at row 12).
OW_HEADS = {
    "down": {
        12: ".....oooooo.....",
        13: "....onnnnnio....",
        14: "...onnnnniiio...",
        15: "..oinnnniiiiio..",
        16: "..oiinniiiidio..",
        17: "..odiididiiddo..",
    },
    "up": {
        12: ".....oooooo.....",
        13: "....onnnnnno....",
        14: "...onnnnnniio...",
        15: "..onnnnniiiiio..",
        16: "..oinniiiiiiio..",
        17: "..oiiiiiiiidio..",
    },
    "left": {
        12: ".....oooooo.....",
        13: "...oonnnnnnoo...",
        14: "..onnnnnniiiio..",
        15: "..onnniiiiiiiio.",
        16: "..oinniiiiiiiio.",
        17: "..odidiiiiiiiio.",
    },
}
BLUE_HAIR = 8  # index Brendan's black hair shares with his trousers; repainted as hair below
SKIN = (1, 2, 3, 4)
# Hand touch-ups after the heads are placed: (sheet, frame) -> {(x, y): letter}.
TOUCH_UPS = {
    ("fishing", 1): {(26, 10): "e", (25, 11): "e", (26, 11): "o"},  # the rod's end, hidden by the cap before
}

# Every overworld sheet (walking, running, bikes) reuses the heads above. Each frame's cap is
# found by a row of pixels that only the cap has, per facing; its position in the walking
# frames (column, row) is where OW_HEADS sits, so the offset from there places the new head.
ANCHORS = {
    "down": (re.compile("k[jk]nnnn[jk]k"), 4, 17),  # the cap's brim
    "up": (re.compile("[ob]hii[id]{4}iih[ob]"), 2, 17),  # the cap's back edge (b: raised arms)
    "left": (re.compile("h[in][in]j"), 2, 15),   # the cap's peak
}
# The overworld sheets with Brendan's cap, and their frame width.
OW_SHEETS = {"walking": 16, "running": 16, "mach_bike": 32, "acro_bike": 32, "surfing": 32, "fishing": 32}
LETTERS = "".join(sorted(KEY, key=KEY.get))  # index -> letter


def find_head(px, x0, width):
    """(facing, dx, dy) of the cap in one frame, relative to the walking frames' head."""
    rows = ["".join(LETTERS[px[x0 + x, y]] for x in range(width)) for y in range(32)]
    for facing, (pattern, ax, ay) in ANCHORS.items():
        for y, row in enumerate(rows):
            m = pattern.search(row)
            if m:
                return facing, m.start() - ax, y - ay
    return None


def head_outline():
    """Per facing, the cells the walking frames' cap and the new head cover (walking layout).
    Anything else in the cleared box that runs out of it (a fishing rod) is put back."""
    walking = Image.open(os.path.join(HERE, "vanilla", "walking.png")).load()
    outline = {}
    for frame, facing in enumerate(("down", "up", "left")):
        cells = {(x, y) for y in range(8, 18) for x in range(16) if walking[frame * 16 + x, y]}
        cells |= {(x, y) for y, line in OW_HEADS[facing].items() for x, ch in enumerate(line) if ch != "."}
        outline[facing] = cells
    return outline


def place_head(px, x0, width, facing, dx, dy, outline):
    fringe = 17 + dy
    box = {(x, y) for y in range(8 + dy, fringe + 1) for x in range(max(0, dx), min(width, dx + 16))}
    loose = {c for c in box if (c[0] - dx, c[1] - dy) not in outline[facing] and px[x0 + c[0], c[1]]}
    # Of those, keep what runs out of the box above or to the side (a rod); stray bits of cap
    # stay cleared. (Below the box is the body, which touches the cap anyway.)
    def near(x, y):
        return [(x + i, y + j) for i in (-1, 0, 1) for j in (-1, 0, 1) if (i, j) != (0, 0)]
    todo = [c for c in loose if any(n not in box and 0 <= n[0] < width and 0 <= n[1] <= fringe and px[x0 + n[0], n[1]]
                                    for n in near(*c))]
    keep = {}
    while todo:
        c = todo.pop()
        if c not in keep:
            keep[c] = px[x0 + c[0], c[1]]
            todo += [n for n in near(*c) if n in loose]
    for y in range(8 + dy, fringe + 1):
        for x in range(max(0, dx), min(width, dx + 16)):
            # Running and biking, the brim sits where the arms start: keep them.
            if not (facing == "down" and y == fringe and px[x0 + x, y] in SKIN):
                px[x0 + x, y] = 0
    for row, line in OW_HEADS[facing].items():
        for x, ch in enumerate(line):
            if ch != "." and 0 <= dx + x < width:
                if facing == "down" and row + dy == fringe and ch == "o" and px[x0 + dx + x, fringe] in SKIN:
                    continue
                px[x0 + dx + x, row + dy] = KEY[ch]
    for (x, y), v in keep.items():
        px[x0 + x, y] = v
    # Hair below the cap line that used the trousers' blue: back of the head (up, left).
    if facing == "up":
        for y in (fringe + 1, fringe + 2):
            for x in range(max(0, dx), min(width, dx + 16)):
                if px[x0 + x, y] == BLUE_HAIR:
                    px[x0 + x, y] = KEY["d"]
    if facing == "left":
        for y in range(fringe + 1, fringe + 4):
            for x in range(max(0, dx + 7), min(width, dx + 16)):
                if px[x0 + x, y] == BLUE_HAIR:
                    px[x0 + x, y] = KEY["i"]


def redraw_overworld():
    outline = head_outline()
    for name, width in OW_SHEETS.items():
        im = Image.open(os.path.join(HERE, "vanilla", f"{name}.png"))
        px = im.load()
        for frame in range(im.width // width):
            found = find_head(px, frame * width, width)
            if found is None:
                raise SystemExit(f"{name} frame {frame}: no cap found")
            place_head(px, frame * width, width, *found, outline)
            for (x, y), ch in TOUCH_UPS.get((name, frame), {}).items():
                px[frame * width + x, y] = KEY[ch]
        im.save(os.path.join(REPO, f"graphics/object_events/pics/people/brendan/{name}.png"))
        print(f"{name}: {im.width // width} frames")


def read_pal(path):
    w = open(os.path.join(REPO, path)).read().split()[3:]
    return [tuple(int(v) for v in w[i * 3:i * 3 + 3]) for i in range(16)]


def remap_body(frame, head_bottom):
    """Hoodie reds (12-13) -> greys (10-11) except the Poké Ball; 9 (vanilla light grey) -> 10."""
    px = frame.load()
    seen, ball = set(), set()
    for y in range(64):
        for x in range(64):
            if (x, y) in seen or px[x, y] not in (12, 13, 14):
                continue
            comp, stack = [], [(x, y)]
            while stack:
                p = stack.pop()
                if p in seen or not (0 <= p[0] < 64 and 0 <= p[1] < 64) or px[p] not in (12, 13, 14):
                    continue
                seen.add(p)
                comp.append(p)
                stack += [(p[0] + dx, p[1] + dy) for dx in (-1, 0, 1) for dy in (-1, 0, 1)]
            values = {px[p] for p in comp}
            if 14 in values and values & {12, 13} and any(p[1] > head_bottom for p in comp):
                ball.update(comp)  # red and white together below the head: the Poké Ball
    for y in range(64):
        for x in range(64):
            v = px[x, y]
            if v in (12, 13) and (x, y) not in ball:
                px[x, y] = 10 if v == 12 else 11
            elif v == 9:
                px[x, y] = 10  # 9 is hair now; the head merge repaints the hair itself


def sample_grid(img, cols, rows):
    """One color per grid cell (median of the cell's middle), for AI output at any scale."""
    img = img.convert("RGB")
    cw, ch = img.width / cols, img.height / rows
    out = Image.new("RGB", (cols, rows))
    for gy in range(rows):
        for gx in range(cols):
            box = (int((gx + .25) * cw), int((gy + .25) * ch), max(int((gx + .25) * cw) + 1, int((gx + .75) * cw)),
                   max(int((gy + .25) * ch) + 1, int((gy + .75) * ch)))
            cell = list(img.crop(box).getdata())
            out.putpixel((gx, gy), tuple(sorted(c[i] for c in cell)[len(cell) // 2] for i in range(3)))
    return out


def dist(a, b):
    return sum((x - y) ** 2 for x, y in zip(a, b))


def merge_head(frame, vanilla, draft, pal, head_bottom):
    """Replace the cap on `frame` (64x64, P) with the hair in `draft` (64x64 RGB, roughly aligned).
    The cap is found on `vanilla` (before the body remap turns the red gloves grey like the band)."""
    px = frame.load()
    vpx = vanilla.load()
    # Align the draft on the body (rows below the head), which the AI was told to keep.
    best = None
    for dx in range(-3, 4):
        for dy in range(-3, 4):
            err = n = 0
            for y in range(head_bottom + 1, 64):
                for x in range(64):
                    if px[x, y] and 0 <= x + dx < 64 and 0 <= y + dy < 64:
                        err += dist(pal[px[x, y]], draft.getpixel((x + dx, y + dy)))
                        n += 1
            if n and (best is None or err / n < best[0]):
                best = (err / n, dx, dy)
    _, dx, dy = best
    at = lambda x, y: draft.getpixel((x + dx, y + dy)) if 0 <= x + dx < 64 and 0 <= y + dy < 64 else (255, 255, 255)
    cap = {(x, y) for y in range(head_bottom + 1) for x in range(64) if vpx[x, y] in (9, 10, 11, 14)}
    cap_bottom = max(y for _, y in cap)
    mask = {(x + i, y + j) for x, y in cap for i in range(-2, 3) for j in range(-2, 3)
            if 0 <= x + i < 64 and 0 <= y + j <= cap_bottom}
    hair = (4, 9)
    allowed = (1, 2, 3, 4, 9, 15)
    for y in range(head_bottom + 1):
        for x in range(64):
            c = at(x, y)
            nearest = min(allowed, key=lambda i: dist(c, pal[i]))
            if nearest in hair and dist(c, pal[nearest]) < 3000 and vpx[x, y] in (0, 15):
                mask.add((x, y))  # hair the draft added where there was nothing (never over the body)
    for x, y in mask:
        if vpx[x, y] in (12, 13):
            continue  # the red gloves (and ball) are never part of the head
        c = at(x, y)
        if min(c) > 225:
            px[x, y] = 0  # background: the cap's spikes are gone
            continue
        nearest = min(allowed, key=lambda i: dist(c, pal[i]))
        if dist(c, pal[nearest]) < 2500:
            px[x, y] = nearest  # else the draft drew something else here (a glove): keep ours
    # Old cap outline left alone under the new hair: a navy pixel with no navy neighbour goes.
    navy = (5, 6, 7, 8)
    for y in range(head_bottom + 1):
        for x in range(64):
            if px[x, y] in navy and not any(0 <= x + i < 64 and 0 <= y + j < 64 and (i or j) and px[x + i, y + j] in navy
                                            for i in (-1, 0, 1) for j in (-1, 0, 1)):
                px[x, y] = 0
    # Outline stragglers: a lone outline pixel with no hair or skin next to it goes.
    for x, y in list(mask):
        if px[x, y] == 15 and not any(0 <= x + i < 64 and 0 <= y + j < 64 and px[x + i, y + j] in allowed[:5]
                                      for i in (-1, 0, 1) for j in (-1, 0, 1)):
            px[x, y] = 0
    return dx, dy


def redraw_battle():
    pal = read_pal("graphics/trainers/palettes/brendan.pal")
    vanilla_front = Image.open(os.path.join(HERE, "vanilla", "front.png"))
    front = vanilla_front.copy()
    remap_body(front, 23)
    offset = merge_head(front, vanilla_front, sample_grid(Image.open(os.path.join(HERE, "ai_drafts", "front.png")), 64, 64), pal, 23)
    front.save(os.path.join(REPO, "graphics/trainers/front_pics/brendan.png"))
    print(f"front: draft aligned by {offset}")
    back = Image.open(os.path.join(HERE, "vanilla", "back.png")).copy()
    strip = sample_grid(Image.open(os.path.join(HERE, "ai_drafts", "back_strip.png")), 256, 64)
    for f in range(4):
        vanilla_frame = back.crop((0, f * 64, 64, f * 64 + 64))
        frame = vanilla_frame.copy()
        fpx = frame.load()
        head_bottom = max(y for y in range(64) for x in range(64) if fpx[x, y] == 14) + 2
        remap_body(frame, head_bottom)
        offset = merge_head(frame, vanilla_frame, strip.crop((f * 64, 0, f * 64 + 64, 64)), pal, head_bottom)
        back.paste(frame, (0, f * 64))
        print(f"back frame {f}: draft aligned by {offset}")
    back.save(os.path.join(REPO, "graphics/trainers/back_pics/brendan.png"))


if __name__ == "__main__":
    redraw_overworld()
    redraw_battle()
    print("redrew the overworld sheets and the battle sprites")
