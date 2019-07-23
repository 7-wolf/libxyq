#include "_global.h"


bool TaskZhuXian::Process8(int stage)
{
	int next = stage + 1;
	setJobTitle("��ȡ�Ž���");
	int i = 10;
	int r = rand() % 100;

	static int s_hadG;
	switch (stage)
	{
	case 0:
		AddTriggerDialog("�������˵��������", "#G�ǰ����Ҷ��ȵ�ͷð�󺹣�����ʪ͸�ˣ�����ʲô��ط�������ô��#G#103"
			, "�����Ҷ��ȵú�����������ȥ��ƿŮ������������������ϸ˵��",
			"ʲô������������ڵľ�������Ҫ����ô��ô����#17#4");
		AddJob("#R������ʾ#R��\n#B���ƾ���#B\n#R������#R\n#B���Ի� #B\n#R�������#R\n��Ů��������Ի���ʣ���⿣����Ը��ؾƵ꿴�� ");
		break;
	case 1:
		AddTriggerGive("���Ի�", 23, 4, _next);
		break;
	case 2:

		AddTriggerDialog("����С���湻��˼�����Ҿ͸������"
			, "�ϻ���˵���Ͻ��ģ����������һ���ȥ��ӿ�����",
			"�������ǰ���ϵ��»���ʹ���������˻���ɽ�������س�����ׯ�ڣ����ǵ����ȹ���������������������������Ҳ��̫������Ǳ��и����ཱུ���үү������ܸ�������ӣ��㲻��ȥ����#17#4");
		AddJob("#R������ʾ#R��\n#B���ƾ���#B\n#R������#R\n#B���ع� #B\n#R�������#R\n�һ���ɽ���ع��� ");
		break;
	case 3:
		AddTriggerObj("����ɽ����");
		break;
	case 4:
		AddTriggerDialog(
			"��Ӵι������������������������������������������������������",
			"������ͷ��������ô���°�����ط��������˵�",
			"���ȹ�������ţħ�������ӣ���Ҫ���������Ҫ���㹻�Ĺ�Ʒ������Ĺ������������Ȳ��Ͻ���#4",
			"Ŷ��Ϊʲô��ط�����������Ӱ���",
			"����Ļ��˵��������ʥ�����칬ʱ������¯�����£���Ҫһ����Ե��ȥϨ�𣬶���Ȼ�ģ�������Ǹ���Ե�ˣ�Ҫ��ȥ�����Ƚ�Ž��ȣ��ѻ���ɽ�Ļ�Ϩ��#4",
			"�Ҷ�������ͨ��#2");
		AddJob("#R������ʾ#R��\n#B���ƾ���#B\n#R������#R\n#B������ #B\n#R�������#R\n��һ�������� ");
		break;
	case 5:
		AddTriggerObj("������");
		break;
	case 6:
		AddTriggerDialog("��֪��������������ʲô���������ǲ���װ׸�����ģ���ø����Ҹ���ˮ�������У�ֻ������Ҳ��ܴ���ȥ����",
			"#G�ðɣ��Ҷ�ϰ����Ҫ�Ͷ�����#103"
			, "û�취��Ŷ����թ���������ҵĿ��ұ���");
		g_pHeroObj->say("#24");
		AddJob("#R������ʾ#R��\n#B���ƾ���#B\n#R������#R\n#B������ #B\n#R�������#R\n�ұ�ˮ��������� ");
		break;
	case 7:
		AddTriggerGive("������", 27, 10, _next);
		break;
	case 8:
		g_pMainState->awardk(0, 90);
		g_pMainState->m_pNowSelect = g_pMainState->FindObjByName("������");
		AddTriggerDialog("���ȹ������˳��ٽ�������", "#68Ŷ��֪�������������̰�", "���̣�NO,NO ,NO���ҲŲ�ȥ���ø�.��ʱ�����ѱ�����", "�Բۣ������ǲ������ð�������˵�õ�һ�𵽰�ͷ����ȴ͵͵�h����");
		break;
	case 9:	
	{

		auto pc = AddEnemy(47000, e���ӹ�, 80, eMP_ħ��կ, "������");
		pc->getObj()->say("#17����˵��ȥ�Ͳ�ȥ#24#2");
		AddEnemy(25000, eţ��, 60, eMP_���);
		AddEnemy(25000, e���ܾ�, 60, eMP_���);
		AddEnemy(25000, e������, 60, eMP_���);
		AddEnemy(25000, e��󡾫, 60, eMP_���);
		AddEnemy(25000, e����, 60, eMP_���);
		AddEnemy(25000, e֩�뾫, 60, eMP_���);
		g_StateType = STATE_FIGHT;
		AddTriggerFightSuccess(_next);
		break;
	}
		
	case 10:
		SetJiangLiItem(6 + rand() % 5, 27);
		g_pMainState->awardk(600, 1000);//60W���飬100WǮ
		AddTriggerDialog("��Ȼ�������ҵ����һ��ǲ������ȥ��",
			"#G�ðɣ�Ҳ�������#G");
		AddJob("#R������ʾ#R��\n#B���ٽ���#B\n#R������#R\n#B���ȹ��� #B\n#R�������#R\nȥ�����ȹ��� ");
		break;
	case 11:
		AddTriggerObj("���ȹ���", "���ٽ���");
		break;
	case 12:
		g_pMainState->m_TriggerDialog.AddSelect(this, "�㿴��������", "���ȹ���", -1, "̫���ˣ����¾�Ȼ����˾�ɫû��", 13, "̫���ˣ���ֱ�޷�ֱ�ӣ�����̫�Բ��������", 14);
		AddJob("#R������ʾ#R��\n#B���ƾ���#B\n#R������#R\n#B������ #B\n#R�������#R\n�ұ�ˮ��������� ");
		break;
	case 13:
		AddTriggerDialogList({ "���⻰����������˵�İɣ��ߣ�", "#4���ǰ�", "ƭ�ӣ����Ұ����ȵ���������", "#4" }, next+2);
		
		AddJob("#R������ʾ#R��\n#B������#B\n#R������#R\n#B������ #B\n#R�������#R\n�������а취������� ");
		break;

	case 14:
		AddTriggerDialog(
			"#G���Ȼ��˵�ҳ󣬲���ѵ�㣬���ǲ�֪�����������#103",
			"�������ֲ�����");	
		AddJob("#R������ʾ#R��\n#B�ز�����#B\n#R������#R\n#B�ز��� #B\n#R�������#R\n�ҵز�����æ ");
		break;
	case 15:
	{
	
		auto pc = AddEnemy(990000, 41, 80, eMP_��������, "���ȹ���");
		pc->getObj()->say("#17˵�ҳ��һ������������̫��#2");
		pc->DmgAddOfMagic.d1 += 0x2fff;
		pc->DmgAdd.d1 += 0x2fff;
		g_StateType = STATE_FIGHT;
		AddTriggerFightSuccess(_next);
		AddTriggerFightFalse(_next);
		break;
		AddTriggerFightEscape(_next);
		g_pHeroObj->Set(POS_DEAD, 0);
		g_pMainState->m_Map.LoadMap(21, 46, "������");
	}
	case 16:
		g_pMainState->m_Map.LoadMap(21, 46, "������");
		AddTriggerObj("������", "������");
		break;
	case 17:
		AddTriggerDialog(
			"ʩ�������ǴӺζ������ֹ��ȥ��#3",
			".....��������....����ô����������",
			"ʩ�������ǲ��Ǹ����˴�ܴ������ӣ�",
			"#24Ŷ�����������ˣ������ȹ����Ǹ����˰����ȷ���",
			"Ŷ��֪���ˣ����ǵ�9999�������ȷɵ����������",
			"#24����Ȼ��ô�������кν��֮������",
			"����˵�������е�,˵������Ļ�,��ׯ�۵����ɷ����������,���������Ԫ���ɽ��������#3#24");
		AddJob("#R������ʾ#R��\n#BǬ����#B\n#R������#R\n#B��Ԫ���� #B\n#R�������#R\n��������� ");
		break;
	case 18:
		AddTriggerObj("��Ԫ����", "Ǭ����");
	
		break;
	case 19:
	{
		sNpc npc;
		npc.Set("�������", "Ǭ����", e�������, 13, 14, DIRECTION_LEFT);
		AddTriggerObjMap(&npc, _next, false);

		npc.Set("��������", "Ǭ����", e�ն���ʦ, 17, 16, DIRECTION_RIGHT);
		AddTriggerObjMap(&npc, _next, false);

		npc.Set("������ʦ", "Ǭ����", e������ʦ, 20, 17, DIRECTION_RIGHT);
		AddTriggerObjMap(&npc, _next, false);
	}

		break;

	case 20:
		AddTriggerDialog("���Ǻ��ˣ�������������ʦѧ�յ�ô��",
			"#G���Ѿ������ɺ�ʦ���ˣ���������������������һ�Ŷ����飬�Һ�ȥ�Ը����ȹ���#103",
			"���Ȼ��Ҫȥ��Ů�ˣ������Ҿ�����Ӧ#4",
			"��ֻ�������ȹ����Ӱ����������ѣ����������ϣ��������ȷ���#3",
			"���Լ����в�����û�취�����鰡��",
			"�ѵ������Ŀ�������������ܿ���ô��#24",
			"�Ա��⼸λ���Ѻ����л�Ҫ˵Ŷ");
		AddJob("#R������ʾ#R��\n#BǬ����#B\n#R������#R\n#B��Ԫ���� #B\n#R�������#R\n��������� ");
		break;

	case 21:
		g_pMainState->FindObjByName("�������")->say("��Ȼ�Ҷ���ûʲô��,������λ����������,��Ҳ������æ��#18#52");
		g_pMainState->FindObjByName("��������")->say("��������,���δ����ҵ�ͽ��!#54");
		g_pMainState->FindObjByName("������ʦ")->say("��������,���⻹��õ�,��ͽ����С����ɽȥն����ħ,���˺�����ɱ��,�º�����Ȼ������ƭ�߾�������ҩ,ʵ�������޿�ˡ#78");
		g_pMainState->FindObjByName("��Ԫ����")->say(".��λ������Ǻܴ󰡣�");
		AddTriggerObj("��Ԫ����", "Ǭ����");
		break;
	case 22:
		AddTriggerDialog("������ģ����Ҳ���ѵ��ѵ��",
			"#GһȺ����̣������Ѹ㡣����",
			"���ҳ��Բ�ѷ������#4"
			);
		AddJob("#R������ʾ#R��\n#BǬ����#B\n#R������#R\n#B��Ԫ���� #B\n#R�������#R\n��������� ");
		break;
	
	case 23:
	{

		auto pc = AddEnemy(70000, e��Ԫ����, 90, eMP_��ׯ��, "�ϵ�ʿ");
		pc->getObj()->say("#17���ˣ���Ȼ�ڳ�����#24#2");
		auto pc1 = AddEnemy(70000, e�������, 90, eMP_��ׯ��, "��������");
		pc1->getObj()->say("#17��ֻ��·��#2");
		auto pc2 = AddEnemy(70000, e�ն���ʦ, 90, eMP_��ׯ��, "��ͺ¿");
		pc2->getObj()->say("#17ר�θ��ֿ�#2");
		auto pc3 = AddEnemy(70000, e������ʦ, 90, eMP_��ׯ��, "�����ү");
		pc3->getObj()->say("#17��ҪΪͽ�ܱ���#2");
		AddEnemy(35000, e�ϻ�, 80, eMP_���);
		AddEnemy(35000, e����, 80, eMP_���);
		AddEnemy(35000, e֩�뾫, 80, eMP_���);
		g_StateType = STATE_FIGHT;
		AddTriggerFightSuccess(_next);
		break;
	}

	case 24:
		AddTriggerDialog("���˰��ˣ����Ƕ�������ȥ��",
			"�Ƕ�л��",
			"��������û�취#4"
			);
		break;
		AddJob("#R������ʾ#R��\n#BǬ����#B\n#R������#R\n#B��Ԫ���� #B\n#R�������#R\n��������� ");
		break;
	case 25:
		AddTag("�������񵽴˽����������ĵȴ�����");
		g_pMainState->m_Job.ReMoveJob(this);
		RemoveTriggerObj();
		break;
		/////////////////////////////////////////////////////////////////////////////
		if (r < 10)//���������
		{

			if (r < 5)
			{
				g_pMainState->awardBook(100 + (rand() % 4 * 10));//��
			

			}
			else if (r > 5)
			{
				g_pMainState->awardIron(100 + (rand() % 4 * 10));//��
			
			}
			else if (r <2)
			{
				g_pMainState->awardBook(160);//��
				g_pMainState->awardIron(160);//��
				g_pMainState->awardk(666, 6666.666);//60W���飬100WǮ
			}
		}
		else if (r < 20)
		{
			if (!g_pMainState->awardBookIron(10 * rand() % 16))
			{
				
				g_pMainState->awardShouJue1();
				
				g_pMainState->awardk(600, 1000);//60W���飬100WǮ
			}
		}
		else if (r < 30)
		{
			g_pMainState->awardEquip(80);
			g_pMainState->awardItem(27, 42 + rand() % 9, 1, true);
			g_pMainState->awardk(600, 1000);//60W���飬100WǮ
		}
		else if (r <90)
		{
			g_pMainState->awardk(600, 1000);//60W���飬100WǮ
			g_pHeroObj->say("#15����̫����");;
		}
		else if (r > 90)
		{
			g_pHeroObj->say("#15���쵹��Ѫù��ɶҲû�õ�");
		}
		//////////////////////////////////////////////////////////////////////////////////////////////////////////
		AddTriggerDialog("��������ô��ô����,��������#15������¶�һ����#71",
			"#G�Ը��ܺ�ֽר��#103",
			"���ſ���ɣ����뿴������#17",
			"�����ˣ��ҵ�С����#3",
			"�Դ���С���治Ҫ��",
			"˵�ö�#24");
		AddJob("#R������ʾ#R��\n#B������#B\n#R������#R\n#B���� #B\n#R�������#R\n�õ����ң�������ɽ��������ֱ�Ӹ��������㡣 ");
		break;

	case 26:
		AddTriggerObj("�������", "������");
		break;

	case 27:

		AddTriggerDialog("���꣬����ô�����ˣ��ǲ���̰���ҵ���ɫ��#71",
			"#17��û���أ��Ұ�������ֵܹĽ����û�����",
			"Ŷ��ԭ�����������㸽�������Ҹ�������ô�Ը�����ٺ�����******���������ȥ����Ī�����Ǻ���������#17",
			"�õģ�лл�ˣ������Ͼ�ȥ�������ͷ#3");
		AddJob("#R������ʾ#R��\n#Bˮ����#B\n#R������#R\n#B������ #B\n#R�������#R\n���ݽ�����ʾ�ֱ��ðα�ӵ�����գ������Ǹ��� ");
		break;

	case 28:
		AddTriggerObj("������", "ˮ����");
		break;


	case 29:
		g_pHeroObj->say("***********");
		g_pMainState->FindObjByName("������")->say("�Բۣ��Բۣ�ʹ�����ˣ��ĸ��������������");
		AddJob("#R������ʾ#R��\n#B����ɽ 40 240#B\n#R������#R\n#B��ҽ�� #B\n#R�������#R\n#R#B��#RΪ������٣�ȥ�Һ�ҽ��ȷ��#B" + g_strNeedBattle);
		AddTriggerObj("��ҽ��", "����ɽ", _next);
		break;

	case 30:

		AddTriggerDialog("",
			"#17�Ϻ��ӣ����Ǵ��������ڶ�����Ϣ",
			"˵��ע��㣬�ҿ����ⷽԲʮ����������ҽ#G��ӹҽ�������Ǵ������ڶ�����Ϣ���������������Ҹ���ȥ���档#G",
			"�����ˣ������ˣ�лл��#G������֪��������Ľ����䣬�һ�����ô��#G#3");
		AddJob("#R������ʾ#R��\n#B����ɽ#B\n#R������#R\n#B������ #B\n#R�������#R\nȷ����ֻ�����Ǽٰ�ģ����������ڻ���ɽ78,108��ֻ�Ի����� ");
		break;

	case 31:
		AddTriggerObj("������", "����ɽ");
		break;
	case 32:
		AddTriggerDialog("���˽֣������㣬�������ǲ����ײĲ����ᰡ��",
			"#17������������������ļ���",
			"#GӴ����Ȼʶ�����ˣ��˲��𣬵��ޣ�666������ûë����ת�����ͷɻ������ִ���#G",
			"#4��ģ�����������Щɵ��˵��Щ���ˣ�����һ�н���ʮ����");
		AddJob("#R������ʾ#R��\n#B����ɽ#B\n#R������#R\n#B������ #B\n#R�������#R\nȷ����ֻ�����Ǽٰ�ģ����������ڻ���ɽ78,108��ֻ�Ի����� ");
		break;

	case 33:
	{

		auto pc = AddEnemy(50000, e�����, 120, eMP_���ƹٸ�, "�������");
		g_pMainState->SetRanse(10, rand() % 5, rand() % 5, rand() % 5, rand() % 5);
		pc->getObj()->say("#G#18#G");
		pc->DmgPercent.d2 += 100;//������ķ����͹���
		pc->Pierce�̴�.d1 += 90;
		pc->DmgPercentOfMagic.d1 += 18;
		pc->DmgPercentOfMagic.d2 += 44;
		pc->Pierce�̴�OfMagic.d1 += 100;
		pc->Pierce�̴�OfMagic.d2 += 126;



		pc = AddEnemy(40000, 87, 120, eMP_����ɽ, "��ҽ��");
		pc->SetJinJie(3);
		g_pMainState->SetRanse(11, rand() % 5, rand() % 5, rand() % 5, rand() % 5);
		pc->LiveHp = 500;//ÿ�غϻ�Ѫ
		pc->DmgPercent.d2 += 29;//����
		pc->Pierce�̴�.d2 += 29;//����
		pc->DmgPercentOfMagic.d1 += 28;//����
		pc->DmgPercentOfMagic.d2 += 24;//����
		pc->Pierce�̴�OfMagic.d2 += 99;
		pc->DmgPercentOfFix.d2 -= 32;//�¹���


		pc = AddEnemy(40000, 87, 160, eMP_������, "�����");
		pc->SetJinJie(3);
		g_pMainState->SetRanse(12, rand() % 5, rand() % 5, rand() % 5, rand() % 5);
		pc->LiveHp = 5000;//ÿ�غϻ�Ѫ
		pc->DmgPercentOfMagic.d1 += 30;//+����
		pc->DmgPercent.d2 += 20;//�￹
		pc->Pierce�̴�.d2 += 20;//�￹
		pc->DmgPercentOfMagic.d2 += 29;//����
		pc->Pierce�̴�OfMagic.d2 += 29;//����
		pc->DmgPercentOfFix.d2 -= 35;//�¹���




		pc = AddEnemy(30000, eѲ������, 160, eMP_���ܵظ�, "����ɽ����");

		pc->SetJinJie(3);
		g_pMainState->SetRanse(13, rand() % 5, rand() % 5, rand() % 5, rand() % 5);
		pc->DmgPercent.d2 += 20;
		pc->Pierce�̴�.d2 -= 16;
		pc->Ghost.d1 += 5;
		pc->m_XiuLian.GetMag() = cct::getCurrMaxXiulianLv(30);
		pc->applyXL();


		pc = AddEnemy(30000, eѲ������, 160, eMP_����ɽ, "���");
		pc->SetJinJie(3);
		g_pMainState->SetRanse(14, rand() % 5, rand() % 5, rand() % 5, rand() % 5);
		pc->ParryRateOfMaigc.d1 += 5;
		pc->LiveHp = 50;//ÿ�غϻ�Ѫ
		pc->_isWeakSeal = false;
		pc->DmgPercent.d2 += 20;
		pc->Pierce�̴�.d2 -= 20;
		pc->Pierce�̴�OfMagic.d2 -= 70;
		pc->HitRate.d2 += 50;
		pc->Evade.AddDataAddPercent(800);
		pc->m_XiuLian.GetMag() = cct::getCurrMaxXiulianLv(25);
		pc->applyXL();

		pc = AddEnemy(40000, e��Ѫ��, 160, eMP_���ƹٸ�, "·������Ѫ��");//���ݺܺ�
		pc->SetJinJie(3);
		pc->CriRate.d1 += 20;
		g_pMainState->SetRanse(15, rand() % 5, rand() % 5, rand() % 5, rand() % 5);
		pc->LiveHp = 500;//ÿ�غϻ�Ѫ
		pc->_isWeakSeal = false;
		pc->DmgPercent.d2 += 10;//������ķ����͹���
		pc->Pierce�̴�.d1 += 10;
		pc->HitRate.d2 += 10;
		pc->Evade.AddDataAddPercent(100);
		pc->m_XiuLian.GetMag() = cct::getCurrMaxXiulianLv(25);
		pc->applyXL();


		pc = AddEnemy(30000, e������Գ, 120, eMP_���ƹٸ�, "���ȷ�");
		pc->SetJinJie(3);
		g_pMainState->SetRanse(16, rand() % 5, rand() % 5, rand() % 5, rand() % 5);
		pc->_isWeakSeal = false;
		pc->DmgPercent.d2 += 30;//������ķ����͹���
		pc->Pierce�̴�.d1 += 30;
		pc->HitRate.d2 += 30;
		pc->Evade.AddDataAddPercent(30);
		pc->m_XiuLian.GetMag() = cct::getCurrMaxXiulianLv(23);
		pc->applyXL();

		pc = AddEnemy(30000, e������, 120, eMP_��������, "�﷨ʦ");
		pc->SetJinJie(3);
		pc->DmgAdd.d1 += 50;//ÿ�غϻ�Ѫ
		g_pMainState->SetRanse(17, rand() % 5, rand() % 5, rand() % 5, rand() % 5);
		pc->Pierce�̴�.d2 -= 29;
		pc->DmgPercent.d2 += 20;
		pc->DmgPercentOfMagic.d2 += 29;
		pc->DmgPercentOfMagic.d1 += 30;
		pc->DmgPercentOfMagic.d2 += 24;
		pc->Pierce�̴�OfMagic.d1 += 10;
		pc->Pierce�̴�OfMagic.d2 += 24;

		pc = AddEnemy(30000, e��ʦ, 160, eMP_ħ��կ, "���ʦ");
		pc->SetJinJie(3);
		g_pMainState->SetRanse(18, rand() % 2, rand() % 3, rand() % 4, rand() % 5);
		pc->StabPercent.d1 += 50;//ÿ�غϻ�Ѫ

		pc->DmgPercentOfMagic.d2 += 29;
		pc->DmgPercentOfMagic.d1 += 28;
		pc->DmgPercentOfMagic.d2 += 24;
		pc->Pierce�̴�OfMagic.d1 += 20;
		pc->Pierce�̴�OfMagic.d2 += 24;

		pc = AddEnemy(30000, e�ɷ�Ů�, 160, eMP_�貨��, "�����");
		pc->SetJinJie(3);
		g_pMainState->SetRanse(19, rand() % 5, rand() % 5, rand() % 5, rand() % 5);
		pc->HitRate.d2 += 60;//ÿ�غϻ�Ѫ
		pc->DmgPercent.d2 += 39;
		pc->Pierce�̴�.d1 += 20;
		pc->DmgPercentOfMagic.d2 += 29;
		pc->DmgPercentOfMagic.d2 += 24;//����
		pc->Pierce�̴�OfMagic.d2 += 29;
		pc->m_XiuLian.GetMag() = cct::getCurrMaxXiulianLv(35);
		pc->applyXL();


		int c = 0;
		for (int i = 10; i < 15; ++i)
		{
			if (g_pMainState->m_FightWorkList[i].isExist)
			{
				++c;
			}
		}
		if (c >= 3)
		{
			g_pMainState->m_InterfaceTeam.SetFormation(eFormation(1 + rand() % 10), true);
		}
		g_StateType = STATE_FIGHT;

		AddTriggerFightSuccess(34);//��ת��Ƚ���
	}
		return true;

	case 34:
		/////////////////////////////////////////////////////////////////////////////
		if (r < 10)//���������
		{

			if (r < 5)
			{
				g_pMainState->awardBook(100 + (rand() % 4 * 10));//��
				

			}
			else if (r > 5)
			{
				g_pMainState->awardIron(100 + (rand() % 4 * 10));//��
			
			}
			else if (r <2)
			{
				g_pMainState->awardBook(160);//��
				g_pMainState->awardIron(160);//��
				
			}
		}
		else if (r < 20)
		{
			if (!g_pMainState->awardBookIron(10 * rand() % 16))
			{
				
				g_pMainState->awardShouJue1();
			
				g_pMainState->awardk(600, 1000);//60W���飬100WǮ
			}
		}
		else if (r < 30)
		{
			g_pMainState->awardEquip(80);
		
			g_pMainState->awardk(600, 1000);//60W���飬100WǮ
		}
		else if (r <90)
		{
			g_pMainState->awardk(600, 1000);//60W���飬100WǮ
			g_pHeroObj->say("#15����̫����");;
		}
		else if (r > 90)
		{
			g_pHeroObj->say("#15���쵹��Ѫù��ɶҲû�õ�");
		}
		//////////////////////////////////////////////////////////////////////////////////////////////////////////
		AddTag("���<���������>����");
		AddJob("#R������ʾ#R���������񵽴˽����������ĵȴ�����");
		g_pMainState->m_Job.ReMoveJob(this);



		break;
	case 35:
		AddTag("���<���������>����");
		break;


	case 36:
		RemoveTriggerObj();
		g_pMainState->m_Job.ReMoveJob(this);

		g_pHeroObj->say("#24�¸������� ��ݸ�ж��� �������-С��#18����");
		break;

//	switch (stage)
//	{
#if 0
	case 0:

	{
		SetChapter(8);
		g_GlobalValues[5] = 3;
		g_pMainState->SetDialogListPet(m_Textlist[1], eɳ����);
		TalkList(0, 2, 3, 4, next); break;
	}
		break;
	case 1:
		g_pMainState->m_DialogList.clear();
		TalkList(2, 8, 9, 10, 3); break;//���Ž���
	case 3:TalkList(3, 11, 9, 12, next); break;//����ʦ
	case 4:AddTriggerDialog2(4, next); break;//����
	case 5:

	{
		cPropertyData* pPet;
		pPet = Add����Enemy2(10000, e����, 69, eMP_��������, 11);
		pPet->MagicWater.d2 += 20;
		for (int i = 0; i < 4; i++)
		{
			pPet = Add����Enemy2(8000, e����, 60);
			pPet->MagicWater.d2 += 20;
		}
		SetMusic();
		g_StateType = STATE_FIGHT;
		AddTriggerFightSuccess(next);
	}
		return true;
	case 6:

	{
		SetJiangLi2(600000, 100000, 50000, 600000);

		sNpc npc;
		npc.Reset();
		npc.Set(m_Textlist[13], m_Textlist[14], 82, 41, 73, 3);
		AddTriggerObjMap(&npc, -1);
		npc.Set(m_Textlist[16], m_Textlist[14], 1074, 32, 75, 3);
		AddTriggerObjMap(&npc, -1, false);
		TalkList(5, 13, 14, 15, next);
		AddTriggerObj2(8, 9, 106, false);
		// 			g_pCharacter->m_PCData.AddDefZZ(50);
		// 			g_pCharacter->m_PCData.AddGrowing(1);
		//			g_pMainState->LockLv(64);
	}
		return true;
	case 106:
		AddTriggerDialog2(16);
		return true;
	case 7:AddTriggerDialog2(6, next); break;//Ы�Ӿ�
	case 8:

	{
		Un����(m_Textlist[27]);
		cPropertyData* pPet;
		pPet = Add����Enemy2(20000, eЫ�Ӿ�, 79, eMP_Ů����);
		pPet->HitRateOfPoison.d1 += 20;
		ePetID petid;
		for (int i = 0; i < 4; i++)
		{
			switch (rand() % 4)
			{
			case 0:petid = eϬţ����; break;
			case 1:petid = eϬţ������; break;
			case 2:petid = e���㽫��; break;
			default:petid = eҰ��; break;
			}
			Add����Enemy2(10000, petid, 69);
		}
		SetMusic();
		g_StateType = STATE_FIGHT;
		AddTriggerFightSuccess(next);
	}
		return true;
	case 9:

	{
		RemoveNpc(13, true);
		RemoveTriggerObjMap(7);
		SetJiangLi2(650000, 100000, 50000, 650000);

		sNpc npc;
		npc.Set(m_Textlist[13], m_Textlist[14], 82, 50, 50, 0);
		TalkList(7, 16, 14, 17, next, 109);
		// 			g_pCharacter->m_PCData.AddHpZZ(300);
		// 			g_pCharacter->m_PCData.AddGrowing(1);
		g_pMainState->LockLv(75);
	}
		return true;
	case 109:
		Un����(m_Textlist[28]);
		Un����(m_Textlist[29]);

		break;
	case 10:TalkList(8, 18, 6, 19, next); break;//����
	case 11:
		g_pMainState->SetDialogListNpc(m_Textlist[16], 1074);
		TalkList(9, 20, 21, 22, next);
		RemoveTriggerObjMap();
		break;//����Ů������
	case 12:
		g_pMainState->ClearDialogList();
		TalkList(10, 23, 24, 25, next); break;//����
	case 13:
		Invite(m_Textlist[28]);
		Invite(m_Textlist[29]);
		Invite(m_Textlist[27]);

		TalkList(11, 20, 21, 22, next);
		break;//������Ů
	case 14:AddTriggerDialog2(12, next); break;//���ػ�Ӱ
	case 15:

	{
		AddTriggerDialog2(17);
		cPropertyData* pPet;
		pPet = AddPCEnemy2(20000, 1, 0, 79, eMP_������, 26/*, 0, 6*/);;
		pPet->CriRateOfCure.d1 += 20;
		ePetID petid;
		for (int i = 0; i < 9; i++)
		{
			switch (rand() % 4)
			{
			case 0:petid = e����; break;
			case 1:petid = e����; break;
			case 2:petid = e��ˮҹ��; break;
			default:petid = e����; break;
			}
			Add����Enemy2(8000, petid, 60);
		}
		SetMusic("��ɫ�ಾ�");
		g_StateType = STATE_FIGHT;
		AddTriggerFightSuccess(next);
	}
		return true;
	case 16:
	{
		SetJiangLi2(700000, 100000, 50000, 700000);

		TalkList(13, 18, 6, 19, next);
		// 			g_pCharacter->m_PCData.AddSpdZZ(50);
		// 			g_pCharacter->m_PCData.AddGrowing(1);
		//			g_pMainState->LockLv(66);
	}
		return true;
	case 17:TalkList(14, 20, 21, 22, next); break;//����Ů������
	case 18:
		TalkList(15, -1, -1, -1, -1, 19);
		break;//����
	case 19:
		//		g_pCharacter->m_PCData.AddGrowing(5);
		SetJiangLiItem(16, 24);
		return Process3(0);
#endif
	default:
		ERRBOX2(stage);
		break;
	}


	return true;
}
