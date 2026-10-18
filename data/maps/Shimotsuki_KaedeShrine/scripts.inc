@ Kaede's shrine in Shimotsuki (design/locations/shimotsuki.md): a shrine area and a thin place
@ (src/eien_places.c), where Eien Poochyena evolves. Shares Route 1's shrine layout for now.
@ First milestone: Kaede's cameo and her grandmother. Her quest chain starts here in milestone 2.

Shimotsuki_KaedeShrine_MapScripts::
	.byte 0

Shimotsuki_KaedeShrine_EventScript_Kaede::
	msgbox Shimotsuki_KaedeShrine_Text_Kaede, MSGBOX_NPC
	end

Shimotsuki_KaedeShrine_EventScript_Grandmother::
	msgbox Shimotsuki_KaedeShrine_Text_Grandmother, MSGBOX_NPC
	end

Shimotsuki_KaedeShrine_EventScript_Komainu::
	msgbox Shimotsuki_KaedeShrine_Text_Komainu, MSGBOX_NPC
	end

Shimotsuki_KaedeShrine_EventScript_Torii::
	msgbox Shimotsuki_KaedeShrine_Text_Torii, MSGBOX_SIGN
	end

@ TODO(design): this shrine's tablet text, and its bit in QUEST_KAEDE_TABLETS (Kaede reads it
@ when he first meets her in milestone 2).
Shimotsuki_KaedeShrine_EventScript_Tablet::
	msgbox Shimotsuki_KaedeShrine_Text_Tablet, MSGBOX_SIGN
	end

@ Kaede's line is decided (brainstorm-shimotsuki.md); the rest are drafts (TODO(design)).
Shimotsuki_KaedeShrine_Text_Kaede:
	.string "If you're here to pray,\n"
	.string "the box is on the left.\p"
	.string "If not, you're in the way.$"

Shimotsuki_KaedeShrine_Text_Grandmother:
	.string "Oh, a visitor.\p"
	.string "When I was young, the whole town\n"
	.string "came up here at New Year.\p"
	.string "Now it's just us. And the snow.$"

Shimotsuki_KaedeShrine_Text_Komainu:
	.string "(A stone dog. There's one on\n"
	.string "each side of the path.)$"

Shimotsuki_KaedeShrine_Text_Torii:
	.string "(The shrine gate.)$"

Shimotsuki_KaedeShrine_Text_Tablet:
	.string "There's an old tablet.\n"
	.string "The writing's too worn to read.$"
