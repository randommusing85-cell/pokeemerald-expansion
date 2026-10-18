# Brainstorm: Eien Hoothoot

Working notes for the second Eien variant (`variants.md`, `locations/route-2.md`). Decisions
move into `variants.md` when settled; this file stays as the record.

## Givens (from the docs)

- Eien Hoothoot, Ghost/Flying: a lantern owl of the night pass, touched by the fading. The
  answer to gym 2 (Fighting): immune to Fighting moves, hits Fighting with Flying.
- Lives on Route 2's mountain pass, grass near the town end, more common at night; caught at
  about Lv 10-15, before gym 2 (ace about Lv 21).
- Variant rules (`variants.md`, `brainstorm-eien-species.md`): a regional form with its own
  form entry; the same stat total as the original (Hoothoot 262, Noctowl 452), redistributed
  to fit the typing; existing abilities that fit the theme; non-starter variants evolve by an
  Eien method (a shrine area, an aurora night, a thin place). Every variant needs front (2
  frames), back, icon, normal and shiny palettes; the starters' and Poochyena's art went
  through AI drafts (`tools/eien_species/`).
- It gets a research entry in the professor's list (side-quests E2), like Eien Poochyena's
  (seen / battled / caught).
- Vanilla Hoothoot: 60 / 30 / 30 / 36 / 56 / 50 (HP / Atk / Def / SpA / SpD / Spe);
  Insomnia / Keen Eye / Tinted Lens; Peck (1), Echoed Voice (6), Confusion (9), Reflect (12),
  Defog (15), Air Slash (18); evolves into Noctowl at Lv 20.

## Decided

- **Look (r1 1b):** a half-faded owl: its wings and tail fade into mist; only the face and
  glowing eyes are solid. Drops the lantern overlap with Eien Torchic; the fading made
  visible, tied to the thinning patch on the same route. Still "the owl of the night pass".
- **Stats (r1 2b):** fast special attacker, 50 / 30 / 26 / 60 / 36 / 60 (HP / Atk / Def / SpA /
  SpD / Spe), 262.
- **Abilities (r1 3b):** Insomnia / Frisk / Cursed Body (hidden).
- **Early moves (r1 4c):** Astonish (1) and Gust (6, replacing Echoed Voice); Ominous Wind (15,
  replacing Defog). Confusion (9), Reflect (12) and Air Slash (18) stay; otherwise vanilla.
- **Evolution (r1 5b):** levels up to 20+ at night on its home pass (Route 2's mountain pass).
  The roadside tablet could hint at it.
- **Research (r1 6d):** seen / battled / caught, like Poochyena, plus a journal note when one
  reaches Lv 20 without evolving (the hint for the rule, like Poochyena's).
- **Eien Noctowl's look (r2 1c):** shrouded: the faded wings stretch into long trailing veils
  that drift behind it like a funeral shroud; bigger and more spectral, still a clear owl.
- **Eien Noctowl's stats (r2 2a):** the same shift as Eien Hoothoot's: 90 / 50 / 46 / 110 / 76
  / 80, 452.
- **On evolving (r2 3a):** learns Hex.
- **Wild rates (r2 4c):** about 10% by day, 30% at night, on the pass near the town end.
- **Shiny (r2 5b):** aurora mist, green-violet instead of grey (for both stages).
- **Defaults (r2):** Eien Noctowl keeps Eien Hoothoot's abilities and the name "Eien Noctowl";
  dex entries are drafts written at build time; sprites through AI drafts like Poochyena's.

## Leaning

## Open questions

Still open after round 2: the dex entries (drafted at build time), the roadside tablet's
hint for the night-pass rule (part of the tablet text), the exact rates fitted to the land
slots.

## Gaps and tensions

- Eien Torchic is already "a shrine-lantern bird" (Fire/Ghost) (settled by r1 1b: the
  half-faded owl; `variants.md` and `route-2.md` still say "lantern owl" until promoted).
- r1 5b: "at night on the pass" needs the engine's time and map conditions together (`IF_TIME`
  and `IF_IN_MAP` or `IF_IN_MAPSEC` on one evolution entry).
- r1 6d: a second no-evolution note means another journal flag, and the research page is
  already full with Poochyena's note (`variants.md`): it may need to scroll.
- Gym 2 is Fighting: its leader's Pokémon will likely carry a Rock or Dark move for Ghost and
  Flying (to be settled in the gym 2 team brainstorm), so Hoothoot shouldn't be a free win.
- An aurora-night evolution couldn't happen until Act 3 (aurora nights only return after
  Kaede's step 2).
- Eien Noctowl's look and name follow from the answers here.

## Parked ideas

## Rejected
