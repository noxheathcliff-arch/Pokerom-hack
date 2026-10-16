PetalburgCity_WallysHouse_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, PetalburgCity_WallysHouse_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, PetalburgCity_WallysHouse_OnWarp
	.byte 0

PetalburgCity_WallysHouse_OnWarp:
	map_script_2 VAR_PETALBURG_CITY_STATE, 4, PetalburgCity_WallysHouse_EventScript_PlayerWallysDadFaceEachOther
	.2byte 0

PetalburgCity_WallysHouse_EventScript_PlayerWallysDadFaceEachOther::
	turnobject LOCALID_PLAYER, DIR_EAST
	turnobject LOCALID_WALLYS_HOUSE_WALLYS_DAD, DIR_WEST
	end

PetalburgCity_WallysHouse_OnFrame:
	map_script_2 VAR_PETALBURG_CITY_STATE, 4, PetalburgCity_WallysHouse_EventScript_GiveHMSurf
	.2byte 0

PetalburgCity_WallysHouse_EventScript_GiveHMSurf::
	lockall
	msgbox PetalburgCity_WallysHouse_Text_PleaseExcuseUs, MSGBOX_DEFAULT
	giveitem ITEM_HM_SURF
	setflag FLAG_RECEIVED_HM_SURF
	msgbox PetalburgCity_WallysHouse_Text_SurfGoAllSortsOfPlaces, MSGBOX_DEFAULT
	setvar VAR_PETALBURG_CITY_STATE, 5
	releaseall
	end

PetalburgCity_WallysHouse_EventScript_WallysDad::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_WALLY_VICTORY_ROAD, PetalburgCity_WallysHouse_EventScript_DefeatedWallyInVictoryRoad
	goto_if_set FLAG_RECEIVED_HM_SURF, PetalburgCity_WallysHouse_EventScript_ReceievedHMSurf
	goto_if_set FLAG_THANKED_FOR_PLAYING_WITH_WALLY, PetalburgCity_WallysHouse_EventScript_PlayedWithWally
	msgbox PetalburgCity_WallysHouse_Text_ThanksForPlayingWithWally, MSGBOX_DEFAULT
	setflag FLAG_THANKED_FOR_PLAYING_WITH_WALLY
	release
	end

PetalburgCity_WallysHouse_EventScript_ReceievedHMSurf::
	msgbox PetalburgCity_WallysHouse_Text_WallyIsComingHomeSoon, MSGBOX_DEFAULT
	release
	end

PetalburgCity_WallysHouse_EventScript_DefeatedWallyInVictoryRoad::
	msgbox PetalburgCity_WallysHouse_Text_YouMetWallyInEverGrandeCity, MSGBOX_DEFAULT
	release
	end

PetalburgCity_WallysHouse_EventScript_PlayedWithWally::
	msgbox PetalburgCity_WallysHouse_Text_WonderHowWallyIsDoing, MSGBOX_DEFAULT
	release
	end

PetalburgCity_WallysHouse_EventScript_WallysMom::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_HM_SURF, PetalburgCity_WallysHouse_EventScript_ReceivedHMSurf
	msgbox PetalburgCity_WallysHouse_Text_WallyWasReallyHappy, MSGBOX_DEFAULT
	release
	end

PetalburgCity_WallysHouse_EventScript_ReceivedHMSurf::
	msgbox PetalburgCity_WallysHouse_Text_WallyLeftWithoutTelling, MSGBOX_DEFAULT
	release
	end

PetalburgCity_WallysHouse_Text_ThanksForPlayingWithWally:
	.string "Hé! On frappe avant d’entrer!\n"
	.string "Qui t’a dit que c’était ouvert?\p"
	.string "… Tu es l’étranger dont tout le monde\n"
	.string "parle. Celui des Seko.\p"
	.string "Mon fils a le souffle court depuis\n"
	.string "tout petit. On l’a envoyé à Vergazon.\p"
	.string "L’air y est meilleur, et on y voit\n"
	.string "moins d’uniformes.\p"
	.string "Si tu cherches un endroit où dormir,\n"
	.string "ce n’est pas ici. Désolé.$"

PetalburgCity_WallysHouse_Text_WonderHowWallyIsDoing:
	.string "Encore toi? Je n’ai rien à te dire.\n"
	.string "Ferme la porte, il y a des oreilles.$"

PetalburgCity_WallysHouse_Text_PleaseExcuseUs:
	.string "{PLAYER}{KUN}! Merci d'avoir accepté\n"
	.string "de venir.\p"
	.string "Notre TIMMY est en meilleure santé\n"
	.string "depuis qu'il est allé à VERGAZON.\p"
	.string "Et c'est à toi que nous le devons!\p"
	.string "Quand TIMMY a quitté la ville, tu l'as\n"
	.string "aidé à attraper un POKéMON, pas vrai?\p"
	.string "Je pense que ça l'a rendu très heureux.\p"
	.string "En fait, il n'y a pas que lui. Cela m'a\n"
	.string "aussi rendu heureux, moi son père.\p"
	.string "Quelle chance pour lui d'avoir comme\n"
	.string "camarade quelqu'un d'aussi bien que toi!\p"
	.string "Ce n'est pas pour te flatter, mais\n"
	.string "j'aimerais que tu acceptes ça.$"

PetalburgCity_WallysHouse_Text_SurfGoAllSortsOfPlaces:
	.string "Si ton POKéMON peut utiliser SURF,\n"
	.string "tu découvriras toutes sortes de lieux.$"

PetalburgCity_WallysHouse_Text_WallyIsComingHomeSoon:
	.string "TIMMY va bientôt rentrer.\n"
	.string "Je l'attends avec impatience.$"

PetalburgCity_WallysHouse_Text_YouMetWallyInEverGrandeCity:
	.string "Ah? Tu as vu TIMMY à ETERNARA?\p"
	.string "Oh, {PLAYER}{KUN}, ne dis pas n'importe quoi!\p"
	.string "Même s'il va mieux, il n'a pas\n"
	.string "pu aller aussi loin tout seul.$"

PetalburgCity_WallysHouse_Text_WallyWasReallyHappy:
	.string "Ne fais pas attention à mon mari.\n"
	.string "Il a peur, comme tout le monde.\p"
	.string "Le Rempart est passé hier. Ils ont\n"
	.string "noté nos noms, nos Pokémon.\p"
	.string "Notre fils était si heureux d’avoir\n"
	.string "son premier Pokémon…\p"
	.string "J’espère qu’ils ne le lui prendront\n"
	.string "pas pour leur ‘effort commun’.$"

PetalburgCity_WallysHouse_Text_WallyLeftWithoutTelling:
	.string "N'en parle pas à mon mari…\p"
	.string "Mais notre TIMMY a quitté VERGAZON\n"
	.string "sans rien dire à personne.\p"
	.string "Tu sais, TIMMY est frêle, mais\n"
	.string "il a beaucoup de volonté.\p"
	.string "Je suis sûre qu'il rentrera bientôt\n"
	.string "sain et sauf.$"

