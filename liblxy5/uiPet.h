#pragma once
#include "_uiinc.h"

class cInterfacePet :public cInterfaceFather
{
public:
	void AddExp(cPropertyData* pPetSelect, int num);
	cInterfacePetSkill m_PetSkill;
	void OnOff(bool NeedShow);
	//CWFile* m_frampre;
	//cWfileP* m_framprep;


	bool   Move(int x, int y);//�ƶ�����
	cWasFile m_UpB;
	cWasFile m_DownB;
	//CWFile m_ItemDataBack;

	cWasFile m_SetAttackB;
	cWasFile m_AddPoint[5];
	cWasFile m_SubPoint[5];
	cWasFile m_XunYang;
	cWasFile m_ChaKanZiZhi;
	cWasFile m_FreePet;//����
	cObjWas m_SetAddPoint;//���üӵ�
	bool  m_bAddPoint = false;
	void   FreePet();
	bool   m_FreePetMode;
	//CWFile m_DaShu;
	int m_SkillPage;//�������������12��,��Ҫ��ҳ
	int m_PetPage = 0;//���BB������4��,��Ҫҳ

	cWasFile m_back;

	cWasFile m_PetSelectBack[2];
	cObjWas _btnJJ;
	array<cText, 5> m_TPetName;
	bool Init();

	bool MovePetProPerty();
	bool CheckL();
	bool ProcessFreePet();
	bool ProcessInput();
//	bool UpdateDescript(cWdfFile* pHead, sPetSkill* pPet, int xMouse, int yMouse);
	bool Show(cCanvas* pCanvas);
	bool SetPage(int page);
	void UpdateList(int page);
	//bool InitPage();
	void UpDateExp();
	void UpDateByLvUp();
	int m_TrueSelect;


	int m_ItemDataTime;

	cText m_TSkillSelectData[2];
	//CWFile* m_PetPic[4]; //һ���ٻ��޿�����4���������,���⻹�и���
	cObj m_PetObj;
	//cWfileP m_Shadow;
	int m_PetSelectID = 0;

	cText m_TPetProPerty[26];
	~cInterfacePet();
	bool Free();
	void UpdatePointButton();
	void UpdateProPerty();

	cInterfacePet();
	void setCharactor(int id = -1);
	void setPointTemps();
private:

	bool m_bInit = false;
	cObj  m_FreePetObj;
	bool SelectPet(int id);
	/*bool CheckOn(CWFile* pTarget, int id);
	bool CheckOn(cWfileP* pTarget, int id);*/
	/*int m_xMouse;
	int m_yMouse;*/
	cCharacter *_charactor = nullptr;
	int _heroID;
	vector<int> _pointTemps;

};
