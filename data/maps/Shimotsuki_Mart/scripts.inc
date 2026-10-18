@ Shimotsuki's Mart (design/locations/shimotsuki.md). TODO(design): the stock is a placeholder.

Shimotsuki_Mart_MapScripts::
	.byte 0

Shimotsuki_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart Shimotsuki_Mart_Pokemart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
Shimotsuki_Mart_Pokemart:
	.2byte ITEM_POKE_BALL
	.2byte ITEM_POTION
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_AWAKENING
	.2byte ITEM_ICE_HEAL
	.2byte ITEM_ESCAPE_ROPE
	pokemartlistend
