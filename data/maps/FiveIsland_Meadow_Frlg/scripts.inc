FiveIsland_Meadow_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, FiveIsland_Meadow_OnLoad
	.byte 0

FiveIsland_Meadow_OnLoad::
	call_if_set FLAG_UNLOCKED_ROCKET_WAREHOUSE, FiveIsland_Meadow_EventScript_SetWarehouseDoorUnlocked
	end

FiveIsland_Meadow_EventScript_WarehouseDoor::
	lockall
	goto_if_set FLAG_UNLOCKED_ROCKET_WAREHOUSE, FiveIsland_Meadow_EventScript_WarehouseDoorAlreadyOpen
	goto_if_set FLAG_LEARNED_YES_NAH_CHANSEY, FiveIsland_Meadow_EventScript_OpenWarehouseDoor
	msgbox FiveIsland_Meadow_Text_EnteredPasswordAnotherNeeded
	releaseall
	end

FiveIsland_Meadow_EventScript_OpenWarehouseDoor::
	setflag FLAG_UNLOCKED_ROCKET_WAREHOUSE
	message FiveIsland_Meadow_Text_EnteredPasswordDoorOpened
	waitmessage
	delay 60
	call FiveIsland_Meadow_EventScript_SetWarehouseDoorUnlocked
	special DrawWholeMapView
	playse SE_PIN
	waitse
	releaseall
	end

FiveIsland_Meadow_EventScript_WarehouseDoorAlreadyOpen::
	msgbox FiveIsland_Meadow_Text_WarehouseDoorAlreadyOpen
	releaseall
	end

FiveIsland_Meadow_EventScript_SetWarehouseDoorUnlocked::
	setmetatile 12, 21, METATILE_SeviiIslands45_RocketWarehouseDoor_Unlocked, 1
	return

FiveIsland_Meadow_EventScript_Rocket1::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_49, FiveIsland_Meadow_Text_Rocket1Intro, FiveIsland_Meadow_Text_Rocket1Defeat
	msgbox FiveIsland_Meadow_Text_Rocket1PostBattle, MSGBOX_AUTOCLOSE
	end

FiveIsland_Meadow_EventScript_Rocket2::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_50, FiveIsland_Meadow_Text_Rocket2Intro, FiveIsland_Meadow_Text_Rocket2Defeat
	msgbox FiveIsland_Meadow_Text_Rocket2PostBattle, MSGBOX_AUTOCLOSE
	end

FiveIsland_Meadow_EventScript_Rocket3::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_51, FiveIsland_Meadow_Text_Rocket3Intro, FiveIsland_Meadow_Text_Rocket3Defeat
	msgbox FiveIsland_Meadow_Text_Rocket3PostBattle, MSGBOX_AUTOCLOSE
	end

@ Unused
FiveIsland_Meadow_Text_DoorNeedsTwoPasswords::
	.string "とびらを　あけるには\n"
	.string "パスワードが　2つ　いるようだ$"

FiveIsland_Meadow_Text_EnteredPasswordAnotherNeeded::
	.string "{PLAYER} entre le mot de passe.\p"
	.string "“ICI, GIRAFARIG, ICI”.\p"
	.string "… …  … …  … …\p"
	.string "Il faut un autre mot de passe\n"
	.string "pour ouvrir la porte…$"

FiveIsland_Meadow_Text_EnteredPasswordDoorOpened::
	.string "{PLAYER} entre les mots de passe.\p"
	.string "“ICI, GIRAFARIG, ICI”.\n"
	.string "“TARSAL LA STAR”.\p"
	.string "… …  … …  … …\p"
	.string "La porte de l'ENTREPOT\n"
	.string "est ouverte!$"

FiveIsland_Meadow_Text_WarehouseDoorAlreadyOpen::
	.string "La porte de l'ENTREPOT est\n"
	.string "déjà ouverte.$"

FiveIsland_Meadow_Text_Rocket1Intro::
	.string "L'accès à cette zone est interdit!\n"
	.string "Dehors!$"

FiveIsland_Meadow_Text_Rocket1Defeat::
	.string "Non, j'ai vraiment perdu, là?$"

FiveIsland_Meadow_Text_Rocket1PostBattle::
	.string "Tu n'as rien à faire ici!\n"
	.string "Rentre chez toi!$"

FiveIsland_Meadow_Text_Rocket2Intro::
	.string "A part notre ENTREPOT, il n'y\n"
	.string "a rien dans le coin.\p"
	.string "Alors qu'est-ce que tu fais ici?$"

FiveIsland_Meadow_Text_Rocket2Defeat::
	.string "Ça devait pas se passer\n"
	.string "comme ça…$"

FiveIsland_Meadow_Text_Rocket2PostBattle::
	.string "Tu veux savoir ce qui se\n"
	.string "passe dans l'ENTREPOT?\p"
	.string "Crois-moi, pour ta sécurité, il\n"
	.string "vaut mieux que tu le saches pas.$"

FiveIsland_Meadow_Text_Rocket3Intro::
	.string "Tu perds ton temps à essayer\n"
	.string "de me battre.$"

FiveIsland_Meadow_Text_Rocket3Defeat::
	.string "Arrh, ça me rend furieuse!$"

FiveIsland_Meadow_Text_Rocket3PostBattle::
	.string "De toute façon, tu ne pourras pas\n"
	.string "continuer sans mot de passe.$"

