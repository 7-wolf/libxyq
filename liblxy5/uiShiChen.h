#pragma once
#include "_uiinc.h"

class cShiCheng
{
public:
	void Save(ofstream& File);
	void Load(ifstream& File);

	ulong  m_23_1;  //��
	ulong  m_1_3;   //��
	ulong  m_3_5;   //��
	ulong  m_5_7;   //î
	ulong  m_7_9;   //��
	ulong  m_9_11;  //��  
	ulong  m_11_13;  //��
	ulong  m_13_15;  //δ
	ulong  m_15_17; //��
	ulong  m_17_19; //��
	ulong  m_19_21;  //��
	ulong  m_21_23;  //��

	cWasFile m_Data;
	int year;
	int month;
	int day;
	int hour;
	int minute;
	int second;
	int ss;
	int m_fps;
	int m_week; //����
	cShiCheng();
	void SetFPS(int fps){ fps = m_fps; }
	//ǰ��һ����
	void stepMiliSec();
	void stepMinuteAndAutoSave(int add);
	void AddHour(int num = 1);
	void AddDay();
	void AddMonth();
	void AddYear();
	void Init(int fps, int y, int m, int d, int h, int mi, int sec, int millisecond = 0)
	{
		m_fps = fps;
		year = y;
		month = m;
		day = d;
		hour = h;
		minute = mi;
		second = sec;
		ss = millisecond;
		CountDayOfWeek();
		UpdateShiCheng(hour);
	}
	void CountDayOfWeek();
	void UpdateShiCheng(int h);
	bool CheckWhite(){ return m_bWhite; }
	array<function<void()>, 12> onSwicths;
private:
	bool m_bWhite;
};

class cInterfaceDoor :public cInterfaceFather
{
public:
	int m_SaveNum = 0;
	void OnOff(bool NeedShow){};
	cText m_CharacterPos;
	char   m_MapNameBuf[50];
	cText  m_MapName;
	bool  m_MapNameNeedShow;//�Ƿ���ʾ��ͼ������
	cShiCheng m_TimeShiCheng;//ʱ��
	cWasFile m_SmallMap;
	int    m_time;
	//cWasFile m_Back;
	cWasFile m_Door;
	cWasFile m_WorldmapGlim; //����
	cWasFile m_Glim;
	cWasFile m_MapGlim;
	int   m_GlimSelect;
	cWasFile m_SmallPeople[2];
	bool ProcessInput();
	void UpdatePos(cObj* pObj);
	bool CheckL();
	bool Init();
	bool Show(cCanvas* pCanvas);
	void SetName(string name);
	cInterfaceDoor(){ m_time = 0; }
	int m_xoldHeroPos;
	int m_yoldHeroPos;
	int wid = 70;
	int m_bRunMode = 0;
	void SetTrigger(cTaskFather* pFather = 0, int stage = -1, int least = 1024);
	void CheckFight();
	int m_AvoidFight = 0;
	void SetWhite(int b);
	int CheckWhite(){ return m_bWhite; }
	int m_HeroX;
	int m_HeroY;
	void Save(ofstream& File);
	void Load(ifstream& File);
	void SetHalf(bool bTrue = true);
	cTaskFather* m_pTask;
	int m_stage;
private:
	bool m_bHalf = false;
	int m_bWhite = 2;
	bool m_bInit = false;

	int m_timeleast;  //�������ֵ����ʱ����
	int  m_rate;//������
	int m_nowtimeleast = 200;


};