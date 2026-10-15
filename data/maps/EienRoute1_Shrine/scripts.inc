@ Route 1's shrine (design/locations/route-1.md): a shrine area and a thin place
@ (src/eien_places.c). Placeholder layout. TODO(art): torii and komainu tiles; the torii is two
@ poles and the komainu are Poochyena objects for now.

EienRoute1_Shrine_MapScripts::
	.byte 0

@ Examining the torii notes the shrine for Haru's map.
EienRoute1_Shrine_EventScript_Torii::
	lockall
	checkquest QUEST_HARU_MAP
	goto_if_ne VAR_RESULT, QUEST_STATE_OPEN, EienRoute1_Shrine_EventScript_ToriiPlain
	checkquestbit QUEST_HARU_MAP, HARU_MAP_SHRINE
	goto_if_eq VAR_RESULT, TRUE, EienRoute1_Shrine_EventScript_ToriiPlain
	setquestbit QUEST_HARU_MAP, HARU_MAP_SHRINE
	msgbox EienRoute1_Shrine_Text_NoteShrine, MSGBOX_DEFAULT
	releaseall
	end

EienRoute1_Shrine_EventScript_ToriiPlain::
	msgbox EienRoute1_Shrine_Text_Torii, MSGBOX_DEFAULT
	releaseall
	end

@ Reading the tablet adds its lore page and counts for Kaede's tablets, even before she asks.
EienRoute1_Shrine_EventScript_Tablet::
	lockall
	msgbox EienRoute1_Shrine_Text_Tablet, MSGBOX_DEFAULT
	checkquestbit QUEST_KAEDE_TABLETS, TABLET_ROUTE1_SHRINE
	goto_if_eq VAR_RESULT, TRUE, EienRoute1_Shrine_EventScript_TabletEnd
	setquestbit QUEST_KAEDE_TABLETS, TABLET_ROUTE1_SHRINE
	msgbox EienRoute1_Shrine_Text_TabletThought, MSGBOX_DEFAULT
EienRoute1_Shrine_EventScript_TabletEnd:
	releaseall
	end

EienRoute1_Shrine_EventScript_Komainu::
	msgbox EienRoute1_Shrine_Text_Komainu, MSGBOX_NPC
	end

EienRoute1_Shrine_EventScript_Lass::
	trainerbattle_single TRAINER_EIEN_ROUTE1_LASS, EienRoute1_Shrine_Text_LassIntro, EienRoute1_Shrine_Text_LassDefeat
	msgbox EienRoute1_Shrine_Text_LassAfter, MSGBOX_AUTOCLOSE
	end

@ TODO(design): all lines are drafts in the style guide's voice, except the tablet's
@ inscription and his thought after it (decided in brainstorm-route-1.md).
EienRoute1_Shrine_Text_NoteShrine:
	.string "(A shrine. That's all three for Haru.)$"

EienRoute1_Shrine_Text_Torii:
	.string "(The shrine gate.)$"

EienRoute1_Shrine_Text_Tablet:
	.string "There's an old tablet.\p"
	.string "“The dogs keep the gate.\n"
	.string "They grow at the gate,\l"
	.string "and nowhere else.”$"

EienRoute1_Shrine_Text_TabletThought:
	.string "(In the games, Poochyena just\n"
	.string "evolves at 18.)\p"
	.string "(…Does it say something else here?)$"

EienRoute1_Shrine_Text_Komainu:
	.string "(A stone dog. There's one on\n"
	.string "each side of the path.)$"

EienRoute1_Shrine_Text_LassIntro:
	.string "I come here before every battle.\n"
	.string "It helps. Watch!$"

EienRoute1_Shrine_Text_LassDefeat:
	.string "Maybe it doesn't help.$"

EienRoute1_Shrine_Text_LassAfter:
	.string "The stone dogs at night…\n"
	.string "My gran says they move.$"
