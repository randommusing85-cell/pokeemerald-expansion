@ Hamakaze (design/locations/hamakaze.md). Act 1 beat 1: he wakes on the beach and Celebi
@ finds him (STORY_ARRIVED).

Hamakaze_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Hamakaze_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Hamakaze_OnFrame
	.byte 0

Hamakaze_OnTransition:
	@ Once Celebi follows him, its map object stays hidden (the follower walks with him)
	call_if_ge VAR_EIEN_STORY, STORY_ARRIVED, Hamakaze_EventScript_HideCelebi
	end

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
	setfollowernpc LOCALID_HAMAKAZE_CELEBI, FNPC_ALL, EienCelebi_EventScript_Talk
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
