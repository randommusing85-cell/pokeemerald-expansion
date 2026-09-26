# Eien species tools

The Eien regional forms (design/variants.md) are defined in:

- `include/constants/species.h`: `SPECIES_TORCHIC_EIEN`, `SPECIES_BULBASAUR_EIEN`,
  `SPECIES_FROAKIE_EIEN`, `SPECIES_POOCHYENA_EIEN`, in the custom range (append only).
- `src/data/pokemon/species_info/eien_families.h`: their species entries (stats, types,
  abilities, dex text, graphics).
- `src/data/pokemon/species_info/eien_forms_data.h`: their level-up learnsets, palettes and
  the form tables (each original species points at its table).

Until their own art exists, the forms reuse the original sprites with placeholder palettes:

  tools/eien_species/placeholder_palettes.py   # writes graphics/pokemon/eien/<species>/*.pal

AI draft front sprites for review are in `design/art/eien_<species>/`
(`design/art/eien_starters_drafts.md`, `eien_starters_contact_sheet.png`).

To give one in game for a check: debug menu, Give X, Pokémon (Basic), species 1573-1576.
