#pragma once
#include "_uiinc.h"

class cState :public cInterfaceFather
{
public:

	void OnOff(bool NeedShow);
	array<cText, 9> m_TPetDate;
	array<cText, 32> m_TPcFnt; //27 ����  28 ���� 29��ν 30���� 31�ӵ��ٶ�
	array<cObjWas, 11> _btns;
	array<cText, 11> _tBtns;
	cWasFile m_LeveUp;
	cText m_Text;
	cObjWas m_ButtonLvDown;   //����
	cObjWas m_ButtonLvUp;   //����
	cObjWas m_PointSpeed;
	cObjWas m_ButtonSkill;  //����
	int m_SkillPage;//�������������12��,��Ҫ��ҳ
	array<cWasFile, 12> m_SkillHead;
	int m_SkillSelect;
	cObjWas m_SkillHeadSelect;
	////�鿴����

	array<cText, 2> m_TSkillHeadSelectDate;
	cObjWas m_SeeZZ;

	cInterfacePetSkill m_PetSkill;
	bool UpDatePcDate();
	void UpdateAddPointB();
	void UpdateProPerty();
	void UpDateHp();
	void UpDateMp();
	void UpDateCp();
	vector<cObjWas> m_Addp;
	vector<cObjWas> m_Subp;
	cWasFile m_Add;
	cWasFile m_Sub;

	cWasFile* m_pShow;
	bool Init();
	bool ProcessInput();
	bool CheckL();
	bool CheckRB();
	bool SetCharacter(cCharacter* pc);
	cPcData* m_pPCData;
	bool Show(cCanvas* pCanvas);
	bool Move(int x, int y);
	int m_NowFighter;
	cWasFile m_State;
	void switchAddPoint();
	bool CheckAddPoint(){ return m_bAddPoint; }

private:
	bool m_bAddPoint;
	bool m_isNeedLvupOfFriend = false;
	bool m_bInit = false;
	vector<int> _pointTemps;
	cCharacter *_cC = nullptr;
};

