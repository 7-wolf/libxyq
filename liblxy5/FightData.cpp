#include "FightData.h"

bool sFightData::Init()
{
	chaos���ҷ��� = 0;
	cannotAttack = 0; //�Ƿ����ʹ��������   
	cannotMagic = 0;  //�Ƿ����ʹ��ħ��
	cannotSpesialSkill = 0;  //�Ƿ����ʹ���ؼ�
	cannotUseItem = 0;//�Ƿ����ʹ�õ���
	cannotAddHP = 0;  //�Ƿ���Լ�Ѫ
	cannotAll = 0;  //�Ƿ���Զ�  ���߷���Ч���������,������Ҳ�����
	cannotLive = 0;
	m_bHit = 0; //��¼�Ƿ�����  �����ֵ���ж��Ƿ���Ҫ����
	yanhu = 0;
	zhanyi = 0;
	//��¼�Ƿ񱻳ɹ����� �� �������Ľ�ɫ��ID
	m_guardID.clear();
// 	m_MaxDef = 0;
// 	m_MaxMagicDef = 0;

	m_TurnHPAdd = 0;
	m_TurnMPAdd = 0;

	m_TurnHPHurtAdd = 0;
	//һ����ɫ��״̬�б�
	Clear();

//	_isDieOnceForPet = false;
	return true;
}

void sFightData::Reset()
{
	SufferNum = 0;//��¼һ�غ��н�ɫ����Ĵ���
	AttackNum = 0; //��¼��ɫ���غϵĹ�����
}


