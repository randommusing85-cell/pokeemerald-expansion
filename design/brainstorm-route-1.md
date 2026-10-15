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

- **Shape (r1 1a):** north from Hamakaze in a straight line: the coast along one side, then
  the snowy fields. The shrine is a short side path near the Shimotsuki end: optional but
  easy to see.
- **Wild species (r1 2a+c+d):** Eien Poochyena, Starly, Bidoof, Wingull (the coast), Snover,
  Machop, Zigzagoon. Machop is a second answer to the Ice gym.
- **Day and night tables (r1 2d):** Eien Poochyena is rarer by day and common at night (the
  stone dogs stir after dark). Turns on `OW_TIME_OF_DAY_ENCOUNTERS`; maps without suffixed
  tables keep their one table, so vanilla data is unaffected.
- **Shrine grass (r1 3b):** Eien Poochyena about 50%, Shuppet 15-20%, the route's commons for
  the rest.
- **Trainers (r1 4c):** locals at their jobs: a Fisherman on the coast, a Hiker or Picnicker
  in the fields, a Lass visiting the shrine, a kid who says he'll beat Fuyumi. One of them
  uses an Eien Poochyena (counts as "battled" for the research). Generic trainer sprites.
- **Items (r1 5b):** Potion, Poké Ball, an Ice Heal near the shrine, a hidden X Defense.
- **Quests given in Hamakaze (r1 6a):** the professor asks for the Poochyena research and
  gives Poké Balls after Akira's battle; Haru stops him at the north exit and asks for the
  map notes.

## Leaning

## Open questions

- Round 2: exact day/night rates, the shrine's day/night split, trainer teams and who has
  the Poochyena, the tablet's text and storage, how Haru's three places are noted, music.

## Gaps and tensions

- The Route 1 shrine is a shrine area, so an Eien Poochyena reaching Lv 18 there evolves.
  `variants.md` calls Kaede's shrine "the first chance", which holds only because nobody is
  Lv 18 on Route 1. Fine, but the tablet's hint then points at the right place.
- Catching Ice types on Route 1 doesn't help against the Ice gym; too many would undercut
  the "every starter can handle gym 1" goal.
- Wild battles in the shrine grass get the thin-place effect.
- Music for the route and the shrine (placeholder until decided).
- Day/night vs gym fairness: someone who only plays in daylight must still find Eien
  Poochyena often enough.
- GBA land slots have fixed rates (20/20/10/10/10/10/5/5/4/4/1/1), so the picked percentages
  get fitted to the nearest slot sums.

## Parked ideas

## Rejected
