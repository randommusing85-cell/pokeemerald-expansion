#!/usr/bin/env python3
"""Back, idle-frame and icon drafts for Eien forms whose front is already picked.

Each draft gets the vanilla sprite it replaces (back, the two front frames, or the icon) for
framing and motion, and the form's picked front (graphics/pokemon/eien/<species>/) for the
design, both enlarged 8x. Backs and idle frames are indexed with the form's palette (normal.pal)
so a pick can go straight into convert_art.py (BACK_PICKS, FRAME2_PICKS); icons keep their raw
output for make_icons.py and get a preview indexed with the Eien icon palette (pal6.pal).

  tools/eien_species/stage_drafts.py back combusken ivysaur frogadier
  tools/eien_species/stage_drafts.py frame2 combusken
  tools/eien_species/stage_drafts.py icon --convert-only combusken

Writes design/art/eien_<species>/{back_drafts,frame2_drafts,icon_drafts}/ (raw output in raw/)
and design/art/eien_<kind>_drafts_contact_sheet.png. AI-assisted art: credit it in
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
TRIES = ("a", "b")
EIEN_ICON_PALETTE = "graphics/pokemon/icon_palettes/pal6.pal"
# the vanilla icons' palettes (their species' iconPalIndex), to color the reference icon
VANILLA_ICON_PALETTE = {"combusken": 0, "ivysaur": 4, "frogadier": 0, "hoothoot": 2, "noctowl": 2, "blaziken": 0, "venusaur": 4, "greninja": 0, "ledyba": 0, "ledian": 0}

STYLE = (
    "Style: Gen 4/5 Pokemon sprite pixel art enlarged 8x (crisp square pixels, no anti-aliasing, "
    "no gradients or blur), dark outline, limited palette of at most 15 colors, using only the "
    "colors of the second image. Plain flat pure white background, nothing else in the image, no "
    "text. Output a square image."
)
PROMPTS = {
    "back": (
        "The first image is the original 64x64 back battle sprite of {name} (seen from behind, as "
        "the player's Pokemon in battle), enlarged 8x. The second image is the front sprite of its "
        "regional variant, Eien {name}, enlarged 8x. Redraw the back sprite as Eien {name}: keep "
        "exactly the first image's framing, size, position and viewpoint, and give it Eien {name}'s "
        "colors, materials and details as they would look from behind. "
    ),
    "frame2": (
        "The first image shows the two frames of the original 64x64 front sprite animation of "
        "{name}, side by side, enlarged 8x: frame 1 on the left, frame 2 on the right. The second "
        "image is frame 1 of its regional variant, Eien {name}, enlarged 8x. Draw frame 2 of Eien "
        "{name}'s animation: the same small motion that frame 2 makes in the first image, applied "
        "to the second image, with the same framing, size and position, and the feet staying in "
        "place. Draw only the one 64x64 frame. "
    ),
    "icon": (
        "The first image is the original party menu icon of {name}: two 32x32 frames stacked "
        "vertically (a 32x64 strip), enlarged 8x. The second image is the front sprite of its "
        "regional variant, Eien {name}, enlarged 8x. Draw Eien {name}'s party icon: the same two "
        "frames in the same tiny chibi style and pose as the first image, with Eien {name}'s "
        "colors and details. Put the 32x64 strip in the middle of a 64x64 pixel grid enlarged 8x, "
        "the rest white. "
    ),
}


def colored(png, pal, crop=None):
    src = Image.open(os.path.join(REPO, png))
    if crop:
        src = src.crop(crop)
    palette = sprite_prep.read_jasc(os.path.join(REPO, pal))
    out = Image.new("RGB", src.size, (255, 255, 255))
    px, sp = out.load(), src.load()
    for y in range(src.height):
        for x in range(src.width):
            if sp[x, y]:
                px[x, y] = tuple(palette[sp[x, y]])
    return out


def image_part(img):
    path = os.path.join("/tmp", "stage_draft_ref.png")
    img.resize((img.width * 8, img.height * 8), Image.NEAREST).save(path)
    return {"inline_data": {"mime_type": "image/png", "data": base64.b64encode(open(path, "rb").read()).decode()}}


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


def references(kind, species):
    vanilla, eien = f"graphics/pokemon/{species}", f"graphics/pokemon/eien/{species}"
    front = colored(f"{eien}/anim_front.png", f"{eien}/normal.pal", (0, 0, 64, 64))
    if kind == "back":
        first = colored(f"{vanilla}/back.png", f"{vanilla}/normal.pal")
    elif kind == "frame2":
        if os.path.exists(os.path.join(REPO, vanilla, "anim_front.png")):
            sheet = colored(f"{vanilla}/anim_front.png", f"{vanilla}/normal.pal")
        else:  # a single-frame species (Wyrdeer): both reference frames are the one front
            single = colored(f"{vanilla}/front.png", f"{vanilla}/normal.pal")
            sheet = Image.new("RGB", (64, 128), (255, 255, 255))
            sheet.paste(single.crop((0, 0, 64, 64)), (0, 0))
            sheet.paste(single.crop((0, 0, 64, 64)), (0, 64))
        first = Image.new("RGB", (128, 64), (255, 255, 255))
        first.paste(sheet.crop((0, 0, 64, 64)), (0, 0))
        first.paste(sheet.crop((0, 64, 64, 128)), (64, 0))
    else:
        first = colored(f"{vanilla}/icon.png", f"graphics/pokemon/icon_palettes/pal{VANILLA_ICON_PALETTE.get(species, 0)}.pal")
    return first, front


def convert(kind, species, raw):
    """The draft as RGBA for the contact sheet, and its indexed file next to raw/."""
    if kind == "icon":
        # the 32x64 strip in the middle of the 64-cell grid, previewed in the Eien icon palette
        grid = sprite_prep.sample_grid(raw, 64).crop((16, 0, 48, 64))
        bg = sprite_prep.background_mask(grid)
        rgba = grid.convert("RGBA")
        for x, y in bg:
            rgba.putpixel((x, y), (0, 0, 0, 0))
        palette = sprite_prep.read_jasc(os.path.join(REPO, EIEN_ICON_PALETTE))
    else:
        img = sprite_prep.sample_grid(raw, 64)
        bg = sprite_prep.background_mask(img)
        rgba = img.convert("RGBA")
        for x, y in bg:
            rgba.putpixel((x, y), (0, 0, 0, 0))
        palette = sprite_prep.read_jasc(os.path.join(REPO, f"graphics/pokemon/eien/{species}/normal.pal"))
    indexed = sprite_prep.index(rgba, palette)
    indexed.save(os.path.join(os.path.dirname(os.path.dirname(raw)), os.path.basename(raw)))
    preview = Image.new("RGBA", indexed.size, (0, 0, 0, 0))
    px = preview.load()
    for y in range(indexed.height):
        for x in range(indexed.width):
            i = indexed.getpixel((x, y))
            if i:
                px[x, y] = tuple(palette[i]) + (255,)
    return preview


def contact_sheet(kind, rows, out):
    scale, pad, label_h = 2, 8, 14
    cw = (32 if kind == "icon" else 64) * scale
    ch = 64 * scale
    cols = 1 + max(len(d) for _, _, d in rows)
    sheet = Image.new("RGB", (pad + cols * (cw + pad), pad + len(rows) * (ch + label_h + pad)), (152, 208, 160))
    draw = ImageDraw.Draw(sheet)
    for r, (species, ref, drafts) in enumerate(rows):
        y = pad + r * (ch + label_h + pad)
        sheet.paste(ref.resize((cw, ch), Image.NEAREST), (pad, y))
        draw.text((pad, y + ch + 2), species, fill=(0, 0, 0))
        for c, (label, rgba) in enumerate(drafts, start=1):
            x = pad + c * (cw + pad)
            tile = Image.new("RGBA", rgba.size, (152, 208, 160, 255))
            tile.alpha_composite(rgba)
            sheet.paste(tile.convert("RGB").resize((cw, ch), Image.NEAREST), (x, y))
            draw.text((x, y + ch + 2), label, fill=(0, 0, 0))
    sheet.save(out)


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("kind", choices=sorted(PROMPTS))
    parser.add_argument("species", nargs="+")
    parser.add_argument("--convert-only", action="store_true")
    args = parser.parse_args()

    rows = []
    for species in args.species:
        name = species.capitalize()
        first, front = references(args.kind, species)
        raw_dir = os.path.join(REPO, "design", "art", f"eien_{species}", f"{args.kind}_drafts", "raw")
        os.makedirs(raw_dir, exist_ok=True)
        drafts = []
        for tag, model in MODELS.items():
            for t in TRIES:
                stem = f"{args.kind}_{tag}_{t}"
                raw = os.path.join(raw_dir, stem + ".png")
                if not args.convert_only:
                    try:
                        # Generate before opening the file, so a failed call keeps the old draft
                        data = generate(model, PROMPTS[args.kind].format(name=name) + STYLE,
                                        [image_part(first), image_part(front)])
                        with open(raw, "wb") as f:
                            f.write(data)
                    except Exception as e:  # keep going; one failed draft shouldn't lose the rest
                        print(f"{species} {stem}: {e}", file=sys.stderr)
                if os.path.exists(raw):
                    drafts.append((f"{tag}_{t}", convert(args.kind, species, raw)))
                    print(species, stem)
        ref = first.crop((64, 0, 128, 64)) if args.kind == "frame2" else first
        rows.append((species, ref, drafts))
    contact_sheet(args.kind, rows, os.path.join(REPO, "design", "art", f"eien_{args.kind}_drafts_contact_sheet.png"))


if __name__ == "__main__":
    main()
