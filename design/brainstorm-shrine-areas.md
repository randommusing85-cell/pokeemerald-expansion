# Brainstorm: shrine areas

Running notes. Nothing is decided until it's under **Decided**; decisions move into
`variants.md` (and the location docs) when the user agrees.

## Givens

- Eien Poochyena evolves into Eien Mightyena by leveling up to 18+ in a shrine area
  (`variants.md`). It doesn't evolve in the game until shrine areas are decided.
- Other Eien variants may also evolve by an Eien method: a shrine area, an aurora night, a thin
  place (`variants.md`).
- Route 1 ends with a small shrine before Shimotsuki; its tileset has the pagoda
  (`locations/route-1.md`). Haru's first quest has him note the shrine.
- Eien Poochyena is caught on Route 1 at Lv 2-5. Gym 1 (Fuyumi, Ice) has an ace at Lv 13-14,
  and soft level caps follow the next gym (`progression.md`). So it reaches Lv 18 after gym 1.
- The "thin place" terrain applies at shrines and the mountain and boosts Ghost and Psychic
  moves (`game-bible.md`; exact rules `TODO(design)`).
- Kaede is a shrine keeper; where her shrine is, is `TODO(design)`. Her first quest collects
  shrine tablet rubbings "around Eien" (one tablet per few maps).
- New maps are made by the user in Porymap.
- Engine: evolutions can check `IF_IN_MAP` (one map) or `IF_IN_MAPSEC` (a map section, e.g.
  all of Route 1), and a species can list several evolution entries.

## Decided

- **What counts (1a):** only real shrine maps, the grounds around a shrine. Not whole routes,
  not the mountain.
- **Route 1's shrine (2a):** its own small map entered from Route 1 (the user makes it in
  Porymap). It's a shrine area.
- **First chance (3c):** Shimotsuki gets a shrine (its own map), reachable right after gym 1,
  about when Eien Poochyena reaches Lv 18.
- **Teaching it (4a+c):** the journal's Poochyena research entry gets a note the first time it
  reaches 18 and doesn't evolve; a shrine tablet at the Route 1 shrine hints at the rule.
- **Built as (5a):** one evolution entry per shrine map (`IF_IN_MAP`), no engine change. Switch
  to a shared "shrine area" mark when a second system needs it.
- **Thin places (6b):** every shrine area is a thin place; the mountain is a thin place but not
  a shrine area.

- **Shimotsuki's shrine (r2 1a):** it's Kaede's shrine. That settles where her shrine is; her
  first quest starts there after gym 1.
- **Route 1 shrine map (r2 2b):** torii, komainu statues, the tablet, and a patch of grass where
  Eien Poochyena appears more often.
- **Tablets read early (r2 3a):** he can read the Route 1 tablet before Kaede's quest; it adds
  a lore page, and tablets already read count when her quest starts.
- **Journal note (r2 4b):** when he opens the journal with an Eien Poochyena of Lv 18+ in his
  party, its research entry gets the "it didn't evolve" note. Checked on open; no battle code
  changes.
- **Rare Candy (r2 5a):** counts, like any level-up (engine default).
- **Default:** the evolution entries are added once the two shrine maps exist; the first
  milestone ends below Lv 18, so it doesn't need them.

Promoted into `variants.md` ("Shrine areas" and Eien Poochyena), the Route 1 and Shimotsuki
location docs, Kaede in `side-quests.md`, `characters.md` and `story-outline.md`.

## Leaning

_(none)_

## Open questions

- How many shrines the whole game has, and where (each new one is a new evolution entry).
- Wild Eien Mightyena: whether they appear, and where (shrines would be natural).
- The Route 1 shrine's encounter rate for Eien Poochyena, and the Shimotsuki shrine's layout.

## Gaps and tensions

- Two new maps for the user to make in Porymap: the Route 1 shrine and Kaede's shrine in
  Shimotsuki.
- Kaede is now met in Shimotsuki; her first quest's "Act 1 or 2" becomes just after gym 1,
  when the first milestone ends. Whether she appears in the first milestone is open.
- Evolution only checks where the player is when it levels up. A Poochyena that levels past
  18 elsewhere must level again at a shrine (or use a Rare Candy there).
- Fan knowledge: he knows Mightyena evolves at 18, so a Poochyena that doesn't evolve is a
  small surprise the game can use or must explain.

## Parked ideas

_(none yet)_

## Rejected

_(none yet)_
