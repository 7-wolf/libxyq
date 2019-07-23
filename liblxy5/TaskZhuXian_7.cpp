#include "_global.h"


bool TaskZhuXian::Process7(int stage)
{
int next = stage + 1;
setJobTitle("���������");
int i = 10;
int r = rand() % 20;

static int s_hadG;
switch (stage)
{
case 0:
	AddTriggerDialog("", "#Gι����ͷ����˵�����������˽䡢ɳ��������3���򸱱�������;�һ��ˣ�������������������#G#103"
		, "��~��˵��,��3��ɵ�ƣ��Ҷ������ˣ�",
		"ʲô�����������#17#4",
		"�������3ɵ��ӻ����粻���ˣ����ܹһ�����ѣ�����Խ������ͷ�����ɹ���һ���壬�˿����ȶ�ʮͶ��ǰ�ܷɽžȲеУ����ܷ�ǽ�¶��ѡ�������겻���ˣ�����ǧ���ͳ���Ӣ��������һѪ��������Ѳ���ͷ��˳���ˣ����Ͷ���ʾ����м���ǡ�������Ŀ�20Ͷ��#1",
		"���Ƿ����涨ֻ�����ʲ���ȥ����ȡ����#24",
		"������Ҳ�����ʰ�#24,");
	AddJob("#R������ʾ#R��\n#B����ɽ#B\n#R������#R\n#B������ #B\n#R�������#R\n������ðα�ӵ��ǉ�ʦͽ ");
	break;
case 1:
	AddTriggerObj("������");
	break;
case 2:

	g_pMainState->FindObjByName("������")->say("�����ɣ�ʦ����ʦ����");
	g_pHeroObj->say("#24");
	AddJob("#R������ʾ#R��\n#B����ɽ#B\n#R������#R\n#B������ #B\n#R�������#R\n�ͺ����ٴν�̸ ");
	AddTriggerObj("������", "����ɽ",_next+1);
	//break;
case 3:
{
	sNpc npc;
	npc.Set("�ǉ�", "����ɽ", e�ն���ʦ, 77, 101, DIRECTION_LEFT);
	AddTriggerObjMap(&npc, _next, false);

	npc.Set("ɯ����", "����ɽ", eɳ����, 88, 105, DIRECTION_RIGHT);
	AddTriggerObjMap(&npc, _next, false);

	npc.Set("�Ұ˽�", "����ɽ", e��˽�, 89, 99, DIRECTION_UP);
	AddTriggerObjMap(&npc, _next, false);
	npc.Set("������", "����ɽ", e����, 99, 104, DIRECTION_UP);
	AddTriggerObjMap(&npc, _next, false);
}
	g_pMainState->FindObjByName("�ǉ�")->say("ʬ�������#52");
	g_pMainState->FindObjByName("ɯ����")->say("��ʦ�������������#52");
	g_pMainState->FindObjByName("�Ұ˽�")->say("�����ã����ʺ���أ�#52");
	AddTriggerObj("������", "����ɽ", _next + 1);
	break;
case 4:
	AddTriggerDialog(
		"������ûƭ��ɣ�������Ҳ��",
		"�ɶ�,���������ðα�Ӳ�Ʒ��#54",
		"�б������ٰ�#4",
		"�������ǲ����ײĲ����ᰡ��",
		"���Ǵ��������µİ�,ɵ��!�԰�����һ��#4",
		"�ź����#2");
	AddJob("#R������ʾ#R��\n#B����ɽ#B\n#R������#R\n#B������ #B\n#R�������#R\n������ðα�ӵ��ǉ�ʦͽ ");
	break;
case 5:
{

	auto pc = AddEnemy(990000, e�����, 69, eMP_ʨ����, "������");
	pc->getObj()->say("#17���յģ�û�����£���������#2");
	pc->DmgAdd.d1 += 0x1fff;
	AddEnemy(15000, e��˽�, 60, eMP_���, "�Ұ˽�");
	AddEnemy(15000, eɳ����, 60, eMP_���, "ɯ����");
	AddEnemy(15000, e����, 60, eMP_���, "������");
	AddEnemy(15000, e�ն���ʦ, 60, eMP_���, "�ǉ�");
	auto p = AddEnemy(15000, 2000 + rand() % 16, 160, eMP_���, "�Թ�Ⱥ��");
	p->getObj()->say("#Rɧ�꣬�����Ĳ�Ҫ����ν������#R");
	g_StateType = STATE_FIGHT;
	AddTriggerFightSuccess(_next);
	AddTriggerFightEscape(_next);
	AddTriggerFightEscape(_next);
	break;
}
	//return TRUE;
case 6:
	AddTriggerDialog("",
		"#G����ӳɾ��ˣ���ô������������ȥ���¹������̰���æ��#103"
		, "��Զ�㣬��Ȼ�������");
	g_pHeroObj->say("#24");
	AddJob("#R������ʾ#R��\n#B������#B\n#R������#R\n#B���� #B\n#R�������#R\n��ȹ��� ");

	break;
case 7:
	AddTriggerObj("�������","������");
	break;
case 8:
	AddTriggerDialog("�������㿴����ô��",
		"#G�������̣�����ɽ�ĺ�ͷ���ϸ�����������������ô��#103"
		, "�����ɶ����������#4���㻹�벻��������̫��",
		"#G#4,�Բ���һʱ���󣬹��������а취�����#G",
		"#G����ɽ�Ǹ�����Ǽٵ�,������ȥ����������������#103#G",
		"#G����ҽ������,�������ֱܷ���#1#G",
		"#G�����,��ѹ�����ѧ��30��������.Ŷ����,�㲻�����ӵ���,�ͳ���ʵ�ڶԲ�����ڣ��Ǿͱ�����,���ȥ��#28#G",
		"#G����ô����ô������#71");
	AddJob("#R������ʾ#R��\n#B��������#B\n#R������#R\n#B� #B\n#R�������#R\n����������� ");
	break;

case 9:
	AddTriggerObj("�", "��������");
	break;
case 10:
	AddTriggerDialog("�������������ˣ����������¸Ľ���������",
		"#G�Һܺ����������ʲô�߿Ƽ����⣬�ѵ��ᷢ��Ⲩ��#G",
		"��û�ﵽ���̶ֳȣ�ֻ������������ʶ��AR�������Ը��ֶ��ﶼ��Ч",
		"#G#4��ô������������24##G",
		"#G�������������ǲ��ǳ�����һͷ��#1#G",
		"#G�����������������������#4#G",
		"#G����������Ц���ˣ����ž���ȥ����������#28#G",
		"#Gлл������#71");
	AddJob("#R������ʾ#R��\n#B����ɽ#B\n#R������#R\n#B������ #B\n#R�������#R\n���������ֱ��ðα�ӵ������ ");
	getTag("��õ���������");
	break;

case 11:
	AddTriggerObj("������", "����ɽ");
	break;
case 12:
	getTag("�����ž��Ӷ�������������");
	g_pHeroObj->say("�����Ȼ����ģ�������һ�����Ǽٵ��ޡ�");
	AddJob("#R������ʾ#R��\n#Bˮ����#B\n#R������#R\n#B������ #B\n#R�������#R\nȥˮ�����Ҽٵ������� ");
	AddTriggerObj("������", "ˮ����", _next);
	break;
case 13:
	AddTriggerDialog(
		"ʲô�ˣ������ž������Ҹ�ʲô",
		"����,�����ʥ��Ҳ�Ҽ�ð,�ϴ�����Ϊ��û�㼼��,��������ʶ��ʶ�ҵ�����#4",
		"ס��,�Ҳ������������.....",
		"��������һ�վ�֪����", "",
		"��?�����ȻҲ�����......������������������û�ð�.��֮�ȰѾ��ӻ�����������",
		"#2");
	AddJob("#R������ʾ#R��\n#B��������#B\n#R������#R\n#B� #B\n#R�������#R\n���˵������������ ");
	break;

case 14:
	AddTriggerObj("�", "��������");
	break;
case 15:
	AddTriggerDialog("",
		"#G������������������ǲ��ǽֱ�2��Ǯ�������İ�#103",
		"��˵�������Ŀ���о��˼�Сʱ��������",
		"�Բۣ��ֲ���������ô��",
		"û�뵽��������Ȼ��������û��....�����ҵ��ÿƼ�����̫���Ͼ����Ƽ����˰�#8",
		"����ô�찡#74",
		"�ز���������Ҳ�ֱܷ�����,����ȥ������" );
	AddJob("#R������ʾ#R��\n#B�ز�����#B\n#R������#R\n#B�ز��� #B\n#R�������#R\n�ҵز�����æ ");
	break;
case 16:
	AddTriggerObj("�ز���", "�ز�����");
	break;
case 17:
	AddTriggerDialog(
		"���ź�,����Ҳ�ֱ粻��.������ȥ�ҹ���,�������������ͱ��Ҵ�#3",
		"����˵��֮ǰ����������.....",
		"������ô˵������������;ʹ����鲻�����;�С",
		"#24���������ֲ���",
		"����˵���������˿����ÿ��������;ͱȽϴ���",
		"#24�ðɣ���������֮ǰ�������̵�Ե��",
		"�㻹�������Ǹ��漣#24");
	AddJob("#R������ʾ#R��\n#B������#B\n#R������#R\n#B���� #B\n#R�������#R\n������ҽ��֮�� ");
	break;
case 18:
	AddTriggerObj("�������", "������");
	break;

case 19:
	AddTriggerDialog("����ô�����ˣ��������������Ҳ��뿴����",
		"#G��ѽ���Բ��������������ɰ����������ʣ��˼��˰������䳵�ء����������Ĺ������������#103",
		"�ף����ӿɽ�Ŷ������3�գ�Ӧ����Ŀ�࿴Ŷ����������ȡ��·�ϵĽ���,������͸����ҽ���.�Ұ����������ֱܹ�����#1",
		"�Բۣ�����֮ǰ��ô������˵",
		"#4�����֮ǰ���������̣�����Ƕ���ĳͷ���Ҳ����Ľ���",
		"����ô�찡��",
		"�Ҷ�˵���ǽ�����#24" );
	AddJob("#R������ʾ#R��\n#B����ɽ#B\n#R������#R\n#B���ܹ� #B\n#R�������#R\n�Һ���Ҫ���� ");
	break;

case 20:
	AddTriggerObj("���ܹ�", "����ɽ");
	break;

case 21:
	AddTriggerDialog(".......����,ʱ��̫��,�Ҿ�Ȼ�������ǹ��������ҵ���.",
		"#G�������룬�������ˣ�#103",
		"��Ů�������ǳ���Ҫ��������,��һ���Ͱ��⵱�������������#17",
		"������ɺܺ���#8��ȥ������#3",
		"Ҫ����Լ�ȥ���ͳ�ȥ�Ķ�������ô����ô��Ҫ����Ҫ������",
		"�ðɣ�ֻ�п����Լ���#24");
	AddJob("#R������ʾ#R��\n#B����ɽ#B\n#R������#R\n#B��Ů���� #B\n#R�������#R\n����Ů�����ֻؽ��� ");
	break;
case 22:
	AddTriggerObj("��Ů����", "����ɽ");
	break;
case 23:
	AddTriggerDialog("",
		"#G��Ů����,���������˹�����Ǹ��㣬��������Ǻ��ܹ��������㱣�ܵ�,���ܹ������Ӳ���ʹ���˲Ű��⵱���������,���ڹ������Ҫ�ջؽ�����.ϣ�����ܻ�����.",
		"����������ڱ��������,���Ǳ�������,˭Ҳ��������#90���������ҲҪ��#1",
		"�㲻Ҫ��ô��Ƥ�ò������ܹ�˵,����������һ�����õĸ���,��Ϊ����#17",
		"�ú��ְܹ��Ǹ����õĸ���������,�������ܴ󷽵�#3",
		"�����Ǳ��Ҷ�����#24�Ҵ�������Ů��,��������ƽ�#3(<--֮ǰ���Ǵ���������,��ʥ����,��������#74)");

	break;

case 24:
{
	auto pc = AddEnemy(47000, eС��Ů, 75, eMP_����ɽ, "��Ů����");
	pc->getObj()->say("#17��Ȼ���۸���������ƮƮȭ����#2");
	AddEnemy(40000, e����, 65, eMP_���, "����ආ�");
	AddEnemy(40000, e����, 65, eMP_���, "����ආ�");
	AddEnemy(40000, e����, 65, eMP_���, "����ආ�");
	AddEnemy(40000, eз��, 65, eMP_���, "з��ආ�");
	AddEnemy(40000, e����, 65, eMP_���, "����ආ�");
	AddEnemy(40000, e��ة��, 65, eMP_���, "��ة��ආ�");
	AddEnemy(40000, e��ة��, 65, eMP_���, "��ة��ආ�");
	AddEnemy(40000, e��ة��, 65, eMP_���, "��ة��ආ�");
	AddEnemy(40000, eϺ��, 65, eMP_���, "Ϻ��ආ�");
	g_StateType = STATE_FIGHT;
	AddTriggerFightSuccess(_next);
	break;
}

case 25:
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
	AddTriggerObj("��ҽ��", "����ɽ", _next );
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
			g_pMainState->awardk(666, 6666);//60W���飬100WǮ
		}
	}
	else if (r < 20)
	{
		if (!g_pMainState->awardBookIron(10 * rand() % 6))
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
	AddTag("���<���������>����");
//	AddJob("#R������ʾ#R���������񵽴˽����������ĵȴ�����");
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


#if 0
	case 0:
		g_GlobalValues[4] = 50;
		g_GlobalValues[6] = 12;
		g_GlobalValues[5] = 10;
		SetChapter(7);
		g_pMainState->SetDialogListPet(m_Textlist[1], e��˽�);
		TalkList(0, 6, 3, 7, 3); break;
		break;
	case 3:
		g_pMainState->m_DialogList.clear();
		TalkList(3, 8, 3, 9, next); break;//����ɽ����
	case 4:TalkList(4, 10, 11, 12, next); break;//������
	case 5:AddTriggerDialog2(5, 6); break;//���ȹ���
	case 6:
	{
		g_pMainState->m_Map.LoadMap(21, 46, m_Textlist[13].c_str(), 0);
		g_pHeroObj->Set(POS_DEAD, 0);
		TalkList(6, 14, 15, 16, next);


		AddTriggerObjMap2(35, 15, e�������, 14, 15, 3, 7);
		AddTriggerObjMap2(33, 15, e�ն���ʦ, 10, 14, 3, 7);
		AddTriggerObjMap2(34, 15, e������ʦ, 28, 8, 7, 7);
	}
		break;//������
	case 7://��Ԫ����
		if (CheckINT(12, 3))
		{
			g_pMainState->SetDialogListPC(m_Textlist[32], 9);
			AddTriggerDialog2(7, -7);
		}
		else
			AddTriggerDialog2(28, -7);
		break;
	case -7://��������

	{
		g_pMainState->ClearDialogList();
		cPropertyData* pPet;
		pPet = Add����Enemy2(3000, e��Ԫ����, 60, eMP_��ׯ��);
		pPet->HitRateOfSeal.d1 += 50;
		pPet->HitRateOfSeal.d2 += 50;
		pPet->DmgPercent.d2 += 9990;
		pPet->DmgPercentOfMagic.d2 += 9990;
		pPet->DmgPercentOfArm.d2 += 99;
		pPet->DmgPercentOfFix.d2 += 90;
		pPet->m_XiuLian.Set(30, 30, 30, 30);
		pPet = Add����Enemy2(3000, e������ʦ, 60, eMP_����ɽ);
		pPet->HitRateOfSeal.d1 += 50;
		pPet->HitRateOfSeal.d2 += 50;
		pPet->DmgPercent.d2 += 9990;
		pPet->DmgPercentOfMagic.d2 += 9990;
		pPet->DmgPercentOfArm.d2 += 99;
		pPet->DmgPercentOfFix.d2 += 90;
		pPet->m_XiuLian.Set(30, 30, 30, 30);
		pPet = Add����Enemy2(3000, e�ն���ʦ, 60, eMP_������, 33);
		pPet->DmgPercentOfCure.d1 += 50;
		pPet->DmgPercent.d2 += 9990;
		pPet->DmgPercentOfMagic.d2 += 9990;
		pPet->DmgPercentOfArm.d2 += 99;
		pPet->DmgPercentOfFix.d2 += 90;
		pPet->m_XiuLian.Set(30, 30, 30, 30);
		pPet = Add����Enemy2(3000, e�������, 60, eMP_����ɽ);
		pPet->DmgPercentOfCure.d1 += 50;
		pPet->DmgPercent.d2 += 9990;
		pPet->DmgPercentOfMagic.d2 += 9990;
		pPet->DmgPercentOfArm.d2 += 99;
		pPet->DmgPercentOfFix.d2 += 90;
		pPet->m_XiuLian.Set(30, 30, 30, 30);
		if (CheckINT(12, 3))
		{
			AddPCEnemy2(30000, 9, 0, 120, eMP_��ׯ��, 32);
		}
		pPet = AddPetEnemy2(8000, e��������, 100);
		pPet->RelifeRate.d1 = 130;
		pPet = AddPetEnemy2(8000, e�����˲�����, 100);
		pPet->RelifeRate.d1 += 90;
		ePetID petid;
		for (int i = 0; i < 4; i++)
		{
			switch (rand() % 3)
			{
			case 0:petid = e�����޺�; break;
			case 1:petid = e���Ů�; break;
			default:petid = e��«����; break;
			}
			Add����Enemy2(8000, petid, 100);
		}
		SetMusic("Lacrimosa");
		g_StateType = STATE_FIGHT;
		AddTriggerFightSuccess(-6);
	}
		return true;
	case -6:

	{

		RemoveTriggerObjMap();
		g_pMainState->m_Map.RemoveAllNpc();
		SetJiangLi2(2000000, 500000, 500000, 2000000);

		TalkList(23, 10, 11, 12, 8);
		////////////////////////////////////////////////////////////////////////// �Ǻ��� �����ӳ�
		g_GlobalValues[14] += 200;
		g_GlobalValues[15] += 200;
//		g_pCharacter->m_PcData.GetShangPinPet(1);
		// 			g_pCharacter->m_PCData.AddGrowing(1);
		// 			g_pCharacter->m_PCData.AddHpZZ(800);
		// 			g_pCharacter->m_PCData.AddAtkZZ(200);
		// 			g_pCharacter->m_PCData.AddAvoidZZ(200);
		//			g_pMainState->LockLv(132);
	}
		return true;

	case 8:AddTriggerDialog2(8, next); break;//���ȹ���
	case 9:

	{
		cPropertyData* pPet;
		pPet = Add����Enemy2(50000, e��ӿ����, 148, eMP_ħ��կ, 10);
		pPet->DmgPercent.d2 += 10;
		ePetID petid;
		for (int i = 0; i < 7; i++)
		{
			switch (rand() % 4)
			{
			case 0:petid = e��������; break;
			case 1:petid = e����; break;
			case 2:petid = e���޿��ܹ�; break;
			default:petid = e���޿�����; break;
			}
			Add����Enemy2(20000, petid, 129);
		}
		SetMusic("��Ӱ��Ե");
		g_StateType = STATE_FIGHT;
		AddTriggerFightSuccess(next);
	}
		return true;
	case 10:

	{
		SetJiangLi2(2100000, 500000, 500000, 2100000);

		TalkList(9, 6, 3, 7, next);
		//			g_pCharacter->m_PCData.AddGrowing(1);
		//			g_pMainState->LockLv(135);
	}
		return true;
	case 11:TalkList(10, 17, 18, 19, next); break;//���ع���
	case 12:AddTriggerDialog2(11, next); break;//���ȹ���
	case 13:

	{
		AddTriggerDialog2(29);
		Add����Enemy2(50000, e������ţ, 148, eMP_ħ��կ, 17);
		AddPCEnemy2(50000, 2005, 0, 148, eMP_ħ��կ, 52);
		ePetID petid;
		for (int i = 0; i < 6; i++)
		{
			switch (rand() % 4)
			{
			case 0:petid = e������; break;
			case 1:petid = e��ħ��; break;
			case 2:petid = e̤����; break;
			default:petid = e������; break;
			}
			Add����Enemy2(20000, petid, 138);
		}
		SetMusic();
		g_StateType = STATE_FIGHT;
		AddTriggerFightSuccess(next);
	}
		return true;
	case 14:

	{

		SetJiangLi2(2200000, 9999999, 600000, 2200000);

		TalkList(12, 20, 21, 22, next);
		//			g_pCharacter->m_PCData.AddGrowing(1);
		//			g_pMainState->LockLv(140);
	}
		return true;
	case 15://����

	{
		TalkList(13, 10, 11, 12, next);
		g_pCharacter->UseCard(133);
	}
		break;
	case 16:TalkList(14, 6, 3, 7, next); break;//���ȹ���
	case 17://����ɽ����

	{
		g_pCharacter->UseCard(-1);
		TalkList(15, 10, 11, 12, next);
	}
		break;
	case 18:TalkList(16, 23, 3, 24, next); break;//���ȹ���
	case 19:TalkList(17, 25, 26, 27, next); break;//ţ����
	case 20:
		SetDialogList(25);
		TalkList(18, 17, 18, 19, next); break;//���湫��
	case 21:AddTriggerDialog2(19, next); break;//ţħ��
	case 22:

	{
		cPropertyData* pPet;
		pPet = Add����Enemy2(50000, eţħ��, 159, eMP_ħ��կ);
		pPet->MagicFire.d2 += 30;
		pPet = Add����Enemy2(50000, e���꾫, 148, eMP_��˿��, 25);
		pPet->AddSkill(ePS_��������);
		ePetID petid;
		for (int i = 0; i < 6; i++)
		{
			switch (rand() % 4)
			{
			case 0:petid = e��ħ��; break;
			case 1:petid = e̤����; break;
			case 2:petid = e��«����; break;
			default:petid = e������; break;
			}
			Add����Enemy2(20000, petid, 138);
		}
		SetMusic();
		g_StateType = STATE_FIGHT;
		AddTriggerFightSuccess(next);
	}
		return true;
	case 23:

	{
		AddTriggerDialog2(20, next);
	}
		break;
	case 24:

	{
		cPropertyData* pPet;
		pPet = Add����Enemy2(50000, e�������, 148, eMP_��˿��, 25);
		pPet->AddSkill(ePS_�߼���������);
		pPet = Add����Enemy2(50000, e��ɫ¹, 159, eMP_���ƹٸ�);
		pPet->AddSkill(ePS_�߼������);
		ePetID petid;
		for (int i = 0; i < 8; i++)
		{
			switch (rand() % 4)
			{
			case 0:petid = eè��; break;
			case 1:petid = e��; break;
			case 2:petid = eè����; break;
			default:petid = e����; break;
			}
			Add����Enemy2(30000, petid, 138);
		}
		SetMusic();
		g_StateType = STATE_FIGHT;
		AddTriggerFightSuccess(next);
	}
		return true;
	case 25:

	{
		SetJiangLi2(2500000, 600000, 800000, 2500000);

		TalkList(21, 10, 11, 12, next);
		g_pMainState->ClearDialogList();
		g_GlobalValues[14] += 200;
		g_GlobalValues[15] += 200;
		// 			g_pCharacter->m_PCData.AddMagZZ(150);
		// 			g_pCharacter->m_PCData.AddGrowing(1);
		// 			g_pCharacter->m_PCData.AddHpZZ(500);
		g_pMainState->LockLv(145);
	}
		return true;
	case 26:
		g_pMainState->SetDialogListPet(m_Textlist[1], e��˽�);
		TalkList(22, -1, -1, -1, -1, -26); break;//���ȹ���
	case -26:
		g_pMainState->m_DialogList.clear();
		//Process9(0);
		g_pMainState->m_TaskHuoDong.Start(���ɴ���);
		g_pMainState->m_TaskHuoDong.SetTrigger(this, 27, 12);
		return true;
	case 27:
		g_pMainState->LockLv(155);
		TalkList(24, 36, 37, 38, 28, -27);
		return true;
	case -27:

	{
		//			int id;
		Un����(m_Textlist[39]);
		Un����(m_Textlist[40]);
		// 			id = g_pMainState->m_Friend.FindFriend("����");
		// 			g_pMainState->m_Friend.m_FriendList[id].m_dataFileName = "����3";
		// 			id = g_pMainState->m_Friend.FindFriend("ɵ�");
		// 			g_pMainState->m_Friend.m_FriendList[id].m_dataFileName = "ɵ�2";
		Invite(m_Textlist[41]);
		Invite(m_Textlist[42]);
	}
		return true;
	case 28:

	{
		cPropertyData* pPet;
		pPet = Add����Enemy2(80000, e���, 169, eMP_ʨ����);
		pPet->SetJinJie(0);
		pPet->LiveRestoreRate += 100;
		pPet->HitRateOfSeal.d2 += 30;
		pPet->ParryRate.d1 += 20;
		pPet->CriRate.d1 += 20;
		pPet->DmgPercent.d1 += 30;
		pPet->SuckBloodPercent.d1 += 30;
		pPet->CounterRate.d1 += 100;
		pPet->StabRate.d1 += 100;
		pPet->StabPercent.d1 += 20;
		pPet->StabRateOfMagic.d1 += 100;
		pPet->StabPercentOfMagic.d1 += 50;
		ePetID petid;
		eMengPai e;
		for (int i = 0; i < 7; i++)
		{
			switch (rand() % 4)
			{
			case 0:petid = e���޿��ܹ�; e = eMP_���ܵظ�; break;
			case 1:petid = e�ֹ�Ѳ��; e = eMP_������; break;
			case 2:petid = e����ͯ��; e = eMP_����ɽ; break;
			default:petid = e���ӻ���; e = eMP_���; break;
			}
			Add����Enemy2(30000, petid, 159, e);
		}
		SetMusic("ս��BOSS");
		g_StateType = STATE_FIGHT;
		AddTriggerFightSuccess(next);
	}
		return true;
	case 29:

	{
		SetJiangLi2(2800000, 800000, 1000000, 2800000);

		TalkList(25, -1, -1, -1, -1, 30);
		// 			g_pCharacter->m_PCData.AddGrowing(5);
		// 			g_pCharacter->m_PCData.AddAtkZZ(200);
		// 			g_pCharacter->m_PCData.AddDefZZ(100);
		// 			g_pCharacter->m_PCData.AddMagZZ(200);
		// 			g_pCharacter->m_PCData.AddHpZZ(1000);
		// 			g_pCharacter->m_PCData.AddSpdZZ(100);
		// 			g_pCharacter->m_PCData.AddAvoidZZ(100);

		//			g_pMainState->LockLv(160);
	}
		return true;
	case 30:

	{
		Un����(m_Textlist[41]);
		Un����(m_Textlist[42]);
		Un����(m_Textlist[43]);
		Un����(m_Textlist[44]);
		AddTriggerObjMap2(46, 45, 2000, 17, 13, 3);
		AddTriggerObjMap2(39, 45, 2010, 24, 12, 9);
		AddTriggerObjMap2(47, 45, 2001, 30, 10, 8);
		g_pMainState->m_Map.LoadMap(29, 12, m_Textlist[45].c_str(), 0);
		g_pHeroObj->Set(POS_DEAD, 0);
		TalkList(26, -1, -1, 51, -1, 31);
	}
		return true;
	case 31:

	{
		g_pMainState->m_Map.RemoveAllNpc();
		RemoveTriggerObjMap();
		Invite(m_Textlist[46]);
		Invite(m_Textlist[47]);
		g_pMainState->FindObj();
		AddTriggerObjMap2(49, 50, 2013, 84, 37, 7, 32);
		AddTriggerObjMap2(48, 50, 2008, 79, 41, 3, 32);
	}
		return true;
	case 32:

	{
		TalkList(27, -1, -1, -1, -1, 33);
		RemoveNpc(48);
		RemoveNpc(49, true);
		// 			int id = g_pMainState->m_Friend.FindFriend("���");
		// 			g_pMainState->m_Friend.m_FriendList[id].m_dataFileName = "���2";
		Invite(m_Textlist[48]);
		Invite(m_Textlist[49]);
		g_pMainState->FindObj();
	}
		return true;
	case 33:
		Process9(0);
		return true;
#endif
	default:
		ERRBOX2(stage);
		break;
	}


	return true;
}

