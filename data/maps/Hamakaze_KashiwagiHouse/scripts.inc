@ The Kashiwagi house (design/locations/hamakaze.md). Act 1 beat 2: the family takes him in,
@ Haru becomes his first friend, he starts the journal (STORY_TAKEN_IN, FLAG_RECEIVED_JOURNAL).
@ After that the professor is at her lab (FLAG_TEMP_1) and Haru is too until the starters are
@ picked (FLAG_TEMP_2).

Hamakaze_KashiwagiHouse_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Hamakaze_KashiwagiHouse_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Hamakaze_KashiwagiHouse_OnFrame
	.byte 0

Hamakaze_KashiwagiHouse_OnTransition:
	call_if_ge VAR_EIEN_STORY, STORY_TAKEN_IN, Hamakaze_KashiwagiHouse_EventScript_HideProfessor
	call_if_eq VAR_EIEN_STORY, STORY_TAKEN_IN, Hamakaze_KashiwagiHouse_EventScript_HideHaru
	end

Hamakaze_KashiwagiHouse_EventScript_HideProfessor:
	setflag FLAG_TEMP_1
	return

Hamakaze_KashiwagiHouse_EventScript_HideHaru:
	setflag FLAG_TEMP_2
	return

Hamakaze_KashiwagiHouse_OnFrame:
	map_script_2 VAR_EIEN_STORY, STORY_ARRIVED, Hamakaze_KashiwagiHouse_EventScript_TakenIn
	.2byte 0

Hamakaze_KashiwagiHouse_EventScript_TakenIn::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, Hamakaze_KashiwagiHouse_Movement_PlayerEnter
	waitmovement 0
	applymovement LOCALID_KASHIWAGI_HOUSE_PROFESSOR, Common_Movement_FaceRight
	waitmovement 0
	msgbox Hamakaze_KashiwagiHouse_Text_HalfFrozen, MSGBOX_DEFAULT
	applymovement LOCALID_KASHIWAGI_HOUSE_HUSBAND, Common_Movement_FaceRight
	waitmovement 0
	msgbox Hamakaze_KashiwagiHouse_Text_WhereFrom, MSGBOX_DEFAULT
	msgbox Hamakaze_KashiwagiHouse_Text_CantSay, MSGBOX_DEFAULT
	msgbox Hamakaze_KashiwagiHouse_Text_StayWithUs, MSGBOX_DEFAULT
	msgbox Hamakaze_KashiwagiHouse_Text_IntroduceFamily, MSGBOX_DEFAULT
	applymovement LOCALID_KASHIWAGI_HOUSE_HARU, Common_Movement_FaceRight
	waitmovement 0
	msgbox Hamakaze_KashiwagiHouse_Text_Haru, MSGBOX_DEFAULT
	msgbox Hamakaze_KashiwagiHouse_Text_Notebook, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_ITEM
	message Hamakaze_KashiwagiHouse_Text_GotNotebook
	waitfanfare
	waitmessage
	setflag FLAG_RECEIVED_JOURNAL
	msgbox Hamakaze_KashiwagiHouse_Text_FirstPage, MSGBOX_DEFAULT
	msgbox Hamakaze_KashiwagiHouse_Text_JournalInMenu, MSGBOX_DEFAULT
	msgbox Hamakaze_KashiwagiHouse_Text_ComeToLab, MSGBOX_DEFAULT
	setvar VAR_EIEN_STORY, STORY_TAKEN_IN
	releaseall
	end

Hamakaze_KashiwagiHouse_Movement_PlayerEnter:
	walk_up
	walk_up
	walk_left
	face_left
	step_end

Hamakaze_KashiwagiHouse_EventScript_Professor::
	msgbox Hamakaze_KashiwagiHouse_Text_ComeToLab, MSGBOX_NPC
	end

Hamakaze_KashiwagiHouse_EventScript_Husband::
	msgbox Hamakaze_KashiwagiHouse_Text_MakeYourselfAtHome, MSGBOX_NPC
	end

Hamakaze_KashiwagiHouse_EventScript_Haru::
	goto_if_ge VAR_EIEN_STORY, STORY_GOT_STARTER, Hamakaze_KashiwagiHouse_EventScript_HaruAfterStarter
	msgbox Hamakaze_KashiwagiHouse_Text_Haru, MSGBOX_NPC
	end

Hamakaze_KashiwagiHouse_EventScript_HaruAfterStarter::
	msgbox Hamakaze_KashiwagiHouse_Text_HaruAfterStarter, MSGBOX_NPC
	end

@ TODO(design): the scene's exact lines (drafts in the style guide's voice), who gives him
@ the notebook (here: the professor), and the husband's name.
Hamakaze_KashiwagiHouse_Text_HalfFrozen:
	.string "PROFESSOR: You're half frozen.\n"
	.string "Come in, sit by the stove.$"

Hamakaze_KashiwagiHouse_Text_WhereFrom:
	.string "HUSBAND: On the beach, in this cold?\n"
	.string "Where are you from?$"

Hamakaze_KashiwagiHouse_Text_CantSay:
	.string "(From another world.\n"
	.string "I can't say that.)$"

Hamakaze_KashiwagiHouse_Text_StayWithUs:
	.string "HUSBAND: …Never mind. You can stay\n"
	.string "with us until you're on your feet.$"

Hamakaze_KashiwagiHouse_Text_IntroduceFamily:
	.string "PROFESSOR: I'm Professor Kashiwagi.\n"
	.string "I study Pokémon here.\p"
	.string "This is my husband.\n"
	.string "And that's our son, Haru.$"

Hamakaze_KashiwagiHouse_Text_Haru:
	.string "HARU: Hi! I'm Haru.\n"
	.string "I'll show you around town.$"

Hamakaze_KashiwagiHouse_Text_Notebook:
	.string "PROFESSOR: Here, a notebook.\n"
	.string "Write down whatever you remember.$"

Hamakaze_KashiwagiHouse_Text_GotNotebook:
	.string "{PLAYER} got a notebook.$"

Hamakaze_KashiwagiHouse_Text_FirstPage:
	.string "(I'll start with what I'm sure of.)\p"
	.string "My name is {PLAYER}.\n"
	.string "I'm from another world.\l"
	.string "If I start forgetting, read this.$"

Hamakaze_KashiwagiHouse_Text_JournalInMenu:
	.string "(The journal is in the START menu.)$"

Hamakaze_KashiwagiHouse_Text_ComeToLab:
	.string "PROFESSOR: When you're warm, come to\n"
	.string "my lab. The yellow building.\p"
	.string "I have something for you.$"

Hamakaze_KashiwagiHouse_Text_MakeYourselfAtHome:
	.string "HUSBAND: Make yourself at home.$"

Hamakaze_KashiwagiHouse_Text_HaruAfterStarter:
	.string "HARU: Mine's still shy.\n"
	.string "Yours already looks tough.$"
