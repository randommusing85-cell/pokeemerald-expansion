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

## Leaning

_(none)_

## Open questions

Round 2 (asked):
1. What the Shimotsuki shrine is (whose, what's there).
2. What's on the Route 1 shrine map.
3. The Route 1 tablet before Kaede's quest exists.
4. When the journal note appears.
5. Whether a Rare Candy used at a shrine counts.

Default (not asked): the evolution is added once the shrine maps exist. The first milestone
ends at gym 1, below Lv 18, so it isn't needed for that milestone.

## Gaps and tensions

- The Route 1 shrine is the obvious shrine area but sits before gym 1, while Lv 18 comes
  after it; the first evolution may mean backtracking, or it happens at a later shrine.
- Shimotsuki's shrine is new content in a town whose doc has no landmarks yet; it could also
  answer where Kaede's shrine is.
- The Route 1 tablet comes before Kaede asks for rubbings.
- Evolution only checks where the player is when it levels up. A Poochyena that levels past
  18 elsewhere must level again at a shrine (or use a Rare Candy there).
- Fan knowledge: he knows Mightyena evolves at 18, so a Poochyena that doesn't evolve is a
  small surprise the game can use or must explain.
- How many shrines the game has, and where, isn't decided yet.

## Parked ideas

_(none yet)_

## Rejected

_(none yet)_
