#!/usr/bin/env python3
"""Redraw the hero's head: short messy dark hair with a side fringe instead of Brendan's cap.

Works on palette indices (the colors come from recolor.py). Reads the vanilla sprites kept in
tools/eien_hero/vanilla/ and writes the files below.

Walking frames: heads drawn by hand below (OW_HEADS); hair uses 14 (light), 9 (mid), 4 (dark).
Battle sprites: the hoodie's red panels move to the strap greys (10-11) except the Poké Ball,
pixels of 9 (now hair) move to 10, and the head comes from an AI draft
(tools/eien_hero/ai_drafts/, Gemini 3 Pro image edit of the enlarged sprite): the draft is
snapped back to the pixel grid, aligned on the unchanged body, and used only around the old cap
and where it drew hair, limited to hair, skin and outline colors. Hair uses 9 and 4.

  graphics/object_events/pics/people/brendan/walking.png   (9 walking frames)
  graphics/trainers/front_pics/brendan.png                 (battle front)
  graphics/trainers/back_pics/brendan.png                  (battle back, 4 frames)
  tools/eien_hero/redraw_hair.py
"""

import os

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
# frame -> (facing, rows the frame is shifted down relative to its facing frame)
OW_FRAMES = {0: ("down", 0), 1: ("up", 0), 2: ("left", 0), 3: ("down", 1), 4: ("down", 1),
             5: ("up", 1), 6: ("up", 1), 7: ("left", 1), 8: ("left", 1)}
BLUE_HAIR = 8  # index Brendan's black hair shares with his trousers; repainted as hair below


def redraw_walking():
    im = Image.open(os.path.join(HERE, "vanilla", "walking.png"))
    px = im.load()
    for frame, (facing, shift) in OW_FRAMES.items():
        x0 = frame * 16
        for y in range(10 + shift, 18 + shift):
            for x in range(16):
                px[x0 + x, y] = 0
        for row, line in OW_HEADS[facing].items():
            for x, ch in enumerate(line):
                if ch != ".":
                    px[x0 + x, row + shift] = KEY[ch]
        # Hair below the cap line that used the trousers' blue: back of the head (up, left).
        if facing == "up":
            for y in (18 + shift, 19 + shift):
                for x in range(16):
                    if px[x0 + x, y] == BLUE_HAIR:
                        px[x0 + x, y] = KEY["d"]
        if facing == "left":
            for y in range(18 + shift, 21 + shift):
                for x in range(7, 16):
                    if px[x0 + x, y] == BLUE_HAIR:
                        px[x0 + x, y] = KEY["i"]
    im.save(os.path.join(REPO, "graphics/object_events/pics/people/brendan/walking.png"))


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
    redraw_walking()
    redraw_battle()
    print("redrew the walking frames and the battle sprites")
