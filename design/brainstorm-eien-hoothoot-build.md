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

- **Evolution (r1 1a):** like Eien Wooper's, no evolution entry until `MAP_EIEN_ROUTE2_UPPER`
  exists. The journal's Lv 20 note covers the meantime.
- **Where to catch it (r1 2a):** nowhere yet. Species data only, tested through the debug menu,
  until the pass maps are built.
- **Research opener (r1 3a):** the professor's list. She opens every variant's research in the
  lab at the start (where she opens Poochyena's now); unseen ones show as "???" until met. This
  also gives Eien Wooper its opener.
- **Sprites (r1 4d):** one draft round with three mist concepts: pale solid mist, dithered mist,
  and mist that fades to loose pixels at the tips. Picked from the contact sheet.
- **Eien Noctowl's veils (r1 5b):** hanging down behind it into the space below the wings, a
  shroud shape inside 64x64.

- **Unseen entries (r2 1a):** "???" as the title, and a hint naming the place ("Something on
  Route 2.").
- **When entries show (r2 2b):** the professor gives the whole list at the lab, but each entry
  only shows in the journal once the hero reaches its region: Hoothoot after gym 1, Wooper
  after gym 2 (the badge flags decide; no new flags).
- **Research rewards (r2 3d):** left for E2's own brainstorm. Hoothoot's research is built
  without rewards, like Poochyena's.
- **Build order (r2 4b):** the data and the professor's list, plus the draft round, together.
  The art goes into the same PR once picked.

## Leaning

## Open questions

- The drafts' picks (after the draft round).
- Both dex entries and the research tier lines: drafted at build time, marked `TODO(design)`.
- E2's rewards (its own brainstorm).

## Gaps and tensions

- The research detail page holds four tiers plus one note per species, so a second species'
  note doesn't crowd Poochyena's page. The "may need to scroll" worry in `variants.md` looks
  settled (to check at build).
- E2 closes when the professor dies: closing it must close every open research entry, not just
  Poochyena's (for her death scene's build).
- The roadside tablet's hint for the night rule belongs to the Route 2 maps' build, not this one.

## Parked ideas

## Rejected
