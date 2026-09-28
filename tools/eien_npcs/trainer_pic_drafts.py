#!/usr/bin/env python3
"""Draft trainer front pictures (64x64) for Eien characters with Gemini image models.

Each draft gets a vanilla trainer picture for style, proportions and framing, and the
character's overworld sprite for colors and design. The output is sampled to 64x64 and cut to
its own 15 colors plus the transparent key color, so it can go straight into
graphics/trainers/front_pics/ with a matching .pal. Raw output is kept for reference.

  tools/eien_npcs/trainer_pic_drafts.py akira fuyumi
  tools/eien_npcs/trainer_pic_drafts.py --convert-only akira   # redo the 64x64 files from raw/

Writes design/art/eien_<name>/battle_drafts/ and a contact sheet
design/art/eien_<name>_battle_contact_sheet.png. AI-assisted art: credit it in
design/asset-credits.md when a draft is used.
"""

import argparse
import base64
import json
import os
import sys
import urllib.request

from PIL import Image, ImageDraw

REPO = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
sys.path.insert(0, os.path.join(REPO, "tools", "sprite_prep"))
import sprite_prep  # noqa: E402

API = "https://generativelanguage.googleapis.com/v1beta/models/{model}:generateContent"
MODELS = {"gemini3pro": "gemini-3-pro-image", "gemini31flash": "gemini-3.1-flash-image"}

COMMON = (
    "Draw a Pokémon trainer battle sprite (the picture of the opponent shown in battle) in the "
    "exact style of the first reference image: Game Boy Advance FireRed/LeafGreen trainer art, "
    "pixel art on a 64x64 pixel grid, dark outlines, simple cel shading, no more than 15 colors, "
    "the whole figure visible with the same size and framing as the reference. Use the second "
    "reference image (a small overworld sprite of the same character) for the character's "
    "colors and design. Draw it enlarged so each pixel of the 64x64 grid is a clear square, on a "
    "plain white background, with no text, no border, no ground shadow and no other objects. "
)

CHARACTERS = {
    "akira": {
        "style": "graphics/trainers/front_pics/youngster_frlg.png",
        "overworld": "graphics/object_events/pics/people/eien/akira.png",
        "who": (
            "The character is Akira, a cheerful local boy of about 12, the player's friendly rival, "
            "who looks up to the Pokémon League. Spiky light brown hair, an orange shirt, blue "
            "overalls, as in his overworld sprite. Friendly and eager, not tough. "
        ),
        "poses": {
            "a": "Pose: grinning, holding a Poké Ball up in front of him, ready to battle.",
            "b": "Pose: pointing forward at the viewer with a big confident grin, the other hand on his hip.",
            "c": "Pose: an excited fist pump, one fist raised, a Poké Ball in the other hand.",
        },
    },
    "fuyumi": {
        "style": "graphics/trainers/front_pics/cooltrainer_f.png",
        "overworld": "graphics/object_events/pics/people/eien/fuyumi.png",
        "who": (
            "The character is Fuyumi, the Ice-type gym leader of a snowy town: a woman around 40, "
            "a stern, experienced veteran and a mother. Dark slate hair tied in a bun and a red "
            "outfit, as in her overworld sprite, with a practical winter look. Calm and serious, "
            "not glamorous. "
        ),
        "poses": {
            "a": "Pose: arms crossed, standing straight, a stern look.",
            "b": "Pose: holding a Poké Ball out toward the viewer at arm's length, serious and steady.",
            "c": "Pose: one hand on her hip, the other raised in front of her with a Poké Ball, a small confident look.",
        },
    },
}


def image_part(path, scale):
    src = Image.open(os.path.join(REPO, path))
    img = src.convert("RGBA")
    if src.mode == "P":  # index 0 is the transparent key color
        key = tuple(src.getpalette()[:3])
        img.putdata([(0, 0, 0, 0) if p[:3] == key else p for p in sprite_prep.pixels(img)])
    if img.width > 64:  # an overworld sheet of 16x32 frames: the first one (facing down)
        img = img.crop((0, 0, 16, 32))
    bg = Image.new("RGBA", img.size, (255, 255, 255, 255))
    bg.alpha_composite(img)
    bg = bg.convert("RGB").resize((img.width * scale, img.height * scale), Image.NEAREST)
    tmp = os.path.join("/tmp", "trainer_pic_ref.png")
    bg.save(tmp)
    return {"inline_data": {"mime_type": "image/png", "data": base64.b64encode(open(tmp, "rb").read()).decode()}}


def generate(model, prompt, parts):
    body = {
        "contents": [{"parts": [{"text": prompt}] + parts}],
        "generationConfig": {"responseModalities": ["TEXT", "IMAGE"]},
    }
    req = urllib.request.Request(API.format(model=model), data=json.dumps(body).encode(),
                                 headers={"Content-Type": "application/json"})
    with urllib.request.urlopen(req, timeout=300) as resp:
        data = json.load(resp)
    for cand in data.get("candidates", []):
        for part in cand.get("content", {}).get("parts", []):
            inline = part.get("inlineData") or part.get("inline_data")
            if inline:
                return base64.b64decode(inline["data"])
    raise RuntimeError("no image in response: " + json.dumps(data)[:400])


def convert(raw_path, out_png, out_pal):
    img = sprite_prep.sample_grid(raw_path, 64)
    bg = sprite_prep.background_mask(img)
    rgba, _ = sprite_prep.fit(img, bg, 64)
    palette = sprite_prep.build_palette([rgba], 15)
    sprite_prep.index(rgba, palette).save(out_png)
    sprite_prep.write_jasc(out_pal, palette)
    return rgba


def contact_sheet(name, drafts, out):
    scale, pad, label_h = 3, 8, 14
    cell = 64 * scale
    sheet = Image.new("RGB", (pad + len(drafts) * (cell + pad), cell + label_h + 2 * pad), (255, 255, 255))
    draw = ImageDraw.Draw(sheet)
    for i, (label, rgba) in enumerate(drafts):
        x = pad + i * (cell + pad)
        tile = Image.new("RGBA", (64, 64), sprite_prep.TRANSPARENT + (255,))
        tile.alpha_composite(rgba)
        sheet.paste(tile.convert("RGB").resize((cell, cell), Image.NEAREST), (x, pad))
        draw.text((x, pad + cell + 2), label, fill=(0, 0, 0))
    sheet.save(out)


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("names", nargs="+", choices=sorted(CHARACTERS))
    parser.add_argument("--convert-only", action="store_true")
    args = parser.parse_args()

    for name in args.names:
        char = CHARACTERS[name]
        out_dir = os.path.join(REPO, "design", "art", f"eien_{name}", "battle_drafts")
        raw_dir = os.path.join(out_dir, "raw")
        os.makedirs(raw_dir, exist_ok=True)
        drafts = []
        for pose, pose_text in char["poses"].items():
            for tag, model in MODELS.items():
                stem = f"{name}_{tag}_{pose}"
                raw = os.path.join(raw_dir, stem + ".png")
                if not args.convert_only:
                    parts = [image_part(char["style"], 4), image_part(char["overworld"], 8)]
                    try:
                        # Generate before opening the file, so a failed call keeps the old draft
                        data = generate(model, COMMON + char["who"] + pose_text, parts)
                        with open(raw, "wb") as f:
                            f.write(data)
                    except Exception as e:  # keep going; one failed draft shouldn't lose the rest
                        print(f"{stem}: {e}", file=sys.stderr)
                if os.path.exists(raw):
                    rgba = convert(raw, os.path.join(out_dir, stem + ".png"), os.path.join(out_dir, stem + ".pal"))
                    drafts.append((stem.replace(name + "_", ""), rgba))
                    print(stem)
        contact_sheet(name, drafts, os.path.join(REPO, "design", "art", f"eien_{name}_battle_contact_sheet.png"))


if __name__ == "__main__":
    main()
