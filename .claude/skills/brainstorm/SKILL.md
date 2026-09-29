---
name: brainstorm
description: Run an interactive brainstorming session with the user - for a story, world, characters, game design, a product, a feature or any open-ended idea. Asks focused questions in rounds, offers concrete options for each, flags gaps and contradictions, and keeps a running notes file of what's decided. Use whenever the user asks to brainstorm, explore ideas, "figure out" a story/design/concept, or wants help deciding what something should be.
---

# Brainstorm with the user

The user is the author. Your job is to draw out what they want, show them options they
hadn't considered, and point out the holes, not to write the thing for them. Nothing you
propose is decided until they pick it.

## 1. Start: take stock

- Read what already exists: the user's brief, and any project docs that hold the design
  (e.g. a `design/` folder, README, CLAUDE.md rules on where decisions go).
- Split the brief into **givens** (things the user stated; treat as locked) and
  **open questions** (everything the brief leaves undecided).
- Look for **tensions** between givens: two things the user wants that pull against each
  other, or a given that makes another one hard. Name them early; they're often where
  the most interesting decisions are.

## 2. Run rounds

Each round is one message:

1. **What I heard** - a short list of the givens and anything decided in earlier rounds.
   Keep it brief so the user can catch misreadings.
2. **Questions** - 4 to 6 per round, most important (most load-bearing) first. For each:
   - One line on why it matters (what depends on the answer).
   - 3 or 4 **options**, lettered, each a sentence or two, concrete and meaningfully
     different from each other (not three flavors of the same idea). Include at least one
     option the user probably hasn't thought of.
   - Your recommendation and why, when you have one. Say it's a recommendation.
   - The user can always pick, mix, or write their own.
3. **Gaps and tensions** - things missing or contradictory that aren't this round's
   questions yet. One line each. These become later rounds.
4. How to answer: e.g. "Reply like `1b, 2a+c, 3: your own idea`; skip any you want to
   leave open."

Guidelines:

- Ask about foundations before details: premise, stakes and the ending before scene-level
  beats; the core loop before features.
- Don't ask what the user already answered, and don't ask things you could settle with a
  sensible default. Propose the default in the notes instead.
- Follow the user's energy. If they riff on something, build on it in the next round.
- When an answer creates a new tension or consequence, say so ("If the mentor is the
  betrayer, the Act 2 reveal needs someone else to set up the tournament").
- Keep options grounded in the medium and its limits (a GBA game has short text boxes and
  a fixed budget of maps; a mobile app has small screens; etc.).
- Don't invent names, lore or facts and present them as decided. Placeholder names are
  fine when marked as placeholders.

## 3. Keep notes

Keep a notes file for the session so nothing is lost between rounds or sessions:

- Location: the project's design/docs folder if it has one (e.g.
  `design/brainstorm-<topic>.md`), otherwise `brainstorm-<topic>.md` in the working
  directory. Follow any project rule about where design decisions live.
- Sections: **Decided**, **Leaning** (picked tentatively), **Open questions**,
  **Gaps and tensions**, **Parked ideas** (liked but not now), **Rejected** (with a
  one-line reason, so it isn't proposed again).
- Update it after every round of answers, then continue with the next round.
- If the project is a git repo and the user works through commits, commit the notes
  with the related change; otherwise just save the file.

## 4. Wrap up

When the big questions are settled, or the user says so:

- Summarize what's decided in a few lines and list what's still open.
- Offer to promote decisions into the project's real docs (e.g. a game bible, story
  outline, spec). Do that only when the user agrees; the notes file stays as the record.
- Suggest the next brainstorm topic if there's an obvious one.
