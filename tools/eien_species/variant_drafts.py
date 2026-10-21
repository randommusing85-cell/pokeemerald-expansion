#!/usr/bin/env python3
"""Front sprite drafts for Eien variants without an Eien first stage to copy (design/variants.md).

Each draft gets frame 1 of the vanilla species' front sprite (pose, framing, silhouette),
enlarged 8x, and one concept brief. Every concept is tried on both models. The output is sampled
to 64x64 and cut to 15 colors plus the transparent key color, like the starters' drafts
(design/art/eien_starters_drafts.md). Raw output is kept for reference.

  tools/eien_species/variant_drafts.py                    # all species
  tools/eien_species/variant_drafts.py wooper
  tools/eien_species/variant_drafts.py --convert-only     # redo the 64x64 files from raw/

Writes design/art/eien_<species>/drafts/{raw,converted}/ and the contact sheet
design/art/eien_<species>_contact_sheet.png. AI-assisted art: credit it in
design/asset-credits.md when a draft is used.
"""

import argparse
import os
import sys

from evolved_drafts import MODELS, REPO, contact_sheet, convert, frame1, generate, image_part

# species: (vanilla name, the shared brief from variants.md, {concept: its own details})
SPECIES = {
    "wooper": ("Wooper", (
        "Eien Wooper is Ground/Steel, a mine Wooper that lives in the muddy pools of an old mine "
        "tunnel. Its skin is crusted with iron and copper ore, and its gill frills are stiff and "
        "glint like metal. Keep its round, friendly face."), {
        "a": "Patchy crust: iron-grey skin with rust-brown and copper-orange ore patches, the gill "
             "frills like hammered copper.",
        "b": "Wet slate: dark wet blue-grey stone skin with small bright copper nuggets embedded "
             "in it, the gill frills like thin iron fins with copper tips.",
        "c": "Raw ore: rough, lumpy iron ore over its back and tail, a smoother pale grey belly, "
             "the gill frills like riveted metal plates.",
    }),
    "quagsire": ("Quagsire", (
        "Eien Quagsire is Ground/Steel, the evolution of a mine Wooper: its body is smooth "
        "polished metal like a Nanbu tetsubin, the cast-iron kettle of Iwate's ironware craft. "
        "Keep Quagsire's goofy, open-mouthed face exactly."), {
        "a": "Classic tetsubin: near-black cast iron covered in the kettle's small raised hobnail "
             "bumps (arare pattern), with a soft shine on the polished parts.",
        "b": "Rusted kettle: warm rust-brown iron with darker hobnail bumps on its back, the belly "
             "smoother and lighter, a few copper accents left from the ore.",
        "c": "Polished iron: smooth dark iron with a strong highlight, faint copper ore veins on "
             "its arms and tail, as if Eien Wooper's crust had been polished smooth.",
    }),
}

PROMPT = (
    "The image is the original 64x64 front battle sprite of {name}, enlarged 8x. Redraw {name} "
    "as its regional variant, Eien {name}, for a Pokemon fan game. {brief} {concept} Keep exactly "
    "the same pose, the same framing, size and position in the frame, and the same silhouette as "
    "the image, so it is still clearly {name}. Style: Gen 4/5 Pokemon battle sprite pixel art "
    "drawn on a 64x64 pixel grid and enlarged 8x (crisp square pixels, no anti-aliasing, no "
    "gradients or blur), dark outline, limited palette of at most 15 colors. Plain flat pure white "
    "background, nothing else in the image, no text. Output a square image."
)


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("species", nargs="*", help="default: all of " + ", ".join(SPECIES))
    parser.add_argument("--convert-only", action="store_true")
    args = parser.parse_args()
    for species in args.species:
        if species not in SPECIES:
            parser.error(f"unknown species {species}")

    for species in args.species or list(SPECIES):
        name, brief, concepts = SPECIES[species]
        original = frame1(f"graphics/pokemon/{species}/anim_front.png", f"graphics/pokemon/{species}/normal.pal")
        base = os.path.join(REPO, "design", "art", f"eien_{species}", "drafts")
        raw_dir, out_dir = os.path.join(base, "raw"), os.path.join(base, "converted")
        os.makedirs(raw_dir, exist_ok=True)
        os.makedirs(out_dir, exist_ok=True)
        drafts = []
        for concept, details in concepts.items():
            for tag, model in MODELS.items():
                stem = f"front_{tag}_{concept}"
                raw = os.path.join(raw_dir, stem + ".png")
                if not args.convert_only:
                    prompt = PROMPT.format(name=name, brief=brief, concept=details)
                    try:
                        # Generate before opening the file, so a failed call keeps the old draft
                        data = generate(model, prompt, [image_part(original)])
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
                          os.path.join(REPO, "design", "art", f"eien_{species}_contact_sheet.png"))


if __name__ == "__main__":
    main()
