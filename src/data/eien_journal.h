// Journal content (design/side-quests.md, design/story-outline.md). Included only by
// src/eien_journal.c. Text is written in the hero's voice (design/dialogue-style.md) and is
// wrapped to the page at runtime, so write plain sentences without line breaks.

// The cover: the first page he wrote. Shown the first time the journal opens.
static const u8 sJournalCoverTitle[] = _("First page");
static const u8 sJournalCoverText[] = _("My name is {PLAYER}. I'm from another world. If I start forgetting, read this.");

// One entry per story beat (VAR_EIEN_STORY). "next" is the "what's next" line while this
// is the latest beat reached.
struct JournalStoryEntry
{
    u8 beat;
    const u8 *title;
    const u8 *text;
    const u8 *next;
};

static const struct JournalStoryEntry sJournalStory[] =
{
    {
        .beat = STORY_ARRIVED,
        .title = COMPOUND_STRING("Hamakaze"),
        .text = COMPOUND_STRING("I woke up on a cold beach. A Celebi was watching me. This isn't a dream."),
        .next = COMPOUND_STRING("Find somewhere warm."),
    },
    {
        .beat = STORY_TAKEN_IN,
        .title = COMPOUND_STRING("The Kashiwagis"),
        .text = COMPOUND_STRING("Professor Kashiwagi's family took me in. Her son Haru showed me around. I started this journal."),
        .next = COMPOUND_STRING("Go to the professor's lab."),
    },
    {
        .beat = STORY_GOT_STARTER,
        .title = COMPOUND_STRING("A partner"),
        .text = COMPOUND_STRING("I picked my first Pokémon at the lab. Akira took the one strong against mine and battled me right away."),
        .next = COMPOUND_STRING("Follow Route 1 to Shimotsuki."),
    },
    {
        .beat = STORY_ROUTE_1,
        .title = COMPOUND_STRING("Route 1"),
        .text = COMPOUND_STRING("Snow, sea and a small shrine. The Poochyena here aren't just Dark. They're Rock too. The games never had that."),
        .next = COMPOUND_STRING("Reach Shimotsuki."),
    },
    {
        .beat = STORY_SHIMOTSUKI,
        .title = COMPOUND_STRING("Shimotsuki"),
        .text = COMPOUND_STRING("Akira showed me his mother's gym. Fuyumi. She uses Ice types."),
        .next = COMPOUND_STRING("Challenge Fuyumi's gym."),
    },
    {
        .beat = STORY_BADGE_1,
        .title = COMPOUND_STRING("First badge"),
        .text = COMPOUND_STRING("I beat Fuyumi and got my first badge."),
        .next = COMPOUND_STRING("Keep going past Shimotsuki."),
    },
    {
        .beat = STORY_MET_NAMI,
        .title = COMPOUND_STRING("Nami"),
        .text = COMPOUND_STRING("I got lost past Shimotsuki. A girl with a Lapras helped me. Her name is Nami."),
        .next = COMPOUND_STRING("Keep going."),
    },
};

// Lore pages (shrine tablets, folk tales): shown once a quest reaches a step.
// TODO(design): Kaede's tablets and the folk tales (side-quests.md) fill this.
struct JournalLorePage
{
    u16 quest;
    u8 minStep;
    const u8 *title;
    const u8 *text;
};

static const struct JournalLorePage sJournalLore[] =
{
    { .title = NULL },
};

// Research on unknown species. The quest's step holds the tiers as bits (RESEARCH_*).
enum
{
    RESEARCH_TIER_SEEN,
    RESEARCH_TIER_BATTLED,
    RESEARCH_TIER_CAUGHT,
    RESEARCH_TIER_LORE,
    RESEARCH_TIER_COUNT,
};

struct JournalResearch
{
    u16 quest;
    const u8 *name;
    const u8 *notes[RESEARCH_TIER_COUNT];
};

static const u8 *const sResearchTierNames[RESEARCH_TIER_COUNT] =
{
    [RESEARCH_TIER_SEEN] = COMPOUND_STRING("Seen"),
    [RESEARCH_TIER_BATTLED] = COMPOUND_STRING("Battled"),
    [RESEARCH_TIER_CAUGHT] = COMPOUND_STRING("Caught"),
    [RESEARCH_TIER_LORE] = COMPOUND_STRING("Lore"),
};

static const struct JournalResearch sJournalResearch[] =
{
    {
        .quest = QUEST_RESEARCH_POOCHYENA,
        .name = COMPOUND_STRING("Eien Poochyena"),
        .notes = {
            [RESEARCH_TIER_SEEN] = COMPOUND_STRING("Grey, like a stone shrine dog."),
            [RESEARCH_TIER_BATTLED] = COMPOUND_STRING("Rock and Dark!"),
            [RESEARCH_TIER_CAUGHT] = COMPOUND_STRING("Heavier than it looks."),
            [RESEARCH_TIER_LORE] = NULL, // TODO(design): a lore step for Eien Poochyena
        },
    },
};

// Missions. Each is shown once its quest isn't QUEST_STATE_NONE, under the person who gave
// it (or the Eien group). log[i] is shown once the step is above i; with stepIsBits, log[i]
// is shown when bit i of the step is set.
#define JOURNAL_GROUP_EIEN  PERSON_COUNT
#define JOURNAL_LOG_MAX     4

struct JournalMission
{
    u16 quest;
    u8 group;       // PERSON_* or JOURNAL_GROUP_EIEN
    bool8 stepIsBits;
    const u8 *title;
    const u8 *giver;
    const u8 *hint;
    const u8 *log[JOURNAL_LOG_MAX];
    const u8 *closedLine;
};

static const struct JournalMission sJournalMissions[] =
{
    {
        .quest = QUEST_HARU_MAP,
        .group = PERSON_HARU,
        .title = COMPOUND_STRING("Haru's map"),
        .giver = COMPOUND_STRING("Haru"),
        .hint = COMPOUND_STRING("Note the coast, the fields and the shrine on Route 1."),
        .log = {
            COMPOUND_STRING("Noted one place."),
            COMPOUND_STRING("Noted two."),
            COMPOUND_STRING("Noted all three."),
        },
        .closedLine = COMPOUND_STRING("I never finished it."),
    },
    {
        .quest = QUEST_AKIRA_PRACTICE,
        .group = PERSON_AKIRA,
        .title = COMPOUND_STRING("Practice battle"),
        .giver = COMPOUND_STRING("Akira"),
        .hint = COMPOUND_STRING("Meet Akira at the edge of Shimotsuki."),
        .log = {
            COMPOUND_STRING("We battled. He talked about the League."),
        },
        .closedLine = COMPOUND_STRING("I never went back. Now I can't."),
    },
    {
        .quest = QUEST_RESEARCH_POOCHYENA,
        .group = JOURNAL_GROUP_EIEN,
        .stepIsBits = TRUE,
        .title = COMPOUND_STRING("Eien Poochyena"),
        .giver = COMPOUND_STRING("Professor"),
        .hint = COMPOUND_STRING("See, battle and catch one on Route 1."),
        .log = {
            [RESEARCH_TIER_SEEN] = COMPOUND_STRING("Saw one."),
            [RESEARCH_TIER_BATTLED] = COMPOUND_STRING("Battled one."),
            [RESEARCH_TIER_CAUGHT] = COMPOUND_STRING("Caught one."),
        },
        .closedLine = COMPOUND_STRING("She's gone. Too late now."),
    },
};

// The Missions tab's groups, in order. Each person's line changes with relationship points
// at these thresholds. TODO(design): the real thresholds (side-quests.md); these are
// placeholders.
static const u8 sRelationshipThresholds[] = {1, 10, 25};

struct JournalPerson
{
    const u8 *name;
    const u8 *lines[ARRAY_COUNT(sRelationshipThresholds)];
};

static const struct JournalPerson sJournalPeople[PERSON_COUNT + 1] =
{
    // TODO(design): lines for Nami, Yuki, Kaede, Tetsu and Ren when they have scenes.
    [PERSON_NAMI] = { .name = COMPOUND_STRING("Nami") },
    [PERSON_HARU] = {
        .name = COMPOUND_STRING("Haru"),
        .lines = {
            COMPOUND_STRING("Haru's easy to talk to."),
            COMPOUND_STRING("Haru trusts me now."),
            COMPOUND_STRING("Haru's my best friend here."),
        },
    },
    [PERSON_YUKI] = { .name = COMPOUND_STRING("Yuki") },
    [PERSON_KAEDE] = { .name = COMPOUND_STRING("Kaede") },
    [PERSON_TETSU] = { .name = COMPOUND_STRING("Tetsu") },
    [PERSON_REN] = { .name = COMPOUND_STRING("Ren") },
    [PERSON_AKIRA] = {
        .name = COMPOUND_STRING("Akira"),
        .lines = {
            COMPOUND_STRING("Akira talks about the League a lot."),
            COMPOUND_STRING("Akira's a rival. A friendly one."),
            COMPOUND_STRING("Akira and I understand each other."),
        },
    },
    [JOURNAL_GROUP_EIEN] = { .name = COMPOUND_STRING("Eien") },
};
