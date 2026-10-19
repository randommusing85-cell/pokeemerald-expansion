# Brainstorm: Ibuki's sprites

Working notes for gym 2 leader Ibuki's overworld sprite and battle picture. Decisions move into
`characters.md` and `locations/yunotaki.md` when settled; this file stays as the record.

## Givens (from the docs)

- Ibuki (伊吹, "breath"): a man in his 40s, a former League fighter who walked away after a
  season that ended badly and won't say why. Trains under the hot waterfalls of Yunotaki, like
  Tohoku's mountain ascetics (yamabushi). Quietly sceptical of the League. Fighting type; ace
  Medicham (with Throh and Sawk, "like his disciples"). The Misogi Badge (waterfall purification).
- Now: vanilla stand-ins (Black Belt overworld and battle pic). He appears twice in town: under
  the falls (before the badge) and in the gym.
- How past characters were made: overworld sprites from the FRLG-style NPC megapack
  (`tools/eien_npcs/convert.py`, shared palettes), sometimes recolored (Kaede's grandmother);
  battle pics as AI drafts (`tools/eien_npcs/trainer_pic_drafts.py`, Gemini, a vanilla trainer
  for style and the overworld sprite for colors), picked from a contact sheet, credited in
  `asset-credits.md`.
- The pilgrims (Route 2, gym 2, the gym guide) still use Black Belt / Battle Girl stand-ins.

## Decided

- **Look (r1 1c):** a mix of both lives: a plain white training gi with a rope belt, prayer
  beads, and old wrist tape from his League days.
- **Build and face (r1 2c):** lean, grey streaks in tied-back hair, with one old scar across the
  eyebrow (a hint at the bad season, never explained).
- **Battle pose (r1 3b):** a fighting stance with one open palm forward: composed, Medicham-like
  (the "breath" theme).
- **Overworld source (r1 4b):** a megapack sheet recolored to his colors, like Kaede's
  grandmother, so he matches the rest of the cast.
- **Pilgrims too (r1 5a):** a shared pilgrim look in the same pass (white travel clothes, straw
  hat, staff): an overworld sprite plus male and female battle pics, matched to Ibuki's.
- **Under the falls (r1 6a):** the same sprite standing in the splash.
- **Ibuki's colors (r2 1a):** off-white gi, dark brown belt and prayer beads, faded red wrist
  tape, dark hair with grey. The red tape is his one color: the League past.
- **Pilgrims' look (r2 2b):** white travel clothes, a wide straw hat, a wooden staff with a
  small bell or ring, straw sandals, a cloth pack. Male and female differ in hair and build.
- **Pilgrim overworld sprites (r2 3b):** two, male and female, matching the two battle pics.
  The retired-pilgrim gym guide uses the male one.
- **Battle pic style reference (r2 4b):** Brawly (the vanilla Fighting leader) for Ibuki's
  framing and pose, with Fuyumi's picked pic as a second reference so the Eien leaders sit
  together; Black Belt for the male pilgrim, Battle Girl for the female.
- **Drafts (r2 5a):** as before: 2 models x 2 tries per picture, one contact sheet per
  character; the user picks.
- **Defaults (r2):** megapack sheets picked at build time from a contact sheet of candidates;
  Ibuki and the pilgrims share one NPC palette group if their colors allow; credits (the
  megapack artists, an AI-assisted note) in `asset-credits.md` when used.

## Leaning

## Open questions

Promoted into `characters.md`, `locations/yunotaki.md` and `whats-left.md`. Nothing open
from rounds 1-2. The picks happen at build time.

## Gaps and tensions

- Eien NPCs share 4 palettes (`OBJ_EVENT_PAL_TAG_EIEN_NPC_1..4`): Ibuki's and the pilgrims'
  whites may need to fit an existing group.
- The battle pic's style reference: Emerald's Black Belt or Brawly.

## Parked ideas

## Rejected
