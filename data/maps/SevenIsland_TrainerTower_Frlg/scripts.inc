SevenIsland_TrainerTower_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SevenIsland_TrainerTower_OnTransition
	.byte 0

SevenIsland_TrainerTower_OnTransition::
	setvar VAR_MAP_SCENE_TRAINER_TOWER, 0
	end

SevenIsland_TrainerTower_EventScript_TrainerTowerSign::
	msgbox SevenIsland_TrainerTower_Text_TrainerTowerSign, MSGBOX_SIGN
	end

SevenIsland_TrainerTower_EventScript_TrainerTowerAheadSign::
	msgbox SevenIsland_TrainerTower_Text_TrainerTowerAhead, MSGBOX_SIGN
	end

SevenIsland_TrainerTower_Text_DarioIntro::
	.string "Je savais que tu viendrais.$"

SevenIsland_TrainerTower_Text_DarioDefeat::
	.string "Abandonne…$"

SevenIsland_TrainerTower_Text_DarioPostBattle::
	.string "Dans le futur, je pressens que tu\n"
	.string "affronteras de nombreux DRESSEURS.\p"
	.string "Un lien étrange et invisible te\n"
	.string "reliera à eux.$"

SevenIsland_TrainerTower_Text_RodetteIntro::
	.string "Quelque part sur cette île, des\n"
	.string "POKéMON spéciaux se reposent.$"

SevenIsland_TrainerTower_Text_RodetteDefeat::
	.string "Je sens une grande force en toi!$"

SevenIsland_TrainerTower_Text_RodettePostBattle::
	.string "Quelque part sur cette île, des\n"
	.string "POKéMON spéciaux se reposent.\p"
	.string "Se pourrait-il qu'ils attendent\n"
	.string "ta venue?$"

SevenIsland_TrainerTower_Text_TrainerTowerSign::
	.string "ENTREE de la TOUR DRESSEURS\n"
	.string "Relevez le défi!$"

SevenIsland_TrainerTower_Text_TrainerTowerAhead::
	.string "TOUR DRESSEURS DROIT DEVANT$"

