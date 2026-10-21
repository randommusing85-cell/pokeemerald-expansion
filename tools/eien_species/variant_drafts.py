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
    "hoothoot": ("Hoothoot", (
        "Eien Hoothoot is Ghost/Flying, a half-faded owl of a snowy night mountain pass, touched "
        "by the fading of the world: its wings and tail fade into grey mist, and only its face "
        "and glowing pale eyes are solid. Its colors are cold greys and grey-violet."), {
        "a": "Pale solid mist: the wings and tail are drawn in pale grey-lavender with no dark "
             "outline, soft and flat, so they look faded next to the solid, outlined face.",
        "b": "Dithered mist: the wing and tail edges break into a checkerboard of mist pixels and "
             "empty background pixels, so the background shows through them.",
        "c": "Evaporating mist: the wings and tail are solid near the body and fade outward, "
             "ending in a few loose scattered mist pixels at the tips, as if evaporating.",
    }),
    "noctowl": ("Noctowl", (
        "Eien Noctowl is Ghost/Flying, the evolution of a half-faded owl: bigger and more "
        "spectral, its faded wings stretched into long veils of grey mist that hang down behind "
        "it into the empty space below the wings, like a funeral shroud, still inside the frame. "
        "Only its face and glowing pale eyes are solid. Cold greys and grey-violet."), {
        "a": "Pale solid mist: the veils are drawn in pale grey-lavender with no dark outline, "
             "soft and flat, next to the solid, outlined face and body.",
        "b": "Dithered mist: the veils break into a checkerboard of mist pixels and empty "
             "background pixels toward their edges, so the background shows through them.",
        "c": "Evaporating mist: the veils are solid near the body and fade downward, ending in a "
             "few loose scattered mist pixels at their hems, as if evaporating.",
    }),
    "ledyba": ("Ledyba", (
        "Eien Ledyba is Bug/Fire, an ember firefly of summer rice paddies in northern Japan: its "
        "spots are glowing embers and its abdomen glows orange like a hot coal. Warm, clearly a "
        "fire Pokemon, still clearly Ledyba."), {
        "a": "Red-brown shell with bright orange-yellow ember spots that glow, a glowing orange "
             "abdomen; dark limbs.",
        "b": "Charcoal-black shell like burnt wood, its spots glowing ember cracks, and an "
             "abdomen like a coal glowing orange through the dark.",
        "c": "Warm amber shell with small glowing ember spots, and a big softly glowing "
             "yellow-orange firefly light at the tip of its abdomen, like a real firefly's.",
    }),
    "ledian": ("Ledian", (
        "Eien Ledian is Bug/Fire, the evolution of an ember firefly of summer rice paddies: its "
        "light has brightened into a warm lantern-like glow on its back, its spots are glowing "
        "embers. A firefly, not a paper lantern. Still clearly Ledian."), {
        "a": "Red-brown shell with bright ember spots, and its back glowing warm orange like a "
             "lantern through the shell.",
        "b": "Charcoal-black shell like burnt wood with glowing ember cracks, and a bright orange "
             "glow from its back and abdomen.",
        "c": "Warm amber shell with small ember spots and a big softly glowing yellow-orange "
             "firefly light on its back.",
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
