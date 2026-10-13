CeladonCity_Condominiums_3F_Frlg_MapScripts::
	.byte 0

CeladonCity_Condominiums_3F_EventScript_Programmer::
	msgbox CeladonCity_Condominiums_3F_Text_ImTheProgrammer, MSGBOX_NPC
	end

CeladonCity_Condominiums_3F_EventScript_GraphicArtist::
	msgbox CeladonCity_Condominiums_3F_Text_ImTheGraphicArtist, MSGBOX_NPC
	end

CeladonCity_Condominiums_3F_EventScript_Writer::
	msgbox CeladonCity_Condominiums_3F_Text_IWroteTheStory, MSGBOX_NPC
	end

CeladonCity_Condominiums_3F_EventScript_Designer::
	lock
	faceplayer
	specialvar VAR_RESULT, HasAllKantoMons
	goto_if_eq VAR_RESULT, TRUE, CeladonCity_Condominiums_3F_EventScript_CompletedPokedex
	msgbox CeladonCity_Condominiums_3F_Text_ImGameDesignerShowMeFinishedPokedex
	release
	end

CeladonCity_Condominiums_3F_EventScript_CompletedPokedex::
	goto CeladonCity_Condominiums_3F_EventScript_ShowDiploma
	end

CeladonCity_Condominiums_3F_EventScript_ShowDiploma::
	message CeladonCity_Condominiums_3F_Text_CompletedPokedexCongratulations
	waitmessage
	delay 60
	special Special_ShowDiploma
	release
	end

CeladonCity_Condominiums_3F_EventScript_DevelopmentRoomSign::
	msgbox CeladonCity_Condominiums_3F_Text_GameFreakDevelopmentRoom, MSGBOX_SIGN
	end

CeladonCity_Condominiums_3F_EventScript_Computer1::
	msgbox CeladonCity_Condominiums_3F_Text_ItsTheGameProgram, MSGBOX_SIGN
	end

CeladonCity_Condominiums_3F_EventScript_Computer2::
	msgbox CeladonCity_Condominiums_3F_Text_SomeonesPlayingGame, MSGBOX_SIGN
	end

CeladonCity_Condominiums_3F_EventScript_Computer3::
	msgbox CeladonCity_Condominiums_3F_Text_ItsScriptBetterNotLookAtEnding, MSGBOX_SIGN
	end

CeladonCity_Condominiums_3F_Text_ImTheProgrammer::
	.string "Moi?\n"
	.string "J'suis un programmeur!$"

CeladonCity_Condominiums_3F_Text_ImTheGraphicArtist::
	.string "Je fais tous les graphismes!\n"
	.string "J'ai même créé ton personnage!$"

CeladonCity_Condominiums_3F_Text_IWroteTheStory::
	.string "J'ai écrit l'histoire!\n"
	.string "ERIKA est belle!\p"
	.string "ONDINE aussi, non?\n"
	.string "Et puis MORGANE! Elle est mimi!$"

CeladonCity_Condominiums_3F_Text_ImGameDesignerShowMeFinishedPokedex::
	.string "Je suis le concepteur du jeu!\p"
	.string "Remplir ton POKéDEX est difficile,\n"
	.string "hein?\p"
	.string "Complète-le et reviens me voir!$"

CeladonCity_Condominiums_3F_Text_CompletedPokedexCongratulations::
	.string "Woah! Génial!\n"
	.string "Tu as complété ton POKéDEX!\l"
	.string "Félicitations!\l"
	.string "…$"

CeladonCity_Condominiums_3F_Text_ItsTheGameProgram::
	.string "Le programme du jeu! Si tu y\n"
	.string "touches, tout va planter!$"

CeladonCity_Condominiums_3F_Text_SomeonesPlayingGame::
	.string "Quelqu'un joue au lieu de bosser!$"

CeladonCity_Condominiums_3F_Text_ItsScriptBetterNotLookAtEnding::
	.string "Le script du jeu!\n"
	.string "Surtout ne pas lire la fin!$"

CeladonCity_Condominiums_3F_Text_GameFreakDevelopmentRoom::
	.string "GAME FREAK Développement$"

