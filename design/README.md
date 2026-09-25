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

**Vertical slice: prologue through gym 1.** Everything outside this scope waits.

- [ ] Prologue in our world: the accident, Palkia (engine: remove the boy/girl choice, keep
      the naming screen)
- [ ] Hometown: he wakes in Eien, Celebi finds him and follows him
- [ ] Kashiwagi household: taken in, Haru, the journal key item
- [ ] Meet Akira
- [ ] Route 1
- [ ] First town and gym 1 (Fuyumi, Ice)
- [ ] Location docs for each map above (`locations/_template.md`)
- [ ] TODO(design): starters, hometown and first town names

## Conventions

- Names in docs match the code: a location doc names its map (`MAP_...`) and every story flag
  or var it uses.
- Unknowns are written as `TODO(design): question` so they're easy to find (`grep -rF 'TODO(design)' design`).
- Keep docs short. Bullet points over prose; a doc nobody reads doesn't help.
