#pragma once
//����ż�����ش���
#include "_global.h"

class cFightState;
class cSkillManager
{
	enum eMagicWuXing
	{
		eMWX��,
		eMWX��,
		eMWX��,
		eMWXˮ,
		eMWX��,
		eMWX��ˮ,
		eMWX��
	};
public:
//	bool SetPetSkill1(cPropertyData* pPetDate, int ID, int lv = 1);
	void SetMengPaiSkill(cDescribe& describe, int id);

	bool CheckGodLivePercent(int& dam, int target,int userid);//��������
//	void lvUpFuZhuSkill(int targetID, int FuZhuSkillID, int lv);
//	void lvUpMainSkill(cPcData& pcDate, int lv, int ID, bool isHero = false);
//
//	bool SetMainSkill(int targetID,int MainSkillID);
//
//	void SetSpecialSkill2(int targetID, int SkillID,  int Setup);//��װ��Ч
//	void SetSpecialSkill2(cPropertyData* pPetdata, int SkillID, int Setup);//��װ��Ч
//	int  SetPetSkill(cPropertyData* pTarget,int PetSkillID,int Pos=12);
//	bool ReMoveMainSkill(int targetID, int MainSkillID);
	bool CheckHit(cPropertyData* pUserData, cPropertyData *pTargetData, int offset = 0);//����������Ƿ�����
	bool CheckCRI(cPropertyData* pUserData, cPropertyData *pTargetData, int offset = 0);//���



	bool SetDateBuffUp(int userID, int targetID, int stateid, sBuff& buf, int skilllv = 0);  // ��Ŀ���һ��BUFF
	bool SetDateBuffDown(list<sBuff>::iterator& sbuf);//int targetID, int stateid); //��Ŀ��ȥ��һ��BUFF  ������Щ�ܸı��ɫ���Ե�BUFF
	bool CheckFightState(int FightListID);  //ʹBUFF����Ч�� ,  �����ն�����,ÿ�غϿ�ʼҪ��Ѫ
	bool CheckFightStateOnLine����(int FightListID,int& dam);//����ɫ�ܵ�����ʱ,BUFF��Ӱ��
	//bool CheckFightStateApproach(int FightListID);//����ɫ��Ҫ����ʱ��BUFF��Ӱ��;
//	int GetLiveNum(bool our);//�õ����ŵĵ��˵�����
	int GetTargetID(int UserID, int TargetID, int Num); //�õ���UserID��Num���Ļ��ŵĶ���ID
//	bool isIDLive(int ID, int& Num);//���һ�������Ƿ����ѡ�� ,�����Ǹ�Num�����������0,����Զ����0
//	bool SetIndexPos(int UserID, int Index, bool bToAll, ulong DataID);  //��ָ���������ñ�������״̬
	cMengPaiManager m_MengPaiManager;
	bool Init();
	bool Use(sFightSkillSelect SkillSelect, int UserID, bool isPut = false);
	bool UseNormal(int skillID);
	sSkill* GetPetSkill(int ID){ return &m_PetSkillList[ID]; }
	sSkill* GetFuZhuSkill(int ID){ return &m_FuZhuSkillList[ID]; }
	sSkill* GetSkill(int ID);
	sSkill* GetMengPaiSkill(int ID){ return &m_MengPaiManager.m_SkillList[ID]; }
	sSkill* GetSpecialSkill(int ID){return &m_SpecialSkill[ID];}
	sSkill* GetSpecialSkill2(int ID){ return &m_SpecialSkill2[ID]; }
	array<sSkill, c_NumPetSkill> m_PetSkillList;
	array<sSkill, c_NumFuZhu> m_FuZhuSkillList;
	vector<sSkill>    m_SpecialSkill;//�ؼ�
	vector<sSkill>    m_SpecialSkill2;//��Ч
	bool UseSwitchMap(int Skilllv, int sSkillID, int UserID, int TargetID);//���ֻ����ɷ���
	bool Use1��(int Skilllv, int sSkillID, int UserID, int TargetID); //������
//	bool Use7�Ƹ�����(int Skilllv, int sSkillID, int UserID, int TargetID); //�Ƹ�����
	bool Use26(int Skilllv, int sSkillID, int UserID, int TargetID); //������
	
	bool Use71������������(int Skilllv, int sSkillID, int UserID, int TargetID); //����ն ���꽣��
	bool Use80�����ɳ(int Skilllv, int sSkillID, int UserID, int TargetID); //�������
	bool Use84����(int Skilllv, int sSkillID, int UserID, int TargetID);//����
	bool Use1000ƽ��(int Skilllv, int sSkillID, int UserID, int TargetID); //��ͨ����
//	bool Use1002����(int Skilllv, int sSkillID, int UserID, int TargetID); //����
	bool Use1003��Ʒ(int Skilllv, int sSkillID, int UserID, int TargetID); //ʹ�õ���
	bool Use1004�ٻ�(int Skilllv, int sSkillID, int UserID, int TargetID); //�ٻ�
	bool Use1005����(int Skilllv, int sSkillID, int UserID, int TargetID); //ʹ�ð���
	bool Use61����(int Skilllv, int sSkillID, int UserID, int TargetID); //ʹ�ð���
	bool UseĬ�ϼ���(int Skilllv, int sSkillID, int UserID, int TargetID);//  �Ƚϼ򵥵ķ���
	bool Use2105(int Skilllv, int sSkillID, int UserID, int TargetID);//  �Ƚϼ򵥵ķ���
	bool Use1006(int Skilllv, int sSkillID, int UserID, int TargetID); //����
	bool Use107������̩ɽ���޵���(int Skilllv, int sSkillID, int UserID, int TargetID); //������...........
	int CheckMagicHit(int Skilllv, int sSkillID, int UserID, int TargetID);
	//1017 //�Ƹ�
		//case 1050:  //���컨��
		//case 1095://����

	//���һ��������ʾ �Ƿ�����
//	bool Cost(int& outhp, int Skilllv, int sSkillID, int UserID, int num, bool bCost);
	bool Cost(int userid, int skill, int num, bool bCost);
	int GetSpeed(int skillid);
	void EffectSkill(int Skilllv, int sSkillID, int UserID, int TargetID);

	int AddHp(int target, int num, int percent = 0); //��percent��Ϊ0, numΪ�ٷֱ�,�ı����ֵΪpercent*num;
	int AddMp(int target, int num, int percent = 0);
	void AddHpHurt(int target, int num, int percent = 0);
	void AddCp(int target, int num, int percent = 0);
	int m_time;
	bool Resurgence(int TargetID);
	//3000�������ؼ�
	sItem2* GetItem(int UserID);
	bool CoutCombo����(cPropertyData* user, cPropertyData* target);
	bool CountCri(cPropertyData* user, cPropertyData* target);//��ɱ����,�����Ƿ��ɱ
	void CountCriDamage(cPropertyData* user, cPropertyData* target, int& dam);
	int CountSpecial(cPropertyData* user, cPropertyData* target/*, bool targetSex*/);//�ع�����
	bool CountCriMagic(cPropertyData* user, cPropertyData* target, int& nowdam);//��������
	bool CoutComboMagic(int skillid, cPropertyData* user, int userid, cPropertyData* ptarget);
	
	void  CountphysicalDamage(int& dam, int UserID, int TargetID, int Damage�ӳɰٷֱ� = 0);
	void count�׻�(int& dam, int TargetID);

	bool  CountMagicDamage(int& dam, int UserID, int TargetID, int Damageup, eMagicWuXing wuxing, int& userData); //���㷨���˺�
	bool  CountMagicDamage(int& dam, int UserID, int TargetID, int Damageup = 0, eMagicWuXing wuxing = eMWX��)
	{
		int v;
		return CountMagicDamage(dam, UserID, TargetID, Damageup, wuxing, v);
	}
	
	void  CountMagic2Damage�̶�(int& dam, int UserID, int TargetID, eMagicWuXing wuxing = eMWX��);//�̶��˺�����
	bool  CountParry(cPropertyData* pUserData,cPropertyData* pTargetData);//��������
	bool  CountProtect(int& dam, cObj* pUser, cObj* pTarget);//��������
	void CorrectCureHP(int& dam,int UserID,int TargetID);//������������
	void CorrectCureHP(int& hp, int& hp2, int UserID, int TargetID);//������������
	void CorrectCureMP(int& dam, int UserID, int TargetID);//������������
	int  CountHPPercent(cPropertyData* ptarget, uint num, uint bili)
	{ 
		uint dam = (ptarget->HPMax.GetData() *num) / 100;
		if (dam > num*bili)dam = num*bili;
		return (int)dam;
	}
	int  CountMPPercent(cPropertyData* ptarget, uint num, uint bili)
	{
		uint dam = (ptarget->MPMax.GetData() *num) / 100;
		if (dam > num*bili)dam = num*bili;
		return (int)dam;
	}
	cFightState* m_pFightState;
	bool SetDamage(int HP, int Who); //��ʾ���˶���Ѫ,����Ǹ���,��ʾ�ָ�����Ѫ, �˺��������ڱ�����ʾ��Щ����,��Ϊ��ʱ����������10000Ѫ,�������ʾ9999 
	bool CheckFanZheng(int UserID,int TargetID,int& dam);//������
	void SuckBlood(int dam, int UserID,cPropertyData* target);
	// buf: state time damage(��ɱ�õ�)
	void CheckPoision(int UserID, int TargetID, int offs, sBuff buf);
	void CheckPoision(int UserID, int TargetID);

	bool StageWaitReturn(int UserID, int retStage);//�ȴ�����
	bool StageWaitFightBack(int UserID, int TargetID, int retStage);//�ȴ����ַ���
	bool StageWaitProtect(int atkid, int UserID, int retStage);//�ȴ������߾�λ
	bool StageWaitSleep(int time, int UserID, int retStage);
	// 0�ӳ�?
	bool GetSkill��ҪĿ�걻�򶯻�(int ID);
	bool isAni������(int ID);
private:
	int CorrectWuXing(cPropertyData* pUser, cPropertyData* pTarget, eMagicWuXing MagicWuXing);
	bool WaitForMagicPoint(int Waiter);
	void GetDelayAnd(int skillID, int& delay, ulong& magicID);
	void GetMagicAndNum�뼸(int Skilllv, int sSkillID, int UserID, int TargetID, ulong& MagicID, int& NumMax, int& MagicPos,  bool& MagicUporDown, bool&  toAll������);
	bool PhysicalAtkHitStage(int UserID, int targetid, int sSkillID);//�����Ƿ�����
	bool m_bInit = false;
};