@ Yunotaki, the hot-spring town of gym 2 (design/locations/yunotaki.md). Vanilla Lavaridge Town's
@ layout, copied with a south entrance for Route 2 and a short waterfall by the gym. Route 2's
@ upper map doesn't exist yet, so the south entrance has no connection.
@ FLAG_TEMP_1 hides Ren until the badge; VAR_TEMP_1 = 1 runs his scene once (FLAG_MET_REN_YUNOTAKI).

Yunotaki_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Yunotaki_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Yunotaki_OnFrame
	.byte 0

Yunotaki_OnTransition:
	setflag FLAG_TEMP_1
	setvar VAR_TEMP_1, 0
	goto_if_unset FLAG_BADGE02_GET, Yunotaki_OnTransitionEnd
	goto_if_set FLAG_MET_REN_YUNOTAKI, Yunotaki_OnTransitionEnd
	clearflag FLAG_TEMP_1
	setvar VAR_TEMP_1, 1
Yunotaki_OnTransitionEnd:
	end

Yunotaki_OnFrame:
	map_script_2 VAR_TEMP_1, 1, Yunotaki_EventScript_Ren
	.2byte 0

@ Ren's cameo (side-quests.md): he arrives as the hero leaves the gym with the badge, says
@ "Next.", and walks in to challenge Ibuki officially. No battle.
Yunotaki_EventScript_Ren::
	lockall
	setvar VAR_TEMP_1, 0
	applymovement LOCALID_YUNOTAKI_REN, Yunotaki_Movement_RenApproach
	waitmovement 0
	msgbox Yunotaki_Text_RenNext, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Yunotaki_Movement_PlayerStepAside
	waitmovement 0
	applymovement LOCALID_YUNOTAKI_REN, Yunotaki_Movement_RenEnterGym
	waitmovement 0
	playse SE_EXIT
	removeobject LOCALID_YUNOTAKI_REN
	setflag FLAG_MET_REN_YUNOTAKI
	releaseall
	end

Yunotaki_Movement_RenApproach:
	walk_up
	walk_in_place_faster_up
	step_end

Yunotaki_Movement_PlayerStepAside:
	walk_right
	face_left
	step_end

Yunotaki_Movement_RenEnterGym:
	walk_up
	walk_up
	set_invisible
	step_end

@ Akira blocks the gym door until he's battled (yunotaki.md): he just lost to Ibuki and wants a
@ warm-up. One trainer entry per starter he took (VAR_EIEN_AKIRA_STARTER).
Yunotaki_EventScript_Akira::
	lock
	faceplayer
	goto_if_eq VAR_EIEN_AKIRA_STARTER, SPECIES_TORCHIC_EIEN, Yunotaki_EventScript_AkiraTorchic
	goto_if_eq VAR_EIEN_AKIRA_STARTER, SPECIES_BULBASAUR_EIEN, Yunotaki_EventScript_AkiraBulbasaur
	trainerbattle_single TRAINER_EIEN_AKIRA_YUNOTAKI_FROAKIE, Yunotaki_Text_AkiraIntro, Yunotaki_Text_AkiraDefeat, Yunotaki_EventScript_AkiraDone
	goto Yunotaki_EventScript_AkiraDone

Yunotaki_EventScript_AkiraTorchic::
	trainerbattle_single TRAINER_EIEN_AKIRA_YUNOTAKI_TORCHIC, Yunotaki_Text_AkiraIntro, Yunotaki_Text_AkiraDefeat, Yunotaki_EventScript_AkiraDone
	goto Yunotaki_EventScript_AkiraDone

Yunotaki_EventScript_AkiraBulbasaur::
	trainerbattle_single TRAINER_EIEN_AKIRA_YUNOTAKI_BULBASAUR, Yunotaki_Text_AkiraIntro, Yunotaki_Text_AkiraDefeat, Yunotaki_EventScript_AkiraDone
	goto Yunotaki_EventScript_AkiraDone

Yunotaki_EventScript_AkiraDone::
	msgbox Yunotaki_Text_AkiraAfter, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_YUNOTAKI_AKIRA, Yunotaki_Movement_AkiraLeave
	waitmovement 0
	removeobject LOCALID_YUNOTAKI_AKIRA
	setflag FLAG_BEAT_AKIRA_YUNOTAKI
	release
	end

Yunotaki_Movement_AkiraLeave:
	walk_left
	walk_down
	walk_down
	walk_down
	step_end

@ Ibuki under the falls before the badge; he's also in the gym.
Yunotaki_EventScript_IbukiFalls::
	msgbox Yunotaki_Text_IbukiFalls, MSGBOX_NPC
	end

@ The outdoor bath heals the team (yunotaki.md: a second heal spot).
Yunotaki_EventScript_BathAttendant::
	lock
	faceplayer
	msgbox Yunotaki_Text_SitSoak, MSGBOX_DEFAULT
	closemessage
	call Common_EventScript_OutOfCenterPartyHeal
	msgbox Yunotaki_Text_Better, MSGBOX_DEFAULT
	release
	end

@ Three rumours about why Ibuki left the League; nobody agrees (yunotaki.md).
Yunotaki_EventScript_GossipBath::
	msgbox Yunotaki_Text_GossipInjury, MSGBOX_NPC
	end

Yunotaki_EventScript_GossipKid::
	msgbox Yunotaki_Text_GossipSawSomething, MSGBOX_NPC
	end

Yunotaki_EventScript_RoadEast::
	msgbox Yunotaki_Text_RoadEast, MSGBOX_NPC
	end

Yunotaki_EventScript_TownSign::
	msgbox Yunotaki_Text_TownSign, MSGBOX_SIGN
	end

Yunotaki_EventScript_GymSign::
	msgbox Yunotaki_Text_GymSign, MSGBOX_SIGN
	end

Yunotaki_EventScript_HerbShopSign::
	msgbox Yunotaki_Text_HerbShopSign, MSGBOX_SIGN
	end

Yunotaki_EventScript_InnSign::
	msgbox Yunotaki_Text_InnSign, MSGBOX_SIGN
	end

@ TODO(design): all lines are drafts. Ren's "Next." and the bath's "Sit. Soak." are decided
@ (brainstorm-yunotaki.md); so is the road east's line.
Yunotaki_Text_RenNext:
	.string "(A trainer in a League jacket.\n"
	.string "He nods once.)\p"
	.string "Next.$"

Yunotaki_Text_AkiraIntro:
	.string "AKIRA: {PLAYER}! I just lost\n"
	.string "to Ibuki.\p"
	.string "I need a warm-up before I go\n"
	.string "back in. You'll do.$"

Yunotaki_Text_AkiraDefeat:
	.string "Okay. I'm warm.$"

Yunotaki_Text_AkiraAfter:
	.string "AKIRA: Watch his Medicham.\n"
	.string "It doesn't miss.\p"
	.string "Go on. I'll try again later.$"

Yunotaki_Text_IbukiFalls:
	.string "IBUKI: …\p"
	.string "The gym's open. Go in.$"

Yunotaki_Text_SitSoak:
	.string "Sit. Soak.$"

Yunotaki_Text_Better:
	.string "Better.$"

Yunotaki_Text_GossipInjury:
	.string "Ibuki? Came home with a bad\n"
	.string "shoulder. That's why he quit.\p"
	.string "That's what I heard, anyway.$"

Yunotaki_Text_GossipSawSomething:
	.string "My dad says Ibuki saw something\n"
	.string "at the League.\p"
	.string "He won't say what.$"

Yunotaki_Text_RoadEast:
	.string "The road east is shut\n"
	.string "for the thaw.$"

Yunotaki_Text_TownSign:
	.string "YUNOTAKI\n"
	.string "Hot water from the falls.$"

Yunotaki_Text_GymSign:
	.string "YUNOTAKI POKéMON GYM\n"
	.string "LEADER: IBUKI$"

Yunotaki_Text_HerbShopSign:
	.string "HERB SHOP\n"
	.string "Bitter medicine. Works.$"

Yunotaki_Text_InnSign:
	.string "YUNOTAKI INN\n"
	.string "Rooms and baths.$"
