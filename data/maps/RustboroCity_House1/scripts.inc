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
	.string "Mon Pokémon est mignon?\n"
	.string "Je sais, je sais.\p"
	.string "Mais j’ai peur que la brigade me le\n"
	.string "prenne. Il est né loin d’ici.\p"
	.string "Je t’échange mon {STR_VAR_2} contre\n"
	.string "un {STR_VAR_1}. D’accord?$"

RustboroCity_House1_Text_PleaseBeGoodToMyPokemon:
	.string "Merci. Il sera plus en\n"
	.string "sécurité avec toi.$"

RustboroCity_House1_Text_DoesntLookLikeMonToMe:
	.string "Hein? Ça, ce n’est pas\n"
	.string "un {STR_VAR_1}!$"

RustboroCity_House1_Text_YouDontWantToThatsOkay:
	.string "Tant pis. Je le cacherai\n"
	.string "encore un peu, alors.$"

RustboroCity_House1_Text_AnyPokemonCanBeCute:
	.string "Un Pokémon élevé avec douceur\n"
	.string "devient adorable. Même un arrivant.\p"
	.string "Ne le dis pas trop fort. Ici,\n"
	.string "ce genre d’idée, ça dérange.$"

RustboroCity_House1_Text_AllSortsOfPlaces:
	.string "J’ai marché dans toute la région.\n"
	.string "Chaque coin a ses Pokémon.\p"
	.string "Maintenant, il faut un laissez-passer\n"
	.string "pour sortir de la ville.\p"
	.string "Si tu vas vers Vergazon, oublie\n"
	.string "le Tunnel Mérazon. Plein d’arrivants.$"

