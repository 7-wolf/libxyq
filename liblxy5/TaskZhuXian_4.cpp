#include "_global.h"


bool TaskZhuXian::Process4(int stage)
{
	int r = rand() % 10;
 	int next = stage + 1;
	setJobTitle("Ѱ��������");
	int i = 10;
	switch (stage)
	{
	case 0:
		AddTriggerDialog("#G����#G#103��#G���������յ�����´���㵽����Ҫ�����������ܷ�#G��#B�������ÿ����˯��ϱ����������ӣ����ɽ�������в���£����գ��ֵ�Ű��֮�գ�������#B#18"
			, "ס�֣�˯��ϱ������������������Ҳ�ɵĳ���#4����TM��������#118���ô�", "�ֵ��л���˵��˵���������������յ���ѱ���ز�����#R��ʱ��#R�����������Ķ��飬��Ȱ���ٹ�����#2", "�ҽ����Ҫ�ܹ���#53",
		"���Ʋ��ԣ��Է��ƣ�С���Ǹ����ϡ�");
			
			break;
	case 1:
	{		
		auto p = AddEnemy(35000, e���, 50, eMP_����, "����ɽ�");
		p->SetJinJie(2);
		g_pMainState->SetRanse(i, 1);//���ٻ��޼���ɫ����

		for (int i = 0; i < 4; ++i)
		{
			AddEnemy(20000, e���, 45, eMP_���, "������Ա");
		}

		for (int i = 0; i < 5; ++i)
		{
			AddEnemy(10000, e����, 45, eMP_���, "��ʱ��");
			
		}
		
		g_pMainState->m_FightWorkList[15 + rand() % 5].m_pObj->say("#G��Ϊһ����ʱ������������ʵ�Ǿܾ���#G#17");

		if (g_pMainState->m_InterfaceTeam.getLeaveBegin() == 5)
		{
			g_pMainState->SetFightPet(g_pMainState->m_HeroID, -1);
		}
		auto pc = AddEnemy(0, eɳ����, 60, eMP_ʨ����, "������", nullptr, -1, -1, true);
		if (pc)
		{
			pc->PointRemain = cct::PointRemian;
			pc->setPointAfterLv(g_pMainState->getAddpointFromMp(eMP_ʨ����, true), true);
			pc->autoEquip(false);
			pc->autoData(false, true, true);
			pc->apply();
			pc->m_Controler.Set(0);
			g_pMainState->m_pFightState->m_FightMenu.SetControl(pc->m_IDinFightWorkList, false);

			g_pMainState->setNowSelect(pc->getObj());
		}
		g_pMainState->FindObjByName("����ɽ�")->say("#R����߷��ˣ��������������еĸ�ͷͬ��ͬ��#965#R", 0xFFFF);
		g_pMainState->FindObjByName("������")->say("#R�Һ���֮�������Ҫ�����⿴�Ź���һ�ٲ���#4#R", 0xFFFF);
		AddJob("#R������ʾ#R��\n#B���ƾ���#B\n#R������#R\n#B������ #B\n#R�������#R\n���¾����󽫵���� ");
		readyFightAndSucces();
	}
		break;
	case 2:
		g_pMainState->awardEquip(50);
		g_pMainState->awardk(120, 100);//
		AddTriggerObj("������");
		break;
	case 3:	 
		AddTriggerDialog("�������,���ճ��ɴ����,����Ϊ��....#52",
			"����л!���˵���,˵��ô��ϻ�����޷�����Ҫ�Ұ����һ�������������Ƭ#24",
			"����������㣬�ҵ��뷨�������֪����",
			"û�취��˭���ܾ����Ǯ�ָ����飬�������벻���ľ�ϲ�أ�");
			AddJob("#R������ʾ#R��#BŮ����#B\n#R������#R#B������ #B\n#R�������#R\n��Ӧ��֪��������Ƭ������");
	case 4:
		g_pMainState->FindObjByName("����ɽ�")->say("���꣬�������������Ÿ��ٽŴ���������", 0xFFFF);
		g_pMainState->FindObjByName("������")->say("#Gǰ������������,�������û�취��ȥ���#2#G");
		 AddTriggerObj("������", "Ů����");
		break;
	case 5:
		g_pMainState->setNowSelect();
		AddTriggerDialog("Ů������������Ů��ʧ����,��˵�Ǳ���˿��Ů��ץ����#15,�����ܲ��ܰ�æ����#52",
		"���ԣ�û���⣬��˵�³�֮������ܶ���#2",
		"��Ȼ������İ�������ǰ����г����з��Ӵ���ϰ���","#24");
		AddJob("#R������ʾ#R��\n#G��˿��#G\n�������꣺\n#BŮ��#B \n#R�������#R\nȥ�����ǲ���Ů��׽����С��");
		break;
	case 6:
		AddTriggerObj("Ů��","��˿��");
		break;
	case 7:
		AddTriggerDialog("Ӵ�����þò���Ŷ������LOL�������ң��ҹ�����6","��˵������˷����˿ڵĹ�����","������ô����ô��ȥ������Υ��������","������#71��Ů��ʲô����������");
		break;
	case 8:
	{
		auto pc = AddEnemy(30000, eܽ������, 60, eMP_��˿��, "Ů��");
		pc->getObj()->say("#G��Ȼ˵�����ģ������㵥��һ����#G#99");
		for (int i = 0; i < 4; ++i)
		{
			AddEnemy(20000, e���ӹ�, 45, eMP_���);
		}
		g_pMainState->m_FightWorkList[15 + rand() % 5].m_pObj->say("#G��������˳�����ȥ�����������С��##G#47");
		g_pHeroObj->say("��ƾ���µ�����������������#24");
		g_StateType = STATE_FIGHT;
		readyFightAndSucces();
	}
		break;
	case 9:
		g_pMainState->awardEquip(60);
		g_pMainState->awardk(130, 120);//
		getTag("��������Ƭ");
		g_pMainState->FindObjByName("Ů��")->say("#65˵�˲����ң���Ȼ�����ң������С��˵���ͷ�");
		AddJob("#R������ʾ#R��\n#G��˿��#G\n�������꣺\n#B������ ��ͤ���� #B \n������ܣ�\nӦ���������������ɵ�");
		RemoveTriggerObj();
		AddTriggerObj("������");
		break;

	case 10:
		AddTriggerDialog("û��,С��ȷʵ����°�ߵ�.����Ϊ��,����.�д���?��ʹ����С��һ��,�������ɱ��,�������ƻ�ʳ����,����",
			"#24���һ�û�����أ������Ƕ����ȸ�״ô��",
			"�Ҳ��ܣ��Ҿ�Ҫ");
		break;
	case 11:
	{
		auto pc = AddEnemy(20000, e��������, 65, eMP_��˿��, "������");
		pc->getObj()->say("#G���Ҿ����񹦰�����#G#17"); 
		AddEnemy(18000, e��������, 60, eMP_���);
		AddEnemy(18000, e��������, 60, eMP_���);
		AddEnemy(18000, eܽ������, 60, eMP_���);
		AddEnemy(18000, eܽ������, 60, eMP_���);
		AddEnemy(18000, eܽ������, 60, eMP_���);
		AddEnemy(18000, eܽ������, 60, eMP_���);
		AddEnemy(18000, eܽ������, 60, eMP_���);
		g_pMainState->m_FightWorkList[10 + rand() % 5].m_pObj->say("#G�ϴ��Ǿ����澭#G#17");
		g_pMainState->m_FightWorkList[10 + rand() % 5].m_pObj->say("#118");
		readyFightAndSucces();
	}
		break;
	
	case 12:
		getTag("����������Ƭ");
		g_pMainState->m_Map.RemoveNpc("������", true);
		g_pMainState->awardEquip(60);
		g_pMainState->awardItem(27, 42 + rand() % 9, 1, true);//����
		g_pMainState->awardk(130, 120);//
		g_pMainState->FindObjByName("������")->say("#G#1лл�㣬������#G");
		AddJob("#R������ʾ#R��#BŮ����#B\n#R������#R#B������ #B\n#R�������#R\n��Ӧ��֪������������Ƭ������");
		AddTriggerObj("������", "Ů����");
		break;
	case 13:
		AddTriggerDialog("��л������������Ů����Ĵ�����������Ҫ���ܶ���ô�����ʳ��ӡ����ӡ����׼������ô���ˣ��Ҵ���绨����˵�������Ѿ���Ľ�Ѿá���",
			"#17���⡣�������⡣���������������������ԾͲ���������ˡ�����#95#G��ʵ���Ǹ�����Ǯ#G����",
			"Ŷ��ԭ�����������ðɣ�ǰ��ʱ�䣬�и���Ů��Ϊ���շ������˵ķ����,ȥ����«����,�����ڻ�û����,ϣ�������ܰ�æ����.",
			"#RӢ�۾���#100#R�����£�������������ˣ����Һ���Ϣ�ɣ�");
		break;
	case 14:
		AddTriggerObj("������", "����«��");
		AddJob("#R������ʾ#R��#B����«��#B\n#R������#R#B������ #B\n#R�������#R\nȥ����«��Ӣ�۾���");
		break;
	case 15:
		g_pMainState->FindObjByName("������")->say("#G�ҵİ������ӣ���������#37#2#G");
		AddTriggerDialog("�ұ�����ֱ�İ�������ƭ��ƭɫ#97���Ҵ򲻹����������ˣ�˭���ҽ�ѵ��ѵ����",
			"��Ů����û�°ɣ�Ҫ��Ҫ�ҷ��㵽������Ϣһ����˫��֮��Ϊ������#80","#90���ɫ��#90���ȱ����,����־�Ҫ����,���Ʒ�����ְɣ����Ǹ���#R���ɡ��޳ܡ�����������#R�ļһ",
			"#117���������ھ�ȥȡ��������Ϊ��������ڶ�����");	
		break;
	case 16:
	
		AddJob("#R������ʾ#R��#B����«��#B\n#R������#R#B����� #B\n#R�������#R\nȥ��ѵƭ��ƭɫ�ķ����");
		AddTriggerObj("�����", "����«��", _next + 1);
		break;
	case 17:
		break;
	case 18:	
		AddTriggerDialog("վס�������������������#4��һ����֪������ʲô����#113�������������������鷳�İɣ�",
			"#24���ڵľ���ֶ���Ԥ֪������#117",
			"������Ȼ���ø�����ᳱ�������Ǿ����Ҳ��Ҫ�������#114", "#111����Ҫ�Թ�Ͷ����!�������ҽ̽�����ô����",
			"��ʲô���ӣ��������", "#17�ðɣ��ҿ�ʼ������");
		break;
	case 19:
	{
		auto pc = AddEnemy(40000, e����ս��, 65, eMP_���, "�����");
		pc->getObj()->say("#G�ҷ�����ݺὭ����ʮ�꣬��û�¹�˭#G#17");
		AddEnemy(18000, e��ɽ����, 60, eMP_���);
		AddEnemy(18000, e��ɽ����, 60, eMP_���);
		AddEnemy(18000, e��ɽ����, 60, eMP_���);
		AddEnemy(18000, e��ɽ����, 60, eMP_���);
		g_pMainState->SetRanse(i, 1);//���ٻ��޼���ɫ����
		g_pMainState->m_FightWorkList[10 + rand() % 5].m_pObj->say("#G������������#18#");
		g_pMainState->m_FightWorkList[10 + rand() % 5].m_pObj->say("#18");
		readyFightAndSucces();
	}
		break;
	case 20:
		AddTriggerDialog("�ɶ񣬾�Ȼ����������....�Ҳ�Ҫ�������Ҳ�Ҫ��������",
			"�����Ͷ�����ˣ���Ҫ��������SOLO",
			"�Ҳ���������һ��",
			"����û�ո����棬���ҽ���ʮ����");
		g_pMainState->awardEquip(50);
		g_pMainState->awardk(210, 200);//60W���飬100WǮ
		AddTriggerObj("�����");
		g_pMainState->FindObjByName("�����")->say("��...����...��ɱ��...#R����������#R...��~");
		AddJob("#R������ʾ#R��#B����«��#B\n#R������#R#B������ #B\n#R�������#R\nȥ����������������");
		break;
	case 21:
		AddTriggerObj("������");
		break;
	case 22:
		AddTriggerDialog("��������,����ֻ�ܿ���������������������",
			"#36�������ûɶ�󰭣�������ƭ��ƭ��",
			"#28��Ȼ���㷢���ˣ������ø�����Ȼ������õ�������Ƭ",
			"������#43������Ҫ����",
			"#51������Ч");
		AddJob("#R������ʾ#R��#B����«��#B\n#R������#R#B������ #B\n#R�������#R\n�����������������������ƣ����񽭺�������������");
		break;
	case 23:
		AddTriggerGive("������", 22, 52, _next);
		break;
	case 24:
		g_pMainState->awardk(0, 50);
		g_pMainState->m_pNowSelect = g_pMainState->FindObjByName("������");
	    AddTriggerDialog("лл�㣬�Һö���","#68�������·��","лл��,��������Ը����,��֪������������Ϊ��ʲô,�Ҹ�����.","�ҵ�����Ƭ��,�Ƚ��������󽫰ɣ�");
	    break;
	case 25:
		getTag("����������Ƭ");
		g_pMainState->m_Map.RemoveNpc("������", true);
		AddJob("#R������ʾ#R��\n#B���ƾ���#B\n#R������\n#B#������ #B\n#R�������#R\n��2Ƭ����յ��Ƭ������������");
		AddTriggerObj("������", "���ƾ���", _next + 1);
		break;
	case 26:
	
		break;
	case 27:
		AddTriggerDialog("������̫�������,�����ٶ��治��һ��Ŀ죬����һƬ�Ҿ��ܻ���ͥ��#1",
			"#3�����ǵ�Ȼ�����ڰ���û���ٶȣ�����ô��������������档",
			"#28ʣ�µ�һƬ�Ͱ�������",
			"���İɣ������¾������ƣ�");
		AddJob("#R������ʾ#R��#B���ƾ���#B\n#R������#R#B���� #B\n#R�������#R\nС�������һƬ������Ƭ");
		break;
	case 28:
		AddTriggerObj("����", "���ƾ���");
		break;
	case 29:
		AddTriggerDialog("��֪��������Ŀ��,���ܰ��Ұ�����͸���������",
			"#3����Ȼ���ԣ��㵽��ϲ��������#3",
			"ϲ��һ����,����Ҫ����#17",
			"�������ҵĵ���ʵ�ڣ�");
		g_pMainState->FindObjByName("����")->say("��������Ϊ���ֱ������������#8~");
		break;
	case 30:
		g_pMainState->awardk(0, 50);
		AddJob("#R������ʾ#R��#B���ƾ���#B\n#R������#R#B������ #B\n#R�������#R\n��С�ϵ����齻��������");
		getTag("���ϵ�����");
		AddTriggerObj("������", "���ƾ���");
		break;
	case 31:
		AddTriggerDialog("#24�ҵ��ˣ�",
			"���ǰ��ϸ����,����������Ӧ�ö��İ�#3",
			"�������ڵ�����,���ǻ��ǲ�Ҫ����Ϊ��#74",
			"����㵥��");
		g_pMainState->FindObjByName("������")->say("��������Ϊ����#108~");
		AddJob("#R������ʾ#R��#B���ƾ���#B\n#R������#R#B���� #B\n#R�������#R\n����С�Ͼ�������������,�������ȴ���Ҧ̫ξ");
		break;
	case 32:
		AddTriggerObj("Ҧ̫ξ");
		break;
	case 33:
		AddTriggerDialog("#28����С��,���ǼҶ�����#37������ӭ��.",
			"ס��,����ǿ����Ů,�ҵúúý�ѵ��ѵ��#44#3",
			"�����ĵ�������Ȼ���ҵĵ�#4��������#74",
			"��������������Ǵ��еط�ʩչ��#18��");
		break;
	case 34:
	{
		auto pc = AddEnemy(40000, e���, 65, eMP_�칬, "Ҧ̫ξ");
		pc->getObj()->say("#Gרҵ���׼�ʮ�꣬ͷһ��������������#G#17");
		pc->SetJinJie(2);
		AddEnemy(28000, e���, 60, eMP_���);
		AddEnemy(28000, e���, 60, eMP_���);
		AddEnemy(28000, e���, 60, eMP_���);
		AddEnemy(28000, e���, 60, eMP_���);
		g_pMainState->SetRanse(i, 1);//���ٻ��޼���ɫ����
		g_pMainState->m_FightWorkList[10 + rand() % 5].m_pObj->say("#Gרҵ��Ů��#18#");
		g_pMainState->m_FightWorkList[10 + rand() % 5].m_pObj->say("#18");
		readyFightAndSucces();
	}
		break;
	case 35:
		g_pMainState->FindObjByName("Ҧ̫ξ")->say("�����˶����������ӭ�ף��ԹԸ����߰�#108~");
		g_pMainState->FindObjByName("����")->say("�Ҳ�Ҫ���Ҳ�Ҫ���Ҳ�Ҫ�޸����۹֣��Ҳ�Ҫ�Թ���#15~");
		AddJob("#R������ʾ#R��#B���ƾ���#B\n#R������#R#BҦ̫ξ #B\n#R�������#R\nҦ̫ξ�����л�Ҫ˵");
		AddTriggerObj("Ҧ̫ξ", "���ƾ���", _next + 1);
		break;
	//case 36:

	//{
	//	int lnum = g_pMainState->GetLiveNum(10, 20);
	//	if (lnum == 1)
	//	{
	//		g_pMainState->m_pFightState->SuccessFight();
	//		break;
	//	}
	//	if (lnum != 2)
	//	{
	//		break;
	//	}

	//	cPcData* lb = g_pMainState->m_FightWorkList[11].m_pObj->getPcData();
	//	cPcData* lh = g_pMainState->m_FightWorkList[10].m_pObj->getPcData();
	//	lh->DmgAdd.d2 -= 1000000;
	//	lb->Hit.AddDataAdd(1000000);

	//	auto& list = g_pMainState->m_FightWorkList[11];
	//	list.m_pObj->ReMoveState(eBuffType��ӡ);
	//	auto& ski = list.m_SkillSelect;

	//	list.m_WorkType = WORKTYPE_ATTACK;
	//	list.targetID = ski.TargetID = 10;
	//	ski.SkillID = 1000;

	//	lb->getObj()->say("��,û�õķ���!");
	//	lh->getObj()->say("���Ŵ��ˣ��Ҵ���!");
	//}
	//	break;
	case 37:
		AddTriggerObj("Ҧ̫ξ");
		break;
	case 38:
		AddTriggerDialog("�һ�������ģ�.");
		break;
	case 39:
		g_pMainState->FindObjByName("Ҧ̫ξ")->say("ʮ���������һ���ú�~");	
		g_pMainState->awardEquip(60);
		if (r >6)//���������
		{

			if (r >= 0 && r <1)//10%
			{
				g_pMainState->awardBook(100 + (rand() % 4 * 10));//��
				

			}
			else if (r >= 1 && r<2)//10%
			{
				g_pMainState->awardIron(100 + (rand() % 4 * 10));//��
				

			}
			else if (r >= 2 && r<4)
			{
				g_pMainState->awardItem(23, rand() % 9, 1, true);
				g_pMainState->awardItem(27, 38 + rand() % 3, 1, true);//ǿ��ʯ
			}
			else if (r >= 4 && r <= 7)
			{
				g_pMainState->awardItem(23, rand() % 9, 1, true);
			}
		}

		else if (r>7)
		{
			g_pMainState->awardk(100, 100);//10W���飬10WǮ
			g_pHeroObj->say("#15�Ҳ�Ҫ��������");;
		}
		AddJob("#R������ʾ#R��#B���ƾ���#B\n#R������#R#B���� #B\n#R�������#R\n���߰��Ͼ���������");
		g_pMainState->m_Map.RemoveNpc("Ҧ̫ξ", true);
		AddTriggerObj("����");
		break;
	case 40:
		AddTriggerDialog("��������������ô˵",
			"����,�����󽫾��������ڵ���ò̫��,�䲻���㣬��Ը����#78",
			"��,��Ȼ���,�Ҿͳ�ȫ��",
			"���������#75");
		AddJob("#R������ʾ#R��#B���ƾ���#B\n#R������#R#B������ #B\n#R�������#R\nȥ����Ƭ����������");
		break;
	case 41:
		getTag("����������Ƭ");
		g_pMainState->m_Map.RemoveNpc("����", true);
		AddTriggerObj("������");
		break;
	case 42:
		AddTriggerDialog("̫����,�鷳����������յ������ĸ����,��˵��,ֻҪ���޺�������յ�����ҹٸ�ԭְ��#1",
			"�������ˣ��Ͳ������������");
		AddJob("#R������ʾ#R��#B��������#B\n#R������#R#B��ĸ���� #B\n#R�������#R\nȥ����Ƭ������ĸ����");
		break;
	case 43:
		g_pMainState->awardk(0, 50);
		AddTriggerObj("��ĸ����", "��������");
		break;
	case 44:
		AddTriggerObj("��ĸ����", "��������");
		break;
	case 45:
		AddTriggerDialog("���ź��ˣ���ʲ��˭�����ںη��������С���Ƿ���䣬�����Ƿ��е������ϵ�����Ҿ��Ƿ�ԣ��������Ϊ����.",
			"#24�Բۣ������ǲ��լ���������ף������ʹ�ϵ#78",
			"#28���е�ɣ�˵�ɣ�������ɶ�£��ǲ��ǽ���ȥ���㳡�����Ӱ���#56",
			"#24�Զ����������#24��������յ,ϣ����ĸ�����ָܻ������󽫵Ĺ�λ",
			"��ͥ�Ĺ�λ����˵���ͻ���, �Ҳ�������һ�¶���, ���ص���#24",
			"ʲô#4������������˵�����㻰������.",
			"��ô�⣬�����ӱ�Ů���ǰɣ����ˣ���������");

		break;
	case 46:
	{
		auto pc = AddEnemy(100000, e����, 60, eMP_��������, "��ʴ��");
		pc->LiveHp = 100000;
		pc->getObj()->say("#G�Ҳݣ�����ô����ս����#G#24");
		pc = AddEnemy(150000, e���, 60, eMP_���ܵظ�, "��ĸ����");
		pc->getObj()->say("#G�����ģ�����ν����ͬ�ģ������Ͻ�#G#28");
		pc->LiveHp = 100000;
		pc->Speed.AddDataAdd(8000);
		for (int i = 0; i < 4; ++i)
		{
			AddEnemy(15000, e�콫, 45, eMP_���);
		}

		for (int i = 0; i < 3; ++i)
		{
			AddEnemy(15000, e���, 45, eMP_���);
		}

		g_StateType = STATE_FIGHT;
		AddTriggerFightSuccess(_next + 1);
		AddTriggerFightTurn(_next);
	}
		break;
	case 47:
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

		list.m_WorkType = WORKTYPE_ATTACK;
		list.targetID = ski.TargetID = 10;
		ski.SkillID = 1000;

		lb->getObj()->say("��,û�õķ���!");
		lh->getObj()->say("���Ŵ��ˣ��Ҵ���!");
	}
		break;

	case 48:

		/////////////////////////////////////////////////////////////////////////////
	
		if (r >6)//���������
		{

			if (r >= 0 && r <1)//10%
			{
				g_pMainState->awardBook(100 + (rand() % 4 * 10));//��
				

			}
			else if (r >= 1 && r<2)//10%
			{
				g_pMainState->awardIron(100 + (rand() % 4 * 10));//��
				

			}
			else if (r >= 2 && r<4)
			{
				g_pMainState->awardItem(23, rand() % 9, 1, true);
			
			}
			else if (r >= 4 && r <= 7)
			{
				g_pMainState->awardItem(23, rand() % 9, 1, true);
			}
		}

		else if (r>7)
		{
			g_pMainState->awardk(100, 100);//10W���飬10WǮ
			g_pHeroObj->say("#15�Ҳ�Ҫ��������");;
		}
		//////////////////////////////////////////////////////////////////////////////////////////////////////////
		AddTriggerObj("��ĸ����");
		g_pMainState->FindObjByName("��ĸ����")->say("�����������ˣ������㳡��ȥ��#36~");
		AddJob("#R������ʾ#R��#B���ƾ���#B\n#R������#R#B������ #B\n#R�������#R\n���߾���������");
		break;
	case 49:
		AddTriggerObj("������", "���ƾ���");
		break;
	case 50:
		AddTriggerDialog("�����չ����ô���ˣ���ĸ������ô˵��#47",
			"������,��ĸһֱ����ƭ��.#17",
			"�ð�,���ѿ���һ��,�����ҵ�ʹ������������ȥ����ȡ��.");

		break;

	case 51:
		AddTag("���<������>����");
		g_pMainState->m_Job.ReMoveJob(this);
		g_pMainState->awardEquip(50);//����װ�����
		break;
	case 52:
		RemoveTriggerObj();
		g_pMainState->m_Job.ReMoveJob(this);

		g_pHeroObj->say("#24�¸��������칬������������");
		break;


#if 0
	case 0:
		g_GlobalValues[5] = 6;
		SetChapter(4);
		TalkList(0, 1, 2, 3, 1, 100);
		break;
	case 100:
		Un����(m_Textlist[44]);
		break;
	case 1:
		g_pMainState->m_DialogList.clear();
		TalkList(1, 4, 2, 5, 2); break;//��˽�
	case 2:TalkList(2, 6, 7, 8, 3); break;//���ع���
	case 3:TalkList(3, 9, 10, 11, 4); break;//�ߴ���
	case 4:TalkList(4, 6, 7, 8, 5); break;//����
	case 5:TalkList(5, 1, 2, 3, 6); break;//�ߴ���
	case 6:TalkList(6, 4, 2, 5, 7); break;//��˽�
	case 7:TalkList(7, 12, 13, 14, 8); break;//���ع���
	case 8:TalkList(8, 15, 13, 14, 9); break;//������Ů
	case 9://��̫ξ
		AddTriggerDialog2(9, 10);
		break;
	case 10:
	{
		cPropertyData* ppet = Add����Enemy2(20000, eѲ������, 79, eMP_�칬, 15);
		ppet->SetJinJie(2);
		ppet = Add����Enemy2(20000, e���, 79, eMP_�칬, 65);
		ppet->SetJinJie(2);
		ppet = Add����Enemy2(20000, e�粮, 79, eMP_�칬, 66);
		ppet->SetJinJie(2);
		ePetID petid;
		for (int i = 0; i < 4; i++)
		{
			switch (rand() % 4)
			{
			case 0:petid = e�콫; break;
			case 1:petid = e���; break;
			case 2:petid = e��ʦ; break;
			default:petid = e�粮; break;
			}
			Add����Enemy2(10000, petid, 69);
		}
		SetMusic();

		g_StateType = STATE_FIGHT;
		AddTriggerFightSuccess(11);
	}
		return true;
	case 11:
	{
		SetJiangLi2(900000, 100000, 100000, 900000);

		TalkList(10, 16, 17, 18, 12);
		// 			g_pCharacter->m_PCData.AddAtkZZ(200);
		// 			g_pCharacter->m_PCData.AddGrowing(5);
		//			g_pMainState->LockLv(75);
	}
		return true;
	case 12:TalkList(11, 19, 20, 21, 13); break;//�϶�
	case 13://���
		AddTriggerDialog2(12, 14);
		break;
	case 14:
	{
		if (g_GlobalValues[0]>50)
			AddTriggerDialog2(38);
		Add����Enemy2(20000, e������, 89, eMP_���ƹٸ�);
		cPropertyData* pPet = Add����Enemy2(20000, eХ��Ȯ, 89, eMP_ʨ����);
		pPet->SuckBloodPercent.d1 += 10;
		pPet->SetJinJie(3);
		ePetID petid;
		for (int i = 0; i < 6; i++)
		{
			switch (rand() % 4)
			{
			case 0:petid = eѲ������; break;
			case 1:petid = e�콫; break;
			case 2:petid = e��ʦ; break;
			default:petid = e�粮; break;
			}
			Add����Enemy2(15000, petid, 69);
		}
		SetMusic("stonecoldFictionJunction");
		g_StateType = STATE_FIGHT;
		AddTriggerFightSuccess(15);
	}
		return true;
	case 15:
	{
		SetJiangLi2(1000000, 150000, 150000, 1000000);

		TalkList(13, 22, 23, 24, 16);
		// 			g_pCharacter->m_PCData.AddDefZZ(100);
		// 			g_pCharacter->m_PCData.AddGrowing(1);
		//			g_pMainState->LockLv(80);
	}
		return true;
	case 16:TalkList(14, 16, 17, 18, 115); break;//�۾�
	case 115:
	{

		sTaskMapObj obj;
		obj.m_Npc.Set(m_Textlist[52], m_Textlist[13], e��������, 72, 72);
		obj.m_pTask = this;
		obj.m_Stage = -1;
		AddTriggerObjMap(&obj);
		TalkList(31, 52, 13, 53, 116); break;//�϶�
	}
		break;
	case 116://��������
	{
		AddTriggerDialog2(39);
		auto p = AddPetEnemy2(66666, e��������, 66);
		p->MPMax.SetData(6666);
		p->FillHpMp();
		for (int i = 0; i < 6; i++)
		{
			Add����Enemy2(20000, e��������, 35);
		}
		SetMusic();
		g_StateType = STATE_FIGHT;
		AddTriggerFightSuccess(118);
	}
		return true;
	case 118:

	{
		RemoveTriggerObjMap();
		RemoveTriggerObj();
		RemoveNpc(52, true);
		SetJiangLi2(1080000, 150000, 150000, 1080000);
		AddChannel2(67);
		TalkList(32, 16, 17, 18, 17, -118);
		g_GlobalValues[14] += 200;
		g_GlobalValues[15] += 200;
		// 			g_pCharacter->m_PCData.AddGrowing(1);
		// 			g_pCharacter->m_PCData.AddAvoidZZ(200);
		// 			g_pCharacter->m_PCData.AddHpZZ(100);
		//			g_pMainState->LockLv(85);

		sShangPinPet sppet;
		sAddPoint addpoint;
		addpoint.Set(0, 0, 4, 1, 0);
		sppet.Set(e��������, &addpoint, 100, true);
		GetPet(m_Textlist[57], &sppet, 100);
	}
		break;
	case -118:
		AddTriggerDialog2(40);
		break;
	case 17:TalkList(15, 1, 2, 3, 18); break;//�϶�
	case 18:TalkList(16, 4, 2, 5, 19); break;//����Ԫ˧
	case 19:TalkList(17, 25, 26, 27, 20); break;//���ع���
	case 20:TalkList(18, 28, 26, 29, 21); break;//����ʮ��
	case 21:TalkList(19, 30, 2, 31, 22); break;//�׾���
	case 22:TalkList(20, 32, 2, 33, 23); break;//����
	case 23:TalkList(21, 34, 35, 36, 24); break;//������
	case 24:TalkList(22, 37, 38, 39, 25); break;//��������
	case 25://����

	{
		sNpc npc;
		int x, y;
		g_pMainState->m_Map.AutoGetPos(x, y, m_Textlist[41]);
		npc.Set(m_Textlist[40], m_Textlist[41], 123, x, y, 0);
		AddTriggerObjMap(&npc, -1);
		TalkList(23, 40, 41, 42, 26);
	}
		break;
	case 26://��������
		AddTriggerDialog2(24, 27);
		break;
	case 27:

	{
		AddPetEnemy2(30000, e��������, 99/*, eMP_ħ��կ*/);
		for (int i = 0; i < 6; i++)
		{
			Add����Enemy2(8000, e����, 69);
		}
		SetMusic();
		g_StateType = STATE_FIGHT;
		AddTriggerFightSuccess(28);
	}
		return true;
	case 28:

	{
		SetJiangLi2(1120000, 200000, 200000, 1120000);
		g_GlobalValues[14] += 200;
		g_GlobalValues[15] += 200;
		RemoveTriggerObjMap();
		TalkList(25, 37, 38, 39, 29);
		// 			g_pCharacter->m_PCData.AddDefZZ(100);
		// 			g_pCharacter->m_PCData.AddGrowing(1);
		//			g_pMainState->LockLv(95);
	}
		return true;
	case 29: TalkList(26, 59, 60, 58, 133);
		break;//����
	case 133://ȥ�ظ��������ֻ�
		g_pMainState->m_Friend.AddFriend(m_Textlist[61]);
		TalkList(33, -1, -1, 64, -1, 134);
		//AddRangeMap(63, 95, 57, 10, 135);
		break;
	case 134:
		Invite(m_Textlist[61]);
		{
			sShangPinPet sppet;
			sAddPoint addpoint;
			addpoint.Set(0, 0, 4, 1, 0);
			sppet.Set(e��������, &addpoint, 100, true);
			GetPet(m_Textlist[61], &sppet, 100);
		}
		AddTriggerObj2(62, 63, 135);
		break;
	case 135://ǧ��Թ��
		AddTriggerDialog2(34, 136);
		break;
	case 136:

	{
		cPropertyData* Pet = Add����Enemy2(24000, e����, 89, eMP_���ܵظ�, 62);
		Pet->AddSkill(ePS_����);
		Pet->SetJinJie(3);
		ePetID petid;
		for (int i = 0; i < 9; i++)
		{
			switch (rand() % 4)
			{
			case 0:petid = e��ʬ; break;
			case 1:petid = e��; break;
			case 2:petid = e��Ѫ��; break;
			default:petid = e����; break;
			}
			Add����Enemy2(12000, petid, 79);
		}
		SetMusic("OneLight");
		g_StateType = STATE_FIGHT;
		AddTriggerFightSuccess(137);
		//AddTriggerFightEscape(-137);
	}
		return true;
		//case -137:
		//	AddTriggerObj2(62, 63, 135);
		//	return true;
	case 137:

	{
		SetJiangLi2(1200000, 200000, 200000, 1200000);

		RemoveTriggerObjMap();
		TalkList(35, 32, 2, 33, 138);
		//			g_pCharacter->m_PCData.AddGrowing(1);
		g_pMainState->LockLv(95);
	}
		return true;
	case 138:
		AddTriggerDialog2(36, 139);
		UpdateJob2(-1);
		////////////////////////////////////////////////////////////////////////// �Ǻ��� ��Ҫ����
		return true;
	case 139:
		g_pMainState->m_TaskFB.Start(3);
		g_pMainState->m_TaskFB.SetTask(this, 140);
		g_pMainState->m_TaskFB.Process(0);
		g_pMainState->m_TaskFB.Process(3);
		return true;
	case 140:
		TalkList(37, 30, 2, 31, 30);
		return true;
	case 30: TalkList(27, 28, 26, 29, 31);
		SetJiangLiItem(11, 24);
		break;//����
	case 31:TalkList(28, 25, 26, 27, 32); break;//�׾���
	case 32:TalkList(29, 1, 2, 3, 33); break;//����ʮ��
	case 33:
		TalkList(30, -1, -1, -1, -1, 34);
		SetJiangLiItem(50, 40);
		g_pMainState->LockLv(105);
		/*	SetChapter(5);
		AddTriggerLv(0, 105);*/
		break;//����Ԫ˧
	case 34:
		Process5(0);
		break;
#endif
	default:
		ERRBOX2(stage);
		break;

	}

	return true;
}
