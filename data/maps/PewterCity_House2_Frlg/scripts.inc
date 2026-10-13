PewterCity_House2_Frlg_MapScripts::
	.byte 0

PewterCity_House2_EventScript_OldMan::
	msgbox PewterCity_House2_Text_MonsLearnTechniquesAsTheyGrow, MSGBOX_NPC
	end

PewterCity_House2_EventScript_LittleBoy::
	msgbox PewterCity_House2_Text_MonsEasierCatchIfStatused, MSGBOX_NPC
	end

PewterCity_House2_Text_MonsLearnTechniquesAsTheyGrow::
	.string "Un POKéMON apprend des attaques\n"
	.string "en gagnant des niveaux!\p"
	.string "Mais certaines attaques ne sont\n"
	.string "enseignées que par certaines\l"
	.string "personnes!$"

PewterCity_House2_Text_MonsEasierCatchIfStatused::
	.string "Les POKéMON sont plus faciles à\n"
	.string "capturer s'ils ont un problème\l"
	.string "de statut!\p"
	.string "Sommeil, poison, brûlure ou\n"
	.string "paralysie sont très efficaces. \p"
	.string "Mais attraper un POKéMON, c'est\n"
	.string "jamais du tout cuit!$"

