#include "global.h"
#include "eien_places.h"
#include "constants/maps.h"

// Thin places: every shrine area (a shrine's grounds, on its own map) and the door mountain.
// Every battle on these maps starts with the thin-place effect (STATUS_FIELD_THIN_PLACE).
// Add each map here once it exists in Porymap.
static const u16 sThinPlaceMaps[] =
{
    // TODO: the Route 1 shrine, Kaede's shrine in Shimotsuki, the door mountain.
    MAP_UNDEFINED,
};

bool32 IsThinPlaceMap(u32 mapGroup, u32 mapNum)
{
    u32 map = mapNum | (mapGroup << 8);

    for (u32 i = 0; i < ARRAY_COUNT(sThinPlaceMaps); i++)
    {
        if (sThinPlaceMaps[i] != MAP_UNDEFINED && sThinPlaceMaps[i] == map)
            return TRUE;
    }
    return FALSE;
}

bool32 IsCurrentMapThinPlace(void)
{
    return IsThinPlaceMap(gSaveBlock1Ptr->location.mapGroup, gSaveBlock1Ptr->location.mapNum);
}
