SaffronCity_CopycatsHouse_1F_Frlg_MapScripts::
	.byte 0

SaffronCity_CopycatsHouse_1F_EventScript_CopycatsMom::
	msgbox SaffronCity_CopycatsHouse_1F_Text_DaughterIsSelfCentered, MSGBOX_NPC
	end

SaffronCity_CopycatsHouse_1F_EventScript_CopycatsDad::
	msgbox SaffronCity_CopycatsHouse_1F_Text_DaughterLikesToMimicPeople, MSGBOX_NPC
	end

SaffronCity_CopycatsHouse_1F_EventScript_Chansey::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_CHANSEY, CRY_MODE_NORMAL
	msgbox SaffronCity_CopycatsHouse_1F_Text_Chansey
	waitmoncry
	release
	end

SaffronCity_CopycatsHouse_1F_Text_DaughterIsSelfCentered::
	.string "Ma fille est très égocentrique!\n"
	.string "Elle n'a pas beaucoup d'amis.$"

SaffronCity_CopycatsHouse_1F_Text_DaughterLikesToMimicPeople::
	.string "Ma fille adore imiter les gens.\p"
	.string "Elle imite si bien qu'on l'appelle\n"
	.string "la COPIEUSE dans le coin!$"

SaffronCity_CopycatsHouse_1F_Text_Chansey::
	.string "LEVEINARD : Vénar! Vénar!$"

