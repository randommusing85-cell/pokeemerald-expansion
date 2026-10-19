@ Yunotaki's Pokémon Center (design/locations/yunotaki.md). Lavaridge's layout; there's no 2F,
@ so the stairs have no warp. The back door leads out by the hot spring.

Yunotaki_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Yunotaki_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

Yunotaki_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_YUNOTAKI
	end

Yunotaki_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_YUNOTAKI_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end
