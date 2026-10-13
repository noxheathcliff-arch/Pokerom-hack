TwoIsland_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, TwoIsland_OnTransition
	.byte 0

TwoIsland_OnTransition::
	setworldmapflag FLAG_WORLD_MAP_TWO_ISLAND
	setflag FLAG_VISITED_TWO_ISLAND
	call TwoIsland_EventScript_SetShopState
	end

TwoIsland_EventScript_SetShopState::
	goto_if_set FLAG_IS_CHAMPION, TwoIsland_EventScript_SetShopStateAfterHoennLink
	goto_if_set FLAG_SYS_GAME_CLEAR, TwoIsland_EventScript_SetShopStateAfterChampion
	goto_if_set FLAG_RESCUED_LOSTELLE, TwoIsland_EventScript_SetShopStateAfterLostelleRescue
	goto TwoIsland_EventScript_SetShopStateDefault
	end

TwoIsland_EventScript_SetShopStateAfterHoennLink::
	goto_if_unset FLAG_TWO_ISLAND_SHOP_INTRODUCED, TwoIsland_EventScript_SetShopInitial
	goto_if_unset FLAG_TWO_ISLAND_SHOP_EXPANDED_1, TwoIsland_EventScript_SetShopExpanded1
	goto_if_unset FLAG_TWO_ISLAND_SHOP_EXPANDED_2, TwoIsland_EventScript_SetShopExpanded2
	goto TwoIsland_EventScript_SetShopExpanded3
	end

TwoIsland_EventScript_SetShopStateAfterChampion::
	goto_if_unset FLAG_TWO_ISLAND_SHOP_INTRODUCED, TwoIsland_EventScript_SetShopInitial
	goto_if_unset FLAG_RESCUED_LOSTELLE, TwoIsland_EventScript_SetShopInitial
	goto_if_unset FLAG_TWO_ISLAND_SHOP_EXPANDED_1, TwoIsland_EventScript_SetShopExpanded1
	goto TwoIsland_EventScript_SetShopExpanded2
	end

TwoIsland_EventScript_SetShopStateAfterLostelleRescue::
	goto_if_unset FLAG_TWO_ISLAND_SHOP_INTRODUCED, TwoIsland_EventScript_SetShopInitial
	goto TwoIsland_EventScript_SetShopExpanded1
	end

TwoIsland_EventScript_SetShopStateDefault::
	goto TwoIsland_EventScript_SetShopInitial
	end

TwoIsland_EventScript_SetShopInitial::
	setvar VAR_MAP_SCENE_TWO_ISLAND, 1
	return

TwoIsland_EventScript_SetShopExpanded1::
	setvar VAR_MAP_SCENE_TWO_ISLAND, 2
	clearflag FLAG_HIDE_TWO_ISLAND_WOMAN
	return

TwoIsland_EventScript_SetShopExpanded2::
	setvar VAR_MAP_SCENE_TWO_ISLAND, 3
	clearflag FLAG_HIDE_TWO_ISLAND_BEAUTY
	return

TwoIsland_EventScript_SetShopExpanded3::
	setvar VAR_MAP_SCENE_TWO_ISLAND, 4
	clearflag FLAG_HIDE_TWO_ISLAND_SUPER_NERD
	return

TwoIsland_EventScript_Clerk::
	lock
	faceplayer
	goto_if_eq VAR_MAP_SCENE_TWO_ISLAND, 4, TwoIsland_EventScript_ClerkShopExpanded3
	goto_if_eq VAR_MAP_SCENE_TWO_ISLAND, 3, TwoIsland_EventScript_ClerkShopExpanded2
	goto_if_eq VAR_MAP_SCENE_TWO_ISLAND, 2, TwoIsland_EventScript_ClerkShopExpanded1
	goto TwoIsland_EventScript_ClerkShopInitial
	end

TwoIsland_EventScript_ClerkShopExpanded3::
	goto_if_set FLAG_TWO_ISLAND_SHOP_EXPANDED_3, TwoIsland_EventScript_ClerkShopSkipIntro
	setflag FLAG_TWO_ISLAND_SHOP_EXPANDED_3
	message TwoIsland_Text_BringingItemsFromDistantLands
	waitmessage
	goto TwoIsland_EventScript_ShopExpanded3
	end

TwoIsland_EventScript_ClerkShopExpanded2::
	goto_if_set FLAG_TWO_ISLAND_SHOP_EXPANDED_2, TwoIsland_EventScript_ClerkShopSkipIntro
	setflag FLAG_TWO_ISLAND_SHOP_EXPANDED_2
	message TwoIsland_Text_HopeYouGiveItYourBest
	waitmessage
	goto TwoIsland_EventScript_ShopExpanded2
	end

TwoIsland_EventScript_ClerkShopExpanded1::
	goto_if_set FLAG_TWO_ISLAND_SHOP_EXPANDED_1, TwoIsland_EventScript_ClerkShopSkipIntro
	setflag FLAG_TWO_ISLAND_SHOP_EXPANDED_1
	message TwoIsland_Text_AddedMerchandiseForLostelle
	waitmessage
	goto TwoIsland_EventScript_ShopExpanded1
	end

TwoIsland_EventScript_ClerkShopInitial::
	goto_if_set FLAG_TWO_ISLAND_SHOP_INTRODUCED, TwoIsland_EventScript_ClerkShopSkipIntro
	setflag FLAG_TWO_ISLAND_SHOP_INTRODUCED
	message TwoIsland_Text_WelcomeToShopMerchandiseLimited
	waitmessage
	goto TwoIsland_EventScript_ShopInitial
	end

TwoIsland_EventScript_ClerkShopSkipIntro::
	message gText_HowMayIServeYou
	waitmessage
	goto_if_eq VAR_MAP_SCENE_TWO_ISLAND, 4, TwoIsland_EventScript_ShopExpanded3
	goto_if_eq VAR_MAP_SCENE_TWO_ISLAND, 3, TwoIsland_EventScript_ShopExpanded2
	goto_if_eq VAR_MAP_SCENE_TWO_ISLAND, 2, TwoIsland_EventScript_ShopExpanded1
	goto TwoIsland_EventScript_ShopInitial
	end

TwoIsland_EventScript_ShopInitial::
	pokemart TwoIsland_Items_ShopInitial
	msgbox gText_PleaseComeAgain
	release
	end

	.align 2
TwoIsland_Items_ShopInitial::
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_FRESH_WATER
	.2byte ITEM_NONE
	release
	end

TwoIsland_EventScript_ShopExpanded1::
	pokemart TwoIsland_Items_ShopExpanded1
	msgbox gText_PleaseComeAgain
	release
	end

	.align 2
TwoIsland_Items_ShopExpanded1::
	.2byte ITEM_ULTRA_BALL
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_SODA_POP
	.2byte ITEM_FRESH_WATER
	.2byte ITEM_NONE
	release
	end

TwoIsland_EventScript_ShopExpanded2::
	pokemart TwoIsland_Items_ShopExpanded2
	msgbox gText_PleaseComeAgain
	release
	end

	.align 2
TwoIsland_Items_ShopExpanded2::
	.2byte ITEM_ULTRA_BALL
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_LEMONADE
	.2byte ITEM_SODA_POP
	.2byte ITEM_FRESH_WATER
	.2byte ITEM_MOOMOO_MILK
	.2byte ITEM_NONE
	release
	end

TwoIsland_EventScript_ShopExpanded3::
	pokemart TwoIsland_Items_ShopExpanded3
	msgbox gText_PleaseComeAgain
	release
	end

	.align 2
TwoIsland_Items_ShopExpanded3::
	.2byte ITEM_ULTRA_BALL
	.2byte ITEM_REPEAT_BALL
	.2byte ITEM_TIMER_BALL
	.2byte ITEM_LEMONADE
	.2byte ITEM_SODA_POP
	.2byte ITEM_FRESH_WATER
	.2byte ITEM_MOOMOO_MILK
	.2byte ITEM_LAVA_COOKIE
	.2byte ITEM_NONE
	release
	end

TwoIsland_EventScript_Sailor::
	msgbox TwoIsland_Text_FellowMovedFromCeladonCity, MSGBOX_NPC
	end

TwoIsland_EventScript_Woman::
	msgbox TwoIsland_Text_ShopkeepersBrotherWorksGameCorner, MSGBOX_NPC
	end

TwoIsland_EventScript_Beauty::
	lock
	faceplayer
	famechecker FAMECHECKER_BRUNO, 4
	msgbox TwoIsland_Text_BrunoCameToIslandWhileBack
	release
	end

TwoIsland_EventScript_SuperNerd::
	msgbox TwoIsland_Text_BuyRareItemsHere, MSGBOX_NPC
	end

TwoIsland_EventScript_Boy::
	msgbox TwoIsland_Text_OldWomanLivesOutOnCape, MSGBOX_NPC
	end

TwoIsland_EventScript_LittleBoy::
	msgbox TwoIsland_Text_HaveYouTriedJumpingGame, MSGBOX_NPC
	end

TwoIsland_EventScript_IslandSign::
	msgbox TwoIsland_Text_IslandSign, MSGBOX_SIGN
	end

TwoIsland_EventScript_JoyfulGameCornerSign::
	msgbox TwoIsland_Text_JoyfulGameCornerSign, MSGBOX_SIGN
	end

TwoIsland_EventScript_FastCurrentSign::
	msgbox TwoIsland_Text_DangerFastCurrent, MSGBOX_SIGN
	end

TwoIsland_Text_IslandSign::
	.string "ILE 2\n"
	.string "Le bonheur à deux$"

TwoIsland_Text_JoyfulGameCornerSign::
	.string "SALLE DE JEU\n"
	.string "Affrontez vos adversaires$"

TwoIsland_Text_DangerFastCurrent::
	.string "DANGER! RAPIDES!\n"
	.string "Surf et pêche interdits!$"

TwoIsland_Text_WelcomeToShopMerchandiseLimited::
	.string "Oh, bienvenue dans ma boutique!\p"
	.string "Nous n'avons ouvert que très\n"
	.string "récemment.\p"
	.string "Nos stocks sont limités mais\n"
	.string "j'espère vous servir au mieux.$"

TwoIsland_Text_AddedMerchandiseForLostelle::
	.string "Je ne trouve pas les mots pour\n"
	.string "vous remercier d'avoir sauvé\p"
	.string "LOSTELLE. Grâce à vos exploits,\n"
	.string "les habitants de l'ILE 3 ont\p"
	.string "changé leurs idées reçues sur\n"
	.string "les gens de KANTO.\p"
	.string "Je suis de KANTO, vous savez.\p"
	.string "Les gens de l'ILE 3 m'ont aidé à\n"
	.string "monter mon STAND.$"

TwoIsland_Text_HopeYouGiveItYourBest::
	.string "Je donne le meilleur de moi-même.\n"
	.string "J'espère que vous aussi, {PLAYER}.$"

TwoIsland_Text_BringingItemsFromDistantLands::
	.string "Oh, bonjour, {PLAYER}!\n"
	.string "Bienvenue!\p"
	.string "J'ai commencé à rapporter des\n"
	.string "objets des îles aux alentours.\p"
	.string "J'en ai de très rares, vous devriez\n"
	.string "venir voir.$"

TwoIsland_Text_FellowMovedFromCeladonCity::
	.string "Ce type là, il est venu de\n"
	.string "CELADOPOLE pour s'installer ici.\p"
	.string "Il a ouvert un STAND avec son\n"
	.string "jeune frère.\p"
	.string "Je me demande s'il sait dans quoi\n"
	.string "il s'est embarqué.$"

TwoIsland_Text_ShopkeepersBrotherWorksGameCorner::
	.string "Le frère du vendeur du STAND\n"
	.string "a un job à la SALLE DE JEU.\p"
	.string "Ils essaient d'économiser à deux\n"
	.string "pour acheter plus de marchandises.$"

TwoIsland_Text_BrunoCameToIslandWhileBack::
	.string "Ecoute, écoute.\p"
	.string "Un DRESSEUR célèbre est venu\n"
	.string "sur l'ILE il y a quelque temps.\p"
	.string "Il fait partie du CONSEIL 4,\n"
	.string "il s'appelle ALDO.\p"
	.string "Il est reparti très déçu quand\n"
	.string "il a vu que les SUPER BONBONS\p"
	.string "étaient en rupture de stock\n"
	.string "partout.$"

TwoIsland_Text_BuyRareItemsHere::
	.string "Les DRESSEURS futés savent que\n"
	.string "les objets rares se trouvent ici.$"

TwoIsland_Text_OldWomanLivesOutOnCape::
	.string "Il y a une femme qui vit au bout\n"
	.string "du cap.\p"
	.string "Elle fait des commentaires sur\n"
	.string "les POKéMON.\p"
	.string "C'est super troublant.$"

TwoIsland_Text_HaveYouTriedJumpingGame::
	.string "Boing, boing!\n"
	.string "T'as essayé le jeu de saut?\p"
	.string "Il te faut des POKéMON qui\n"
	.string "peuvent… boing, boing!\p"
	.string "Y'en a qui font boing!\n"
	.string "Et d'autres boiiiiiing!\p"
	.string "Tu savais pas, hein?$"

