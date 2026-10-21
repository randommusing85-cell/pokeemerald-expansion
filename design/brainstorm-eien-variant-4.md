# Brainstorm: the next Eien variant

Working notes for the fourth non-starter Eien variant. Decisions move into `variants.md` (and the
location doc) when settled; this file stays as the record.

## Givens (from the docs)

- **The variants so far** (`variants.md`, "Others"): each is a regional form of a Gen 1-5
  species, found on the route before a gym, and each answers that gym:
  - Eien Poochyena (Rock/Dark): Route 1, before the Ice gym.
  - Eien Hoothoot (Ghost/Flying): Route 2, before the Fighting gym.
  - Eien Wooper (Ground/Steel): Route 3, before the Electric gym.
  - Each has a place-based evolution twist, seen / battled / caught research on the
    professor's list (shown after the gym before it), and a journal note for the rule.
  - Some are touched by the fading (Poochyena, Hoothoot); some just adapted to the land
    (Wooper).
- **Variant rules** (`brainstorm-eien-species.md`):
  - Regional forms keep the original's stat total, redistributed.
  - They use existing abilities that fit.
  - Non-starters evolve by an Eien method.
  - 5-10 variants are planned in all. The starters' three lines plus three others are built so
    far.
- **The next stretch** (`story-outline.md` Act 1 beat 9, `locations/route-4.md`,
  `locations/hanashiro.md`):
  - Route 4 is the rice plain inland from Isaribi to Hanashiro, Lv 22-27: rice paddies and farm
    villages, then apple orchards near the castle town. Its planned species are Hoppip, Oddish,
    Seedot, Ledyba and Spinarak, with Applin (rare) in the orchard.
  - On Route 4, an orchard blossoms and withers in an hour (a bigger thinning); the Eien Survey
    ropes it off.
  - Gym 4 is Mamoru (Grass) in Hanashiro, Lv 29-32: Cherrim, Dipplin and Appletun
    (Grass/Dragon, so Ice answers it).
  - Then comes the tournament (Act 2).
- **Medium:** each variant is a full art set (front 2 frames, back, icon, two palettes, per
  stage), drafted with `tools/eien_species/`.

## Decided

- **Role (r1 1c):** it answers gym 4 (Grass), and it's first seen in Route 4's orchard thinning
  scene.
- **Species (r1 2a):** Ledyba / Ledian as Bug/Fire: fireflies (*hotaru*) over the summer rice
  paddies. Ledyba is already on Route 4's list.
- **Fading (r1 3b):** not touched by the fading; adapted to the plain and its paddies, like
  Eien Wooper to the mine.
- **How many more (r1 4b):** one variant for each remaining gym a variant answers well, about
  three more after this one, plus Trubbish's split. That keeps within the planned 5-10.
- **The orchard scene (r2 1c):** unaffected. The orchard greys around them while the fireflies
  keep glowing, the only colour left in the scene, which hints that some Pokémon resist the
  fading. On the GBA this uses the thinning's "kept objects" (two at most): a firefly takes one.
- **Look (r2 2a):** ember fireflies.
  - Eien Ledyba's spots are glowing embers and its abdomen glows orange like a coal.
  - Eien Ledian's light brightens into a lantern-like glow on its back. It's still a firefly,
    distinct from the paper lanterns of Torchic's line.
- **Stats (r2 3a):** special attackers.
  - Eien Ledyba: 40 / 20 / 30 / 70 / 50 / 55 (HP / Atk / Def / SpA / SpD / Spe), 265.
  - Eien Ledian: 55 / 35 / 50 / 95 / 80 / 75, 390.
- **Abilities and moves (r2 4c):**
  - Abilities: Flame Body / Swarm / Illuminate (hidden). In Gen 9, Illuminate stops its
    accuracy from being lowered and ignores the target's evasion; the config is
    `B_ILLUMINATE_EFFECT GEN_LATEST`.
  - Moves: Ember at 1 (replacing Tackle), Will-O-Wisp at 12 (replacing Safeguard), Flame Wheel
    at 15 (replacing Mach Punch); otherwise vanilla.
- **Evolution (r2 5b):** into Eien Ledian at Lv 18+ while it's raining. The engine's
  `IF_WEATHER` condition supports this; Route 4 needs rain some of the time.
- **Research, note and shiny (r2 6, defaults):**
  - Research: seen / battled / caught on the professor's list, shown after gym 3's badge.
  - A journal note when one reaches Lv 18 without evolving.
  - Shiny: a real firefly's pale green light instead of ember orange.

## Leaning

- Eien Ledian keeps Eien Ledyba's abilities (a default, as with the other variants).

## Open questions

- Route 4's weather: how the rain comes and goes (a weather cycle on the map, or rain on some
  visits). This belongs to Route 4's build.
- Both dex entries, drafted at build time.
- The sprites: AI drafts through `tools/eien_species/`, as for the others.

## Gaps and tensions

- r1 1c + 3b: settled by r2 1c (unaffected: it keeps its colour in the greyed orchard).
- r2 1c: the orchard scene's kept objects are the hero's partner and at most two others. A
  firefly takes one, so Yuki or a Survey member can't also stay in colour there.
- r2 5b: Route 4 needs rain. Its doc gives no weather yet.
- Vanilla Ledyba: 40 / 20 / 30 / 40 / 80 / 55 (HP / Atk / Def / SpA / SpD / Spe), 265; Swarm /
  Early Bird / Rattled; Tackle 1, Supersonic 5, Swift 8, screens 12, Mach Punch 15, Roost 19,
  Struggle Bug 22; Ledian at Lv 18: 55 / 35 / 50 / 55 / 110 / 85, 390, Iron Fist hidden.

- The pattern so far is "one variant per route, answering the next gym". Breaking it for one
  variant could be refreshing, or confusing.
- Appletun's weakness to Ice is already "a nod to Fuyumi's gym". An Ice variant would answer
  Mamoru twice over (Appletun 4x).

## Parked ideas

- Trubbish's Fresh Water split (planned in `variants.md`, a new Pokémon, its own brainstorm,
  a later act).

## Rejected
