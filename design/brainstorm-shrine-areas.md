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

_(none yet)_

## Leaning

_(none)_

## Open questions

Round 1 (asked):
1. What counts as a shrine area.
2. Route 1's shrine: its own map or part of the route.
3. Where the first chance to evolve is, given it reaches Lv 18 after gym 1.
4. How the player learns the rule.
5. How it's built in the engine.
6. Shrine areas and thin places: the same set or not.

## Gaps and tensions

- The Route 1 shrine is the obvious shrine area but sits before gym 1, while Lv 18 comes
  after it; the first evolution may mean backtracking, or it happens at a later shrine.
- Evolution only checks where the player is when it levels up. A Poochyena that levels past
  18 elsewhere must level again at a shrine (or use a Rare Candy there).
- Fan knowledge: he knows Mightyena evolves at 18, so a Poochyena that doesn't evolve is a
  small surprise the game can use or must explain.
- How many shrines the game has, and where, isn't decided yet.

## Parked ideas

_(none yet)_

## Rejected

_(none yet)_
