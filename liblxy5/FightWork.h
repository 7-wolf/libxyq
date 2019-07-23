#pragma once
#include "_stateinc.h"

struct sFightWork
{
	int m_FriendListid = -1;//������¼�ǲ�����ҵĺ���,�Ӷ����º���״̬
	bool Swap(sFightWork& fightlist);

	//���ڼ�¼��ɫս��ǰ��λ��
	int  xOldPos;
	int  yOldPos;
	int  m_oldDirection;
	int m_WorkType;
	bool Free();
	//�ٻ�������ʱ����Ч��
	bool InitFly();
	bool m_bFlyInit;
	int  m_DiePoint;
	// ��: ˵�õ�״̬����?
	bool DieFly();

	int  m_rotateRate;
	bool Rotate(int rotaterate = 3);
	//��һ����ɫ�ȴ�  ,����˵,ת������Ŀ��ʱҪͣ����,���������ܹ�
	int m_SleepTime;
	bool Sleep(int Time, bool bStatic = true);
	//�ܵ����˺�
	cObjWas m_Damage[5]; //��λ,Ҳ�����������ʾ99999���˺�
	int   m_DamageTime[5];
	int m_DamageNum;   //�˺��м�λ
	bool ShowDamage(CMainState* p);
	bool SetDamageRect(int Num); //����ÿ���ֵ�λ�� ���������ֱ��� �ڼ����ֺ�������
	//
	bool m_bSufferFullSkill;//�ý�ɫ�Ƿ�ȫ�巨����

	sFightSkillSelect m_SkillSelect;
	sFightSkillSelect m_SkillPreSelect;
	sFightSkillSelect m_SkillSelectForCounter;
	int               m_ItemSelectID;
	int               m_autoItemSelectID;
	const sFightPoint* GetFightPoint();
//	int           m_SkillIDEx;//����ʹ�÷���ʱ��ʹ��

	cObj* m_pObj = 0;

	// ���ʽ����
	bool NextTarget(cFightState* pFightState, int skillid);
	int  targetID = -1;
	int  m_NowTargetID;
	int  m_NowBeAtkowner = -1;
	vector<int>  targetlist;
	int  m_MaxTargetNum; //��๥��Ŀ��
	int  m_NowTargetIdx;//��ǰĿ����Ŀ���б��е�λ��
	struct sWork
	{
		int type = -1;
		int stage = -1;
	};
	// ��:Ϊʲô����ջ...
	int GetNowWorkType(){ if (!m_work.size())return -1;  return m_work[m_work.size() - 1].type; }
	int GetNowWorkStage(){ if (!m_work.size())return -1; return m_work[m_work.size() - 1].stage; }
	void SetWork(int type, int state = 0);
	void SetWorkFront(int type, int state = 0);
	vector<sWork>  m_work;  //��ɫ�Ĺ���
	sWork* GetWork(){ return &m_work[m_work.size() - 1]; }

	//��ɫ�Ƿ���� ,�����ɫ�ڱ����ɵ�ʱ��,�Ѿ�����,����������
	bool isExist = false;
	bool m_bPrePareFight = false;

	int  m_sufferDirection = 1;

	bool SetMagiSufferID(ulong MagicID, int MagicPos, cWasFile* pFile, bool up = 1);
	bool ShowOnScreen(cCanvas* pCanvas);
	sFightWork();
	~sFightWork();
	void RestTarget();
//	void operator=(sFightWork& flist);
	void SetDie(bool bDie){ m_bDie = bDie; }
	bool CheckDie(){ return m_bDie; }
	int _turnOfSpeed = -1;

	int _myTurn;
	int _ghostTurn;
	int _zhuiji;
	int _nuji;
// 	int _nujiFromCri;
// 	int _nujiFromCom;
	int _longhun;
	int _endmagic;
	int _combo;
	int _moon;
	int _magicCri;

	void reset()
	{
		_myTurn = 0;
		_ghostTurn = 0;
		_zhuiji = 0;
		_nuji = 0;
		_longhun = 0;
		_endmagic = -1;
		_combo = 0;
		_moon = 0;
		_magicCri = 0;
		// ��Ѫ׷��
		if (m_pObj && m_pObj->getPropertyData() && m_pObj->getPropertyData()->isHadPetSkill(2076))
		{
			_zhuiji = 1;
		}
		// ������
		if (m_pObj && m_pObj->getPropertyData() && m_pObj->getPropertyData()->isHadPetSkill(2100))
		{
			_nuji = 1;
		}
	}

private:
	bool m_bDie = false;  //��ɫ�Ƿ����
};

