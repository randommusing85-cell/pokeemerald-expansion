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
  a note to himself: "My name is ___. I'm from ___. If I start forgetting, read this." Near
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
- Her husband runs the household. `TODO(design)`: his name.

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
| Yuki | Main friend, Act 3 | Tournament, then Act 3 | Girl from another town. Tournament rival, becomes a friend after Akira leaves. |
| Kaede | Smaller friend | `TODO(design)` | Young shrine keeper who knows the old tales of the cycle. |
| Tetsu | Smaller friend | Near the door mountain | Old mountain guide. |
| Ren | Smaller friend | `TODO(design)` | League trainer who quits after learning about the cover-up. |

## Gym leaders

| # | Town | Leader | Type | Personality | Ace | Level |
| --- | --- | --- | --- | --- | --- | --- |
| 1 | Shimotsuki | Fuyumi | Ice | Stern veteran in the gym, softer at home with Akira. Akira's mother; dies at the tournament. | Bergmite (with Spheal) | 13-14 |
| 2-8 | | `TODO(design)` | | | | |

## Champion

- **Seiji** (man). Ordered the League's cover-up of the cycle. When Minato's plan starts
  partway through the Elite Four, he admits it and fights beside the hero, Haru and Yuki.

## Factions / villains

### `TODO(design)`: faction name

- **Goal:** stop Arceus's cycle by drawing energy from other worlds (the hero's included)
  through Palkia's door, to sustain Arceus.
- **Look:** `TODO(design)`.
- **Leader:** **Minato** (man). Believes he can stop the cycle. Lives; the final villain.
- **Lieutenant:** **Hashimoto** (older man), Nami's mentor. Dies in the tournament disaster.
  `TODO(design)`: his relationship to Nami beyond mentor.
- **Members:** principled; don't see themselves as evil; never change their minds; lose
  gracefully.
- **Where they appear:** from Act 1; the tournament; the door mountain at the end.

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
| Nami | `OBJ_EVENT_GFX_EIEN_NAMI` |
| Professor Kashiwagi | `OBJ_EVENT_GFX_EIEN_KASHIWAGI` |
| Her husband | `OBJ_EVENT_GFX_EIEN_KASHIWAGI_HUSBAND` |
| Fuyumi | `OBJ_EVENT_GFX_EIEN_FUYUMI` |
| Celebi | `OBJ_EVENT_GFX_SPECIES(CELEBI)` (engine) |
| Hamakaze townsfolk | `OBJ_EVENT_GFX_EIEN_FISHERMAN`, `_SAILOR`, `_VILLAGE_WOMAN`, `_SCHOOLBOY` |
| Shimotsuki townsfolk | `OBJ_EVENT_GFX_EIEN_SNOW_TRAINER`, `_WORKER`, `_POKEFAN_M`, `_SOCIALITE` |
| Nurse, Mart clerk | the engine's Emerald sprites |
