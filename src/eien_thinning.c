#include "global.h"
#include "eien_thinning.h"
#include "event_data.h"
#include "event_object_movement.h"
#include "field_weather.h"
#include "follower_npc.h"
#include "overworld.h"
#include "palette.h"
#include "sprite.h"
#include "trig.h"
#include "constants/rgb.h"
#include "constants/event_objects.h"
#include "constants/weather.h"

// The thinning (design/game-bible.md, "The thinning on the map").
//
// Every few frames the weather's normal palettes (time of day included) are rebuilt, then the
// map's palettes and the object palettes are pulled toward their own grey by the drain amount.
// The palettes of the hero, his follower and the kept objects are left alone.
// TODO(design): the grey (an art pass: a cold blue-grey instead of a neutral one?).

#define FRAMES_PER_STEP 2
#define CREEP_STEPS    90 // Colour drains over 90 steps * 2 frames, 3 seconds
#define CLOSE_STEPS    30 // and comes back over 1 second when it closes
#define PULSE_STEPS   120 // One faint pulse: 4 seconds
#define DRAIN_FULL    256
#define DRAIN_PULSE    40 // At the pulse's low point a trace of colour comes back

#define MAX_KEPT_OBJECTS 2

static EWRAM_DATA u16 sStep = 0;
static EWRAM_DATA u8 sStepTimer = 0;
static EWRAM_DATA u16 sDrain = 0;   // 0 (full colour) to DRAIN_FULL (grey)
static EWRAM_DATA u16 sCloseFrom = 0;
static EWRAM_DATA bool8 sClosing = FALSE;
static EWRAM_DATA u8 sKeptLocalIds[MAX_KEPT_OBJECTS] = {0};

bool32 IsThinningActive(void)
{
    return gSaveBlock1Ptr->weather == WEATHER_THINNING;
}

static u16 GreyColor(u16 color, u32 drain)
{
    s32 r = GET_R(color), g = GET_G(color), b = GET_B(color);
    s32 grey = (r * 77 + g * 150 + b * 29) >> 8;

    r += ((grey - r) * (s32)drain) >> 8;
    g += ((grey - g) * (s32)drain) >> 8;
    b += ((grey - b) * (s32)drain) >> 8;
    return RGB2(r, g, b);
}

static void GreyPalettes(u16 *palettes, u32 count, u32 drain)
{
    u32 i;

    for (i = 0; i < count * 16; i++)
        palettes[i] = GreyColor(palettes[i], drain);
}

static u32 GetObjectPaletteBit(u32 objectEventId)
{
    if (objectEventId >= OBJECT_EVENTS_COUNT || !gObjectEvents[objectEventId].active)
        return 0;
    return 1 << (16 + gSprites[gObjectEvents[objectEventId].spriteId].oam.paletteNum);
}

// The map palettes and the object palettes, minus the ones that stay in colour
static u32 GetDrainedPalettes(void)
{
    u32 i, palettes = PALETTES_MAP | PALETTES_OBJECTS;
    u8 objectEventId;

    palettes &= ~GetObjectPaletteBit(gPlayerAvatar.objectEventId);
    if (PlayerHasFollowerNPC())
        palettes &= ~GetObjectPaletteBit(GetFollowerNPCObjectId());
    for (i = 0; i < MAX_KEPT_OBJECTS; i++)
    {
        if (sKeptLocalIds[i] != 0
         && !TryGetObjectEventIdByLocalIdAndMap(sKeptLocalIds[i], gSaveBlock1Ptr->location.mapNum, gSaveBlock1Ptr->location.mapGroup, &objectEventId))
            palettes &= ~GetObjectPaletteBit(objectEventId);
    }
    for (i = 0; i < 16; i++)
    {
        if (IS_BLEND_IMMUNE_TAG(GetSpritePaletteTagByPaletteNum(i)))
            palettes &= ~(1 << (16 + i));
    }
    return palettes;
}

static void GreyDrainedPalettes(void)
{
    u32 i, palettes;

    if (sDrain == 0)
        return;
    palettes = GetDrainedPalettes();
    for (i = 0; i < 32; i++)
    {
        if (palettes & (1 << i))
            GreyPalettes(&gPlttBufferFaded[PLTT_ID(i)], 1, sDrain);
    }
}

static void ApplyThinning(void)
{
    // Don't touch the palettes during a fade (warps, battles, menus) or a weather change
    if (gPaletteFade.active || gWeatherPtr->palProcessingState != WEATHER_PAL_STATE_IDLE)
        return;
    ApplyWeatherColorMapIfIdle(gWeatherPtr->colorMapIndex);
    GreyDrainedPalettes();
}

// Coming back to the map while it's open (after a battle or a menu), the screen fades in from the
// grey palettes, not the normal ones: each step rebuilds them (time of day included), drains
// them, then blends toward the fade colour, like the vanilla fog and drought fade-ins.
bool8 FadeInScreen_Thinning(void)
{
    if (gWeatherPtr->fadeScreenCounter == 16)
        return FALSE;
    gWeatherPtr->fadeScreenCounter++;
    CpuFastCopy(gPlttBufferUnfaded, gPlttBufferFaded, PLTT_BUFFER_SIZE * 2);
    UpdateAltBgPalettes(PALETTES_BG);
    UpdatePalettesWithTime(PALETTES_ALL);
    GreyDrainedPalettes();
    if (gWeatherPtr->fadeScreenCounter < 16)
    {
        BlendPalettesFine(PALETTES_ALL, gPlttBufferFaded, gPlttBufferFaded, 16 - gWeatherPtr->fadeScreenCounter, gWeatherPtr->fadeDestColor);
        return TRUE;
    }
    return FALSE;
}

// Eased from 0 to 256 over `steps` (half a cosine wave)
static u32 Ease(u32 step, u32 steps)
{
    return (256 - Cos(step * 128 / steps, 256)) / 2;
}

static void UpdateDrain(void)
{
    if (sClosing)
    {
        sDrain = sCloseFrom - sCloseFrom * Ease(min(sStep, CLOSE_STEPS), CLOSE_STEPS) / 256;
    }
    else if (sStep < CREEP_STEPS)
    {
        sDrain = DRAIN_FULL * Ease(sStep, CREEP_STEPS) / 256;
    }
    else
    {
        // Grey, with a faint trace of colour coming and going
        u32 pulse = (sStep - CREEP_STEPS) % PULSE_STEPS;
        sDrain = DRAIN_FULL - DRAIN_PULSE * (256 - Cos(pulse * 256 / PULSE_STEPS, 256)) / 512;
    }
}

void Thinning_InitVars(void)
{
    gWeatherPtr->initStep = 0;
    gWeatherPtr->targetColorMapIndex = 0;
    gWeatherPtr->colorMapStepDelay = 20;
    Weather_SetBlendCoeffs(8, BASE_SHADOW_INTENSITY);
    gWeatherPtr->noShadows = FALSE;
    sStep = 0;
    sStepTimer = 0;
    sDrain = 0;
    sClosing = FALSE;
}

// Coming back to a map where it's open (after a battle or a menu): already grey, no creep
void Thinning_InitAll(void)
{
    Thinning_InitVars();
    sStep = CREEP_STEPS;
    UpdateDrain();
    ApplyThinning();
}

void Thinning_Main(void)
{
    if (++sStepTimer < FRAMES_PER_STEP)
        return;
    sStepTimer = 0;
    if (++sStep >= CREEP_STEPS + PULSE_STEPS * 100)
        sStep = CREEP_STEPS; // Keep pulsing
    UpdateDrain();
    ApplyThinning();
}

// The colour comes back over a second, then the next weather starts
bool8 Thinning_Finish(void)
{
    if (!sClosing)
    {
        sClosing = TRUE;
        sCloseFrom = sDrain;
        sStep = 0;
        sStepTimer = 0;
        memset(sKeptLocalIds, 0, sizeof(sKeptLocalIds));
    }
    if (++sStepTimer >= FRAMES_PER_STEP)
    {
        sStepTimer = 0;
        sStep++;
        UpdateDrain();
        ApplyThinning();
    }
    if (sStep < CLOSE_STEPS)
        return TRUE;
    sDrain = 0;
    ApplyThinning();
    return FALSE;
}

// special KeepObjectInColourInThinning: VAR_0x8004 is the local ID of an object (Yuki, a
// partner) that stays in colour with the hero. Up to two; cleared when the thinning closes.
void KeepObjectInColourInThinning(void)
{
    u32 i;

    for (i = 0; i < MAX_KEPT_OBJECTS; i++)
    {
        if (sKeptLocalIds[i] == 0 || sKeptLocalIds[i] == gSpecialVar_0x8004)
        {
            sKeptLocalIds[i] = gSpecialVar_0x8004;
            return;
        }
    }
}

// The battle background's palettes (BG palettes 2-4) go grey while it's open
void TintBattleBackgroundForThinning(void)
{
    if (!IsThinningActive())
        return;
    GreyPalettes(&gPlttBufferUnfaded[BG_PLTT_ID(2)], 3, DRAIN_FULL);
    CpuCopy16(&gPlttBufferUnfaded[BG_PLTT_ID(2)], &gPlttBufferFaded[BG_PLTT_ID(2)], 3 * PLTT_SIZE_4BPP);
}
