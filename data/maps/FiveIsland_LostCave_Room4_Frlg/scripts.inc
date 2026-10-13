FiveIsland_LostCave_Room4_Frlg_MapScripts::
	.byte 0

FiveIsland_LostCave_Room4_EventScript_Laura::
	trainerbattle_single TRAINER_PSYCHIC_LAURA, FiveIsland_LostCave_Room4_Text_LauraIntro, FiveIsland_LostCave_Room4_Text_LauraDefeat
	msgbox FiveIsland_LostCave_Room4_Text_LauraPostBattle, MSGBOX_AUTOCLOSE
	end

FiveIsland_LostCave_Room4_Text_LauraIntro::
	.string "Il doit y avoir une puissance\n"
	.string "étrange dans cette grotte.$"

FiveIsland_LostCave_Room4_Text_LauraDefeat::
	.string "Si tu ne vas pas dans le bon\n"
	.string "tunnel, tu ne pourras jamais sortir.$"

FiveIsland_LostCave_Room4_Text_LauraPostBattle::
	.string "Une femme est venue dans les\n"
	.string "grottes il y a quelque temps.$"

