@ Yunotaki's inn (design/locations/yunotaki.md), in Lavaridge's house. The innkeeper is the inn's
@ gossip; JIRO, Route 2's porter, unloads the baskets he carried up.

Yunotaki_Inn_MapScripts::
	.byte 0

Yunotaki_Inn_EventScript_Innkeeper::
	msgbox Yunotaki_Inn_Text_GossipChampion, MSGBOX_NPC
	end

Yunotaki_Inn_EventScript_Jiro::
	msgbox Yunotaki_Inn_Text_Jiro, MSGBOX_NPC
	end

@ TODO(design): drafts.
Yunotaki_Inn_Text_GossipChampion:
	.string "Welcome. The baths are outside.\p"
	.string "Ibuki? He lost to the Champion.\n"
	.string "Badly. Never went back.\p"
	.string "That's the real story.$"

Yunotaki_Inn_Text_Jiro:
	.string "JIRO: You made it up too.\n"
	.string "These baskets nearly didn't.$"
