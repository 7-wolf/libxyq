#include "_global.h"
#include "_txt.h"

// 0-1000, 2000+
static bool runSkill(eSkill skill, int size)
{
	if (!g_pMainState->m_AI.isCanMag())
	{
		return false;
	}
	int k;
	auto ts = g_pMainState->m_AI.findTarget((int)skill, k);
	if (k >= 0 && k < size)
	{
		return false;
	}
	if (k < 0 && ts.size() < size)
	{
		return false;
	}
	if (!g_pMainState->m_AI.Cost((int)skill))
	{
		return false;
	}

	if (g_pMainState->m_AI.isSkillSeal((int)skill))
	{
		g_pMainState->m_AI.setData(g_pMainState->m_AI.m_UserID, ts.front());
		if (g_pMainState->m_SkillManager.CheckMagicHit(g_pMainState->m_AI.m_pUser->GetSkillLv(0), (int)skill, g_pMainState->m_AI.m_UserID, ts.front()) <= 20)
		{
			return false;
		}
	}

	g_pMainState->m_AI.UseSkill((int)skill, ts);
	return true;
}

// 0-1000, 2000+
static bool runSkill(const vector<eSkill>& skills)
{
	forv(skills, i)
	{
		if (runSkill(skills[i], 1))
		{
			return true;
		}
	}
	return false;
}

// 0-1000, 2000+
static bool runSkill(eSkill s){ vector<eSkill> es = { s }; return runSkill(es); }



bool cAI::CureSelf()
{
	if (!isHpLessThan(m_pUserData, 35))
	{
		return false;
	}

	if (getCures(m_UserID).size())
	{
		return false;
	}

	if (!isCanMag())
	{
		return runCure3000();
	}

	eMengPai mp = (eMengPai)m_pUserPc->m_PcData.m_MengPaiID;
	switch (mp)
	{
	case eMP_���ƹٸ�:
		if (!isStateDMag(m_pUser))
		{
			auto ts = findOthers(m_UserID, eFindType::MpMag,
				[&](int i)
			{
				int uOld = m_UserID;
				SetUser(i);
				bool b = isCanMag();
				SetUser(uOld);
				return b;
			});
			if (ts.size() > 0)
			{
				if (runSkill(eSkill::�����))
				{
					return true;
				}
			}
		}
		break;
	case eMP_������:
		break;
	case eMP_Ů����:
		break;
	case eMP_����ɽ:
		if (!isStateDMag(m_pUser))
		{
			auto ts = findOthers(m_UserID, eFindType::MpMag,
				[&](int i)
			{
				int uOld = m_UserID;
				SetUser(i);
				bool b = isCanMag();
				SetUser(uOld);
				return b;
			});
			if (ts.size() > 0)
			{
				if (runSkill(eSkill::������))
				{
					return true;
				}
			}
		}

		if (runSkill(eSkill::��Ԫ��))
		{
			return true;
		}

		break;
	case eMP_ʨ����:
		if (!isStateDMag(m_pUser))
		{
			auto ts = findOthers(m_UserID, eFindType::MpMag,
				[&](int i)
			{
				int uOld = m_UserID;
				SetUser(i);
				bool b = isCanMag();
				SetUser(uOld);
				return b;
			});
			if (ts.size() > 0)
			{
				if (runSkill(eSkill::������))
				{
					return true;
				}
			}
		}
		break;
	case eMP_ħ��կ:
		break;
	case eMP_��˿��:
		if (runSkill(eSkill::����))
		{
			return true;
		}
		{
			auto ts = findOthers(m_UserID, eFindType::MpMag,
				[&](int i)
			{
				int uOld = m_UserID;
				SetUser(i);
				bool b = isCanMag();
				SetUser(uOld);
				return b;
			});
			if (ts.size() > 0)
			{
				if (runSkill(eSkill::�þ���))
				{
					return true;
				}
			}
		}
		break;
	case eMP_���ܵظ�:
		break;
	case eMP_��������:
		if (!isStateDMag(m_pUser))
		{
			if (runSkill(eSkill::������β))
			{
				return true;
			}
		}
		break;
	case eMP_��ׯ��:
		break;
	case eMP_����ɽ:
		break;
	case eMP_�칬:
		if (!isStateDMag(m_pUser))
		{
			auto ts = findOthers(m_UserID, eFindType::MpMag,
				[&](int i)
			{
				int uOld = m_UserID;
				SetUser(i);
				bool b = isCanMag();
				SetUser(uOld);
				return b;
			});
			if (ts.size() > 0)
			{
				if (runSkill(eSkill::������))
				{
					return true;
				}
			}
		}
		break;
	case eMP_�貨��:
		if (runSkill(eSkill::������ɽ))
		{
			return true;
		}
		break;
	case eMP_�޵׶�:
		break;
	case eMP_��ľ��:
		if (runSkill(eSkill::�׻�))
		{
			return true;
		}
		if (runSkill(eSkill::����֮��))
		{
			return true;
		}
		break;
	case eMP_���:
		break;
	default:
		break;
	}

	return runCure3000();
}



bool cAI::RunDT()
{
	if (isCanMag())
	{
		int skill = (int)eSkill::�Ƹ�����;
		auto ts = findTarget(skill);
		if (ts.size() >= 3)
		{
			setData(m_UserID, ts.front());
			if (getDamage(m_UserID, ts.front(), skill) > s_data2->m_HP)
			{
				if (Cost(skill))
				{
					UseSkill(skill, ts);
					return true;
				}
			}
		}
		else if (ts.size() > 0)
		{

			skill = 1000;
			if (getDamage(m_UserID, ts.front(), skill) > s_data2->m_HP)
			{
				if (Cost(skill))
				{
					UseSkill(skill, ts);
					return true;
				}
			}

			skill = (int)eSkill::��ɨǧ��;
			if (getDamage(m_UserID, ts.front(), skill) > s_data2->m_HP)
			{
				if (Cost(skill))
				{
					UseSkill(skill, ts);
					return true;
				}
			}
		}
	}

	if (Summon())
	{
		return true;
	}


	if (getCureSeals(m_UserID).empty() && ((g_pMainState->m_FightWorkList[m_UserID]._myTurn % 3) == 0))
	{
		if (runSkill(eSkill::����֮��))
		{
			return true;
		}
	}

	if (isCanMag())
	{
		int skill = 1000;
		auto ts = findTarget(skill);
		if (ts.size() && getDamage(m_UserID, ts.front(), skill) > s_data2->m_HP)
		{
			if (Cost(skill))
			{
				UseSkill(skill, ts);
				return true;
			}
		}
	}

	if (runSkill(eSkill::��ɨǧ��))
	{
		return true;
	}

	return false;

}

bool cAI::RunNR()
{
	if (runSkill(eSkill::��������))
	{
		return true;
	}

	if (Summon())
	{
		return true;
	}

	if (runSkill(eSkill::���亮ɳ, 3))
	{
		return true;
	}

	if (runSkill({ eSkill::���컨��, eSkill::���亮ɳ }))
	{
		return true;
	}

	return false;


}

bool cAI::RunFC()
{
	if (m_pUserData->m_MP == 0)
	{
		if (runSkill(eSkill::������))
		{
			return true;
		}
	}

	if (runSkill(eSkill::ʧ�ķ�))
	{
		return true;
	}

	if (Summon())
	{
		return true;
	}

	auto ts = findOthers(m_UserID, eFindType::MpMag,
	[&](int i)
	{
		int uOld = m_UserID;
		SetUser(i);
		bool b = isCanMag();
		SetUser(uOld);
		return b;
	});

	if (ts.size() && runSkill(eSkill::������))
	{
		return true;
	}

	if (runSkill({ eSkill::�����, eSkill::��׷�, eSkill::���׷� }))
	{
		return true;
	}


	return false;


}

bool cAI::RunHS()
{
	int phy = findOthers(m_UserID, eFindType::MpPhy, [&](int i)
	{
		int uOld = m_UserID;
		SetUser(i);
		bool b = isCanMag();
		SetUser(uOld);
		return b;
	}).size();
	int size = findOwners(m_UserID).size();

	if (size >= 5 && runSkill(eSkill::��ջ���, 3))
	{
		return true;
	}

	if (phy > 0 && size >= 5 && runSkill(eSkill::��ջ���, 3))
	{
		return true;
	}


	if (Summon())
	{
		return true;
	}

	if (runSkill(eSkill::���ޱ�))
	{
		return true;
	}

	if (size >= 5 && runSkill(eSkill::Τ�ӻ���, 3))
	{
		return true;
	}

	if (size <= 3 && runSkill(eSkill::��ջ���))
	{
		return true;
	}

	if (phy > 0 && size <= 3 && runSkill(eSkill::��ջ���))
	{
		return true;
	}


	if (runSkill(eSkill::��������))
	{
		return true;
	}

	return false;


}

bool cAI::RunLG()
{
	if (Summon())
	{
		return true;
	}

	if (runSkill(eSkill::�������, 3))
	{
		return true;
	}


	if (runSkill(eSkill::����Ϸ��))
	{
		return true;
	}

	return false;


}

bool cAI::RunTG()
{
	if (runSkill(eSkill::����))
	{
		return true;
	}

	if (Summon())
	{
		return true;
	}

	if (runSkill(eSkill::�������))
	{
		return true;
	}

	if (isCanMag())
	{
		auto ts = findOthers(m_UserID, eFindType::MpMag,
			[&](int i)
		{
			int uOld = m_UserID;
			SetUser(i);
			bool b = isCanMag();
			SetUser(uOld);
			return b;
		});

		if (ts.size() && runSkill(eSkill::������))
		{
			return true;
		}

		int skill = (int)eSkill::���׺䶥;
		ts = findTarget(skill);
		if (ts.size() && Cost(skill))
		{
			setData(m_UserID, ts.front());
			if (s_data2->m_HP > s_data1->m_Lv * 120)
			{
				UseSkill(skill, ts);
				return true;
			}
		}
	}

	if (runSkill(eSkill::�������))
	{
		return true;
	}
	return false;



}

bool cAI::RunWZ()
{
	if (runSkill(eSkill::����Ǭ��))
	{
		return true;
	}


	if (Summon())
	{
		return true;
	}

	auto ts = findOwners(m_UserID, eFindType::Mp0);
	if (ts.size())
	{
		if (runSkill(eSkill::��������))
		{
			return true;
		}
	}

	if (isCanMag())
	{
		int skill = (int)eSkill::Ʈ��ʽ;
		ts = findTarget(skill);
		if (ts.size() >= 3)
		{
			setData(m_UserID, ts.front());
			if (getDamage(m_UserID, ts.front(), skill) > s_data2->m_HP)
			{
				if (Cost(skill))
				{
					UseSkill(skill, ts);
					return true;
				}
			}
		}
		else if (ts.size() > 0)
		{
			skill = (int)eSkill::���꽣��;
			if (getDamage(m_UserID, ts.front(), skill) > s_data2->m_HP)
			{
				if (Cost(skill))
				{
					UseSkill(skill, ts);
					return true;
				}
			}
		}
	}

	if (getFires(m_UserID).size() && runSkill(eSkill::���꽣��))
	{
		return true;
	}

	if (runSkill(eSkill::Ʈ��ʽ, 3))
	{
		return true;
	}

	if (runSkill(eSkill::���꽣��))
	{
		return true;
	}

	return false;


}

bool cAI::RunPT()
{
	int mag = findOthers(m_UserID, eFindType::MpMag,
		[&](int i)
	{
		int uOld = m_UserID;
		SetUser(i);
		bool b = isCanMag();
		SetUser(uOld);
		return b;
	}).size();
	int mag2 = findOwners(m_UserID, eFindType::MpMag, nullptr, (int)eSkill::�鶯����).size();
	int size = findOwners(m_UserID).size();
	if (mag || mag2)
	{
		if (size >= 5 && runSkill(eSkill::�鶯����, 3))
		{
			return true;
		}
	}

	if (Summon())
	{
		return true;
	}

	if (runSkill(eSkill::�ߵ�����))
	{
		return true;
	}


	if (mag2)
	{
		if (runSkill(eSkill::�鶯����))
		{
			return true;
		}
	}

	int skill = rand() % 5 + 105;
	if (runSkill((eSkill)skill))
	{
		return true;
	}
	return false;


}

bool cAI::RunDF()
{
	if (findOthers(m_UserID, eFindType::Hide).size() || findOthers(m_UserID, eFindType::MpSeal, [&](int i)
	{
		int uOld = m_UserID;
		SetUser(i);
		bool b = isCanMag();
		SetUser(uOld);
		return b;
	}).size())
	{
		if (runSkill(eSkill::��ڤ����))
		{
			return true;
		}
	}

	if (Summon())
	{
		return true;
	}

	if (runSkill({ eSkill::������, eSkill::�����ɢ }))
	{
		return true;
	}

	if (runSkill(eSkill::������, 3))
	{
		return true;
	}

	if (rand() % 100 < 50 && runSkill(eSkill::�й���))
	{
		return true;
	}

	if (runSkill(eSkill::��Ȫ֮Ϣ))
	{
		return true;
	}

	return false;

}

bool cAI::RunPS()
{
	if (m_pUserData->m_MP == 0)
	{
		if (runSkill(eSkill::����))
		{
			return true;
		}
	}

	if (runSkill(eSkill::��������))
	{
		return true;
	}

	if (Summon())
	{
		return true;
	}

	if (runSkill(eSkill::���޵���))
	{
		return true;
	}

	return false;


}

bool cAI::RunMW()
{
	eSkill e = eSkill::�޵�ţʭ;
	if (rand() % 100 < 50)
	{
		e = eSkill::�޵�ţ��;
	}

	if (((g_pMainState->m_FightWorkList[m_UserID]._myTurn % 3) == 1) && runSkill(e))
	{
		return true;
	}

	auto ts = findOthers(m_UserID, eFindType::Hide);
	if (ts.size())
	{
		if (runSkill(eSkill::ţ��))
		{
			return true;
		}
	}

	if (Summon())
	{
		return true;
	}

	if (runSkill(eSkill::��ɰ��ʯ, 2))
	{
		return true;
	}

	if (runSkill(eSkill::�������))
	{
		return true;
	}

	return false;

}

bool cAI::RunST()
{
	auto get145Times = [&]()
	{
		for (list<sBuff>::iterator it = m_pUser->m_StateList.begin(); it != m_pUser->m_StateList.end(); it++)
		{
			if (it->ID == 145)
				return it->remainingTimes;
		}
		return -1;
	};

	if (get145Times() < 0)
	{
		if (runSkill(eSkill::����))
		{
			return true;
		}
	}

	if (isCanMag())
	{
		int skill = (int)eSkill::ӥ��;
		auto ts = findTarget(skill);
		if (ts.size() >= 3)
		{
			setData(m_UserID, ts.front());
			if (getDamage(m_UserID, ts.front(), skill) > s_data2->m_HP)
			{
				if (Cost(skill))
				{
					UseSkill(skill, ts);
					return true;
				}
			}
		}
		else if (ts.size() > 0)
		{
			skill = (get145Times() == 0) ? (int)eSkill::������ : (int)eSkill::ʨ��;
			if (getDamage(m_UserID, ts.front(), skill) > s_data2->m_HP)
			{
				if (Cost(skill))
				{
					UseSkill(skill, ts);
					return true;
				}
			}
		}
	}

	if (getFires(m_UserID).size() && runSkill((get145Times() == 0) ? eSkill::������ : eSkill::ʨ��))
	{
		return true;
	}

	if (getCureSeals(m_UserID).empty())
	{
		if (runSkill(eSkill::����))
		{
			return true;
		}
	}

// 	auto ts = findOthers(m_UserID, eFindType::MpMag,
// 		[&](int i)
// 	{
// 		int uOld = m_UserID;
// 		SetUser(i);
// 		bool b = isCanMag();
// 		SetUser(uOld);
// 		return b;
// 	});
// 
// 	if (ts.size() && runSkill(eSkill::������))
// 	{
// 		return true;
// 	}

	if ((get145Times() > 1 && !m_pUserData->m_FightData.cannotAll || get145Times() < 0) && Summon())
	{
		return true;
	}

	if (runSkill(eSkill::ӥ��, 3))
	{
		return true;
	}

	if (get145Times() == 0)
	{
		if (runSkill(eSkill::������))
		{
			return true;
		}
	}

	if (runSkill(eSkill::ʨ��))
	{
		return true;
	}

	return false;

}

bool cAI::RunLB()
{
	if (runSkill(eSkill::��������, 5))
	{
		return true;
	}

	// 	if (runSkill(eSkill::����ŭ, 3))
	// 	{
	// 		return true;
	// 	}

	if (Summon())
	{
		return true;
	}

	if (runSkill(eSkill::��ӿ, 2))
	{
		return true;
	}

	if (isCanMag())
	{
		int skill = (int)eSkill::��ʯ;
		auto ts = findTarget(skill);
		if (ts.size())
		{
			setData(m_UserID, ts.front());
			if (getDamage(m_UserID, ts.front(), skill) > s_data2->m_HP)
			{
				if (Cost(skill))
				{
					UseSkill(skill, ts);
					return true;
				}
			}
		}
		skill = (int)eSkill::������;
		if (Cost(skill))
		{
			ts = findTarget(skill);
			if (ts.size())
			{
				setData(m_UserID, ts.front());
				if (getDamage(m_UserID, ts.front(), skill) > s_data2->m_HP)
				{
					UseSkill(skill, ts);
					return true;
				}
			}
		}
		skill = (int)eSkill::�������;
		if (Cost(skill))
		{
			ts = findTarget(skill);
			if (ts.size())
			{
				setData(m_UserID, ts.front());
				if (getDamage(m_UserID, ts.front(), skill) > s_data2->m_HP)
				{
					UseSkill(skill, ts);
					return true;
				}
			}
		}
	}

	if (runSkill(eSkill::��ʯ))
	{
		return true;
	}
	return false;
}

bool cAI::RunWD()
{
	int phy = findOthers(m_UserID, eFindType::MpPhy,
		[&](int i)
	{
		int uOld = m_UserID;
		SetUser(i);
		bool b = isCanMag();
		SetUser(uOld);
		return b;
	}).size();
	int mag = findOthers(m_UserID, eFindType::MpMag,
		[&](int i)
	{
		int uOld = m_UserID;
		SetUser(i);
		bool b = isCanMag();
		SetUser(uOld);
		return b;
	}).size();
	int size = findOwners(m_UserID).size();

	if (mag > 0 && size >= 5 && runSkill(eSkill::��������, 3))
	{
		return true;
	}

	if (phy > 0 && size >= 5 && runSkill(eSkill::���ⱦ��, 3))
	{
		return true;
	}

	if (Summon())
	{
		return true;
	}

	if (runSkill(eSkill::������))
	{
		return true;
	}


	if (mag > 0 && size <= 3 && runSkill(eSkill::��������))
	{
		return true;
	}

	if (phy > 0 && size <= 3 && runSkill(eSkill::���ⱦ��))
	{
		return true;
	}

	if (runSkill({ eSkill::�ƻ껯��, eSkill::������ }))
	{
		return true;
	}

	return false;

}

bool cAI::RunSM()
{

	int size = findOwners(m_UserID).size();

	if (size >= 5 && runSkill(eSkill::����, 3))
	{
		return true;
	}

	if (Summon())
	{
		return true;
	}

	if (runSkill(eSkill::��Ҷ����, 2))
	{
		return true;
	}

	if (size <= 3 && runSkill(eSkill::����))
	{
		return true;
	}

	if (isCanMag())
	{
		int skill = rand() % 3 + 195;
		auto ts = findTarget(skill);
		if (ts.size())
		{
			setData(m_UserID, ts.front());
			int d = getDamage(m_UserID, ts.front(), skill);
			if (d * 2 < getDamage(m_UserID, ts.front(), (int)eSkill::Ѫ��))
			{
				skill = (int)eSkill::Ѫ��;
				if (Cost(skill))
				{
					UseSkill(skill, ts);
					return true;
				}
			}
			if (Cost(skill))
			{
				UseSkill(skill, ts);
				return true;
			}
		}
	}
	return false;
}















