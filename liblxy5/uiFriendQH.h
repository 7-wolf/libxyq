#pragma once
#include "_uiinc.h"

struct sFriendList
{
	int getIDinTeam();
	bool CheckInTeam();
	//bool m_bOnLine;
	int m_traderLV = 0;
	int m_Feeling = 0;//�øж�
	string m_Name;//����
	string m_dataFileName;//�����ļ�������
	int  m_stronglv;//��ɫ��ǿ�Ȼ�ı�
	int  m_modeid;
	bool m_bDuJie = 0;//�Ƿ�ɽ�
	//��������
	int m_weapontype = -1;
	int m_weaponid = -1;
	cJinJieNum m_JinJieNum;
	sZiZhi m_zizhi;//����
	//Ⱦɫ
	sChangeColorData2 m_Ranse;
	//Ǯ
	int  m_money;
	//����
	bool  m_bOnZuoQi = 0;
	int   m_ZuoQiID = -1;
	sChangeColorData m_ZuoQiRanse;
	int   m_bZhuangShi = 0;
	int   m_ZhuangShiID = -1;
	sChangeColorData m_ZhuangShiRanse;

	int  m_FightBB = -1;//�׷��ٻ���
	vector<sShangPinPet>  m_BBList;
	//vector<int>  m_PetSkillList;
	void Save(ofstream& File);
	void Load(ifstream& File);
	ulong GetFriendHead();
	ulong GetDialogHead();
};

// ���Ѷ���
class cInterfaceFriendQiangHua :public cInterfaceFather
{
public:
	void Set(sFriendList& list);
	void Update();
	bool Init();
	bool CheckRB();
	virtual bool ProcessInput();
	virtual bool Show(cCanvas* pCanvas);
	virtual bool CheckL();
	virtual void OnOff(bool NeedShow);
	bool Move(int xPos, int yPos);
	void Change(int id);
private:
	bool m_bUpdateTeam;
	int m_Mode = 0;
	sFriendList* m_pData;
	cObjWas m_Buttonp[12];
	cText m_Name;
	cText m_Money;
	cText m_title;
	bool m_bInit = false;
	//cWasFile m_Back;

	cText m_Text[12];
};

