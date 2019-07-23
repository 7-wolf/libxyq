#include "_global.h"

static bool is��������(int skill)
{
	switch (skill)
	{
	case 0: //��ɨǧ��
	case 1010: // ��
	case 1050: //����
	case 97:  //���꽣��
	case 141://����
	case 143:// ʨ��
	case 148://������
	case 167://��ʯ
	case 168:
	case 169:

	case 2092://����һ��
	case 2094://�����ٻ�
	case 1095: //����
	case 2098://�ƶ��б�
	case 2099://���ݻ���

	case 3034://��Ѫ
	case 3035://����
	case 3040://����
		return true;
	}
	return false;
}

static bool is�ֻ�(int skill)
{
	switch (skill)
	{
	case 1017:// �Ƹ��ڶ���
	case 71:  // ����ն
	case 98:  // ���ʽ
	case 142: // ӥ��
	case 170: // ��ӿ
	case 1171:
	case 1172:

	case 2110:// �����ķ�
		return true;
	}
	return false;
}

static void cbCounter(int UserID)
{
	auto& ss = g_pMainState->m_FightWorkList[UserID].m_SkillSelectForCounter;
	if (ss.SkillID >= 0)
	{
		g_pMainState->m_FightWorkList[UserID].m_SkillSelect = ss;
		ss.SkillID = -1;
	}
};


bool cSkillManager::Use(sFightSkillSelect SkillSelect, int UserID, bool isPut /* = false */)
{
	int& stage = m_pFightState->m_pFightWorkList[UserID]->GetWork()->stage;
	if (stage == 0)
	{
		auto& list = g_pMainState->m_FightWorkList[UserID];
		auto& ski = list.m_SkillSelect;
		int& sid = ski.SkillID;
		int& tid = ski.TargetID;

		bool isfj = false;
		if (g_pMainState->m_FightWorkList[UserID].m_pObj->getPropertyData()->m_FightData.chaos���ҷ���)
		{
			isfj = true;
			int autoSelect = g_pMainState->m_AI.find׷�������¹�(UserID, 3, true);
			if (autoSelect >= 0)
			{
				list.GetWork()->type = list.m_WorkType = WORKTYPE_ATTACK;
				list.targetID = autoSelect;
				sid = 1000;
				tid = autoSelect;
				SkillSelect = ski;

				list.m_MaxTargetNum = 1;
				list.targetlist[0] = tid;
			}
			else
			{
				g_pMainState->m_AI.defense(UserID);
			}
		}

		int numMax = 1;
		if (!isfj && (sid <= 1000 || sid >= 2000))
		{
			//	int uold = g_pMainState->m_AI.m_UserID;
			g_pMainState->m_AI.SetUser(UserID);
			auto ts = sid == 3048 ?  g_pMainState->m_AI.findOwners(UserID, cAI::eFindType::Relifeable) : g_pMainState->m_AI.findTarget(sid);
			if (ts.empty())
			{
				g_pMainState->m_FightWorkList[UserID].m_work.clear();
				return true;
			}
			if (tid >= 0 && g_pMainState->m_FightWorkList[tid].isExist && g_pMainState->m_AI.See(UserID, tid) && 
				(!g_pMainState->m_FightWorkList[tid].CheckDie() || g_pMainState->m_AI.isSkillResurgence(sid)))
			{
				if (std::find(ts.begin(), ts.end(), tid) == ts.end())
				{
					ts.insert(ts.begin(), tid);
				}
				else
				{
					for (int i = ts.size() - 1; i >= 1; --i)
					{
						if (ts[i] == tid)
						{
							swap(ts[i], ts[0]);
							break;
						}
					}
				}
			}
			auto& list = g_pMainState->m_FightWorkList[UserID];

			if (sid != 1000)
			{
				numMax = g_pMainState->m_SkillManager.GetSkill(sid)->m_TargetNum;
				if (sid == 1017)
				{
					numMax = g_pMainState->m_SkillManager.GetSkill(7)->m_TargetNum;
				}
				else if (sid == 1171)
				{
					numMax = g_pMainState->m_SkillManager.GetSkill(171)->m_TargetNum;
				}
				else if (sid == 1172)
				{
					numMax = g_pMainState->m_SkillManager.GetSkill(172)->m_TargetNum;
				}
			}
			list.m_MaxTargetNum = ts.size();
			if (is��������(sid))
			{
				list.m_MaxTargetNum = numMax;
				for (int i = 0; i < list.m_MaxTargetNum; ++i)
				{
					list.targetlist[i] = ts[0];
				}
			}
			else
			{
				list.m_MaxTargetNum = min(list.m_MaxTargetNum, numMax);
				for (int i = 0; i < list.m_MaxTargetNum; ++i)
				{
					list.targetlist[i] = ts[i];
				}
			}

			tid = list.targetlist[0];
			SkillSelect = ski;
		}
	}


	int  Skilllv = SkillSelect.SkillLv;
	int  TargetID = SkillSelect.TargetID;
	int sSkillID = SkillSelect.SkillID;
	

	if (stage == 0x10086 || stage == 0x10087)
	{
		auto& ss = m_pFightState->m_pFightWorkList[UserID]->m_SkillSelect;
		ss.SkillID = 1000;
		return Use1000ƽ��(Skilllv, 1000, UserID, TargetID);
	}


	if (0 == stage)
	{
		if (m_pFightState->m_pFightWorkList[UserID]->m_pObj->m_NowPos == POS_FIGHT_STAND)
		{
			cPropertyData* petdata;
			cObj* pUser = m_pFightState->m_pFightWorkList[UserID]->m_pObj;
			pUser->AutoFightDirection(UserID);
			pUser->GetPropertyData(petdata);
			pUser->SetStatic(false);//�п��ܸղ��ڱ���,���ھ�ֹ״̬ʱ�ֵ�����

// 			if (petdata->m_FightData.chaos���ҷ���)
// 			{
// 				int autoSelect = g_pMainState->m_AI.find׷�������¹�(FightListID, 3, true);
// 				if (-1 != autoSelect)
// 				{
// 					// ��
// 					m_pFightState->m_pFightWorkList[FightListID]->m_work.clear();
// 					//
// 					m_pFightState->m_pFightWorkList[FightListID]->m_WorkType = WORKTYPE_ATTACK;
// 					m_pFightState->m_pFightWorkList[FightListID]->m_SkillSelect.SkillLv = 0;
// 					m_pFightState->m_pFightWorkList[FightListID]->m_SkillSelect.SkillID = 1000;
// 					m_pFightState->m_pFightWorkList[FightListID]->targetID = autoSelect;
// 					m_pFightState->m_pFightWorkList[FightListID]->m_SkillSelect.TargetID = autoSelect;
// 				}
// 			}

			g_pMainState->m_FightWorkList[UserID].targetID = SkillSelect.TargetID;
			g_pMainState->m_FightWorkList[UserID].m_NowTargetID = SkillSelect.TargetID;
			bool bSeal = false;
			if (petdata->m_FightData.cannotAll)
			{
				bSeal = true;
			}
			else
			{
				if (sSkillID < 3000)//3000�������ؼ������ڷ���
				{
					if (sSkillID < 2000 && sSkillID>1000)
					{

					}
					else
					{
						if (1000 == sSkillID)
						{
							if (petdata->m_FightData.cannotAttack)
							{
								bSeal = true;
							}
						}
						else if (petdata->m_FightData.cannotMagic || pUser->CheckHaveState(199))
						{
							bSeal = true;
						}
					}
				}
				else if (petdata->m_FightData.cannotSpesialSkill)
				{
						bSeal = true;
				}
			}
			if (!isPut && bSeal)
			{
//				if (UserID == g_pMainState->m_HeroID || UserID == g_pMainState->m_HeroID + 5)
// 				if (g_pMainState->m_pFightState->m_FightMenu.CheckControl(UserID))
// 				{
// 					g_pMainState->m_Channel.AddNewString("�ж�����");
// 				}
				if (sSkillID >= 3000)
				{
//					m_pFightState->m_MiaoShu.SetString("�ؼ�����");
					pUser->saySkill("�ؼ�����");
					
				}
				else if (sSkillID == 1000)
				{
//					m_pFightState->m_MiaoShu.SetString("��������");
					pUser->saySkill("��������");
				}
				else
				{
//					m_pFightState->m_MiaoShu.SetString("��������");
					pUser->saySkill("��������");
				}
// 				m_pFightState->m_MiaoShu.SetTime(120);
// 				m_pFightState->m_MiaoShu.UpdateXCenter();
				g_pMainState->m_FightWorkList[UserID].m_work.clear();
				return true;
			}
//			int hpout;
//			if (!isPut && !Cost(hpout, Skilllv, sSkillID, UserID, 1, false))
			if (!Cost(UserID, sSkillID, 1, false))
			{
//				if (UserID==g_pMainState->m_HeroID)
// 				if (g_pMainState->m_pFightState->m_FightMenu.CheckControl(UserID))
// 				{
// 					g_pMainState->m_Channel.AddNewString("���Ĳ���");
// 				}

				if (sSkillID >= 3000)
				{
//					m_pFightState->m_MiaoShu.SetString("�ؼ�����");
					pUser->saySkill("��ŭ����");

				}
				else
				{
//					m_pFightState->m_MiaoShu.SetString("��������");
					pUser->saySkill("ʩ������");
				}
// 				m_pFightState->m_MiaoShu.SetTime(120);
// 				m_pFightState->m_MiaoShu.UpdateXCenter();
				m_pFightState->m_pFightWorkList[UserID]->m_work.pop_back();
				return true;
			}
			bool m_bmiaoshushow = true;
			string actionname;
			sSkill* pskill = g_pMainState->m_SkillManager.GetSkill(m_pFightState->m_pFightWorkList[UserID]->m_SkillSelect.SkillID);
			if (pskill)
			{
				actionname = pskill->m_Name;
			}
			else
			{
				switch (m_pFightState->m_pFightWorkList[UserID]->m_SkillSelect.SkillID)
				{
				case 1003:
				case 1007:
				{
//					switch (m_pFightState->m_pFightWorkList[UserID]->m_ItemSelectID)
//					{
// 					case eAIUseItemTypeHP:
// 					case eAIUseItemTypeHPALL:
// 						actionname = "ҩƷ��Ѫ";
// 						break;
// 					case eAIUseItemTypeMP:
// 					case eAIUseItemTypeMPALL:
// 						actionname = "ҩƷ����";
// 						break;
// 					case eAIUseItemTypeHPHurt:
// 						actionname = "ҩƷ����";
// 						break;
// 					case eAIUseItemTypelive:
// 						actionname = "ҩƷ����";
// 						break;
// 					case eAIUseItemTypeUnseal:
// 						actionname = "ҩƷ���";
// 						break;
// 					case eAIUseItemTypeCP:
// 						actionname = "ҩƷ��ŭ";
// 						break;
// 					default:
// 						actionname = "ҩƷ";
// 						if (GetItem(UserID))
// 						{
// 							actionname = GetItem(UserID)->GetName();
// 						}
// 						break;
// 					}
// 					if (UserID == g_pMainState->m_HeroID || UserID == g_pMainState->m_HeroID + 5)
// 					{
// 						actionname = "ҩƷ";
// 					}

					actionname = "ҩƷ";
					if (GetItem(UserID))
					{
						actionname = GetItem(UserID)->GetName();
					}
				}
					break;
				case 1004:actionname = "�ٻ�"; break;
				case 1005:actionname = "����"; break;
				default:m_bmiaoshushow = false; break;
				}
			}
			if (m_bmiaoshushow)
			{
// 				ostringstream oss;
// 				oss << m_pFightState->m_pFightWorkList[UserID]->m_pObj->m_TrueName.GetString();
// 				oss << ": ";
// 				oss << actionname;
// 				m_pFightState->m_MiaoShu.SetString(oss.str());
// 				m_pFightState->m_MiaoShu.SetTime(120);
// 				m_pFightState->m_MiaoShu.UpdateXCenter();

				pUser->saySkill(actionname);
			}


			//���ڼ��
			int truetarget = TargetID; // m_pFightState->CheckTarget(UserID, TargetID, sSkillID);
			m_pFightState->m_pFightWorkList[UserID]->m_NowTargetID = truetarget;
			m_pFightState->m_pFightWorkList[UserID]->targetID = truetarget;
			if (truetarget == -1)
			{
				m_pFightState->m_pFightWorkList[UserID]->m_work.pop_back();
				return true;
			}
			if (truetarget == UserID)
			{
				cObj* pUser = m_pFightState->m_pFightWorkList[UserID]->m_pObj;
				cPropertyData* pUserData;
				pUser->GetPropertyData(pUserData);
				if (pUserData->m_FightData.chaos���ҷ���)
				{
					if (sSkillID == 1000)
					{
						m_pFightState->m_pFightWorkList[UserID]->m_work.pop_back();
						return true;
					}
				}
			}
// 			if (truetarget != TargetID)
// 			{
// 				m_pFightState->m_pFightWorkList[UserID]->m_SkillSelect.TargetID = truetarget;
// 				TargetID = truetarget;
// 			}
		}

	}

	if (is��������(sSkillID) || is�ֻ�(sSkillID))
	{
		return Use71������������(Skilllv, sSkillID, UserID, TargetID);
	}
	else if ((sSkillID == 107 || sSkillID == 2087) && (m_pFightState->_turn % 2) == 0)
	{
		return Use107������̩ɽ���޵���(Skilllv, sSkillID, UserID, TargetID);
	}
	switch (sSkillID)
	{
	case 1:
		return Use1��(Skilllv, sSkillID, UserID, TargetID);

// 		/*if (Use50(Skilllv, sSkillID, UserID, TargetID))
// 		return true;
// 		return false;*/
// 	case 1050:  //���컨��
// 	case 1095://����
// 	case 0: //��ɨǧ��
// 	case 1010:
// 	case 1017://�Ƹ��ڶ���
// 	case 71:  //����ն
// 	case 97://���꽣��
// 	case 98:
// 	case 141://����
// 	case 142:// ӥ��
// 	case 143:// ʨ��
// 	case 148://������
// 	case 2092://����һ��
// 	case 2094://�����ٻ�
// 	case 2096://�����ķ�
// 	case 2098://�ƶ��б�
// 	case 2099://���ݻ���
// 	case 2100://���ŭ��
// 		//	case 2102:
// 	case 3034://��Ѫ
// 	case 3035://����
// 	case 3040://����
// 	case 3042://��Ѫ2
// 	case 3043://����EX
// 	case 3044://��ѪEX
// 		if (Use71������������(Skilllv, sSkillID, UserID, TargetID))
// 			return true;
// 		return false;
// 	case 80://�������
// 	case 131:// ��ɰ��ʯ
// 		if (Use80�����ɳ(Skilllv, sSkillID, UserID, TargetID))
// 			return true;
// 		return false;
//	case 84:	return Use84����(Skilllv, sSkillID, UserID, TargetID);//����


	case 135:
	case 136:
	{
		int tid = -1;
		int start = UserID / 10 * 10;
		int end = start + 5;
		int t;
		for (int i = start; i < end; ++i)
		{
			t = g_pMainState->m_InterfaceTeam.GetTeamTurn(i);
			if (!g_pMainState->m_FightWorkList[t].isExist)
			{
				tid = t;
				break;
			}
		}
		if (tid < 0)
		{
			ccc_msgbox("�ٻ��޵�ţ��/ţʭ ����");
		}
		auto& ski = g_pMainState->m_FightWorkList[UserID].m_SkillSelect;
		TargetID = ski.TargetID = tid;
		return Use1004�ٻ�(Skilllv, sSkillID, UserID, TargetID);
	}
	case 1000:	return  Use1000ƽ��(Skilllv, sSkillID, UserID, TargetID);
	case 1003: return Use1003��Ʒ(Skilllv, sSkillID, UserID, TargetID);
	case 1004:
	{
		TargetID = SkillSelect.TargetID = UserID + 5;
		return Use1004�ٻ�(Skilllv, sSkillID, UserID, SkillSelect.TargetID);
	}
	case 61: return Use61����(Skilllv, sSkillID, UserID, TargetID);
	case 1005:	return Use1005����(Skilllv, sSkillID, UserID, TargetID);
	case 1006:  return Use1006(Skilllv, sSkillID, UserID, TargetID);
	case 2105:  return  Use2105(Skilllv, sSkillID, UserID, TargetID);
	default:
	{
		if (sSkillID == 1007)
		{
			g_pMainState->m_FightWorkList[UserID].m_MaxTargetNum = 1;
			g_pMainState->m_FightWorkList[UserID].targetlist[0] = TargetID;
		}
		if (UseĬ�ϼ���(Skilllv, sSkillID, UserID, TargetID))
			return true;
	}
		return false;
	}
}



bool cSkillManager::Use1000ƽ��(int Skilllv, int sSkillID, int UserID, int TargetID)
{
	sFightWork* pUserList = &g_pMainState->m_FightWorkList[UserID];
	sFightWork* pTargetList = nullptr;
	if (TargetID >= 0)
	{
		pTargetList = &g_pMainState->m_FightWorkList[TargetID];
	}
	
	cObj* pUser = pUserList->m_pObj;
	cPropertyData* pUserData;
	pUser->GetPropertyData(pUserData);
	pUserList->targetID = TargetID;
	cObj* pTarget = pTargetList->m_pObj;
	cPropertyData* pTargetData;
	pTarget->GetPropertyData(pTargetData);
	
	auto setSkillSelect = [&](int t)
	{
		sFightSkillSelect select;
		select.SkillLv = pUserData->m_Lv;  //pUserList->m_pObj->GetSkillLv(pUserData->EndMagic) + pUserData->m_XiuLian.GetMag();
		select.SkillID = pUserData->EndMagic;
		if (g_pMainState->m_AI.isSkillSeal(pUserData->EndMagic))
		{
			select.SkillLv = pUserData->m_Lv - 25;
			if (select.SkillLv < 5)
			{
				select.SkillLv = 5;
			}
		}
		select.TargetID = t;
		return select;
	};

	int& stage = pUserList->GetWork()->stage;
	switch (stage)
	{
	case 0:
		if (1)
		{
			const sFightPoint* pOffse = pUserList->GetFightPoint();
			if (pOffse->m_xOff > 0)
				stage = 22;
// 			else if (pUser->m_IndexType == INDEXTYEP_PET && pUserData->modeid == ePetID::���)
// 			{
// 				stage = 120;
// 			}
			else
			{
				stage = 21;
			}
		}
		return true;
	case 22:
		if (m_pFightState->Approach(UserID, TargetID))
			stage = 21;
		return true;
	case 21:
		if (1)
		{
			if (pUserList->_combo)
			{
				pTargetData->m_FightData.m_bHit = true;
			}
			else
			{
				//�������
				CheckHit(pUserData, pTargetData);
				// �������
				if (pTargetData->m_FightData.m_bHit &&
					pUserData->isHadPetSkill(2104) &&
					rand() % 100 < 5)
				{
					pTargetData->m_FightData.m_bHit = false;
				}
			}

//			if (pUserData->m_FightData.AttackNum > 0)
//			{
// 				pUserData->NightLv = pTargetData->m_FightData.m_bHit;
// 				pUserData->AbnormalResist = false;
// 				if (pTargetData->ShiXueAdd >= 0xffffff)
// 				{
// 					pTargetData->ShiXueAdd -= 0xffffff;
// 				}
// 			}
// 			else if (pUserData->NightLv)
// 			{
// 				pUserData->NightLv = pTargetData->m_FightData.m_bHit;
// 			}
			pUser->Set(POS_FIGHT_STAND);
			if (pTargetData->m_FightData.m_bHit)
			{
				bool is��� = pUserData->isHadPetSkill(2109);
				if (is���)
				{
					pUserData->CriRate.d1 += 10;
				}

				CountParry(pUserData, pTargetData);//����
				CountCri(pUserData, pTargetData);//��ɱ

				if (is���)
				{
					pUserData->CriRate.d1 -= 10;
				}

				auto& gs = pTargetData->m_FightData.m_guardID;
				forr(gs, i)
				{
					auto& list = g_pMainState->m_FightWorkList[gs[i]];
					if (!list.isExist || list.CheckDie())
					{
						gs.erase(gs.begin() + i);
					}
				}
				//������˱���,�ȴ������߾�λ
				if (gs.size())
				{
					pTarget->m_MagicWav.LoadWav(0x4ADFB0ED);
					stage = 101;
					return true;
				}
			}
			stage = 20;
		}
		return true;
	case 20:
		StageWaitSleep(4, UserID, 120);
		return true;
	case 120:
	{
		int pos;
		if (rand() % 100 < 50)
			pos = POS_ATTACK2;
		else
			pos = POS_ATTACK;
		pUser->Set(pos);
		pUser->SetSound(pos);
		stage = 1;
	}
	case 1:
	{
		int atkp = m_pFightState->WorkAttack(UserID);
		switch (atkp)
		{
		case 0:
			return true;
		default:
		{
			//�ǲ��ǹ���
			const sFightPoint* pOffse = pUserList->GetFightPoint();
			if (pOffse->m_xOff == 0 && !(
				(pUser->m_IndexType == INDEXTYEP_PET && pUserData->modeid == ePetID::���) |
				(pUser->m_IndexType == INDEXTYEP_CHARACTER && ((cPcData*)pUserData)->m_CardPetID == ePetID::���)
				))
			{
				m_pFightState->m_HiddenWeapons.Load(0xE2BC8127);
				m_pFightState->m_HiddenWeaponsUseNum = 1;
				m_pFightState->m_HiddenWeaponsp[0].m_NeedShow = true;
				m_pFightState->m_HiddenWeaponsp[0].m_x = pUser->GetX();
				m_pFightState->m_HiddenWeaponsp[0].m_y = pUser->GetY() + 20;
				m_pFightState->m_HiddenWeaponsTargetID[0] = TargetID;
				stage = 23;
				return true;
			}
			if (!PhysicalAtkHitStage(UserID, TargetID, sSkillID))
			{

				stage = 3;
				return true;
			}
			if (atkp != 1)
			{
				stage += 1;
				return true;
			}
		}
			break;
		}
	}
		return true;
	case 23://����

	{
		if (m_pFightState->WaitPosEnd(UserID))
		{
			pUser->Set(POS_FIGHT_STAND);
		}
		if (m_pFightState->HiddenWeaponsMove(0, 50))
		{
			if (!PhysicalAtkHitStage(UserID, TargetID, sSkillID))
			{
				stage = 3;
				return true;
			}
			stage = 2;
		}
	}
		return true;
	case 2:  //�����ж�
	{
		if (m_pFightState->WaitPosEnd(UserID))
		{
			pUser->Set(POS_FIGHT_STAND);
		}
		stage = 3;
		int dam = 0;
		int dup = 0;
		// �������
		if (pUserData->isHadPetSkill(2104))
		{
//			if (pUserData->ShiXueAdd >= 0xffffff)
			if (pUserList->_zhuiji == 5)
			{
				dup -= 45;
			}
			else
			{
				dup += 10;
			}
		}
		else
		{
//			if (pUserData->ShiXueAdd >= 0xffffff)
			if (pUserList->_zhuiji == 5)
			{
				dup -= 50;
			}
		}

		CountphysicalDamage(dam, UserID, TargetID, dup);
		// ǧ��һŭ
		if (pUserData->isHadPetSkill(2107))
		{
			if (dam > pTargetData->HPMax.GetData() / 10)
			{
				if (UserID % 10 >= 5)
				{
					sFightWork* u = &g_pMainState->m_FightWorkList[UserID - 5];
					if (u->isExist && u->m_pObj)
					{
						AddCp(UserID - 5, 10);
					}
				}
			}
		}
		if (pUserData->Spurting.d1)
		{
			int jianshetarget;
			for (int i = 0; i < 2; i++)
			{
				if (g_pMainState->m_FightWorkList[TargetID].CheckDie())
					jianshetarget = g_pMainState->m_AI.find���䰵��(UserID, TargetID, i, true/* + 2*/);
				else
					jianshetarget = g_pMainState->m_AI.find���䰵��(UserID, TargetID, i + 1, true/* + 2*/);
				if (jianshetarget>-1 && dam > 0)
				{
					cPropertyData* jianshepet;
					g_pMainState->m_FightWorkList[jianshetarget].m_pObj->GetPropertyData(jianshepet);
					int rate = pUserData->Spurting.d1 - jianshepet->Spurting.d2;
					if (rate > 0)
					{
						int   dam2 = (dam*rate) / 100;
						AddHp(jianshetarget, -dam2);
						SetDamage(dam2, jianshetarget);
						if (1 > jianshepet->m_HP)//��������
						{
							if (UserID < 10)
								g_pMainState->m_FightWorkList[jianshetarget].m_sufferDirection = 7;
							else g_pMainState->m_FightWorkList[jianshetarget].m_sufferDirection = 3;
							g_pMainState->m_pFightState->SetDie(jianshetarget);
							pTargetData->m_CP /= 2;
					//		 return true;
						}
					}
				}
			}
		}	
	}
		return true;
	case 3:
		if (m_pFightState->WaitPosEnd(UserID) || (pUser->m_NowPos == POS_FIGHT_STAND))
		{
			//pUser->SetStatic(false);
			g_pMainState->m_FightWorkList[TargetID].SetMagiSufferID(0, 1, &m_pFightState->m_FullSkill.m_SufferMagic[TargetID]);
			bool die = g_pMainState->m_FightWorkList[TargetID].CheckDie();

			pUserList->_endmagic = -1;
			if (!die && pUserData->EndMagic >= 0 && !pUserData->m_FightData.chaos���ҷ��� && rand() % 100 < 20)
			{
				pUserList->_endmagic = pUserData->EndMagic;
			}

			bool isCombo = false;
			if (pUserList->_combo)
			{
				isCombo = true;
				pUserList->_combo = 0;
			}
			else if (!die && pUserList->_zhuiji != 5 && pUserList->_nuji != 5)
			{
				bool is��� = pUserData->isHadPetSkill(2109);
				if (is���)
				{
					pUserData->ComboRate.d1 += 10;
				}
				pUserList->_combo = CoutCombo����(pUserData, pTargetData);
				if (is���)
				{
					pUserData->ComboRate.d1 -= 10;
				}
				
			}

			if (pUserList->_nuji == 5)
			{
				if (!isCombo)
				{
					pUserList->_nuji = 0;
				}
			}
			if ((pUserData->m_FightData.m_bCri/* || pUserList->_combo*/) && pUserList->_nuji > 0 && pUserList->_nuji < 5)
			{
				++pUserList->_nuji;
			}

			if (pUserList->_zhuiji == 5)
			{
				pUserList->_zhuiji = 0;
			}

			if (die)
			{
				if (pUserList->_nuji > 1)
				{
					int tid = g_pMainState->m_AI.find׷�������¹�(UserID, 4, true);
					if (tid >= 0)
					{
						pUserList->_nuji = 5;
						pUserList->m_SkillSelect.TargetID = tid;
						stage = 22;
						ccc_log("��������ŭ��");
						return true;
					}
				}
				else if (pUserList->_zhuiji == 1)
				{
					int tid = g_pMainState->m_AI.find׷�������¹�(UserID, 4, true);
					if (tid >= 0)
					{
						pUserList->_zhuiji = 5;
						pUserList->m_SkillSelect.TargetID = tid;
						stage = 22;
						ccc_log("����׷��");
						return true;
					}
				}
				stage = 5;
				return true;
			}
			stage = 4;
		}
		return true;
	case 4:
		if (pTargetData)
		{
			//�Ƿ񷴻�
			int rat = pTargetData->CounterRate.d1 - pUserData->CounterRate.d2;
			if ((rand() % 100) < rat)
			{
				pUserList->_combo = 0;
				pUser->Set(POS_FIGHT_STAND);
				stage = 14;
			}
			else
			{
				stage = 7;
			}
		}
		else 
			stage = 7;
		return true;
	case 14:
	{
		//�ȵȴ�Ӳֱ����
		if (g_pMainState->m_FightWorkList[TargetID].m_work.size())
			return true;
		stage = 6;
		//����
		pUser->Set(POS_FIGHT_STAND);
		pTarget->SetStatic(false);
		m_pFightState->SetCounter(TargetID, UserID);
	}
		return true;
	case 5:
	{
		bool isReturn = m_pFightState->ReturnApproach(UserID);
		// �����ɫ�Ѿ�����ԭζ
		if (isReturn)
		{
			// work��ɣ����
			pUserList->m_work.pop_back();
			// ׷�ӷ���
			if (0) // �������� ����TargetIDû��/����ʲô��
			{
				// ���work
				pUserList->SetWork(WORKTYPE_MAGIC);
			//	pUserList->m_WorkType = -1;
				pUserList->m_SkillSelect = setSkillSelect(TargetID); // ���úü���ѡ��� Ŀ��, ���, �ȼ�
				// ʹ�ü���
				return Use(pUserList->m_SkillSelect, UserID, true);
			}
		} 
		return true;
	}
	case 6://�ȴ����ַ�����
	{
//		return StageWaitFightBack(UserID, TargetID, 7);
		if (pTargetList->m_work.empty())
		{
			pUserList->GetWork()->stage = 7;
		}
		return true;
	}

	case 7://�Ƿ�����
	{
		// 5 ����
		// 21 ԭ��
		// 22 ����
		if (!pTargetData->m_FightData.m_bHit)
		{
			stage = 5;
			pUserList->_endmagic = -1;
			return true;
		}
		bool combo = pUserList->_combo == 1;
		if (combo && pUserList->_nuji > 0 && pUserList->_nuji < 5)
		{
			++pUserList->_nuji;
// 			if (pUserList->_nuji > 1)
// 			{
// 				pUserList->_nuji = 5;
// 			}
		}

		bool isNj = pUserList->_nuji == 5;
		bool isZj = pUserList->_zhuiji == 5;
		int mag = pUserList->_endmagic;

		if (mag >= 0)
		{
			if (!combo)
			{
				stage = 10086;
			}
			else
			{
				stage = 10010;
			}
		}
		else
		{
			if (combo)
			{
				stage = 21;
			}
			else if (pUserList->_nuji > 1)
			{
				int tid = g_pMainState->m_AI.find׷�������¹�(UserID, 4, true);
				if (tid >= 0)
				{
					pUserList->_nuji = 5;
					pUserList->m_SkillSelect.TargetID = tid;
// 					pTargetList = &g_pMainState->m_FightWorkList[TargetID];
// 					pTarget = pTargetList->m_pObj;
// 					pTarget->GetPropertyData(pTargetData);
					ccc_log("����ŭ��");
					stage = 22;
				}
				else
				{
					stage = 5;
				}
			}
			else
			{
				stage = 5;
			}
		}
	}
		return true;
	case 10010: // �����ķ������������
	{
		if (m_pFightState->ReturnApproach(UserID))
		{
			ccc_log("��������,�к���");
//			pUserList->m_work.pop_back();
			pUserList->GetWork()->stage = 0x10086;
			pUserList->SetWork(WORKTYPE_MAGIC);
		//	pUserList->m_WorkType = -1;
			pUserList->_endmagic = -1;
			pUserList->m_SkillSelect = setSkillSelect(TargetID);
			return Use(pUserList->m_SkillSelect, UserID, true);
		}
	}
		return true;
	case 0x10086: // ��������
	{
		if (!pTargetList || !pTargetList->isExist)
		{
			pUserList->m_work.pop_back();
			return true;
		}

		if (pUserList->_combo && !pTargetList->CheckDie())
		{
			stage = 22;
			return true;
		}
		int nid = -1;
		if (pUserList->_nuji > 1)
		{
			int tid = g_pMainState->m_AI.find׷�������¹�(UserID, 4, true);
			if (tid >= 0)
			{
				nid = tid;
			}
		}
		int zid = -1;
		if (pTargetList->CheckDie())
		{
			if (pUserList->_zhuiji == 1)
			{
				int tid = g_pMainState->m_AI.find׷�������¹�(UserID, 4, true);
				if (tid >= 0)
				{
					zid = tid;
				}
			}
		}
		if (zid < 0 && nid < 0)
		{
			pUserList->m_work.pop_back();
			return true;
		}

		if (nid >= 0)
		{
			pUserList->_nuji = 5;
			pUserList->m_SkillSelect.TargetID = nid;
			ccc_log("����������, ����ŭ��");
		}
		else if (zid >= 0)
		{
			pUserList->_zhuiji = 5;
			pUserList->m_SkillSelect.TargetID = zid;
			ccc_log("����������, ����׷��");
		}

//		Q_LOG("�����������������");
		// ����
		stage = 22;
	}
		return true;
	case 0x10087:
	{
		if (!pTargetList || !pTargetList->isExist)
		{
			pUserList->m_work.pop_back();
			return true;
		}
		int nid = -1;
		if (pUserList->_nuji > 1)
		{
			int tid = g_pMainState->m_AI.find׷�������¹�(UserID, 4, true);
			if (tid >= 0)
			{
				nid = tid;
			}
		}
		int zid = -1;
		if (pTargetList->CheckDie())
		{
			if (pUserList->_zhuiji == 1)
			{
				int tid = g_pMainState->m_AI.find׷�������¹�(UserID, 4, true);
				if (tid >= 0)
				{
					zid = tid;
				}
			}
		}

		if (nid >= 0)
		{
			pUserList->_nuji = 5;
			pUserList->m_SkillSelect.TargetID = nid;
			stage = 22;
			ccc_log("����������, ��������ŭ��");
		}
		else if (zid >= 0)
		{
			pUserList->_zhuiji = 5;
			pUserList->m_SkillSelect.TargetID = zid;
			stage = 22;
			ccc_log("����������, ����׷��");
		}
		else
		{
			pUserList->m_work.pop_back();
		}
		return true;

		//////////////////////////////////////////////////////////////////////////
		bool iszj = false;
		if (pTargetList && pTargetList->isExist && pTargetList->CheckDie())
		{
			if (pUserList->_zhuiji == 1)
			{
				int tid = g_pMainState->m_AI.find׷�������¹�(UserID, 4, true);
				if (tid >= 0)
				{
					pUserList->_zhuiji = 5;
					pUserList->m_SkillSelect.TargetID = tid;
				}
			}
		}
		if (!iszj)
		{
			pUserList->m_work.pop_back();
			return true;
		}

		ccc_log("����������׷��");
		stage = 22;
	}
		return true;
	case 10086: // ���һ�ι��������ķ��� 
	{
		if (m_pFightState->ReturnApproach(UserID))
		{
			ccc_log("���һ�ι�����������");
			pUserList->GetWork()->stage = 0x10087;
			pUserList->m_SkillSelect = setSkillSelect(TargetID);
			pUserList->SetWork(WORKTYPE_MAGIC);
		//	pUserList->m_WorkType = -1;
			pUserList->_endmagic = -1;
			return Use(pUserList->m_SkillSelect, UserID, true);
		}
	}
		return true;
	case 101: //�ȴ������߾�λ
		return StageWaitProtect(UserID, TargetID, 120);
	}
	return false;
}



bool cSkillManager::UseĬ�ϼ���(int Skilllv, int sSkillID, int UserID, int TargetID)
{
	sFightWork* pUserList = &g_pMainState->m_FightWorkList[UserID];
	sFightWork* pTargetList = &g_pMainState->m_FightWorkList[TargetID];
	cObj* pUser = pUserList->m_pObj;
	cPropertyData* pUserData;
	cPropertyData* pTargetData;
	pUser->GetPropertyData(pUserData);
	cObj* pTarget = pTargetList->m_pObj;
	pTarget->GetPropertyData(pTargetData);
	int& stage = pUserList->GetWork()->stage;
	static ulong s_magic2102;

	switch (stage)
	{
	case 0:
	{
//		int hpout = 0;
//		Cost(hpout, Skilllv, sSkillID, UserID, 1, true);
// 		if (hpout)
// 		{
// 			SetDamage(hpout, UserID);
// 		}
		pUser->Set(POS_MAGIC);
		pUser->SetSound(POS_MAGIC);
		stage = 1;
	}
		return true;
	case 1:
		if (WaitForMagicPoint(UserID) || pUser->m_pShowData[0]->m_isStatic)
		{
			pUser->SetStatic(false);
			pUser->SetMagicSound(sSkillID);//����

			ulong MagicID;
			int MagicPos;
			bool MagicUporDown;
			bool  toAll;
			bool bAtk = GetSkill��ҪĿ�걻�򶯻�(sSkillID);
			int maxnum;
			GetMagicAndNum�뼸(Skilllv, sSkillID, UserID, TargetID, MagicID, maxnum, MagicPos, MagicUporDown, toAll);
 			int magicspeed = GetSpeed(MagicID/*sSkillID*/);

			if (sSkillID == 2102)
			{
				// ���
				int r = rand() % 100;
				if (r < 13)
				{
					maxnum = 1;
				}
				else if (r < 33)
				{
					maxnum = 2;
				}
				else if (r < 67)
				{
					maxnum = 3;
				}
				else if (r < 87)
				{
					maxnum = 4;
				}
				else
				{
					maxnum = 5;
				}
				if (maxnum == 2 || maxnum == 3)
				{
					MagicID = 0x75331968;
					toAll = true;
				}
				else if (maxnum == 4 || maxnum == 5)
				{
					MagicID = 0xF99822CE;
					toAll = true;
				}
				s_magic2102 = MagicID;
				if (maxnum < pUserList->m_MaxTargetNum)
				{
					pUserList->m_MaxTargetNum = maxnum;
				}
			}

//			pUserList->m_MaxTargetNum = 0;
			if (toAll)
			{
				// QQ��ͼ
				int x = 0, y = 0;
				if (TargetID < 10)
				{
					x = 553;
					y = 412;
				}
				else
				{
					x = 290;
					y = 230;
				}
				if (MagicID == 0x4DB67680)
				{
					// ��ɳ
					x -= 120;
					y -= 140;
				}
				else if (MagicID == 0xDED2253F)
				{
					// �����һ�
					x += 120;
					y -= 135;
				}

				while (!m_pFightState->m_ThreadSleep)
				{
					Sleep(1);  //�ȴ��߳�
				}

				m_pFightState->m_FullSkill.SetMagicUp(0, MagicID, x, y);
				m_pFightState->m_FullSkill.m_FullSkilUP[0].SetFrame(0);
				m_pFightState->m_FullSkill.m_FullSkilUP[0].m_NeedShow = true;
				m_pFightState->m_FullSkill.m_FullSkilUP[0].m_Picture.m_x = x;
				m_pFightState->m_FullSkill.m_FullSkilUP[0].m_Picture.m_y = y;

				m_pFightState->m_IDtoLoad[0] = MagicID;
				m_pFightState->m_pFileToLoad[0] = &m_pFightState->m_FullSkill.m_FullSkilUP[0];
				ResumeThread(m_pFightState->m_hThread);
			}

// 			auto func = [&](bool isCheckDie, cAI::eEnemyType type, int stateid)
// 			{
// 				vector<POINT> tList;
// 				g_pMainState->m_AI.finds(isCheckDie, false, tList, type, TargetID, stateid);
// 				if (tList.empty())tList.push_back({ TargetID, 0 });
// 				if (tList.size() < maxnum)maxnum = tList.size();
// 				int i = 0;
// 				for (; i < maxnum; ++i)
// 				{
// 					if (tList[i].x == TargetID)break;
// 				}
// 				if (i == maxnum)tList[maxnum - 1].x = TargetID;
// 				for (int i = 0; i < maxnum; ++i)
// 				{
// 					pUserList->targetlist[i] = tList[i].x;
// 				}
// 				pUserList->m_MaxTargetNum = maxnum;
// 			};
// 
// 			// �������
// 			auto func2 = [&](bool isCheckDie, cAI::eEnemyType type, int stateid)
// 			{
// 				vector<POINT> tList;
// 				g_pMainState->m_AI.finds(isCheckDie, false, tList, type, TargetID, stateid);
// 				auto list2 = g_pMainState->m_AI.check����(tList, UserID);
// 				if (!list2.size())list2.push_back(TargetID);
// 				if (list2.size() < maxnum)maxnum = list2.size();
// 				int i = 0;
// 				for (; i < maxnum; ++i)
// 				{
// 					if (list2[i] == TargetID)break;
// 				}
// 				if (i == maxnum)list2[maxnum - 1] = TargetID;
// 				for (int i = 0; i < maxnum; ++i)
// 				{
// 					pUserList->targetlist[i] = list2[i];
// 				}
// 				pUserList->m_MaxTargetNum = maxnum;
// 			};
// 
// 
// 			if (maxnum < 2)
// 			{
// 				pUserList->targetlist[0] = TargetID;
// 				pUserList->m_MaxTargetNum = 1;
// 			}
// 			else
// 			{
// 				switch (sSkillID)
// 				{
// 				case 27: // ���
// 				{
// 					func2(true, cAI::eET��ӡ����, 27);
// 					break;
// 				}
// 				case 33: // ��ջ���
// 				case 176:// ����
// 				case 177:// ���
// 					func(true, cAI::eET�Ͻ��33, 33);
// 					break;
// // 				case 38:
// // 				case 39:
// 				case 40: // ��
// 				case 41: // ����
// 				case 42: // ��������
// //				case 45:
// //			    case 94:
// 				case 189: // ����
// // 				case 3007: // �ĺ�
// // 				case 3013: // ����
// 				{
// 					func(true, cAI::eETѪ����, -1);
// 					int i = 1;
// 					for (; i < pUserList->m_MaxTargetNum; ++i)
// 					{
// 						if (pUserList->targetlist[i] == TargetID)
// 						{
// 							break;
// 						}
// 					}
// 					if (i != pUserList->m_MaxTargetNum)
// 					{
// 						swap(pUserList->targetlist[i], pUserList->targetlist[0]);
// 					}
// 				}
// // 				{
// // 					vector<POINT> tList;
// // 					g_pMainState->m_AI.find������͵ļ���(false,false,tList, cAttackAI::eETѪ����, UserID);
// // 					if (tList.size() < maxnum)maxnum = tList.size();
// // 					int i = 0;
// // 					for (; i < maxnum; i++)
// // 					{
// // 						if (tList[i].x == TargetID)break;
// // 					}						
// // 					if (i == maxnum)tList[maxnum - 1].x = TargetID;
// // 					for (i = 0; i < maxnum; i++)
// // 					{
// // 						pUserList->targetlist[i] = tList[i].x;
// // 					}
// // 					pUserList->m_MaxTargetNum = maxnum;
// // 				}
// 
// 					break;
// 				case 91: // ��
// 				case 102:
// 					func(true, cAI::eETѪ����, sSkillID);
// 					// 			{
// 					// 				vector<POINT> tList;
// 					// 				g_pMainState->m_AI.find������͵ļ���(false, false, tList, cAttackAI::eETѪ����, UserID, 102);
// 					// 				if (!tList.size())tList.push_back({ TargetID, 0 });
// 					// 				if (tList.size() < maxnum)maxnum = tList.size();
// 					// 				int i = 0;
// 					// 				for (; i < maxnum; i++)
// 					// 				{
// 					// 					if (tList[i].x == TargetID)break;
// 					// 				}
// 					// 				if (i == maxnum)tList[maxnum - 1].x = TargetID;
// 					// 				for (i = 0; i < maxnum; i++)
// 					// 				{
// 					// 					pUserList->targetlist[i] = tList[i].x;
// 					// 				}
// 					// 				pUserList->m_MaxTargetNum = maxnum;
// 					// 			}
// 					break;
// 				case 112: // �鶯����
// 				case 204: // ����
// 					func(true, cAI::eET���鶯112, 112);
// 					// 				{
// 					// 					vector<POINT> tList;
// 					// 					g_pMainState->m_AI.find������͵ļ���(false, false, tList, cAttackAI::eET���鶯112, UserID, 112);
// 					// 					if (!tList.size())tList.push_back({ TargetID, 0 });
// 					// 					if (tList.size() < maxnum)maxnum = tList.size();
// 					// 					int i = 0;
// 					// 					for (; i < maxnum; i++)
// 					// 					{
// 					// 						if (tList[i].x == TargetID)break;
// 					// 					}
// 					// 					for (int i = 0; i < maxnum; i++)
// 					// 					{
// 					// 						pUserList->targetlist[i] = tList[i].x;
// 					// 					}
// 					// 					pUserList->m_MaxTargetNum = maxnum;
// 					// 				}
// 					break;
// 				case 120: // ����
// 					func(true, cAI::eET����120, -1);
// 					// 			{
// 					// 				int num = 1;
// 					// 				int star = UserID >= 10 ? 10 : 0;
// 					// 				for (int i = star; i < star + 10; ++i)
// 					// 				{
// 					// 					if (i == TargetID)continue;
// 					// 					if (!g_pMainState->m_FightList[i].isExist)
// 					// 					{
// 					// 						continue;
// 					// 					}
// 					// 					cPetData *data = nullptr;
// 					// 					g_pMainState->m_FightList[i].m_pData->GetDateP(data);
// 					// 					if (!data)
// 					// 					{
// 					// 						continue;
// 					// 					}
// 					// 					if (data->PeopleSpecial.d1 >= 100)
// 					// 					{
// 					// 						continue;
// 					// 					}
// 					// 					pUserList->targetlist[num] = i;
// 					// 					if (++num == maxnum)
// 					// 					{
// 					// 						break;
// 					// 					}
// 					// 				}
// 					// 				pUserList->targetlist[0] = TargetID;
// 					// 				pUserList->m_MaxTargetNum = num;
// 					// 			}
// 					break;
// // 				case 126://��Ȫ
// // 					func2(true, cAttackAI::eET��Ȫ֮Ϣ126, 126);
// // 					break;
// // 				case 127://�����ɢ
// // 					func2(true, cAttackAI::eET�����ɢ127, -1);
// // 					break;
// // 				case 37: // �ҷ�ȱ�
// // 				case 104: // ����
// // 				case 125: // ����
// // 				case 3008: // �ػ���
// // 				case 3009: // ��������
// // 					pUserList->m_MaxTargetNum = 0;
// // 					for (int i = 0; i < maxnum; i++)
// // 					{
// // 						pUserList->targetlist[pUserList->m_MaxTargetNum] = g_pMainState->m_AI.Getս��Id������Id(UserID, TargetID, i, 2);
// // 
// // 						if (bAtk)
// // 						{
// // 							if (UserID == pUserList->targetlist[pUserList->m_MaxTargetNum])
// // 							{//��ֹ���󹥻��Լ�
// // 								continue;
// // 							}
// // 						}
// // 						if (-1 == pUserList->targetlist[pUserList->m_MaxTargetNum])
// // 						{
// // 							break;
// // 						}
// // 						pUserList->m_MaxTargetNum += 1;
// // 					}
// // 					break;
// 				case 3048: // �Ⱥ�
// 				{
// 					int num = 0;
// 					int star = UserID >= 10 ? 10 : 0;
// 					for (int i = star; i < star + 10; ++i)
// 					{
// //					    if (i == TargetID)continue;
// 						if (!g_pMainState->m_FightWorkList[i].isExist)
// 						{
// 							continue;
// 						}
// 						if (g_pMainState->m_FightWorkList[i].m_pObj->m_IndexType != INDEXTYEP_CHARACTER)
// 						{
// 							continue;
// 						}
// 						if (!g_pMainState->m_FightWorkList[i].CheckDie())
// 						{
// 							continue;
// 						}
// 						cPropertyData *data = nullptr;
// 						g_pMainState->m_FightWorkList[i].m_pObj->GetPropertyData(data);
// 						if (!data)
// 						{
// 							continue;
// 						}
// 						if (!pUserData->Hide.d2 && data->Hide.d1)
// 						{
// 							continue;
// 						}
// 						pUserList->targetlist[num] = i;
// 						if (++num == maxnum)
// 						{
// 							// break;
// 						}
// 					}
// //				    pUserList->targetlist[0] = TargetID;
// 					pUserList->m_MaxTargetNum = num;
// 					int d = pUserData->m_HP - pUserData->HPMax.GetData() / 10;
// 					if (d > 0)
// 					{
// 						AddHp(UserID, -d);
// 						SetDamage(d, UserID);
// 					}
// 					d = pUserData->m_HP2 - pUserData->HPMax.GetData() / 10;
// 					if (d > 0)
// 					{
// 						AddHpHurt(UserID, -d);
// 					}
// 					pUserData->m_MP = 0;
// 				}
// 					break;
// 				default:
// 					for (int i = 0; i < maxnum; i++)
// 					{
// 						pUserList->targetlist[pUserList->m_MaxTargetNum] = g_pMainState->m_AI.find���䰵��(UserID, TargetID, i, 3);
// 						// GetTargetID(UserID, TargetID, i);
// 
// 						if (bAtk)
// 						{
// 							if (UserID == pUserList->targetlist[pUserList->m_MaxTargetNum])
// 							{
// 								//��ֹ���󹥻��Լ�
// 								continue;
// 							}
// 						}
// 
// 						if (-1 == pUserList->targetlist[pUserList->m_MaxTargetNum])
// 						{
// 							break;
// 						}
// 						pUserList->m_MaxTargetNum += 1;
// 					}
// 					break;
// 				}
// 			}
			if (sSkillID != 7)
			{
				Cost(UserID, sSkillID, pUserList->m_MaxTargetNum, true);
			}
			for (int i = 0; i < pUserList->m_MaxTargetNum; i++)
			{
				pUserList->m_NowTargetID = pUserList->targetlist[i];
				if (bAtk)
				{
//					m_pFightState->SetMagicSuffer(pUserList->m_NowTargetID, pUser->GetDirection());
					g_pMainState->m_FightWorkList[pUserList->m_NowTargetID].m_sufferDirection = pUser->GetDirection();
				}

				if (toAll)
				{
					while (!m_pFightState->m_ThreadSleep)
					{
						Sleep(1);  //�ȴ��߳�
					}
					m_pFightState->m_pFightWorkList[pUserList->m_NowTargetID]->m_bSufferFullSkill = true;
					m_pFightState->m_FullSkill.m_FullSkilUP[0].SetDirection((sSkillID == 2102 && TargetID < 10));
					m_pFightState->m_FullSkill.m_FullSkilUP[0].m_Picture.m_FrameGap = magicspeed;
				}
				else
				{
					m_pFightState->m_pFightWorkList[pUserList->m_NowTargetID]->m_bSufferFullSkill = false;
					m_pFightState->m_pFightWorkList[pUserList->m_NowTargetID]->SetMagiSufferID(MagicID, MagicPos, &m_pFightState->m_FullSkill.m_SufferMagic[TargetID], MagicUporDown);
					m_pFightState->m_pFightWorkList[pUserList->m_NowTargetID]->m_pObj->m_MagicSuffer.m_FrameGap = magicspeed;
					m_pFightState->m_pFightWorkList[pUserList->m_NowTargetID]->m_pObj->m_MagicSuffer.m_direction = (sSkillID == 2102 && TargetID < 10);
				}
			}
			stage += 1;
		}
		return true;
	case 2:
	{
		bool isOk = m_pFightState->WaitPosEnd(UserID) || pUser->m_pShowData[0]->m_isStatic;// || (pUser->m_NowPos == POS_FIGHT_STAND);
		if (isOk)
		{
			pUser->Set(POS_FIGHT_STAND);
			pUser->SetStatic(false);
//			stage += 1;
		}



		ulong MagicID;
		bool toAll = isAni������(sSkillID);
		int LateTime; //�˺�������ʱ
//		bool bAtk = GetSkill��ҪĿ�걻�򶯻�(sSkillID);
		GetDelayAnd(sSkillID, LateTime, MagicID);
		cct::setDelta(MagicID, LateTime);
		if (sSkillID == 2102)
		{
			MagicID = s_magic2102;
			toAll = (MagicID != GetSkill(sSkillID)->m_MagicID);
		}
		bool bover = false;
		if (toAll)
		{
// 			if (!pTarget->m_MagicSuffer.m_NeedShow)
// 			{
// 				bover = true;
// 			}
// 			else
			{
				while (!m_pFightState->m_ThreadSleep)
				{
					Sleep(1);  //�ȴ��߳�
				}
				int maxf = m_pFightState->m_FullSkill.m_FullSkilUP[0].GetMaxFrame();
				LateTime += max((maxf - LateTime) / 2, 3);
				if (LateTime >/*=*/ maxf)
				{
					LateTime = maxf/* - 1*/;
				}
				if (m_pFightState->m_FullSkill.m_FullSkilUP[0].GetNowFrame() == maxf - max(1, LateTime))
				{
					bover = true;
				}
			}
		}
		else
		{
			if (!pTarget->m_MagicSuffer.m_NeedShow)
			{
				bover = true;
			}
			else
			{
				int maxf = pTarget->m_MagicSuffer.m_pFile->GetMaxFrame();
				LateTime += max((maxf - LateTime) / 2, 3);

				if (LateTime >/*=*/ maxf)
				{
					LateTime = maxf/* - 1*/;
				}
				if (pTarget->m_MagicSuffer.GetFrame() == maxf - LateTime)
				{
					bover = true;
				}
			}
		}

		if (bover)
		{
			bool bAtk = GetSkill��ҪĿ�걻�򶯻�(sSkillID);
			for (int i = 0; i < pUserList->m_MaxTargetNum; i++)
			{
				pUserList->m_NowTargetID = pUserList->targetlist[i];
				if (bAtk)
				{
					m_pFightState->SetMagicSuffer(pUserList->m_NowTargetID, g_pMainState->m_FightWorkList[pUserList->m_NowTargetID].m_sufferDirection);
				}
			}
			stage = 3;
		}
	}
//		return true;
	case 3:  //����BUFF
	{
		if (m_pFightState->WaitPosEnd(UserID) || pUser->m_pShowData[0]->m_isStatic/* || (pUser->m_NowPos == POS_FIGHT_STAND)*/)
		{
			pUser->Set(POS_FIGHT_STAND);
			pUser->SetStatic(false);
		}
		ulong MagicID;
		bool toAll = isAni������(sSkillID);
		int LateTime; //�˺�������ʱ
		bool bAtk = GetSkill��ҪĿ�걻�򶯻�(sSkillID);
		GetDelayAnd(sSkillID, LateTime, MagicID);
		cct::setDelta(MagicID, LateTime);

		if (sSkillID == 2102)
		{
			MagicID = s_magic2102;
			toAll = (MagicID != GetSkill(sSkillID)->m_MagicID);
		}

		bool bover = false;
		if (toAll)
		{
// 			if (!pTarget->m_MagicSuffer.m_NeedShow)
// 			{
// 				bover = true;
// 			}
// 			else
			{
				while (!m_pFightState->m_ThreadSleep)
				{
					Sleep(1);  //�ȴ��߳�
				}
				int maxf = m_pFightState->m_FullSkill.m_FullSkilUP[0].GetMaxFrame();
				if (LateTime >/*=*/ maxf)
				{
					LateTime = maxf/* - 1*/;
				}
				if (m_pFightState->m_FullSkill.m_FullSkilUP[0].GetNowFrame() == maxf - LateTime)
				{
					bover = true;
				}
			}
		}
		else
		{
			if (!pTarget->m_MagicSuffer.m_NeedShow)
			{
				bover = true;
			}
			else
			{
				if (LateTime >= pTarget->m_MagicSuffer.m_pFile->GetMaxFrame())
				{
					LateTime = pTarget->m_MagicSuffer.m_pFile->GetMaxFrame() - 1;
				}
				if (pTarget->m_MagicSuffer.GetFrame() == pTarget->m_MagicSuffer.m_pFile->GetMaxFrame() - LateTime)
				{
					bover = true;
				}
			}
		}
		if (bover)
		{
			stage = 4;
			pUserList->m_NowTargetIdx = -1;
			for (int i = 0; i < pUserList->m_MaxTargetNum; i++)
			{
				pUserList->m_NowTargetID = pUserList->targetlist[i];
				if (bAtk)
				{
					m_pFightState->SwitchMagicSuffer(pUserList->m_NowTargetID);
					m_pFightState->m_pFightWorkList[pUserList->m_NowTargetID]->m_pObj->SetSound(POS_SUFFER);//����
					m_pFightState->m_pFightWorkList[pUserList->m_NowTargetID]->m_NowBeAtkowner = UserID;

				}

				if ((rand() % 100) < CheckMagicHit(Skilllv, sSkillID, UserID, pUserList->m_NowTargetID/*TargetID*/))
				{
					EffectSkill(Skilllv, sSkillID, UserID, pUserList->m_NowTargetID);
					if (g_pMainState->m_FightWorkList[pUserList->m_NowTargetID]._magicCri)
					{
						g_pMainState->m_FightWorkList[pUserList->m_NowTargetID]._magicCri = 0;
						g_pMainState->m_FightWorkList[pUserList->m_NowTargetID].m_pObj->SetMagicCri(&m_pFightState->_magicCri);
					}
				}
			}
			cPropertyData* pPet;
			pUser->GetPropertyData(pPet);
			if (1 > pPet->m_HP)
			{
				if (UserID < 10)
					pUserList->m_sufferDirection = 3;
				else pUserList->m_sufferDirection = 7;
				g_pMainState->m_pFightState->SetDie(UserID);
				pTargetData->m_CP /= 2;
				return true;
			}
		}
	}
		return true;
	case 4://�ȴ����Ƕ������
		if (m_pFightState->WaitPosEnd(UserID) || pUser->m_pShowData[0]->m_isStatic)
		{
			// ����
			if (pUserData->isHadPetSkill(2108))
			{
				int& lh = m_pFightState->m_pFightWorkList[UserID]->_longhun;
				if (++lh == 3)
				{
					lh = 0;
					pUserData->DmgPercentOfMagic.d1 += 1;
				}
			}
			switch (sSkillID)
			{
			case 7: // �Ƹ�����
				pUserList->m_SkillSelect.SkillID = 1017;
				stage = 0;
				return true;

			case 50: // ���컨��
				pUserList->m_SkillSelect.SkillID = 1050;
				stage = 0;
				return true;
			case 171: // ����ŭ
				pUserList->m_SkillSelect.SkillID = 1171;
				stage = 0;
				return true;
			case 172: // ��������
				pUserList->m_SkillSelect.SkillID = 1172;
				stage = 0;
				return true;
			case 2095: // ������ɽ
				pUserList->m_SkillSelect.SkillID = 1095;
				stage = 0;
				return true;
			}
			pUser->Set(POS_FIGHT_STAND);
			pUser->SetStatic(false);
			stage = 5;
		}
		return true;
	case 5:StageWaitSleep(10, UserID, 6); break;
	case 6:
	{
		pUser->SetMagicSound(-1);//����
		pUserList->m_work.pop_back();

		if (g_pMainState->m_FightWorkList[TargetID].isExist && (!g_pMainState->m_FightWorkList[TargetID].CheckDie()))
		{
			CoutComboMagic(sSkillID, pUserData, UserID, pTargetData);
		}
		else
		{
			cbCounter(UserID);
		}
	}
		break;
	}
	return true;
}



bool cSkillManager::Use71������������(int Skilllv, int sSkillID, int UserID, int TargetID)
{
	sFightWork* pUserList = m_pFightState->m_pFightWorkList[UserID];
	cObj* pUser = pUserList->m_pObj;
	cObj* pTarget = m_pFightState->m_pFightWorkList[TargetID]->m_pObj;
	cPropertyData* pUserData;
	cPropertyData* pTargetData;
	pUserList->m_pObj->GetPropertyData(pUserData);
	pTarget->GetPropertyData(pTargetData);
	int& stage = pUserList->GetWork()->stage;

	switch (stage)
	{
	case 0: // Ŀ���б�
	{
		if (is��������(sSkillID))
		{
			if (TargetID == UserID)
			{
				pUserList->m_work.clear();
				return true;
			}
			pUserList->m_MaxTargetNum += pUserData->TargetNumAdd;
			for (int i = 0; i < pUserList->m_MaxTargetNum; i++)
			{
				pUserList->targetlist[i] = TargetID;
			}
		}
		else if (is�ֻ�(sSkillID))
		{
			int maxnum = pUserList->m_MaxTargetNum;
			pUserList->m_MaxTargetNum = 0;
			for (int i = 0; i < maxnum; i++)
			{
//				pUserList->targetlist[pUserList->m_MaxTargetNum] = GetTargetID(UserID, TargetID, i);
				int id = pUserList->targetlist[pUserList->m_MaxTargetNum];
				if (id == UserID)continue;
				if (-1 == id)break;
				pUserList->m_MaxTargetNum += 1;
			}
		}

// 		switch (sSkillID)
// 		{
// 		case 1050:  //���컨��
// 		case 1095://����
// 		case 0://��ɨǧ��
// 		case 97://���꽣��
// 		case 141://����
// 		case 143:// ʨ��
// 		case 148://������
// 		case 1010://��
// 		case 2092://����һ��
// 		case 2094://�����ٻ�
// 		case 2098://�ƶ��б�
// 		case 2099://���ݻ���
// 		case 2100://���ŭ��
// 		case 3034://��Ѫ
// 		case 3035://����
// 		case 3040://����
// 		case 3042://��Ѫ2
// 		case 3043://����EX
// 		case 3044://��ѪEX
// 		{
// 			switch (sSkillID)
// 			{
// 			case 0:pUserList->m_MaxTargetNum = 4; break;  //��ɨǧ��
// 			case 97:pUserList->m_MaxTargetNum = 2; break;//���꽣��
// 			case 148:
// 
// 			{
// 				if (Skilllv < 30)pUserList->m_MaxTargetNum = 1;
// 				else
// 					if (Skilllv < 50)pUserList->m_MaxTargetNum = 2;
// 					else
// 						if (Skilllv < 70)pUserList->m_MaxTargetNum = 3;
// 						else
// 							if (Skilllv < 105)pUserList->m_MaxTargetNum = 4;
// 							else
// 								if (Skilllv < 140)pUserList->m_MaxTargetNum = 5;
// 								else
// 									pUserList->m_MaxTargetNum = 6;
// 			}
// 				break;
// 			case 3034:pUserList->m_MaxTargetNum = 2; break;//��Ѫ
// 			case 1050:  //���컨��
// 			case 1095://����
// 			case 1010://��
// 			case 2092://����һ��
// 			case 2094://�����ٻ�
// 			case 2098://�ƶ��б�
// 			case 2099://���ݻ���
// 			case 2100://���ŭ��
// 			case 3040://����
// 			case 3043://����EX
// 			case 3035:
// 				pUserList->m_MaxTargetNum = 1; break;//����	
// 			case 3042:pUserList->m_MaxTargetNum = 3; break;//��Ѫ2
// 			case 3044:pUserList->m_MaxTargetNum = 4; break;//��ѪEX
// 			default:pUserList->m_MaxTargetNum = 1;
// 				break;
// 			}
// 			if (TargetID == UserID)
// 			{
// 				pUserList->m_work.clear();
// 				return true;
// 			}
// 			pUserList->m_MaxTargetNum += pUserData->TargetNumAdd;
// 			for (int i = 0; i < pUserList->m_MaxTargetNum; i++)
// 			{
// 				pUserList->targetlist[i] = TargetID;
// 			}
// 		}
// 			break;
// 		case 1017://�Ƹ�
// 		case 142://ӥ��
// 		case 71://����ն
// 		case 98: // ���ʽ
// 		case 2096:
// 			//		case 2102:
// 		{
// 			int maxnum = 0;
// 			switch (sSkillID)
// 			{
// 			case 1017:
// 			case 2096:
// 				maxnum = 3;
// 				break;
// 				//			case 2102:
// 				//				maxnum = 2;
// 			case 142://ӥ��
// 
// 			{
// 				maxnum = Skilllv / 30 + 1;
// 				if (maxnum > 6)maxnum = 6;
// 			}
// 				break;
// 			case 71://����ն
// 			case 98:
// 			{
// 				// 				if (g_pMainState->m_AI.m_bPKMode || TargetID < 10)
// 				// 				{
// 				// 					maxnum = 1;
// 				// 				}
// 				// 				else
// 				{
// 					if (Skilllv > 59)maxnum = 3;
// 					else 	if (Skilllv > 29)maxnum = 2;
// 					else  	maxnum = 1;
// 				}
// 			}
// 				break;
// 			}
// 			maxnum += pUserData->TargetNumAdd;
// 			pUserList->m_MaxTargetNum = 0;
// 			for (int i = 0; i < maxnum; i++)
// 			{
// 				pUserList->targetlist[pUserList->m_MaxTargetNum] = GetTargetID(UserID, TargetID, i);
// 				int id = pUserList->targetlist[pUserList->m_MaxTargetNum];
// 				if (id == UserID)continue;
// 				if (-1 == id)break;
// 				pUserList->m_MaxTargetNum += 1;
// 			}
// 
// 		}
// 			break;
// 		default:
// 			ERRBOX;
// 			break;
// 		}

	}
		pUserList->m_NowTargetIdx = -1;
		if (!pUserList->NextTarget(m_pFightState, sSkillID)) // �Ҳ���Ŀ�꣬����
			stage = 7;
		else
			stage = 1;
		return true;
	case 1:
		if (pUserList->m_NowTargetIdx != -1)
		{

			if (pUserList->m_NowTargetIdx == 0)
			{
				// ����
				// ������һ����
				pUserList->targetID = pUserList->targetlist[pUserList->m_NowTargetIdx];
				pUserList->m_pObj->SetMagicSound(sSkillID);
			}
			else
			{
				if (pUserList->targetlist[0] != pUserList->targetlist[1])
				{
					// ����ÿ�ζ���
					pUserList->targetID = pUserList->targetlist[pUserList->m_NowTargetIdx];
					pUserList->m_pObj->SetMagicSound(sSkillID);
				}
			}
			stage = 22; // �ж��ƶ�
		}
		else stage = 7; // û��Ŀ���ˣ���������
		return true;
	case 22:

	{
		const sFightPoint* pOffse = g_pMainState->m_FightWorkList[UserID].GetFightPoint();
		if (pOffse->m_xOff > 0)
		{
			if (pUserList->m_NowTargetIdx > 0)
			{
				if (pUserList->m_NowTargetID == pUserList->targetlist[pUserList->m_NowTargetIdx - 1])
				{
					stage = 23;//Ŀ����ͬ�����ƶ�
					return true;
				}
			}
			stage = 2; // �ƶ�
		}
		else
		{
			stage = 23; // �������
		}
	}
		return true;
	case 2:
		// ӥ��
		if (sSkillID == 142) 
		{
			if (m_pFightState->Approach(UserID, pUserList->m_NowTargetID, false, 30))
			{
				stage = 23;
			}
		}
		else
		{
			if (m_pFightState->Approach(UserID, pUserList->m_NowTargetID))
			{
				stage = 23;
			}
		}
		return true;
	case 23:

	{
		m_pFightState->m_pFightWorkList[pUserList->m_NowTargetID]->m_pObj->GetPropertyData(pTargetData);
		//�������
		CheckHit(pUserData, pTargetData, 200);
		pUserList->m_pObj->Set(POS_FIGHT_STAND);
		CountParry(pUserData, pTargetData);//��
		CountCri(pUserData, pTargetData);//��ɱ

		auto& gs = pTargetData->m_FightData.m_guardID;
		forr(gs, i)
		{
			auto& list = g_pMainState->m_FightWorkList[gs[i]];
			if (!list.isExist || list.CheckDie())
			{
				gs.erase(gs.begin() + i);
			}
		}
		//������˱���,�ȴ������߾�λ
		if (pTargetData->m_FightData.m_guardID.size())
		{
			pTarget->m_MagicWav.LoadWav(0x4ADFB0ED);
			stage = 101;
			return true;
		}
		stage = 20;
	}
		return true;
	case 20: return StageWaitSleep(10, UserID, 3);// �ȴ�
	case 3:

	{
		int pos;
		if (rand() % 100 < 50)
			pos = POS_ATTACK2;
		else
			pos = POS_ATTACK;
		pUserList->m_pObj->Set(pos);
		pUserList->m_pObj->SetSound(pos);
		stage = 120;
	}
	case 120:
	{
		int atkp = m_pFightState->WorkAttack(UserID); // �Ƿ񵽹�����
		switch (atkp)
		{
		case 0:return true;
		default:
		{
			//�ǲ��ǹ���
			const sFightPoint* pOffse = g_pMainState->m_FightWorkList[UserID].GetFightPoint();
			if (pOffse->m_xOff == 0)
			{
				m_pFightState->m_HiddenWeapons.Load(0xE2BC8127);
				m_pFightState->m_HiddenWeaponsUseNum = 1;
				m_pFightState->m_HiddenWeaponsp[0].m_NeedShow = true;
				m_pFightState->m_HiddenWeaponsp[0].m_x = pUser->GetX();
				m_pFightState->m_HiddenWeaponsp[0].m_y = pUser->GetY() + 20;
				m_pFightState->m_HiddenWeaponsTargetID[0] = pUserList->m_NowTargetID;
				stage = 24;
				return true;
			}
			if (!PhysicalAtkHitStage(UserID, pUserList->m_NowTargetID, sSkillID)) // �����㶯��
			{
				stage = 4;
				return true;
			}
			if (atkp != 1)
			{
				stage = 4;
			}
		}
			break;
		}
	}
		return true;
	case 24://����

	{
		if (m_pFightState->WaitPosEnd(UserID))
		{
			pUser->Set(POS_FIGHT_STAND);
		}
		if (m_pFightState->HiddenWeaponsMove(0, 50))
		{
			PhysicalAtkHitStage(UserID, pUserList->m_NowTargetID, sSkillID);

			stage = 4;
		}
	}
		return true;
	case 4:  //�����ж�
	{
		if (m_pFightState->WaitPosEnd(UserID))
		{
			pUser->Set(POS_FIGHT_STAND);
		}
		stage = 5;//����÷���effectskill֮ǰ,��Ϊ�����������,stage����ʧЧ
		cPropertyData* pPet;
		g_pMainState->m_FightWorkList[pUserList->m_NowTargetID].m_pObj->GetPropertyData(pPet);
		if (pPet->m_FightData.m_bHit)
			EffectSkill(Skilllv, sSkillID, UserID, pUserList->m_NowTargetID);

		g_pMainState->m_FightWorkList[pUserList->m_NowTargetID].m_pObj->GetPropertyData(pTargetData);
		if (pTargetData->m_HP < 1)
		{
			pUserList->m_pObj->SetSpeed(15);
		}


		if (!pUserList->NextTarget(m_pFightState, sSkillID))
		{
//			int hpout;
//			Cost(hpout, Skilllv, sSkillID, UserID, pUserList->m_MaxTargetNum, true);
			Cost(UserID, sSkillID, pUserList->m_MaxTargetNum, true);
			switch (sSkillID)
			{
			case 142://ӥ��	
			{
				sBuff buf;
				buf.remainingTimes = 1;
				SetDateBuffUp(UserID, UserID, sSkillID, buf);
			}
				break;
			case 148:
				pUser->ReMoveStateID(145);//ȡ������
				break;
			case 0: //��ɨ 
			case 1017:
			{
				sBuff buf;
				buf.remainingTimes = 1;
				SetDateBuffUp(UserID, UserID, 0, buf);
			}
				break;
			case 167:
			case 170:
				++pUserData->m_FightData.zhanyi;
				break;
			}
		}
	}
		return  true;
	case 5:
		if (m_pFightState->WaitPosEnd(UserID) || pUser->m_NowPos == POS_FIGHT_STAND)
		{

			if (pUserList->m_NowTargetID == -1)
			{
				pUserList->m_pObj->Set(POS_FIGHT_STAND);
				stage = 7;
				return true;
			}
			if (sSkillID == 142)//ӥ��Ҫ�ܻ�ȥ
				stage = 8;
			else
				stage = 1;

		}
		return true;
	case 7:
	{
//		return StageWaitReturn(UserID, -1); //��������
		if (m_pFightState->ReturnApproach(UserID))
		{
			m_pFightState->m_pFightWorkList[UserID]->m_work.pop_back();

			cbCounter(UserID);

		}
		return true;
	}
	case 8:
	{
//		return StageWaitReturn(UserID, 1); // �ȴ�����
		// ӥ��
		if (sSkillID == 142)
		{
			if (m_pFightState->ReturnApproach(UserID, 30))
			{
				m_pFightState->m_pFightWorkList[UserID]->GetWork()->stage = 1;
			}
		}
		else
		{
			if (m_pFightState->ReturnApproach(UserID))
			{
				m_pFightState->m_pFightWorkList[UserID]->GetWork()->stage = 1;
			}
		}
		return true;
	}
	case 101:  return StageWaitProtect(UserID, pUserList->m_NowTargetID, 3);
	}
	return true;
}

