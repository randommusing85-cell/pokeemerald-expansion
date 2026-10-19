# Characters

Names follow Japanese naming. Most names and genders beyond the core cast were proposed by
Claude at the user's request; change freely.

## Player

- A guy from our world and a Pokémon fan. Name chosen by the player; fixed male (Emerald's
  boy/girl choice is removed, the naming screen stays).
- Playing a Pokémon game when an accident nearly kills him. Palkia catches him at the edge
  of death; his body lies in a coma in our world for the whole game.
- **Voice:** mostly silent; speaks in big scenes. Inner thoughts show his game knowledge
  ("in the games, this is where..."), which is sometimes wrong: this world is real.
- **Journal:** a key item where he records what he knows and what happens. Its first page is
  a note to himself: "My name is ___. I'm from another world. If I start forgetting, read this." Near
  the end its pages go blank as his memories are paid away; in the epilogue they fill back in.
  Also holds his research on unknown Pokémon and his missions (game bible, Mechanics).
- **Game knowledge:** he knows Gen 1-5 Pokémon; Eien variants and later species are new to him.
- **Ending:** helps Arceus's cycle finish safely, paying with his memories of Eien. Wakes in
  a hospital at home.

## Rival

- **Name:** Akira (boy).
- **Personality:** a cheerful local kid who looks up to the League.
- **Arc:** his mother Fuyumi (gym 1) dies in the tournament disaster. The League plays her
  death down, and a few towns later Akira decides the "good" side can't protect anyone and
  joins Minato openly. He fights against the hero at the end.
- **Team:** takes the starter strong against the player's (see [variants.md](variants.md)).
- **Battles:** first battle at Kashiwagi's lab right after picking starters. Meets the player
  again in Shimotsuki and shows him his mother's gym. `TODO(design)`: later battles.
- **Relationship points and chain:** before he leaves, training battles and helping around
  Shimotsuki (ends with Fuyumi's death); after, optional meetings on the other side where he
  explains himself. His points change his last scene and his epilogue flash, not his choice.

## Professor

- **Professor Kashiwagi** (woman). Researches the cycle. Her family takes the hero in.
- Dies in Act 3 in a lab disaster, leaving the research that explains the cycle.
- Her husband, **Makoto** (誠, "sincerity"), runs the household.

## Love interest

- **Nami** (girl). Signature Pokémon: **Lapras**.
- Helps him when he's lost or Celebi is struggling, just after gym 1 (the end of the first
  milestone); they battle later.
- A committed believer in Minato's cause. He learns she's with them at the tournament.
  She knows Minato's plan drains the hero's world and honestly chooses her world over his.
  She never changes her mind; they choose each other anyway.
- **Relationship points** add optional warm scenes (the coast, Lapras) and change her lines;
  the core romance scenes always play.
- Her mentor Hashimoto dies in the tournament disaster.

## Friends

They have their own battles and lives; they don't follow him around. They fight beside him
in scripted tag battles and turn up at big moments. All survive, and he says goodbye to
each on-screen before he goes home. Keep these friendships clearly friendships.

Each has relationship points and a quest chain ([side-quests.md](side-quests.md)). Yuki and
Ren get earlier cameos so their chains have room: Yuki is met once or twice in Act 1, Ren
is a League trainer at a gym. At the door mountain Kaede always comes to help; with enough
points, Tetsu and Ren come too.

| Name | Role | Where | Notes |
| --- | --- | --- | --- |
| Haru Kashiwagi | Main friend, Act 1 | Hamakaze | Boy, the professor's son, about the hero's age. Takes the third starter. Shares the grief when his mother dies. |
| Yuki | Main friend, Act 3 | Route 3 cameo, tournament, then Act 3 | Girl from another town. Tournament rival, becomes a friend after Akira leaves. See below. |
| Kaede | Smaller friend | Her shrine in Shimotsuki | Young shrine keeper who knows the old tales of the cycle. |
| Tetsu | Smaller friend | Near the door mountain | Old mountain guide. |
| Ren | Smaller friend | `TODO(design)` | League trainer who quits after learning about the cover-up. |

### Kaede

- A teen shrine keeper, about his age. Red hakama with a heavy winter coat over it and snow
  boots.
- **Voice:** blunt and practical. Tired of being young and in charge, no patience for
  ceremony, but she does everything properly.
- **Role:** she keeps the folk version of the old tales and doesn't know they're true. He sees
  the truth behind them, sometimes before she does. She notices he's not from here, says so
  once, and doesn't pry.
- **Her shrine** is in Shimotsuki. Her elderly grandmother still lives there but can't do the
  work: small talk about the old days, repeats the evolution rule, gives the charm item at the
  end of her quest chain. Her name is **Chiyo** (千代, "a thousand generations").
- **Ties:** none close to Fuyumi or Akira; they're neighbors.
- **Team:** Eien Mightyena (the shrine's guardian, the player's first look at what Eien
  Poochyena becomes), Froslass (a snow spirit) and Mismagius (both of its move types get the
  thin-place boost). One joins per quest step: Mightyena is there at the first meeting,
  Froslass on the aurora night (drawn by the aurora), Mismagius before the League.
- **Battles:** always beside him, never against him. On the aurora night (quest step 2), a
  wild double battle beside him against two stone dogs woken by the aurora (the engine's
  follower-NPC partner); then the finale: at the door mountain she and the hero fight two ordinary members
  of Minato's group in a tag battle with the thin-place effect, with those three Pokémon. It's
  the same battle whatever her points; they change only her lines. Afterwards she follows
  him up and sees the cycle end: the tale she has always told happens in front of her.
  Her back sprite for these tag battles is in (`TRAINER_PIC_EIEN_KAEDE`). The follower-NPC
  partner is switched on (`include/config/follower_npc.h`): a follower set with a battle
  partner joins every wild battle as a double against two wild Pokémon; Celebi, set without
  one, never does. Still needed: her `PARTNER_` entry in `src/data/battle_partners.party`
  (levels `TODO(design)`), and her scene has to take Celebi's follower slot for the night
  (one walking follower at a time) and give it back after.
- **First meeting** (second milestone): she's reading her shrine's tablet, asks if he read the
  one on Route 1, sees his Poochyena and says the stone dogs grow at their post. In the first
  milestone she only has a cameo, sweeping at the shrine.
- `TODO(design)`: whether the League cares about her tales; her letters; her finale lines.
  Decided in [brainstorm-kaede-finale.md](brainstorm-kaede-finale.md) and
  [brainstorm-kaede-aurora.md](brainstorm-kaede-aurora.md).
  Decided in [brainstorm-kaede.md](brainstorm-kaede.md).

### Yuki

Decided in [brainstorm-yuki.md](brainstorm-yuki.md).

- **Name:** Yuki (幸, "happiness, good fortune"): a warm counterweight to the disasters, and
  quietly ironic beside her Absol.
- **Why she competes:** for her hometown, a small struggling place; a tournament win would
  bring it money and attention. No sponsor (against KAITO's League money on Route 3). Act 3's
  disaster hits what she's fighting for.
- **Hometown:** `TODO(design)`, placed with Act 3's maps; leaning a small farming village
  (rice terraces, one festival a year).
- **Voice:** cheerful and teasing; ribs him, laughs off a loss, serious in battle.
- **Look:** a farm girl on the road: a straw hat on her back, a work jacket, walking boots, a
  cloth bag, and a festival cord in her hair from her town's one festival. The cord is her
  keepsake.
- **Team:** mixed, with one clear ace she's had since she was small: **Absol**, the disaster
  Pokémon (in the games it appears before calamities). `TODO(design)`: the rest of her team
  for the tournament and Act 3.
- **In Act 1:** the Route 3 bridge (Absol alone, Lv 22; [route-3.md](locations/route-3.md)), then
  a heal-and-chat at Hanashiro's Pokémon Center (gym 4), teasing him about the bridge, no battle.
- **Sprites:** `TODO`: AI drafts like Ibuki's (an overworld recolor, a battle pic).

## Gym leaders

| # | Town | Leader | Type | Personality | Ace | Level |
| --- | --- | --- | --- | --- | --- | --- |
| 1 | Shimotsuki | Fuyumi | Ice | Stern veteran in the gym, softer at home with Akira. Akira's mother; dies at the tournament. | Bergmite (with Spheal) | 13-14 |
| 2 | Yunotaki | Ibuki (man, 40s) | Fighting | Lean, grey-streaked hair tied back, a scar across one eyebrow; an off-white training gi, a rope belt, prayer beads and faded red wrist tape from his League days. A former League fighter who walked away after a season that ended badly and won't say why. Trains under the hot waterfalls, like Tohoku's mountain ascetics. Quietly sceptical of the League (a seed for the cover-up, not spelled out). | Medicham (with Throh, Sawk) | 19-21 |
| 3 | Isaribi | Akari (woman) | Electric | Runs the squid-boat fleet; her Electric Pokémon light its lamps. Practical, loud, well loved: the first leader with a big, warm personality. ([locations/isaribi.md](locations/isaribi.md)) | Lanturn (with Magneton, Luxio) | 24-27 |
| 4 | Hanashiro | Mamoru (man) | Grass | The castle's head gardener: keeps the cherry trees and moss gardens; quiet and exact; watches the trees for the fading. Survives the tournament disaster, shaken; turns up once in Act 3. ([locations/hanashiro.md](locations/hanashiro.md)) | Appletun (with Cherrim, Dipplin) | 29-32 |
| 5-8 | | `TODO(design)` | | | | |

## Champion

- **Seiji** (man). Ordered the League's cover-up of the cycle. When Minato's plan starts
  partway through the Elite Four, he admits it and fights beside the hero, Haru and Yuki.

## Factions / villains

### The Eien Survey (true name: Tokoyo)

- **Name:** in Act 1 they go by **the Eien Survey**, a public name that fits the field
  researchers they look like. Their true name, **Tokoyo** (常世, the eternal land of Japanese
  myth), comes out at the tournament.

- **Goal:** stop Arceus's cycle by drawing energy from other worlds (the hero's included)
  through Palkia's door, to sustain Arceus.
- **Look:** `TODO(design)`. Placeholder: field gear (headlamps, measuring poles, notebooks); they
  look like researchers, which is why nobody finds them suspicious.
- **Leader:** **Minato** (man). Believes he can stop the cycle. Lives; the final villain.
- **Lieutenant:** **Hashimoto** (older man), Nami's mentor. Dies in the tournament disaster.
  `TODO(design)`: his relationship to Nami beyond mentor.
- **Members:** principled; don't see themselves as evil; never change their minds; lose
  gracefully.
- **Where they appear:** from Act 1 (first on Route 2's mountain pass, helping at a thinning
  patch); the tournament; the door mountain at the end.
- **Hinata** (陽向, "sunny place"), a young woman: the first member he meets, on the pass. Loves
  Pokémon, fascinated by Celebi, warm and open. Returns at the tournament, clearly on the
  other side.
- **The member on Route 4** (`TODO(design)`: name): asks about Celebi a little too closely at
  the orchard thinning; seen again at the tournament, near where the villains move; the one who
  reports Celebi to Minato.

## Pokémon characters

- **Celebi:** finds the hero when he arrives and follows him on the map (not in the party).
  Shows him glimpses of what's coming and gives hints when he talks to it.
  Came from a future where the world ended; can't jump again or fight. Dies in the final act
  protecting him from Minato's plan.
- **Palkia:** the door. Brought him here; sends him home.

## Overworld sprites

Gen 3 style, from the FRLG-style NPC megapack, converted by `tools/eien_npcs/` (credits in
`asset-credits.md`).

| Character | Sprite |
| --- | --- |
| Player | Brendan's sprites recolored (`tools/eien_hero/`): short messy dark hair with a side fringe, grey hoodie, blue jeans. An ordinary guy from our world. Every sprite (overworld sheets and battle) has the new hairstyle |
| Haru | `OBJ_EVENT_GFX_EIEN_HARU` |
| Akira | `OBJ_EVENT_GFX_EIEN_AKIRA` |
| Akira (battle) | `TRAINER_PIC_EIEN_AKIRA`: an AI draft, pointing with a grin (`design/art/eien_akira/`) |
| Nami | `OBJ_EVENT_GFX_EIEN_NAMI` |
| Professor Kashiwagi | `OBJ_EVENT_GFX_EIEN_KASHIWAGI` |
| Her husband, Makoto | `OBJ_EVENT_GFX_EIEN_KASHIWAGI_HUSBAND` |
| Fuyumi | `OBJ_EVENT_GFX_EIEN_FUYUMI` |
| Fuyumi (battle) | `TRAINER_PIC_EIEN_FUYUMI`: an AI draft, a Poké Ball held out, red winter coat (`design/art/eien_fuyumi/`) |
| Kaede | `OBJ_EVENT_GFX_EIEN_KAEDE`: a recolor (dark hair, white ribbon, navy winter coat, red hakama, brown boots) |
| Kaede (battle) | `TRAINER_PIC_EIEN_KAEDE`: AI drafts, arms crossed (front) and a 4-frame throw from behind (back, for tag battles) (`design/art/eien_kaede/`) |
| Chiyo, Kaede's grandmother (battle) | `TRAINER_PIC_EIEN_KAEDE_GRANDMOTHER`: an AI draft with a walking stick; ready if she ever battles (the design doesn't give her a battle yet) |
| Chiyo, Kaede's grandmother | `OBJ_EVENT_GFX_EIEN_KAEDE_GRANDMOTHER`: the HGSS Medium in shrine colors (white robe, purple hakama) |
| Ibuki | `OBJ_EVENT_GFX_EIEN_IBUKI`: the RSE Black Belt recolored ([brainstorm-ibuki-sprites.md](brainstorm-ibuki-sprites.md)): the headband turned to tied-back hair, dark with grey; off-white gi, dark brown belt, faded red wrist tape. The same sprite under the falls (`design/art/eien_ibuki/`) |
| Ibuki (battle) | `TRAINER_PIC_EIEN_IBUKI`: an AI draft, a fighting stance with one open palm forward, hair in a topknot, prayer beads, red wrist tape (Brawly and Fuyumi's pic as references) |
| Pilgrims (male, female) | `OBJ_EVENT_GFX_EIEN_PILGRIM_M` (the RSE Ruin Maniac recolored) and `_PILGRIM_F` (the HGSS Picnicker recolored): white travel clothes, a wide straw hat, a cloth pack (no staff on the small sprites). The retired-pilgrim gym guide uses the male one. Battle: `TRAINER_PIC_EIEN_PILGRIM_M` (an AI draft: staff with a bell, fist raised); `TRAINER_PIC_EIEN_PILGRIM_F` (an AI draft: a Poké Ball out, the staff on her shoulder) |
| Celebi | `OBJ_EVENT_GFX_SPECIES(CELEBI)` (engine) |
| Hamakaze townsfolk | `OBJ_EVENT_GFX_EIEN_FISHERMAN`, `_SAILOR`, `_VILLAGE_WOMAN`, `_SCHOOLBOY` |
| Shimotsuki townsfolk | `OBJ_EVENT_GFX_EIEN_SNOW_TRAINER`, `_WORKER`, `_POKEFAN_M`, `_SOCIALITE` |
| Nurse, Mart clerk | the engine's Emerald sprites |
