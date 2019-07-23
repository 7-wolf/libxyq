#pragma once
#include "_asert.h"

enum eAIUseItemType
{
	eAIUseItemTypeHP,
	eAIUseItemTypeHPALL,
	eAIUseItemTypeMP,
	eAIUseItemTypeMPALL,
	eAIUseItemTypeHPHurt,
	eAIUseItemTypelive,
	eAIUseItemTypeUnseal,
	eAIUseItemTypeCP,
	eAIUseItemType����
};


struct sFightWork;
// class cObj;
// class cCharacter;
// class cPetData;
class cAI
{
public:
//	cAI();
// 	
// 	int m_ButtonSelect = -1;
// 	int m_ObjSelectid=-1;
//	bool m_bPKMode = false;//��������,�ѶȽ�����
//	void resetNeed();

	bool See(int user, int target, bool check = true);

	// ��Ҫ�Ǽ������
	void checkHero();

	void Escape(int userID);//����
	// ����
	// ������/�ж����� return;
	// ���� ��״̬1�غ�
	// sFightList::m_WorkType = -2 ?? Ϊʲô���� WorkType_defense
	void defense(int userID);

//	int m_FightTarget[20];

	enum eEnemyType
	{
		// �з�����
		eET�Ͻ��33,  //����1������
		eET���鶯112, //����1������
		eET�ɷ�ϵ,	  // FC NR PS WZ TG WD
//		eET��Ҫ��ϵ,  // ��DT
		eETҽ��ϵ,    // HS PT WD Ѫ��
//		eET����,
//		eET����,
//		eETѪ��,
		eETѪ����,
//		eET����������,
		eET�����,
		eET�����,
//		eET��������,
//		eET���ⷨ��,
//		eET������,
		eET���ٻ���,
		eET��������,
		eET�ٶ����,
		eET�ٶ����2,
		eET��ӡ����,
		eET��Ѫ,
		eET������ϵ,
 		eET�ɷ�ϵ,
 		eET����6,
		eET�ߵ�����113,
		eET���ޱ�46,
		eET������ɽ95,
		eET���ݻ���99,
		eET������129,
		eET��Ȫ֮Ϣ126,
		eET�����ɢ127,
		eET����120,
	};

	int finds(bool CheckDie, bool bCheckWork, vector<POINT>& out, eEnemyType type, int userid, int data = -1, int data2 = -1);//Ѱ���ض�����


	enum class eFindType
	{
		None,
		SpeedMax,
		Hp30,
		Hp70,
		HpNotFull,
		HpRateMin,
		Mp0,
		MpMin,
		ManaMin,
		MpSeal,
		MpCure,
		MpPhy,
		MpMag,
		Dying,
		Relifeable,
		Sealable,
		UnSeal,
		UnSealAndPosion,
		Hide,
	};

	// ���˺ͽ��
	map<eFindType, set<int>> _controlMap;


	vector<int> finds(int user, int start, int end, eFindType e = eFindType::None, const function<bool(int)>& condition = nullptr, int checkState = -1, bool checkDie = true, bool checkHide = true);

	vector<int> findOthers(int user, eFindType e = eFindType::None, const function<bool(int)>& condition = nullptr, int checkState = -1, bool checkDie = true, bool checkHide = true)
	{
		int start = user < 10 ? 10 : 0;
		int end = start + 10;
		return finds(user, start, end, e, condition, checkState, checkDie, checkHide);
	}

	vector<int> findOwners(int user, eFindType e = eFindType::None, const function<bool(int)>& condition = nullptr, int checkState = -1, bool checkDie = true, bool checkHide = true)
	{
		int start = user / 10 * 10;
		int end = start + 10;
		return finds(user, start, end, e, condition, checkState, checkDie, checkHide);
	}

//	vector<int> check����(vector<POINT>& out, int user);


//	void RunZhiHui(int start, int end, int mode, int select);
//	void GetNeed(int start,int end);//����,����Ѫ������,Ҫ���Ѫ
//private:
//	void PreRun(int start, int end);//��������
//	bool SaveOneself(int start, int end);//�Ծ�
//	int FintTarget(int i);

	vector<int> findTarget(int skill, int& findsCount);
	vector<int> findTarget(int skill){ int findsCount;  return findTarget(skill, findsCount); }
//	int FindCpMaxTarget(int num=100);//Ѱ�ҵз�CP>num�Ķ���
//	int FindDefminTarget(int start, int end, eProPerty prop,bool maxormin, int userID = -1);
//	int FindDefminTarget(eProPerty prop, bool isMax){ return FindDefminTarget(m_UserID < 10 ? 10 : 0, m_UserID < 10 ? 20 : 10, prop, isMax, m_UserID); }
//	int findʬ��������();
//	int find��ȫ��();
// 	int FindδSeal(int num);
// 	int FindδSeal(int start, int end);
// 	// 0�� 1�� 2�ؼ�  
// 	int FindδSeal(char &isMorA);
// 	bool FindδSeal(int id, char &isMorA);
public:
	bool AutoRunAi(int id);//,int targetid);
//private:
//	void AutoRunEnemyAi(int id);
//	bool CheckHaveState(int userid,int skillid);
	void NormalAtk(const vector<int>& targets);
	bool Summon();//�ٻ�
public:
	void UseSkill(int id, const vector<int>& targets);
//private:
//	void NpcTryMagic(int id);//�����Ƿ����㹻������ħ��,�����������



//	bool UseItem(eAIUseItemType mode);
//	bool CheckItem(eAIUseItemType mode);
	int m_HPLimit = 66;//1-99 HP���� 100 - m_HPLimitʱ��Ѫ
//	void ResetNeed();
// 	int m_bNeedAddHp[20];//���غϸö����Ƿ���Ҫ��Ѫ
// 	int m_bNeedAddHpHurt[20];
// 	int m_bNeedUnSeal[20];//���غϸö����Ƿ���Ҫ���
// 	int m_bNeedlive[20];
// 	int m_bNeedAddMp[20];
// 	bool m_bBeSeal[20];//�Ƿ񱻷�
// 	bool  m_bSeal[20];//
// 	int  m_bAtk[20];//
// 	bool  _isShiFudu[20];
	//bool  m_bBeLive[20];//�Ƿ񱻸���
	//bool m_bCure[20];//������
	//bool m_bCureMP[20];//����MP
	////void CoutIdleList(int start,int end);
	

	void SetUser(int userid);
	int m_UserID = -1;
	sFightWork* pUserList=0;
	cObj* m_pUser=0;
	cCharacter* m_pUserPc=0;
	cPropertyData* m_pUserData=0;

// 	void SetTarget(int target);
// 	int m_TargetID = -1;
// 	sFightWork* m_pTargetList=0;
// 	cObj* m_pTarget=0;
// 	cCharacter* m_pTargetPc = 0;
// 	cPropertyData* m_pTargetData=0;

public:
//	void ZhiHui(bool bOut);//
//private:
// 	void ContentLive(int start,int end);
// 	void ContentLive2(int start,int end);
// 	void ContentHP(int start, int end);
// 	void ContentHP2(int start, int end);
// 	void ContentUnSeal(int start, int end);
// 	void ContentUnSeal2(int start, int end);
	bool Cost(int skillid);
	bool Cost(int user, int skill);
public:
	bool isHadPetSkill(cPropertyData *data, vector<int> &buffSkills, vector<int> &pSkills, vector<int> &mSkills, vector<int> &m2Skills);
	bool isHadPetSkill(const vector<sSkill*> &skills, vector<int> &buffSkills, vector<int> &pSkills, vector<int> &mSkills, vector<int> &m2Skills);
// private:
//	int getVisibleNO(int userID, bool userTeam, bool isCheckPeopleSpecial);
//	int getVisibleNO(){ return getVisibleNO(m_UserID, false, true); }

	bool runPoxueRuodianPosui3000();
	bool runUnSeal3000(bool isSelf);
	bool runResurgence3000();
	bool runCure3000();
//	bool isAtkMode(){ return cct::get()->isAtkMode(m_UserID); }
	bool isCanAtk(){ return !m_pUserData->m_FightData.cannotAttack; }
	bool isCanMag(){ return !m_pUserData->m_FightData.cannotMagic && !m_pUser->CheckHaveState(199); }
	bool isCanSpec(){ return !m_pUserData->m_FightData.cannotSpesialSkill; }
//	bool isPut(){ return false/*m_pUserPetData->m_ZiZhi.grow < (int)cct::get()->putMenpaiSkills.size()*/; }
//	bool isPutRate();
//	bool isPetRate(){ return rand() % 100 < 38; }
//	bool isUseOtherRate(){ return rand() % 100 < 62; }
//	bool selectAtk();
	// 0����
	// 1����
	// 2״̬
	// 3����
	// 4����
	int RunPet();
	bool RunLH();
	bool RunDT();
	bool RunHS();
	bool RunNR();
	bool RunFC();
	bool RunLG();
	bool RunWZ();
	bool RunPT();
	bool RunTG();
	bool RunDF();
	bool RunPS();
	bool RunMW();
	bool RunST();
	bool RunWD();
	bool RunLB();
	bool RunSM();
//	void SaveOneself2(int id);
 	bool resurgence(int user/*, int target*/);
// 	void resurgence2(vector<POINT>& user, vector<POINT>& target,int targetID);
 	bool Cure(int user/*, int target,bool toall=false*/);
	bool CureSelf();
// 	void Cure2(vector<POINT>& tlist, int start, int end);
// 	void UnSeal2(vector<POINT>& tlist, int start, int end);
// 	bool UnSeal(int user, int target);
// 
// 	bool CureMP(int user, int target, bool toall = false);
// 	void CureMP2(vector<POINT>& tlist, int start, int end);


// 	enum eEnemyCorrect
// 	{
// 		eEC����
// 	};
// 	void CorrectEnemy(vector<POINT>& out,eEnemyCorrect typ);



	// ���ѡ��Ŀ��
	// SelectType �Ƿ���������
	// 0 ƽʱ�Լ�
	// 1 ƽʱ����
	// 2 ս���Լ�
	// 3 ս������
	// 4 ս���з�
	// 5 ƽʱս���Լ�
	// 6 ƽʱս������
	// 7 ����
	// 8 δ
	// 9 ս������but�Լ�
	int  find׷�������¹�(int userID, int SelectType, bool isCheckPeopleSpecial);
	vector<int>  findSkillType2(int userID, int SelectType);
	vector<int>  findSkillType(int user, int skill);
	// �������˫��
	// Num 0~19 ûɶ��
	// bLive
	// 0 ��λ
	// 1 ���
	// 2 ����
	// 3 ���ü��Ļ���
	int  find���䰵��(int usetId, int ID, int idx, int bLive);

	// Ŀǰֻ���ڼ�����λ
	int  find��λ(int ID, int Num, int bLive);




	bool isSkillSeal(int skill);
	bool isSkillResurgence(int skill);
	sFightWork* s_list1, *s_list2;
	cObj* s_obj1, *s_obj2;
	cPropertyData* s_data1, *s_data2;
	void setData(int i1, int i2);
	int getMagicDamage(int user, int target, int Damageup);
	int getPhyDamage(int UserID, int TargetID, int Damageup);
	int getDamage(int user, int target, int skill);
	bool isAtkFromPoint(cPropertyData* data);
	bool isMagFromPoint(cPropertyData* data);
	bool isState(cObj* obj, const vector<int>& ss);
	bool isStateDMag(cObj* obj);
	bool isNotState(cObj* obj, const vector<int>& ss);
	bool isPosion(cObj* obj);
	bool isMpSeal(cPcData* pc);
	bool isMpCure(cPcData* pc);
	bool isMpPhy(cPcData* pc);
	bool isMpMag(cPcData* pc);
	vector<int> getCures(int user);
	vector<int> getSeals(int user);
	vector<int> getCureSeals(int user);
// 	bool runSkill(eSkill skill, int size);
// 	bool runSkill(const vector<eSkill>& skills);
// 	bool runSkill(eSkill s);
	vector<int> getFires(int user);
	bool isHpLessThan(cPropertyData* data, int rate);

};