#include "_global.h"


bool cTaskZhiXian::Process(int stage)
{

	switch (m_Chapter)
	{
	case 0:return Process0(stage);
	case 2:return Process2(stage);
	case 3:return Process3(stage);
	case 4:return Process4(stage);
	case 6:return Process6(stage);
	default:return Process1(stage);
	}
}


bool cTaskZhiXian::Process0(int stage)
{
	int r = rand() % 100;
	switch (stage)
	{
	case -1:return true;
// 	case 0://����Ұ��
// 	{
// 		return false;
// 		int& num = g_pMainState->m_GlobalButton[11];
// 		if (num & 0x01)return true;
// 		AddTriggerDialog2(0, 1);
// 	}
// 		break;
// 	case 1:
// 		Select(2, 1, -1, 3, 2, 4, -1); break;
// 	case 2:
// 
// 	{
// 		sItem2* pItem = FindItem(28, 23);
// 		if (pItem)
// 		{
// 			pItem->m_Num = 0;
// 			SetINT(11, 0);
// 			sShangPinPet pet;
// 			sAddPoint point;
// 			point.Set(0, 0, 4, 1, 0);
// 			pet.Set(e������, &point);
// 			pet.m_zizhi.mag = 4800;
// 			pet.m_zizhi.speed = 1700;
// 			pet.m_zizhi.hp = 9700;
// 			pet.m_zizhi.grow = 150;
// 			pet.AddSkill(ePS_������);
// 			pet.AddSkill(ePS_�׻�);
// 			pet.AddSkill(ePS_�߼�ħ֮��);
// 			pet.AddSkill(ePS_�߼���������);
// 			pet.AddSkill(ePS_�߼���������);
// 			pet.AddSkill(ePS_�߼�����);
// 			pet.AddSkill(ePS_�߼�������);
// 			pet.AddSkill(ePS_�߼����Ӹ���);
// 			pet.AddSkill(ePS_�߼�����);
// 			pet.AddSkill(ePS_�����ػ�);
// 			pet.AddSkill(ePS_�߼�����);
// 			pet.AddSkill(ePS_�߼��м�);
// 			pet.AddSkill(ePS_�߼�����);
// //			pet.AddSkill(ePS_�߼�����);
// 			pet.AddSkill(ePS_�߼��۸�);
// 			pet.AddSkill(ePS_�߼�ڤ˼);
// 			pet.AddSkill(ePS_�ƻ���ľ);
// 			GetPet2(&pet, 100);
// 		}
// 	}
// 		break;
// 	case 3://������
// 		if (g_pCharacter->m_PcData.m_Money[0] < 2000)
// 		{
// 			AddTriggerDialog2(2);
// 			SetJiangLi2(0, 2000);
// 		}
// 		else AddTriggerDialog2(3);
// 		break;
 		////////////////////////////////////////////////////////////////////////// ����Ի�Ҫ�ĳɡ����족
	case 4:
	{
		g_pMainState->m_TriggerDialog.AddSelect(this, "ֻҪ������,�ҿ��԰������װ��", 5);
		break;
		g_pMainState->m_TriggerDialog.AddSelect(this, "ֻҪ������,�ҿ��԰������װ��", "������", -1,
			"ȷ��", 5,
			"ȡ��", -1);
		break;
		Select(6, 5, -1, 3, 5, 4, -1); break;//����
	}
	case 5:	
		// �ǣ����첻Ҫ? Ҫ
		g_pMainState->m_Dazao.m_MoneyNeed = 1;
		g_pMainState->m_Dazao.OnOff(true); 
		break;
	case 6:
//		if (g_pCharacter->m_PcData.m_BangPaiID == -1)
// 		{
// 			TalkList(4, -1, -1, -1, -1);
// 		}
//		else 
//		Select(8, 7, -1, 3, 7, 4, -1);
		g_pMainState->m_TriggerDialog.AddSelect(this, "�ҿ�������ذ���", 7);
		break;
		return true;
	case 7:
		g_pMainState->m_Map.LoadMap(124, 115, "����", 0);
		break;
// 	case 8://��᪴���
// 		if (!CheckINT(11, 1))
// 		{
// 			for (int i = 0; i < 5; i++)
// 			{
// 				auto p = AddPetEnemy2(99999, e��������, 169, 9);
// 				p->SetJinJie(3);
// 				p->Atk.AddDataAddPercent(35);
// 				p->CriRate.d1 += 30;
// 			}
// 			SetMusic(m_Textlist[9]);
// 			g_StateType = STATE_FIGHT;
// 			AddTriggerFightSuccess(9);
// 		}
// 		else AddTriggerDialog2(5);
// 		return true;
// 	case 9: //
// 	{
// 		SetJiangLi2(5000000, 300000, 500000, 1000000, true);
// 		SetJiangLiItem(23, 24);
// 		AddTriggerDialog2(5);
// 		SetINT(11, 1);
// 		g_pMainState->m_GlobalButton[14] += 200;
// 		g_pMainState->m_GlobalButton[15] += 200;
// // 		g_pCharacter->m_PCData.AddGrowing(5);
// // 		g_pCharacter->m_PCData.AddAtkZZ(100);
// // 		g_pCharacter->m_PCData.AddDefZZ(100);
// 	}
// 		return true;
	case 10:
		// 		if (g_pMainState->m_State.CheckAddPoint())
		// 		{
		// 			Select(12, 10, -1, 3, 12, 4, -1);
		// 		}
		// 		else
		// 		{
		// 			Select(11, 10, -1, 3, 11, 4, -1);
		// 		}
		g_pMainState->m_FangWu.SetGuiMo(1);
		g_pMainState->m_Tags.Add("���ݹ�ģ����Ϊ1");
		return true;
	case 11:
		//		g_pMainState->m_State.switchAddPoint();
		g_pMainState->m_FangWu.SetGuiMo(2);
		g_pMainState->m_Tags.Add("���ݹ�ģ����Ϊ2");
		return true;
	case 12:

	{
		//			g_pCharacter->m_PCData.ResetAddPoint(false);
		//			g_pMainState->m_State.switchAddPoint();
	}
		g_pMainState->m_FangWu.SetGuiMo(3);
		g_pMainState->m_Tags.Add("���ݹ�ģ����Ϊ3");
		return true;
	case 13:
	{
// 		if (g_pMainState->m_FangWu.GetGuiMo() > 3)
// 		{
// 			AddTriggerDialog2(6);
// 			return true;
// 		}
// 		ostringstream oss;
// 		oss << "��ǰ���ݹ�ģΪ";
// 		oss << g_pMainState->m_FangWu.GetGuiMo();
// 		oss << "������Ҫ";
// 		oss << (g_pMainState->m_FangWu.GetGuiMo() + 1) * 200;
// 		oss << "��,��Ҫ��?";
// 		g_pMainState->m_TriggerDialog.AddSelect(this, oss.str(), g_pMainState->m_pNowSelect->m_TrueName.GetString(), -1,
// 			m_Textlist[3], 14,
// 			m_Textlist[4], -1
// 			);

		g_pMainState->m_TriggerDialog.AddSelect(this, toString("��ǰ���ݹ�ģΪ: %d", g_pMainState->m_FangWu.GetGuiMo()), 
			g_pMainState->m_pNowSelect->m_TrueName.GetString(), -1,
			"���Ĺ�ģΪ 1", 10,
			"���Ĺ�ģΪ 2", 11,
			"���Ĺ�ģΪ 3", 12,
			"���Ĺ�ģΪ 4", 14);
	}
		return true;
	case 14:
		g_pMainState->m_FangWu.SetGuiMo(4);
		g_pMainState->m_Tags.Add("���ݹ�ģ����Ϊ4");
		return true;
	case 15:
	      {
		
		
			  {//1
				  auto objSelect = g_pMainState->m_pNowSelect;
				  if (1)
				  {
					  auto pc = AddEnemy(150000, 2000+rand()%16, cct::MaxRoleLv, eMP_��������, "���²�", nullptr, 160);
					  pc->AddSkill(ePS_�߼���������);
					  pc->AddSkill(ePS_�߼���������);
					  pc->AddSkill(ePS_�߼���������);
					  pc->AddSkill(ePS_�߼�ħ֮��);
					  pc->AddSkill(ePS_�߼�������);
					  pc->AddSkill(ePS_���Ӹ���);
					  pc->AddSkill(ePS_�߼�����);
					  pc->AddSkill(ePS_�߼�����);
					  pc->AddSkill(ePS_�߼�����);
					  pc->AddSkill(ePS_�߼�����);
 //					  pc->LiveRestoreRate += 50;
 					  pc->HitRateOfSeal.d2 += 30;
 					  pc->CounterRate.d1 += 100;
 					  pc->StabRate.d1 += 300;
 					  pc->StabPercent.d2 += 100;;
 					  pc->StabRateOfMagic.d1 += 100;
 					  pc->StabPercentOfMagic.d1 += 50;
					  pc->m_XiuLian.AddXiuLianLv(30, eXLMAG);
// 					  pc->Pierce�̴�.d2 += 120;
// 					  pc->DmgPercentOfMagic.d1 += 333;
// 					  pc->DmgPercentOfMagic.d2 += 333;
 					  pc->Pierce�̴�OfMagic.d1 += 50;
// 					  pc->Pierce�̴�OfMagic.d2 += 164;
// 					  pc->DmgPercent.d2 += 80;
// 					  pc->Pierce�̴�.d1 += 120;
// 					  pc->DmgPercent.d2 += 89;
					  g_pMainState->SetRanse(10, 5, 2, 1, 3);
					  pc->getObj()->say("#1���꣬��Ӯ�����벻�����ջ�Ŷ#18");
					  g_pMainState->m_ColorManage.Give2(&pc->m_RanSe.m_ranse[0], pc->modeid);
					  
				  }
				 
		{//2
			cPropertyData* Pet;
			Pet = AddEnemy(100000, 2000 + rand() % 16, 160, eMP_���ƹٸ�, "������", nullptr, 160);
			Pet->m_XiuLian.AddXiuLianLv(30, eXLATK);
//			Pet->DmgPercent.d2 += 110;//��������
			Pet->SuckBloodRate.d1 += 100;//��Ѫ��
			Pet->SuckBloodPercent.d1 += 100;//��Ѫ��
// 			Pet->DmgPercentOfMagic.d2 += 99;
 			Pet->Pierce�̴�.d1 += 80;
// 			Pet->DmgPercent.d2 += 59;
// 			Pet->Pierce�̴�.d2 += 59;
// 			Pet->DmgPercentOfMagic.d2 += 59;
// 			Pet->Pierce�̴�OfMagic.d2 += 59;
// 			Pet->DmgPercentOfFix.d2 -= 32;
			g_pMainState->SetRanse(11, 5, 2, 1, 3);
			g_pMainState->m_ColorManage.Give2(&Pet->m_RanSe.m_ranse[0], 2000);
		}
	{//3
		cPropertyData* Pet;
		Pet = AddEnemy(100000, 2000 + rand() % 16, 160, eMP_������, "������", nullptr, 160);
		Pet->m_XiuLian.AddXiuLianLv(30, eXLDEF);
//		Pet->DmgPercent.d2 += 110;
//		Pet->Pierce�̴�.d2 += 110;
//		Pet->DmgPercentOfMagic.d2 += 110;
//		Pet->Pierce�̴�OfMagic.d2 += 110;
//		Pet->DmgPercentOfFix.d2 -= 32;
		Pet->DmgPercentOfCure.d1 += 100;
		Pet->CriRateOfCure.d1 += 30;
		g_pMainState->SetRanse(12, 4, 2, 3, 3);
		g_pMainState->m_ColorManage.Give2(&Pet->m_RanSe.m_ranse[0], 2000);
	}


	{//4
		cPropertyData* Pet;
		Pet = AddEnemy(100000, 2000 + rand() % 16, 160, eMP_�貨��, "������", nullptr, 160);
//		Pet->m_XiuLian.AddXiuLianLv(20, eXLATK);
//		Pet->DmgPercent.d2 += 140;//������ķ����͹���
//	    Pet->MagicWater.d2 += 30;//ˮ����
		Pet->Pierce�̴�.d1 += 40;
//		Pet->DmgPercentOfMagic.d1 += 28;
//		Pet->DmgPercentOfMagic.d2 += 64;
//		Pet->Pierce�̴�OfMagic.d1 += 120;
//		Pet->Pierce�̴�OfMagic.d2 += 166;
		g_pMainState->SetRanse(13, 4, 2, 3, 3);
		g_pMainState->m_ColorManage.Give2(&Pet->m_RanSe.m_ranse[0], 2000);
	}


	{//5
		auto pc = AddEnemy(100000, 2000 + rand() % 16, 160, eMP_��ׯ��, "��������", nullptr, 160);
//		pc->m_XiuLian.AddXiuLianLv(19, eXLATK);
		pc->AddSkill(ePS_�߼������);
		pc->HitRateOfSeal.d1 += 85;
		pc->HitRateOfSeal.d2 +=85;
//		pc->DmgPercentOfMagic.d2 += 99;//����
//		pc->Pierce�̴�OfMagic.d2 += 99;//����
		g_pMainState->SetRanse(14, 1, 2, 3, 3);
		pc->getObj()->say("#24");
		g_pMainState->m_ColorManage.Give2(&pc->m_RanSe.m_ranse[0], pc->modeid);
	}
{//6
	auto pc = AddEnemy(90000, 2000 + rand() % 16, 150, eMP_�貨��, "��֮��", nullptr, 160);
	pc->m_XiuLian.AddXiuLianLv(18, eXLATK);
	pc->_isWeakSeal = false;
	pc->DmgPercent.d2 += 35;//������ķ����͹���
	pc->Pierce�̴�.d1 += 100;
	pc->HitRate.d2 += 50;
	pc->Evade.AddDataAddPercent(100);
	g_pMainState->SetRanse(15, 4, 2, 3, 3);
	pc->getObj()->say("����֮�У���Ϊ������");
	g_pMainState->m_ColorManage.Give2(&pc->m_RanSe.m_ranse[0], pc->modeid);
}
 {//7
	 auto pc = AddEnemy(90000, 2000 + rand() % 16, 150, eMP_��˿��, "��֮��", nullptr, 160);
	pc->m_XiuLian.AddXiuLianLv(18, eXLDMAG);
	pc->Pierce�̴�.d2 -= 99;
	pc->DmgPercent.d2 += 80;
// 	pc->DmgPercentOfMagic.d2 += 99;
// 	pc->DmgPercentOfMagic.d1 += 128;
// 	pc->DmgPercentOfMagic.d2 += 64;
// 	pc->DmgPercentOfMagic.d2 += 79;
	pc->Pierce�̴�OfMagic.d2 += 69;
	g_pMainState->SetRanse(16, 4, 2, 3, 3);
	pc->getObj()->say("�ҵĽ��в���׼�����Һݣ�");
	g_pMainState->m_ColorManage.Give2(&pc->m_RanSe.m_ranse[0], pc->modeid);
  }
	{//8
		auto pc = AddEnemy(90000, 2000 + rand() % 16, 150, eMP_ʨ����, "��֮��", nullptr, 160);
		pc->m_XiuLian.AddXiuLianLv(18, eXLATK);
		pc->AddSkill(ePS_�߼���ɱ);
		pc->AddSkill(ePS_�߼�����);
		pc->Pierce�̴�.d1 += 30;
		pc->DmgPercent.d2 += 80;
// 		pc->DmgPercentOfMagic.d2 += 99;
// 		pc->DmgPercentOfMagic.d1 += 128;
// 		pc->DmgPercentOfMagic.d2 += 64;
// 		pc->DmgPercentOfMagic.d2 += 79;
// 		pc->Pierce�̴�OfMagic.d2 += 69;
		g_pMainState->SetRanse(17, 4, 2, 3, 3);
		pc->getObj()->say("ʱ�䲻վ�����Ǳ�");
		g_pMainState->m_ColorManage.Give2(&pc->m_RanSe.m_ranse[0], pc->modeid);
	}
	{//9
		auto pc = AddEnemy(90000, 2000 + rand() % 16, 150, eMP_����ɽ, "���罣��-����", nullptr, 160);
		pc->m_XiuLian.AddXiuLianLv(18, eXLDEF);
		pc->MagicWater.d2 += 100;
		pc->MagicFire.d2 += 100;
		pc->MagicSoil.d2 += 100;
		pc->MagicThunder.d2 += 100;
// 		pc->Pierce�̴�.d2 -= 50;
// 		pc->DmgAddOfCure.d2 += 120;
// 		pc->StabRateOfMagic.d1 += 110;
// 		pc->StabPercentOfMagic.d2 += 110;
// 		pc->DmgAddOfCure.d1 += 99;
// 		pc->DmgPercentOfMagic.d2 += 99;
// 		pc->DmgPercentOfMagic.d1 += 128;
// 		pc->DmgPercentOfMagic.d2 += 64;
// 		pc->DmgPercentOfMagic.d2 += 79;
// 		pc->Pierce�̴�OfMagic.d2 += 69;
		g_pMainState->SetRanse(18, 4, 2, 3, 3);
		pc->getObj()->say("��Լ���ɣ�");
		g_pMainState->m_ColorManage.Give2(&pc->m_RanSe.m_ranse[0], pc->modeid);
	}


	{//10
		auto pc = AddEnemy(120000, 2000 + rand() % 16, 150, eMP_���ܵظ�, "����", nullptr, 160);
		pc->LiveHp = 5000;//ÿ�غϻ�Ѫ
// 		pc->DmgPercent.d2 += 100;
// 		pc->Pierce�̴�.d2 -= 16;
		pc->Ghost.d1 += 5;
// 		pc->DmgPercentOfMagic.d2 += 99;
// 		pc->Pierce�̴�OfMagic.d2 += 89;
//		pc->m_XiuLian.GetMag() = cct::getCurrMaxXiulianLv(30);
		g_pMainState->SetRanse(19, 4, 2, 3, 3);
		pc->getObj()->say("#17��Ӯ���߼�����");
		g_pMainState->m_ColorManage.Give2(&pc->m_RanSe.m_ranse[0], pc->modeid);
	}

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
				  AddTriggerFightSuccess(16);
			  }
	     }
		return true;
		case 16:
			g_pMainState->awardBook(150);//��
			g_pMainState->awardIron(150);
			/////////////////////////////////////////////////////////////////////////////
			if (r < 10)//���������
			{

			if (r < 5)
			{
				g_pMainState->awardBook(100 + (rand() % 4 * 10));//��
				g_pMainState->awardItem(27, 42 + rand() % 9, 1, true);//����

			}
			else if (r > 5)
			{
				g_pMainState->awardIron(100 + (rand() % 4 * 10));//��
				// g_pMainState->awardItem(27, 38 + rand() % 3, 1, true);//ǿ��ʯ
			}
			else if (r <2)
			{
				g_pMainState->awardBook(150);//��
				g_pMainState->awardIron(150);//��
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

			return true;
 	case 17:
		
 	{
		
		auto pc = AddEnemy(100000, e���, 160, eMP_ʨ����, "���");
		pc->LiveHp = 10000;//ÿ�غϻ�Ѫ�߼�����
		pc->SetJinJie(3);
		g_pMainState->SetRanse(10, rand() % 5, rand() % 5, rand() % 5, rand() % 5);
		pc->getObj()->say("#G���ܾ�����#18#G");
		pc->DmgPercent.d2 += 140;//������ķ����͹���
		pc->Pierce�̴�.d1 += 120;
//		pc->DmgPercentOfMagic.d1 += 28;
		pc->DmgPercentOfMagic.d2 += 64;
//		pc->Pierce�̴�OfMagic.d1 += 120;
		pc->Pierce�̴�OfMagic.d2 += 166;



		pc = AddEnemy(90000, e�ֹ�Ѳ��, 160, eMP_����ɽ, "����");
		pc->SetJinJie(3);
		g_pMainState->SetRanse(11, rand() % 5, rand() % 5, rand() % 5, rand() % 5);
		pc->LiveHp = 5000;//ÿ�غϻ�Ѫ
		pc->DmgPercent.d2 += 99;//����
		pc->Pierce�̴�.d2 += 99;//����
//		pc->DmgPercentOfMagic.d1 += 28;//����
		pc->DmgPercentOfMagic.d2 += 24;//����
		pc->Pierce�̴�OfMagic.d2 += 99;
		pc->DmgPercentOfFix.d2 -= 32;//�¹���


		 pc = AddEnemy(90000, e����ͯ��, 160, eMP_������, "����");
		pc->SetJinJie(3);
		g_pMainState->SetRanse(12, rand() % 5, rand() % 5, rand() % 5, rand() % 5);
		pc->LiveHp = 5000;//ÿ�غϻ�Ѫ
//		pc->DmgPercentOfMagic.d1 += 30;//+����
		pc->DmgPercent.d2 += 100;//�￹
		pc->Pierce�̴�.d2 += 100;//�￹
		pc->DmgPercentOfMagic.d2 += 99;//����
		pc->Pierce�̴�OfMagic.d2 += 99;//����
		pc->DmgPercentOfFix.d2 -= 35;//�¹���




		 pc = AddEnemy(90000, e������, 160, eMP_���ܵظ�, "�ݱ�ʬ");
		
		pc->SetJinJie(3);
		g_pMainState->SetRanse(13, rand() % 5, rand() % 5, rand() % 5, rand() % 5);
		pc->LiveHp = 5000;//ÿ�غϻ�Ѫ
		pc->DmgPercent.d2 += 100;
		pc->Pierce�̴�.d2 -= 16;
		pc->Ghost.d1 += 5;
		pc->m_XiuLian.GetMag() = cct::getCurrMaxXiulianLv(30);
		pc->applyXL();


		 pc = AddEnemy(60000, e���ӻ���, 160, eMP_����ɽ, "��ڤ");
		pc->SetJinJie(3);
		g_pMainState->SetRanse(14, rand() % 5, rand() % 5, rand() % 5, rand() % 5);
		pc->ParryRateOfMaigc.d1 += 5;
		pc->LiveHp = 5000;//ÿ�غϻ�Ѫ
		pc->_isWeakSeal = false;
		pc->DmgPercent.d2 += 50;
		pc->Pierce�̴�.d2 -= 100;
		pc->Pierce�̴�OfMagic.d2 -= 100;
		pc->HitRate.d2 += 50;
		pc->Evade.AddDataAddPercent(800);
		pc->m_XiuLian.GetMag() = cct::getCurrMaxXiulianLv(25);
		pc->applyXL();

		 pc = AddEnemy(70000, e��Ѫ��, 160, eMP_���ƹٸ�, "����");//���ݺܺ�
		pc->SetJinJie(3);
		pc->CriRate.d1 += 20;
		g_pMainState->SetRanse(15, rand() % 5, rand() % 5, rand() % 5, rand() % 5);
		pc->LiveHp = 5000;//ÿ�غϻ�Ѫ
		pc->_isWeakSeal = false;
		pc->DmgPercent.d2 += 120;//������ķ����͹���
		pc->Pierce�̴�.d1 += 100;
		pc->HitRate.d2 += 50;
		pc->Evade.AddDataAddPercent(100);
		pc->m_XiuLian.GetMag() = cct::getCurrMaxXiulianLv(25);
		pc->applyXL();


		 pc = AddEnemy(70000, e������Գ, 160, eMP_���ƹٸ�, "ǿ��");
		pc->SetJinJie(3);
		g_pMainState->SetRanse(16, rand() % 5, rand() % 5, rand() % 5, rand() % 5);
		pc->LiveHp = 5000;//ÿ�غϻ�Ѫ
		pc->_isWeakSeal = false;
		pc->DmgPercent.d2 += 120;//������ķ����͹���
		pc->Pierce�̴�.d1 += 110;
		pc->HitRate.d2 += 20;
		pc->Evade.AddDataAddPercent(30);
		pc->m_XiuLian.GetMag() = cct::getCurrMaxXiulianLv(23);
		pc->applyXL();

		 pc = AddEnemy(70000, e������, 160, eMP_��������, "����");
		pc->SetJinJie(3);
		pc->DmgAdd.d1 += 50;//ÿ�غϻ�Ѫ
		g_pMainState->SetRanse(17, rand() % 5, rand() % 5, rand() % 5, rand() % 5);
		pc->LiveHp = 5000;//ÿ�غϻ�Ѫ
		pc->Pierce�̴�.d2 -= 99;
		pc->DmgPercent.d2 += 80;
		pc->DmgPercentOfMagic.d2 += 99;
		pc->DmgPercentOfMagic.d1 += 128;
		pc->DmgPercentOfMagic.d2 += 64;
		pc->Pierce�̴�OfMagic.d1 += 20;
		pc->Pierce�̴�OfMagic.d2 += 64;

		pc = AddEnemy(60000, e��ʦ, 160, eMP_ħ��կ, "ף��");
		pc->SetJinJie(3);
		g_pMainState->SetRanse(18, rand() % 5, rand() % 5, rand() % 5, rand() % 5);
		pc->StabPercent.d1 += 50;//ÿ�غϻ�Ѫ
		pc->LiveHp = 5000;//ÿ�غϻ�Ѫ
		//pc->Pierce�̴�.d2 -= 50;
		pc->DmgPercentOfMagic.d2 += 69;
		pc->DmgPercentOfMagic.d1 += 128;
		pc->DmgPercentOfMagic.d2 += 64;
		pc->Pierce�̴�OfMagic.d1 += 20;
		pc->Pierce�̴�OfMagic.d2 += 64;

		pc = AddEnemy(60000, e�ɷ�Ů�, 160, eMP_�貨��, "����");
		pc->SetJinJie(3);
		g_pMainState->SetRanse(19, rand() % 5, rand() % 5, rand() % 5, rand() % 5);
		pc->HitRate.d2 +=60 ;//ÿ�غϻ�Ѫ
		pc->LiveHp = 5000;//ÿ�غϻ�Ѫ
		pc->DmgPercent.d2 += 159;
		pc->Pierce�̴�.d1 += 60;
		pc->DmgPercentOfMagic.d2 += 99;
		pc->DmgPercentOfMagic.d2 += 34;//����
		pc->Pierce�̴�OfMagic.d2 += 39;
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
 
 		AddTriggerFightSuccess(37);//��ת��Ƚ���
 	}
 		return true;
 	case 18:
	{//1
		auto objSelect = g_pMainState->m_pNowSelect;
		if (1)
		{
			auto pc = AddEnemy(100000, ����, 180, eMP_ʨ����, "�̹�", nullptr, 180);
			pc->m_XiuLian.AddXiuLianLv(30, eXLATK);
			g_pMainState->SetRanse(10, rand() % 5, rand() % 5, rand() % 5, rand() % 5);
			//pc->getObj()->say("#17���꣬��Ӯ�����벻�����ջ�Ŷ#24");
			pc->AddSkill(ePS_�߼�������);
			pc->AddSkill(ePS_���Ӹ���);
			pc->AddSkill(ePS_�߼�����);
			pc->AddSkill(ePS_�߼�����);
			pc->AddSkill(ePS_�߼�����);
			pc->AddSkill(ePS_�߼�����);
			pc->AddSkill(ePS_�߼���ɱ);
			pc->AddSkill(ePS_�߼�ҹս);
			pc->AddSkill(ePS_�߼�����);
			pc->DmgPercent.d2 += 150;//������ķ����͹���
			pc->Pierce�̴�.d1 += 130;
			pc->DmgPercentOfMagic.d1 += 38;
			pc->DmgPercentOfMagic.d2 += 74;
			pc->Pierce�̴�OfMagic.d1 += 130;
			pc->Pierce�̴�OfMagic.d2 += 176;
			g_pMainState->m_ColorManage.Give2(&pc->m_RanSe.m_ranse[0], pc->modeid);

		}

		{//2
			cPropertyData* Pet;
			Pet = AddEnemy(90000, e֪����, 160, eMP_�칬, "����", nullptr, 160);
			Pet->m_XiuLian.AddXiuLianLv(25, eXLATK);
			Pet->_isWeakSeal = false;
			Pet->DmgPercent.d2 += 120;//������ķ����͹���
			Pet->Pierce�̴�.d1 += 100;
			Pet->HitRate.d2 += 50;
			Pet->Evade.AddDataAddPercent(100);
			Pet->applyXL();
			//Pet->m_RanSe.m_ranse[1].Set(2, 3, 1, 3); //����Ⱦɫ
			g_pMainState->SetRanse(11, rand() % 5, rand() % 5, rand() % 5, rand() % 5);
			g_pMainState->m_ColorManage.Give2(&Pet->m_RanSe.m_ranse[0], 2000);
		}
		{//2
			cPropertyData* Pet;
			Pet = AddEnemy(90000, e���Ů�, 160, eMP_ħ��կ, "����", nullptr, 160);
			Pet->m_XiuLian.AddXiuLianLv(25, eXLATK);
			//Pet->m_RanSe.m_ranse[1].Set(2, 3, 1, 3); //����Ⱦɫ
			Pet->DmgPercentOfMagic.d2 += 69;
			Pet->DmgPercentOfMagic.d1 += 128;
			Pet->DmgPercentOfMagic.d2 += 64;
			Pet->Pierce�̴�OfMagic.d1 += 20;
			Pet->Pierce�̴�OfMagic.d2 += 64;
			g_pMainState->SetRanse(12, rand() % 5, rand() % 5, rand() % 5, rand() % 5);
			g_pMainState->m_ColorManage.Give2(&Pet->m_RanSe.m_ranse[0], 2000);
		}
	{//2
		cPropertyData* Pet;
		Pet = AddEnemy(90000, e��ƿŮ�, 160, eMP_����ɽ, "Ů��", nullptr, 160);
		Pet->m_XiuLian.AddXiuLianLv(25, eXLATK);
		//Pet->m_RanSe.m_ranse[1].Set(2, 3, 1, 3); //����Ⱦɫ
		Pet->DmgPercent.d2 += 100;
		Pet->Pierce�̴�.d2 -= 16;
		Pet->Ghost.d1 += 5;
		Pet->m_XiuLian.GetMag() = cct::getCurrMaxXiulianLv(30);
		g_pMainState->SetRanse(13, rand() % 5, rand() % 5, rand() % 5, rand() % 5);
		g_pMainState->m_ColorManage.Give2(&Pet->m_RanSe.m_ranse[0], 2000);
	}

{//2
	cPropertyData* Pet;
	Pet = AddEnemy(90000, e��ħ��, 160, eMP_ħ��կ, "����̫һ", nullptr, 160);
	Pet->m_XiuLian.AddXiuLianLv(25, eXLATK);
	//Pet->m_RanSe.m_ranse[1].Set(2, 3, 1, 3); //����Ⱦɫ
	Pet->Pierce�̴�.d2 -= 99;
	Pet->DmgPercent.d2 += 80;
	Pet->DmgPercentOfMagic.d2 += 99;
	Pet->DmgPercentOfMagic.d1 += 128;
	Pet->DmgPercentOfMagic.d2 += 64;
	Pet->Pierce�̴�OfMagic.d1 += 20;
	Pet->Pierce�̴�OfMagic.d2 += 64;
	g_pMainState->SetRanse(14, rand() % 5, rand() % 5, rand() % 5, rand() % 5);
	g_pMainState->m_ColorManage.Give2(&Pet->m_RanSe.m_ranse[0], 2000);
}
{//2
	cPropertyData* Pet;
	Pet = AddEnemy(90000, e�������, 160, eMP_��������, "�Ƶ�", nullptr, 160);
	Pet->m_XiuLian.AddXiuLianLv(25, eXLATK);
	//Pet->m_RanSe.m_ranse[1].Set(2, 3, 1, 3); //����Ⱦɫ
	Pet->Pierce�̴�.d2 -= 99;
	Pet->DmgPercent.d2 += 80;
	Pet->DmgPercentOfMagic.d2 += 99;
	Pet->DmgPercentOfMagic.d1 += 128;
	Pet->DmgPercentOfMagic.d2 += 64;
	Pet->Pierce�̴�OfMagic.d1 += 20;
	Pet->Pierce�̴�OfMagic.d2 += 64;
	g_pMainState->SetRanse(15, rand() % 5, rand() % 5, rand() % 5, rand() % 5);
	g_pMainState->m_ColorManage.Give2(&Pet->m_RanSe.m_ranse[0], 2000);
}
{//2
	cPropertyData* Pet;
	Pet = AddEnemy(90000, e�������, 160, eMP_��˿��, "����", nullptr, 160);
	Pet->m_XiuLian.AddXiuLianLv(25, eXLATK);
	//Pet->m_RanSe.m_ranse[1].Set(2, 3, 1, 3); //����Ⱦɫ
	g_pMainState->SetRanse(16, rand() % 5, rand() % 5, rand() % 5, rand() % 5);
	g_pMainState->m_ColorManage.Give2(&Pet->m_RanSe.m_ranse[0], 2000);
}



		{//2
			cPropertyData* Pet;
			Pet = AddEnemy(90000, e�������, 160, eMP_�貨��, "�����", nullptr, 160);
			Pet->m_XiuLian.AddXiuLianLv(25, eXLATK);
			Pet->_isWeakSeal = false;
			Pet->DmgPercent.d2 += 120;//������ķ����͹���
			Pet->Pierce�̴�.d1 += 100;
			Pet->HitRate.d2 += 50;
			Pet->Evade.AddDataAddPercent(100);
			Pet->m_XiuLian.GetMag() = cct::getCurrMaxXiulianLv(25);
			Pet->applyXL();
			//Pet->m_RanSe.m_ranse[1].Set(2, 3, 1, 3); //����Ⱦɫ
			g_pMainState->SetRanse(17, rand() % 5);
			g_pMainState->m_ColorManage.Give2(&Pet->m_RanSe.m_ranse[0], 2000);
		}
				{//2
					cPropertyData* Pet;
					Pet = AddEnemy(90000, e�������, 160, eMP_������, "��������", nullptr, 160);
					Pet->m_XiuLian.AddXiuLianLv(25, eXLATK);
					//Pet->m_RanSe.m_ranse[1].Set(2, 3, 1, 3); //����Ⱦɫ
					Pet->DmgPercentOfMagic.d1 += 40;//+����
					Pet->DmgPercent.d2 += 110;//�￹
					Pet->Pierce�̴�.d2 += 110;//�￹
					Pet->DmgPercentOfMagic.d2 += 119;//����
					Pet->Pierce�̴�OfMagic.d2 += 119;//����
					Pet->DmgPercentOfFix.d2 -= 45;//�¹���
					g_pMainState->SetRanse(18, rand() % 5, rand() % 5);
					g_pMainState->m_ColorManage.Give2(&Pet->m_RanSe.m_ranse[0], 2000);
				}
				{//2
					cPropertyData* Pet;
					Pet = AddEnemy(90000, e�������, 160, eMP_���ƹٸ�, "���", nullptr, 160);
					Pet->m_XiuLian.AddXiuLianLv(25, eXLATK);
					//Pet->m_RanSe.m_ranse[1].Set(2, 3, 1, 3); //����Ⱦɫ
					Pet->_isWeakSeal = false;
					Pet->DmgPercent.d2 += 120;//������ķ����͹���
					Pet->Pierce�̴�.d1 += 100;
					Pet->HitRate.d2 += 50;
					Pet->Evade.AddDataAddPercent(100);
					Pet->m_XiuLian.GetMag() = cct::getCurrMaxXiulianLv(25);
					Pet->applyXL();
					g_pMainState->SetRanse(19, rand() % 5, rand() % 5, rand() % 5, rand() % 5);
					g_pMainState->m_ColorManage.Give2(&Pet->m_RanSe.m_ranse[0], 2000);
				}
		g_pMainState->m_InterfaceTeam.SetFormation(tiger, true);//���ʹ���
			SetMusic("������");
			g_StateType = STATE_FIGHT;
			AddTriggerFightSuccess(37);
		}
		return true;
 	case 19:

	{

		auto pc = AddEnemy(80000, ���, 160, eMP_ʨ����, "��򼾫");
		pc->LiveHp = 10000;//ÿ�غϻ�Ѫ�߼�����
		pc->AddSkill(ePS_�߼�ҹս);
		pc->AddSkill(ePS_�߼�������);
		pc->AddSkill(ePS_���Ӹ���);
		pc->AddSkill(ePS_�߼�����);
		pc->AddSkill(ePS_�߼�����);
		pc->AddSkill(ePS_�߼�����);
		pc->AddSkill(ePS_�߼���Ѫ);
		pc->AddSkill(ePS_�߼���֪);
		pc->AddSkill(ePS_������);
		pc->AddSkill(ePS_�߼�ǿ��);
		pc->AddSkill(ePS_���Ǵ�);
		pc->AddSkill(ePS_��Ѫ׷��);
		pc->AddSkill(ePS_�߼�����);
		pc->AddSkill(ePS_�߼�����);
		pc->AddSkill(ePS_�߼�����);
		pc->SetJinJie(3);
		pc->DmgPercent.d2 += 130;//������ķ����͹���
		pc->Pierce�̴�.d1 += 120;
		pc->DmgPercentOfMagic.d1 += 38;
		pc->DmgPercentOfMagic.d2 += 74;
		pc->Pierce�̴�OfMagic.d1 += 130;
		pc->Pierce�̴�OfMagic.d2 += 176;
		g_pMainState->SetRanse(10, rand() % 5, rand() % 5, rand() % 5, rand() % 5);

		pc = AddEnemy(60000, e������, 160, eMP_����ɽ, "����");
		pc->SetJinJie(3);
		pc->AddSkill(ePS_�߼�����);
		pc->AddSkill(ePS_�߼�����);
		pc->DmgPercentOfMagic.d1 += 30;//+����
		pc->DmgPercent.d2 += 100;//�￹
		pc->Pierce�̴�.d2 += 100;//�￹
		pc->DmgPercentOfMagic.d2 += 99;//����
		pc->Pierce�̴�OfMagic.d2 += 99;//����
		pc->DmgPercentOfFix.d2 -= 35;//�¹���
		g_pMainState->SetRanse(11, rand() % 5, rand() % 5, rand() % 5, rand() % 5);
		pc->LiveHp = 5000;//ÿ�غϻ�Ѫ
		pc = AddEnemy(60000, e������, 160, eMP_������, "������");
		pc->SetJinJie(3);
		pc->AddSkill(ePS_�߼�����);
		pc->AddSkill(ePS_�߼�����);
		pc->DmgPercentOfMagic.d1 += 30;//+����
		pc->DmgPercent.d2 += 100;//�￹
		pc->Pierce�̴�.d2 += 100;//�￹
		pc->DmgPercentOfMagic.d2 += 99;//����
		pc->Pierce�̴�OfMagic.d2 += 99;//����
		pc->DmgPercentOfFix.d2 -= 35;//�¹���
		g_pMainState->SetRanse(12, rand() % 5, rand() % 5, rand() % 5, rand() % 5);
		pc->LiveHp = 5000;//ÿ�غϻ�Ѫ
		pc = AddEnemy(60000, e������, 160, eMP_���ܵظ�, "����");
		pc->AddSkill(ePS_�߼���������);
		pc->AddSkill(ePS_�߼���������);
		pc->Pierce�̴�.d2 -= 99;
		pc->DmgPercent.d2 += 80;
		pc->DmgPercentOfMagic.d2 += 99;
		pc->DmgPercentOfMagic.d1 += 128;
		pc->DmgPercentOfMagic.d2 += 64;
		pc->Pierce�̴�OfMagic.d1 += 20;
		pc->Pierce�̴�OfMagic.d2 += 64;
		pc->SetJinJie(3);
		g_pMainState->SetRanse(13, rand() % 5, rand() % 5, rand() % 5, rand() % 5);
		pc->LiveHp = 5000;//ÿ�غϻ�Ѫ
		pc = AddEnemy(50000, e������, 160, eMP_����ɽ, "������");
		pc->SetJinJie(3);
		pc->AddSkill(ePS_�߼���������);
		pc->AddSkill(ePS_�߼�ħ֮��);
		pc->DmgPercent.d2 += 50;
		pc->Pierce�̴�.d2 -= 100;
		pc->Pierce�̴�OfMagic.d2 -= 100;
		pc->HitRate.d2 += 50;
		pc->Evade.AddDataAddPercent(800);
		pc->m_XiuLian.GetMag() = cct::getCurrMaxXiulianLv(25);
		pc->applyXL();
		g_pMainState->SetRanse(14, rand() % 5, rand() % 5, rand() % 5, rand() % 5);
		pc->ParryRateOfMaigc.d1 += 5;
		
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

		AddTriggerFightSuccess(37);//��ת��Ƚ���
	}
		return true;

// //		return true;
// 	{
// 		if (g_pCharacter->m_PcData.m_FightPetID == -1)return true;
// 		cPropertyData& Pet = g_pCharacter->m_PcData.m_pPets[g_pCharacter->m_PcData.m_FightPetID]->m_PetData;
// 		ostringstream oss;
// 		switch (Pet.m_JinJieNum.m_JinJieNum)
// 		{
// 		case 0:
// 		case 1:
// 		case 2:
// 			oss << "��ĳ�ս�ٻ������´ν��׻���" << (Pet.m_JinJieNum.m_JinJieNum + 1) * 2000000 << "(��������������ɽ���)";
// 			break;
// 		default:
// 			oss << "��ĳ�ս�ٻ����Ѿ��޷��ٽ�����";
// 			break;
// 		}
// 		m_pObj = g_pMainState->m_pNowSelect;
// 		g_pMainState->m_TriggerDialog.AddSelect(this, oss.str(), m_pObj->m_TrueName.GetString(), -1,
// 			m_Textlist[3], 20,
// 			m_Textlist[4], -1);
// 	}
// 		break;
// 	case 20:
// 
// 	{
// 		if (g_pCharacter->m_PcData.m_FightPetID == -1)return true;
// 		cPropertyData& Pet = g_pCharacter->m_PcData.m_pPets[g_pCharacter->m_PcData.m_FightPetID]->m_PetData;
// 		if (g_pCharacter->m_PcData.AddMoney(-(Pet.m_JinJieNum.m_JinJieNum + 1) * 2000000, 0, 0, 0))
// 		{
// 			Pet.SetJinJie(1);
// 			m_pObj->Talk("���׳ɹ�");
// 			g_pMainState->m_PCHead.UpdatePet();
// 		}
// 		else m_pObj->Talk("Ǯ����");
// 	}
 		break;
		
	case 21:
	{
		// ������
// 		m_pObj = g_pMainState->m_pNowSelect;
// 		g_pMainState->m_TriggerDialog.AddSelect(this, "��ȡ����"/*m_Textlist[13]*/, m_pObj->m_TrueName.GetString(), -1,
// 			m_Textlist[3], 22,
// 			m_Textlist[4], -1);
		g_pMainState->m_TriggerDialog.AddSelect(this, "��ȡ����", 22);
	}
		break;
	case 22:
	{
		vector<int> lis;
		g_pMainState->m_ZuoQi.GetShiPei(lis, g_pCharacter->m_PcData.modeid);
		if (lis.size() && g_pCharacter->m_PcData.AddMoney(-10000, 0, 0, 0))
		{
			g_pMainState->m_ZuoQi.GetZuoQi(g_pCharacter->m_PcData, lis[rand() % lis.size()]);
			m_pObj->Talk("�õ�������");
		}
		else m_pObj->Talk("��ɫ����orǮ����");
	}
		break;
// 	case 23:
// 	{
// 		// �屦
// 		bool bhave[5] = { 0 };
// 		for (int i = 0; i < 60; i++)
// 		{
// 			if (27 == g_pCharacter->m_PcData.m_Items[i].GetType())
// 			{
// 				switch (g_pCharacter->m_PcData.m_Items[i].GetID())
// 				{
// 				case 6:bhave[0] = true; break;
// 				case 7:bhave[1] = true; break;
// 				case 8:bhave[2] = true; break;
// 				case 9:bhave[3] = true; break;
// 				case 10:bhave[4] = true; break;
// 				default:break;
// 				}
// 			}
// 		}
// 		for (int i = 0; i < 5; i++)
// 		{
// 			if (!bhave[i])
// 			{
// 				AddTriggerDialog2(10);
// 				return true;
// 			}
// 		}
// 		for (int i = 0; i < 60; i++)
// 		{
// 			if (27 == g_pCharacter->m_PcData.m_Items[i].GetType())
// 			{
// 				switch (g_pCharacter->m_PcData.m_Items[i].GetID())
// 				{
// 				case 6:
// 					if (bhave[0])
// 					{
// 						bhave[0] = 0;
// 						g_pCharacter->m_PcData.m_Items[i].m_Num -= 1;
// 					}
// 					break;
// 				case 7:
// 					if (bhave[1])
// 					{
// 						bhave[1] = 0;
// 						g_pCharacter->m_PcData.m_Items[i].m_Num -= 1;
// 					}
// 					break;
// 				case 8:
// 					if (bhave[2])
// 					{
// 						bhave[2] = 0;
// 						g_pCharacter->m_PcData.m_Items[i].m_Num -= 1;
// 					}
// 					break;
// 				case 9:
// 					if (bhave[3])
// 					{
// 						bhave[3] = 0;
// 						g_pCharacter->m_PcData.m_Items[i].m_Num -= 1;
// 					}
// 					break;
// 				case 10:
// 					if (bhave[4])
// 					{
// 						bhave[4] = 0;
// 						g_pCharacter->m_PcData.m_Items[i].m_Num -= 1;
// 					}
// 					break;
// 				default:break;
// 				}
// 			}
// 		}
// 		SetJiangLiItem(23, 28);
// 	}
// 		break;
// 	case 24:Select(14, 15, -1, 3, 25, 4, -1); break;
// 	case 25:
// 		if (g_pCharacter->m_PcData.AddMoney(-1000000, 0, 0, false))
// 		{
// //			g_pCharacter->m_PcData.Add����(10);
// 		}
// 		else g_pMainState->m_Tags.Add("Ǯ����");
// 		break;
// 	case 26:
// 	{
// 		int moneyneed;
// 		if (g_pMainState->m_FightWorkList[g_pMainState->m_HeroID + 5].isExist)
// 		{
// 			cPet* Pet = (cPet*)g_pMainState->m_FightWorkList[g_pMainState->m_HeroID + 5].m_pObj->m_pIndex;
// 			moneyneed = 10000 * (Pet->m_PetData.m_Lv/* - Pet->m_PetData.m_FuZhuSkillLvList[0]*/);
// 		}
// 		else moneyneed = -1;
// 		ostringstream oss;
// 		oss << m_Textlist[17];
// 		if (moneyneed > -1)
// 			oss << "(��Ҫ#R" << moneyneed << "#RǮ)";
// 		else
// 			oss << "������û�г�ս�ٻ���";
// 		g_pMainState->m_TriggerDialog.AddSelect(this, oss.str(), m_Textlist[16], -1,
// 			"ǿ��", 27,
// 			m_Textlist[21], -1
// 			/*		m_Textlist[19], 28,
// 			m_Textlist[20], 29,
// 			m_Textlist[21], -1*/
// 			);
// 	}
// 		break;
// 	case 27:
// 	case 28:
// 	case 29:
// 		// 		if (g_pMainState->m_FightList[g_pMainState->m_HeroID + 5].isExist)
// 		// 		{
// 		// 			cPet* Pet = (cPet*)g_pMainState->m_FightList[g_pMainState->m_HeroID + 5].m_pData->m_pIndex;
// 		// 			int lvadd = Pet->m_PetDataZZ.m_Lv - Pet->m_PetDataZZ.m_FuZhuSkillLvList[0];
// 		// 			int moneyneed = 10000 * lvadd;
// 		// 			if (lvadd<1)
// 		// 			{
// 		// 				g_pMainState->m_Tags.Add("�ٻ�����Ҫ�������ܼ���ǿ��");
// 		// 				return true;
// 		// 			}
// 		// 			if (g_pCharacter->m_PCData.AddMoney(-moneyneed, 0, 0, false))
// 		// 			{		
// 		//  				for (int i = 0; i < 3;i++)
// 		//  					Pet->m_PetDataZZ.lvUpFuZhuSkill(lvadd, i);
// 		// 			}
// 		// 			else g_pMainState->m_Tags.Add("Ǯ����");
// 		// 		}
// 		// 		else g_pMainState->m_Tags.Add("û�г�ս�ٻ���");
// 		break;
//  	case 30:
// 		if (g_pCharacter->m_PcData.m_Lv < 60)
// 			g_pMainState->m_LearnBangPaiSkill.OnOff(true);
// 		else
// 			g_pMainState->m_pNowSelect->Talk("��ֻ������(60�����µ�)");
// 		break;
	case 31:
		g_pMainState->_uiFoot2.OnOff(true);
		break;
	case 32:
		g_pMainState->_uiFoot.OnOff(true);
		break;
	case 33:
		g_pMainState->_uiXiangRui.OnOff(true);
		break;
	case 34:
		g_pMainState->_uiAnimalSign.OnOff(true);
		break;
	case 35:
		g_pMainState->_uiHeadTop.OnOff(true);
		break;
	case 36:
	{
		// Ӱ��
		if (g_StateType != STATE_MAIN)return false;
		ccm::get()->PKinit();
		ccm::get()->PK();
		string musicname = "ս������";
		musicname += toString("%d", 2 + rand() % 4);
		g_pMainState->m_Mp3.Load(musicname);
		if (g_pMainState->m_InterfaceTeam.getLeaveBegin() >= 3)
		{
			g_pMainState->m_InterfaceTeam.SetFormation(g_pMainState->m_InterfaceTeam.m_eOurFormation, true);
		}
		AddTriggerFightSuccess(37);
//		AddTriggerFightFalse(37);
//		AddTriggerFightEscape(37);
		g_StateType = STATE_FIGHT_MUSIC;
	}
		break;
	case 37://��ħ����
		if (r < 10)//���������
		{

			if (r < 5)
			{
				g_pMainState->awardBook(100 + (rand() % 4 * 10));//��
				g_pMainState->awardItem(27, 42 + rand() % 9, 1, true);//����

			}
			else if (r > 5)
			{
				g_pMainState->awardIron(100 + (rand() % 4 * 10));//��
				// g_pMainState->awardItem(27, 38 + rand() % 3, 1, true);//ǿ��ʯ
			}
			else if (r <2)
			{
				g_pMainState->awardBook(150);//��
				g_pMainState->awardIron(150);//��
				g_pMainState->awardk(666, 6666.666);//60W���飬100WǮ
			}
		}
		else if (r < 20)
		{
			if (!g_pMainState->awardBookIron(10 * rand() % 16))
			{
				
				g_pMainState->awardShouJue1();
				g_pMainState->awardItem(32 + rand() % 2, 7 + rand() % 4, 1, true);
				g_pMainState->awardk(600, 500);//60W���飬50WǮ
			}
		}
		else if (r < 30)
		{
	
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
		ccm::get()->PKover();
		break;
	case 38://��ħ����
		ccm::get()->PKover();
		break;
	case 0:
	case 69:
	case 89:
	case 109:
	case 129:
	case 159:
	case cct::MaxRoleLv:
		g_pMainState->m_ZhiXian3.Process(stage);
		break;
	default:
// 		if (stage == 31)
// 		{
// 			g_pMainState->m_ZhiXian3.Process(0);
// 		}
// 		else if (stage >(1 << 24))
// 		{
// 			g_pMainState->m_ZhiXian3.Process(stage);
// 		}
// 		else
// 		{
// 			ERRBOX;
// 		}
//		g_pMainState->m_pNowSelect->Talk(g_pMainState->m_TaskNormal.getNews());
		break;
	}
	return true;
}



bool cTaskZhiXian::Process1(int stage)
{
//	g_pMainState->m_pNowSelect->Talk(g_pMainState->m_TaskNormal.getNews());
	return true;
	if (stage < 0)return true;
	AddTriggerDialog2(stage);
	return true;
}



bool cTaskZhiXian::Process2(int stage)
{
//	g_pMainState->m_pNowSelect->Talk(g_pMainState->m_TaskNormal.getNews());
	return true;
	if (stage < 0)return true;
	switch (stage)
	{
	case 5:
		if (CheckINT(12, 0))
		{
			AddTriggerDialog2(-stage);
		}
		else
		{
			SetINT(12, 2);
			AddTriggerDialog2(stage);
		}
		break;
	case 6:
		if (CheckINT(12, 0))
		{
			AddTriggerDialog2(-stage);
		}
		else
		{
			SetINT(12, 1);
			AddTriggerDialog2(stage);
		}
		break;
	case 7:
		if (CheckINT(12, 1) && CheckINT(12, 2))
		{
			if (!CheckINT(12, 0))
			{
				SetINT(12, 0);
				AddTriggerDialog2(-stage);
				SetJiangLiItem(4, 40);
			}
			else
			{
				AddTriggerDialog2(-stage - 100);
			}
		}
		else
		{
			AddTriggerDialog2(stage);
		}
		break;
	default:
		AddTriggerDialog2(stage);
		break;
	}
	return true;
}




bool cTaskZhiXian::Process3(int stage)
{
	g_pMainState->m_pNowSelect->Talk("�տ���Ҳ");
	g_pMainState->m_Map.RemoveNpc(g_pMainState->m_pNowSelect, true);
	return true;
	//����
	int baoxiangid;
	int baoxiangindex;
	GetBaoXiangID(stage, baoxiangid, baoxiangindex);
	SetINT(baoxiangid, baoxiangindex);
	// 100 + stage / 30;
	switch (stage)
	{
	case -1:
		return true;
		//��������
	case 0:SetJiangLiItem(0, 32); break;
	case 1:SetJiangLiItem(0, 33); break;
		//����
	case 2:SetJiangLiItem(0, 34); break;
		//�����Ҷ�
	case 3:SetJiangLiItem(2, 22, 10); break;
	case 4:SetJiangLiItem(0, 23, 30); break;
	case 5:SetJiangLiItem(10, 24); break;
		//������
	case 6:SetJiangLiItem(1, 27); SetJiangLiItem(2, 27); break;
		//
	case 7:SetJiangLiItem(0, 29); break;
	case 8:SetJiangLi2(0, 500000, 0, 0); break;
		//�������
	case 9:SetJiangLiItem(4, 24); break;
		//������
	case 10:SetJiangLiItem(59, 27); break;
	case 11:
	case 12:
	case 13:
	case 14:
	case 15:
		SetJiangLi(1, 0, 0, 0, 100, 50); break;
	case 16:
		SetJiangLi2(500); break;
	case 17:
		SetJiangLiItem(3, 24);
		break;
	case 18:
		SetJiangLiItem(77, 40);
		break;
	default:
		break;
	}
	g_pMainState->m_Map.RemoveNpc(g_pMainState->m_pNowSelect, true);
	return true;
}



void cTaskZhiXian::GetBaoXiangID(int type, int& id, int& index)
{
	//�����Ӧ�Ľű���
	id = 100 + type / 30;
	index = type % 30;
}



bool cTaskZhiXian::Process4(int stage)
{
	if (stage == -1)return true;
	if (stage < 300)
	{//�̵�
		g_pMainState->m_InterFaceBuy.Open(stage);
		return true;
	}
	switch (stage)
	{
	case -1:return true;
	default:ERRBOX;
		break;

	}
	return true;
}




void cTaskZhiXian::ProcessSelect(int stage)
{
	m_pObj = g_pMainState->m_pNowSelect;
	g_pMainState->m_TriggerDialog.AddSelect(this, m_Textlist[stage], g_pMainState->m_pNowSelect->m_TrueName.GetString(), -1,
		"ȷ��", stage,
		"ȡ��", -1
		);
}



bool cTaskZhiXian::Process6(int stage)
{
	return true;
	switch (stage)
	{
	case -1:return true;
	case 0:Select(2, 1, -1, 3, 1, 4, 2, 5, 3); break;
	case 1:
	case 2:
	case 3:

	{
		// 			int& k = g_pMainState->m_GlobalButton[0];
		// 			switch (stage)
		// 			{
		// 			case 1:
		// 				if (k <= 50)g_pCharacter->m_PCData.GoldLivePercent.d1 -= 100;
		// 				k = 100; 
		// 				g_pMainState->m_pFightState->m_FightMenu.SetTeamControl(true);
		// 				break;
		// 			case 2:
		// 				if (k<=50)g_pCharacter->m_PCData.GoldLivePercent.d1 -= 100;
		// 				k = 80; 	
		// 				g_pMainState->m_pFightState->m_FightMenu.SetTeamControl(false);
		// 				break;
		// 			case 3:
		// 				if (k > 50)g_pCharacter->m_PCData.GoldLivePercent.d1 += 100;
		// 				k = 50;
		// 				g_pMainState->m_pFightState->m_FightMenu.SetTeamControl(false);
		// 				break;
		// 			}
	}
		break;
	default:
		ERRBOX;
		break;
	}
	return true;
}




bool cTaskZhiXian3::Process(int stage)
{
	switch (stage)
	{
	case -1:
//		m_bPK = false;
		ccm::get()->PKover();
//		g_pMainState->m_InterfaceTeam.SetFormation(m_eOurFormation, true);
		if(1)
		{
			g_pMainState->m_Map.RemoveNpc(g_pMainState->m_pNowSelect, true);
		}
		if (0)
		{
			for (int i = 0; i < 5; i++)
			{
				g_pMainState->SetFightPet(i, -1);
			}
			for (int i = 10; i < 15; i++)
			{
				g_pMainState->SetFightPet(i, -1);
			}
			for (int i = 0; i < 10; i++)
			{
				g_pMainState->m_FightWorkList[i].m_pObj = m_PreFighter[i];
				g_pMainState->m_FightWorkList[i].isExist = m_islive[i];
			}
			swap(m_prehard, g_GlobalValues[0]);


			g_pMainState->m_InterfaceTeam.SetFormation(m_eOurFormation, 0, true);
			g_pMainState->SetCharacter(g_pMainState->m_HeroID);
			g_pMainState->m_PCHead.UpDateHead();
			g_pMainState->FindObj();
		}
		break;
	default:
//		if (stage > (1 << 24))
		{
			if (g_StateType != STATE_MAIN)return false;
			ccm::get()->PKinit();
			ccm::get()->PK(stage);
			if (0)
			{
				string path1;
				ifstream File;

				int userid, enemyid;
				File >> userid;
				File >> enemyid;
				File.close();
				for (int i = 0; i < 10; i++)
				{
					m_PreFighter[i] = g_pMainState->m_FightWorkList[i].m_pObj;
					g_pMainState->m_FightWorkList[i].m_pObj = m_pFighter[i];
					m_islive[i] = g_pMainState->m_FightWorkList[i].isExist;
					g_pMainState->m_FightWorkList[i].isExist = true;
					g_pMainState->m_FightWorkList[i].m_SkillPreSelect.SkillID = -1;
				}


				swap(m_prehard, g_GlobalValues[0]);
				m_eOurFormation = g_pMainState->m_InterfaceTeam.m_eOurFormation;
				if (!LoadTeam(userid, path1, false))return false;
				if (!LoadTeam(enemyid, path1, true))return false;
			}

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
			string musicname = "ս������";
			musicname += toString("%d", 2 + rand() % 4);
			g_pMainState->m_Mp3.Load(musicname);
			g_StateType = STATE_FIGHT_MUSIC;
			AddTriggerFightSuccess(-1);
			AddTriggerFightFalse(-1);
			AddTriggerFightEscape(-1);
		}
		break;
	}
	return true;
}



void cTaskZhiXian3::Init2()
{
	if (m_bInit2)return;
	m_bInit2 = true;
	for (int i = 0; i < 10; i++)
	{
		m_pFighter[i] = new cObj;
		m_pFighter[i]->Init();
		m_pFighter[i]->m_IDInFightlist = i;
	}
}



cTaskZhiXian3::~cTaskZhiXian3()
{
	if (!m_bInit2)return;
	for (int i = 0; i < 10; i++)
	{
		m_pFighter[i]->Free();
		SAFE_DELETE(m_pFighter[i]);
	}
}
















bool cTaskZhiXian3::LoadTeam(int id, string path, bool bEnemy)

{
	int startid = 0;
	if (bEnemy)
	{
		startid = 10;
	}
// 	ifstream File;
// 	ostringstream oss;
// 	string name, path2, path3;
// 	for (int i = 0; i < 5; i++)
// 	{
// 		oss.str("");
// 		oss << path;
// 		oss << id << "\\";
// 		path2 = oss.str();
// 		oss.str("");
// 		oss << i;
// 		name = oss.str();
// 		if (!File)
// 		{
// 			Process(-1);
// 			return false;
// 		}
// 		g_pMainState->m_FightWorkList[startid + i].m_pObj->LoadCharacter(name, path2);
// 
// 		g_pMainState->m_FightWorkList[startid + i].isExist = true;
// 	}
// 	oss.str("");
// 	oss << path;
// 	oss << id << "\\index.txt";
// 	File.open(oss.str());
// 	if (!File)
// 	{
// 		Process(-1);
// 		return false;
// 	}
// 	//����
// 	int formation;
// 	File >> formation;
// 	g_pMainState->m_InterfaceTeam.SetFormation((eFormation)formation, bEnemy);
// 	string dustbin;
// 	getline(File, dustbin);
// 	//�ٻ���
// 	cPet* pet;
// 	cCharacter* pc;
// 	ifstream File2;
// 	int num;
// 	for (int i = 0; i < 5; i++)
// 	{
// 		pc = (cCharacter*)g_pMainState->m_FightWorkList[startid + i].m_pObj->m_pIndex;
// 		File >> num;
// 		int weapontype;
// 		int weaponid = 0;
// 		File >> weapontype;
// 		if (weapontype > -1)
// 		{
// 			File >> weaponid;
// 		}
// 		string petfilename;
// 		int positonid;
// 		for (int i2 = 0; i2 < num; i2++)
// 		{
// 			File >> petfilename;
// 			File >> positonid;
// 			pet = new cPet;
// 			oss.str("");
// 			oss << path;
// 			oss << id << "\\";
// 			path2 = oss.str();
// 			pet->m_PetData.ReadPet(petfilename, path2);
// 			pet->SetData(g_pMainState->m_PetDataManager.GetPetData(pet->m_PetData.modeid));
// 			pet->m_PetData.Followlv(cct::get()->maxRoleLv + cct::get()->lvGapFromRoleAndBaby, true, true, true);
// 			pet->m_PetData.SetJinJie(3);
// 			pet->m_PetData.m_JinJieNum.m_index = positonid;
// 			pc->m_PcData.AddPet(pet);
// 			pet = 0;
// 		}
// 
// 		g_pMainState->SetFightPet(startid + i, 0, false);
// 		g_pMainState->m_FightWorkList[startid + i].isExist = true;
// 		pc->m_PcData.m_IDinFightWorkList = startid + i;
// 		pc->m_PcData.Followlv(cct::get()->maxRoleLv, false, true, true);
// 		if (weapontype > -1)
// 		{
// 			pc->m_PcData.m_Equip[2].Set(weapontype, weaponid, false);
// 			pc->m_PcData.m_pWeaponData2 = 0;
// 			pc->m_PcData.m_pCharacterData2 = 0;
// 		}
// 		g_pMainState->m_FightWorkList[startid + i].m_pObj->Reset();
// 		g_pMainState->m_FightWorkList[startid + i].m_pObj->Set(POS_FIGHT_STAND);
// 		g_pMainState->m_FightWorkList[startid + i + 5].m_pObj->Set(POS_FIGHT_STAND);
// 
// 
// 		if (bEnemy)
// 			pc->m_PcData.m_Controler.Set(false, false, false, true, false);
// 		else
// 			pc->m_PcData.m_Controler.Set(false, false, false, true, false);
// 
// 	}
// 
// 
// 	File.close();
	return true;
}





bool cTaskZhiXian2::Process(int stage)
{
	if (stage == -1)
	{
		return true;
	}
	if (stage < 1000)
	{
		g_pMainState->m_Dialog.Reset();
		g_pMainState->m_Dialog.SetObj(g_pMainState->m_pNowSelect);
		g_pMainState->m_Dialog.SetString("Ҫ��#109", "Ҫ", "��Ҫ");
		g_pMainState->m_Dialog.SetTrigger(this, -1, stage + 1000);
		g_pMainState->m_Dialog.OnOff(true);
		return true;
	}
	if (stage > 1000)
	{
		int sid = stage - 1000;
		if (g_pCharacter->m_PcData.m_NumofBB == g_pCharacter->m_PcData.m_pPets.size())
		{
			g_pMainState->dialog("�ٻ���������");
			return true;
		}

		cPet* pet = new cPet;
		pet->SetData(&g_pMainState->m_PetDataManager.m_PetList[sid]);
		auto& p = pet->m_PetData;
		p.Load(sid, true, true);
		p.PointRemain = cct::PointRemian;
		p.apply();
		p.FillHpMp();
		g_pCharacter->m_PcData.AddPet(pet);
		g_pMainState->m_Tags.Add(pet->GetData()->m_Name + " +1");
		return true;
	}
	////////////////////////////////////////////////////////////////////////// �Ǻ��� ������
	return true;
	switch (g_pCharacter->m_PcData.m_MengPaiID)
	{
	case eMP_���ƹٸ�:
		switch (stage)
		{
		case 100:
			g_pHeroObj->Talk("�������¼���");
			return true;
		case 0:
			AddTriggerLv(1, 20);
			break;
		case 1:
			Process(100);
			g_pCharacter->m_PcData.AddSkill(ePS_�߼�����);
			AddTriggerLv(2, 40);
			break;
		case 2:
			Process(100);
			g_pCharacter->m_PcData.AddSkill(ePS_�߼�͵Ϯ);
			AddTriggerLv(3, 60);
			break;
		case 3:
			Process(100);
			g_pCharacter->m_PcData.AddSkill(ePS_�߼�����);
			AddTriggerLv(4, 80);
			break;
		case 4:
			Process(100);
			g_pCharacter->m_PcData.AddSkill(ePS_�߼�ҹս);
			AddTriggerLv(5, 100);
			break;
		case 5:
			Process(100);
			g_pCharacter->m_PcData.AddSkill(ePS_�߼���ɱ);
			AddTriggerLv(6, 120);
			break;
		case 6:
			Process(100);
			g_pCharacter->m_PcData.AddSkill(ePS_�߼�����);
			AddTriggerLv(7, 140);
			break;
		case 7:
			Process(100);
			g_pCharacter->m_PcData.AddSkill(ePS_����);
			AddTriggerLv(8, 160);
			break;
		case 8:
			Process(100);
			g_pCharacter->m_PcData.AddSkill(ePS_ֱ��);
			break;
		default:ERRBOX;
			break;
		}
		break;
	case eMP_����ɽ:
	case eMP_������:
		switch (stage)
		{
		case 100:
			g_pHeroObj->Talk("�������¼���");
			return true;
		case 0:
			AddTriggerLv(1, 20);
			break;
		case 1:
			Process(100);
			g_pCharacter->m_PcData.AddSkill(ePS_�߼�����);
			AddTriggerLv(2, 40);
			break;
		case 2:
			Process(100);
			g_pCharacter->m_PcData.AddSkill(ePS_�߼�ҹս);
			AddTriggerLv(3, 60);
			break;
		case 3:
			Process(100);
			g_pCharacter->m_PcData.AddSkill(ePS_�߼�����);
			AddTriggerLv(4, 80);
			break;
		case 4:
			Process(100);
			g_pCharacter->m_PcData.AddSkill(ePS_�߼������ֿ�);
			AddTriggerLv(5, 100);
			break;
		case 5:
			Process(100);
			g_pCharacter->m_PcData.AddSkill(ePS_�߼���������);
			AddTriggerLv(6, 120);
			break;
		case 6:
			Process(100);
			g_pCharacter->m_PcData.AddSkill(ePS_�߼�����);
			AddTriggerLv(7, 140);
			break;
		case 7:
			Process(100);
			g_pCharacter->m_PcData.AddSkill(ePS_�߼��м�);
			AddTriggerLv(8, 160);
			break;
		case 8:
			Process(100);
			g_pCharacter->m_PcData.AddSkill(ePS_�߼�����);
			break;
		default:ERRBOX;
			break;
		}
		break;
	case eMP_����ɽ:
	case eMP_Ů����:
		switch (stage)
		{
		case 100:
			g_pHeroObj->Talk("�������¼���");
			return true;
		case 0:
			AddTriggerLv(1, 20);
			break;
		case 1:
			Process(100);
			g_pCharacter->m_PcData.AddSkill(ePS_�߼�����);
			AddTriggerLv(2, 40);
			break;
		case 2:
			Process(100);
			g_pCharacter->m_PcData.AddSkill(ePS_�߼�ҹս);
			AddTriggerLv(3, 60);
			break;
		case 3:
			Process(100);
			g_pCharacter->m_PcData.AddSkill(ePS_�߼�����);
			AddTriggerLv(4, 80);
			break;
		case 4:
			Process(100);
			g_pCharacter->m_PcData.AddSkill(ePS_�߼�����);
			AddTriggerLv(5, 100);
			break;
		case 5:
			Process(100);
			g_pCharacter->m_PcData.AddSkill(ePS_�߼�������);
			AddTriggerLv(6, 120);
			break;
		case 6:
			Process(100);
			g_pCharacter->m_PcData.AddSkill(ePS_�߼������ֿ�);
			AddTriggerLv(7, 140);
			break;
		case 7:
			Process(100);
			g_pCharacter->m_PcData.AddSkill(ePS_�߼�����);
			AddTriggerLv(8, 160);
			break;
		case 8:
			Process(100);
			g_pCharacter->m_PcData.AddSkill(ePS_�߼���);
			break;
		default:ERRBOX;
			break;
		}
		break;
	case eMP_ʨ����:
		switch (stage)
		{
		case 100:
			g_pHeroObj->Talk("�������¼���");
			return true;
		case 0:
			AddTriggerLv(1, 20);
			break;
		case 1:
			Process(100);
			g_pCharacter->m_PcData.AddSkill(ePS_�߼�����);
			AddTriggerLv(2, 40);
			break;
		case 2:
			Process(100);
			g_pCharacter->m_PcData.AddSkill(ePS_�߼�͵Ϯ);
			AddTriggerLv(3, 60);
			break;
		case 3:
			Process(100);
			g_pCharacter->m_PcData.AddSkill(ePS_�߼�����);
			AddTriggerLv(4, 80);
			break;
		case 4:
			Process(100);
			g_pCharacter->m_PcData.AddSkill(ePS_�߼�ҹս);
			AddTriggerLv(5, 100);
			break;
		case 5:
			Process(100);
			g_pCharacter->m_PcData.AddSkill(ePS_�߼���ɱ);
			AddTriggerLv(6, 120);
			break;
		case 6:
			Process(100);
			g_pCharacter->m_PcData.AddSkill(ePS_�߼�����);
			AddTriggerLv(7, 140);
			break;
		case 7:
			Process(100);
			g_pCharacter->m_PcData.AddSkill(ePS_�߼�����);
			AddTriggerLv(8, 160);
			break;
		case 8:
			Process(100);
			g_pCharacter->m_PcData.AddSkill(ePS_�߼���);
			break;
		default:ERRBOX;
			break;
		}
		break;
	case eMP_ħ��կ:
	case eMP_��������:
		switch (stage)
		{
		case 100:
			g_pHeroObj->Talk("�������¼���");
			return true;
		case 0:
			AddTriggerLv(1, 20);
			break;
		case 1:
			Process(100);
			g_pCharacter->m_PcData.AddSkill(ePS_�߼�����);
			AddTriggerLv(2, 40);
			break;
		case 2:
			Process(100);
			g_pCharacter->m_PcData.AddSkill(ePS_�߼�����);
			AddTriggerLv(3, 60);
			break;
		case 3:
			Process(100);
			g_pCharacter->m_PcData.AddSkill(ePS_�߼�����);
			AddTriggerLv(4, 80);
			break;
		case 4:
			Process(100);
			g_pCharacter->m_PcData.AddSkill(ePS_�߼���������);
			AddTriggerLv(5, 100);
			break;
		case 5:
			Process(100);
			g_pCharacter->m_PcData.AddSkill(ePS_�߼�ħ֮��);
			AddTriggerLv(6, 120);
			break;
		case 6:
			Process(100);
			g_pCharacter->m_PcData.AddSkill(ePS_�߼���������);
			AddTriggerLv(7, 140);
			break;
		case 7:
			Process(100);
			g_pCharacter->m_PcData.AddSkill(ePS_�߼���������);
			AddTriggerLv(8, 160);
			break;
		case 8:
			Process(100);
			g_pCharacter->m_PcData.AddSkill(ePS_����ռ���);
			break;
		default:ERRBOX;
			break;
		}
		break;
	case eMP_��˿��:
		switch (stage)
		{
		case 100:
			g_pHeroObj->Talk("�������¼���");
			return true;
		case 0:
			AddTriggerLv(1, 20);
			break;
		case 1:
			Process(100);
			g_pCharacter->m_PcData.AddSkill(ePS_�߼�����);
			AddTriggerLv(2, 40);
			break;
		case 2:
			Process(100);
			g_pCharacter->m_PcData.AddSkill(ePS_�߼�͵Ϯ);
			AddTriggerLv(3, 60);
			break;
		case 3:
			Process(100);
			g_pCharacter->m_PcData.AddSkill(ePS_�߼������ֿ�);
			AddTriggerLv(4, 80);
			break;
		case 4:
			Process(100);
			g_pCharacter->m_PcData.AddSkill(ePS_�߼������);
			AddTriggerLv(5, 100);
			break;
		case 5:
			Process(100);
			g_pCharacter->m_PcData.AddSkill(ePS_�߼���ɱ);
			AddTriggerLv(6, 120);
			break;
		case 6:
			Process(100);
			g_pCharacter->m_PcData.AddSkill(ePS_�߼�����);
			AddTriggerLv(7, 140);
			break;
		case 7:
			Process(100);
			g_pCharacter->m_PcData.AddSkill(ePS_ֱ��);
			AddTriggerLv(8, 160);
			break;
		case 8:
			Process(100);
			g_pCharacter->m_PcData.AddSkill(ePS_�绪��ʥ);
			break;
		default:ERRBOX;
			break;
		}
		break;
	case eMP_���ܵظ�:
		switch (stage)
		{
		case 100:
			g_pHeroObj->Talk("�������¼���");
			return true;
		case 0:
			AddTriggerLv(1, 20);
			break;
		case 1:
			Process(100);
			g_pCharacter->m_PcData.AddSkill(ePS_�߼�����);
			AddTriggerLv(2, 40);
			break;
		case 2:
			Process(100);
			g_pCharacter->m_PcData.AddSkill(ePS_�߼�����);
			AddTriggerLv(3, 60);
			break;
		case 3:
			Process(100);
			g_pCharacter->m_PcData.AddSkill(ePS_�߼�ҹս);
			AddTriggerLv(4, 80);
			break;
		case 4:
			Process(100);
			g_pCharacter->m_PcData.AddSkill(ePS_�߼������ֿ�);
			AddTriggerLv(5, 100);
			break;
		case 5:
			Process(100);
			g_pCharacter->m_PcData.AddSkill(ePS_�߼�����);
			AddTriggerLv(6, 120);
			break;
		case 6:
			Process(100);
			g_pCharacter->m_PcData.AddSkill(ePS_�߼��м�);
			AddTriggerLv(7, 140);
			break;
		case 7:
			Process(100);
			g_pCharacter->m_PcData.AddSkill(ePS_�߼���Ѫ);
			AddTriggerLv(8, 160);
			break;
		case 8:
			Process(100);
			g_pCharacter->m_PcData.AddSkill(ePS_�߼������);
			break;
		default:ERRBOX;
			break;
		}
		break;
	case eMP_��ׯ��:
		switch (stage)
		{
		case 100:
			g_pHeroObj->Talk("�������¼���");
			return true;
		case 0:
			AddTriggerLv(1, 20);
			break;
		case 1:
			Process(100);
			g_pCharacter->m_PcData.AddSkill(ePS_�߼�����);
			AddTriggerLv(2, 40);
			break;
		case 2:
			Process(100);
			g_pCharacter->m_PcData.AddSkill(ePS_�߼������ֿ�);
			AddTriggerLv(3, 60);
			break;
		case 3:
			Process(100);
			g_pCharacter->m_PcData.AddSkill(ePS_�߼�����);
			AddTriggerLv(4, 80);
			break;
		case 4:
			Process(100);
			g_pCharacter->m_PcData.AddSkill(ePS_�߼�ҹս);
			AddTriggerLv(5, 100);
			break;
		case 5:
			Process(100);
			g_pCharacter->m_PcData.AddSkill(ePS_�߼�����);
			AddTriggerLv(6, 120);
			break;
		case 6:
			Process(100);
			g_pCharacter->m_PcData.AddSkill(ePS_�߼�ǿ��);
			AddTriggerLv(7, 140);
			break;
		case 7:
			Process(100);
			g_pCharacter->m_PcData.AddSkill(ePS_�߼�������);
			AddTriggerLv(8, 160);
			break;
		case 8:
			Process(100);
			g_pCharacter->m_PcData.AddSkill(ePS_�߼���);
			break;
		default:ERRBOX;
			break;
		}
		break;
	case eMP_�칬:
		switch (stage)
		{
		case 100:
			g_pHeroObj->Talk("�������¼���");
			return true;
		case 0:
			AddTriggerLv(1, 20);
			break;
		case 1:
			Process(100);
			g_pCharacter->m_PcData.AddSkill(ePS_����);
			AddTriggerLv(2, 40);
			break;
		case 2:
			Process(100);
			g_pCharacter->m_PcData.AddSkill(ePS_͵Ϯ);
			AddTriggerLv(3, 60);
			break;
		case 3:
			Process(100);
			g_pCharacter->m_PcData.AddSkill(ePS_����);
			AddTriggerLv(4, 80);
			break;
		case 4:
			Process(100);
			g_pCharacter->m_PcData.AddSkill(ePS_ҹս);
			AddTriggerLv(5, 100);
			break;
		case 5:
			Process(100);
			g_pCharacter->m_PcData.AddSkill(ePS_�߼�ħ֮��);
			AddTriggerLv(6, 120);
			break;
		case 6:
			Process(100);
			g_pCharacter->m_PcData.AddSkill(ePS_�߼�����);
			AddTriggerLv(7, 140);
			break;
		case 7:
			Process(100);
			g_pCharacter->m_PcData.AddSkill(ePS_�绪��ʥ);
			AddTriggerLv(8, 160);
			break;
		case 8:
			Process(100);
			g_pCharacter->m_PcData.AddSkill(ePS_����ռ���);
			break;
		default:ERRBOX;
			break;
		}
		break;
	default:
		switch (stage)
		{
		case 100:
			g_pHeroObj->Talk("�������¼���");
			return true;
		case 0:
			AddTriggerLv(1, 20);
			break;
		case 1:
			Process(100);
			g_pCharacter->m_PcData.AddSkill(ePS_����);
			AddTriggerLv(2, 40);
			break;
		case 2:
			Process(100);
			g_pCharacter->m_PcData.AddSkill(ePS_͵Ϯ);
			AddTriggerLv(3, 60);
			break;
		case 3:
			Process(100);
			g_pCharacter->m_PcData.AddSkill(ePS_����);
			AddTriggerLv(4, 80);
			break;
		case 4:
			Process(100);
			g_pCharacter->m_PcData.AddSkill(ePS_ҹս);
			AddTriggerLv(5, 100);
			break;
		case 5:
			Process(100);
			g_pCharacter->m_PcData.AddSkill(ePS_�߼�ħ֮��);
			AddTriggerLv(6, 120);
			break;
		case 6:
			Process(100);
			g_pCharacter->m_PcData.AddSkill(ePS_�߼�����);
			AddTriggerLv(7, 140);
			break;
		case 7:
			Process(100);
			g_pCharacter->m_PcData.AddSkill(ePS_�绪��ʥ);
			AddTriggerLv(8, 160);
			break;
		case 8:
			Process(100);
			g_pCharacter->m_PcData.AddSkill(ePS_����ռ���);
			break;
		default:ERRBOX;
			break;
		}
		break;

	}

	return true;
}

