# Brainstorm: building Eien Hoothoot

Working notes for building Eien Hoothoot and Eien Noctowl. The design is settled
(`variants.md`, `brainstorm-eien-hoothoot.md`); these are the questions the build raises.
Decisions move into `variants.md` (and `locations/route-2.md`) when settled; this file stays as
the record.

## Givens (from the docs)

- **The forms** (`variants.md`):
  - Eien Hoothoot: Ghost/Flying, 50 / 30 / 26 / 60 / 36 / 60, Insomnia / Frisk / Cursed Body.
    Moves: Astonish 1, Gust 6, Ominous Wind 15.
  - Eien Noctowl: 90 / 50 / 46 / 110 / 76 / 80, the same abilities, learns Hex on evolving.
  - Shiny: aurora mist, green-violet, for both stages. Dex entries are drafted at build time.
- **Look:** Hoothoot is a half-faded owl whose wings and tail fade into mist; only the face and
  glowing eyes are solid. Noctowl's faded wings stretch into long trailing veils, like a
  funeral shroud.
- **Evolution:** Lv 20+ at night on Route 2's upper map only (`IF_TIME` plus a map condition).
  The journal notes one that reaches Lv 20 without evolving (its own flag).
- **Where it lives:** Route 2's upper map, 10% by day and 30% at night. That map isn't built:
  the pass maps (`MAP_EIEN_ROUTE2_LOWER` / `_UPPER`, placeholders) wait on Porymap. Today
  `MAP_EIEN_ROUTE2` is the Lake Usurai map, with a fishing table only. Yunotaki and gym 2 are
  built.
- **Research:** seen / battled / caught, part of the professor's list (side-quests E2). Eien
  Poochyena's quest is opened by the professor in her lab
  (`data/maps/Hamakaze_Lab/scripts.inc`). Eien Wooper's quest has no opener yet
  (`TODO(design)`). The journal already shows an unseen entry as "???".
- **Gym 2:** Ibuki's Throh has Rock Tomb and his Sawk has Bite, so Eien Hoothoot isn't a free win.
- **Precedent from Eien Wooper's build:**
  - The evolution waited on its map.
  - Placeholder palettes came first, then AI drafts, picked fronts, backs, idle frames, icons
    and shinies.

## Decided

## Leaning

## Open questions

Round 1 (asked): the evolution without its map, where to catch it meanwhile, who opens the
research, the sprites' mist treatment, how Eien Noctowl's veils fit the frame.

## Gaps and tensions

- The research detail page holds four tiers plus one note per species, so a second species'
  note doesn't crowd Poochyena's page. The "may need to scroll" worry in `variants.md` looks
  settled (to check at build).
- The roadside tablet's hint for the night rule belongs to the Route 2 maps' build, not this one.

## Parked ideas

## Rejected
