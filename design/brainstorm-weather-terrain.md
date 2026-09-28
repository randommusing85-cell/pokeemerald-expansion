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

- **Thin place (1d):** not a terrain but its own permanent field effect, set at battle start:
  Ghost and Psychic moves do 30% more damage. It doesn't take the terrain slot, so normal
  terrains still work on top of it. One contained engine addition (a new starting status).
- **Where (2c):** every battle on a thin-place map, wild or trainer; the map's script sets it
  on entering. A short message at battle start ("The air feels thin here…", placeholder text).
- **Aurora in battle (3b):** the engine's "Rainbow" effect for both sides (moves' secondary
  effects twice as likely), shown as the aurora shimmering. No new engine code.
- **Aurora on the map (4a):** a tint: the map's colors shift to a cold night palette with a slow
  color pulse. Mostly palette work.
- **Defaults (not asked):** both apply together (a thin place on an aurora night, like Kaede's
  step 2). The thin-place effect is permanent for the battle and can't be removed. The journal
  explains each effect the first time he meets it (his fan knowledge doesn't cover them).
  Aurora nights are clear nights, so no snow then.

Promoted into `game-bible.md` (Mechanics, Eien weather and terrain).

## Leaning

_(none)_

## Open questions

- The exact battle-start messages (placeholder text above).
- The night palette and pulse (art pass on a real map).

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
