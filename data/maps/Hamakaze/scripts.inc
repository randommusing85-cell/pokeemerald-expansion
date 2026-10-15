@ Hamakaze (design/locations/hamakaze.md). Act 1 beat 1: he wakes on the beach and Celebi
@ finds him (STORY_ARRIVED).

Hamakaze_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Hamakaze_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Hamakaze_OnFrame
	.byte 0

Hamakaze_OnTransition:
	@ Once Celebi follows him, its map object stays hidden (the follower walks with him)
	call_if_ge VAR_EIEN_STORY, STORY_ARRIVED, Hamakaze_EventScript_HideCelebi
	@ Haru's map quest: he catches up at the north exit once there's a starter (VAR_TEMP_3 arms
	@ the trigger); his object only shows during that scene
	setflag FLAG_TEMP_2
	setvar VAR_TEMP_3, 0
	goto_if_lt VAR_EIEN_STORY, STORY_GOT_STARTER, Hamakaze_EventScript_OnTransitionEnd
	checkquest QUEST_HARU_MAP
	call_if_eq VAR_RESULT, QUEST_STATE_NONE, Hamakaze_EventScript_ArmHaru
Hamakaze_EventScript_OnTransitionEnd:
	end

Hamakaze_EventScript_ArmHaru:
	setvar VAR_TEMP_3, 1
	return

Hamakaze_EventScript_HideCelebi:
	setflag FLAG_TEMP_1
	return

Hamakaze_OnFrame:
	map_script_2 VAR_EIEN_STORY, STORY_PROLOGUE, Hamakaze_EventScript_WakeUp
	.2byte 0

Hamakaze_EventScript_WakeUp::
	lockall
	delay 30
	msgbox Hamakaze_Text_Cold, MSGBOX_DEFAULT
	applymovement LOCALID_HAMAKAZE_CELEBI, Hamakaze_Movement_CelebiApproach
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	playmoncry SPECIES_CELEBI, CRY_MODE_NORMAL
	waitmoncry
	msgbox Hamakaze_Text_ACelebi, MSGBOX_DEFAULT
	@ Every permission except FNPC_WHITE_OUT: Celebi stays with him after a white-out
	setfollowernpc LOCALID_HAMAKAZE_CELEBI, FNPC_ALL_LAND | FNPC_ALL_WATER, EienCelebi_EventScript_Talk
	setvar VAR_EIEN_STORY, STORY_ARRIVED
	msgbox Hamakaze_Text_ItsFollowingMe, MSGBOX_DEFAULT
	releaseall
	end

@ Celebi drifts down beside him, so it can fall in behind once he walks
Hamakaze_Movement_CelebiApproach:
	walk_slow_down
	walk_slow_down
	walk_slow_down
	face_left
	step_end

Hamakaze_EventScript_Fisherman::
	msgbox Hamakaze_Text_Fisherman, MSGBOX_NPC
	end

@ Haru runs up from behind him at the north exit and asks for three notes on Route 1.
Hamakaze_EventScript_HaruMap::
	lockall
	getplayerxy VAR_0x8004, VAR_0x8005
	addvar VAR_0x8005, 3
	setobjectxyperm LOCALID_HAMAKAZE_HARU, VAR_0x8004, VAR_0x8005
	clearflag FLAG_TEMP_2
	addobject LOCALID_HAMAKAZE_HARU
	msgbox Hamakaze_Text_HaruWait, MSGBOX_DEFAULT
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	applymovement LOCALID_HAMAKAZE_HARU, Hamakaze_Movement_HaruUp
	waitmovement 0
	msgbox Hamakaze_Text_HaruMap, MSGBOX_DEFAULT
	setquest QUEST_HARU_MAP, QUEST_STATE_OPEN
	setvar VAR_TEMP_3, 0
	msgbox Hamakaze_Text_HaruThanks, MSGBOX_DEFAULT
	applymovement LOCALID_HAMAKAZE_HARU, Hamakaze_Movement_HaruBack
	waitmovement 0
	removeobject LOCALID_HAMAKAZE_HARU
	setflag FLAG_TEMP_2
	releaseall
	end

@ One step: Celebi follows right behind him, so Haru stops behind Celebi
Hamakaze_Movement_HaruUp:
	walk_up
	step_end

Hamakaze_Movement_HaruBack:
	walk_down
	walk_down
	walk_down
	step_end

Hamakaze_EventScript_Woman::
	goto_if_ge VAR_EIEN_STORY, STORY_TAKEN_IN, Hamakaze_EventScript_WomanLab
	msgbox Hamakaze_Text_WomanKashiwagi, MSGBOX_NPC
	end

Hamakaze_EventScript_WomanLab::
	msgbox Hamakaze_Text_WomanLab, MSGBOX_NPC
	end

@ TODO(design): the scene's exact lines (these are drafts in the style guide's voice).
Hamakaze_Text_Cold:
	.string "(…Cold. Sand, and snow on it.)\p"
	.string "(This isn't my room.)$"

Hamakaze_Text_ACelebi:
	.string "(Is that… a Celebi?)\p"
	.string "(In the games you only ever see one\n"
	.string "at a shrine. If you're lucky.)$"

Hamakaze_Text_ItsFollowingMe:
	.string "(It's following me.)\p"
	.string "(There are houses up the beach.\n"
	.string "Maybe someone there can help.)$"

Hamakaze_Text_HaruWait:
	.string "HARU: Wait up!$"

Hamakaze_Text_HaruMap:
	.string "HARU: I'm drawing a map of Eien.\n"
	.string "For you, since you're new here.\p"
	.string "Can you look at three places on\n"
	.string "Route 1 for me?\p"
	.string "The coast, the snowy fields,\n"
	.string "and the shrine.\p"
	.string "Just write them in your journal.$"

Hamakaze_Text_HaruThanks:
	.string "HARU: Thanks! See you later.$"

Hamakaze_Text_Fisherman:
	.string "Sea's too cold to fish today.\n"
	.string "Nothing's biting.$"

Hamakaze_Text_WomanKashiwagi:
	.string "You're not from Hamakaze.\p"
	.string "The Kashiwagis live in the blue house.\n"
	.string "They'll look after you.$"

Hamakaze_Text_WomanLab:
	.string "The yellow building is Professor\n"
	.string "Kashiwagi's lab.$"
