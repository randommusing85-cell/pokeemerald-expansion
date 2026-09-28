# Brainstorm: the aurora weather and thin-place terrain rules

Running notes. Nothing is decided until it's under **Decided**; decisions move into
`game-bible.md` (Mechanics) when the user agrees.

## Givens

- Game bible: "Snow on most routes, an aurora weather on clear nights, and a thin place
  terrain at shrines and the mountain that boosts Ghost and Psychic moves. Built on the
  engine's weather and terrain." The aurora's battle effect and the terrain's exact rules are
  `TODO(design)`.
- Every shrine area is a thin place; the mountain is a thin place but not a shrine area.
- Aurora nights: the first is story-set (Kaede's step 2); after that they come back at
  random. Wild Eien Mightyena appear only on aurora nights at thin places.
- Kaede's aurora-night battle (a thin place, on an aurora night) and her finale tag battle
  (the mountain) both use these rules. Her team is Ghost-heavy (Froslass, Mismagius).
- CLAUDE.md: prefer config switches; keep engine edits small and isolated.
- Engine: `setstartingstatus` (script command) makes the next battle start with a status,
  including permanent Psychic Terrain and "Rainbow" (the Pledge effect: secondary effects are
  twice as likely), for each side. Statuses reset on map load. Overworld snow gives Snow in
  battle (Gen 9 rules).

## Decided

_(none yet)_

## Leaning

_(none)_

## Open questions

Round 1 (asked):
1. How the thin-place terrain is built.
2. Which battles it applies to.
3. The aurora's battle effect.
4. How the aurora looks on the map.

## Gaps and tensions

- A truly new weather or terrain touches many engine files (messages, animations, AI, tests);
  reusing or lightly extending existing effects is cheaper and merges better with upstream.
- The mountain is where the finale happens: the terrain there helps Kaede's Ghosts, but also
  any Ghost or Psychic types Minato's side uses.
- The hero's fan knowledge doesn't cover Eien-only effects; the journal could explain them.

## Parked ideas

_(none yet)_

## Rejected

_(none yet)_
