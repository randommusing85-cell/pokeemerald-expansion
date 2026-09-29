@ Professor Kashiwagi's lab (design/locations/hamakaze.md). Act 1 beat 3: he picks a starter,
@ Akira takes the one strong against it, Haru the third, then Akira battles him
@ (STORY_GOT_STARTER). Starter cycle (design/variants.md): Torchic beats Bulbasaur, Bulbasaur
@ beats Froakie, Froakie beats Torchic.
@ FLAG_TEMP_1 hides the professor (before he's taken in), FLAG_TEMP_2 Haru and Akira and
@ FLAG_TEMP_3 the three balls (outside the starter scene). VAR_TEMP_1 = 1 once the intro ran;
@ VAR_TEMP_2-5 hold the chosen ball's species, Akira's ball, Haru's ball and Akira's trainer.

Hamakaze_Lab_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Hamakaze_Lab_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Hamakaze_Lab_OnFrame
	.byte 0

Hamakaze_Lab_OnTransition:
	call_if_lt VAR_EIEN_STORY, STORY_TAKEN_IN, Hamakaze_Lab_EventScript_HideProfessor
	call_if_ne VAR_EIEN_STORY, STORY_TAKEN_IN, Hamakaze_Lab_EventScript_HideStarterScene
	end

Hamakaze_Lab_EventScript_HideProfessor:
	setflag FLAG_TEMP_1
	return

Hamakaze_Lab_EventScript_HideStarterScene:
	setflag FLAG_TEMP_2
	setflag FLAG_TEMP_3
	return

Hamakaze_Lab_OnFrame:
	map_script_2 VAR_TEMP_1, 0, Hamakaze_Lab_EventScript_Intro
	.2byte 0

Hamakaze_Lab_EventScript_Intro::
	setvar VAR_TEMP_1, 1
	goto_if_ne VAR_EIEN_STORY, STORY_TAKEN_IN, Hamakaze_Lab_EventScript_End
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, Hamakaze_Lab_Movement_PlayerToBalls
	waitmovement 0
	msgbox Hamakaze_Lab_Text_TheseThree, MSGBOX_DEFAULT
	msgbox Hamakaze_Lab_Text_KnowTwoOfThem, MSGBOX_DEFAULT
	applymovement LOCALID_LAB_AKIRA, Common_Movement_FaceLeft
	waitmovement 0
	msgbox Hamakaze_Lab_Text_AkiraHello, MSGBOX_DEFAULT
	msgbox Hamakaze_Lab_Text_PickOne, MSGBOX_DEFAULT
	releaseall
	end

Hamakaze_Lab_Movement_PlayerToBalls:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	face_up
	step_end

Hamakaze_Lab_EventScript_TorchicBall::
	lock
	setvar VAR_TEMP_2, SPECIES_TORCHIC_EIEN
	setvar VAR_TEMP_3, LOCALID_LAB_FROAKIE_BALL
	setvar VAR_TEMP_4, LOCALID_LAB_BULBASAUR_BALL
	setvar VAR_TEMP_5, TRAINER_EIEN_AKIRA_LAB_FROAKIE
	goto Hamakaze_Lab_EventScript_ChooseStarter

Hamakaze_Lab_EventScript_BulbasaurBall::
	lock
	setvar VAR_TEMP_2, SPECIES_BULBASAUR_EIEN
	setvar VAR_TEMP_3, LOCALID_LAB_TORCHIC_BALL
	setvar VAR_TEMP_4, LOCALID_LAB_FROAKIE_BALL
	setvar VAR_TEMP_5, TRAINER_EIEN_AKIRA_LAB_TORCHIC
	goto Hamakaze_Lab_EventScript_ChooseStarter

Hamakaze_Lab_EventScript_FroakieBall::
	lock
	setvar VAR_TEMP_2, SPECIES_FROAKIE_EIEN
	setvar VAR_TEMP_3, LOCALID_LAB_BULBASAUR_BALL
	setvar VAR_TEMP_4, LOCALID_LAB_TORCHIC_BALL
	setvar VAR_TEMP_5, TRAINER_EIEN_AKIRA_LAB_BULBASAUR
	goto Hamakaze_Lab_EventScript_ChooseStarter

Hamakaze_Lab_EventScript_ChooseStarter::
	showmonpic VAR_TEMP_2, 10, 3
	bufferspeciesname STR_VAR_1, VAR_TEMP_2
	msgbox Hamakaze_Lab_Text_TakeIt, MSGBOX_YESNO
	hidemonpic
	goto_if_eq VAR_RESULT, NO, Hamakaze_Lab_EventScript_Declined
	removeobject VAR_LAST_TALKED
	setflag FLAG_SYS_POKEMON_GET
	givemon VAR_TEMP_2, 5
	playfanfare MUS_OBTAIN_ITEM
	message Hamakaze_Lab_Text_ReceivedStarter
	waitfanfare
	waitmessage
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	call_if_eq VAR_RESULT, YES, Hamakaze_Lab_EventScript_Nickname
	@ Akira takes the one strong against it; Haru takes the last
	msgbox Hamakaze_Lab_Text_AkiraTakes, MSGBOX_DEFAULT
	removeobject VAR_TEMP_3
	applymovement LOCALID_LAB_HARU, Common_Movement_FaceRight
	waitmovement 0
	msgbox Hamakaze_Lab_Text_HaruTakes, MSGBOX_DEFAULT
	removeobject VAR_TEMP_4
	applymovement LOCALID_LAB_AKIRA, Common_Movement_FaceLeft
	waitmovement 0
	msgbox Hamakaze_Lab_Text_AkiraBattle, MSGBOX_DEFAULT
	goto_if_eq VAR_TEMP_5, TRAINER_EIEN_AKIRA_LAB_TORCHIC, Hamakaze_Lab_EventScript_BattleTorchic
	goto_if_eq VAR_TEMP_5, TRAINER_EIEN_AKIRA_LAB_BULBASAUR, Hamakaze_Lab_EventScript_BattleBulbasaur
	goto Hamakaze_Lab_EventScript_BattleFroakie

Hamakaze_Lab_EventScript_AfterBattle::
	special HealPlayerParty
	msgbox Hamakaze_Lab_Text_AkiraAfterBattle, MSGBOX_DEFAULT
	applymovement LOCALID_LAB_AKIRA, Hamakaze_Lab_Movement_AkiraLeaves
	waitmovement 0
	removeobject LOCALID_LAB_AKIRA
	setvar VAR_EIEN_STORY, STORY_GOT_STARTER
	msgbox Hamakaze_Lab_Text_RouteOneNorth, MSGBOX_DEFAULT
	release
	end

Hamakaze_Lab_EventScript_Declined::
	release
Hamakaze_Lab_EventScript_End::
	end

Hamakaze_Lab_EventScript_Nickname::
	setvar VAR_0x8004, 0
	call Common_EventScript_NameReceivedPartyMon
	return

@ Losing is fine: an early rival battle with RIVAL_BATTLE_HEAL_AFTER heals instead of whiting out.
Hamakaze_Lab_EventScript_BattleTorchic::
	trainerbattle_earlyrival TRAINER_EIEN_AKIRA_LAB_TORCHIC, RIVAL_BATTLE_HEAL_AFTER, Hamakaze_Lab_Text_AkiraLost, Hamakaze_Lab_Text_AkiraWon
	goto Hamakaze_Lab_EventScript_AfterBattle

Hamakaze_Lab_EventScript_BattleBulbasaur::
	trainerbattle_earlyrival TRAINER_EIEN_AKIRA_LAB_BULBASAUR, RIVAL_BATTLE_HEAL_AFTER, Hamakaze_Lab_Text_AkiraLost, Hamakaze_Lab_Text_AkiraWon
	goto Hamakaze_Lab_EventScript_AfterBattle

Hamakaze_Lab_EventScript_BattleFroakie::
	trainerbattle_earlyrival TRAINER_EIEN_AKIRA_LAB_FROAKIE, RIVAL_BATTLE_HEAL_AFTER, Hamakaze_Lab_Text_AkiraLost, Hamakaze_Lab_Text_AkiraWon
	goto Hamakaze_Lab_EventScript_AfterBattle

Hamakaze_Lab_Movement_AkiraLeaves:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

Hamakaze_Lab_EventScript_Professor::
	goto_if_ge VAR_EIEN_STORY, STORY_GOT_STARTER, Hamakaze_Lab_EventScript_ProfessorAfter
	msgbox Hamakaze_Lab_Text_PickOne, MSGBOX_NPC
	end

Hamakaze_Lab_EventScript_ProfessorAfter::
	msgbox Hamakaze_Lab_Text_RouteOneNorth, MSGBOX_NPC
	end

Hamakaze_Lab_EventScript_Haru::
	msgbox Hamakaze_Lab_Text_HaruWaiting, MSGBOX_NPC
	end

Hamakaze_Lab_EventScript_Akira::
	msgbox Hamakaze_Lab_Text_AkiraHello, MSGBOX_NPC
	end

@ TODO(design): the scene's exact lines (drafts in the style guide's voice).
Hamakaze_Lab_Text_TheseThree:
	.string "PROFESSOR: There you are.\p"
	.string "These three are Pokémon from Eien.\n"
	.string "They look like ones from books,\l"
	.string "but they're not quite the same.$"

Hamakaze_Lab_Text_KnowTwoOfThem:
	.string "(Torchic and Bulbasaur…\n"
	.string "but not like in the games.)\p"
	.string "(And the third one I've never seen.)$"

Hamakaze_Lab_Text_AkiraHello:
	.string "AKIRA: I'm Akira! Haru said there's\n"
	.string "a new kid. You pick first!$"

Hamakaze_Lab_Text_PickOne:
	.string "PROFESSOR: Take the one you like.$"

Hamakaze_Lab_Text_TakeIt:
	.string "Take {STR_VAR_1}?$"

Hamakaze_Lab_Text_ReceivedStarter:
	.string "{PLAYER} received {STR_VAR_1}!$"

Hamakaze_Lab_Text_AkiraTakes:
	.string "AKIRA: Then I'll take this one.\n"
	.string "It's strong against yours!$"

Hamakaze_Lab_Text_HaruTakes:
	.string "HARU: So this one's mine.$"

Hamakaze_Lab_Text_AkiraBattle:
	.string "AKIRA: Let's see how they do.\n"
	.string "Just a quick battle!$"

Hamakaze_Lab_Text_AkiraLost:
	.string "Aw, I lost!$"

Hamakaze_Lab_Text_AkiraWon:
	.string "I won! That was close.$"

Hamakaze_Lab_Text_AkiraAfterBattle:
	.string "AKIRA: I'm going home to Shimotsuki.\n"
	.string "Come find me there!\p"
	.string "One day I'll battle in the League.$"

Hamakaze_Lab_Text_RouteOneNorth:
	.string "PROFESSOR: Route 1 is north of town.\n"
	.string "Take your time out there.$"

Hamakaze_Lab_Text_HaruWaiting:
	.string "HARU: Go on, you pick first.$"
