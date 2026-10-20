# Story outline

Write beats in order. Each beat says where it happens, what happens, and what state it sets.
Locations and flags are `TODO` until the maps exist. Main story progress is one var,
`VAR_EIEN_STORY`, set to the `STORY_*` values in `include/constants/eien_story.h`; the
journal writes an entry for each beat reached (`src/data/eien_journal.h`).

## Prologue: our world

| # | Where | What happens | Sets (flag/var) |
| --- | --- | --- | --- |
| 1 | His bedroom (our world) | He's playing a Pokémon game. The accident happens in text on a black screen; Palkia catches him. | `TODO` |

## Act 1: Arrival (gyms 1-4)

| # | Where | What happens | Sets (flag/var) |
| --- | --- | --- | --- |
| 1 | Hamakaze | He wakes in Eien. Celebi finds him and starts following him. | `VAR_EIEN_STORY` = `STORY_ARRIVED` |
| 2 | Hamakaze, Kashiwagi house | Professor Kashiwagi's family takes him in. Haru becomes his first friend. He starts the journal. | `STORY_TAKEN_IN`; `FLAG_RECEIVED_JOURNAL` |
| 3 | Hamakaze, Kashiwagi's lab | He picks a starter; Akira takes the one strong against it, Haru the third. First battle with Akira. | `STORY_GOT_STARTER` |
| 4 | Route 1 | Coast, snowy fields, a small shrine. Eien Poochyena, which helps against the Ice gym. | `STORY_ROUTE_1` |
| 5 | Shimotsuki | Akira shows him his mother's gym. Gym 1: Fuyumi (Ice). | `STORY_SHIMOTSUKI`, then `STORY_BADGE_1` |
| 6 | Lake Usurai, north of Shimotsuki (`MAP_EIEN_ROUTE2`) | Celebi flickers and drops at a frozen lake; Nami's Lapras carries them across to a shelter, where Celebi recovers. End of the first milestone. | `STORY_MET_NAMI` |
| 7 | Route 2's mountain pass ([route-2.md](locations/route-2.md)) | Haru gives him the Town Map. Midway, a patch where the world thins (the snow stops, colours drain, Celebi reacts, Pokémon flee). People in field gear (the Eien Survey) rope it off as if they've seen it before; Hinata, a young researcher among them, chats with him about Celebi. He only learns later they were the villains. | `TODO` |
| 8 | Yunotaki ([yunotaki.md](locations/yunotaki.md)), Route 3 ([route-3.md](locations/route-3.md)), then Isaribi ([isaribi.md](locations/isaribi.md)) | Akira battles him by the gym door (he just lost to Ibuki). Ren passes him at the gym door after the badge. Gym 2: Ibuki (Fighting), the Misogi Badge. On Route 3, down a gorge to the coast: Yuki's cameo at a rope bridge, the Eien Survey's cleared tunnel round the washed-out road, and the first sight of the door mountain from its exit. Gym 3 in Isaribi, a Sea of Japan fishing port: Akari (Electric), the Lantern Badge; Akira watches from the stands. He battles Nami on Isaribi's pier after gym 3. | `TODO` |
| 9 | Route 4 ([route-4.md](locations/route-4.md)), then Hanashiro ([hanashiro.md](locations/hanashiro.md)) | Inland across the rice plain. An orchard by the road blossoms and withers in an hour; the Eien Survey ropes it off, and one member asks about Celebi a little too closely (seen again at the tournament; the one who reports Celebi to Minato). In Hanashiro, a castle town of apples and cherry trees, Yuki teases him at the Pokémon Center. Gym 4: Mamoru (Grass), the castle's head gardener, the Blossom Badge. | `TODO` |

## Act 2: The tournament (midpoint)

| # | Where | What happens | Sets (flag/var) |
| --- | --- | --- | --- |
Two days in Hanashiro's castle grounds ([hanashiro.md](locations/hanashiro.md)). Decided in
[brainstorm-tournament.md](brainstorm-tournament.md). He plays three matches; the final never
happens.

| # | Where | What happens | Sets (flag/var) |
| --- | --- | --- | --- |
| 1 | Hanashiro, the castle grounds, day 1 | The opening. Round 1: KAITO (the bridge rematch, about Lv 30). The chain steps: Yuki's spar, training with Akira while Fuyumi watches, and Fuyumi asking him to look out for Akira. | `TODO` |
| 2 | Hanashiro, the inn, night 1 | A last quiet scene for Fuyumi, Akira and him. | `TODO` |
| 3 | The castle grounds, day 2 | Round 2: Yuki (Lv 32). The semi-final: Nami (Lv 34). On the next field Akira's evolved starter wins his semi-final (first seen here). | `TODO` |
| 4 | The castle grounds, day 2 | Mid-semi-final a signal goes up; Nami stops ("I'm sorry. Not now.") and runs. Tokoyo has opened a thinning on purpose under the castle (a thin place) to test a small version of the door-mountain machine; it gets away from them. They didn't mean to kill anyone. Celebi flickers and drops, as at Lake Usurai. Hinata, in Tokoyo's gear, leads the crowd out. | `TODO` |
| 5 | The grounds, the passage under the castle | He fights through two or three Tokoyo members (the Route 4 member among them, Lv 30-33) to reach the stands. | `TODO` |
| 6 | The stands | He arrives as Fuyumi (with her Ice Pokémon) and Hashimoto hold the thinning back side by side so the stands can empty: two people on opposite sides. Both die, plainly and briefly. Akira sees it. He's too late. | `TODO` |
| 7 | The stands, after | He finds Nami at Hashimoto's body among Tokoyo's members, in their gear: that's how he learns she's with them. Minato, first seen, calm and grieving Hashimoto: "We are Tokoyo." The League names Akira the winner (his semi-final finished); it's hollow to him. | `TODO` |
| 8 | Shimotsuki | Fuyumi's funeral; Kaede keeps the rite. Then the League's statement: "an accident". Akira hears it. (`TODO(design)`: Akira's and Kaede's lines; who reads the statement; whether Seiji is seen.) | `TODO` |

## Act 3: The split (gyms 5-8)

| # | Where | What happens | Sets (flag/var) |
| --- | --- | --- | --- |
| 1 | Route 5 ([route-5.md](locations/route-5.md)), east out of Shimotsuki | Through old beech forest, greyed in patches; a Tokoyo member openly ropes off a thinning. At the forest's end Akira waits to say goodbye properly and asks him not to follow; they battle (about Lv 36); then he goes to Minato. Fuyumi's promise changes one line. Decided in [brainstorm-act-3-gym-5.md](brainstorm-act-3-gym-5.md). | `TODO` |
| 1b | Kanaya ([kanaya.md](locations/kanaya.md)) | An ironworks town. Ren asks what he saw at the tournament. Fresh Survey digging in the old mine's sealed seam. Gym 5: Takumi (Fire), a League loyalist who believes the "accident" story; the Forge Badge. | `TODO` |
| 2 | Route 6, then Minori ([minori.md](locations/minori.md)), Yuki's village | After gym 5 her letter asks for help: her Absol sensed something coming. On festival night a thinning opens at the terraces and the village's Pokémon walk into it; he and Yuki bring them back and beat two Tokoyo members measuring it. The festival ends late; the terraces stay grey for the year. Helping is how they become friends. | `TODO` |
| 3 | Route 7, then Hoshimi ([hoshimi.md](locations/hoshimi.md)), the League's research station | Up onto the highland plateau. Ren, who has just quit, gets him into the station's archive: the cycle and the League's cover-up from the League's side, and Tokoyo's plan to drain other worlds, his own included. Gym 6: Tsukiko (Psychic), the astronomer who hid it; he challenges her knowing; she's opening the records now because the fading is speeding up. The Aurora Badge. Decided in [brainstorm-gym-6.md](brainstorm-gym-6.md). | `TODO` |
| 4 | The road out of Hoshimi | Nami knew he'd find out and comes to tell him herself that she chooses her world over his. Then Haru's letter calls him home: his mother is close to a breakthrough. | `TODO` |
| 5 | Hamakaze: the Kashiwagi house, then the lab | A scene takes him home: a calm evening with the professor and Makoto; she shows him her readings (Kumo, her Altaria, on its beam). The next day her own experiment opens a thinning in the lab: to prove other worlds exist she'd tuned her instruments to a thin place under the beach where he woke up. No villain: the cost of knowing. She sends him and Haru out with her notes and Kumo and stays to shut the instruments down; Haru turns back and he pulls him out; he walks out through the lab as it drains to grey. The lab goes grey, then quiet. That evening at the house, Makoto, Haru and him, little said. Decided in [brainstorm-lab-disaster.md](brainstorm-lab-disaster.md). | `TODO` |
| 6 | Hamakaze's beach, the grey lab, then Shimotsuki | That night Celebi takes him to the beach where he woke: its glimpse of the ended world is that beach with no colour and no snow, the sea not moving. The next day, in the grey lab where only her desk is still in colour, Haru reads her key line aloud (his step 3); her notes go into the journal: the cycle, Palkia's test, Celebi's future, and how a cycle ends safely (an outsider has to carry the change, and forgets it; Arceus has to be let go, not saved; `TODO(design)`: the details, Act 4). Haru gives him Kumo, which flies him from the Town Map (fast travel). In Shimotsuki: Akira at Fuyumi's grave (optional, his step 3), then Kaede's first aurora night (her step 2). | `TODO` |
| 7 | Route 8, then Uminari ([uminari.md](locations/uminari.md)) | He flies back to Hoshimi and goes down onto the door mountain's peninsula. Gym 7 in a tuna port on a rough strait: Ushio (Water), who openly sides with Minato (she lost her husband to the strait and won't lose her town to the fading). The Tide Badge. Decided in [brainstorm-gyms-7-8.md](brainstorm-gyms-7-8.md). | `TODO` |
| 8 | Route 9, then Kawara ([kawara.md](locations/kawara.md)) | Inland: a slide leaves climbers lost in the snow; he finds them with Tetsu (his step 1). In Kawara, the temple town at the mountain's foot: Tetsu's hut and the climbing gear (his step 2). Gym 8: Tome (Ghost), an old blind *itako* on no side, who knew Kaede's grandmother and has "heard of him from the dead". The Bell Badge. Across the caldera lake, the League and the door mountain side by side. Optional any time with Kumo: Hanashiro's missing child with Mamoru (E5); Kaede's step 3 in Shimotsuki. | `TODO` |

## Act 4: The League and the end

| # | Where | What happens | Sets (flag/var) |
| --- | --- | --- | --- |
| 1 | Tokiwa Hall, the League ([tokiwa-hall.md](locations/tokiwa-hall.md)), on the caldera lake beside Tobira-yama | The Bell Badge opens it. Three new Elite Four (Dark, Steel, Dragon), then Ibuki, back at the League he walked away from because it needs him now. Then the door opens: a thinning spreads from the mountain across the caldera into the hall; the screen drains, the hall goes grey, the Elite Four stop. The Dragon member holds the hall so he can go. Decided in [brainstorm-act-4.md](brainstorm-act-4.md). | `TODO` |
| 2 | Tokiwa Hall, Seiji's room | At Seiji's door the Champion's battle becomes his confession: he ordered the cover-up. He joins him. He never becomes Champion. | `TODO` |
| 3 | Tobira-yama, the door mountain ([tobira-yama.md](locations/tobira-yama.md)) | The caldera lake path → Kaede fights beside him in a tag battle against two Tokoyo members at the riverbed of souls → Tetsu's path and Ren holding the side trail (if their points are high) → Nami's last battle near the summit, on Minato's side; she never changes her mind. Haru and Yuki go up with Seiji. | `TODO` |
| 4 | Tobira-yama, the summit | Akira, one on one (the rival's ending; with high points he steps aside afterwards and stays out of it). Then he and Seiji fight Minato. Minato's machine fires to pull him (an outsider, the bridge between worlds) through the door, and Celebi takes it and dies: plain, physical, no speech. Minato walks away, unrepentant, in silence. Palkia appears at the door: he walks into the light, the cycle finishes through him, Arceus renews (the colour coming back), his memories start to go. Palkia gives him until dawn. | `TODO` |
| 5 | Across Eien, at night, then the door at dawn | Under the renewed world's first aurora Kumo flies him to each friend in turn: Haru and Makoto (Hamakaze), Yuki (Minori), Kaede and Chiyo (Shimotsuki), Akira at Fuyumi's grave (his line depends on his points), Tetsu and Ren (Kawara), and Nami last, at Lake Usurai where they met: she lends him Lapras to cross one last time. At first light he steps into the door's light; the journal's pages go blank; Kaede sees the tale she has always told happen. Palkia sends him home. |

## Ending

He wakes up in a hospital in our world, remembering Eien only vaguely. The main ending shows
only a short glimpse of a woman who looks exactly like Nami.

## Epilogue (the post-game)

The post-game is a memory epilogue in our world. It mirrors the prologue: he plays the
ordinary Pokémon game he was playing before the accident, and Eien seeps into it.

- Things that shouldn't be there appear: a snowy route, a Rock/Dark Poochyena. Only he
  notices.
- His friends are ordinary game NPCs with generic lines that change slightly as he
  remembers.
- Post-game content (Frontier-style battles, legendaries, finishing research) happens inside
  this game.
- Memories come back three ways, all collected in the journal: its blank pages refill as
  post-game content is done; short flashes at places that mattered (the tournament, the
  lab, where Celebi died); finishing an Eien species' research returns the memory tied to
  it.
- At the very end, a faint echo of Celebi recognizes him (an echo: Celebi stays dead).
- Finishing the epilogue gives the full meeting with the woman who looks like Nami. The game
  leaves it open whether it's really her; the hint for attentive players is a small Lapras
  charm.

`TODO(design)`: hospital or home; where the Frontier and legendaries sit in the home game;
whether catching Arceus or Palkia inside "a game" is deliberate; he knows only real
Pokémon again, so research restarts at "???" (a deliberate echo, but check it isn't
repetitive).

## Open questions

- TODO(design): should the hospital ending make players wonder if it was all a coma dream,
  or only whether the woman is Nami? The epilogue (Eien seeping into an ordinary game)
  keeps this ambiguous rather than answering it.
- TODO(design): does Palkia's test serve Arceus, or go against it?
- TODO(design): are the villains' loyal Pokémon a theme ("loyalty doesn't mean they're
  right")?
- TODO(design): Hashimoto's relationship to Nami beyond mentor.
- Kaede's shrine is in Shimotsuki; she's met there after gym 1.
- TODO(design): where Tetsu and Ren appear, and whether the friends get tag battles.
