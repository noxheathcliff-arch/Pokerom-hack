TwoIsland_PokemonCenter_1F_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, TwoIsland_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

TwoIsland_PokemonCenter_1F_OnTransition::
	setrespawn HEAL_LOCATION_TWO_ISLAND
	end

TwoIsland_PokemonCenter_1F_EventScript_Nurse::
	lock
	faceplayer
	call EventScript_PkmnCenterNurse_Frlg
	release
	end

TwoIsland_PokemonCenter_1F_EventScript_GBAKid::
	msgbox TwoIsland_PokemonCenter_1F_Text_HaveYouVisitedGameCorner, MSGBOX_NPC
	end

TwoIsland_PokemonCenter_1F_EventScript_BugCatcher::
	msgbox TwoIsland_PokemonCenter_1F_Text_OldLadyLivesOutOnCape, MSGBOX_NPC
	end

TwoIsland_PokemonCenter_1F_Text_HaveYouVisitedGameCorner::
	.string "Tu connais la SALLE DE JEU?\p"
	.string "Si tu y vas, n'oublie pas d'amener\n"
	.string "des amis avec toi.$"

TwoIsland_PokemonCenter_1F_Text_OldLadyLivesOutOnCape::
	.string "Peu de monde habite sur\n"
	.string "l'ILE 2.\p"
	.string "Il y a une vieille fille qui habite\n"
	.string "au bout du cap.\p"
	.string "Personne ne sait depuis quand\n"
	.string "elle habite là-bas.$"

