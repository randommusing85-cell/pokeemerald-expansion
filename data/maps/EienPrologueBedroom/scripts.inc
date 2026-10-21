@ Map foundation only. Scene design: design/locations/prologue-bedroom.md.
EienPrologueBedroom_MapScripts::
	.byte 0

EienPrologueBedroom_EventScript_Game::
	@ TODO(design): Claude supplies the console dialogue and prologue trigger.
	@ No story progress is consumed while that design is unresolved.
	end

@ Override inherited furniture interactions (including TV/region-map and decoration
@ bookkeeping) in this world.
@ Their story-specific text can be added by Claude with the prologue design.
EienPrologueBedroom_EventScript_Furniture::
	end
