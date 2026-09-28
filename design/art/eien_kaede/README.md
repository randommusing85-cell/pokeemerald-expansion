# Drafts: Kaede and her grandparent (overworld)

**Picked:** Kaede a (navy coat) and grandparent b (Medium in shrine colors), in the game as
`OBJ_EVENT_GFX_EIEN_KAEDE` and `OBJ_EVENT_GFX_EIEN_KAEDE_GRANDMOTHER`. `ingame_test.png` shows
both, each facing down, sideways and up, placed on Littleroot for the test only.
 Contact sheet:
[../eien_kaede_ow_contact_sheet.png](../eien_kaede_ow_contact_sheet.png) (each facing down,
left, right, up). Made by `tools/eien_npcs/kaede_drafts.py` as recolors of FRLG-style NPC
megapack sheets, like the other Eien NPCs. A picked draft goes through
`tools/eien_npcs/convert.py`, and its artists get credited in `asset-credits.md`.

## Kaede

The pack has no shrine keeper, so these start from `Anime NPC 07` (Kalarie; first frames by
Pokésho): tied-up hair and an open coat over a darker layer. Maroon hair becomes dark brown,
the layer under the coat becomes a red hakama, the hair band becomes a white ribbon, and the
shoes become brown boots. The base wears glasses; they're painted out as plain eyes.

- **a, navy coat:** a dark winter coat. The red hakama stands out most.
- **b, cream coat:** a light padded coat. Reads the most "shrine".
- **c, grey coat:** closest to the base's colors.

A recolor can't change the silhouette: the hakama only shows as a strip under the coat. For a
real hakama shape, the sheet would need an edit (by hand or an AI pass like the hero's hair).

## Grandparent

- **a, Medium** (HGSS `trainer_MEDIUM`; Delta231, Mimi, M.vit, Kimoras): an elderly woman in an
  orange robe, as it is.
- **b, Medium in shrine colors:** the same sheet with a white upper robe and a purple hakama,
  the color senior keepers wear.
- **c, Kurt** (HGSS `NPC_Kurt`): an elderly man in a green coat, as it is.

The docs leave the grandparent's gender open; picking a sprite settles it.

## Battle sprite drafts

**Picked:** `kaede_gemini3pro_c` (arms crossed), in the game as `TRAINER_PIC_EIEN_KAEDE`
(`graphics/trainers/front_pics/eien_kaede.png`). `battle_ingame.png` is a debug battle with the
debug opponent's picture swapped for the test only.

Contact sheet: [../eien_kaede_battle_contact_sheet.png](../eien_kaede_battle_contact_sheet.png).
A trainer front picture (64x64); a back picture is only needed if she joins tag battles
(`TODO(design)`). Gemini 3 Pro Image and 3.1 Flash Image got FRLG's Channeler (a shrine maiden)
for style, proportions and framing, and her overworld sprite for colors and design: navy
winter coat open over a white kimono top and red hakama, white ribbon, brown boots. Each draft
was sampled to 64x64 and cut to its own 15 colors (`battle_drafts/`, raw output in
`battle_drafts/raw/`). AI-assisted art, to be noted in `asset-credits.md` when one is used.

- **a, broom** (bamboo shrine broom, hand on hip): ties to her sweeping cameo. Flash a is the
  cleaner of the two.
- **b, throw** (Poké Ball throw): Pro b reads well and has the most energy; Flash b's coat
  flares into a white swoosh that looks odd.
- **c, arms crossed** (blunt, tired-but-capable): Pro c is the tallest and most in character;
  Flash c is plainer.

## Grandmother battle sprite drafts

**Picked:** `grandmother_gemini31flash_a` (walking stick), in the game as
`TRAINER_PIC_EIEN_KAEDE_GRANDMOTHER`. `grandmother_battle_ingame.png` is a debug battle with the
debug opponent's picture swapped for the test only.

Contact sheet: [../eien_kaede_grandmother_battle_contact_sheet.png](../eien_kaede_grandmother_battle_contact_sheet.png).
The design doesn't give her a battle yet (`characters.md`); these are ready if she gets one.
Made like Kaede's: Emerald's Expert F (an elderly woman in a white robe) for style and framing,
her overworld sprite for the design (white hair in a bun, white kimono top, purple hakama, a
grey shawl), sampled to 64x64 with their own palettes (`grandmother_battle_drafts/`, raw in
`grandmother_battle_drafts/raw/`). AI-assisted.

- **a, walking stick:** Flash a (hands on the stick, a Poké Ball at her feet) and Pro a (more
  stooped) are both clean. Flash a reads most like a trainer.
- **b, seiza:** Flash b is calm and tidy; Pro b's hair came out frizzy and greenish.
- **c, ofuda:** Flash c holds a clear paper charm; Pro c's hair and charm are smudgy.

## Back sprite drafts

**Picked:** `back_gemini3pro_b`, in the game as the back sprite of `TRAINER_PIC_EIEN_KAEDE`
(`graphics/trainers/back_pics/eien_kaede.png`, animation `sBackAnims_OldManPokedude`), with a
4-pixel speck removed from the last frame. Checked in the debug menu's tag battle with Steven's
partner picture swapped for the test only: `back_tag_battle_ingame.png`, `back_throw_ingame.png`.

Contact sheet: [../eien_kaede_back_contact_sheet.png](../eien_kaede_back_contact_sheet.png);
`back_drafts/*_anim.gif` play each strip. Needed for her tag battles (aurora night, finale).
A trainer back sprite is a 64x256 strip of four frames: standing, then three throw frames. It
shares the front sprite's palette, so the drafts are indexed with `eien_kaede.pal`.
Gemini got Steven's four back frames in a 2x2 grid (pose, size, framing) and her front sprite
(design), and drew the same grid; each cell was sampled to 64x64 (`back_drafts/`, raw in
`back_drafts/raw/`). AI-assisted.

The frame order (stand, wind-up, forward, follow-through) matches the engine's
`sBackAnims_OldManPokedude` animation (idle frame 0, throw 1-2-3-0), not the Hoenn one that
Steven's own sheet uses; the GIFs use that timing.

- **3 Pro b:** large and cropped at the bottom like the vanilla backs; bun, ribbon and coat
  read well; the clearest throw. One stray pixel next to the ball in frame 3 to clean up.
- **3.1 Flash b:** the same framing; a bigger ribbon, a softer throw.
- **3 Pro a, 3.1 Flash a:** smaller full-body figures (the red hakama shows), smaller than a
  back sprite should be, the same problem the Poochyena back test had.
