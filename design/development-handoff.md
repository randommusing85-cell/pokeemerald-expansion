# Development handoff: Claude + Codex

Updated 2026-10-21. Remote baseline verified: `cfed829a7b` (PR #27 merged).
Read this at session start; update it with actual outcomes and the next owner at handoff.

## Ownership and next tasks

| Owner | Next task | Completion evidence |
| --- | --- | --- |
| Claude | Dialogue pass: Hamakaze town, household and lab, one map per PR | Design text updated, build passes, screenshots of changed dialogue |
| Codex | Research-page detail scrolling | Current-master implementation, overflow/navigation checks and emulator screenshots |
| Claude | Use its brainstorm skill to develop the anime visual style, then Higgsfield for movie cutscenes | Style options/recommendation, style guide, first pilot storyboard and production brief; see `cutscenes.md` |
| User / Porymap | Prologue bedroom and production layouts | Map files, constants, event/entry positions |
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
