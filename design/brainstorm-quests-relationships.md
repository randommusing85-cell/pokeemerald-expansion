# Brainstorm: side quests and relationship points

Running notes. Nothing is decided until it's under **Decided**; decisions move into the real
docs (game bible, characters, story outline) when the user agrees.

## Givens

- Relationship points with Nami and the friends change scenes, dialogue, who helps in the
  finale and small epilogue details, never the outcome. Shown only as a line per person in
  the journal (game bible, Mechanics).
- The journal has a missions tab.
- Friends: Haru (Act 1), Yuki (from the tournament, Act 3), smaller friends Kaede (shrine
  keeper), Tetsu (mountain guide), Ren (League trainer who quits). They don't follow him;
  they turn up at big moments and in tag battles.
- Fixed beats: Akira defects; Nami and the hero choose each other anyway; Fuyumi, Hashimoto,
  the professor and Celebi die; Seiji, Haru and Yuki fight beside him at the end.

## Decided

- **Earning points (1a+b):** dialogue choices in story scenes (two or three answers, never an
  "evil" one; they read as how he treats someone) and a short quest chain per friend
  (2-4 steps across the game).
- **Who has points (2b):** Nami, Haru, Yuki, Kaede, Tetsu, Ren, and Akira. Akira still
  defects; his points change his last scene, what he says at the end and his flash in the
  epilogue.
- **What high points change (3a+d+b):** smaller friends with enough points turn up at the
  door mountain and hold off part of Minato's forces in their own battles; the epilogue's
  returning memories and how much each friend's game NPC "remembers"; a modest gift from
  each friend at their peak (a Pokémon, TM or item tied to them).
- **Nami (4a):** the romance is fixed. Points add optional warm scenes (the coast, Lapras) and
  change her lines; the core scenes always play.
- **Quest kinds (5c+a+b+d):** friend chains are the backbone, plus research quests (study Eien
  Pokémon; ties to fan knowledge), the fading's small disasters (help towns; shows the
  stakes before the big deaths) and lore (shrine tablets, folk tales, Kaede as the thread).
- **Size (r2 1b):** about 25 quests at launch (7 friend chains of 2-3 steps, plus about 8
  research, disaster and lore quests), but the system is built to grow to Unbound's scale
  (80 or more) without redesign.
- **Late arrivals (r2 2a):** Yuki and Ren get earlier cameos (Yuki met once or twice in Act 1,
  Ren as a League trainer at a gym); their chains start at the cameo.
- **Akira's chain (r2 3c):** before he leaves, training battles and helping around Shimotsuki
  (ends with Fuyumi's death); after, optional meetings on the other side where he explains
  himself and the hero can answer, no fight unless the player wants one.
- **Delivery (r2 4a+c):** chains are picked up at the friend's home (Haru in Hamakaze, Kaede
  at her shrine, Tetsu at the mountain), and letters in the journal say when someone wants
  to see him. Celebi's hints can point to them as a fallback.
- **Gifts (r2 5d):** smaller friends (Kaede, Tetsu, Ren) give an item or TM tied to them; main
  ones (Haru, Yuki, Nami, Akira) give a keepsake that does nothing in Eien but appears in the
  epilogue game and brings back that friend's memory.
- **Finale helpers (r2 6b):** Kaede always comes; high points bring Tetsu and Ren too.
- **Quest storage (r3 1b):** a dedicated quest table in the save file (a few bits of state per
  quest), read and written by new script commands (e.g. `setquest` / `checkquest`). A small,
  isolated engine addition, built before the first quest. Scales to hundreds of quests and
  keeps quests off the spare story flags.
- **Relationship storage (r3 2b):** a byte per person in the same save table; no vars used.
- **Missions tab (r3 3c):** title, a one-line hint of where to go, state (open / done /
  closed), and who gave it; grouped by person, plus an "Eien" group for research, disasters
  and lore. Filters (open only, by act) come once there are about 40 quests.
- **Rewards (r3 4b):** items, TMs, keepsakes, lore, money and battle items. No Rare Candies or
  EXP rewards, so the soft level caps hold.
- **First milestone (r3 5b):** one quest per system: Haru's step 1 in Hamakaze, a research
  quest from the professor (study Eien Poochyena on Route 1), Akira's step 1 around
  Shimotsuki. Proves the quest table, the missions tab and points end to end. Fuyumi's
  chain starts in the second milestone, still before the tournament.
- **Missable (6c):** quests tied to people who die or leave close for good, but the journal
  notes the unfinished thing and the epilogue gives it back as a memory.

## Leaning

_(none)_

## Open questions (later)

- Each friend's chain, step by step (draft outlines; new lore as `TODO(design)`).
- The journal's screen layout (three tabs), its own short brainstorm.
- The letter trigger rule (after the next badge, on entering a town, ...).
- Point thresholds: what counts as "enough" for a finale helper or a peak gift.

## Gaps and tensions

- Yuki's scenes must read as friendship, not a second romance.
- Quests with the professor and Fuyumi are missable by design; their chains need to start
  early enough that a player can finish them.
- The "seeing the other side" quest kind (5e) wasn't picked; Akira's "after" meetings cover
  some of it.
- Save space: 375 spare flags but only 23 spare vars today. Vanilla Hoenn flags free up only
  once the vanilla scripts that use them are removed.

## Parked ideas

- Free "hang out" visits between gyms (1c): good, but many scenes.
- Points from battles (1d): maybe a small bonus later.

## Rejected

- No points for Nami (4c): the romance should feel personal.
- Non-missable quests (6b): loses the sting of the deaths.
