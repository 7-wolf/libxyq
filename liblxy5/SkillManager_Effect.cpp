#include "_global.h"
static const int c_bufRemainingTimesOnce = -0xFF;

void cSkillManager::EffectSkill(int Skilllv, int sSkillID, int UserID, int TargetID)
{
	if (TargetID == -1)return;
	sFightWork* pUserList = m_pFightState->m_pFightWorkList[UserID];
	cObj* pTarget = m_pFightState->m_pFightWorkList[TargetID]->m_pObj;
	cObj* pUser = m_pFightState->m_pFightWorkList[UserID]->m_pObj;
	cPropertyData* pTargetData;
	cPropertyData* pUserData;
	sBuff buf;
	buf.remainingTimes = c_bufRemainingTimesOnce;

	pTarget->GetPropertyData(pTargetData);
	pUser->GetPropertyData(pUserData);
	int userlv = pUserData->m_Lv;
	int targetlv = pTargetData->m_Lv;
	int dam = 0;
	auto getRemianTime = [&]()
	{
		int t = Skilllv/* + pUserData->m_XiuLian.GetMag()*/ + 15 - targetlv;
		t = t / 5;
		t = min(t, 7);
		return t;
	};
	auto getRemianTimeSelf = [&]()
	{
		int t = Skilllv/* + pUserData->m_XiuLian.GetMag()*/ + 25 - targetlv;
		t = t / 5;
		t = min(t, 9);
		return t;
	};

	int targetNum = g_pMainState->m_FightWorkList[UserID].m_MaxTargetNum;
//	int targetNow = pUserList->m_NowTarget;// g_pMainState->m_FightWorkList[UserID].m_NowTarget;
	int targetMax = 1;
	if (sSkillID < 1000 || sSkillID >= 2000)
	{
		targetMax = g_pMainState->m_SkillManager.GetSkill(sSkillID)->m_TargetNum;
	}
	Skilllv += pUserData->m_XiuLian.GetMag();
	int damPT = (Skilllv * 4 + 80) * 13 / 10 * (23 - targetNum) / 20;
	if (pUserList->m_NowTargetIdx == 0)
	{
		damPT += Skilllv / 2;
	}

	int dam2 = 0;
	switch (sSkillID)
	{
	case 0://��ɨǧ��
	{
		int damageup;
		switch (pUserList->m_NowTargetIdx)
		{
		case 0:
			damageup = -15;
			break;
		case 1:// �����߹���-Ŀ����� 120%���˺�
			damageup = 0;
			break;
		case 2:// �����߹���-Ŀ�����  ����10%�Ĳ���  150%���˺�
			damageup = 15;
			break;
		default:
			damageup = 30;
			break;
		}
		CountphysicalDamage(dam, UserID, TargetID, damageup);
	}
		break;
	case 1: // ��
		SetDateBuffUp(TargetID, UserID, sSkillID, buf, Skilllv);
		buf.remainingTimes = c_bufRemainingTimesOnce;
		break;
	case 1010: // ��
	{
		pUserData->DmgAdd.d1 += Skilllv * 3 / 2;
		CountphysicalDamage(dam, UserID, TargetID, 155);
		pUserData->DmgAdd.d1 -= Skilllv * 3 / 2;
		pUser->ReMoveStateID(1);
	}
		break;
	case 7: // �Ƹ�
	{
		CountphysicalDamage(dam, UserID, TargetID, -0xFFFF);
	}
		break;
	case 1017:// �Ƹ�
		CountphysicalDamage(dam, UserID, TargetID, 45);
		break;
	case 8://�����
		buf.remainingTimes = getRemianTime();
		break;
	case 4://ɱ����
		buf.remainingTimes = getRemianTime();
		break;
	case 11://������
	case 28://���׷�
	{
		pUserData->Ghost.d2 += 50;
		int dadd = pUserData->Def.GetData() >> 4;
		pUserData->Mana.AddDataOriginal(dadd);
		CountMagicDamage(dam, UserID, TargetID, 20/*20 + Skilllv / 5 - (m_pFightState->m_pList[UserID]->m_MaxTargetNum - 1) * 5,eMWX��*/);
		pUserData->Ghost.d2 -= 50;
		pUserData->Mana.AddDataOriginal(-dadd);
	}
		break;
	case 13: // �����
	{
		m_pFightState->m_pFightWorkList[UserID]->isExist = false;
		if (UserID == g_pMainState->m_HeroID)
			m_pFightState->m_bEscape = true;
	}
		break;
	case 6: //�����
		buf.remainingTimes = getRemianTime() / 2 + 1;
		break;
	case 14://���߷�
	case 15://ʧ�ķ�
	case 16://����
	case 17://ʧ��
	case 18://׷��
	case 19://���
	case 20://ʧ��
	case 21://����
	case 26:
	case 27:
// 		buf.remainingTimes = 3;
// 		buf.remainingTimes += (Skilllv - targetlv) / 5;
// 		break;
// 		buf.remainingTimes = 2;
// 		buf.remainingTimes += (Skilllv - targetlv) / 10;
		buf.remainingTimes = getRemianTime();
		break;
	case 22://��Ԫ��
		dam = Skilllv * 5 / 2 + 128;
		CorrectCureHP(dam, UserID, UserID);//��������
//		SetDamage(-dam, TargetID);
		break;
	case 23://������
//		SetDamage(20, TargetID);
		CorrectCureMP(dam = Skilllv * 2, UserID, UserID);//��������
//		AddMp(TargetID, dam = Skilllv * 2);
		break;
// 	case 26://������
// 		buf.remainingTimes = 3;
// 		buf.remainingTimes += (Skilllv - targetlv) / 5;
// 		break;
// 	case 27://��׷�
// 		buf.remainingTimes = 3;
// 		buf.remainingTimes += (Skilllv - targetlv) / 5;
// 		break;
	case 31://��������

	{
		int dadd = pUserData->Def.GetData() >> 4;
		pUserData->Mana.AddDataOriginal(dadd);
		CountMagicDamage(dam, UserID, TargetID, 20/*15 + Skilllv / 5 - (m_pFightState->m_pList[UserID]->m_MaxTargetNum - 1) * 4*/);
		pUserData->Mana.AddDataOriginal(-dadd);
		if (pUserList->m_NowTargetIdx == 0 && pUserData->m_HP > 5)
		{
			dadd = -5;
			AddHp(UserID, -5);
			SetDamage(5, UserID);
		}
	}
		break;
 	case 33:  //��ջ���
// 
// 	{
// 		buf.remainingTimes = 3;
// 		buf.remainingTimes += (Skilllv - targetlv) / 5;
// 	}
// 		break;
	case 34:  //Τ�ӻ���  
	case 35:  //��ջ���
	case 36:  //һέ�ɽ�

	{
// 		buf.remainingTimes = 3;
// 		buf.remainingTimes += (Skilllv - targetlv) / 5;
		buf.remainingTimes = getRemianTime();
		break;
	}
	case 37:     //�ҷ�ȱ�
		if (Resurgence(TargetID))
		{
			dam2 = dam = Skilllv * 12 + 256;
			CorrectCureHP(dam, dam2, UserID, TargetID);//��������
		}
//		AddHpHurt(TargetID, (Skilllv * 12 + 256));
//		dam2 = dam = Skilllv * 12 + 256;
//		CorrectCureHP(dam, dam2, UserID, TargetID);//��������
		break;
	case 38:     //����
		dam = Skilllv * 12;
		AddHpHurt(TargetID, dam);
		CorrectCureHP(dam, UserID, TargetID);//��������

		break;
// 	case 39:    //��Ѫ
// 		dam = Skilllv * 12;
// 		CorrectCureHP(dam, UserID, TargetID);//��������
// 
// 		break;
	case 40:    //��������
		dam = Skilllv * 8;
		CorrectCureHP(dam, UserID, TargetID);//��������
		break;
	case 41:    //���ֻش�
		AddHpHurt(TargetID, (Skilllv * 8));
		break;
	case 42:    //��������
		dam = Skilllv * 7 + 64;
		dam += dam * (targetMax - targetNum) / (targetMax * 5 + 1);
//		AddHpHurt(TargetID, dam);
		dam2 = dam;
		CorrectCureHP(dam, dam2, UserID, TargetID);//��������
		break;
	case 39:
	case 43://�ⶾ
		pTarget->ReMoveState(eBuffType��);
		dam2 = dam = Skilllv * 10 + 192;
//		AddHpHurt(TargetID, dam);
		CorrectCureHP(dam, dam2, UserID, TargetID);//��������
		break;
	case 45://����
// 		AddHpHurt(TargetID, 100, (1 << 14));
		pUserData->Def.AddDataAddPercent(-5);
		pUserData->Mana.AddDataAddPercent(-3);
// 		dam = -AddHp(TargetID, 100, 0xFFFFFF);
		CorrectCureHP(dam = 99999, UserID, TargetID);
// 		SetDamage(dam, TargetID);
		break;
	case 46:    //���ޱ�
// 	{
// 		buf.remainingTimes = 3;
// 		buf.remainingTimes += (Skilllv - targetlv) / 5;
// 		buf.remainingTimes = getRemianTime();
// 	}
// 		break;
	case 49:    //��������
// 	{
// 		buf.remainingTimes = 3;
// 		buf.remainingTimes += (Skilllv - targetlv) / 5;
// 	}
		buf.remainingTimes = getRemianTime();
		break;
	case 50: return;
	case 1050:
		CountphysicalDamage(dam, UserID, TargetID/*, 30*/);
		// 15 ʧ�ķ�
		if ((rand() % 100) < CheckMagicHit(Skilllv, 15, UserID, TargetID))
		{
			buf.remainingTimes = 2 + rand() % 4;
			SetDateBuffUp(UserID, TargetID, 50, buf, Skilllv);
			buf.remainingTimes = c_bufRemainingTimesOnce;
		}
		break;

	case 54:    //��������
// 	{
// 		buf.remainingTimes = 3;
// 		buf.remainingTimes += (Skilllv - targetlv) / 5;
// 	}
// 		break;
	case 59:    //һЦ���
// 	{
// 		buf.remainingTimes = 3;
// 		buf.remainingTimes += (Skilllv - targetlv) / 5;
// 	}
// 		break;
	case 62:    //���񻤷�
// 	{
// 		buf.remainingTimes = 5;
// 		buf.remainingTimes += (Skilllv - targetlv) / 5;
// 	}
		buf.remainingTimes = getRemianTimeSelf();
		break;
	case 66:	//����
		pUser->ReMoveState(eBuffType����);
		break;
	case 67:    //���� 
// 	{
// 		buf.remainingTimes = 3;
// 		buf.remainingTimes += (Skilllv - targetlv) / 5;
// 	}
// 		break;
	case 68:    //����
	case 69:    //�������
// 	{
// 		buf.remainingTimes = 3;
// 		buf.remainingTimes += (Skilllv - targetlv) / 5;
// 	}
		buf.remainingTimes = getRemianTime();
		break;
	case 71://����ն
	{
		int dadd = pUserData->Def.GetData() >> 4;
		pUserData->Atk.AddDataOriginal(dadd);
		CountphysicalDamage(dam, UserID, TargetID);
		pUserData->Atk.AddDataOriginal(-dadd);
		if (sSkillID == 71)
		{
			if (pUserList->m_NowTargetIdx == 0)
			{
				pUserData->Def.AddDataAddPercent(-1);
			}
			pTargetData->Mana.AddDataAddPercent(-1);
		}
	}
		break;
	case 72://���׺䶥
	{
// 		int rate = (pUserData->m_XiuLian.GetMag() - pTargetData->m_XiuLian.GetDMag())/**2*/;
// 		int offset = Skilllv - pTargetData->m_Lv;
// 		rate = 70 + rate + offset;
// 		if (rand() % 100 < rate)

		// ʧ�ķ�
		if ((rand() % 100) < CheckMagicHit(Skilllv, 15, UserID, TargetID))
		{
			dam = pTargetData->m_HP / 4;
		}
		else
		{
			dam = pTargetData->m_HP / 20;
		}
		if (dam > (pUserData->m_Lv * 50))
		{
			dam = pUserData->m_Lv * 50;
		}
		AddHp(TargetID, -dam);
		SetDamage(dam, TargetID);
	}
		break;
	case 74://�������
	{
		int dadd = pUserData->Def.GetData() >> 4;
		pUserData->Mana.AddDataOriginal(dadd);
		CountMagicDamage(dam, UserID, TargetID, 25/*20 + Skilllv / 5 - (m_pFightState->m_pList[UserID]->m_MaxTargetNum - 1) * 8,eMWX��*/);
		pUserData->Mana.AddDataOriginal(-dadd);
	}
		break;
	case 77: //���
	{
		m_pFightState->ReMoveSealState(TargetID);
	}
		break;
	case 78: // ����
	{
		pTarget->ReMoveState(eBuffType��);
		break;
	}
	case 79://����
		CountMagicDamage(dam, UserID, TargetID, 25/*40 + Skilllv / 5, eMWXˮ*/);
		break;
	case 80://�������
		CountMagicDamage(dam, UserID, TargetID, 20/*25 + Skilllv / 5 - (m_pFightState->m_pList[UserID]->m_MaxTargetNum - 1) * 4,eMWX��ˮ*/);
		break;
	case 81://����
		buf.remainingTimes = getRemianTimeSelf();
		break;
	case 87://������β
		buf.remainingTimes = getRemianTimeSelf();
		break;
	case 84: //����
		dam = Skilllv + 10;
		CountMagic2Damage�̶�(dam, UserID, TargetID/*, eMWXˮ*/);
		AddMp(TargetID, -dam);
		break;
	case 88://����
		CountMagicDamage(dam, UserID, TargetID, 30/*30 + Skilllv / 5 - (m_pFightState->m_pList[UserID]->m_MaxTargetNum - 1) * 4,eMWXˮ*/);
		break;
	case 89://����Ǭ��
	{
		buf.remainingTimes = 3;
		buf.remainingTimes += (Skilllv - targetlv) / 5;
		buf.remainingTimes = getRemianTime();
	}
		break;
	case 90: //��������
	{
		buf.remainingTimes = 3;
		buf.remainingTimes += (Skilllv - targetlv) / 5;
		buf.remainingTimes = getRemianTimeSelf();
		dam = Skilllv;
		CorrectCureMP(dam, UserID, TargetID);
		buf.damage = dam;
//		SetDamage(30, UserID);
	}
		break;
	case 91://����֮Ȫ
	{
		buf.remainingTimes = 3;
		buf.remainingTimes += (Skilllv - targetlv) / 5;
		buf.remainingTimes = getRemianTimeSelf();
		dam = Skilllv * 5 / 2 + 64;
		buf.damage = dam;
		CorrectCureHP(dam, UserID, TargetID); //��������
		
	}
		break;
	case 94:   //�����۶�
		dam = (Skilllv * 5 + 128);
		CorrectCureMP(dam, UserID, TargetID);
//		SetDamage(30, UserID);
		break;
	case 96: // ��ʬ
	{
		pTarget->ReMoveState(eBuffType��);
	}
		break;
	case 97: //����
	case 98: //���ʽ
	{
		int dadd = pUserData->Def.GetData() >> 4;
		pUserData->Atk.AddDataOriginal(dadd);
		CountphysicalDamage(dam, UserID, TargetID);
		pUserData->Atk.AddDataOriginal(-dadd);
	}
		break;
	case 102://�ն�����
	{
		buf.remainingTimes = 3;
		buf.remainingTimes += (Skilllv - targetlv) / 5;
		buf.remainingTimes = getRemianTimeSelf();

		int d = Skilllv * 4 + 192;
		dam += d;
		dam2 += d;
		buf.damage = d;
		buf.damage2 = d;
//		AddHpHurt(TargetID, dam + Skilllv);
		CorrectCureHP(dam, dam2, UserID, TargetID);//��������
	}
		break;
	case 103://������
// 		buf.remainingTimes = 3;
// 		buf.remainingTimes += (Skilllv - targetlv) / 5;
		if ((rand() % 100) < CheckMagicHit(Skilllv, 15, UserID, TargetID))
		{
			buf.damage = (Skilllv * 3 + pTargetData->HPMax.GetData() / 50);
			int lvMax = max(pTargetData->m_Lv, pUserData->m_Lv);
			if (buf.damage > lvMax * 8)
			{
				buf.damage = lvMax * 8;
			}
			buf.remainingTimes = getRemianTime();
		}
		break;
	case 104://������¶
	{
//		Resurgence(TargetID);
		{
			cObj* pObj = g_pMainState->m_FightWorkList[TargetID].m_pObj;
			pObj->SetStatic(false);
			pObj->Set(POS_FIGHT_STAND);
			g_pMainState->m_FightWorkList[TargetID].SetDie(false);
			cPropertyData* pPet;
			pObj->GetPropertyData(pPet);
			if (pPet->m_HP < 1)
			{
				pPet->m_HP = 1;
			}
			AddHpHurt(1, TargetID);
			AddHp(1, TargetID);
			pObj->MoveShadow();
		}

		dam2 = dam = Skilllv * Skilllv / 144 + Skilllv * 6;
		buf.remainingTimes = getRemianTimeSelf();

		int d = Skilllv * 4 + 192;
		dam += d;
		dam2 += d;
		buf.damage = d;
		buf.damage2 = d;
		CorrectCureHP(dam, dam2, UserID, TargetID);//��������
	}
		break;
	case	105:// �չ⻪ �ȼ���4 + 100
		dam = damPT + Skilllv / 2;
		CountMagic2Damage�̶�(dam, UserID, TargetID, eMWX��);
		break;
	case	106:// ��׺�
		dam = damPT;
		CountMagic2Damage�̶�(dam, UserID, TargetID, eMWXˮ);
// 		if ((rand() % 100) < 10)
// 		{
// 			m_pFightState->m_pFightWorkList[TargetID]->m_WorkType = -1;
// 		}
		break;
	case	107:// ������
		dam = damPT;
		CountMagic2Damage�̶�(dam, UserID, TargetID, eMWX��);
		if ((rand() % 100) < 10)
		{
			AddCp(TargetID, -dam / 50);
		}
		break;
	case	108:// ��ã��
		dam = damPT;
		CountMagic2Damage�̶�(dam, UserID, TargetID);
		if ((rand() % 100) < 10)
		{
			AddMp(UserID, -dam / 10);
		}
		break;
	case	109:// ���ѻ�
		dam = damPT;
		CountMagic2Damage�̶�(dam, UserID, TargetID, eMWX��);
		if ((rand() % 100) < 10)
		{
			AddHpHurt(TargetID, -dam / 10);
		}
		break;
	case 112://�鶯
		buf.remainingTimes = 3;
		buf.remainingTimes += (Skilllv - targetlv) / 5;
		buf.remainingTimes = getRemianTimeSelf();
		break;
	case 113://���еߵ�
		buf.remainingTimes = 3;
		buf.remainingTimes += (Skilllv - targetlv) / 5;
		buf.remainingTimes = getRemianTimeSelf();
		break;
	case 115://�����ķ�
		if (pTarget->m_StateList.size())
		{
			int hp = 1;
			int hp2 = 1;
			int t = 1;
			for (list<sBuff>::iterator Iterator = pTarget->m_StateList.begin(); Iterator != pTarget->m_StateList.end();)
			{
// 				if (Iterator->ID == 102 || Iterator->ID == 91)
// 				{
// 					list<sBuff>::iterator it2 = Iterator;
// 					Iterator++;
// 					if (Iterator->ID == 91)
// 					{
// 						int hpadd = it2->damage2*it2->times;
// 						AddHpHurt(TargetID, hpadd);
// 					}
// 					dam = -it2->damage*it2->times;
// 					AddHp(TargetID, -dam);
// 					g_pMainState->m_SkillManager.SetDateBuffDown(it2);// it2->targetID, it2->ID);
// 					it2->data.Free();
// 					pTarget->m_StateList.erase(it2);
// 					break;
// 				}
// 				else 
				if (Iterator->ID == 102 || Iterator->ID == 104)
				{
					if (t < Iterator->remainingTimes)
					{
						t = Iterator->remainingTimes;
					}
					if (hp < Iterator->damage)
					{
						hp = Iterator->damage;
					}
					if (hp2 < Iterator->damage2)
					{
						hp2 = Iterator->damage2;
					}
					g_pMainState->m_SkillManager.SetDateBuffDown(Iterator);// it2->targetID, it2->ID);
					Iterator->data.Free();
					pTarget->m_StateList.erase(Iterator++);
				}
				else
				{
					++Iterator;
				}
			}
			hp *= t;
			hp2 *= t;
// 			if (hp > 0)
// 			{
// 				AddHpHurt(TargetID, hp);
// 				AddHp(TargetID, hp);
// 				SetDamage(-hp, TargetID);
// 			}
			CorrectCureHP(hp, hp2, UserID, TargetID);
		}
		break;
	case 116://������
		dam = (Skilllv * 3 / 2 + 30) * 13 / 10 * 2;
		CountMagic2Damage�̶�(dam, UserID, TargetID);
		AddHpHurt(TargetID, -(Skilllv * 3 / 2 + 30));
		break;
	case 117://�й���
		dam = (Skilllv * 3 + 75) * 13 / 10 * 3 / 2;
		CountMagic2Damage�̶�(dam, UserID, TargetID);
		AddMp(TargetID, -(Skilllv * 3 + 75));
		break;
	case 119://������
		m_pFightState->ReMoveSealState(TargetID);
	case 120://����
		buf.remainingTimes = 3;
		buf.remainingTimes += (Skilllv - targetlv) / 5;
		buf.remainingTimes = getRemianTimeSelf();
		break;
	case 122://ʬ����
	{
		if (pTarget->CheckHaveState(sSkillID))return;
//		if (pTargetData->m_Race == 5 || pTargetData->m_Race == 6 || pTargetData->m_Race >= 1000)return;//��е�͹����ж�
		if (pTargetData->Ghost.d1 > 0) return;
// 		int Poision = pUserData->poisonRate.d1 - pUserData->poisonRate .d2 + 80; //�ж���
// 		if (rand() % 100 < Poision)
		{
			sBuff buf;
			buf.damage = pUserData->DmgPercentOfPoison.d1 - pTargetData->DmgPercentOfPoison.d2;//�ж��˺�����
			buf.remainingTimes = Skilllv + pUserData->m_XiuLian.GetMag() - targetlv;
			buf.remainingTimes = buf.remainingTimes / 5;
			buf.remainingTimes = min(buf.remainingTimes, 4);

			SetDateBuffUp(UserID, TargetID, sSkillID, buf);
			buf.remainingTimes = c_bufRemainingTimesOnce;
			dam = pTargetData->m_HP / 10 + Skilllv;
			if (dam > userlv * 15)
			{
				dam = userlv * 15;
			}
			AddHp(TargetID, -dam);
			SetDamage(dam, TargetID);

			cPropertyData* pPet;
			int randstart, randend;
			if (UserID < 10)randstart = 0; else randstart = 10;
			randend = randstart + 10;
			for (int i = randstart; i < randend; i++)
			{
				sFightWork& list = g_pMainState->m_FightWorkList[i];
				if (!list.isExist)continue;
				list.m_pObj->GetPropertyData(pPet);

				if (pPet->m_HP < 1)continue;
				int d = dam + pPet->DmgAddOfCure.d2 + pUserData->DmgAddOfCure.d1;
				if (d > Skilllv * 9 / 2 + 192)
				{
					d = Skilllv * 9 / 2 + 192;
				}
				AddHp(i, d);
				SetDamage(-d, i);
			}
		}
	}
		break;
	case 123:   //��������
		buf.remainingTimes = 3;
		buf.remainingTimes += (Skilllv - targetlv) / 5;
		if (pUserData->Hide.d1 >= 2)
		{
			buf.remainingTimes = pUserData->Hide.d1;
			pUserData->Hide.d1 = 0;
		}
		else
		{
			buf.remainingTimes = getRemianTime();
		}
		break;
	case 125:
		if (Resurgence(TargetID))
		{
			//		AddHpHurt(TargetID, Skilllv * 10);
			dam2 = dam = Skilllv * 8 + 128;
			//		AddHp(TargetID, dam);
			CorrectCureHP(dam, dam2, UserID, TargetID);//��������
			buf.remainingTimes = 3;
			buf.remainingTimes += (Skilllv - targetlv) / 5;
			buf.remainingTimes = getRemianTime();
		}

		break;
	case 126: // ��Ȫ֮Ϣ
		buf.remainingTimes = 3;
		buf.remainingTimes += (Skilllv - targetlv) / 5;
		buf.remainingTimes = getRemianTime();

		dam = pUserData->Mana.GetData() - pTargetData->Mana.GetData();
		dam += pUserData->Atk.GetData() - pTargetData->Def.GetData();
		if (dam < 0)
		{
			dam = 0;
		}
		dam += Skilllv * 3 + 30;
		CountMagic2Damage�̶�(dam, UserID, TargetID);
		break;
	case 127:// �����ɢ
		pTarget->ReMoveState(eBuffType����);
		break;
	case 129: // ������
		buf.remainingTimes = 5;
		buf.remainingTimes += (Skilllv - targetlv) / 25;
		buf.remainingTimes = getRemianTime();
		
		break;
	case 131://��ɰ��ʯ
		CountMagicDamage(dam, UserID, TargetID, 25/*25 + Skilllv / 4 - (m_pFightState->m_pList[UserID]->m_MaxTargetNum - 1) * 4, eMWX��*/);
		break;
	case 132:// �������
		CountMagicDamage(dam, UserID, TargetID, 30/*70 + Skilllv / 4, eMWX��*/);
		break;
	case 133:// ţ��
		buf.remainingTimes = getRemianTimeSelf();
		break;
	case 135:// ţ��
		
		break;
	case 136:// ����ţ��
		break;
	case 137: // ħ������
		buf.remainingTimes = getRemianTimeSelf();
		break;
	case 141://����
		CountphysicalDamage(dam, UserID, TargetID, 60);
		pUser->ReMoveStateID(145);//ȡ������
		buf.remainingTimes = 1;
		SetDateBuffUp(UserID, TargetID, sSkillID, buf);
		buf.remainingTimes = c_bufRemainingTimesOnce;
		break;
	case 142://ӥ�� 
		CountphysicalDamage(dam, UserID, TargetID, 5);
// 		if (pUserList->m_NowTarget == 0/*pUserList->m_MaxTargetNum - 1*/)
// 		{
// 			buf.times = 1;
// 			SetDateBuffUp(UserID, UserID, sSkillID, buf);
// 		}
// 		buf.times = -999;
		break;
	case 143:// ʨ��
		CountphysicalDamage(dam, UserID, TargetID, 125);
		break;
	case 144:// ����
		if (pTarget->m_IndexType != INDEXTYEP_CHARACTER)
		{
			buf.remainingTimes = 5;
			buf.remainingTimes += (Skilllv - targetlv) / 25;
			buf.remainingTimes = getRemianTime();
		}

		break;
	case 145://����
// 		buf.remainingTimes = 5;
// 		buf.remainingTimes += (Skilllv - targetlv) / 5;
// 		break;
	case 147://����
		buf.remainingTimes = getRemianTimeSelf();
		break;
	case 148:// ������
		CountphysicalDamage(dam, UserID, TargetID, 10 - pUserData->m_FightData.AttackNum * 5);
// 		if (pUserList->m_NowTarget == 0)
// 		{
//  			buf.times = 1;
//  			SetDateBuffUp(UserID, UserID, sSkillID, buf);
//  			buf.times = -999;
// 			pUser->ReMoveStateID(145);//ȡ������
// 			buf.times = 1;
// 			SetDateBuffUp(UserID, TargetID, sSkillID, buf);
// 			buf.times = -999;
// 		}
		break;
	case 150://���ȷ��
// 		buf.remainingTimes = 3;
// 		buf.remainingTimes += (Skilllv - targetlv) / 5;
// 		break;
	case 152:
		buf.remainingTimes = 3;
		buf.remainingTimes += (Skilllv - targetlv) / 5;
		buf.remainingTimes = getRemianTime();
		break;
	case 154://����
	{
		dam = pTargetData->HPMax.GetData() / 20;
		dam += Skilllv * 3;
		dam = dam * (100 - pTargetData->DmgPercentOfFix.d2) / 100;
		if (dam > userlv * 12)
		{
			dam = userlv * 12;
		}
// 		AddHp(TargetID, -dam);
// 		SetDamage(dam, TargetID);
		CountMagic2Damage�̶�(dam, UserID, TargetID);
		CorrectCureHP(dam, UserID, UserID);//��������
	}
		break;
	case 155://����
// 		dam = -AddMp(TargetID, -5, userlv * 100);
// 		dam += -AddMp(TargetID, -Skilllv * 2);
		dam = pTargetData->MPMax.GetData() / 20;
		dam += Skilllv * 2;
// 		if (dam > userlv * 5)
// 		{
// 			dam = userlv * 5;
// 		}

		AddMp(TargetID, -dam);
//		dam /= 2;
		CorrectCureMP(dam, UserID, UserID);//��������
		dam = 0;
		break;
	case 156://ħ�����
// 		buf.remainingTimes = 3;
// 		buf.remainingTimes += (Skilllv - targetlv) / 5;
// 		break;
	case 159://��������
// 		buf.remainingTimes = 3;
// 		buf.remainingTimes += (Skilllv - targetlv) / 5;
// 		break;
	case 160:// ��˿��
		buf.remainingTimes = 3;
		buf.remainingTimes += (Skilllv - targetlv) / 5;
		buf.remainingTimes = getRemianTimeSelf();
		break;
	case 161: //����
		m_pFightState->ReMoveSealState(UserID);
		m_pFightState->ReMoveDeBuffState(UserID);
		m_pFightState->ReMovePoisionState(UserID);
		break;
	case 162:  //���޵���
		dam = Skilllv * 2 + (pUserData->Atk.GetData() / 5);
		dam = dam * 5 / 3;
		CountMagic2Damage�̶�(dam, UserID, TargetID);
		// 59 һЦ���
		if ((rand() % 100) < CheckMagicHit(Skilllv, 59, UserID, TargetID))
		{
			buf.remainingTimes = rand() % 3 + 1;
			buf.remainingTimes = getRemianTime();
		}
		break;
	case 164://����ͬ��
		dam = AddMp(TargetID, -10, userlv * 100);
		dam += AddMp(TargetID, Skilllv * 5);
		dam = 0;
		break;
	case 166://�þ���
		buf.remainingTimes = 3;
		buf.remainingTimes += (Skilllv - userlv) / 5;
		buf.remainingTimes = getRemianTimeSelf();
		break;
	case 171:
	case 172:
		break;
	case 167:
	case 168:
	case 169:
	case 170:
	case 1171:
	case 1172:
	{
		int cri = 0;
		int add = 0;
		if (sSkillID <= 169)
		{
			cri += Skilllv / 10;
		}
		else if (sSkillID > 170)
		{
			add += Skilllv;
		}
		pUserData->CriRate.d1 += cri;
		pUserData->DmgAdd.d1 += add;
		CountphysicalDamage(dam, UserID, TargetID);
		pUserData->CriRate.d1 -= cri;
		pUserData->DmgAdd.d1 -= add;
// 		else if (sSkillID == 168)
// 		{
// 			--pUserData->m_FightData.zhanyi;
// 		}
// 		else if (sSkillID == 169 || sSkillID == 171)
// 		{
// 			pUserData->m_FightData.zhanyi -= 2;
// 		}
// 		else if (sSkillID == 172)
// 		{
// 			pUserData->m_FightData.zhanyi -= 3;
// 		}
	}
		break;
	case 175: // ������ɽ
	case 176:
	case 177:
	case 181: // ����

	case 187: // ����
	case 188: // ����
	case 201: // �׻�
	case 204: // ����
		buf.remainingTimes = getRemianTimeSelf();
		break;
	case 182:
	case 185: // ������
		buf.remainingTimes = getRemianTime();
		break;
	case 186: // ������ �����ܵȼ�*3+80��*[(11-��������)/10]+�����˺�/4 
		dam = damPT;
		CountMagic2Damage�̶�(dam, UserID, TargetID);
		break;
	case 189: // ��ӿ����
		dam = Skilllv * 11 + 128;
		if (TargetID == pUserList->targetlist[0])
		{
			dam += dam / 2 + pUserData->HPMax.GetData() / 33;
		}
		dam2 = 128 + dam / 10;
		CorrectCureHP(dam, dam2, UserID, TargetID);
		break;
	case 193: // �ɼ�����
		if (Resurgence(TargetID))
		{
			dam2 = dam = Skilllv * 7 + 256;
			CorrectCureHP(dam, dam2, UserID, TargetID);//��������
		}

		break;
	case 194: // ��Ҷ����
		CountMagicDamage(dam, UserID, TargetID, 25);
		break;
	case 195: // ������
		CountMagicDamage(dam, UserID, TargetID, 40);
		break;
	case 196: // ������
		CountMagicDamage(dam, UserID, TargetID, 30);
		if ((rand() % 100) < 20)
		{
			AddHpHurt(TargetID, -dam / 20);
		}
		break;
	case 197: // ����ŭ
		CountMagicDamage(dam, UserID, TargetID, 30);
		if ((rand() % 100) < 20)
		{
			AddCp(TargetID, -dam / 50);
		}
		break;
	case 198: // ��ɱ �ȼ�*�ȼ�/100+���ȼ�+45��+������
		CountMagicDamage(dam, UserID, TargetID, 10086, eMWX��, dam2);
		buf.damage = dam2;
		buf.remainingTimes = 3;
		break;
	case 199: // Ѫ��
		dam2 = g_pMainState->m_SkillManager.GetSkill(sSkillID)->m_Cost;
		dam2 = pUserData->HPMax.GetData() * dam2 / 100;
		CountMagicDamage(dam, UserID, TargetID, 10087, eMWX��, dam2);
		buf.remainingTimes = 1;
		SetDateBuffUp(UserID, UserID, sSkillID, buf, Skilllv);
		buf.remainingTimes = c_bufRemainingTimesOnce;
		break;
	case 200: // ����֮��
	{
		int randstart, randend;
		if (UserID < 10)randstart = 0; else randstart = 10;
		randend = randstart + 5;
		int die = 0;
		for (int i = randstart; i < randend; i++)
		{
			sFightWork& list = g_pMainState->m_FightWorkList[i];
			if (!list.isExist)continue;
			if (list.CheckDie())
			{
				++die;
			}
		}
		dam = Skilllv * 4 + 128;
		dam += dam * die / 2;
		CorrectCureHP(dam, UserID, TargetID);
	}
		break;
	case 1001://ץ��

	{
		if (!pTargetData->m_Controler.CheckGrab())
		{
//			g_pMainState->m_Channel.AddNewString("�ö����޷�ץ��");
			pTarget->say("��ץ��?û��!");
			return;
		}
		cCharacter* pc1 = (cCharacter*)pUser->m_pIndex;
		if (pc1->m_PcData.m_NumofBB > 7)
		{
			g_pMainState->m_Tags.Add("�ٻ�������");
			break;
		}
		// �ݶ��ع�???
		cPet* pPet = (cPet*)pTarget->m_pIndex;
		if (pc1->m_PcData.m_Lv < pPet->GetData()->m_LvTake)//�ȼ�����
		{
			g_pMainState->m_Tags.Add("û�дﵽ���ٻ��޵�Я���ȼ�");
			break;
		}
		if ((rand() % 100) > 50)
		{

			m_pFightState->BackFromFight(TargetID);
			cPet* pPet = (cPet*)pTarget->m_pIndex;
			pc1->m_PcData.AddPet(pPet);
			pTarget->m_pIndex = 0;
			pTarget->m_IndexType = 0;
			m_pFightState->m_pFightWorkList[TargetID]->m_work.clear();
			
		}
	}
		break;


	case 1007://Ǭ����

	{
		cObj* target = g_pMainState->m_FightWorkList[TargetID].m_pObj;
// 		string targetname = target->m_TrueName.GetString();
// 		if (0 == targetname.compare(g_pMainState->m_taskSM.m_Npc.m_name))
		if (target == g_pMainState->m_taskSM.m_pNowObj)
		{
			cPropertyData* pData;
			target->GetPropertyData(pData);
//			if (pData->m_HP < (pData->HPMax.GetData()) / 2)
			{
				if (rand() % 100 > (pData->m_HP * 100 / pData->HPMax.GetData()))
				{
					dam = pData->m_HP;
					AddHp(TargetID, -dam);
					SetDamage(dam, TargetID);
					g_pMainState->m_taskSM.m_bXiangFuSuccess = true;
				}
			}

		}
	}
		break;
	case 2084:  //�׻�
		CountMagicDamage(dam, UserID, TargetID, 30, eMWX��);
		break;
	case 2085://������
		CountMagicDamage(dam, UserID, TargetID, 20/*35 - pUserList->m_NowTarget * 5*/, eMWX��);
		break;
	case 2086: //����
		CountMagicDamage(dam, UserID, TargetID, 30, eMWX��);
		if (rand() % 5 == 0)
		{
			AddCp(TargetID, -20);
		}
		break;
	case 2087: //̩ɽѹ��
		CountMagicDamage(dam, UserID, TargetID, 20/*30 - pUserList->m_NowTarget * 5*/, eMWX��);
// 		if (rand() % 10 == 0)
// 		{
// 			AddCp(TargetID, -20);
// 		}
		break;
	case 2088: //ˮ��
		CountMagicDamage(dam, UserID, TargetID, 30, eMWXˮ);
// 		if (rand() % 15 == 0)
// 		{
// 			m_pFightState->m_pFightWorkList[TargetID]->m_WorkType = -1;
// 		}
		break;
	case 2089: //ˮ����ɽ
		CountMagicDamage(dam, UserID, TargetID, 20/*30 - pUserList->m_NowTarget * 5*/, eMWXˮ);
// 		if (rand() % 30 == 0)
// 		{
// 			m_pFightState->m_pFightWorkList[TargetID]->m_WorkType = -1;
// 		}
		break;
	case 2090: //�һ�
		CountMagicDamage(dam, UserID, TargetID, 30, eMWX��);
		if (rand() % 10 == 0)
		{
			AddHpHurt(TargetID, -dam / 10);
		}
		break;
	case 2091: //�����һ�
		CountMagicDamage(dam, UserID, TargetID, 20/*30 - pUserList->m_NowTarget * 5*/, eMWX��);
// 		if (rand() % 20 == 0)
// 		{
// 			AddHpHurt(TargetID, -dam / 10);
// 		}
		break;
	case 2092://����һ��
		CountphysicalDamage(dam, UserID, TargetID/*, -10*/);
		AddMp(TargetID, -(dam / 4 + userlv / 3));
		break;
	case 2093://ҹ�����
		buf.remainingTimes = 3;
		dam = pUserData->PointStr * 3 / 2 + pUserData->Speed.GetData() / 3;
		AddHp(TargetID, -dam);
		SetDamage(dam, TargetID);
		break;
	case 2094://�����ٻ�
		CountphysicalDamage(dam, UserID, TargetID);
		if (rand() % 100 < 15)
		{
			buf.remainingTimes = 10;
		}
		break;
	case 2095://������ɽ ��ʱ��
		SetDateBuffUp(UserID, UserID, sSkillID, buf, Skilllv);

		break;
	case 1095://����
		CountphysicalDamage(dam, UserID, TargetID, 10086);
		break;
		
	case 2097:// ��������
		buf.remainingTimes = 6;
		break;
	case 2098://�ƶ��б�
		CountphysicalDamage(dam, UserID, TargetID, 10088);
		break;
	case 2099://���ݻ���
		CountphysicalDamage(dam, UserID, TargetID, 10087);
		break;
	case 2101://��η��ʩ
		buf.remainingTimes = 3;
		SetDateBuffUp(UserID, UserID, 1998, buf, Skilllv);
		break;
	case 2102://�콵���
		CountMagicDamage(dam, UserID, TargetID, 25);
		break;
	case 2105: //�¹�
		pUserData->DmgPercentOfMagic.d1 -= (pUserList->_moon - 2) * 20;
//		pUserData->m_MagicCriRate.d1 -= pUserData->m_FightProperty.AttackNum * 5;
		CountMagicDamage(dam, UserID, TargetID, 30);
		pUserData->DmgPercentOfMagic.d1 += (pUserList->_moon - 2) * 20;
//		pUserData->m_MagicCriRate.d1 += pUserData->m_FightProperty.AttackNum * 5;
		break;
	case 2110: //�����ķ�
		CountphysicalDamage(dam, UserID, TargetID, -35);
		break;
	case 2111: //���Ǵ�
		CountMagicDamage(dam, UserID, TargetID, 50);
		if (dam > 1)
		{
			AddMp(TargetID, dam / 5);
		}
		break;
	case 3000: //����
	{
		dam = CountHPPercent(pTargetData, 3, userlv);
		dam += 200;
		CorrectCureHP(dam, UserID, TargetID);//��������
	}
		break;
	case 3001: //����

	{
		dam = CountHPPercent(pTargetData, 6, userlv);
		dam += 400;
		CorrectCureHP(dam, UserID, TargetID);//��������
	}
		break;
	case 3002: //����

	{
		dam = CountHPPercent(pTargetData, 9, userlv);
		dam += 600;
		CorrectCureHP(dam, UserID, TargetID);//��������
	}
		break;
	case 3003: //����

	{
		dam = CountMPPercent(pTargetData, 10, userlv);
		dam += 150;
		CorrectCureMP(dam, UserID, TargetID);//��������
	}
		break;
	case 3004:  //����

	{
		dam = CountMPPercent(pTargetData, 15, userlv);
		dam += 240;
		CorrectCureMP(dam, UserID, TargetID);//��������
	}
		break;
	case 3006: //����
		dam = CountHPPercent(pTargetData, 50, userlv * 20 / 50);
		CorrectCureHP(dam, UserID, TargetID);//��������
		break;
	case 3005:  //����
	case 3007: //�ĺ���ƽ
		dam = CountHPPercent(pTargetData, 30, userlv * 12 / 30);
		CorrectCureHP(dam, UserID, TargetID);//��������
		break;
	case 3008://�ػ���
		if (Resurgence(TargetID))
		{
			dam = 150;// CountHPPercent(pTargetData, 20, userlv);
			AddHpHurt(TargetID, dam);
			CorrectCureHP(dam, UserID, TargetID);//��������
		}
		break;
	case 3009: //��������
		if (Resurgence(TargetID))
		{
			dam = CountHPPercent(pTargetData, 50, userlv * 20 / 50);
			CorrectCureHP(dam, UserID, TargetID);//��������
			AddHpHurt(TargetID, dam);
		}
		break;
	case 3010://ˮ��
	case 3012://����
		pTarget->ReMoveState(eBuffType��ӡ);
		pTarget->ReMoveState(eBuffType��);
		pTarget->ReMoveState(eBuffType����);
		break;
	case 3011://����
	case 3013://����
		pTarget->ReMoveState(eBuffType��ӡ);
		pTarget->ReMoveState(eBuffType��);
		pTarget->ReMoveState(eBuffType����);
		dam = CountHPPercent(pTargetData, 15, userlv * 12 / 15);
		CorrectCureHP(dam, UserID, TargetID);//��������
// 		pTarget->ReMoveState(eBuffType��ӡ);
// 		pTarget->ReMoveState(eBuffType��);
// 		pTarget->ReMoveState(eBuffType����);
		break;
	case 3016://Ц��ص�
		AddCp(TargetID, -70);
		break;
	case 3017://����ħ��
		AddCp(TargetID, -20);
		break;
	case 3018://Ұ��	
		if (!(pTargetData->m_FightData.m_AtkIntensify && 2))
			pTargetData->Atk.AddDataAddPercent(10);
		break;
	case 3019://ħ��֮ӡ
		if (!(pTargetData->m_FightData.m_AtkIntensify && 1))
			pTargetData->Atk.AddDataAddPercent(5);
		break;
	case 3020://���
		if (!(pTargetData->m_FightData.m_DefIntensify && 2))
			pTargetData->Def.AddDataAddPercent(10);
		break;
	case 3021://ʥ��
		if (!(pTargetData->m_FightData.m_DefIntensify && 1))
			pTargetData->Def.AddDataAddPercent(5);
		break;
	case 3022://����
		if (!(pTargetData->m_FightData.m_SpdIntensify && 2))
			pTargetData->Speed.AddDataAddPercent(10);
		break;
	case 3023://Х��
		if (!(pTargetData->m_FightData.m_SpdIntensify && 1))
			pTargetData->Speed.AddDataAddPercent(5);
		break;
	case 3024://̫������
		buf.remainingTimes = 3;
		break;
	case 3025://�޺�����
		buf.remainingTimes = 3;
		break;
	case 3026://������
		buf.remainingTimes = 3;
		break;
	case 3027://�����޷�
		buf.remainingTimes = 5;
		break;
	case 3028://��������
		if (!(pTargetData->m_FightData.m_AtkIntensify && 8))
		{
			pTargetData->m_FightData.m_AtkIntensify += 8;
			pTargetData->Atk.AddDataAddPercent(-10);
		}
		break;
	case 3029://��ɽѹ��
		if (!(pTargetData->m_FightData.m_AtkIntensify && 4))
		{
			pTargetData->m_FightData.m_AtkIntensify += 4;
			pTargetData->Atk.AddDataAddPercent(-5);
		}
		break;
	case 3030://�Ƽ���
		if (!(pTargetData->m_FightData.m_DefIntensify && 8))
		{
			pTargetData->m_FightData.m_DefIntensify += 8;
			pTargetData->Def.AddDataAddPercent(-10);
		}
		break;
	case 3031://�����
		if (!(pTargetData->m_FightData.m_DefIntensify && 4))
		{
			pTargetData->m_FightData.m_DefIntensify += 4;
			pTargetData->Def.AddDataAddPercent(-5);
		}
		break;
	case 3032://������
		if (!(pTargetData->m_FightData.m_SpdIntensify && 8))
		{
			pTargetData->m_FightData.m_SpdIntensify += 8;
			pTargetData->Speed.AddDataAddPercent(-10);
		}
		break;
	case 3033://ͣ����
		if (!(pTargetData->m_FightData.m_SpdIntensify && 4))
			pTargetData->Speed.AddDataAddPercent(-5);
		break;


	case 3034://��Ѫ
		pUserData->Pierce�̴�.d1 += 5;
		CountphysicalDamage(dam, UserID, TargetID, 45);
		pUserData->Pierce�̴�.d1 -= 5;
		break;

	case 3035://����
		pUserData->Pierce�̴�.d1 += 45;
		CountphysicalDamage(dam, UserID, TargetID, 5);
		pUserData->Pierce�̴�.d1 -= 45;
		break;

// 	case 3038://�Ǳ�ʥ��
// 		pTargetData->m_FightData.m_WallNum = 2;
// 		break;
// 	case 3039://������EX
// 
// 	{
// 		dam = CountHPPercent(pTargetData, 50, userlv);
// 		dam += 1000;
// 		CorrectCureHP(dam, UserID, TargetID);//��������
// 	}
// 		break;

	case 3040://����
		CountphysicalDamage(dam, UserID, TargetID, 0);
		AddMp(TargetID, -dam);
		break;	

// 	case 3043://����EX
// 		pUserData->Pierce�̴�.d1 += 80;
// 		CountphysicalDamage(dam, UserID, TargetID, 0);
// 		pUserData->Pierce�̴�.d1 -= 80;
// 		break;
// 
// 	case 3042://��Ѫ2
// 	case 3044://��ѪEX
// 		pUserData->Pierce�̴�.d1 += 5;
// 		CountphysicalDamage(dam, UserID, TargetID, 0);
// 		pUserData->Pierce�̴�.d1 -= 5;
// 		break;
// 
// 	case 3046://���֮ǽ
// 		pTargetData->m_FightData.m_WallNum = 1;
// 		break;
	case 3047://��������
		pTarget->ReMoveState(eBuffType��ӡ);
		pTarget->ReMoveState(eBuffType��);
		pTarget->ReMoveState(eBuffType����);
		buf.remainingTimes = 4;
		break;
	case 3048://�Ⱥ��ն�
		if (TargetID == UserID)
		{
			dam2 = pUserData->HPMax.GetData() / 10 - pUserData->m_HP2;
			if (dam2 < 0)
			{
				dam = 0;
				CorrectCureHP(dam, dam2, UserID, TargetID);
			}
			pUserData->m_MP = 0;
			if (UserID == g_pMainState->m_HeroID)
			{
				g_pMainState->m_PCHead.UpdatePcMp();
			}
		}
		else if (Resurgence(TargetID))
		{
			dam = CountHPPercent(pTargetData, 100, userlv << 5);
			AddHpHurt(TargetID, 100, 0xFFFF);
			CorrectCureHP(dam, UserID, TargetID);//��������
			pTarget->ReMoveState(eBuffType��ӡ);
			pTarget->ReMoveState(eBuffType��);
			pTarget->ReMoveState(eBuffType����);
		}

// 		Resurgence(TargetID);
// 		dam = CountHPPercent(pTargetData, 50, userlv);
// 		CorrectCureHP(dam, UserID, TargetID);//��������
// 		AddHpHurt(TargetID, dam);

		break;
// 	case 3049://Ѹ�����
// 		buf.remainingTimes = 5;
// 		break;

	default:
		if (sSkillID > 1000)
		{
			ERRBOX2(sSkillID);
		}
		return;
	}
	if (buf.remainingTimes != c_bufRemainingTimesOnce)
	{
		if (buf.remainingTimes < 1)buf.remainingTimes = 1;
		if (buf.remainingTimes > 1)
		{
			if (UserID < 10 && TargetID < 10)
				buf.remainingTimes += pTargetData->BuffedTiemsAdd;
			else
				if (TargetID>9 && UserID>10)
					buf.remainingTimes += pTargetData->BuffedTiemsAdd;
		}
		SetDateBuffUp(UserID, TargetID, sSkillID, buf, Skilllv);
	}
}

