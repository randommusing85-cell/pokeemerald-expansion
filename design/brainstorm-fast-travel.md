# Brainstorm: fast travel and field moves

Working notes. Decisions move into `progression.md`, `game-bible.md` (Mechanics) and the location
docs when settled; this file stays as the record.

## Givens (from the docs and the engine)

- **Fast travel** unlocks in Act 3 after the professor's death: Haru gives it ("a rail pass, or a
  Pokémon that can now Fly him", `progression.md`). Until then story scenes move him (the funeral
  to Shimotsuki; Haru's letter from Hoshimi to Hamakaze).
- **Field moves without HMs** (brainstorm-mechanics.md, quality of life): `TODO(design)` which key
  item or Pokémon does them. Tetsu's step 2 gives climbing gear: a field-move key item, "shortcut
  only, never a gate". The Town Map is its own key item (Haru's first quest reward). Fishing rods:
  Old Rod (Tomo), Good Rod (Isaribi's shop).
- **Obstacles so far:** none need a field move. Lake Usurai is crossed by Nami's Lapras in a scene;
  Route 3's cave is lit by the Survey; Shimotsuki's east exit to Route 5 is shut until Act 3
  (`TODO(design)`: what keeps it shut).
- **Engine:** `OW_FLAG_POKE_RIDER` (`include/config/overworld.h`): when its flag is set, he can fly
  from the Town Map key item by pressing R on a place he can fly to, with no Pokémon knowing Fly.
  `OW_ROCK_CLIMB_FIELD_MOVE` / `OW_DEFOG_FIELD_MOVE` exist (off). Field moves otherwise come from
  moves a party Pokémon knows (vanilla HMs); HM-free field moves would be our own (small) engine
  work.
- **Rules:** config switches before engine edits; engine edits small and isolated.

## Decided

## Leaning

## Open questions

## Gaps and tensions

## Parked ideas

## Rejected
