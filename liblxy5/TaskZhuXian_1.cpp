#include "_global.h"



bool TaskZhuXian::Process1(int stage)
{
	static string s_jobTitle = "���ʵ�����(��ƪ)";
	static string s_needbattle = "\n(��ս��)";
	int next = stage + 1;
	switch (stage)
	{
	case 0:
		g_pMainState->setNowSelect();
		AddTriggerDialogList({ "�ҵİ�¹ȥ����?", "�õ�֪����#28���ȥ���������һ���"}, next);
		AddJob(s_jobTitle, "ȥ#R���ƾ���#R��#R��¹��#R" + s_needbattle);
		break;
	case 1:
		AddTriggerObj("��¹��", "���ƾ���", next);
		break;
	case 2:
		g_pMainState->setNowSelect();
		AddTriggerDialogList({ "��ͷ�ӽ��������ǲ�,�Ҳ���ȥ", "�����ո��޳�����#24��������Ƶ�������", 
			"�Ҳ�����Ҫ��С������һ��#97"}, next);
		break;
	case 3:
	{
		auto pc = g_pMainState->AddEnemy(e��ɫ¹, 25, eMP_�貨��, "��¹��");
		pc->HPMax.SetData(5000);
		pc->FillHpMp();

		pc = g_pMainState->AddEnemy(e���꾫, 25, eMP_��˿��, "�������");
		pc->HPMax.SetData(5000);
		pc->FillHpMp();
		pc->getObj()->say("�ҵ�ϷС��,�����ﲻ�������#24");


		pc = g_pMainState->AddEnemy(e����, 20, eMP_���);
		pc->HPMax.SetData(3000);
		pc->FillHpMp();

		pc = g_pMainState->AddEnemy(e����, 20, eMP_���);
		pc->HPMax.SetData(3000);
		pc->FillHpMp();

		pc = g_pMainState->AddEnemy(eС���, 20, eMP_���);
		pc->HPMax.SetData(3000);
		pc->FillHpMp();

		g_StateType = STATE_FIGHT;
		AddTriggerFightSuccess(next);
	}
		break;
	case 4:
		clearSay();
		g_pMainState->awardEquip(30);
		g_pHeroObj->Talk("��ô��, ��ȥ�������̰�");
		AddJob(s_jobTitle, "��#R���ٴ�#R��#R�ϼ�����#R");
		AddTriggerObj("�ϼ�����", "���ٴ�", next);
		break;
	case 5:
		g_pMainState->awardk(20, 10);
		g_pMainState->m_pNowSelect->Talk("���˰���,�����㻯��ʱ���ʾ�һ��,����˷��ľ�����ȥ��,�¹���������,�����˷�ϵ�����ת��,���ɵ��Ҷ��в���,����������ȥ��#R������#R��#R��������#R�˽�һ���й����ʵ�����");
		AddTriggerObj("��������", "���۱���", next);
		AddJob(s_jobTitle, "ȥ#R������#R���#R���۱���#R�ݷ�#R��������#R");
		break;
	case 6:
		g_pMainState->m_pNowSelect->Talk("���Ѫ��, ������������, ���Ͷ������");
		AddTriggerObj("����", "��ɽ��", next);
		AddJob(s_jobTitle, "��Ѫ�齻��#R����#R\n#R��ɽ��#R");
		getTag("����������Ѫ��");
		break;
	case 7:
		g_pMainState->m_pNowSelect->Talk("�о�������ʮ�뵽��ս��!");
		AddTriggerObj("�������", "��ɽ��", next);
		AddJob(s_jobTitle, "�϶���#R�������#R���,��Ҫ��Ϊʲô֪��" + s_needbattle);
		break;
	case 8:
		g_pMainState->setNowSelect();
		AddTriggerDialogList({"����Ľ���ʺް�!��Сʦ���ͳ�����,����ס�ֽ���������,�������Ǹ�û�и�ĸ��Ұ����!", "��������¶�������?"}, next);
		break;
	case 9:
	{
		auto pc = g_pMainState->AddEnemy(e�ۺ�, 30, eMP_������, "�������");
		pc->HPMax.SetData(6000);
		pc->FillHpMp();

		pc = g_pMainState->AddEnemy(e�ۺ�, 30, eMP_����, "ľ��ɮ");
		pc->HPMax.SetData(6000);
		pc->FillHpMp();

		pc = g_pMainState->AddEnemy(e�ۺ�, 30, eMP_��ϵ, "����ɮ");
		pc->HPMax.SetData(6000);
		pc->FillHpMp();

		pc = g_pMainState->AddEnemy(e�ۺ�, 30, eMP_��ϵ, "ɨ��ɮ");
		pc->HPMax.SetData(6000);
		pc->FillHpMp();

		pc = g_pMainState->AddEnemy(e�ۺ�, 30, eMP_����, "��ɮ");
		pc->HPMax.SetData(6000);
		pc->FillHpMp();

		g_pMainState->m_FightWorkList[11 + rand() % 4].m_pObj->say("˭�гԵĺȵİ��͸�˭");

		g_StateType = STATE_FIGHT;
		AddTriggerFightSuccess(next);
	}
		break;
	case 10:
		clearSay();
		g_pMainState->awardEquip(40);
		AddTriggerDialogList({ "", "��ҩ������!", "������,��ҩʲô�Ĳ����ڵ�", "...��֪������ô˵,���б�İ취,������¹��ź��" }, next);
		AddJob(s_jobTitle, "����ҽ#R������Ů#R������ʲô�취�ܽ����ʵĶ�\n����ɽ->������");
		break;
	case 11:
		AddTriggerObj("������Ů", "������", next);
		break;
	case 12:
		g_pMainState->awardk(30, 15);
		g_pMainState->setNowSelect();
		AddTriggerDialogList({ "�����зݵ�ҩ,��Ҫ���������������Ч", "������Ҫ��һ��#R���ܵظ�#R��" }, next);
		AddJob(s_jobTitle, "��#R����#R��Ҫ������\n#R���ܵظ�#R");
		g_pMainState->awardItem(22, 45, 1, true);
		break;
	case 13:
		AddTriggerObj("����", "���ܵظ�", next);
		break;
	case 14:
		AddTriggerDialogList({ "ԭ����������Ů��ָ��, ������, #R�����Թ�һ��#R��#R��ڤ��#R����Ϻ��ҵ���,��������ȰȰ��, �³�֮�����㰾һ��" }, next);
		AddJob(s_jobTitle, "Ȱ#R��ڤ��#R����\n#R�����Թ�һ��#R" + s_needbattle);
		break;
	case 15:
		AddTriggerObj("��ڤ��", "�����Թ�һ��", next);
		break;
	case 16:
		AddTriggerDialogList({ "�Ҳ����Ҳ����ҾͲ���!����������!", "cho tto ma tte ku da sa! #35"}, next);
		break;
	case 17:
	{
		auto pc = g_pMainState->AddEnemy(eѲ������, 35, eMP_���ܵظ�, "��ڤ��");
		pc->HPMax.SetData(10000);
		pc->FillHpMp();
		g_pMainState->setNowSelect(pc->getObj());

		for (int i = 0; i < 7; ++i)
		{
			int r = rand() % 100;
			int m = e��ʬ;
			if (r < 35)
			{
				m = eҰ��;
			}
			else if (r < 65)
			{
				m = e���ù�;
			}
			else
			{
				m = e��ʬ;
			}
			pc = g_pMainState->AddEnemy(m, 30, eMP_���);
			pc->HPMax.SetData(6000);
			pc->FillHpMp();
		}
		g_StateType = STATE_FIGHT;
		AddTriggerFightSuccess(next);
	}
		break;
	case 18:
		g_pMainState->awardEquip(40);
		AddTriggerDialogList({ "", "���������Ľ���", "�һ�������Ҽ�����#17", "��������#68" }, next);
		AddJob(s_jobTitle, "����ڤ��������#R����#R\n#R���ƹ���#R\n�������2");
		getTag("��ڤ�������");
		break;
	case 19:
		AddTriggerObj("����", "�������2", next);
		break;
	case 20:
		g_pMainState->awardk(50, 20);
		AddTriggerDialogList({ "лл��, ������������, ����һ�з���"}, next);
		AddJob(s_jobTitle, "������������#R��ڤ��#R\n#R�����Թ�һ��#R");
		lostTag("��ڤ�������");
		getTag("���������");
		break;
	case 21:
		AddTriggerObj("��ڤ��", "�����Թ�һ��", next);
		break;
	case 22:
		AddTriggerDialogList({ "����#1������ȥ����#R����#R��,�ҽ������������������"}, next);
		AddJob(s_jobTitle, "���ڿ���ȥ��#R����#R��\n#R���ܵظ�#R");
		lostTag("���������");
		break;
	case 23:
		AddTriggerObj("����", "���ܵظ�", next);
		break;
	case 24:
		g_pMainState->m_pNowSelect->Talk("лл��,����������,��ȥæ��");
	//	AddTriggerObj("����", "��ɽ��", next);
		AddTriggerGive("����", 22, 45, 25);
		AddJob(s_jobTitle, "��#R����#Rι#R��ת���굤#R\n(����)\n#R��ɽ��#R");
		getTag("������");
		break;
	case 25:
		lostTag("������");
		lostTag("����������Ѫ��");
		g_pMainState->setNowSelect(g_pMainState->FindObjByName("����"));
		AddTriggerDialogList({ "��Ѫ��...ԭ���������вش������!ԭ��ĸ������#15"}, next);
		RemoveTriggerGive();
		break;
	case 26:
		AddTriggerDialogList({ "", "��һ�����,������ֶ����#107" }, next);
		getTag("����������Ѫ��");
		AddJob(s_jobTitle, "��˵������λ��Ů��ԩ�޹�\n#R���ƹ���#R\n����\n����\n#R��������#R" + s_needbattle);
		break;
	case 27:
		AddTriggerObj("��������", "���ƹ���", next);
		break;
	case 28:
		AddTriggerDialogList({ "վס,ʲô��?�������ҵ����Ҫ�Ƚ�������#90", "��˵û�и��򵥱����İ취ô?"}, next);
		break;
	case 29:
	{
		auto pc = g_pMainState->AddEnemy(e����, 35, eMP_�޵׶�);
		pc->HPMax.SetData(8000);
		pc->FillHpMp();
		g_pMainState->setNowSelect(pc->getObj());

		pc = g_pMainState->AddEnemy(e����, 35, eMP_������);
		pc->HPMax.SetData(8000);
		pc->FillHpMp();

		for (int i = 0; i < 6; ++i)
		{
			pc = g_pMainState->AddEnemy(e����, 35, eMP_���);
			pc->HPMax.SetData(8000);
			pc->FillHpMp();
		}

		g_pMainState->m_FightWorkList[10 + rand() % 8].m_pObj->say("���˶಻����#28");
		g_StateType = STATE_FIGHT;
		AddTriggerFightSuccess(next);
	}
	break;
	case 30:
		clearSay();
		g_pMainState->awardEquip(40);
		AddTriggerDialogList({ "����������#17", "���������?", "������,��Щ,��Щ,������Щ,�ǺǺ�"}, next);
		break;
	case 31:
		g_pMainState->awardk(0, 30);
		AddTriggerObj("���½�", "���ƹ���", next);
		AddJob(s_jobTitle, "�����ſ���#R���½�#R\n���ƹ���\n����\n����");
		break;
	case 32:
		g_pMainState->awardk(50);
		lostTag("����������Ѫ��");
		AddTriggerDialogList({ "������ҵ�������Ѫ��#52", "����Ī����", "��ʱ����¹��￼����״Ԫ��ǡ�ɸ�����ة����������������,������ǡ���Ź������ɴñ, �Ҷ����ɴ˳ɾ���һ����Ե" }, next);
		break;
	case 33:
		AddTriggerDialogList({ "������︰�ν���, ���˺齭�ɿڡ��������顢����ɫ����, ɱ�˹���ͼ���,����˳�ӡ���ʱ�齭�ϲ�����ӿ,����ˮ�徭��,�º󲻼����ʬ�ף���Ѱ˼�޼�,ֻ��˳������" }, next);
		break;
	case 34:
		AddTriggerDialogList({ "���鴩�˹����¹ڣ����˹�ƾ���飬ͬ������������ȥ�ˡ���������ְλ֮�㣬��ͨһЩ�ٸ����������£�����ԩ����û�л�Ӧ" }, next);
		break;
	case 35:
		AddTriggerDialogList({ "��ʱ�ҵ��Ļ��ŵĺ�����Σ�գ����º������º�˳ˮ���ߣ���������ʶ�ϣ���ҧ����ָ��д��Ѫ��һֽ������ĸ����������ԭ�ɣ���ϸ���ء��ֽ����������һ��Сָ���ÿ�ҧ�£���Ϊ����" }, next);
		break;
	case 36:
		AddTriggerDialogList({ "", "����ʬ��...���º�������...Сָ�ÿ�ҧ��...��Ϣ���ô�...\n\n#110" }, next);
		break;
	case 37:
		AddTriggerDialogList({ "�һ��ɷ����ʱ�Ǳ�ˮ������,��������ȥ��������ˮ������", "�У����Ҷ�ˮ~(�ղ�·�����񿴵��и�ˮ��#RϺ��#R, ȥ����)" }, next);
		break;
	case 38:
		AddTriggerDialogList({ "", "(�ղ�·�����񿴵��и�ˮ��#RϺ��#R, ȥ����)" }, next);
		break;
	case 39:
		AddTriggerDialogList({ "", "(�ղ�·�����񿴵��и�ˮ��#RϺ��#R, ȥ����)" }, next);
		break;
	case 40:
		g_pMainState->FindObjByName("Ϻ��")->say("������һ��Ǯһ��~��˦����", 0xFFFF);
		RemoveTriggerObj();
		g_pMainState->m_Job.ReMoveJob(this);
		break;


#if 0
	case 0:AddTriggerDialog2(0, 1); break;
	case 1://���ϼ�����
		Un����("����");
		Un����("����");
		Un����("�ϲ�");
		RemoveTriggerObj();
		UpdateJob2(1);
		AddTriggerObj2(2, 3, 2);
//		g_pMainState->LockLv(36);
		g_GlobalValues[4] = 1;
		break;
	case 2:AddTriggerDialog2(1, 3); break;
	case 3://�Ұ�¹
		AddTriggerObj2(5, 4, 4);
		UpdateJob2(6);
		break;
	case 4:
		AddTriggerDialog2(2, 5);
		break;
	case 5: //��¹ս��

	{
		//			m_AddPoint = g_addPointAtk;
		Add����Enemy2(3000, e��ɫ¹, 20, eMP_���ƹٸ�, 5);
		//			m_AddPoint = g_addPointSpd;
		Add����Enemy2(3000, e���꾫, 20, eMP_����ɽ, 65);
		//			m_AddPoint = g_addPointMag;
		for (int i = 0; i < 3; ++i)
		{
			AddPetEnemy2(2000, e����, 30);
		}
		SetMusic();
		g_StateType = STATE_FIGHT;
		AddTriggerFightSuccess(6);
	}
		return true;
	case 6://��¹����

	{
		SetJiangLi2(100000, 20000, 50000, 200000, true);
		AddTriggerDialog2(3, 7);
		// 			g_pCharacter->m_PCData.AddDefZZ(50);
		// 			g_pCharacter->m_PCData.AddGrowing(1);
		//			g_pMainState->LockLv(37);
	}
		return true;
	case 7:

	{
		UpdateJob2(1);
		AddTriggerObj2(2, 3, 8);
	}
		break;
	case 8:
		AddTriggerDialog2(4, -1);
		AddTriggerObj2(7, 8, 9);
		UpdateJob2(9);
		g_pCharacter->AddMoney(0, -500);
		g_GlobalValues[3] = 1;//ѧ������
		break;
	case 9:
		AddTriggerDialog2(5, -1);
		AddTriggerObj2(10, 11, 10);
		UpdateJob2(15);
		break;
	case 10:AddTriggerDialog2(6, 11);
		AddTriggerObj2(10, 11, 11);
		break;
	case 11://����1

	{
		//			m_AddPoint = g_addPointSpd;
		Add����Enemy2(3000, e��ʦ, 30, eMP_������, 10);
		//			m_AddPoint = g_addPointAtk;
		for (int i = 0; i < 4; i++)
		{
			AddPetEnemy2(2000, e��ͽ, 40);
		}
		SetMusic();
		g_StateType = STATE_FIGHT;
		AddTriggerFightSuccess(12);
	}
		break;
	case 12:

	{
		AddTriggerObj2(12, 13, 13);
		AddTriggerDialog2(7, -1);
		SetJiangLi2(150000, 20000, 50000, 200000);
		UpdateJob2(14);
		//			g_pCharacter->m_PCData.AddGrowing(1);
	}
		break;
	case 13:
		g_pMainState->m_Friend.AddFriend("���");
		AutoGetPet("���"/*, 0*/);
		AddTriggerDialog2(8, -13);
		AddTriggerObj2(16, 17, 14);
		UpdateJob2(19);
		break;
	case -13:

	{
		g_pMainState->m_Friend.Invite("���");
		RemoveTriggerObjMap();
	}
		break;
	case 14:AddTriggerDialog2(9, 15); break;//�콫
	case 15:

	{
		//			m_AddPoint = g_addPointSpd;
		Add����Enemy2(3000, e�콫, 35, eMP_�칬, 16);
		//			m_AddPoint = g_addPointAtk;
		for (int i = 0; i < 4; i++)
		{
			AddPetEnemy2(2000, e���, 45);
		}
		SetMusic("�ѩǧҹ");
		g_StateType = STATE_FIGHT;
		AddTriggerFightSuccess(16);

	}
		break;
	case 16:
		AddTriggerObj2(20, 8, 17);
		AddTriggerDialog2(10, -1);
		SetJiangLi2(180000, 20000, 50000, 120000);
		UpdateJob2(18);
		// 		g_pCharacter->m_PCData.AddDefZZ(50);
		// 		g_pCharacter->m_PCData.AddGrowing(1);
		//		g_pMainState->LockLv(39);
		break;
	case 17:
		AddTriggerDialog2(11, 19);
		break;
	case 19://������

	{
		//			m_AddPoint = g_addPointSpd;
		Add����Enemy2(3000, e��������, 39, eMP_���ܵظ�, 20);
		//			m_AddPoint = g_addPointMag;
		for (int i = 0; i < 4; i++)
		{
			AddPetEnemy2(2000, eС��Ů, 40);
		}
		SetMusic();

		g_StateType = STATE_FIGHT;
		AddTriggerFightSuccess(20);

	}
		break;
	case 20:
		RemoveTriggerObj();
		AddTriggerGive(m_Textlist[12], 22, 44, 21);
		AddTriggerDialog2(12, -1);
		SetJiangLi2(200000, 50000, 50000, 100000);
		UpdateJob2(38);
		// 		g_pCharacter->m_PCData.AddHpZZ(100);
		// 		g_pCharacter->m_PCData.AddGrowing(1);
		g_pMainState->LockLv(35);
		break;
	case 21:
		AddTriggerDialog2(13, -21);
		UpdateJob2(21);
		AddTriggerObj2(22, 11, 22);
		g_pMainState->m_Friend.AddFriend(m_Textlist[64]);
		break;
	case -21:g_pMainState->m_Friend.Invite(m_Textlist[64]);
		break;
	case 22:AddTriggerDialog2(14, 23);
		break;
	case 23://����2

	{
		//			m_AddPoint = g_addPointSpd;
		Add����Enemy2(5000, e��ʦ, 40, eMP_������, 10);
		ePetID petid;
		for (int i = 0; i < 5; i++)
		{
			//				m_AddPoint = g_addPointAtk;
			switch (rand() % 3)
			{
			case 0:petid = e��ͽ;
				break;
			case 1:
				petid = eǿ��;
				//					m_AddPoint = g_addPointMag;
				break;
			default:petid = eɽ��;
				break;
			}
			AddPetEnemy2(3000, petid, 49);
		}
		SetMusic();
		g_StateType = STATE_FIGHT;
		AddTriggerFightSuccess(24);
	}
		break;
	case 24:
		TalkList(15, 23, 24, 39, 125);
		SetJiangLi2(240000, 20000, 50000, 250000);
		// 		g_pCharacter->m_PCData.AddAtkZZ(50);
		// 		g_pCharacter->m_PCData.AddHpZZ(100);
		// 		g_pCharacter->m_PCData.AddGrowing(1);
		//		g_pMainState->LockLv(42);
		break;
	case 125://������Ů

	{
		TalkList(49, 75, 76, 77, 126);
		sTaskMapObj obj;
		obj.m_Npc.Set(m_Textlist[75], m_Textlist[76], e��������è, 84, 59);
		obj.m_Stage = 126;
		obj.m_pTask = this;
		AddTriggerObjMap(&obj);
	}
		break;
	case 126:

	{
		//			m_AddPoint = g_addPointAtk;
		Add����Enemy2(8000, e��������è, 35, eMP_ʨ����);
		ePetID petid;
		for (int i = 0; i < 4; i++)
		{
			switch (rand() % 3)
			{
			case 0:petid = e����;
				break;
			case 1:petid = e����;
				break;
			default:petid = e���ܾ�;
				break;
			}
			AddPetEnemy2(3000, petid, 40);
		}
		SetMusic();
		g_StateType = STATE_FIGHT;
		AddTriggerFightSuccess(127);
	}
		break;
	case 127:

	{
		SetJiangLi2(200000, 20000, 50000, 200000);
		AddTriggerObj2(23, 24, 25);
		UpdateJob2(39);

		RemoveTriggerObjMap();
		RemoveNpc(81, true);
		//		g_pMainState->LockLv(55);
		g_GlobalValues[14] += 200;
		g_GlobalValues[15] += 200;
		// 		g_pCharacter->m_PCData.AddAtkZZ(50);
		// 		g_pCharacter->m_PCData.AddGrowing(1);
		AddChannel2(82);
		AddChannel2(83);
		sShangPinPet sppet;
		sppet.Set(e��������è, 0, 100, true);
		GetPet(m_Textlist[64], &sppet, 100);
	}
		break;
	case 25://������Ů
		AddFriend(84);
		AutoGetPet(m_Textlist[84]/*, 0*/);
		AddTriggerDialog2(16, -1);
		AddTriggerObj2(25, 26, 26);
		UpdateJob2(27);
		break;
	case 26://����
		AddTriggerDialog2(17, -1);
		AddTriggerObj2(28, 29, 27);
		UpdateJob2(30);
		break;
	case 27://��ڤ��
		AddTriggerDialog2(18, 28);
		break;
	case 28:

	{
		//			m_AddPoint = g_addPointSpd;
		Add����Enemy2(5000, eѲ������, 40, eMP_���ܵظ�, 28);
		for (int i = 0; i < 4; i++)
		{
			ePetID petid;
			switch (rand() % 4)
			{
			case 0:petid = e���ù�;
				break;
			case 1:petid = e����;
				break;
			case 2:petid = e��ʬ;
				break;
			default:petid = eţͷ;
				break;
			}
			Add����Enemy2(3000, petid, 30);
		}
		SetMusic();

		g_StateType = STATE_FIGHT;
		AddTriggerFightSuccess(29);
	}
		break;
	case 29:
		TalkList(19, 31, 32, 33, 30);

		SetJiangLi2(300000, 50000, 50000, 250000);

		// 		g_pCharacter->m_PCData.AddDefZZ(50);
		// 		g_pCharacter->m_PCData.AddGrowing(1);
		//		g_pMainState->LockLv(45);
		break;
	case 30://����
		AddTriggerObj2(28, 29, 31);
		AddTriggerDialog2(20, -30);
		break;
	case -30:
		SetJiangLiItem(5, 18);
		UpdateJob2(30);
		break;
	case 31://��ڤ��
		AddTriggerObj2(25, 26, 32);
		AddTriggerDialog2(21, -1);
		UpdateJob2(27);
		break;
	case 32://����
		AddTriggerObj2(22, 11, 33);
		AddTriggerDialog2(22, -1);
		UpdateJob2(40);
		break;
	case 33://����
		AddTriggerObj2(34, 8, 34);
		AddTriggerDialog2(23, -1);
		UpdateJob2(35);
		break;
	case 34://����
		AddTriggerDialog2(24, 35); break;
	case 35:
	{
		//		m_AddPoint = g_addPointAtk;
		for (int i = 0; i < 5; i++)
		{
			auto p = Add����Enemy2(5000, e����, 35, eMP_���ƹٸ�, 34);
			p->AddSkill(ePS_�߼���Ѫ);

		}
		SetMusic();
		g_StateType = STATE_FIGHT;
		AddTriggerFightSuccess(36);
	}
		break;
	case 36:
		AddTriggerObj2(36, 8, 37);
		AddTriggerDialog2(25, -1);
		SetJiangLi2(300000, 20000, 50000, 270000);
		UpdateJob2(37);
		// 		g_pCharacter->m_PCData.AddHpZZ(100);
		// 		g_pCharacter->m_PCData.AddGrowing(1);
		g_pMainState->LockLv(45);
		break;
	case 37://���½�
		AddTriggerObj2(41, 8, 38);
		AddTriggerDialog2(26, -1);
		UpdateJob2(42);
		break;
	case 38:AddTriggerDialog2(27, 39);
		break;
	case 39://Ϻ��ս��

	{
		cPropertyData* pPet;
		//			m_AddPoint = g_addPointMag;
		pPet = Add����Enemy2(8000, eϺ��, 40, eMP_��������, 41);
		pPet->MagicWater.d2 += 30;
		for (int i = 0; i < 4; i++)
		{
			ePetID petid;
			switch (rand() % 4)
			{
			case 0:petid = e����;
				break;
			case 1:petid = e����;
				break;
			case 2:petid = e�󺣹�;
				break;
			default:petid = e��ë��;
				break;
			}
			pPet = Add����Enemy2(5000, petid, 40);
			pPet->MagicWater.d2 += 20;
		}
		g_pMainState->m_Mp3.Load("ս��BOSS");
		g_StateType = STATE_FIGHT;
		AddTriggerFightSuccess(40);
		AddTriggerDialog2(51);
	}
		break;
	case 40:
		AddTriggerObj2(44, 45, 41);
		SetJiangLi2(300000, 100000, 50000, 300000);
		UpdateJob2(43);
		// 		g_pCharacter->m_PCData.AddMagZZ(100);
		// 		g_pCharacter->m_PCData.AddGrowing(1);
		//		g_pMainState->LockLv(47);
		break;
		//з��ս��
	case 41:AddTriggerDialog2(28, 42);
		break;
	case 42:

	{
		cPropertyData* pPet;
		pPet = Add����Enemy2(8000, eз��, 49, eMP_��������, 44);
		pPet->MagicWater.d2 += 50;
		for (int i = 0; i < 4; i++)
		{
			ePetID petid;
			switch (rand() % 4)
			{
			case 0:petid = e����;
				break;
			case 1:petid = e����;
				break;
			case 2:petid = eϺ��;
				break;
			default:petid = e��ë��;
				break;
			}
			Add����Enemy2(5000, petid, 49, eMP_���);
			pPet->MagicWater.d2 += 30;
		}
		SetMusic();
		g_StateType = STATE_FIGHT;
		AddTriggerFightSuccess(43);
	}
		break;
	case 43:
		TalkList(29, 46, 45, 47, 44);
		SetJiangLi2(300000, 100000, 50000, 320000);
		// 		g_pCharacter->m_PCData.AddMagZZ(100);
		// 		g_pCharacter->m_PCData.AddGrowing(1);
		//		g_pMainState->LockLv(48);
		break;
	case 44://��ǧ��
		TalkList(30, 36, 8, 37, 45);
		break;
	case 45://���½�
		TalkList(31, 49, 50, 48, 46);
		break;
	case 46://��ة��
		TalkList(32, 52, 53, 51, 47);
		AddTriggerGive(m_Textlist[49], 22, 30, 49);
		break;
	case 47://��������
		AddTriggerDialog2(33, 48); break;
	case 48:
		RemoveTriggerObj();
		SetJiangLiItem(30, 22);
		g_pCharacter->m_PcData.m_Money[0] -= 50000;
		break;
	case 49://��ة��

	{
		AddTriggerDialog2(34, -1);
		UpdateJob2(56);
		sNpc npc;
		npc.Set(m_Textlist[66], m_Textlist[8], 2012, 226, 190, 3);
		AddTriggerObjMap(&npc, 152);
		npc.Set(m_Textlist[67], m_Textlist[8], eɽ��, 230, 186, 7);
		AddTriggerObjMap(&npc, 152, 0);
		npc.Set(m_Textlist[67], m_Textlist[8], eɽ��, 233, 194, 1);
		AddTriggerObjMap(&npc, 152, 0);
		AddTriggerObjMap(m_Textlist[8], 151, 0);
	}
		break;
	case 151:
		AddTriggerDialog2(44, -1);
		RemoveTriggerObjMap(151);
		UpdateJob2(68);
		break;
	case 152://ɽ��ս��
		AddTriggerDialog2(45, 153);
		break;
	case 153:
	{
		cPropertyData *pet = Add����Enemy2(50000, e��ҧ��, 50, eMP_���ƹٸ�, -1, true);
		if (!pet)
		{
			g_pMainState->SetFightPet(g_pMainState->m_HeroID, -1);
			pet = Add����Enemy2(50000, e��ҧ��, 50, eMP_���ƹٸ�, -1, true);
		}
		g_pMainState->m_pFightState->m_FightMenu.SetControl(pet->m_IDinFightWorkList, false);
		for (int i = 0; i < 10; i++)
		{
			ePetID petid;
			switch (rand() % 4)
			{
			case 0:petid = eɽ��;
				break;
			default:petid = eǿ��;
				break;
			}
			Add����Enemy2(5000, petid, 30);
		}
		SetMusic();

		g_StateType = STATE_FIGHT;
		AddTriggerFightSuccess(154);
	}
		break;
	case 154:
		RemoveNpc(67);
		RemoveNpc(67, 1);
		RemoveTriggerObjMap(-1);
		TalkList(46, 54, 55, 56, 50, 155);
		SetJiangLi2(300000, 100000, 50000, 340000);
		//		g_pCharacter->m_PCData.AddGrowing(5);
		//		g_pMainState->LockLv(49);
		break;
	case 155:
		RemoveNpc(66, 1);
		break;
	case 50://����1
		AddTriggerDialog2(35, 51);
		break;
	case 51:
	{
		cPropertyData *pet = Add����Enemy2(50000, e��ҧ��, 50, eMP_���ƹٸ�, -1, true);
		if (!pet)
		{
			g_pMainState->SetFightPet(g_pMainState->m_HeroID, -1);
			pet = Add����Enemy2(50000, e��ҧ��, 50, eMP_���ƹٸ�, -1, true);
		}
		g_pMainState->m_pFightState->m_FightMenu.SetControl(pet->m_IDinFightWorkList, false);
		auto p = Add����Enemy2(8000, e����, 50, eMP_���ƹٸ�, 54);
		p->AddSkill(ePS_��Ѫ);
		for (int i = 0; i < 7; i++)
		{
			// 			ePetID petid;
			// 			switch (rand() % 4)
			// 			{
			// 			case 0:petid = eɽ��;
			// 				break;
			// 			case 1:petid = e����;
			// 				break;
			// 			case 2:petid = e��ͽ;
			// 				break;
			// 			default:petid = eǿ��;
			// 				break;
			// 			}
			Add����Enemy2(5000, e����, 49);
		}
		SetMusic();

		g_StateType = STATE_FIGHT;
		AddTriggerFightSuccess(52);
	}
		break;
	case 52:
	{
		g_pMainState->SetDialogList(m_Textlist[69], g_pMainState->m_PetDataManager.GetPetData(e��ҧ��)->m_dialoghead[0]);
		TalkList(36, 54, 57, 58, 53);

		SetJiangLi2(400000, 100000, 50000, 350000);
		// 			g_pCharacter->m_PCData.AddAtkZZ(50);
		// 			g_pCharacter->m_PCData.AddGrowing(1);
		g_pMainState->LockLv(55);
	}
		break;
	case 53://����2
		AddTriggerDialog2(37, 54);
		break;
	case 54:
	{
		cPropertyData *pet = Add����Enemy2(50000, e��ҧ��, 50, eMP_���ƹٸ�, -1, true);
		if (!pet)
		{
			g_pMainState->SetFightPet(g_pMainState->m_HeroID, -1);
			pet = Add����Enemy2(50000, e��ҧ��, 50, eMP_���ƹٸ�, -1, true);
		}
		g_pMainState->m_pFightState->m_FightMenu.SetControl(pet->m_IDinFightWorkList, false);
		cPropertyData* pPet;
		pPet = Add����Enemy2(12000, e����, 59, eMP_���ƹٸ�, 54);
//		pPet->m_AtkDownHPHurt.d1 += 5;
		pPet = Add����Enemy2(8000, eǿ��, 59, eMP_���ܵظ�, 59);
		pPet->AddSkill(ePS_�����);
		for (int i = 0; i < 5; i++)
		{
			ePetID petid;
			switch (rand() % 4)
			{
			case 0:petid = e���ù�;
				break;
			case 1:petid = e����;
				break;
			case 2:petid = e��ʬ;
				break;
			default:petid = eţͷ;
				break;
			}
			Add����Enemy2(5000, petid, 49);//(eMengPai)(rand() % 12));
		}
		SetMusic("OneLight");

		g_StateType = STATE_FIGHT;
		AddTriggerFightSuccess(55);
	}
		break;
	case 55:
	{
		//			g_pMainState->LockLv(65);
		AddTriggerDialog2(38, -57);
		cPropertyData *pet = Add����Enemy2(50000, e��ҧ��, 50, eMP_���ƹٸ�, -1, true);
		if (!pet)
		{
			g_pMainState->SetFightPet(g_pMainState->m_HeroID, -1);
			pet = Add����Enemy2(50000, e��ҧ��, 50, eMP_���ƹٸ�, -1, true);
		}
		g_pMainState->m_pFightState->m_FightMenu.SetControl(pet->m_IDinFightWorkList, false);
		cPropertyData* pPet = Add����Enemy2(20000, e��ɽ����, 59, eMP_���ܵظ�, 59);
		pPet->AddSkill(ePS_�����);
		pPet->SuckBloodPercent.d1 += 30;
		pPet->SetJinJie(2);
		for (int i = 0; i < 9; i++)
		{
			ePetID petid;
			switch (rand() % 4)
			{
			case 0:petid = e��ɽ����;
				break;
			case 1:petid = e����;
				break;
			case 2:petid = e��ʬ;
				break;
			default:petid = eţͷ;
				break;
			}
			Add����Enemy2(5000, petid, 49);
		}
		SetMusic("�׉�Ⱦ");
		g_StateType = STATE_FIGHT;
		AddTriggerFightSuccess(57);

	}
		break;
	case -57:
		AddTriggerDialog2(47);
		break;
	case 57:
		AddTriggerDialog2(39, -1);
		AddTriggerObj2(61, 8, 58);
		SetJiangLi2(500000, 100000, 50000, 400000);
		UpdateJob2(62);
		// 		g_pCharacter->m_PCData.AddDefZZ(100);
		// 		g_pCharacter->m_PCData.AddHpZZ(300);
		// 		g_pCharacter->m_PCData.AddGrowing(1);
		//		g_pMainState->LockLv(56);
		break;
	case 58://��ĸ
		AddTriggerDialog2(40, 59);
		g_pMainState->m_DialogList.clear();
		break;
	case 59:
		AddTriggerObj2(36, 8, 60);
		UpdateJob2(37);
		break;
	case 60://���½�
		AddTriggerDialog2(41, -1);
		AddTriggerObj2(22, 11, 61);
		UpdateJob2(63);
		break;
	case 61://����
		TalkList(42, -1, -1, -1, -1, 62);
		break;
	case 62:
		SetJiangLiItem(6, 40);
		AddTriggerDialog2(48);
		Process2(0);
		break;
#endif
	default:
		ERRBOX;
		break;

	}
	return true;
}

