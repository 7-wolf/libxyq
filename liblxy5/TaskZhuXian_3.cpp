#include "_global.h"


bool TaskZhuXian::Process3(int stage)
{
	//С����
	setJobTitle("���ʵ�����(��ƪ)");
	switch (stage)
	{
	case 0:
		AddTriggerDialog("��! ��...", "���ˣ��α�Ϊ�������أ�һ����֪�����Ǽ�ðα�ӵģ���Ϣͦ��ͨ�����ô����ܵ���", 
			"���ǲ����������������ȥ���ƾ����˵ģ�", 
			"���ø�����ǢǢ��ָҲ��ó������������д��ƹٸ� ������ ������������ۺ���Ǳߵ����ܵظ� ������Ҳ����ȥ�������ҽ���������ߴ���ʹ�ߴ�ȥ�貨�ǡ�Ů��Ĺ������ɽ�ˣ��������������һ������ɵ���Ҳ������һ����", 
			"����......�ܵ�λ�������ǣ������������ľ�������û���ƽ�#18", 
			"��֮���������Զ�,#4��ͺܺð���");
		break;
	case 1:
	{
		AddEnemy(20000, e����, 50, eMP_����, "α-����");
		for (int i = 0; i < 4; ++i)
		{
			AddEnemy(10000, e����, 45, eMP_���);
		}

		for (int i = 0; i < 5; ++i)
		{
			AddEnemy(10000, e����, 45, eMP_���);
		}

		if (g_pMainState->m_InterfaceTeam.getLeaveBegin() == 5)
		{
			g_pMainState->SetFightPet(g_pMainState->m_HeroID, -1);
		}
		auto pc = AddEnemy(0, e��ͷ, 29, eMP_���ƹٸ�, "֣����", nullptr, -1, -1, true);
		if (pc)
		{
			pc->PointRemain = cct::PointRemian;
			pc->setPointAfterLv(g_pMainState->getAddpointFromMp(eMP_���ƹٸ�, true), true);
			pc->autoEquip(false);
			pc->autoData(false, true, true);
			pc->apply();
			pc->m_Controler.Set(0);
			g_pMainState->m_pFightState->m_FightMenu.SetControl(pc->m_IDinFightWorkList, false);

			g_pMainState->setNowSelect(pc->getObj());
		}
		readyFightAndSucces();
	}
		break;
	case 2:
		g_pMainState->FindObjByName("����")->say("Ϊ����ͷ,��ס����!");
		g_pMainState->awardEquip(50);
		AddTriggerObj("����");
		break;
	case 3:
		g_pMainState->awardk(100, 30);
		g_pMainState->m_pNowSelect = nullptr;
		AddTriggerDialog("", "��֮ǰ�Ŀ���������������#24�ⲻ��ѧ��", 
			"������ȥ׷����ɣ���Ȼ���������������ǾͲ������ˣ�����������Ҫ������ȥ�������ϵܵ��ھ֣��ּ�������#83",
			"�ⶼʲôʱ���˻�������Լ�����...");
		AddJob("��-#R����#R\n���ƾ��� 590 20" + g_strNeedBattle);
		break;
	case 4:
		AddTriggerObj("����", "���ƾ���");
		break;
	case 5:
		AddTriggerDialog("�����Ǽ���׷�����������ҵ������ǻ�������ס���ǵı���#28", 
			"���˰ɣ���Ҫ������������ʲô�������˶�����ǵĽ�����ͨ�ظϹ�����", 
			"����ν�����ó������ǲ��ǹٸ����ӵ��ˣ�����Ҳ��Ϊ������������ȡ���ʱ������Ǽ������Ҳ�Ǵ´�������", 
			"�Բ��𣬴�����ᱻ������#90");
		break;
	case 6:
	{
		auto pc = AddEnemy(200000, eǿ��, 40, eMP_���ƹٸ�, "����");
		pc->LiveHp = 100000;
		pc = AddEnemy(200000, eɽ��, 40, eMP_���ܵظ�, "���");
		pc->LiveHp = 100000;
		pc->Speed.AddDataAdd(8000);
		for (int i = 0; i < 4; ++i)
		{
			AddEnemy(15000, e����, 45, eMP_���);
		}

		for (int i = 0; i < 4; ++i)
		{
			AddEnemy(15000, e����, 45, eMP_���);
		}

		g_StateType = STATE_FIGHT;
		AddTriggerFightSuccess(_next + 1);
		AddTriggerFightTurn(_next);
	}
	break;
	case 7:
	{		
		int lnum = g_pMainState->GetLiveNum(10, 20);
		if (lnum == 1)
		{
			g_pMainState->m_pFightState->SuccessFight();
			break;
		}
		if (lnum != 2)
		{
			break;
		}

		cPcData* lb = g_pMainState->m_FightWorkList[11].m_pObj->getPcData();
		cPcData* lh = g_pMainState->m_FightWorkList[10].m_pObj->getPcData();
		lh->DmgAdd.d2 -= 1000000;
		lb->Hit.AddDataAdd(1000000);
		
		auto& list = g_pMainState->m_FightWorkList[11];
		list.m_pObj->ReMoveState(eBuffType��ӡ);
		auto& ski = list.m_SkillSelect;

// 		if (list.m_work.empty())
// 		{
// 			list.SetWork(WORKTYPE_ATTACK);
// 		}
// 		list.GetWork()->type = 
		list.m_WorkType = WORKTYPE_ATTACK;
		list.targetID = ski.TargetID = 10;
		ski.SkillID = 1000;

// 		list.m_MaxTargetNum = 1;
// 		list.targetlist[0] = 10;

		lb->getObj()->say("��,û�õķ���!");
		lh->getObj()->say("������!");
	}
	break;
	case 8:
		g_pMainState->awardEquip(50);
		AddTriggerObj("����");
		g_pMainState->FindObjByName("����")->say("��...����...������...��#R����#R��#R��ĸ��#R...��~");
		AddJob("��һ��#R����#R��");
		break;
	case 9:
		g_pMainState->awardk(150, 40);
		AddTriggerDialog("��...����...������...��#R����#R��#R��ĸ��#R...��~", "......");
		AddJob("�벻������#R���#R����Ļ��BOSS" + g_strNeedBattle);
		break;
	case 10:
		g_pMainState->FindObjByName("����")->m_ShowTime = 0;
		g_pMainState->m_Map.RemoveNpc("����", true);
		AddTriggerObj("���");
		break;
	case 11:
		AddTriggerDialog("�����վ�����ס...", "������ô˵�Ҿ������ˣ���˵���������ô��ô������ ������˻�������ʲô�������ֳ�ԭ�γ��#90");
		break;
	case 12:
		
		g_pMainState->setNowSelect("���.", g_pMainState->m_PetDataManager.m_PetList[e���ù�].m_dialoghead[0]);
		AddTriggerDialog("��ɶ��", "���ù֣���#60�����˼�Ұ����ô�ã������ٺ��˵Ĺ�����ϴ����Ҳ���������ҵĽ���¶#4");
		break;
	case 13:
	{
		auto pc = AddEnemy(30000, e���ù�, 50, eMP_���ܵظ�, "���");
		pc->LiveHp += 1000;
		pc->LiveRestoreRate += 50;
		pc->StartMagic = ePS_�������� + 2000;
		pc->DmgPercentOfFix.d2 += 30;
		pc->DmgPercentOfMagic.d2 += 20;
		pc->HitRateOfSeal.d1 += 10000;
		pc->DmgAddOfCure.d1 += 800;

		for (int i = 0; i < 4; ++i)
		{
			pc = AddEnemy(20000, e������, 50, eMP_���, "����");
		}

		for (int i = 0; i < 5; ++i)
		{
			pc = AddEnemy(20000, e������, 50, eMP_���, "����");
		}

		g_StateType = STATE_FIGHT;
		AddTriggerFightSuccess(_next + 1);
		AddTriggerFightTurn(_next);
		break;
	}
	case 14:
	{

		auto& list0 = g_pMainState->m_FightWorkList[10];
		if (!list0.isExist)
		{
			break;
		}
		cPropertyData* data = list0.m_pObj->getPropertyData();
		if (!data->m_FightData.cannotMagic)
		{
			list0.m_WorkType = WORKTYPE_MAGIC;
			auto& ski = list0.m_SkillSelect;
			list0.targetID = ski.TargetID = -1;
			ski.SkillID = 122;
			ski.SkillLv = cct::MaxSkillLv;
		}
		auto& gs = data->m_FightData.m_guardID;
		for (int i = 11; i < 20; ++i)
		{
			auto& list = g_pMainState->m_FightWorkList[i];
			if (!list.isExist)
			{
				continue;
			}

// 			g_pMainState->m_FightWorkList[Objselect].m_pObj->GetPropertyData(pTargetData);
// 			pTargetData->m_FightData.m_guardID.push_back(m_NowFighterID);
// 			m_pSkillSelect = 0;
// 			g_pMainState->m_FightWorkList[m_NowFighterID].m_WorkType = -2;
			if (std::find(gs.begin(), gs.end(), i) == gs.end())
			{
				gs.push_back(i);
			}
		}
	}
		break;
	case 15:
		g_pMainState->awardEquip(60);
		g_pMainState->FindObjByName("���")->say("�ڲ���ʡ���Ѱ�!");
		RemoveTriggerObj();
		g_pMainState->m_pNowSelect = nullptr;
		AddJob("#R������#RҲ�Ϲ�����");
		{
			sNpc npc;
			npc.Set("֣����", "���ƾ���", e��ͷ, 580, 20, DIRECTION_RIGHT);
			AddTriggerObjMap(&npc, _next, false);
		}
		break;
	case 16:
		g_pMainState->awardk(200, 50);
		lostTag("����");
		AddTriggerDialog("��붼����һϢ�ˣ�����Ӣ�۳����갡", "������뽫���������ش���������", "ĩ�����ȥ��");
		break;
	case 17:
		RemoveTriggerObjMap(580, 20);
		g_pMainState->m_Map.RemoveNpc("֣����", true);
		g_pMainState->m_Map.RemoveNpc("���", true);
		AddJob("����ȥ��һ�������ĸ��#R��ĸ#R��\n���ƹ��� 250 300");
		AddTriggerObj("��ĸ", "���ƹ���");
		break;
	case 18:
		AddTriggerDialog("�Ҷ�������Ӧ��...", "Ҳ�գ���Щ�����������Ӱ�...");
		break;
	case 19:
		AddJob("��#R���½�#R��̸\n���ƹ���\n���� ����");
		AddTriggerObj("���½�");
		break;
	case 20:
		AddTriggerDialog("������ƽԩ֮�����Իر�#15", "�Ѿ��ر��˺ܶྭ���װ����#24����ʵ������±���������Ļر���#1", "#120����������֪�����������޷��ɻ�����");
		break;
	case 21:
		AddJob("��#R����#R��̸\n���ƹ���\n#R��ɽ��#R��");
		AddTriggerObj("����", "��ɽ��");
		break;
	case 22:
		AddTriggerDialog("�ҳ�ñ�����֪��ĸƽ�����ӽ��Ժ�Ը���ⰲ����Ը�Դ˹��£�ׯ�Ϸ������ϱ����ض����¼���;�ࡣ���м����ߣ�Ϥ�������ġ�ͬ�����ֹ���������һ��");
		break;
	case 23:
		AddTag("���<���ʵ�����>����");
		g_pMainState->m_Job.ReMoveJob(this);
		g_pMainState->awardEquip(50);
		break;

#if 0
	case 0:
		g_GlobalValues[5] = 4;
		SetChapter(3);
		AddTriggerObj2(7, 8, 1);
		UpdateJob2(9);
		AddTriggerDialog2(1, -1);
		break;
	case 1://С����
		AddTriggerDialog2(2, 2);
		break;
	case 2://��������
	{
		cPropertyData* petdata = AddPetEnemy2(20000, e��������, 89/*, eMP_��������*/);
		petdata->MagicWater.d1 += 20;
		ePetID petid;
		for (int i = 0; i < 6; i++)
		{
			switch (rand() % 4)
			{
			case 0:petid = e��ة��; break;
			case 1:petid = e����; break;
			case 2:petid = eз��; break;
			default:petid = eС��Ů; break;
			}
			Add����Enemy2(10000, petid, 69);
		}
		SetMusic("Paranoia");
		g_StateType = STATE_FIGHT;
		AddTriggerFightSuccess(5);
	}
		return true;
	case 5:
	{
		SetJiangLi2(800000, 100000, 50000, 800000);
		AddChannel2(27);
		AddChannel2(38);
		AddTriggerObj2(7, 8, 6);

		g_GlobalValues[14] += 200;
		g_GlobalValues[15] += 200;
		// 			g_pCharacter->m_PCData.AddGrowing(1);
		// 			g_pCharacter->m_PCData.AddAvoidZZ(100);
		// 			g_pCharacter->m_PCData.AddHpZZ(100);
		//			g_pMainState->LockLv(67);

		// 			sShangPinPet sppet;
		// 			sAddPoint addpoint;
		// 			addpoint.Set(0, 0, 4, 1, 0);
		// 			sppet.Set(e��������,&addpoint,100,true);
		// 			GetPet(m_Textlist[35], &sppet, 100);
	}
		break;
	case 6://С����
		TalkList(0, 10, 11, 12, 7);
		break;
	case 7://����֮��
		AddTriggerDialog2(6, -1);
		AddTriggerObj2(13, 14, 8);
		UpdateJob2(15);
		break;
	case 8://��������
		AddTriggerDialog2(7, -1);
		AddTriggerObj2(16, 17, 9);
		UpdateJob2(18);
		break;
	case 9://з��
		AddTriggerDialog2(8, 10);
		break;
	case 10://з��
	{
		cPropertyData* pPet;
		pPet = Add����Enemy2(20000, eз��, 89, eMP_��������);
		pPet->MagicWater.d2 += 20;
		ePetID petid;
		for (int i = 0; i < 6; i++)
		{
			switch (rand() % 4)
			{
			case 0:petid = e����; break;
			case 1:petid = e����; break;
			case 2:petid = eз��; break;
			default:petid = eϺ��; break;
			}
			Add����Enemy2(10000, petid, 69);
		}
		SetMusic("ħ����Ů��");
		g_StateType = STATE_FIGHT;
		AddTriggerFightSuccess(11);
	}
		return true;
	case 11:
	{
		SetJiangLi2(810000, 100000, 50000, 810000);
		AddTriggerDialog2(9, -1);
		AddTriggerObj2(19, 17, 12);
		UpdateJob2(20);
		// 			g_pCharacter->m_PCData.AddMagZZ(50);
		// 			g_pCharacter->m_PCData.AddGrowing(1);
		//			g_pMainState->LockLv(70);
	}
		return true;
	case 12://��ʤ����
	{
		AddTriggerDialog2(10, -1);
		AddTriggerObj2(21, 22, 13);
		UpdateJob2(23);

	}
		break;
	case 13://��ͷ����
		g_pMainState->SetDialogListNpc(m_Textlist[19], 1001);
		AddTriggerDialog2(11, 14);
		break;
	case 14://
	{
		cPropertyData* pPet;
		pPet = Add����Enemy2(20000, e��ͷ����, 90, eMP_ʨ����, 21);
//		pPet->m_AtkDownHPHurt.d1 = 5;
		pPet = Add����Enemy2(20000, e����, 90, eMP_��������, 19);
		pPet->MagicWater.d2 += 20;
		pPet->SetJinJie(3);
		ePetID petid;
		for (int i = 0; i < 8; i++)
		{
			switch (rand() % 4)
			{
			case 0:petid = eţ��; break;
			case 1:petid = eϬţ����; break;
			case 2:petid = eϬţ������; break;
			default:petid = eҰ��; break;
			}
			Add����Enemy2(8000, petid, 69);
		}
		SetMusic("redmoon");
		g_StateType = STATE_FIGHT;
		AddTriggerFightSuccess(15);
	}
		return true;
	case 15:
	{
		g_pMainState->ClearDialogList();
		SetJiangLi2(850000, 100000, 50000, 850000);

		AddTriggerDialog2(12, -1);
		AddTriggerObj2(24, 25, 16);
		UpdateJob2(26);
		g_pMainState->ClearDialogList();
		// 			g_pCharacter->m_PCData.AddHpZZ(600);
		// 			g_pCharacter->m_PCData.AddGrowing(2);
		g_pMainState->LockLv(85);
	}
		return true;
	case 16://��ʴ��
		AddTriggerDialog2(13, -1);
		AddTriggerObj2(7, 8, 17);
		UpdateJob2(9);
		break;
	case 17://С����
		TalkList(14, -1, -1, -1, -1, 18);
		break;
	case 18:
		Process4(0);
		break;
#endif
	default:
		ERRBOX2(stage);
		break;

	}

	
	return true;
}
