#include "global.h"
#include "battle.h"
#include "battle_setup.h"
#include "follower_npc.h"
#include "task.h"
#include "constants/battle_partner.h"
#include "test/test.h"

// Eien: a follower NPC with a battle partner joins scripted wild double battles too, not only
// random encounters (Kaede's aurora night, design/characters.md).

static void SetFollowerPartner(u32 partner)
{
    SetFollowerNPCData(FNPC_DATA_IN_PROGRESS, partner != PARTNER_NONE);
    SetFollowerNPCData(FNPC_DATA_BATTLE_PARTNER, partner);
}

TEST("(Eien follower NPC) a scripted wild double battle includes the follower partner")
{
    u32 partner;

    PARAMETRIZE { partner = PARTNER_NONE; }
    PARAMETRIZE { partner = PARTNER_STEVEN; }

    SetFollowerPartner(partner);
    BattleSetup_StartScriptedDoubleWildBattle();
    ResetTasks();
    SetFollowerPartner(PARTNER_NONE);

    EXPECT(gBattleTypeFlags & BATTLE_TYPE_DOUBLE);
    if (partner == PARTNER_NONE)
        EXPECT(!(gBattleTypeFlags & (BATTLE_TYPE_MULTI | BATTLE_TYPE_INGAME_PARTNER)));
    else
        EXPECT((gBattleTypeFlags & (BATTLE_TYPE_MULTI | BATTLE_TYPE_INGAME_PARTNER)) == (BATTLE_TYPE_MULTI | BATTLE_TYPE_INGAME_PARTNER));
}
