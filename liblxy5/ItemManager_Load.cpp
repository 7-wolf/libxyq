#include "_global.h"
#include "_txt.h"


//#define ccc_checkwas

bool ItemManager::Init()
{
	if (m_bInit)return true;
	m_bInit = true;
	m_MagicAddHP.Load(0x77D2082D);
	m_MagicAddMP.Load(0x3E912705);
	m_MagicAddHPMP.Load(0x808CEB72);

	cWasFile was;

	sItem it;
	it.m_Price = 100;
	const auto& ts = ctt::getItems();
	for (const auto& t : ts)
	{
		it.m_Type = (int)t.e;
		it.m_ID = t.id;
		it.m_Name = t.name;
		it.m_SmallHead = t.small;
		it.m_BigHead = t.big;
		it.m_Text = t.desc;
		if (t.e == ctt::eItem::����f)
		{
			it.m_UseType = 7;
		}
		if ((t.e <= ctt::eItem::����f || (t.e >= ctt::eItem::�޽�j && t.e <= ctt::eItem::ɡɡs)) && it.m_ID >= 9 && it.m_ID <= 14)
		{
		//	it.m_ID = (it.m_ID + 2 * (it.m_ID - 9));
		//	it.SetLv(it.m_ID);
			m_ItemList[it.m_Type].push_back(it);
		//	++it.m_ID;
			m_ItemList[it.m_Type].push_back(it);
		//	++it.m_ID;
			m_ItemList[it.m_Type].push_back(it);
		}
// 		else if (t.e == ctt::eItem::����h || t.e == ctt::eItem::��Ȧx || t.e == ctt::eItem::����h)
// 		{
// 			if (it.m_ID == 0)
// 			{
// 				continue;
// 			}
// 			else if (it.m_ID == )
// 			{
// 				it.m_ID = it.m_ID - 1;
// 			}
// 		}
		else 
		{
			if (t.e == ctt::eItem::��Ƭk)
			{
				int size = m_ItemList[it.m_Type].size();
				if (size == (int)eModel::����dx/* || size == (int)eModel::С��xx*/)
				{
					it.m_SmallHead = 0xD5D3D1A7;
// 					if (size == (int)eModel::С��xx)
// 					{
// 						it.m_BigHead = m_ItemList[it.m_Type][(int)eModel::����dx].m_BigHead;
// 					}
				}
				else if (size == (int)eModel::�Ʋ�ͯ��sc)
				{
					it.m_SmallHead = 0x404532E8;
				}
				else if (size == (int)eModel::����ts)
				{
					it.m_SmallHead = 0x66E05E50;
				}
				else if (size == (int)eModel::С����xb)
				{
//					it.m_SmallHead = m_ItemList[it.m_Type][(int)eModel::����bz].m_SmallHead;
					it.m_BigHead = m_ItemList[it.m_Type][(int)eModel::����bz].m_BigHead;
				}
				else if (size == (int)eModel::С����xp)
				{
//					it.m_SmallHead = m_ItemList[it.m_Type][(int)eModel::����pp].m_SmallHead;
					it.m_BigHead = m_ItemList[it.m_Type][(int)eModel::����pp].m_BigHead;
				}
			}
			m_ItemList[it.m_Type].push_back(it);
			if (t.e == ctt::eItem::��Ƭk && m_ItemList[it.m_Type].size() == c_PetNumber - 2)
			{
			}
		}


#ifdef ccc_checkwas
		was.Load(it.m_SmallHead);
		was.Load(it.m_BigHead);
#endif
	}



	for (const auto& fb : { 4, 11, 12, 13, 14, 15, 16, 34 })
	{
		m_ItemList[(int)ctt::eItem::����f][fb].m_UseType = 0;
	}

	const auto& ws = ctt::getWeapons();
	const auto& tiggerDie = ctt::getWeapon���Ợ������s();
	for (const auto& w : ws)
	{
		int i = -1;
		for (const auto& a : w.actions)
		{
			int type = (int)w.e;
			if (type >= 42)
			{
				type -= 27;
			}
			if (m_pWeaponList2[type][++i].empty())
			{
				m_pWeaponList2[type][i].resize(2);
			}
			auto& data = m_pWeaponList2[type][i][0];
			auto& data2 = m_pWeaponList2[type][i][1];
			data.m_attack = a.action.atk;
			data.m_attack2 = a.action.atk/*2*/;
			data.m_defend = a.action.def;
			data.m_dead = a.action.dead;
			data.m_fstand = a.action.await;
			data.m_magic = a.action.maigc;
			data.m_return = a.action.back;
			data.m_run = a.action.go;
			data.m_stand = a.action.stand;
			data.m_walk = a.action.walk;
			data.m_suffer = a.action.atkd;
			data.Master = (int)a.role;
			data.MasterPos = (int)a.actionsIndex;

			if (type < 15)
			{

				data2.m_attack = a.action2.atk;
				data2.m_attack2 = a.action2.atk/*2*/;
				data2.m_defend = a.action2.def;
				if (cct::getINT(6) && w.e == ctt::eItem::����f)
				{
					data2.m_dead = tiggerDie[i];
				}
				else
				{
					data2.m_dead = a.action2.dead;
				}
				data2.m_fstand = a.action2.await;
				data2.m_magic = a.action2.maigc;
				data2.m_return = a.action2.back;
				data2.m_run = a.action2.go;
				data2.m_stand = a.action2.stand;
				data2.m_walk = a.action2.walk;
				data2.m_suffer = a.action2.atkd;
				data2.Master = (int)a.role2;
				data2.MasterPos = (int)a.actionsIndex2;
			}
			else
			{
				if (type == 15)
				{
					swap(data.m_magic, data.m_attack);
				}
				data2 = data;
				
#ifdef ccc_checkwas
				was.Load(data.m_attack);
				was.Load(data.m_attack2);
				was.Load(data.m_defend);
				was.Load(data.m_dead);
				was.Load(data.m_fstand);
				was.Load(data.m_magic);
				was.Load(data.m_return);
				was.Load(data.m_run);
				was.Load(data.m_stand);
				was.Load(data.m_walk);
				was.Load(data.m_suffer);

				was.Load(data2.m_attack);
				was.Load(data2.m_attack2);
				was.Load(data2.m_defend);
				was.Load(data2.m_dead);
				was.Load(data2.m_fstand);
				was.Load(data2.m_magic);
				was.Load(data2.m_return);
				was.Load(data2.m_run);
				was.Load(data2.m_stand);
				was.Load(data2.m_walk);
				was.Load(data2.m_suffer);
#endif
			}
		}
	}

	// װ���ȼ�
	for (int i = 0; i < 22; i++)
	{
		for (int j = 0; j < m_ItemList[i].size(); j++)
		{
			m_ItemList[i][j].m_ID = j;
			m_ItemList[i][j].SetLv(GetlvByID(i, j));
		}
	}
	for (int i = 32; i <= 34; i++)
	{
		for (int j = 0; j < m_ItemList[i].size(); j++)
		{
			m_ItemList[i][j].m_ID = j;
			if (j == 0)
			{
				m_ItemList[i][j].SetLv(m_ItemList[i].size() * 10 - 5);
				m_ItemList[i][j].m_Text = "�Ǳ��ع�";
			}
			else
			{
				m_ItemList[i][j].SetLv(j * 10 - 5);
			}
		}
	}
	for (int i = 42; i <= 44; i++)
	{
		for (int j = 0; j < m_ItemList[i].size(); j++)
		{
			m_ItemList[i][j].m_ID = j;
			m_ItemList[i][j].SetLv(GetlvByID(i, j));
		}
	}


	const auto& zqzs = ctt::getZqzss();
	const auto& cTable = ctt::getColors();
	forv(zqzs, k)
	{
		auto& t = zqzs[k];
		it.m_Type = (int)ctt::eItem::����z;
		it.m_ID = t.id;
		it.m_Name = t.name;
		it.m_SmallHead = t.small;
		it.m_BigHead = t.big;
		m_ItemList[it.m_Type].push_back(it);

		auto& zs = m_ZuoQiZhuangShiList[k];
		zs.NodeStand = t.stand;
		zs.NodeWalk = t.walk;
		zs.m_ColorID = t.color;
		const auto& iter = cTable.find(zs.m_ColorID);
		if (iter != cTable.end())
		{
			zs.m_ColorID = iter->second;
		}

#ifdef ccc_checkwas
		was.Load(it.m_SmallHead);
		was.Load(it.m_BigHead);
		was.Load(zs.NodeStand);
		was.Load(zs.NodeWalk);
		was.Load(zs.m_ColorID);
#endif
		forv(zs.Stand, i)
		{
			zs.Stand[i] = 0;
			zs.Walk[i] = 0;
		}

		forv(t.masters, i)
		{
			const auto& m = t.masters[i];
			zs.Stand[(int)m.master] = m.stand;
			zs.Walk[(int)m.master] = m.walk;

#ifdef ccc_checkWas
			was.Load(m.stand);
			was.Load(m.walk);
#endif
		}
	}

	//��԰����Դ,��ʱ����
	sJiaJuData data;
	const auto& jjs = ctt::getJiajus();
	forv(jjs, k)
	{
		const auto& jj = jjs[k];
		it.m_Type = (int)jj.type;
		it.m_ID = jj.id;
		it.m_Name = jj.desc;
		it.m_SmallHead = jj.small;
		it.m_BigHead = jj.big;
		it.SetLv(0);
		if (it.m_Name == "�ݱ��̺" || it.m_Name == "�׺�չ����" || it.m_Name == "��Ƥ��̺" || it.m_Name == "�鲼��̺" || 
			it.m_Name == "Ϧ��ɽˮͼ" || it.m_Name == "�ͻ���ɽͼ" || it.m_Name == "��֮�鱴ͼ" || it.m_Name == "�ƶн�����" || 
			it.m_Name == "��˹��̺" || it.m_Name == "�׻�Ƥ̺" || it.m_Name == "��˰���ͼ" || it.m_Name == "��֮����̺" || 
			it.m_Name == "�����÷۶���")
		{
			it.SetLv(1);
		}
		else if (it.m_Name == "̤��ͼ")
		{
			it.SetLv(2);
		}
		else if (it.m_Name == "�Ứ�ذ�" || it.m_Name == "��ľ�ذ�" || it.m_Name == "��ľ�ذ�" || 
			it.m_Name == "��֮ε��ʯש" || it.m_Name == "�������λü�԰")
		{
			it.SetLv(3);
		}
		else if (it.m_Name == "����������" || it.m_Name == "��������������")
		{
			it.SetLv(4);
		}
		else if (it.m_Name == "��֮��ɫ��")
		{
			it.SetLv(5);
		}
		it.m_Text = jj.name;
		m_ItemList[it.m_Type].push_back(it);

#ifdef ccc_checkwas
		was.Load(it.m_SmallHead);
		was.Load(it.m_BigHead);
#endif
		const auto& js = jj.uids;
		data.num = js.size();
		data.m_data.clear();
		forv(js, i)
		{
			data.m_data.push_back(js[i]);
#ifdef ccc_checkwas
			was.Load(js[i]);
#endif
		}
		m_JiaJuData[it.m_Type - (int)ctt::eItem::һ��y].push_back(data);
	}


#if 0

	cct::get()->pushWdf("��ҩ��", 0x77D2082D);
	cct::get()->pushWdf("��ҩ��", 0x3E912705);
	cct::get()->pushWdf("��ҩ��", 0x808CEB72);

	string myWeaponPath = g_pathData + "����//";
	string myEquipPath = g_pathData + "װ��//";
#pragma omp parallel sections
	{
#pragma omp  section
		{
			ifstream File;
			int id, num;
			ostringstream oss;
			oss << myWeaponPath << "����.txt";
			File.open(oss.str());
			int typenum;
			File >> typenum;
			vector<string> weaponNames = { "��", "��", "ǹ", "��", "��", "��",
				"צ", "��", "Ʈ��", "��", "��", "˫��", "��", "��", "��" };
			for (int j = 0; j < typenum; j++)
			{
				File >> id;
				File >> num;
				string dustbin;
				for (int i = 0; i < 11; i++)
				{
					vector<sWeaponData>& data = m_pWeaponList2[j][i];
					data.resize(num);
					for (int k = 0; k < num; k++)
					{
						cct::get()->strDescTemp = weaponNames[j] + toString("%d_%d_", i, k);
						data[k].Read(File);
						if (k < 2 || (k == 2 && cct::get()->isPushRole15))
						{
							// 		vector<string> weaponAtcs = { "��", "��", "��", "ս", "��", "ת",
							// 			"��", "վ", "��", "��", "" };
							cct::get()->pushWeapon(cct::get()->strDescTemp + "��", data[k].m_attack);
							cct::get()->pushWeapon(cct::get()->strDescTemp + "��", data[k].m_defend);
							cct::get()->pushWeapon(cct::get()->strDescTemp + "��", data[k].m_dead);
							cct::get()->pushWeapon(cct::get()->strDescTemp + "ս", data[k].m_fstand);
							cct::get()->pushWeapon(cct::get()->strDescTemp + "��", data[k].m_magic);
							cct::get()->pushWeapon(cct::get()->strDescTemp + "ת", data[k].m_return);
							cct::get()->pushWeapon(cct::get()->strDescTemp + "��", data[k].m_run);
							cct::get()->pushWeapon(cct::get()->strDescTemp + "վ", data[k].m_stand);
							cct::get()->pushWeapon(cct::get()->strDescTemp + "��", data[k].m_suffer);
							cct::get()->pushWeapon(cct::get()->strDescTemp + "��", data[k].m_walk);
						}
						if (k == 0)getline(File, dustbin);//��ע
					}
				}
			}
			File.close();
			oss.str("");
			oss << myWeaponPath << "��.txt";
			cct::get()->strDescTemp = "��";
			LoadItem1(oss.str());
		}

#pragma omp  section
		{
			ostringstream oss;
			oss << myWeaponPath << "��.txt";
			cct::get()->strDescTemp = "��";
			LoadItem1(oss.str());
			oss.str("");
			oss << myWeaponPath << "ǹ.txt";
			cct::get()->strDescTemp = "ǹ";
			LoadItem1(oss.str());
			oss.str("");
			oss << myWeaponPath << "��.txt";
			cct::get()->strDescTemp = "��";
			LoadItem1(oss.str());
			oss.str("");
			oss << myWeaponPath << "��.txt";
			cct::get()->strDescTemp = "��";
			LoadItem1(oss.str());
			oss.str("");
		}
#pragma omp  section
		{
			ostringstream oss;
			oss << myWeaponPath << "��.txt";
			cct::get()->strDescTemp = "��";
			LoadItem1(oss.str());
			oss.str("");
			oss << myWeaponPath << "צ.txt";
			cct::get()->strDescTemp = "צ";
			LoadItem1(oss.str());
			oss.str("");
			oss << myWeaponPath << "��.txt";
			cct::get()->strDescTemp = "��";
			LoadItem1(oss.str());
			oss.str("");
			oss << myWeaponPath << "Ʈ��.txt";
			cct::get()->strDescTemp = "Ʈ��";
			LoadItem1(oss.str());
		}
#pragma omp  section
		{
			ostringstream oss;
			oss << myWeaponPath << "��.txt";
			cct::get()->strDescTemp = "��";
			LoadItem1(oss.str());
			oss.str("");
			oss << myWeaponPath << "��.txt";
			cct::get()->strDescTemp = "��";
			LoadItem1(oss.str());
			oss.str("");
			oss << myWeaponPath << "˫��.txt";
			cct::get()->strDescTemp = "˫��";
			LoadItem1(oss.str());
			oss.str("");
			oss << myWeaponPath << "��.txt";
			cct::get()->strDescTemp = "��";
			LoadItem1(oss.str());
		}
#pragma omp  section
		{
			ostringstream oss;
			oss << myWeaponPath << "��.txt";
			cct::get()->strDescTemp = "��";
			LoadItem1(oss.str());
			oss.str("");
			oss << myWeaponPath << "��.txt";
			cct::get()->strDescTemp = "��";
			LoadItem1(oss.str());
			oss.str("");
			oss << g_pathData << "�����б�//����װ��.txt";
			//			cct::get()->strDescTemp = "����װ��";
			LoadZuoqiZhuangShi(oss.str());
			oss.str("");
			oss << myEquipPath << "ͷ��.txt";
			cct::get()->strDescTemp = "ͷ��";
			LoadItem1(oss.str());
			oss.str("");
			oss << myEquipPath << "����.txt";
			cct::get()->strDescTemp = "����";
			LoadItem1(oss.str());
			oss.str("");

		}
#pragma omp  section
		{
			ostringstream oss;
			oss << myEquipPath << "����.txt";
			cct::get()->strDescTemp = "����";
			LoadItem1(oss.str());
			oss.str("");
			oss << myEquipPath << "Ů��.txt";
			cct::get()->strDescTemp = "Ů��";
			LoadItem1(oss.str());
			oss.str("");
			oss << myEquipPath << "����.txt";
			cct::get()->strDescTemp = "����";
			LoadItem1(oss.str());
			oss.str("");
			oss << myEquipPath << "����.txt";
			cct::get()->strDescTemp = "����";
			LoadItem1(oss.str());
		}
#pragma omp  section
		{
			ostringstream oss;
			oss << myEquipPath << "Ь.txt";
			cct::get()->strDescTemp = "Ь";
			LoadItem1(oss.str());
			oss.str("");
			oss << g_pathData << "�����б�\\ҩƷ.txt";
			cct::get()->strDescTemp = "ҩƷ";
			LoadItem1(oss.str());
			oss.str("");
			oss << g_pathData << "�����б�\\���.txt";
			cct::get()->strDescTemp = "���";
			LoadItem1(oss.str());
			oss.str("");
			oss << g_pathData << "�����б�\\����.txt";
			//			cct::get()->strDescTemp = "����";
			LoadFaBao(oss.str());
			oss.str("");
			oss << g_pathData << "�����б�\\�޾�.txt";
			//			cct::get()->strDescTemp = "�޾�";
			LoadShouJue(oss.str());
		}
#pragma omp  section
		{
			ostringstream oss;
			oss << g_pathData << "�����б�\\����.txt";
			cct::get()->strDescTemp = "����";
			LoadItem1(oss.str());
			oss.str("");
			oss << g_pathData << "�����б�\\����.txt";
			cct::get()->strDescTemp = "����";
			LoadItem1(oss.str());
			oss.str("");
			oss << g_pathData << "�����б�\\����.txt";
			cct::get()->strDescTemp = "����";
			LoadItem1(oss.str());
			oss.str("");
			oss << g_pathData << "�����б�\\���ɵ��ӵ���.txt";
			cct::get()->strDescTemp = "���ɵ�";
			LoadItem1(oss.str());
		}
#pragma omp  section
		{
			ostringstream oss;
			oss << g_pathData << "�����б�\\��.txt";
			cct::get()->strDescTemp = "��";
			LoadItem1(oss.str());
			oss.str("");
			oss << g_pathData << "�����б�\\��ʯ.txt";
			cct::get()->strDescTemp = "��ʯ";
			LoadItem1(oss.str());
			oss.str("");
			oss << myEquipPath << "�ٻ��޻���.txt";
			cct::get()->strDescTemp = "����";
			LoadItem1(oss.str());
			oss.str("");
			oss << myEquipPath << "�ٻ�������.txt";
			cct::get()->strDescTemp = "BB��";
			LoadItem1(oss.str());
		}
#pragma omp  section
		{
			ostringstream oss;
			oss << myEquipPath << "�ٻ�����Ȧ.txt";
			cct::get()->strDescTemp = "��Ȧ";
			LoadItem1(oss.str());
			// 			oss.str("");
			// 			oss << g_strDataPath << "����//����//��.txt";
			// 			cct::get()->strDescTemp = "��";
			// 			LoadItem1(oss.str());
			oss.str("");
			oss << g_pathData << "�����б�\\����.txt";
			cct::get()->strDescTemp = "����";
			LoadItem1(oss.str());
			oss.str("");
			oss << g_pathData << "�����б�\\�Ҿ�.txt";
			//			cct::get()->strDescTemp = "�Ҿ�";
			LoadJiaJu(oss.str());
		}
#pragma omp  section
	{
		ifstream File;
		int num;
		ostringstream oss;
		oss << g_pathData << "�����б�\\�޾�����.txt";
		File.open(oss.str());
		int ID;
		File >> num;
		for (int i = 0; i < num; i++)
		{
			File >> ID;
			m_LShouJueList.push_back(ID);
		}
		File >> num;
		for (int i = 0; i < num; i++)
		{
			File >> ID;
			m_HShouJueList.push_back(ID);
		}
		File.close();
	}
#pragma omp  section
		{
			ifstream File;
			int num, ID;
			ostringstream oss;
			oss << g_pathData << "�����б�\\��Ʒ������.txt";
			File.open(oss.str());
			if (!File)ERRBOX;
			File >> num;
			string name;
			for (int i = 0; i < num; i++)
			{
				File >> ID;
				File >> name;
				m_ItemTypeName.push_back(name);
			}
			File.close();
			oss.str("");
			oss << g_pathData << "�����б�\\��ʯ.txt";
			File.open(oss.str());
			if (!File)ERRBOX;
			int type;
			File >> type;
			ulong smallhead, bighead;
			vector<sItem>& list = m_ItemList[type];
			File >> bighead;
			File >> smallhead;
			File >> name;
			File >> num;
			list.resize(num);
			for (int i = 0; i < num; i++)
			{
				File >> list[i].m_ID;
				File >> ID;//����
				File >> list[i].m_Price;
				list[i].m_Name = name;
				File >> list[i].m_Text;
				list[i].m_Type = type;
				list[i].m_BigHead = bighead;
				list[i].m_SmallHead = smallhead;
			}
			cct::get()->pushItemHead("��ʯ��", bighead);
			cct::get()->pushItemHead("��ʯС", smallhead);
			File.close();
		}
	}

	for (int i = 0; i < 22; i++)
	{
		for (int j = 0; j < m_ItemList[i].size(); j++)
		{
			m_ItemList[i][j].SetLv(GetlvByID(i, j));
		}
	}

#endif

	return true;
}


//��ȡ����װ��
bool ItemManager::LoadZuoqiZhuangShi(string path)
{
	ifstream File;
	File.open(path);
	if (!File)return false;
	int num;
	string dustbin;
	File >> num;
	sItem item;
	item.m_Type = 31;
	if (num != 24)return false;
	for (int i = 0; i < num; i++)
	{
		item.m_Price = 1000000;
		File >> item.m_ID;
		File >> item.m_Name;
		File >> item.m_SmallHead;
		File >> item.m_BigHead;
		m_ItemList[31].push_back(item);
		File >> m_ZuoQiZhuangShiList[i].NodeStand;
		File >> m_ZuoQiZhuangShiList[i].NodeWalk;
		File >> m_ZuoQiZhuangShiList[i].m_ColorID;
		ccm::get()->pushZuoqiHead(item.m_Name + "(����װ�δ�)", item.m_BigHead);
		ccm::get()->pushZuoqiHead(item.m_Name + "(����װ��С)", item.m_SmallHead);
		ccm::get()->pushZuoqi(item.m_Name + "(����װ��վ)", m_ZuoQiZhuangShiList[i].NodeStand);
		ccm::get()->pushZuoqi(item.m_Name + "(����װ����)", m_ZuoQiZhuangShiList[i].NodeWalk);
		forv(m_ZuoQiZhuangShiList[i].Stand, j)
		{
			File >> dustbin;
			File >> m_ZuoQiZhuangShiList[i].Stand[j];
			File >> m_ZuoQiZhuangShiList[i].Walk[j];
// 			if (j == 14 && !cct::get()->isPushRole15)
// 			{
// 				continue;
// 			}
			ccm::get()->pushZuoqi(item.m_Name + toString("(����װ��_��ɫ%d_վ)", j), m_ZuoQiZhuangShiList[i].Stand[j]);
			ccm::get()->pushZuoqi(item.m_Name + toString("(����װ��_��ɫ%d_��)", j), m_ZuoQiZhuangShiList[i].Walk[j]);
		}
	}
	File.close();
	return true;
}


bool ItemManager::LoadItem1(string path)
{
	ifstream File;
	File.open(path);
	int type;
	File >> type;

	int num;
	File >> num;
	vector<sItem>& item = m_ItemList[type];
	item.resize(num);

	string tex;
	for (int i = 0; i < num; i++)
	{
		item[i].m_Type = type;
		File >> item[i].m_ID;
		File >> item[i].m_Name;
		File >> item[i].m_SmallHead;
		File >> item[i].m_BigHead;
		File >> item[i].m_Price;
		getline(File, item[i].m_Text);
		getline(File, item[i].m_Text);

		ccm::get()->pushItemHead(item[i].m_Name + "��(" + ccm::get()->strDescTemp + ")", item[i].m_BigHead);
		ccm::get()->pushItemHead(item[i].m_Name + "С(" + ccm::get()->strDescTemp + ")", item[i].m_SmallHead);
	}
	File.close();
	if (type == 0)
	{
		std::swap(item[12], item[15]);
		std::swap(item[12].m_ID, item[15].m_ID);

		std::swap(item[13], item[16]);
		std::swap(item[13].m_ID, item[16].m_ID);

		std::swap(item[14], item[17]);
		std::swap(item[14].m_ID, item[17].m_ID);
	}
// 	else if (type == 22)
// 	{
// 		item[17].m_Text = "HP+2000,����+2000";
// 		item[18].m_Text = "HP+3000";
// 		item[43].m_Text = "MP+1000";
// 	}
	return true;
}

bool ItemManager::LoadFaBao(string path)
{
	ifstream File;
	File.open(path);
	int type;
	File >> type;
	int num;
	File >> num;
	sItem item;
	for (int i = 0; i < num; i++)
	{
		item.m_Type = type;
		File >> item.m_ID;
		File >> item.m_Name;
		//File >> item.m_Lv;
		File >> item.m_SmallHead;
		File >> item.m_BigHead;
		File >> item.m_UseType;
		File >> item.m_Price;
		getline(File, item.m_Text);
		getline(File, item.m_Text);
		m_ItemList[type].push_back(item);
		ccm::get()->pushItemHead(item.m_Name + "(������)", item.m_BigHead);
		ccm::get()->pushItemHead(item.m_Name + "(����С)", item.m_SmallHead);
	}
	File.close();
	item.m_ID = num;
	item.m_Name = "��ɫ������";
	item.m_SmallHead = 1084205009;
	item.m_BigHead = 1030021222;
	item.m_UseType = m_ItemList[type][12].m_UseType;
	item.m_Price = m_ItemList[type][12].m_Price;
	item.m_Text = "���⵼����";
	m_ItemList[type].push_back(item);
	ccm::get()->pushItemHead(item.m_Name + "(������)", item.m_BigHead);
	ccm::get()->pushItemHead(item.m_Name + "(����С)", item.m_SmallHead);

	return true;
}


bool ItemManager::LoadShouJue(string path)
{
	ifstream File;
	File.open(path);
	string name = "ħ��Ҫ��";
	int type;
	File >> type;
	int num;
	File >> num;
	ulong head[2];
	string text;
	File >> head[0];
	File >> head[1];
	ccm::get()->pushItemHead("�޾���", head[1]);
	ccm::get()->pushItemHead("�޾�С", head[0]);
	File >> text;
	text += "(��������:";
	sItem item;
	for (int i = 0; i < num; i++)
	{
		item.m_Type = type;
		File >> item.m_ID;
		File >> item.m_Name;
		if (item.m_ID == 77)
		{
			item.m_Name = "����";
		}
		else if (item.m_ID == 78)
		{
			item.m_Name = "�߼�����";
		}
		else if (item.m_ID == 81)
		{
			item.m_Name = "�绪����";
		}
		else if (item.m_ID == 96)
		{
			item.m_Name = "�����ķ�";
		}
		//File >> item.m_Lv;
		item.m_SmallHead = head[0];
		item.m_BigHead = head[1];
		File >> item.m_Price;
		//		item.m_Price /= 10;
		item.m_Text = text;
		item.m_Text += item.m_Name;
		item.m_Text += ")";
		item.m_Name = name;
		m_ItemList[type].push_back(item);
	}
	File.close();
	vector<string> names = { "��������", "�������", "�¹�" };
	vector<int> prices = { 50000000, 10000000, 50000000 };
	for (int i = 0; i < 3; ++i)
	{
		item.m_Type = type;
		item.m_ID = i + num;
		item.m_Name = names[i];
		item.m_SmallHead = head[0];
		item.m_BigHead = head[1];
		item.m_Price = prices[i];
		item.m_Text = text;
		item.m_Text += item.m_Name;
		item.m_Text += ")";
		item.m_Name = name;
		m_ItemList[type].push_back(item);
	}
	return true;
}



bool ItemManager::LoadWeapon(string path)
{
	ifstream File;
	File.open(path);
	int type;
	File >> type;
	int num;
	File >> num;
	sItem item;
	int weaponlv;
	for (int i = 0; i < num; i++)
	{
		item.m_Type = type;
		File >> item.m_ID;
		File >> item.m_Name;

		File >> weaponlv;
		item.SetLv(weaponlv);
		File >> item.m_SmallHead;
		File >> item.m_BigHead;
		getline(File, item.m_Text);
		getline(File, item.m_Text);

		//int k = 0;
		//if (i >= 9)k = i - 6;    //
		//else if (i < 3)k = 0;  //0-20������������һ��
		//else if (i < 6)k = 1;  //30-50������������һ��
		//else if (i < 9)k = 2;  //60-80
		////int WeaponOffset = m_pWeaponList[0].Type * 11 + k;
		//m_pWeaponList[type].data[i].m_pData[0] = &m_pWeaponList2[k + type * 11];
		//m_pWeaponList[type].data[i].m_pData[1] = &m_pWeaponList2[k + type * 11 + 165];
	}
	File.close();
	return true;
}



bool ItemManager::LoadJiaJu(string path)
{
	ifstream File;
	File.open(path);
	LoadJiaJuCube(File, 35);
	LoadJiaJuCube(File, 36);
	LoadJiaJuCube(File, 37);
	LoadJiaJuCube(File, 38);
	File.close();
	return true;
}

void ItemManager::LoadJiaJuCube(ifstream& File, int type)
{
	int lv;
	int num;
	sItem item;

	File >> lv;
	File >> num;
	int jiajulv;
	for (int i = 0; i < num; i++)
	{
		item.m_Type = type;
		item.m_ID = i;
		File >> item.m_Name;
		File >> item.m_SmallHead;
		File >> item.m_BigHead;
		File >> jiajulv;
		item.SetLv(jiajulv);//��¼�Ҿߵ�����
		File >> item.m_Price;

		switch (lv)
		{
		case 1:
			item.m_Text = "һ���Ҿ�"; break;
		case 2:
			item.m_Text = "�����Ҿ�"; break;
		case 3:
			item.m_Text = "�����Ҿ�"; break;
		case 4:
			item.m_Text = "�ļ��Ҿ�"; break;
		default:
			ERRBOX;
			break;
		}
		ccm::get()->pushHomeHead(item.m_Name + "_" + item.m_Text + "��", item.m_BigHead);
		ccm::get()->pushHomeHead(item.m_Name + "_" + item.m_Text + "С", item.m_SmallHead);
		m_ItemList[type].push_back(item);
		//�����Ǽ�԰����Դ,��ʱ����
		sJiaJuData data;
		ulong PicID;
		File >> data.num;

		for (int j = 0; j < data.num; j++)
		{
			File >> PicID;
			data.m_data.push_back(PicID);
			ccm::get()->pushHome(item.m_Name + "_" + item.m_Text + toString("%d", j), PicID);
		}
		m_JiaJuData[lv - 1].push_back(data);
	}
}
