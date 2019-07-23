#pragma once
#include "_uiinc.h"

enum eFightMenu
{
	FMENU_NORMAL,  //��ͨ
	FMENU_MAGIC2,   //����Ŀ��ѡ��
	FMENU_ITEM,  //��Ʒѡ��
	FMENU_GRAB,   //ץ
	FMENU_ITEM2,  //��ƷĿ��ѡ��
	FMENU_MAGIC, //����Ŀ��
	FMENU_PET,   //�ٻ�
	FMENU_PROTECT, //����
	FMENU_SPECIAL,  //�ؼ�
//	FMENU_CONDUCT,   //ָ��
//	FMENU_FABAO,  //����
	FMENU_SPECIAL2
};


class cFightState;
class cInterfaceFight :public cInterfaceFather
{
public:
	cInterfaceFight();
	void SetTeamControl(bool bC);
	cInterfaceConduct m_InterfaceConduct;
	void OnOff(bool NeedShow);
	RECT m_ItemRect;
	cDescribe m_Describe;
	void InitPet();
	void ShowPet�ٻ�����();
	void MovePet(int x, int y);

	cWasFile m_Button;
	cText m_PetName[8];
	cText m_PetProPerty[6];
	cText m_Text;
	cWasFile	m_UpB;
	cWasFile	m_DownB;
	int  m_PetPage;
	int m_PetIDSelect;
	int m_TruePetIDSelect;
	cWasFile m_PetBack;
	cWasFile m_ItemDataBack;
	cWasFile m_BackMagic6;//��������  0x2FD95E30
	cWasFile m_BackMagic10;//�������� 0x69823EE5
	cWasFile m_BackMagic14;//��������  0A8B7D87
	cWasFile m_BackMagic20;//��������  0x32F119A5
	cWasFile m_BackMagic30;// 0x4226BD41
	cWasFile m_BackPet; // 0xE87F26E1
	cWasFile m_BackItem;//  0xE3AEF018
	bool AddTurn(bool do10086 = true);
	bool CheckTurn(int ID);

	bool UpdateMenu();
	void SwitchMode(eFightMenu eFightMenu);
	void SelectMode(eFightMenu eFightMenu);
	bool Move(int x, int y);
	void MoveMagicBack(int x, int y);
	void MoveMenu(int x, int y);
	void MoveItem(int x, int y);
	int  m_NumofButtonShow;  //��Ҫ��ʾ�İ�ť��


	cWasFile m_Magic;
	cWasFile m_Stunt;  //�ؼ�
	cWasFile m_Conduct; //ָ��
	cWasFile m_Item;
	cWasFile m_Defend;
	cWasFile m_Guard;
	cWasFile m_Summon; //�ٻ�
	//	CWFile m_Auto;
	cWasFile m_Catch; //ץ
	cWasFile m_Fabao;
	cWasFile m_Escape;
	eFightMenu    m_MenuMode;
	void   InitItem(int offset);
	//bool   SetSpecialMode(bool b);
	cWasFile m_ItemSelectFrame;
	int    m_NumofSkill;
	//	CWFile m_ItemHead[20];

	sSkill* m_pSkillShow[30];

	sSkill* m_pSkillSelect = 0;
	cWasFile m_SkillHead[30];

	bool   InitMagic2();
	bool   InitMagic();
	bool   InitSpecial();
	void   MoveSpecial(int x, int y);
	void   ShowSpecial(cCanvas* pCanvas);
	bool   ProcessSpecial();
	bool   ProcessSpecial2();
	bool  ProcessGrabץ��();
	bool  ProcessItem2();

	bool  ProcessProtect();
	bool ProcessPet�ٻ�����();
	cText  m_TitleT;
	cText  m_SkillPreSelectT;
	cObjWas m_MagicBack;
	int    m_SpecialNum = 0;
	int	   m_SpecialID[6];
	cWasFile m_SpecialHead[6];
	int    m_SpecialSelect;

	virtual bool ProcessInput();
	bool ProcessMenu();
	//��Ʒ
	cWasFile m_PetSelectBack[2];
	cWasFile m_ItemBack;

	int  m_ItemSelect;

	bool Init();
	bool m_bInit = false;
	bool SetNowFight(int fight);
	bool Show(cCanvas* pCanvas);
	bool   m_ItemCanUse[20];


	int  m_NowFighterID;
	int  m_PreFighterID;


	cFightState* m_pFightState;
	bool CheckL();
	//�ƶ�
	int m_xMenuPos;
	int m_yMenuPos;
	int m_xAutoPos;
	int m_yAutoPos;
	bool m_MoveBack = false;
	int m_OldxMouse;
	int m_OldyMouse;
	void SetControl(int id, bool cancontrol){ m_bCanControl[id] = cancontrol; }
	bool CheckControl(int id);
	bool CheckControl();

	int _timeWaiting = 0;
	bool _isAutoBattle = false;

	cWasFile _autoBack;
	cObjWas _autoBtn;
	cText _tAutoBtn;
	cText _tAutoTurn;
	void moveAuto(int x, int y);
	bool ProcessAuto();
private:
	bool m_bCanControl[20];
	cObj* m_pObjSelect = 0;
	//int SelectObj(int Userid,int type);
	inline  bool ProcessItem();
	inline  bool ProcessNormal();
	inline  bool ProcessMagic2();
	inline  bool ProcessMagic();


	inline	bool RunA();
public:
	inline  bool RunQ();
private:
	inline	bool CheckA();
	inline	bool CheckQ();
	inline	bool CheckD();
	inline	bool CheckT();
	inline	bool CheckG();
	inline	bool CheckW();
	inline	bool CheckX();
	inline	bool CheckS();
	inline	bool CheckE();
	inline	bool CheckV();

	inline	bool CheckRButton();
	inline	void Def();
	inline	void Guard();
	inline	void ShowMenu(cCanvas* pCanvas);
	inline	void ShowItem(cCanvas* pCanvas);
	inline	void ShowMagic(cCanvas* pCanvas);
};