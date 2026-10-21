# Development handoff: Claude + Codex

## Active direction: port to RPG Maker XP + Pokémon Essentials

User decision, 2026-10-21: Eien is moving to RPG Maker XP with Pokémon Essentials v21.1. The user already owns RPG Maker XP. This decision supersedes the ROM implementation tasks below; those sections remain historical reference.

- Claude: continue Hamakaze dialogue, prologue text and engine-independent story design. Write scene triggers and outcomes without GBA text escapes. Use your brainstorm skill for the anime style and Higgsfield for movie cutscene production, as previously requested.
- Codex: own the Essentials setup, Ruby/event implementation and validation. Rebuild maps in RPG Maker XP; Porymap files and C/event scripts are references, not directly importable project files.
- Preserve the GBA repository and drafts #29/#31 as reference. No automatic merge, closure or deletion is part of this decision.
- First port milestone: fresh game → bedroom → Hamakaze → starter selection/battle, then save/load. Reimplement journal/follower systems incrementally. Prototype video playback, skipping and return to gameplay before producing a full cinematic.
- Keep ordinary story beats as traditional in-engine Pokémon scenes. Movies remain reserved for important scenes. Existing GBA delivery constraints in cutscenes.md are historical, not requirements for the new target.

### Setup status

Official tagged v21.1 scripts downloaded to Codex workspace at /workspace/pokemon-essentials-v21.1-source, commit ea7b5d56d2436591160983c4e641a2ceee2d875a. This is NOT a runnable Essentials project: the upstream GitHub repository excludes graphics, audio and runtime files. No Windows/RPG Maker playtest has run.

The full author-linked package and hotfix are verified below, but MediaFire download is blocked by this workspace's network proxy (HTTP 403). Obtain these on the user's Windows machine, extract the full package into a separate Eien project folder, and install the hotfix folder under Plugins. Keep a clean baseline copy before customization. Do not replace the package scripts with current upstream master.

- [Official release](https://www.eeveeexpo.com/essentials/)
- [Full v21.1 package](https://www.mediafire.com/file/7o3yjnuxniojmad/Pokemon_Essentials_v21.1_2023-07-30.zip/file)
- [Official v21.1 hotfix instructions](https://www.eeveeexpo.com/resources/1376/)
- [Hotfix download](https://www.mediafire.com/file/znhw2jk5judt3ga/v21.1_Hotfixes.zip/file)
- [Upstream README explaining omitted files](https://github.com/Maruno17/pokemon-essentials/blob/v21.1/README.md)

### Resource guide review

[User-supplied beginner guide](https://www.reddit.com/r/PokemonRMXP/comments/1s1lfp0/a_beginners_quick_start_resource_guide_for_rpg/) reviewed, along with the author release pages and selected linked resources.

| Resource | Use for Eien / review limits |
| --- | --- |
| [Thundaga](https://www.youtube.com/thundaga) | Setup and event/mapping tutorials; compare examples against v21.1. Videos not watched during this review. |
| [Route mapping tutorial](https://www.reddit.com/r/PokemonRMXP/comments/1ldtb5h/tutorial_mapping_routes_in_rpg_maker_xp_for/) | Candidate reference when blocking out Hamakaze/Route 1. Text page inspected; slideshow images not inspected. |
| [Graphics collection](https://docs.google.com/spreadsheets/d/1Wu-nl64WyZXKwz88CfKz4CalXolD9e0Y-I57mEEEc80/edit) | Index inspected. Select a consistent tileset family and record each creator's terms and credits; listing is not blanket permission. |
| [Eevee Expo](https://eeveeexpo.com/) and [PokeCommunity](https://www.pokecommunity.com/) | Engine support and candidate plugins. Check exact v21.1 compatibility before adoption. |
| [World builder](https://kewaydex.notion.site/Ultimate-Pok-mon-Game-World-Builder-11b438d594a280d7939cd2f6e4310be2) | Returned 404 in review; existing design docs remain our planning source. |
| [Custom Pokédex tool](https://littlerootdreams.com/custom_pokedex.html) | Timed out; functionality unverified. Existing species designs can be mapped into Essentials PBS data. |
| Type-chart spreadsheet, FrogMegadrive videos, Spriters Resource and sound collections | Listed by the guide; not individually evaluated. Defer until needed for a concrete implementation or asset task. |
| Pokémon Studio | Separate alternative ecosystem; do not mix its setup with this Essentials port. |

Next dependency: make the complete extracted package available in the development workspace, then verify an untouched project boots in RPG Maker XP before adding Eien content.

---

Updated 2026-10-21. Remote baseline verified: `cfed829a7b` (PR #27 merged).
Read this at session start; update it with actual outcomes and the next owner at handoff.

## Ownership and next tasks

| Owner | Next task | Completion evidence |
| --- | --- | --- |
| Claude | Dialogue pass: Hamakaze town, household and lab, one map per PR | Design text updated, build passes, screenshots of changed dialogue |
| Codex | Research-page detail scrolling | Current-master implementation, overflow/navigation checks and emulator screenshots |
| Claude | Use its brainstorm skill to develop the anime visual style, then Higgsfield for movie cutscenes | Style options/recommendation, style guide, first pilot storyboard and production brief; see `cutscenes.md` |
| Codex / Porymap | Bedroom delivered in draft #31; production layouts next | Map files, constants, event/entry positions |
| Claude | Settle accident text and the prologue-to-Hamakaze transition | Location/story docs with exact text and trigger/state requirements |
| Codex | Implement the settled prologue after its map/text exist | Fresh-save journey into Hamakaze, including correct initialization and follower state |

- Claude leads story, characters and dialogue; Codex leads implementation, tooling and validation.
- User retains creative direction. Do not invent lore or hand-write new maps without direction.
- Current playable milestone: prologue through gym 1 and Nami's meeting. Later design can
  progress without expanding that build milestone.
- Before editing, inspect the current branch/diff and coordinate ownership of specific files.
  Codex's journal task is separate from Claude's Hamakaze script/dialogue work.
- Coordinator agent `/root/development_coordinator` removes immediate tooling blockers and
  tracks owner, dependency and concrete next action. It runs on demand in the Codex chat;
  no recurring background monitor is scheduled.
- These files must be merged or checked out from their PR for another Claude workspace to
  read them. They are not an automatic message delivery mechanism.

## Latest delivery: prologue bedroom (draft PR #31)

- Map and screenshots: https://github.com/randommusing85-cell/pokeemerald-expansion/pull/31
- User authorized Codex map creation. The 9x8 bedroom is built in Porymap-compatible
  files using existing tiles; Porymap's GUI was not available or tested here.
- Entry (3,3), console event (3,1), sealed stairs, no inherited Hoenn interactions or
  Secret Base bookkeeping. Build and map harness passed; room/console screenshots included.
- The bedroom map dependency is addressed in this draft, not yet merged. Claude now needs
  to settle console/accident/Palkia dialogue and transition; Codex can then wire New Game.
- Read `design/locations/prologue-bedroom.md` on that branch for coordinates and the no-op
  scene hook. The playable prologue itself remains unfinished.

## Latest delivery: research scrolling (draft PR #29)

- Implementation and screenshots: https://github.com/randommusing85-cell/pokeemerald-expansion/pull/29
- Built against `cfed829a7b`. Hold A + Up/Down to scroll research details; titles stay fixed,
  locked tiers remain hidden, and selection/tab/reopen resets the scroll position.
- Fresh build and final rebuild passed. The research harness verified both bounds, eight
  wrapped Poochyena lines/max scroll two, locked entry, selection/tab/reopen resets and
  field return. Three inspected PNGs are included in that PR.
- The PR #28 arrival fixture also passed against the current-master ROM with the scrolling
  change. This supplements the older historical results below; no full suite was rerun.
- Both #28 (handoff) and #29 (scrolling) are drafts, not merged. Claude can start the Hamakaze
  dialogue pass independently; keep that separate from `src/eien_journal.c`.

## Current status

- PR #27 is merged. Its Pelipper learnset finding was fixed in `12d604c902`; do not repeat
  the earlier request to fix Soak/Hydro Pump.
- Claude's latest inventory supersedes the old local snapshot: species and design work
  have advanced substantially. Consult current `whats-left.md`, `variants.md` and location
  docs; the early local claim that later starter forms/Hoothoot/Wooper were unbuilt is stale.
- Hamakaze, Route 1, Shimotsuki and Yunotaki exist on placeholder layouts. The prologue
  bedroom and later connecting maps remain dependencies. Lake Usurai uses `MAP_EIEN_ROUTE2`;
  that does not mean the later Route 2 mountain-pass maps exist.
- Existing dialogue remains draft. Start Claude's pass with Hamakaze, then move map by map.
- No Higgsfield movie assets or in-ROM movie player have been implemented. Higgsfield is
  the user's chosen production tool; the anime style and GBA delivery format still need
  a pilot. Do not equate a movie export with a playable ROM cutscene.

## Completed by Codex before this handoff

These checks ran on local commit `3a43be1713`, **not** the newer `cfed829a7b` baseline.
The notes and fixture are now prepared against current master; old results are historical.

- Added `tests/screens/eien_arrival.txt` and its README so the arrival check can travel
  with the repository rather than remain a throwaway local script.
- Build passed. Arrival harness passed at 14,670 emulated frames: story reaches
  `STORY_ARRIVED` then `STORY_TAKEN_IN`; journal receipt and cover flags set; Celebi's
  follower active state and hint script survive the checked transitions.
- Inspected the eight-shot sheet: arrival and household dialogue, Celebi, JOURNAL in the
  menu, first journal page, and the return visits. Subsequent debug warps succeed, checking
  return of input. No gameplay bug found in that bounded check.
- Journal closing returns to the Start menu; the fixture closes that before travel.
- Restored local emulator tooling by installing Debian `libmgba-dev` and `libmgba0.10t64`
  0.10.5+dfsg-1 in `/workspace/toolchains/root`. Updated that workspace's activation and
  install scripts. Those files are not repository content; other environments need the
  dependencies in `tools/mgba_harness/README.md`.
- Historical engine suite on October 20: 5,423 passed, 16 known-failing, 421 TODO,
  9 expected-failing. PR #27 separately reports 5,449 passes; that is Claude's report,
  not a fresh Codex run.

## Reproduce and limits

```sh
# Managed Codex workspace only; use your usual toolchain elsewhere.
source /workspace/toolchains/activate.sh
make -j$(nproc)
python3 tools/mgba_harness/run.py tests/screens/eien_arrival.txt
```

Inspect `build/harness/eien_arrival/_sheet.png`. The fixture's README documents save-layout
assumptions, including exact offsets; check them when configuration changes. This test uses
fresh-save initialization plus debug warps, not a continuous milestone playthrough. It does
not cover the prologue, starter battle, early whiteout or battery-save/reload yet.

Full milestone completion requires prologue → Hamakaze → starter/rival → Route 1 → gym 1
→ Nami, with progression gates, journal, follower, whiteout and save/reload verified.
At each handoff record changed files, commands/results, screenshots, remaining limits,
blockers and the next owner. Distinguish designed, implemented, built and playtested.
