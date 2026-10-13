IndigoPlateau_PokemonCenter_1F_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, IndigoPlateau_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

IndigoPlateau_PokemonCenter_1F_OnTransition::
	setrespawn HEAL_LOCATION_INDIGO_PLATEAU
	specialvar VAR_RESULT, IsNationalPokedexEnabled
	call_if_eq VAR_RESULT, TRUE, IndigoPlateau_PokemonCenter_1F_EventScript_CheckBlockDoor
	end

IndigoPlateau_PokemonCenter_1F_EventScript_CheckBlockDoor::
	goto_if_set FLAG_IS_CHAMPION, Common_EventScript_NopReturn
	setobjectxyperm LOCALID_LEAGUE_DOOR_GUARD, 4, 2
	return

IndigoPlateau_PokemonCenter_1F_EventScript_DoorGuard::
	lock
	faceplayer
	specialvar VAR_RESULT, IsNationalPokedexEnabled
	goto_if_eq VAR_RESULT, TRUE, IndigoPlateau_PokemonCenter_1F_EventScript_CheckSeviiIslandComplete
	msgbox IndigoPlateau_PokemonCenter_1F_Text_FaceEliteFourGoodLuck
	release
	end

IndigoPlateau_PokemonCenter_1F_EventScript_CheckSeviiIslandComplete::
	goto_if_set FLAG_IS_CHAMPION, IndigoPlateau_PokemonCenter_1F_EventScript_SeviiIslandComplete
	msgbox IndigoPlateau_PokemonCenter_1F_Text_LoreleiIsAbsentClosedForTimeBeing
	release
	end

IndigoPlateau_PokemonCenter_1F_EventScript_SeviiIslandComplete::
	msgbox IndigoPlateau_PokemonCenter_1F_Text_FaceEliteFourGoodLuck
	release
	end

IndigoPlateau_PokemonCenter_1F_EventScript_GymGuy::
	msgbox IndigoPlateau_PokemonCenter_1F_Text_GymGuyAdvice, MSGBOX_NPC
	end

IndigoPlateau_PokemonCenter_1F_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart IndigoPlateau_PokemonCenter_1F_Items
	msgbox gText_PleaseComeAgain
	release
	end

	.align 2
IndigoPlateau_PokemonCenter_1F_Items::
	.2byte ITEM_ULTRA_BALL
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_FULL_RESTORE
	.2byte ITEM_MAX_POTION
	.2byte ITEM_REVIVE
	.2byte ITEM_FULL_HEAL
	.2byte ITEM_MAX_REPEL
	.2byte ITEM_NONE
	release
	end

IndigoPlateau_PokemonCenter_1F_EventScript_Nurse::
	lock
	faceplayer
	call EventScript_PkmnCenterNurse_Frlg
	release
	end

IndigoPlateau_PokemonCenter_1F_Text_GymGuyAdvice::
	.string "Salut,\n"
	.string "CHAMPION en herbe!\p"
	.string "Tu vas devoir affronter le CONSEIL\n"
	.string "4 dans l'ordre pour triompher\l"
	.string "de la LIGUE POKéMON.\p"
	.string "Si tu perds, d'abord tu auras\n"
	.string "honte, et ensuite tu devras tout\l"
	.string "recommencer!\p"
	.string "Alors fais bien attention et…\n"
	.string "Ecrase-les!$"

IndigoPlateau_PokemonCenter_1F_Text_FaceEliteFourGoodLuck::
	.string "A partir d'ici, tu affronteras les\n"
	.string "quatre membres du…\l"
	.string "CONSEIL 4!\p"
	.string "Remporte la victoire et une porte\n"
	.string "s'ouvrira vers le prochain\l"
	.string "DRESSEUR. Bonne chance!$"

IndigoPlateau_PokemonCenter_1F_Text_LoreleiIsAbsentClosedForTimeBeing::
	.string "Désolée. Tu perds ton temps en\n"
	.string "venant ici.\p"
	.string "OLGA du CONSEIL 4 s'est absentée.\p"
	.string "La LIGUE POKéMON est fermée\n"
	.string "jusqu'à son retour.$"

IndigoPlateau_PokemonCenter_1F_Text_AgathaWhuppedUs::
	.string "Les POKéMON SPECTRE\n"
	.string "d'AGATHA sont terrifiants.\p"
	.string "J'avais entraîné mes POKéMON\n"
	.string "COMBAT comme un malade.\p"
	.string "J'suis allé affronter AGATHA tout\n"
	.string "sûr de moi, mais elle m'a éclaté.\p"
	.string "En plus, elle se met facilement\n"
	.string "en rogne. J'te raconte pas.$"

IndigoPlateau_PokemonCenter_1F_Text_LancesCousinGymLeaderFarAway::
	.string "C'est peut-être héréditaire de\n"
	.string "faire partie du CONSEIL 4.\p"
	.string "Y'a un copain d'un cousin d'une\n"
	.string "amie qui dit que PETER\p"
	.string "a un cousin CHAMPION D'ARENE\n"
	.string "quelque part.$"

