#include "_global.h"



bool TaskZhuXian::Process6(int stage)
{
	int next = stage + 1;
	setJobTitle("����׹Ǿ�");
	int i = 10;
	int r = rand() % 20;

	static int s_hadG;
	switch (stage)
	{
	case 0:
		AddTriggerDialog("#G�٣��������ɵȵ������ˣ��м������ͷ�����һ��#17#G#103"
			, "��~��������,����ôҲ���Һ����ˣ�����ô��������ˣ�", "��ʦ����Ҫ�ģ����������˸���,�μ�����ׯ���ٴ���,�����ּ縺ȡ������,�޷�����,����������������ȥȷ��һ��.#17#4", "����պ��пգ���������ô�г���ķ����ҾͰ�����һ�˰�#1",
			"��̫лл�㣡�������ҵĺ��ֵܡ�");
		AddJob("#R������ʾ#R��\n#B���ƾ���#B\n#R������#R\n#B����ɮ #B\n#R�������#R\n���ƾ��⣨351��29������ɮ�ƺ�ÿ�춼����ô�ͣ��ȥ������ ");
		break;
	case 1:
		AddTriggerObj("����ɮ");
		break;
	case 2:

		AddTriggerDialog("���ް����ӷ�C�Cଣ��������� �������� ��������������� �������� ��������"
			, "��ʦ#24�����ڳ���ô",
			"#2���꣬�������Ǹ�����֮�ţ��Ƿ�����Ȥ����ѧϰ���ְ���",
			"�ҲŲ���ͺ¿��������������ڸ���ׯ���������ɶ�¡�",
			"Ŷ��ԭ������������ֻ֪���������ں��У���ȥ�ʸ��������ɣ���֪���ñȽ������",
			"�ðɣ������������������ˡ�������");
		g_pMainState->m_Mp3.Load("C��C��");
		AddJob("#R������ʾ#R��\n#B���ƾ���#B\n#R������#R\n#B�������� #B\n#R�������#R\n�ڸ���ׯ�������������������� ");
		break;

	case 3:
		AddTriggerObj("��������", "����ׯ����");
		break;
	
	case 4:
		AddTriggerDialog("�������ׯ���춪�������һ�����ڣ���������ׯ��Ҳ���������Ұ�޵�ʬ�壬ʬ��֧�����飬ȫ��Ѫ�����ɣ������ǰ������ׯ�ļҶ���Ӷ��Ҳ��ʼʧ����",
			"#3���Բۣ���ô���£��һ��ǲ�Ҫ�����������ˣ�",
			"վס��#4�����߿ɷ����ˣ�����æ�����µľ����޷�������������#28���������������㻹��̫�ۣ�", "#24�������൱�ɶ񰡣�", "����ģ���˵ˮ���ɼ���ʶ�㣬��ȥ�������ɣ�"
			, "�������꣬�����ܸ����鶼Ҫ�ܵ����ֲ���ƽ����#65��");
		AddJob("#R������ʾ#R��#B���ƾ���#B\n#R������#R#Bˮ���� #B\n#R�������#R\n��ˮ���ɴ�̽��Ϣ");
		break;
		
	case 5:
		AddTriggerObj("ˮ����", "���ƾ���", _next);
		break;
	case 6:

		AddTriggerDialog("#98",
			"#3����������ô���������ľ�����Ů#80",
			"�Ǻǣ�����С������Ϳ�����", "������и�ë�ã���ϧ���һ��ǵ���", "����������ҵ������˵ģ���֪��������ɶ����ʵ��Ҳ��֪������ȥʨ���������������ɣ�"
			,"�õģ�лл��");
		AddJob("#R������ʾ#R��#Bʨ����#B\n#R������#R#B������ #B\n#R�������#R\nȥʨ�����������������ֳ��˵���");
		break;
	case 7:
		AddTriggerObj("������", "�ϵ�");
		break;
	case 8:
		AddTriggerDialog("��ѽ,ʲôʱ�����ٳ�һ����ɮ�Ⱑ.��һ�ξ���ȫͣ��������#80"
			, "����,һ��������Եĸ���ׯ����,����#4",
			"#24������ʲô�����");
		break;
	case 9:
	{
	
		auto pc = AddEnemy(30000, eţ��, 65, eMP_ʨ����, "������");
		pc->getObj()->say("#17�԰���ʳ-<������>��Ȼ����һ����Ź#24#2");
		AddEnemy(15000, eţ��, 60, eMP_���);
		AddEnemy(15000, e���ܾ�, 60, eMP_���);
		AddEnemy(15000, e������, 60, eMP_���);
		AddEnemy(15000, e��󡾫, 60, eMP_���);
		g_StateType = STATE_FIGHT;
		AddTriggerFightSuccess(_next);
		break;
	}
	case 10:
		AddTriggerDialog("��磬����ׯ��Ѫ����������Ϊ�����Ҵ�����#115",
			"����˭��Ϊ���㶼˵���������ˣ��������㣿",
			"��û��ͯ��ô�������������ʳ����֪�������ֲ��ǳ����������",
			"˵�ĺ��е����Ҿ�Ȼ�����Զԣ�������ɶ�м�ֵ����Ϣ����", "��˿���Ů��֪��������ֵܶ࣬��ǰȥ̽��һ��", "�ð�,������þ͵�������Թ���#3",
			"�������ɷ������һ���������͸��Һ���Ұ����",
			"#103��һ����������Ǯ����Ҫ���ʵ�Ҫ�󣬲����ʣ��������߰��ŵ��ˣ�#B�����Ｘʮ����������ܹ�������)#B#3");
		g_pMainState->awardk(400, 150);
		AddJob("#R������ʾ#R��#B���ƾ���#B\n#R������#R#BҰ���� #B\n#R�������#R\n���ƾ��⣨483��7����һ�����ޱ�������������Ұ����");
		break;
	case 11:
		AddTriggerObj("Ұ����", "���ƾ���");
		break;
	case 12:
		AddTriggerDialog("û�� ���ޱ���(����) ����ʲô������˵��");
		break;
	case 13:
		AddTriggerGive("Ұ����", 26, 153 , _next);
		//AddTriggerObj("Ұ����", "���ƾ���");
		break;
	case 14:
		g_pMainState->m_pNowSelect = g_pMainState->FindObjByName("Ұ����");
		AddTriggerDialog("�ۣ��ⲻ����������������ޱ���ô�������������ҾͿ��ԳưԴ��ƾ�����",
			"#17�������Ϣ�����ﲻ��˵���������ʸ���ׯѪ��������ģ�",
			"Ŷ������°������⼸�춼�����ĵ����Ļ��ţ������ۼ��������ҵ����֡�������ϲ��һ����£��߶�ʱ���ŵ���ۻ��һ���ȷ�",
			"��Ȼ��ôǿ��", "��������������˿���Ů�����ʰɣ�#3");
		g_pMainState->awardEquip(60);
		AddTriggerObj("Ұ����");
		g_pMainState->FindObjByName("Ұ����")->say("�ưԴ��ƾ���ָ�տɴ�");
		AddJob("#R������ʾ#R��\n#B��˿��#B\n#R������#R\n#BŮ�� #B\n#R�������#R\nȥ��˿����Ů��һЩ����");
		break;
	case 15:
		AddTriggerObj("Ů��", "��˿��");
		break;
	case 16:
		AddTriggerDialog("#4�������ĵ��˾�Ȼ���������ң�",
			"���ޣ��Ҵ����в��������������һ���£�",
			"��֪������.",
			"����������������#17");
		AddJob("#R������ʾ#R��\n#B���ƾ���#B\n#R������#R\n#Bɽ��ͷ�� #B\n#R�������#R\nɽ��ͷ�ӣ����ƾ���94��90��Ҳ�ڴ�����Ѫ�����֣�������Щ������");
	case 17:
		AddTriggerObj("ɽ��ͷ��", "���ƾ���");
		break;
	case 18:
		AddTriggerDialog("#96",
			"��ô�ˣ�",
			"�ҵ��ֵܾ������ִ����ˣ�Σ�ڵ�Ϧ��ֻ�о�ת�ػ굤����Ϊ���ֵ�����",
			"����ʶ�Ľ������̺���������");
		AddJob("#R������ʾ#R��\n#B����Ұ��#B\n#R������#R\n#B�������� #B\n#R�������#R\n�ҽ�������Ҫ��ת���굥");
		break;

	case 19:
		AddTriggerObj("��������", "����Ұ��");
		break;
	case 20:
		AddTriggerDialog("Ӵ���Ͽͻ�������ʲô��Ҫ���ܸ���˵������ŵ�Ű��۸���#1",
			"����Ƚ��ûɶǮ��ҩ�ˣ����޸���ת���굤������#28",
			"ûǮ��������˼���������ת���굤û���ˣ��´�����#98",
			"��Ҫ��ʹ�������ſϽ������ǰɡ�");
		break;
		

	case 21:
	{
		auto pc = AddEnemy(30000, eɽ��, 65, eMP_���, "��������");
		pc->getObj()->say("#17����ң��������ˣ�С������#24#2");
		AddEnemy(15000, eǿ��, 60, eMP_���);
		AddEnemy(15000, e��ͽ, 60, eMP_���);
		AddEnemy(15000, e��ͷ��, 60, eMP_���);
		AddEnemy(15000, e��󡾫, 60, eMP_���);
		g_StateType = STATE_FIGHT;
		AddTriggerFightSuccess(_next);
		break;
	}
		
	case 22:
		AddTriggerDialog("�����㣬����ˣ����������Ǿ�ת���굤����ȥ�ɣ�#1",
			"��֪��ˣ��αص����֣��ԹԽ��������ͺ���#2",
			"���ֲ��ǹ�����֯�ģ����Ǻ�ʮ�ֻ���Ա#98",
			"#24");
		g_pMainState->awardItem(22, 45, 1, true);
		AddJob("#R������ʾ#R��\n#B���ƾ���#B\n#R������#R\n#Bɽ��ͷ�� #B\n#R�������#R\n�õ��ľ�ת���굤��ɽ��ͷ�ӣ��ȵ���ٸ��裩");
		break;
	case 23:

		AddTriggerObj("ɽ��ͷ��", "���ƾ���");
		break;
	case 24:
		AddTriggerDialog("�������Ƿ��ҵ���ת���굤��");
		break;

	case 25:

		AddTriggerGive("ɽ��ͷ��", 22, 45, _next);
		break;

	case 26:
	g_pMainState->m_pNowSelect = g_pMainState->FindObjByName("ɽ��ͷ��");
	AddTriggerDialog("̫��л���ˣ��ҵ��ֵ��о��ˡ�#1",
		"С��һ׮����֪������ׯ����������ֵ�������#2",
			"�����֪���������ۿ������������������£����ź�����˵�����ֺ��󣬶��Ҵ���һ�ɶ�������񻹷ǳ��׶�#98",
			"�õģ������Ĵ�ȥѰ��һ��������");
		g_pMainState->awardItem(22, 45, 1, true);
		g_pCharacter->m_PcData.AddMoney(100000);
		AddJob("#R������ʾ#R��\n#B���ƾ���#B\n#R������#R\n#B������ #B\n#R�������#R\nȥ���ƾ��⣨233��7��̽��һ��");
	break;
	case 27:
	AddTriggerObj("������", "���ƾ���");
		break;
	case 28:
		g_pHeroObj->say("�������ɢ���Ŷ����Ѭ�����ˣ��һ��ǿ���߰�#24");
		AddJob("#R������ʾ#R��\n#B���ƾ���#B\n#R������#R\n#B����ɮ #B\n#R�������#R\nȥ���ƾ��⣨350��30��������ɮ����������");
		AddTriggerObj("����ɮ", "���ƾ���", _next + 1);
		break;
	case 29:
		AddTriggerObj("����ɮ", "���ƾ���");
		break;
	case 30:
		AddTriggerDialog("","��ʦ���ղ�������һ������ɫ�·�����ɢ���������ˣ����ò��������ְɣ�",
			"#Gû��������������������ռ��Ѫ���ڸ���ׯ������̽���϶������ˡ�", "#G�ã�������ȥ�����е�#4��");
		AddJob("#R������ʾ#R��\n#B���ƾ���#B\n#R������#R\n#B������ #B\n#R�������#R\nȥ���ƾ��⣨233��7���������-������");
		break;

	case 31:
		AddTriggerObj("������");
		break;
	case 32:
		g_pMainState->FindObjByName("������")->say("#R#�⼸��ûϴ���ˣ������ѬѬ�ģ���������");
		g_pHeroObj->say("������#4����һ�н���ʮ����#28");
		AddTriggerObj("������", "���ƾ���", _next);
		break;
	case 33:
	{
		auto objSelect = g_pMainState->m_pNowSelect;
		if (1)
		{
			auto pc = AddEnemy(30000, 2001, 75, eMP_��ׯ��, objSelect->m_TrueName.GetString(), nullptr, 160);
			pc->m_XiuLian.AddXiuLianLv(30, eXLATK);
			pc->m_RanSe.m_ranse[0].Set(4, 3, 3, 3); //����Ⱦɫ
			pc->getObj()->say("#17��Ȼ�ҳ���˧������Ҳû˧������ĳ̶Ȱ�#24");
			g_pMainState->m_ColorManage.Give2(&pc->m_RanSe.m_ranse[0], pc->modeid);
		}

		{
		cPropertyData* Pet;
		Pet = AddPCEnemyF(25000, 2001, 0, 70, eMP_���ƹٸ�, "������", 2, 22);
		Pet->m_XiuLian.AddXiuLianLv(20, eXLATK);
		//Pet->m_RanSe.m_ranse[1].Set(2, 3, 1, 3); //����Ⱦɫ
		g_pMainState->SetRanse(11, 5, 2, 1, 3);
		g_pMainState->m_ColorManage.Give2(&Pet->m_RanSe.m_ranse[0], 2000);
	}
{
	cPropertyData* Pet;
	Pet = AddPCEnemyF(25000, 2001, 0, 70, eMP_������, "������", 2, 22);
	Pet->m_XiuLian.AddXiuLianLv(20, eXLATK);
	//Pet->m_RanSe.m_ranse[3].Set(0, 3, 3, 3); //����Ⱦɫ
	g_pMainState->SetRanse(12, 4, 2, 3, 3);
	g_pMainState->m_ColorManage.Give2(&Pet->m_RanSe.m_ranse[0], 2000);
}
	{
		auto pc = AddEnemy(20000, 2002, 65, eMP_�貨��, "", nullptr, 160);
		pc->m_XiuLian.AddXiuLianLv(10, eXLATK);
		pc->m_RanSe.m_ranse[0].Set(4, 3, 3, 3); //����Ⱦɫ
		pc->getObj()->say("#24");
		g_pMainState->m_ColorManage.Give2(&pc->m_RanSe.m_ranse[0], pc->modeid);
	}
	{
		auto pc = AddEnemy(20000, 2003, 65, eMP_ʨ����, "", nullptr, 160);
		pc->m_XiuLian.AddXiuLianLv(10, eXLATK);
		pc->m_RanSe.m_ranse[0].Set(4, 3, 3, 3); //����Ⱦɫ
		pc->getObj()->say("#17");
		g_pMainState->m_ColorManage.Give2(&pc->m_RanSe.m_ranse[0], pc->modeid);
	}
		AddTriggerObj("������");
		g_StateType = STATE_FIGHT;
		AddTriggerFightSuccess(34);
	}
		break;
	case 34:
		AddJob("#R������ʾ#R��\n#B���ƾ���#B\n#R������#R\n#B������ #B\n#R�������#R\n����������");
		AddTriggerObj("������","���ƾ���");
		break;
	case 35:
		
		AddTriggerDialog("����Ҫ�����������ص����ˣ�����ô��ܸ������ëС��#1",
			"�����������ɣ�#2",
			"�Ҳ���������������ׯ�۵�����С�꣬��ʦ��֮����ɽ������ħ�������ϵĳ��������������ִ�ʱ��������ʬ���������������������ң�����������#98",
			"#24������˼���ҳ嶯�ˣ���ʲô�취���κ��㣿",
			"ȥ��ׯ������ʦ����Ԫ������һζ��ѩɢ#98�Ҳ��ܺ�ת","�ã�������ȥ��������" );
		
		//////////////////////////////////////////////////////////////////////////////
	
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
		////////		////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		AddJob("#R������ʾ#R��\n#B��ׯ��#B\n#R������#R\n#B��Ԫ���� #B\n#R�������#R\n����Ԫ������һζ��ѩɢ");
		break;
	case 36:
		AddTriggerObj("��Ԫ����", "Ǭ����");
		break;
	case 37:
		AddTriggerDialog("ʲô#4���Ȼ�����ᰮͽ��",
			"�����д�������ᣬһʱ���˵�����������ֻ�к�ѩɢ�ܾ�����#4",
			"���Ǻ�ѩɢ����Ͻ���ȥ�������°ɣ�#15.",
			"#32�ã����Ͼ�ȥ#18",
			"��Ը�ҵĵ�����ͦ������.");
		g_pMainState->awardItem(22, 11, 1, true);
		AddJob("#R������ʾ#R��\n#B���ƾ���#B\n#R������#R\n#B������ #B\n#R�������#R\n�ú�ѩɢ����С��ʳ��");
		break;
	case 38:
		AddTriggerGive("������", 22, 11, _next);
		break;
	case 39:	
		AddTriggerDialog("��ϻش��ƾ��⣨233��7���������˾��ֱ���͵Ϯ���������Ѿ�������������ĵز����Ͻ��ð����˷�����ҩ��");
		AddTriggerObj("������", "���ƾ���");
		break;
	case 40:	
		
		AddTriggerDialog("��ϻش��ƾ��⣨233��7���������˾��ֱ���͵Ϯ���������Ѿ�������������ĵز����Ͻ��ð����˷�����ҩ��");
		AddTriggerDialog("����ׯǰ�Ǹ�����ɮ����ʵ�����ֵ��ĸ������������֮ǰ͵Ϯ����","��ͺ¿��Ȼ���ص���ô����Ҹ�ƭ��#4",
			"�����ҵ����ֱ�����һǧ�����óɾ��������仯�����Ϊ��Ů�����Ϊ����������ƭ�����˴���ʳ������������鷳������ȥ��ׯ������Ԫ����Ѱ�����","");
		AddJob("#R������ʾ#R��\n#B���ƾ���#B\n#R������#R\n#B����ɮ #B\n#R�������#R\n����ׯǰ�Ǹ�����ɮ����ʵ�����ֵ��ĸ�������͵Ϯ��������");
		break;

	case 41:
		AddTriggerObj("����ɮ", "���ƾ���");
		break;

	case 42:
		AddTriggerDialog("�����Ƿ�鵽ʲô����?#4",
			"�ǵ�,�������ˣ���Ѷ���չ�����,�Ҹ�����#1", "ʲô��,����ô����#24");
		
		break;
	case 43:
		{
		auto pc = AddEnemy(30000, e�ն���ʦ, 70, eMP_������, "����ɮ");
		pc->getObj()->say("#���������Ǻ���#24");
		AddEnemy(15000, e����, 60, eMP_���);
		AddEnemy(15000, e���ܾ�, 60, eMP_���);
		AddEnemy(15000, e�ϻ�, 60, eMP_���);
		AddEnemy(15000, e��󡾫, 60, eMP_���);
		g_pMainState->m_FightWorkList[0].m_pObj->say("#G��ͺ¿������ƭ�ң����Ѿ�ʶ����Ĺ���ˣ�#G#118");
		g_StateType = STATE_FIGHT;
		AddTriggerFightSuccess(_next);
		break;
	}


	case 44:
		
		g_pMainState->awardEquip(50);
		AddTriggerObj("����ɮ");
		g_pMainState->FindObjByName("����ɮ")->say("��...�Բ�...����...#R���˾Ⱦ���...��~");
		AddJob("#R������ʾ#R��\n#B���ƾ���#B\n#R������#R\n#B����ɮ #B\n#R�������#R\n��������ɮ");
		break;

	case 45:
		g_pMainState->awardk(600, 200);
		AddTriggerDialog("��...�Բ�...����...#R���˾Ⱦ���...��~");
		AddJob("#R������ʾ#R��\n#B���ƾ���#B\n#R������#R\n#B����ɮ #B\n#R�������#R\n��������ɮ" + g_strNeedBattle);
		break;
	case 46:
		g_pMainState->FindObjByName("����ɮ")->m_ShowTime = 0;
		g_pMainState->m_Map.RemoveNpc("����ɮ", true);
		g_pHeroObj->say("���¸��ǰ׹Ǿ���#24");
		g_pMainState->m_FightWorkList[0].m_pObj->say("���������Ǳ�����Ů�Ŀ�����,��ȥ������#3");
		AddJob("#R������ʾ#R��\n#B���ƾ���#B\n#R������#R\n#B��Ů #B\n#R�������#R\n������ڴ��ƾ���Ѱ�����֣�;��������Ů�����ƾ���559��104���ڿ���#3");
		AddTriggerObj("��Ů");
		break;
	case 47:
		AddTriggerDialog("", "��Ů,����ô��?#1", "�Ҳ�С��ˤ��һ��,�����޷���·��#15?#1", 
			"û��ϵ,����������ס��,�ұ���ؼҰ�#1", 
			"��л����.�ҼҾ��ڸ���ׯ.#1", 
			"", "�Ҷ��Ӷ��ˣ�����Զ����ˣ�");
		break;
	case 48:
	{
		auto pc = AddEnemy(45000, e����, 65, eMP_��˿��, "������Ů");
		pc->getObj()->say("#17�Ҷ��Ӷ���#17����͵��ҵĵ��İ�#2");
		AddEnemy(10000, e���ӹ�, 60, eMP_���, "���ӹ�ආ�");
		AddEnemy(10000, e����, 60, eMP_���, "����ආ�");
		AddEnemy(10000, e���ӹ�, 60, eMP_���, "���ӹ�ආ�");
		AddEnemy(10000, e����, 60, eMP_���, "����ආ�");
		AddEnemy(10000, e��ͷ��, 60, eMP_���, "��ͷ�ֹ�ආ�");
		AddEnemy(10000, e֩�뾫, 60, eMP_���, "֩�뾫��ආ�");
		AddEnemy(10000, e֩�뾫, 60, eMP_���, "֩�뾫��ආ�");
		g_pMainState->m_FightWorkList[0].m_pObj->say("#G�Һ���������׼������Ȼ������ˣ�#G#118");
		g_StateType = STATE_FIGHT;
		AddTriggerFightSuccess(_next);
		break;
	}
	case 49:

		AddTriggerDialog("�򲻹��㣬���ܡ��������ֻ���һ�����̣�����ʧ����Ӱ���٣�");
		g_pMainState->FindObjByName("��Ů")->m_ShowTime = 0;
		g_pMainState->m_Map.RemoveNpc("��Ů", true);
		
		//////////////////////////////////////////////////////////////////////////////
		
		if (r >6)//jiutou���������
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
		////////		////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		AddJob("#R������ʾ#R��\n#B���ƾ���536��30#B\n#R������#R\n#B��̫�š���̫ү #B\n#R�������#R\n�ڴ��ƾ���һ·Ѳ�ӣ�������̫�š���̫ү�������޷��ֱ�����");
		break;
	case 50:
		AddTriggerObj("��̫��", "���ƾ���", _next);
		break;
	case 51:
		g_pMainState->FindObjByName("��̫��")->say("�Ǻǣ�������ʳ���ζ��ʵ����̫������#52");
		g_pHeroObj->say("����˵���ȽϿ��ɣ��ò��������ֱ�İɣ�����������Ԫ�������ʰɣ�#28");
		AddJob("#R������ʾ#R��\n#BǬ����#B\n#R������#R\n#B��Ԫ���� #B\n#R�������#R\n����Ԫ��������");
		AddTriggerObj("��Ԫ����", "Ǭ����", _next + 1);
		break;
	case 52:
		AddTriggerObj("��Ԫ����", "Ǭ����");
		break;
	case 53:
		AddTriggerDialog("","���������֪������ׯ���ֵ�����","��֪����������������Ҫ����������æ��");
		AddJob("#R������ʾ#R��\n#B��������#B\n#R������#R\n#B� #B\n#R�������#R\n�����æ����������");
		break;
	case 54:
		AddTriggerObj("�", "��������");
		break;
	case 55:
		AddTriggerDialog("", "�����������֪������ׯ���ֵ�����", "����ָ��������ֵ�������������������㣬���㽵����");
		AddJob("#R������ʾ#R��\n#B���ƾ���#B\n#R������#R\n#B��̫�� #B\n#R�������#R\n����̫��ʹ��������");
		getTag("��õ���������");
		break;
	case 56:
		AddTriggerObj("��̫��", "���ƾ���", _next);
		break;
	case 57:
		AddTriggerDialog("","��������ɣ��������̫��ʹ������������", "��ѽ������ʶ���ˣ�û�취�˿��ҳ�����", "��̫��");
		AddJob("#R������ʾ#R��\n#B���ƾ���#B\n#R������#R\n#B��̫�� #B\n#R�������#R\n����̫��ʹ��������");
		break;

	case 58:
	{
		auto pc = AddEnemy(47000, e���ù�, 65, eMP_���ܵظ�, "�׹Ǿ�");
		pc->getObj()->say("#17�������ɣ�С��#2");
		AddEnemy(10000, e���ӹ�, 60, eMP_���, "���ӹ�ආ�");
		AddEnemy(10000, e����, 60, eMP_���, "����ආ�");
		AddEnemy(10000, e��ͷ��, 60, eMP_���, "��ͷ��ආ�");
		AddEnemy(10000, e�ϻ�, 60, eMP_���, "�ϻ�ආ�");
		AddEnemy(10000, e��ʬ, 60, eMP_���, "��ʬආ�");
		AddEnemy(10000, eҰ��, 60, eMP_���, "Ұ���ආ�");
		AddEnemy(10000, e֩�뾫, 60, eMP_���, "֩�뾫��ආ�");
		g_pMainState->m_FightWorkList[0].m_pObj->say("#G��Ҫ��������#G#118");
		g_pMainState->m_FightWorkList[1].m_pObj->say("#G����Ҳ���ǳ��ص�#G#4");
		g_StateType = STATE_FIGHT;
		AddTriggerFightSuccess(_next);
		break;
	}
		
	case 59:
		AddTriggerDialog("�򲻹��㣬�����������������еģ���������Ե�ٻ�", "�Բۣ��ָ����ӵ��ˣ���֪������װ��������λϵͳ�ˣ���ϧ��");
		g_pMainState->m_FightWorkList[1 + rand() % 3].m_pObj->say("#G��������ܼ��ܵ����˰�.����������������Ҫ�㱦����#3#G#77");
		g_pHeroObj->say("�����и���̫ү���ò����������ֱ�İɣ���������������˵#24");
		/////////////////////////////////////////////////////////////////////////////
		
	
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
		//////////////////////////////////////////////////////////////////////////////////////////////////////////
		AddJob("#R������ʾ#R��\n#B���ƾ���#B\n#R������#R\n#B�ϴ�ү #B\n#R�������#R\n����̫үʹ��������");
		break;

	case 60:
		AddTriggerObj("��̫ү", "���ƾ���");
		break;
	case 61:
		g_pMainState->FindObjByName("��̫ү")->say("#R�����õ��գ�һ���������");
		g_pHeroObj->say("#24��Ȼ���޷�Ӧ");
		g_pMainState->m_FightWorkList[1+rand()%3].m_pObj->say("#G����Ц#G#77");
		AddJob("#R������ʾ#R��\n#B��������#B\n#R������#R\n#B� #B\n#R�������#R\n����������̫үû��Ӧ�������æ����");
		AddTriggerObj("�", "��������", _next + 1);
		break;
	case 62:
		AddTriggerObj("�", "��������");
	case 63:
		AddTriggerDialog("�������£��������������ļ�������˰������ڵø���һ�����У���ȻȺ������ܴ�", "����������ô��źã��ܲ��������ȥɱ������̫ү�ɣ���������ô���˻���Ь������ر�죬��һ�������֣����ϸ����ɵģ���ҵ��������п��ܵ�",
			"�����ɣ���ȥ�Ҷ�����������������־��ܲ��ˣ����ȸĽ���������");
		getTag("ʧȥ������");
		AddJob("#R������ʾ#R��\n#B��������#B\n#R������#R\n#B��߸ #B\n#R�������#R\n����߸��������");
		break;
	case 64:
		AddTriggerObj("��߸", "��������");
		break;
	case 65:
		AddTriggerDialog("", "����ү���ܲ��ܽ���Ĺ���������һ��", "ʲô������#24", "�������ϵĻ���籰���",
			"���������ðɣ�������������������Ӹ���Ǯ��ѡ��ģ������뵽ͦ�鷳��û�������ԾͲ�����", "��л���ߣ���л������������������#24");
		getTag("�õ��Ľ����������");
		getTag("�õ�����籣������ӣ�");
		AddJob("#R������ʾ#R��\n#B���ƾ���#B\n#R������#R\n#B�ϴ�ү #B\n#R�������#R\n����̫үʹ��������");
		break;
	case 66:
		AddTriggerObj("��̫ү", "���ƾ���");
		break;

	case 67:
		AddTriggerDialog("�������������ң�������û���ˣ��������ƾ��ӻ����ճ��ҵ�ԭ��������Цô", "�����þ��Ӷ�����̫ү�����գ�", "���������⾵�Ӻ�ҫ�ۡ�����Ҫ�Գ�ԭ����", "���������º�ľ��ӹ�Ȼ����",
			"�ۣ��⾵�ӳ��ֵ���Ůʵ����̫Ư����#", "����Ψһһ�����Լ���ƭ��Ҫ��#24");
		break;

	case 68:
	{
		auto pc = AddEnemy(47000, e���ù�, 45, eMP_���ܵظ�, "�׹Ǿ�");
		pc->getObj()->say("���첻����������������#2");
		g_pMainState->SetRanse(10, 1, 3, 2);
		AddEnemy(15000, e��ʬ, 45, eMP_���, "��ʬ����");
		AddEnemy(15000, eҰ��, 45, eMP_���, "Ұ������");
		AddEnemy(15000, eţͷ, 45, eMP_���, "ţͷ���");
		AddEnemy(15000, e����, 45, eMP_���, "����ܵ�");
		AddEnemy(10000, e����ս��, 45, eMP_���, "����ս��ආ�");
		AddEnemy(10000, e���꾫, 45, eMP_���, "���꾫ආ�");
		AddEnemy(10000, e֩�뾫, 45, eMP_���, "�׹Ǿ�ආ�");
		g_pMainState->m_FightWorkList[13 + rand() % 5].m_pObj->say("#G��ս��#G#18");
		g_pMainState->m_FightWorkList[0].m_pObj->say("#G�϶���������#G#118");
		g_pMainState->m_FightWorkList[3].m_pObj->say("#G������������#G#4");
		g_StateType = STATE_FIGHT;
		AddTriggerFightSuccess(_next + 1);
		AddTriggerFightTurn(_next);
		s_hadG = 0;
		break;
	}
	case 69:
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
			if (l.m_pObj->m_TrueName.GetString() == "�׹Ǿ�����")
			{
				idG = i;
				break;
			}
			++num;
		}
		if (idG < 0 && num < 2 && fw && !s_hadG)
		{
			int bbmode = g_pMainState->m_Map.m_EnemyList[rand() % g_pMainState->m_Map.m_NumOfEmemyType];
			sPetData* pm = g_pMainState->m_PetDataManager.GetPetData(bbmode);
			auto ppp = AddEnemy(47000, e���ù�, 50, eMP_��������, "�׹Ǿ�����");
			g_pMainState->SetRanse(11, 1, 1, 2);
			int cid = ppp->m_IDinFightWorkList;
			g_pMainState->m_pFightState->PrePareToFight(12);
			ppp->FillHpMp();
			cObj* obj = ppp->getObj();
			obj->SetXY(g_pMainState->m_pFightState->m_ս������xs[12], g_pMainState->m_pFightState->m_ս������ys[12]);
			obj->MoveShadow();
			obj->MoveDialog();
			obj->MoveHpLine();
			obj->UpdateHpLine();
			obj->MoveName();
			g_pMainState->FindObj();
			fw->m_pObj->say("������");
			s_hadG = 1;

			auto bbb = AddEnemy(47000, e���ù�, 50, eMP_��������, "�׹Ǿ�����");
			g_pMainState->SetRanse(12, 3, 1, 2);
			int abc = bbb->m_IDinFightWorkList;
			g_pMainState->m_pFightState->PrePareToFight(abc);
			bbb->FillHpMp();
			obj->SetXY(g_pMainState->m_pFightState->m_ս������ys[abc], g_pMainState->m_pFightState->m_ս������ys[abc]);
			obj->MoveShadow();
			obj->MoveDialog();
			obj->MoveHpLine();
			obj->UpdateHpLine();
			obj->MoveName();
			g_pMainState->FindObj();
			s_hadG = 3;
		}
		else if (idG >= 0 && g_pMainState->m_FightWorkList[idG]._myTurn == 1)
		{
			g_pMainState->m_FightWorkList[idG].m_pObj->say("����#2�Ѷ���������Ŷ��");
		}
		
	}
		break;
		
	case 70:
		
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
		AddTriggerDialog("�һ��������", "��ز����ˣ��ҿ��ݳ���", "�������������������һ��ס��ġ�������Ҳ����Ź���", "#24");
		g_pMainState->m_Map.RemoveNpc("��̫ү", true);
		AddJob("#R������ʾ#R��\n#B��������#B\n#R������#R\n#B��߸ #B\n#R�������#R\n���������ͻ���类�����߸");
		break;

	case 71:
		AddTriggerObj("��߸", "��������");
		break;

	case 72:
		getTag("ʧȥ�Ľ����������");
		getTag("ʧȥ����籣������ӣ�");
		AddTriggerDialog("", "��л��ı���ҽ������ܴ����׹Ǿ�һ�ٲ�����", "������������ˣ��Ժ���ɶ��Ҫ��æ�ľ������ң�");
		AddJob("#R������ʾ#R��\n#B����ׯ#B\n#R������#R\n#B�������� #B\n#R�������#R\n���߸������������Ѿ�����");
		break;

	case 73:
		AddTriggerObj("��������", "����ׯ����");
		break;

	case 74:
		AddTriggerDialog("",
			"����ׯ���������Ѿ����Ҳ����ˣ����ǿ��Թ�̫ƽ������",
			"̫��л�����ˣ����Ǵ�׼�����#Rŵ������ƽ��#R���㣬��л��Ϊ�������Ĺ��ף�", "��̫�����ˣ��治��Ϊ�鰡#39��ʲôʱ��佱����#77", "#27���������������С�������"
			, "�ðɣ������˸��ҿ�ݹ������ǵ���˳����Ŷ����������Ҿ��յ�");
		
		break;

	case 75:
		AddTag("���<����׹Ǿ�����>����");
		AddJob("#R������ʾ#R���������񵽴˽����������ĵȴ�����");
		g_pMainState->m_Job.ReMoveJob(this);
	
		
	
		break;
	case 76:
		AddTag("���<����׹Ǿ�����>����");
		break;


	case 77:
		RemoveTriggerObj();
		g_pMainState->m_Job.ReMoveJob(this);

		g_pHeroObj->say("#24�¸������� ��ݸ�ж��� �������-С��#18����");
		break;

//#if 0
//	case 0:
//		g_GlobalValues[5] = 8;
//		SetChapter(6);
//		g_pMainState->SetDialogListPet(m_Textlist[1], e��˽�);
//		TalkList(0, 2, 3, 4, next); break;//��˽�
//		break;
//	case 1:
//		g_pMainState->m_DialogList.clear();
//		TalkList(1, 5, 26, 6, next); break;//����ɮ
//	case 2:TalkList(2, 9, 10, 11, next); break;//��������
//	case 3:AddTriggerDialog2(3, next); break;//������
//	case 4:
//
//	{
//		cPropertyData* pPet;
//		pPet = Add����Enemy2(30000, e��������, 138, eMP_ʨ����, 9);
//		pPet = Add����Enemy2(30000, e��������, 138, eMP_ʨ����, 28);
//		pPet = Add����Enemy2(30000, e��������, 138, eMP_ʨ����, 29);
//		ePetID petid;
//		for (int i = 0; i < 5; i++)
//		{
//			switch (rand() % 2)
//			{
//			case 0:petid = e������; break;
//			default:petid = e��������; break;
//			}
//			Add����Enemy2(20000, petid, 109);
//		}
//		g_pMainState->m_InterfaceTeam.SetFormation(sky, true);
//		SetMusic("Magia");
//		g_StateType = STATE_FIGHT;
//		AddTriggerFightSuccess(next);
//	}
//		return true;
//	case 5:
//
//	{
//		SetJiangLi2(1500000, 250000, 300000, 1500000);
//
//		TalkList(4, 7, 3, 8, next);
//		g_GlobalValues[14] += 200;
//		g_GlobalValues[15] += 200;
//		// 			g_pCharacter->m_PCData.AddHpZZ(500);
//		// 			g_pCharacter->m_PCData.AddSpdZZ(100);
//		// 			g_pCharacter->m_PCData.AddGrowing(1);
//		//			g_pMainState->LockLv(109);
//	}
//		return true;
//	case 6:TalkList(5, 12, 3, 13, next); break;//Ұ����
//	case 7:AddTriggerDialog2(6, next); break;//������
//	case 8:
//
//	{
//		sZiZhi zizhi;
//		zizhi.Set(1400, 1200, 2000, 6000, 1200, 1200, 120);
//		AddPCEnemy2(30000, 1, &zizhi, 129, eMP_����ɽ, 12);
//		ePetID petid;
//		for (int i = 0; i < 4; i++)
//		{
//			switch (rand() % 2)
//			{
//			case 0:petid = eţͷ; break;
//			default:petid = e����; break;
//			}
//			Add����Enemy2(20000, petid, 129);
//		}
//		SetMusic();
//		g_StateType = STATE_FIGHT;
//		AddTriggerFightSuccess(next);
//	}
//		return true;
//	case 9:
//	{
//		SetJiangLi2(1550000, 250000, 350000, 1550000);
//
//		TalkList(7, 14, 15, 16, next);
//		//			g_pCharacter->m_PCData.AddGrowing(1);
//		//			g_pMainState->LockLv(125);
//	}
//		return true;
//	case 10:TalkList(8, 12, 3, 13, next); break;//����
//	case 11:TalkList(9, 2, 3, 4, next); break;//������
//	case 12:TalkList(10, 17, 3, 18, next); break;//����ɮ
//	case 13:AddTriggerDialog2(11, next); break;//��Ů
//	case 14:
//	{
//		cPropertyData* pPet;
//		pPet = Add����Enemy2(30000, e���޿�����, 129, eMP_��˿��, 27);
//		pPet->SuckBloodPercent.d1 += 20;
//		ePetID petid;
//		for (int i = 0; i < 7; i++)
//		{
//			switch (rand() % 4)
//			{
//			case 0:petid = e����; break;
//			case 1:petid = e��; break;
//			case 2:petid = e��Ѫ��; break;
//			default:petid = e����; break;
//			}
//			eMengPai e = petid == e���� ? eMP_���ƹٸ� : eMP_���;
//			pPet = Add����Enemy2(10000, petid, 129, e);
//			pPet->SuckBloodPercent.d1 += 30;
//		}
//		SetMusic();
//		g_StateType = STATE_FIGHT;
//		AddTriggerFightSuccess(next);
//	}
//		return true;
//	case 15:
//	{
//		SetJiangLi2(1600000, 250000, 400000, 1600000);
//
//		TalkList(12, 19, 20, 21, next);
//		// 			g_pCharacter->m_PCData.AddDefZZ(50);
//		// 			g_pCharacter->m_PCData.AddGrowing(1);
//		//			g_pMainState->LockLv(118);
//	}
//		return true;
//	case 16:TalkList(13, 22, 3, 23, next); break;//�
//	case 17:AddTriggerDialog2(14, next); break;//��̫��
//	case 18:
//	{
//		cPropertyData* pPet;
//		pPet = Add����Enemy2(30000, e������, 129, eMP_��˿��, 27);
//		pPet->HitRateOfPoison.d1 += 50;
//		pPet->SuckBloodPercent.d1 += 20;
//		ePetID petid;
//		for (int i = 0; i < 7; i++)
//		{
//			switch (rand() % 4)
//			{
//			case 0:petid = e����; break;
//			case 1:petid = e��; break;
//			case 2:petid = e��Ѫ��; break;
//			default:petid = e����; break;
//			}
//			eMengPai e = petid == e���� ? eMP_���ƹٸ� : eMP_���;
//			Add����Enemy2(20000, petid, 129, e);
//		}
//		SetMusic();
//		g_StateType = STATE_FIGHT;
//		AddTriggerFightSuccess(next);
//	}
//		return true;
//	case 19:
//	{
//		SetJiangLi2(1700000, 250000, 400000, 1700000);
//
//		TalkList(15, 19, 20, 21, next);
//		// 			g_pCharacter->m_PCData.AddDefZZ(100);
//		// 			g_pCharacter->m_PCData.AddGrowing(1);
//		//			g_pMainState->LockLv(125);
//	}
//		return true;
//	case 20:TalkList(16, 24, 3, 25, next); break;//�
//	case 21:AddTriggerDialog2(17, next); break;//��̫ү
//	case 22:
//	{
//		cPropertyData* pPet;
//		pPet = Add����Enemy2(30000, e�׾���, 138, eMP_��˿��, 27);
//		pPet->SuckBloodPercent.d1 += 20;
////		pPet->m_AtkDownDef.d1 = 2;
//		ePetID petid;
//		for (int i = 0; i < 9; i++)
//		{
//			switch (rand() % 4)
//			{
//			case 0:petid = e���޿�����; break;
//			case 1:petid = e��ħ��; break;
//			case 2:petid = e���޿��ܹ�; break;
//			default:petid = eЫ�Ӿ�; break;
//			}
//			Add����Enemy2(30000, petid, 129);
//		}
//		SetMusic();
//		g_StateType = STATE_FIGHT;
//		AddTriggerFightSuccess(next);
//	}
//		return true;
//	case 23:
//	{
//		SetJiangLi2(1800000, 300000, 400000, 1800000);
//
//		TalkList(18, 19, 20, 21, next);
//		// 			g_pCharacter->m_PCData.AddDefZZ(150);
//		// 			g_pCharacter->m_PCData.AddGrowing(1);
//		g_pMainState->LockLv(135);
//	}
//		return true;
//	case 24:TalkList(19, 5, 26, 6, next); break;//�
//	case 25:
//		TalkList(20, -1, -1, -1, -1, next);
//		break;
//	case 26:
//		Process7(0);
//		break;//��������
//#endif
	default:
		ERRBOX2(stage);
		break;

	}

	
	return true;
}
