@ Celebi follows the hero (design/game-bible.md: talking to Celebi gives a hint about where
@ to go next). It's his follower NPC from Hamakaze on (Hamakaze_EventScript_WakeUp).

EienCelebi_EventScript_Talk::
	lock
	playmoncry SPECIES_CELEBI, CRY_MODE_NORMAL
	waitmoncry
	goto_if_ge VAR_EIEN_STORY, STORY_GOT_STARTER, EienCelebi_EventScript_HintRoute1
	goto_if_ge VAR_EIEN_STORY, STORY_TAKEN_IN, EienCelebi_EventScript_HintLab
	msgbox EienCelebi_Text_HintHouses, MSGBOX_DEFAULT
	release
	end

EienCelebi_EventScript_HintLab::
	msgbox EienCelebi_Text_HintLab, MSGBOX_DEFAULT
	release
	end

EienCelebi_EventScript_HintRoute1::
	msgbox EienCelebi_Text_HintRoute1, MSGBOX_DEFAULT
	release
	end

EienCelebi_Text_HintHouses:
	.string "Celebi floats toward the houses\n"
	.string "up the beach.$"

EienCelebi_Text_HintLab:
	.string "Celebi keeps looking at the yellow\n"
	.string "building.$"

EienCelebi_Text_HintRoute1:
	.string "Celebi looks north, past the trees.$"
