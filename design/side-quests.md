# Side quests and relationship points

Decided in [brainstorm-quests-relationships.md](brainstorm-quests-relationships.md).

## Rules

- **Relationship points** with Nami, Haru, Yuki, Kaede, Tetsu, Ren and Akira. Earned through
  answers in story scenes (two or three answers, never an "evil" one) and each friend's
  quest chain. They change scenes, dialogue, finale helpers, gifts and the epilogue, never
  the outcome. Shown only as the journal's line per person, never as numbers.
- **What high points give:**
  - **Finale helpers:** at the door mountain Kaede always comes; with enough points Tetsu
    and Ren come too, each holding off part of Minato's forces in their own battle.
  - **Gifts:** the smaller friends (Kaede, Tetsu, Ren) give an item or TM tied to them; the
    main ones (Haru, Yuki, Nami, Akira) give a **keepsake** that does nothing in Eien but
    appears in the epilogue game and brings back that friend's memory.
  - **Epilogue:** which memories come back, and how much each friend's game NPC "remembers".
- **Nami:** the romance is fixed. Points add optional warm scenes and change her lines; the
  core scenes always play.
- **Akira** still defects. His points change his last scene, what he says at the end and
  his epilogue flash.
- **Quest kinds:** friend chains (the backbone), research (study Eien Pokémon), the fading's
  small disasters (help towns), lore (shrine tablets, folk tales).
- **Delivery:** chains are picked up at the friend's home; a letter in the journal says when
  someone wants to see him. Celebi's hints can point to them as a fallback.
- **Missable:** quests tied to people who die or leave close for good. The journal notes the
  unfinished thing, and the epilogue gives it back as a memory.
- **Rewards:** items, TMs, keepsakes, lore, money, battle items. Never Rare Candies or EXP.
- **Size:** about 25 at launch; the system is built to grow to 80+ (Unbound's scale).
- **Storage:** a quest table in the save file (a byte per quest: state and step; a byte of
  points per person; a bit per person for letters). No spare vars or flags used. See
  [Scripting](#scripting).
- **Missions tab:** title, one-line hint, state (open / done / closed) and who gave it;
  grouped by person, plus an "Eien" group. Filters once there are about 40 quests.

`TODO(design)`: point thresholds (what counts as "enough"); the letter trigger rule; which
friends get tag battles.

## Scripting

The table is `gSaveBlock1Ptr->eienQuests` (`src/eien_quests.c`), with room for 128 quests
and 16 people (148 bytes of SaveBlock1). Ids are in `include/constants/eien_quests.h`:
append new `QUEST_*` / `PERSON_*` at the end and never renumber them, since saves store them
by number. Every argument can be a number or a var.

| Command | Does |
| --- | --- |
| `setquest QUEST, QUEST_STATE_*` | Sets the state: `NONE` (hidden), `OPEN`, `DONE`, `CLOSED` (missed) |
| `checkquest QUEST` | `VAR_RESULT` = the state |
| `setqueststep QUEST, n` | Sets the step (0-63) the journal's log shows |
| `checkqueststep QUEST` | `VAR_RESULT` = the step |
| `addpoints PERSON, n` / `removepoints PERSON, n` | Changes relationship points (kept within 0-255) |
| `checkpoints PERSON` | `VAR_RESULT` = the points |
| `setletter PERSON, TRUE/FALSE` | Marks or clears a letter in the journal |
| `checkletter PERSON` | `VAR_RESULT` = TRUE if a letter is waiting |

Tests: `make check TESTS="(Eien quests)"` (`test/eien_quests.c`).

The journal's text for each quest (title, giver, hint, log lines, the line shown when it's
closed) and the relationship line per person live in `src/data/eien_journal.h`; the screen
is `src/eien_journal.c`. Research quests store their tiers as bits of the step (seen,
battled, caught, lore). The relationship thresholds there are placeholders until the design
sets them.

## Chains

Approved as drafted. Steps marked (M1) are in the first milestone. Places, items and lore
still open are `TODO(design)`.

### Haru (Act 1 to Act 3)

| # | When / where | What happens | Points from | Reward | Missable |
| --- | --- | --- | --- | --- | --- |
| 1 (M1) | Act 1, Hamakaze | Haru is drawing a map of Eien for the newcomer and asks him to note three places on Route 1 (the coast, the snowy fields, the shrine). Teaches the missions tab. | Finishing it; an answer about where he's "really" from | Town Map | No |
| 2 | Act 1, before the tournament | Haru feels behind his friends. A training battle, then a tag battle together against two trainers who've been bothering him. | The answer after the loss or win | Battle item | No |
| 3 | Act 3, Kashiwagi's lab, after the professor dies | Haru is sorting his mother's notes. Help him find her last field notes; they finish a research entry she started. | Staying to help; the answer about grief | **Keepsake:** Haru's map from step 1, finished | No |

The map bookends the chain: the first quest starts it, the last one gives it back.

### Akira (Act 1, then Act 3 to 4)

| # | When / where | What happens | Points from | Reward | Missable |
| --- | --- | --- | --- | --- | --- |
| 1 (M1) | Act 1, Shimotsuki, after gym 1 | A practice battle at the edge of town, then Akira talks about why he looks up to the League (sets up his turn). | The answer about the League | Battle item | Closes at the tournament |
| 2 | Act 1, before the tournament | Training together for the tournament; Fuyumi watches (overlaps her chain). | The answer when Akira doubts himself | none | Closes at the tournament |
| 3 | Act 3, after he leaves | Optional meeting on the other side. He explains why; no fight unless the player wants one. | The answer (agree he was failed / ask him to come back / just listen) | none | Closes at the League |
| 4 | Act 4, before the League | A second meeting. He gives something of his mother's. | The answer | **Keepsake:** `TODO(design)`: an object of Fuyumi's | Closes at the League |

### Fuyumi (Act 1 to the tournament; missable)

| # | When / where | What happens | Points from | Reward | Missable |
| --- | --- | --- | --- | --- | --- |
| 1 | Act 1, Shimotsuki, after gym 1 (second milestone) | A rematch at home, not in the gym; she's softer there. | none (she has no points) | TM `TODO(design)` | Closes at the tournament |
| 2 | Act 1, before the tournament | She asks him to look out for Akira. He can promise or not; it comes back when Akira leaves. | Akira's points (the promise) | none | Closes at the tournament |

### Kaede (lore thread; always helps in the finale)

`TODO(design)`: where her shrine is.

| # | When / where | What happens | Points from | Reward | Missable |
| --- | --- | --- | --- | --- | --- |
| 1 | Act 1 or 2, her shrine | She asks for rubbings of old shrine tablets around Eien. A collection quest that scales (one tablet per few maps); each rubbing adds a lore page to the journal. | Each tablet brought back | Spell Tag (Ghost boost) | No |
| 2 | Act 3, a thin place on an aurora night | She shows him a folk tale "happening": Eien variants act strangely under the aurora. Adds a research step. | The answer about whether the tales are true | Lore | No |
| 3 | Act 3, before the League | She tells what the tales say about the end of a cycle: someone always pays. Foreshadows his memories. | The answer | `TODO(design)`: charm item | No |

### Yuki (cameo in Act 1; friend from Act 3)

`TODO(design)`: her hometown.

| # | When / where | What happens | Points from | Reward | Missable |
| --- | --- | --- | --- | --- | --- |
| 0 | Act 1, a route after gym 2 (cameo) | She beats a trainer he struggled with, battles him briefly, says she'll see him at the tournament. Starts her chain. | none | none | No |
| 1 | Act 2, the tournament | Before her match she asks to spar; afterwards, her answer to losing or winning. | The answer | Battle item | Closes after the tournament |
| 2 | Act 3, her hometown | One of the fading's small disasters hits her town (overlaps the Eien quests). Helping is how they become friends. | Helping; the answer | **Keepsake:** `TODO(design)`: a tournament token | No |

Keep her scenes friendship: rivals who respect each other, no flirting.

### Ren (cameo as a League trainer; quits in Act 3)

| # | When / where | What happens | Points from | Reward | Missable |
| --- | --- | --- | --- | --- | --- |
| 0 | Act 1, a gym (cameo) | A by-the-book League trainer at gym 2 or 3. | none | none | No |
| 1 | Act 3, after the tournament | He's uneasy about the League's story and asks what the hero saw. He quits either way. | Telling him the truth or not | none | No |
| 2 | Act 3, after he quits | He helps dig through League records about the cycle. | Helping | League TM `TODO(design)` | No |

### Tetsu (near the door mountain)

| # | When / where | What happens | Points from | Reward | Missable |
| --- | --- | --- | --- | --- | --- |
| 1 | Act 3, the mountain approach | Climbers are lost in the snow after a small slide (one of the fading's signs). Find them with Tetsu. | Helping | Money | No |
| 2 | Act 3, his hut | He teaches the old paths. | The answer about why the hero is going up | Climbing gear (field-move key item; shortcut only, never a gate) | No |

### Nami (warm scenes, not quests)

Her core scenes are fixed (story outline). Optional warm scenes, earned by her points:

- Act 1: the coast with her Lapras, after they battle.
- Act 3: an aurora night, after she tells him she chooses her world.
- **Keepsake:** `TODO(design)`: does she give him a Lapras charm (and the woman in the
  epilogue has the matching one), or does only the woman have it?

### Eien quests (research, disasters, lore)

| # | Kind | When / where | What happens | Reward | Missable |
| --- | --- | --- | --- | --- | --- |
| E1 (M1) | Research | Act 1, Route 1 | The professor asks him to study Eien Poochyena (see, battle, catch). | Poké Balls | No |
| E2 | Research | Act 1 to 3 | The professor's list: study each Eien variant as they appear. Closes when she dies; Haru's step 3 finishes one entry. | Items per entry | After her death |
| E3 | Research | Act 3, aurora nights | Night-only research steps (lore notes). | Lore | No |
| E4 | Disaster | Act 1, Hamakaze | The harbor freezes early; fishermen can't go out. `TODO(design)`: what the hero does. | Money | No |
| E5 | Disaster | Act 2 or 3, `TODO(design)` | A child goes missing near a thin place. | Battle item | No |
| E6 | Disaster | Act 3, Yuki's hometown | Yuki's step 2. | (Yuki's) | No |
| E7 | Lore | Act 1 to 3 | Kaede's tablets (her step 1). | (Kaede's) | No |
| E8 | Lore | Act 1 to 3 | Old people in each town tell a folk tale about earlier cycles; each adds a journal page. Scales with the number of towns. | Lore | No |

**Count:** Haru 3, Akira 4, Fuyumi 2, Kaede 3, Yuki 2, Ren 2, Tetsu 2, E1-E5 and E8 6
(E6 and E7 are friend steps) = 24 quests, plus Nami's warm scenes and the cameos.
