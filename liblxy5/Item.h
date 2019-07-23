#pragma once
#include "_asert.h"

struct sItem //��ʾһ������
{
	int m_Type;
	int m_ID;
	string m_Name;
	ulong m_SmallHead; //ͷ��
	ulong m_BigHead;
	int m_Price = 0;//�۸�

	string m_Text; //����
	int m_UseType;
	void SetLv(int lv){ m_lv = lv; }
	int GetLv(){ return m_lv; }
private:
	int m_lv;
};


struct sJiaJuData
{
	int num;
	vector<ulong> m_data;
};


enum ItemProPerty
{
	enum_hp,
	enum_hphurt,
	enum_mp
};


enum eFaBao
{
	eFaBao0������,
	eFaBao1�ɽ�Īа,
	eFaBao2�޺���,
	eFaBao3����,
	eFaBao4����,
	eFaBao5������,
	eFaBao6��Ԫɡ,
	eFaBao7�޻����,
	eFaBao8Ǭ��������,
	eFaBao9�ն�,
	eFaBao10���س�,
	eFaBao11�¹ⱦ��,
	eFaBao12��ɫ������,
	eFaBao13��ɫ������,
	eFaBao14��ɫ������,
	eFaBao15��ɫ������,
	eFaBao16����,
	eFaBao17�ܽ����ְ�,
	eFaBao18ʱ֮��,
	eFaBao19ͨ�鱦��,
	eFaBao20�۱���,
	eFaBao21�����«,
	eFaBao22��ľ����,
	eFaBao23���뾵,
	eFaBao24��Ѫ�,
	eFaBao25�������,
	eFaBao26��ħ����,
	eFaBao27����,
	eFaBao28������ë,
	eFaBao29����,
	eFaBao30�������ӡ,
	eFaBao31����,
	eFaBao32�ȱ�,
	eFaBao33�ε�,
	eFaBao15��ɫ������
};

enum eProPerty
{
	eProPerty�˺�,
	eProPerty����,
	eProPerty����,
	eProPerty����,
	eProPertyħ��,
	eProPerty����,
	eProPerty�ٶ�,
	eProPerty��Ѫ,
	eProPerty����,
	eProPerty����,
	eProPerty����,
	eProPertyħ��,
	eProPerty����,
	eProPertyˮ��,
	eProPerty��,
	eProPerty����,
	eProPerty�׿�,
	eProPerty���,
	eProPerty����,
	eProPerty����,
	eProPerty����,
	eProPerty���,
	eProPerty�ظ�,
	eProPerty��ŭ
};

