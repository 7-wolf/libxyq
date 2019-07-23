#pragma once
#include "_global.h"

// ��ݼ�
//class cCanvas;
class cAccelator :public cInterfaceFather
{
public:
	bool CheckRB();
	bool Init();
	void setCharacter(cCharacter* c){ _c = c; }
	bool init2();
	bool ProcessAccelator();
	virtual bool ProcessInput();
	virtual bool Show(cCanvas* pCanvas);
	virtual bool CheckL();
	void OnOff(bool NeedShow);

	bool UseSkill(int id);
	int m_AccelatorSelect = -1;
	cDescribe m_Describe;

	int m_Mode = 0;

	bool m_bInit = false;
	cWasFile m_Accelatorback; //��ݼ��ı�����
	cObjWas m_Accelatorbackp[8];
	cWasFile  m_AccelatorSkill[8];
	cText   m_tAccelatorSkill[8];
	int		m_AccelatorSkillid[8];

	RECT m_redrawrect;
	int m_NumofSkill = 0;
	cObjWas m_MagicBack;
	cWasFile m_SkillHead[30];
	sSkill* m_pSkillShow[30];

	void MoveMagicBack(int x, int y);

	cText m_TitleT;
	int m_SkillSelect;

	cCharacter* _c = nullptr;

	int _show8 = 8;
	int _tag = 0;
	function<void(int, int)> _cb = nullptr;
};