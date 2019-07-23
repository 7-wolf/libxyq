#include "_global.h"



bool TaskZhuXian::Process5(int stage)
{
	int next = stage + 1;
	setJobTitle("��ԩ��С����");
	int i = 10;
	int r = rand() % 20;
	switch (stage)
	{
	case 0:
		AddTriggerDialog("#G������������ӿ����ѹ�#G#103"
			, "������ʲô������ô���İ�", "����������������ںȾƵ�ʱ�򣬲�֪���Ѵ���������Ĵ��ˣ�û�Ǳ����ҿ�Ҫְλ��������#4", "����պ��пգ��Ұ������Ұ�",
			"��̫лл�㣡�������ҵĺ��ֵܡ�");
		AddJob("#R������ʾ#R��\n#B���ٴ�#B\n#R������#R\n#Bë¿�� #B\n#R�������#R\n���ٴ壨81��129����ë¿�ż���һ����������ı��ӣ����Ǵ���������ʧ���������ޡ� ");
		break;
	case 1:
		AddTriggerObj("ë¿��", "���ٴ�");
		break;
	case 2:
		AddTriggerDialog(""
			, "ë��¿����˵��������˼�����ܷ����Ҽ�ʶ��ʶ",
			"#2��˭������զ����ʶ�㰡�������ҽ�ë¿�ţ�����ë��¿��",
			"������������Ϲ��������ǻ�һ��ȹ��Ƶ��֣��������ͦƯ���ģ����͸��Ҳ���",
			"�ǿɲ��У�����������ƿ������������",
			"û���⣬�������ϡ�");
		AddJob("#R������ʾ#R��\n#B���ٴ�#B\n#R������#R\n#Bë¿�� #B\n#R�������#R\n����������ë¿�ŵĴ���� ");
		break;

	case 3:
		AddTriggerGive("ë¿��", 22, 52, _next);
		break;

	case 4:
		g_pMainState->awardk(0, 50);
		g_pMainState->m_pNowSelect = g_pMainState->FindObjByName("ë¿��");
		AddTriggerDialog("лл�㣬�����оƺ���");
		break;
	case 5:
		getTag("�õ������");
		AddJob("#R������ʾ#R��\n#B�칬#B\n#R������\n#B#�������� #B\n#R�������#R\n�Ѵ���޽�������������");
		AddTriggerObj("��������", "�칬", _next);
		break;
	case 6:
		getTag("ʧȥ�����");
		AddTriggerDialog("������̫�������,�����ٶ��治��һ��Ŀ죬�����ڲ��ñ�����巣��#1",
			"#3�����ǵ�Ȼ�����ڰ���û���ٶȣ�����ô��������������档��ò���Ҹ�˭Ҳ˵���⻰����������",
			"", "��˵��׼����˭���̰���", "�㲻֪��ô����������������̫�Ӵ���������״͵�ҹ���飬���������Ĵ��������Ϊ�˱�������Ѫ���������ϸ���ͥ����۴�ŭ�������ش�300��壬Ȼ������ȥ�����棬�����������κ�ԩ�أ�"
			,"������£���ȥ����С��������ʲô�����û��������ȥ��������ȡ������");
		AddJob("#R������ʾ#R��#B�칬#B\n#R������#R#B�������� #B\n#R�������#R\nȥ���ο���С����");
		break;
	case 7:
		AddTriggerObj("��������");
		break;
	case 8:
		AddTriggerDialog(""
			, "������磬�������������������С���������飬˳�㿴��һ����",
			"����°첻����С�����������������������Խ���ˣ�����ȥ������Ҳ��֪�������ܷ��غ����˰�",
			"Ŷ��ԭ���������ӣ������ҷ����������Ⱥ�ڵ������������ܾ����ҵ�����лл�ˡ�",
			"���ÿ�������Ҳ��������ԩ���ģ�");
		AddJob("#R������ʾ#R��\n#B�����Թ����#B\n#R������#R\n#BС���� #B\n#R�������#R\nȥ�����Թ���㣨54��38���ҵ�Խ����С���� ");
		break;
	case 9:
		AddTriggerObj("С����", "�����Թ����");
		break;
	case 10:
		AddTriggerDialog(""
			, "���ҵ�����,��ʦ�������Ѿ��뿪�������,������ȥ����ʦ����׼������ȥȡ����.",
			"���ߺ��ˣ��ò�������ͥ������׽�ҵĹ����Ӱɣ��϶��ǣ����ǲ���ԹԵؾͷ��ģ�����һ��",
			"just wait a minute!#8����ģ�������ˮ�µĶ����������������˻���ô��",
			"�����ɣ���۵��߹���");
		break;
	case 11:
	{
		auto pc = AddEnemy(30000, e����, 65, eMP_��������, "С����");
		pc->getObj()->say("#17��۵��߹�#17�����ǲ����������������֮�µ�#2");
		AddEnemy(10000, eС��Ů, 60, eMP_���);
		AddEnemy(10000, e����, 60, eMP_���);
		AddEnemy(10000, e����, 60, eMP_���);
		AddEnemy(10000, e��ة��, 60, eMP_���);
		AddEnemy(10000, eϺ��, 60, eMP_���);
		g_pMainState->m_FightWorkList[13 + rand() % 5].m_pObj->say("#G����С����������������ң�#G#118");
		g_StateType = STATE_FIGHT;
		AddTriggerFightSuccess(_next);
		break;
	}

	case 12:
		AddTriggerDialog("�ɶ񣬾�Ȼ����������..�Ҳ����ġ���",
			"С�����Ҳ�����׽��ģ��������˽����������ģ���������������ô��ϲ������Ϳ���",
			"������˼����ˣ����⼸�춼�����ĵ����ģ�ǰ�����ұ���ʤ�����۸�˵�Ҵ���������͵����ӣ���ͥ���˰���ץ�˹�ȥ,����������,�Һò������ӳ���.�����������ԩ����#15����͵�����,��һֱ�ķ�������������֮������.������Ǹ�ֻ��180��һ�����˻�,����ʤ������һ��ҧ�����Ҵ���������͵�����",
			"(180W�ı��˻�.........�������������������#71)", "�������ҵ���������ȥ������֮���æ��", "�ð�,��ȥ������֮������#3");
		g_pMainState->awardEquip(60);
		g_pMainState->awardk(350, 80);
		getTag("�õ�����");
		AddTriggerObj("С����");
		g_pMainState->FindObjByName("С����")->say("�����׽�ң�û��ô����");
		AddJob("#R������ʾ#R��\n#B�������߲�#B\n#R������#R\n#B����֮�� #B\n#R�������#R\nȥ�������߲��ҵ�����֮�������ӵ�����");
		break;

	case 13:
		AddTriggerObj("����֮��", "�������߲�");
		break;
	case 14:
		getTag("ʧȥ����");
		AddTriggerDialog("������,��Ȼ�Һ����С����,���Ǹ����ӱ���͵����.������Ҳ�޷�֤������С��������������.������ħ���У�Ҫ�Ǹ������ӳ����������鷳��",
			"���Ҹ���ô��źã�",
			"���÷�����ס��һ��С͵,��Ϊ����֮��,�Ҳ�������ְ��,���������������ȥ��,��Ӧ�����Ĳ�,��ȥ�ҵ���,����ͬ��������.",
			"�õġ�лл��");
		AddJob("#R������ʾ#R��\n#B�������Ĳ�#B\n#R������#R\n#B������� #B\n#R�������#R\nȥ�������Ĳ����ձ���");
	case 15:
		AddTriggerObj("�������", "�������Ĳ�");
		break;
	case 16:
		AddTriggerDialog("�ҽб�����屡�����ʯɽ����̸��ʥ�������µĸ�󡾫���Ҽ���ʥ�������˸���Ϊ��ͷ���ֵ����������ޱߣ����������͵��һ�����ӣ��±��˷��֣����������￴��",
			"�����Ǹ���ʵ�ĺ�ֽ��",
			"��Ҳû�취�������Ҳ���ս���ģ���������˵��������һ����ս������Ȼ����̫�̣�����û�취���㶮�ģ���������֮ǰ����Ⱥ���3�����¹����У��ұϾ���BOSS�������ǳ�",
			"����Ҳ�����еĵ��۰���û�취ֻ���ܾ���ά��ά�����������ӡ�");
		AddJob("#R������ʾ#R��\n#B�������Ĳ�#B\n#R������#R\n#BѪ֮�� #B\n#R�������#R\nȥ�������Ĳ��ո�Ѫ֮�ȣ���ս����");
		break;

	case 17:
		AddTriggerObj("Ѫ֮��");
		break;
	case 18:
	{
		AddEnemy(20000, eҰ��, 60, eMP_���ܵظ�, "Ѫ֮��");
		for (int i = 0; i < 4; ++i)
		{
			AddEnemy(10000, eҰ��, 60, eMP_���);
		}
		AddJob("#R������ʾ#R��\n#B���������#B\n#R������#R\n#Bɭ֮�� #B\n#R�������#R\nȥ����������ո�ɭ֮�ȣ���ս����");
		readyFightAndSucces();
	}
		break;

	case 19:
		
		AddTriggerObj("ɭ֮��", "���������");
		break;

	case 20:
	{
		AddEnemy(20000, e��Ѫ��, 60, eMP_ʨ����, "ɭ֮��");
		for (int i = 0; i < 4; ++i)
		{
			AddEnemy(10000, e��ʬ, 60, eMP_���);
		}
		AddJob("#R������ʾ#R��\n#B����������#B\n#R������#R\n#B������� #B\n#R�������#R\nȥ�����������ո���֮�ȣ���ս����");
		readyFightAndSucces();
	}
		break;

	case 21:

		AddTriggerObj("��֮��", "����������");
		break;
	case 22:
	{
		AddEnemy(20000, e��ʬ, 60, eMP_���ƹٸ�, "��֮��");
		for (int i = 0; i < 4; ++i)
		{
			AddEnemy(10000, eҰ��, 60, eMP_���);
		}
		AddJob("#R������ʾ#R��\n#B�������Ĳ�#B\n#R������#R\n#B������� #B\n#R�������#R\nȥ�������Ĳ��ܱ�����屣���ս����");
		readyFightAndSucces();
	}
		break;

	case 23:

		AddTriggerObj("�������", "�������Ĳ�");
		break;
	case 24:
		AddTriggerDialog("���������˵ã�������Ҳ�þ�ȫ��Ӧս����",
			"�Ǻǣ�û�а취�Ҿ�����ôǿ������һѪ�Ҷ�����",
			"�̷�-��������֮�����̷�-ͨ��֮��",
			"#17���������������");
		AddJob("#R������ʾ#R��\n#B�������Ĳ�#B\n#R������#R\n#BѪ֮�� #B\n#R�������#R\nȥ�������Ĳ��ո�Ѫ֮�ȣ���ս����");
		break;
	case 25:
	{
		auto pc = AddEnemy(30000, e��󡾫, 40, eMP_���ƹٸ�, "�������");
		pc->LiveHp += 1000;
		pc->LiveRestoreRate += 50;
		pc->StartMagic = ePS_�߼���ɱ + 2000;
		pc->DmgPercentOfFix.d2 += 30;
		pc->DmgPercentOfMagic.d2 += 20;
		pc->HitRateOfSeal.d1 += 10000;
		pc->DmgAddOfCure.d1 += 800;
		pc = AddEnemy(20000, e��Ѫ��, 40, eMP_��������, "��֮��");
		pc->LiveHp = 10000;
		pc->Speed.AddDataAdd(8000);
		pc = AddEnemy(20000, e��ʬ, 40, eMP_���ܵظ�, "Ѫ֮��");
		pc->LiveHp = 10000;
		pc->Speed.AddDataAdd(8000);
		pc = AddEnemy(20000, eҰ��, 40, eMP_ʨ����, "ɭ֮��");
		pc->LiveHp = 10000;
		pc->Speed.AddDataAdd(8000);
		for (int i = 0; i < 2; ++i)
		{
			AddEnemy(15000, eţͷ, 45, eMP_���);
		}

		for (int i = 0; i < 2; ++i)
		{
			AddEnemy(15000, e����, 45, eMP_���);
		}

		g_StateType = STATE_FIGHT;
		AddTriggerFightSuccess(_next );}
		break;
	case 26:
		AddTriggerObj("�������");
		break;
	case 27:
		AddTriggerDialog("�����ˣ������ˣ��㶼�ǿ��ҵģ���ȫ������",
			"�罻������û��ô��������",
			"�����Ǿ�ͷ����͵��,������ʤ�����м���.���Ǻϻ���С������������,�����պ������ù�������ҡ����Ҳû������.",
			"#17ԭ�����,���Ѿ�û�����ü�ֵ��#18");
		g_pMainState->awardk(400, 100);
		g_pMainState->awardItem(26, 108 + rand() % 80, 1, true);
		AddJob("#R������ʾ#R��\n#B����#B\n#R������#R\n#Bз�� #B\n#R�������#R\nȥ��������ʥ����");
		break;
	case 28:

		AddTriggerObj("з����", "����");
		break;
	case 29:

		AddTriggerObj("з����", "����");
		break;
	case 30:
		g_pMainState->setNowSelect();
		AddTriggerDialog("���ߺ��˺�����ɺ�ħ!��Ȼ���ô�����������һǯ�ӡ�",
			"�⻰�Һ�������������.......�������˾��ϴ�����ʱ�����꣬������ô������", "#G�ϻ���˵�����ɡ�", "#G�Ҿ����˽������������з��");
		break;

	case 31:
	{
		auto pc = AddEnemy(30000, eз��, 60, eMP_���ƹٸ�, "з����");
		pc->LiveHp = 1000;
		pc = AddEnemy(25000, eϺ��, 60, eMP_�貨��, "Ϻ����");
		pc->LiveHp = 1000;
		pc->Speed.AddDataAdd(8000);
		for (int i = 0; i < 4; ++i)
		{
			AddEnemy(15000, eϺ��, 45, eMP_���);
		}

		for (int i = 0; i < 4; ++i)
		{
			AddEnemy(15000, eз��, 45, eMP_���);
		}

		g_StateType = STATE_FIGHT;
		AddTriggerFightSuccess(_next + 1);
		AddTriggerFightTurn(_next);
	}
		break;
	case 32:
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
		lh->DmgAdd.d2 -= 5000;
		lb->Hit.AddDataAdd(5000);

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

		lb->getObj()->say("�������������в�!");
		lh->getObj()->say("�õģ������һ��Ŭ��!");
	}
		break;

	case 33:
		g_pMainState->awardEquip(80);
		g_pMainState->awardItem(27, 42 + rand() % 9, 1, true);
		g_pMainState->awardk(200, 250);//60W���飬100WǮ
		AddJob("#R������ʾ#R��\n#B����#B\n#R������#R\n#Bз�� #B\n#R�������#R\n��з������̽��ʥ����λ��");
		AddTriggerObj("з����","����");
		break;
	case 34:
		
		g_pMainState->FindObjByName("з����")->say("#R��ʥ����#R��20 64");
		g_pHeroObj->say("��˵���Ͳ��ð�������#24");	
		AddTriggerObj("��ʥ����", "����", _next + 1);
		break;
	case 35:
		AddTriggerObj("��ʥ����", "����");
		break;
	case 36:
		
		AddTriggerDialog("����ʲô��?�ǲ��ǿ�������������ǿ������ң�",
			"�����#4����;�ͷ���������ݺ�С���������Ҷ��Ѿ�֪����,̹�״ӿ�,���ܴ���#4",
			"�����Ǿ�ͷ����͵��,����,���Ǳ��ȵ�,��ͷ����͵�������������,�����������˵����,���Ͱ�����ݴ���#15.",
			"#17ԭ�����,Ȼ����#3#18",
			"�Ҷ�������,�����ǰ������������#8��ͷ����������ţħ�����︰��,������ȥ������.");
		AddJob("#R������ʾ#R��\n#Bħ����#B\n#R������#R\n#B��ͷ���� #B\n#R�������#R\nȥţħ��ס���Ҿ�ͷ����");
		break;

	case 37:

		AddTriggerObj("��ͷ����", "ħ����");
		break;
	case 38:
		AddTriggerDialog("","��ͷ����,��������������#4",
			"�ڳ�����,����Ҫ����������#18#4");
		AddJob("#R������ʾ#R��\n#Bħ����#B\n#R������#R\n#B��ͷ���� #B\n#R�������#R\n��ܾ�ͷ����");
		break;

	case 39:
	{
		auto pc = AddEnemy(40000, e��ͷ����, 65, eMP_���, "��ͷ����");
		pc->getObj()->say("#Gû����������͵�ģ��б�����������ȥ��#G#17");
		pc = AddEnemy(35000, e���꾫, 60, eMP_��������, "��ʥ����");
		pc->getObj()->say("#G�ղ�û���ղŰ������������,������#18#G");
		pc->LiveHp = 100000;
		pc->Speed.AddDataAdd(8000);
		pc = AddEnemy(35000, eţħ��, 60, eMP_ħ��կ, "ţħ��");
		pc->getObj()->say("#G������������,�����۸�����ţ������,��������#4#G");
		pc->LiveHp = 100000;
		pc->Speed.AddDataAdd(8000);
		AddEnemy(18000, e����, 60, eMP_���);
		AddEnemy(18000, e��ɽ����, 60, eMP_���);
		AddEnemy(18000, e��ɽ����, 60, eMP_���);
		AddEnemy(18000, e����, 60, eMP_���);
		AddEnemy(18000, eţ��, 60, eMP_���);
		AddEnemy(18000, eţ��, 60, eMP_���);
		g_pMainState->SetRanse(i, 1);//���ٻ��޼���ɫ����
		g_pMainState->m_FightWorkList[10 + rand() % 5].m_pObj->say("#G������������#18#");
		g_pMainState->m_FightWorkList[10 + rand() % 5].m_pObj->say("#18");
		readyFightAndSucces();
	}
		break;

	case 40:
		g_pMainState->awardEquip(70);
	
		if (r >6)//���������
		{

			if (r >= 0 && r <1)//10%
			{
				g_pMainState->awardBook(100 + (rand() % 4 * 10));//��
				g_pMainState->award5bao();//�屦

			}
			else if (r >= 1 && r<2)//10%
			{
				g_pMainState->awardIron(100 + (rand() % 4 * 10));//��
				g_pMainState->awardItem(27, 38 + rand() % 3, 1, true);//ǿ��ʯ

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
		///
		AddTriggerObj("��ͷ����");
		g_pMainState->FindObjByName("��ͷ����")->say("��...�ɶ�...�Ҿ�Ȼ...�����������������ʽ��~");
		AddJob("#R������ʾ#R��\n#B��������#B\n#R������#R\n#B��� #B\n#R�������#R\n�����˵�����");
		break;
	case 41:
		g_pMainState->awardk(1500, 400);
		AddTriggerDialog("��...�ɶ�...�Ҿ�Ȼ...�����������������ʽ��~", ".....��Ȼ��Ӯ��,���ǲ���˼��#3������.");
		AddJob("#R������ʾ#R��\n#B��������#B\n#R������#R\n#B��� #B\n#R�������#R\n�����˵��������ȿ�����ͷ����ɶ���԰�");
		break;

	case 42:
		AddTriggerObj("��ʴ��", "��������");
		break;
	case 43:

		AddTriggerDialog("�ⲻ������С�����ı�����....",
			"С�����Ǳ���ͷ�����ݺ���.��û�д�������",
			"�ð�,��ȥ����С������,��������#17");
		AddJob("#R������ʾ#R��\n#B�����Թ����#B\n#R������#R\n#BС���� #B\n#R�������#R\nȥ�����Թ���㣨54��38����С���� ");
		break;
	case 44:
		AddTriggerObj("С����", "�����Թ����");
		break;

	case 45:

		AddTriggerDialog("����С����һ��,�����ȥ��ʦ��ȥ.",
			"������ȥ����˽��.");
		AddJob("#R������ʾ#R��\n#B���ƾ���#B\n#R������#R\n#B��˽� #B\n#R�������#R\nȥ���ƾ���������Ԫ˧��˽� ");
		break;
	case 46:
		RemoveTriggerObj();
		g_pMainState->m_Job.ReMoveJob(this);

		g_pHeroObj->say("#24�¸������Ҵ��ƾ�������Ԫ˧����");
		break;









#if 0
	case 0:
		g_GlobalValues[6] = 8;
		g_GlobalValues[5] = 7;
		SetChapter(5);
		AddTriggerObj2(8, 9, 1);
		UpdateJob2(10);
		break;
	case 1:
		AddTriggerDialog2(3, 3); //������
		break;
	case 3:
	{
		Add����Enemy2(30000, e��ʦ, 109, eMP_������, 26);
		Add����Enemy2(30000, eɳ����, 109, eMP_��������, 28);
		Add����Enemy2(30000, e��˽�, 109, eMP_ʨ����, 27);
		ePetID petid;
		for (int i = 0; i < 3; i++)
		{
			switch (rand() % 3)
			{
			case 0:petid = e������Գ; break;
			case 1:petid = e��ü���; break;
			default:petid = e�������; break;
			}
			Add����Enemy2(10000, petid, 99);
		}
		SetMusic();
		g_StateType = STATE_FIGHT;
		AddTriggerFightSuccess(11);
	}
		return true;
	case 11:

	{
		SetJiangLi2(1250000, 250000, 250000, 1250000);

		AddTriggerDialog2(4, -11); //������
		//			g_pCharacter->m_PCData.AddGrowing(1);
		//			g_pMainState->LockLv(95);
	}
		return true;
	case -11:

	{
		auto pet = Add����Enemy2(990000, e�����, 69, eMP_���ƹٸ�);
		pet->DmgAdd.d1 += 0x1fff;
		ePetID petid;
		for (int i = 0; i < 4; i++)
		{
			switch (rand() % 4)
			{
			case 0:petid = e������Գ; break;
			case 1:petid = e��ü���; break;
			default:petid = e�������; break;
			}
			Add����Enemy2(8000, petid, 59);
		}
		SetMusic();
		g_StateType = STATE_FIGHT;
		AddTriggerFightSuccess(-13);
		AddTriggerFightFalse(-13);
		AddTriggerFightEscape(-13);
	}
		return true;
	case -13:

	{
		TalkList(5, 11, 12, 13, 12);
	}
		return true;


	case 12:TalkList(6, 14, 15, 16, next); break;//�������
	case 13:TalkList(7, 8, 9, 10, next); break;//�
	case 14:TalkList(8, 8, 17, 10, next); break;//������
	case 15:AddTriggerDialog2(9, next); break;//������
	case 16:

	{
		cPropertyData* pPet;
		pPet = Add����Enemy2(30000, e�����, 138, eMP_���ƹٸ�);
		pPet->MagicFire.d2 += 20;
		pPet->HitRate.d2 += 30;
//		pPet->PeopleSpecial.d1 += 1000;
		ePetID petid;
		for (int i = 0; i < 4; i++)
		{
			switch (rand() % 4)
			{
			case 0:petid = e������Գ; break;
			case 1:petid = e��ü���; break;
			default:petid = e�������; break;
			}
			Add����Enemy2(10000, petid, 99);
		}
		SetMusic("�򲻵��Ŀ�����");
		g_StateType = STATE_FIGHT;
		AddTriggerFightSuccess(17);
	}
		return true;
	case 17:

	{
		SetJiangLi2(1300000, 250000, 250000, 1300000);

		TalkList(10, 14, 15, 16, next);
		//			g_pCharacter->m_PCData.AddGrowing(1);
		//			g_pMainState->LockLv(105);
		AddChannel2(37);
		int xp, yp;
		for (int i = 0; i < 55; i++)
		{
			g_pMainState->m_Map.AutoGetPos(xp, yp, m_Textlist[36]);
			switch (rand() % 3)
			{
			case 0:
				AddTriggerObjMap2(35, 36, e��, xp, yp, -1, -17);
				break;
			case 1:
				AddTriggerObjMap2(35, 36, e��ƿŮ�, xp, yp, -1, -18);
				break;
			case 2:
				AddTriggerObjMap2(35, 36, e��ħ��, xp, yp, -1, -19);
				break;
			}
		}
	}
		return true;
	case -17:

	{
		m_pObj = g_pMainState->m_pNowSelect;
		int lv = g_pCharacter->m_PcData.m_Lv;
		Add����Enemy2(lv * 250, e��, lv + 5, eMP_���, 35);
		for (int i = 0; i < 7; i++)
			Add����Enemy2(lv * 200, (ePetID)(35 + rand() % 20), lv);

		SetMusic();
		g_StateType = STATE_FIGHT;
		AddTriggerFightSuccess(-117);
	}
		return true;
	case -18:

	{
		m_pObj = g_pMainState->m_pNowSelect;
		int lv = g_pCharacter->m_PcData.m_Lv;
		Add����Enemy2(lv * 250, e��ƿŮ�, lv + 5, eMP_���, 35);
		for (int i = 0; i < 7; i++)
			Add����Enemy2(lv * 200, (ePetID)(35 + rand() % 20), lv);

		SetMusic();
		g_StateType = STATE_FIGHT;
		AddTriggerFightSuccess(-117);
	}
		return true;//
	case -19://��ħ��

	{
		m_pObj = g_pMainState->m_pNowSelect;
		int lv = g_pCharacter->m_PcData.m_Lv;
		cPropertyData* pPet;
		pPet = Add����Enemy2(lv * 250, e��ħ��, lv + 5, eMP_ħ��կ, 35);
		pPet->AddSkill(ePS_�߼�����);
		for (int i = 0; i < 7; i++)
			Add����Enemy2(lv * 200, (ePetID)(35 + rand() % 20), lv);

		SetMusic();
		g_StateType = STATE_FIGHT;
		AddTriggerFightSuccess(-117);
	}
		return true;
	case -117:
		SetJiangLi2(100000, 50000, 50000, 100000);
		RemoveTriggerObjMap2(m_pObj);
		g_pMainState->m_Map.RemoveNpc(m_pObj, true);
		return true;
	case 18:TalkList(11, 18, 19, 20, next); break;//�
	case 19:TalkList(12, 11, 12, 13, next); break;//�ز���
	case 20:TalkList(13, 21, 22, 23, -20); break;//�������
	case -20:TalkList(14, 24, 22, 25, 21); break;//���ܾ�
	case 21:AddTriggerDialog2(15, next); break;//С��Ů
	case 22:

	{
		Add����Enemy2(20000, eС��Ů, 109, eMP_����ɽ);
		ePetID petid;
		for (int i = 0; i < 7; i++)
		{
			switch (rand() % 2)
			{
			case 0:petid = e���ܾ�; break;
			default:petid = e����; break;
			}
			Add����Enemy2(10000, petid, 89);
		}
		SetMusic();
		g_StateType = STATE_FIGHT;
		AddTriggerFightSuccess(23);
	}
		return true;
	case 23:

	{

		SetJiangLi2(1320000, 250000, 250000, 1320000);

		TalkList(16, 8, 9, 10, next);
		//			g_pCharacter->m_PCData.AddGrowing(1);
		//			g_pMainState->LockLv(99);
	}
		return true;
	case 24:AddTriggerDialog2(17, next); break;//������
	case 25:

	{
		Add����Enemy2(30000, e����⨺�, 159, eMP_���ƹٸ�);
		ePetID petid;
		for (int i = 0; i < 9; i++)
		{
			switch (rand() % 4)
			{
			case 0:petid = e������Գ; break;
			case 1:petid = e��ü���; break;
			default:petid = e�������; break;
			}
			Add����Enemy2(8000, petid, 109);
		}
		SetMusic();
		g_StateType = STATE_FIGHT;
		AddTriggerFightSuccess(26);

	}
		return true;
	case 26:

	{
		//			RemoveTriggerObjMap();//����û��
		SetJiangLi2(1400000, 250000, 300000, 1400000);
		RemoveTriggerObj();
		TalkList(18, -1, -1, -1, -1, -26);
		g_GlobalValues[14] += 200;
		g_GlobalValues[15] += 200;
//		g_pCharacter->m_PcData.m_BangPaiID = 0;
		// 			g_pCharacter->m_PCData.AddDefZZ(50);
		// 			g_pCharacter->m_PCData.AddGrowing(1);
		g_pMainState->LockLv(115);
	}
		return true;
	case -26:
		Un����("���");
		AddFriend(32);
		g_pMainState->SetDialogListNpc(m_Textlist[31], 1081);
		TalkList(19, -1, -1, -1, -1, 28); break;//
		break;
	case 28:

	{
		g_pMainState->ClearDialogList();
		Un����("����");
		AddFriend(33);
		TalkList(20, -1, -1, -1, -1, -1);

		AutoGetPet(m_Textlist[33]/*, 3*/);
		Invite(m_Textlist[33]);

		AutoGetPet(m_Textlist[32]/*, 2*/);
		Invite(m_Textlist[32]);
		Un����("С��");
		AddFriend(34);
		//			AutoGetPet(m_Textlist[34], 4,5);
		Invite(m_Textlist[34]);

		////////////////////////////////////////////////////////////////////////// �Ǻ��� ��Ҫ����
		//			Process6(0);

		g_pMainState->m_TaskFB.Start(0);
		g_pMainState->m_TaskFB.Process(0);
		g_pMainState->m_TaskFB.SetTask(this, 29);

	}
		break;
	case 29:
		g_pMainState->m_TaskFB.Start(1);
		g_pMainState->m_TaskFB.Process(0);
		g_pMainState->m_TaskFB.SetTask(this, 30);
		break;
	case 30:
		g_pMainState->m_TaskFB.Start(2);
		g_pMainState->m_TaskFB.Process(0);
		g_pMainState->m_TaskFB.SetTask(this, 31);
		break;
	case 31:
		Process6(0);
		g_pMainState->LockLv(125);
		break;
#endif
	default:
		ERRBOX2(stage);
		break;
	}


	return true;
}
