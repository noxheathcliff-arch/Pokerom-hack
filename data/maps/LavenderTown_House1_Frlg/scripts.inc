LavenderTown_House1_Frlg_MapScripts::
	.byte 0

LavenderTown_House1_EventScript_CooltrainerF::
	lock
	faceplayer
	goto_if_set FLAG_RESCUED_MR_FUJI, LavenderTown_House1_EventScript_CooltrainerFGhostGone
	msgbox LavenderTown_House1_Text_RocketsKilledCubonesMother
	release
	end

LavenderTown_House1_EventScript_CooltrainerFGhostGone::
	msgbox LavenderTown_House1_Text_GhostOfPokemonTowerIsGone
	release
	end

LavenderTown_House1_EventScript_Cubone::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_CUBONE, CRY_MODE_NORMAL
	msgbox LavenderTown_House1_Text_Cubone
	waitmoncry
	release
	end

LavenderTown_House1_Text_Cubone::
	.string "OSSELAIT: Lailaii!$"

LavenderTown_House1_Text_RocketsKilledCubonesMother::
	.string "Je déteste ces méchants ROCKET!\p"
	.string "La pauvre mère d'OSSELAIT…\p"
	.string "Elle a disparu en essayant\n"
	.string "d'échapper à la TEAM ROCKET!$"

LavenderTown_House1_Text_GhostOfPokemonTowerIsGone::
	.string "Le SPECTRE de la TOUR POKéMON\n"
	.string "est parti!\p"
	.string "Quelqu'un a dû apaiser son âme\n"
	.string "tourmentée!$"

