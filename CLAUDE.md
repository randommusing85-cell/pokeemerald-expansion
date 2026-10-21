# CLAUDE.md

## Active migration decision (2026-10-21)

The user has decided to port Eien to RPG Maker XP + Pokémon Essentials v21.1.
Read the active migration section in `design/development-handoff.md` first.
This repository now serves as the GBA implementation and design reference. The ROM-specific
instructions below apply only when maintaining that reference; they do not govern the new
Essentials project. Pause new GBA implementation unless the user requests it. Claude owns
engine-independent dialogue/story and the anime-style brainstorm; Codex owns the port.
Continue using Higgsfield for important movie cutscenes and in-engine scenes for ordinary beats.

This is a Pokémon ROM hack with a new region and an original story, built on
[pokeemerald-expansion](https://github.com/rh-hideout/pokeemerald-expansion) (a fork of it).
The engine is upstream's; the region, story, maps, characters and dialogue are ours.

## Design comes first

- Collaboration: Claude leads brainstorming and story design; Codex leads implementation,
  builds and validation. Read `design/development-handoff.md` at session start and update it
  at handoff with changes, checks, blockers and the next task. Cinematic proposals live in
  `design/cutscenes.md`; proposals are not settled story decisions.
- User direction (2026-10-21): use your brainstorm skill to develop the anime visual style
  for important movie cutscenes, and use Higgsfield to produce those cutscenes. Follow the
  brief in `design/cutscenes.md`. If the skill or Higgsfield is unavailable in your session,
  report that concrete blocker rather than claiming it ran. Codex owns engine integration.
- The design lives in `design/`. Read `design/README.md`, then the docs relevant to the task
  (the game bible, the location doc for the map you're touching, the story outline for scenes).
- Design lands in the docs **before** code. If a request adds or changes story, characters,
  locations or progression, update the doc in the same change, or ask if the doc says otherwise.
- If a request conflicts with the docs, point out the conflict and ask; don't silently pick one.
- Don't invent lore, names or plot points that aren't in the docs. Leave a clear `TODO(design):`
  and mention it instead.

## Build and check

- Build in WSL/Linux: `make -j$(nproc)` produces `pokeemerald.gba`. A build must pass before a
  change is done.
- `make check -j$(nproc)` runs the engine test suite. Run it after engine or battle changes.
- **Check visual changes by running the game.** After editing maps, events, scripts, dialogue,
  tilesets or sprites, use the screenshot skill (`.claude/skills/screenshot/SKILL.md`,
  harness in `tools/mgba_harness/`): warp to the map, screenshot the scene, read `_sheet.png`,
  and say what it shows. Don't report a scene as working from reading the script alone.

## Maps and scripts

- New maps are created in **Porymap** by the user; it writes `data/maps/<Map>/map.json`, the
  layout and the header entries. Don't hand-write new map JSON or layouts unless asked.
  Filling in a map's events, warps, connections and `scripts.inc` is normal work.
- Map scripts are in `data/maps/<Map>/scripts.inc`; shared scripts in `data/scripts/`.
- Story state uses named flags and vars. Take spare ones by renaming `FLAG_UNUSED_0x...`
  in `include/constants/flags.h` / `VAR_UNUSED_0x...` in `include/constants/vars.h` to a
  descriptive name (e.g. `FLAG_MET_RIVAL_IN_HOMETOWN`), and record new story flags in the
  location doc. Never repurpose a flag that vanilla scripts still use.
- Prefer `include/config/*.h` switches over editing engine code. Keep engine edits small and
  isolated so upstream updates still merge.

## Text and dialogue

- The game's text uses its own character set (`charmap.txt`). It has `…`, curly quotes
  (`“ ” ‘ ’`), `é`, `♂`/`♀`, but **no em or en dash**; use `-` or restructure the sentence.
  Characters not in the charmap break the build.
- Line breaks are manual: `\n` new line, `\l` scroll one line, `\p` new text box. Keep each
  line short enough to fit the box, and check long lines in a screenshot rather than
  guessing.
- Write dialogue in the voice described in `design/dialogue-style.md`: plain, short,
  in character. No overdramatic narration, speeches or "AI voice".

## Assets

- Community tilesets, sprites and music must be credited in `design/asset-credits.md` when
  they're added. GBA limits: a primary tileset has 512 tiles and 6 palettes, a secondary one
  512 tiles and 7 palettes, 16 colors per palette.

## Repository

- `docs/` is upstream's engine documentation; leave it alone. Our docs go in `design/`.
- To pull engine updates: `git remote add upstream https://github.com/rh-hideout/pokeemerald-expansion`
  (once), then `git fetch upstream` and merge `upstream/master`.
- Never commit ROMs, saves or save states (`*.gba`, `*.sav`, `*.ss*`).
