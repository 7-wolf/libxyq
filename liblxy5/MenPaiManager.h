#pragma once
#include "_global.h"


//����һ��������
class cZhuJiNeng
{
public:
	int m_ID; //������ID
	string m_Name;
	ulong m_SmallHead;
	ulong m_BigHead;
	string m_Text;//����  ����ʲô����
	string m_Text2;//����2   ѧϰЧ��
	//��������
	int m_NumSkillInclude;
	// ԭ��12
	array<int, 14> m_Limit���ܽ���;
	array<int, 14> m_SkillIncludeID;

};
//����һ������
class cMengPai
{
public:
	int m_ID;
	string m_Name;			//���ɵ�����
	string m_ShiFuName;    //����ʦ��������
	string m_ShiFuMap; //����ʦ�����ڵ�ͼ
	string m_XunLuoMapName;//ʦ��Ѳ�ߵĵص�
	array<cZhuJiNeng, 7> m_MainSkill;//������
};



const int c_SkillNum = 206;

class cMengPaiManager
{
public:
	bool  Init();
	cMengPai* GetMengPai(cCharacter* pc);
	cMengPai* GetMengPai(int ID){ if (ID < 0 || ID >= c_NumofCharacter)return nullptr;  return &m_MengPai[ID]; }
	sSkill*   GetSMSkill(int ID){ return &m_SkillList[ID]; }
	cMengPai  m_MengPai[c_MenPaiNumber];//���ɱ�
	sSkill m_SkillList[c_SkillNum];//ʦ�ż��ܱ�
//	void lvUpMainSkill(cPcData& pcDate, int lv, int ID, bool isHero = false);
private:
	bool m_bInit;
};