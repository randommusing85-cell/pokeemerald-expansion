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

## Leaning

## Open questions

## Gaps and tensions

## Parked ideas

## Rejected
