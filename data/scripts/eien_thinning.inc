@ The thinning (design/game-bible.md, "The thinning on the map"; src/eien_thinning.c).
@ A scene calls EienThinning_EventScript_Open where the world thins and
@ EienThinning_EventScript_Close when it's closed. While it's open: no snow, no music, the screen
@ drained to grey (the hero and Celebi stay in colour), and every battle gets the thin-place
@ effect and a grey background. To keep another object in colour (Yuki, a partner), before
@ opening: setvar VAR_0x8004, LOCALID_..., then callnative KeepObjectInColourInThinning.
@ Leaving the map closes it (the map's own weather comes back).

EienThinning_EventScript_Open::
	playse SE_M_EARTHQUAKE
	callnative StopSnowForThinning
	setweather WEATHER_THINNING
	doweather
	fadeoutbgm 4 @ waits for the music to stop
	checkfollowernpc
	call_if_eq VAR_RESULT, TRUE, EienThinning_EventScript_CelebiFlickers
	waitse
	return

EienThinning_EventScript_CelebiFlickers::
	applymovement OBJ_EVENT_ID_NPC_FOLLOWER, EienThinning_Movement_Flicker
	waitmovement 0
	return

EienThinning_EventScript_Close::
	resetweather
	doweather
	callnative ResumeMusicAfterThinning
	return

EienThinning_Movement_Flicker:
	delay_16
	set_invisible
	delay_8
	set_visible
	delay_8
	set_invisible
	delay_4
	set_visible
	step_end

@ Debug menu, Scripts: 1 opens a thinning on the current map (with Celebi as the follower if
@ there's none), 2 closes it, 3 a wild battle inside it. For trying the effect on built maps.
EienThinning_EventScript_DebugOpen::
	lockall
	checkfollowernpc
	goto_if_eq VAR_RESULT, TRUE, EienThinning_EventScript_DebugOpenNow
	createfollowernpc OBJ_EVENT_GFX_SPECIES(CELEBI), FNPC_ALL_LAND | FNPC_ALL_WATER, EienCelebi_EventScript_Talk
EienThinning_EventScript_DebugOpenNow::
	call EienThinning_EventScript_Open
	releaseall
	end

EienThinning_EventScript_DebugClose::
	lockall
	call EienThinning_EventScript_Close
	releaseall
	end

EienThinning_EventScript_DebugBattle::
	lockall
	setwildbattle SPECIES_DUSKULL, 30
	dowildbattle
	releaseall
	end
