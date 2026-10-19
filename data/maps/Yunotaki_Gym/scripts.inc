@ Yunotaki Gym (design/locations/yunotaki.md). Gym 2, Ibuki (Fighting). Reuses Dewford's gym
@ layout: dark at first, the light grows as he beats the two pilgrims, and comes on fully when
@ Ibuki is beaten (like clarity under the falls).

Yunotaki_Gym_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Yunotaki_Gym_OnTransition
	.byte 0

Yunotaki_Gym_OnTransition:
	call Yunotaki_Gym_EventScript_SetFlashLevel
	end

@ VAR_0x8000 = how many of the two pilgrims are beaten
Yunotaki_Gym_EventScript_CountTrainersDefeated::
	setvar VAR_0x8000, 0
	goto_if_not_defeated TRAINER_EIEN_YUNOTAKI_GYM_DAICHI, Yunotaki_Gym_EventScript_CheckShizuka
	addvar VAR_0x8000, 1
Yunotaki_Gym_EventScript_CheckShizuka::
	goto_if_not_defeated TRAINER_EIEN_YUNOTAKI_GYM_SHIZUKA, Yunotaki_Gym_EventScript_CountDone
	addvar VAR_0x8000, 1
Yunotaki_Gym_EventScript_CountDone::
	return

Yunotaki_Gym_EventScript_SetFlashLevel::
	goto_if_defeated TRAINER_EIEN_IBUKI, Yunotaki_Gym_EventScript_LightsOn
	call Yunotaki_Gym_EventScript_CountTrainersDefeated
	goto_if_eq VAR_0x8000, 0, Yunotaki_Gym_EventScript_Flash6
	goto_if_eq VAR_0x8000, 1, Yunotaki_Gym_EventScript_Flash4
	setflashlevel 2
	return

Yunotaki_Gym_EventScript_Flash6::
	setflashlevel 6
	return

Yunotaki_Gym_EventScript_Flash4::
	setflashlevel 4
	return

Yunotaki_Gym_EventScript_LightsOn::
	setflashlevel 0
	return

@ After a pilgrim is beaten: brighten to the new level
Yunotaki_Gym_EventScript_BrightenRoom::
	call Yunotaki_Gym_EventScript_CountTrainersDefeated
	playse SE_SWITCH
	goto_if_eq VAR_0x8000, 1, Yunotaki_Gym_EventScript_Animate4
	animateflash 2
	call Yunotaki_Gym_EventScript_SetFlashLevel
	return

Yunotaki_Gym_EventScript_Animate4::
	animateflash 4
	call Yunotaki_Gym_EventScript_SetFlashLevel
	return

Yunotaki_Gym_EventScript_Ibuki::
	trainerbattle_single TRAINER_EIEN_IBUKI, Yunotaki_Gym_Text_IbukiIntro, Yunotaki_Gym_Text_IbukiDefeat, Yunotaki_Gym_EventScript_IbukiDefeated, NO_MUSIC
	goto_if_unset FLAG_RECEIVED_TM_BRICK_BREAK_EIEN, Yunotaki_Gym_EventScript_GiveBrickBreak
	msgbox Yunotaki_Gym_Text_IbukiPostBattle, MSGBOX_DEFAULT
	release
	end

Yunotaki_Gym_EventScript_IbukiDefeated::
	playse SE_SWITCH
	animateflash 0
	call Yunotaki_Gym_EventScript_SetFlashLevel
	message Yunotaki_Gym_Text_ReceivedBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	setflag FLAG_BADGE02_GET
	msgbox Yunotaki_Gym_Text_TakeThis, MSGBOX_DEFAULT
	goto Yunotaki_Gym_EventScript_GiveBrickBreak
	end

@ If the bag is full, talking to him again retries the TM.
Yunotaki_Gym_EventScript_GiveBrickBreak::
	giveitem ITEM_TM31
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_TM_BRICK_BREAK_EIEN
	msgbox Yunotaki_Gym_Text_ExplainBrickBreak, MSGBOX_DEFAULT
	release
	end

Yunotaki_Gym_EventScript_Daichi::
	trainerbattle_single TRAINER_EIEN_YUNOTAKI_GYM_DAICHI, Yunotaki_Gym_Text_DaichiIntro, Yunotaki_Gym_Text_DaichiDefeat, Yunotaki_Gym_EventScript_DaichiBrighten
	msgbox Yunotaki_Gym_Text_DaichiAfter, MSGBOX_AUTOCLOSE
	end

Yunotaki_Gym_EventScript_DaichiBrighten::
	call Yunotaki_Gym_EventScript_BrightenRoom
	release
	end

Yunotaki_Gym_EventScript_Shizuka::
	trainerbattle_single TRAINER_EIEN_YUNOTAKI_GYM_SHIZUKA, Yunotaki_Gym_Text_ShizukaIntro, Yunotaki_Gym_Text_ShizukaDefeat, Yunotaki_Gym_EventScript_ShizukaBrighten
	msgbox Yunotaki_Gym_Text_ShizukaAfter, MSGBOX_AUTOCLOSE
	end

Yunotaki_Gym_EventScript_ShizukaBrighten::
	call Yunotaki_Gym_EventScript_BrightenRoom
	release
	end

@ The guide is a retired pilgrim who trained under Ibuki (yunotaki.md).
Yunotaki_Gym_EventScript_GymGuide::
	lock
	faceplayer
	goto_if_set FLAG_BADGE02_GET, Yunotaki_Gym_EventScript_GymGuideAfter
	msgbox Yunotaki_Gym_Text_GymGuide, MSGBOX_DEFAULT
	release
	end

Yunotaki_Gym_EventScript_GymGuideAfter::
	msgbox Yunotaki_Gym_Text_GymGuideAfter, MSGBOX_DEFAULT
	release
	end

Yunotaki_Gym_EventScript_Statue::
	lockall
	goto_if_set FLAG_BADGE02_GET, Yunotaki_Gym_EventScript_StatueAfter
	msgbox Yunotaki_Gym_Text_Statue, MSGBOX_DEFAULT
	releaseall
	end

Yunotaki_Gym_EventScript_StatueAfter::
	msgbox Yunotaki_Gym_Text_StatueAfter, MSGBOX_DEFAULT
	releaseall
	end

@ TODO(design): all lines are drafts. Ibuki's "The League likes its stories tidy." is the
@ decided losing line (brainstorm-gym-2.md, r2 5a); the badge is the Misogi Badge.
Yunotaki_Gym_Text_IbukiIntro:
	.string "IBUKI: You found your way in\n"
	.string "the dark.\p"
	.string "Good. Breathe. Then show me.$"

Yunotaki_Gym_Text_IbukiDefeat:
	.string "…Clean. No wasted moves.\p"
	.string "The League would make a story\n"
	.string "out of you.\p"
	.string "The League likes its stories\n"
	.string "tidy.$"

Yunotaki_Gym_Text_ReceivedBadge:
	.string "{PLAYER} received the\n"
	.string "MISOGI BADGE from IBUKI.$"

Yunotaki_Gym_Text_TakeThis:
	.string "IBUKI: This too.$"

Yunotaki_Gym_Text_ExplainBrickBreak:
	.string "IBUKI: Brick Break. It goes\n"
	.string "through walls like Reflect.\p"
	.string "Hit what's in front of you.$"

Yunotaki_Gym_Text_IbukiPostBattle:
	.string "IBUKI: Go on. I've got\n"
	.string "the falls to get back to.$"

Yunotaki_Gym_Text_DaichiIntro:
	.string "I climbed all the way up here\n"
	.string "to learn from Ibuki.\p"
	.string "You're my first lesson!$"

Yunotaki_Gym_Text_DaichiDefeat:
	.string "Lesson learned.$"

Yunotaki_Gym_Text_DaichiAfter:
	.string "Breathe out when you strike.\n"
	.string "That's what he tells us.$"

Yunotaki_Gym_Text_ShizukaIntro:
	.string "Quiet. I'm meditating.\p"
	.string "…Fine. One battle.$"

Yunotaki_Gym_Text_ShizukaDefeat:
	.string "My focus slipped.$"

Yunotaki_Gym_Text_ShizukaAfter:
	.string "His Medicham never loses\n"
	.string "its focus. Not once.$"

Yunotaki_Gym_Text_GymGuide:
	.string "I trained under Ibuki, years\n"
	.string "ago. Still come by.\p"
	.string "He uses Fighting types. Flying\n"
	.string "and Psychic moves hit them hard.\p"
	.string "And a Ghost won't take a punch\n"
	.string "at all.$"

Yunotaki_Gym_Text_GymGuideAfter:
	.string "You beat him. Good breathing.$"

Yunotaki_Gym_Text_Statue:
	.string "YUNOTAKI GYM\n"
	.string "LEADER: IBUKI$"

Yunotaki_Gym_Text_StatueAfter:
	.string "YUNOTAKI GYM\n"
	.string "LEADER: IBUKI\p"
	.string "Winning trainers:\n"
	.string "{PLAYER}$"
