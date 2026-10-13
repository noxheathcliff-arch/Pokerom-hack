.equ REQUIRED_OWNED_MONS, 20

Route10_PokemonCenter_1F_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route10_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

Route10_PokemonCenter_1F_OnTransition::
	setworldmapflag FLAG_WORLD_MAP_ROUTE10_POKEMON_CENTER_1F
	setrespawn HEAL_LOCATION_ROUTE10
	end

Route10_PokemonCenter_1F_EventScript_Nurse::
	lock
	faceplayer
	call EventScript_PkmnCenterNurse_Frlg
	release
	end

Route10_PokemonCenter_1F_EventScript_FatMan::
	msgbox Route10_PokemonCenter_1F_Text_NuggetUselessSoldFor5000, MSGBOX_NPC
	end

Route10_PokemonCenter_1F_EventScript_Gentleman::
	msgbox Route10_PokemonCenter_1F_Text_EveryTypeStrongerThanOthers, MSGBOX_NPC
	end

Route10_PokemonCenter_1F_EventScript_Youngster::
	msgbox Route10_PokemonCenter_1F_Text_HeardGhostsHauntLavender, MSGBOX_NPC
	end

Route10_PokemonCenter_1F_EventScript_Aide::
	lock
	faceplayer
	call Route10_PokemonCenter_1F_EventScript_GetAideRequestInfo
	goto_if_set FLAG_GOT_EVERSTONE_FROM_OAKS_AIDE, Route10_PokemonCenter_1F_EventScript_AlreadyGotEverstone
	msgbox Route10_PokemonCenter_1F_Text_GiveEverstoneIfCaught20Mons, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Aide_EventScript_DeclineCheckMons
	setvar VAR_0x8004, 0
	specialvar VAR_RESULT, GetFrlgPokedexCount
	buffernumberstring STR_VAR_3, VAR_0x8006
	call Route10_PokemonCenter_1F_EventScript_GetAideRequestInfo
	goto_if_lt VAR_0x8006, REQUIRED_OWNED_MONS, Aide_EventScript_HaventCaughtEnough
	msgbox Route10_PokemonCenter_1F_Text_GreatHereYouGo
	checkitemspace ITEM_EVERSTONE
	goto_if_eq VAR_RESULT, FALSE, Aide_EventScript_NoRoomForItem
	giveitem_msg Route10_PokemonCenter_1F_Text_ReceivedEverstoneFromAide, ITEM_EVERSTONE
	setflag FLAG_GOT_EVERSTONE_FROM_OAKS_AIDE
	msgbox Route10_PokemonCenter_1F_Text_ExplainEverstone
	release
	end

Route10_PokemonCenter_1F_EventScript_AlreadyGotEverstone::
	msgbox Route10_PokemonCenter_1F_Text_ExplainEverstone
	release
	end

Route10_PokemonCenter_1F_EventScript_GetAideRequestInfo::
	buffernumberstring STR_VAR_1, REQUIRED_OWNED_MONS
	bufferitemname STR_VAR_2, ITEM_EVERSTONE
	return

Route10_PokemonCenter_1F_Text_EveryTypeStrongerThanOthers::
	.string "Le type d'un POKéMON l'avantage\n"
	.string "ou pas par rapport aux autres.\p"
	.string "Chaque type a des avantages et\n"
	.string "des inconvénients.$"

Route10_PokemonCenter_1F_Text_NuggetUselessSoldFor5000::
	.string "J'ai vendu une PEPITE pour 5000¥!$"

Route10_PokemonCenter_1F_Text_HeardGhostsHauntLavender::
	.string "On m'a dit qu'il y a des SPECTRES\n"
	.string "à LAVANVILLE!$"

Route10_PokemonCenter_1F_Text_GiveEverstoneIfCaught20Mons::
	.string "Salut, {PLAYER}! Je te cherchais.\n"
	.string "Je suis un assistant du PROF. CHEN!\p"
	.string "Si tu attrapes vingt POKéMON\n"
	.string "différents, je suis censé t'offrir\l"
	.string "cette PIERRE STASE!\p"
	.string "Alors {PLAYER}, as-tu attrapé au\n"
	.string "moins vingt POKéMON différents?$"

Route10_PokemonCenter_1F_Text_GreatHereYouGo::
	.string "Super! Tu as {STR_VAR_3} POKéMON\n"
	.string "différents!\p"
	.string "Félicitations!\n"
	.string "Voici ta récompense!$"

Route10_PokemonCenter_1F_Text_ReceivedEverstoneFromAide::
	.string "{PLAYER} obtient une\n"
	.string "PIERRE STASE!$"

Route10_PokemonCenter_1F_Text_ExplainEverstone::
	.string "Tu peux agrandir ton POKéDEX\n"
	.string "en faisant évoluer tes POKéMON.\p"
	.string "Mais il se peut que tu ne veuilles\n"
	.string "pas faire évoluer un POKéMON.\p"
	.string "Dans ce cas, donne cette\n"
	.string "PIERRE STASE à ton POKéMON.\p"
	.string "Selon le PROFESSEUR, ça\n"
	.string "l'empêchera d'évoluer.$"

