#include "_global.h"

#if 0
void ItemManager::AutoItemProperty(sItem2* item, cCharacter* pc, int dustbin)
{
	return AutoItemProperty(item, &pc->m_PCData, dustbin);
}


void ItemManager::AutoItemProperty(sItem2* item, cPCData* pc, int dustbin)
{
	int Luck;
	if (!pc)
	{
		cCharacter* pc2 = g_pCharacter;
		Luck = pc2->m_PCData.m_Popularity;
	}
	else
		Luck = pc->m_Popularity;
	AutoItemProperty(item, Luck, dustbin);
	return;
}


void ItemManager::AutoItemProperty(sItem2* item, int Luck, int dustbin)
{
	////////////////////////////////////////////////////////////////////////// �Ǻ���
	g_pMainState->m_InterfaceDoor.m_TimeShiCheng.stepMiliSec();
	if (Luck < 10)Luck = 10;
	if (Luck > 1000)Luck = 1000;
	item->m_Property.clear();
	item->m_strProperty = "";
	vector<int>& property = item->m_Property;
	property.clear();

	int stone = dustbin % 10;
	// ����һ��
	int skillSpecialID = (dustbin / 10) - 1;
	switch (item->GetType())
	{
	case 0:
	case 1:
	case 2:
	case 3:
	case 4:
	case 5:
	case 6:
	case 7:
	case 8:
	case 9:
	case 10:
	case 11:
	case 12:
	case 13:
	case 14:
		// ����
		if (1)
		{
			g_pMainState->m_InterfaceDoor.m_TimeShiCheng.stepMiliSec();
			int lv = item->m_pItemData->GetLv();
			int Offset = lv / 10;


			property.push_back(Offset);//ǿ���ȼ�
			property.push_back(0); //ʯͷ
			// 			if (0==rand()%10)
			// 				property.push_back(rand()%36);
			// 			else 	
			// 				property.push_back(-1);
			// �ؼ�
			property.push_back(skillSpecialID);
			// �Ƿ��޼���
			property.push_back(rand() % 100 < 5 ? 0 : -1);
			// �Ƿ�����/��ŭ
			property.push_back(rand() % 100 < 5 ? 0 : -1);
			property.push_back(-1);
			
			// 			int extranum = rand() % 10;
			// 			if (extranum > 2)
			// 				extranum = 0;
			// 
			// 			property.push_back(extranum+2);
			property.push_back(4);
			property.push_back(eProPerty�˺�);
			//			property.push_back((15 + Offset * 40)+(40*rand()%(1000+Luck))/2000 );
			property.push_back(37 + Offset * 40/* + 200*/);// ע��getEquipAtkһ��
			property.push_back(eProPerty����);
			property.push_back(57 + Offset * 45 + 600);
			// 			property.push_back(eProPerty��Ѫ);
			// 			property.push_back(400);
			property.push_back(eProPertyħ��);
			property.push_back(400);
			property.push_back(eProPerty����);
			property.push_back(200);
			//			property.push_back((10 + Offset * 35) + (35 * rand() % (1000 + Luck)) / 2000);
			//			AutoItemPropertyװ��(property, extranum, Luck, Offset);

		}
		break;
		//װ��
	case 15:
	case 16:
	case 17:
	case 18:
	case 19:
	case 20:
	case 21:

	{
		g_pMainState->m_InterfaceDoor.m_TimeShiCheng.stepMiliSec();
		int lv;
		lv = item->m_pItemData->GetLv();//  GetlvByID(item->m_pItemData->m_Type, item->m_pItemData->m_ID);

		int Offset = lv / 10;
		property.push_back(Offset);//ǿ���ȼ�

		//// �õ��ؼ��ļ���
		//int special, special2;
		//if (rand() % (15 - Luck / 100) == 0)
		//	special = rand() % 50;
		//else special = -1;
		//if (rand() % (15 - Luck / 100) == 0)
		//	special2 = 50 + rand() % 8;
		//else  special2 = -1;
		//property.push_back(special);
		//property.push_back(special2);

		// 			if (0 == rand() % 10)
		// 				property.push_back(rand() % 36);
		// 			else 	property.push_back(-1);
		property.push_back(skillSpecialID);
		property.push_back(-1);
		property.push_back(-1);
		property.push_back(-1);
		// 			int extranum=0;
		// 			if (18 == item->GetType())
		// 			{
		// 				int extranum = rand() % 10;
		// 				if (extranum > 2)extranum = 0;
		// 			}

		switch (item->GetType())
		{
		case 15:  //ͷ
		case 16:
			//				property.push_back(extranum+2);
			property.push_back(3);
			if (stone)
			{
				property.push_back(eProPerty����);
				//				property.push_back((5 + Offset * 5) + (5 * (rand() % (100 + Luck / 10))) / 100);
				property.push_back(3 + Offset * 7 + 60);
				property.push_back(eProPertyħ��);
				//				property.push_back((5 + Offset * 10) + (10 * (rand() % (100 + Luck / 10))) / 100);
				property.push_back(32 + Offset * 12);
				property.push_back(eProPerty�˺�);
				property.push_back(60 + Offset * 8);
			}
			else
			{
				property.push_back(eProPerty����);
				property.push_back(3 + Offset * 7 + Offset * 12 + 60);
				property.push_back(eProPertyħ��);
				property.push_back(32 + Offset * 12);
				property.push_back(eProPerty�˺�);
				property.push_back(60);
			}
			break;
		case 17:   //��
		case 18:
			//				property.push_back(extranum+1);
			if (stone == 1)
			{
				property.push_back(3);
				property.push_back(eProPerty����);
				//				property.push_back((10 + Offset * 15) + (15 * (rand() % (100 + Luck / 10))) / 100);
				property.push_back(20 + Offset * 20);
				property.push_back(eProPerty����);
				property.push_back(6 * Offset + 28);

			}
			else if (stone == 0)
			{
				property.push_back(3);
				property.push_back(eProPerty����);
				property.push_back(20 + Offset * (20 + 12));
				property.push_back(eProPerty����);
				property.push_back(28);
			}
			else if (stone == 2)
			{
				property.push_back(4);
				property.push_back(eProPerty����);
				property.push_back(20 + Offset * 20);
				property.push_back(eProPerty����);
				property.push_back(28);
				property.push_back(eProPerty��Ѫ);
				property.push_back(Offset * 40);
			}
			else
			{
				property.push_back(1);
			}
			property.push_back(eProPertyħ��);
			property.push_back(160);

			break;
		case 19:  //����
			//				property.push_back(extranum+1);
			property.push_back(2);
			property.push_back(eProPerty����);
			//				property.push_back((5 + Offset * 12) + (12 * (rand() % (100 + Luck / 10))) / 100);
			property.push_back(11 + Offset * (16 + 6));
			property.push_back(eProPerty��Ѫ);
			property.push_back(240);
			break;
		case 20: //����
			//				property.push_back(extranum+2);
			if (stone)
			{
				property.push_back(3);
				property.push_back(eProPerty����);
				//				property.push_back((5 + Offset * 5) + (5 * (rand() % (100 + Luck / 10))) / 100);
				property.push_back(3 + Offset * 7);
				property.push_back(eProPerty��Ѫ);
				//				property.push_back((10 + Offset * 20) + (20 * (rand() % (100 + Luck / 10))) / 100);
				property.push_back(33 + Offset * (26 + 25)); // 25����������ʱ��
				property.push_back(eProPerty�ٶ�);
				property.push_back(Offset * 8);
			}
			else
			{
				property.push_back(2);
				property.push_back(eProPerty����);
				property.push_back(3 + Offset * 7);
				property.push_back(eProPerty��Ѫ);
				property.push_back(33 + Offset * (26 + 40 + 25));
			}
			break;
		case 21: //Ь
			//				property.push_back(extranum+2);

			if (stone == 0)
			{
				// �ٶ�
				property.push_back(2);
				property.push_back(eProPerty����);
				property.push_back(3 + Offset * 7);
				property.push_back(eProPerty�ٶ�);
				property.push_back(3 + Offset * (3 + 8 + 18));
			}
			else if (stone == 1)
			{
				// �˺�
				property.push_back(3);
				property.push_back(eProPerty����);
				property.push_back(3 + Offset * 7);
				property.push_back(eProPerty�ٶ�);
				property.push_back(2 + Offset * 3 + 60);
				property.push_back(eProPerty�˺�);
				property.push_back(Offset * 25);

			}
			else if (stone == 2)
			{
				// ����
				property.push_back(3);
				property.push_back(eProPerty����);
				property.push_back(3 + Offset * 7);
				property.push_back(eProPerty�ٶ�);
				property.push_back(2 + Offset * 3 + 60);
				property.push_back(eProPerty����);
				property.push_back(Offset * 25);
			}
			// 				else if (stone == 3)
			// 				{
			// 					// ��Ѫ
			// 					property.push_back(3);
			// 					property.push_back(eProPerty����);
			// 					property.push_back(3 + Offset * 7);
			// 					property.push_back(eProPerty�ٶ�);
			// 					property.push_back(2 + Offset * 3 + 60);
			// 					property.push_back(eProPerty��Ѫ);
			// 					property.push_back(80 + Offset * 80/*145*/);
			// 				}
			//				property.push_back(eProPerty����);
			//				property.push_back((5 + Offset * 5) + (5 * (rand() % (100 + Luck / 10))) / 100);
			//				property.push_back(eProPerty�ٶ�);
			//				property.push_back((5 + Offset * 3) + (3 * (rand() % (100 + Luck / 10))) / 100);
			break;
		}
		//			AutoItemPropertyװ��(property, extranum, Luck, Offset);

	}
		break;
	case 32:
	case 33:
	case 34:
	{
		g_pMainState->m_InterfaceDoor.m_TimeShiCheng.stepMiliSec();
		int Offset = item->m_pItemData->m_ID + 1;
		property.push_back(Offset);//ǿ���ȼ�

		//// �õ���Ч�ļ���
		//int special2;
		//if (rand() % (15 - Luck / 100) == 0)
		//	special2 = 50 + rand() % 8;
		//else  special2 = -1;
		//property.push_back(-1);
		//property.push_back(special2);
		property.push_back(-1);
		property.push_back(-1);
		property.push_back(-1);
		property.push_back(-1);
		// 			int extranum = 0;
		// 			if (18 == item->GetType())
		// 			{
		// 				int extranum = rand() % 10;
		// 				if (extranum > 2)extranum = 0;
		// 			}
		// 			property.push_back(extranum + 2);
		property.push_back(3);
		switch (item->GetType())
		{
		case 32://���� ����

			property.push_back(eProPerty����);
			property.push_back(15 + Offset * 50 + (50 * (rand() % (100 + Luck / 10))) / 100);
			property.push_back(eProPerty��Ѫ);
			property.push_back(Offset * 10);
			if (stone)
			{
				property.push_back(eProPerty����);
				property.push_back(Offset * (2 + 4));

			}
			else
			{
				property.push_back(eProPerty�˺�);
				//					property.push_back(5 + Offset * 20 + (20 * (rand() % (100 + Luck / 10))) / 100);
				property.push_back(Offset * (3 + 10));
			}

			break;
		case 33://��Ȧ �ٶ�	
			property.push_back(eProPerty��Ѫ);
			property.push_back(Offset * 10);
			if (stone)
			{
				property.push_back(eProPerty����);
				property.push_back(Offset * (2));

			}
			else
			{
				property.push_back(eProPerty�˺�);
				property.push_back(Offset * (3));
			}
			property.push_back(eProPerty�ٶ�);
			//				property.push_back(3 + Offset * 4 + (4 * (rand() % (100 + Luck / 10))) / 100);
			property.push_back(Offset * (5 + 6));

			// 				property.push_back(eProPerty����);
			// 				property.push_back(2 + Offset * 3 + (3 * (rand() % (100 + Luck / 10))) / 100);
			break;
		case 34://���� ��
			property.push_back(eProPerty����);
			//				property.push_back(10 + Offset * 15 + (15 * (rand() % (100 + Luck / 10))) / 100);
			property.push_back(Offset * 10);

			property.push_back(eProPerty��Ѫ);
			//				property.push_back(30 + Offset * 50 + (50 * (rand() % (100 + Luck / 10))) / 100);
			property.push_back(Offset * (10 + 30));
			if (stone)
			{
				property.push_back(eProPerty����);
				property.push_back(Offset * (2));

			}
			else
			{
				property.push_back(eProPerty�˺�);
				property.push_back(Offset * (3));
			}
			break;
		}
		//			AutoItemPropertyװ��(property, extranum, Luck, Offset);
	}
		break;
	case 24://����
		property.push_back(0);
		break;
	case 27:
		break;
	case 28: //���ɵ��ӵ���
		switch (item->GetID())
		{
		case 12:
		case 13:
		case 14:
		case 15:
		case 16:
			property.push_back(20);
			break;
		case 6:

		{
			int xbaotu, ybaotu;
			int mapid = rand() % g_pMainState->m_TaskBaoTu.m_MapNameList.size();
			property.push_back(mapid);;
			g_pMainState->m_Map.AutoGetPos(xbaotu, ybaotu, g_pMainState->m_TaskBaoTu.m_MapNameList[mapid]);
			property.push_back(xbaotu);
			property.push_back(ybaotu);
			property.push_back(xbaotu * 20);
			property.push_back(g_pMainState->m_Map.m_BmpTest.GetHeight() - ybaotu * 20);

		}
			break;
		case 8:  //������
			if (1)
			{
				int equiptype = rand() % 22;
				if (equiptype == 13)equiptype = rand() % 13;
				int equipid = (rand() % 8) * 10;
				property.push_back(equiptype);
				property.push_back(equipid);
			}
			break;
		default:
			break;
		}
		break;
	case 31:
		if (1)
		{
			property.push_back(0);//����װ��Ⱦɫ
		}
		break;
	default:
		return;
		break;
	}
}


void ItemManager::AutoItemProperty����(sItem2* item, int Luck)
{
	if (item->GetType() > 21)
	{
		return AutoItemProperty(item, Luck, 0);
	}
	if (Luck < 10)Luck = 10;
	if (Luck > 1000)Luck = 1000;
	item->m_Property.clear();
	item->m_strProperty = "";
	vector<int>& property = item->m_Property;
	property.clear();
	switch (item->GetType())
	{
	case 0:
	case 1:
	case 2:
	case 3:
	case 4:
	case 5:
	case 6:
	case 7:
	case 8:
	case 9:
	case 10:
	case 11:
	case 12:
	case 13:
	case 14:
		if (1)
		{
			int lv = item->m_pItemData->GetLv();
			int Offset = lv / 10;


			property.push_back(0);//ǿ���ȼ�
			property.push_back(rand() % 36);
			property.push_back(-1);
			property.push_back(-1);
			property.push_back(-1);
			int extranum = 0;
			//			extranum = rand() % 10;
			// 			if (extranum > 2)extranum = 0;
			// 			extranum = 2;

			property.push_back(extranum + 2);
			property.push_back(eProPerty�˺�);
			property.push_back((15 + Offset * 40) + (40 * rand() % (1000 + Luck)) / 1000);
			property.push_back(eProPerty����);
			property.push_back((10 + Offset * 35) + (55 * rand() % (1000 + Luck)) / 1000);
			AutoItemPropertyװ��(property, extranum, Luck, Offset);
		}
		break;
		//װ��
	case 15:
	case 16:
	case 17:
	case 18:
	case 19:
	case 20:
	case 21:
	{
		int lv;
		lv = item->m_pItemData->GetLv();//  GetlvByID(item->m_pItemData->m_Type, item->m_pItemData->m_ID);

		int Offset = lv / 10;
		property.push_back(0);//ǿ���ȼ�

		//// �õ��ؼ��ļ���
		//int special, special2;
		//if (rand() % (15 - Luck / 100) == 0)
		//	special = rand() % 50;
		//else special = -1;
		//if (rand() % (15 - Luck / 100) == 0)
		//	special2 = 50 + rand() % 8;
		//else  special2 = -1;
		//property.push_back(special);
		//property.push_back(special2);

		property.push_back(rand() % 36);
		property.push_back(-1);
		property.push_back(-1);
		property.push_back(-1);
		int extranum = 0;
		// 		if (18 == item->GetType() || 17 == item->GetType())
		// 		{
		// 			extranum = rand() % 10;
		// 			if (extranum > 2)extranum = 0;
		// 			extranum = 2;
		// 		}

		switch (item->GetType())
		{
		case 15:  //ͷ
		case 16:
			property.push_back(extranum + 2);
			property.push_back(eProPerty����);
			property.push_back((5 + Offset * 5) + (5 * (rand() % (100 + Luck / 10))) / 50);
			property.push_back(eProPertyħ��);
			property.push_back((5 + Offset * 10) + (10 * (rand() % (100 + Luck / 10))) / 50);
			break;
		case 17:   //��
		case 18:
			property.push_back(extranum + 1);
			property.push_back(eProPerty����);
			property.push_back((10 + Offset * 15) + (15 * (rand() % (100 + Luck / 10))) / 50);
			break;
		case 19:  //����
			property.push_back(extranum + 1);
			property.push_back(eProPerty����);
			property.push_back((5 + Offset * 12) + (12 * (rand() % (100 + Luck / 10))) / 50);
			break;
		case 20: //����
			property.push_back(extranum + 2);
			property.push_back(eProPerty����);
			property.push_back((5 + Offset * 5) + (5 * (rand() % (100 + Luck / 10))) / 50);
			property.push_back(eProPerty��Ѫ);
			property.push_back((10 + Offset * 20) + (20 * (rand() % (100 + Luck / 10))) / 50);
			break;
		case 21: //Ь
			property.push_back(extranum + 2);
			property.push_back(eProPerty����);
			property.push_back((5 + Offset * 5) + (5 * (rand() % (100 + Luck / 10))) / 50);
			property.push_back(eProPerty�ٶ�);
			property.push_back((5 + Offset * 3) + (3 * (rand() % (100 + Luck / 10))) / 50);
			break;
		}
		AutoItemPropertyװ��(property, extranum, Luck, Offset);

	}
		break;
	}
}



void ItemManager::AutoItemPropertyװ��(vector<int>& property, int extranum, int Luck, int Offset)
{
	if (!extranum)return;
	int extraprop[2];
	int extrapropnum[2];
	for (int i = 0; i < extranum; i++)
	{
		extrapropnum[i] = rand() % (Offset * 2 + Luck / 50 + 1);
		if (extrapropnum[i] == 0)extrapropnum[i] = 1;
		switch (rand() % 5)
		{
		case 0:extraprop[i] = eProPerty����; break;
		case 1:extraprop[i] = eProPertyħ��; break;
		case 2:extraprop[i] = eProPerty����; break;
		case 3:extraprop[i] = eProPerty����; break;
		case 4:extraprop[i] = eProPerty����; break;
		default:{extraprop[i] = -1; extrapropnum[i] = 0; }
		}
	}
	for (int i = 0; i < extranum; i++)
	{
		property.push_back(extraprop[i]);
		property.push_back(extrapropnum[i]);
	}
}

#endif

void ItemManager::AutoItemProperty(sItem2* item, bool isNormalEquip /*= true*/)
{
	item->m_strProperty = "";
	if (cct::isEquipBB(item))
	{
		item->m_Property = AutoItemPropertyBB(item);
		return;
	}
	if (cct::isWeapon(item))
	{
		item->m_Property = AutoItemPropertyWeapon(item, isNormalEquip);
		return;
	}
	if (cct::isEquipButWeapon(item))
	{
		item->m_Property = AutoItemPropertyEquipButWeapon(item, isNormalEquip);
		return;
	}
	vector<int>& property = item->m_Property;
	property.clear();
	switch (item->GetType())
	{
	case 24://����
		property.push_back(0);
		break;
	case 27:
		break;
	case 28: //���ɵ��ӵ���
		switch (item->GetID())
		{
			// ������
		case 12:
		case 13:
		case 14:
		case 15:
		case 16:
			property.push_back(20);
			break;
		case 6:
		{
			// �ر�ͼ
			int xbaotu, ybaotu;
			int mapid = rand() % g_pMainState->m_TaskBaoTu.m_MapNameList.size();
			property.push_back(mapid);
			g_pMainState->m_Map.AutoGetPos(xbaotu, ybaotu, g_pMainState->m_TaskBaoTu.m_MapNameList[mapid]);
			property.push_back(xbaotu);
			property.push_back(ybaotu);
			property.push_back(xbaotu * 20);
			property.push_back(g_pMainState->m_Map.m_BmpTest.GetHeight() - ybaotu * 20);

		}
			break;
		case 8:  //������
			if (1)
			{
// 				int equiptype = rand() % 22;
// 				if (equiptype == 13)equiptype = rand() % 13;
// 				int equipid = (rand() % 8) * 10;
// 				property.push_back(equiptype);
// 				property.push_back(equipid);
			}
			break;
		default:
			break;
		}
		break;
	case 31:
		if (1)
		{
			property.push_back(0);//����װ��Ⱦɫ
		}
		break;
	}
}

#define ccc_auto_equip_rand rand() %

vector<int> ItemManager::AutoItemPropertyWeapon(sItem2* item, bool isNormal)
{
	vector<int> property;
	int lv = item->m_pItemData->GetLv();
	if (lv < 10)
	{
		lv = 5;
	}
	property.push_back(-1);//ǿ���ȼ�
	property.push_back(-1); //ʯͷ
	auto rAtk = [=](){return 10 + lv * 3; };
	auto rHit = [=](){return 10 + lv * 7 / 2; };
	if (isNormal || lv < 10)
	{
		// ע��getEquipAtkһ��
		property.push_back(eProPerty����);
		property.push_back(rHit());
		property.push_back(eProPerty�˺�);
		property.push_back(rAtk());
		
		// ˫��
		property.push_back(-1);
		property.push_back(-1);
		property.push_back(-1);
		property.push_back(-1);
		// ��ʯ���� 10-11
		property.push_back(-1);
		property.push_back(-1);
		return property;
	}

	// ����
	property.push_back(eProPerty����);
	property.push_back(rHit() + lv / 6 + ccc_auto_equip_rand(lv + 1));
	property.push_back(eProPerty�˺�);
	property.push_back(rAtk() + lv / 5 + ccc_auto_equip_rand(lv * 6 / 5 + 1));

	// ˫�� 6-9
	auto skills = cct::getSpecialSkills();
	if (rand() % 50 < 100)
	{
		skills =
		{
			eProPerty����,
			eProPerty����,
			eProPerty����,
			eProPertyħ��,
			eProPerty����
		};
		int r = rand() % skills.size();
		property.push_back(skills[r]);
		property.push_back(3 + ccc_auto_equip_rand(lv / 5 + 1));
		skills.erase(skills.begin() + r);
		if (rand() % 50 < 100)
		{
			r = rand() % skills.size();
			property.push_back(skills[r]);
			property.push_back(3 + ccc_auto_equip_rand(lv / 5 + 1));
		}
		else
		{
			property.push_back(-1);
			property.push_back(-1);
		}
	}
	else
	{
		property.push_back(-1);
		property.push_back(-1);
		property.push_back(-1);
		property.push_back(-1);
	}
	// ��ʯ���� 10-11
	property.push_back(-1);
	property.push_back(-1);

	skills = cct::getSpecialSkills();
	// �ؼ� 12
	property.push_back(rand() % 100 < 35 ? skills[rand() % skills.size()] : -1);
	// �Ƿ��޼��� 13
	property.push_back(rand() % 100 < 3 ? 0 : -1);
	// �Ƿ�����(/��ŭ) 14
	property.push_back(rand() % 100 < 5 ? 0 : -1);
	// ��ʯ 15
	property.push_back(-1);

	auto rLv = [&]()
	{ 
		int slv = (160 - lv) / 2;  
		return lv + ((slv > 0) ? (ccc_auto_equip_rand slv) : 0);
		return slv * 3 + (rand() % (slv)) - (rand() % (slv)); 
	};
	auto rate = [](int a, int b)
	{
		return (b * 1.0f / 100);
		return (a + (rand() % (b - a))) * 1.0f / 100; 
	};
	// ��ʱ(����) 16-
	property.push_back(eProPerty��Ѫ);
	property.push_back(rLv() * rate(50, 200));
	property.push_back(eProPertyħ��);
	property.push_back(rLv() *  rate(100, 200));
	property.push_back(eProPerty�˺�);
	property.push_back(rLv() *  rate(50, 100));
	property.push_back(eProPerty����);
	property.push_back(rLv() *  rate(50, 100));
	property.push_back(eProPerty�ظ�);
	property.push_back(rLv() *  rate(15, 30));
	return property;

}


vector<int> ItemManager::AutoItemPropertyEquipButWeapon(sItem2* item, bool isNormal)
{
	vector<int> property;
	int lv = item->m_pItemData->GetLv();
	if (lv < 10)
	{
		lv = 5;
	}
	property.push_back(-1);//ǿ���ȼ�
	property.push_back(-1); //ʯͷ
	auto rcb = [=](int a1, int a2, int b1, int b2){return (lv * a1 / a2) + ccc_auto_equip_rand(lv * b1 / b2 + 1); };
	auto rHp = [=](){return 10 + lv * 2 + (isNormal ? 0 : rcb(1, 5, 2, 3)); };
	auto rMp = [=](){return 5 + lv + (isNormal ? 0 : rcb(1, 10, 1, 3));};
	auto rDef = [=](){return 5 + lv / 3 + (isNormal ? 0 : rcb(1, 14, 1, 5));};
	auto rMana = [=](){return 5 + lv * 6 / 5 + (isNormal ? 0 : rcb(1, 9, 2, 5)); };
	auto rAgi = [=](){return 5 + lv / 3 + (isNormal ? 0 : rcb(1, 17, 1, 10)); };
	auto rDef2 = [=](){return 10 + lv * 5 / 3 + (isNormal ? 0 : rcb(1, 5, 1, 2)); };
	
	switch (item->GetType())
	{
	case 15:  //ͷ
	case 16:
		property.push_back(eProPerty����);
		property.push_back(rDef());
		property.push_back(eProPertyħ��);
		property.push_back(rMp());
		break;
	case 17:   //��
	case 18:
		property.push_back(eProPerty����);
		property.push_back(rDef2());
		property.push_back(-1);
		property.push_back(-1);
		break;
	case 19:  //����
		property.push_back(eProPerty����);
		property.push_back(rMana());
		property.push_back(-1);
		property.push_back(-1);
		break;
	case 20: //����
		property.push_back(eProPerty����);
		property.push_back(rDef());
		property.push_back(eProPerty��Ѫ);
		property.push_back(rHp());
		break;
	case 21: //Ь
		property.push_back(eProPerty����);
		property.push_back(rDef());
		property.push_back(eProPerty����);
		property.push_back(rAgi());
		break;
	}

	if (isNormal || lv < 10)
	{
		// ˫��
		property.push_back(-1);
		property.push_back(-1);
		property.push_back(-1);
		property.push_back(-1);
		// ��ʯ���� 10-11
		property.push_back(-1);
		property.push_back(-1);
		return property;
	}

	// ˫�� 6-9
	auto skills = cct::getSpecialSkills();
	if ((item->GetType() == 17 || item->GetType() == 18) && rand() % 50 < 100)
	{
		skills =
		{
			eProPerty����,
			eProPerty����,
			eProPerty����,
			eProPertyħ��,
			eProPerty����
		};
		int r = rand() % skills.size();
		property.push_back(skills[r]);
		property.push_back(3 + ccc_auto_equip_rand(lv / 5));
		skills.erase(skills.begin() + r);
		if (rand() % 50 < 100)
		{
			r = rand() % skills.size();
			property.push_back(skills[r]);
			property.push_back(3 + ccc_auto_equip_rand(lv / 5));
		}
		else
		{
			property.push_back(-1);
			property.push_back(-1);
		}
	}
	else
	{
		property.push_back(-1);
		property.push_back(-1);
		property.push_back(-1);
		property.push_back(-1);
	}

	// ��ʯ���� 10-11
	property.push_back(-1);
	property.push_back(-1);

	skills = cct::getSpecialSkills();
	// �ؼ� 12
	property.push_back(rand() % 100 < 35 ? skills[rand() % skills.size()] : -1);
	// �Ƿ��޼��� 13
	property.push_back(rand() % 100 < 3 ? 0 : -1);
	// �Ƿ�(����/)��ŭ 14
	property.push_back((item->GetType() == 20 && rand() % 100 < 8) ? 0 : -1);
	// ��ʯ 15
	property.push_back(-1);

	// ��ʱ(����) 16-
	auto rLv = [&]()
	{
		int slv = (160 - lv) / 2;
		return lv + ((slv > 0) ? (ccc_auto_equip_rand slv) : 0);
		return slv * 3 + (rand() % (slv)) - (rand() % (slv));
	};
	auto rate = [](int a, int b)
	{
		return (b * 1.0f / 100);
		return (a + (rand() % (b - a))) * 1.0f / 100;
	};
	switch (item->GetType())
	{
	case 15:  //ͷ
	case 16:
		property.push_back(eProPerty����);
		property.push_back(rLv() * rate(50, 100));
		property.push_back(eProPerty����);
		property.push_back(rLv() * rate(15, 20));
		break;
	case 17:   //��
	case 18:
		property.push_back(eProPertyħ��);
		property.push_back(rLv() * rate(10, 20));
		property.push_back(eProPerty����);
		property.push_back(rLv() * rate(15, 30));
		break;
	case 19:  //����
		property.push_back(eProPerty����);
		property.push_back(rLv() * rate(15, 20));
		property.push_back(eProPerty����);
		property.push_back(rLv() * rate(15, 30));
		break;
	case 20: //����
		property.push_back(eProPerty��ŭ);
		property.push_back(rLv() * rate(10, 20));
		property.push_back(eProPerty���);
		property.push_back(rLv() * rate(15, 30));
		break;
	case 21: //Ь
		property.push_back(eProPerty�ٶ�);
		property.push_back(rLv() * rate(10, 20));
		property.push_back(eProPerty����);
		property.push_back(rLv() * rate(15, 30));
		break;
	}
	return property;
}


vector<int> ItemManager::AutoItemPropertyBB(sItem2* item)
{
	vector<int> property;
	int lv = item->m_pItemData->GetLv();
	if (lv < 5)
	{
		lv = 5;
	}
	property.push_back(-1);//ǿ���ȼ�
	property.push_back(-1);//ʯͷ
	switch (item->GetType())
	{
	case 32:
		property.push_back(eProPerty����);
		property.push_back(4 + lv / 8 + ccc_auto_equip_rand(lv / 20 + 1));
		break;
	case 33:
		property.push_back(eProPerty�ٶ�);
		property.push_back(4 + lv / 5 + ccc_auto_equip_rand(lv / 10 + 1));
		break;
	case 34:
		property.push_back(eProPerty����);
		property.push_back(8 + lv * 3 / 5 + ccc_auto_equip_rand(lv / 6 + 1));
		break;
	}
	auto skills = cct::getSpecialSkills();
	skills =
	{
		eProPerty�˺�,
		eProPerty����,
		eProPerty��Ѫ,
		eProPertyħ��,
	};
	for (int i = 0; i < 3; ++i)
	{
 		if (rand() % 100 < 50)
		{
 			continue;
 		}
		int r = rand() % skills.size();
		property.push_back(skills[r]);
		if (skills[r] == eProPerty�˺�)
		{
			property.push_back(10 + ccc_auto_equip_rand(lv / 2 + 1));
		}
		else if (skills[r] == eProPerty����)
		{
			property.push_back(4 + ccc_auto_equip_rand(lv / 4 + 1));
		}
		else
		{
			property.push_back(30 + ccc_auto_equip_rand(lv * 3 / 2 + 1));
		}
		if (skills[r] == eProPerty�˺� || skills[r] == eProPerty����)
		{
			forr(skills, i)
			{
				if (skills[i] == eProPerty�˺� || skills[i] == eProPerty����)
				{
					skills.erase(skills.begin() + i);
				}
			}
		}
		else
		{
			skills.erase(skills.begin() + r);
		}
	}
	while (property.size() < 16/*12*/)
	{
		property.push_back(-1);
	}
	return property;
}
