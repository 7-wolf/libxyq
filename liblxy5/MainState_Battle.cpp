#include "_global.h"


void CMainState::FreeFightList(int i)
{
	if (!m_FightWorkList[i].isExist)return;

	cPropertyData* pPet;
	m_FightWorkList[i].m_pObj->GetPropertyData(pPet);
	if (pPet->m_Controler.CheckHaveBB())
	{
//		if (i < 10)
		{
			m_FightWorkList[i + 5].m_pObj->m_pIndex = 0;
			m_FightWorkList[i + 5].m_pObj->m_IndexType = 0;
			m_FightWorkList[i + 5].Free();
		}
	}
	else if (pPet->m_Controler.CheckBB())
	{
		m_FightWorkList[i].m_pObj->m_pIndex = 0;
		m_FightWorkList[i].m_pObj->m_IndexType = 0;
	}

	m_FightWorkList[i].Free();
	if (g_StateType != STATE_GAMEOVER)
	{
		FindObj();
	}

}





bool CMainState::ReadyToFight()
{
	if (m_Map.m_MapType < 1)return true;
	if (0 == m_Map.m_NumOfEmemyType)return true;
	for (int i = 10; i < 20; i++)
	{
		m_FightWorkList[i].isExist = false;
	}
	int num = 10; // AtutoGetEnemyNum();
	string mapname = "ս��";
	mapname += toString("%d", 1 + rand() % 3);
	// 		switch (rand()%5)
	// 		{
	// 		case 0:
	// 			mapname = "ս��1";
	// 			break;
	// 		case 1:
	// 			mapname = "ս��2";
	// 			break;
	// 		case 2:
	// 			mapname = "ս��3";
	// 			break;
	// 		case 3:
	// 			mapname = "ս��4";
	// 			break;
	// 		default:
	// 			mapname = "ս��5";
	// 			break;
	// 		};
	m_Mp3.Load(mapname);
	//		cct::get()->initControl();
	int pettype = m_Map.m_NumOfEmemyType;
	int k1 = 0;
	int BBType;  //�ٻ�������,0 ���� 1ͷ�� 2 ����
	string name2;
	bool pixiu = false;
	for (int i = 10; i < 10 + num; i++)
	{
		m_FightWorkList[i].m_pObj->SetDataType(INDEXTYEP_PET);
		cObj* pObj = m_FightWorkList[i].m_pObj;
		cPropertyData* pPetData;
		pObj->GetPropertyData(pPetData);
		k1 += 1;
		m_FightWorkList[i].isExist = true;
		m_FightWorkList[i].SetDie(false);
		cPet* pPet;
		pPet = (cPet*)pObj->m_pIndex;
// 		int dus = rand() % 100;
// 		if (dus < 20)  //20%�ļ��ʳ�ͷ��
// 		{
// 			BBType = 1;
// 			//ֻ�е���ɫ�ĵȼ�С�ڳ����ȼ�+10ʱ,���п��ܳ�����;
// 			if ((g_pCharacter->m_PcData.m_Lv) < m_Map.m_EnemyLv + 10)
// 				if (0 == dus)  //1%�ļ��ʳ�����
// 					BBType = 1/*2*/;
// 		}
// 		else BBType = 0;
		sAddPoint addpoint;
		int bbmode = g_pMainState->m_Map.m_EnemyList[rand() % pettype];
		BBType = 0;
		if (i == 10)
		{
			if (g_pMainState->m_TaskNormal.m_pNpc)
			{
				bbmode = g_pMainState->m_TaskNormal.m_pNpc->GetModeID();
				//	g_pMainState->m_TaskNormal.m_pNpc = 0;
			}
			else if (rand() % 100 < 7)
			{
				bbmode = e��̫��;
				BBType = 1;
			}
		}
		switch (BBType)
		{
		case 0:
		{
			AutoPet(pPet, bbmode, 30, m_Map.m_EnemyLv + rand() % 5);
			pObj->m_TrueName.SetString(pObj->GetName());
// 			pObj->m_TrueName.SetColor(RGB(1, 0xFF, 1));
// 			pObj->m_TrueName.SetBackColor(RGB(0, 0, 0));
			pPet->m_PetData.FillHpMp();
		}
			break;
		case 1:

		{
			AutoPet(pPet, bbmode, 50, m_Map.m_EnemyLv + rand() % 5 + rand() % 5 + 3);
			name2 = pObj->GetName();
			name2 += "ͷ��";
			pObj->m_TrueName.SetString(/*name2*/"�ƻ�������");
			pPet->m_PetData.Hide.d1 = 2;
			pixiu = true;
		}
			break;
		case 2:

		{
			AutoPet(pPet, bbmode, 100, 5);
			name2 = pObj->GetName();
			name2 += "����";
			pObj->m_TrueName.SetString(name2);

		}
			break;
		}
		pPetData->m_Controler.Set(1, 1, 0, 0, 1);
	}
	g_pMainState->m_Map.m_EnemyNum = num;
	g_StateType = STATE_FIGHT_MUSIC;
//	cct::get()->isBattle��Ұ = true;
	return (!pixiu);
}





bool CMainState::SwapFightOffset(int Original, int Target)
{
	m_FightWorkList[Original].Swap(m_FightWorkList[Target]);

	if (Original < 5 || Target < 5)
		m_PCHead.UpDateHead();//���½�ɫͷ��

	return true;
}




