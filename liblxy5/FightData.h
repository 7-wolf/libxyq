#pragma once
#include "_asert.h"
#include "IntData.h"

struct sFightData
{
	//��ʾ��ɫս��ʱ������ (ս��ʱ���Ի���õ���BUFF���ı�.���ǵ�Ȼ����ֱ���ý�ɫ��������������)
// 	sInt3  m_oldATK;   //�˺�
// 	sInt3  m_oldHIT;   //����
// 	sInt3  m_oldDEF;   //����
// 	sInt3  m_oldWakan; //����
// 	sInt3  m_oldSPD;   //�ٶ�
// 	sInt3  m_oldEvade; //����
// 	sInt2  m_oldGoldLive;//����
//	bool _isFlyOld;
	//һ����ɫ��״̬�б�
	int SufferNum;	//��¼���غϱ���Ĵ���
	int AttackNum;	//��¼���غϵĹ�����
	int cannotAttack; //�Ƿ����ʹ��������   
	int cannotMagic;  //�Ƿ����ʹ��ħ��
	int cannotSpesialSkill;  //�Ƿ����ʹ���ؼ�
	int cannotUseItem;//�Ƿ����ʹ�õ���
	int cannotAddHP;  //�Ƿ���Լ�Ѫ
	int cannotAll;  //�Ƿ���Զ�  ���߷���Ч���������,������Ҳ�����
	int chaos���ҷ���;		//�Ƿ����
	int cannotLive;  //�Ƿ���Ա�����
	int yanhu; // �׻�
	int zhanyi; // ս��
	bool m_bHit; //��¼�Ƿ�����  �����ֵ���ж��Ƿ���Ҫ����	
	bool m_bDefend;//�Ƿ����
	bool m_bCri;//�Ƿ񱻱�ɱ
	vector<int>  m_guardID;//��¼�Ƿ񱻳ɹ����� �� �������Ľ�ɫ��ID
//	bool _isDieOnceForPet;
// 
// 	int m_MaxDef;
// 	int m_MaxMagicDef;
	//��¼ǿ��״̬
	int m_AtkIntensify;
	int m_DefIntensify;
	int m_SpdIntensify;
	int m_WallNum; //
	void Reset();
	void Clear()
	{
		m_guardID.clear();
		m_AtkIntensify = 0;
		m_DefIntensify = 0;
		m_SpdIntensify = 0;
		m_WallNum = 0; //
		Reset();
	}
	bool Init();
	// ���� * �ȼ��� ��ϧ���Ѿ��Լ�*�ȼ���
	int m_TurnHPAdd;
	int m_TurnHPHurtAdd;
	int m_TurnMPAdd;
};