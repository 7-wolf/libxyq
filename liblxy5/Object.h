#pragma once
#include "_objinc.h"

const int c_NumFuZhu = 4/*13*/;
struct sBuff
{
	int ID;   //BUFF��ID
	ulong MagicID;
	//int Type; 
	int remainingTimes;//ʣ��ʱ��
	//buf�ķ�����ʾЧ��
	int bufPos;  //λ��
	cWasFile data;
	bool bBuffup; //�����滹������
	int userID;
	int targetID;
	eBuffType EffectType;//���BUFF������, 0 ����  1 �쳣 2 �� 3 �����ٻ�  
	int damage;
	int damage2;
	int skilllv = -1;
};


// struct sItemData
// {
// 	string m_name;
// 	ulong	m_smallhead;
// };
// struct sFabaoData
// {
// 	string m_name;
// 	ulong	m_smallhead;
// };
// 
// 
// struct sSkillData
// {
// 	string m_name;
// 	ulong	m_smallhead;
// 	ulong	m_bighead;
// 	ulong	m_majic;
// 	ulong	m_defend;
// };




#define WORKTYPE_ATTACK    1    //����
#define WORKTYPE_MAGIC     3    //ʩ��
#define WORKTYPE_APPROACH  4    //�ӽ�
#define WORKTYPE_DEFEND    5    //��
#define WORKTYPE_SUFFER    6    //�ܵ�������
#define WORKTYPE_RETURN    7    //����
#define WORKTYPE_MAGICSUFFER  8  //�ܵ�ħ������
#define WORKTYPE_MAGICATTACK  9   //����������������
#define WORKTYPE_FLY       10     //�ٻ��ޱ�����
#define WORKTYPE_FALLDOWN  11  //��ɫ����
#define WORKTYPE_CATCH  12  // ץ��
#define WORKTYPE_AVOID  13  // �ر�
#define WORKTYPE_MAGIC2   14    //ʹ�����ⷨ�� �������,����
#define WORKTYPE_ITEM     15    //�õ���
#define WORKTYPE_SUMMON   16    //�ٻ�
#define WORKTYPE_GUARD   17    //����
#define WORKTYPE_COUNTER 18  //����

#define INDEXTYEP_CHARACTER 100
#define INDEXTYEP_PET       101
#define INDEXTYEP_NPC       102

enum PropertyType
{
	typeAtkZZ,
	typeDefZZ,
	typeHPZZ,
	typeMagZZ,
	typeSpdZZ,
	typeAvoidZZ
};


// 
// 
// 
// struct sShangPinPet;
// 
// 
// 
// 
// class cCharacter;
// class cPCData;
//һ��BBӦ���е�����

// class cPetData : public cPetData, public cZZBase
// {
// public:
// 	virtual void Followlv(int lv, bool isBabyMode, bool isAdd, bool isEquip);
// 	void AddHpZZ(int num);
// 	void AddMagZZ(int num);
// 	void AddAtkZZ(int num);
// 	void AddAvoidZZ(int num);
// 	void AddSpdZZ(int num);
// 	void AddDefZZ(int num);
// 	void AddGrowing(int num);
// };
// 
// 
// class cMengPai;
// struct sSkill;

struct sFightSkillSelect
{
	int SkillLv=0;
	int SkillID=-1;
	int TargetID=-1;
};


// enum eCharacterEquip
// {
// 	eChaEquipWuqi,
// 	eChaEquipTouKui,
// 	eChaEquipYaoDai,
// 	eChaEquipXieZi,
// 	eChaEquipXiangLian,
// 	eChaEquipYiFu
// };

