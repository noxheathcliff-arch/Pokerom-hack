LavenderTown_House2_Frlg_MapScripts::
	.byte 0

LavenderTown_House2_EventScript_NameRater::
	lock
	faceplayer
	msgbox LavenderTown_House2_Text_WantMeToRateNicknames, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, LavenderTown_House2_EventScript_ChooseMon
	goto_if_eq VAR_RESULT, NO, LavenderTown_House2_EventScript_DontRateNickname
	end

LavenderTown_House2_EventScript_ChooseMon::
	msgbox LavenderTown_House2_Text_CritiqueWhichMonsNickname
	special ChoosePartyMon
	goto_if_lt VAR_0x8004, PARTY_SIZE, LavenderTown_House2_EventScript_CheckCanRateMon
	goto_if_ge VAR_0x8004, PARTY_SIZE, LavenderTown_House2_EventScript_DontRateNickname
	end

LavenderTown_House2_EventScript_DontRateNickname::
	msgbox LavenderTown_House2_Text_ISeeComeVisitAgain
	release
	end

LavenderTown_House2_EventScript_CheckCanRateMon::
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	goto_if_eq VAR_RESULT, SPECIES_EGG, LavenderTown_House2_EventScript_CantNicknameEgg
	special BufferMonNickname
	special IsMonOTIDNotPlayers
	goto_if_eq VAR_RESULT, TRUE, LavenderTown_House2_EventScript_CantNicknameTradeMon
	specialvar VAR_RESULT, MonOTNameNotPlayer
	special BufferMonNickname
	goto_if_eq VAR_RESULT, TRUE, LavenderTown_House2_EventScript_CantNicknameTradeMon
	msgbox LavenderTown_House2_Text_GiveItANicerName, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, LavenderTown_House2_EventScript_ChooseNewNickname
	goto_if_eq VAR_RESULT, NO, LavenderTown_House2_EventScript_DontRateNickname
	end

LavenderTown_House2_EventScript_CantNicknameEgg::
	msgbox LavenderTown_House2_Text_ThatIsMerelyAnEgg
	release
	end

LavenderTown_House2_EventScript_CantNicknameTradeMon::
	msgbox LavenderTown_House2_Text_TrulyImpeccableName
	release
	end

LavenderTown_House2_EventScript_ChooseNewNickname::
	msgbox LavenderTown_House2_Text_WhatShallNewNicknameBe
	call Common_EventScript_NameReceivedPartyMon
	specialvar VAR_RESULT, TryPutNameRaterShowOnTheAir
	special BufferMonNickname
	goto_if_eq VAR_RESULT, TRUE, LavenderTown_House2_EventScript_ChoseNewNickname
	msgbox LavenderTown_House2_Text_FromNowOnShallBeKnownAsSameName
	release
	end

LavenderTown_House2_EventScript_ChoseNewNickname::
	msgbox LavenderTown_House2_Text_FromNowOnShallBeKnownAsName
	release
	end

LavenderTown_House2_Text_WantMeToRateNicknames::
	.string "Salut tout le monde! Je suis le\n"
	.string "SPECIALISTE DES NOMS!\p"
	.string "Dis-moi, tu serais pas du\n"
	.string "genre à vouloir donner un p'tit\l"
	.string "nom à un de tes POKéMON?$"

LavenderTown_House2_Text_CritiqueWhichMonsNickname::
	.string "Le surnom de quel POKéMON veux-tu\n"
	.string "que j'examine?$"

LavenderTown_House2_Text_GiveItANicerName::
	.string "{STR_VAR_1}?\n"
	.string "Mouais, c'est pas mal!\p"
	.string "Mais tu voudrais pas que je lui\n"
	.string "donne un nom un peu… plus…\l"
	.string "qui aurait plus de… Mieux, quoi!\p"
	.string "Bon, alors?$"

LavenderTown_House2_Text_WhatShallNewNicknameBe::
	.string "Bon, alors quel va être le nouveau\n"
	.string "surnom?$"

LavenderTown_House2_Text_FromNowOnShallBeKnownAsName::
	.string "Très bien! A partir de maintenant,\n"
	.string "ce POKéMON sera surnommé\l"
	.string "{STR_VAR_1}!\p"
	.string "C'est mieux qu'avant!\n"
	.string "Tu en as de la chance!$"

LavenderTown_House2_Text_ISeeComeVisitAgain::
	.string "Je vois.\n"
	.string "Reviens me voir.$"

LavenderTown_House2_Text_FromNowOnShallBeKnownAsSameName::
	.string "Ça y est! A partir de maintenant,\n"
	.string "ce POKéMON sera surnommé\l"
	.string "{STR_VAR_1}!\p"
	.string "Ce surnom ne semble pas très\n"
	.string "différent de l'autre et pourtant,\l"
	.string "il est bien mieux!\p"
	.string "Tu en as de la chance!$"

LavenderTown_House2_Text_TrulyImpeccableName::
	.string "{STR_VAR_1}?\n"
	.string "C'est un nom parfait, fais-moi\l"
	.string "confiance, je m'y connais!\p"
	.string "Prends soin de {STR_VAR_1}.$"

LavenderTown_House2_Text_ThatIsMerelyAnEgg::
	.string "Voyons, voyons…\n"
	.string "Ce n'est qu'un OEUF!$"

