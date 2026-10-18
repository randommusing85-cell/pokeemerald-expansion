@ The lake path north of Shimotsuki (design/locations/shimotsuki.md); "Route 2" is a placeholder
@ name. Act 1 beat 6: Nami. After gym 1 (STORY_BADGE_1), VAR_TEMP_1 arms the coord events on
@ row 16, just short of the lake. Celebi flickers and drops; Nami arrives on Lapras and takes him
@ across. The far shore is a warp onto this same map, so VAR_EIEN_SCENE = 1 carries the scene
@ over it: FLAG_TEMP_1 hides the first Nami and Lapras, FLAG_TEMP_2 the pair on the far shore.

EienRoute2_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, EienRoute2_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, EienRoute2_OnFrame
	.byte 0

EienRoute2_OnTransition:
	setflag FLAG_TEMP_1
	setflag FLAG_TEMP_2
	setvar VAR_TEMP_1, 0
	call_if_eq VAR_EIEN_STORY, STORY_BADGE_1, EienRoute2_EventScript_ArmNami
	call_if_eq VAR_EIEN_SCENE, 1, EienRoute2_EventScript_ShowFarShore
	end

EienRoute2_EventScript_ArmNami::
	setvar VAR_TEMP_1, 1
	return

EienRoute2_EventScript_ShowFarShore::
	clearflag FLAG_TEMP_2
	return

EienRoute2_OnFrame:
	map_script_2 VAR_EIEN_SCENE, 1, EienRoute2_EventScript_FarShore
	.2byte 0

EienRoute2_EventScript_Nami::
	lockall
	setvar VAR_TEMP_1, 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	msgbox EienRoute2_Text_Lake, MSGBOX_DEFAULT
	applymovement OBJ_EVENT_ID_NPC_FOLLOWER, EienRoute2_Movement_Flicker
	waitmovement 0
	msgbox EienRoute2_Text_CelebiFading, MSGBOX_DEFAULT
	applymovement OBJ_EVENT_ID_NPC_FOLLOWER, EienRoute2_Movement_Drop
	waitmovement 0
	msgbox EienRoute2_Text_CelebiGone, MSGBOX_DEFAULT
	@ Lapras swims in; Nami hops off onto the shore
	addobject LOCALID_EIEN_ROUTE2_LAPRAS
	playmoncry SPECIES_LAPRAS, CRY_MODE_NORMAL
	applymovement LOCALID_EIEN_ROUTE2_LAPRAS, EienRoute2_Movement_LaprasSwimsIn
	waitmovement 0
	waitmoncry
	addobject LOCALID_EIEN_ROUTE2_NAMI
	applymovement LOCALID_EIEN_ROUTE2_NAMI, EienRoute2_Movement_NamiHopsOff
	waitmovement 0
	msgbox EienRoute2_Text_NamiGetOn, MSGBOX_DEFAULT
	setvar VAR_EIEN_SCENE, 1
	warp MAP_EIEN_ROUTE2, 9, 5
	waitstate
	releaseall
	end

EienRoute2_Movement_Flicker:
	set_invisible
	delay_8
	set_visible
	delay_8
	set_invisible
	delay_4
	set_visible
	delay_16
	set_invisible
	delay_4
	set_visible
	step_end

EienRoute2_Movement_Drop:
	set_invisible
	step_end

EienRoute2_Movement_LaprasSwimsIn:
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

EienRoute2_Movement_NamiHopsOff:
	jump_down
	step_end

@ The far shore by the shelter. Celebi recovers; Nami says a little and leaves.
EienRoute2_EventScript_FarShore::
	lockall
	setvar VAR_EIEN_SCENE, 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
	waitmovement 0
	delay 30
	applymovement OBJ_EVENT_ID_NPC_FOLLOWER, EienRoute2_Movement_CelebiRecovers
	waitmovement 0
	playmoncry SPECIES_CELEBI, CRY_MODE_NORMAL
	waitmoncry
	msgbox EienRoute2_Text_CelebiBack, MSGBOX_DEFAULT
	msgbox EienRoute2_Text_NamiName, MSGBOX_DEFAULT
	applymovement LOCALID_EIEN_ROUTE2_NAMI_SHORE, EienRoute2_Movement_NamiLeaves
	waitmovement 0
	removeobject LOCALID_EIEN_ROUTE2_NAMI_SHORE
	removeobject LOCALID_EIEN_ROUTE2_LAPRAS_SHORE
	setvar VAR_EIEN_STORY, STORY_MET_NAMI
	msgbox EienRoute2_Text_MilestoneEnd, MSGBOX_DEFAULT
	releaseall
	end

@ The follower arrives on his tile after the warp; Celebi drifts out beside him
EienRoute2_Movement_CelebiRecovers:
	set_visible
	walk_slow_left
	face_right
	step_end

EienRoute2_Movement_NamiLeaves:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

EienRoute2_EventScript_Sign::
	msgbox EienRoute2_Text_Sign, MSGBOX_SIGN
	end

@ Nami's "It's cold. Get on." is decided (brainstorm-shimotsuki.md); the rest are drafts
@ (TODO(design)), including the end-of-milestone message.
EienRoute2_Text_Lake:
	.string "(The lake's frozen at the edges.\n"
	.string "The middle's black water.)$"

EienRoute2_Text_CelebiFading:
	.string "(Celebi? It's flickering.\n"
	.string "Like it's fading out.)$"

EienRoute2_Text_CelebiGone:
	.string "(Celebi!)$"

EienRoute2_Text_NamiGetOn:
	.string "It's cold. Get on.$"

EienRoute2_Text_CelebiBack:
	.string "(Celebi's back.\n"
	.string "It looks okay now.)$"

EienRoute2_Text_NamiName:
	.string "I'm NAMI.\p"
	.string "I'm heading the same way as you.\n"
	.string "Maybe we'll run into each other.\p"
	.string "Keep that Celebi warm.$"

EienRoute2_Text_MilestoneEnd:
	.string "That's the end of the first part.\n"
	.string "Thanks for playing!$"

EienRoute2_Text_Sign:
	.string "(The sign's buried in snow.)$"
