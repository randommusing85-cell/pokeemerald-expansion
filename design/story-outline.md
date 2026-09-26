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
| 6 | Past Shimotsuki `TODO(design)` | Nami helps him when he's lost or Celebi is struggling. End of the first milestone. | `STORY_MET_NAMI` |
| 7 | `TODO(design)` | The villains appear: principled, gracious when beaten. Signs of the fading: small disasters, off-screen losses. | `TODO` |
| 8 | `TODO(design)` | He battles Nami. Gyms 2-4. | `TODO` |

## Act 2: The tournament (midpoint)

| # | Where | What happens | Sets (flag/var) |
| --- | --- | --- | --- |
| 1 | Tournament `TODO(design)` | Nami and Yuki are competitors. | `TODO` |
| 2 | Tournament | The villains move during the event. The disaster kills Fuyumi and Hashimoto. | `TODO` |
| 3 | Tournament | He learns Nami is with the villains. | `TODO` |

## Act 3: The split (gyms 5-8)

| # | Where | What happens | Sets (flag/var) |
| --- | --- | --- | --- |
| 1 | `TODO(design)` | The League plays Fuyumi's death down. A few towns later Akira joins Minato openly. | `TODO` |
| 2 | `TODO(design)` | Yuki becomes a friend. | `TODO` |
| 3 | `TODO(design)` | He learns about the cycle and Minato's plan to drain other worlds, his own included. | `TODO` |
| 4 | `TODO(design)` | Nami tells him she chooses her world over his. | `TODO` |
| 5 | Kashiwagi's lab | The professor dies in a lab disaster, leaving the research that explains the cycle. | `TODO` |
| 6 | `TODO(design)` | He learns why Palkia brought him, and that Celebi came from a future where the world ended. | `TODO` |

## Act 4: The League and the end

| # | Where | What happens | Sets (flag/var) |
| --- | --- | --- | --- |
| 1 | Pokémon League | Partway through the Elite Four, Minato's plan starts. | `TODO` |
| 2 | League | Seiji admits the cover-up and joins him. | `TODO` |
| 3 | Door mountain | With Seiji, Haru and Yuki he fights Minato and Akira. Celebi dies protecting him. | `TODO` |
| 4 | Door mountain | He helps the cycle finish safely; Arceus renews. The journal's pages go blank. | `TODO` |
| 5 | `TODO(design)` | He says goodbye to his friends. Palkia sends him home. | `TODO` |

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
- TODO(design): where Kaede, Tetsu and Ren appear, and whether they get tag battles.
