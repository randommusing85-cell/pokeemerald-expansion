# Brainstorm: first milestone (prologue through gym 1)

Working notes (see `.claude/skills/brainstorm/SKILL.md`). Firm decisions move into the
design docs: `README.md` milestone, `progression.md`, `characters.md`, `story-outline.md`,
and a location doc per map.

## Decided (from the story docs)

- Scope: prologue in our world → hometown (wakes in Eien, Celebi, Kashiwagi household,
  Haru, journal) → meet Akira → route 1 → first town and gym 1 (Fuyumi, Ice).
- Hero: player-named, fixed male; mostly silent; inner thoughts show his game knowledge.
- Celebi follows him on the map (not in the party) and can't battle.

## Proposed defaults (not asked; change if wrong)

- **Celebi follower** uses the engine's follower NPC system (`include/follower_npc.h`) with
  Celebi's existing overworld sprite. No engine changes needed.
- **Level curve:** route 1 wild Pokémon Lv 2-5; route trainers Lv 5-8; gym trainers Lv 9-11;
  Fuyumi's ace about Lv 13-14.
- **Palkia** has an overworld sprite in the engine already (`graphics/pokemon/palkia/`).

## Leaning

_(nothing yet)_

## Open questions

1. How the prologue in our world is shown.
2. How he gets his first Pokémon, and the starter types.
3. Fuyumi: personality, team, and how an Ice gym stays fair at gym 1.
4. What story beats the slice includes beyond the checklist, and what it ends on.
5. How the snow look is achieved for the slice.
6. Names for the hometown and the first town.

## Gaps and tensions

- **Ice as gym 1.** Grass starters are weak to Ice; Fire, Fighting, Rock and Steel beat it.
  The starter trio and route 1's wild Pokémon decide whether gym 1 is fair for every pick.
- **No snow tileset in the engine.** Vanilla Emerald and FRLG have no snowy overworld tiles
  (only ice cave floors). A snow-country look needs a community tileset (credited in
  `asset-credits.md`) or custom art.
- **Our-world prologue art.** A modern street or car scene needs tiles and sprites the engine
  doesn't have.
- **Celebi can't battle**, so he needs a battling Pokémon before the first trainer fight.

## Parked ideas

_(none yet)_

## Rejected

_(none yet)_
