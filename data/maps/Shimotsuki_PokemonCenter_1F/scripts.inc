@ Shimotsuki's Pokémon Center (design/locations/shimotsuki.md). Vanilla layout; there's no 2F,
@ so the stairs have no warp.

Shimotsuki_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Shimotsuki_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

Shimotsuki_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_SHIMOTSUKI
	end

Shimotsuki_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_SHIMOTSUKI_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end
