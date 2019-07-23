
// void cAI::SetTarget(int target)
// {
// 	if (m_TargetID == target)return;
// 	m_TargetID = target;
// 	if (target < 0)
// 	{
// 		m_pTarget = nullptr;
// 		m_pTargetPc = nullptr;
// 		m_pTargetData = nullptr;
// 		return;
// 	}
// 	if (!g_pMainState->m_FightWorkList[target].isExist)
// 	{
// 		m_TargetID = -1;
// 		m_pTarget = nullptr;
// 		m_pTargetPc = nullptr;
// 		m_pTargetData = nullptr;
// 		return;
// 	}
// 	m_pTargetList = &g_pMainState->m_FightWorkList[m_TargetID];
// 	m_pTarget = g_pMainState->m_FightWorkList[m_TargetID].m_pObj;
// 	if (m_pTarget->m_IndexType == INDEXTYEP_CHARACTER)
// 		m_pTargetPc = (cCharacter*)m_pTarget->m_pIndex;
// 	else
// 		m_pTargetPc = 0;
// 	m_pTarget->GetPropertyData(m_pTargetData);
// 	if (0 == m_pTargetData)
// 	{
// 		ERRBOX(target);
// 	}
// }

// 
// bool cAI::UseItem(eAIUseItemType mode)
// {
// 	if (m_TargetID == -1)return false;
// 	int ItemOwnerID = m_UserID;
// 	if (g_pMainState->m_FightWorkList[ItemOwnerID].m_pObj->m_IndexType == INDEXTYEP_PET)
// 	{
// 		if ((m_UserID % 10) >= 5)
// 			ItemOwnerID = m_UserID - 5;
// 		if (g_pMainState->m_FightWorkList[ItemOwnerID].m_pObj->m_IndexType == INDEXTYEP_PET)
// 		{
// 			return false;
// 		}
// 	}
// 	cCharacter* pc = (cCharacter*)g_pMainState->m_FightWorkList[ItemOwnerID].m_pObj->m_pIndex;
// 	if (!pc)
// 	{
// 		return false;
// 	}
// 	sFightWork& list = g_pMainState->m_FightWorkList[m_UserID];
// 	if (pc->m_PcData.m_Items[mode].GetNum() < 2)
// 		return false;
// 	list.m_ItemSelectID = mode;
// 	list.m_SkillSelect.SkillID = 1003;
// 	if (mode == eAIUseItemType����)
// 		list.m_SkillSelect.SkillID = 1005;
// 	list.m_SkillSelect.SkillLv = 0;
// 	list.m_SkillSelect.TargetID = m_TargetID;
// 	list.m_WorkType = WORKTYPE_MAGIC;
// 
// 
// 	int start, end;
// 	if (m_TargetID < 10)start = 0;
// 	else start = 10;
// 	end = start + 10;
// 	switch (mode)
// 	{
// 	case eAIUseItemTypeHP:
// 		m_bNeedAddHp[m_TargetID] -= 50;
// 		break;
// 	case eAIUseItemTypeHPALL:
// 		if (1)
// 		{
// 			for (int i = start; i < end;i++)
// 				m_bNeedAddHp[m_TargetID] -= 30;
// 		}
// 		break;
// 	case eAIUseItemTypeMP:
// 		m_bNeedAddMp[m_TargetID] = 0;
// 		break;
// 	case eAIUseItemTypeMPALL:
// 		if (1)
// 		{
// 			for (int i = start; i < end; i++)
// 				m_bNeedAddMp[m_TargetID] = 0;
// 		}
// 		break;
// 	case eAIUseItemTypelive:
// 		m_bNeedlive[m_TargetID] = 0;
// 		break;
// 	case eAIUseItemTypeUnseal:
// 		m_bNeedUnSeal[m_TargetID] = 0;
// 		break;
// 	case eAIUseItemType����:
// 		m_bAtk[m_TargetID] += 20;
// 		break;
// 	}
// 	return true;
// 	
// 	
// }
// 
//
// 
// 
// int cAI::FindDieFight(int start /*= 0*/, int end /*= 5*/)
// {
// 
// 
// 	for (int i = start; i < end; i++)
// 	{
// 		if (g_pMainState->m_FightList[i].isExist)
// 		if (g_pMainState->m_FightList[i].CheckDie())
// 		{
// 			return i;
// 		}
// 	}
// 	return -1;
// }
// 
// 
// 
// int cAI::getVisibleNO(int userID, bool our, bool isCheckPeopleSpecial)
// {
// 	int star;
// 	if (our && userID < 10 || (!our && userID >= 10))
// 	{
// 		star = 0;
// 	}
// 	else
// 	{
// 		star = 10;
// 	}
// 	int num = 0;
// 	for (int i = star; i < star + 10; ++i)
// 	{
// 
// 		if (See(userID, i, isCheckPeopleSpecial))
// 		{
// 			++num;
// 		}
// 		if (g_pMainState->m_FightWorkList[i].isExist && !g_pMainState->m_FightWorkList[i].CheckDie())
// 		{
// 			cPropertyData *data = nullptr;
// 			g_pMainState->m_FightWorkList[userID].m_pObj->GetPropertyData(data);
// 			cPropertyData *data2 = nullptr;
// 			g_pMainState->m_FightWorkList[i].m_pObj->GetPropertyData(data2);
// 			if (data && data->Hide.d1 < data2->Hide.d2)
// 			if ((data2->Hide.d1 == 0) || (data->Hide.d2 > 0) || !(isCheckPeopleSpecial && data->Hide.d2 == 0 && data2->Hide.d1 > 0))
// 			{
// 				++num;
// 				continue;
// 			}
// 			
// 		}
// 	}
// 	return num;
// }


// bool cAI::isPutRate()
// {
// 	if (isAtkMode())
// 	{
// 		return (isCanAtk() && isPut() && rand() % 100 < 15) || !isCanMag();
// 	}
// 	return isCanAtk() && isPut() && !isCanMag();
// }
// 
// bool cAI::selectAtk()
// {
// 	if (!isCanAtk())
// 	{
// 		return false;
// 	}
// 	if (m_TargetID < 0)
// 	{
// 		SetTarget(findTarget(100, true, m_UserID));
// 	}
// 	if (m_TargetID >= 0)
// 	{
// 		NormalAtk();
// 		return true;
// 	}
// 	return false;
// }
// 
// 



// 
// void cAI::ResetNeed()
// {
// 	for (int i = 0; i < 20; i++)
// 	{
// 		m_bNeedUnSeal[i] = 0;
// 		m_bNeedAddHp[i] = 0;
// 		m_bNeedAddMp[i] = 0;
// 		m_bNeedlive[i] = 0;
// 		m_bNeedAddHpHurt[i] = 0;
// 	}
// }
//
// ����+2
// bool cAI::SaveOneself(int start,int end)
// {
// 	for (int i = start; i < end; i++)
// 	{
// 		if (i == g_pMainState->m_HeroID)continue;
// 		SaveOneself2(i);
// 	}
// 	return false;
// }
// void cAI::SaveOneself2(int i)
// {
// 	if (!g_pMainState->m_FightWorkList[i].isExist)return;
// 	if (g_pMainState->m_FightWorkList[i].CheckDie())return;
// 	if (g_pMainState->m_FightWorkList[i].m_WorkType != -1)return;
// 	SetUser(i);
// 	SetTarget(i);
// 	if (m_pUserPc)
// 		if (!m_pUserData->m_FightData.cannotSpesialSkill)
// 		{
// 		//		if (m_pUserPetData->m_StrongLv > 90 - 50)
// 			{
// 				if (m_bNeedAddHp[i] > 0 || m_bNeedAddHpHurt[i] > 0)
// 				{
// 					if (Cost(3006))
// 					{
// 						m_bNeedAddHp[i] = false;
// 						m_bNeedAddHpHurt[i] = false;
// 						return UseSkill(3006);//����
// 					}
// 				}
// 				if (m_bNeedAddMp[i])
// 				{
// 					if (Cost(3004))
// 					{
// 						m_bNeedAddMp[i] = false;
// 						return UseSkill(3004);//�����  
// 					}
// 				}
// 			}
// 		//		else
// 		//		if (m_pUserPetData->m_StrongLv > 50)
// 		{
// 			if (m_bNeedAddHp[i] || m_bNeedAddHpHurt[i])
// 			{
// 				if (Cost(3005))
// 				{
// 					m_bNeedAddHp[i] = false;
// 					m_bNeedAddHpHurt[i] = false;
// 					return UseSkill(3005);//����
// 
// 				}
// 			}
// 			if (m_bNeedAddMp[i])
// 			{
// 				if (Cost(3003))
// 				{
// 					m_bNeedAddMp[i] = false;
// 					return UseSkill(3003);//������
// 				}
// 			}
// 		}
// 		}
// 	if (m_pUserData->m_FightData.cannotUseItem)return;
// 	if (m_bNeedAddHpHurt[i])
// 	{
// 		if (CheckItem(eAIUseItemTypeHPHurt))
// 		{
// 			UseItem(eAIUseItemTypeHPHurt);
// 		}
// 		return;
// 	}
// 	if (m_bNeedAddHp[i])
// 	{
// 		if (CheckItem(eAIUseItemTypeHP))
// 		{
// 			UseItem(eAIUseItemTypeHP);
// 		}
// 		return;
// 	}
// 	if (m_bNeedUnSeal[i])
// 	{
// 		if (CheckItem(eAIUseItemTypeUnseal))
// 			UseItem(eAIUseItemTypeUnseal);//���
// 		return;
// 	}
// 	if (m_bNeedAddMp[i])
// 	{
// 		if (CheckItem(eAIUseItemTypeMP))
// 			UseItem(eAIUseItemTypeMP);
// 		return;
// 	}
// }
// 
// 
// void cAI::GetNeed(int start, int end)
// {
// 	for (int i = start; i < end; i++)
// 	{
// 		if (!g_pMainState->m_FightWorkList[i].isExist)continue;
// 		SetUser(i);
// 		//����
// 		if (m_pUserData->m_HP == 0)
// 		{
// 			if (!m_pUserData->m_FightData.cannotLive)
// 			{
// 				m_bNeedlive[i] = true;
// 			}
// 		}
// 		int limit = m_pUserPc ? m_HPLimit : m_HPLimit / 2 + 50;
// 		//Ѫ����
// 		if (m_pUserData->m_HP < (m_pUserData->HPMax.GetData() * limit) / 100)
// 		{
// 			//Ѫ��,Խ��Ҫ��Ѫ
// 			int k = (m_pUserData->m_HP * 100) / m_pUserData->HPMax.GetData() + 1;
// 			k = k * limit / m_HPLimit;
// 			k = 100 - k;
// 			if (m_pUserData->m_HP2 < m_pUserData->HPMax.GetData())
// 
// 				m_bNeedAddHpHurt[i] = true;
// 
// 			m_bNeedAddHp[i] = k;
// 	
// 			if (m_pUserPc && m_pUserData->m_FightData.cannotAddHP)//����Ҳ���
// 			{
// 				m_bNeedUnSeal[i] = true;
// 			}
// 		}
// 
// 		m_bNeedAddMp[i] = true;
// 		vector<int> ms, m2s, ps, bs;
// 		isHadPetSkill(m_pUserData, bs, ps, ms, m2s);
// 		if (m_pUserData->LiveMp || (!m_pUserPc && !bs.size() && !ps.size() && !ms.size() && !m2s.size()))
// 		{
// 			m_bNeedAddMp[i] = false;
// 		}
// 		else if (m_pUserData->m_MP >= m_pUserData->m_Lv + 10 ||
// 			m_pUserData->m_MP >= m_pUserData->MPMax.GetData() - 30)
// 		{
// 			m_bNeedAddMp[i] = false;
// 		}
// 		else if (m_pUserPc && !m_pUserPc->m_PcData.m_MengPaiID)
// 		{
// // 			m_bNeedAddMp[i] = (m_pUserPetData->m_MP * 100) / m_pUserPetData->m_MPMax.GetData();
// // 			m_bNeedAddMp[i] = 100 - m_bNeedAddMp[i];
// 			m_bNeedAddMp[i] = false;
// 		}
// 		if (m_pUser->CheckHaveState(6))	
// 		{
// 			//���˷���
// 			m_bNeedUnSeal[i] = true;
// 		}
// 		if (m_pUserData->m_FightData.cannotMagic)//����ʹ��ħ��
// 		{
// 			if (!m_pUser->m_StateList.size())
// 			{
// 				continue;
// 			}
// 			if (m_pUser->m_StateList.back().remainingTimes < 3)
// 			{
// 				continue;//3�غ����µ�BUFF���ù�
// 			}
// 			if (i % 10 > 4)
// 			{
// 				if (m_pUserData->PointBody >= m_pUserData->m_Lv * 3)
// 				{
// 					continue;//Ѫ�費�þ�
// 				}
// 				if (m_pUserData->PointStr > m_pUserData->m_Lv)
// 				{
// 					continue;//����ⷨ��Ҫ��
// 				}
// 			}
// 			m_bNeedUnSeal[i] = true;
// 		}
// 		
// 		if (m_pUserData->m_FightData.cannotAttack)//���ܹ���
// 		{
// 			if (!m_pUser->m_StateList.size())
// 			{
// 				continue;
// 			}
// 			if (m_pUser->m_StateList.back().remainingTimes < 3)
// 			{
// 				continue;//3�غ����µ�BUFF���ù�
// 			}
// 			if (!m_pUserPc)
// 			{
// 				if (m_pUserData->PointStr > m_pUserData->m_Lv)
// 				{
// 					if (!ps.size())
// 					{
// 						m_bNeedUnSeal[i] = true;
// 					}					
// 				}
// 			}
// 		}
// 		if (m_pUserData->m_FightData.cannotSpesialSkill)//����
// 		{
// 			if (m_pUserPc && m_pUserData->m_CP > 80)
// 			{
// 				m_bNeedUnSeal[i] = true;
// 			}
// 		}
// 
// 		if (m_pUserData->Hide.d1 || 
// 			m_pUserData->LiveRestoreRate ||
// 			m_pUser->CheckHaveState(0) ||
// 			m_pUser->CheckHaveState(7) ||
// 			m_pUser->CheckHaveState(142))
// 		{
// 			m_bNeedUnSeal[i] = false;
// 		}
// 
// // 		if (m_bNeedlive[i])
// // 		{
// // 			m_bNeedUnSeal[i] = false;
// // 			m_bNeedAddHp[i] = false;
// // 			m_bNeedAddHpHurt[i] = false;
// // 			m_bNeedAddMp[i] = false;
// // 		}
// 	}
// }




















// ����
// void cAI::PreRun(int start, int end)
// {
// 	//CoutIdleList(start,end);
// 	GetNeed(start, end);
// 	ContentLive(start,end);
// 	ContentHP(start, end);
// 	ContentUnSeal(start, end);
// 	SaveOneself(start, end);
// }

// void cAI::AutoRunEnemyAi(int i)
// {
// 	vector<POINT> tlist;
// 	SetUser(i);
// 	if (m_pUserData->m_FightData.cannotAll)return;
// 	if (m_FightTarget[i] > -1)
// 	{
// 		SetTarget(m_FightTarget[i]);
// 	}
// 	else
// 		SetTarget(g_pMainState->m_AI.find׷�������¹�(i, 4, true));
// 	
// //	int ailv = m_pUserPetData->m_AiLv;
// 	if (m_pUserData->m_FightData.cannotMagic)//���ⷨ��ʱ������
// 	{
// 		return NormalAtk();
// 	}
// 	if (!m_pUserPc)//�ٻ���
// 	{
// 		vector<int> skilllist;
// 		//Ѱ���ٻ��޵���������
// 		for (int j = 0; j < m_pUserData->m_NumofBBSkill; j++)
// 		{
// 			if (m_pUserData->m_petSkills[j]->m_SkillType == 4)
// 			{
// 				skilllist.push_back(m_pUserData->m_petSkills[j]->m_Id);
// 			}
// 		}
// 		if (skilllist.size())
// 		{//�����
// 			int skilluse = 2000 + skilllist[rand() % skilllist.size()];
// 			if (Cost(skilluse))
// 				return UseSkill(skilluse);
// 		}
// 		return	NormalAtk();
// 	}
// 	eMengPai emngpaiid = (eMengPai)m_pUserPc->m_PcData.m_MengPaiID;
// 	if (m_pUserData->m_FightData.cannotMagic)
// 	{
// 		switch (emngpaiid)
// 		{
// 		case eMP_Ů����:
// 			if (!m_pUserData->m_FightData.cannotUseItem)
// 			 UseItem(eAIUseItemType����);
// 			else NormalAtk();
// 			return;
// 		default:
// 			NormalAtk();
// 			return;
// 		}
// 	}
// 	switch (emngpaiid)
// 	{
// 	case eMP_���ƹٸ�:
// 			switch (rand() % 7)
// 			{
// 			case 0:return NormalAtk();
// 			case 1:
// 				if (m_pUserData->m_HP<5000)
// 				{
// 					if (m_pUserData->m_Lv > 129)
// 					{
// 						return NpcTryMagic(7);
// 					}
// 				}
// 				if (m_pUserData->m_FightData.cannotAttack)return NpcTryMagic(0);
// 				return NormalAtk();
// 				break;
// 			case 2:return NpcTryMagic(1);
// 			case 3:
// 				if (!CheckHaveState(i, 4))
// 				{
// 					if (Cost(4))
// 					{
// 						SetTarget(i);
// 						return UseSkill(4);
// 					}
// 					else
// 						return NormalAtk();
// 				}
// 				else
// 				{
// 					if (m_pUserData->m_FightData.cannotAttack)return NpcTryMagic(0);
// 					return NormalAtk();
// 				}
// 			case 4:return NpcTryMagic(6);
// 			default:return NpcTryMagic(0);
// 			}
// 			break;
// 	case eMP_����ɽ:
// 		switch (rand() % 4)
// 		{
// 		case 0:
// 			if (m_pUserData->m_FightData.cannotAttack)
// 			{
// 				return NpcTryMagic(11);
// 			}
// 			else
// 			return NormalAtk();
// 		case 1:
// 			if (1)
// 			{
// 				int start, end;
// 				if (m_UserID < 10)start = 10;
// 				else start = 0;
// 				end = start + 10;
// 				int target2 = FindδSeal(start, end);
// 				if (target2 == -1)return NormalAtk();
// 				SetTarget(target2);
// 				m_bSeal[m_TargetID] = true;
// 				switch (rand() % 5)
// 				{
// 				case 1:return NpcTryMagic(14);
// 				case 2:return NpcTryMagic(15);
// 				case 3:return NpcTryMagic(19);
// 				case 4:return NpcTryMagic(20);
// 				default:return NpcTryMagic(21);
// 				}
// 			}
// 		default:return NpcTryMagic(11);
// 		}
// 		break;
// 	case eMP_������:
// 			switch (rand() % 7)
// 			{
// 			case 0:
// 				return UseSkill(31);
// 			case 1:
// 				if (m_pUserData->m_FightData.cannotAttack)
// 				{
// 					return NpcTryMagic(40);
// 				}
// 				else
// 				return NormalAtk();
// 			case 2:
// 				if (1)
// 				{
// 					SetTarget(g_pMainState->m_AI.find׷�������¹�(m_UserID, 3, true));
// 					switch (rand() % 5)
// 					{
// 					case 0: return NpcTryMagic(42);
// 					case 1:return NpcTryMagic(33);
// 					case 2: return NpcTryMagic(35);
// 					case 3: return NpcTryMagic(39);
// 					case 4: return NpcTryMagic(40);
// 					}
// 				}
// 				break;
// 			default:
// 				SetTarget(g_pMainState->m_AI.find׷�������¹�(m_UserID, 3, true));
// 				if (rand() % 2)return NpcTryMagic(40);
// 				else  return NpcTryMagic(42);
// 			}
// 			break;
// 	case eMP_Ů����:
// 			switch (rand() % 4)
// 			{
// 			case 0:
// 				if (m_pUserData->m_FightData.cannotAttack)
// 				{
// 					 UseItem(eAIUseItemType����);
// 					 return;
// 				}
// 				else
// 				return NormalAtk();
// 			case 1:
// 				if (1)
// 				{
// 					int start, end;
// 					if (m_UserID < 10)start = 10;
// 					else start = 0;
// 					end = start + 10;
// 					int target2 = FindδSeal(start, end);
// 					if (target2 == -1)return NormalAtk();
// 					SetTarget(target2);
// 					m_bSeal[m_TargetID] = true;
// 					if (m_pUserData->m_Lv > 129)return NpcTryMagic(54);
// 					return NpcTryMagic(54);
// 				}
// 			default:
// 				UseItem(eAIUseItemType����);
// 				return;
// 			
// 			}
// 		break;
// 	case eMP_�칬:
// 			switch (rand() % 10)
// 			{
// 			case 1:
// 			case 2:
// 				if (1)
// 				{
// 					int start, end;
// 					if (m_UserID < 10)start = 10;
// 					else start = 0;
// 					end = start + 10;
// 					int target2 = FindδSeal(start, end);
// 					if (target2 == -1)return NormalAtk();
// 					SetTarget(target2);
// 					m_bSeal[m_TargetID] = true;
// 					if (rand() % 2)
// 					{
// 						return NpcTryMagic(68);
// 					}
// 					else return NpcTryMagic(69);
// 				}
// 				return;
// 			case 3:
// 				if (m_pUserData->m_FightData.cannotAttack)
// 				{
// 					return NpcTryMagic(71);
// 				}
// 				else
// 				return NormalAtk();
// 			case 4:return NpcTryMagic(72); 
// 			case 5: 
// 				if (m_pUserData->m_Lv > 129)return NpcTryMagic(74);
// 			default:return NpcTryMagic(71);
// 			}
// 		break;
// 	case eMP_��������:
// 			switch (rand()%7)
// 			{
// 			case 0:return NpcTryMagic(84);
// 			case 1:return NpcTryMagic(79);
// 			case 2:
// 				if (m_pUserData->m_Lv > 129)return NpcTryMagic(88);
// 				else 
// 				if (m_pUserData->m_FightData.cannotAttack)
// 				{
// 					return NpcTryMagic(80);
// 				}
// 				else
// 					return NormalAtk();
// 			case 3:
// 				if (!CheckHaveState(m_UserID,147))
// 				{
// 					if (Cost(147))
// 					{
// 						SetTarget(m_UserID);
// 						return UseSkill(147);
// 					}
// 				}
// 				return NpcTryMagic(80);
// 			default:return NpcTryMagic(80);
// 			}
// 		break;
// 	case eMP_��ׯ��:
// 			switch (rand() % 7)
// 			{
// 			case 0: 
// 				if (m_pUserData->m_FightData.cannotAttack)
// 				{
// 					return NpcTryMagic(97);
// 				}
// 				else
// 				return NormalAtk();
// 			case 2: 
// 				if (1)
// 				{
// 					int start, end;
// 					if (m_UserID < 10)start = 11;
// 					else start = 1;
// 					end = start + 9;
// 					if (m_bPKMode)//�չ�Ǭ���ڷ�PKʱ�޷�������
// 					{
// 						start -= 1;
// 						end -= 5;
// 					}
// 					int target2 = FindδSeal(start, end);
// 					if (target2 == -1)return NormalAtk();
// 					SetTarget(target2);
// 					m_bSeal[m_TargetID] = true;
// 					return NpcTryMagic(89);
// 				}
// 			case 3: 
// 					SetTarget(g_pMainState->m_AI.find׷�������¹�(m_UserID, 3, true));
// 					return NpcTryMagic(91);
// 			default: 
// 				return NpcTryMagic(97);
// 			}
// 		break;
// 	case eMP_����ɽ:
// 		if (rand() % 3)
// 		{
// 			return NpcTryMagic(105 + rand() % 5);
// 		}
// 		else
// 		{
// 			int targetid = g_pMainState->m_AI.find׷�������¹�(m_UserID, 3, true);
// 			switch (rand() % 5)
// 			{
// 			case 0: 
// 				if (Cost(113))
// 				{//�ߵ�����
// 					SetTarget(targetid);
// 					if (m_pTarget->CheckHaveState(113))
// 					{
// 						SetTarget(g_pMainState->m_AI.find׷�������¹�(i, 4, true));
// 						return NpcTryMagic(105 + rand() % 5);
// 					}
// 					return  NpcTryMagic(113);
// 				}
// 				return NpcTryMagic(105 + rand() % 5);
// 			case 1:
// 				if (Cost(102))//�ն�
// 				{
// 					SetTarget(g_pMainState->m_AI.find׷�������¹�(m_UserID, 3, true));
// 					if (tlist.size())
// 					{
// 						SetTarget(tlist[0].x);
// 						return NpcTryMagic(102);
// 					}
// 				}
// 				SetTarget(g_pMainState->m_AI.find׷�������¹�(i, 4, true));
// 				return NpcTryMagic(105 + rand() % 5);
// 			case 2: 
// 				if (Cost(103))
// 				return UseSkill(103);
// 				return NormalAtk();
// 			case 3: 
// 				if (Cost(112))
// 				{
// 					SetTarget(targetid);
// 					return UseSkill(112);
// 				}
// 				return NpcTryMagic(105 + rand() % 5);
// 			case 4:
// 				if (m_pUserData->m_FightData.cannotAttack)
// 				{
// 					return NpcTryMagic(105 + rand() % 5);
// 				}
// 				else
// 				return NormalAtk();
// 			}
// 		}
// 		break;
// 	case eMP_���ܵظ�:
// 		if (1)
// 		{
// 			
// 			switch (rand() % 6)
// 			{
// 			case 0: 
// 				if (m_pUserData->m_FightData.cannotAttack)
// 				{
// 					return NpcTryMagic(117);
// 				}
// 				else
// 				return NormalAtk();
// 			case 1:return NpcTryMagic(117);
// 			case 3: return NpcTryMagic(122);
// 			case 4: 
// 				if (Cost(123))
// 				{
// 					SetTarget(g_pMainState->m_AI.find׷�������¹�(m_UserID, 3, true));
// 					return NpcTryMagic(123);
// 				}
// 				else return NpcTryMagic(116);
// 			default: return NpcTryMagic(116);
// 			}
// 		}
// 		break;
// 	case eMP_ħ��կ:
// 		if (1)
// 		{
// 			switch (rand() % 6)
// 			{
// 			case 0: 
// 				if (m_pUserData->m_FightData.cannotAttack)
// 				{
// 					return NpcTryMagic(131);
// 				}
// 				else
// 				return NormalAtk();
// 			case 1:return NpcTryMagic(132);
// 			case 2:
// 				if (!m_pUser->CheckHaveState(133))
// 				{
// 					if (Cost(133))
// 					{
// 						SetTarget(m_UserID);
// 						return NpcTryMagic(133);
// 					}
// 				}
// 				return NpcTryMagic(131);
// 			default:  return NpcTryMagic(131);
// 			}
// 		}
// 		break;
// 	case eMP_ʨ����:
// 		if (1)
// 		{
// 			if (m_pUser->CheckHaveState(145))
// 			{
// 				switch (rand() % 5)
// 				{
// 				case 0:return NpcTryMagic(143);
// 				case 1:return NpcTryMagic(148);
// 				case 2:return NpcTryMagic(141);
// 				default: return NpcTryMagic(142);
// 				}
// 			}
// 			else
// 			{
// 				switch (rand() % 3)
// 				{
// 				case 0:
// 					if (m_pUserData->m_FightData.cannotAttack)
// 					{
// 						SetTarget(m_UserID);
// 						return NpcTryMagic(145);
// 					}
// 					else
// 					return NormalAtk();
// 				default:
// 					SetTarget(m_UserID);
// 					return NpcTryMagic(145);
// 				}
// 			}
// 		}
// 		break;
// 	case eMP_��˿��:
// 		switch (rand() % 6)
// 		{
// 		case 0:
// 			if(rand()%2)
// 			return NpcTryMagic(154);
// 			return NpcTryMagic(155);
// 		case 1:return NpcTryMagic(156);
// 		case 2:
// 			if (1)
// 			{
// 				int start, end;
// 				if (m_UserID < 10)start = 10;
// 				else start = 0;
// 				end = start + 10;
// 				int target2 = FindδSeal(start, end);
// 				if (target2 == -1)return NormalAtk();
// 				SetTarget(target2);
// 				m_bSeal[m_TargetID] = true;
// 				return NpcTryMagic(159);
// 			}
// 		case 3:
// 			if (!CheckHaveState(m_UserID, 160))
// 			{
// 				if (Cost(160))
// 				{
// 					SetTarget(m_UserID);
// 					return UseSkill(160);
// 				}
// 				
// 			}
// 			if (m_pUserData->m_FightData.cannotAttack)
// 			{
// 				return NpcTryMagic(162);
// 			}
// 			else
// 			return NormalAtk();
// 		case 4:return NpcTryMagic(164);
// 		default:return NpcTryMagic(162);
// 		}
// 		break;
// 	 default:
// 		 ERRBOX;
// 		break;
// 	}
// }
// 
// // ����+4
// void cAI::ContentHP(int start, int end)
// {
// 	
// 	for (int i = start; i < end; i++)
// 	{
// 		if (!m_bNeedlive[i])//ȷ��Ӧ�û���
// 		if (m_bNeedAddHp[i]>0 || m_bNeedAddHpHurt[i]>0)
// 		{
// 			SetTarget(i);
// 			ContentHP2(start, end);
// 			if (m_bNeedAddHp[i]<0)
// 			m_bNeedAddHp[i] = 0;
// 			if (m_bNeedAddHpHurt[i]<0)
// 			m_bNeedAddHpHurt[i] = 0;
// 		}
// 	}
// }
// void cAI::ContentHP2(int start, int end)
// {
// 	vector<int> list;
// 	int id2 = -1;
// 	int id;
// 	int firstpos = -1;
// 	for (int i = 19; i >-1; i--)
// 	{
// 		id = g_pMainState->m_pFightState->m_SpeedListPos[i];
// 		if (id < start || id >= end)continue;
// 		if (!g_pMainState->m_FightWorkList[id].isExist)continue;
// 		if (g_pMainState->m_FightWorkList[id].CheckDie())continue;
// 		if (g_pMainState->m_FightWorkList[id].m_WorkType != -1)continue;
// 
// 		if (-1 == id2)
// 		if (g_pMainState->m_FightWorkList[id].m_pObj->m_IndexType == INDEXTYEP_CHARACTER)
// 		{//
// 			cCharacter* pc = (cCharacter*)g_pMainState->m_FightWorkList[id].m_pObj->m_pIndex;
// 			if (!pc->m_PcData.m_FightData.cannotMagic)
// 			{
// 				switch (pc->m_PcData.m_MengPaiID)
// 				{
// 				case eMP_����ɽ:
// 				case eMP_������:
// 				case eMP_��ׯ��:
// 					id2 = id;
// 					firstpos = list.size();
// 					break;
// 				}
// 			}
// 		}
// 		cPropertyData* pPet;
// 		g_pMainState->m_FightWorkList[id].m_pObj->GetPropertyData(pPet);
// 		if (!pPet->m_FightData.cannotUseItem)
// 			list.push_back(id);
// 	}
// 	if (!list.size())return;
// 	if (-1 == id2)
// 	{
// 		id2 = list[0];
// 		firstpos = 0;
// 	}
// 	SetUser(id2);
// 	//bool bUse = false;
// 
// 		int num = 0;//��Ҫ���ƵĶ�����
// 		for (int i2 = start; i2 < end; i2++)
// 		if (m_bNeedAddHp[i2]>0 || m_bNeedAddHpHurt[i2]>0)
// 			num += 1;
// 		if (m_pUserPc)
// 		{
// 			eMengPai mengpai = (eMengPai)m_pUserPc->m_PcData.m_MengPaiID;
// 			switch (mengpai)
// 			{
// 			case eMP_������:
// 				if (1)
// 				{
// 					if (num == 1)
// 					{
// // 						switch (m_pUserPetData->m_StrongLv >> 5)
//  						{
// // 						case 3:
// 							if (Cost(39))
// 							{
// 								m_bNeedAddHpHurt[m_TargetID] = -20;
// 								m_bNeedAddHp[m_TargetID] = -20;
// 								return UseSkill(39);
// 							}
// 							else 
// //						case 2:
// 							if (Cost(3002))
// 							{
// 								m_bNeedAddHpHurt[m_TargetID] = -15;
// 								m_bNeedAddHp[m_TargetID] = -15;
// 								return UseSkill(3002);
// 							}
// //						case 1:
// 							else 
// 							if (Cost(3001))
// 							{
// 								m_bNeedAddHpHurt[m_TargetID] = -10;
// 								m_bNeedAddHp[m_TargetID] = -10;
// 								return UseSkill(3001);
// 							}
// // 							break;
//  						}
// 					}
// 					//����
// 					if (!m_pUserData->m_FightData.cannotMagic)
// 					{
// 						int skillid;
// 						if (num > 1)
// 						{
// 							if (m_bNeedAddHpHurt>0)skillid = 42;
// 							else skillid = 40;
// 						}
// 						else
// 						{
// 							
// 							if (m_bNeedAddHpHurt>0)skillid = 38;
// 							else
// 							{
// 								if (m_pUserData->m_Lv > 129)
// 									skillid = 45;
// 								else
// 									skillid = 39;
// 							}
// 
// 						}
// 						if (Cost(skillid))
// 						{
// 							m_bNeedAddHpHurt[m_TargetID] = -10;
// 							m_bNeedAddHp[m_TargetID] = -10;
// 							return UseSkill(skillid);
// 						}
// 					}
// 				}
// 				break;
// 			case eMP_���ܵظ�:
// 				if (num > 1) //�ĺ�
// 				{
// //					if (m_pUserPetData->m_StrongLv > 90)
// 					{
// 						if (Cost(7))
// 						{
// 							m_bNeedAddHpHurt[m_TargetID] = -20;
// 							m_bNeedAddHp[m_TargetID] = -20;
// 							return UseSkill(39);
// 						}
// 					}
// 				}
// 				break;
// 			case eMP_����ɽ:
// 				if (1)
// 				{
// 					if (num > 1) //�ĺ�
// 					{
// //						if (m_pUserPetData->m_StrongLv >90)
// 						{
// 							if (Cost(7))
// 							{
// 								m_bNeedAddHpHurt[m_TargetID] = -20;
// 								m_bNeedAddHp[m_TargetID] = -20;
// 								return UseSkill(39);
// 							}
// 						}
// 					}
// 					//����
// 					if (!m_pUserData->m_FightData.cannotMagic)
// 					{
// 						if (Cost(102))
// 						{
// 							m_bNeedAddHpHurt[m_TargetID] = -30;
// 							m_bNeedAddHp[m_TargetID] = -30;
// 							return UseSkill(102);
// 						}
// 					}
// 				}
// 				break;
// 			}
// 		}
// 		//����
// 
// 		if (m_bNeedAddHp[m_TargetID]>0)
// 		{
// 			if (num > 3)
// 			{
// 				if (CheckItem(eAIUseItemTypeHPALL))
// 				{
// 					for (int i2 = start; i2 < end;i2++)
// 						m_bNeedAddHp[i2] =0;
// 					  UseItem(eAIUseItemTypeHPALL);
// 					  return;
// 				}
// 			}
// 			if (CheckItem(eAIUseItemTypeHP))
// 			{
// 				m_bNeedAddHp[m_TargetID] = 0;
// 				  UseItem(eAIUseItemTypeHP);
// 				  return;
// 			}
// 		}
// 		if (CheckItem(eAIUseItemTypeHPHurt))
// 		{
// 			m_bNeedAddHpHurt[m_TargetID] = 0;
// 			  UseItem(eAIUseItemTypeHPHurt);
// 			  return;
// 		}
// 	
// }
// void cAI::ContentLive(int start, int end)
// {
// 	for (int i = start; i < end; i++)
// 	{
// 		if (m_bNeedlive[i])
// 		{
// 			SetTarget(i);
// 			ContentLive2(start, end);
// 		}
// 	}
// }
// void cAI::ContentLive2(int start, int end)
// {
// 	vector<int> list;
// 	int id2=-1;
// 	int id;
// 	int firstpos=-1;
// 	for (int i = 0; i < 20; i++)
// 	{
// 		id= g_pMainState->m_pFightState->m_SpeedListPos[i];
// 		if (id < start || id >= end)continue;
// 		if (!g_pMainState->m_FightWorkList[id].isExist)continue;
// 		if (g_pMainState->m_FightWorkList[id].CheckDie())continue;
// 		if (g_pMainState->m_FightWorkList[id].m_WorkType != -1)continue;
// 
// 		if (-1==id2)
// 		if (g_pMainState->m_FightWorkList[id].m_pObj->m_IndexType == INDEXTYEP_CHARACTER)
// 		{//
// 			cCharacter* pc = (cCharacter*)g_pMainState->m_FightWorkList[id].m_pObj->m_pIndex;
// 			if (!pc->m_PcData.m_FightData.cannotMagic)
// 			{
// 				switch (pc->m_PcData.m_MengPaiID)
// 				{
// 				case eMP_����ɽ:
// 				case eMP_������:
// 					id2 = id;
// 					firstpos = list.size();
// 					break;
// 				case eMP_���ܵظ�:
// 					if (pc->m_PcData.m_Lv > 128)
// 					{
// 						id2 = id;
// 						firstpos = list.size();
// 					}
// 				}
// 			}
// 		}
// 		cPropertyData* pPet;
// 		g_pMainState->m_FightWorkList[id].m_pObj->GetPropertyData(pPet);
// 		if (!pPet->m_FightData.cannotUseItem)
// 			list.push_back(id);
// 	}
// 	if (!list.size())return;
// 	if (-1 == id2)
// 	{
// 		id2 = list[0];
// 		firstpos =0;
// 	}
// 	SetUser(id2);
// 	bool bUse = false;
// 	if (m_pUserPc)
// 	{
// 		eMengPai mengpai = (eMengPai)m_pUserPc->m_PcData.m_MengPaiID;
// 		switch (mengpai)
// 		{
// 		case eMP_����ɽ:
// 			if (1)
// 			{
// 				//�ؼ�   �����дȺ�
// //				if (m_pUserPetData->m_StrongLv > 95)
// 				{
// 					int num = 0;
// 					for (int i2 = start; i2<end; i2++)
// 					if (m_bNeedlive[i2])num += 1;
// 					if (num > 2)
// 					{
// 						if (Cost(3048))
// 						{
// 							for (int i2 = start; i2 < end; i2++)
// 								m_bNeedlive[i2] = false;
// 							UseSkill(3048);
// 							bUse = true;
// 						}
// 					}
// 				}
// 				if (!bUse)
// 				//����
// 				if (!m_pUserData->m_FightData.cannotMagic)
// 				{
// 					if (Cost(102))
// 					{
// 						m_bNeedlive[id2] = false;
// 						 UseSkill(102);
// 						 bUse = true;
// 					}
// 				}
// 			}
// 			break;
// 		case eMP_������:
// 			//����
// 			if (!m_pUserData->m_FightData.cannotMagic)
// 			{
// 				if (Cost(37))
// 				{
// 					m_bNeedlive[id2] = false;
// 					UseSkill(37);
// 					bUse = true;
// 				}
// 			}
// 			break;
// 		case eMP_���ܵظ�:
// 			//����
// 			if (m_pUserData->m_Lv > 129)
// 			if (!m_pUserData->m_FightData.cannotMagic)
// 			{
// 				if (Cost(37))
// 				{
// 					m_bNeedlive[id2] = false;
// 					UseSkill(37);
// 					bUse = true;
// 				}
// 			}
// 			break;
// 		}
// 	}
// 	if (!bUse)
// 	//����
// 	if (!m_pUserData->m_FightData.cannotUseItem)
// 	if (CheckItem(eAIUseItemTypelive))
// 	{
// 		m_bNeedlive[m_TargetID] = false;
// 		 UseItem(eAIUseItemTypelive);
// 		 bUse = true;
// 	}
// 	if (!bUse)return;
// 	for (int i = firstpos + 1; i < list.size(); i++)
// 	{
// 		SetUser(list[firstpos + 1]);
// 		//����
// 		if (!m_pUserData->m_FightData.cannotUseItem)
// 		if (CheckItem(eAIUseItemTypelive))
// 		{
// 			m_bNeedlive[m_TargetID] = false;
// 			m_bNeedAddHp[m_TargetID] = false;
// 			m_bNeedAddHpHurt[m_TargetID] = false;
// 			 UseItem(eAIUseItemTypeHPHurt);
// 			 return;
// 		}
// 
// 	}
// }











//void cAttackAI::CoutIdleList(int start, int end)
//{
//	int needlist[10];
//	for (int i = start; i < end; i++)
//	{
//		m_IdleList[i] = i;
//	}
//	for (int i = 0; i < 10; i++)
//	{
//		SetUser(i);
//		if (!m_pUserPc)
//		{
//			if (m_pUserPetData->m_AddPoint.hp>1 || m_pUserPetData->m_AddPoint.spd>1)
//			{
//				needlist[i] = 80;
//			}
//			else
//				needlist[i] = 10;
//		}
//		else
//		{
//			eMengPai mp = (eMengPai)m_pUserPc->m_PCData.m_MengPaiID;
//			switch (mp)
//			{
//			case eMP_���ƹٸ�:
//				needlist[i] = 1;
//				break;
//			case eMP_������:
//				needlist[i] = 99;
//				break;
//			case eMP_Ů����:
//				needlist[i] = 10;
//				break;
//			case eMP_����ɽ:
//				needlist[i] = 10;
//				break;
//			case eMP_ʨ����:
//				needlist[i] = 1;
//				break;
//			case eMP_ħ��կ:
//				needlist[i] = 1;
//				break;
//			case eMP_��˿��:
//				needlist[i] = 10;
//				break;
//			case eMP_���ܵظ�:
//				if (m_pUserPetData->m_AddPoint.atk > 2)
//				{
//					needlist[i] = 10;
//				}
//				else
//				{
//					needlist[i] = 98;
//				}
//				break;
//			case eMP_��������:
//				needlist[i] = 1;
//				break;
//			case eMP_��ׯ��:
//				needlist[i] = 90;
//				break;
//			case eMP_����ɽ:
//				needlist[i] = 95;
//				break;
//			case eMP_�칬:
//				needlist[i] = 80;
//				break;
//			default:
//				needlist[i] = 0;
//				break;
//			}
//		}
//		if (m_pUserPetData->m_FightProperty.cannotMagic)
//		{
//			needlist[i] += 10;
//		}
//		if (m_pUserPetData->m_FightProperty.chaos)
//		{
//			needlist[i] -= 100;
//			continue;
//		}
//		if (g_pMainState->m_FightList[i].m_bDie)
//		{
//			needlist[i] -= 100;
//			continue;
//		}
//	}
//	for (int a = 0; a < 9; a++)
//	for (int b = a + 1; b<10; b++)
//	{
//		if (needlist[a]<needlist[b])//ǰ�����ں���
//		{
//			swap(needlist[a], needlist[b]);
//			swap(m_IdleList[a+start], m_IdleList[b+start]);
//		}
//	}//����	
//}
// 
// void cAI::resetNeed()
// {
// 	cPropertyData* pPetdata;
// 	for (int i = 0; i < 20; i++)
// 	{
// 
// 		m_bNeedAddHp[i] = 0;//���غϸö����Ƿ���Ҫ��Ѫ
// 		m_bNeedAddHpHurt[i] = 0;
// 		m_bNeedUnSeal[i] = 0;//���غϸö����Ƿ���Ҫ���
// 		m_bNeedlive[i] = 0;
// 		m_bNeedAddMp[i] = 0;
// 		//����ɫ�Ƿ񱻷�
// 		m_bBeSeal[i] = false;
// 		_isShiFudu[i] = false;
// 		if (g_pMainState->m_FightWorkList[i].isExist)
// 		{
// 			g_pMainState->m_FightWorkList[i].m_pObj->GetPropertyData(pPetdata);
// 			if (pPetdata->m_FightData.cannotMagic && !pPetdata->Hide.d1)
// 				m_bBeSeal[i] = true;
// 			if (g_pMainState->m_FightWorkList[i].m_pObj->CheckHaveState(122))
// 			{
// 				_isShiFudu[i] = true;
// 			}
// 		}
// 		
// 	}
// 
// 
// 
// 	////////////////////////////////////////////////////////////////////////// getNeed
// 	for (int i = start; i < end; i++)
// 	{
// 		if (!g_pMainState->m_FightWorkList[i].isExist)continue;
// 		SetUser(i);
// 		//����
// 		if (m_pUserData->m_HP == 0)
// 		{
// 			if (!m_pUserData->m_FightData.cannotLive)
// 			{
// 				m_bNeedlive[i] = true;
// 			}
// 		}
// 		int limit = m_pUserPc ? m_HPLimit : m_HPLimit / 2 + 50;
// 		//Ѫ����
// 		if (m_pUserData->m_HP < (m_pUserData->HPMax.GetData() * limit) / 100)
// 		{
// 			//Ѫ��,Խ��Ҫ��Ѫ
// 			int k = (m_pUserData->m_HP * 100) / m_pUserData->HPMax.GetData() + 1;
// 			k = k * limit / m_HPLimit;
// 			k = 100 - k;
// 			if (m_pUserData->m_HP2 < m_pUserData->HPMax.GetData())
// 
// 				m_bNeedAddHpHurt[i] = true;
// 
// 			m_bNeedAddHp[i] = k;
// 
// 			if (m_pUserPc && m_pUserData->m_FightData.cannotAddHP)//����Ҳ���
// 			{
// 				m_bNeedUnSeal[i] = true;
// 			}
// 		}
// 
// 		m_bNeedAddMp[i] = true;
// 		vector<int> ms, m2s, ps, bs;
// 		isHadPetSkill(m_pUserData, bs, ps, ms, m2s);
// 		if (m_pUserData->LiveMp || (!m_pUserPc && !bs.size() && !ps.size() && !ms.size() && !m2s.size()))
// 		{
// 			m_bNeedAddMp[i] = false;
// 		}
// 		else if (m_pUserData->m_MP >= m_pUserData->m_Lv + 10 ||
// 			m_pUserData->m_MP >= m_pUserData->MPMax.GetData() - 30)
// 		{
// 			m_bNeedAddMp[i] = false;
// 		}
// 		else if (m_pUserPc && !m_pUserPc->m_PcData.m_MengPaiID)
// 		{
// 			// 			m_bNeedAddMp[i] = (m_pUserPetData->m_MP * 100) / m_pUserPetData->m_MPMax.GetData();
// 			// 			m_bNeedAddMp[i] = 100 - m_bNeedAddMp[i];
// 			m_bNeedAddMp[i] = false;
// 		}
// 		if (m_pUser->CheckHaveState(6))
// 		{
// 			//���˷���
// 			m_bNeedUnSeal[i] = true;
// 		}
// 		if (m_pUserData->m_FightData.cannotMagic)//����ʹ��ħ��
// 		{
// 			if (!m_pUser->m_StateList.size())
// 			{
// 				continue;
// 			}
// 			if (m_pUser->m_StateList.back().remainingTimes < 3)
// 			{
// 				continue;//3�غ����µ�BUFF���ù�
// 			}
// 			if (i % 10 > 4)
// 			{
// 				if (m_pUserData->PointBody >= m_pUserData->m_Lv * 3)
// 				{
// 					continue;//Ѫ�費�þ�
// 				}
// 				if (m_pUserData->PointStr > m_pUserData->m_Lv)
// 				{
// 					continue;//����ⷨ��Ҫ��
// 				}
// 			}
// 			m_bNeedUnSeal[i] = true;
// 		}
// 
// 		if (m_pUserData->m_FightData.cannotAttack)//���ܹ���
// 		{
// 			if (!m_pUser->m_StateList.size())
// 			{
// 				continue;
// 			}
// 			if (m_pUser->m_StateList.back().remainingTimes < 3)
// 			{
// 				continue;//3�غ����µ�BUFF���ù�
// 			}
// 			if (!m_pUserPc)
// 			{
// 				if (m_pUserData->PointStr > m_pUserData->m_Lv)
// 				{
// 					if (!ps.size())
// 					{
// 						m_bNeedUnSeal[i] = true;
// 					}
// 				}
// 			}
// 		}
// 		if (m_pUserData->m_FightData.cannotSpesialSkill)//����
// 		{
// 			if (m_pUserPc && m_pUserData->m_CP > 80)
// 			{
// 				m_bNeedUnSeal[i] = true;
// 			}
// 		}
// 
// 		if (m_pUserData->Hide.d1 ||
// 			m_pUserData->LiveRestoreRate ||
// 			m_pUser->CheckHaveState(0) ||
// 			m_pUser->CheckHaveState(7) ||
// 			m_pUser->CheckHaveState(142))
// 		{
// 			m_bNeedUnSeal[i] = false;
// 		}
//
// 		if (m_bNeedlive[i])
// 		{
// 			m_bNeedUnSeal[i] = false;
// 			m_bNeedAddHp[i] = false;
// 			m_bNeedAddHpHurt[i] = false;
// 			m_bNeedAddMp[i] = false;
// 		}
//	}
//}
//
// bool cAI::CheckItem(eAIUseItemType mode)
// {
// 	if (m_UserID % 10 < 5)
// 	{
// 		if (m_pUserPc)
// 		if (m_pUserPc->m_PcData.m_Items[mode].GetNum())
// 			return true;
// 	}
// 	else
// 	{
// 		if (INDEXTYEP_CHARACTER == g_pMainState->m_FightWorkList[m_UserID - 5].m_pObj->m_IndexType)
// 		{
// 			cCharacter* pc = (cCharacter*)g_pMainState->m_FightWorkList[m_UserID - 5].m_pObj->m_pIndex;
// 			if (pc)
// 			{
// 				if (pc->m_PcData.m_Items[mode].GetNum())
// 					return true;
// 			}
// 
// 		}
// 	}
// 	return false;
// }
// // ����+2
// void cAI::ContentUnSeal(int start, int end)
// {
// 	for (int i = start; i < end; i++)
// 	{
// 		if (m_bNeedUnSeal[i])
// 		{
// 			SetTarget(i);
// 			ContentUnSeal2(start, end);
// 			m_bNeedUnSeal[i] = false;
// 		}
// 	}
// }
// void cAI::ContentUnSeal2(int start, int end)
// {
// 	vector<int> list;
// 	int id2 = -1;
// 	int id;
// 	int firstpos = -1;
// 	for (int i = 19; i > -1; i--)
// 	{
// 		id = g_pMainState->m_pFightState->m_SpeedListPos[i];
// 		if (id < start || id >= end)continue;
// 		if (!g_pMainState->m_FightWorkList[id].isExist)continue;
// 		if (g_pMainState->m_FightWorkList[id].CheckDie())continue;
// 		if (g_pMainState->m_FightWorkList[id].m_WorkType != -1)continue;
// 		cPropertyData* pPet;
// 		g_pMainState->m_FightWorkList[id].m_pObj->GetPropertyData(pPet);
// 		if (!pPet->m_FightData.cannotUseItem)
// 			list.push_back(id);
// 	}
// 	if (!list.size())return;
// 	if (-1 == id2)
// 	{
// 		id2 = list[0];
// 		firstpos = 0;
// 	}
// 	SetUser(id2);
// //	bool bUse = false;
// 	
// 	int num = 0;
// 	for (int i2 = start; i2 < end; i2++)
// 	if (m_bNeedUnSeal[i2])num += 1;
// 		
// 		if (m_pUserPc)
// 		{
// 			eMengPai mengpai = (eMengPai)m_pUserPc->m_PcData.m_MengPaiID;
// 			switch (mengpai)
// 			{
// 			case eMP_����ɽ:
// 			case eMP_��˿��:
// 			case eMP_���ܵظ�:
// 			case eMP_��ׯ��:
// 			case eMP_�칬:
// 			case eMP_Ů����:
// 				if (1)
// 				{
// 					if (num > 2)
// 					{
// //						switch (m_pUserPetData->m_StrongLv >> 6)
// 						{
// //						case 1:
// 							if (Cost(3013))
// 							{
// 								for (int i2 = start; i2 < end; i2++)
// 								{
// 									m_bNeedUnSeal[i2] = false;
// 									if (m_bNeedAddHp[i2]>0)
// 									{
// 										m_bNeedAddHp[i2] -= 20;
// 									}
// 								}
// 								return UseSkill(3013);
// 							}
// //						case 0: 
// 							else 
// 							if (Cost(3012))
// 							{
// 								for (int i2 = start; i2 < end; i2++)
// 									m_bNeedUnSeal[i2] = false;
// 								return UseSkill(3012);
// 							}
// //							break;
// 						}
// 					}
// 					else
// 					//�ؼ�   
// //					switch (m_pUserPetData->m_StrongLv >> 6)
// 					{
// //					case 1:
// 						if (Cost(3011))
// 						{
// 							m_bNeedUnSeal[m_TargetID] = false;
// 							if (m_bNeedAddHp[m_TargetID]>0)
// 							m_bNeedAddHp[m_TargetID] -= 20;
// 							return UseSkill(3013);
// 						}
// 						else 
// //					case 0:
// 						if (Cost(3010))
// 						{
// 								m_bNeedUnSeal[m_TargetID] = false;
// 							return UseSkill(3012);
// 						}
// //						break;
// 					}
// 				}
// 				break;
// 			
// 			}
// 		}
// 		//����
// 		if (!m_pUserData->m_FightData.cannotUseItem)
// 		if (CheckItem(eAIUseItemTypeUnseal))
// 		{
// 			m_bNeedUnSeal[m_TargetID] = false;
// 			  UseItem(eAIUseItemTypeUnseal);
// 			  return;
// 		}
// }
//
//cAI::cAI()
//{
// 	for (int i = 0; i < 20; i++)
// 	{
// 		m_FightTarget[i] = -1;
// 		m_bSeal[i] = false;
// 		m_bNeedAddHp[i] = 0;//���غϸö����Ƿ���Ҫ��Ѫ
// 		m_bNeedAddHpHurt[i] = 0;
// 		m_bNeedUnSeal[i] = 0;//���غϸö����Ƿ���Ҫ���
// 		m_bNeedlive[i] = 0;
// 		m_bNeedAddMp[i] = 0;
// 		m_bBeSeal[i] = 0;//�Ƿ񱻷�
// 		m_bAtk[i] = 0;//
// 		_isShiFudu[i] = 0;
// 	}
//}
//
//int cAttackAI::FintTarget(int id)
//{
//	int targetid;
//	int start, end;
//	if (id < 10)start = 10;
//	else start = 0;
//	end = start + 10;
//
//	if (-1 == m_FightTarget[id])
//	{
//		SetUser(id);
//		if (m_pUserPc)
//		{
//
//			eMengPai mengpai = (eMengPai)m_pUserPc->m_PCData.m_MengPaiID;
//			switch (mengpai)
//			{
//			case eMP_��ׯ��:
//				if (m_pUserPetData->m_AddPoint.atk < 3)
//				{
//					return FindUnSeal(start, end);
//				}
//			case eMP_���ƹٸ�:
//			case eMP_ʨ����:
//			case eMP_�칬:
//				switch (rand() % 3)
//				{
//				case 0:
//					return FindDefminTarget(start, end, eProPerty����);
//				case 1:
//					return FindDefminTarget(start, end, eProPerty�˺�, 1);
//				case 2:
//					return FindDefminTarget(start, end, eProPerty����, 1);
//				}
//				break;
//			case eMP_������:
//				if (id < 10)start = 0;
//				else start = 10;
//				end = start + 10;
//				return FindDefminTarget(start, end, eProPerty����);
//				break;
//			case eMP_����ɽ:
//					return FindUnSeal(start, end);
//				break;
//			case eMP_ħ��կ:
//			case eMP_��������:
//					return FindDefminTarget(start, end, eProPerty����);
//				break;
//			case eMP_��˿��:
//				if (m_pUserPetData->m_AddPoint.atk > 2)
//					return FindDefminTarget(start, end, eProPerty����);
//				else
//					return FindUnSeal(start, end);
//			case eMP_���ܵظ�:
//				if (m_pUserPetData->m_AddPoint.atk>2)
//					return FindDefminTarget(start, end, eProPerty����);
//			case eMP_����ɽ:
//				switch (rand() % 3)
//				{
//				case 0:
//					return FindDefminTarget(start, end, eProPerty����, 1);
//				case 1:
//					return FindDefminTarget(start, end, eProPerty�˺�, 1);
//				case 2:
//					return FindDefminTarget(start, end, eProPerty����, 1);
//				}
//				break;
//			case eMP_Ů����:
//					return FindUnSeal(start, end);
//			}
//		}
//		else
//		{
//			if (m_pUserPetData->m_AddPoint.atk>2)
//				return FindDefminTarget(start, end, eProPerty����);
//			else
//				return FindDefminTarget(start, end, eProPerty����);
//		}
//	}
//	else
//	{
//		if (!g_pMainState->m_FightList[m_FightTarget[id]].isLive)
//		{
//			return FintTarget(id);
//		}
//		else targetid = m_FightTarget[id];
//	}
//	if (targetid == -1)return -1;
//	SetTarget(targetid);
//	return targetid;
//}
// 
// int cAI::FindDefminTarget(int start, int end, eProPerty prop,bool maxormin, int userID)
// {
// 	int id=-1;
// 	for (int i = start; i < end; i++)
// 	{
// 		if (g_pMainState->m_FightWorkList[i].isExist)
// 		{
// 			id = i;
// 			break;
// 		}
// 	}
// 	if (-1 == id)return id;
// 	cPropertyData *pP1;
// 	cPropertyData* pP2;
// 	for (int i = id + 1; i < end; i++)
// 	{
// 
// 		g_pMainState->m_FightWorkList[id].m_pObj->GetPropertyData(pP1);
// 		if (!g_pMainState->m_FightWorkList[i].isExist)continue;
// 		g_pMainState->m_FightWorkList[i].m_pObj->GetPropertyData(pP2);
// 		if (userID != -1)
// 		{
// 			cPropertyData *data = nullptr;
// 			g_pMainState->m_FightWorkList[userID].m_pObj->GetPropertyData(data);
// 			if (data && !data->Hide.d2 && pP2->Hide.d1)
// 			{
// 				continue;
// 			}
// 		}
// 		if (maxormin)
// 		{
// 			switch (prop)
// 			{
// 			case eProPerty�˺�:if (pP1->Atk.GetData() < pP2->Atk.GetData())id = i; break;
// 			case eProPerty����:if (pP1->Def.GetData() < pP2->Def.GetData())id = i; break;
// 			case eProPerty����:if (pP1->Mana.GetData() < pP2->Mana.GetData())id = i; break;
// 			case eProPerty�ٶ�:if (pP1->Speed.GetData() < pP2->Speed.GetData())id = i; break;
// 			case eProPerty��Ѫ:	if (pP1->m_HP < pP2->m_HP)id = i;	break;
// 			}
// 		}
// 		else
// 		{
// 			switch (prop)
// 			{
// 			case eProPerty�˺�:if (pP1->Atk.GetData() > pP2->Atk.GetData())id = i; break;
// 			case eProPerty����:if (pP1->Def.GetData() > pP2->Def.GetData())id = i; break;
// 			case eProPerty����:if (pP1->Mana.GetData() > pP2->Mana.GetData())id = i; break;
// 			case eProPerty�ٶ�:if (pP1->Speed.GetData() > pP2->Speed.GetData())id = i; break;
// 			case eProPerty��Ѫ:	if (pP1->m_HP > pP2->m_HP)id = i;	break;
// 			}
// 		}
// 	}
// 	return id;
// }
// 
// int cAI::findʬ��������()
// {
// 	int id = -1;
// 	int start = m_UserID < 10 ? 10 : 0;
// 	int end = start + 10;
// 	cPropertyData *data = nullptr;
// 	g_pMainState->m_FightWorkList[m_UserID].m_pObj->GetPropertyData(data);
// 	for (int i = start; i < end; i++)
// 	{
// 		if (_isShiFudu[i])continue;
// 		if (!g_pMainState->m_FightWorkList[i].isExist)continue;
// 		if (g_pMainState->m_FightWorkList[i].m_pObj->CheckHaveState(122))continue;
// 		cPropertyData *data2 = nullptr;
// 		g_pMainState->m_FightWorkList[i].m_pObj->GetPropertyData(data2);
// 		if (/*data2->m_Race >= 1000 || */!data->Hide.d2 && data2->Hide.d1)continue;
// 		id = i;
// 		break;
// 	}
// 	if (-1 == id)
// 		return -1;
// 	cPropertyData *pP1;
// 	cPropertyData* pP2;
// 	for (int i = id + 1; i < end; i++)
// 	{
// 		if (_isShiFudu[i])continue;
// 		g_pMainState->m_FightWorkList[id].m_pObj->GetPropertyData(pP1);
// 		if (!g_pMainState->m_FightWorkList[i].isExist)continue;
// 		if(g_pMainState->m_FightWorkList[i].m_pObj->CheckHaveState(122))continue;
// 		g_pMainState->m_FightWorkList[i].m_pObj->GetPropertyData(pP2);
// 		if (!data->Hide.d2 && pP2->Hide.d1/* || pP2->m_Race >= 1000*/)
// 		{
// 			continue;
// 		}
// 		if (pP1->m_HP < pP2->m_HP)id = i;
// 	}
// 	return id;
// }
// 
// int cAI::FindδSeal(int start, int end)
// {
// 	int num = end - start;
// 	int id = rand()%num+start;
// 	for (int i = 0; i < num+1; i++)
// 	{
// 		if (g_pMainState->m_FightWorkList[id].isExist)
// 		{
// 			if ((!m_bBeSeal[id]) && (!m_bSeal[id]))
// 			{
// //				m_bSeal[id] = true;
// 				return id;
// 			}
// 		}
// 		id += 1;
// 		if (id == end)
// 			id = start;
// 	}
// 
// 	return -1;
// }
// 
// int cAI::FindδSeal(int num)
// {
// 	int start, end;
// 	if (m_UserID < 10)
// 		start = 10;
// 	else start = 0;
// 	end = start + num;
// 	return FindδSeal(start, end);
// }
// 
// int cAI::FindδSeal(char &isMorA)
// {
// 	vector<POINT> out;
// 	finds(true, false, out, eET��ӡ����, m_UserID < 10 ? 10 : 0);
// // 	int star = m_UserID < 10 ? 10 : 0;
// // 	for (int i = star; i < star + 10; ++i)
// 	forv(out, i)
// 	{
// 		if (FindδSeal(out[i].x, isMorA))
// 		{
// 			return out[i].x;
// 		}
// 	}
// 	return -1;
// 
// // 	auto func = [&](const std::function<bool(int, bool, const cPetData*)> &f)
// // 	{
// // 		int star = m_UserID < 10 ? 10 : 0;
// // 		for (int i = star; i < star + 10; ++i)
// // 		{
// // 			if (!g_pMainState->m_FightList[i].isExist)
// // 			{
// // 				continue;
// // 			}
// // 			if (m_bBeSeal[i] || m_bSeal[i])
// // 			{
// // 				continue;
// // 			}
// // 			cPetData *data = nullptr;
// // 			g_pMainState->m_FightList[i].m_pData->GetDateP(data);
// // 			if (!data)
// // 			{
// // 				continue;
// // 			}
// // 			if (data->PeopleSpecial.d2 > 0 || data->m_race >= 1000 ||
// // 				g_pMainState->m_FightList[i].m_pData->CheckHaveState(0)|| 
// // 				g_pMainState->m_FightList[i].m_pData->CheckHaveState(7) ||
// // 				g_pMainState->m_FightList[i].m_pData->CheckHaveState(142)||
// // 				g_pMainState->m_FightList[i].m_pData->CheckHaveState(148))
// // 			{
// // 				continue;
// // 			}	
// // 			if (f(i, g_pMainState->m_FightList[i].m_pData->m_IndexType == INDEXTYEP_CHARACTER, data))
// // 			{
// // 				return i;
// // 			}
// // 		}
// // 		return -1;
// // 	};
// // 
// // 	int id = func([&](int i, bool isPc, const cPetData *data)
// // 	{
// // 		isMorA = 1;
// // 		return isPc && !data->m_FightProperty.cannotMagic;
// // 	});
// // 	if (id < 0)
// // 	{
// // 		id = func([&](int i, bool isPc, const cPetData *data)
// // 		{
// // 			if (!isPc && data->m_ProPertyAtk >= data->m_Lv * 3)
// // 			{
// // 				vector<int> ms, m2s, ps, bs;
// // 				if (isHadPetSkill((cPetData*)data, bs, ps, ms, m2s))
// // 				{
// // 					if (ps.size() && !data->m_FightProperty.cannotMagic)
// // 					{
// // 						isMorA = 1;
// // 						return true;
// // 					}
// // 					
// // 					if (!ps.size() && !data->m_FightProperty.cannotAttack)
// // 					{
// // 						isMorA = 0;
// // 						return true;
// // 					}
// // 				}
// // 			}
// // 			return false;
// // 		});
// // 	}
// // 	if (id < 0)
// // 	{
// // 		id = func([&](int i, bool isPc, const cPetData *data)
// // 		{
// // 			if (isPc && !data->m_FightProperty.cannotSkill && data->m_CP >= 80)
// // 			{
// // 				isMorA = 2;
// // 				return true;
// // 			}
// // 			return false;
// // 		});
// // 	}
// // 
// // 	return id;
// }
// 
// bool cAI::FindδSeal(int i, char &isMorA)
// {
// 	if (i < 0)
// 	{
// 		return false;
// 	}
// 	if (!g_pMainState->m_FightWorkList[i].isExist)
// 	{
// 		return false;
// 	}
// 	if (m_bBeSeal[i] || m_bSeal[i])
// 	{
// 		return false;
// 	}
// 	cPropertyData *data = nullptr;
// 	g_pMainState->m_FightWorkList[i].m_pObj->GetPropertyData(data);
// 	if (!data)
// 	{
// 		return false;
// 	}
// 	if (data->Hide.d1 > 0 || /*data->m_Race >= 1000 ||*/
// 		g_pMainState->m_FightWorkList[i].m_pObj->CheckHaveState(0) ||
// 		g_pMainState->m_FightWorkList[i].m_pObj->CheckHaveState(7) ||
// 		g_pMainState->m_FightWorkList[i].m_pObj->CheckHaveState(142))// ||
// // 		g_pMainState->m_FightList[i].m_pData->CheckHaveState(148))
// 	{
// 		return false;
// 	}
// 	if (rand() % 100 < data->LiveRestoreRate)
// 	{
// 		return false;
// 	}
// 
// 	bool isPc = g_pMainState->m_FightWorkList[i].m_pObj->m_IndexType == INDEXTYEP_CHARACTER;
// 
// 	if (isPc && !data->m_FightData.cannotMagic)
// 	{
// 		isMorA = 1;
// 		return true;
// 	}
// 
// 
// 	if (!isPc && data->PointStr >= data->m_Lv * 3)
// 	{
// 		vector<int> ms, m2s, ps, bs;
// 		if (isHadPetSkill((cPropertyData*)data, bs, ps, ms, m2s))
// 		{
// 			if (ps.size() && !data->m_FightData.cannotMagic)
// 			{
// 				isMorA = 1;
// 				return true;
// 			}
// 
// 			if (!ps.size() && !data->m_FightData.cannotAttack)
// 			{
// 				isMorA = 0;
// 				return true;
// 			}
// 		}
// 	}
// 
// 	if (isPc && !data->m_FightData.cannotSpesialSkill && data->m_CP >= 80)
// 	{
// 		isMorA = 2;
// 		return true;
// 	}
// 
// 	return false;
// }



// 
// 
// 
// 	//Ѱ����������������м�ֵ�Ķ���
// 	int start, end;
// 	if (m_UserID < 10)start = 10;
// 	else start = 0;
// 	end = start + 10;
// 	int num = end - start;
// 	int id = rand() % num+start;
// 	int idret = -1;
// 	int damage = 0;
// 	int damage2;
// 	int DamageAddPercent;
// 	int DamageDefAddPercent;
// 	for (int i = 0; i < num+1; i++)
// 	{
// 		if (g_pMainState->m_FightWorkList[id].isExist)
// 		if (!g_pMainState->m_FightWorkList[id].CheckDie())
// 		{
// 			if (userID != -1)
// 			{
// 				cPropertyData *data = nullptr;
// 				g_pMainState->m_FightWorkList[userID].m_pObj->GetPropertyData(data);
// 				cPropertyData *data2 = nullptr;
// 				g_pMainState->m_FightWorkList[id].m_pObj->GetPropertyData(data2);
// 				if (data && !data->Hide.d2 && data2->Hide.d1)
// 				{
// 					if (++id >= end)
// 					{
// 						id = start;
// 					}
// 					continue;
// 				}
// 			}
// 			SetTarget(id);
// 			int targethp = m_pTargetData->m_HP - m_bAtk[id];
// 			if (ATKOrMagic)
// 			{
// 				DamageAddPercent = m_pUserData->DmgPercent.d1; //����������
// 				DamageDefAddPercent = m_pTargetData->DmgPercent.d2;   //Ŀ���������
// 				damage2 = (m_pUserData->Atk.GetData() - m_pTargetData->Def.GetData()) * rate / 100;
// // 				int prr =  m_pTargetPetData->m_ParryRate.d1 - m_pUserPetData->m_ParryRate.d2;
// // 				if (prr > 100)
// // 				{
// // 					prr = 100;
// // 				}
// // 				damage2 = damage2 * prr / 200;
// 			}
// 			else
// 			{
// 				DamageAddPercent = m_pUserData->DmgPercentOfMagic.d1; //��������������
// 				DamageDefAddPercent = m_pTargetData->DmgPercentOfMagic.d2;   //Ŀ�귨����������
// 				damage2 = (m_pUserData->m_Lv * 3 + m_pUserData->Atk.GetData() / 6 + m_pUserData->Mana.GetData() - m_pTargetData->Mana.GetData()) * rate / 100;
// 			}
// 			damage2 = damage2 * (100 + DamageAddPercent - DamageDefAddPercent) / 100;//��������
// 			if (damage2 > targethp)
// 			{
// 				//���ֵ�HPԽ��Խ��    �ҷ����˺�Խ��Խ��
// 				damage2 = (targethp << 2) - damage2;
// 			}
// 			
// 			if (-1 == idret)
// 			{
// 				idret = id;
// 				damage = damage2;
// 			}
// 			else
// 			{
// 				if (m_pTargetData->m_HP - m_bAtk[id] < 1)
// 				{
// 					continue;
// 				}
// 				if (damage2 > damage)
// 				{
// 					idret = id;
// 					damage = damage2;
// 				}
// 			}
// 		}
// 		id += 1;
// 		if (id >= end)
// 		{
// 			id = start;
// 		}
// 	}
// 	if (idret > -1)
// 	{
// 		m_bAtk[idret] += damage; //��¼���󵥻غ��ܵ����˺���Ԥ��ֵ
// 	}
// 	return idret;


// 
// int cAI::FindCpMaxTarget(int num/*=100*/)
// {
// 	int start, end;
// 	if (m_UserID < 10)start = 10;
// 	else start = 5;
// 	end = start + 5;
// 	cPropertyData* petdata;
// 	int id = rand() % 5 + start;
// 	for (int i = 0; i < 5; i++)
// 	{
// 		if (!g_pMainState->m_FightWorkList[id].isExist)continue;
// 		g_pMainState->m_FightWorkList[id].m_pObj->GetPropertyData(petdata);
// 		if (petdata->m_CP>num)
// 		{
// 			return id;
// 		}
// 		id += 1;
// 		if (id >= end)id = start;
// 	}
// 	return -1;
// }
// 
// bool cAI::CheckHaveState(int userid, int skillid)
// {
// 	return g_pMainState->m_FightWorkList[userid].m_pObj->CheckHaveState(skillid);
// }
// 
// void cAI::NpcTryMagic(int id)
// {
// 	if (Cost(id))
// 	{
// 		return UseSkill(id);
// 	}
// 	else
// 	{
// 		if (m_UserID<10 && m_TargetID<10)
// 			SetTarget(g_pMainState->m_AI.find׷�������¹�(m_UserID, 4, true));
// 		else
// 		if (m_UserID > 9 && m_TargetID > 9)
// 			SetTarget(g_pMainState->m_AI.find׷�������¹�(m_UserID, 4, true));
// 		if(m_TargetID < 0)
// 		{
// 			if (m_UserID < 10 && m_TargetID < 10)
// 				SetTarget(g_pMainState->m_AI.find׷�������¹�(m_UserID, 4, false));
// 			else
// 				if (m_UserID > 9 && m_TargetID > 9)
// 					SetTarget(g_pMainState->m_AI.find׷�������¹�(m_UserID, 4, false));
// 		}
// 		return NormalAtk();
// 	}
// }






















// 
// void cAI::ZhiHui(bool bOur)
// {
// 	int start = 10;
// 	int end;
// 	if (bOur)start = 0;
// 	end = start + 10;
// 	vector<POINT> tList;
// 	vector<POINT> tList2;
// 	//�ٻ�������,������
// 	int num2;
// 	int num = finds(true,true,tList, eET���ٻ���, start);
// 	for (int i = 0; i < num; i++)
// 	{
// 		if (!g_pMainState->m_pFightState->m_FightMenu.CheckControl(i))continue;
// 		SetUser(tList[i].x);
// 		for (int j = 0; j < m_pUserPc->m_PcData.m_NumofBB; j++)
// 		{
// 			cPet* pet = m_pUserPc->m_PcData.m_pPets[j];
// 			cPetData& pd = pet->m_PetData;
// 			cPcData& pc = m_pUserPc->m_PcData;
// 			if (pd._owerIdx >= 0 && pd._owerIdx != pc.m_FightPetID &&
// 				pd.m_Lv <= pc.m_Lv + cct::lvGapFromRoleAndBaby &&
// 				pet->GetData()->m_LvTake <= pc.m_Lv)
// 			{
// 				Summon(j);
// 				break;
// 			}
// 
// 
// // 			if (m_pUserPc->m_PcData.m_pPets[j]->m_PetData.m_HP > 0)
// // 			if (m_pUserPc->m_PcData.m_pPets[j]->GetData()->m_LvTake <= m_pUserPc->m_PcData.m_Lv)
// // 			{
// // 				 Summon(j);
// // 			}
// 		}
// 	}
// 	//��������,����
// 	num = finds(false, false, tList2, eET��������, start);
// 	if (num)
// 	{
// 		// 6 ���䲻��
// 		num2 = finds(true, true, tList, eETҽ��ϵ, start, 6);
// 		if (!num2)
// 		{
// 			num2 = finds(true, true, tList, eET�ٶ����, start, 6);
// 		}
// 
// 		if (num2)
// 		{
// 			resurgence2(tList, tList2, 0);
// 		}
// 	}
// 
// 	//���
// 	finds(false, true, tList, eET�ٶ����, start, 6);
// 	UnSeal2(tList, start, end);
// 
// 	//�����Ѫ
// 	if (finds(false, true, tList, eET��Ѫ, start))
// 	{
// 		Cure2(tList, start, end);
// 	}
// 
// 	CureMP2(tList,start,end);
// }
// 

// void cAI::resurgence2(vector<POINT>& user, vector<POINT>& target, int targetID)
// {
// 	if (target.size() <= targetID)return;
// 	bool blist=true;//�Ƿ�A��B B��C
// 	int i;
// 	for (i = 0; i < user.size(); i++)
// 	{
// 		if (target[targetID].x == user[i].x)
// 		{//������ٶ�̫��
// 			blist = false;
// 			continue;
// 		}
// 		if (resurgence(user[i].x, target[targetID].x))
// 			break;
// 	}
// 	if (!blist)return resurgence2(user,target,targetID+1);
// 	//A��B B��C C��D
// 	if (i == g_pMainState->m_HeroID)return;
// 	if (i == g_pMainState->m_HeroID+5)return;
// 	i = targetID;
// 	for (; i < target.size() - 1; i++)
// 	{
// 		if (!resurgence(target[i].x, target[i+1].x))break;
// 	}
// 	//D��BB
// 	if (!g_pMainState->m_FightWorkList[target[i].x + 5].isExist)
// 	{
// 		SetUser(target[i].x);
// 		int j = 0;
// 		for (; j < m_pUserPc->m_PcData.m_NumofBB; j++)
// 		{
// 			if (m_pUserPc->m_PcData.m_pPets[j]->m_PetData.m_HP>0)
// 			if (m_pUserPc->m_PcData.m_pPets[j]->GetData()->m_LvTake <= m_pUserPc->m_PcData.m_Lv)
// 			{
// 				Summon(j);
// 			}
// 		}
// 		//û��BB,�Լ���ҩ
// 		if (j == m_pUserPc->m_PcData.m_NumofBB)
// 		{
// 			SetTarget(target[i].x);
// 			if (!UseItem(eAIUseItemTypeHPHurt))
// 			{
// 				//�����κδ���
// 			}
// 		}
// 	}
// }
// 
// void cAI::CorrectEnemy(vector<POINT>& out, eEnemyCorrect typ)
// {
// 	bool bFind = false;
// 	int i;
// 	for (i = 0; i < out.size(); i++)
// 	{
// 		SetTarget(out[i].x);
// 		switch (typ)
// 		{
// 		case cAI::eEC����:
// 			if (!m_pTargetList->isExist)bFind = true;
// 			if (m_pTargetList->CheckDie() && (!m_bNeedlive[m_TargetID]))bFind = true;
// 			if (m_pTargetData->m_FightData.cannotUseItem)bFind = true;
// 			break;
// 		default:
// 			break;
// 		}
// 		if (bFind)
// 		{
// 			out.erase(out.begin() + i);
// 			return CorrectEnemy(out, typ);
// 		}
// 	}
// 	return;
// }
// 



// bool cAI::CureMP(int user, int target, bool toall /*= false*/)
// {
// // 	if (!m_bNeedAddMp[target])
// // 	{
// // 		return true;
// // 	}
// 	SetUser(user);
// 	SetTarget(target);
// 	if (m_pUserPc)
// 	{
// 		if (m_pUserData->m_FightData.cannotMagic)
// 			switch (m_pUserPc->m_PcData.m_MengPaiID)
// 		{
// 			case eMP_��ׯ��:
// 				if (!m_pTarget->CheckHaveState(90))
// 				{
// 					UseSkill(90);
// 					m_bNeedAddMp[target] = false;
// 					return true;
// 				}
// 				else
// 				{
// 					if (target == user)
// 					{
// 						UseSkill(94);
// 						m_bNeedAddMp[target] = false;
// 						return true;
// 					}
// 				}
// 				break;
// 			case eMP_����ɽ:
// 				if (target == user)
// 				{
// 					if (m_pUserData->m_HP > 100)
// 					{
// 						UseSkill(23);
// 						m_bNeedAddMp[target] = false;
// 						return true;
// 					}
// 				}
// 				break;
// 		}
// 	}
// 	if (!m_pUserData->m_FightData.cannotUseItem)
// 	{
// // 		if (toall)
// // 		{
// // 			UseItem(eAIUseItemTypeMPALL);
// // 			return true;
// // 		}
// // 		else
// 		{
// 			if (UseItem(eAIUseItemTypeMP))
// 			{
// 				m_bNeedAddMp[target] = false;
// 				return true;
// 			}
// 		}
// 	}
// 	return false;
// }
// 
// void cAI::UnSeal2(vector<POINT>& tlist, int start, int end)
// {
// 	uint start1 = 0;
// 	for (int i = start; i < end; i++)
// 	{
// 		if (!m_bNeedUnSeal[i])
// 		{
// 			continue;
// 		}
// 		if (g_pMainState->m_FightWorkList[i].m_pObj->m_IndexType != INDEXTYEP_CHARACTER)
// 		{
// 			continue;
// 		}
// 		for (int j = start1; j < tlist.size(); j++)
// 		{
// 			if (UnSeal(tlist[j].x, i))
// 			{
// 				start1 += 1;
// 				if (start1 == tlist.size())
// 				{
// 					return;
// 				}
// 				break;
// 			}
// 		}
// 	}
// 
// 	for (int i = start; i < end; i++)
// 	{
// 		if (!m_bNeedUnSeal[i])
// 		{
// 			continue;
// 		}
// 		for (int j = start1; j < tlist.size(); j++)
// 		{
// 			if (UnSeal(tlist[j].x, i))
// 			{
// 				start1 += 1;
// 				if (start1 == tlist.size())
// 				{
// 					return;
// 				}
// 				break;
// 			}
// 		}
// 	}
// }
// 
// void cAI::Cure2(vector<POINT>& tlist, int start, int end)
// {
// 	bool toall = true;
// 	int start1 = 0;
// 	for (int i = start; i < end; i++)
// 	{
// 		if (m_bNeedAddHp[i] > (100 - m_HPLimit) && g_pMainState->m_FightWorkList[i].m_pObj->m_IndexType != INDEXTYEP_PET)
// 		{
// 			for (int j = start1; j < tlist.size(); j++)
// 			{
// 				if (toall)
// 				{
// 					int num = 0;
// 					int limit2 = m_HPLimit / 2 + 50;
// 					for (int k = start; k < end; k++)
// 					{
// 						if (m_bNeedAddHp[k] > 100 - limit2)
// 							num += 1;
// 					}
// 					if (num < 2)toall = false;
// 				}
// 				if (Cure(tlist[j].x, i, toall))
// 				{
// 					start1 += 1;
// 					if (start1 == tlist.size())return;
// 					break;
// 				}
// 			}
// 
// 		}
// 	}
// }
// 
// bool cAI::UnSeal(int user, int target)
// {
// // 	if (!m_bNeedUnSeal[target])
// // 	{
// // 		return true;
// // 	}
// 	SetUser(user);
// 	if (!pUserList->isExist)return false;
// 	if (pUserList->CheckDie())return false;
// 	if (pUserList->m_WorkType > -1)return false;
// 	if (m_pUserPc && !m_pUserData->m_FightData.cannotSpesialSkill)
// 	{
// 		if (Cost(3013))
// 		{
// // 			m_bNeedAddHpHurt[target] -= 20;
// // 			m_bNeedAddHp[target] -= 20;
// 			SetTarget(target);
// 			UseSkill(3013);
// 			int star = target < 10 ? 0 : 10;
// 			for (int i = star; i < star + 10; ++i)
// 			{
// 				m_bNeedUnSeal[i] = false;
// 				m_bNeedAddHp[i] -= 20;
// 			
// 			}
// 			return true;
// 		}
// 	}
// 	if (m_pUserData->m_FightData.cannotUseItem)
// 		return false;
// 	SetTarget(target);
// 	if (UseItem(eAIUseItemTypeUnseal))
// 	{
// 		m_bNeedUnSeal[target] = false;
// 		m_bNeedAddHp[target] -= 10;
// 		return true;
// 	}
// 	return false;
// }
// 
// void cAI::CureMP2(vector<POINT>& tlist, int start, int end)
// {
// 	bool toall = true;
// 	int start1 = 0;
// 	for (int i = start; i < end; i++)
// 	{
// 		if (m_bNeedAddMp[i])
// 		{
// 			for (int j = start1; j < tlist.size(); j++)
// 			{
// 				if (toall)
// 				{
// 					int num = 0;
// 					for (int k = start; k < end; k++)
// 					{
// 						if (m_bNeedAddMp[k])
// 							num += 1;
// 					}
// 					if (num < 3)toall = false;
// 				}
// 				if (CureMP(tlist[j].x, i, toall))
// 				{
// 					start1 += 1;
// 					if (start1 == tlist.size())return;
// 					break;
// 				}
// 			}
// 
// 		}
// 	}
// }
// 
// vector<int> cAI::check����(vector<POINT>& out, int user)
// {
// 	cPropertyData *data;
// 	g_pMainState->m_FightWorkList[user].m_pObj->GetPropertyData(data);
// 	vector<int> out2;
// 	forv(out, i)
// 	{
// 		cPropertyData *data2;
// 		g_pMainState->m_FightWorkList[out[i].x].m_pObj->GetPropertyData(data2);
// 		if (data->Hide.d2 || !data2->Hide.d1)
// 		{
// 			out2.push_back(out[i].x);
// 		}
// 	}
// 	return out2;
// }
// 













// 		if ((i%5)==g_pMainState->m_HeroID)
// 		{
// 			if (g_pMainState->m_FightWorkList[i].isExist)
// 			{
// 				SetUser(i);
// 				if (m_pUserPc)
// 				{
// 					if (pUserList->m_WorkType == WORKTYPE_MAGIC)
// 					{
// 						//������� ��ӡ
// 						if (pUserList->m_SkillSelect.TargetID > 9)
// 						{
// 							m_bNeedUnSeal[pUserList->m_SkillSelect.TargetID] = true;
// 						}
// 						else
// 						{
// 							m_bNeedAddHp[pUserList->m_SkillSelect.TargetID] -= 50;
// 						}
// 					}
// 				}
// 				if (pUserList->m_WorkType == WORKTYPE_ITEM)
// 				{	//������Ǽ�Ѫ
// 					if (pUserList->m_SkillSelect.TargetID < 10)
// 					{
// 					//	sItem2* pItem = &m_pUserPc->m_PCData.m_Item[pUserList->m_ItemSelectID];
// 						m_bNeedAddHp[pUserList->m_SkillSelect.TargetID] -= 20;
// 					}
// 				}
// 			}
// 		}
//	}
	//	ZhiHui(false);
	//	ZhiHui(true);
	// 	PreRun(0,10);
	// 	if (m_bPKMode)
	// 	{
	// 		ZhiHui(false);
	// 	}
	// 
	// 
	// 	for (int i = 0; i < 10; i++)
	// 	{
	// 		g_pMainState->m_InterfaceDoor.m_TimeShiCheng.stepMiliSec();
	// 		if (g_pMainState->m_FightList[i].isExist)
	// 		if (g_pMainState->m_FightList[i].m_WorkType == -1)
	// 		{
	// 			g_pMainState->m_InterfaceDoor.m_TimeShiCheng.stepMiliSec();
	// 			AutoRunAi(i);
	// 		}
	// 	}
	//	if (m_bPKMode)
	// 	{
	// 		for (int i = 10; i < 20; i++)
	// 		{
	// 			g_pMainState->m_InterfaceDoor.m_TimeShiCheng.stepMiliSec();
	// 			if (g_pMainState->m_FightList[i].isExist)
	// 			if (g_pMainState->m_FightList[i].m_WorkType == -1)
	// 			{
	// 				g_pMainState->m_InterfaceDoor.m_TimeShiCheng.stepMiliSec();
	// 				AutoRunAi(i);
	// 			}
	// 		}
	// 	}
	// 	else
	// 	{
	// 		for (int i = 10; i < 20; i++)
	// 		{
	// 			g_pMainState->m_InterfaceDoor.m_TimeShiCheng.stepMiliSec();
	// 			if (g_pMainState->m_FightList[i].isExist)
	// 			if (g_pMainState->m_FightList[i].m_WorkType == -1)
	// 			{
	// 				g_pMainState->m_InterfaceDoor.m_TimeShiCheng.stepMiliSec();
	// 				AutoRunEnemyAi(i);
	// 			}
	// 		}
	// 	}
	//
	// 	vector<POINT>out;
	// 	find������͵ļ���(false, true, out, eET�ٶ����, 10);
	// 	forv(out, i)
	// 	{
	// 		g_pMainState->m_InterfaceDoor.m_TimeShiCheng.stepMiliSec();
	// 		AutoRunAi(out[i].x);
	// 	}
	// 	out.clear();
	// 	find������͵ļ���(false, true, out, eET�ٶ����, 0);
	// 	forv(out, i)
	// 	{
	// 		g_pMainState->m_InterfaceDoor.m_TimeShiCheng.stepMiliSec();
	// 		AutoRunAi(out[i].x);
	// 	}
	// 
	// 
	// 	for (int i = 0; i < 20; i++)
	// 	{
	// 		m_FightTarget[i] = -1;
	// 		m_bSeal[i] = false;
	// 		m_bAtk[i] = 0;
	// 	}























	// 	int start = 10;
	// 	int end;
	// 	if (bOur)start = 0;
	// 	end = start + 10;
	// 	vector<POINT> tList;
	// 	vector<POINT> tList2;
	// 	//�ٻ�������,������
	// 	int num2;
	// 	int num = finds(true, true, tList, eET���ٻ���, start);
	// 	for (int i = 0; i < num; i++)
	// 	{
	// 		if (!g_pMainState->m_pFightState->m_FightMenu.CheckControl(i))continue;
	// 		SetUser(tList[i].x);
	// 		for (int j = 0; j < m_pUserPc->m_PcData.m_NumofBB; j++)
	// 		{
	// 			cPet* pet = m_pUserPc->m_PcData.m_pPets[j];
	// 			cPetData& pd = pet->m_PetData;
	// 			cPcData& pc = m_pUserPc->m_PcData;
	// 			if (pd._owerIdx >= 0 && pd._owerIdx != pc.m_FightPetID &&
	// 				pd.m_Lv <= pc.m_Lv + cct::lvGapFromRoleAndBaby &&
	// 				pet->GetData()->m_LvTake <= pc.m_Lv)
	// 			{
	// 				Summon(j);
	// 				break;
	// 			}
	// 
	// 
	// 			if (m_pUserPc->m_PcData.m_pPets[j]->m_PetData.m_HP > 0)
	// 			if (m_pUserPc->m_PcData.m_pPets[j]->GetData()->m_LvTake <= m_pUserPc->m_PcData.m_Lv)
	// 			{
	// 				 Summon(j);
	// 			}
	// 		}
	// 	}
	// 	//��������,����
	// 	num = finds(false, false, tList2, eET��������, start);
	// 	if (num)
	// 	{
	// 		// 6 ���䲻��
	// 		num2 = finds(true, true, tList, eETҽ��ϵ, start, 6);
	// 		if (!num2)
	// 		{
	// 			num2 = finds(true, true, tList, eET�ٶ����, start, 6);
	// 		}
	// 
	// 		if (num2)
	// 		{
	// 			resurgence2(tList, tList2, 0);
	// 		}
	// 	}
	// 
	// 	//���
	// 	finds(false, true, tList, eET�ٶ����, start, 6);
	// 	UnSeal2(tList, start, end);
	// 
	// 	//�����Ѫ
	// 	if (finds(false, true, tList, eET��Ѫ, start))
	// 	{
	// 		Cure2(tList, start, end);
	// 	}
	// 
	// 	CureMP2(tList, start, end);






#if 0
bool isAtk = m_pUserData->PointMag == m_pUserData->m_Lv;
SetTarget(m_FightTarget[m_UserID]);
bool isTar = true;
if (m_TargetID < 0)
{
	isTar = false;
	SetTarget(findTarget(100, isAtk, m_UserID));
}
if (m_pUserData->m_FightData.cannotMagic)
{
	if (isAtk && m_TargetID >= 0)
	{
		NormalAtk();
		return 1;
	}
	return 0;
	defense(m_UserID);
}

// 	//Ѱ��Ŀ��
// 	if (m_FightTarget[m_UserID] > -1)
// 	{
// 		
// 	}
// 	else
// 	{
// //		int targetid = g_pMainState->m_AI.findBattleTargetAndStepMiliSec(m_UserID, 4, true);
// 		int targetid = FindAtkTarget(100, isAtk, m_UserID);
// 		if (targetid == -1)
// 		{
// 			if (runSelfunseal())
// 			{
// 				return;
// 			}
// 			return defense(m_UserID);
// 		}
// 		SetTarget(targetid);
// 	}

vector<int> ms, m2s, ps, bs;
if (!isHadPetSkill(m_pUserData, bs, ps, ms, m2s))
{
	return 0;
}
// 	if (!cct::get()->isAtkMode(m_UserID) && bs.size())
// 	{
// 		int s = bs[rand() % bs.size()];
// 		if (!m_pUser->CheckHaveState(s) && CheckCanSkill(s))
// 		{
// 			SetTarget(m_UserID);
// 			UseMagic(s);
// 			return 2;
// 		}
// 	}

if (!m2s.size() && !ps.size() && !ms.size())
{
	if (cct::get()->isAtkMode(m_UserID) || isAtk)
	{
		NormalAtk();
		return 1;
	}
	return 0;
	defense(m_UserID);

}

auto isCan = [&](const vector<int> &ss)
{
	if (!ss.size())
	{
		return -1;
	}
	bool isCan = false;
	int s;
	for (int i = 0; i < 99; ++i)
	{
		s = ss[rand() % ss.size()];
		if (Cost(s))
		{
			isCan = true;
			break;
		}
	}
	if (isCan)
	{
		return s;
	}
	return -1;
};

auto runM2s = [&]()
{
	if (!m2s.size())
	{
		return false;
	}

	int s = -1;
	if (getVisibleNO() < 2)
	{
		forr(m2s, i)
		{
			if (m2s[i] == 2105 && Cost(2105))
			{
				s = 2105;
				break;
			}
		}
	}
	if (s == -1)
	{
		s = isCan(m2s);
	}
	if (s >= 0)
	{
		UseSkill(s);
		return true;
	}
	return false;
};

auto runPs = [&]()
{
	int s = isCan(ps);
	if (s >= 0)
	{
		if (isTar)
		{
			UseSkill(s);
			return true;
		}
		int self = m_UserID < 10 ? 10 : 0;
		if (s == 2095)
		{
			vector<POINT> out;
			finds(true, false, out, eET������ɽ95, self);
			auto out2 = check����(out, m_UserID);
			if (out2.size())
			{
				SetTarget(out2.front());
			}
			// 				int id = -1;
			// 				int start = m_UserID < 10 ? 10 : 0;
			// 				for (int i = start; i < start + 10; i++)
			// 				{
			// 					if (g_pMainState->m_FightList[i].isExist)
			// 					{
			// 						id = i;
			// 						break;
			// 					}
			// 				}
			// 				if (id >= 0)
			// 				{
			// 					cPetData *pP1;
			// 					cPetData* pP2;
			// 					for (int i = id + 1; i < start + 10; i++)
			// 					{
			// 
			// 						g_pMainState->m_FightList[id].m_pData->GetDateP(pP1);
			// 						if (!g_pMainState->m_FightList[i].isExist)continue;
			// 						g_pMainState->m_FightList[i].m_pData->GetDateP(pP2);
			// 						if (m_pUserPetData->PeopleSpecial.d1 < pP2->PeopleSpecial.d2)
			// 						{
			// 							continue;
			// 						}
			// 						if (pP1->m_ATK.GetData() + pP1->m_DEF.GetData() > pP2->m_ATK.GetData() + pP2->m_DEF.GetData())
			// 						{
			// 							id = i;
			// 						}
			// 					}
			// 				}
			// 				if (id >= 0)
			// 				{
			// 					SetTarget(id);
			// 				}
		}
		else if (s == 2099)
		{
			vector<POINT> out;
			finds(true, false, out, eET���ݻ���99, self);
			auto out2 = check����(out, m_UserID);
			if (out2.size())
			{
				SetTarget(out2.front());
			}
		}
		else if (s == 2094)
		{
			SetTarget(FindDefminTarget(eProPerty��Ѫ, false));
		}
		if (m_TargetID >= 0)
		{
			UseSkill(s);
			return true;
		}
	}
	return false;
};

auto runMs = [&]()
{
	int s = isCan(ms);
	if (s >= 0)
	{
		UseSkill(s);
		return true;
	}
	return false;
};

if (isAtk)
{
	if (runPs())
	{
		return 3;
	}
	NormalAtk();
	return 1;
}
if (getVisibleNO() > 1 || !ms.size())
{
	if (runM2s())
	{
		return 4;
	}
}
if (runMs())
{
	return 4;
}

return 0;

// 
// 	//Ѱ�Ҽ���
// 	vector<sSkill*> skilllist;
// 	bool bHaveBuff=false;//�Ƿ��״̬����
// 	bool bHaveMagic=false;//�Ƿ�ᵥ��
// 	bool bHaveMagic2=false;//�Ƿ��Ⱥ��
// 	for (int j = 0; j < m_pUserPetData->m_NumofBBSkill; j++)
// 	{
// 		switch (m_pUserPetData->m_pPetSkill[j]->m_SkillType)
// 		{
// 		case 4:
// 			if (1)
// 			{
// 				if (1<g_pMainState->m_SkillManager.GetPetSkill(m_pUserPetData->m_pPetSkill[j]->m_Id)->m_TargetNum)
// 				{
// 					bHaveMagic2 = true;
// 				}
// 				else bHaveMagic = true;
// 			}
// 			break;
// 		case 7:continue;
// 		default:
// 			bHaveBuff = true;
// 			break;
// 		}
// 		skilllist.push_back(m_pUserPetData->m_pPetSkill[j]);
// 	}
// 	//�������������
// 	if (skilllist.size())
// 	{
// 		if (bHaveBuff)
// 		{
// 			if (rand() % 3 == 1)
// 			{
// 				//״̬�෨��
// 				for (int i = 0; i < skilllist.size(); i++)
// 				{
// 					if (skilllist[i]->m_SkillType == 2)
// 					{
// 						int skillid = skilllist[i]->m_Id + 2000;
// 						if (!m_pUser->CheckHaveState(skillid))
// 						{
// 							if (CheckCanSkill(skillid))
// 							{
// 								SetTarget(m_UserID);
// 								return UseMagic(skillid);
// 							}
// 						}
// 					}
// 				}
// 			}
// 		}
// 		if (bHaveMagic && (0 == bHaveMagic2))
// 		{
// 			for (int i = 0; i < skilllist.size(); i++)
// 			{//����
// 				if (g_pMainState->m_SkillManager.m_PetSkillList[skilllist[i]->m_Id].m_EffectType == 0)
// 				{
// 					return NpcTryMagic(2000 + skilllist[i]->m_Id);
// 				}
// 			}
// 		}
// 		else
// 		if ((0==bHaveMagic) && bHaveMagic2)
// 		{
// 			for (int i = 0; i < skilllist.size(); i++)
// 			{//��Ⱥ��
// 				if (g_pMainState->m_SkillManager.m_PetSkillList[skilllist[i]->m_Id].m_EffectType == -3)
// 				{
// 					return NpcTryMagic(2000 + skilllist[i]->m_Id);
// 				}
// 			}
// 		}
// 		else
// 		if (bHaveMagic&& bHaveMagic2)
// 		{
// 			//ʹ�õ�����Ⱥ��
// 			int start, end;
// 			if (m_UserID<10)start = 10;
// 			else start = 0;
// 			end = start + 10;
// 			if (g_pMainState->GetLiveNum(start, end) > 1)
// 			for (int i = 0; i < skilllist.size(); i++)
// 			{//��Ⱥ��
// 				if (g_pMainState->m_SkillManager.m_PetSkillList[skilllist[i]->m_Id].m_EffectType == -3)
// 				{
// 					return NpcTryMagic(2000 + skilllist[i]->m_Id);
// 				}
// 			}
// 
// 			for (int i = 0; i < skilllist.size(); i++)
// 			{//����
// 				if (g_pMainState->m_SkillManager.m_PetSkillList[skilllist[i]->m_Id].m_EffectType == 0)
// 				{
// 					return NpcTryMagic(2000 + skilllist[i]->m_Id);
// 				}
// 			}
// 		}
// 		
// 	}
// 	if (m_pUserPetData->m_ProPertyAtk < m_pUserPetData->m_Lv * 2)
// 		return defense(m_UserID);
// 	return	NormalAtk();

#endif


// 	if (!m_bNeedlive[target])
// 	{
// 		return true;
// 	}
// 	SetUser(user);
// 	if (pUserList->m_WorkType > -1)return false;
// 	SetTarget(target);
// 	if (INDEXTYEP_CHARACTER == m_pUser->m_IndexType)
// 	{
// 		if (!m_pUserData->m_FightData.cannotSpesialSkill)
// 		{
// 			if (Cost(3048))
// 			{
// 				UseSkill(3048);
// 				vector<int> ts;
// 				int star = target < 10 ? 0 : 10;
// 				for (int i = star; i < star + 10; ++i)
// 				{
// 					if (!g_pMainState->m_FightWorkList[i].isExist)
// 					{
// 						continue;
// 					}
// 					if (g_pMainState->m_FightWorkList[i].m_pObj->m_IndexType != INDEXTYEP_CHARACTER)
// 					{
// 						continue;
// 					}
// 					if (!g_pMainState->m_FightWorkList[i].CheckDie())
// 					{
// 						continue;
// 					}
// 					cPropertyData *data = nullptr;
// 					g_pMainState->m_FightWorkList[i].m_pObj->GetPropertyData(data);
// 					if (!data)
// 					{
// 						continue;
// 					}
// 					if (!m_pUserData->Hide.d2 && data->Hide.d1)
// 					{
// 						continue;
// 					}
// 					ts.push_back(i);
// 				}
// 				if (ts.size() > 2)
// 				{
// 					for (int i : ts)
// 					{
// 						m_bNeedUnSeal[i] = false;
// 						m_bNeedlive[i] = false;
// 						m_bNeedAddHpHurt[i] -= 100;
// 						m_bNeedAddHp[i] -= 100;
// 					}
// 					return true;
// 				}
// 			}
// 		}
// 
// 		if (!m_pUserData->m_FightData.cannotMagic)
// 		{
// 			switch (m_pUserPc->m_PcData.m_MengPaiID)
// 			{
// 			case eMP_����ɽ:
// 				if (Cost(104))
// 				{
// 					UseSkill(104);
// 					m_bNeedlive[target] = false;
// 					m_bNeedAddHpHurt[target] -= 40;
// 					m_bNeedAddHp[target] -= 40;
// 					return true;
// 				}
// 				break;
// 			case eMP_������:
// 				if (Cost(37))
// 				{
// 					UseSkill(37);
// 					m_bNeedlive[target] = false;
// 					m_bNeedAddHpHurt[target] -= 30;
// 					m_bNeedAddHp[target] -= 30;
// 					return true;
// 				}
// 				break;
// 			case eMP_���ܵظ�:
// 				if (m_pUserPc->m_PcData.m_Lv >= 120)
// 				{
// 					if (Cost(125))
// 					{
// 						UseSkill(125);
// 						m_bNeedlive[target] = false;
// 						m_bNeedAddHpHurt[target] -= 25;
// 						m_bNeedAddHp[target] -= 25;
// 						return true;
// 					}
// 				}
// 				break;
// 			}
// 		}
// 
// 	}
// 	if (UseItem(eAIUseItemTypelive))
// 	{
// 		m_bNeedlive[target] = false;
// 		return true;
// 	}
// 	if (INDEXTYEP_CHARACTER == m_pUser->m_IndexType)
// 	{
// 		if (!m_pUserData->m_FightData.cannotSpesialSkill)
// 		{
// 			if (Cost(3009))
// 			{
// 				UseSkill(3009);
// 				m_bNeedlive[target] = false;
// 				m_bNeedAddHpHurt[target] -= 60;
// 				m_bNeedAddHp[target] -= 60;
// 				return true;
// 			}
// 			else if (Cost(3008))
// 			{
// 				UseSkill(3008);
// 				m_bNeedlive[target] = false;
// 				m_bNeedAddHpHurt[target] -= 30;
// 				m_bNeedAddHp[target] -= 30;
// 				return true;
// 			}
// 		}
// 	}
// 
// 	return false;







// 	if (m_bNeedAddHp[target] < 100 - m_HPLimit)
// 	{
// 		return true;
// 	}
// 
// 	SetUser(user);
// 	if (pUserList->m_WorkType > -1)return false;
// 	SetTarget(target);
// 	bool bHurt = false;
// 	if (m_pTargetData->m_HP2 < m_pTargetData->HPMax.GetData())
// 		bHurt = true;
// 	int start = 10;
// 	int end;
// 	if (target<10)start = 0;
// 	end = start + 10;
// 
// 	if (m_pUserPc)
// 	{
// 		if (!m_pUserData->m_FightData.cannotSpesialSkill)
// 		{
// 			if (Cost(3013))
// 			{
// 				UseSkill(3013);
// 				int star = target < 10 ? 0 : 10;
// 				for (int i = star; i < star + 10; ++i)
// 				{
// 					m_bNeedAddHp[i] -= 20;
// 					m_bNeedUnSeal[i] = false;
// 				}
// 				return true;
// 			}
// 			else if (Cost(3007))
// 			{
// // 				m_bNeedAddHpHurt[m_TargetID] -= 30;
// // 				m_bNeedAddHp[m_TargetID] -= 30;
// 				UseSkill(3007);
// 				int star = target < 10 ? 0 : 10;
// 				for (int i = star; i < star + 10; ++i)
// 				{
// 					m_bNeedAddHp[i] -= 30;
// 				}
// 				return true;
// 			}
// 		}
// 
// 		if (!m_pUserData->m_FightData.cannotMagic)
// 		{
// 			switch (m_pUserPc->m_PcData.m_MengPaiID)
// 			{
// 			case eMP_������:
// //			if (bHurt)
// 			{
// 				if (toall)
// 				{
// 					UseSkill(42);
// 					for (int i = start; i < end; i++)
// 						m_bNeedAddHp[i] -= 15;
// 					return true;
// 				}
// 				else
// 				{
// 					if (m_pUserData->m_Lv >= 120)
// 					{
// 						UseSkill(45);
// 						m_bNeedAddHp[target] = 0;
// 					}
// 					else
// 					{
// 						UseSkill(38);
// 						m_bNeedAddHp[target] -= 20;
// 					}
// 					return true;
// 				}
// 			}
// // 			else
// // 			{
// // 				if (toall)
// // 				{
// // 					UseMagic(40);
// // 					for (int i = start; i < end; i++)
// // 						m_bNeedAddHp[i] -= 30;
// // 					return true;
// // 				}
// // 				else
// // 				{
// // 					UseMagic(39);
// // 					m_bNeedAddHp[target] -= 60;
// // 					return true;
// // 				}
// // 			}
// 				break;
// 			case eMP_���ܵظ�:
// 			{
// 				SetTarget(findʬ��������());
// 				if (m_TargetID >= 0)
// 				{
// 					_isShiFudu[m_TargetID] = true;
// 					UseSkill(122);
// 					for (int i = start; i < end; i++)
// 						m_bNeedAddHp[i] -= 15;
// 					return true;
// 				}
// 			}
// 				break;
// 			case eMP_����ɽ:
// 				if (!m_pTarget->CheckHaveState(102))
// 				{
// 					UseSkill(102);
// 					m_bNeedAddHp[target] -= 15;
// 					return true;
// 				}
// 				else
// 				{
// 					UseSkill(115);
// 					m_bNeedAddHp[target] -= 45;
// 					return true;
// 				}
// 				break;
// 			case eMP_��ׯ��:
// 				if (!m_pTarget->CheckHaveState(91))
// 				{
// 					UseSkill(91);
// 					for (int i = start; i < end; i++)
// 						m_bNeedAddHp[i] -= 5;
// 					return true;
// 				}
// 				break;
// 			}
// 		}
// 	}
// 
// 	if (!m_pUserData->m_FightData.cannotUseItem && !cct::get()->isAtkMode(m_UserID))
// 	{
// 		bool haveall=false;
// 		if (m_pUserPc)
// 		{
// 			if (m_pUserPc->m_PcData.m_Items[1].GetNum())haveall = true;
// 		}
// 		else
// 		{
// 			if (!m_pUserData->m_Controler.CheckBB())return false;
// 			if (user - 5 < 0){
// 				ERRBOX(user - 5);
// 				return false;
// 			}
// 			cCharacter* pc = (cCharacter*)g_pMainState->m_FightWorkList[user-5].m_pObj->m_pIndex;
// 			if (pc)
// 			{
// 				if (pc->m_PcData.m_Items[1].GetNum())haveall = true;
// 			}
// 
// 		}
// 		if (toall&&haveall)
// 		{	
// 			UseItem(eAIUseItemTypeHPALL);
// 			for (int i = start; i < end; i++)
// 				m_bNeedAddHp[i] -= 40;
// 			return true;
// 		}
// 		else
// 		{
// 			if (bHurt)
// 			{
// 				if (UseItem(eAIUseItemTypeHPHurt) || UseItem(eAIUseItemTypeHP))
// 				{
// 					m_bNeedAddHp[target] -= 30;
// 					return true;
// 				}
// 			}
// 			else
// 			{
// 				if (UseItem(eAIUseItemTypeHP) || UseItem(eAIUseItemTypeHPHurt))
// 				{
// 					m_bNeedAddHp[target] -= 50;
// 					return true;
// 				}
// 			}
// 		}
//	}
//	return false;













// 	if (isCanAtk() && isPut() && selectAtk())
// 	{
// 		return true;
// 	}
// 	if (m_pUserData->m_FightData.cannotMagic || m_pUserData->m_FightData.cannotSpesialSkill)
// 	{
// //		if (!m_pUserPetData->Hide.d2)
// 		{
// 			if (!m_pUserData->m_FightData.cannotUseItem)
// 			{
// 				if (m_bNeedUnSeal[m_UserID])
// 				{
// //					if (CheckItem(eAIUseItemTypeUnseal))
// 					{
// 						SetTarget(m_UserID);
// 						if (UseItem(eAIUseItemTypeUnseal))
// 						{
// 							m_bNeedUnSeal[m_UserID] = false;
// 							return true;
// 						}
// 					}
// 				}
// 			}
// 		}
// 	}














// 	SetTarget(m_FightTarget[m_UserID]);
// 	bool isTasrget = (m_TargetID >= 0);
// 	int self = m_UserID < 10 ? 10 : 0;
// 	auto runPoxue = [&]()
// 	{
// 		if (isCanSpec() && Cost(3034))
// 		{
// 			if (m_TargetID < 0)
// 			{
// 				SetTarget(findTarget(300, true, m_UserID));
// 			}
// 			if (m_TargetID >= 0)
// 			{
// 				UseSkill(3034);
// 				return true;
// 			}
// 		}
// 		return false;
// 	};
// 
// 	auto isBlood10 = [&]()
// 	{
// 		return m_pUserData->m_HP > m_pUserData->HPMax.GetData() / 10;
// 	};
// 	
// 	auto isPofuBlood = [&]()
// 	{
// 		return m_pUserData->Atk.GetData() - m_pTargetData->Def.GetData() > m_pTargetData->m_HP;
// 	};
// 
// 	auto runPofuOfNoTarget = [&]()
// 	{
// 		if (isBlood10())
// 		{
// 			SetTarget(findTarget(150, true, m_UserID));
// 			if (m_TargetID >= 0)
// 			{
// 				UseSkill(7);
// 				return true;
// 			}
// 		}
// 		return false;
// 	};
// 
// 	auto runHengsao = [&]()
// 	{
// 		if (isBlood10())
// 		{
// 			if (m_TargetID < 0)
// 			{
// 				SetTarget(findTarget(400, true, m_UserID));
// 			}
// 			if (m_TargetID >= 0)
// 			{
// 				UseSkill(0);
// 				return true;
// 			}
// 		}
// 		return false;
// 	};
// 
// 
// 	if (m_TargetID >= 0)
// 	{
// 		if (isCanMag())
// 		{
// 			if (isPofuBlood() && isBlood10() && getVisibleNO() > 2)
// 			{
// 				return UseSkill(7);
// 			}
// 			if (!isAtkMode() && runHengsao())
// 			{
// 				return;
// 			}
// 			if (isBlood10() && getVisibleNO() > 2)
// 			{
// 				return UseSkill(7);
// 			}
// 		}
// 		if (isCanAtk() && isPut() && selectAtk())
// 		{
// 			return;
// 		}
// 		if (runPoxue())
// 		{
// 			return;
// 		}
// 	}
// 
// 	if (!isAtkMode())
// 	{
// 		if (isCanSpec() && RunLH())
// 		{
// 			return;
// 		}
// 		if (m_TargetID < 0 && isCanMag())
// 		{
// 			vector<POINT> out;
// 			if (g_pMainState->m_pFightState->_turn < 5)
// 			{
// 				finds(true, false, out, eET�ɷ�ϵ, m_UserID);
// 				auto out2 = check����(out, m_UserID);
// 				if (!out2.size() && rand() % 100 < 20)
// 				{
// 					out.clear();
// 					finds(true, false, out, eET����6, self);
// 					out2 = check����(out, m_UserID);
// 					if (out2.size())
// 					{
// 						SetTarget(out2.front());
// 						return UseSkill(6);
// 					}
// 				}
// 			}
// 
// 			finds(true, false, out, eET�ɷ�ϵ, self);
// 			if (out.size() > 2 && !m_pUser->CheckHaveState(8) &&
// 				!m_pUser->CheckHaveState(113) &&
// 				!m_pUser->CheckHaveState(2097) &&
// 				!m_pUser->CheckHaveState(3024) && 
// 				!m_pUser->CheckHaveState(3025))
// 			{
// 				if (isUseOtherRate())
// 				{
// 					SetTarget(m_UserID);
// 					return UseSkill(8);
// 				}
// 			}
// 		}
// 	}
// 	if (runPoxue())
// 	{
// 		return;
// 	}
// 	if (isPutRate() && selectAtk())
// 	{
// 		return;
// 	}
// 	int t = m_TargetID;
// 	if (RunPet() == 3 && isPetRate())
// 	{
// 		return;
// 	}
// 	m_TargetID = t;
// 	if (isCanMag() && getVisibleNO() > 2)
// 	{
// //		if (m_UserID < 10 || (m_UserID >= 10 && rand() % 100 < 70))
// 		if ((isAtkMode() && (m_UserID < 10 || (m_UserID >= 10 && rand() % 100 < 70))) || (!isAtkMode() && isPofuBlood()))
// 		{
// 			if (runPofuOfNoTarget())
// 			{
// 				return;
// 			}
// 		}
// 	}
// 	if (isCanMag() && runHengsao())
// 	{
// 		return;
// 	}
// 
// 	if (runUnSeal3000())
// 	{
// 		return;
// 	}
// 	if (!m_pUser->CheckHaveState(0) && !m_pUser->CheckHaveState(7))
// 	{
// 		return defense(m_UserID);
// 	}
















#if 0
SetTarget(m_FightTarget[m_UserID]);
int tOld = m_TargetID;
// 	bool bConduct = false;
// 	if (m_FightTarget[m_UserID] > -1)
// 	{
// 		SetTarget(m_FightTarget[m_UserID]);
// 		bConduct = true;
// 	}
// 	else SetTarget(-1);

if (!isAtkMode())
{
	if (isCanSpec() && RunLH())
	{
		return;
	}
	if (isCanMag())
	{
		//���ָ��Ŀ�������²���Ŀ��û�б��� ���Է�ӡĿ��
		char isM = -1;
		if (m_TargetID < 0 || (m_TargetID >= 0 && !FindδSeal(m_TargetID, isM)))
		{
			SetTarget(FindδSeal(isM));
		}
		if (m_TargetID >= 0 && (isM == 0 || isM == 1))
		{
			m_bSeal[m_TargetID] = true;
			return UseSkill(54);
		}
	}

	// 		if (!m_bSeal[m_TargetID])
	// 		{
	// 			if (!m_pTargetPetData->m_FightProperty.cannotMagic)
	// 			{
	// 				m_bSeal[m_TargetID] = true;
	//  				if (m_pUserPetData->m_Lv > 129)
	//  				{
	//  					return UseMagic(59);
	//  				}
	// 				return UseMagic(54);
	// 			}
	// 		}

}
// 	if ((cct::get()->isAtkMode(m_UserID) || (!cct::get()->isAtkMode(m_UserID) && rand() % 100 < 60)) && !m_pUserPetData->m_FightProperty.cannotUseItem)
// 	{//ʹ�ð���
// 		if (m_TargetID < 0)
// 		{
// 			SetTarget(g_pMainState->m_AI.findBattleTargetAndStepMiliSec(m_UserID, 4, true));
// 		}
// 		if (m_TargetID >= 0 && UseItem(eAIUseItemType����))
// 		{
// 			return;
// 		}
// 	}

int told = m_TargetID;
m_TargetID = tOld;
if (isPutRate() && selectAtk())
{
	return;
}
m_TargetID = told;

int t = m_TargetID;
if (RunPet() == 3 && isPetRate())
{
	return;
}
m_TargetID = t;
if (isCanMag() && rand() % 100 < 30)
{
	if (m_TargetID < 0)
	{
		SetTarget(g_pMainState->m_AI.find׷�������¹�(m_UserID, 4, true));
	}
	if (m_TargetID >= 0)
	{
		return UseSkill(50);
	}
}
if (!m_pUserData->m_FightData.cannotUseItem)
{
	if (m_TargetID < 0)
	{
		SetTarget(g_pMainState->m_AI.find׷�������¹�(m_UserID, 4, true));
	}
	if (m_TargetID >= 0 && UseItem(eAIUseItemType����))
	{
		return;
	}
}

// 	if (!m_pUserPetData->m_FightProperty.cannotMagic)
// 	{
// 		if (m_TargetID < 0)
// 		{
// 			SetTarget(g_pMainState->m_AI.findBattleTargetAndStepMiliSec(m_UserID, 4, true));
// 		}
// 		if (m_TargetID >= 0)
// 		{
// 			return UseMagic(50);
// 		}
// 	}
if (!runUnSeal3000())
{
	defense(m_UserID);
}
#endif















#if 0
// 	if (m_FightTarget[m_UserID] > -1)
// 	{
SetTarget(m_FightTarget[m_UserID]);
// 	}
// 	else SetTarget(-1);
// 	if (m_pUserPetData->m_AiLv > 80)
// 	if (!m_pUserPetData->m_FightProperty.cannotSkill)
// 	{
// 		if (m_pUserPetData->m_StrongLv > 70)
// 		{//Ц��
// 
// 			if (m_FightTarget[m_UserID] == -1)
// 			{
// 				int target = FindCpMaxTarget();
// 				if (target > -1)
// 				{
// 					SetTarget(target);
// 
// 					if (m_pTarget->m_IndexType == INDEXTYEP_CHARACTER)
// 					{
// 						cCharacter* pc = (cCharacter*)m_pTarget->m_pIndex;
// 						if (pc->m_PCData.m_CP > 100)
// 						{
// 
// 							if (CheckCanSkill(3016))return UseMagic(3016);//Ц��
// 						}
// 					}
// 				}
// 			}
// 		}
// 	}

auto runLuoleifu = [&]()
{
	if (!m_pUserData->m_FightData.cannotMagic)
	{
		if (m_TargetID < 0)
		{
			//				SetTarget(g_pMainState->m_AI.findBattleTargetAndStepMiliSec(m_UserID, 4, true));
			SetTarget(findTarget(100, false, m_UserID));
		}
		if (m_TargetID >= 0)
		{
			UseSkill(28);
			return true;
		}
	}
	return false;
};

if (!isAtkMode())
{
	if (isCanSpec() && RunLH())
	{
		return;
	}
	int self = m_UserID < 10 ? 10 : 0;
	if (isCanMag())
	{
		if (m_TargetID < 0)
		{
			vector<POINT> out;
			finds(true, false, out, eET�ɷ�ϵ, self);
			if (out.size() > 2 && !m_pUser->CheckHaveState(26) && !m_pUser->CheckHaveState(113))
			{
				if (isUseOtherRate())
				{
					SetTarget(m_UserID);
					return UseSkill(26);
				}
			}
		}
		char isM = -1;
		if (m_TargetID < 0 || (m_TargetID >= 0 && !FindδSeal(m_TargetID, isM)))
		{
			SetTarget(FindδSeal(isM));
		}
		if (m_TargetID >= 0 && isM >= 0)
		{
			m_bSeal[m_TargetID] = true;
			return UseSkill(isM == 1 ? 15 : (isM == 0 ? 21 : 17));
		}
		vector<POINT> out;
		finds(true, false, out, eET��ӡ����, self, 27);
		auto out2 = check����(out, m_UserID);
		if (out2.size() > 2)
		{
			SetTarget(out2.front());
			return UseSkill(27);
		}
	}
}
// 		if (m_pUserPetData->m_Lv >= 120 && !m_pUser->CheckHaveState(26))
// 		{
// 			SetTarget(m_UserID);
// 			return UseMagic(26);
// 		}

int t = m_TargetID;
if (RunPet() == 4 && isPetRate())
{
	return;
}
m_TargetID = t;
if (isCanMag())
{
	if (runLuoleifu())
	{
		return;
	}
}
if (!runUnSeal3000())
{
	defense(m_UserID);
}


// 			if (target2 == -1)
// 			{//�з�ȫ��������.........
// 				if (m_bPKMode)
// 				{
// 					if (m_pUserPetData->m_Lv>129)
// 					{
// 						if (!m_pUser->CheckHaveState(26))
// 							return UseMagic(26);
// 						if (!m_pTarget->CheckHaveState(27))
// 							return UseMagic(27);
// 						return defense(m_UserID);
// 					}
// 				}
// 				else
// 					return UseMagic(28);
// 			}
// 			SetTarget(target2);
// 		}
// 	
// 		if (m_FightTarget[m_UserID] == -1)
// 		{
// 			if (!m_pTarget->CheckHaveState(15))
// 				return UseMagic(15);
// 		}
// 		else
// 		{
// 			//����ҷ��������͵Ķ໹�Ƿ����͵Ķ�
// 			int ouratknum = 0;
// 			int start, end;
// 			if (m_UserID < 10)start = 0;
// 			else start = 10;
// 			end = start + 10;
// 			cPetData* pPetdata;
// 			for (int i = start; i < end; i++)
// 			{
// 				g_pMainState->m_FightList[i].m_pData->GetDateP(pPetdata);
// 				if (pPetdata->m_AddPoint.atk> 2)
// 				{
// 					ouratknum += 1;
// 					continue;
// 				}
// 				if (pPetdata->m_AddPoint.mp > 2)
// 				{
// 					ouratknum -= 1;
// 					continue;
// 				}
// 			}
// 			if (ouratknum > 1)
// 			{
// 				return UseMagic(20);
// 			}
// 			else return UseMagic(14);
// 		}
// 		if (!m_pUserPetData->m_FightProperty.cannotUseItem)
// 		{
// 			if (CheckItem(eAIUseItemTypeMP)) { UseItem(eAIUseItemTypeMP); return; }
// 			if (CheckItem(eAIUseItemTypeMPALL)) { UseItem(eAIUseItemTypeMPALL); return; }
// 		}
// 	}else
// 	if (!m_pUserPetData->m_FightProperty.cannotUseItem)
// 	{
// 		if (CheckItem(eAIUseItemTypeUnseal)){ UseItem(eAIUseItemTypeUnseal); return; }
// 	}

#endif




















#if 0
// 	if (m_FightTarget[m_UserID] > -1)
// 	{
SetTarget(m_FightTarget[m_UserID]);
// 	}
// 	else SetTarget(-1);
//��˫ר��

auto runjjyy = [&]()
{
	if (!m_pUserData->m_FightData.cannotMagic)
	{
		if (m_TargetID < 0)
		{
			SetTarget(g_pMainState->m_AI.find׷�������¹�(m_UserID, 4, true));
		}
		if (m_TargetID >= 0)
		{
			UseSkill(31);
			return true;
		}
	}
	return false;
};

if (!isAtkMode())
{
	//ʹ�÷���
	vector<POINT> tList;

	auto hf = [&](int i)
	{
		//��ջ���
		int rr = finds(true, false, tList, eET�Ͻ��33, m_UserID, 33);
		if (rr > i && tList.size())
		{
			SetTarget(tList[0].x);
			UseSkill(33);
			return true;
		}
		return false;
	};

	int self = m_UserID < 10 ? 10 : 0;
	auto ht = [&](int i)
	{
		//���Է�����
		finds(true, false, tList, eET������ϵ, self);
		if (tList.size() >= 2)
		{
			tList.clear();
			//��ջ���
			finds(true, false, tList, eET�����, m_UserID, 35);
			if (tList.size() > i)
			{
				SetTarget(tList[0].x);
				UseSkill(35);
				return true;
			}
		}
		return false;
	};
	if (isCanMag())
	{
		if (hf(2))
		{
			return;
		}
	}

	if (isCanSpec() && RunLH())
	{
		return;
	}

	if (isCanMag())
	{
		if (ht(2))
		{
			return;
		}

		// ���ޱ�
		finds(true, false, tList, eET���ޱ�46, m_UserID, 46);
		if (tList.size())
		{
			SetTarget(tList[0].x);
			return UseSkill(46);
		}

		//Τ�ӻ���
		finds(true, false, tList, eET������ϵ, m_UserID, 34);
		if (tList.size() > 2)
		{
			SetTarget(tList[0].x);
			return UseSkill(34);
		}

		if (hf(0))
		{
			return;
		}

		if (ht(0))
		{
			return;
		}
	}
}
int t = m_TargetID;
if (RunPet() == 4 && isPetRate())
{
	return;
}
m_TargetID = t;
if (isCanMag())
{
	if (runjjyy())
	{
		return;
	}
}

if (!runUnSeal3000())
{
	defense(m_UserID);
}
#endif














#if 0
if (!isAtkMode() && isCanSpec() && RunLH())
{
	return;
}
int t = m_TargetID;
if (RunPet() == 4 && isPetRate())
{
	return;
}
m_TargetID = t;
if (m_FightTarget[m_UserID] >= 0)
{
	SetTarget(m_FightTarget[m_UserID]);
}
else
{
	SetTarget(g_pMainState->m_AI.find׷�������¹�(m_UserID, 4, true));
}
if (m_TargetID >= 0 && !m_pUserData->m_FightData.cannotMagic)
{
	int n = getVisibleNO();
	if (n > 2)
	{
		if (m_UserID >= 10 && rand() % 100 < 20)
		{
			return UseSkill(88);
		}
		return UseSkill(80);
	}
	return UseSkill(88);
}
if (!runUnSeal3000())
{
	defense(m_UserID);
}

// 	int start, end;
// 	if (m_UserID<10)start = 10;
// 	else start = 0;
// 	end = start + 10;
// 	switch (g_pMainState->GetLiveNum(start, end))
// 	{
// 	case 1://����
// 		if (m_pUserPetData->m_AiLv > 90)
// 		if (m_pUserPetData->CheckHavePetSkill(2101))
// 		{
// 			return UseMagic(2101);
// 		}
// 		return UseMagic(79);
// 		break;
// 	case 2://����
// 		if (m_pUserPetData->m_Lv > 109)
// 			return UseMagic(88);
// 	default://����
// 		return UseMagic(80);
// 		break;
// 	}

#endif
















#if 0
// 	if (m_FightTarget[m_UserID] > -1)
// 	{
SetTarget(m_FightTarget[m_UserID]);
// 	}
// 	else SetTarget(-1);
// 	if (!m_pUserPetData->m_FightProperty.cannotSkill)
// 	{
// 	}

auto runLeitingwanjun = [&]()
{
	if (m_pUserData->PointMag >= m_pUserData->PointStr)
	{
		if (m_TargetID < 0)
		{
			//				SetTarget(FindDefminTarget(eProPerty����, false));
			SetTarget(findTarget(100, false, m_UserID));
		}
		if (m_TargetID >= 0)
		{
			UseSkill(74);
			return true;
		}
	}
	else
	{
		if (m_TargetID < 0)
		{
			//				SetTarget(FindDefminTarget(eProPerty����, false));
			SetTarget(findTarget(100, true, m_UserID));
		}
		if (m_TargetID >= 0)
		{
			UseSkill(71);
			return true;
		}
	}
	return false;
};

if (!isAtkMode())
{
	if (isCanSpec() && RunLH())
	{
		return;
	}
	if (isCanMag())
	{
		if (rand() % 100 < 20)
		{
			if (m_TargetID < 0)
			{
				SetTarget(FindDefminTarget(eProPerty��Ѫ, true));
			}
			if (m_TargetID >= 0 && m_pTargetData->m_HP > m_pUserData->m_Lv * 50 && m_pTargetData->m_HP > 6000)
			{
				return UseSkill(72);
			}
		}
		char isM = -1;
		if (m_TargetID < 0 || (m_TargetID >= 0 && !FindδSeal(m_TargetID, isM)))
		{
			SetTarget(FindδSeal(isM));
		}
		if (m_TargetID >= 0 && isM >= 0)
		{
			m_bSeal[m_TargetID] = true;
			return UseSkill(isM == 1 ? 68 : (isM == 0 ? 69 : 67));
		}
	}
}
int t = m_TargetID;
int p = RunPet();
if ((p == 3 || p == 4) && isPetRate())
{
	return;
}
m_TargetID = t;
if (isCanMag())
{
	if (runLeitingwanjun())
	{
		return;
	}
}

if (!runUnSeal3000())
{
	defense(m_UserID);
}
// 
// 	if (!m_pUserPetData->m_FightProperty.cannotMagic)
// 	{
// 		if (g_pMainState->m_FightList[10].isExist)
// 		{
// 			cPetData* ppetdata;
// 			g_pMainState->m_FightList[10].m_pData->GetDateP(ppetdata);
// 			if (ppetdata->m_HP > m_pUserPetData->m_Lv * 200)
// 			{
// 				SetTarget(10);
// 				if (!CheckCanSkill(72))
// 				{
// 					SetTarget(m_UserID);
// 					if (CheckItem(eAIUseItemTypeMP)) { UseItem(eAIUseItemTypeMP); return; }
// 					if (CheckItem(eAIUseItemTypeMPALL)){ UseItem(eAIUseItemTypeMPALL); return; }
// 
// 					if (m_pUserPetData->m_ProPertyMag >= m_pUserPetData->m_Lv * 2)//ħ�칬
// 						return UseMagic(74);
// 					return defense(m_UserID);
// 				}
// 				return UseMagic(72);
// 			}
// 		}
// 		if (m_pUserPetData->m_ProPertyMag >= m_pUserPetData->m_Lv * 2)//���칬
// 		{
// 			if (m_FightTarget[m_UserID] == -1)
// 				SetTarget(FindAtkTarget(130));
// 			return  UseMagic(74);
// 		}
// 		else
// 		{
// //			if (m_pUserPetData->m_Lv > 129)
// 			{
// 				if (m_FightTarget[m_UserID] == -1)
// 					SetTarget(FindAtkTarget(110,false));
// 				return UseMagic(74);
// 			}
// //			else
// 			{
// 				if (m_FightTarget[m_UserID] == -1)
// 				{
// 					int start, end;
// 					if (m_UserID < 10)start = 10;
// 					else start = 0;
// 					end = start + 10;
// 					SetTarget(FindDefminTarget(start,end,eProPerty��Ѫ,true));
// 				}
// 				if (m_pTargetPetData->m_HP > m_pUserPetData->m_Lv * 200)
// 					return UseMagic(71);
// 				else
// 				{
// 					m_bSeal[m_TargetID] = true;
// 					return UseMagic(68);
// 				}
// 			}
// 		}
// 	}
// 	if (!m_pUserPetData->m_FightProperty.cannotMagic)
// 	{
// // 		if (m_pUserPetData->m_AddPoint.atk > 2)//���칬
// // 		{
// // 			if (m_FightTarget[m_UserID] == -1)
// // 				SetTarget(FindAtkTarget(100));
// // 			return NormalAtk();
// // 
// // 		}
// 
// 		if (m_pUserPetData->m_ProPertyMag >= m_pUserPetData->m_Lv * 2)//���칬
// 		{
// 			if (m_FightTarget[m_UserID] == -1)
// 				SetTarget(FindAtkTarget(130));
// 			return  UseMagic(74);
// 		}
// 	}
// 	defense(m_UserID);

#endif



















#if 0
// 	if (m_FightTarget[m_UserID] > -1)
// 	{
SetTarget(m_FightTarget[m_UserID]);
// 	}
// 	else SetTarget(-1);
auto runYanyujianfa = [&]()
{
	if (m_pUserData->m_HP > m_pUserData->HPMax.GetData() / 10)
	{
		if (m_TargetID < 0)
		{
			//				SetTarget(FindDefminTarget(eProPerty����, false));
			SetTarget(findTarget(200, true, m_UserID));
		}
		if (m_TargetID >= 0)
		{
			UseSkill(97);
			return true;
		}
	}
	return false;
};

auto runPiaomiaoshi = [&]()
{
	if (m_TargetID < 0)
	{
		//			SetTarget(FindDefminTarget(eProPerty����, false));
		SetTarget(findTarget(100, true, m_UserID));
	}
	if (m_TargetID >= 0)
	{
		UseSkill(98);
		return true;
	}
	return false;
};

if (!isAtkMode())
{
	if (isCanSpec() && RunLH())
	{
		return;
	}
	if (isCanMag())
	{
		char isM = -1;
		if (m_TargetID < 0 || (m_TargetID >= 0 && !FindδSeal(m_TargetID, isM)))
		{
			SetTarget(FindδSeal(isM));
		}
		else
		{
			isM = 0;
		}
		if (m_TargetID >= 0 && isM >= 0)
		{
			m_bSeal[m_TargetID] = true;
			return UseSkill(89);
		}
	}
}
int t = m_TargetID;
if (RunPet() == 3 && isPetRate())
{
	return;
}
m_TargetID = t;
if (isCanMag())
{
	int n = getVisibleNO();
	if (m_TargetID >= 0 || n < 3 || (m_UserID >= 10 && rand() % 100 < 30))
	{
		if (runYanyujianfa())
		{
			return;
		}

	}
	if (runPiaomiaoshi())
	{
		return;
	}
}
if (!runUnSeal3000())
{
	defense(m_UserID);
}

// 		m_bSeal[m_TargetID] = true;
// 		if (m_pUserPetData->m_ProPertyAtk >= m_pUserPetData->m_Lv * 2)//�ǲ��ǽ���ׯ
// 		{
// 			int n = g_pMainState->GetLiveNum(m_UserID < 10 ? 10 : 0, m_UserID < 10 ? 20 : 10);
// 			if (n > 2 || (n <= 2 && (rand() & n) > 0))
// 			{
// 				SetTarget(FindDefminTarget(m_UserID < 10 ? 10 : 0, m_UserID < 10 ? 20 : 10, eProPerty��Ѫ, true));
// 				return UseMagic(98);
// 			}
// 			else if (m_pUserPetData->m_HP > m_pUserPetData->m_HPMax.GetData() * 50 / 100)
// 			{//����
// 				if (m_TargetID == -1)SetTarget(FindAtkTarget(200));
// 				if (!m_pUserPetData->m_FightProperty.cannotAttack)
// 				if (m_pTargetPetData->m_HP < m_pUserPetData->m_ATK.GetData() - m_pTargetPetData->m_DEF.GetData())
// 					return NormalAtk();
// 				return UseMagic(97);
// 			}
// 			else
// 			{
// 				//����֮Ȫ
// 				if (m_pUser->CheckHaveState(91))
// 				{
// 					SetTarget(m_UserID);
// 					return UseMagic(91);
// 				}
// 				else return NormalAtk();
// 			}
// 		}
// 		if (m_TargetID == -1)
// 		{
// 			int start, end;
// 			if (m_UserID < 10)start = 11;
// 			else start = 1;
// 			end = start + 9;
// 			if (m_bPKMode)//�չ�Ǭ���ڷ�PKʱ�޷�������
// 			{
// 				start -= 1;
// 				end -= 5;
// 			}
// 			int target2= FindUnSeal(start, end);
// 			if (target2 == -1)
// 			{
// 				SetTarget(m_UserID);
// 				if (m_pUser->CheckHaveState(91))return UseMagic(91);
// 				SetTarget(FindAtkTarget(200));
// 				if (!m_pUserPetData->m_FightProperty.cannotAttack)
// 				if (m_pTargetPetData->m_HP < m_pUserPetData->m_ATK.GetData() - m_pTargetPetData->m_DEF.GetData())
// 					return NormalAtk();
// 				return UseMagic(97);
// 			}
// 			SetTarget(target2);
// 		}
// 		m_bSeal[m_TargetID] = true;
// 		return UseMagic(89);//����
// 	}
// 	
// 	if (!m_pUserPetData->m_FightProperty.cannotAttack)
// 	{
// 		if (m_pUserPetData->m_AddPoint.atk > 2)
// 		{
// 			if (m_TargetID == -1)SetTarget(FindAtkTarget(100));
// 			return NormalAtk();
// 		}
// 	}
// 
// 	if (!m_pUserPetData->m_FightProperty.cannotUseItem)
// 	{
// 		if (CheckItem(eAIUseItemTypeHP)){ UseItem(eAIUseItemTypeHP); return; }
// 	}
// 	return defense(m_UserID);
#endif 
















#if 0
// 	if (m_FightTarget[m_UserID] > -1)
// 	{
SetTarget(m_FightTarget[m_UserID]);
// 	}
// 	else SetTarget(-1);
// 	if (!m_pUserPetData->m_FightProperty.cannotAttack)
// 	{
// 	}
// 	if (!m_pUserPetData->m_FightProperty.cannotSkill)
// 	{
// 	}

auto runWuxing = [&]()
{
	if (m_TargetID < 0)
	{
		SetTarget(g_pMainState->m_AI.find׷�������¹�(m_UserID, 4, true));
	}
	if (m_TargetID >= 0)
	{
		UseSkill(105 + rand() % 5);
		return true;
	}
	return false;
};

if (!isAtkMode())
{
	if (isCanSpec() && RunLH())
	{
		return;
	}
}
int self = m_UserID < 10 ? 10 : 0;
if (!isAtkMode() && isCanMag())
{
	vector<POINT> outMself;
	finds(true, false, outMself, eET�ɷ�ϵ, self);

	vector<POINT> outMuser;
	finds(true, false, outMuser, eET�ɷ�ϵ, m_UserID);

	vector<POINT> outLd;
	int rr = finds(true, false, outLd, eET���鶯112, m_UserID, 112);
	auto out2 = check����(outLd, m_UserID);
	// 		if (out2.size() < rr)
	// 		{
	// 			rr = out2.size();
	// 		}

	if (outMself.size() > 2 || outMuser.size()/* || rr > 2*/)
	{
		if (out2.size())
		{
			SetTarget(out2.front());
			return UseSkill(112);
		}
	}

	vector<POINT> out;
	finds(true, false, out, eET�ߵ�����113, m_UserID, 113);
	auto out3 = check����(out, m_UserID);
	if (out3.size() && outMself.size())
	{
		SetTarget(out3.front());
		return UseSkill(113);
	}

	if (out2.size())
	{
		SetTarget(out2.front());
		return UseSkill(112);
	}
	if (runWuxing())
	{
		return;
	}
}
int t = m_TargetID;
if (RunPet() == 4 && isPetRate())
{
	return;
}
m_TargetID = t;
if (isCanMag())
{
	if (runWuxing())
	{
		return;
	}
}
if (!runUnSeal3000())
{
	defense(m_UserID);
}

#endif 














#if 0
// 	if (m_FightTarget[m_UserID] > -1)
// 	{
SetTarget(m_FightTarget[m_UserID]);
int tOld = m_TargetID;
// 	}
// 	else SetTarget(-1);
// 	if (!m_pUserPetData->m_FightProperty.cannotSkill)
// 	{
// 		if ((!m_pUserPetData->m_FightProperty.cannotSkill) && m_pUserPetData->m_AiLv > 90)
// 		{
// 			if (m_pUserPetData->m_ProPertyAtk >= m_pUserPetData->m_Lv * 2)//���ظ�
// 			{
// 				if (CheckCanSkill(3034))
// 				{
// 					if (m_FightTarget[m_UserID] == -1)
// 						SetTarget(FindAtkTarget(200));
// 					return UseMagic(3034);
// 				}
// 			}
// 		}
// 	}
// 	if (!m_pUserPetData->m_FightProperty.cannotAttack)
// 	{
// 		if (m_pUserPetData->m_AddPoint.atk > 2)//���ظ�
// 		{
// 			if (m_FightTarget[m_UserID] == -1)
// 				SetTarget(FindAtkTarget(150));
// 			return NormalAtk();
// 		}
// 	}

auto runYanluoling = [&]()
{
	if (m_TargetID < 0)
	{
		SetTarget(g_pMainState->m_AI.find׷�������¹�(m_UserID, 4, true));
	}
	if (m_TargetID >= 0)
	{
		UseSkill(getVisibleNO() > 1 ? 116 : 117);
		return true;
	}
	return false;
};

int self = m_UserID < 10 ? 10 : 0;

auto runGuiyan = [&](int n)
{
	vector<POINT> outMself;
	finds(true, false, outMself, eET�ٶ����2, self);
	auto out2 = check����(outMself, m_UserID);
	if (outMself.size() != out2.size())
	{
		finds(true, false, outMself, eET����120, m_UserID);
		if (outMself.size() > n)
		{
			SetTarget(outMself.front().x);
			UseSkill(120);
			return true;
		}
	}
	return false;
};

auto runGuiyanSeal = [&](int n)
{
	vector<POINT> outMself;
	finds(true, false, outMself, eET�ɷ�ϵ, self);
	auto out2 = check����(outMself, m_UserID);
	if (out2.size() > 1)
	{
		finds(true, false, outMself, eET����120, m_UserID);
		if (outMself.size() > n)
		{
			SetTarget(outMself.front().x);
			UseSkill(120);
			return true;
		}
	}
	return false;
};

if (!isAtkMode())
{
	if (isCanSpec() && RunLH())
	{
		return;
	}
	if (isCanMag())
	{
		if (runGuiyanSeal(5))
		{
			return;
		}

		if (runGuiyan(5))
		{
			return;
		}

		// 		int yinshen = 0;
		// 		//		int guiyan = 0;
		// 		int star = m_UserID < 10 ? 10 : 0;
		// 		for (int i = star; i < star + 10; ++i)
		// 		{
		// 			if (!g_pMainState->m_FightList[i].isExist || g_pMainState->m_FightList[i].CheckDie())
		// 			{
		// 				continue;
		// 			}
		// 			cPetData *data = nullptr;
		// 			g_pMainState->m_FightList[i].m_pData->GetDateP(data);
		// 			if (!data)
		// 			{
		// 				continue;
		// 			}
		// 			if (data->PeopleSpecial.d2 > 0)
		// 			{
		// 				++yinshen;
		// 			}
		// 		}
		// 		int star = m_UserID < 10 ? 0 : 10;
		// 		for (int i = star; i < star + 10; ++i)
		// 		{
		// 			if (!g_pMainState->m_FightList[i].isExist || g_pMainState->m_FightList[i].CheckDie())
		// 			{
		// 				continue;
		// 			}
		// 			cPetData *data = nullptr;
		// 			g_pMainState->m_FightList[i].m_pData->GetDateP(data);
		// 			if (!data)
		// 			{
		// 				continue;
		// 			}
		// 			if (data->PeopleSpecial.d1 > 0)
		// 			{
		// 				++guiyan;
		// 			}
		// 		}
		// 		if (yinshen > 0 && !m_pUserPetData->PeopleSpecial.d1)
		// 		{
		// 			SetTarget(m_UserID);
		// 			return UseMagic(120);
		// 		}

		if (m_TargetID < 0)
		{
			vector<POINT> out;
			int rr = finds(true, false, out, eET�����ɢ127, self);
			auto out2 = check����(out, m_UserID);
			if (rr > 0 && out2.size())
			{
				SetTarget(out2.front());
				return UseSkill(127);
			}

			finds(true, false, out, eET������129, self);
			out2 = check����(out, m_UserID);
			if (out2.size())
			{
				SetTarget(out2.front());
				return UseSkill(129);
			}

			if (runGuiyanSeal(1))
			{
				return;
			}
			if (runGuiyan(1))
			{
				return;
			}

			finds(true, false, out, eET��Ȫ֮Ϣ126, self, 126);
			out2 = check����(out, m_UserID);
			if (out2.size() > 3)
			{
				SetTarget(out2.front());
				return UseSkill(126);
			}
		}
	}
}
int told = m_TargetID;
m_TargetID = tOld;
if (isPutRate() && selectAtk())
{
	return;
}
m_TargetID = told;
int t = m_TargetID;
if (RunPet() == 3 && isPetRate())
{
	return;
}
m_TargetID = t;
if (isCanMag())
{
	if (runYanluoling())
	{
		return;
	}
}
if (!runUnSeal3000())
{
	defense(m_UserID);
}

// 		int start, end;
// 		if (m_TargetID<10)start = 0;
// 		else start = 10;
// 		end = start + 10;
// 		if (g_pMainState->GetLiveNum(start, end) > 1)
// 		{
// 			SetTarget(g_pMainState->m_AI.findBattleTargetAndStepMiliSec(m_UserID, 4));
// 			return UseMagic(116);
// 		}
// 		else
// 		{
// 			SetTarget(g_pMainState->m_AI.findBattleTargetAndStepMiliSec(m_UserID, 4));
// 			UseMagic(117);
// 		}
// 	}
// 
// 
// 	if (!m_pUserPetData->m_FightProperty.cannotSkill && m_pUserPetData->m_ProPertyAtk > m_pUserPetData->m_Lv * 2)
// 	{
// 		if (CheckCanSkill(3034))
// 		{
// 			if (m_TargetID < 0)
// 			{
// 				SetTarget(FindAtkTarget(300, true, m_UserID));
// 				if (m_TargetID >= 0)
// 				{
// 					return UseMagic(3034);
// 				}
// 			}
// 		}
// 	}
// 
// 	if (!m_pUserPetData->m_FightProperty.cannotAttack)
// 	{
// 		if (m_TargetID < 0)
// 		{
// 			SetTarget(FindAtkTarget(100, true, m_UserID));
// 			if (m_TargetID >= 0)
// 			{
// 				return NormalAtk();
// 			}
// 		}
// 	}
// 
// 	if (m_pUserPetData->m_FightProperty.cannotMagic &&
// 	return defense(m_UserID);
#endif












#if 0
// 	bool bConduct = false;
// 	if (m_FightTarget[m_UserID] > -1)
// 	{
SetTarget(m_FightTarget[m_UserID]);
int tOld = m_TargetID;
// 		bConduct = true;
// 	}
// 	else SetTarget(-1);

auto runTianluodiwang = [&]()
{
	if (!m_pUserData->m_FightData.cannotMagic)
	{
		if (m_TargetID < 0)
		{
			SetTarget(g_pMainState->m_AI.find׷�������¹�(m_UserID, 4, true));
		}
		if (m_TargetID >= 0)
		{
			UseSkill(162);
			return true;
		}
	}
	return false;
};

auto runGouhun = [&]()
{
	if (m_pUserData->m_HP * 100 / m_pUserData->m_HP2 < 60)
	{
		if (m_TargetID < 0)
		{
			SetTarget(FindDefminTarget(eProPerty��Ѫ, true));
		}
		if (m_TargetID >= 0)
		{
			UseSkill(154);
			return true;
		}
	}
	return false;
};

int self = m_UserID < 10 ? 10 : 0;
if (!isAtkMode())
{
	if (isCanSpec() && RunLH())
	{
		return;
	}
	if (isCanMag())
	{
		if (m_TargetID < 0)
		{
			vector<POINT> outMself;
			finds(true, false, outMself, eET�ɷ�ϵ, self);
			if (outMself.size() > 2 && isUseOtherRate() &&
				!m_pUser->CheckHaveState(166) &&
				!m_pUser->CheckHaveState(2097) &&
				!m_pUser->CheckHaveState(3024) &&
				!m_pUser->CheckHaveState(3025))
			{
				SetTarget(m_UserID);
				return UseSkill(166);
			}
		}

		char isM = -1;
		if (m_TargetID < 0 || (m_TargetID >= 0 && !FindδSeal(m_TargetID, isM)))
		{
			SetTarget(FindδSeal(isM));
		}
		if (m_TargetID >= 0 && (isM == 0 || isM == 1))
		{
			m_bSeal[m_TargetID] = true;
			return UseSkill(159);
		}

		//		if (m_pUser->CheckHaveState(166))
		// 		{
		// 
		// 		}
		// 		if (m_pUserPetData->m_Lv >= 120)
		// 		{
		// 			SetTarget(m_UserID);
		// 			return UseMagic(166);
		// 		}

		vector<POINT> outMself;
		finds(true, false, outMself, eET������129, self);
		auto out2 = check����(outMself, m_UserID);
		if (out2.size())
		{
			SetTarget(out2.front());
			return UseSkill(156);
		}

		if (runGouhun())
		{
			return;
		}

		if (m_TargetID < 0)
		{
			vector<POINT> outMself;
			finds(true, false, outMself, eET������ϵ, self);
			if (outMself.size() > 2 && !m_pUser->CheckHaveState(160))
			{
				SetTarget(m_UserID);
				return UseSkill(160);
			}
		}
	}

	// 		if ((m_pUserPetData->m_MP * 100 / m_pUserPetData->m_MPMax.GetData() < 5) || (m_pUserPetData->m_MP < 80))
	// 		{
	// 			if (m_TargetID < 0)
	// 			{
	// 				SetTarget(FindDefminTarget(eProPertyħ��, true));
	// 			}
	// 			if (m_TargetID >= 0)
	// 			{
	// 				return UseMagic(155);
	// 			}
	// 		}


}

int told = m_TargetID;
m_TargetID = tOld;
if (isPutRate() && selectAtk())
{
	return;
}
m_TargetID = told;
int t = m_TargetID;
if (RunPet() == 3 && isPetRate())
{
	return;
}
m_TargetID = t;

if (isCanMag() && runGouhun())
{
	return;
}

if (runTianluodiwang())
{
	return;
}
if (!runUnSeal3000())
{
	defense(m_UserID);
}

// 	bool bCanMagic, bCanAtk,bCanSkill;
// 	bCanMagic = !m_pUserPetData->m_FightProperty.cannotMagic;
// 	bCanAtk = !m_pUserPetData->m_FightProperty.cannotAttack;
// 	bCanSkill = !m_pUserPetData->m_FightProperty.cannotSkill;
// 	if (m_pUserPetData->m_ProPertyAtk >= m_pUserPetData->m_Lv * 2)//����˿
// 	{
// 		if (m_FightTarget[m_UserID] == -1)
// 			SetTarget(FindAtkTarget(150));
// 		if (bCanAtk)
// 		{
// 			if(!bCanMagic)return NormalAtk();
// 			if (m_pUserPetData->m_ATK.GetData() - m_pTargetPetData->m_DEF.GetData() > m_pUserPetData->m_Lv * 5)
// 				return NormalAtk();
// 			else
// 				return UseMagic(162); //���޵���
// 		}
// 		else
// 		{
// 			if (bCanMagic)UseMagic(162); //���޵���
// 		}
// 		
// 	}
// 
// 	if (bCanMagic)
// 	{//����ʹ��ħ���������
// 		if (bConduct)
// 		{//���ָ��Ŀ�������²���Ŀ��û�б��� ���Է�ӡĿ��
// 			if (!m_bSeal[m_TargetID])
// 			{
// 				if (!m_pTargetPetData->m_FightProperty.cannotMagic)
// 				{
// 					m_bSeal[m_TargetID] = true;
// 					return UseMagic(159);
// 				}
// 
// 			}
// 			else
// 			{
// 				if (!m_bPKMode)
// 					return UseMagic(162); //���޵���
// 				else
// 					return UseMagic(155);//����
// 			}
// 		}
// 		if (!m_bPKMode)
// 		{
// 			if (m_FightTarget[m_UserID] == -1)
// 				SetTarget(g_pMainState->m_AI.findBattleTargetAndStepMiliSec(m_UserID, 4));
// 			return UseMagic(162); //���޵���
// 		}
// 		//PK
// 		if (m_FightTarget[m_UserID] == -1)
// 		{
// 			int unsealtarget = FindUnSeal(5);
// 			if (unsealtarget == -1)
// 			{//���еĵ��˶�������?
// 				SetTarget(g_pMainState->m_AI.findBattleTargetAndStepMiliSec(m_UserID, 4));
// 			}
// 			else
// 			{
// 				SetTarget(unsealtarget);
// 				return UseMagic(159);
// 			}
// 		}
//	}
//	return defense(m_UserID);
#endif



















#if 0
if (!isAtkMode() && isCanSpec() && RunLH())
{
	return;
}
int t = m_TargetID;
if (RunPet() == 4 && isPetRate())
{
	return;
}
m_TargetID = t;
if (m_FightTarget[m_UserID] > -1)
{
	SetTarget(m_FightTarget[m_UserID]);
}
else SetTarget(g_pMainState->m_AI.find׷�������¹�(m_UserID, 4, true));

int self = m_UserID < 10 ? 10 : 0;
if (!m_pUserData->m_FightData.cannotMagic)
{
	if (!m_pUserData->Hide.d2)
	{
		vector<POINT> outMself;
		finds(true, false, outMself, eET�ٶ����2, self);
		auto out2 = check����(outMself, m_UserID);
		if (outMself.size() != out2.size())
		{
			if (out2.size() < 3)
			{
				SetTarget(m_UserID);
				return UseSkill(133);
			}
		}
	}
	return UseSkill((getVisibleNO() <= 1 || (m_UserID >= 10 && rand() % 100 < 20)) ? 132 : 131);
}
if (!runUnSeal3000())
{
	defense(m_UserID);
}


// 	int start, end;
// 	if (m_UserID<10)start = 10;
// 	else start = 0;
// 	end = start + 10;
// 	if (g_pMainState->GetLiveNum(start, end) > 1)
// 	{//��ɰ��ʯ	
// 		return UseMagic(131);
// 	}
// 	else
// 	{//��ζ���
// 		return UseMagic(132);
// 	}
#endif
























#if 0
if (!isAtkMode() && isCanSpec() && RunLH())
{
	return;
}
SetTarget(m_FightTarget[m_UserID]);

auto get145Times = [&]()
{
	for (list<sBuff>::iterator it = m_pUser->m_StateList.begin(); it != m_pUser->m_StateList.end(); it++)
	{
		if (it->ID == 145)
			return it->remainingTimes;
	}
	return -1;
};

auto isYingji = [&]()
{
	int n = getVisibleNO();
	return n > 3 || (n == 3 && rand() % 100 < 35);
};


auto runYingji = [&]()
{
	if (!m_pUserData->m_FightData.cannotMagic)
	{
		if (m_TargetID < 0)
		{
			SetTarget(findTarget(100, true, m_UserID));
		}
		if (m_TargetID >= 0)
		{
			UseSkill(142);
			return true;
		}
	}
	return false;
};

auto runShibo = [&]()
{
	if (!m_pUserData->m_FightData.cannotMagic)
	{
		if (m_TargetID < 0)
		{
			SetTarget(findTarget(250, true, m_UserID));
		}
		if (m_TargetID >= 0)
		{
			UseSkill(143);
			return true;
		}
	}
	return false;
};

auto runLianhuanji = [&]()
{
	if (!m_pUserData->m_FightData.cannotMagic)
	{
		if (m_TargetID < 0)
		{
			SetTarget(findTarget(500, true, m_UserID));
		}
		if (m_TargetID >= 0)
		{
			UseSkill(148);
			return true;
		}
	}
	return false;
};

int t = get145Times();
if (m_TargetID >= 0 && t >= 0 && runLianhuanji())
{
	return;
}
if (cct::get()->isAtkMode(m_UserID))
{
	if (t >= 0 && m_UserID >= 10 && rand() % 100 < 30 && runLianhuanji())
	{
		return;
	}
}

if (t >= 0 && isYingji() && runYingji())
{
	return;
}
if (t >= 0)
{
	if (t > 0 && runShibo())
	{
		return;
	}
	else if (t == 0 && runLianhuanji())
	{
		return;
	}
}
if (!m_pUserData->m_FightData.cannotSpesialSkill)
{
	if (Cost(3034))
	{
		if (m_TargetID < 0)
		{
			SetTarget(findTarget(300, true, m_UserID));
		}
		if (m_TargetID >= 0)
		{
			return UseSkill(3034);
		}
	}
}
if (!m_pUserData->m_FightData.cannotMagic)
{
	SetTarget(m_UserID);
	return UseSkill(145);
}

if (!m_pUserData->m_FightData.cannotAttack)
{
	if (m_TargetID < 0)
	{
		SetTarget(findTarget(100, true, m_UserID));
	}
	if (m_TargetID >= 0)
	{
		return NormalAtk();
	}
}

if (!m_pUser->CheckHaveState(142)/* && !m_pUser->CheckHaveState(148)*/)
{
	return defense(m_UserID);
}

#endif