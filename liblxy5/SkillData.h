#pragma once

//����һ������
struct sSkill
{
	string m_Name;
	int    m_Id = 0;
	string m_Text;//����
	string m_tCost;//���ĵ�����
	string m_tCostHpMp;
	int    m_Cost = 0;
	ulong  m_BigHead = 0;
	ulong  m_SmallHead = 0;
	int   m_SkillType = 0;
	int   m_EffectType = 0;
	int   m_Owner = -1; //λ��
	ulong m_State = 0;
	ulong  m_Sound = 0;
	int m_NumUnCompatible = 0;
	vector<int> m_UnCompatible;
	ulong  m_MagicID = 0;  //��������
	int  m_MagicPos = 0; //������λ��
	int  m_TargetNum = 0;//Ŀ������� �������������7 �Ǹ���������7
	int  m_TargetNumOffset = 0;//���ټ�Ŀ����+1   �����������25����һ��Ŀ��
};

//struct sPetSkill
//{
//	int m_ID;
//	int m_SkillType;
//	ulong m_BigHead;
//	ulong m_SmallHead;
//	string m_Describe;
//	string m_Cost;
//	string m_Name;
//	int m_NumUnCompatible;
//	vector<int> m_UnCompatible;
//};


const int c_NumPetSkill = 112;        //�ٻ��޼��ܵ�����
