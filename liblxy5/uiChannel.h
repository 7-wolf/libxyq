#pragma once
#include "_global.h"

enum eChannel
{
	ec��ǰ, //0
	ec����,    //1
	ec����,
	ecϵͳ,
	ec˽��
};
class cInterfaceChannel :public cInterfaceFather
{
public:
	void OnOff(bool NeedShow){};
	cWasFile m_MoveIcon;
	cWasFile* m_pCurrentChannel;
	cWasFile m_Channel[5];
	cWasFile m_Face[129];
	sFaceText m_ContextList[30];
	int     m_ContextStart;  //��1����λ��
	int     m_ContextNum;//�ܹ��ж�����
	int     m_ContextShowStart;//��������ʼ��ʾ
	int    m_ContextShowNum;
	bool AddNewString(string str, string name = "", int channel = 3);
	void UpDateShow();
	void SetPos();
	int m_WidthChannel;
	int m_HeightChannel;

	int m_HeightCube;//�о�
	//cWasFile m_Back;
	cObjWas m_BackP[4];
	bool Init();
	ulong m_FaceId[129];
	virtual bool ProcessInput();
	virtual bool CheckL();
	bool Show(cCanvas* pCanvas);
	bool Move(int x, int y);
};
