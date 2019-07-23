#include "_global.h"


bool TaskZhuXian::Process2(int stage)
{
	setJobTitle("���ʵ�����(��ƪ)");

	static int s_hadG;
	switch (stage)
	{
	case 0:
		AddTriggerDialog("������һ��Ǯһ��~��˦����", "��ô����? ��Ʒ��?", "�����ֵ! ������Ҵ����������������", "��ɶ��û����~");
		g_pMainState->m_pNowSelect->say("������һ��Ǯһ��~��˦����", 0xFFFF);
		break;
	case 1:
	{
		auto pc = AddEnemy(15000, eϺ��, 40, eMP_��������);
		pc->getObj()->say("�ҿ�ɶ��û˵��#17");

		AddEnemy(8000, e��󡾫, 40, eMP_���);
		AddEnemy(8000, e����, 40, eMP_���);
		AddEnemy(8000, e����, 40, eMP_����);
		AddEnemy(8000, e��ë��, 40, eMP_���);
		AddEnemy(8000, e����, 40, eMP_���);
		AddEnemy(8000, e�󺣹�, 40, eMP_���);
		AddEnemy(8000, eС����, 40, eMP_����);

		g_pMainState->m_FightWorkList[13 + rand() % 5].m_pObj->say("����!����ˮ���¹�˭#118");

		readyFightAndSucces();
	}
	break;
	case 2:
		clearSay();
		g_pMainState->awardEquip(40);
		AddTriggerDialog("�����������#15", 
			"��������˳·ȥ����#24, ��Ϊ̫����,��������ˮ���²���ˮ��,��զ��˳��ǣ����ˮ�������", 
			"#15ۺ���Ǳ���λɽ��,���б�ˮ��", "����,�Ǳ���λ�Է�,��ȥ����");

		AddJob("ȥۺ���Ǳ����Է�#R����#R����ɽ������\n���ƹ���90 220");
		getTag("������s");
		break;
	case 3:
		AddTriggerObj("����");
		break;
	case 4:
		g_pMainState->awardk(80, 20);
		g_pMainState->FindObjByName("����")->say("#Rɽ��#R��40 240");
		g_pHeroObj->say("����л#24");
	//	AddTriggerDialog("���� 40 240", "������˾���ˬ��#24");
		AddJob("��#Rɽ��#R���ˮ��\n���ƹ��� 40 240" + g_strNeedBattle);
		AddTriggerObj("ɽ��", "���ƹ���", _next + 2);
		break;

		break;
	case 7:
		AddTriggerDialog("", "������û��! ÷����̫��!", 
			"#24�һ�ʲô��û˵��", 
			"�Ҳ���!�ѱ�ˮ�齻����!", 
			"����ֻ���俴�����б�ˮ��?", 
			"���۾�������,�����־Ƶ�,�ٳ���ʳ��Է����ְ�? �㿴�Ǳ߽��ݴ����貨�ǵ�����,�ֵ���ô�ɰ�", 
			"������������#14,�ݏCȭ����");
		break;
	case 8:
	{
		AddEnemy(15000, e��ʦ, 40, eMP_����);
		AddEnemy(8000, e������, 40, eMP_���);
		AddEnemy(8000, e����, 40, eMP_���);
		AddEnemy(8000, eС���, 40, eMP_���);
		AddEnemy(8000, eҰ��, 40, eMP_���);
		AddEnemy(8000, e��ͷ��, 40, eMP_���);
		AddEnemy(8000, e�ϻ�, 40, eMP_���);
		AddEnemy(8000, e����, 40, eMP_���);

		readyFightAndSucces();
		break;
	}
	case 9:
		g_pMainState->awardEquip(30);
		AddTriggerObj("ɽ��");
		g_pMainState->FindObjByName("ɽ��")->say("#15�һ���������ߵ�Ұ��,�����ɰ������Ա��");
		break;
	case 10:
		g_pMainState->awardk(80, 30);
		AddTriggerDialog("", "��ˮ��, л��");
		AddJob("������������\n#Rз����#R\n���� 30 15" + g_strNeedBattle);
		break;
	case 11:
		AddTriggerObj("з����", "����");
		break;
	case 12:
		g_pMainState->setNowSelect();
		AddTriggerDialog("���ߺ��˺�����ɺ�ħ!",
			"just wait a minute!#8");
		break;
	case 13:
	{
		AddEnemy(20000, eз��, 45, eMP_��������, "з����");
		AddEnemy(10000, e��ˮҹ��, 45, eMP_���);
		AddEnemy(10000, e����, 45, eMP_���);
		AddEnemy(10000, e����, 45, eMP_���);
		AddEnemy(10000, e��ة��, 45, eMP_���);
		AddEnemy(10000, eϺ��, 45, eMP_���);
		AddEnemy(10000, eϺ��, 45, eMP_���);
		AddEnemy(10000, eϺ��, 45, eMP_���);

		g_StateType = STATE_FIGHT;
		AddTriggerFightSuccess(_next + 1);
		AddTriggerFightTurn(_next);
		s_hadG = 0;
		break;
	}
	case 14:
	{
		int idG = -1;
		int num = 0;
		const sFightWork* fw = nullptr;
		for (int i = 10; i < 20; ++i)
		{
			const sFightWork& l = g_pMainState->m_FightWorkList[i];
			if (!l.isExist)
			{
				continue;
			}
			if (num == 0)
			{
				fw = &l;
			}
			if (l.m_pObj->m_TrueName.GetString() == "������")
			{
				idG = i;
				break;
			}
			++num;
		}
		if (idG < 0 && num < 5 && fw && !s_hadG)
		{
			int bbmode = g_pMainState->m_Map.m_EnemyList[rand() % g_pMainState->m_Map.m_NumOfEmemyType];
			sPetData* pm = g_pMainState->m_PetDataManager.GetPetData(bbmode);
			auto ppp = AddEnemy(20000, e����, 50, eMP_��������, "������");
			int cid = ppp->m_IDinFightWorkList;
			g_pMainState->m_pFightState->PrePareToFight(cid);
			ppp->FillHpMp();
			cObj* obj = ppp->getObj();
			obj->SetXY(g_pMainState->m_pFightState->m_ս������xs[cid], g_pMainState->m_pFightState->m_ս������ys[cid]);
			obj->MoveShadow();
			obj->MoveDialog();
			obj->MoveHpLine();
			obj->UpdateHpLine();
			obj->MoveName();
			g_pMainState->FindObj();
			fw->m_pObj->say("���߲���,����������");
			s_hadG = 1;
		}
		else if (idG >= 0 && g_pMainState->m_FightWorkList[idG]._myTurn == 1)
		{
			g_pMainState->m_FightWorkList[idG].m_pObj->say("���������������#2");
		}
	}
		break;
	case 15:
		clearSay();
		g_pMainState->awardEquip(50);
		AddTriggerDialog("", "ͣ!#90���е��������������", "#17��");
		AddJob("��#R��ǧ��#R��̸\n���� 100 60");
		break;
	case 16:
		AddTriggerObj("��ǧ��");
		break;
	case 17:
		g_pMainState->awardk(100, 30);
		lostTag("������s");
		AddTriggerDialog("�ǳ���л���������ǽ���˶������¼������ڹ����Ǹ����ˣ�������������ˮ���ȷ�оȹ������������˺������ǾͰ����ͻذ����ˣ�����ȥ����������Ҳ��֪��", "�ð�, ��ȥ�������½���");
	//	AddJob("����\n������ ��\n#R��ة��#R");
		AddJob("���¹�����������#R���½�#R\n���ƹ���\n����\n����");
		break;
	case 18:
		AddTriggerObj("���½�", "���ƹ���");
		break;
	case 19:
		AddTriggerDialog("��л��������������žͺã��������������ɢ�Ѿã������ɷ�Ը���æ��", "�н�����ȻԸ��#24");
		break;
	case 20:
		AddTriggerObj("С��");
		AddJob("�������ŵ���Ϣ\n#RС��#R\n���ƹ��� 60 70");
		break;
	case 21:
		AddTriggerDialog("�����ţ��ղ��Ǳ�����һ���ˣ��������һλ���˼�");
		break;
	case 22:
		AddJob("��������Ϣ�ˣ��������#R����#R\n���ƹ��� 30 30" + g_strNeedBattle);
		g_pMainState->FindObjByName("����")->say("..�Һ�...����#52");
		{
			sNpc npc;
			npc.Set("��Ʀ", "���ƹ���", e��ͽ, 26, 31, DIRECTION_LEFT);
			AddTriggerObjMap(&npc, _next, false);

			npc.Set("��å", "���ƹ���", eǿ��, 21, 29, DIRECTION_RIGHT);
			AddTriggerObjMap(&npc, _next, false);

			npc.Set("���", "���ƹ���", eɽ��, 24, 25, DIRECTION_UP);
			AddTriggerObjMap(&npc, _next, false);
		}
		g_pMainState->FindObjByName("��Ʀ")->say("..ιιι...��̫�ţ��ý��������ˣ�#52");
		g_pMainState->FindObjByName("��å")->say(".....����...��Ҳͦ����#52");
		g_pMainState->FindObjByName("���")->say("..�ٷϻ�...�Ͻ���Ǯ��������#52");
		break;
	case 23:
		AddTriggerDialog("��̫�ţ���ʲôֵǮ�Ķ����Ͽ콻������");
		break;
	case 24:
		g_pMainState->setNowSelect("����", g_pMainState->m_pNpcList[57].m_dialog);
		AddTriggerDialog("..�Һ�...����#52", "ס�֣���������Ǯ������");
		break;
	case 25:
	{
		auto p = AddEnemy(10000, e��ͽ, 5, "���");
		p->getObj()->say("��������֪������#15");
		AddEnemy(10000, eǿ��, 5, "��Ʀ");
		AddEnemy(10000, eɽ��, 5, "��å");


		g_StateType = STATE_FIGHT;
		AddTriggerFightSuccess(_next + 1);
		AddTriggerFightTurn(_next);
		break;
	}
	case 26:
	{
		for (int i = 10; i < 20; ++i)
		{
			auto& list = g_pMainState->m_FightWorkList[i];
			if (!list.isExist)
			{
				continue;
			}
			list.m_SkillSelect.SkillID = 1006;
			list.m_SkillSelect.TargetID = i;
		//	list.SetWork(WORKTYPE_MAGIC);
			list.m_WorkType = WORKTYPE_MAGIC;
			break;
		}
	}
	break;
	case 27:
		clearSay();
		g_pMainState->m_Map.RemoveNpc("��Ʀ", true);
		g_pMainState->m_Map.RemoveNpc("��å",  true);
		g_pMainState->m_Map.RemoveNpc("���",  true);
		RemoveTriggerObjMap(26, 31);
		RemoveTriggerObjMap(21, 29);
		RemoveTriggerObjMap(24, 25);
		AddTriggerObj("����");
		break;
	case 28:
		g_pMainState->awardk(50, 20);
		AddTriggerDialog("", "�������ţ��Ե���ӣ������ҭ�ţ�ˮ��~");
		break;
	case 29:
		getTag("����");
		g_pMainState->m_Map.RemoveNpc("����", true);
		AddTriggerObj("���½�");
		AddJob("��Ȼ�����ţ�����ȥ��#R���½�#R��\n���ƹ���\n����\n����");
		break;
	case 30:
		// ������������ţ�Ҳ�������պ�����͵�����������
		// getTag("���½�������");
		lostTag("����");
		AddTriggerDialog("����...��л������������ţ��������������͵�#R������#R��#R��#R");
		AddJob("����\n������ ��\n#R��ة��#R");
	case 31:
		AddTriggerObj("��ة��", "ة�ฮ");
		break;
	case 32:
		lostTag("���½�������");
		AddTriggerDialog("���겻��Ů��������⣬ԭ��������Ϊ�Ǹ�˭����#14");
		break;
	case 33:
		g_pMainState->m_pNowSelect = g_pMainState->FindObjByName("�����");
		AddTriggerDialog("�ҿ�����Ů����#15", "�����ҳ�ȥ̾����...");
		g_pMainState->m_pNowSelect->say("�ҿ�����Ů����#15");
		AddJob("�����һ������, ��#R��¶��#R�����˷���\n��˵#R#R��������#R����");
		break;
	case 34:
		AddTriggerGive("�����", 22, 58, _next);
		break;
	case 35:
		g_pMainState->awardk(0, 50);
		g_pMainState->m_pNowSelect = g_pMainState->FindObjByName("�����");
		AddTriggerDialog("лл�㣬�Һö���");
		break;
	case 36:
		g_pMainState->m_pNowSelect = g_pMainState->FindObjByName("��ة��");
		AddTriggerDialog("�����Ϸ�����ۣ���������ȥ���ʹ�#Rʥ��#R��������ַ����飡", "��ة�������.get() !");
		getTag("��ة�������");
		AddJob("�ʹ�����!\n������\n���ǵ�\n#R������#R");
		break;
	case 37:
		AddTriggerObj("������", "���ǵ�");
		break;
	case 38:
		AddTriggerDialog("�޵Ĵ��ƾ�Ȼ���������£�#Rκ����#R�����⼸λ���������������");
		lostTag("��ة�������");	
		AddJob("�ʹ�����!\n������\n���ǵ�\n#Rκ��#R");
		break;
	case 39:
		AddTriggerObj("κ��");
		break;
	case 40:
		AddTriggerDialog("�뼸λ��������ǰ��#R���ƹ���#R��#R��������#R�ַ�#R����!#R");
		getTag("����");
		AddJob("�ַ�����!\n���ƹ���\n���� ����\n�Ⱥ�#R���½�#R˵һ��");
		break;
	case 41:
		AddTriggerObj("���½�", "���ƹ���");
		break;
	case 42:
		AddTriggerDialog("���������ˣ��������Ѿ��͵���", "���ģ�����ͽ�#R����#Rȥߣ#R����#R�����Ǽ�ƽԩ#16");
		break;
	case 43:
		AddTriggerDialog("", "��#R����#Rȥߣ#R����#R#16");
		break;
	case 44:
		AddTriggerDialog("", "��#R����#Rȥߣ#R����#R#16");
		break;
	case 45:
		RemoveTriggerObj();
		g_pMainState->m_Job.ReMoveJob(this);
		break;

#if 0
		//������
	case 0:
		SetChapter(2);
		g_GlobalValues[5] = 2;
		AddTriggerDialog2(0, -1);
		AddTriggerObj2(1, 2, 1);
		UpdateJob2(16);
		break;
	case 1://������
		AddTriggerDialog2(1, -1);
		AddTriggerObj2(3, 4, 2);
		UpdateJob2(15);
		break;
	case 2://������
		AddTriggerDialog2(2, -1);
		AddTriggerObj2(5, 6, 3);
		UpdateJob2(17);
		break;
	case 3://Ů��
		AddTriggerDialog2(3, 4);
		break;
	case 4:
	{
		cPropertyData* pPet;
		pPet = Add����Enemy2(10000, eܽ������, 50, eMP_��˿��, 5);
		pPet->LiveHp += 10;
		pPet->ComboRate.d1 += 20;
		ePetID petid;
		for (int i = 0; i < 4; i++)
		{
			switch (rand() % 3)
			{
			case 0:petid = e��ͽ;
				break;
			case 1:petid = eǿ��;
				break;
			default:petid = eɽ��;
				break;
			}
			Add����Enemy2(8000, petid, 40);
		}
		SetMusic("��Ӱ��Ե");

		g_StateType = STATE_FIGHT;
		AddTriggerFightSuccess(5);
	}
		return true;
	case 5:
	{
		SetJiangLi2(450000, 100000, 50000, 450000);
		AddTriggerDialog2(4, -1);
		AddTriggerObj2(7, 6, 6);
		UpdateJob2(18);
		// 			g_pCharacter->m_PCData.AddDefZZ(50);
		// 			g_pCharacter->m_PCData.AddGrowing(1);
		//			g_pMainState->LockLv(57);
	}
		return true;
	case 6://������
		AddTriggerDialog2(5, 7);
		break;
	case 7:
	{
		cPropertyData* pPet;
		pPet = Add����Enemy2(10000, e��������, 59, eMP_��˿��, 7);
		pPet->HitRateOfPoison.d1 += 20;
		ePetID petid;
		for (int i = 0; i < 4; i++)
		{
			switch (rand() % 3)
			{
			case 0:petid = e֩�뾫;
				break;
			case 1:petid = e���꾫;
				break;
			default:petid = e��������;
				break;
			}
			Add����Enemy2(8000, petid, 50);
		}
		SetMusic("��Ӱ��Ե");
		g_StateType = STATE_FIGHT;
		AddTriggerFightSuccess(8);
	}
		return true;
	case 8:
	{
		g_pMainState->m_Friend.AddFriend(m_Textlist[28]);
		AutoGetPet(m_Textlist[28]/*, 0*/);
		SetJiangLi2(480000, 100000, 50000, 480000);
		AddTriggerDialog2(6, 88);
		AddTriggerObj2(8, 4, 9);
		UpdateJob2(15);
		// 			g_pCharacter->m_PCData.AddDefZZ(50);
		// 			g_pCharacter->m_PCData.AddGrowing(1);
		//			g_pMainState->LockLv(59);
	}
		return true;
	case 88:
		g_pMainState->m_Friend.Invite(m_Textlist[28]);
		AddChannel2(29);
		break;
	case 9://������
		AddTriggerDialog2(7, -1);
		AddTriggerObj2(9, 10, 10);
		UpdateJob2(20);
		break;
	case 10://������
		AddTriggerDialog2(8, -1);
		AddTriggerObj2(26, 10, 11);
		UpdateJob2(21);
		break;
	case 11://�����
		AddTriggerDialog2(9, 12);
		break;
	case 12:
	{
		cPropertyData* p = Add����Enemy2(10000, e����ս��, 60, eMP_ħ��կ, 26);
		p->StabRate.d1 = 100;
		p->StabPercent.d1 = 40;
		Add����Enemy2(8000, e����, 60);
		Add����Enemy2(8000, e�Ŵ�����, 60);

		SetMusic();
		g_StateType = STATE_FIGHT;
		AddTriggerFightSuccess(13);
	}
		return true;
	case 13:
	{
		SetJiangLi2(500000, 100000, 50000, 500000);
		AddTriggerDialog2(10, -1);
		AddTriggerObj2(9, 10, 14);
		UpdateJob2(22);
		//			g_pCharacter->m_PCData.AddGrowing(1);
		//			g_pMainState->LockLv(75);
	}
		return true;
	case 14://������
		AddTriggerDialog2(11, -1);
		AddTriggerObj2(11, 10, 15);
		AddTriggerGive(m_Textlist[9], 22, 30, 17);
		UpdateJob2(23);
		break;
	case 15:AddTriggerDialog2(12, 16); break;
	case 16:
		SetJiangLiItem(30, 22);
		SetJiangLi2(0, 40000);
		RemoveTriggerObj();
		AddTriggerDialog2(23, -1);
		break;
	case 17://������
		AddTriggerDialog2(13, -1);
		AddTriggerObj2(1, 2, 18);
		UpdateJob2(16);
		break;
	case 18://������
		AddTriggerDialog2(14, -1);
		AddTriggerObj2(12, 2, 19);
		UpdateJob2(24);
		break;
	case 19://����
		AddTriggerDialog2(15, -1);
		AddTriggerObj2(1, 2, 20);
		UpdateJob2(16);
		break;
	case 20://������
		AddTriggerDialog2(16, -1);
		AddTriggerObj2(12, 2, 21);
		UpdateJob2(24);
		break;
	case 21://Ҧ̫ξ
		AddTriggerDialog2(17, 22);
		break;
	case 22:
	{
		cPropertyData* ppet = Add����Enemy2(20000, e�콫, 69, eMP_�칬, 27);
		ppet->SetJinJie(2);
		ePetID petid;
		for (int i = 0; i < 4; i++)
		{
			switch (rand() % 2)
			{
			case 0:petid = e���;
				break;
			default:petid = e�콫;
				break;
			}
			Add����Enemy2(8000, petid, 59);
		}
		SetMusic();
		g_StateType = STATE_FIGHT;
		AddTriggerFightSuccess(23);
	}
		return true;
	case 23:
	{
		SetJiangLi2(550000, 100000, 50000, 550000);
		AddTriggerDialog2(18, 123);
		AddTriggerObj2(1, 2, 24);
		UpdateJob2(16);
		// 			g_pCharacter->m_PCData.AddAtkZZ(100);
		// 			g_pCharacter->m_PCData.AddGrowing(2);
		g_pMainState->LockLv(65);
	}
		return true;
	case 123:AddTriggerDialog2(24, -1); return true;
	case 24://������
		AddTriggerDialog2(19, -1);
		AddTriggerObj2(13, 14, 25);
		UpdateJob2(25);
		break;
	case 25://��ĸ����
		AddTriggerDialog2(20, 26);
		break;
	case 26:
	{
		cPropertyData* pPet;
		pPet = Add����Enemy2(20000, e������ȸ, 69, eMP_�칬);
		pPet->ComboNumDown += 1;
		ePetID petid;
		for (int i = 0; i < 7; i++)
		{
			switch (rand() % 4)
			{
			case 0:petid = e���;
				break;
			case 1:petid = e��ʦ;
				break;
			case 2:petid = e����;
				break;
			default:petid = e�粮;
				break;
			}
			Add����Enemy2(10000, petid, 59);
		}
		SetMusic();
		g_StateType = STATE_FIGHT;
		AddTriggerFightSuccess(27);
	}
		return true;
	case 27:
	{
		SetJiangLi2(550000, 100000, 50000, 550000);
		AddTriggerDialog2(21, -1);
		AddTriggerObj2(1, 2, 28);
		UpdateJob2(16);
		g_GlobalValues[14] += 200;
		g_GlobalValues[15] += 200;
		// 			g_pCharacter->m_PCData.AddDefZZ(100);
		// 			g_pCharacter->m_PCData.AddGrowing(1);
		//			g_pMainState->LockLv(75);
	}
		return true;
	case 28://������
		TalkList(22, -1, -1, 30, -1);
		g_pMainState->m_TaskZhuaGui.SetTrigger(this, 3, 29);
		break;
	case 29://ת������Ů������
		Process8(0);
		return true;
#endif
	default:
		ERRBOX2(stage);
		break;

	}


	return true;
}
