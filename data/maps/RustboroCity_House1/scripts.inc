RustboroCity_House1_MapScripts::
	.byte 0

RustboroCity_House1_EventScript_Trader::
	lock
	faceplayer
	goto_if_set FLAG_RUSTBORO_NPC_TRADE_COMPLETED, RustboroCity_House1_EventScript_TradeCompleted
	ingame_trade INGAME_TRADE_SEEDOT, RustboroCity_House1_Text_IllTradeIfYouWant, RustboroCity_House1_EventScript_DeclineTrade, RustboroCity_House1_EventScript_NotRequestedMon, RustboroCity_House1_Text_PleaseBeGoodToMyPokemon
	setflag FLAG_RUSTBORO_NPC_TRADE_COMPLETED
	release
	end

RustboroCity_House1_EventScript_DeclineTrade::
	msgbox RustboroCity_House1_Text_YouDontWantToThatsOkay, MSGBOX_DEFAULT
	release
	end

RustboroCity_House1_EventScript_NotRequestedMon::
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox RustboroCity_House1_Text_DoesntLookLikeMonToMe, MSGBOX_DEFAULT
	release
	end

RustboroCity_House1_EventScript_TradeCompleted::
	msgbox RustboroCity_House1_Text_AnyPokemonCanBeCute, MSGBOX_DEFAULT
	release
	end

RustboroCity_House1_EventScript_Hiker::
	msgbox RustboroCity_House1_Text_AllSortsOfPlaces, MSGBOX_NPC
	end

RustboroCity_House1_Text_IllTradeIfYouWant:
	.string "Hein? Mon POKéMON est mignon?\n"
	.string "Bien sûr que je le sais.\p"
	.string "Mais si tu veux, je suis d'accord pour\n"
	.string "te l'échanger.\p"
	.string "Je t'échange mon {STR_VAR_2} contre\n"
	.string "un {STR_VAR_1} si tu veux.$"

RustboroCity_House1_Text_PleaseBeGoodToMyPokemon:
	.string "Hé hé…\n"
	.string "Sois sympa avec mon POKéMON.$"

RustboroCity_House1_Text_DoesntLookLikeMonToMe:
	.string "Hein? Il ressemble pas vraiment à\n"
	.string "un {STR_VAR_1}!$"

RustboroCity_House1_Text_YouDontWantToThatsOkay:
	.string "Oh, si tu ne veux pas, c'est d'accord.\n"
	.string "Mais il est vraiment mignon, tu sais?$"

RustboroCity_House1_Text_AnyPokemonCanBeCute:
	.string "Tous les POKéMON peuvent être mignons\n"
	.string "s'ils sont élevés avec gentillesse.$"

RustboroCity_House1_Text_AllSortsOfPlaces:
	.string "Chaque endroit a ses types précis de\n"
	.string "POKéMON et de personnes.\p"
	.string "Je trouve ça si fascinant que je me\n"
	.string "balade un peu partout.$"

