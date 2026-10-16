RustboroCity_Flat2_1F_MapScripts::
	.byte 0

RustboroCity_Flat2_1F_EventScript_OldWoman::
	msgbox RustboroCity_Flat2_1F_Text_DevonWorkersLiveHere, MSGBOX_NPC
	end

RustboroCity_Flat2_1F_EventScript_Skitty::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_SKITTY, CRY_MODE_NORMAL
	msgbox RustboroCity_Flat2_1F_Text_Skitty, MSGBOX_DEFAULT
	waitmoncry
	release
	end

RustboroCity_Flat2_1F_Text_DevonWorkersLiveHere:
	.string "Ici, ce sont les logements Devon.\n"
	.string "Tout l’immeuble y travaille.\p"
	.string "Depuis les anneaux, on chuchote.\n"
	.string "Les murs sont fins, tu sais.\p"
	.string "On ne sait pas qui est ingénieur\n"
	.string "et qui répète tout au Rempart.$"

RustboroCity_Flat2_1F_Text_Skitty:
	.string "SKITTY: Skiiit!$"

