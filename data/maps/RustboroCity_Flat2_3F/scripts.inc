RustboroCity_Flat2_3F_MapScripts::
	.byte 0

RustboroCity_Flat2_3F_EventScript_DevonEmployee::
	msgbox RustboroCity_Flat2_3F_Text_PresidentCollectsRareStones, MSGBOX_NPC
	end

RustboroCity_Flat2_3F_EventScript_Woman::
	msgbox RustboroCity_Flat2_3F_Text_PresidentsSonAlsoCollectsRareStones, MSGBOX_NPC
	end

RustboroCity_Flat2_3F_Text_PresidentCollectsRareStones:
	.string "Le Président collectionne\n"
	.string "les pierres rares.\p"
	.string "Depuis les anneaux, il en reçoit\n"
	.string "de bien étranges. Des inconnues.\p"
	.string "Les géologues disent qu’elles ne\n"
	.string "viennent d’aucune mine connue.$"

RustboroCity_Flat2_3F_Text_PresidentsSonAlsoCollectsRareStones:
	.string "Hé! On frappe avant d’entrer!\n"
	.string "C’est un logement Devon, ici.\p"
	.string "… Tu as vu les affiches de Sylphe?\n"
	.string "Tu ressembles au garçon dessus.\p"
	.string "Non, rien. Je dois être fatiguée.\n"
	.string "Ferme la porte en sortant.$"

