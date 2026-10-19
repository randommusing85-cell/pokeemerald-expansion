# Drafts: Ibuki and the pilgrims

Designed in [../../brainstorm-ibuki-sprites.md](../../brainstorm-ibuki-sprites.md). Nothing is
picked yet; the game still uses vanilla stand-ins (Black Belt, Battle Girl).

## Overworld drafts

Contact sheet: [../eien_ibuki_ow_contact_sheet.png](../eien_ibuki_ow_contact_sheet.png) (each
draft's down, left and up frames at game size). Recolors of FRLG-style NPC megapack sheets by
`tools/eien_npcs/ibuki_drafts.py` (`ow_drafts/`, RPG Maker sheets like the pack's; a picked one
is converted by `tools/eien_npcs/convert.py`).

- **Ibuki** (RSE Black Belt, by Poffin_Case: the red headband becomes his tied-back hair, the gi
  off-white, the belt dark brown):
  - `ibuki_a_blackbelt`: dark hair with grey streaks.
  - `ibuki_b_blackbelt_tape`: the same, with faded red tape at the wrists.
  - `ibuki_c_blackbelt_grey`: greyer hair, with the tape.
  The base has the vanilla Black Belt's open gi (bare chest); prayer beads and the scar are too
  small for 16x24 and are left to the battle pic.
- **Male pilgrim** (straw hat, white clothes, cloth pack):
  - `pilgrim_m_a_hiker`: RSE Hiker (Poffin_Case); the hat's feather removed. Its big pack
    covers most of the white clothes.
  - `pilgrim_m_b_ruinmaniac`: RSE Ruin Maniac (Poffin_Case); a wide hat, white clothes and the
    pack on the back read most like a pilgrim. Neither base has a staff.
- **Female pilgrim:**
  - `pilgrim_f_a_picnicker`: HGSS Picnicker (Delta231, Mimi, M.vit, Kimoras); the cap as a straw
    hat, dark brown hair, white clothes.
  - `pilgrim_f_b_battlegirl`: DPPt Battle Girl; no hat, a hair bun, white clothes.

## Battle drafts

Made by `tools/eien_npcs/trainer_pic_drafts.py ibuki pilgrim_m pilgrim_f`: Gemini 3 Pro Image
(`gemini3pro`) and 3.1 Flash Image (`gemini31flash`), two tries each (a, b), each sampled to 64x64
and cut to its own 15 colors (`battle_drafts/` in each folder, raw output in `battle_drafts/raw/`).
AI-assisted art, to be credited in `asset-credits.md` when one is used.

- **Ibuki** ([contact sheet](../eien_ibuki_battle_contact_sheet.png); style references Brawly's
  pic and Fuyumi's, colors from `ibuki_b_blackbelt_tape`): all four have the open-palm stance,
  the off-white gi, the brown belt, the bead necklace and the red wrist tape.
  - `gemini3pro_a`: the biggest and most forceful; hair loose behind.
  - `gemini31flash_a`: clean and calm.
  - `gemini3pro_b`: hair in a topknot, the clearest "tied back".
  - `gemini31flash_b`: clean, closest to the leaders' scale.
- **Male pilgrim** ([contact sheet](../eien_pilgrim_m_battle_contact_sheet.png); style
  reference the Black Belt pic, colors from `pilgrim_m_b_ruinmaniac`):
  - `gemini3pro_a`: a staff with a bell, fist raised, conical straw hat: reads best.
  - `gemini3pro_b`: a Poké Ball out, the staff on his shoulder; a brown vest over the white.
  - `gemini31flash_a` and `_b`: white patches left beside the staff by the background cut;
    usable only after cleanup.
- **Female pilgrim** ([contact sheet](../eien_pilgrim_f_battle_contact_sheet.png); style
  reference the Battle Girl pic, colors from `pilgrim_f_a_picnicker`): the weakest set.
  - `gemini3pro_a`: unusable (it drew three views side by side).
  - `gemini31flash_a`: good pose and hat, but white patches by the staff.
  - `gemini3pro_b`: chunky but whole; a Poké Ball out, the staff across her back.
  - `gemini31flash_b`: good, but white patches by the staff.
  A second round (or a cleanup of `gemini31flash_a`) may be worth it.
