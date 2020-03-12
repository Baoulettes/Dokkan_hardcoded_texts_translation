/****************************************************************\
|=== Made by Joffrey Panisset (Baoulettes) 12.03.2020 03:05pm ===|
|======= With the huge help from ThievingSix & Marcanin3 ========|
|=================== from Unidokkan discord. ====================|
|================ Do not forget to say thanks :) ================|
\****************************************************************/
#include <unidokkan/log.h>
#include <unidokkan/hook.h>
//Text variable - Translate only there 
static auto Text_Char_Details	=	"Détails du personnage";		//Character details
static auto Text_sp_skill		=	"Effet";						//Effect
static auto Text_limit			=	"Limite";						//Limit
static auto Text_details		=	"Plus";							//Details
static auto Text_itemsforbid	=	"Objets de soutien interdits";	//Support items not allowed
static auto Text_deck1			=	"Choix du deck";				//Deck selection
static auto Size_deck1			=	18.0f;
static auto Text_deck2			=	"Objets de soutien";			//Support Items
static auto Size_deck2			=	18.0f;
static auto Text_baba_tab1		=	"Pts. d'échange";				//Trade pts.
static auto Text_baba_tab2		=	"Zénis";						//Zeni
static auto Text_baba_tab3		=	"Trésors";						//Treasure
static auto Size_header_num		=	18.0f;
static auto Text_header_nextR	=	"Rang suivant";					//Next rank
static auto Size_header_nextR	=	18.0f;
static auto Text_header_ready	=	"Prêt dans";					//Ready in:
static auto Size_header_ready	=	18.0f;
static auto Text_ui_mission		=	"Mission";						//Mission
static auto Size_ui_mission		=	20.0f;
static auto Text_ui_scouter		=	"Détecteur";					//Scouter
static auto Size_ui_scouter		=	20.0f;
static auto Text_stg_friendpts	=	"Pts. Ami";						//Friend pts.
static auto Text_stg_zeni		=	"Zéni";							//Zeni
static auto Text_stg_nextR		=	"Rang suivant";					//Next rank
static auto Text_stg_rank		=	"RANG";							//Rank
static auto Text_stg_chardrop	=	"Personnage(s)";				//Character(s)
static auto Text_stg_itemsdrop	=	"Objet(s)";						//Item(s)
static auto Text_stg_time		=	"Temps écoulé";					//Elapsed time
static auto Text_stg_title		=	"Détails de la victoire";		//Victory details
static auto Text_stg_continue	=	"Nb. de \"continuer\"";			//Used continues
static auto Text_stg_deck		=	"Formation de l'équipe";		//Team formation
static auto Text_stg_item		=	"Objet(s) utilisé(s)";			//Used item(s)
static auto Size_Footer			=	20.0f;
static auto Size_Area_name		=	18.0f;
static auto Size_AreanameEvent	=	18.0f;
static auto Size_Scene_title	=	24.0f;
static auto Text_S_rank			=	"Rang";							//Rank
static auto XPos_Supporter_1	=	460.0f;
static auto Text_S_friendpts	=	"Pts. amis";					//Friend pts.
static auto XPos_Supporter_2	=	410.0f;
static auto Size_Supporter		=	12.0f;
static auto Size_Supporter_1	=	16.0f;
static auto Text_S_speciallv	=	"Att. sp nv";					//Special move level
static auto Text_S_potential	=	"Potentiel";					//Potential
static auto Text_S_hp 			=	"PV";							//HP
static auto Text_S_atk 			=	"ATT";							//ATK
static auto Text_S_def			=	"DÉF";							//DEF
static auto Text_S_leader		=	"Aptitude leader";				//Leader skill
static auto Text_S_npcname		=	"Invité spécial";				//Special Guest
static auto Text_S_label		=	"Potentiel";					//Potential
static auto Text_Reversal_A		=	"Disponible(s) :";				//Available :
static auto Size_Reversal		=	20.0f;
static auto Size_Reversal_A		=	20.0f;
static auto Size_generic_btn	=	24.0f;
static auto Size_CharNameRot	=	20.0f; //Character Name (the one at -90° )
static auto Size_CharTitleRot	=	20.0f; //Character Title (the one at -90° )
static auto Size_IngameHP		=	25.0f;
static auto Text_SPInfo_Title	=	"ATT SP. Nv";					//Special move level
static auto Text_SPInfo_Effect	=	"l'éffet de l'ATT SP";			//Special move effect
static auto Text_SPInfo_KI		=	"Ki";							//Ki
static auto Text_SPInfo_Level	=	"ATT SP. Nv";					//Special move level
static auto Text_SPInfo_EfBonus	=	"Effet Extra";					//Additionnal effect(s)
static auto Text_Filter_Link	=	"Aptitude de lien";				//Link skill
static auto Text_Filter_Equip	=	"Orbe";							//Equipment
static auto Text_CatList_Title	=	"Sélection de la catégorie";	//Category selection
static auto Text_CatList_STitle	=	"(Choix multiple possible)";	//(Multiple choices is possible)
static auto Text_EFList_Title	=	"Filtrer par effect d'aptitude";//Filter by skill effects
static auto Text_EFList_STitle	=	"Critère du filtre";			//Filter criteria
static auto Text_Item_Carry		=	"Quantité :";					//Quantity :
static auto XPos_Item_Num		=	375.0f;
static auto XPos_Item_Carry		=	230.0f;
static auto Text_Item_Effect	=	"Effet de l'objet";				//Item effect
static auto Text_Copy_Deck_Label=	"Copier le deck";				//Copy deck
static auto Text_BTN_Info_EZA	=	"Infos Combat";					//Battle information
static auto Text_EZA_T_Victory	=	"Récompenses de victoire";		//Victory details
static auto Text_EZA_T_SelLvl	=	"Sélection niveau ennemi";		//Select ennemi level
static auto Size_BaseStats		=	40.0f;
static auto Size_ATKSPNums		=	20.0f;


// For reused dokkan functions, you can make them global
auto setString		= 	DokkanFunction<void *(void *, std::string)>("_ZN7cocos2d2ui10TextBMFont9setStringERKNSt6__ndk112basic_stringIcNS2_11char_traitsIcEENS2_9allocatorIcEEEE");
auto setStringUI	=	DokkanFunction<void *(void *, std::string)>("_ZN7cocos2d2ui4Text9setStringERKNSt6__ndk112basic_stringIcNS2_11char_traitsIcEENS2_9allocatorIcEEEE");
auto setStringTitle	=	DokkanFunction<void *(void *, std::string)>("_ZN13TitleBarLayer13setTitleLabelERKNSt6__ndk112basic_stringIcNS0_11char_traitsIcEENS0_9allocatorIcEEEE");
auto setFontNameUI	=	DokkanFunction<void *(void *, std::string)>("_ZN7cocos2d2ui4Text11setFontNameERKNSt6__ndk112basic_stringIcNS2_11char_traitsIcEENS2_9allocatorIcEEEE");
auto setFontSize	=	DokkanFunction<void *(void *, float)>("_ZN7cocos2d2ui4Text11setFontSizeEf");
auto setFontSize1	=	DokkanFunction<void *(void *, float)>("_ZN7cocos2d2ui4Text11setFontSizeEf");
auto setFontSize2	=	DokkanFunction<void *(void *, float)>("_ZN7cocos2d2ui4Text11setFontSizeEf");
auto setPositionX	=	DokkanFunction<void *(void *, float)>("_ZN7cocos2d4Node12setPositionXEf");

//No need to crawl there to translate or move (except if you add things)
void *(*ori__CopyDeck)(void *, bool) = nullptr;
void *CopyDeck(void *self, bool create_new) { 						//Copy deck button 
    auto label = ori__CopyDeck(self, create_new);
    if (!create_new) {
        return label;
    }
    setString(label, Text_Copy_Deck_Label);
    return label;
}
void *(*ori__BabaTab1)(void *, bool) = nullptr;
void *BabaTab1(void *self, bool create_new) { 						//Baba tab 1
    auto label = ori__BabaTab1(self, create_new);
    if (!create_new) {
        return label;
    }
    setString(label, Text_baba_tab1);
    return label;
}
void *(*ori__BabaTab2)(void *, bool) = nullptr;
void *BabaTab2(void *self, bool create_new) {						//Baba tab 2
    auto label = ori__BabaTab2(self, create_new);
    if (!create_new) {
        return label;
    }
    setString(label, Text_baba_tab2);
    return label;
}
void *(*ori__BabaTab3)(void *, bool) = nullptr;
void *BabaTab3(void *self, bool create_new) {						//Baba tab 3
    auto label = ori__BabaTab3(self, create_new);
    if (!create_new) {
        return label;
    }
    setString(label, Text_baba_tab3);
    return label;
}
void *(*ori__InfoRBtn)(void *, bool) = nullptr;
void *InfoRBtn(void *self, bool create_new) { 						//Battle info red button EZA
    auto label = ori__InfoRBtn(self, create_new);
    if (!create_new) {
        return label;
    }
    setString(label, Text_BTN_Info_EZA);
    return label;
}
void *(*ori__LayoutCommonBtn10_getFontDetail)(void *, int) = nullptr;
void *LayoutCommonBtn10_getFontDetail(void *self, int create_new) {	//Details Button (tiny green one)
    auto label = ori__LayoutCommonBtn10_getFontDetail(self, create_new);
    if (!create_new) {
        return label;
    }
    setString(label, Text_details);
    return label;
}
void *(*ori__HeaderRecoverText)(void *, int) = nullptr;					
void *HeaderRecoverText(void *self, int create_new) {				//Header ui text - "Recover in"
    auto label = ori__HeaderRecoverText(self, create_new);
    if (!create_new) {
        return label;
    }
    setStringUI(label, Text_header_ready);
	setFontSize(label, Size_header_ready);
    return label;
}
void *(*ori__HeaderNextLankText)(void *, int) = nullptr;
void *HeaderNextLankText(void *self, int create_new) {				//Header ui text - "Next rank :"
    auto label = ori__HeaderNextLankText(self, create_new);
    if (!create_new) {
        return label;
    }
	setStringUI(label, Text_header_nextR);
	setFontSize(label, Size_header_nextR);
    return label;
}
void *(*ori__MypageMissionText)(void *, bool) = nullptr;
void *MypageMissionText(void *self, bool create_new) {				//Mypage "Mission" button
    auto label = ori__MypageMissionText(self, create_new);
    if (!create_new) {
        return label;
    }
    setStringUI(label, Text_ui_mission);
    setFontSize(label, Size_ui_mission);
    return label;
}
void *(*ori__limiteBTN)(void *, bool) = nullptr;
void *limiteBTN(void *self, bool create_new) {						//Red tiny "Limitations" button
    auto label = ori__limiteBTN(self, create_new);
    if (!create_new) {
        return label;
    }
    setString(label, Text_limit);
    return label;
}
void *(*ori__effectBTN)(void *, bool) = nullptr;
void *effectBTN(void *self, bool create_new) {						//Blue tiny "Effect" button
    auto label = ori__effectBTN(self, create_new);
    if (!create_new) {
        return label;
    }
    setString(label, Text_sp_skill);
    return label;
}
void *(*ori__decktitle1)(void *, bool) = nullptr;
void *decktitle1(void *self, bool create_new) {						//Select a team / deck title
    auto label = ori__decktitle1(self, create_new);
    if (!create_new) {
        return label;
    }
    setStringUI(label, Text_deck1);
	setFontSize(label, Size_deck1);
    return label;
}
void *(*ori__decktitle2)(void *, bool) = nullptr;
void *decktitle2(void *self, bool create_new) {						//Support items title during deck selection
    auto label = ori__decktitle2(self, create_new);
    if (!create_new) {
        return label;
    }
	setFontSize(label, Size_deck2);
    setStringUI(label, Text_deck2);
    return label;
}
void *(*ori__SummonScouterText)(void *, bool) = nullptr;
void *SummonScouterText(void *self, bool create_new) {				//Summon scene "Check scouter text"
    auto label = ori__SummonScouterText(self, create_new);
    if (!create_new) {
        return label;
    }
	setStringUI(label, Text_ui_scouter);
    setFontSize(label, Size_ui_scouter);
    return label;
}
void *(*ori__ResultFPText)(void *, bool) = nullptr;
void *ResultFPText(void *self, bool create_new) {					//Stage result ui "Friend pts." label
    auto label = ori__ResultFPText(self, create_new);
    if (!create_new) {
        return label;
    }
    setStringUI(label, Text_stg_friendpts);
    return label;
}
void *(*ori__ResultZeniText)(void *, bool) = nullptr;
void *ResultZeniText(void *self, int create_new) {					//Stage result ui "Zeni" label
    auto label = ori__ResultZeniText(self, create_new);
    if (!create_new) {
        return label;
    }
    setStringUI(label, Text_stg_zeni);
    return label;
}
void *(*ori__ResultNextRankText)(void *, bool) = nullptr;
void *ResultNextRankText(void *self, bool create_new) {				//Stage result ui "Until next rank" label
    auto label = ori__ResultNextRankText(self, create_new);
    if (!create_new) {
        return label;
    }
    setStringUI(label, Text_stg_nextR);
    return label;
}
void *(*ori__ResultCurrRankText)(void *, bool) = nullptr;
void *ResultCurrRankText(void *self, bool create_new) {				//Stage result ui "Rank." label
    auto label = ori__ResultCurrRankText(self, create_new);
    if (!create_new) {
        return label;
    }
    setStringUI(label, Text_stg_rank);
    return label;
}
void *(*ori__ResultCharDropText)(void *, bool) = nullptr;
void *ResultCharDropText(void *self, bool create_new) {				//Stage result ui "Characters drop" label
    auto label = ori__ResultCharDropText(self, create_new);
    if (!create_new) {
        return label;
    }
    setStringUI(label, Text_stg_chardrop);
    return label;
}
void *(*ori__ResultItemsDropText)(void *, bool) = nullptr;
void *ResultItemsDropText(void *self, bool create_new) {			//Stage result ui "Items drop" label
    auto label = ori__ResultItemsDropText(self, create_new);
    if (!create_new) {
        return label;
    }
    setStringUI(label, Text_stg_itemsdrop);
    return label;
}
void *(*ori__ResultClearTimeText)(void *, bool) = nullptr;
void *ResultClearTimeText(void *self, bool create_new) {			//Stage result ui "Cleared time" label
    auto label = ori__ResultClearTimeText(self, create_new);
    if (!create_new) {
        return label;
    }
    setStringUI(label, Text_stg_time);
    return label;
}
void *(*ori__Footer1_FontSize)(void *, bool) = nullptr;
void *Footer1_FontSize(void *self, bool create_new) {				//Mypage Footer size / tab Home
    auto label = ori__Footer1_FontSize(self, create_new);
    if (!create_new) {
        return label;
    }
    setFontSize(label, Size_Footer);
    return label;
}
void *(*ori__Footer2_FontSize)(void *, bool) = nullptr;
void *Footer2_FontSize(void *self, bool create_new) {				//Mypage Footer size / tab Team
    auto label = ori__Footer2_FontSize(self, create_new);
    if (!create_new) {
        return label;
    }
    setFontSize(label, Size_Footer);
    return label;
}
void *(*ori__Footer3_FontSize)(void *, bool) = nullptr;
void *Footer3_FontSize(void *self, bool create_new) {				//Mypage Footer size / tab Summon
    auto label = ori__Footer3_FontSize(self, create_new);
    if (!create_new) {
        return label;
    }
    setFontSize(label, Size_Footer);
    return label;
}
void *(*ori__Footer4_FontSize)(void *, bool) = nullptr;
void *Footer4_FontSize(void *self, bool create_new) {				//Mypage Footer size / tab Shop
    auto label = ori__Footer4_FontSize(self, create_new);
    if (!create_new) {
        return label;
    }
    setFontSize(label, Size_Footer);
    return label;
}
void *(*ori__Footer5_FontSize)(void *, bool) = nullptr;
void *Footer5_FontSize(void *self, bool create_new) {				//Mypage Footer size / tab Baba exchange
    auto label = ori__Footer5_FontSize(self, create_new);
    if (!create_new) {
        return label;
    }
    setFontSize(label, Size_Footer);
    return label;
}
void *(*ori__FontAreaName)(void *, bool) = nullptr;
void *FontAreaName(void *self, bool create_new) {					//Area name At difficulties selection (quest)
    auto label = ori__FontAreaName(self, create_new);
    if (!create_new) {
        return label;
    }
    setFontSize(label, Size_Area_name);
    return label;
}
void *(*ori__FontAreanameEvent)(void *, bool) = nullptr;
void *FontAreanameEvent(void *self, bool create_new) {				//Area name At difficulties selection (events)
    auto label = ori__FontAreanameEvent(self, create_new);
    if (!create_new) {
        return label;
    }
    setFontSize(label, Size_AreanameEvent);
    return label;
}
void *(*ori__GeneralTitle12)(void *, bool) = nullptr;
void *GeneralTitle12(void *self, bool create_new) {					//Scene title Green bar
    auto label = ori__GeneralTitle12(self, create_new);
    if (!create_new) {
        return label;
    }
    setFontSize1(label, Size_Scene_title);
    return label;
}
void *(*ori__SupporterRank)(void *, bool) = nullptr;
void *SupporterRank(void *self, bool create_new) {					//Supporter Rank label
    auto label = ori__SupporterRank(self, create_new);
    if (!create_new) {
        return label;
    }
	setPositionX(label, XPos_Supporter_1);
    setStringUI(label, Text_S_rank);
	setFontSize(label, Size_Supporter_1);
    return label;
}
void *(*ori__Supporterfriendpts)(void *, bool) = nullptr;
void *Supporterfriendpts(void *self, bool create_new) {				//Supporter Friend pts label
    auto label = ori__Supporterfriendpts(self, create_new);
    if (!create_new) {
        return label;
    }
	setPositionX(label, XPos_Supporter_2);
    setStringUI(label, Text_S_friendpts);
    setFontSize(label, Size_Supporter_1);
    return label;
}
void *(*ori__EZAVictoryTitle)(void *, bool) = nullptr;
void *EZAVictoryTitle(void *self, bool create_new) {				//Eza Victory yellow title
    auto label = ori__EZAVictoryTitle(self, create_new);
    if (!create_new) {
        return label;
    }
    setStringUI(label, Text_EZA_T_Victory);
    return label;
}
void *(*ori__EZASelLvlTitle)(void *, bool) = nullptr;
void *EZASelLvlTitle(void *self, bool create_new) {				//Eza Level Select yellow title
    auto label = ori__EZASelLvlTitle(self, create_new);
    if (!create_new) {
        return label;
    }
    setStringUI(label, Text_EZA_T_SelLvl);
    return label;
}
void *(*ori__CharDetailTitle)(void *, bool) = nullptr;
void *CharDetailTitle(void *self, bool create_new) {				//Characters details windows title
    auto label = ori__CharDetailTitle(self, create_new);
    if (!create_new) {
        return label;
    }
    setStringUI(label, Text_Char_Details);
    return label;
}
void *(*ori__SupporterHP)(void *, bool) = nullptr;
void *SupporterHP(void *self, bool create_new) {					//Supporter HP label
    auto label = ori__SupporterHP(self, create_new);
    if (!create_new) {
        return label;
    }
    setStringUI(label, Text_S_hp);
    return label;
}
void *(*ori__Supporterdef)(void *, bool) = nullptr;
void *Supporterdef(void *self, bool create_new) {					//Supporter DEF label
    auto label = ori__Supporterdef(self, create_new);
    if (!create_new) {
        return label;
    }
    setStringUI(label, Text_S_def);
    return label;
}
void *(*ori__Supporteratk)(void *, bool) = nullptr;
void *Supporteratk(void *self, bool create_new) {					//Supporter ATK label
    auto label = ori__Supporteratk(self, create_new);
    if (!create_new) {
        return label;
    }
    setStringUI(label, Text_S_atk);
    return label;
}
void *(*ori__Supporterspeciallv)(void *, bool) = nullptr;
void *Supporterspeciallv(void *self, bool create_new) {				//Supporter Special Level label
    auto label = ori__Supporterspeciallv(self, create_new);
    if (!create_new) {
        return label;
    }
    setStringUI(label, Text_S_speciallv);
    setFontSize(label, Size_Supporter);
    return label;
}
void *(*ori__Supporterpotential)(void *, bool) = nullptr;
void *Supporterpotential(void *self, bool create_new) {				//Supporter Potential label
    auto label = ori__Supporterpotential(self, create_new);
    if (!create_new) {
        return label;
    }
    setStringUI(label, Text_S_potential);
    setFontSize(label, Size_Supporter);
    return label;
}
void *(*ori__Supporterleader)(void *, bool) = nullptr;
void *Supporterleader(void *self, bool create_new) {				//Supporter Leader skill label
    auto label = ori__Supporterleader(self, create_new);
    if (!create_new) {
        return label;
    }
    setStringUI(label, Text_S_leader);
    return label;
}
void *(*ori__ReversalDescription)(void *, bool) = nullptr;
void *ReversalDescription(void *self, bool create_new) {			//Reversal description text
    auto label = ori__ReversalDescription(self, create_new);
    if (!create_new) {
        return label;
    }
    setFontSize(label, Size_Reversal);
    return label;
}
void *(*ori__ReversalAvailable)(void *, bool) = nullptr;
void *ReversalAvailable(void *self, bool create_new) {				//Reversal Available : text
    auto label = ori__ReversalAvailable(self, create_new);
    if (!create_new) {
        return label;
    }
    setFontSize1(label, Size_Reversal_A);
    setStringUI(label, Text_Reversal_A);
    return label;
}
void *(*ori__ItemCarryText)(void *, bool) = nullptr;
void *ItemCarryText(void *self, bool create_new) {					//Item carry text in description.
    auto label = ori__ItemCarryText(self, create_new);
    if (!create_new) {
        return label;
    }
	setStringUI(label, Text_Item_Carry);
	setPositionX(label, XPos_Item_Carry);
    return label;
}
void *(*ori__ItemCarryText2)(void *, bool) = nullptr;
void *ItemCarryText2(void *self, bool create_new) {					//Item carry text in description.
    auto label = ori__ItemCarryText2(self, create_new);
    if (!create_new) {
        return label;
    }
    setStringUI(label, Text_Item_Carry);
	setPositionX(label, XPos_Item_Carry);
    return label;
}
void *(*ori__ItemCarryText3)(void *, bool) = nullptr;
void *ItemCarryText3(void *self, bool create_new) {					//Item carry text in description.
    auto label = ori__ItemCarryText3(self, create_new);
    if (!create_new) {
        return label;
    }
	setStringUI(label, Text_Item_Carry);
	setPositionX(label, XPos_Item_Carry);
    return label;
}
void *(*ori__ItemeffectText1)(void *, bool) = nullptr;
void *ItemeffectText1(void *self, bool create_new) {					//Item effect text in description.
    auto label = ori__ItemeffectText1(self, create_new);
    if (!create_new) {
        return label;
    }
	setStringUI(label, Text_Item_Effect);
    return label;
}
void *(*ori__ItemeffectText2)(void *, bool) = nullptr;
void *ItemeffectText2(void *self, bool create_new) {					//Item effect text in description.
    auto label = ori__ItemeffectText2(self, create_new);
    if (!create_new) {
        return label;
    }
	setStringUI(label, Text_Item_Effect);
    return label;
}
void *(*ori__ItemeffectText3)(void *, bool) = nullptr;
void *ItemeffectText3(void *self, bool create_new) {					//Item effect text in description.
    auto label = ori__ItemeffectText3(self, create_new);
    if (!create_new) {
        return label;
    }
	setStringUI(label, Text_Item_Effect);
    return label;
}
void *(*ori__ItemCarrynum)(void *, bool) = nullptr;
void *ItemCarrynum(void *self, bool create_new) {					//Item carry numbers in description.
    auto label = ori__ItemCarrynum(self, create_new);
    if (!create_new) {
        return label;
    }
	setPositionX(label, XPos_Item_Num);
    return label;
}
void *(*ori__SpecialTitle)(void *, bool) = nullptr;
void *SpecialTitle(void *self, bool create_new) {					//Special Moved information Label "window title"
    auto label = ori__SpecialTitle(self, create_new);
    if (!create_new) {
        return label;
    }
    setStringUI(label, Text_SPInfo_Title);
    return label;
}
void *(*ori__SpecialTitle1)(void *, bool) = nullptr;
void *SpecialTitle1(void *self, bool create_new) {					//Special Moved information Label "window title"
    auto label = ori__SpecialTitle1(self, create_new);
    if (!create_new) {
        return label;
    }
    setStringUI(label, Text_SPInfo_Title);
    return label;
}
void *(*ori__SpecialEffect)(void *, bool) = nullptr;
void *SpecialEffect(void *self, bool create_new) {					//Special Moved information Label "Effect"
    auto label = ori__SpecialEffect(self, create_new);
    if (!create_new) {
        return label;
    }
    setStringUI(label, Text_SPInfo_Effect);
    return label;
}
void *(*ori__SpecialKI)(void *, bool) = nullptr;
void *SpecialKI(void *self, bool create_new) {						//Special Moved information Label "Ki"
    auto label = ori__SpecialKI(self, create_new);
    if (!create_new) {
        return label;
    }
    setStringUI(label, Text_SPInfo_KI);
    return label;
}
void *(*ori__SpecialLevel)(void *, bool) = nullptr;
void *SpecialLevel(void *self, bool create_new) {					//Special Moved information Label "Special move level"
    auto label = ori__SpecialLevel(self, create_new);
    if (!create_new) {
        return label;
    }
    setStringUI(label, Text_SPInfo_Level);
    return label;
}
void *(*ori__SpecialEFBonus)(void *, bool) = nullptr;
void *SpecialEFBonus(void *self, bool create_new) {					//Special Moved information Label "Addition effects"
    auto label = ori__SpecialEFBonus(self, create_new);
    if (!create_new) {
        return label;
    }
    setStringUI(label, Text_SPInfo_EfBonus);
    return label;
}
void *(*ori__FilterLink)(void *, bool) = nullptr;
void *FilterLink(void *self, bool create_new) {						//Filters List Label "Link skill"
    auto label = ori__FilterLink(self, create_new);
    if (!create_new) {
        return label;
    }
    setStringUI(label, Text_Filter_Link);
    return label;
}
void *(*ori__FilterEquip)(void *, bool) = nullptr;
void *FilterEquip(void *self, bool create_new) {					//Filters List Label "Equipments"
    auto label = ori__FilterEquip(self, create_new);
    if (!create_new) {
        return label;
    }
    setStringUI(label, Text_Filter_Equip);
    return label;
}
void *(*ori__CategoriesListTitle)(void *, bool) = nullptr;
void *CategoriesListTitle(void *self, bool create_new) {			//Categories list title
    auto label = ori__CategoriesListTitle(self, create_new);
    if (!create_new) {
        return label;
    }
    //setFontSize1(label, Size_Reversal_A);
    setStringUI(label, Text_CatList_Title);
    return label;
}
void *(*ori__CategoriesListSTitle)(void *, bool) = nullptr;
void *CategoriesListSTitle(void *self, bool create_new) {			//Categories list sub title
    auto label = ori__CategoriesListSTitle(self, create_new);
    if (!create_new) {
        return label;
    }
    setStringUI(label, Text_CatList_STitle);
    return label;
}
void *(*ori__EffectListTitle)(void *, bool) = nullptr;
void *EffectListTitle(void *self, bool create_new) {				//Effect list title
    auto label = ori__EffectListTitle(self, create_new);
    if (!create_new) {
        return label;
    }
    setStringUI(label, Text_EFList_Title);
    return label;
}
void *(*ori__EffectListSTitle)(void *, bool) = nullptr;
void *EffectListSTitle(void *self, bool create_new) {				//Effect list sub title
    auto label = ori__EffectListSTitle(self, create_new);
    if (!create_new) {
        return label;
    }
    setStringUI(label, Text_EFList_STitle);
    return label;
}
void *(*ori__Header_act)(void *, bool) = nullptr;
void *Header_act(void *self, bool create_new) {						//Header ACT/ACT text
    auto label = ori__Header_act(self, create_new);
    if (!create_new) {
        return label;
    }
    setFontSize(label, Size_header_num);
    return label;
}
void *(*ori__Header_timer)(void *, bool) = nullptr;
void *Header_timer(void *self, bool create_new) {					//Header timer text
    auto label = ori__Header_timer(self, create_new);
    if (!create_new) {
        return label;
    }
    setFontSize(label, Size_header_num);
    return label;
}
void *(*ori__Header_name)(void *, bool) = nullptr;
void *Header_name(void *self, bool create_new) {					//Header user name text
    auto label = ori__Header_name(self, create_new);
    if (!create_new) {
        return label;
    }
    setFontSize(label, Size_header_num);
    return label;
}			
void *(*ori__Header_zeni)(void *, bool) = nullptr;
void *Header_zeni(void *self, bool create_new) {					//Header Zeni counter text
    auto label = ori__Header_zeni(self, create_new);
    if (!create_new) {
        return label;
    }
    setFontSize(label, Size_header_num);
    return label;
}	
void *(*ori__Header_ds)(void *, bool) = nullptr;
void *Header_ds(void *self, bool create_new) {						//Header Dragon stones counter text
    auto label = ori__Header_ds(self, create_new);
    if (!create_new) {
        return label;
    }
    setFontSize(label, Size_header_num);
    return label;
}	
void *(*ori__Header_exp)(void *, bool) = nullptr;
void *Header_exp(void *self, bool create_new) {						//Header exp left before rank up (number) counter text
    auto label = ori__Header_exp(self, create_new);
    if (!create_new) {
        return label;
    }
    setFontSize(label, Size_header_num);
    return label;
}
void *(*ori__IngameMaxHPText)(void *, bool) = nullptr;
void *IngameMaxHPText(void *self, bool create_new) {				//HP max text ingame
    auto label = ori__IngameMaxHPText(self, create_new);
    if (!create_new) {
        return label;
    }
    setFontSize(label, Size_IngameHP);
    return label;
}
void *(*ori__IngameHPText)(void *, bool) = nullptr;
void *IngameHPText(void *self, bool create_new) {					//Hp text ingame
    auto label = ori__IngameHPText(self, create_new);
    if (!create_new) {
        return label;
    }
    setFontSize(label, Size_IngameHP);
    return label;
}
void *(*ori__IngameItemText)(void *, bool) = nullptr;
void *IngameItemText(void *self, bool create_new) {					//Item text ingame
    auto label = ori__IngameItemText(self, create_new);
    if (!create_new) {
        return label;
    }
    setFontSize(label, Size_IngameHP);
    return label;
}
void *(*ori__IngameCharText)(void *, bool) = nullptr;
void *IngameCharText(void *self, bool create_new) {					//Characters text ingame
    auto label = ori__IngameCharText(self, create_new);
    if (!create_new) {
        return label;
    }
    setFontSize(label, Size_IngameHP);
    return label;
}
void *(*ori__IngameZeniText)(void *, bool) = nullptr;
void *IngameZeniText(void *self, bool create_new) {					//Zeni text ingame
    auto label = ori__IngameZeniText(self, create_new);
    if (!create_new) {
        return label;
    }
    setFontSize(label, Size_IngameHP);
    return label;
}
void *(*ori__Stats_base)(void *, bool) = nullptr;
void *Stats_base(void *self, bool create_new) {						//base stat numbers
    auto label = ori__Stats_base(self, create_new);
    if (!create_new) {
        return label;
    }
    setFontSize(label, Size_BaseStats);
    return label;
}
void *(*ori__details_attsplv)(void *, bool) = nullptr;
void *details_attsplv(void *self, bool create_new) {				//atk sp lv & max num in chardetails
    auto label = ori__details_attsplv(self, create_new);
    if (!create_new) {
        return label;
    }
    setFontSize(label, Size_ATKSPNums);
    return label;
}
void *(*ori__details_attsplvm)(void *, bool) = nullptr;
void *details_attsplvm(void *self, bool create_new) {				//atk sp lv & max num in chardetails
    auto label = ori__details_attsplvm(self, create_new);
    if (!create_new) {
        return label;
    }
    setFontSize(label, Size_ATKSPNums);
    return label;
}
void *(*ori__SpdRun1)(void *, bool) = nullptr;
void *SpdRun1(void *self, bool create_new) {						//Speed run screen Title
    auto label = ori__SpdRun1(self, create_new);
    if (!create_new) {
        return label;
    }
    setStringUI(label, Text_stg_title);
    return label;
}
void *(*ori__SpdRun2)(void *, bool) = nullptr;
void *SpdRun2(void *self, bool create_new) {						//Speed run screen Elapsed time
    auto label = ori__SpdRun2(self, create_new);
    if (!create_new) {
        return label;
    }
    setStringUI(label, Text_stg_time);
    return label;
}
void *(*ori__SpdRun3)(void *, bool) = nullptr;
void *SpdRun3(void *self, bool create_new) {						//Speed run screen continue label
    auto label = ori__SpdRun3(self, create_new);
    if (!create_new) {
        return label;
    }
    setStringUI(label, Text_stg_continue);
    return label;
}
void *(*ori__SpdRun4)(void *, bool) = nullptr;
void *SpdRun4(void *self, bool create_new) {						//Speed run used deck label
    auto label = ori__SpdRun4(self, create_new);
    if (!create_new) {
        return label;
    }
    setStringUI(label, Text_stg_deck);
    return label;
}
void *(*ori__SpdRun5)(void *, bool) = nullptr;
void *SpdRun5(void *self, bool create_new) {						//Speed run screen used items label
    auto label = ori__SpdRun5(self, create_new);
    if (!create_new) {
        return label;
    }
    setStringUI(label, Text_stg_item);
    return label;
}
extern "C" {
	int unidokkan_init(ApplyHooksFn apply_hooks_fn) {
		UD_LOGI("Translation add-on : Loaded");
		std::vector<Hook> hooks = {
			{DOKKAN_LIB, "_ZN43LayoutCharactermenuChaDetailCharaInfoStatus12getFontNumLvEb", (void*)Stats_base, (void**)& ori__Stats_base},						// Base Stats numbers
			{DOKKAN_LIB, "_ZN45LayoutCharactermenuChaDetailCharaDetailDialog12getFontTitleEb", (void*)CharDetailTitle, (void**)& ori__CharDetailTitle},			// Chara. details full screen window title
			{DOKKAN_LIB, "_ZN45LayoutCharactermenuChaDetailCharaInfoDialogLv14getFontSpAtkLvEb", (void*)details_attsplv, (void**)& ori__details_attsplv},		// Chara. details full screen atk sp level
			{DOKKAN_LIB, "_ZN45LayoutCharactermenuChaDetailCharaInfoDialogLv17getFontSpAtkMaxlvEb", (void*)details_attsplvm, (void**)& ori__details_attsplvm},	// Chara. details full screen atk sp level max.
			{DOKKAN_LIB, "_ZN34LayoutZbattleZbattlePartsEnemyInfo16getFontEnemyInfoEb", (void*)InfoRBtn, (void**)& ori__InfoRBtn},								// EZA ennemy info btn
			{DOKKAN_LIB, "_ZN32LayoutZbattleZbattleRewardDialog12getFontTitleEb", (void*)EZAVictoryTitle, (void**)& ori__EZAVictoryTitle},						// EZA yellow victory title
			{DOKKAN_LIB, "_ZN31LayoutZbattleZbattleEnemyLvList12getFontTitleEb", (void*)EZASelLvlTitle, (void**)& ori__EZASelLvlTitle},							// EZA yellow select ennemy level title
			{DOKKAN_LIB, "_ZN44LayoutQuestSugorokuResultGetTimeAttackDialog12getFontTitleEb", (void*)SpdRun1, (void**)& ori__SpdRun1},							// Victory details title
			{DOKKAN_LIB, "_ZN44LayoutQuestSugorokuResultGetTimeAttackDialog16getFontClearTimeEb", (void*)SpdRun2, (void**)& ori__SpdRun2},						// Victory details elapsed time
			{DOKKAN_LIB, "_ZN44LayoutQuestSugorokuResultGetTimeAttackDialog19getFontContinueTimeEb", (void*)SpdRun3, (void**)& ori__SpdRun3},					// Victory details number of continues used
			{DOKKAN_LIB, "_ZN44LayoutQuestSugorokuResultGetTimeAttackDialog15getFontUserDeckEb", (void*)SpdRun4, (void**)& ori__SpdRun4},						// Victory details used deck title
			{DOKKAN_LIB, "_ZN44LayoutQuestSugorokuResultGetTimeAttackDialog14getFontUseItemEb", (void*)SpdRun5, (void**)& ori__SpdRun5},						// Victory details used items title
			{DOKKAN_LIB, "_ZN24LayoutIngameIngameBattle12getFontHpMaxEb", (void*)IngameMaxHPText, (void**)& ori__IngameMaxHPText},								// Ingame Max HP text
			{DOKKAN_LIB, "_ZN24LayoutIngameIngameBattle9getFontHpEb", (void*)IngameHPText, (void**)& ori__IngameHPText},										// Ingame HP text
			{DOKKAN_LIB, "_ZN24LayoutIngameIngameBattle11getFontItemEb", (void*)IngameItemText, (void**)& ori__IngameItemText},									// Ingame Item text
			{DOKKAN_LIB, "_ZN24LayoutIngameIngameBattle11getFontCardEb", (void*)IngameCharText, (void**)& ori__IngameCharText},									// Ingame Char text
			{DOKKAN_LIB, "_ZN24LayoutIngameIngameBattle11getFontZeniEb", (void*)IngameZeniText, (void**)& ori__IngameZeniText},									// Ingame Zeni text
			{DOKKAN_LIB, "_ZN17LayoutCommonBtn1315getFontDeckCopyEb", (void*)CopyDeck, (void**)& ori__CopyDeck},												// Copy Deck BM Label BTN
			{DOKKAN_LIB, "_ZN21LayoutCommonDialog01212getFontTitleEb", (void*)CategoriesListTitle, (void**)& ori__CategoriesListTitle},							// Categories list title text
			{DOKKAN_LIB, "_ZN21LayoutCommonDialog01211getFontTextEb", (void*)CategoriesListSTitle, (void**)& ori__CategoriesListSTitle},						// Categories list sub title text
			{DOKKAN_LIB, "_ZN34LayoutCommonDialog011FilterContent21getFontLinkskillTitleEb", (void*)FilterLink, (void**)& ori__FilterLink},						// Filter label "link skills"
			{DOKKAN_LIB, "_ZN34LayoutCommonDialog011FilterContent21getFontEquipmentTitleEb", (void*)FilterEquip, (void**)& ori__FilterEquip},					// Filter label "Equipments"
			{DOKKAN_LIB, "_ZN48LayoutCharactermenuChaDetailCharaInfoSpSkill010213getFontLvMax1Eb", (void*)SpecialTitle1, (void**)& ori__SpecialTitle1},			// Special Move information Label "Title" (LR +)
			{DOKKAN_LIB, "_ZN46LayoutCharactermenuChaDetailCharaInfoSpSkill0113getFontLvMax1Eb", (void*)SpecialTitle, (void**)& ori__SpecialTitle},				// Special Move information Label "Title" (UR and lower)
			{DOKKAN_LIB, "_ZN48LayoutCharactermenuChaDetailCharaInfoPartSpSkill17getFontLabelSpAtkEb", (void*)SpecialEffect, (void**)& ori__SpecialEffect},		// Special Move information Label "Effect"
			{DOKKAN_LIB, "_ZN48LayoutCharactermenuChaDetailCharaInfoPartSpSkill12getFontPowerEb", (void*)SpecialKI, (void**)& ori__SpecialKI},					// Special Move information Label "KI"
			{DOKKAN_LIB, "_ZN48LayoutCharactermenuChaDetailCharaInfoPartSpSkill9getFontLvEb", (void*)SpecialLevel, (void**)& ori__SpecialLevel},				// Special Move information Label "Level"
			{DOKKAN_LIB, "_ZN48LayoutCharactermenuChaDetailCharaInfoPartSpSkill16getFontAddEffectEb", (void*)SpecialEFBonus, (void**)& ori__SpecialEFBonus},	// Special Move information Label "Ef bonus"
			{DOKKAN_LIB, "_ZN36LayoutCharactermenuChaItemItemDetail12getFontCarryEb", (void*)ItemCarryText, (void**)& ori__ItemCarryText},						// Item Carry text
			{DOKKAN_LIB, "_ZN40LayoutCharactermenuChaItemItemDetailLong12getFontCarryEb", (void*)ItemCarryText2, (void**)& ori__ItemCarryText2},				// Item Carry text
			{DOKKAN_LIB, "_ZN41LayoutCharactermenuChaItemItemDetailLong212getFontCarryEb", (void*)ItemCarryText3, (void**)& ori__ItemCarryText3},				// Item Carry text
			{DOKKAN_LIB, "_ZN36LayoutCharactermenuChaItemItemDetail16getFontItemTitleEb", (void*)ItemeffectText1, (void**)& ori__ItemeffectText1},				// Item Effect Label text
			{DOKKAN_LIB, "_ZN40LayoutCharactermenuChaItemItemDetailLong16getFontItemTitleEb", (void*)ItemeffectText2, (void**)& ori__ItemeffectText2},			// Item Effect Label text
			{DOKKAN_LIB, "_ZN41LayoutCharactermenuChaItemItemDetailLong216getFontItemTitleEb", (void*)ItemeffectText3, (void**)& ori__ItemeffectText3},			// Item Effect Label text
			{DOKKAN_LIB, "_ZN36LayoutCharactermenuChaItemItemDetail13getFontNumberEb", (void*)ItemCarrynum, (void**)& ori__ItemCarrynum},						// Item Carry text
			{DOKKAN_LIB, "_ZN45LayoutCharactermenuChaPotentialPotReverseMenu11getFontTextEb", (void*)ReversalDescription, (void**)& ori__ReversalDescription}, 	// Reversal Description text
			{DOKKAN_LIB, "_ZN45LayoutCharactermenuChaPotentialPotReversePart12getFontLabelEb", (void*)ReversalAvailable, (void**)& ori__ReversalAvailable}, 	// Reversal Available text
			{DOKKAN_LIB, "_ZN28LayoutQuestQuest03Difficulty15getFontAreaNameEb", (void*)FontAreaName, (void**)& ori__FontAreaName}, 							// Area name At difficulties selection (quest)
			{DOKKAN_LIB, "_ZN28LayoutQuestEvent03Difficulty15getFontAreaNameEb", (void*)FontAreanameEvent, (void**)& ori__FontAreanameEvent},					// Area name At difficulties selection (events)
			{DOKKAN_LIB, "_ZN17LayoutCommonTitle12getFontTitleEb", (void*)GeneralTitle12, (void**)& ori__GeneralTitle12},  										// General Title 12 (Green background) text
			{DOKKAN_LIB, "_ZN22LayoutCharacterChaList21getFontLabelRankQuestEb", (void*)SupporterRank, (void**)& ori__SupporterRank},							// "Rank" in get supporter list
			{DOKKAN_LIB, "_ZN22LayoutCharacterChaList27getImgLabelFriendPointQuestEb", (void*)Supporterfriendpts, (void**)& ori__Supporterfriendpts},			// "Friend pts" in get supporter list
			{DOKKAN_LIB, "_ZN22LayoutCharacterChaList14getFontLabelHpEb", (void*)SupporterHP, (void**)& ori__SupporterHP},										// "HP" in get supporter list
			{DOKKAN_LIB, "_ZN22LayoutCharacterChaList15getFontLabelAtkEb", (void*)Supporteratk, (void**)& ori__Supporteratk},									// "ATK" in get supporter list
			{DOKKAN_LIB, "_ZN22LayoutCharacterChaList15getFontLabelDefEb", (void*)Supporterdef, (void**)& ori__Supporterdef},									// "DEF" in get supporter list
			{DOKKAN_LIB, "_ZN22LayoutCharacterChaList17getFontLabelSpAtkEb", (void*)Supporterspeciallv, (void**)& ori__Supporterspeciallv},						// "Special level" in get supporter list
			{DOKKAN_LIB, "_ZN22LayoutCharacterChaList23getFontLabelLeaderSkillEb", (void*)Supporterleader, (void**)& ori__Supporterleader},						// "Leader skill" in get supporter list
			{DOKKAN_LIB, "_ZN22LayoutCharacterChaList15getFontLabelPotEb", (void*)Supporterpotential, (void**)& ori__Supporterpotential},						// "Potential" in get supporter list
			{DOKKAN_LIB, "_ZN19LayoutTradeTradeTab12getFontText1Eb", (void*)BabaTab1, (void**)& ori__BabaTab1}, 												// baba's shop tabs
			{DOKKAN_LIB, "_ZN19LayoutTradeTradeTab12getFontText2Eb", (void*)BabaTab2, (void**)& ori__BabaTab2}, 												// baba's shop tabs
			{DOKKAN_LIB, "_ZN19LayoutTradeTradeTab12getFontText3Eb", (void*)BabaTab3, (void**)& ori__BabaTab3}, 												// baba's shop tabs
			{DOKKAN_LIB, "_ZN24LayoutQuestQuestBtnParts12getFontLimitEb", (void*)limiteBTN, (void**)& ori__limiteBTN}, 											// Buttons red limited btn 
			{DOKKAN_LIB, "_ZN24LayoutQuestQuestBtnParts14getFontSPSkillEb", (void*)effectBTN, (void**)& ori__effectBTN}, 										// Buttons blue effect btn 
			{DOKKAN_LIB, "_ZN22LayoutQuestQuest05Deck13getFontTitle1Eb", (void*)decktitle1, (void**)& ori__decktitle1},											// Select deck text at deck selection
			{DOKKAN_LIB, "_ZN22LayoutQuestQuest05Deck13getFontTitle2Eb", (void*)decktitle2, (void**)& ori__decktitle2}, 										// support items text at deck selection
			{DOKKAN_LIB, "_ZN18LayoutCommonFooter11getFontHomeEb", (void*)Footer1_FontSize, (void**)& ori__Footer1_FontSize},	 								// footer size 1
			{DOKKAN_LIB, "_ZN18LayoutCommonFooter11getFontTeamEb", (void*)Footer2_FontSize, (void**)& ori__Footer2_FontSize}, 									// footer size 2
			{DOKKAN_LIB, "_ZN18LayoutCommonFooter12getFontGashaEb", (void*)Footer3_FontSize, (void**)& ori__Footer3_FontSize},									// footer size 3
			{DOKKAN_LIB, "_ZN18LayoutCommonFooter11getFontShopEb", (void*)Footer4_FontSize, (void**)& ori__Footer4_FontSize}, 									// footer size 4
			{DOKKAN_LIB, "_ZN18LayoutCommonFooter12getFontTradeEb", (void*)Footer5_FontSize, (void**)& ori__Footer5_FontSize}, 									// footer size 5
			{DOKKAN_LIB, "_ZN17LayoutCommonBtn1013getFontDetailEb", (void *) LayoutCommonBtn10_getFontDetail, (void **) &ori__LayoutCommonBtn10_getFontDetail},	// tiny details btn 
			{DOKKAN_LIB, "_ZN18LayoutCommonHeader14getFontRecoverEb", (void*) HeaderRecoverText, (void**)&ori__HeaderRecoverText}, 								// Header Recover text
			{DOKKAN_LIB, "_ZN18LayoutCommonHeader15getFontNextLankEb", (void*) HeaderNextLankText, (void**)&ori__HeaderNextLankText}, 							// Header Next """Lank""" text
			{DOKKAN_LIB, "_ZN18LayoutMypageMypTop12getFontText2Eb", (void*) MypageMissionText, (void**)&ori__MypageMissionText}, 								// Mypage Mission button text
			{DOKKAN_LIB, "_ZN18LayoutCommonHeader10getFontActEb", (void*) Header_act, (void**)&ori__Header_act}, 												// Header ACT counter text
			{DOKKAN_LIB, "_ZN18LayoutCommonHeader12getFontTimerEb", (void*) Header_timer, (void**)&ori__Header_timer}, 											// Header timer text
			{DOKKAN_LIB, "_ZN18LayoutCommonHeader11getFontNameEb", (void*) Header_name, (void**)&ori__Header_name}, 											// Header name text
			{DOKKAN_LIB, "_ZN18LayoutCommonHeader11getFontZeniEb", (void*) Header_zeni, (void**)&ori__Header_zeni}, 											// Header zeni counter text
			{DOKKAN_LIB, "_ZN18LayoutCommonHeader12getFontStoneEb", (void*) Header_ds, (void**)&ori__Header_ds}, 												// Header ds counter text
			{DOKKAN_LIB, "_ZN18LayoutCommonHeader18getFontNextLankNumEb", (void*) Header_exp, (void**)&ori__Header_exp}, 										// Header exp left text
			{DOKKAN_LIB, "_ZN20LayoutGashaGashaBase14getFontScouterEb", (void*) SummonScouterText, (void**)&ori__SummonScouterText}, 							// Summon menu scouter text
			{DOKKAN_LIB, "_ZN38LayoutQuestSugorokuResultGetTimeAttack12getFontGatFPEb", (void*) ResultFPText, (void**)&ori__ResultFPText}, 						// Result screen "FP get" text
			{DOKKAN_LIB, "_ZN38LayoutQuestSugorokuResultGetTimeAttack14getFontGatZeniEb", (void*) ResultZeniText, (void**)&ori__ResultZeniText}, 				// Result screen "Zeni get" text
			{DOKKAN_LIB, "_ZN38LayoutQuestSugorokuResultGetTimeAttack11getFontRankEb", (void*) ResultCurrRankText, (void**)&ori__ResultCurrRankText}, 			// Result screen "Rank" text
			{DOKKAN_LIB, "_ZN38LayoutQuestSugorokuResultGetTimeAttack15getFontNextRankEb", (void*) ResultNextRankText, (void**)&ori__ResultNextRankText}, 		// Result screen "Next rank" text
			{DOKKAN_LIB, "_ZN38LayoutQuestSugorokuResultGetTimeAttack15getFontGetText1Eb", (void*) ResultCharDropText, (void**)&ori__ResultCharDropText}, 		// Result screen "Char obtained" text
			{DOKKAN_LIB, "_ZN38LayoutQuestSugorokuResultGetTimeAttack15getFontGetText2Eb", (void*) ResultItemsDropText, (void**)&ori__ResultItemsDropText},		// Result screen "Items obtained" text
			{DOKKAN_LIB, "_ZN38LayoutQuestSugorokuResultGetTimeAttack16getFontClearTimeEb", (void*) ResultClearTimeText, (void**)&ori__ResultClearTimeText},	// Result screen "Clear time" text
		};
		if (!apply_hooks_fn(hooks)) {
            return 1;
        }
        return 0;
	}
}