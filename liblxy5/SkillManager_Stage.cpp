#include "_global.h"
#include "_txt.h"



bool cSkillManager::WaitForMagicPoint(int Waiter)
{
	cWasFile* file = m_pFightState->m_pFightWorkList[Waiter]->m_pObj->m_pShowData[0];
	const sFightPoint* p = m_pFightState->m_pFightWorkList[Waiter]->m_pObj->GetFightPoint();
	if (file->GetNowFrame() == p->m_MagicPoint &&file->GetWillNextFrame())
	{
		return true;
	}
	if (p->m_MagicPoint >= file->GetMaxFrame())
	{
		if (file->GetNowFrame() == file->GetMaxFrame() - 1 /*&& file->GetWillNextFrame()*/)
		{
			return true;
		}
	}

	return false;
}





bool cSkillManager::StageWaitProtect(int atkid, int UserID, int retStage)
{
	cObj* pTarget = g_pMainState->m_FightWorkList[UserID].m_pObj;
	cPropertyData* pTargetData;
	pTarget->GetPropertyData(pTargetData);
	int targetID = pTargetData->m_FightData.m_guardID[0];
	if (m_pFightState->ApproachProtect(targetID, UserID))
	{
		if (0 == g_pMainState->m_FightWorkList[targetID].m_work.size())
		{
			g_pMainState->m_FightWorkList[atkid].GetWork()->stage = retStage;
		}
	}
	return true;
}


bool cSkillManager::StageWaitFightBack(int UserID, int TargetID, int retStage)
{
	if (0 == m_pFightState->m_pFightWorkList[TargetID]->m_work.size())
	{
		m_pFightState->m_pFightWorkList[UserID]->GetWork()->stage = retStage;
	}
	return true;
}

bool cSkillManager::StageWaitReturn(int UserID, int retStage)
{
	if (m_pFightState->ReturnApproach(UserID))
	{
		if (-1 == retStage)
		{
			m_pFightState->m_pFightWorkList[UserID]->m_work.pop_back();
			return true;
		}
		m_pFightState->m_pFightWorkList[UserID]->GetWork()->stage = retStage;
	}
	return true;
}




bool cSkillManager::StageWaitSleep(int time, int UserID, int retStage)
{
	if (m_pFightState->m_pFightWorkList[UserID]->Sleep(time, false))
	{
		m_pFightState->m_pFightWorkList[UserID]->GetWork()->stage = retStage;
	}
	return true;
}




bool cSkillManager::PhysicalAtkHitStage(int UserID, int targetid, int sSkillID)
{
	sFightWork* pUserList = &g_pMainState->m_FightWorkList[UserID];
	cObj* pUser = pUserList->m_pObj;
	cPropertyData* pUserData;
	pUser->GetPropertyData(pUserData);
	int pos = 0;
	ulong id = 0x1D3FF13C;
	auto skill = g_pMainState->m_SkillManager.GetSkill(sSkillID);
	vector<ulong> ids;
	auto func = [&]()
	{
		if (skill && skill->m_MagicID)
		{
			ids.push_back(skill->m_MagicID);
		}
		const auto& s = ctt::getSkillHits();
		forr(s, i)
		{
			if ((int)s[i].e == sSkillID)
			{
				const auto& u = s[i];
				if (u.u1)
				{
					ids.push_back(u.u1);
				}
				if (u.u2)
				{
					ids.push_back(u.u2);
				}
				if (u.u3)
				{
					ids.push_back(u.u3);
				}
				break;
			}
		}
		if (ids.empty())
		{
			id = 0x1D3FF13C;
		}
		else
		{
			int turn = g_pMainState->m_pFightState->_turn;
			if (sSkillID == 1017 || sSkillID == 1010 || sSkillID == 141 || sSkillID == 142)
			{
				turn /= 2;
			}
			id = ids[max(0, turn) % ids.size()];
		}
	};
	switch (sSkillID)
	{
	case 0://��ɨ
		func();
		break;
	case 1010:
		func();
//		pos = -10;
		break;
	case 1017:
// 		id = 0xACA4A54A;
// 		id = 0x6AD55205;
		func();
		break;
	case 71://����ն
//		id = 0x4C117B7C;
		func();
		pos = -10;
		break;
	case 97://���꽣��0xD06119B3   
//		id = 0xC29A0737;
//		id = 0xA3FD9577;
		func();
		break;
	case 98: // ���ʽ
//		id = 0x66BEBCBA;
		func();
		break;
	case 141:
		func();
		break;
	case 142: // ӥ��
//		id = 2194212682;
		func();
		break;
	case 143: // ʨ��
//		id = 0x718754A2;
		func();
		break;
	case 148: // ������
//		id = 0x6AD55205;
//		id = 0xB0B36693;
		func();
		break;
	case 167:
	case 168:
	case 169:
	case 170:
	case 1171:
	case 1172:
		func();
		break;
	case 2092://����һ��
//		id = 0x3BA4B993;
		pUser->SetMagicSound(sSkillID, 50);
		pos = -10;
		func();
		break;
	case 2094://�����ٻ�
		pUser->SetMagicSound(sSkillID, 30);
		func();
		if (id == 0x4E02EC44)
		{
			pos = -10;
		}
		break;
	case 2096: //�����ķ�
//		id = 0xB0B36693;
		func();
		break;
	case 2098://�ƶ��б�
		pUser->SetMagicSound(sSkillID);
//		id = 0xDBFCCCBA;
//		id = 0xB0B36693;
		func();
		break;
	case 2099://���ݻ���
		pUser->SetMagicSound(sSkillID);
//		id = 0x6B59951D;
//		id = 0xB0B36693;
		func();
		break;
	case 2110://�����ķ�
		pUser->SetMagicSound(sSkillID);
//		id = 0xB0B36693;
		func();
		break;
	case 3034://��Ѫ
		pUser->SetMagicSound(sSkillID);
//		id = 0x171544B2;
		func();
		break;
	case 3035://����
		pUser->SetMagicSound(sSkillID);
//		id = 0xB1822745;
		func();
		break;
	case 3040://����
		pUser->SetMagicSound(sSkillID);
//		id = 0x21FAE73F;
		func();
		break;

	default:
		id = 0x1D3FF13C;

		// �º�ɨ?
//		id = 0xB0B36693;
		break;
	}

	cObj* pTarget = m_pFightState->m_pFightWorkList[targetid]->m_pObj;
	cPropertyData* pTargetData;
	pTarget->GetPropertyData(pTargetData);

	if (false == pTargetData->m_FightData.m_bHit)
	{
		if (g_pMainState->m_FightWorkList[targetid].m_work.size())
			if (g_pMainState->m_FightWorkList[targetid].GetWork()->type == WORKTYPE_AVOID)
				return false;
		m_pFightState->SetAvoid_state15(targetid, pUser->GetDirection());
		return false;
	}
	if (pUserData->m_FightData.m_bCri)
	{
		m_pFightState->SetSuffer_state30(targetid, pUser->GetDirection(), UserID);
		pTarget->SetSound(POS_SUFFER);
		id = 0xECD0E003; //��ɱ
	//	id = 0xDAD8AC20;
		pos = 0;
	}
	else
	{
		if (pTargetData->m_FightData.m_bDefend)
		{
			if (sSkillID == 1000)
			{
				id = 0x3622636F;
				id = 0xAC3D253B;
				pos = -10;
			}
			m_pFightState->SetDefend_stage30(targetid, pUser->GetDirection(), UserID);
			pTarget->SetSound(POS_DEF);
		}
		else
		{
			m_pFightState->SetSuffer_state30(targetid, pUser->GetDirection(), UserID);
			pTarget->SetSound(POS_SUFFER);
		}
	}
	m_pFightState->m_pFightWorkList[targetid]->SetMagiSufferID(id, pos, &m_pFightState->m_FullSkill.m_SufferMagic[targetid]);
	if (pUserData->m_FightData.m_bCri)
	{
		pTarget->m_MagicSuffer.m_FrameGap = 1;
	}
	else
	{
		pTarget->m_MagicSuffer.m_FrameGap = GetSpeed(0/*sSkillID*/);
	}
	return true;
}


static ulong getMagic(int sSkillID)
{
	if (sSkillID == 7)
	{
		return 0x559C8ECF;
	}
	if (sSkillID >= 1000 && sSkillID < 2000)
	{
		return 0;
	}

	sSkill* pskill = g_pMainState->m_SkillManager.GetSkill(sSkillID);
	ulong MagicID = pskill->m_MagicID;

	vector<ulong> ids;
	if (MagicID)
	{
		ids.push_back(MagicID);
	}
	const auto& s = ctt::getSkillActs();
	forr(s, i)
	{
		if ((int)s[i].e == sSkillID)
		{
			const auto& u = s[i];
			if (u.u1)
			{
				ids.push_back(u.u1);
			}
			if (u.u2)
			{
				ids.push_back(u.u2);
			}
			if (u.u3)
			{
				ids.push_back(u.u3);
			}
			break;
		}
	}
	if (ids.size() < 2)
	{
	}
	else if (g_GlobalValues[22] != 0)
	{
		int turn = g_pMainState->m_pFightState->_turn;
		if (sSkillID == 199)
		{
			// Ѫ��
//			turn /= 2;
		}
		// ͬһ�غ϶�ε��ã��ʲ������
		turn = turn % ids.size();
		turn = max(1, turn);
		MagicID = ids[turn];
	}
	return MagicID;
}



void cSkillManager::GetDelayAnd(int sSkillID, int& LateTime, ulong& magicID)
{
	magicID = getMagic(sSkillID);

// 	if (sSkillID == 163)
// 	{
// 		magicID = 0x8F3E73D5;
// 		magicID = g_pMainState->m_SkillManager.GetSkill(162)->m_MagicID;
// 	}

	cWasFile was;
	ifstream *fileWdf = nullptr;
	auto cb = [&](const uchar* data18)
	{
		if ((*(ushort*)data18) != 0x5053)
		{
			LateTime = 0;
			return;
		}
		LateTime = *(((ushort*)data18) + 3);
	};
	was.GetFileP(magicID, fileWdf, cb);
	return;
	//////////////////////////////////////////////////////////////////////////
	switch (sSkillID)
	{
	case 2105:
		LateTime -= 6;
		break;
	default:
		LateTime = 5;
		break;
	}

	switch (sSkillID)
	{
	case 11:
		LateTime = 7;
		break;
	case 28://���׷�
		LateTime = 5;
		break;
	case 88:// ����Ϸ��
		LateTime = 20;
		break;
	case 72://����
		LateTime = 10;
		break;
	case 74:
		LateTime = 10;
		break;
	case 79://����
		LateTime = 11;
		break;
	case  80:
		LateTime = 8;
		break;
	case 105://�չ⻪
		LateTime = 10;
		break;
	case 106://��׺�
		LateTime = 6;
		break;
	case 107://������
		LateTime = 20;
		break;
	case 108://��ã��
		LateTime = 6;
		break;
	case 109://���ѻ�
		LateTime = 8;
		break;
	case 116:  //������
		LateTime = 7;
		break;
	case 117:  //�й���
		LateTime = 2;
		break;
	case 131:// ��ɰ��ʯ
		LateTime = 10;
		break;
	case 132:// �������
		LateTime = 2;
		break;
	case 160: //
		LateTime = 4;
		break;
	case  162:
		magicID = 0x8F3E73D5;
		magicID = g_pMainState->m_SkillManager.GetSkill(162)->m_MagicID;
		break;
	case 2088:
		LateTime = 10;
		break;
	case 2089:
		LateTime = 20;
		break;
	case 2091:
		LateTime = 10;
		break;
	case 2101:
		LateTime = 10;
	case 2105:
		LateTime = 16;
		break;
	}
}



void cSkillManager::GetMagicAndNum�뼸(int Skilllv, int sSkillID, int UserID, int TargetID, ulong& MagicID, int& NumMax, int& MagicPos, bool& MagicUporDown, bool&  toAll1)
{
	toAll1 = isAni������(sSkillID);
	MagicUporDown = 1;
	if (sSkillID == 175)
	{
		MagicUporDown = false;
	}
	MagicID = getMagic(sSkillID);
	NumMax = 1;
	MagicPos = 0;
	cObj* pUserobj = g_pMainState->m_FightWorkList[UserID].m_pObj;
	cPropertyData* pUserData;
	pUserobj->GetPropertyData(pUserData);

	if (sSkillID < 1000 || sSkillID>= 2000)
	{
		sSkill* pskill = g_pMainState->m_SkillManager.GetSkill(sSkillID);
		MagicPos = pskill->m_MagicPos;
		if (pskill->m_TargetNumOffset > 0)
		{
			if (sSkillID >= 2000)
				NumMax = pUserData->m_Lv / pskill->m_TargetNumOffset + 1;
			else
				NumMax = Skilllv / pskill->m_TargetNumOffset + 1;
			if (NumMax > pskill->m_TargetNum)NumMax = pskill->m_TargetNum;
		}
		else NumMax = pskill->m_TargetNum;

	}
	switch (sSkillID)
	{
	case 1007:
		MagicID = 0x78246FE4;
		break;
// 	case 116:  //������
// 		MagicUporDown = false;
// 		break;
	case 1001: //ץ��
		MagicID = 0xBE7DDF16;
		break;
	}
	cct::setMagicPos(MagicID, MagicPos);
	

	NumMax += pUserData->TargetNumAdd;
	if (NumMax > 10)NumMax = 10;

}





bool cSkillManager::GetSkill��ҪĿ�걻�򶯻�(int ID)
{
	// �¹������϶���
	switch (ID)
	{
//	case 0:   // ��ɨǧ��
//	case 1:	  // ������
	case 7:	  // �Ƹ�����
	case 11:  // ������
	case 28:  // ���׷�
	case 31:  // ��������
//	case 71:  // ����ն
	case 72:  // ���׺䶥
	case 74:  // �������
	case 79:  // ����
	case 80:  // �������
	case 84:  // ����
	case 88:  // ����Ϸ��
//	case 97:  // ���꽣��
//	case 98:  // Ʈ��ʽ
	case 105: // �չ⻪
	case 106: // 
	case 107: // 
	case 108: // 
	case 109: // 
	case 116: // ������
	case 117: // �й���
	case 122: // ʬ����
	case 126: // ��Ȫ֮Ϣ
	case 131: // ��ɰ��ʯ
	case 132: // �������
//	case 141: // ����
//	case 142: // ӥ��
//	case 143: // ʨ��
//	case 148: // ������
	case 154: // ����
	case 155: // ����
	case 162: // ���޵���
//	case 167: // ��ʯ
//	case 168: // ������
//	case 169: // �������
//	case 171: // ����ŭ
//	case 172: // ��������
//	case 184: // ������
	case 186: // ������
//	case 193: // ��Ҷ����
	case 194: // ��Ҷ����
	case 195: // ������
	case 196: // ������
	case 197: // ����ŭ
	case 198: // ��ɱ
	case 199: // Ѫ��
//	case 1007:// �Ƹ�����2
	case 2084:// �׻�
	case 2085:// 
	case 2086:// 
	case 2087:// 
	case 2088:// 
	case 2089:// 
	case 2090:// 
	case 2091:// 
//	case 2092:// ����һ��
	case 2093:// ҹ�����
//	case 2094:// �����ٻ�
//	case 2098:// �ƶ��б�
//	case 2099:// ���ݻ���
//	case 2110:// �����ķ�
	case 2102:// �콵���
//	case 2105:// �¹�
	case 2111:// ���Ǵ�
// 	case 3034:
// 	case 3035:
// 	case 3040:
		return true;
	default:
		return false;
	}
}



int cSkillManager::GetSpeed(int skillid)
{
	ulong mag = skillid;
	if (mag == 0)
	{
		return 3;
	}
	if (mag < 3050)
	{
		ERRBOX2(mag);
	}
	cWasFile was;
	ifstream *fileWdf = nullptr;

	int speed;
	auto cb = [&](const uchar* data18)
	{
		if ((*(ushort*)data18) != 0x5053)
		{
			speed = 3;
			return;
		}
		speed = *(((ushort*)data18) + 3);

	};
	was.GetFileP(mag, fileWdf, cb);

	if (speed > 0)
	{
		speed = 75 / speed;
	}
	if (speed < 2)
	{
		speed = 2;
	}
	if (speed > 4)
	{
		speed = 4;
	}
	return speed;


	switch (skillid)
	{
	case 7:return 3;
	case 79:return 3;
	case 74:return 5;
	case 80:return 3;
	case 88:return 4;// ����Ϸ��
	case 107:return 3;
	case 131:return 3;
	case 142:return 3;
	case 2089:return 3;
	case 2091:return 3;
	case 2092:return 3;
	case 2093:return 3;
	case 2098:return 3;
	case 2101:return 2;

	default:
		return 5;
	}
}




bool cSkillManager::isAni������(int ID)
{
	switch (ID)
	{
	case 42: // ��
	case 74: // ����
	case 80: // �������
	case 84: // ����
	case 88: // ����
	case 131: // ��ɰ��ʯ
	case 172: // ��������
	case 194: // ��Ҷ����
	case 2087: // ̩ɽ
	case 2089: // ˮ��
	case 2091: // �����һ�
	case 2111: // ���Ǵ�
		return true;
	}
	return false;
}

