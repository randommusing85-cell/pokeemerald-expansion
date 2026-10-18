# Brainstorm: place and people names (Route 2 and the hot-spring town)

Working notes for the names still marked as placeholders after the Route 2, gym 2 and Eien
Hoothoot brainstorms. Decisions move into the location docs and `characters.md` when settled;
this file stays as the record.

## Givens (from the docs)

- Names follow Japanese naming (`characters.md`). Towns so far are short poetic compounds:
  Hamakaze (浜風, "beach wind"), Shimotsuki (霜月, "frost month"). The first route is "Route 1".
- Placeholders now: the lake path north of Shimotsuki (`MAP_EIEN_ROUTE2`, region-map name
  "ROUTE 2"), Route 2's mountain pass (planned as its own map), the hot-spring town, the
  villain faction, the young researcher. The gym 2 leader is Ibuki.
- The faction: principled people who want to stop Arceus's cycle by drawing energy from other
  worlds through Palkia's door. Leader Minato, lieutenant Hashimoto. They first appear dressed
  as field researchers, and nobody finds them suspicious.
- The young researcher: warm, loves Pokémon, fascinated by Celebi; returns at the tournament
  on the other side. Gender not set.
- Names in use: Akira, Haru, Nami, Kaede, Fuyumi, Kashiwagi, Yuki, Tetsu, Ren, Seiji, Minato,
  Hashimoto, Ibuki; route trainers Shin, Goro, Emi, Riku; gym trainers Tomo, Saya
  (placeholders).
- Text limits: map names on the region map and the location pop-up hold 16 characters; the
  game's text has no long vowels (ō, ū), so names are spelled plainly (RAIZO, not RAIZŌ).

## Decided

- **Routes (r1 1b):** numbers for routes, names for landmarks. The mountain pass is Route 2;
  the lake path takes the lake's name.
- **The hot-spring town (r1 2a):** Yunotaki (湯の滝, "hot-water falls"), after the falls where
  Ibuki trains.
- **The lake (r1 3a):** Lake Usurai (薄氷, "thin ice"): frozen at the edges, open in the middle.
  The lake path's region-map name becomes "LAKE USURAI".
- **The faction (r1 4d):** a public name in Act 1, "the Eien Survey" (they look like field
  researchers); their true name, Tokoyo (常世, the eternal land of Japanese myth), comes out at
  the tournament.
- **The young researcher (r1 5a):** Hinata (陽向, "sunny place"), a young woman.
- **Shimotsuki's gym trainers (r2 1a):** Tomo (Ice Fisher) and Saya (Shoveler) stay.
- **The pilgrims (r2 2a):** Daichi ("earth", Makuhita) and Shizuka ("quiet", Meditite).
- **Kashiwagi's husband (r2 3b):** Makoto (誠, "sincerity").
- **Kaede's grandmother (r2 4a):** Chiyo (千代, "a thousand generations").
- **Default (r2):** the trainers on the pass get placeholder names when built, `TODO(design)`.

## Leaning

## Open questions

Promoted into `characters.md`, `story-outline.md`, `progression.md`, `whats-left.md` and
the location docs (`onsen-town.md` renamed `yunotaki.md`); the lake path's region-map name
is LAKE USURAI in the game. Still open: the trainers on the pass (placeholders when built).

## Gaps and tensions

- The faction's name has to work twice (settled by r1 4d: two names).
- r1 1b + 3a: the built lake map keeps its constant `MAP_EIEN_ROUTE2` (renaming map constants
  is churn), but its region-map section and pop-up become "LAKE USURAI"; the pass gets the
  "ROUTE 2" section when it's built. The location docs need the same change.
- Smaller names (settled by round 2): the gym trainers, the pilgrims, Kashiwagi's husband,
  Kaede's grandmother. The route trainers on the pass wait for the build.

## Parked ideas

## Rejected
