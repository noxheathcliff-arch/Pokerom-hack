CeladonCity_Restaurant_Frlg_MapScripts::
	.byte 0

CeladonCity_Restaurant_EventScript_Chef::
	msgbox CeladonCity_Restaurant_Text_TakingBreakRightNow, MSGBOX_NPC
	end

CeladonCity_Restaurant_EventScript_Woman::
	msgbox CeladonCity_Restaurant_Text_OftenGoToDrugstore, MSGBOX_NPC
	end

CeladonCity_Restaurant_EventScript_CoinCaseMan::
	lock
	faceplayer
	goto_if_set FLAG_GOT_COIN_CASE, CeladonCity_Restaurant_EventScript_AlreadyGotCoinCase
	msgbox CeladonCity_Restaurant_Text_TakeThisImBusted
	checkitemspace ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, CeladonCity_Restaurant_EventScript_NoRoomForCoinCase
	giveitem_msg CeladonCity_Restaurant_Text_ReceivedCoinCaseFromMan, ITEM_COIN_CASE
	setflag FLAG_GOT_COIN_CASE
	release
	end

CeladonCity_Restaurant_EventScript_NoRoomForCoinCase::
	msgbox CeladonCity_Restaurant_Text_MakeRoomForThis
	release
	end

CeladonCity_Restaurant_EventScript_AlreadyGotCoinCase::
	msgbox CeladonCity_Restaurant_Text_ThoughtIdWinItBack
	release
	end

CeladonCity_Restaurant_EventScript_WorkerM::
	msgbox CeladonCity_Restaurant_Text_PsstBasementUnderGameCorner, MSGBOX_NPC
	end

CeladonCity_Restaurant_EventScript_FatMan::
	msgbox CeladonCity_Restaurant_Text_ManLostItAllAtSlots, MSGBOX_NPC
	end

CeladonCity_Restaurant_Text_TakingBreakRightNow::
	.string "Salut!\p"
	.string "On fait une p'tite pause là.$"

CeladonCity_Restaurant_Text_OftenGoToDrugstore::
	.string "Mes POKéMON sont faibles alors je\n"
	.string "vais souvent acheter des\l"
	.string "accélérateurs.$"

CeladonCity_Restaurant_Text_PsstBasementUnderGameCorner::
	.string "Pssst! Il y a un truc sous le\n"
	.string "CASINO.$"

CeladonCity_Restaurant_Text_ManLostItAllAtSlots::
	.string "Miam…\p"
	.string "Le type à cette table a tout\n"
	.string "perdu…$"

CeladonCity_Restaurant_Text_TakeThisImBusted::
	.string "Vas-y! Rigole!\n"
	.string "J'ai plus une thune!\p"
	.string "C'est marrant, hein? Pfff…\n"
	.string "Je te hais!\p"
	.string "Prends ça tiens!\n"
	.string "Et surtout, perds tout ton blé!$"

CeladonCity_Restaurant_Text_ReceivedCoinCaseFromMan::
	.string "{PLAYER} reçoit\n"
	.string "BOITE JETONS!$"

CeladonCity_Restaurant_Text_MakeRoomForThis::
	.string "T'as plus de place!$"

CeladonCity_Restaurant_Text_ThoughtIdWinItBack::
	.string "Faut qu'j'me refasse…$"

