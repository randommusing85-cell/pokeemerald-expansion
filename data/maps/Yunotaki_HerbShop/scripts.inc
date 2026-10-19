@ Yunotaki's herb shop (design/locations/yunotaki.md): bitter mountain medicine (vanilla
@ Lavaridge's herbs), no gifts. The keeper won't gossip about Ibuki.

Yunotaki_HerbShop_MapScripts::
	.byte 0

Yunotaki_HerbShop_EventScript_Keeper::
	lock
	faceplayer
	msgbox Yunotaki_HerbShop_Text_Welcome, MSGBOX_DEFAULT
	pokemart Yunotaki_HerbShop_Pokemart
	msgbox Yunotaki_HerbShop_Text_AskHim, MSGBOX_DEFAULT
	release
	end

	.align 2
Yunotaki_HerbShop_Pokemart:
	.2byte ITEM_ENERGY_POWDER
	.2byte ITEM_ENERGY_ROOT
	.2byte ITEM_HEAL_POWDER
	.2byte ITEM_REVIVAL_HERB
	pokemartlistend

@ TODO(design): drafts; "Ask him yourself." is decided (brainstorm-yunotaki.md).
Yunotaki_HerbShop_Text_Welcome:
	.string "Herbs. Bitter, but they work.$"

Yunotaki_HerbShop_Text_AskHim:
	.string "Ibuki? I don't gossip.\n"
	.string "Ask him yourself.$"
