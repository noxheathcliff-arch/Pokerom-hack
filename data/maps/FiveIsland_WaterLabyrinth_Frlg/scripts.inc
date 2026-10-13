FiveIsland_WaterLabyrinth_Frlg_MapScripts::
	.byte 0

FiveIsland_WaterLabyrinth_EventScript_EggGentleman::
	lock
	faceplayer
	goto_if_set FLAG_GOT_TOGEPI_EGG, FiveIsland_WaterLabyrinth_EventScript_PostEggComment
	goto_if_set FLAG_NO_ROOM_FOR_TOGEPI_EGG, FiveIsland_WaterLabyrinth_EventScript_ReturnForEgg
	msgbox FiveIsland_WaterLabyrinth_Text_LetMeTakeLookAtMons
	specialvar VAR_RESULT, GetLeadMonFriendship
	goto_if_eq VAR_RESULT, 6, FiveIsland_WaterLabyrinth_EventScript_LeadMonMaxFriendship
	msgbox FiveIsland_WaterLabyrinth_Text_HmmISeeIsee
	release
	end

FiveIsland_WaterLabyrinth_EventScript_MonDaisyComment::
	famechecker FAMECHECKER_DAISY, 2
	msgbox FiveIsland_WaterLabyrinth_Text_CuteMonRemindsMeOfDaisy
	release
	end

FiveIsland_WaterLabyrinth_EventScript_LeadMonMaxFriendship::
	msgbox FiveIsland_WaterLabyrinth_Text_TreatMonRightHaveThis
	goto FiveIsland_WaterLabyrinth_EventScript_TryGiveEgg
	end

FiveIsland_WaterLabyrinth_EventScript_TryGiveEgg::
	getpartysize
	goto_if_eq VAR_RESULT, PARTY_SIZE, FiveIsland_WaterLabyrinth_EventScript_NoRoomForEgg
	setflag FLAG_GOT_TOGEPI_EGG
	giveegg SPECIES_TOGEPI
	textcolor NPC_TEXT_COLOR_NEUTRAL
	playfanfare MUS_LEVEL_UP
	message FiveIsland_WaterLabyrinth_Text_ReceivedEggFromMan
	waitfanfare
	waitmessage
	call EventScript_RestorePrevTextColor
	goto FiveIsland_WaterLabyrinth_EventScript_PostEggComment
	end

@ If the player has a Togepi/Togetic from this game (assumed to be the one the man gave you) then comment on it
@ Otherwise make normal comment
FiveIsland_WaterLabyrinth_EventScript_PostEggComment::
	bufferspeciesname STR_VAR_2, SPECIES_TOGEPI
	setvar VAR_0x8004, SPECIES_TOGEPI
	specialvar VAR_RESULT, PlayerPartyContainsSpeciesWithPlayerID
	goto_if_eq VAR_RESULT, TRUE, FiveIsland_WaterLabyrinth_EventScript_MonDaisyComment
	bufferspeciesname STR_VAR_2, SPECIES_TOGETIC
	setvar VAR_0x8004, SPECIES_TOGETIC
	specialvar VAR_RESULT, PlayerPartyContainsSpeciesWithPlayerID
	goto_if_eq VAR_RESULT, TRUE, FiveIsland_WaterLabyrinth_EventScript_MonDaisyComment
	msgbox FiveIsland_WaterLabyrinth_Text_GladIMetSomeoneLikeYou
	release
	end

FiveIsland_WaterLabyrinth_EventScript_NoRoomForEgg::
	setflag FLAG_NO_ROOM_FOR_TOGEPI_EGG
	msgbox FiveIsland_WaterLabyrinth_Text_DontHaveSpaceInYourParty
	release
	end

FiveIsland_WaterLabyrinth_EventScript_ReturnForEgg::
	goto FiveIsland_WaterLabyrinth_EventScript_TryGiveEgg
	end

FiveIsland_WaterLabyrinth_Text_LetMeTakeLookAtMons::
	.string "Tu voyages dans le coin, non?\p"
	.string "J'espère que tu traites tes POKéMON\n"
	.string "avec beaucoup d'amour.\p"
	.string "Laisse-moi voir.\n"
	.string "… … …   … … …$"

FiveIsland_WaterLabyrinth_Text_HmmISeeIsee::
	.string "Ah, hmm…\n"
	.string "Je vois, je vois…$"

FiveIsland_WaterLabyrinth_Text_TreatMonRightHaveThis::
	.string "Oh, impressionnant.\n"
	.string "Tu t'occupes bien de tes POKéMON.\p"
	.string "Je crois que je peux te faire\n"
	.string "confiance.\p"
	.string "Tiens, je voudrais te donner ceci.$"

FiveIsland_WaterLabyrinth_Text_ReceivedEggFromMan::
	.string "{PLAYER} reçoit l'OEUF.$"

FiveIsland_WaterLabyrinth_Text_DontHaveSpaceInYourParty::
	.string "Malheureusement, il n'y a plus de\n"
	.string "place dans ton équipe.\p"
	.string "Tu devrais repasser me voir\n"
	.string "plus tard.$"

@ Unused
FiveIsland_WaterLabyrinth_Text_YouveComeBackForTheEgg::
	.string "やあ\n"
	.string "タマゴを　もらいに\l"
	.string "きて　くれたんだね$"

FiveIsland_WaterLabyrinth_Text_GladIMetSomeoneLikeYou::
	.string "J'ai reçu cet OEUF pendant un de\n"
	.string "mes voyages.\p"
	.string "Je suis content de rencontrer\n"
	.string "quelqu'un comme toi.$"

FiveIsland_WaterLabyrinth_Text_CuteMonRemindsMeOfDaisy::
	.string "Oh, bonjour.\n"
	.string "Il est mignon ton {STR_VAR_2}.\p"
	.string "Il me rappelle une petite fille que\n"
	.string "j'ai rencontrée pendant un voyage.\p"
	.string "Elle adorait ses POKéMON et les\n"
	.string "traitait avec beaucoup d'amour.\p"
	.string "Le nom de cette petite fille, je\n"
	.string "crois que c'est NINA.$"

FiveIsland_WaterLabyrinth_Text_AlizeIntro::
	.string "C'est un endroit parfait pour\n"
	.string "élever les POKéMON.$"

FiveIsland_WaterLabyrinth_Text_AlizeDefeat::
	.string "Tes POKéMON semblent être\n"
	.string "en pleine forme.$"

FiveIsland_WaterLabyrinth_Text_AlizePostBattle::
	.string "Tu sais, je crois que tu feras\n"
	.string "un très bon DRESSEUR.$"
