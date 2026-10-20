# Brainstorm: the Eien region map

Working notes. Decisions move into `game-bible.md` (The region) and `progression.md`, and the
built map into `src/data/region_map/`, when settled; this file stays as the record. **Built** as a placeholder
(`tools/eien_region_map/make_map.py`; shots in `art/region_map/`). **Promoted** into
`game-bible.md`, `progression.md`, `story-outline.md`, `locations/isaribi.md`, `route-3.md` and
`whats-left.md`.

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

- **Shape (r1 1b):** two bands going east (north: Yunotaki → Isaribi → Hanashiro; south: Shimotsuki →
  Kanaya → Minori → Hoshimi) with the peninsula to the north-east, closed into a ring around a
  central range of mountains by a road from Hanashiro down to Hoshimi's plateau, opened late.
- **Compass (r1 2a):** Eien's compass is its own: Isaribi's sea is "the northern sea" (or a bay);
  the docs drop "Sea of Japan". Inspired by Aomori, not a copy.
- **Hamakaze (r1 3b):** the south-west corner, sea on two sides: the game starts in a corner and
  works outward; the beach where he woke has a wide sea view.
- **The peninsula (r1 4a):** axe-shaped, north-east, like Shimokita: Uminari on its northern tip by
  the strait, Kawara inland, the caldera lake beside Tobira-yama, Tokiwa Hall on the far shore.
- **Art (r1 5a):** a clean placeholder now, drawn by a script from the layout in the region map's
  own tiles; AI-drafted art later, once the layout is proven in game.
- **Optional places (r1 6a):** two small surf-only spots (an island off Hamakaze, a sea cave by
  Isaribi); their content `TODO(design)`.
- **The layout (r2 1a):** as sketched below (cells may be nudged at build time).
- **The ring's road (r2 2b, 3c):** Hanashiro to Hoshimi opens with fast travel (Kumo); no map, only a
  line on the Town Map, travelled by Kumo (a walkable Route 10 can come later).
- **Surf spots (r2 4b):** an islet off Hamakaze and a sea cave by Isaribi; content open (a side-content
  brainstorm).
- **The name (r2 5a):** "EIEN" instead of HOENN in the Town Map's title and in "took a closer look at
  the EIEN region map".
- **Build first (r2 6a):** the scripted placeholder map, and the fly spots moved to their real cells for
  the towns that exist (Hamakaze, Shimotsuki, Yunotaki), with the rest of Eien's places drawn but
  empty; sections for future towns added as each is built.

### The sketch (28 x 15 cells, north up)

`~` sea, `.` land, `^` the central range, `=` routes, `o` the caldera lake, `*` surf spots. H Hamakaze,
S Shimotsuki, Y Yunotaki, I Isaribi, C Hanashiro, K Kanaya, M Minori, O Hoshimi, U Uminari, W Kawara,
T Tobira-yama, L Tokiwa Hall.

```
   0123456789012345678901234567
 0 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 1 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 2 ~~~~~~~~~~*~~~~~~~~~~.U....~
 3 ~~.......I............=....~
 4 ~~.Y=====.====C......===.T.~
 5 ~~.=.^^^^^^^^^^==...=..Wo..~
 6 ~~.=.^^^^^^^^^^^.=.=.....L.~
 7 ~~.=.^^^^^^^^^^^.=O........~
 8 ~~.=.^^^^^^^^^^==....~~~~~~~
 9 ~~.=.........==......~~~~~~~
10 ~~.S=====K==M........~~~~~~~
11 ~~.=.................~~~~~~~
12 ~~.=.................~~~~~~~
13 ~~.H..*..............~~~~~~~
14 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~
```

Cells: Hamakaze (3,13), Route 1 (3,11-12), Shimotsuki (3,10), Lake Usurai (3,9), Route 2's pass
(3,5-8), Yunotaki (3,4), Route 3 (4-8,4), Isaribi (9,3), Route 4 (10-13,4), Hanashiro (14,4), Route 5
(4-8,10), Kanaya (9,10), Route 6 (10-11,10), Minori (12,10), Route 7 (13-17, 9-7), Hoshimi (18,7),
Route 8 (19-22, 6-3), Uminari (22,2), Route 9 (22-23,4), Kawara (23,5), the caldera lake (24,5),
Tobira-yama (25,4), Tokiwa Hall (25,6); the ring's line (15-17, 5-6); the islet (6,13; to sit in the
sea at build), the sea cave (10,2). The Route 1 cell sits on (3,11-12), so Hamakaze's current
placeholder fly spot moves from Littleroot's square to (3,13).

## Leaning

## Open questions

## Gaps and tensions

## Parked ideas

## Rejected
