# Brainstorm: Route 1

Working notes for Route 1's open design (`locations/route-1.md`). Decisions move into the
location doc when they're settled; this file stays as the record.

## Givens (from the docs)

- Coast near Hamakaze, turning into snowy fields, then a small shrine before Shimotsuki.
- The shrine is its own small map: torii, komainu, a tablet, a patch of grass. It's a shrine
  area and a thin place (`IF_IN_MAP` evolution entry, `sThinPlaceMaps`).
- 3-4 trainers, Lv 5-8. Wild Pokémon Lv 2-5.
- Eien Poochyena (Rock/Dark) is common on the route (~20%), more common in the shrine grass.
  It's the route's answer to the Ice gym (Fuyumi: Spheal, Bergmite Lv 13-14).
- The tablet can be read before Kaede asks for rubbings; it adds a journal lore page and
  counts toward her tablet quest. Its text hints that the stone dogs grow at their post.
- Quests that touch the route: E1 `QUEST_RESEARCH_POOCHYENA` (see, battle, catch) and Haru
  step 1 `QUEST_HARU_MAP` (note the coast, the fields, the shrine).
- `STORY_ROUTE_1` is set the first time he steps onto the route.
- Placeholder maps are built by Claude (like Hamakaze) and can be redrawn in Porymap.

## Decided

(nothing yet)

## Leaning

## Open questions

- Round 1: route shape and direction, wild table, trainers, items, tablet text and storage,
  where the two quests are given.

## Gaps and tensions

- The Route 1 shrine is a shrine area, so an Eien Poochyena reaching Lv 18 there evolves.
  `variants.md` calls Kaede's shrine "the first chance", which holds only because nobody is
  Lv 18 on Route 1. Fine, but the tablet's hint then points at the right place.
- Catching Ice types on Route 1 doesn't help against the Ice gym; too many would undercut
  the "every starter can handle gym 1" goal.
- Wild battles in the shrine grass get the thin-place effect.
- Music for the route and the shrine (placeholder until decided).

## Parked ideas

## Rejected
