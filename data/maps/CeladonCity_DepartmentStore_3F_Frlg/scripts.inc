CeladonCity_DepartmentStore_3F_Frlg_MapScripts::
	.byte 0

CeladonCity_DepartmentStore_3F_EventScript_CounterTutor::
	goto EventScript_CounterTutor
	end

CeladonCity_DepartmentStore_3F_EventScript_GBAKid1::
	msgbox CeladonCity_DepartmentStore_3F_Text_OTStandsForOriginalTrainer, MSGBOX_NPC
	end

CeladonCity_DepartmentStore_3F_EventScript_GBAKid2::
	msgbox CeladonCity_DepartmentStore_3F_Text_BuddyTradingKangaskhanForHaunter, MSGBOX_NPC
	end

CeladonCity_DepartmentStore_3F_EventScript_GBAKid3::
	msgbox CeladonCity_DepartmentStore_3F_Text_HaunterEvolvedOnTrade, MSGBOX_NPC
	end

CeladonCity_DepartmentStore_3F_EventScript_LittleGirl::
	msgbox CeladonCity_DepartmentStore_3F_Text_CanIdentifyTradeMonsByID, MSGBOX_NPC
	end

CeladonCity_DepartmentStore_3F_EventScript_SuperNES::
	msgbox CeladonCity_DepartmentStore_3F_Text_ItsSuperNES, MSGBOX_SIGN
	end

CeladonCity_DepartmentStore_3F_EventScript_TV1::
	msgbox CeladonCity_DepartmentStore_3F_Text_AnRPG, MSGBOX_SIGN
	end

CeladonCity_DepartmentStore_3F_EventScript_TV2::
	msgbox CeladonCity_DepartmentStore_3F_Text_SportsGame, MSGBOX_SIGN
	end

CeladonCity_DepartmentStore_3F_EventScript_TV3::
	msgbox CeladonCity_DepartmentStore_3F_Text_PuzzleGame, MSGBOX_SIGN
	end

CeladonCity_DepartmentStore_3F_EventScript_TV4::
	msgbox CeladonCity_DepartmentStore_3F_Text_FightingGame, MSGBOX_SIGN
	end

CeladonCity_DepartmentStore_3F_EventScript_FloorSign::
	msgbox CeladonCity_DepartmentStore_3F_Text_TVGameShop, MSGBOX_SIGN
	end

CeladonCity_DepartmentStore_3F_EventScript_Poster::
	msgbox CeladonCity_DepartmentStore_3F_Text_RedGreenBothArePokemon, MSGBOX_SIGN
	end

CeladonCity_DepartmentStore_3F_Text_OTStandsForOriginalTrainer::
	.string "Tous les POKéMON capturés ont un\n"
	.string "numéro d'immatriculation et un nom\l"
	.string "de DO (Dresseur d'Origine)!$"

CeladonCity_DepartmentStore_3F_Text_BuddyTradingKangaskhanForHaunter::
	.string "Ouaiiis!\p"
	.string "Mon pote va m'échanger son\n"
	.string "KANGOUREX contre mon GRAVALANCH!$"

CeladonCity_DepartmentStore_3F_Text_HaunterEvolvedOnTrade::
	.string "Cool! Un GRAVALANCH!\p"
	.string "J'adore les GRAVALANCH!\p"
	.string "Qu… Hein??\p"
	.string "GRAVALANCH se transforme en un\n"
	.string "autre POKéMON!$"

CeladonCity_DepartmentStore_3F_Text_CanIdentifyTradeMonsByID::
	.string "Le numéro d'immatriculation d'un\n"
	.string "POKéMON sert à l'identifier lors\l"
	.string "d'un échange!$"

CeladonCity_DepartmentStore_3F_Text_ItsSuperNES::
	.string "Une SUPER NINTENDO!$"

CeladonCity_DepartmentStore_3F_Text_AnRPG::
	.string "Un RPG! Cool…\n"
	.string "Mais j'ai pas le temps!$"

CeladonCity_DepartmentStore_3F_Text_SportsGame::
	.string "Un jeu de sport!\n"
	.string "Vive le foot!$"

CeladonCity_DepartmentStore_3F_Text_PuzzleGame::
	.string "Un jeu de puzzle!\n"
	.string "J'y suis accro!$"

CeladonCity_DepartmentStore_3F_Text_FightingGame::
	.string "Un jeu de combat!\n"
	.string "Trop coool!$"

CeladonCity_DepartmentStore_3F_Text_TVGameShop::
	.string "2ème: JEUX VIDEO$"

CeladonCity_DepartmentStore_3F_Text_RedGreenBothArePokemon::
	.string "Rouge et Vert!\n"
	.string "Deux jeux POKéMON!$"

Text_CounterTeach::
	.string "J'ai fini!!!!\n"
	.string "J'ai fini POKéMON!!!!\p"
	.string "Pas vous? Ça vous dirait\n"
	.string "d'apprendre une nouvelle capacité?\p"
	.string "Je pensais vous apprendre\n"
	.string "RIPOSTE, ça vous tente?$"

Text_CounterDeclined::
	.string "Non? Revenez si vous\n"
	.string "changez d'avis.$"

Text_CounterWhichMon::
	.string "A quel POKéMON enseigner\n"
	.string "RIPOSTE?$"

Text_CounterTaught::
	.string "Vous utilisez la capacité que je\n"
	.string "vous ai apprise?$"
