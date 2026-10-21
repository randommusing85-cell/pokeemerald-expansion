#!/usr/bin/env python3
"""Second-round front drafts for an evolved Eien starter whose first concepts missed the brief
(design/brainstorm-eien-starters-finals.md: Eien Blaziken's paper lantern float).

Like evolved_drafts.py, but the colour reference is the picked middle stage's front
(graphics/pokemon/eien/<middle>/) instead of the first stage's, and the brief is stronger.
Writes design/art/eien_<species>/drafts/{raw,converted}/front_<model>_r2_<try>.png and
design/art/eien_<species>_r2_contact_sheet.png. AI-assisted art: credit it in
design/asset-credits.md when a draft is used.
  tools/eien_species/final_redrafts.py
  tools/eien_species/final_redrafts.py --convert-only
"""

import argparse
import os
import sys

from evolved_drafts import MODELS, REPO, TRIES, contact_sheet, convert, frame1, generate, image_part

# species: (vanilla name, picked middle stage, the brief)
SPECIES = {
    "blaziken": ("Blaziken", "combusken", (
        "Eien Blaziken is Fire/Ghost: it IS a Nebuta festival float, the giant illuminated paper "
        "lantern sculptures of Aomori's summer festival, shaped as a warrior. Its whole body is "
        "white washi paper stretched over a visible thin dark frame (the frame lines show through "
        "the paper like the ribs of a lantern), glowing warm from inside with a pale blue-violet "
        "ghost flame. Its face is a fierce painted warrior's face in bold black, red and blue "
        "brush strokes on the paper, like a Nebuta float's painted face. The wrist and leg flames "
        "are blue-violet ghost fire.")),
}

PROMPT = (
    "The first image is the original 64x64 front battle sprite of {name}, enlarged 8x. The second "
    "image is the front sprite of Eien {middle}, its regional variant's previous stage, enlarged 8x. "
    "Redraw {name} as its regional variant, Eien {name}, for a Pokemon fan game, keeping the "
    "second image's colors so the line looks like one family. {brief} Keep exactly the same pose, "
    "the same framing, size and position in the frame, and the same silhouette as the first image, "
    "so it is still clearly {name}. Style: Gen 4/5 Pokemon battle sprite pixel art drawn on a "
    "64x64 pixel grid and enlarged 8x (crisp square pixels, no anti-aliasing, no gradients or "
    "blur), dark outline, limited palette of at most 15 colors. Plain flat pure white background, "
    "nothing else in the image, no text. Output a square image."
)


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("--convert-only", action="store_true")
    args = parser.parse_args()
    for species, (name, middle, brief) in SPECIES.items():
        original = frame1(f"graphics/pokemon/{species}/anim_front.png", f"graphics/pokemon/{species}/normal.pal")
        reference = frame1(f"graphics/pokemon/eien/{middle}/anim_front.png", f"graphics/pokemon/eien/{middle}/normal.pal")
        base = os.path.join(REPO, "design", "art", f"eien_{species}", "drafts")
        raw_dir, out_dir = os.path.join(base, "raw"), os.path.join(base, "converted")
        os.makedirs(raw_dir, exist_ok=True)
        os.makedirs(out_dir, exist_ok=True)
        drafts = []
        for tag, model in MODELS.items():
            for t in TRIES:
                stem = f"front_{tag}_r2_{t}"
                raw = os.path.join(raw_dir, stem + ".png")
                if not args.convert_only:
                    prompt = PROMPT.format(name=name, middle=middle.capitalize(), brief=brief)
                    try:
                        # Generate before opening the file, so a failed call keeps the old draft
                        data = generate(model, prompt, [image_part(original), image_part(reference)])
                        with open(raw, "wb") as f:
                            f.write(data)
                    except Exception as e:  # keep going; one failed draft shouldn't lose the rest
                        print(f"{species} {stem}: {e}", file=sys.stderr)
                if os.path.exists(raw):
                    rgba = convert(raw, os.path.join(out_dir, stem + ".png"), os.path.join(out_dir, stem + ".pal"))
                    drafts.append((stem.replace("front_", ""), rgba))
                    print(species, stem)
        if drafts:
            contact_sheet([(species, original, drafts)],
                          os.path.join(REPO, "design", "art", f"eien_{species}_r2_contact_sheet.png"))


if __name__ == "__main__":
    main()
