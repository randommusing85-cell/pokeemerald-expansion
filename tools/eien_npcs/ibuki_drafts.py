#!/usr/bin/env python3
"""Overworld sprite drafts for Ibuki and the pilgrims (design/brainstorm-ibuki-sprites.md):
recolors of FRLG-style NPC megapack sheets (tools/fetch_assets.py frlg_npc_megapack). Writes
design/art/eien_ibuki/ow_drafts/*.png (RPG Maker sheets, like the pack's) and a contact sheet,
design/art/eien_ibuki_ow_contact_sheet.png. Picked drafts are converted by convert.py.
  tools/eien_npcs/ibuki_drafts.py
"""
import os
from PIL import Image, ImageDraw

REPO = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
P = REPO + '/build/community_assets/frlg_npc_megapack/FRLG Accurate NPC Megapack (Relic Castle Edition)/'
OUT = REPO + '/design/art/eien_ibuki/ow_drafts/'

# Ibuki: off-white gi, dark brown belt, faded red wrist tape, dark hair with grey
GI, GI_M, GI_D = (240, 236, 220), (204, 196, 180), (150, 140, 124)
HAIR, HAIR_GREY, HAIR_D = (44, 44, 52), (104, 104, 112), (24, 24, 32)
BELT = (92, 60, 40)
TAPE, TAPE_D = (200, 96, 84), (150, 64, 56)
# Pilgrims: white travel clothes, straw hat, cloth pack
STRAW, STRAW_M, STRAW_D = (232, 204, 120), (192, 160, 88), (128, 96, 48)
PACK, PACK_D = (176, 152, 112), (120, 100, 72)
HAIR_F, HAIR_F_D = (92, 64, 56), (56, 40, 40)


def recolor(path, rule):
    im = Image.open(P + path).convert('RGBA')
    px = im.load()
    fw, fh = im.width // 4, im.height // 4
    for y in range(im.height):
        for x in range(im.width):
            p = px[x, y]
            if p[3]:
                n = rule(p[:3], y % fh, x % fw, y // fh)
                if n:
                    px[x, y] = n + (255,)
    return im


def ibuki(grey_hair=False, tape=True):
    hair = {(32, 40, 64): HAIR, (64, 72, 96): HAIR_GREY}
    if grey_hair:  # older: the grey takes over
        hair = {(32, 40, 64): HAIR_GREY, (64, 72, 96): (148, 148, 152)}
    def rule(c, y, x, d):
        if c in hair:
            return hair[c]
        # the red headband becomes hair (tied back, no band)
        if c == (192, 64, 56):
            return hair[(32, 40, 64)]
        if c == (240, 88, 80):
            return hair[(64, 72, 96)]
        if c == (96, 40, 32):
            return HAIR_D
        if c == (240, 224, 224):
            return GI
        if c == (200, 184, 184):
            return GI_M
        if c == (144, 128, 120):
            return GI_D
        if c == (88, 72, 64):
            return BELT
        # wrist tape: the skin of the forearms, low and to the sides
        if tape and c in ((216, 144, 112), (240, 184, 144)) and 32 <= y <= 36 and (x <= 8 or x >= 23):
            return TAPE if c == (240, 184, 144) else TAPE_D
        return None
    return rule


def pilgrim_hiker(c, y, x, d):
    hat = y <= 17
    if hat:
        if c == (208, 176, 96):
            return STRAW
        if c == (168, 144, 96):
            return STRAW_M
        if c == (224, 96, 88):  # the feather goes
            return STRAW
        return None
    if c == (120, 184, 88):
        return GI
    if c == (112, 144, 88):
        return GI_M
    if c == (224, 96, 88):
        return GI_M
    if c == (168, 144, 96):
        return PACK
    if c == (104, 88, 64):
        return PACK_D
    return None


def pilgrim_ruin(c, y, x, d):
    if y <= 17:
        if c == (216, 216, 184):
            return STRAW
        if c == (176, 176, 136):
            return STRAW_M
        if c == (80, 72, 48):
            return STRAW_D
        return None
    if c == (216, 216, 184):
        return GI
    if c == (176, 176, 136):
        return GI_M
    if c == (112, 104, 64):
        return GI_D
    if c in ((216, 184, 40), (248, 216, 88), (248, 240, 136)):
        return PACK
    if c == (128, 112, 32):
        return PACK_D
    if c == (208, 112, 136):  # the pink pack straps
        return PACK
    if c == (128, 64, 80):
        return PACK_D
    return None


def pilgrim_picnicker(c, y, x, d):
    if y <= 19:
        if c == (80, 160, 120):
            return STRAW
        if c == (56, 112, 88):
            return STRAW_M
        if c == (40, 64, 48):
            return STRAW_D
        if c == (216, 88, 72):
            return STRAW_M
    if c == (72, 96, 168):
        return HAIR_F
    if c in ((64, 64, 88), (40, 40, 64)):
        return HAIR_F_D
    if c == (80, 160, 120):
        return GI
    if c == (56, 112, 88):
        return GI_M
    if c == (40, 64, 48):
        return GI_D
    if c == (168, 168, 216):
        return GI_M
    if c == (216, 88, 72):
        return TAPE
    return None


def pilgrim_battlegirl(c, y, x, d):
    if c == (224, 192, 88):
        return HAIR_F
    if c == (176, 152, 72):
        return HAIR_F_D
    if c in ((72, 80, 136), (88, 120, 176)):
        return STRAW_M if y <= 12 else GI_D
    if c == (248, 136, 48):
        return GI
    if c == (176, 112, 48):
        return GI_M
    return None


DRAFTS = {
    'ibuki_a_blackbelt': ('RSE NPCs/Characters/trainer_BLACKBELT.png', ibuki(tape=False)),
    'ibuki_b_blackbelt_tape': ('RSE NPCs/Characters/trainer_BLACKBELT.png', ibuki()),
    'ibuki_c_blackbelt_grey': ('RSE NPCs/Characters/trainer_BLACKBELT.png', ibuki(grey_hair=True)),
    'pilgrim_m_a_hiker': ('RSE NPCs/Characters/trainer_HIKER.png', pilgrim_hiker),
    'pilgrim_m_b_ruinmaniac': ('RSE NPCs/Characters/trainer_RUINMANIAC.png', pilgrim_ruin),
    'pilgrim_f_a_picnicker': ('HGSS NPCs/Characters/trainer_PICNICKER.png', pilgrim_picnicker),
    'pilgrim_f_b_battlegirl': ('DPPt NPCs/Characters/trainer_DPBATTLEGIRL.png', pilgrim_battlegirl),
}


def contact_sheet(images, out):
    """Each draft's down, left and up standing frames at game size (16x24), shown 4x."""
    scale, pad, label_h = 4, 10, 14
    cw, ch = 3 * 16 * scale + pad, 24 * scale + label_h + pad
    cols = 4
    rows = (len(images) + cols - 1) // cols
    sheet = Image.new('RGB', (cols * cw + pad, rows * ch + pad), (152, 208, 160))
    draw = ImageDraw.Draw(sheet)
    for i, (name, im) in enumerate(images.items()):
        fw, fh = im.width // 4, im.height // 4
        x0, y0 = pad + (i % cols) * cw, pad + (i // cols) * ch
        for k, row in enumerate((0, 1, 3)):
            fr = im.crop((0, row * fh, fw, (row + 1) * fh)).resize((16, 24), Image.NEAREST)
            fr = fr.resize((16 * scale, 24 * scale), Image.NEAREST)
            sheet.paste(fr, (x0 + k * 16 * scale, y0), fr)
        draw.text((x0, y0 + 24 * scale + 2), name, fill=(0, 0, 0))
    sheet.save(out)


def main():
    os.makedirs(OUT, exist_ok=True)
    images = {}
    for name, (path, rule) in DRAFTS.items():
        images[name] = recolor(path, rule)
        images[name].save(OUT + name + '.png')
    contact_sheet(images, REPO + '/design/art/eien_ibuki_ow_contact_sheet.png')


if __name__ == '__main__':
    main()
