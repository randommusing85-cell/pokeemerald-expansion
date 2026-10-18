# Brainstorm: Route 2's trainers and wild tables

Working notes for the trainers and wild Pokémon on Route 2, the mountain pass
(`locations/route-2.md`). Decisions move into the route doc and `progression.md` when settled;
this file stays as the record.

## Givens (from the docs)

- Route 2 climbs from Lake Usurai (snowy forest) to Yunotaki (steam vents, bare rock). Order:
  Haru's handover → trainers → the thinning patch midway → a quieter stretch with the
  roadside shrine side path and the Hoothoot grass → Yunotaki. The shrine is its own small map.
- Trainers: locals at their jobs (woodcutter, inn porter, charcoal burner) and pilgrims
  climbing to the falls (Fighting-leaning, previewing the gym). Lv 12-17. Names are
  placeholders when built. No spare trainer slots: new trainers reuse vanilla Hoenn slots.
  Trainer class names hold 12 characters. Gym 2 adds a PILGRIM class.
- Wild: Lv 10-15. Eien Hoothoot in the grass near the town end, about 10% by day and 30% at
  night; the route's one notable Pokémon. It evolves at Lv 20+ at night on this route.
  Day and night tables, like Route 1 (`OW_TIME_OF_DAY_ENCOUNTERS`).
- Gym 2 is Fighting (Ibuki: Throh, Sawk, Medicham; pilgrims with Makuhita and Meditite).
  Answers: Eien Hoothoot, the Torchic and Bulbasaur lines; Eien Poochyena is 4x weak.
- Species so far: Route 1 has Starly, Bidoof, Zigzagoon, Wingull, Machop, Snover, Eien
  Poochyena, Shuppet (shrine). Kaede's shrine has Duskull. Lake Usurai has no wild table.

## Decided

- **Maps (r1 1a):** the route is two maps: a lower snowy forest and an upper stretch of steam
  vents and rock. Each has its own grass tables; Eien Hoothoot is only in the upper one.
- **Trainer count (r1 2b):** six: woodcutter, inn porter, charcoal burner, a pilgrim, a second
  pilgrim, and a pilgrim pair in a double battle.
- **Classes (r1 3a):** all new: WOODCUTTER, PORTER, CHARCOALER, and PILGRIM (shared with gym 2).
- **Locals' teams (r1 4a+d):** job Pokémon: the woodcutter Pineco and Timburr, the porter
  Machop and a pack Pokémon, the charcoal burner Slugma or Numel. One local has a vanilla
  Hoothoot and says the owls up here look see-through at night.
- **Wild species (r1 5b):** lower forest Snorunt, Swinub, Pineco; upper vents Geodude, Numel,
  Meditite and Eien Hoothoot.
- **Lake Usurai (r1 6b):** Tomo the Ice Fisher gives an Old Rod after the badge; the lake gets a
  fishing table (Magikarp, Goldeen, Spheal).
- **The patch (r2 1a+c):** at the end of the lower map; the grass around it is empty (Pokémon
  flee it). The upper map opens quietly after it.
- **Trainer spread (r2 2b):** lower map: woodcutter, porter, first pilgrim; upper map, by the
  vents: charcoal burner (his kiln needs the heat), second pilgrim, the pilgrim pair.
- **Teams (r2 3c):** porter Machop only (Lv 14); pilgrims Tyrogue; Mankey and Machop; the pair
  Mankey and Makuhita. Meditite stays for the gym and the wild.
- **The Hoothoot hint (r2 4a):** the charcoal burner has the vanilla Hoothoot; he works the kilns
  through the night and has seen the see-through owls.
- **Hoothoot's evolution (r2 5a):** Lv 20+ at night on the upper map only.
- **Haru (r2 6a):** only gives the Town Map; no battle.
- **Lower map wild (r3 1b):** Lv 10-13. Day: Snorunt 30%, Swinub 30%, Pineco 25%, Starly 15%.
  Night: Snorunt 35%, Swinub 30%, Pineco 25%, Sneasel 10% (no Starly; it roosts).
- **Upper map wild (r3 2a):** Lv 12-15. Day: Geodude 30%, Numel 30%, Meditite 20%, Eien Hoothoot
  10%, Machop 10%. Night: Eien Hoothoot 30%, Geodude 25%, Numel 25%, Meditite 20%.
- **Fishing (r3 3b):** Tomo stands on Lake Usurai's shore after the badge and gives the Old Rod.
  Old Rod table: Magikarp 60%, Goldeen 30%, Spheal 10%.
- **Items (r3 4c):** lower map Super Potion, Great Ball; upper map Charcoal, Revive; hidden Burn
  Heal by the vents.
- **Charcoal burner (r3 5a):** Slugma Lv 15 and Hoothoot Lv 15.
- **Music (r3 6b, vanilla placeholders):** lower map Route 119's forest track, upper map Mt.
  Chimney's ascent; the patch scene plays silence.
- **Defaults (r3):** levels: woodcutter Pineco 12, Timburr 13; porter Machop 14; first pilgrim
  Tyrogue 14; charcoal burner Slugma 15, Hoothoot 15; second pilgrim Mankey 15, Machop 16; the
  pair Mankey 16 and Makuhita 17. Vanilla level-up moves. Lake Usurai fishing has one table
  for day and night. Trainer names are placeholders.

## Leaning

## Open questions

Promoted into `locations/route-2.md`, `locations/shimotsuki.md`, `progression.md`,
`variants.md` and `whats-left.md`. Nothing open from rounds 1-3. Still open later: the trainers' names (placeholders), their
lines, the two maps' layouts (Porymap).

## Gaps and tensions

- Settled in round 2: Hoothoot's evolution map, the patch's place, Haru, the patch's grass.
- A map has one grass table (settled by r1 1a: two maps).
- Lake Usurai has no wild table and he has no rod yet (settled by r1 6b).

## Parked ideas

## Rejected
