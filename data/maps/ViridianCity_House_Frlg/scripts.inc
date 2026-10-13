ViridianCity_House_Frlg_MapScripts::
	.byte 0

ViridianCity_House_EventScript_BaldingMan::
	msgbox ViridianCity_House_Text_NicknamingIsFun, MSGBOX_NPC
	end

ViridianCity_House_EventScript_LittleGirl::
	msgbox ViridianCity_House_Text_MyDaddyLovesMonsToo, MSGBOX_NPC
	end

ViridianCity_House_EventScript_Speary::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_SPEAROW, CRY_MODE_NORMAL
	msgbox ViridianCity_House_Text_Speary
	waitmoncry
	release
	end

ViridianCity_House_EventScript_NicknameSign::
	msgbox ViridianCity_House_Text_SpearowNameSpeary, MSGBOX_SIGN
	end

ViridianCity_House_Text_NicknamingIsFun::
	.string "Trouver des noms, c'est rigolo mais\n"
	.string "c'est dur!\p"
	.string "Les noms les plus simples sont les\n"
	.string "plus faciles à retenir.$"

ViridianCity_House_Text_MyDaddyLovesMonsToo::
	.string "Mon papa aime les POKéMON aussi.$"

ViridianCity_House_Text_Speary::
	.string "PIAFFY: Cui-cui!$"

ViridianCity_House_Text_SpearowNameSpeary::
	.string "PIAFABEC\n"
	.string "Nom: PIAFFY$"

