# Arrival movie: production log

The pilot movie cutscene ([cutscene-arrival.md](../../../cutscene-arrival.md)). Everything here
was generated on Higgsfield; the 2400x1792 masters stay in the Higgsfield account under the
job ids below, and the files in this folder are 1600-wide JPEG copies.

**Status (2026-11-26):** reference sheets, the beach plate and the last shot's keyframe are
made and picked. Waiting on the user's look at the style before the other keyframes and any
video are generated.

## Settings

Model `nano_banana_2` (Higgsfield reports it as `nano_banana_flash`), 4:3, resolution `2k`,
two takes per prompt, paid with credits (2 per image).

## Picks

| File | What | Job id (pick) | Other takes |
| --- | --- | --- | --- |
| `ref_hero.jpg` | The hero's model sheet: front, side, back, head | `8546c0f8-e618-49e8-a28c-f446a4f88d46` | `fe609351-d5be-488f-bd11-45830681fc86` (shaggier hair) |
| `ref_palkia.jpg` | Palkia's model sheet, with the shoulder pearl and a hand (shots 3-4) | `5f7e6bc4-c101-4c12-96b1-0724671c94c4` | `8c859969-08f4-42a0-8279-f15bfdeb27df` (extra arm fins in the front view) |
| `ref_celebi.jpg` | Celebi's model sheet (not in this movie; for later scenes) | `1898a476-796d-4982-96ad-cf8d4490caae` | `9498b9ad-77b3-4d08-8411-08cdab46c499` (antenna tips less blue) |
| `bg_hamakaze_beach.jpg` | Hamakaze's beach, background plate | `1a4f8a68-f308-4315-8152-a2e37c0060d5` | `fe643b63-61d5-41ff-be93-3e26113eef34` (no boats, more forest) |
| `key_shot6.jpg` | Shot 6 keyframe: he lies at the tide line, from above | `c85c3965-5515-42d0-9097-82e7dcca5dab` | `6b685849-17d3-43d5-afb7-26f531b05a31` (reads as standing; rejected) |
| `key_shot6_alt.jpg` | Shot 6, a closer and more sprawled alternative | `b1ccfcdc-676e-46bc-b8ff-ed0cff751b8f` | `8214dbb4-97b5-4e24-8ef0-69a352ac8918` (blocked by Higgsfield's content filter) |

## Prompts

Shared style clause, used in every character prompt: "restrained hand-drawn cel animation,
thin dark outline, flat cel shading with only two tones per colour, muted cool palette, no
gradients, no glow, no sparkle ... no text, no labels, no watermark".

- **Hero sheet:** "Anime character reference sheet, one character shown four times on a plain
  pale grey background: full-body front view, full-body side view, full-body back view, and a
  head-and-shoulders close-up. The character: an ordinary Japanese boy in his late teens, about
  seven heads tall, slim, average build. Short messy dark brown-black hair with a side fringe
  falling across his forehead. Plain face with small features, calm neutral expression, dark
  eyes. He wears a plain mid-grey zip-up hoodie with the hood down, blue jeans, and simple dark
  sneakers. No accessories, no logos." + the style clause.
- **Palkia sheet:** "Anime model sheet of the Pokemon Palkia, exactly its official design and
  proportions: [its features]. Shown three times on a plain pale grey background: full-body
  front three-quarter view, full-body side view, and a close-up of one shoulder plate with its
  pearl and one clawed hand." + the style clause.
- **Celebi sheet:** "Anime model sheet of the Pokemon Celebi, exactly its official design and
  proportions: [its features]. Shown four times on a plain pale grey background: floating front
  view, side view, back view, and a head close-up with a gentle, quiet expression." + the style
  clause ("soft muted green").
- **Beach plate:** "Anime background painting, no characters, no people, no animals. A small
  fishing village beach in northern Japan (Tohoku) in winter, overcast afternoon. Foreground: a
  strip of dark wet sand at the tide line with a thin layer of fresh snow settling on the drier
  sand above it, a low grey wave running up. Middle distance: snow-covered ground rising gently
  from the beach to a few low wooden houses with snow on their roofs, one with a pale blue wall,
  and a line of snow-laden pines behind them. A grey-blue sea to one side, heavy pale sky, snow
  falling lightly. Style: gouache-painted anime background with visible brushwork, muted cold
  blue-greys and off-whites, no warm colours, no sun, soft flat light, quiet and empty."
- **Shot 6 keyframe** (references: the hero sheet and the beach plate): "Anime film still, 4:3.
  Camera directly overhead, looking straight down. The boy from the first reference image (same
  face, hair, hoodie, jeans, sneakers) lies on his back on a winter beach, eyes closed, arms
  loose at his sides, asleep or unconscious, small in the frame, slightly left of centre. He lies
  on dark wet sand at the tide line; fresh snow is settling on the sand around him and a few
  flakes on his hoodie and hair. Along the bottom edge of the frame a thin grey wave with a pale
  foam line runs up the sand and stops short of his feet. Beach, sand, snow and sea painted in
  the same gouache style and cold blue-grey palette as the second reference image." + figure and
  background style clauses.
- **Shot 6 alternative:** the same, with the pose spelled out ("lies diagonally across the
  frame ... head tipped to one side ... one arm bent with the hand resting near his head ... one
  knee slightly bent ... a soft contact shadow").

## Notes for the next steps

- The overhead pose needs words like "lies diagonally", "contact shadow" and a described limp
  pose, or the model pastes the sheet's standing front view onto the ground.
- One take was blocked by the content filter (the "collapsed ... unconscious" wording, most
  likely). Prefer "asleep" and "eyes closed".
- Still to make: keyframes for shots 1-5, the six motion clips, assembly and sound.
