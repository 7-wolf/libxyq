#include "_global.h"


bool cFightState::DoWork()
{
	m_FightMenu.ProcessAuto();
	cObj* pUser;
	cPropertyData* pUserData;
	// �ǣ���ע��
	switch (m_turn)
	{
	case 0: // 0 �ȴ�ָ�����
	{
		// �ȴ�����״̬ ��װ �������
		bool isOk = true;
		for (int i = 0; i < 20; ++i)
		{
			if (!m_pFightWorkList[i]->isExist)
			{
				continue;
			}
			if (m_pFightWorkList[i]->m_work.size())
			{
				isOk = false;
				break;
			}
		}
		if (!isOk)
		{
			break;
		}
	}
	m_FightMenu.m_NeedShow = true;
	m_FightMenu.ProcessInput();

	if (m_FightMenu._isAutoBattle)
	{
		m_FightMenu._timeWaiting = 0;
		m_turn = 10086;
	}

	for (int i = 0; i < 3; i++)
	{
		if (m_FullSkill.m_FullSkilUP[i].m_NeedShow)
		{
			m_FullSkill.m_FullSkilUP[i].m_NeedShow = false;
		}
	}
	break;
	case 10086:
	{
		if (m_FightMenu._isAutoBattle)
		{
			if (++m_FightMenu._timeWaiting > 300)
			{
				while (m_turn != 1)
				{
					if (m_FightMenu.m_NowFighterID >= 0)
					{
						if (m_FightMenu.CheckControl(m_FightMenu.m_NowFighterID))
						{
							m_FightMenu.RunQ();
						}
					}
					m_FightMenu.AddTurn();
				}
			}
		}
		else
		{
			m_turn = 1;
		}
	}
	break;
	case 1: // 1 �����ٶ�����AI��ʼ��
	if (_turn == 0)
	{
		m_FightMenu._tAutoTurn.SetString("��1�غ�");
		g_pMainState->m_AI.checkHero();
	}
	SortBySpeed();
	g_pMainState->m_TriggerFightTurn.Process();
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
	}

	if (g_StateType != STATE_FIGHT)return true;
	m_MiaoShu.SetTime(30);
//	g_pMainState->m_AI.Run();
//	g_pMainState->m_AI.resetNeed();
// 	g_pMainState->m_AI.GetNeed(0, 20);
// 	g_pMainState->m_AI.ZhiHui(false);
// 	g_pMainState->m_AI.ZhiHui(true);
// 	for (int i = 0; i < 20; i++)
// 	{
// 		g_pMainState->m_InterfaceDoor.m_TimeShiCheng.stepMiliSec();
// 		if (g_pMainState->m_FightList[i].isExist)
// 		if (g_pMainState->m_FightList[i].m_WorkType == -1)
// 		{
// 			g_pMainState->m_InterfaceDoor.m_TimeShiCheng.stepMiliSec();
// 			if (g_pMainState->m_FightList[i].m_pData->CheckHaveState(148) || g_pMainState->m_FightList[i].m_pData->CheckHaveState(142))
// 			{
// 				g_pMainState->m_AI.defense(i);
// 			}
// 			cPetData *data = nullptr;
// 			g_pMainState->m_FightList[i].m_pData->GetDateP(data);
// 			if (!data)
// 			{
// 				continue;
// 			}
// 			if (((cPCData*)data)->m_MengPaiID == eMP_ʨ����)
// 			{
// 				g_pMainState->m_AI.AutoRunAi(i);
// 			}
// 		}
// 	}
	m_FightMenu.m_NeedShow = false;
	m_CurrIDPerTurn = 0;
	m_turn += 1;
	case 2: // 2 ���ս�����������
		if (!g_pMainState->GetLiveNum(10, 20))
		{
			//սʤ��
			SuccessFight();
			return true;
		}
		if (!g_pMainState->GetLiveNum(0, 10))
		{
			//ս����
			FailFight();
			return true;
		}
		while (true)
		{
			if (m_CurrIDPerTurn > 19)
			{
				// �ж���� ׼����һ�غ�
				m_turn = 4;
				break;
			}
			int nowid = m_SpeedListPos[m_CurrIDPerTurn];
			// ���� ����һ���ж�ID
			sFightWork*& list = m_pFightWorkList[nowid];
			if (list->m_work.size())
				break;
// 			if (list->m_WorkType == -2)
// 				break;
			g_pMainState->m_InterfaceDoor.m_TimeShiCheng.stepMiliSec();
			// ���ID��δ�յ�ָ��
			if (list->isExist)
			{
				if (list->_myTurn == 0)
				{
					bool is0 = true;
					int start = nowid / 10 * 10;
					int end = start + 10;
					for (int i = start; i < end; ++i)
					{
						if (!m_pFightWorkList[i]->isExist)
						{
							continue;
						}
						if (m_pFightWorkList[i]->_myTurn > 0)
						{
							is0 = false;
							break;
						}
					}
					if (!is0)
					{
						// �ոձ��ٻ����� 
						// ��һ�غϾ��ٻ�ţ����ô��,������...
						m_CurrIDPerTurn += 1;
						if (m_CurrIDPerTurn == 20)
						{
							m_turn = 4;
							break;
						}
					}
					else if(list->m_WorkType == -1)
					{
						// AI�ж�ָ��
						g_pMainState->m_AI.AutoRunAi(nowid);
					}
				}
				else if (list->m_WorkType == -1)
				{
					// AI�ж�ָ��
					g_pMainState->m_AI.AutoRunAi(nowid);
				}
			}
			// �յ�ָ��ٴ��ж�ս���Ƿ����
			if (list->m_WorkType >= 0)
			{
				if (!g_pMainState->GetLiveNum(10, 20))
				{
					//սʤ��
					SuccessFight();
					return true;
				}
				if (!g_pMainState->GetLiveNum(0, 10))
				{
					//ս����
					FailFight();
					return true;
				}
				// �յ�ָ�������,û�취,��һ����
				if (list->CheckDie())
				{
					m_CurrIDPerTurn += 1;
					continue;
				}

				// ָ�������Ϊ��
				SetWork(nowid, list->m_WorkType);

				// ���ָ��
				list->m_WorkType = -1;


				m_turn += 1;
				break;
			}
			else
			{
				// ����û�յ�ָ����Űɣ���һ������
				m_CurrIDPerTurn += 1;
				if (m_CurrIDPerTurn == 20)
				{
					m_turn = 4;
					break;
				}
			}
		}
		break;
	case 3://�ȴ�1����ɫ�ж����
	{
		int i3 = 0;
		for (; i3 < 20; i3++)
		{
			if (m_pFightWorkList[i3]->isExist)
			{
				if (m_pFightWorkList[i3]->m_work.size())
					break;
			}
		}
		if (i3 == 20)
		{
			// ÿ��ID�ж���ϣ����������ĸ�������ID�ж�
			m_CurrIDPerTurn += 1;
			m_turn = 2;
			if (m_CurrIDPerTurn == 20) //һ�غϽ���
			{
				// ������ID���ж���ϣ�׼����һ�غ�
				m_turn = 4;
			}
		}
	}
		break;
	case 4:// ׼����һ�غ�

	{//ս���������

		if (!g_pMainState->GetLiveNum(10, 20))
		{
			//սʤ��
			SuccessFight();
			return true;
		}
		if (!g_pMainState->GetLiveNum(0, 10))
		{
			//ս����
			FailFight();
			return true;
		}

		for (int i = 0; i < 20; i++)
		{
			//m_pList[i]->targetID = -1;
			if (m_pFightWorkList[i]->isExist)
			{
				m_pFightWorkList[i]->m_pObj->GetPropertyData(pUserData);
				pUserData->m_FightData.AttackNum = 0;
				pUserData->m_FightData.SufferNum = 0;
				m_pFightWorkList[i]->RestTarget();
				m_pFightWorkList[i]->m_work.clear();
				m_pFightWorkList[i]->m_WorkType = -1;
			}
		}

		for (int i = 0; i < 20; i++)
		{
			if (!m_pFightWorkList[i]->isExist)
				continue;
			//���½�ɫBUFF
			g_pMainState->m_SkillManager.CheckFightState(i);
			pUser = g_pMainState->m_FightWorkList[i].m_pObj;
			pUser->GetPropertyData(pUserData);

			//״̬�����
			if (pUserData->LiveRestoreRate > 0)
			{
				if (rand() % 100 < pUserData->LiveRestoreRate)
				{
					pUser->ReMoveState(eBuffType��ӡ);
					pUser->ReMoveState(eBuffType��);
					pUser->ReMoveState(eBuffType����);
				}
			}

			
			if (pUserData->m_FightData.m_TurnHPHurtAdd)
				g_pMainState->m_SkillManager.AddHpHurt(i, pUserData->m_FightData.m_TurnHPHurtAdd);
			if (pUserData->m_FightData.m_TurnHPAdd)
				g_pMainState->m_SkillManager.AddHp(i, pUserData->m_FightData.m_TurnHPAdd);
			if (pUserData->m_FightData.m_TurnMPAdd)
				g_pMainState->m_SkillManager.AddMp(i, pUserData->m_FightData.m_TurnMPAdd);
			if (pUserData->LiveCp)
				g_pMainState->m_SkillManager.AddCp(i, pUserData->LiveCp);

			// ������ë
			if (g_pMainState->m_FightWorkList[i].CheckDie())
			{
				if (rand() % 100 < pUserData->LiveRelifeRate)
				{
					if (g_pMainState->m_SkillManager.Resurgence(i))
					{
						g_pMainState->m_SkillManager.AddHpHurt(i, 499 + pUserData->m_Lv * 3);
						g_pMainState->m_SkillManager.AddHp(i, 499 + pUserData->m_Lv * 3);
						g_pMainState->m_SkillManager.SetDamage(-499 - pUserData->m_Lv * 3, i);
					}
				}
				else if (pUserData->Ghost.d1 > 0)
				{
					// �����
					if (++g_pMainState->m_FightWorkList[i]._ghostTurn == pUserData->Ghost.d1)
					{
						if (g_pMainState->m_SkillManager.Resurgence(i))
						{
							g_pMainState->m_SkillManager.AddHpHurt(i, pUserData->HPMax.GetData());
							g_pMainState->m_SkillManager.AddHp(i, pUserData->HPMax.GetData());
							g_pMainState->m_SkillManager.SetDamage(-pUserData->HPMax.GetData(), i);
							g_pMainState->m_FightWorkList[i]._ghostTurn = 0;
						}
						else
						{
							--g_pMainState->m_FightWorkList[i]._ghostTurn;
						}
					}
				}
			}

			// ��Ѫ׷��
			if (pUserData->isHadPetSkill(2076))
			{
				m_pFightWorkList[i]->_zhuiji = 1;
			}
			// ������
			if (pUserData->isHadPetSkill(2100))
			{
				m_pFightWorkList[i]->_nuji = 1;
// 				m_pFightWorkList[i]->_nujiFromCom = 0;
// 				m_pFightWorkList[i]->_nujiFromCri = 0;
			}

			pUserData->m_FightData.m_bDefend = false;
		}
	}
		m_turn = 0;
		m_FightMenu._timeWaiting = 0;
// 		m_FightMenu.SetControl(g_pMainState->m_HeroID, true);
// 		m_FightMenu.SetControl(g_pMainState->m_HeroID + 5, true);
		g_pMainState->m_AI.checkHero();
		m_FightMenu._tAutoTurn.SetString(toString("��%d�غ�", (++_turn) + 1));
		if (!m_FightMenu._autoBack.m_NeedShow)
		{
			g_pMainState->m_Tags.Add(m_FightMenu._tAutoTurn.GetString());
		}

		for (int i = 0; i < 20; i++)
		{
			++m_pFightWorkList[i]->_myTurn;
		}
		return true;
	} // swicth m_turn end



	for (int i = 0; i < 20; i++)
	{
		if (m_pFightWorkList[i]->isExist)
		{
			if (m_pFightWorkList[i]->m_work.empty())
				continue;
			for (int j = 0; j < m_pFightWorkList[i]->m_work.size(); j++)
			{
				pUser = g_pMainState->m_FightWorkList[i].m_pObj;
				pUser->GetPropertyData(pUserData);
				switch (m_pFightWorkList[i]->GetWork()->type)
				{
				case WORKTYPE_MAGICSUFFER:
					MagicSuffer(i);
					break;
				case WORKTYPE_SUFFER:  //����,ʲôʱ������ɹ����߾���
					Suffer(i);
					break;
				case WORKTYPE_ATTACK:
					//�Ƿ񱻷�
				{
//					if (pUserData->m_FightData.cannotAttack)
//					{
//						m_pFightWorkList[i]->m_work.clear();
// 						if (i == g_pMainState->m_HeroID)
// 							g_pMainState->m_Channel.AddNewString("��������");
// 						m_MiaoShu.SetString("��������");
// 						m_MiaoShu.SetTime(120);
// 						m_MiaoShu.UpdateXCenter();
//						break;
//					}
					if (g_pMainState->m_SkillManager.Use(m_pFightWorkList[i]->m_SkillSelect, i))
					{
					}
				}
					break;
				case WORKTYPE_MAGIC2:
					g_pMainState->m_SkillManager.Use(m_pFightWorkList[i]->m_SkillSelect, i);
					break;
				case WORKTYPE_MAGIC:
					//�Ƿ񱻷�
					g_pMainState->m_SkillManager.Use(m_pFightWorkList[i]->m_SkillSelect, i);
					break;
				case WORKTYPE_ITEM:
					//ʹ�õ���
					if (pUserData->m_FightData.cannotAll)
					{
						pUser->saySkill("���߲���");
						m_pFightWorkList[i]->m_work.clear();
// 						if (i == g_pMainState->m_HeroID)
// 							g_pMainState->m_Channel.AddNewString("���߲���");
// 						m_MiaoShu.SetString("���߲���");
// 						m_MiaoShu.SetTime(120);
// 						m_MiaoShu.UpdateXCenter();
						break;
					}
					g_pMainState->m_SkillManager.Use(m_pFightWorkList[i]->m_SkillSelect, i);



					break;
				case WORKTYPE_SUMMON:
					if (pUserData->m_FightData.cannotAll)
					{
						pUser->saySkill("�ٻ�����");
						m_pFightWorkList[i]->m_work.clear();
// 						if (i == g_pMainState->m_HeroID)
// 							g_pMainState->m_Channel.AddNewString("�ٻ�����");
// 						m_MiaoShu.SetString("�ٻ�����");
// 						m_MiaoShu.SetTime(120);
// 						m_MiaoShu.UpdateXCenter();
						break;
					}
					if (m_pFightWorkList[i + 5]->isExist && m_pFightWorkList[i + 5]->m_pObj->getPcData())
					{
						pUser->saySkill("�ٻ�����");
						m_pFightWorkList[i]->m_work.clear();
						break;
					}
					if (g_pMainState->m_SkillManager.Use(m_pFightWorkList[i]->m_SkillSelect, i))
					{

					}
					break;
				case WORKTYPE_DEFEND:
					Defend(i);
					break;
				case WORKTYPE_FLY:
					if (!m_pFightWorkList[i]->DieFly())
					{
						BackFromFight(i);
					}
					break;
				case WORKTYPE_FALLDOWN:
					FallDown(i);
					break;
				case  WORKTYPE_CATCH:
					if (g_pMainState->m_SkillManager.Use(m_pFightWorkList[i]->m_SkillSelect, i))
					{
					}
					break;
				case WORKTYPE_AVOID:
					Avoid(i);
					break;
				case WORKTYPE_RETURN:
					if (ReturnApproach(i))
					{
						m_pFightWorkList[i]->m_work.pop_back();
						return true;
					}
					break;
				case WORKTYPE_COUNTER:
					if (Counter(i))
					{

					}
					break;
				default:
					ERRBOX;
					break;
				}
			}
		}
	}
	return false;
}






bool cFightState::PrePareToFight(int i)
{
	if (!m_pFightWorkList[i]->isExist)return true;

	if (m_pFightWorkList[i]->m_bPrePareFight)return true;
	m_pFightWorkList[i]->m_bPrePareFight = true;
	cObj* pTarget = m_pFightWorkList[i]->m_pObj;
	pTarget->SetSound(POS_SOUNDSUFFER, false);
	cPropertyData* pTargetData;
	pTarget->GetPropertyData(pTargetData);
	if (1 > pTargetData->m_HP)pTargetData->m_HP = 1;

	if (i < 10 && !pTargetData->_isOurTeamTemp)
	{
		if (pTarget->getPcData())
		{
			pTarget->getPcData()->apply();
		}
		else if (pTarget->getPetData())
		{
			pTarget->getPetData()->apply();
		}
	}
//	pTargetData->SetXLEffect(true);
	//��ʼ����ɫ״̬
	pTargetData->m_FightData.Init();
	pTarget->m_ConductFire.m_NeedShow = false;
	pTarget->m_ConductSeal.m_NeedShow = false;
	pTarget->m_TrueName.SetColor(RGB(0, 255, 0));
	m_pFightWorkList[i]->SetDie(false);
	pTarget->m_TrueName.m_bShowOnScreen = true;
	m_pFightWorkList[i]->m_work.clear();
	m_pFightWorkList[i]->m_WorkType = -1;

	m_pFightWorkList[i]->reset();
	if (!pTargetData->m_Controler.GetDel())
	{
		//��¼��ɫ�ĵ�λ��,����ͻ�������
		m_pFightWorkList[i]->xOldPos = pTarget->GetX();
		m_pFightWorkList[i]->yOldPos = pTarget->GetY();
		m_pFightWorkList[i]->m_oldDirection = m_pFightWorkList[i]->m_pObj->GetDirection();

// 		pTargetData->m_FightProperty.m_oldATK = pTargetData->Atk;      //�˺�
// 		pTargetData->m_FightProperty.m_oldHIT = pTargetData->Hit;   //����
// 		pTargetData->m_FightProperty.m_oldDEF = pTargetData->Def;   //����
// 		pTargetData->m_FightProperty.m_oldWakan = pTargetData->Mana; //����
// 		pTargetData->m_FightProperty.m_oldSPD = pTargetData->Speed;   //�ٶ�
// 		pTargetData->m_FightProperty.m_oldEvade = pTargetData->Evade; //����
// 		pTargetData->m_FightProperty.m_oldGoldLive = pTargetData->RelifeRate;
//		pTargetData->m_FightData._isFlyOld = pTargetData->m_Controler.GetFly();
		pTargetData->m_FightData.m_TurnHPAdd = pTargetData->LiveHp/**pTargetData->m_Lv / 10*/;
		pTargetData->m_FightData.m_TurnHPHurtAdd = 0;
		pTargetData->m_FightData.m_TurnMPAdd = pTargetData->LiveMp/**pTargetData->m_Lv / 10*/;
	}

	if (pTargetData->_isOurTeamTemp || i >= 10)
	{
		pTargetData->m_FightData.m_TurnHPAdd = pTargetData->LiveHp;
		pTargetData->m_FightData.m_TurnMPAdd = pTargetData->LiveMp;
	}

	//������Ч��
	g_pMainState->m_InterfaceTeam.SetupOneFormationEffect(g_pMainState->m_InterfaceTeam.GetReTramTrun(i), pTargetData, 1);

	//���ý�ɫ�ĳ�ʼ����, ����,λ��
	pTarget->Set(POS_FIGHT_STAND);
	if (i < 10)
		pTarget->SetDirection(DIRECTION_LEFT_UP);
	else
		pTarget->SetDirection(DIRECTION_RIGHT_DOWN);

	pTarget->SetXY(m_ս������xs[i], m_ս������ys[i]);
	pTarget->MoveShadow();
	pTarget->MoveDialog();
	pTarget->MoveHpLine();
	pTarget->UpdateHpLine();
	pTarget->MoveName();
	pTarget->SetShadow(false);

	int skilllv = pTarget->GetSkillLv(0);
	if (pTarget->m_IndexType == INDEXTYEP_CHARACTER)
	{
		cPcData* pc = (cPcData*)pTargetData;
		if (pc->m_MengPaiID == eMP_�貨��)
		{
			pTargetData->m_FightData.zhanyi = 3;
			sBuff buf;
			buf.ID = 1997;
			buf.remainingTimes = 0xFFF;
			buf.EffectType = eBuffType����;
			buf.bBuffup = true;
			buf.bufPos = 10;
			buf.damage = 2;
			buf.MagicID = 0x3D3C8D10;
			buf.targetID = i;
			buf.userID = i;
			buf.skilllv = 0;
			buf.data.m_Picture.m_FrameGap = 1;
			AddState(i, buf);
		}
		else if (pc->m_MengPaiID == eMP_ʨ����)
		{
			sBuff buf;
			buf.remainingTimes = 8;
			g_pMainState->m_SkillManager.SetDateBuffUp(i, i, 145, buf, pTargetData->m_Lv);
		}

		for (int k = 0; k < pc->m_NumofBB; ++k)
		{
			pc->m_pPets[k]->m_PetData._owerIdx = k;
		}
		if (pc->m_FightPetID >= 0)
		{
			pc->m_pPets[pc->m_FightPetID]->m_PetData._owerIdx = -1;
		}
	}

	if (pTargetData->Cp1)
	{
		g_pMainState->m_SkillManager.AddCp(i, pTargetData->Cp1);
	}


	auto cbSkill = [&](int sid)
	{
		auto& s = m_pFightWorkList[i]->m_SkillSelect;
		s.SkillID = sid;
		s.SkillLv = pTargetData->m_Lv;
		s.TargetID = i;
		m_pFightWorkList[i]->SetWork(WORKTYPE_MAGIC);
//		m_pFightWorkList[i]->m_WorkType = -1;
		g_pMainState->m_SkillManager.Use(s, i);
	};

	// ����
	if (pTargetData->Hide.d1 >= 2)
	{
		// ����
		cbSkill(123);
	}
	else if (pTargetData->StartMagic >= 0)
	{
		cbSkill(pTargetData->StartMagic);
	}

	// ������
	if (pTargetData->isHadPetSkill(2096))
	{
		sBuff buf;
		buf.remainingTimes = 5;
		g_pMainState->m_SkillManager.SetDateBuffUp(i, i, 2096, buf, skilllv);
		if (i % 10 >= 5)
		{
			g_pMainState->m_SkillManager.SetDateBuffUp(i - 5, i - 5, 2096, buf, skilllv);
		}
	}

	int hpmax = pTargetData->HPMax.GetData();
	int& hp2 = pTargetData->m_HP2;
	int& hp = pTargetData->m_HP;
	if (hp2 > hpmax)
	{
		hp2 = hpmax;
	}
	if (hp > hp2)
	{
		hp = hp2;
	}

	return true;
}







bool cFightState::BackFromFight(int i)
{
	auto plist = m_pFightWorkList[i];
	if (!plist->m_bPrePareFight)return true;
	plist->m_bPrePareFight = false;


	plist->m_work.clear();
	plist->m_WorkType = -1;
	plist->m_pObj->m_MagicSuffer.m_NeedShow = false;
	plist->m_DamageTime[0] = 100;
	plist->m_pObj->SetStatic(false);
	plist->m_pObj->m_TrueName.m_bShowOnScreen = false;

	cObj* pTarget = m_pFightWorkList[i]->m_pObj;
	pTarget->Reset();
	pTarget->SetShake(false);
	cPropertyData* pTargetData;
	pTarget->GetPropertyData(pTargetData);

	SetFightBufDown(i);
	if (!pTargetData->m_Controler.GetDel())
	{
//		pTargetData->SetXLEffect(false);
		//��ԭ��ɫ��λ��,����,��ʹ֮վ��
		pTarget->SetXY(plist->xOldPos, plist->yOldPos);
		pTarget->SetDirection(m_pFightWorkList[i]->m_oldDirection);
		pTarget->m_TrueName.SetColor(RGB(0, 255, 0));
		pTarget->Stand();
		pTarget->MoveShadow();
		pTarget->MoveDialog();
		//ȥ��Ч��
// 		pTargetData->Atk = pTargetData->m_FightProperty.m_oldATK;      //�˺�
// 		pTargetData->Hit = pTargetData->m_FightProperty.m_oldHIT;   //����
// 		pTargetData->Def = pTargetData->m_FightProperty.m_oldDEF;   //����
// 		pTargetData->Mana = pTargetData->m_FightProperty.m_oldWakan; //����
// 		pTargetData->Speed = pTargetData->m_FightProperty.m_oldSPD;   //�ٶ�
// 		pTargetData->Evade = pTargetData->m_FightProperty.m_oldEvade; //����
// 		pTargetData->RelifeRate = pTargetData->m_FightProperty.m_oldGoldLive;
//		pTargetData->m_FightData.Clear();
//		pTargetData->m_Controler.setFly(pTargetData->m_FightData._isFlyOld);

// 		if (i >= 15)
// 		{
// 			g_pMainState->FreeFightList(i);
// 		}
	}
	else
	{
		g_pMainState->FreeFightList(i);
	}
	plist->isExist = false;

//	auto& listTemp = g_pMainState->m_FightWorkTemps[(i >= 10)];
//	if (i == listTemp._moon)
//	{
//		plist->Free();
//		*plist = listTemp;
//		m_FightMenu.SetControl(i, (listTemp._myTurn != -1));
//		listTemp._moon = -1;
// 		listTemp._moon = -1;
// 		plist->m_pObj = listTemp.m_pObj;
// 		plist->m_FriendListid = listTemp.m_FriendListid;
// 		plist->m_SkillPreSelect = listTemp.m_SkillPreSelect;
// 		if (g_StateType != STATE_GAMEOVER)
// 		{
// 			g_pMainState->FindObj();
// 		}
//	}

	return true;
}

