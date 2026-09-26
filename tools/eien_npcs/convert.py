#!/usr/bin/env python3
"""Convert Eien's overworld characters from the FRLG-style NPC megapack and register them.

Reads the megapack downloaded by tools/fetch_assets.py (build/community_assets/), and for every
entry in CHARACTERS:
  * halves the RPG Maker sheet (4 directions x 4 frames, 32x48 at 2x) to 16x24 frames,
  * lays them out in the engine's 9-frame order (face S, N, W; walk S x2, N x2, W x2; east is
    west mirrored), feet aligned with Emerald's own 16x32 sprites,
  * shares colors: the characters are grouped into PALETTES shared palettes (like Emerald's
    four NPC palettes) so a map full of NPCs doesn't run out of sprite palette slots,
and writes graphics/object_events/pics/people/eien/<name>.png and
graphics/object_events/palettes/eien_npc_<n>.pal.

It then (re)writes the registration between "Eien NPCs" BEGIN/END markers in the engine's
object event tables, so the characters appear in Porymap as OBJ_EVENT_GFX_EIEN_<NAME>.
Rerunning replaces the marked blocks; nothing outside them is touched.

  tools/eien_npcs/convert.py
"""

import os
import re
import sys

from PIL import Image

HERE = os.path.dirname(os.path.abspath(__file__))
REPO = os.path.dirname(os.path.dirname(HERE))
sys.path.insert(0, os.path.join(REPO, "tools", "eien_tileset"))
from build_source import merge_colors, snap  # noqa: E402  (shared color reduction)

PACK = os.path.join(REPO, "build", "community_assets", "frlg_npc_megapack",
                    "FRLG Accurate NPC Megapack (Relic Castle Edition)")
PIC_DIR = "graphics/object_events/pics/people/eien"
PAL_DIR = "graphics/object_events/palettes"
PALETTES = 4
PAL_TAG_BASE = 0x1180  # OBJ_EVENT_PAL_TAG_EIEN_NPC_<n>; the engine's tags stop at 0x116A
FEET_Y = 8             # paste the 16x24 frame this far down the 16x32 frame (feet on row 30)

# (constant suffix, file name, sheet in the pack, credit)
HGSS = "HGSS OWs in FR style: Delta231, Mimi, M.vit, Kimoras"
RSE = "FRLG-style RSE NPCs: Poffin_Case"
DPPT = "DPPt NPCs: artist not named in the pack readme"
CHARACTERS = [
    ("HARU", "haru", "HGSS NPCs/Characters/NPC_YoungMan.png", HGSS),
    ("AKIRA", "akira", "FRLG NPCs/Characters/trainer_BIRDKEEPER.png", "Bird Keeper: Spherical Ice"),
    ("NAMI", "nami", "FRLG NPCs/Characters/trainer_YOUNGCOUPLE_F.png", "Young Couple: Kalarie"),
    ("KASHIWAGI", "kashiwagi", "HGSS NPCs/Characters/NPC_MidageWoman.png", HGSS),
    ("KASHIWAGI_HUSBAND", "kashiwagi_husband", "HGSS NPCs/Characters/NPC_Shopkeeper.png", HGSS),
    ("FUYUMI", "fuyumi", "HGSS NPCs/Characters/trainer_ACETRAINER_F.png", HGSS),
    ("FISHERMAN", "fisherman", "HGSS NPCs/Characters/trainer_FISHERMAN.png", HGSS),
    ("SAILOR", "sailor", "HGSS NPCs/Characters/trainer_SAILOR.png", HGSS),
    ("VILLAGE_WOMAN", "village_woman", "RSE NPCs/Characters/Hoenn NPC 06.png", RSE),
    ("SCHOOLBOY", "schoolboy", "RSE NPCs/Characters/trainer_SCHOOLBOY.png", RSE),
    ("SNOW_TRAINER", "snow_trainer", "DPPt NPCs/Characters/trainer_ACETRAINERSNOW_M.png", DPPT),
    ("WORKER", "worker", "DPPt NPCs/Characters/trainer_WORKER.png", DPPT),
    ("POKEFAN_M", "pokefan_m", "RSE NPCs/Characters/trainer_POKEFAN_M.png", RSE),
    ("SOCIALITE", "socialite", "DPPt NPCs/Characters/trainer_SOCIALITE.png", DPPT),
]


def camel(name):
    return "Eien" + "".join(part.title() for part in name.split("_"))


def frames(path):
    """The 9 engine frames (RGBA 16x32) from an RPG Maker sheet (rows S, W, E, N; cols stand, step, stand, step)."""
    sheet = Image.open(path).convert("RGBA")
    sheet = sheet.resize((sheet.width // 2, sheet.height // 2), Image.NEAREST)  # exact 2x
    fw, fh = sheet.width // 4, sheet.height // 4
    if (fw, fh) != (16, 24):
        sys.exit(f"{path}: frames are {fw}x{fh} after halving, expected 16x24")

    def cell(row, col):
        out = Image.new("RGBA", (16, 32))
        out.paste(sheet.crop((col * fw, row * fh, col * fw + fw, row * fh + fh)), (0, FEET_Y))
        return out
    south, west, north = 0, 1, 3
    return [cell(south, 0), cell(north, 0), cell(west, 0),
            cell(south, 1), cell(south, 3), cell(north, 1), cell(north, 3), cell(west, 1), cell(west, 3)]


def palette_groups(sprites, n):
    """Group sprites so each group's colors merge into one 15-color palette with little loss:
    greedily add each sprite (most colors first) to the group whose color set grows least,
    with at most an even share of sprites per group."""
    colors = {k: {snap(p) for f in fs for p in f.getdata() if p[3]} for k, fs in sprites.items()}
    order = sorted(colors, key=lambda k: -len(colors[k]))
    groups = [[] for _ in range(n)]
    union = [set() for _ in range(n)]
    cap = -(-len(sprites) // n)  # even share, so no palette has to cover everyone
    for k in order:
        open_groups = [i for i in range(n) if len(groups[i]) < cap]
        g = min(open_groups, key=lambda i: (len(union[i] | colors[k]) - len(union[i]), len(groups[i])))
        groups[g].append(k)
        union[g] |= colors[k]
    return groups


def write_pal(path, colors):
    colors = [(0, 0, 0)] + colors + [(0, 0, 0)] * (15 - len(colors))
    with open(path, "w", newline="\r\n") as f:
        f.write("JASC-PAL\n0100\n16\n" + "".join(f"{r} {g} {b}\n" for r, g, b in colors))


BEGIN = "// Eien NPCs BEGIN (generated by tools/eien_npcs/convert.py)"
END = "// Eien NPCs END"


def put_block(path, text, find_position):
    """Write `text` between the Eien NPC markers in `path`. If the markers aren't there yet,
    `find_position(src)` gives the index to insert them at."""
    full = os.path.join(REPO, path)
    src = open(full).read()
    block = f"{BEGIN}\n{text.rstrip()}\n{END}\n"
    if BEGIN in src:
        i, j = src.index(BEGIN), src.index(END, src.index(BEGIN)) + len(END) + 1
        src = src[:i] + block + src[j:]
    else:
        i = find_position(src)
        src = src[:i] + block + src[i:]
    open(full, "w").write(src)


def before(anchor, start=None):
    """Position just before `anchor` (searching after `start`, if given)."""
    return lambda src: src.index(anchor, src.index(start) if start else 0)


def at_end(src):
    return len(src)


def main():
    if not os.path.isdir(PACK):
        sys.exit("run tools/fetch_assets.py frlg_npc_megapack first")
    sprites = {c[1]: frames(os.path.join(PACK, c[2])) for c in CHARACTERS}
    groups = palette_groups(sprites, PALETTES)
    os.makedirs(os.path.join(REPO, PIC_DIR), exist_ok=True)
    pal_of = {}
    for g, members in enumerate(groups):
        counts = {}
        for k in members:
            for f in sprites[k]:
                for p in f.getdata():
                    if p[3]:
                        counts[snap(p)] = counts.get(snap(p), 0) + 1
        mapping = merge_colors(counts, 15)
        palette = sorted(set(mapping.values()))
        write_pal(os.path.join(REPO, PAL_DIR, f"eien_npc_{g + 1}.pal"), palette)
        for k in members:
            pal_of[k] = g + 1
            out = Image.new("P", (16 * 9, 32))
            out.putpalette([c for rgb in [(0, 0, 0)] + palette for c in rgb] + [0] * (768 - 3 * (len(palette) + 1)))
            for i, f in enumerate(sprites[k]):
                for y in range(32):
                    for x in range(16):
                        p = f.getpixel((x, y))
                        out.putpixel((i * 16 + x, y), palette.index(mapping[snap(p)]) + 1 if p[3] else 0)
            out.save(os.path.join(REPO, PIC_DIR, f"{k}.png"))
        print(f"palette {g + 1}: {', '.join(members)} ({len(counts)} colors -> {len(palette)})")

    consts = "".join(f"    OBJ_EVENT_GFX_EIEN_{c[0]},\n" for c in CHARACTERS)
    tags = "".join(f"#define OBJ_EVENT_PAL_TAG_EIEN_NPC_{g}    0x{PAL_TAG_BASE + g - 1:04X}\n" for g in range(1, PALETTES + 1))
    gfx = "".join(f'const u16 gObjectEventPal_EienNpc{g}[] = INCGFX_U16("{PAL_DIR}/eien_npc_{g}.pal", ".gbapal");\n'
                  for g in range(1, PALETTES + 1))
    gfx += "".join(f'const u32 gObjectEventPic_{camel(c[1])}[] = INCGFX_U32("{PIC_DIR}/{c[1]}.png", ".4bpp", "-mwidth 2 -mheight 4");\n'
                   for c in CHARACTERS)
    pics = "".join(f"static const struct SpriteFrameImage sPicTable_{camel(c[1])}[] = {{\n"
                   f"    overworld_ascending_frames(gObjectEventPic_{camel(c[1])}, 2, 4),\n}};\n\n" for c in CHARACTERS)
    infos = ""
    for c in CHARACTERS:
        infos += (f"// {c[2].split('/')[-1]} ({c[3]})\n"
                  f"const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_{camel(c[1])} = {{\n"
                  "    .tileTag = TAG_NONE,\n"
                  f"    .paletteTag = OBJ_EVENT_PAL_TAG_EIEN_NPC_{pal_of[c[1]]},\n"
                  "    .reflectionPaletteTag = OBJ_EVENT_PAL_TAG_NONE,\n"
                  "    .size = 256,\n    .width = 16,\n    .height = 32,\n"
                  "    .paletteSlot = PALSLOT_NPC_1,\n    .shadowSize = SHADOW_SIZE_M,\n"
                  "    .inanimate = FALSE,\n    .compressed = FALSE,\n    .tracks = TRACKS_FOOT,\n"
                  "    .oam = &gObjectEventBaseOam_16x32,\n    .subspriteTables = sOamTables_16x32,\n"
                  f"    .anims = sAnimTable_Standard,\n    .images = sPicTable_{camel(c[1])},\n}};\n\n")
    externs = "".join(f"extern const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_{camel(c[1])};\n" for c in CHARACTERS)
    pointers = "".join(f"    [OBJ_EVENT_GFX_EIEN_{c[0]}] = &gObjectEventGraphicsInfo_{camel(c[1])},\n" for c in CHARACTERS)
    pal_table = "".join(f"    {{gObjectEventPal_EienNpc{g}, OBJ_EVENT_PAL_TAG_EIEN_NPC_{g}}},\n" for g in range(1, PALETTES + 1))

    put_block("include/constants/event_objects.h", consts, before("    NUM_OBJ_EVENT_GFX,\n"))
    # second block in the same file: the tag defines, before the NONE tag
    tags_path = "include/constants/event_objects.h"
    src = open(os.path.join(REPO, tags_path)).read()
    tag_begin = BEGIN.replace("BEGIN", "palette tags BEGIN")
    tag_end = END.replace("END", "palette tags END")
    tag_block = f"{tag_begin}\n{tags.rstrip()}\n{tag_end}\n"
    if tag_begin in src:
        i, j = src.index(tag_begin), src.index(tag_end) + len(tag_end) + 1
        src = src[:i] + tag_block + src[j:]
    else:
        i = src.index("#define OBJ_EVENT_PAL_TAG_WHITE ")
        src = src[:i] + tag_block + src[i:]
    open(os.path.join(REPO, tags_path), "w").write(src)

    put_block("src/data/object_events/object_event_graphics.h", gfx, at_end)
    put_block("src/data/object_events/object_event_pic_tables.h", pics, at_end)
    put_block("src/data/object_events/object_event_graphics_info.h", infos, at_end)
    pointers_h = "src/data/object_events/object_event_graphics_info_pointers.h"
    array = "gObjectEventGraphicsInfoPointers[NUM_OBJ_EVENT_GFX] = {"
    src = open(os.path.join(REPO, pointers_h)).read()
    ext_begin = BEGIN.replace("BEGIN", "externs BEGIN")
    ext_end = END.replace("END", "externs END")
    ext_block = f"{ext_begin}\n{externs.rstrip()}\n{ext_end}\n"
    if ext_begin in src:
        i, j = src.index(ext_begin), src.index(ext_end) + len(ext_end) + 1
        src = src[:i] + ext_block + src[j:]
    else:
        i = src.index("const struct ObjectEventGraphicsInfo *const " + array)
        src = src[:i] + ext_block + "\n" + src[i:]
    open(os.path.join(REPO, pointers_h), "w").write(src)
    put_block(pointers_h, pointers, before("\n};", array))
    put_block("src/event_object_movement.c", pal_table,
              before("#ifdef BUGFIX", "sObjectEventSpritePalettes[] = {"))
    print(f"wrote {len(CHARACTERS)} characters to {PIC_DIR}/ and registered OBJ_EVENT_GFX_EIEN_*")


if __name__ == "__main__":
    main()
