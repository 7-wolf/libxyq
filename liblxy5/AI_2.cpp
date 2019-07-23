#include "_global.h"
#include "_txt.h"


void cAI::UseSkill(int id, const vector<int>& targets)
{
	//	if (m_TargetID == -1)return;
	sFightWork& list = g_pMainState->m_FightWorkList[m_UserID];
	list.m_WorkType = WORKTYPE_MAGIC;
	// 	list.m_SkillSelect.SkillLv = m_pUserPetData->m_Lv + m_pUserPetData->m_StrongLv/5-10;
	// 	if (list.m_SkillSelect.SkillLv < 0)list.m_SkillSelect.SkillLv = 0;
	// 	if (list.m_SkillSelect.SkillLv>180)list.m_SkillSelect.SkillLv = 180;
	list.m_SkillSelect.SkillLv = list.m_pObj->GetSkillLv(0);
	list.m_SkillSelect.SkillID = id;
	list.m_SkillSelect.TargetID = targets.front();
	// 	list.m_MaxTargetNum = g_pMainState->m_SkillManager.GetSkill(id)->m_TargetNum;
	// 	if (list.m_MaxTargetNum > targets.size())
	{
		list.m_MaxTargetNum = targets.size();
	}
	for (int i = 0; i < list.m_MaxTargetNum; ++i)
	{
		list.targetlist[i] = targets[i];
	}
}

void cAI::NormalAtk(const vector<int>& targets)
{
	sFightWork& list = g_pMainState->m_FightWorkList[m_UserID];
	list.m_WorkType = WORKTYPE_ATTACK;
	list.m_SkillSelect.SkillLv = 0;
	list.m_SkillSelect.SkillID = 1000;
	list.m_SkillSelect.TargetID = targets.front();

	list.m_MaxTargetNum = targets.size();
	for (int i = 0; i < list.m_MaxTargetNum; ++i)
	{
		list.targetlist[i] = targets[i];
	}
}


void cAI::checkHero()
{
	//	Reset();
	//	GetNeed(0, 20);
	_controlMap.clear();
	_controlMap.insert(make_pair(eFindType::Dying, set<int>()));
	_controlMap.insert(make_pair(eFindType::UnSeal, set<int>()));
	auto isItemResurgence = [](int k)
	{
		sItem2* item = g_pMainState->m_SkillManager.GetItem(k);
		if (!item)
		{
			return false;
		}
		if (item->GetType() != 22)
		{
			return false;
		}
		return item->GetID() == 44 || item->GetID() == 45;
	};

	auto isItemUnSeal = [](int k)
	{
		sItem2* item = g_pMainState->m_SkillManager.GetItem(k);
		if (!item)
		{
			return false;
		}
		if (item->GetType() != 22)
		{
			return false;
		}
		return item->GetID() == 49;
	};

	for (int i = 0; i < 10; ++i)
	{
		if (!g_pMainState->m_pFightState->m_FightMenu.CheckControl(i))
		{
			continue;
		}
		if (g_pMainState->m_FightWorkList[i].m_FriendListid >= 0)
		{
			continue;
		}
		const auto& ss = g_pMainState->m_FightWorkList[i].m_SkillSelect;
		if (ss.TargetID < 0)
		{
			continue;
		}

		if (isSkillResurgence(ss.SkillID) || (ss.SkillID == 1003 && isItemResurgence(i)))
		{
			_controlMap.at(eFindType::Dying).insert(ss.TargetID);
		}
		else if ((ss.SkillID >= 3010 && ss.SkillID <= 3013) ||
			(ss.SkillID == 1003 && isItemUnSeal(i)))
		{
			_controlMap.at(eFindType::UnSeal).insert(ss.TargetID);
		}

	}
}



bool cAI::AutoRunAi(int user)
{
	SetUser(user);

	if (!m_pUserPc)
	{
		int skill = RunPet();
		if (skill >= 0)
		{
			auto ts = findTarget(skill);
			if (ts.size())
			{
				UseSkill(skill, ts);
				return true;
			}
			if (!m_pUserData->m_FightData.cannotAll)
			{
				defense(user);
				return true;
			}
		}
		if (!m_pUserData->m_FightData.cannotAll)
		{
			defense(user);
			return true;
		}
		return false;
	}

	eMengPai mp = (eMengPai)m_pUserPc->m_PcData.m_MengPaiID;
	int skill = g_pMainState->m_FightWorkList[user].m_FriendListid;
	if (skill >= 0)
	{
		auto ts = findTarget(skill);
		if (ts.size() && Cost(skill))
		{
			UseSkill(skill, ts);
			return true;
		}
		if ((isMpPhy((cPcData*)m_pUserData) || m_pUserData->m_MP == 0 || mp < 0) && isCanAtk())
		{
			auto ts = findTarget(1000);
			if (ts.size())
			{
				NormalAtk(ts);
				return true;
			}
		}
		if (!m_pUserData->m_FightData.cannotAll)
		{
			defense(user);
			return true;
		}
		return false;
	}

	if (isMpCure((cPcData*)m_pUserData) && isCanMag() && resurgence(user))
	{
		return true;
	}

	if (isMpSeal((cPcData*)m_pUserData))
	{
		if (runResurgence3000())
		{
			return true;
		}
	}

	if (isMpCure((cPcData*)m_pUserData) || isMpSeal((cPcData*)m_pUserData))
	{
		if (runUnSeal3000(false))
		{
			return true;
		}

		if (isMpCure((cPcData*)m_pUserData) && isCanMag() && Cure(user))
		{
			return true;
		}

		if (RunLH())
		{
			return true;
		}
	}
	else
	{
		auto seals = getSeals(user);
		auto cures = getCures(user);

		if (seals.empty() && cures.empty())
		{
			if (runResurgence3000())
			{
				return true;
			}

			if (runUnSeal3000(true))
			{
				return true;
			}
			if (RunLH())
			{
				return true;
			}
		}
	}

	if (CureSelf())
	{
		return true;
	}

	switch (mp)
	{
	case eMP_���ƹٸ�:if (RunDT()) return true; break;
	case eMP_����ɽ:if (RunFC()) return true; break;
	case eMP_������:if (RunHS()) return true; break;
	case eMP_Ů����:if (RunNR()) return true; break;
	case eMP_�칬:if (RunTG()) return true; break;
	case eMP_��������:if (RunLG()) return true; break;
	case eMP_��ׯ��:if (RunWZ()) return true; break;
	case eMP_����ɽ:if (RunPT()) return true; break;
	case eMP_���ܵظ�:  if (RunDF()) return true; break;
	case eMP_ħ��կ:if (RunMW()) return true; break;
	case eMP_ʨ����:if (RunST()) return true; break;
	case eMP_��˿��:if (RunPS()) return true; break;
	case eMP_�貨��:if (RunLB()) return true; break;
	case eMP_�޵׶�:if (RunWD()) return true; break;
	case eMP_��ľ��:if (RunSM()) return true; break;
	}

	if (runPoxueRuodianPosui3000())
	{
		return true;
	}

	if ((isMpPhy((cPcData*)m_pUserData) || m_pUserData->m_MP == 0 || mp < 0) && isCanAtk())
	{
		auto ts = findTarget(1000);
		if (ts.size())
		{
			NormalAtk(ts);
			return true;
		}
	}

	if (!m_pUserData->m_FightData.cannotAll)
	{
		defense(user);
		return true;
	}
	return false;
}


static vector<int> s_petAtkSkills = { (int)eSkill::�����ٻ�, (int)eSkill::�ƶ��б�, (int)eSkill::������ɽ };
static vector<int> s_petAtkSkill2s = { (int)eSkill::���ݻ���, (int)eSkill::����һ��, (int)eSkill::�����ķ� };
static vector<int> s_petMagSkills = { (int)eSkill::�콵���, (int)eSkill::�¹�, (int)eSkill::���Ǵ�xx };

int cAI::RunPet()
{
	if (isCanMag() && 
		m_pUserData->isHadPetSkill((int)eSkill::��������) &&
		!m_pUser->CheckHaveState((int)eSkill::��������) && 
		Cost((int)eSkill::��������))
	{
		if (findOthers(m_UserID, eFindType::MpMag,
			[&](int i)
		{
			int uOld = m_UserID;
			m_UserID = i;
			bool b = isCanMag();
			m_UserID = uOld;
			return b;
		}).size())
		{
			return (int)eSkill::��������;
		}
	}

	auto runSs = [&](vector<int>& ss)
	{
		while (ss.size())
		{
			int r = rand() % ss.size();
			if (Cost(ss[r]))
			{
				auto ts = findTarget(ss[r]);
				if (ts.size())
				{
					return ss[r];
				}
			}
			ss.erase(ss.begin() + r);
		};
		return -1;
	};

	auto runs = [&](const vector<int>& ss)
	{
		vector<int> s2;
		int skill;
		forv(ss, i)
		{
			skill = ss[i];
			if (m_pUserData->isHadPetSkill(skill) && Cost(skill))
			{
				auto ts = findTarget(skill);
				if (skill == (int)eSkill::�����ķ�)
				{
					if (ts.size() >= 3)
					{
						s2.push_back(skill);
					}
				}
				else
				{
					if (ts.size())
					{
						s2.push_back(skill);
					}
				}

			}
		}
		return s2;
	};

	if (isCanMag())
	{
		vector<int> ms, m2s, ps, bs;
		isHadPetSkill(m_pUserData, bs, ps, ms, m2s);

		if (!isMagFromPoint(m_pUserData))
		{
			vector<int> ss = runs(s_petAtkSkills);
			if (ss.size() && rand() % 100 < 90)
			{
				return ss[rand() % ss.size()];
			}

			ss = runs(s_petAtkSkill2s);
			if (ss.size() && rand() % 100 < 90)
			{
				return ss[rand() % ss.size()];
			}

			if (rand() % 100 < 90 && isCanAtk())
			{
				return 1000;
			}
		}

		vector<int> ss = runs(s_petMagSkills);
		if (ss.size() && rand() % 100 < 80)
		{
			return ss[rand() % ss.size()];
		}

		int skill = runSs(m2s);
		if (skill >= 0)
		{
			return skill;
		}
		skill = runSs(ms);
		if (skill >= 0)
		{
			return skill;
		}
	}

	if (isCanAtk())
	{
		if (m_pUserData->m_MP == 0 || !isMagFromPoint(m_pUserData))
		{
			return 1000;
		}
	}

	return -1;
}



bool cAI::resurgence(int user/*, int target*/)
{

	int k;
	auto ts = findTarget((int)eSkill::�ҷ�ȱ�, k);
	if (k == 0)
	{
		return false;
	}
	eMengPai mp = (eMengPai)m_pUserPc->m_PcData.m_MengPaiID;
	int skill = -1;
	switch (mp)
	{
	case eMP_������:
		skill = (int)eSkill::�ҷ�ȱ�;
		break;
	case eMP_����ɽ:
		skill = (int)eSkill::������¶;
		break;
	case eMP_���ܵظ�:
		skill = (int)eSkill::������;
		break;
	case eMP_�޵׶�:
		skill = (int)eSkill::�ɼ�����;
		break;
	}
	if (skill >= 0)
	{
		if (Cost(skill))
		{
			UseSkill(skill, ts);
			return true;
		}
	}
	return false;
}



bool cAI::Cure(int user/*, int target,bool toall*/)
{
	auto ts = findOwners(user, eFindType::Hp70);
	if (ts.empty())
	{
		return false;
	}
	eMengPai mp = (eMengPai)m_pUserPc->m_PcData.m_MengPaiID;
	if (mp == eMP_����ɽ)
	{
		if (ts.size() == 1)
		{
			setData(m_UserID, ts.front());
			if (isState(s_obj2, { (int)eSkill::�ն�����, (int)eSkill::������¶ }))
			{
				int k;
				auto t2s = findTarget((int)eSkill::�����ķ�, k);
				if (k > 0 && std::find(t2s.begin(), t2s.end(), ts.front()) != t2s.end())
				{
					if (Cost((int)eSkill::�����ķ�))
					{
						UseSkill((int)eSkill::�����ķ�, ts);
						return true;
					}
				}
			}
		}
		int k;
		ts = findTarget((int)eSkill::�ն�����, k);
		if (k > 0 && Cost((int)eSkill::�ն�����))
		{
			UseSkill((int)eSkill::�ն�����, ts);
			return true;
		}
		return false;
	}

	if (mp == eMP_��ׯ��)
	{
		int k;
		ts = findTarget((int)eSkill::����֮Ȫ, k);
		if (k > 0 && Cost((int)eSkill::����֮Ȫ))
		{
			UseSkill((int)eSkill::����֮Ȫ, ts);
			return true;
		}
		return false;
	}

	int skill = -1;
	switch (mp)
	{
	case eMP_������:
		if (findOwners(user, eFindType::HpNotFull).size() == 1)
		{
			skill = (int)eSkill::��Ѫ;
		}
		else
		{
			skill = (int)eSkill::��������;
		}
		break;
//	case eMP_��ׯ��:
//	case eMP_����ɽ:
	case eMP_���ܵظ�:
		skill = (int)eSkill::ʬ����;
		break;
	case eMP_�޵׶�:
		skill = (int)eSkill::��ӿ����;
		break;
	}
	if (skill >= 0)
	{
		int k;
		auto ts = findTarget(skill, k);
		if ((k > 0 || (k < 0 && ts.size())) && Cost(skill))
		{
			UseSkill(skill, ts);
			return true;
		}
	}
	return false;


}

