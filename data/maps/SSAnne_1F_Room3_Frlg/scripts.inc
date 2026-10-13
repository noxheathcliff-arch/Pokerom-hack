SSAnne_1F_Room3_Frlg_MapScripts::
	.byte 0

SSAnne_1F_Room3_EventScript_LittleGirl::
	msgbox SSAnne_1F_Room3_Text_AlwaysTravelWithWigglytuff, MSGBOX_NPC
	end

SSAnne_1F_Room3_EventScript_BaldingMan::
	msgbox SSAnne_1F_Room3_Text_CruiseIsElegantAndCozy, MSGBOX_NPC
	end

SSAnne_1F_Room3_EventScript_Wigglytuff::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_WIGGLYTUFF, CRY_MODE_NORMAL
	msgbox SSAnne_1F_Room3_Text_Wigglytuff
	waitmoncry
	release
	end

SSAnne_1F_Room3_Text_CruiseIsElegantAndCozy::
	.string "Ha! Une croisière!\n"
	.string "C'est tellement romantique!$"

SSAnne_1F_Room3_Text_AlwaysTravelWithWigglytuff::
	.string "Je voyage toujours avec\n"
	.string "GRODOUDOU!$"

SSAnne_1F_Room3_Text_Wigglytuff::
	.string "GRODOUDOU: Gro! Douuuuuuu!$"

