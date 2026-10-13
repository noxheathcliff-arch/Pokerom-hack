@ NOTE: The brailleformat macro in this file is leftover from RS.
@       The numbers are simply skipped over. If you'd like to omit
@       this macro you must also stop it from skipping over this
@       section by editing ScrCmd_braillemessage.

@ For some reason, French version ends sentences with an apostrophe and not a period.
@ It's also possible that the braille gfx are different and that's the reason for this.

Underwater_SealedChamber_Braille_GoUpHere::
	brailleformat 4, 6, 26, 13, 7, 9
	.braille "RENDS-TOI\n"
	.braille "DANS LES\n"
	.braille "PROFONDEURS'$"

SealedChamber_OuterRoom_Braille_ABC:
	brailleformat 7, 6, 21, 13, 10, 9
	.braille "ABCD$"

SealedChamber_OuterRoom_Braille_GHI:
	brailleformat 7, 6, 21, 13, 10, 9
	.braille "IJKL$"

SealedChamber_OuterRoom_Braille_MNO:
	brailleformat 7, 6, 21, 13, 10, 9
	.braille "QRST$"

SealedChamber_OuterRoom_Braille_TUV:
	brailleformat 7, 6, 21, 13, 10, 9
	.braille "YZ$"

SealedChamber_OuterRoom_Braille_DEF:
	brailleformat 7, 6, 21, 13, 10, 9
	.braille "EFGH$"

SealedChamber_OuterRoom_Braille_JKL:
	brailleformat 7, 6, 21, 13, 10, 9
	.braille "MNOP$"

SealedChamber_OuterRoom_Braille_PQRS:
	brailleformat 7, 6, 21, 13, 10, 9
	.braille "UVWX$"

SealedChamber_OuterRoom_Braille_Period:
	brailleformat 9, 6, 19, 13, 12, 9
	.braille "'$"

SealedChamber_OuterRoom_Braille_WXYZ:
	brailleformat 7, 6, 21, 13, 10, 9
	.braille "-$"

SealedChamber_OuterRoom_Braille_Comma:
	brailleformat 9, 6, 19, 13, 12, 9
	.braille ",$"

SealedChamber_OuterRoom_Braille_DigHere:
	brailleformat 7, 4, 23, 15, 10, 7
	.braille "RETOURNE\n"
	.braille "LA TERRE'$"

SealedChamber_InnerRoom_Braille_FirstWailordLastRelicanth:
	brailleformat 0, 0, 29, 19, 3, 3
	.braille "COMMENCE PAR\n"
	.braille "WAILORD\n"
	.braille "ET FINIS AVEC\n"
	.braille "RELICANTH'$"

SealedChamber_InnerRoom_Braille_InThisCaveWeHaveLived:
	brailleformat 2, 0, 26, 19, 5, 3
	.braille "DANS CETTE\n"
	.braille "CAVERNE VIVAIT\n"
	.braille "AUTREFOIS\n"
	.braille "NOTRE PEUPLE'$"

SealedChamber_InnerRoom_Braille_WeOweAllToThePokemon:
	brailleformat 7, 2, 23, 17, 10, 5
	.braille "NOUS DEVONS\n"
	.braille "TOUT AUX\n"
	.braille "POKEMON'$"

SealedChamber_InnerRoom_Braille_ButWeSealedThePokemonAway:
	brailleformat 3, 0, 25, 19, 6, 3
	.braille "MAIS NOUS LES\n"
	.braille "AVONS RETENUS\n"
	.braille "LOIN DE NOUS'$"

SealedChamber_InnerRoom_Braille_WeFearedIt:
	brailleformat 5, 6, 25, 13, 8, 9
	.braille "JADIS, NOUS\n"
	.braille "CRAIGNIONS LES\n"
	.braille "POKEMON'$"

SealedChamber_InnerRoom_Braille_ThoseWithCourageHope:
	brailleformat 6, 0, 24, 19, 9, 3
	.braille "DEMONTRE TON\n"
	.braille "COURAGE'$"

SealedChamber_InnerRoom_Braille_OpenDoorEternalPokemonWaits:
	brailleformat 3, 2, 27, 17, 6, 5
	.braille "OUVRE LA PORTE\n"
	.braille "ET LIBERE UN\n"
	.braille "POKEMON\n"
	.braille "ETERNEL'$"

DesertRuins_Braille_UseRockSmash:
	brailleformat 1, 0, 27, 19, 4, 3
	.braille "GAUCHE,\n"
	.braille "GAUCHE, BAS,\n"
	.braille "BAS ET UTILISE\n"
	.braille "ECLATE-ROC'$"

IslandCave_Braille_RunLapAroundWall:
	brailleformat 5, 0, 25, 19, 8, 3
	.braille "RESTE PRES\n"
	.braille "DU MUR'\n"
	.braille "TOURNE AUTOUR\n"
	.braille "UNE FOIS'$"

AncientTomb_Braille_ShineInTheMiddle:
	brailleformat 3, 0, 25, 19, 6, 3
	.braille "HERITEZ DE\n"
	.braille "NOTRE VOLONTE,\n"
	.braille "EN BRILLANT AU\n"
	.braille "MILIEU'$"

@ FRLG
Braille_Text_Up::
	brailleformat 3, 0, 25, 19, 6, 3
	.braille "HAUT$"

Braille_Text_Down::
	brailleformat 3, 0, 25, 19, 6, 3
	.braille "BAS$"

Braille_Text_Right::
	brailleformat 3, 0, 25, 19, 6, 3
	.braille "DROITE$"

Braille_Text_Left::
	brailleformat 3, 0, 25, 19, 6, 3
	.braille "GAUCHE$"

Braille_Text_Cut::
	brailleformat 3, 0, 25, 19, 6, 3
	.braille "COUPE$"

Braille_Text_ABC::
	brailleformat 3, 0, 25, 19, 6, 3
	.braille "ABC$"

Braille_Text_GHI::
	brailleformat 3, 0, 25, 19, 6, 3
	.braille "GHI$"

Braille_Text_MNO::
	brailleformat 3, 0, 25, 19, 6, 3
	.braille "MNO$"

Braille_Text_TUV::
	brailleformat 3, 0, 25, 19, 6, 3
	.braille "TUV$"

Braille_Text_DEF::
	brailleformat 3, 0, 25, 19, 6, 3
	.braille "DEF$"

Braille_Text_JKL::
	brailleformat 3, 0, 25, 19, 6, 3
	.braille "JKL$"

Braille_Text_PQRS::
	brailleformat 3, 0, 25, 19, 6, 3
	.braille "PQRS$"

Braille_Text_WXYZ::
	brailleformat 3, 0, 25, 19, 6, 3
	.braille "WXYZ$"

Braille_Text_Period::
	brailleformat 3, 0, 25, 19, 6, 3
	.braille "'$"

Braille_Text_Comma::
	brailleformat 3, 0, 25, 19, 6, 3
	.braille ",$"

Braille_Text_Everything::
	brailleformat 3, 0, 25, 19, 6, 3
	.braille "TOUT$"

Braille_Text_HasMeaning1::
	brailleformat 3, 0, 25, 19, 6, 3
	.braille "A UN SENS$"

Braille_Text_Existence::
	brailleformat 3, 0, 25, 19, 6, 3
	.braille "EXISTENCE$"

Braille_Text_HasMeaning2::
	brailleformat 3, 0, 25, 19, 6, 3
	.braille "A UN SENS$"

Braille_Text_BeingAlive::
	brailleformat 3, 0, 25, 19, 6, 3
	.braille "ETRE VIVANT$"

Braille_Text_HasMeaning3::
	brailleformat 3, 0, 25, 19, 6, 3
	.braille "A UN SENS$"

Braille_Text_HaveDreams::
	brailleformat 3, 0, 25, 19, 6, 3
	.braille "CROIS EN TOI$"

Braille_Text_UsePower::
	brailleformat 3, 0, 25, 19, 6, 3
	.braille "BATS TOI'$"

Braille_Text_LetTheTwo::
	brailleformat 3, 0, 25, 19, 6, 3
	.braille "LAISSE LES$"

Braille_Text_Glittering::
	brailleformat 3, 0, 25, 19, 6, 3
	.braille "DEUX PIERRES$"

Braille_Text_Stones::
	brailleformat 3, 0, 25, 19, 6, 3
	.braille "BRILLANTES$"

Braille_Text_OneInRed::
	brailleformat 3, 0, 25, 19, 6, 3
	.braille "UNE EN ROUGE$"

Braille_Text_OneInBlue::
	brailleformat 3, 0, 25, 19, 6, 3
	.braille "UNE EN BLEU$"

Braille_Text_ConnectThe::
	brailleformat 3, 0, 25, 19, 6, 3
	.braille "CONNECTER LE$"

Braille_Text_Past::
	brailleformat 3, 0, 25, 19, 6, 3
	.braille "PASSE'$"

Braille_Text_TwoFriends::
	brailleformat 3, 0, 25, 19, 6, 3
	.braille "PARTAGER LA$"

Braille_Text_Sharing::
	brailleformat 3, 0, 25, 19, 6, 3
	.braille "FORCE A DEUX$"

Braille_Text_PowerOpen::
	brailleformat 3, 0, 25, 19, 6, 3
	.braille "AMIS OUVRE$"

Braille_Text_AWindowTo::
	brailleformat 3, 0, 25, 19, 6, 3
	.braille "LA PORTE$"

Braille_Text_ANewWorld::
	brailleformat 3, 0, 25, 19, 6, 3
	.braille "D UN MONDE$"

Braille_Text_ThatGlows::
	brailleformat 3, 0, 25, 19, 6, 3
	.braille "NOUVEAU'$"

Braille_Text_TheNext::
	brailleformat 3, 0, 25, 19, 6, 3
	.braille "LE MONDE$"

Braille_Text_WorldWaits::
	brailleformat 3, 0, 25, 19, 6, 3
	.braille "SUIVANT$"

Braille_Text_ForYou::
	brailleformat 3, 0, 25, 19, 6, 3
	.braille "T ATTEND'$"

