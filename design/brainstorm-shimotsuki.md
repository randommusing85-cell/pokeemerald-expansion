# Brainstorm: Shimotsuki

Working notes for Shimotsuki's open design (`locations/shimotsuki.md`). Decisions move into
the location doc when settled; this file stays as the record.

## Givens (from the docs)

- A snowy inland town ("frost month"), north of Route 1. Tileset `gTileset_EienTown` (houses,
  Pokémon Center, Mart, Gym). Maps: town, gym, Pokémon Center, Mart, Kaede's shrine (its own
  small map, a shrine area and thin place).
- Akira shows him his mother's gym (`STORY_SHIMOTSUKI`). Gym 1: Fuyumi (Ice), a stern veteran
  in the gym and softer at home with Akira. Beating her sets `STORY_BADGE_1`.
- Gym trainers Lv 9-11. Fuyumi: Spheal and Bergmite (ace), Lv 13-14; a small, bulky team.
  Each of her Pokémon carries one move for the Ice-resistant starters (Eien Torchic is
  Fire/Ghost, Eien Froakie is Water/Ice).
- Kaede's cameo at her shrine in the first milestone: sweeping, one blunt line.
- Just past town, Nami helps him when he's lost or Celebi is struggling (`STORY_MET_NAMI`).
  The end of the first milestone.
- Akira step 1 (`QUEST_AKIRA_PRACTICE`): a practice battle at the edge of town after gym 1,
  then he talks about the League.
- Placeholder maps are built by Claude; the gym's trainers reuse vanilla Hoenn trainer slots.

## Decided

- **Akira's scene (r1 1a):** he waits at the town's south entrance, walks him to the gym
  door and points out the Pokémon Center on the way. The gym is shut until then
  (`STORY_SHIMOTSUKI`).
- **Gym layout (r1 2b):** a simple vanilla gym layout reused for now, Ice theme in the text;
  no puzzle. A real ice puzzle can come with the Porymap redraw.
- **Gym trainers (r1 3a):** two (Lv 9 and 10), plus a gym guide NPC who explains Ice and points
  at Route 1's Poochyena.
- **Fuyumi's moves (r1 4a):** Spheal: Water Gun, Powder Snow, Defense Curl, Rollout. Bergmite:
  Rock Tomb, Powder Snow, Curse, Harden. Water Gun covers Torchic, Rock Tomb covers Torchic and
  Froakie; Poochyena resists Rock Tomb.
- **Kaede's cameo (r1 5c):** "If you're here to pray, the box is on the left. If not, you're
  in the way."
- **Nami's meeting (r1 6b):** past town, Celebi suddenly fades and drops at a frozen lake's
  edge; Nami's Lapras carries them across to shelter. The fading's first appearance, not
  explained.

## Leaning

## Open questions

- Round 2: where the lake is, Nami's scene beats, gym trainers' teams, the badge reward,
  Akira's practice battle, the town's NPCs and music.

## Gaps and tensions

- A Fighting move on Fuyumi (e.g. Rock Smash for Eien Froakie) does 4x to Eien Poochyena
  (Rock/Dark), the route's intended answer to her. Rock Tomb is resisted by Poochyena.
- Bulbasaur (Grass/Psychic) is weak to Ice: its player leans on Poochyena or Machop.
- Nami's meeting needs a map past town; "past Shimotsuki" has no location yet.
- Kaede's shrine reuses the shrine tileset; the town uses the town tileset, so the shrine is
  reached by a warp (like Route 1's).
- Only 2 spare trainer slots: everything past that reuses vanilla Hoenn slots.

## Parked ideas

## Rejected
