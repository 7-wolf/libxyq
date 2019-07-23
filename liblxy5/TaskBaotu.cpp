#include "_global.h"

bool cTaskBaotu::Process(int stage)
{
	if (!m_bInit)Init();
	switch (stage)
	{
	case 0:
	{
		g_pMainState->m_Dialog.Reset();
		g_pMainState->m_Dialog.SetObj("��С��");
		m_Robber.m_name = AutoMakeName();
		m_Robber.m_mapname = m_MapNameList[rand() % m_MapNameList.size()];
		m_Robber.m_modeid = eɽ��;
		g_pMainState->m_Map.AutoGetPos(m_Robber.m_x, m_Robber.m_y, m_Robber.m_mapname);

		auto cbText = [&](string b_y)
		{
			ostringstream oss("");
			oss << "#R����";
			oss << m_Robber.m_name;
			oss << "#R";
			oss << ((b_y == "#B") ?  "\n" : " ������������ ");
			oss << "#R" << m_Robber.m_mapname;
			oss << "#R " + b_y;
			oss << m_Robber.m_x;
			oss << " ";
			oss << m_Robber.m_y;
			oss << b_y;
			return oss.str();
		};
		g_pMainState->m_Dialog.SetString(cbText("#Y"));
		g_pMainState->m_Dialog.OnOff(true);
		cObj* pObj = g_pMainState->FindObjByName("��С��");
		pObj->m_AutoRun = false;

		sJob job;
		job.m_Context = cbText("#B");
		job.m_Title = "�ر�ͼ";
		job.m_Time = 40;
		job.m_pTask = this;
		g_pMainState->m_Job.AddaJob(job);
		g_pMainState->m_TriggerObjMap.AddTask(this, 1, m_Robber);
		return true;
	}
		break;
	case 1:
	{
 		g_pMainState->AddEnemy(m_Robber.m_modeid, g_pMainState->getMaxLv(), eMP_���, m_Robber.m_name);
		int num = g_pMainState->AtutoGetEnemyNum(2, 5);
		for (int i = 1; i < num; i++)
		{
			g_pMainState->AddEnemy(eǿ��, g_pMainState->getAvgLv(), eMP_���, "����");

		}
		AddTriggerFightSuccess(3);
		g_StateType = STATE_FIGHT;
// 		cPropertyData* pPetdata;
// 		g_pMainState->m_FightWorkList[id].m_pObj->GetPropertyData(pPetdata);
// 		pPetdata->m_Controler.Set();
// 		SetMusic();
		return true;
	}
		break;
	case 3:

	{
		if (rand() % 100 < 0/*0 == rand()%10*/)
		{
			string nowname = m_Robber.m_name;
			m_Robber.m_name = AutoMakeName();

			m_Robber.m_mapname = m_MapNameList[rand() % m_MapNameList.size()];
			g_pMainState->m_Map.AutoGetPos(m_Robber.m_x, m_Robber.m_y, m_Robber.m_mapname);
			ostringstream oss;
			oss << "�����,��ֻ�Ǹ�Сආ�,�����ϴ���#R";
			oss << m_Robber.m_mapname;
			oss << "#R " << "#R" << m_Robber.m_x << " " << m_Robber.m_y << "#R";
			g_pMainState->FindObjByName(nowname)->Talk(oss.str());
			g_pMainState->m_Dialog.m_pObj = 0;
			g_pMainState->m_Map.RemoveNpc(nowname);
			m_Robber.m_modeid = 8;
			g_pMainState->m_TriggerObjMap.AddTask(this, 4, m_Robber);

			sJob job;
			job.m_Context = oss.str();
			job.m_Title = "��ͼ";
			job.m_Time = 40;
			job.m_pTask = this;
			g_pMainState->m_Job.AddaJob(job);
		}
		else
		{
			g_pMainState->m_Map.RemoveNpc(m_Robber.m_name);
			g_pMainState->m_TriggerObjMap.ReMove(this);
			g_pMainState->m_Job.ReMoveJob(this);
			if (1 || rand() % 100 < 80)
			{
				//�ñ�ͼ
				sItem2 item;
				item.Set(28, 6);
				item.m_Num = 1;
				g_pMainState->m_ItemManage.AutoItemProperty(&item);
			//	for (int i = 0; i < 18; ++i)
				{ 
					g_pMainState->awardItem(item, false);
				}
			}
			g_pMainState->awardklv(30, 10);

		}
// 		sFightWork& lis = g_pMainState->m_FightWorkList[g_pMainState->m_HeroID + 5];
// 		INT64 petexp = 0;
// 		int money = g_pCharacter->m_PcData.m_Lv * 10 + 2000 + rand() % 1000;
// 		if (lis.isExist&&!lis.CheckDie())
// 		{
// 			cPropertyData* petdata;
// 			lis.m_pObj->GetPropertyData(petdata);
// 			petexp = GetNormalFightExp(g_pCharacter->m_PcData.m_Lv, g_pCharacter->m_PcData.m_Lv);
// 		}
// 		SetJiangLi2(0, money, 0, (int)petexp);
		return true;
	}
		break;
	case 4:
	{
		cPropertyData* pPet;
		pPet = Add����EnemyF(g_pCharacter->m_PcData.m_Lv * 120, (ePetID)m_Robber.m_modeid, g_pCharacter->m_PcData.m_Lv, eMP_���, m_Robber.m_name);
		pPet->ComboRate.d1 += 50;
		for (int i = 0; i < 4; i++)
		{
			pPet = Add����EnemyF(g_pCharacter->m_PcData.m_Lv * 80, eǿ��, g_pCharacter->m_PcData.m_Lv);
			pPet->HitRate.d2 += 20;
		}
		SetMusic();
		g_StateType = STATE_FIGHT;
		AddTriggerFightSuccess(5);
		return true;
	}
		break;
	case 5:

	{
		g_pMainState->m_Map.RemoveNpc(m_Robber.m_name);
		g_pMainState->m_TriggerObjMap.ReMove(this);
		g_pMainState->m_Job.ReMoveJob(this);
		//���屦
		SetJiangLiItem(6 + rand() % 5, 27);
		SetJiangLi(3, true, 100, 0, 100, 200);
	}
		break;
	case 6:
	{
		g_pMainState->m_Tags.Add("���ڳ���һ������,�����������ܳ�������");
		int lv = g_pCharacter->m_PcData.m_Lv;
		string name = "Զ��";
		int petid = cct::getPetModel(45, 105);
		name += g_pMainState->m_PetDataManager.GetPetData(petid)->m_Name;
// 		int enemynum = g_pMainState->AtutoGetEnemyNum() - 1;
// 		cPropertyData* pPet = Add����EnemyF(lv * 80, petid, -1, eMP_���, name);
// 		pPet->AddSkill(ePS_�߼�����);
// 		for (int i = 0; i < enemynum; i++)
// 		{
// 			Add����EnemyF(lv * 40, (ePetID)(rand() % 40));
// 		}
// 		AddTriggerFightSuccess(7);


		auto p = g_pMainState->AddEnemy(petid, g_pMainState->getAvgLv() + 5, eMP_���, name);
//		p->m_Name = "Զ��" + p->m_Name;
//		g_pMainState->m_FightWorkList[p->m_IDinFightWorkList].m_pObj->SetTrueName(p->m_Name);
		int num = g_pMainState->AtutoGetEnemyNum(2, 5);
		for (int i = 1; i < num; i++)
		{
			petid = cct::getPetModel();
			name = g_pMainState->m_PetDataManager.GetPetData(petid)->m_Name + "ආ�";
			auto p2 = g_pMainState->AddEnemy(petid, g_pMainState->getAvgLv(), eMP_���, name);
//			p2->m_Name += "ආ�";
//			g_pMainState->m_FightWorkList[p2->m_IDinFightWorkList].m_pObj->SetTrueName(p2->m_Name);
		}
		AddTriggerFightSuccess(7);
		g_StateType = STATE_FIGHT;

	}
		break;
	case 7:
	{
		g_pCharacter->m_PcData.AddMoney(200000);
		g_pMainState->m_Tags.GetMoneyAndExp(200000);
// 		SetJiangLi(2, 1, 50, 0, 100, 200);
// 		if (0 == rand() % 10)
// 		{
// 			SetJiangLiItem(20, 24);
// 		}
	}
	default:
		break;
	}
	return false;
}

void cTaskBaotu::Init()
{
	if (m_bInit)return;
	m_bInit = true;
	//��ȡ�����б�
	m_Firstname = { "��", "Ǯ", "��", "��", "��", "��", "֣", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "ʩ", "��", "��", "��", "��", "��", "��", "κ", "��", "��", "��", "л", "��", "��", "��", "ˮ", "�", "��", "��", "��", "��", "��", "��", "��", "��", "��", "³", "Τ", "��", "��", "��", "��", "��", "��", "��", "��", "Ԭ", "��", "ۺ", "��", "ʷ", "��", "��", "��", "�", "Ѧ", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "ʱ", "��", "Ƥ", "��", "��", "��", "��", "��", "Ԫ", "��", "��", "��", "ƽ", "��", "��", "��", "��", "��", "˾��", "���", "�ĺ�", "��", "��", "��" };
	m_Secondname = { "һ", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "ԭ", "��", "��", "��", "��", "����", "����", "��", "��", "����", "֮��", "��", "����", "��", "��", "��", "ά", "����", "��", "��", "��", "����", "����", "��", "����", "��", "ʼ��", "��", "��ʯ", "��Τ", "Ԫ�", "��", "��ط", "��", "��", "��", "����", "����", "��Ԫ", "Ԩ��", "��Ԫ", "Ǩ", "��", "����", "����", "��", "��", "��", "����", "Ԩ", "��ط", "Ԫ�", "��", "��", "��", "��", "����", "��ΰ", "��", "ΰ��", "��", "����", "����", "����", "ǿ", "��", "����", "����", "��", "��", "��", "��", "��", "�İ�", "����", "ܿ", "��", "��", "����" };
	m_MapNameList = cct::getFields();
// 	ifstream File;
// 	ostringstream oss;
// 	oss << g_pathData << "ǿ������.txt";
// 	File.open(oss.str());
// 	int num;
// 	File >> num;
// 	string data;
// 	string str;
// 	for (int i = 0; i < num; i++)
// 	{
// 		File >> data;
// 		m_Firstname.push_back(data);
// 		str += "\"" + data + "\",";
// 	}
// 	Q_LOG("%s", str.c_str());
// 	str = "";
// 	File >> num;
// 	for (int i = 0; i < num; i++)
// 	{
// 		File >> data;
// 		m_Secondname.push_back(data);
// 		str += "\"" + data + "\",";
// 	}
// 	File.close();
// 	Q_LOG("%s", str.c_str());
// 	oss.str("");
// 	oss << g_pathData << "ǿ���ص�.txt";
// 	File.open(oss.str());
// 	File >> num;
// 	data = "";
// 	for (int i = 0; i < num; i++)
// 	{
// 		File >> str;
// 		m_MapNameList.push_back(str);
// 		data += "\"" + str + "\",";
// 	}
// 	File.close();
// 	Q_LOG("%s", data.c_str());
	m_type = 30;
}

std::string cTaskBaotu::AutoMakeName()
{
	string str;
	str = m_Firstname[rand() % m_Firstname.size()];
	str += m_Secondname[rand() % m_Secondname.size()];
	return str;
}

