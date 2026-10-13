SSAnne_1F_Room4_Frlg_MapScripts::
	.byte 0

SSAnne_1F_Room4_EventScript_Woman::
	lock
	faceplayer
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, SSAnne_1F_Room4_EventScript_WomanPlayerMale
	msgbox SSAnne_1F_Room4_Text_WaitressCherryPiePlease
	release
	end

SSAnne_1F_Room4_EventScript_WomanPlayerMale::
	msgbox SSAnne_1F_Room4_Text_WaiterCherryPiePlease
	release
	end

SSAnne_1F_Room4_Text_WaiterCherryPiePlease::
	.string "C'est le service de chambre?\n"
	.string "Amenez-moi une tarte aux poires!$"

SSAnne_1F_Room4_Text_WaitressCherryPiePlease::
	.string "Mademoiselle? Je voudrais une\n"
	.string "tarte, et plus vite que ça!$"

