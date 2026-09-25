# Design docs

The single source of truth for the game's world, story and progression. Code follows these
docs: when the design changes, the doc changes in the same commit.

| Doc | What it holds |
| --- | --- |
| [game-bible.md](game-bible.md) | The region, its themes and rules. Read this first. |
| [story-outline.md](story-outline.md) | The plot, beat by beat, and what the player learns when |
| [characters.md](characters.md) | Player, rival, professor, gym leaders, factions |
| [progression.md](progression.md) | Route order, badges, level curve, what gates what |
| [dialogue-style.md](dialogue-style.md) | How characters talk, with examples |
| [locations/](locations/) | One doc per town, route or dungeon (copy `_template.md`) |
| [asset-credits.md](asset-credits.md) | Every community asset used, with its author |

## Current milestone

**Vertical slice:** _[e.g. hometown → Route 1 → first town and gym → end of the opening arc]._
Everything outside this scope waits.

- [ ] _[milestone checklist item]_
- [ ] _[milestone checklist item]_

## Conventions

- Names in docs match the code: a location doc names its map (`MAP_...`) and every story flag
  or var it uses.
- Unknowns are written as `TODO(design): question` so they're easy to find (`grep -rF 'TODO(design)' design`).
- Keep docs short. Bullet points over prose; a doc nobody reads doesn't help.
