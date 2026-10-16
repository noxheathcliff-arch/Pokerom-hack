RustboroCity_DevonCorp_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, RustboroCity_DevonCorp_1F_OnTransition
	.byte 0

RustboroCity_DevonCorp_1F_OnTransition:
	call_if_unset FLAG_RETURNED_DEVON_GOODS, RustboroCity_DevonCorp_1F_EventScript_BlockStairs
	end

RustboroCity_DevonCorp_1F_EventScript_BlockStairs::
	setobjectxyperm LOCALID_DEVON_CORP_STAIR_GUARD, 14, 2
	setobjectmovementtype LOCALID_DEVON_CORP_STAIR_GUARD, MOVEMENT_TYPE_FACE_DOWN
	return

RustboroCity_DevonCorp_1F_EventScript_Employee::
	lock
	faceplayer
	goto_if_set FLAG_RETURNED_DEVON_GOODS, RustboroCity_DevonCorp_1F_EventScript_GoodsRecovered
	goto_if_set FLAG_DEVON_GOODS_STOLEN, RustboroCity_DevonCorp_1F_EventScript_RobberWasntBright
	msgbox RustboroCity_DevonCorp_1F_Text_ThoseShoesAreOurProduct, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_RobberWasntBright::
	msgbox RustboroCity_DevonCorp_1F_Text_RobberWasntVeryBright, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_GoodsRecovered::
	msgbox RustboroCity_DevonCorp_1F_Text_SoundsLikeStolenGoodsRecovered, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_StairGuard::
	lock
	faceplayer
	goto_if_set FLAG_RETURNED_DEVON_GOODS, RustboroCity_DevonCorp_1F_EventScript_AlwaysWelcome
	goto_if_set FLAG_RECOVERED_DEVON_GOODS, RustboroCity_DevonCorp_1F_EventScript_GotRobbed
	goto_if_set FLAG_DEVON_GOODS_STOLEN, RustboroCity_DevonCorp_1F_EventScript_GotRobbed
	msgbox RustboroCity_DevonCorp_1F_Text_OnlyAuthorizedPeopleEnter, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_AlwaysWelcome::
	msgbox RustboroCity_DevonCorp_1F_Text_YoureAlwaysWelcomeHere, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_GotRobbed::
	msgbox RustboroCity_DevonCorp_1F_Text_HowCouldWeGetRobbed, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_Greeter::
	lock
	faceplayer
	goto_if_set FLAG_RETURNED_DEVON_GOODS, RustboroCity_DevonCorp_1F_EventScript_WelcomeToDevonCorp
	goto_if_set FLAG_RECOVERED_DEVON_GOODS, RustboroCity_DevonCorp_1F_EventScript_StaffGotRobbed
	goto_if_set FLAG_DEVON_GOODS_STOLEN, RustboroCity_DevonCorp_1F_EventScript_StaffGotRobbed
	msgbox RustboroCity_DevonCorp_1F_Text_WelcomeToDevonCorp, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_WelcomeToDevonCorp::
	msgbox RustboroCity_DevonCorp_1F_Text_WelcomeToDevonCorp, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_StaffGotRobbed::
	msgbox RustboroCity_DevonCorp_1F_Text_StaffGotRobbed, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_RocksMetalDisplay::
	msgbox RustboroCity_DevonCorp_1F_Text_RocksMetalDisplay, MSGBOX_SIGN
	end

RustboroCity_DevonCorp_1F_EventScript_ProductsDisplay::
	msgbox RustboroCity_DevonCorp_1F_Text_ProductDisplay, MSGBOX_SIGN
	end

RustboroCity_DevonCorp_1F_Text_WelcomeToDevonCorp:
	.string "Bienvenue chez Devon SARL.\n"
	.string "Partenaire officiel de Sylphe.\p"
	.string "Ensemble, nous avons créé la\n"
	.string "Passerelle: le monde en une seconde.\p"
	.string "Toute question sur les anneaux doit\n"
	.string "être adressée au service presse.$"

RustboroCity_DevonCorp_1F_Text_StaffGotRobbed:
	.string "Je n’ai pas le droit de parler\n"
	.string "des anneaux. Désolée.\p"
	.string "Le service presse dit que la\n"
	.string "Passerelle n’y est pour rien.$"

RustboroCity_DevonCorp_1F_Text_ThoseShoesAreOurProduct:
	.string "Hé, ces Chaussures de Sport!\n"
	.string "Elles sortent de nos ateliers.\p"
	.string "Avant, Devon fabriquait des choses\n"
	.string "utiles. Des chaussures, des Balls.\p"
	.string "Maintenant, tout le budget part\n"
	.string "dans la Passerelle. Tout.$"

RustboroCity_DevonCorp_1F_Text_RobberWasntVeryBright:
	.string "Un ingénieur sort tous les soirs\n"
	.string "par la porte de service.\p"
	.string "Ferrand, je crois. Il fredonne\n"
	.string "toujours. Ça m’agace.\p"
	.string "Ne dis à personne que je t’en ai\n"
	.string "parlé. Je tiens à mon poste.$"

RustboroCity_DevonCorp_1F_Text_SoundsLikeStolenGoodsRecovered:
	.string "Les registres sont à jour. Le protocole\n"
	.string "est respecté. Tout va bien.\p"
	.string "… C’est ce qu’on me demande de dire\n"
	.string "aux visiteurs, en tout cas.$"

RustboroCity_DevonCorp_1F_Text_OnlyAuthorizedPeopleEnter:
	.string "Halte. Accès réservé au personnel\n"
	.string "autorisé.\p"
	.string "Depuis les anneaux, on ne plaisante\n"
	.string "plus avec la sécurité.\p"
	.string "Sans badge Devon, tu ne passes pas.\n"
	.string "Même avec une jolie casquette.$"

RustboroCity_DevonCorp_1F_Text_HowCouldWeGetRobbed:
	.string "Ne restez pas près de l’escalier,\n"
	.string "s’il vous plaît.\p"
	.string "On a des consignes. Personne ne monte\n"
	.string "sans badge. Même pas un héros.$"

RustboroCity_DevonCorp_1F_Text_YoureAlwaysWelcomeHere:
	.string "Bonjour. Devon est heureux de\n"
	.string "vous accueillir.\p"
	.string "… Sous protocole, bien sûr. Les étages\n"
	.string "restent réservés au personnel.$"

RustboroCity_DevonCorp_1F_Text_RocksMetalDisplay:
	.string "Des échantillons de pierres et de\n"
	.string "métaux sont placés dans une vitrine.\p"
	.string "Il y a un panneau avec quelque chose\n"
	.string "d'écrit…\p"
	.string "“DEVON était à l'origine une\n"
	.string "compagnie d'exploitation minière.\p"
	.string "La compagnie a également produit de\n"
	.string "l'acier en exploitant la limaille se\l"
	.string "trouvant dans le sable.\p"
	.string "DEVON s'est sans cesse développé\n"
	.string "depuis ses humbles débuts.\p"
	.string "DEVON fabrique maintenant\n"
	.string "une grande variété de produits\l"
	.string "industriels.”$"

RustboroCity_DevonCorp_1F_Text_ProductDisplay:
	.string "La vitrine est pleine de prototypes et\n"
	.string "d'échantillons.\p"
	.string "Il y a un panneau avec une inscription…\p"
	.string "“En plus de ses produits industriels,\n"
	.string "DEVON souhaite se développer sur le\p"
	.string "marché pharmaceutique pour\n"
	.string "améliorer notre qualité de vie.\p"
	.string "Récemment, DEVON a commercialisé des\n"
	.string "outils pour les DRESSEURS, comme les\p"
	.string "POKé BALLS et les systèmes POKéNAV.”$"

