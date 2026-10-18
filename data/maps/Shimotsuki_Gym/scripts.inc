@ Shimotsuki Gym (design/locations/shimotsuki.md). Gym 1, Fuyumi (Ice). Reuses the vanilla
@ Rustboro gym layout for now; a real ice puzzle can come with the Porymap redraw.

Shimotsuki_Gym_MapScripts::
	.byte 0

Shimotsuki_Gym_EventScript_Fuyumi::
	trainerbattle_single TRAINER_EIEN_FUYUMI, Shimotsuki_Gym_Text_FuyumiIntro, Shimotsuki_Gym_Text_FuyumiDefeat, Shimotsuki_Gym_EventScript_FuyumiDefeated, NO_MUSIC
	msgbox Shimotsuki_Gym_Text_FuyumiPostBattle, MSGBOX_DEFAULT
	release
	end

Shimotsuki_Gym_EventScript_FuyumiDefeated::
	message Shimotsuki_Gym_Text_ReceivedBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	setflag FLAG_BADGE01_GET
	setvar VAR_EIEN_STORY, STORY_BADGE_1
	msgbox Shimotsuki_Gym_Text_TakeThis, MSGBOX_DEFAULT
	giveitem ITEM_TM07
	msgbox Shimotsuki_Gym_Text_ExplainHail, MSGBOX_DEFAULT
	release
	end

Shimotsuki_Gym_EventScript_Trainer1::
	trainerbattle_single TRAINER_EIEN_SHIMOTSUKI_GYM_1, Shimotsuki_Gym_Text_Trainer1Intro, Shimotsuki_Gym_Text_Trainer1Defeat
	msgbox Shimotsuki_Gym_Text_Trainer1After, MSGBOX_AUTOCLOSE
	end

Shimotsuki_Gym_EventScript_Trainer2::
	trainerbattle_single TRAINER_EIEN_SHIMOTSUKI_GYM_2, Shimotsuki_Gym_Text_Trainer2Intro, Shimotsuki_Gym_Text_Trainer2Defeat
	msgbox Shimotsuki_Gym_Text_Trainer2After, MSGBOX_AUTOCLOSE
	end

Shimotsuki_Gym_EventScript_GymGuide::
	lock
	faceplayer
	goto_if_set FLAG_BADGE01_GET, Shimotsuki_Gym_EventScript_GymGuideAfter
	msgbox Shimotsuki_Gym_Text_GymGuide, MSGBOX_DEFAULT
	release
	end

Shimotsuki_Gym_EventScript_GymGuideAfter::
	msgbox Shimotsuki_Gym_Text_GymGuideAfter, MSGBOX_DEFAULT
	release
	end

Shimotsuki_Gym_EventScript_Statue::
	lockall
	goto_if_set FLAG_BADGE01_GET, Shimotsuki_Gym_EventScript_StatueAfter
	msgbox Shimotsuki_Gym_Text_Statue, MSGBOX_DEFAULT
	releaseall
	end

Shimotsuki_Gym_EventScript_StatueAfter::
	msgbox Shimotsuki_Gym_Text_StatueAfter, MSGBOX_DEFAULT
	releaseall
	end

@ TODO(design): all lines are drafts in the style guide's voice. Fuyumi is a stern veteran
@ in the gym. The badge's name is still a placeholder.
Shimotsuki_Gym_Text_FuyumiIntro:
	.string "FUYUMI: You're the boy my son\n"
	.string "keeps talking about.\p"
	.string "I'm the leader here.\n"
	.string "Show me what you've got.$"

Shimotsuki_Gym_Text_FuyumiDefeat:
	.string "…Fine. You've earned it.$"

Shimotsuki_Gym_Text_ReceivedBadge:
	.string "{PLAYER} received the gym's badge\n"
	.string "from FUYUMI.$"

Shimotsuki_Gym_Text_TakeThis:
	.string "FUYUMI: Take this as well.$"

Shimotsuki_Gym_Text_ExplainHail:
	.string "FUYUMI: That's Hail.\n"
	.string "It brings a storm of ice.\p"
	.string "Anything that isn't an Ice type\n"
	.string "gets hurt every turn.$"

Shimotsuki_Gym_Text_FuyumiPostBattle:
	.string "FUYUMI: Don't stand around.\n"
	.string "You've got somewhere to be.$"

Shimotsuki_Gym_Text_Trainer1Intro:
	.string "You get used to the cold here.\n"
	.string "Let's see if you can.$"

Shimotsuki_Gym_Text_Trainer1Defeat:
	.string "Brr. I lost.$"

Shimotsuki_Gym_Text_Trainer1After:
	.string "The leader trains outside,\n"
	.string "even in a blizzard.$"

Shimotsuki_Gym_Text_Trainer2Intro:
	.string "My fingers are numb,\n"
	.string "but I can still battle!$"

Shimotsuki_Gym_Text_Trainer2Defeat:
	.string "Too cold to think.$"

Shimotsuki_Gym_Text_Trainer2After:
	.string "Warm up before you face\n"
	.string "the leader.$"

Shimotsuki_Gym_Text_GymGuide:
	.string "Taking on the leader?\p"
	.string "She uses Ice types. Rock, Fire,\n"
	.string "Fighting and Steel moves hit hard.\p"
	.string "Those Poochyena on Route 1 are\n"
	.string "part Rock. Worth catching one.$"

Shimotsuki_Gym_Text_GymGuideAfter:
	.string "You beat her! I knew you could.$"

Shimotsuki_Gym_Text_Statue:
	.string "SHIMOTSUKI GYM\n"
	.string "LEADER: FUYUMI$"

Shimotsuki_Gym_Text_StatueAfter:
	.string "SHIMOTSUKI GYM\n"
	.string "LEADER: FUYUMI\p"
	.string "Winning trainers:\n"
	.string "{PLAYER}$"
