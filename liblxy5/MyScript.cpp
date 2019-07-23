#include "_global.h"
#include "_txt.h"

bool cMyScript::ChangeMap(cObj* p)
{
	sAction* pAction = GetAction(p);
	p->m_Script.m_NowScript = 0;
	p->m_AutoRun = false;
	return g_pMainState->m_Map.LoadMap(pAction->pEntryUnoins[1].intData, pAction->pEntryUnoins[2].intData, (char*)pAction->pEntryUnoins[0].stringData.c_str());
}


bool cMyScript::Process(cObj* p)
{
	if (0 == p)return false;
	if (!p->m_bHaveScript)return false;
	if (!p->m_bScriptLoad)
	{
		if (p->m_ScriptPath == "��")
		{
			SetGlobalButton(p->m_ScriptOneType, p->m_ScriptOneId);
			return true;
		}
		else if (p->m_ScriptPath == "�һ�����")
		{
			g_pMainState->m_ZhiXian2.Process(p->m_ScriptOneType);
			return true;
		}
		else
		{
			p->m_bScriptLoad = true;
			//��ȡ�ű�
//			ostringstream oss;
//			oss << g_pathCommon<<p->m_ScriptPath<<".txt";
			if (!p->m_Script.LoadScript(/*oss.str()*/p->m_ScriptPath))
			{
				p->m_bHaveScript = false;
				return false;
			}
		}
	}
	if (m_ActionList.size() == 0)
	{
		// p->Talk(g_pMainState->m_TaskNormal.getNews());
		return false;
	}
	p->m_AutoRun = true;
	while (p->m_AutoRun)
	{
		if (p->m_Script.m_NowScript >= m_ActionList.size())return true;
		sAction*  pAction = GetAction(p);
		switch (pAction->ID)
		{
		case 0: TalkMySelf(p);break;//����
		case 1: NPCSelect2(p);break;
		case 2:  //2ѡ
		case 3:  //3ѡ
		case 4:  //4ѡ
			SelectNum(p, pAction->ID);break;
		case 5:EndScript(p);break;
		case 6:Case(p); break;
		case 7:Break(p);break;
		case 8:
			 Default(p);
			break;
		case 9: //����
			ChangeMap(p);
			return true;
		case  10:  SetPoint(p);break;//����ָ��λ��
		case 15:Talk(p);break;//�²�
		case 16: 
			if (1)
			{
				p->m_Script.m_NowScript += 1;
				p->m_AutoRun = true;
				SetGlobalButton(pAction->pEntryUnoins[0].intData, pAction->pEntryUnoins[1].intData,p);
			}
			break;//���ÿ���
		case 23:  //���
			p->m_Script.m_NowScript += 1;
			break;
		case 40:
			p->m_Script.m_NowScript += 1;
			p->m_AutoRun = false;
			break;
		case 41:
			g_pMainState->m_Dialog.OnOff(false);
			p->m_Script.m_NowScript += 1;
			p->m_AutoRun = false;
			break;
		default:
			ERRBOX;
			return 0;
		}
		
	}
	return true;
}
//�Ƿ���
bool cMyScript::NPCSelect2(cObj* p)
{
	g_pMainState->m_Dialog.Reset();
	sAction* pAction = GetAction(p);
	g_pMainState->m_Dialog.SetObj(p->m_TrueName.GetString());
	g_pMainState->m_Dialog.m_pObj =p;
	g_pMainState->m_Dialog.SetString(pAction->pEntryUnoins[0].stringData, "ȷ��", "ȡ��");
	g_pMainState->m_Dialog.OnOff(true);
	p->m_Script.m_NowScript += 1;
	p->m_AutoRun = false;
	return true;
}


bool cMyScript::LoadScript(string name)
{
	if (name.find("transmit") != string::npos)
	{
		int x = m_DialogueStyle % 0xFFFF;
		int y = m_DialogueStyle / 0xFFFF;
		name = name.substr(8);
		sAction act;
		act.ID = 9;
		act.pEntryUnoins = new sEntryUnion[act.NumOfEntryUnion = 3];
		act.pEntryUnoins[0].Type = SENTRYTYPE_STRING;
		act.pEntryUnoins[0].stringData = name;
		act.pEntryUnoins[1].Type = SENTRYTYPE_INT;
		act.pEntryUnoins[1].intData = x;
		act.pEntryUnoins[2].Type = SENTRYTYPE_INT;
		act.pEntryUnoins[2].intData = y;
		m_ActionList.push_back(act);
		sAction act2;
		act2.ID = 5;
		m_ActionList.push_back(act2);
		return true;
	}
	else if (name.find("ר����") != string::npos)
	{
		name = name.substr(name.length() - 3, 3);
		int shop = atoi(name.c_str());

		sAction act;
		act.ID = 23;
		act.pEntryUnoins = new sEntryUnion[1];
		act.pEntryUnoins[0].Type = SENTRYTYPE_INT;
		act.pEntryUnoins[0].intData = 0;
		m_ActionList.push_back(act);
		sAction act2;
		act2.ID = 16;
		act2.pEntryUnoins = new sEntryUnion[2];
		act2.pEntryUnoins[0].Type = SENTRYTYPE_INT;
		act2.pEntryUnoins[0].intData = 1002;
		act2.pEntryUnoins[1].Type = SENTRYTYPE_INT;
		act2.pEntryUnoins[1].intData = shop;
		m_ActionList.push_back(act2);

		sAction act3;
		act3.ID = 10;
		act3.pEntryUnoins = new sEntryUnion[2];
		act3.pEntryUnoins[0].Type = SENTRYTYPE_INT;
		act3.pEntryUnoins[0].intData = 0;
		act3.pEntryUnoins[1].Type = SENTRYTYPE_INT;
		act3.pEntryUnoins[1].intData = 1;
		m_ActionList.push_back(act3);
// 		{ "����ר����", {
// 				{ 23, // ��ǩ ID ~ 
// 				{ { 0, "" } } },
// 				{ 16, // ���ÿ��� �ĸ�~  ״̬~
// 				{ { 1002, "" }, { 75, "" } } },
// 				{ 10, // ָ����Ծ �������ű�ǩ~ ���� ~ 
// 				{ { 0, "" }, { 1, "" } } },
// 		} },
		return true;
	}

	map<int, int> scriptIds;
	const auto& scs = ctt::getScripts();
	for (const auto& scr : scs)
	{
		for (const auto& sc : scr.second)
		{
			const auto& it = scriptIds.find(sc.id);
			if (it == scriptIds.end())
			{
				scriptIds.insert(make_pair(sc.id, 1));
			}
			else
			{
				++it->second;
			}
		}
	}

	const auto& it = scs.find(name);
	if (it == scs.end())
	{
		return true;
	}

	
	const auto& scr = it->second;
	for (const auto& sc : scr)
	{
		sAction  Action;
		Action.ID = sc.id;
		Action.NumOfEntryUnion = sc.entries.size();
		if (Action.NumOfEntryUnion)
		{
			Action.pEntryUnoins = new sEntryUnion[Action.NumOfEntryUnion];
			forv(sc.entries, i)
			{
				const auto& e = sc.entries[i];
				auto& u = Action.pEntryUnoins[i];
				if (e.str.empty())
				{
					u.Type = SENTRYTYPE_INT;
					u.intData = e.value;
				}
				else
				{
					u.Type = SENTRYTYPE_STRING;
					u.stringData = e.str;
				}
			}
		}
		m_ActionList.push_back(Action);
	}
	return true;

	ifstream  File;
	File.open(/*g_pathCommon + */name + ".txt");
	if (!File)return false;
//	m_pActionTemplateList = &g_pMainState->m_ScriptTemplate.m_ActionTemplateList;
	cScript sc;
	sc.LoadActionTemplate("");

	
	m_ActionList.clear();
	while (true)
	{
		sAction  Action;
		File >> Action.ID;	
		File >> Action.NumOfEntryUnion;
		
		if (Action.ID == 25)//��ȡ�Ի���
		{
			int entrytype;
			File >> entrytype;

			string dialogscriptname;
			File >> dialogscriptname;
			ifstream File2;
			ostringstream oss;
//			oss << g_pathCommon;
			oss << dialogscriptname;
			oss << ".txt";
			File >> entrytype;

			int id;
			File >> id;
			File2.open(oss.str());
			//Ѱ�ҶԻ�ID
			int id2;
			File2 >> id2;
			while (id2!=id)
			{
				int k;
				File2 >> k;
				string dustbinstr;
				for (int i = -1; i < k; i++)
				{
					getline(File2, dustbinstr);
				}
				if (File.eof())
				{
					return false;
				}
				File2 >> id2;
			}
			//
			int k;
			File2 >> k;
			int chane;  //Ƶ��
			File2 >> chane;
			for (int i = 0; i < k; i++)
			{
				sAction  Action1;
				Action1.ID = 15;
				Action1.NumOfEntryUnion = 3;
				Action1.pEntryUnoins = new sEntryUnion[Action1.NumOfEntryUnion];
				Action1.pEntryUnoins[0].Type = 1;
				Action1.pEntryUnoins[1].Type = 1;
				Action1.pEntryUnoins[2].Type = 2;
				File2>>Action1.pEntryUnoins[0].stringData;
				File2 >> Action1.pEntryUnoins[1].stringData;
				Action1.pEntryUnoins[2].intData =chane ;
				m_ActionList.push_back(Action1);
			}
			continue;
		}

		if (File.eof())
		{
// 			static vector<vector<int>> s_map;
// 			bool isFound = false;
// 			forr(s_map, k)
// 			{
// 				if (s_map[k].size() == m_ActionList.size())
// 				{
// 					bool isSname = true;
// 					forr(m_ActionList, i)
// 					{
// 						if (m_ActionList[i].ID != s_map[k][i])
// 						{
// 							isSname = false;
// 							break;
// 						}
// 					}
// 					if (isSname)
// 					{
// 						isFound = true;
// 						break;
// 					}
// 				}
// 			}
// 			if (!isFound)
// 			{
// 				vector<int> as;
// 				forv(m_ActionList, i)
// 				{
// 					as.push_back(m_ActionList[i].ID);
// 				}
// 				s_map.push_back(as);
// 			}
// 
// 
// 			static int s_count = 0;
// 			if (++s_count == 119)
// 			{
// 				int x = 0;
// 			}


			ccc_log("}},");
			return true;
		}
		Action.pEntryUnoins = new sEntryUnion[Action.NumOfEntryUnion];
		if (Action.NumOfEntryUnion != sc.m_ActionTemplateList[Action.ID].NumOfEntryUnoin)
		{
			int x = 0;
		}

		if (m_ActionList.empty())
		{
			ccc_log("{ \"%s\",{", name.c_str());
		}

		ccc_log("{%d, // %s", Action.ID, sc.m_ActionTemplateList[Action.ID].Name.c_str());
		string str = "{";
		for (int k = 0; k < Action.NumOfEntryUnion; k++)
		{
			File >> Action.pEntryUnoins[k].Type;
			switch (Action.pEntryUnoins[k].Type)
			{
			case SENTRYTYPE_INT:
				File >> Action.pEntryUnoins[k].intData;
				if (sc.m_ActionTemplateList[Action.ID].pEntryUnoinsType[k] != 2)
				{
					int x = 0;
				}
				str += toString("{%d, \"\"},", Action.pEntryUnoins[k].intData);
				break;
			case SENTRYTYPE_FLOAT:
				File >> Action.pEntryUnoins[k].floatData;
				break;
			case SENTRYTYPE_BOOL:
				File >> Action.pEntryUnoins[k].intData;
				break;
			case SENTRYTYPE_STRING:
				if (1)
				{
					getline(File, Action.pEntryUnoins[k].stringData);
					if (Action.pEntryUnoins[k].stringData.size() < 3)
					{
						Action.pEntryUnoins[k].stringData = "";
						getline(File, Action.pEntryUnoins[k].stringData);
					}
					str += toString("{0, \"%s\"},", Action.pEntryUnoins[k].stringData.c_str());
				}
				if (sc.m_ActionTemplateList[Action.ID].pEntryUnoinsType[k] != 1)
				{
					int x = 0;
				}
				break;
			default:
				MessageBoxA(0, "δ֪����", "��ȡ", MB_OK);
				break;
			}
		}
		if (str.size() > 1)
		{
			str.pop_back();
		}
		str += "}},";
		ccc_log("%s", str.c_str());
		m_ActionList.push_back(Action);
	
	}
}

bool cMyScript::Case(cObj* p)
{
	p->m_AutoRun = true;
	sAction* pAction = GetAction(p);
	//�������ȷ��ѡ��
	if (p->m_ScriptSelect == pAction->pEntryUnoins[0].intData)
	{
		p->m_Script.m_NowScript+=1;
		return true;
	}
	else  //���������ȷ��ѡ��,��Ѱ��
	{

		p->m_Script.m_NowScript+=1;
		pAction = GetAction(p);
		//�ҵ���һ��CASE �� DEFAULT
		while ((6 != pAction->ID) && (8 != pAction->ID))
		{
			p->m_Script.m_NowScript += 1;
			pAction = GetAction(p);
			if (0 == pAction)
			{
				p->m_AutoRun = false;
				m_NowScript = 0;
				return true;
			}
		}
        return p->m_Script.Process(p);
	}
}

bool cMyScript::Default(cObj* p)
{
	p->m_AutoRun = true;
	p->m_Script.m_NowScript+=1;
	return	true;
}

bool cMyScript::Break(cObj* p)
{
	p->m_Script.m_NowScript += 1;
	sAction* pAction = GetAction(p);
	//�ҵ���һ��DEFAULT
	while (8 != pAction->ID)
	{
		p->m_Script.m_NowScript += 1;	
	}
	//�ҵ���һ��break;
	pAction = GetAction(p);
	while(7 != pAction->ID)
	{
		p->m_Script.m_NowScript += 1;
	}

	p->m_AutoRun = false;
	p->m_Script.m_NowScript += 1;
	return true;
}

cMyScript::cMyScript()
{
	//m_bHaveScript = false;
	m_NowScript = 0;
}

void cMyScript::Free()
{
	//m_bHaveScript = false;

	m_NowScript = 0;
	for (int i = 0; i < m_ActionList.size(); i++)
	{
		SAFE_DELETE_ARRAY(m_ActionList[i].pEntryUnoins);
	}
	vector<sAction> dustbin;
	m_ActionList.swap(dustbin);
}

bool cMyScript::SetPoint(cObj* p)
{
	sAction* pAction = GetAction(p);
	int k = pAction->pEntryUnoins[0].intData;
	while (true)
	{
		if (pAction->pEntryUnoins[1].intData)
		{//����
			p->m_Script.m_NowScript -= 1;
		}
		else
		{//����
			p->m_Script.m_NowScript += 1;
		}

		if (p->m_Script.m_NowScript < 0)
		{
			p->m_Script.m_NowScript = 0;
			return false;
		}

		sAction* pAction1 = GetAction(p);
		if (pAction1->ID == 23)
		{
			if (pAction1->pEntryUnoins[0].intData == k)
			{
				p->m_Script.m_NowScript += 1;
				p->m_AutoRun = false;
				return true;
			}
		}
	
	}
	return true;
}

sAction* cMyScript::GetAction(cObj* p)
{
	if (p->m_Script.m_NowScript > p->m_Script.m_ActionList.size() - 1 || p->m_Script.m_NowScript < 0)
	{
		ERRBOX;
		return 0;
	}
	return &p->m_Script.m_ActionList[p->m_Script.m_NowScript];
}





bool cMyScript::SetGlobalButton(int stype, int sid, cObj* p)
{
	
	switch (stype)
	{
	case 62://�ϼ�����
//		p->m_AutoRun = false;
		g_pMainState->m_TaskNormal.Process(12);
		break;
	case 1010:
	case 1011:
	case 1012:
	case 1015:
	case 1016:
		g_pMainState->m_ZhiXian.SetChapter(stype-1010);
		g_pMainState->m_ZhiXian.Process(sid);
		break;
	case 1014://ѡ��
		g_pMainState->m_ZhiXian.SetChapter(stype - 1010);
		g_pMainState->m_ZhiXian.ProcessSelect(sid);
		break;
	case 1013://����
		g_pMainState->m_ZhiXian.Process3(sid);
		break;
	case 2001:
		if (1)
		{
			cPcData* pdata = &g_pCharacter->m_PcData;
			vector<int>  idlist;
			int money=0;
			int id;
			for (int i = pdata->m_NumofBB -1; i >= 0; --i)
			{
				if (pdata->m_FightPetID == i)
				{
					continue;
				}
				id = pdata->m_pPets[i]->m_PetData.modeid;
				if (id == e�󺣹�)
				{	
					money += 250;
					pdata->RemovePet(i, true);
				}
				else if (id == e����)
				{
					money += 350;
					pdata->RemovePet(i, true);
				}
				else if (id == e��ë��)
				{
					money += 500;
					pdata->RemovePet(i, true);
				}
			}
			if (money)
			{
				pdata->m_Money[0] += money;
				g_pMainState->m_Tags.GetMoneyAndExp(money);
			}
		}
		break;
	case 1000://�ܼ�
		if (1)
		{
			cObj* pObj= g_pMainState->m_pNowSelect;
			int huanjin = g_pMainState->m_FangWu.GetHuanJin();
			ostringstream oss;
			oss << "����,��ǰ������:#R";
			oss << huanjin;
			oss << "#R��ģ:#R";
			oss << g_pMainState->m_FangWu.GetGuiMo();
			oss << "#R������ʲô�Ը�?";
			string context;
			context = oss.str();

			g_pMainState->m_Dialog.Reset();
			g_pMainState->m_Dialog.SetObj(pObj);

			g_pMainState->m_Dialog.SetString(context, "��Ϣ", "����լ��", "��������", "�����һ���Ҿ�");
			g_pMainState->m_Dialog.SetTrigger(&g_pMainState->m_TaskNormal, -1,8,118,119,120);
			g_pMainState->m_Dialog.OnOff(true);
		}
		break;
	case 30://��ͼ
		if (1)
		{
			if (g_pMainState->m_Job.CheckHaveJob("�ر�ͼ"))
			{
				g_pMainState->m_Dialog.m_pObj->Talk("��������ǰ�Ŵ�������");
				return true;
			}
			g_pMainState->m_TaskBaoTu.CheckInit();
			g_pMainState->m_TaskBaoTu.Process(sid);
		
		}
		break;
	case 11:
		if (1)
		{
			g_pMainState->m_TaskBangPai.CheckInit();
			g_pMainState->m_TaskBangPai.Process(sid);
		}
		break;
	case 12:
		g_pMainState->m_LearnBangPaiSkill.OnOff(true);
		break;
	case 13:
		g_pMainState->m_LearnXiuLian.CheckInit();
		g_pMainState->m_LearnXiuLian.setBB(true);
		g_pMainState->m_LearnXiuLian.OnOff(true);
		break;
	case 14:
		g_pMainState->m_LearnXiuLian.CheckInit();
		g_pMainState->m_LearnXiuLian.setBB(false);
		g_pMainState->m_LearnXiuLian.OnOff(true);
		break;
	case 15:
		break;
	case 16:
		g_pMainState->m_YingHang.SetMode(sid);
		g_pMainState->m_YingHang.OnOff(true);
		break;
	case 1040://ץ��
		g_pMainState->m_TaskZhuaGui.Process(0);
		break;
	case 1001://Ⱦɫ
		if (1)
		{
			g_pMainState->m_InterfaceRanSe.SetMode(p->m_ScriptSelect,g_pMainState->m_HeroID);
			g_pMainState->m_InterfaceRanSe.OnOff(true);
		}
		break;
	case 1002:
		if (1)
		{
			g_pMainState->m_InterFaceBuy.Open(sid);
		}
		break;
	case 1003:
		g_pMainState->m_taskSM.Process(sid); break;
		break;
	case 1004://���ܵ���
		switch (sid)
		{
		case 0://����װ��
		case 1://�չ�װ��
		case 2://��̨����
		case 3:
			if (1)
			{
				if (g_pMainState->m_Map.m_MapName == "�������")
				{
//					g_pMainState->m_InterfaceJianDing.SetMode(3);
					g_pMainState->m_Dazao.m_MoneyNeed = 0;
					g_pMainState->m_Dazao.OnOff(true);
				}
				else
				{
					g_pMainState->m_InterfaceJianDing.SetMode(sid);
					g_pMainState->m_InterfaceJianDing.OnOff(true);
				}
//				g_pMainState->m_InterfaceJianDing.OnOff(true);
			}
			break;
		
		default:
			break;
		}
		break;
	case 1005:
		if (1)
		{
			int price = 0;
			const auto& fs = g_pMainState->m_Friend._friends;
			for (int k = fs.size() - 1; k >= 0; --k)
			{
				cPcData& pc = ((cCharacter*)fs[k].obj->m_pIndex)->m_PcData;
				for (int i = pc.m_NumofBB - 1; i >= 0; --i)
				{
					auto& p = pc.m_pPets[i]->m_PetData;
					if (p.m_HP == p.HPMax.GetData() && p.m_MP == p.MPMax.GetData())
					{
						continue;
					}
					p.FillHpMp();
					price += p.m_Lv * 10;
				}
			}
			if (price > 0)
			{
				g_pMainState->m_Tags.GetMoneyAndExp(-price);
			}
			g_pCharacter->m_PcData.AddMoney(-price);
			g_pMainState->m_Dialog.m_pObj->Talk("�ٻ������Ѿ��ָ�����");
			break;
			for (int i = 0; i < g_pCharacter->m_PcData.m_NumofBB; i++)
			{
				cPetData& petdata = g_pCharacter->m_PcData.m_pPets[i]->m_PetData;
				if (petdata.m_HP == petdata.HPMax.GetData() && petdata.m_MP == petdata.MPMax.GetData())continue; //û���˵��ٻ��޲�����
				price += petdata.m_Lv*((petdata.m_NumofBBSkill) * 5 +petdata.m_ZiZhi.grow+petdata.m_ZiZhi.hp/200) + 1;
			}

			for (int i = 0; i < g_pCharacter->m_PcData.m_NumofBB; i++)
			{
				g_pCharacter->m_PcData.m_pPets[i]->m_PetData.FillHpMp();
			}
			if (g_pCharacter->m_PcData.AddMoney(-price))
			{
				ostringstream oss;
				oss << "������#R";
				oss << price;
				oss << "#R��,����ٻ����Ѿ��ָ�����";
				g_pMainState->m_Dialog.m_pObj->Talk(oss.str());
			}
			else
			{
				g_pMainState->m_Dialog.m_pObj->Talk("��ξ����յ��,����Ҫ�ƴ�����ٻ��ް�");
			}
		}
		break;
	case 1006:
		for (int i = 0; i < 5; ++i)
		{
			if (g_pMainState->m_FightWorkList[i].isExist)
			{
				g_pMainState->m_FightWorkList[i].m_pObj->getPropertyData()->FillHpMp();
			}
		}
		if (1)
		{	
			switch (sid)
			{
			case 0://�Ƶ��ϰ�
				if (g_pCharacter->m_PcData.AddMoney(-500, 0,0,0))
				{
					g_pMainState->m_Dialog.m_pObj->Talk("��ӭ�´�����");
				}
				else
				{
					g_pCharacter->m_PcData.m_Money[0] += 500;
					g_pMainState->m_Dialog.m_pObj->Talk("����,��#R500����#R��������,�������");
				}
				break;
			case 1://�³���
				g_pMainState->m_Dialog.m_pObj->Talk("���Ѿ��ָ�����");
				break;
			default:
				ERRBOX;
				break;
			}
			
		}
		break;
	case 1007:
		if (1)
		{
//			g_pMainState->m_InterFaceBuyPet.Init2(0, 0, 0);
			g_pMainState->m_InterFaceBuyPet.OnOff(true);
		}
		break;
	case 1017:
		if (1)
		{
			g_pMainState->_uiCangKu.OnOff(true);
		}
		break;
	case 1018:
		if (1)
		{
			g_pMainState->_uiChangeCharacter.OnOff(true);
		}
		break;
	case 1008:
		if (1)
		{
			if (!sid)
			{
				cObj* obj = g_pMainState->FindObjByName("���ɴ�����");
				g_pMainState->m_Dialog.Reset();
				if (g_pCharacter->m_PcData.m_MengPaiID > -1)
				{

					if (g_pCharacter->m_PcData.m_Lv < 40)
					{
						g_pMainState->m_Dialog.SetObj(obj);
						g_pMainState->m_Dialog.SetString("Ҫ��������?", "��", "��");
						g_pMainState->m_Dialog.SetTrigger(&g_pMainState->m_TaskNormal,-1, 5);
						g_pMainState->m_Dialog.OnOff(true);
					}
					else obj->Talk("�޷�����40�����ϵ���,���Լ�ʹ�ü��ܻ�ȥ");
				}
				else
				{
					obj->Talk("�������ˣ��Լ���·��");
// 					g_pMainState->m_Dialog.SetObj(obj);
// 					cMengPai* pMengpai = g_pMainState->m_SkillManager.m_MengPaiManager.m_MengPai;
// 					switch (g_pCharacter->GetRace())
// 					{
// 					case 0:
// 					case 2://��					
// 						g_pMainState->m_Dialog.SetString("��ѡ��Ҫȥ������?", pMengpai[8].m_Name, pMengpai[9].m_Name, pMengpai[10].m_Name, pMengpai[11].m_Name);
// 						break;
// 					case 1:
// 					case 3://��
// 						g_pMainState->m_Dialog.SetString("��ѡ��Ҫȥ������?", pMengpai[4].m_Name, pMengpai[5].m_Name, pMengpai[6].m_Name, pMengpai[7].m_Name);
// 						break;
// 					case 4:
// 					case 5:
// 					case 6://��
// 						g_pMainState->m_Dialog.SetString("��ѡ��Ҫȥ������?", pMengpai[0].m_Name, pMengpai[1].m_Name, pMengpai[2].m_Name, pMengpai[3].m_Name);
// 						break;
// 					}
// 					g_pMainState->m_Dialog.SetTrigger(&g_pMainState->m_TaskNormal,-1, 6,6,6,6);
// 					g_pMainState->m_Dialog.OnOff(true);
				}
			}
			else
			{
				if (g_pCharacter->m_PcData.m_MengPaiID >-1)
				{
					string mapname = g_pMainState->m_Map.m_MapName;
					string mapname2 = g_pMainState->m_SkillManager.m_MengPaiManager.GetMengPai(g_pCharacter->m_PcData.m_MengPaiID)->m_XunLuoMapName;
					if (0 == mapname2.compare(mapname))
					{
						g_pMainState->m_Dialog.Reset();
						g_pMainState->m_Dialog.SetObj(g_pMainState->m_pNowSelect);
						g_pMainState->m_Dialog.SetString("Ҫ�س�����","��","��");
						g_pMainState->m_Dialog.SetTrigger(&g_pMainState->m_TaskNormal,-1, 7);
						g_pMainState->m_Dialog.OnOff(true);
						return true;
					}
					g_pMainState->m_pNowSelect->Talk("�����ͷǱ��ŵ���");
					return true;
				}
				
				g_pMainState->m_Dialog.Reset();
				g_pMainState->m_Dialog.SetObj(g_pMainState->m_pNowSelect);
				g_pMainState->m_Dialog.SetString("Ҫ�س�����", "��", "��");
				g_pMainState->m_Dialog.SetTrigger(&g_pMainState->m_TaskNormal,-1, 7);
				g_pMainState->m_Dialog.OnOff(true);
				return true;
			}
		}
		break;
	case 1009:
		if (g_pMainState->m_FangWu.GetGuiMo() < 0)
		{
			g_pMainState->m_Dialog.m_pObj->Talk("����,���ס��.......");
			return true;
		}
		g_pMainState->m_FangWu.GoIn();
		return true;
	case 1019:
		if (g_pMainState->m_Job.CheckHaveJob(g_pMainState->m_TaskHuoDong.m_type/*"���ɴ���"*/))
		{
			g_pMainState->m_Dialog.m_pObj->Talk("��Ѿ���ʼ");
			return true;
		}
		g_pMainState->m_TaskHuoDong.Start(���ɴ���);
//		g_pMainState->m_TaskHuoDong.SetTrigger(&g_pMainState->m_taskSM, -1, c_MenPaiNumber);
		return true;
	case 1020: // �Բ�ͷ
		if (sid == 1)
		{
			g_pMainState->award(0, 0, g_GlobalValues[20] * (1 + g_GlobalValues[20] / 86400));    
		}
		else if (sid == 0)
		{
			g_pMainState->award(g_GlobalValues[20] * (1 + g_GlobalValues[20] / 86400));
		}
		g_pMainState->resetLangTime();
		return true;
	case 1021: // ������
	{
		if (g_pCharacter->m_PcData.m_NumofBB == g_pCharacter->m_PcData.m_pPets.size())
		{
			g_pMainState->m_Tags.Add("�ٻ���������");
			return true;
		}
		vector<int> ps = { eСѾѾ, eС��Ů, eС���� };
		cPet* pet = new cPet;
		sid = ps[sid];
		pet->SetData(&g_pMainState->m_PetDataManager.m_PetList[sid]);
		auto& p = pet->m_PetData;
		p.Load(sid, true, true);
		p.PointRemain = cct::PointRemian;
		p.apply();
		p.FillHpMp();
		g_pCharacter->m_PcData.AddPet(pet);
		g_pMainState->m_Tags.Add("��������" + pet->GetData()->m_Name);
	}
		return true;
	case 1022: // ��үү
	{
		if (g_pCharacter->m_PcData.m_NumofBB == g_pCharacter->m_PcData.m_pPets.size())
		{
			g_pMainState->m_Tags.Add("�ٻ���������");
			return true;
		}
		vector<int> ps = { eСëͷ, eС����, eСħͷ };
		cPet* pet = new cPet;
		sid = ps[sid];
		pet->SetData(&g_pMainState->m_PetDataManager.m_PetList[sid]);
		auto& p = pet->m_PetData;
		p.Load(sid, true, true);
		p.PointRemain = cct::PointRemian;
		p.apply();
		p.FillHpMp();
		g_pCharacter->m_PcData.AddPet(pet);
		g_pMainState->m_Tags.Add("��������" + pet->GetData()->m_Name);
	}
		return true;
	case 1024:
		g_pMainState->m_TaskBangPai.Process(sid);
		return true;
	}
	return true;
}

bool cMyScript::Talk(cObj* p)
{
	sAction* pAction = GetAction(p);
	m_DialogueStyle = pAction->pEntryUnoins[2].intData;
	//����Ի�
	if (m_DialogueStyle == -1)
	{
		g_pMainState->m_Dialog.Reset();
		g_pMainState->m_Dialog.SetObj(pAction->pEntryUnoins[0].stringData);
		g_pMainState->m_Dialog.m_pObj = p;
		g_pMainState->m_Dialog.m_ContextList.SetFaceText(pAction->pEntryUnoins[1].stringData,g_pMainState->m_hFont[0],470);
		g_pMainState->InterfaceSetShow(&g_pMainState->m_Dialog, true);

		//����λ��
		int  y = g_pMainState->m_Dialog.m_DialogBack.m_Picture.m_y + 20;
		int xStart = g_pMainState->m_Dialog.m_DialogBack.m_Picture.m_x + 5;
		for (int i = 0; i < g_pMainState->m_Dialog.m_ContextList.m_LineNum; i++)
		{
			y += g_pMainState->m_Dialog.m_ContextList.m_TextLineList[i].m_Height + 2;
			cText& text = g_pMainState->m_Dialog.m_ContextList.m_TextLineList[i].m_line;
			text.SetXY(xStart, y - 18);
			if (1 == g_pMainState->m_Dialog.m_ContextList.m_LineNum && 0 == g_pMainState->m_Dialog.m_ContextList.m_TextLineList[i].m_NumFace)
			{
			}
			else
			{
				//����б���,����ʾ����
				for (int j = 0; j < g_pMainState->m_Dialog.m_ContextList.m_TextLineList[i].m_NumFace; j++)
				{
					g_pMainState->m_Dialog.m_ContextList.m_TextLineList[i].m_Face[j].m_x = xStart + g_pMainState->m_Dialog.m_ContextList.m_TextLineList[i].m_xFace[j];
					g_pMainState->m_Dialog.m_ContextList.m_TextLineList[i].m_Face[j].m_y = y + 2;
				}
			}
		}

	}

	//
	if (m_DialogueStyle > -1)
	{
		g_pMainState->m_Channel.m_pCurrentChannel = &g_pMainState->m_Channel.m_Channel[m_DialogueStyle];
		m_SleepTime = 210;
		g_pMainState->m_Channel.AddNewString(pAction->pEntryUnoins[1].stringData, pAction->pEntryUnoins[0].stringData,pAction->pEntryUnoins[2].intData);
		//Sleep(60);
	}

	p->m_Script.m_NowScript += 1;
	p->m_AutoRun = false;
	return true;
}

bool cMyScript::SelectNum(cObj* p,int num)
{
	sAction* pAction = GetAction(p);
	g_pMainState->m_Dialog.Reset();
	g_pMainState->m_Dialog.SetObj(pAction->pEntryUnoins[0].stringData);
	g_pMainState->m_Dialog.m_pObj = p;  //???????????
	switch (num)
	{
	case 2:
		g_pMainState->m_Dialog.SetString(pAction->pEntryUnoins[1].stringData, pAction->pEntryUnoins[2].stringData, pAction->pEntryUnoins[3].stringData);
		break;
	case 3:
		g_pMainState->m_Dialog.SetString(pAction->pEntryUnoins[1].stringData, pAction->pEntryUnoins[2].stringData, pAction->pEntryUnoins[3].stringData,  pAction->pEntryUnoins[4].stringData);
		break;
	case 4:
		g_pMainState->m_Dialog.SetString(pAction->pEntryUnoins[1].stringData, pAction->pEntryUnoins[2].stringData, pAction->pEntryUnoins[3].stringData, pAction->pEntryUnoins[4].stringData, pAction->pEntryUnoins[5].stringData);
		break;
	default:
		ERRBOX;
		break;
	}
	g_pMainState->m_Dialog.OnOff(true);
	p->m_Script.m_NowScript += 1;
	p->m_AutoRun = false;
	return true;
}

bool cMyScript::EndScript(cObj* p)
{
	p->m_Script.Free();
	p->m_AutoRun = false;
	return true;
}

bool cMyScript::TalkMySelf(cObj* p)
{
	sAction* pAction = GetAction(p);
	g_pMainState->m_Dialog.Reset();
	g_pMainState->m_Dialog.SetObj(p->m_TrueName.GetString());
	g_pMainState->m_Dialog.SetString(pAction->pEntryUnoins[0].stringData);
	g_pMainState->m_Dialog.OnOff(true);
	p->m_Script.m_NowScript += 1;
	p->m_AutoRun = false;
	return true;
}








