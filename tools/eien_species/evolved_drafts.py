#!/usr/bin/env python3
"""Draft front sprites for the evolved Eien starters (design/variants.md, "Evolved stages").

Each draft gets two references: frame 1 of the vanilla species' front sprite (pose, framing,
silhouette) and frame 1 of the Eien first stage's front (colors and materials), both enlarged
8x. The output is sampled to 64x64 and cut to 15 colors plus the transparent key color, like the
first stages' drafts (design/art/eien_starters_drafts.md). Raw output is kept for reference.

  tools/eien_species/evolved_drafts.py                    # all six
  tools/eien_species/evolved_drafts.py combusken ivysaur
  tools/eien_species/evolved_drafts.py --convert-only     # redo the 64x64 files from raw/

Writes design/art/eien_<species>/drafts/{raw,converted}/ and the contact sheet
design/art/eien_evolved_contact_sheet.png. AI-assisted art: credit it in
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

# species: (vanilla name, Eien first stage whose colors it takes, the brief from variants.md)
SPECIES = {
    "combusken": ("Combusken", "torchic", (
        "Eien Combusken is Fire/Ghost: a leaping dancer from Aomori's Nebuta lantern festival. "
        "Its feathers look like glowing lantern paper (washi) stretched over a thin frame, lit "
        "from inside by a pale blue-violet ghost flame, with a few painted festival markings. "
        "It is in mid-dance, light on its feet.")),
    "ivysaur": ("Ivysaur", "bulbasaur", (
        "Eien Ivysaur is Grass/Psychic, a fading bloom between worlds: the bud on its back has "
        "half opened, its petals are partly translucent, and a small aurora (green, teal and "
        "violet light) swirls inside them. Calm, half-closed eyes.")),
    "frogadier": ("Frogadier", "froakie", (
        "Eien Frogadier is Water/Ice, adapted to the cold: a snow scout wearing a cape of woven "
        "straw (a Japanese mino rain cape) over its shoulders and small snowshoes, with frost in "
        "place of its bubbles. Alert and quiet, like a scout in deep snow.")),
    "blaziken": ("Blaziken", "torchic", (
        "Eien Blaziken is Fire/Ghost: it is itself a giant Nebuta festival float of a warrior, "
        "made of glowing lantern paper over a frame, lit from inside by a pale blue-violet ghost "
        "flame, with a fierce painted warrior face and painted patterns. A towering fighter.")),
    "venusaur": ("Venusaur", "bulbasaur", (
        "Eien Venusaur is Grass/Psychic: the great flower on its back is fully open and partly "
        "translucent, and an aurora (green, teal and violet light) streams up from it toward the "
        "sky. Calm and ancient.")),
    "greninja": ("Greninja", "froakie", (
        "Eien Greninja is Water/Ice: a lone mountain guardian of the snow passes, wearing a "
        "woven straw cape and hat (mino and kasa) over its body, its tongue scarf turned to "
        "frost, alert and still like a guardian standing watch in a blizzard.")),
}

PROMPT = (
    "The first image is the original 64x64 front battle sprite of {name}, enlarged 8x. The second "
    "image is the front sprite of Eien {first}, its regional variant's first stage, enlarged 8x. "
    "Redraw {name} as its regional variant, Eien {name}, for a Pokemon fan game, using the second "
    "image's colors and materials so the line looks like one family. {brief} Keep exactly the "
    "same pose, the same framing, size and position in the frame, and the same silhouette as the "
    "first image, so it is still clearly {name}. Style: Gen 4/5 Pokemon battle sprite pixel art "
    "drawn on a 64x64 pixel grid and enlarged 8x (crisp square pixels, no anti-aliasing, no "
    "gradients or blur), dark outline, limited palette of at most 15 colors. Plain flat pure white "
    "background, nothing else in the image, no text. Output a square image."
)


def frame1(png, pal):
    """Frame 1 of a front sprite sheet, colored with its palette, on white, as RGB."""
    src = Image.open(os.path.join(REPO, png))
    palette = sprite_prep.read_jasc(os.path.join(REPO, pal))
    img = src.crop((0, 0, 64, 64))
    out = Image.new("RGB", (64, 64), (255, 255, 255))
    px = out.load()
    for y in range(64):
        for x in range(64):
            i = img.getpixel((x, y))
            if i:
                px[x, y] = tuple(palette[i])
    return out


def image_part(img):
    path = os.path.join("/tmp", "evolved_draft_ref.png")
    img.resize((512, 512), Image.NEAREST).save(path)
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


def convert(raw_path, out_png, out_pal):
    img = sprite_prep.sample_grid(raw_path, 64)
    bg = sprite_prep.background_mask(img)
    rgba, _ = sprite_prep.fit(img, bg, 64)
    palette = sprite_prep.build_palette([rgba], 15)
    sprite_prep.index(rgba, palette).save(out_png)
    sprite_prep.write_jasc(out_pal, palette)
    return rgba


def contact_sheet(rows, out):
    """rows: [(species, original RGB, [(label, rgba), ...])], the original first in each row."""
    scale, pad, label_h = 2, 8, 14
    cell = 64 * scale
    cols = 1 + max(len(d) for _, _, d in rows)
    sheet = Image.new("RGB", (pad + cols * (cell + pad), pad + len(rows) * (cell + label_h + pad)), (255, 255, 255))
    draw = ImageDraw.Draw(sheet)
    for r, (species, original, drafts) in enumerate(rows):
        y = pad + r * (cell + label_h + pad)
        sheet.paste(original.resize((cell, cell), Image.NEAREST), (pad, y))
        draw.text((pad, y + cell + 2), species + " (vanilla)", fill=(0, 0, 0))
        for c, (label, rgba) in enumerate(drafts, start=1):
            x = pad + c * (cell + pad)
            tile = Image.new("RGBA", (64, 64), (255, 255, 255, 255))
            tile.alpha_composite(rgba)
            sheet.paste(tile.convert("RGB").resize((cell, cell), Image.NEAREST), (x, y))
            draw.text((x, y + cell + 2), label, fill=(0, 0, 0))
    sheet.save(out)


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("species", nargs="*", help="default: all of " + ", ".join(SPECIES))
    parser.add_argument("--convert-only", action="store_true")
    args = parser.parse_args()
    for species in args.species:
        if species not in SPECIES:
            parser.error(f"unknown species {species}")
    args.species = args.species or list(SPECIES)

    rows = []
    for species in SPECIES:
        name, first, brief = SPECIES[species]
        original = frame1(f"graphics/pokemon/{species}/anim_front.png", f"graphics/pokemon/{species}/normal.pal")
        eien_first = frame1(f"graphics/pokemon/eien/{first}/anim_front.png", f"graphics/pokemon/eien/{first}/normal.pal")
        base = os.path.join(REPO, "design", "art", f"eien_{species}", "drafts")
        raw_dir, out_dir = os.path.join(base, "raw"), os.path.join(base, "converted")
        os.makedirs(raw_dir, exist_ok=True)
        os.makedirs(out_dir, exist_ok=True)
        drafts = []
        for tag, model in MODELS.items():
            for t in TRIES:
                stem = f"front_{tag}_{t}"
                raw = os.path.join(raw_dir, stem + ".png")
                if species in args.species and not args.convert_only:
                    prompt = PROMPT.format(name=name, first=first.capitalize(), brief=brief)
                    try:
                        # Generate before opening the file, so a failed call keeps the old draft
                        data = generate(model, prompt, [image_part(original), image_part(eien_first)])
                        with open(raw, "wb") as f:
                            f.write(data)
                    except Exception as e:  # keep going; one failed draft shouldn't lose the rest
                        print(f"{species} {stem}: {e}", file=sys.stderr)
                if os.path.exists(raw):
                    rgba = convert(raw, os.path.join(out_dir, stem + ".png"), os.path.join(out_dir, stem + ".pal"))
                    drafts.append((stem.replace("front_", ""), rgba))
                    print(species, stem)
        if drafts:
            rows.append((species, original, drafts))
    contact_sheet(rows, os.path.join(REPO, "design", "art", "eien_evolved_contact_sheet.png"))


if __name__ == "__main__":
    main()
