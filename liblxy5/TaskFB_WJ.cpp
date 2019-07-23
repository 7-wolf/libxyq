#include "_global.h"

void cTaskFB::ProcessWj(int stage)
{
	int lv = g_pCharacter->m_PcData.m_Lv;
	switch (stage)
	{
	case 0:

	{
		m_Stage = 0;
		g_pMainState->m_TriggerObj.AddTask(m_TextList[1], m_TextList[0], this, 1);
		g_pMainState->m_TriggerObjMap.AddTask(this, 2, m_TextList[3]);
		//			StageSetSameNpc(3, m_TextList[3], 3, 10, m_TextList[4]);
		StageSetSameNpc(3, m_TextList[3], 3, 60, m_TextList[4]);
		UpdateJob(m_TextList[20]);
	}
		break;
	case 1:

	{
		g_pMainState->m_pNowSelect->Talk(m_TextList[2], this, -100, "ȷ��", "ȡ��");
	}
		break;
	case -100:
		if (g_pMainState->m_Dialog.m_retSelect)
			return;
	case -1:

	{
		if (m_Stage < 10)
		{
			//				g_pMainState->m_Map.LoadMap(118, 90, m_TextList[3].c_str());
			g_pMainState->m_Map.LoadMap(160, 110, m_TextList[3].c_str());
		}
		else
		{
			//				g_pMainState->m_Map.LoadMap(30, 16, m_TextList[12].c_str());
			g_pMainState->m_Map.LoadMap(21, 38, m_TextList[12].c_str());
		}
	}
		break;
	case -2:
		break;
	case 2:

	{
		if (0 == m_Stage)
		{
			g_pMainState->m_TriggerDialog.AddTaskFB("0", 0, this, -2);
			m_Stage = 1;
		}
		AddNpc();
		ostringstream oss;
		oss << "��ʣ#R" << m_List.size() << "#R������";
		UpdateJob(oss.str(), 40);
	}
		break;
	case 3://����ս��

	{
		m_NowNpc = g_pMainState->m_pNowSelect;
		Add����EnemyF(lv * 200, e����, -1, eMP_���, m_NowNpc->m_TrueName.GetString());
		int enemynum = g_pMainState->AtutoGetEnemyNum() - 1;
		for (int i = 0; i < enemynum; i++)
		{
			Add����EnemyF(lv * 160, e����, -1, eMP_���, "���ľ��");
		}
		SetMusicFB();
		g_StateType = STATE_FIGHT;
		AddTriggerFightSuccess(4);
	}
		break;
	case 4://����ս��ʤ��

	{
		SetJiangLi(2);

		//			if (1==m_List.size())
		{
			if (1 == m_Stage)
			{
				g_pMainState->m_Map.RemoveAllNpc();
				m_List.clear();
				g_pMainState->m_TriggerDialog.AddTaskFB("0", 1, this, -5);
				m_Stage += 1;
			}
			return;
		}
		RemoveNpc(m_NowNpc);
		ostringstream oss;
		oss << "��ʣ#R" << m_List.size() << "#R������";
		UpdateJob(oss.str());
	}
		break;
	case -5:

	{
		RemoveNpc(m_NowNpc);
		//			StageSetSameNpc(1111, m_TextList[3], 6, 15, m_TextList[6]);
		StageSetSameNpc(1111, m_TextList[3], 6, 59, m_TextList[6]);
		g_pMainState->m_TriggerObjMap.AddTask(this, 5, m_TextList[3]);
		ostringstream oss;
		oss << "��ʣ#R" << m_List.size() << "#R������";
		UpdateJob(oss.str(), 40);
	}
		break;
	case 5:

	{
		AddNpc();
		ostringstream oss;
		oss << "��ʣ#R" << m_List.size() << "#R������";
		UpdateJob(oss.str(), 40);
	}
		break;
	case 6:

	{ //����һ������
		m_NowNpc = g_pMainState->m_pNowSelect;
		RemoveNpc(m_NowNpc);
		m_NowNpc = 0;
		SetJiangLi(2, 300, 50);
		//			if (!m_List.size())
		{ //������Ϊ0
			g_pMainState->m_Map.RemoveAllNpc();
			cObj obj;
			//				obj.SetXY(116 * 20, g_pMainState->m_Map.m_pMap->m_Height - 23 * 20);
			obj.SetXY(132 * 20, g_pMainState->m_Map.m_pMap->m_Height - 90 * 20);
			//				g_pMainState->m_FindPt.findAstart(&obj, 26 * 20, g_pMainState->m_Map.m_pMap->m_Height - 42 * 20);
			g_pMainState->m_FindPt.findAstart(&obj, 230 * 20, g_pMainState->m_Map.m_pMap->m_Height - 140 * 20);
			//				m_List.resize(15);
			m_List.resize(10);
			int timenum = obj.m_AstartPathIndex / m_List.size();
			for (int i = 0; i < m_List.size(); i++)
			{
				SetNpc(m_List[i], 8, m_TextList[9], m_TextList[3], 15, obj.m_AstartPathVecs[obj.m_AstartPathIndex].x / 20,
					(g_pMainState->m_Map.m_pMap->m_Height - obj.m_AstartPathVecs[obj.m_AstartPathIndex].y) / 20);
				obj.m_AstartPathIndex -= timenum;
			}
			UpdateJob(m_TextList[10]);
			g_pMainState->m_Tags.Add(m_TextList[10]);
			//����
			m_List2.resize(1);
			//				SetNpc(m_List2[0],-7,m_TextList[8], m_TextList[3], 1003,18,35);
			SetNpc(m_List2[0], -7, m_TextList[8], m_TextList[3], 1003, 130, 80);
			AddTriggerObjMap(m_TextList[3], -6);
			m_Stage = 2;
			Process(-6);
			AddTriggerDialog(3, -2);
			return;
		}
		ostringstream oss;
		oss << "��ʣ#R" << m_List.size() << "#R������";
		UpdateJob(oss.str());
	}
		break;
	case -6: //��������

	{
		if (m_Stage == 3)
		{
			AddNpc();
		}
		else
			AddNpcOne(&m_List2[0], true);
	}
		break;
	case -7://������Ի�

	{
		if (2 == m_Stage)AddTriggerDialog(2, 7);
	}
		break;
	case 7://����������

	{
		m_Stage = 3;
		sJob job;
		job.Set(m_TextList[5], m_TextList[7], 40, this, 1002);
		g_pMainState->m_Job.AddaJob(job);
		Process(-6);
	}
		break;
	case 8://����ս��

	{
		m_NowNpc = g_pMainState->m_pNowSelect;
		cPropertyData* pet;
		pet = Add����EnemyF(lv * 280, e����, lv + 5, eMP_������, m_NowNpc->m_TrueName.GetString());
		pet->AddSkill(ePS_����);
		pet = Add����EnemyF(lv * 280, eţ��, lv + 5, eMP_ħ��կ, "�󷨾���");
		pet->DmgPercentOfMagic.d2 += 60;
		pet = Add����EnemyF(lv * 280, e��ͷ��, lv + 5, eMP_���ƹٸ�, "��������");
		pet->DmgPercent.d2 += 60;
		SetMusicFB();
		g_StateType = STATE_FIGHT;
		AddTriggerFightSuccess(9);
	}
		break;
	case 9://��������

	{
		SetJiangLi(3);
		RemoveNpc(m_NowNpc);
		m_NowNpc = 0;
		//			if (!m_List.size())
		{
			m_List2.clear();
			m_List.clear();
			//				StageSetSameNpc(36, m_TextList[12], 11, 3, m_TextList[13]);
			StageSetSameNpc(36, m_TextList[12], 11, 58, m_TextList[13]);
			g_pMainState->m_Channel.AddNewString(m_TextList[11]);
			m_Stage = 10;
			g_pMainState->m_TriggerObjMap.AddTask(this, 10, m_TextList[12]);
			Process(-1);
			return;
		}
		ostringstream oss;
		oss << "��ʣ#R" << m_List.size() << "#R������";
		UpdateJob(oss.str());
	}
		break;
	case 10://�������ֳ���

	{
		UpdateJob(m_TextList[11], 40);
		AddNpc();
	}
		break;
	case 11://�������� ս��

	{
		//			m_NowNpc = g_pMainState->m_pNowSelect;

		m_NowNpc = g_pMainState->m_pNowSelect;
		Add����EnemyF(lv * 250, e����ս��, lv + 5, eMP_���, m_NowNpc->m_TrueName.GetString());
		for (int i = 0; i < 2; i++)
			Add����EnemyF(lv * 200, e���ӹ�, lv + 3, eMP_���, "��������");
		for (int i = 0; i < 5; i++)
		{
			Add����EnemyF(lv * 180, eţͷ, -1, eMP_���, "����ʿ��");
		}
		SetMusicFB();
		g_StateType = STATE_FIGHT;
		AddTriggerFightSuccess(12);
	}
		break;
	case 12:

	{
		SetJiangLi(5);
		RemoveNpc(m_NowNpc);
		m_NowNpc = 0;
		//			if (!m_List.size())
		{ //���� ;
			g_pMainState->m_Map.RemoveAllNpc();
			vector<int>  modeid;
			modeid.resize(30);
			for (int i = 0; i < 30; i++)
				modeid[i] = i;
			//				StageSetSameNpc(modeid, m_TextList[12], 15, 15, m_TextList[16]);
			StageSetSameNpc(modeid, m_TextList[12], 15, 58, m_TextList[16]);
			g_pMainState->m_TriggerObjMap.AddTask(this, 13, m_TextList[12]);
			UpdateJob(m_TextList[14], 40);
			g_pMainState->m_Channel.AddNewString(m_TextList[14]);
			return;
		}
		if (m_List.size() == 2)
		{
			UpdateJob(m_TextList[11], 5);
		}
	}
		break;
	case 13:

	{
		UpdateJob(m_TextList[14], 40);
		g_pMainState->m_Channel.AddNewString(m_TextList[14]);
		AddNpc();
	}
		break;
	case 15://С��ս��

	{

		m_NowNpc = g_pMainState->m_pNowSelect;

		Add����EnemyF(lv * 200, (ePetID)m_NowNpc->GetModeID(), -1, eMP_���, m_NowNpc->m_TrueName.GetString());
		for (int i = 0; i < 4; i++)
		{
			Add����EnemyF(lv * 160, (ePetID)(rand() % 40), -1, eMP_���, m_NowNpc->m_TrueName.GetString());
		}
		SetMusicFB();
		g_StateType = STATE_FIGHT;
		AddTriggerFightSuccess(16);
	}
		break;
	case 16://С������

	{
		SetJiangLi(2);
		RemoveNpc(m_NowNpc);
		//			if (!m_List.size())
		{ //
			m_List.resize(1);
			//				SetNpc(m_List[0],18,m_TextList[19], m_TextList[12], 51, 64, 32, 1);
			SetNpc(m_List[0], 18, m_TextList[19], m_TextList[12], 51, 56, 177, 1);
			g_pMainState->m_TriggerObjMap.AddTask(this, 17, m_TextList[12]);
			UpdateJob(m_TextList[15]);
			Process(17);
			return;
		}

	}
		break;
	case 17://BOSS����

	{
		g_pMainState->m_Tags.Add(m_TextList[15]);
		AddNpc();
	}
		break;
	case 18:

	{
		m_NowNpc = g_pMainState->m_pNowSelect;
		cPropertyData* pPet;
		Add����EnemyF(lv * 300, e�������, lv + 10, eMP_ʨ����, m_NowNpc->m_TrueName.GetString());
		for (int i = 0; i < 4; i++)
		{
			pPet = AddPetEnemyF(lv * 280, e��󡾫, lv + 5/*, eMP_���*/, "���");
			pPet->ComboRate.d1 = 120;
			pPet->ComboNumUp = 4;
		}
		for (int i = 0; i < 5; i++)
		{
			pPet = AddPetEnemyF(lv * 250, e���꾫, lv/*, eMP_���*/, "ʹŮ");
			pPet->ComboRate.d1 = 80;
			pPet->ComboNumUp = 6;
		}
		SetMusicFB();
		g_StateType = STATE_FIGHT;
		AddTriggerFightSuccess(21);
	}
		break;
	case 21://
	{
		g_pMainState->m_Map.RemoveAllNpc();
		g_pMainState->m_Map.LoadMap(20, 20, "�ڼ�����");
		m_List.resize(20);
		StageSetSameNpc(1125, "�ڼ�����", 20, m_List.size(), "����");
	}
		break;
	case 20:
	{
		m_NowNpc = g_pMainState->m_pNowSelect;
		cTaskJiangLi jiangli;
		jiangli.Add(33, 27, 4);//�ʹ�
		jiangli.AddHShouJue(2);//���޾�
		jiangli.SetExp(30, 8);
		jiangli.SetMoeny(25, 8);
		jiangli.AutoGetJiangLi();
		RemoveNpc(m_NowNpc);
		if (m_List.size() < 3)
		{
			Process(19);
		}
	}
		break;
	case 19:

	{
		//			SetJiangLi(10);
		//			RemoveNpc(m_NowNpc);

		g_pMainState->m_Channel.AddNewString(m_TextList[17]);
		g_pMainState->m_Tags.Add(m_TextList[17]);
	}
	case 1002:

	{
		EndFB();
	}
		break;
	default:
		ERRBOX;
		break;
	}
}