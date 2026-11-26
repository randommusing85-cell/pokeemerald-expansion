# Hamakaze

- **Map(s):** `MAP_HAMAKAZE` (town), `MAP_HAMAKAZE_KASHIWAGI_HOUSE`, `MAP_HAMAKAZE_LAB` (map group
  `gMapGroup_Eien`). Placeholder layout: see **Maps** below.
- **Type:** town (hometown)
- **Connects to:** Route 1, north (the gap in the tree line), decided in
  [brainstorm-route-1.md](../brainstorm-route-1.md).

## Purpose

Where he wakes in Eien, finds a home with the Kashiwagi family, and gets his first Pokémon.

## Look

A coastal fishing village ("sea wind"), snowy. Tilesets: `gTileset_General` + `gTileset_EienCoast`
(beach house, Japanese wooden house, small houses).
`TODO(design)`: landmarks, music.

## Story beats here

Act 1 beats 1-3 in [story-outline.md](../story-outline.md).

**Act 3 (beats 5-6): the lab disaster** ([brainstorm-lab-disaster.md](../brainstorm-lab-disaster.md)).
Haru's letter brings him home. A calm evening; the next day the professor's experiment on the
**thin place under the beach where he woke** (Palkia set him down there; that's why she studied
it and why Celebi found him there) opens a thinning in the lab (`WEATHER_THINNING`). She sends him
and Haru out with her notes and Kumo, her Altaria, and stays; Haru turns back and he pulls him
out; he walks out through the greying lab (a few turns of time pressure). That evening at the
house: Makoto (he ran over from the house when it happened), Haru and him. That night Celebi takes
him to the beach: the glimpse (the beach with no colour, no snow, the sea not moving). Next day
Haru's step 3 at her desk. **Afterwards the lab stays grey** (the thinning's grey tiles) until the
epilogue, but enterable, her desk the one spot in colour. The League says nothing this time;
townsfolk talk about "the lab accident" (`TODO(design)`: whether the League should speak). Lines
`TODO(design)` (short and plain; no speech).

## NPCs and events

| NPC / event | Position (x,y) | Visible when | Says / does |
| --- | --- | --- | --- |
| Celebi | beach (13,11), then follows | from the start | Drifts down beside him on the beach and follows him (follower NPC). Talking to it gives a hint about where to go next (`data/scripts/eien_celebi.inc`) |
| Fisherman | beach (4,15) | always | "Ice in the harbour already. Too early. Nothing's biting." (the early freeze, side-quest E4) |
| Villager | town (9,11), wanders | always | Points to the Kashiwagi house, then the lab, then the road to Shimotsuki ("Wear something.") |
| Professor Kashiwagi | lab | | Offers the three starters |
| The professor's Altaria, Kumo | lab, on the back desk (10,2) | from Act 1 until it's given | Her Pokémon (雲, "cloud", her nickname for it). Built (`LOCALID_LAB_ALTARIA`): its cry and "The professor's Altaria hums softly." (final line under Dialogue). After her death Haru gives it to him: it flies him (fast travel, [progression.md](../progression.md)) |
| Makoto, Kashiwagi's husband | house | | Runs the household that takes him in. Heals the team after a white-out: "Back again? Sit. I'll see to them." |
| Haru Kashiwagi | house / lab | | First friend; takes the third starter |
| Akira | lab | | Takes the starter strong against the player's; battles right after |
| Journal | - | taken in | Opens from the start menu (in place of the PokéNav). First page: "My name is (player). I'm from another world. If I start forgetting, read this." |

## Scenes (built)

1. **Waking (town, `Hamakaze_EventScript_WakeUp`):** runs while `VAR_EIEN_STORY` =
   `STORY_PROLOGUE`. He's on the beach at (12,14) (warp 2, the arrival point); Celebi drifts
   down beside him and starts following. Sets `STORY_ARRIVED`.
2. **Taken in (house, `Hamakaze_KashiwagiHouse_EventScript_TakenIn`):** runs on entering at
   `STORY_ARRIVED`. The professor, her husband and Haru; the professor gives him a notebook
   and he writes the first page. Sets `FLAG_RECEIVED_JOURNAL`, `STORY_TAKEN_IN`.
3. **Starters (lab, `Hamakaze_Lab_EventScript_Intro` / `_ChooseStarter`):** at `STORY_TAKEN_IN`
   three balls on the floor (Torchic, Bulbasaur, Froakie, all Eien forms, Lv 5). He picks one;
   Akira takes the one strong against it, Haru the last; Akira battles him at once. Losing is
   fine (early rival battle: healed, no white-out). Akira leaves for Shimotsuki. Sets
   `STORY_GOT_STARTER`.
4. **The research (lab, after the battle):** the professor asks him to study Eien Poochyena
   (see, battle, catch) and gives him Poké Balls. Opens `QUEST_RESEARCH_POOCHYENA`.
5. **Haru's map (town, north exit):** walking to the north exit after the starters, Haru
   catches up with his half-drawn map and asks him to note three places on Route 1. Opens
   `QUEST_HARU_MAP`.

All three maps' lines are final and listed under **Dialogue (final)** below, which is the
source of truth for the Essentials port. In the GBA reference build only the town map's script
carries them (PR #30); the house's and the lab's scripts still hold the older drafts. Choices
made here that the docs didn't settle, all easy to change:
- The professor hands him the notebook ("Write things down while they're fresh. I always do.").
- Haru is the one who notices Celebi ("You've got a Celebi. A real one."): people here know what
  a Celebi is, which the Survey's interest in it later relies on. The adults don't remark on it.
- Akira's lab level: 5, like the starters.
- Who is where after each beat: the professor is at the lab from `STORY_TAKEN_IN` on; Haru is at
  the lab during the starter scene and home again after.

## Dialogue (final)

Final lines for Hamakaze's three maps (dialogue pass, 2026-10-21 and 2026-11-26), written
without engine text codes: each line below is one text box, and a `/` starts the next box by
the same speaker. *Hero* lines are his thoughts (shown in brackets in the GBA build), except
the journal page. `(player)` and `(species)` are filled in by the game. Stage directions are
in square brackets. Voices: [dialogue-style.md](../dialogue-style.md).

### Town

**Waking.** Trigger: he arrives on the beach for the first time (story state Prologue). Runs
once, no input but advancing text. Outcome: Celebi follows him; story state Arrived.

- *Hero:* …Cold. / Sand. Snow on the sand. / This isn't my room.
- [Celebi drifts down beside him. He turns to it. Celebi's cry.]
- *Hero:* Is that… a Celebi? / In the games you get one at a shrine. If you're lucky.
- [Celebi starts following him.]
- *Hero:* It's following me. / Houses, up the beach. Someone there will know where this is.

**Talking to Celebi** (any time; its cry first, then one line by story state):

- Arrived: Celebi floats toward the houses up the beach.
- Taken in: Celebi keeps looking at the yellow building.
- Got a starter: Celebi looks north, past the trees.

**Fisherman** (beach): Ice in the harbour already. Too early. Nothing's biting.

**Villager** (wanders near the houses), by story state:

- Arrived: You're not from here. / Try the blue house. The Kashiwagis take in all sorts.
- Taken in: The yellow one's the lab. She's always in there.
- Got a starter: Off to Shimotsuki? It's colder up there. Wear something.

**Haru's map.** Trigger: he walks to the north exit after getting his starter, while Haru's
map quest hasn't started. Haru runs up behind him. Runs once. Outcome: Haru's map quest opens
(three places to note on Route 1).

- HARU: Wait up!
- [He turns round; Haru reaches him.]
- HARU: I'm drawing a map of Eien. For you. You don't know where anything is yet. / Route 1's
  just north. Look at three places for me: the coast, the fields, and the shrine. / Write them
  in your journal. I'll copy them in.
- [The quest opens.]
- HARU: Thanks! Don't get lost. It's one road.
- [Haru goes back toward the house.]

### The Kashiwagi house

**Taken in.** Trigger: he enters the house in story state Arrived. Runs once. Present: the
professor, Makoto, Haru. Outcome: he has the journal (it appears in the menu); story state
Taken in; from now on the professor is at the lab, and so is Haru until the starters are picked.

- [He steps in. The professor turns to him.]
- PROFESSOR: You're half frozen. Come in. Sit by the stove.
- [Makoto turns to him.]
- MAKOTO: The beach, in this? Where have you come from?
- *Hero:* Another world. / I can't say that.
- MAKOTO: …All right. Eat first. / You can stay till you're on your feet.
- PROFESSOR: I'm Professor Kashiwagi. I study Pokémon here. / This is Makoto. And that's our
  son, Haru.
- [Haru turns to him.]
- HARU: You've got a Celebi. A real one. / Sorry. Hi. I'm Haru. I'll show you round.
- PROFESSOR: Here, a notebook. / Write things down while they're fresh. I always do.
- [Item fanfare.] (player) got a notebook.
- *Hero:* I'll start with what I'm sure of.
- *The journal's first page:* My name is (player). I'm from another world. If I start
  forgetting, read this.
- [System hint:] The journal is in the menu.
- PROFESSOR: When you've warmed up, come by the lab. The yellow one. / I've got something for you.

**Talking to them afterwards:**

- Makoto: Sit anywhere. It's warm by the stove.
- Haru (home again once the starters are picked): Mine's still shy. Yours already looks tough.

**After a white-out** (before he has reached Shimotsuki's Pokémon Center): he's back in the
house, facing Makoto, who heals the team.

- MAKOTO: Back again? Sit. I'll see to them.

### The lab

**The starters.** Trigger: he enters the lab in story state Taken in. Present: the professor at
her desk, Haru and Akira either side of three Poké Balls (Eien Torchic, Bulbasaur, Froakie,
Lv 5). He walks up to the balls; then the player picks one by examining it.

- PROFESSOR: There you are. / Three Pokémon from Eien. You'll have seen their cousins. Not these.
- *Hero:* Torchic. Bulbasaur. Not the colours I know. / The third one I've never seen.
- [Akira turns to him.]
- AKIRA: New kid! I'm Akira. / You pick first. I'll win with any of them.
- PROFESSOR: Whichever you like.
- [The player examines a ball: its picture shows.] Take (species)? [Yes / No. No: nothing
  happens; he can look at another.]
- [Yes. Item fanfare.] (player) received (species)! [The usual nickname question.]
- AKIRA: Then this one. It's strong against yours. Sorry!
- [Akira's ball is taken: the starter strong against the player's.]
- HARU: Then this one's mine. Hello, you.
- [The last ball is taken.]
- AKIRA: Quick battle? Let's try them!

**The battle with Akira** follows at once (his starter, Lv 5). Losing is fine: the team is
healed either way and the scene goes on.

- Akira, beaten: Aw. You're good.
- Akira, if he wins: Yes! …It was close, though.

**After the battle.** Outcome: story state Got a starter; the house becomes his white-out
point; the professor's research opens (Eien Poochyena, and the rest of her list, each shown
later); he gets 5 Poké Balls.

- AKIRA: I'm heading home. That's Shimotsuki, up Route 1. / Come find me. I'll show you the
  gym. Mum runs it.
- [Akira leaves.]
- PROFESSOR: One more thing. / Route 1 has a Poochyena that isn't like any in the books. / See
  one. Battle one. Catch one, if you can. Write it down. / There are more like it further on.
  I've made you a list. / These will help.
- [He gets 5 Poké Balls. The research quests open.]
- PROFESSOR: Route 1's north of town. Take your time. Write things down.

**Talking to them in the lab:**

- The professor, before he has picked: Whichever you like.
- The professor, afterwards: Route 1's north of town. Take your time. Write things down.
- Haru, before he has picked: Go on. You first.
- Akira, before he has picked: New kid! I'm Akira. / You pick first. I'll win with any of them.
- Kumo, her Altaria, on the back desk (its cry): The professor's Altaria, Kumo, hums to itself.

## Trainers

| Trainer | Class | Team (levels) | Notes |
| --- | --- | --- | --- |
| Akira (`TRAINER_EIEN_AKIRA_LAB_TORCHIC` / `_BULBASAUR` / `_FROAKIE`) | Rival | The starter strong against the player's, Lv 5 | Lab battle, right after picking starters (`trainerbattle_earlyrival`) |

## Items

| Item | Position | Hidden? |
| --- | --- | --- |
| Journal (start menu entry, `FLAG_RECEIVED_JOURNAL`) | given | no |
| Poké Ball ×5 | given by the professor with the research | no |

## White-out

Until he reaches Shimotsuki's Pokémon Center, a white-out brings him back to the Kashiwagi house,
facing her husband, who heals the team (`HEAL_LOCATION_HAMAKAZE`; respawn at (1,6) in the house).
The respawn is set when he leaves the lab with his starter and whenever he enters the house; the
Pokémon Center sets it to Shimotsuki from then on. The black-screen text is the engine's
"scurried back home" one. The engine side is a small edit marked `// Eien` in
`src/heal_location.c` and `src/field_screen_effect.c`.

## Flags and vars

| Name | Set when | Checked by |
| --- | --- | --- |
| `VAR_EIEN_STORY` = `STORY_ARRIVED` | He wakes on the beach | The journal's Story tab |
| `VAR_EIEN_STORY` = `STORY_TAKEN_IN` | The Kashiwagis take him in | The journal |
| `FLAG_RECEIVED_JOURNAL` | He starts the journal (taken in) | The start menu (JOURNAL entry) |
| `FLAG_JOURNAL_COVER_SEEN` | The journal is opened the first time | The journal (opens on the cover once) |
| `VAR_EIEN_STORY` = `STORY_GOT_STARTER` | After the lab battle with Akira | The journal |
| `VAR_EIEN_AKIRA_STARTER` | Akira takes his starter (its species) | His practice battle in Shimotsuki |
| `QUEST_RESEARCH_POOCHYENA` opened | The professor asks, after Akira's battle | The journal's Research and Missions tabs |
| `QUEST_HARU_MAP` opened | Haru asks at the north exit, after the starters | The journal's Missions tab; Route 1 adds the steps |

## Maps

- **Town:** a 24x20 placeholder layout (`data/layouts/Hamakaze/`, `gTileset_General` +
  `gTileset_EienCoast`), hand-made for the first playable pass; redraw it in Porymap freely,
  keeping the warps and object positions (or moving them in the map's events). Tree line along
  the top with a gap north; the Kashiwagi house (blue house, door (5,7)) and the lab (yellow
  shop, door (16,7)); a neighbour's Japanese house (not enterable); beach and sea along the
  bottom. Weather snow, map type town (so the night tint and aurora apply).
  `TODO(design)`: landmarks, music (placeholder `MUS_LITTLEROOT`).
- **Kashiwagi house:** reuses Emerald's `LAYOUT_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F` (the stairs
  lead nowhere yet). **Lab:** reuses `LAYOUT_LITTLEROOT_TOWN_PROFESSOR_BIRCHS_LAB`.
- A new game still starts in Emerald's truck; reach Hamakaze with the debug menu's warp
  (`MAP_HAMAKAZE`, warp 2 is the beach). Starting a new game here (or in the prologue) is a
  separate change: it also changes the harness's `new_game.txt`.

## Screenshot check

Played through with the harness (new game, warp to the beach): waking and Celebi, the walk
to the house with Celebi following, the house scene and the journal's first page, the lab,
picking Bulbasaur, Akira taking Torchic and Haru Froakie, the battle (lost on purpose: healed,
scene continues). Shots in `design/art/hamakaze/`. The dialogue pass (2026-10-21) re-shot the
waking pages and Haru's map ask (`6_wake_cold.png` to `10_haru_map_places.png`); every page fits
the box. The fisherman's and villager's lines are shorter than those and were checked by width.
