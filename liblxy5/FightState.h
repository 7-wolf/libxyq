#pragma once
#include "_stateinc.h"

class CGameState
{
public:
	CGameState(){ isInit = 0; };
	virtual ~CGameState(){};
	virtual bool Init(void* pData = 0) = 0;
	virtual bool Frame(void* pData = 0) = 0;
	virtual bool Free() = 0;
	bool isInit;
};

class cFightState :public CGameState
{
private:
	void FillHpMpMedicine();
	void EndFight(bool bFillHpMpMedicine = true);
public:
	cFightState();
	void EscapeFight();
	void SuccessFight();
	void FailFight();
	void DieEffect(int endTitle_or_fly2DF);//�ɵ��ظ�,����ʧһ������Ǯ



	void ClearState(int id);//ȥ������BUFF
	bool AddState(int userID, sBuff buf);//����һ��BUFF
	bool ReMoveStateID(int id, int userID);//ȥ��һ��IDΪuserID�� BUFF
	bool ReMoveSealState(int userID);//���
	bool ReMovePoisionState(int userID);//�ⶾ
	bool ReMoveBuffState(int userID);//������BUFF
	bool ReMoveDeBuffState(int userID);//�⸺��BUFF
	bool ReMoveState(eBuffType Type, int userID);

	void SetFightBufDown(int i);
	bool m_bEscape = false;//���ܱ�־
	void SetDie(int ID, bool dynamicFly = false);//���һ�������Ƿ�����,����������(�ɵ�,����)
	HDC     m_hFightBack;
	HBITMAP m_hFightBack1;
	cWasFile  m_FightBack1;
	uchar*     m_pFightBack = 0;
	int m_turn;  //�ȴ���������,ս��
	int m_CurrIDPerTurn;//��ǰ���ж���ID
	int _turn = 0;
	int _leaveBegin;
	bool SortBySpeed();


	//����̸߳�����ط���ͼƬ,����������ʾ�Ͳ��Ῠ��0_0!
	cWasFile* m_pFileToLoad[5];
	ulong   m_IDtoLoad[5];

	bool   m_ThreadSleep = true;
	HANDLE m_hThread;

	int m_HiddenWeaponsUseNum = 0;
	cWasFile m_HiddenWeapons;
	cWasFile _magicCri;
	cObjWas m_HiddenWeaponsp[10];
	int   m_HiddenWeaponsTargetID[10];
//	bool HiddenWeaponsFly();
	bool HiddenWeaponsMove(int id, int yoffset = 0);
	int   m_ShowTurnType[30];
	void*  m_pShowTurn[30];
	int   m_ShowTurnUseNum;

	static unsigned int WINAPI ThreadProc(_In_  LPVOID lpParameter);

	cFullMagic m_FullSkill;

	cInterfaceFight m_FightMenu;
	cText m_Frame;  //������
	bool Suffer(int ID);
	float m_Sufferspd = 4;
	void SortShow();

	bool MagicSuffer(int ID);
	bool SetWork(int ID, int Type);
	bool SetMagicSuffer(int ID, int direction);//��һ���������óɱ�������״̬
	bool SwitchMagicSuffer(int ID);  //��һ����λ���ܷ���״̬ת�ɱ���״̬
	bool SwitchMagicSufferAvoid(int ID);  //��һ����λ���ܷ���״̬ת�ɱ��ر�״̬
	bool SetSuffer_state30(int ID, int direction, int userid);//��һ���������óɱ���״̬


	bool SetAvoid_state15(int ID, int direction);
	void SetTarget(int ID, int Target);
	// Idʹ��skillidĿ��target,��һ������target
	int CheckTarget(int ID, int target, int skillid);
	bool DoWork();
	bool isInRect(long x, long y, cWasFile* pPic, cMyMap* pMap);
	bool Init(void* pData = 0);
	bool Frame(void* pData = 0);

	int GetSelect(long x, long y);
	bool Free();
	bool ProcessInput();
	int  AutoSelectRand(bool isSelectEnemy);//���ѡ��һ������,���EnemyΪ1 ��ѡ��з�,���Ϊ0,��ѡ���ҷ�.  ����޷�ѡ������,�򷵻�-1(�����ܳ������������?)
	bool FallDown(int ID);//��ɫ����
	//	bool Catch(int ID);
	bool Avoid(int ID);
	bool ApproachProtect(int ID, int TargetID);
	// ����
	bool Guard(int ID, int xTarget, int yTarget);
	bool Counter(int ID);
	void SetCounter(int ID, int TargetID);
	bool SetDefend_stage30(int ID, int direction, int userid);
	bool Defend(int ID);
	bool Approach(int ID, int TargetID, bool gap = false, float Speed = 15.0f);  //����ƶ����˷�Χ��,����true 
	bool ReturnApproach(int ID, float Speed = 20.0f);  //����ƶ����˷�Χ��,����true
	// 0 �ӽ��� 1 2 3 ������?  �˺���?
	int WorkAttack(int userID);//���Ŀ�겻�ڹ�����Χ��,���ȵ���Approach�ӽ� ����һ���������Ŀ�ʼ�������ж�,ʹ����˺���,��Ҫ��WaitPosEnd�ȴ���������
	bool WaitPosEnd(int userID);//�˺��������ǵȴ�������ɶ���.
	vector<sFightWork*>  m_pFightWorkList;

	int  m_SpeedListPos[20];
	int m_ս������xs[20];
	int m_ս������ys[20];
	cText m_MiaoShu;

	void CheckPetExp();
	bool PrePareToFight(int i);
	bool BackFromFight(int i);
private:


};
