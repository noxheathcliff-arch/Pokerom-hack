FourIsland_LoreleisHouse_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, FourIsland_LoreleisHouse_OnTransition
	.byte 0

FourIsland_LoreleisHouse_OnTransition::
	special UpdateLoreleiDollCollection
	end

FourIsland_LoreleisHouse_EventScript_Lorelei::
	lock
	faceplayer
	goto_if_set FLAG_TALKED_TO_LORELEI_AFTER_WAREHOUSE, FourIsland_LoreleisHouse_EventScript_Lorelei3
	goto_if_set FLAG_DEFEATED_ROCKETS_IN_WAREHOUSE, FourIsland_LoreleisHouse_EventScript_Lorelei2
	msgbox FourIsland_LoreleisHouse_Text_IfAnythingWereToHappenToIsland
	release
	end

FourIsland_LoreleisHouse_EventScript_Lorelei2::
	setflag FLAG_TALKED_TO_LORELEI_AFTER_WAREHOUSE
	msgbox FourIsland_LoreleisHouse_Text_IllReturnToLeagueInShortWhile
	release
	end

FourIsland_LoreleisHouse_EventScript_Lorelei3::
	msgbox FourIsland_LoreleisHouse_Text_WillDoWhatICanHereAndNow
	release
	end

FourIsland_LoreleisHouse_EventScript_Doll::
	lock
	msgbox FourIsland_LoreleisHouse_Text_StuffedMonDollsGalore
	release
	end

FourIsland_LoreleisHouse_Text_IfAnythingWereToHappenToIsland::
	.string "OLGA: Je n'arrête pas de penzer\n"
	.string "à quelque choze.\p"
	.string "Z'il devait arriver malheur zur mon\n"
	.string "île natale pendant que je zuis\p"
	.string "à la LIGUE POKéMON…\p"
	.string "Je n'aurais aucun moyen de le\n"
	.string "zavoir…\p"
	.string "Est-ce que za fait de moi\n"
	.string "quelqu'un d'irresponzable?$"

FourIsland_LoreleisHouse_Text_IllReturnToLeagueInShortWhile::
	.string "OLGA: Zo, alors tu as réuzzi à\n"
	.string "régler les problèmes?\p"
	.string "Z'est fantaztique!\p"
	.string "Za veut dire que je peux repartir\n"
	.string "l'ezprit tranquille.\p"
	.string "Merci…\p"
	.string "Je vais bientôt repartir pour la\n"
	.string "LIGUE POKéMON.$"

FourIsland_LoreleisHouse_Text_WillDoWhatICanHereAndNow::
	.string "Je ne zais pas ze qui peut se\n"
	.string "pazzer dans le futur, mais…\p"
	.string "Tant que je zerai là, je\n"
	.string "protégerai zette île.$"

FourIsland_LoreleisHouse_Text_StuffedMonDollsGalore::
	.string "Il y a plein de poupées POKéMON.$"

