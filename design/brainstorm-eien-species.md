# Brainstorm: the four Eien species (first milestone)

Running notes. Nothing is decided until it's under **Decided**; decisions move into
`variants.md` when the user agrees.

## Givens

- Eien Torchic (Fire/Ghost, a shrine-lantern bird), Eien Bulbasaur (Grass/Psychic, touched by
  the fading), Eien Froakie (Water/Ice, a snow ninja), Eien Poochyena (Rock/Dark, a stone
  komainu shrine dog; common on Route 1; beats the Ice gym).
- Starters beat each other in a cycle: Torchic > Bulbasaur > Froakie > Torchic.
- First evolution at about Lv 18; the first milestone only needs the first stages.
- Named like official regional forms ("Eien Poochyena"). Each needs front (2 frames), back,
  icon, normal + shiny palettes. Poochyena has a sprite test (`art/eien_poochyena/`).
- Fan knowledge: he knows Gen 1-5; Eien variants and Gen 6+ are "???".
- Pokémon art is Gen 4/5 style.

## Decided

- **Forms (1a):** regional forms of the existing species (like Alolan Rattata): same dex
  number, their own form entries.
- **Stats (1b):** the same total as the original, redistributed to fit the new typing.
- **Abilities (3b):** existing abilities that fit the theme; starters keep their pinch ability
  as the main one.
- **Evolutions (4d):** starters evolve by level (first at about Lv 18) and keep their Eien
  typing; other variants like Poochyena evolve by an Eien method (a shrine, an aurora night,
  a thin place). The engine has the conditions (`IF_IN_MAPSEC`, `IF_IN_MAP`, `IF_WEATHER`).
- **Eien Bulbasaur (5c):** a fading bloom: its bulb is partly translucent and glows faintly
  like the aurora, as if it's between worlds.
- **Froakie (6b):** the one starter he doesn't recognize. It's "???" from the start, a quiet
  first demonstration of fan knowledge. The game bible's "he recognizes them" becomes "he
  recognizes two of them".

- **Stats (r2 1a), abilities (r2 2a), early moves (r2 3a):** as proposed; see `variants.md`.
- **Eien Poochyena evolves (r2 4a)** by leveling up to 18+ in a shrine area.
- **Sprites (r2 5c):** placeholder sprites now (recolored originals), Gemini front drafts in
  parallel for review.

Promoted into `variants.md` and `game-bible.md`.

## Parked ideas (round 2)

- A signature move per starter for the final stages (custom engine work, later milestone).

## Gaps and tensions

- Sprites: back sprites and icons need hand work (sprite test findings).

## Parked ideas

_(none yet)_

## Rejected

_(none yet)_
