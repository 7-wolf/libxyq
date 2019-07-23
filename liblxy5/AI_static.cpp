#include "_global.h"
#include "_txt.h"


bool cAI::isSkillSeal(int skill)
{
	eSkill e = (eSkill)skill;
	switch (e)
	{
	case eSkill::����֮��:
	case eSkill::���߷�:
	case eSkill::ʧ�ķ�:
	case eSkill::���Ƿ�:
	case eSkill::ʧ���:
	case eSkill::׷���:
	case eSkill::����:
	case eSkill::ʧ���:
	case eSkill::�����:

	case eSkill::��׷�:

	case eSkill::��������:
	case eSkill::�绨����:
	case eSkill::��������:
	case eSkill::һЦ���:
	case eSkill::����:
	case eSkill::����:
	case eSkill::�������:
	case eSkill::����Ǭ��:

		// 	case eSkill::�����ɢ:
		// 	case eSkill::������:

	case eSkill::����:

		// 	case eSkill::����:
		// 	case eSkill::����:
		// 	case eSkill::ħ�����:

	case eSkill::��������:

	case eSkill::������:
		// 	case eSkill::ɷ����:
		// 	case eSkill::������:
		// 	case eSkill::������:

		return true;
	}
	return false;
}

bool cAI::isSkillResurgence(int skill)
{
	eSkill e = (eSkill)skill;
	return (e == eSkill::�ػ��� ||
		e == eSkill::�������� ||
		e == eSkill::�ҷ�ȱ� ||
		e == eSkill::������ ||
		e == eSkill::�ɼ����� ||

		e == eSkill::������¶ ||
		e == eSkill::�Ⱥ��ն�);
}

void cAI::setData(int i1, int i2)
{
	s_list1 = &g_pMainState->m_FightWorkList[i1];
	s_list2 = &g_pMainState->m_FightWorkList[i2];
	s_obj1 = s_list1->m_pObj;
	s_obj2 = s_list2->m_pObj;
	s_data1 = s_obj1->getPropertyData();
	s_data2 = s_obj2->getPropertyData();
}


int cAI::getMagicDamage(int user, int target, int Damageup)
{
	int UserID = user;
	setData(user, target);
	cObj* pUser = s_obj1;
	cPropertyData* pUserData = s_data1;
	cPropertyData* pTargetData = s_data2;
	int wakanUser = pUserData->Mana.GetData();    //��������
	int  wakanTarget = pTargetData->Mana.GetData(); //Ŀ������
	//	wakanTarget -= pUserData->m_Lv<<1;
	// ����
	// 	int turn = m_pFightState->m_pFightWorkList[TargetID]->_myTurn;
	// 	if (pTargetData->isHadPetSkill(75) && turn < 5) // ���ܼ���
	// 	{
	// 		wakanTarget += (5 - turn) * pTargetData->m_Lv / 5;
	// 	}

	int& atknum = pTargetData->m_FightData.SufferNum;
	////////////////////////////////////////////////////////////////////////// �Ǻ��� ����Խ����Խ�޷�����
	int pierce = pUserData->Pierce�̴�OfMagic.d1 + atknum/* * 3*/;
	//	if (pierce)
	{
		if (pierce > 100)pierce = 100;
		wakanTarget -= (wakanTarget* pierce) / 100; //��������
	}
	// 	int DamageAddPercent = pUserData->DmgPercentOfMagic.d1; //��������������
	// 	int DamageDefPercent = pTargetData->DmgPercentOfMagic.d2;   //Ŀ�귨����������
	// 	if (DamageDefPercent > 9900)
	// 	{
	// 		DamageDefPercent = DamageAddPercent + DamageDefPercent - 9900;
	// 	}
	//	dam = (wakanUser)-(wakanTarget)/*+pUserData->m_Lv*/;

	int װ���˺����� = pUserData->m_Lv;
	if (pUser->m_IndexType == INDEXTYEP_CHARACTER)
	{
		cCharacter *pc = (cCharacter*)pUser->m_pIndex;
		װ���˺����� = pc->m_PcData.getEquipAtk() / 4;
	}
	int skillLv = pUser->GetSkillLv(0);
	if (!skillLv)
	{
		skillLv = pUserData->m_Lv;
	}
	int targetNum = g_pMainState->m_FightWorkList[UserID].m_MaxTargetNum;
	if (targetNum < 1) targetNum = 1;

	int dam = (skillLv * Damageup + wakanUser * 10 - wakanTarget * 10 + װ���˺����� * 10) * (21 - targetNum) / 200;

	// 	if (pUserData->isHadPetSkill(103))
	// 	{
	// 		// ӵ����������,+ħ��*0.4���˺���
	// 		dam += pUserData->PointMag * 2 / 5;
	// 	}
	Damageup = 0;
	int xiuliancha = 0;// pUserData->m_XiuLian.GetMag() - pTargetData->m_XiuLian.GetDMag();
	// 	float damf = (float)dam;
	// 	if (xiuliancha > 0)
	// 	{
	// 		for (int i = 0; i < xiuliancha; ++i)
	// 		{
	// 			damf = damf * 1.02f + 5;
	// 		}
	// 	}
	// 	else
	// 	{
	// 		for (int i = 0; i < (-xiuliancha); ++i)
	// 		{
	// 			damf = damf * 0.98f - 5;
	// 			if (damf < 1)
	// 			{
	// 				damf = 1;
	// 				break;
	// 			}
	// 		}
	// 	}
	// 	dam = (int)damf;
	//	Damageup += CorrectWuXing(pUserData, pTargetData, wuxing);//��������	
	//	Damageup += CountSpecial(pUserData, pTargetData/*, pTarget->GetSex()*/);//�ع�����

	dam = dam * (100 + xiuliancha * 2 + pUserData->DmgPercentOfMagic.d1 - pTargetData->DmgPercentOfMagic.d2 + Damageup) / 100;
	dam += pUserData->DmgAddOfMagic.d1 - pTargetData->DmgAddOfMagic.d2 + xiuliancha * 5;


	return max(dam, 0);
}


int cAI::getPhyDamage(int UserID, int TargetID, int Damageup)
{
	setData(UserID, TargetID);
	cObj* pUser = s_obj1;
	cPropertyData* UserData = s_data1;
	cPropertyData* TargetData = s_data2;
	//	pUser = m_pFightState->m_pFightWorkList[UserID]->m_pObj;
	// 	pUser->GetPropertyData(UserData);
	// 	pTarget = m_pFightState->m_pFightWorkList[TargetID]->m_pObj;
	// 	pTarget->GetPropertyData(TargetData);
	//sFightData& userFightData = UserData->m_FightProperty;
	sFightData& targetFightData = TargetData->m_FightData;
	// 	if (TargetData->m_FightData.m_WallNum > 0)
	// 	{
	// 		TargetData->m_FightData.m_WallNum -= 1;
	// 		dam = 0;
	// 		return;
	// 	}
	int userAtk = UserData->Atk.GetData();    //������
	int SufferDef = TargetData->Def.GetData(); //Ŀ�����
	// ����
	// 	int turn = m_pFightState->m_pFightWorkList[TargetID]->_myTurn;
	// 	if (TargetData->isHadPetSkill(78) && turn < 5)
	// 	{
	// 		SufferDef += (5 - turn) * TargetData->m_Lv * 2 / 5;
	// 	}
	// 	else if (TargetData->isHadPetSkill(77) && turn < 5)
	// 	{
	// 		SufferDef += (5 - turn) * TargetData->m_Lv / 5;
	// 	}

	int& atknum = targetFightData.SufferNum;

	////////////////////////////////////////////////////////////////////////// �Ǻ��� Խ�����Խû��
	int picrcerate = UserData->Pierce�̴�.d1 - TargetData->Pierce�̴�.d2 + atknum/**3*/;
	// 	bool is���� = false;
	// 	bool is�ƶ� = false;
	// 	bool is���� = false;
	// 	if (Damageup == 10086)
	// 	{
	// 		is���� = true;
	// 		Damageup = 0;
	// 		//		picrcerate += 5;
	// 	}
	// 	if (Damageup == 10087)
	// 	{
	// 		Damageup = 0;
	// 		picrcerate += 5;
	// 		if (TargetData->m_FightData.m_bDefend)
	// 		{
	// 			is���� = true;
	// 		}
	// 	}
	// 	if (Damageup == 10088)
	// 	{
	// 		is�ƶ� = true;
	// 		Damageup = 0;
	// 		//		picrcerate += 5;
	// 	}
	if (picrcerate > 0)
	{
		SufferDef -= (SufferDef * picrcerate) / 100;//���ӷ���
	}

	// 	if (is����)
	// 	{
	// 		// ������ɽ
	// 		dam += userAtk * 3 - (SufferDef + TargetData->Atk.GetData() * 2);
	// 	}
	// 	else
	// 	{
	// 		dam += (userAtk)-(SufferDef);
	// 	}
	// 	if (dam < 1)
	// 	{
	// 		dam = 1;
	// 	}
	//�������˺�����
	int xiuliancha = 0;// UserData->m_XiuLian.GetAtk() - TargetData->m_XiuLian.GetDef();
	// 	float damf = (float)dam;
	// 	if (xiuliancha > 0)
	// 	{
	// 		for (int i = 0; i < xiuliancha; ++i)
	// 		{
	// 			damf = damf * 1.02f + 5;
	// 		}
	// 	}
	// 	else
	// 	{
	// 		for (int i = 0; i < (-xiuliancha); ++i)
	// 		{
	// 			damf = damf * 0.98f - 5;
	// 			if (damf < 1)
	// 			{
	// 				damf = 1;
	// 				break;
	// 			}
	// 		}
	// 	}
	// 	dam = (int)damf;
	//	Q_ASSERT(dam < 50000, "�������˺���������");

	int dam = (userAtk)-(SufferDef);
	if (Damageup == 10086)
	{
		Damageup = 0;
		dam = userAtk * 3 - (SufferDef + TargetData->Atk.GetData() * 2);
	}
	//	Damageup += CountSpecial(UserData, TargetData/*, pTarget->GetSex()*/);//�ع�����
	Damageup += UserData->DmgPercent.d1 - TargetData->DmgPercent.d2 + xiuliancha * 2;
	// 	int atk2345 = UserData->ShiXueAdd; //����������
	// 	if (atk2345 >= 0xffffff)
	// 	{
	// 		atk2345 -= 0xffffff;
	// 	}
	// 	// 	while (atk2345 >= 0xffff)
	// 	// 	{
	// 	// 		atk2345 -= 0xffff;
	// 	// 	}
	// 	atk2345 *= atknum;
	// 	Damageup += atk2345;

	//	int& userlv = UserData->m_Lv;  //����ȼ�
	if (Damageup < 0 && dam < 0)
	{
		dam = 1;
	}
	dam += dam * Damageup / 100;




	//�������
	dam += UserData->DmgAdd.d1 - TargetData->DmgAdd.d2 + xiuliancha * 5;

	if (dam > 1 && TargetData->m_FightData.m_bDefend)
	{
		dam /= 2;
	}

	return max(dam, 0);
};


int cAI::getDamage(int user, int target, int skill)
{
	eSkill e = (eSkill)skill;
	if ((e >= eSkill::�׻� && e <= eSkill::�����һ�) ||
		e == eSkill::�¹� ||
		e == eSkill::�콵��� ||
		e == eSkill::���׷� ||
		e == eSkill::�������� ||
		e == eSkill::������� ||
		e == eSkill::������� ||
		e == eSkill::���� ||
		e == eSkill::����Ϸ�� ||
		e == eSkill::��ɰ��ʯ ||
		e == eSkill::������� ||
		(e >= eSkill::��Ҷ���� && e < eSkill::��ɱ))
	{
		return getMagicDamage(user, target, 20);
	}
	else if (skill == 1000 ||
		e == eSkill::����һ�� ||
		e == eSkill::�����ٻ� ||
		e == eSkill::�ƶ��б� ||
		e == eSkill::���ݻ��� ||
		e == eSkill::������˫ ||
		e == eSkill::���컨�� ||
		e == eSkill::����ն ||
		e == eSkill::Ʈ��ʽ ||
		e == eSkill::ӥ�� ||
		e == eSkill::��ʯ ||
		e == eSkill::��ӿ ||
		e == eSkill::����ŭ ||
		e == eSkill::��������)
	{
		return getPhyDamage(user, target, 0);
	}
	else if (e == eSkill::�Ƹ�����)
	{
		return getPhyDamage(user, target, 45);
	}
	else if (e == eSkill::ҹ�����)
	{
		cPropertyData *pd = g_pMainState->m_FightWorkList[user].m_pObj->getPropertyData();
		return pd->PointStr * 3 / 2 + pd->Speed.GetData() / 3;
	}
	else if ((e >= eSkill::�չ⻪ && e <= eSkill::���ѻ�) ||
		e == eSkill::������ ||
		e == eSkill::���޵��� ||
		e == eSkill::������)
	{
		return g_pMainState->m_FightWorkList[user].m_pObj->GetSkillLv(0) * 5 + 1;
	}
	else if (e == eSkill::�й���)
	{
		return g_pMainState->m_FightWorkList[user].m_pObj->GetSkillLv(0) * 7 + 1;
	}
	else if (e == eSkill::������ɽ)
	{
		return getPhyDamage(user, target, 10086);
	}
	else if (e == eSkill::�����ķ�)
	{
		return getPhyDamage(user, target, -40);
	}
	else if (e == eSkill::��Ѫ��)
	{
		return getPhyDamage(user, target, 180);
	}
	else if (e == eSkill::�������)
	{
		cPropertyData *pd = g_pMainState->m_FightWorkList[user].m_pObj->getPropertyData();
		pd->Pierce�̴�.d1 += 45;
		int d = getPhyDamage(user, target, 0);
		pd->Pierce�̴�.d1 -= 45;
		return d;
	}
	else if (e == eSkill::��ɨǧ��)
	{
		return getPhyDamage(user, target, 300);
	}
	else if (e == eSkill::������)
	{
		return getPhyDamage(user, target, 100);
	}
	else if (e == eSkill::���꽣�� ||
		e == eSkill::������)
	{
		return getPhyDamage(user, target, 100);
	}
	else if (e == eSkill::��Ȫ֮Ϣ)
	{
		cPropertyData *u = g_pMainState->m_FightWorkList[user].m_pObj->getPropertyData();
		cPropertyData *t = g_pMainState->m_FightWorkList[target].m_pObj->getPropertyData();
		int d = g_pMainState->m_FightWorkList[user].m_pObj->GetSkillLv(0);
		d = d * 3 + u->Mana.GetData() - t->Mana.GetData() + u->Atk.GetData() - t->Atk.GetData();
		return max(0, d);
	}
	else if (e == eSkill::ʨ��)
	{
		return getPhyDamage(user, target, 120);
	}
	else if (e == eSkill::������)
	{
		return getPhyDamage(user, target, 500);
	}
	else if (e == eSkill::�������)
	{
		return getPhyDamage(user, target, 200);
	}
	else if (e == eSkill::Ѫ��)
	{
		cPropertyData *u = g_pMainState->m_FightWorkList[user].m_pObj->getPropertyData();
		return getMagicDamage(user, target, 20) + u->HPMax.GetData() / 5;
	}
	return -1;
}


bool cAI::See(int user, int target, bool check /* = true */)
{
	if (!check || user == target)
	{
		return true;
	}
	setData(user, target);
	if (s_data1->Hide.d2 > 0)
	{
		return true;
	}
	if (s_data2->Hide.d1 == 0)
	{
		return true;
	}
	return false;
}

bool cAI::isAtkFromPoint(cPropertyData* data)
{
	return data->PointStr > (data->m_Lv + cct::MinPoint);
}

bool cAI::isMagFromPoint(cPropertyData* data)
{
	return data->PointMag > (data->m_Lv + cct::MinPoint);
}

bool cAI::isState(cObj* obj, const vector<int>& ss)
{
	forr(ss, i)
	{
		if (obj->CheckHaveState(ss[i]))
		{
			return true;
		}
	}
	return false;
}

bool cAI::isStateDMag(cObj* obj)
{
	vector<int> states =
	{ (int)eSkill::�����,
	(int)eSkill::������,
	(int)eSkill::������β,
	(int)eSkill::������,
	(int)eSkill::������,
	(int)eSkill::�鶯����,
	(int)eSkill::�ߵ�����,
	(int)eSkill::��������,
	(int)eSkill::̫������,
	(int)eSkill::�޺�����,
	(int)eSkill::��η��ʩ,
	(int)eSkill::��������,
	(int)eSkill::�������� };
	return isState(obj, states);
}


bool cAI::isNotState(cObj* obj, const vector<int>& ss)
{
	forr(ss, i)
	{
		if (obj->CheckHaveState(ss[i]))
		{
			return false;
		}
	}
	return true;
}

bool cAI::isPosion(cObj* obj)
{
	return isState(obj, { 50, 122 });
}

bool cAI::isMpSeal(cPcData* pc)
{
	int mp = pc->m_MengPaiID;
	return (
		mp == eMP_Ů���� ||
		mp == eMP_����ɽ ||
		mp == eMP_��˿�� ||
		mp == eMP_��ׯ�� ||
		mp == eMP_�칬 ||
		mp == eMP_�޵׶�);
}

bool cAI::isMpCure(cPcData* pc)
{
	int mp = pc->m_MengPaiID;
	return (mp == eMP_������ ||
		mp == eMP_���ܵظ� ||
		mp == eMP_����ɽ ||
//		mp == eMP_��ׯ�� ||
		mp == eMP_�޵׶�
		);
}

bool cAI::isMpPhy(cPcData* pc)
{
	int mp = pc->m_MengPaiID;
	return (mp == eMP_���ƹٸ� ||
		(mp == eMP_��ׯ�� && isAtkFromPoint(pc)) ||
		(mp == eMP_�칬 && isAtkFromPoint(pc)) ||
		mp == eMP_ʨ���� ||
		mp == eMP_�貨��);
}

bool cAI::isMpMag(cPcData* pc)
{
	int mp = pc->m_MengPaiID;
	return ((mp == eMP_������ && isMagFromPoint(pc)) ||
		(mp == eMP_����ɽ && isMagFromPoint(pc)) ||
		mp == eMP_��ľ�� ||
		mp == eMP_�������� ||
		(mp == eMP_�칬 && isMagFromPoint(pc)) ||
		mp == eMP_ħ��կ);
}

vector<int> cAI::getCures(int user)
{
	auto con = [&](int i)
	{
		setData(user, i);
		if (s_obj2->getPetData())
		{
			return false;
		}
		if (s_list2->CheckDie())
		{
			return false;
		}
		int uOld = m_UserID;
		SetUser(i);
		bool b = isCanMag() || isCanSpec();
		SetUser(uOld);
		if (!b)
		{
			return false;
		}
	//	int mp = s_obj2->getPcData()->m_MengPaiID;
		return isMpCure((cPcData*)s_data2);
	};
	return findOwners(user, cAI::eFindType::None, con);
}

vector<int> cAI::getSeals(int user)
{
	auto con = [&](int i)
	{
		setData(user, i);
		if (s_obj2->getPetData())
		{
			return false;
		}
		if (s_list2->CheckDie())
		{
			return false;
		}	
		int uOld = m_UserID;
		SetUser(i);
		bool b = isCanMag() || isCanSpec();
		SetUser(uOld);
		if (!b)
		{
			return false;
		}
	//	int mp = s_obj2->getPcData()->m_MengPaiID;
		return isMpSeal((cPcData*)s_data2);
	};
	return findOwners(user, cAI::eFindType::None, con);
}

vector<int> cAI::getCureSeals(int user)
{
	auto con = [&](int i)
	{
		setData(user, i);
		if (s_obj2->getPetData())
		{
			return false;
		}
		if (s_list2->CheckDie())
		{
			return false;
		}
		int uOld = m_UserID;
		SetUser(i);
		bool b = isCanMag() || isCanSpec();
		SetUser(uOld);
		if (!b)
		{
			return false;
		}
	//	int mp = s_obj2->getPcData()->m_MengPaiID;
		return isMpSeal((cPcData*)s_data2) || isMpCure((cPcData*)s_data2);
	};
	return findOwners(user, cAI::eFindType::None, con);
}

vector<int> cAI::getFires(int user)
{
	vector<int> ts;
	if (user >= 10)
	{
		return ts;
	}
	for (int i = 10; i < 20; ++i)
	{
		if (!g_pMainState->m_FightWorkList[i].isExist)
		{
			continue;
		}
		if (g_pMainState->m_FightWorkList[i].CheckDie())
		{
			continue;
		}
		if (!g_pMainState->m_FightWorkList[i].m_pObj->m_ConductFire.m_NeedShow)
		{
			continue;
		}
		ts.push_back(i);
	}
	return ts;
}

bool cAI::isHpLessThan(cPropertyData* data, int rate)
{
	return data->m_HP < data->HPMax.GetData() * rate / 100;
}

