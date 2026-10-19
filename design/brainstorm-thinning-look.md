# Brainstorm: how the thinning looks on the GBA

Working notes. Decisions move into `game-bible.md` (Eien weather and terrain) and the location
docs that use it when settled; this file stays as the record.

## Givens (from the docs and the engine)

- **Where it's needed:** Route 2's patch (the first: the snow stops, colours drain, Celebi reacts,
  Pokémon flee; the grass around it is empty); Route 4's orchard (blossoms and withers in an
  hour); the tournament (Tokoyo's thinning under the castle, holding it back at the stands);
  Route 5's greyed patches (Act 3, lightly); Minori (the terraces go grey, the village's Pokémon
  walk in grey and come back in colour; the terraces stay grey for the year).
- **Act 3 rule:** "a few greyed tiles on routes" (brainstorm-act-3-gym-5.md r1 5c).
- **Engine precedent:** the aurora weather (`src/eien_aurora.c`, `WEATHER_AURORA`) re-blends the
  map palettes every few frames through a loop of tints. The engine has
  `TintPalette_GrayScale` / `_GrayScale2` (`include/palette.h`) and vanilla coord-event weather
  (weather changing as you step on tiles). Celebi's flicker exists as a movement script
  (`EienRoute2_Movement_Flicker`, Lake Usurai).
- **GBA limits:** palette effects work per palette (16 colours), not per area: greying one patch
  without greying the whole screen needs the patch's tiles on their own palette, or grey copies of
  the metatiles. A secondary tileset has 7 palettes and 512 tiles.
- **Thin places** (shrines, the mountain) have a battle effect (Ghost/Psychic +30%); a thinning
  isn't a thin place yet.
- **Rules:** engine edits small and isolated; config switches preferred.

## Decided

- **Technique (r1 1c):** while a thinning is open (Route 2's patch, the tournament, Minori's
  night), a screen-wide drain toward grey, a "thinning" effect built like the aurora (re-blending
  the palettes); what's left behind (Route 5's patches, Minori's terraces, Route 4's orchard) is
  grey copies of the tiles, swapped in with map scripts.
- **Motion (r1 2d):** it creeps in over a few seconds when the scene begins, then pulses faintly
  between grey and a trace of colour while it's open.
- **Weather and sound (r1 3d):** the snow stops (the weather goes off inside), the music fades to
  silence, and one vanilla sound effect (a low rumble) marks it opening.
- **Who stays in colour (r1 4c):** everything on screen drains, objects included, except the
  hero, Yuki and Celebi (their sprite palettes are left out of the blend).
- **Battles (r1 5c):** the thin-place battle effect applies (Ghost and Psychic +30%) and the
  battle background is tinted grey.
- **Afterwards (r1 6b):** grey tiles stay until the epilogue, when Arceus renews and the colour
  comes back (with the journal refilling).

## Leaning

## Defaults (not asked; change any)

- **Build shape:** a `WEATHER_THINNING`-like effect next to the aurora's (`src/eien_thinning.c`),
  started and stopped by script special, with a palette mask so the hero's, Celebi's and a
  partner's sprite palettes are left alone. Kept small and isolated.
- **Sound:** a vanilla rumble (e.g. the earthquake/thud effect; picked by ear at build).
- **Celebi:** the existing flicker movement plays as it opens, then Celebi waits at the edge.
- **Battle effect:** thinning scenes force it per battle with `setstartingstatus
  STARTING_STATUS_THIN_PLACE` (scenes aren't thin-place maps).
- **Grey battle background:** a grey tint on the battle's background palettes while the effect
  is on.
- **Prototype:** behind a debug script on a built map (Lake Usurai or Route 1), screenshotted in
  the harness, before any thinning map exists.
- **Palette budget:** checked per tileset when grey tile copies are made.

## Open questions

## Gaps and tensions

## Parked ideas

## Rejected
