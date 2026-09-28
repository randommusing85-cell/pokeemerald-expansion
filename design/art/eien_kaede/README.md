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

## Battle sprite drafts (proposals)

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
