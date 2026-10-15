@ Route 1 (design/locations/route-1.md). Placeholder layout; redraw it in Porymap any time.
@ VAR_TEMP_1 / VAR_TEMP_2 arm the coast and fields notes for Haru's map (coord events) while
@ his quest is open and that place isn't noted yet.

EienRoute1_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, EienRoute1_OnTransition
	.byte 0

EienRoute1_OnTransition:
	call_if_eq VAR_EIEN_STORY, STORY_GOT_STARTER, EienRoute1_EventScript_SetStory
	setvar VAR_TEMP_1, 0
	setvar VAR_TEMP_2, 0
	checkquest QUEST_HARU_MAP
	goto_if_ne VAR_RESULT, QUEST_STATE_OPEN, EienRoute1_EventScript_OnTransitionEnd
	checkquestbit QUEST_HARU_MAP, HARU_MAP_COAST
	call_if_eq VAR_RESULT, FALSE, EienRoute1_EventScript_ArmCoast
	checkquestbit QUEST_HARU_MAP, HARU_MAP_FIELDS
	call_if_eq VAR_RESULT, FALSE, EienRoute1_EventScript_ArmFields
EienRoute1_EventScript_OnTransitionEnd:
	end

EienRoute1_EventScript_SetStory::
	setvar VAR_EIEN_STORY, STORY_ROUTE_1
	return

EienRoute1_EventScript_ArmCoast::
	setvar VAR_TEMP_1, 1
	return

EienRoute1_EventScript_ArmFields::
	setvar VAR_TEMP_2, 1
	return

EienRoute1_EventScript_NoteCoast::
	lockall
	setquestbit QUEST_HARU_MAP, HARU_MAP_COAST
	setvar VAR_TEMP_1, 0
	msgbox EienRoute1_Text_NoteCoast, MSGBOX_DEFAULT
	releaseall
	end

EienRoute1_EventScript_NoteFields::
	lockall
	setquestbit QUEST_HARU_MAP, HARU_MAP_FIELDS
	setvar VAR_TEMP_2, 0
	msgbox EienRoute1_Text_NoteFields, MSGBOX_DEFAULT
	releaseall
	end

EienRoute1_EventScript_Fisherman::
	trainerbattle_single TRAINER_EIEN_ROUTE1_FISHERMAN, EienRoute1_Text_FishermanIntro, EienRoute1_Text_FishermanDefeat
	msgbox EienRoute1_Text_FishermanAfter, MSGBOX_AUTOCLOSE
	end

EienRoute1_EventScript_Hiker::
	trainerbattle_single TRAINER_EIEN_ROUTE1_HIKER, EienRoute1_Text_HikerIntro, EienRoute1_Text_HikerDefeat
	msgbox EienRoute1_Text_HikerAfter, MSGBOX_AUTOCLOSE
	end

EienRoute1_EventScript_Youngster::
	trainerbattle_single TRAINER_EIEN_ROUTE1_YOUNGSTER, EienRoute1_Text_YoungsterIntro, EienRoute1_Text_YoungsterDefeat
	msgbox EienRoute1_Text_YoungsterAfter, MSGBOX_AUTOCLOSE
	end

EienRoute1_EventScript_SignSouth::
	msgbox EienRoute1_Text_SignSouth, MSGBOX_SIGN
	end

EienRoute1_EventScript_SignShrine::
	msgbox EienRoute1_Text_SignShrine, MSGBOX_SIGN
	end

@ TODO(design): all lines are drafts in the style guide's voice.
EienRoute1_Text_NoteCoast:
	.string "(The coast. I'll note it for Haru.)$"

EienRoute1_Text_NoteFields:
	.string "(Snowy fields. That's two for Haru.)$"

EienRoute1_Text_FishermanIntro:
	.string "The sea's frozen at the edges.\n"
	.string "Might as well battle.$"

EienRoute1_Text_FishermanDefeat:
	.string "Fair enough.$"

EienRoute1_Text_FishermanAfter:
	.string "Fish come back when it warms up.\n"
	.string "If it warms up.$"

EienRoute1_Text_HikerIntro:
	.string "Snow's deep up here.\n"
	.string "Machop and I train in it.$"

EienRoute1_Text_HikerDefeat:
	.string "Ha! Good.$"

EienRoute1_Text_HikerAfter:
	.string "Fighting moves break ice.\n"
	.string "Remember that in Shimotsuki.$"

EienRoute1_Text_YoungsterIntro:
	.string "Rock beats Ice.\n"
	.string "I caught it for Fuyumi.\p"
	.string "You first!$"

EienRoute1_Text_YoungsterDefeat:
	.string "Aw…$"

EienRoute1_Text_YoungsterAfter:
	.string "Fuyumi's still next.\n"
	.string "I just need more practice.$"

EienRoute1_Text_SignSouth:
	.string "ROUTE 1\n"
	.string "South: Hamakaze$"

EienRoute1_Text_SignShrine:
	.string "ROUTE 1\n"
	.string "East: shrine  North: Shimotsuki$"
