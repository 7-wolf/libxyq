#pragma once
#include "_global.h"


class cWorldMap :public cInterfaceFather
{
public:
	enum  eMap
	{
		eMapWorld,
		eMapWorldEast,
		eMapWorldWest,
		eMapWorldSouth,
		eMapWorldNorth,
		eMapWorldLG,
		eMapWorldTG,
		eMapWorldYG,
		eMapWorldPTY,
		eMapSouth,
		eMapNorth,
		eMapEast,
		eMapWest,
		eMapFenChao, //����«�� 13-16
		eMapLongKu,
		eMapNvWa,
		eMapAL,		//��ʤ���� 16-20
		eMapHGS,
		eMapNR,
		eMapPengLai,
		eMapCA,		//�� 20-38
		eMapDT,
		eMapDF,
		eMapGLZ,
		eMapHZ,
		eMapHS,
		eMapJY,
		eMapJZ,
		eMapLG,
		eMapMW,
		eMapPS,
		eMapPT,
		eMapSML,
		eMapST,
		eMapD5,
		eMapWZ,
		eMapXXT,
		eMapMJC,
		eMapBX,		//��  38-45
		eMapBQ,
		eMapCS,
		eMapFC,
		eMapZZ,
		eMapXL,
		eMapQLS
	};

	bool CheckRB();
	int m_xPre = 0;
	int m_yPre = 0;
	cText m_text;
	void OnOff(bool bShow);
	bool  MoveTest(cWasFile& Target);
	virtual bool ProcessInput();
	bool ProcessInput0(); //����
	bool ProcessInput1(); //��
	bool ProcessInput2(); //��
	bool ProcessInput3(); //��
	bool ProcessInput4(); //��
	virtual bool Show(cCanvas* pCanvas);
	bool	Show0(cCanvas* pCanvas);
	bool	Show1(cCanvas* pCanvas);
	bool	Show2(cCanvas* pCanvas);
	bool	Show3(cCanvas* pCanvas);
	bool	Show4(cCanvas* pCanvas);
	virtual bool CheckL();
	int m_Mode;
	cWasFile m_Data[45];
	string m_MapName[45];
	bool Init();
	void InitPos();
	cWasFile* m_pShow = 0;
private:
	bool m_bInit = false;
};

