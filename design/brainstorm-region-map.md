# Brainstorm: the Eien region map

Working notes. Decisions move into `game-bible.md` (The region) and `progression.md`, and the
built map into `src/data/region_map/`, when settled; this file stays as the record.

## Givens (from the docs and the engine)

- **Region:** Eien, northern Honshu snow country (Tohoku, Aomori): fishing towns, snowy inland
  towns, old shrines, a volcanic mountain (Tobira-yama, modeled on Osorezan) with the League
  (Tokiwa Hall) on its caldera lake. `TODO(design)` until now: map layout, route count.
- **Places and links (from the location docs):** Hamakaze (coast, start) → Route 1 north →
  Shimotsuki (snowy inland) → Lake Usurai north → Route 2's mountain pass north → Yunotaki (hot
  springs) → Route 3 east, a gorge down to the coast → Isaribi (fishing port; the docs say "Sea of
  Japan") → Route 4 east/inland across the rice plain → Hanashiro (castle town; onward
  `TODO(design)`). Shimotsuki → Route 5 east (beech forest) → Kanaya (ironworks) → Route 6 east →
  Minori (rice terraces) → Route 7 up → Hoshimi (plateau observatory) → Route 8 down → Uminari
  (tuna port on a strait, on the door mountain's peninsula) → Route 9 inland → Kawara (temple town)
  → the caldera lake → Tokiwa Hall and Tobira-yama. Route 3's cave exit has the first view of the
  door mountain smoking on the horizon. A thin place under Hamakaze's beach.
- **Engine:** the Town Map is Hoenn's region map (28 x 15 cells, `MAP_WIDTH`/`MAP_HEIGHT`;
  `src/data/region_map/region_map_layout.h` says which section each cell is; sections' x/y/w/h in
  `region_map_sections.json`; the art is a tileset and tilemap in `graphics/pokenav/region_map/`).
  Eien's places currently borrow Hoenn squares as placeholders (`progression.md`). The title and
  "{REGION}" still say HOENN.
- **Rules:** tilesets/art community or AI, credited (`asset-credits.md`); GBA palette limits.

## Decided

## Leaning

## Open questions

## Gaps and tensions

## Parked ideas

## Rejected
