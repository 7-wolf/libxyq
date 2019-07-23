#pragma once
#include "_uiinc.h"

class cInterfaceJianDing :public cInterfaceFather
{
public:
	void SetMode(int id){ m_Mode = id; }
	bool Init();
	virtual bool ProcessInput();
	virtual bool Show(cCanvas* pCanvas);
	virtual bool CheckL();
	virtual void OnOff(bool NeedShow);
	bool Move(int xPos, int yPos);
private:
	int m_ItemSelect;
	int m_NowItemSelect;
	int m_Mode = 0;//0��ʾ���� 1��ʾ�չ� 2�չ�һ�� 3��ʾ��Ƕ��ʯ
	bool m_bInit = false;
	//cWasFile m_Back;
	cText m_tPrice;
};

