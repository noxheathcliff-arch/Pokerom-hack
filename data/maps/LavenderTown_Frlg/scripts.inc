LavenderTown_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LavenderTown_OnTransition
	.byte 0

LavenderTown_OnTransition::
	setworldmapflag FLAG_WORLD_MAP_LAVENDER_TOWN
	setvar VAR_MAP_SCENE_S_S_ANNE_2F_CORRIDOR, 1
	setflag FLAG_HIDE_SS_ANNE_RIVAL
	end

LavenderTown_EventScript_LittleGirl::
	lock
	faceplayer
	msgbox LavenderTown_Text_DoYouBelieveInGhosts, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, LavenderTown_EventScript_LittleGirlBelieve
	msgbox LavenderTown_Text_JustImaginingWhiteHand
	release
	end

LavenderTown_EventScript_LittleGirlBelieve::
	msgbox LavenderTown_Text_SoThereAreBelievers
	release
	end

LavenderTown_EventScript_WorkerM::
	msgbox LavenderTown_Text_TownKnownAsMonGraveSite, MSGBOX_NPC
	end

LavenderTown_EventScript_Boy::
	msgbox LavenderTown_Text_GhostsAppearedInTower, MSGBOX_NPC
	end

LavenderTown_EventScript_TownSign::
	msgbox LavenderTown_Text_TownSign, MSGBOX_SIGN
	end

LavenderTown_EventScript_SilphScopeNotice::
	msgbox LavenderTown_Text_SilphScopeNotice, MSGBOX_SIGN
	end

LavenderTown_EventScript_VolunteerHouseSign::
	msgbox LavenderTown_Text_VolunteerPokemonHouse, MSGBOX_SIGN
	end

LavenderTown_EventScript_PokemonTowerSign::
	msgbox LavenderTown_Text_PokemonTowerSign, MSGBOX_SIGN
	end

LavenderTown_Text_DoYouBelieveInGhosts::
	.string "Crois-tu aux SPECTRES?$"

LavenderTown_Text_SoThereAreBelievers::
	.string "Vraiment?\n"
	.string "Il en faut…$"

LavenderTown_Text_JustImaginingWhiteHand::
	.string "T'as raison.\p"
	.string "La main toute blanche sur ton\n"
	.string "épaule est fausse alors…$"

LavenderTown_Text_TownKnownAsMonGraveSite::
	.string "Cette ville est le cimetière des\n"
	.string "POKéMON.\p"
	.string "La TOUR POKéMON est le lieu de\n"
	.string "recueillement.$"

LavenderTown_Text_GhostsAppearedInTower::
	.string "Des SPECTRES sont apparus dans la\n"
	.string "TOUR POKéMON.\p"
	.string "Ils doivent être les esprits des\n"
	.string "POKéMON tués par la ROCKET.$"

LavenderTown_Text_TownSign::
	.string "LAVANVILLE\n"
	.string "Le pourpre de la noblesse$"

LavenderTown_Text_SilphScopeNotice::
	.string "Tout nouveau SCOPE SYLPHE!\n"
	.string "Voir l'invisible!\p"
	.string "SYLPHE SARL$"

LavenderTown_Text_VolunteerPokemonHouse::
	.string "BENEVOLAT DE LAVANVILLE\n"
	.string "MAISON POKéMON$"

LavenderTown_Text_PokemonTowerSign::
	.string "Paix à l'âme des POKéMON\n"
	.string "TOUR POKéMON$"

