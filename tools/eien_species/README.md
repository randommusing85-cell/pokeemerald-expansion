# Eien species tools

The Eien regional forms (design/variants.md) are defined in:

- `include/constants/species.h`: `SPECIES_TORCHIC_EIEN`, `SPECIES_BULBASAUR_EIEN`,
  `SPECIES_FROAKIE_EIEN`, `SPECIES_POOCHYENA_EIEN`, in the custom range (append only).
- `src/data/pokemon/species_info/eien_families.h`: their species entries (stats, types,
  abilities, dex text, graphics).
- `src/data/pokemon/species_info/eien_forms_data.h`: their level-up learnsets, palettes and
  the form tables (each original species points at its table).

The starters' sprites come from the chosen AI drafts; species without chosen art reuse the
original sprites with placeholder palettes:

  tools/eien_species/convert_art.py            # PICKS / BACK_PICKS: drafts -> graphics/pokemon/eien/<species>/
                                               # (front, back, palette, shiny)
  tools/eien_species/placeholder_palettes.py   # the rest: recolored original palettes
  tools/eien_species/make_icons.py             # icons, and the Eien icon palette (pal6.pal)

The Eien icon palette is a seventh icon palette: `graphics/pokemon/icon_palettes/pal6.pal`,
registered in `src/graphics.c` (`gMonIconPalettes`) and `src/pokemon_icon.c`
(`gMonIconPaletteTable`). Screens that load every icon palette now use one more sprite
palette; the PC storage screen gets `PALTAG_MON_ICON_6` so its own tags don't collide, and
now uses all 16 sprite palettes (checked in game: box, party panel, marking menu). A screen
that needs one more palette will have to load icon palettes on demand instead.

AI draft front sprites for review are in `design/art/eien_<species>/`
(`design/art/eien_starters_drafts.md`, `eien_starters_contact_sheet.png`).

To give one in game for a check: debug menu, Give X, Pokémon (Basic), species 1573-1576.
