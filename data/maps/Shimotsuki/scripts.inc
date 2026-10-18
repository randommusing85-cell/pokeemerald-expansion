@ Shimotsuki (design/locations/shimotsuki.md). Placeholder layout; redraw it in Porymap any time.
@ Akira has three objects, one per story state, shown by temp flags: FLAG_TEMP_1 at the south
@ entrance (arriving, STORY_ROUTE_1; the scene walks him to the gym), FLAG_TEMP_2 by the gym door
@ (STORY_SHIMOTSUKI) and FLAG_TEMP_3 at the north edge (after gym 1, until his practice battle).

Shimotsuki_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Shimotsuki_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Shimotsuki_OnFrame
	.byte 0

Shimotsuki_OnTransition:
	setflag FLAG_TEMP_1
	setflag FLAG_TEMP_2
	setflag FLAG_TEMP_3
	call_if_eq VAR_EIEN_STORY, STORY_ROUTE_1, Shimotsuki_EventScript_ShowAkiraEntrance
	call_if_eq VAR_EIEN_STORY, STORY_SHIMOTSUKI, Shimotsuki_EventScript_ShowAkiraGym
	goto_if_lt VAR_EIEN_STORY, STORY_BADGE_1, Shimotsuki_EventScript_OnTransitionEnd
	checkquest QUEST_AKIRA_PRACTICE
	call_if_ne VAR_RESULT, QUEST_STATE_DONE, Shimotsuki_EventScript_ShowAkiraNorth
Shimotsuki_EventScript_OnTransitionEnd:
	end

Shimotsuki_EventScript_ShowAkiraEntrance::
	clearflag FLAG_TEMP_1
	return

Shimotsuki_EventScript_ShowAkiraGym::
	clearflag FLAG_TEMP_2
	return

Shimotsuki_EventScript_ShowAkiraNorth::
	clearflag FLAG_TEMP_3
	return

Shimotsuki_OnFrame:
	map_script_2 VAR_EIEN_STORY, STORY_ROUTE_1, Shimotsuki_EventScript_AkiraShowsGym
	.2byte 0

@ Act 1 beat 5. He arrives on (12,25) from Route 1; Akira meets him and walks him to the gym,
@ pointing out the Pokémon Center on the way.
Shimotsuki_EventScript_AkiraShowsGym::
	lockall
	applymovement LOCALID_SHIMOTSUKI_AKIRA, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_SHIMOTSUKI_AKIRA, Shimotsuki_Movement_AkiraMeets
	waitmovement 0
	msgbox Shimotsuki_Text_AkiraWelcome, MSGBOX_DEFAULT
	applymovement LOCALID_SHIMOTSUKI_AKIRA, Shimotsuki_Movement_UpToCenter
	applymovement OBJ_EVENT_ID_PLAYER, Shimotsuki_Movement_UpToCenter
	waitmovement 0
	applymovement LOCALID_SHIMOTSUKI_AKIRA, Common_Movement_FaceLeft
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
	waitmovement 0
	msgbox Shimotsuki_Text_AkiraCenter, MSGBOX_DEFAULT
	applymovement LOCALID_SHIMOTSUKI_AKIRA, Shimotsuki_Movement_AkiraToGym
	applymovement OBJ_EVENT_ID_PLAYER, Shimotsuki_Movement_PlayerToGym
	waitmovement 0
	msgbox Shimotsuki_Text_AkiraGym, MSGBOX_DEFAULT
	setvar VAR_EIEN_STORY, STORY_SHIMOTSUKI
	releaseall
	end

Shimotsuki_Movement_AkiraMeets:
	walk_down
	walk_down
	step_end

@ Akira from (12,24), the player from (12,25): up to the Pokémon Center's row
Shimotsuki_Movement_UpToCenter:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

@ Akira ends beside the gym door at (13,8), the player in front of the gym at (12,9)
Shimotsuki_Movement_AkiraToGym:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	face_left
	step_end

Shimotsuki_Movement_PlayerToGym:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	face_up
	step_end

Shimotsuki_EventScript_Akira::
	msgbox Shimotsuki_Text_AkiraGoodLuck, MSGBOX_NPC
	end

@ Akira's step 1 (side-quests.md): a practice battle after gym 1, only if you talk to him. His
@ team is the starter he took in the lab (VAR_EIEN_AKIRA_STARTER).
Shimotsuki_EventScript_AkiraPractice::
	lock
	faceplayer
	checkquest QUEST_AKIRA_PRACTICE
	goto_if_eq VAR_RESULT, QUEST_STATE_DONE, Shimotsuki_EventScript_AkiraLeague
	setquest QUEST_AKIRA_PRACTICE, QUEST_STATE_OPEN
	goto_if_eq VAR_EIEN_AKIRA_STARTER, SPECIES_TORCHIC_EIEN, Shimotsuki_EventScript_AkiraPracticeTorchic
	goto_if_eq VAR_EIEN_AKIRA_STARTER, SPECIES_BULBASAUR_EIEN, Shimotsuki_EventScript_AkiraPracticeBulbasaur
	trainerbattle_single TRAINER_EIEN_AKIRA_PRACTICE_FROAKIE, Shimotsuki_Text_AkiraPracticeIntro, Shimotsuki_Text_AkiraPracticeDefeat, Shimotsuki_EventScript_AkiraPracticeDone
	goto Shimotsuki_EventScript_AkiraPracticeDone

Shimotsuki_EventScript_AkiraPracticeTorchic::
	trainerbattle_single TRAINER_EIEN_AKIRA_PRACTICE_TORCHIC, Shimotsuki_Text_AkiraPracticeIntro, Shimotsuki_Text_AkiraPracticeDefeat, Shimotsuki_EventScript_AkiraPracticeDone
	goto Shimotsuki_EventScript_AkiraPracticeDone

Shimotsuki_EventScript_AkiraPracticeBulbasaur::
	trainerbattle_single TRAINER_EIEN_AKIRA_PRACTICE_BULBASAUR, Shimotsuki_Text_AkiraPracticeIntro, Shimotsuki_Text_AkiraPracticeDefeat, Shimotsuki_EventScript_AkiraPracticeDone
	goto Shimotsuki_EventScript_AkiraPracticeDone

Shimotsuki_EventScript_AkiraPracticeDone::
	setquest QUEST_AKIRA_PRACTICE, QUEST_STATE_DONE
Shimotsuki_EventScript_AkiraLeague::
	msgbox Shimotsuki_Text_AkiraLeague, MSGBOX_DEFAULT
	release
	end

Shimotsuki_EventScript_Shoveller::
	msgbox Shimotsuki_Text_Shoveller, MSGBOX_NPC
	end

Shimotsuki_EventScript_Kid::
	msgbox Shimotsuki_Text_Kid, MSGBOX_NPC
	end

Shimotsuki_EventScript_OldWoman::
	msgbox Shimotsuki_Text_OldWoman, MSGBOX_NPC
	end

Shimotsuki_EventScript_TownSign::
	msgbox Shimotsuki_Text_TownSign, MSGBOX_SIGN
	end

Shimotsuki_EventScript_ShutDoor::
	msgbox Shimotsuki_Text_ShutDoor, MSGBOX_SIGN
	end

@ TODO(design): all lines are drafts in the style guide's voice, except the stew line
@ (decided in brainstorm-shimotsuki.md).
Shimotsuki_Text_AkiraWelcome:
	.string "AKIRA: You made it!\n"
	.string "This is Shimotsuki.\p"
	.string "Come on. I'll show you\n"
	.string "my mum's gym.$"

Shimotsuki_Text_AkiraCenter:
	.string "AKIRA: That's the Pokémon Center.\n"
	.string "Heal up there before you go in.$"

Shimotsuki_Text_AkiraGym:
	.string "AKIRA: This is it.\p"
	.string "My mum's the leader.\n"
	.string "She uses Ice types.\p"
	.string "She won't go easy on you.\n"
	.string "She never goes easy on me.$"

Shimotsuki_Text_AkiraGoodLuck:
	.string "AKIRA: Good luck in there.\n"
	.string "I'll be cheering. Quietly.$"

Shimotsuki_Text_AkiraPracticeIntro:
	.string "AKIRA: You got the badge!\p"
	.string "One battle before you go?\n"
	.string "Just practice.$"

Shimotsuki_Text_AkiraPracticeDefeat:
	.string "Okay, okay. You're good.$"

Shimotsuki_Text_AkiraLeague:
	.string "AKIRA: Mum and I watch the League\n"
	.string "matches every year.\p"
	.string "One day it'll be me on there.\n"
	.string "Maybe you too.$"

Shimotsuki_Text_Shoveller:
	.string "Shovel it in the morning, and by\n"
	.string "night it's back. Every day.$"

Shimotsuki_Text_Kid:
	.string "The gym leader's really scary.\p"
	.string "She makes the best stew in\n"
	.string "town, though.$"

Shimotsuki_Text_OldWoman:
	.string "Cold today. Cold every day.\p"
	.string "The shrine's east, past the trees,\n"
	.string "if you want to pay your respects.$"

Shimotsuki_Text_TownSign:
	.string "SHIMOTSUKI\n"
	.string "Route 1 to the south.$"

Shimotsuki_Text_ShutDoor:
	.string "The door's shut.$"
