// The hero's journal (design/game-bible.md, Mechanics; design/brainstorm-journal-screen.md).
//
// An open notebook: the left page lists entries, the right page shows the selected one,
// bookmark tabs on the right edge switch between Story, Research and Missions. Opened from
// the start menu in place of the PokéNav. The art is a placeholder drawn at runtime (solid
// paper, ruled lines, a spine and tabs); final art can replace it without changing the rest.
//
// Controls: Up/Down move, Left/Right or L/R switch tabs, B closes.

#include "global.h"
#include "eien_journal.h"
#include "eien_quests.h"
#include "bg.h"
#include "event_data.h"
#include "gpu_regs.h"
#include "line_break.h"
#include "main.h"
#include "malloc.h"
#include "menu.h"
#include "overworld.h"
#include "palette.h"
#include "scanline_effect.h"
#include "sound.h"
#include "sprite.h"
#include "string_util.h"
#include "task.h"
#include "text.h"
#include "window.h"
#include "constants/eien_story.h"
#include "constants/rgb.h"
#include "constants/songs.h"

#include "data/eien_journal.h"

enum
{
    TAB_STORY,
    TAB_RESEARCH,
    TAB_MISSIONS,
    TAB_COUNT,
};

enum
{
    ROW_COVER,
    ROW_NEXT,
    ROW_STORY,
    ROW_LORE,
    ROW_RESEARCH,
    ROW_GROUP,
    ROW_MISSION,
    ROW_EMPTY,
};

enum
{
    WIN_LEFT,
    WIN_RIGHT,
    WIN_TABS,
    WIN_COUNT,
};

// Text colors (BG palette 15): {background, foreground, shadow}.
enum
{
    COLOR_INK,
    COLOR_GREY,
    COLOR_RED,
    COLOR_BLUE,
};

// Background tiles (BG1), drawn at runtime.
enum
{
    TILE_DESK,
    TILE_PAPER,
    TILE_PAPER_RULED,
    TILE_SPINE,
    TILE_TAB_STORY,
    TILE_TAB_RESEARCH,
    TILE_TAB_MISSIONS,
    TILE_COUNT,
};

#define MAX_ROWS        48
#define LIST_ROWS       7    // rows below the page header
#define ROW_HEIGHT      16
#define LIST_TOP        18
#define PAGE_TOP        1    // tile rows of the pages
#define PAGE_HEIGHT     18
#define LEFT_PAGE_X     1
#define LEFT_PAGE_W     13
#define SPINE_X         14
#define RIGHT_PAGE_X    15
#define RIGHT_PAGE_W    12
#define TABS_X          27
#define TAB_TOP(tab)    (2 + (tab) * 5)
#define TAB_HEIGHT      4
#define TEXT_BUFFER     600

struct JournalRow
{
    u8 kind;
    u8 color;
    bool8 indent;
    bool8 showNew;
    u16 index;
    const u8 *text;
};

struct JournalState
{
    u8 tab;
    u8 cursor;
    u8 scroll;
    u8 rowCount;
    struct JournalRow rows[MAX_ROWS];
    u8 text[TEXT_BUFFER];
    u8 wrapped[TEXT_BUFFER];
};

static EWRAM_DATA struct JournalState *sJournal = NULL;
static EWRAM_DATA u16 *sBgTilemap = NULL;
static EWRAM_DATA u8 sLastTab = TAB_STORY;

static void Task_JournalFadeIn(u8 taskId);
static void Task_JournalInput(u8 taskId);
static void Task_JournalFadeOut(u8 taskId);

static const u8 sText_Tabs[TAB_COUNT][2] = { _("S"), _("R"), _("M") };
static const u8 *const sTabNames[TAB_COUNT] =
{
    [TAB_STORY] = COMPOUND_STRING("Story"),
    [TAB_RESEARCH] = COMPOUND_STRING("Research"),
    [TAB_MISSIONS] = COMPOUND_STRING("Missions"),
};
static const u8 sText_WhatsNext[] = _("What's next");
static const u8 sText_Lore[] = _("Lore");
static const u8 sText_NothingYet[] = _("Nothing yet.");
static const u8 sText_Unknown[] = _("???");
static const u8 sText_New[] = _(" new");
static const u8 sText_Open[] = _("Open");
static const u8 sText_Done[] = _("Done");
static const u8 sText_Closed[] = _("Closed");
static const u8 sText_TierUnknown[] = _(": ?");
static const u8 sText_ColonSpace[] = _(": ");
static const u8 sText_EienGroup[] = _("Things I'm looking into around Eien.");
static const u8 sText_LetterWaiting[] = _("A letter came. They want to see me.");
static const u8 sText_NoLineYet[] = _("We've only just met.");

static const u8 sTextColors[][3] =
{
    [COLOR_INK] = {0, 1, 2},
    [COLOR_GREY] = {0, 3, 4},
    [COLOR_RED] = {0, 5, 6},
    [COLOR_BLUE] = {0, 7, 8},
};

static const u16 sTextPalette[16] =
{
    RGB(0, 0, 0),
    RGB(5, 5, 8),    RGB(24, 23, 19),   // ink
    RGB(15, 15, 15), RGB(25, 24, 20),   // grey
    RGB(22, 5, 5),   RGB(29, 21, 18),   // red
    RGB(4, 8, 20),   RGB(21, 23, 28),   // blue
};

static const u16 sBgPalette[16] =
{
    RGB(6, 5, 5),     // desk
    RGB(30, 29, 25),  // paper
    RGB(21, 24, 29),  // ruled line
    RGB(17, 12, 8),   // spine
    RGB(28, 18, 10),  // story tab
    RGB(14, 22, 14),  // research tab
    RGB(14, 18, 28),  // missions tab
};

#define ROW_OF(c) ((c) * 0x11111111)
static const u32 sBgTiles[TILE_COUNT][8] =
{
    [TILE_DESK] = {0},
    [TILE_PAPER] = {ROW_OF(1), ROW_OF(1), ROW_OF(1), ROW_OF(1), ROW_OF(1), ROW_OF(1), ROW_OF(1), ROW_OF(1)},
    [TILE_PAPER_RULED] = {ROW_OF(1), ROW_OF(1), ROW_OF(1), ROW_OF(1), ROW_OF(1), ROW_OF(1), ROW_OF(1), ROW_OF(2)},
    [TILE_SPINE] = {ROW_OF(3), ROW_OF(3), ROW_OF(3), ROW_OF(3), ROW_OF(3), ROW_OF(3), ROW_OF(3), ROW_OF(3)},
    [TILE_TAB_STORY] = {ROW_OF(4), ROW_OF(4), ROW_OF(4), ROW_OF(4), ROW_OF(4), ROW_OF(4), ROW_OF(4), ROW_OF(4)},
    [TILE_TAB_RESEARCH] = {ROW_OF(5), ROW_OF(5), ROW_OF(5), ROW_OF(5), ROW_OF(5), ROW_OF(5), ROW_OF(5), ROW_OF(5)},
    [TILE_TAB_MISSIONS] = {ROW_OF(6), ROW_OF(6), ROW_OF(6), ROW_OF(6), ROW_OF(6), ROW_OF(6), ROW_OF(6), ROW_OF(6)},
};
#undef ROW_OF

static const struct BgTemplate sBgTemplates[] =
{
    {
        .bg = 0,
        .charBaseIndex = 0,
        .mapBaseIndex = 31,
        .priority = 0,
    },
    {
        .bg = 1,
        .charBaseIndex = 2,
        .mapBaseIndex = 30,
        .priority = 1,
    },
};

static const struct WindowTemplate sWindowTemplates[] =
{
    [WIN_LEFT] = {
        .bg = 0,
        .tilemapLeft = LEFT_PAGE_X,
        .tilemapTop = PAGE_TOP,
        .width = LEFT_PAGE_W,
        .height = PAGE_HEIGHT,
        .paletteNum = 15,
        .baseBlock = 1,
    },
    [WIN_RIGHT] = {
        .bg = 0,
        .tilemapLeft = RIGHT_PAGE_X,
        .tilemapTop = PAGE_TOP,
        .width = RIGHT_PAGE_W,
        .height = PAGE_HEIGHT,
        .paletteNum = 15,
        .baseBlock = 1 + LEFT_PAGE_W * PAGE_HEIGHT,
    },
    [WIN_TABS] = {
        .bg = 0,
        .tilemapLeft = TABS_X,
        .tilemapTop = PAGE_TOP,
        .width = 3,
        .height = PAGE_HEIGHT,
        .paletteNum = 15,
        .baseBlock = 1 + (LEFT_PAGE_W + RIGHT_PAGE_W) * PAGE_HEIGHT,
    },
    DUMMY_WIN_TEMPLATE
};

// ---- Rows -----------------------------------------------------------------

static void AddRow(u8 kind, u16 index, const u8 *text, u8 color, bool8 indent, bool8 showNew)
{
    struct JournalRow *row;

    if (sJournal->rowCount >= MAX_ROWS)
        return;
    row = &sJournal->rows[sJournal->rowCount++];
    row->kind = kind;
    row->index = index;
    row->text = text;
    row->color = color;
    row->indent = indent;
    row->showNew = showNew;
}

static s32 GetLatestStoryEntry(void)
{
    s32 i, latest = -1;

    for (i = 0; i < (s32)ARRAY_COUNT(sJournalStory); i++)
    {
        if (sJournalStory[i].beat <= VarGet(VAR_EIEN_STORY))
            latest = i;
    }
    return latest;
}

static bool32 IsLorePageVisible(u32 i)
{
    return GetQuestState(sJournalLore[i].quest) != QUEST_STATE_NONE
        && GetQuestStep(sJournalLore[i].quest) >= sJournalLore[i].minStep;
}

static bool32 IsGroupVisible(u32 group)
{
    u32 i;

    if (group < PERSON_COUNT && HasLetterFrom(group))
        return TRUE;
    for (i = 0; i < ARRAY_COUNT(sJournalMissions); i++)
    {
        if (sJournalMissions[i].group == group && GetQuestState(sJournalMissions[i].quest) != QUEST_STATE_NONE)
            return TRUE;
    }
    return FALSE;
}

static void BuildRows(void)
{
    u32 i, group;
    bool32 anyLore = FALSE;

    sJournal->rowCount = 0;
    switch (sJournal->tab)
    {
    case TAB_STORY:
        AddRow(ROW_COVER, 0, sJournalCoverTitle, COLOR_INK, FALSE, FALSE);
        if (GetLatestStoryEntry() >= 0)
            AddRow(ROW_NEXT, 0, sText_WhatsNext, COLOR_BLUE, FALSE, FALSE);
        for (i = 0; i < ARRAY_COUNT(sJournalStory); i++)
        {
            if (sJournalStory[i].beat <= VarGet(VAR_EIEN_STORY))
                AddRow(ROW_STORY, i, sJournalStory[i].title, COLOR_INK, FALSE, FALSE);
        }
        for (i = 0; sJournalLore[i].title != NULL; i++)
        {
            if (!IsLorePageVisible(i))
                continue;
            if (!anyLore)
                AddRow(ROW_EMPTY, 0, sText_Lore, COLOR_BLUE, FALSE, FALSE);
            anyLore = TRUE;
            AddRow(ROW_LORE, i, sJournalLore[i].title, COLOR_INK, TRUE, FALSE);
        }
        break;
    case TAB_RESEARCH:
        for (i = 0; i < ARRAY_COUNT(sJournalResearch); i++)
        {
            u32 quest = sJournalResearch[i].quest;

            if (GetQuestState(quest) == QUEST_STATE_NONE)
                continue;
            if (GetQuestStep(quest) & (1 << RESEARCH_TIER_SEEN))
                AddRow(ROW_RESEARCH, i, sJournalResearch[i].name, COLOR_INK, FALSE, FALSE);
            else
                AddRow(ROW_RESEARCH, i, sText_Unknown, COLOR_INK, FALSE, FALSE);
        }
        break;
    case TAB_MISSIONS:
        for (group = 0; group <= JOURNAL_GROUP_EIEN; group++)
        {
            if (!IsGroupVisible(group))
                continue;
            AddRow(ROW_GROUP, group, sJournalPeople[group].name, COLOR_BLUE, FALSE,
                   group < PERSON_COUNT && HasLetterFrom(group));
            for (i = 0; i < ARRAY_COUNT(sJournalMissions); i++)
            {
                u32 state = GetQuestState(sJournalMissions[i].quest);

                if (sJournalMissions[i].group != group || state == QUEST_STATE_NONE)
                    continue;
                AddRow(ROW_MISSION, i, sJournalMissions[i].title,
                       state == QUEST_STATE_CLOSED ? COLOR_GREY : COLOR_INK, TRUE, FALSE);
            }
        }
        break;
    }
    if (sJournal->rowCount == 0)
        AddRow(ROW_EMPTY, 0, sText_NothingYet, COLOR_GREY, FALSE, FALSE);
}

// ---- Drawing --------------------------------------------------------------

static void DrawBackground(void)
{
    u32 y, tab;

    FillBgTilemapBufferRect(1, TILE_DESK, 0, 0, 32, 32, 0);
    for (y = PAGE_TOP; y < PAGE_TOP + PAGE_HEIGHT; y++)
    {
        u32 tile = (y % 2 == 0) ? TILE_PAPER_RULED : TILE_PAPER;

        FillBgTilemapBufferRect(1, tile, LEFT_PAGE_X, y, LEFT_PAGE_W, 1, 0);
        FillBgTilemapBufferRect(1, tile, RIGHT_PAGE_X, y, RIGHT_PAGE_W, 1, 0);
    }
    FillBgTilemapBufferRect(1, TILE_SPINE, SPINE_X, PAGE_TOP, 1, PAGE_HEIGHT, 0);
    for (tab = 0; tab < TAB_COUNT; tab++)
    {
        // The open tab sticks out further.
        u32 width = (tab == sJournal->tab) ? 3 : 2;

        FillBgTilemapBufferRect(1, TILE_TAB_STORY + tab, TABS_X, TAB_TOP(tab), width, TAB_HEIGHT, 0);
    }
    CopyBgTilemapBufferToVram(1);
}

static void DrawTabs(void)
{
    u32 tab;

    FillWindowPixelBuffer(WIN_TABS, PIXEL_FILL(0));
    for (tab = 0; tab < TAB_COUNT; tab++)
    {
        u32 y = (TAB_TOP(tab) - PAGE_TOP) * 8 + 9;

        AddTextPrinterParameterized3(WIN_TABS, FONT_NORMAL, 4, y, sTextColors[COLOR_INK], TEXT_SKIP_DRAW, sText_Tabs[tab]);
    }
    CopyWindowToVram(WIN_TABS, COPYWIN_FULL);
}

static void DrawList(void)
{
    u32 i;

    FillWindowPixelBuffer(WIN_LEFT, PIXEL_FILL(0));
    AddTextPrinterParameterized3(WIN_LEFT, FONT_NORMAL, 4, 2, sTextColors[COLOR_BLUE], TEXT_SKIP_DRAW, sTabNames[sJournal->tab]);
    for (i = 0; i < LIST_ROWS && sJournal->scroll + i < sJournal->rowCount; i++)
    {
        u32 index = sJournal->scroll + i;
        struct JournalRow *row = &sJournal->rows[index];
        u32 x = row->indent ? 12 : 4;
        u32 y = LIST_TOP + i * ROW_HEIGHT;
        u32 color = (index == sJournal->cursor && row->kind != ROW_EMPTY) ? COLOR_RED : row->color;

        AddTextPrinterParameterized3(WIN_LEFT, FONT_NORMAL, x, y, sTextColors[color], TEXT_SKIP_DRAW, row->text);
        if (row->showNew)
            AddTextPrinterParameterized3(WIN_LEFT, FONT_NORMAL, x + GetStringWidth(FONT_NORMAL, row->text, 0), y,
                                         sTextColors[COLOR_RED], TEXT_SKIP_DRAW, sText_New);
    }
    CopyWindowToVram(WIN_LEFT, COPYWIN_FULL);
}

// Prints text wrapped to the right page from y; returns the y below it.
static u32 PrintParagraph(u32 y, const u8 *text, u32 color)
{
    StringExpandPlaceholders(sJournal->wrapped, text);
    BreakStringNaive(sJournal->wrapped, RIGHT_PAGE_W * 8 - 8, 16, FONT_NORMAL, HIDE_SCROLL_PROMPT);
    AddTextPrinterParameterized4(WIN_RIGHT, FONT_NORMAL, 4, y, 0, 0, sTextColors[color], TEXT_SKIP_DRAW, sJournal->wrapped);
    return y + (CountLineBreaks(sJournal->wrapped) + 1) * ROW_HEIGHT;
}

static void PrintTitle(const u8 *title)
{
    AddTextPrinterParameterized3(WIN_RIGHT, FONT_NORMAL, 4, 2, sTextColors[COLOR_BLUE], TEXT_SKIP_DRAW, title);
}

static const u8 *GetPersonLine(u32 person)
{
    u32 points = GetRelationshipPoints(person);
    s32 tier;

    for (tier = ARRAY_COUNT(sRelationshipThresholds) - 1; tier >= 0; tier--)
    {
        if (points >= sRelationshipThresholds[tier] && sJournalPeople[person].lines[tier] != NULL)
            return sJournalPeople[person].lines[tier];
    }
    return sText_NoLineYet;
}

static void DrawResearchDetail(u32 i)
{
    const struct JournalResearch *research = &sJournalResearch[i];
    u32 step = GetQuestStep(research->quest);
    u32 tier, y = LIST_TOP;

    PrintTitle((step & (1 << RESEARCH_TIER_SEEN)) ? research->name : sText_Unknown);
    for (tier = 0; tier < RESEARCH_TIER_COUNT; tier++)
    {
        if (research->notes[tier] == NULL)
            continue;
        if (step & (1 << tier))
        {
            StringCopy(sJournal->text, sResearchTierNames[tier]);
            StringAppend(sJournal->text, sText_ColonSpace);
            StringAppend(sJournal->text, research->notes[tier]);
            y = PrintParagraph(y, sJournal->text, COLOR_INK);
        }
        else
        {
            StringCopy(sJournal->text, sResearchTierNames[tier]);
            StringAppend(sJournal->text, sText_TierUnknown);
            y = PrintParagraph(y, sJournal->text, COLOR_GREY);
        }
    }
}

static void DrawMissionDetail(u32 i)
{
    const struct JournalMission *mission = &sJournalMissions[i];
    u32 state = GetQuestState(mission->quest);
    u32 step = GetQuestStep(mission->quest);
    u32 line, y = LIST_TOP;

    const u8 *stateText;

    PrintTitle(mission->title);
    // Who gave it on the left, its state on the right.
    if (state == QUEST_STATE_CLOSED)
        stateText = sText_Closed;
    else
        stateText = (state == QUEST_STATE_DONE) ? sText_Done : sText_Open;
    AddTextPrinterParameterized3(WIN_RIGHT, FONT_NORMAL, 4, y, sTextColors[COLOR_GREY], TEXT_SKIP_DRAW, mission->giver);
    AddTextPrinterParameterized3(WIN_RIGHT, FONT_NORMAL, RIGHT_PAGE_W * 8 - 4 - GetStringWidth(FONT_NORMAL, stateText, 0), y,
                                 sTextColors[state == QUEST_STATE_CLOSED ? COLOR_GREY : COLOR_RED], TEXT_SKIP_DRAW, stateText);
    y += ROW_HEIGHT;
    if (state == QUEST_STATE_OPEN)
        y = PrintParagraph(y, mission->hint, COLOR_INK);
    for (line = 0; line < JOURNAL_LOG_MAX; line++)
    {
        bool32 reached = mission->stepIsBits ? (step & (1 << line)) : (step > line);

        if (mission->log[line] != NULL && reached)
            y = PrintParagraph(y, mission->log[line], COLOR_INK);
    }
    if (state == QUEST_STATE_CLOSED && mission->closedLine != NULL)
        PrintParagraph(y, mission->closedLine, COLOR_GREY);
}

static void DrawDetail(void)
{
    struct JournalRow *row = &sJournal->rows[sJournal->cursor];
    s32 latest;

    FillWindowPixelBuffer(WIN_RIGHT, PIXEL_FILL(0));
    switch (row->kind)
    {
    case ROW_COVER:
        PrintTitle(sJournalCoverTitle);
        PrintParagraph(LIST_TOP, sJournalCoverText, COLOR_INK);
        break;
    case ROW_NEXT:
        latest = GetLatestStoryEntry();
        PrintTitle(sText_WhatsNext);
        if (latest >= 0)
            PrintParagraph(LIST_TOP, sJournalStory[latest].next, COLOR_INK);
        break;
    case ROW_STORY:
        PrintTitle(sJournalStory[row->index].title);
        PrintParagraph(LIST_TOP, sJournalStory[row->index].text, COLOR_INK);
        break;
    case ROW_LORE:
        PrintTitle(sJournalLore[row->index].title);
        PrintParagraph(LIST_TOP, sJournalLore[row->index].text, COLOR_INK);
        break;
    case ROW_RESEARCH:
        DrawResearchDetail(row->index);
        break;
    case ROW_GROUP:
        PrintTitle(sJournalPeople[row->index].name);
        if (row->index == JOURNAL_GROUP_EIEN)
        {
            PrintParagraph(LIST_TOP, sText_EienGroup, COLOR_INK);
        }
        else
        {
            u32 y = PrintParagraph(LIST_TOP, GetPersonLine(row->index), COLOR_INK);

            if (HasLetterFrom(row->index))
            {
                // Reading the group reads the letter.
                PrintParagraph(y, sText_LetterWaiting, COLOR_RED);
                SetLetterFrom(row->index, FALSE);
                row->showNew = FALSE;
            }
        }
        break;
    case ROW_MISSION:
        DrawMissionDetail(row->index);
        break;
    }
    CopyWindowToVram(WIN_RIGHT, COPYWIN_FULL);
}

static void SetTab(u32 tab)
{
    sJournal->tab = tab;
    sLastTab = tab;
    BuildRows();
    sJournal->scroll = 0;
    // The Story tab opens on "What's next".
    sJournal->cursor = (tab == TAB_STORY && sJournal->rowCount > 1) ? 1 : 0;
    DrawBackground();
    DrawList();
    DrawDetail();
}

// ---- Setup and main loop --------------------------------------------------

static void MainCB2(void)
{
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    UpdatePaletteFade();
}

static void VBlankCB(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

void CB2_OpenJournal(void)
{
    switch (gMain.state)
    {
    case 0:
        SetVBlankCallback(NULL);
        DmaClearLarge16(3, (void *)(VRAM), VRAM_SIZE, 0x1000);
        DmaClear32(3, OAM, OAM_SIZE);
        DmaClear16(3, PLTT, PLTT_SIZE);
        SetGpuReg(REG_OFFSET_DISPCNT, 0);
        ResetBgsAndClearDma3BusyFlags(0);
        InitBgsFromTemplates(0, sBgTemplates, ARRAY_COUNT(sBgTemplates));
        for (u32 bg = 0; bg < 4; bg++)
        {
            // The field leaves its scroll behind.
            ChangeBgX(bg, 0, BG_COORD_SET);
            ChangeBgY(bg, 0, BG_COORD_SET);
        }
        sBgTilemap = AllocZeroed(BG_SCREEN_SIZE);
        SetBgTilemapBuffer(1, sBgTilemap);
        InitWindows(sWindowTemplates);
        DeactivateAllTextPrinters();
        ResetPaletteFade();
        ScanlineEffect_Stop();
        ResetTasks();
        ResetSpriteData();
        gMain.state++;
        break;
    case 1:
        LoadBgTiles(1, sBgTiles, sizeof(sBgTiles), 0);
        LoadPalette(sBgPalette, BG_PLTT_ID(0), sizeof(sBgPalette));
        LoadPalette(sTextPalette, BG_PLTT_ID(15), sizeof(sTextPalette));
        gMain.state++;
        break;
    case 2:
        sJournal = AllocZeroed(sizeof(*sJournal));
        PutWindowTilemap(WIN_LEFT);
        PutWindowTilemap(WIN_RIGHT);
        PutWindowTilemap(WIN_TABS);
        if (!FlagGet(FLAG_JOURNAL_COVER_SEEN))
        {
            // The first time, it opens on the first page he wrote.
            FlagSet(FLAG_JOURNAL_COVER_SEEN);
            SetTab(TAB_STORY);
            sJournal->cursor = 0;
            DrawList();
            DrawDetail();
        }
        else
        {
            SetTab(sLastTab < TAB_COUNT ? sLastTab : TAB_STORY);
        }
        DrawTabs();
        CopyBgTilemapBufferToVram(0);
        gMain.state++;
        break;
    case 3:
        SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_OBJ_ON | DISPCNT_OBJ_1D_MAP);
        ShowBg(0);
        ShowBg(1);
        CreateTask(Task_JournalFadeIn, 0);
        BeginNormalPaletteFade(PALETTES_ALL, 0, 16, 0, RGB_BLACK);
        SetVBlankCallback(VBlankCB);
        SetMainCallback2(MainCB2);
        break;
    }
}

static void Task_JournalFadeIn(u8 taskId)
{
    if (!gPaletteFade.active)
        gTasks[taskId].func = Task_JournalInput;
}

static void MoveCursor(s32 delta)
{
    s32 cursor = sJournal->cursor + delta;

    if (cursor < 0 || cursor >= sJournal->rowCount)
        return;
    PlaySE(SE_SELECT);
    sJournal->cursor = cursor;
    if (sJournal->cursor < sJournal->scroll)
        sJournal->scroll = sJournal->cursor;
    else if (sJournal->cursor >= sJournal->scroll + LIST_ROWS)
        sJournal->scroll = sJournal->cursor - LIST_ROWS + 1;
    DrawList();
    DrawDetail();
}

static void Task_JournalInput(u8 taskId)
{
    if (JOY_NEW(B_BUTTON))
    {
        PlaySE(SE_SELECT);
        BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
        gTasks[taskId].func = Task_JournalFadeOut;
    }
    else if (JOY_REPEAT(DPAD_UP))
    {
        MoveCursor(-1);
    }
    else if (JOY_REPEAT(DPAD_DOWN))
    {
        MoveCursor(1);
    }
    else if (JOY_NEW(DPAD_LEFT | L_BUTTON))
    {
        PlaySE(SE_SELECT);
        SetTab((sJournal->tab + TAB_COUNT - 1) % TAB_COUNT);
    }
    else if (JOY_NEW(DPAD_RIGHT | R_BUTTON))
    {
        PlaySE(SE_SELECT);
        SetTab((sJournal->tab + 1) % TAB_COUNT);
    }
}

static void Task_JournalFadeOut(u8 taskId)
{
    if (gPaletteFade.active)
        return;
    DestroyTask(taskId);
    FreeAllWindowBuffers();
    UnsetBgTilemapBuffer(1);
    TRY_FREE_AND_SET_NULL(sBgTilemap);
    TRY_FREE_AND_SET_NULL(sJournal);
    SetMainCallback2(CB2_ReturnToFieldWithOpenMenu);
}
