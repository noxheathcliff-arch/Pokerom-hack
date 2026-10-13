SSAnne_Kitchen_Frlg_MapScripts::
	.byte 0

SSAnne_Kitchen_EventScript_Chef1::
	msgbox SSAnne_Kitchen_Text_BusyOutOfTheWay, MSGBOX_NPC
	end

SSAnne_Kitchen_EventScript_Chef2::
	msgbox SSAnne_Kitchen_Text_SawOddBerryInTrash, MSGBOX_NPC
	end

SSAnne_Kitchen_EventScript_Chef3::
	msgbox SSAnne_Kitchen_Text_SoBusyImDizzy, MSGBOX_NPC
	end

SSAnne_Kitchen_EventScript_Chef4::
	lock
	faceplayer
	msgbox SSAnne_Kitchen_Text_IAmLeChefMainCourseIs
	random 3
	copyvar VAR_0x8008, VAR_RESULT
	call_if_eq VAR_0x8008, 0, SSAnne_Kitchen_EventScript_SalmonDuSalad
	call_if_eq VAR_0x8008, 1, SSAnne_Kitchen_EventScript_EelsAuBarbecue
	call_if_eq VAR_0x8008, 2, SSAnne_Kitchen_EventScript_PrimeBeefsteak
	release
	end

SSAnne_Kitchen_EventScript_SalmonDuSalad::
	msgbox SSAnne_Kitchen_Text_SalmonDuSalad
	return

SSAnne_Kitchen_EventScript_EelsAuBarbecue::
	msgbox SSAnne_Kitchen_Text_EelsAuBarbecue
	return

SSAnne_Kitchen_EventScript_PrimeBeefsteak::
	msgbox SSAnne_Kitchen_Text_PrimeBeefsteak
	return

SSAnne_Kitchen_EventScript_Chef5::
	msgbox SSAnne_Kitchen_Text_PeelSpudsEveryDay, MSGBOX_NPC
	end

SSAnne_Kitchen_EventScript_Chef6::
	msgbox SSAnne_Kitchen_Text_HearAboutSnorlaxItsAGlutton, MSGBOX_NPC
	end

SSAnne_Kitchen_EventScript_Chef7::
	msgbox SSAnne_Kitchen_Text_OnlyGetToPeelOnions, MSGBOX_NPC
	end

SSAnne_Kitchen_Text_BusyOutOfTheWay::
	.string "Hé! Toi là! Y'en a qui bossent\n"
	.string "dur ici! Alors dégage!$"

SSAnne_Kitchen_Text_SawOddBerryInTrash::
	.string "Y'avait une BAIE bizarre dans la\n"
	.string "poubelle. Tu sais ce que c'est?$"

SSAnne_Kitchen_Text_SoBusyImDizzy::
	.string "J'ai trop de boulot! J'en ai \n"
	.string "des vertiges!$"

SSAnne_Kitchen_Text_PeelSpudsEveryDay::
	.string "Pourquoi?\n"
	.string "Pourquoi moi?\p"
	.string "J'suis tout l'temps d'corvée\n"
	.string "d'patates…$"

SSAnne_Kitchen_Text_HearAboutSnorlaxItsAGlutton::
	.string "Tu connais RONFLEX?\p"
	.string "Il passe ses journées à manger\n"
	.string "et à dormir!$"

SSAnne_Kitchen_Text_OnlyGetToPeelOnions::
	.string "Sniff…\n"
	.string "… sniff…\p"
	.string "J'épluche des oignons…$"

SSAnne_Kitchen_Text_IAmLeChefMainCourseIs::
	.string "Hm, hm!\n"
	.string "Je suis le chef cuistot!\p"
	.string "Voilà le menu:$"

SSAnne_Kitchen_Text_SalmonDuSalad::
	.string "Salade de saumon!\p"
	.string "Pour ceux qui ne sont pas contents\n"
	.string "c'est la même chose!$"

SSAnne_Kitchen_Text_EelsAuBarbecue::
	.string "Pâté d'anguilles!\p"
	.string "De quoi donner des envies de\n"
	.string "mutinerie!$"

SSAnne_Kitchen_Text_PrimeBeefsteak::
	.string "Côtes de bœuf!\p"
	.string "Mais je crois que je n'ai plus de\n"
	.string "viande?!$"

