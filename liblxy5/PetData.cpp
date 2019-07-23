#include "_global.h"



cPetData::cPetData()
{
	_isWeakSeal = true;
}



void cPropertyData::Reset()
{
	sPropertyData::Reset(false, false, false);

	modeid = -1;
	m_HP = 0;
	m_HP2 = 0;
	m_MP = 0;
	m_CP = 0;      //��ŭ
	//����
	m_EXP = 0;
//	m_ExpTotal = 0;

	//ս�����Ա�
	m_FightData.Clear();
	m_IDinFightWorkList = -1;

	m_NumofBBSkill = 0;

	for (int i = 0; i < 6; i++)
	{
		m_Equips[i].m_Num = 0;
	}

	m_JinJieNum.Reset();
	m_RanSe.Reset();

// 	m_AiLv = 0;//AI�ȼ�  ������ɫ��ս��ʱ����Ϊ 0-100
// 	m_StrongLv = 0; //ǿ��  ������ɫ������ǿ��
// 	NightLv = 0;//�ȼ�ҹս����
// 	AbnormalResist = 0; //������
// 
// 	//�ٻ����˺��ӳ�
// 	m_PetDamagePercentMagic.Reset();//�����˺�
// 	m_PetDamagePercent.Reset();//�����˺�
// 
// 	m_DamageAddMagicLv.Reset();//�����˺��������lv
// 	m_DamageAddLv.Reset();  //�����˺����
// 
// 	//����������
// 	m_AtkDownCP.Reset();//����CP
// 	m_MagDownHPHurt.Reset();
// 	m_AtkDownHPHurt.Reset();
// 	m_AtkDownMP.Reset();
// 	m_AtkDownAtk.Reset();
// 	m_AtkDownHit.Reset();
// 	m_AtkDownDef.Reset();
// 	m_AtkDownWakan.Reset();
// 	m_AtkDownSpd.Reset();
// 
// 	BoySpecial.Reset();  //��
// 	GirlSpecial.Reset();   //Ů
// 	GoldSpecial.Reset();    //�����ع�
// 	MagSpecial.Reset();    //ħ���ع�
// 	ImmortalSpecial.Reset(); //�����ع�
// 	MonsterSpecial.Reset();//�����ع�
// 	PeopleSpecial.Reset(); //��
// 	ghostSpecial.Reset();  //���ع�
// 	machineSpecial.Reset();//��е�ع�


// 	m_Race = -1;//����
// 	m_Popularity = 700;
// 	m_Physical = 0;    //����
// 	m_PhysicalMax = 100; //��������
// 	m_Energy = 0;      //����
// 	m_EnergyMax = 100;  //��������
// 
// 	//��������
// 	for (int i = 0; i < c_NumFuZhu; i++)
// 	{
// 		m_FuZhuSkillLvList[i] = 0;
// 	}
	_isWeakSeal = true;
}


void cPropertyData::FillHpMp()
{
	m_HP = m_HP2 = HPMax.GetData();
	m_MP = MPMax.GetData();
}



void cPropertyData::SetJinJie(int num)
{
	if (m_JinJieNum.m_JinJieNum > 2)return;
	if (m_JinJieNum.m_JinJieNum + num > 3)
	{
		num = 3 - m_JinJieNum.m_JinJieNum;
	}
	// 	AddProPertyAtk(m_AddPoint.atk * 10 * num);
	// 	AddProPertyDef(m_AddPoint.def * 10 * num);
	// 	AddProPertySpd(m_AddPoint.spd * 10 * num);
	// 	AddProPertyHp(m_AddPoint.hp* 10 * num);
	// 	AddProPertyMag(m_AddPoint.mp * 10 * num);
	m_JinJieNum.m_JinJieNum += num;
	m_JinJieNum.m_index += num;
	if (m_JinJieNum.m_JinJieNum > 1)
	{
		m_RanSe.m_ranse[0].partnum = 0;
	}
//	FillHpMp();
}


bool cPropertyData::AddSkill(int id, int idx /* = -1 */)
{
	//��ȷ�����ظ�
	sSkill* pPetSkill = g_pMainState->m_SkillManager.GetPetSkill((id >= 2000) ? (id - 2000) : id);
//	const auto& unComs = pPetSkill->m_UnCompatible;
	for (int i = 0; i < m_NumofBBSkill; i++)
	{
		if (id == m_petSkills[i]->m_Id)
		{
			return false;
		}
// 		if (std::find(unComs.begin(), unComs.end(), m_petSkills[i]->m_Id) != unComs.end())
// 		{
// 			m_petSkills[i] = pPetSkill;
// 			return true;
// 		}
	}
	if (idx < m_NumofBBSkill && idx >= 0)
	{
		m_petSkills[idx] = pPetSkill;
		return true;
	}
	else if (m_NumofBBSkill == m_petSkills.size())
	{
		return false;
	}
	m_petSkills[m_NumofBBSkill] = pPetSkill;
	++m_NumofBBSkill;
	return true;
}




bool cPropertyData::isHadPetSkill(int SkillID)
{
	if (SkillID >= 2000)SkillID -= 2000;
	for (int i = 0; i < m_NumofBBSkill; ++i)
	{
		if (m_petSkills[i]->m_Id == SkillID)return true;
	}
	return false;
}



bool cPropertyData::setPointAfterLv(const sAddPoint& ap, bool isRemain)
{
//	int remain = isRemain ? PointRemain / 5 : 0;
	PointBody = cct::MinPoint + (ap.body + 1) * m_Lv/* + ap.body * remain*/;
	PointMag = cct::MinPoint + (ap.mag + 1) * m_Lv/* + ap.mag * remain*/;
	PointStr = cct::MinPoint + (ap.str + 1) * m_Lv/* + ap.str * remain*/;
	PointDex = cct::MinPoint + (ap.dex + 1) * m_Lv/* + ap.dex * remain*/;
	PointAgi = cct::MinPoint + (ap.agi + 1) * m_Lv/* + ap.agi * remain*/;
	if (isRemain)
	{
		vector<int*> ps = { &PointStr, &PointDex, &PointBody, &PointMag/*, &PointAgi*/ };
		std::sort(ps.begin(), ps.end(), [](int* a, int* b){return (*a) > (*b); });
		*ps[0] += PointRemain;
		PointRemain = 0;
//		PointRemain %= 5;
	}
	return true;
}



bool cPropertyData::lvup(int exp, bool onlyChek)
{
//	INT64 exp = GetCharacterExp(m_Lv + 1);
	if (m_EXP < exp)
	{
		return false;
	}
	if (!onlyChek)
	{
		++m_Lv;
		m_EXP -= exp;
		++PointStr;
		++PointDex;
		++PointMag;
		++PointBody;
		++PointAgi;
		PointRemain += 5;
	}
	return true;
}

bool cPropertyData::lvdown(int exp, bool onlyChek)
{
	if (m_Lv == 0)
	{
		return false;
	}
	vector<int*> ps =
	{
		&PointStr,
		&PointDex,
		&PointMag,
		&PointBody,
		&PointAgi
	};
	std::sort(ps.begin(), ps.end(), [](const int* a, const int* b){return (*a) < (*b); });
	int* point = ps.back();

	if ((*point) - cct::MinPoint + PointRemain < 10)
	{
		return false;
	}

	if (!onlyChek)
	{
		--m_Lv;
		m_EXP += exp;// GetCharacterExp(m_Lv);
		if (PointRemain >= 10)
		{
			PointRemain -= 10;
		}
		else
		{
			(*point) -= 10 - PointRemain;
			PointRemain = 0;
		}
	}
	return true;
}


void cPropertyData::apply(const sZiZhi* zz)
{
	sPropertyData::Reset(false, false, false);
	sPropertyData::applyPoint(zz);
	for (int i = 0; i < m_Equips.size(); ++i)
	{
		if (m_Equips[i].m_Num == 1)
		{
			applyEquip(m_Equips[i].m_Property);
		}
	}

	vector<int> unComs;
	for (int i = 0; i < m_NumofBBSkill; i++)
	{
		for (int k = 0; k < m_petSkills[i]->m_NumUnCompatible; ++k)
		{
			unComs.push_back(g_pMainState->m_SkillManager.m_PetSkillList[m_petSkills[i]->m_UnCompatible[k]].m_Id);
		}
	}
	vector<int> skills;
	for (int i = 0; i < m_NumofBBSkill; ++i)
	{
		if (std::find(unComs.begin(), unComs.end(), m_petSkills[i]->m_Id) == unComs.end())
		{
			skills.push_back(m_petSkills[i]->m_Id);
		}
	}

	forr(skills, i)
	{
		applyPetSkill(skills[i]);
	}

// 	for (int i = 0; i < m_NumofBBSkill; ++i)
// 	{
// 		applyPetSkill(m_petSkills[i]->m_Id);
// 	}
	applyXL();
}



void cPetData::apply()
{
	cPropertyData::apply(&m_ZiZhi);
	if (m_HP2 > HPMax.GetData())
	{
		m_HP2 = HPMax.GetData();
	}
	if (m_HP > m_HP2)
	{
		m_HP = m_HP2;
	}

	map<int, int> taozhuangMap;
	forr(m_Equips, i)
	{
		if (m_Equips[i].m_Num != 1)
		{
			continue;
		}
		const auto& props = m_Equips[i].m_Property;
		if (props.size() > 15 && props[15] >= 0)
		{
			const auto& it = taozhuangMap.find(props[15]);
			if (it == taozhuangMap.end())
			{
				taozhuangMap.insert(make_pair(props[15], 1));
			}
			else
			{
				++it->second;
			}
		}
		if (taozhuangMap.size() == 1 && taozhuangMap.begin()->second == 3)
		{
			EndMagic = taozhuangMap.begin()->first;
		}
	}
}



void cPetData::autoEquip(bool isStone, bool isFushi)
{
	int lv = m_Lv;
	sItem2 item;
	item.m_Num = 1;
	item.m_pItemData = new sItem;
	item.m_pItemData->SetLv(lv);

	item.Set(32, g_pMainState->m_ItemManage.GetIDByLv(32, lv));
	item.m_Property = g_pMainState->m_ItemManage.AutoItemPropertyBB(&item);
	m_Equips[0] = item;
	item.Set(33, g_pMainState->m_ItemManage.GetIDByLv(33, lv));
	item.m_Property = g_pMainState->m_ItemManage.AutoItemPropertyBB(&item);
	m_Equips[1] = item;
	item.Set(34, g_pMainState->m_ItemManage.GetIDByLv(34, lv));
	item.m_Property = g_pMainState->m_ItemManage.AutoItemPropertyBB(&item);
	m_Equips[2] = item;

	int slv;
	if (isStone && lv >= 15)
	{
		vector<int> stones = { (g_pMainState->m_AI.isAtkFromPoint(this)) ? 15 : 12, 11, /*(rand() % 100 < 50) ? 13 :*/ 16 };
		slv = (lv - 5) / 10;
		slv = min(slv, cct::MaxStoneLv);
		forr(stones, kk)
		{
			auto& prs = m_Equips[kk].m_Property;
			prs[0] = slv;
			prs[1] = stones[kk];
			g_pMainState->m_ItemManage.SetUpBaoShi(prs, prs[1], prs[0], true);
		}
	}

	if (isFushi)
	{
		static vector<int> s1s;
		if (s1s.empty())
		{
			s1s.push_back(14);
			s1s.push_back(50);
			s1s.push_back(135);
			s1s.push_back(182);

			s1s.push_back(2085);
			s1s.push_back(2087);
			s1s.push_back(2089);
			s1s.push_back(2091);
			s1s.push_back(2092);
			s1s.push_back(2093);
			s1s.push_back(2094);
			s1s.push_back(2095);
			s1s.push_back(2098);
			s1s.push_back(2099);
		}
		slv = s1s[rand() % s1s.size()];

		forr(m_Equips, kk)
		{
			if (m_Equips[kk].m_Num < 1)
			{
				continue;
			}
			m_Equips[kk].m_Property[15] = slv;
		}
	}
}




bool cPetData::autoData(bool resetpoint, bool skill)
{
	bool isMag = g_pMainState->m_AI.isMagFromPoint(this);
	if (resetpoint)
	{
		int& point = isMag ? PointMag : PointStr;
		int r = 25;
		if (rand() % 100 < r && point >= m_Lv * 2 + cct::MinPoint)
		{
			point -= m_Lv;
			PointBody += m_Lv;

			if (rand() % 100 < r && point >= m_Lv * 2 + cct::MinPoint)
			{
				point -= m_Lv;
				PointBody += m_Lv;
			}
		}
		if (rand() % 100 < r && point >= m_Lv * 2 + cct::MinPoint)
		{
			point -= m_Lv;
			PointDex += m_Lv;
			if (rand() % 100 < r && point >= m_Lv * 2 + cct::MinPoint)
			{
				point -= m_Lv;
				PointDex += m_Lv;
			}
		}

		if (!isMag && rand() % 100 < r && point >= m_Lv * 2 + cct::MinPoint)
		{
			point -= m_Lv;
			PointAgi += m_Lv;
		}
	}


	if (skill)
	{

		vector<int> atks = { 14, 78, 80, 83, 96, 106, 1, 3, 7, 13, 24, 50, 76, 82, 100, 104, 107, 109 };
		vector<int> mags = { 14, 78, 80, 83, 96/*, 106*/, 48, 56, 58, 60, 102, 103, 105, 108 };

		const auto& ss = isMag ? mags : atks;
		int r = 10;
		if (m_NumofBBSkill == 0)
		{
			r = 60;
		}
		forr(ss, i)
		{
			if (rand() % 100 < r)
			{
				AddSkill(ss[i]);
			}
		}

		if (rand() % 100 < 10)
		{
			AddSkill(97);
		}
		if (isMag)
		{
			if (isHadPetSkill(85) || isHadPetSkill(87) || isHadPetSkill(89) || isHadPetSkill(91) || isHadPetSkill(102) || isHadPetSkill(105))
			{
				return true;
			}
			int idx = 0;
			int sid;
			for (; idx < m_NumofBBSkill; ++idx)
			{
				sid = m_petSkills[idx]->m_Id;
				if (sid == 84 || sid == 86 || sid == 88 || sid == 90)
				{
					break;
				}
			}
			if (idx < m_NumofBBSkill)
			{
				m_petSkills[idx] = &g_pMainState->m_SkillManager.m_PetSkillList[sid + 1];
				return true;
			}
			AddSkill(85 + (rand() % 4) * 2);
			return true;
		}
		if (isHadPetSkill(6) || isHadPetSkill(7) || isHadPetSkill(12) || isHadPetSkill(13))
		{
			return false;
		}

		vector<int> ps = { 92, 94, 95, 98, 99 };
		if (rand() % 100 < 15)
		{
			AddSkill(ps[rand() % ps.size()]);
			return true;
		}
	}
	return false;
}



void cPropertyData::SaveCode(sOstream& File)
{
// 	//ս�����Ա�
// 	sFightData m_FightData;
// 	int m_IDinFightWorkList = -1;
// 
// 	int  m_NumofBBSkill = 0;
// 	array<sSkill*, 24> m_petSkills;
// 
// 
// 	sControler m_Controler;
// 	cJinJieNum m_JinJieNum;//����
// 	sChangeColorData2 m_RanSe;
// 
// 	array<sItem2, 6> m_Equips;


	File << modeid << g_strSpace;
// 	if (-1 == modeid)
// 	{
// 		return;
// 	}

	File << m_Lv << g_strSpace;
//	m_XiuLian.Save(File);
	File << PointStr << g_strSpace;
	File << PointDex << g_strSpace;
	File << PointMag << g_strSpace;
	File << PointBody << g_strSpace;
	File << PointAgi << g_strSpace;
	File << PointRemain << g_strSpace;

	int id = PointStr + PointDex + PointMag + PointBody + PointAgi + PointRemain;
	if (id > (m_Lv * 10 + cct::MinPoint * 5 + cct::PointRemian))
	{
		ERRBOX2(id);
	}

//	File << m_Name << g_strSpace;
//	File << m_dataFileName << g_strSpace;

	File << m_HP << g_strSpace;
	File << m_HP2 << g_strSpace;
	File << m_MP << g_strSpace;
	File << m_CP << g_strSpace;
	File << m_EXP << g_strSpace;

	File << m_NumofBBSkill << g_strSpace;
	for (int i = 0; i < m_NumofBBSkill; ++i)
	{
		File << m_petSkills[i]->m_Id << g_strSpace;
	}

	for (int i = 0; i < m_Equips.size(); ++i)
	{
		m_Equips[i].SaveCode(File);
	}
}


void cPropertyData::LoadCode(sIstream& File)
{
	File >> modeid;
// 	if (-1 == modeid)
// 	{
// 		return;
// 	}
	File >> m_Lv;
//	m_XiuLian.Load(File);
	File >> PointStr;
	File >> PointDex;
	File >> PointMag;
	File >> PointBody;
	File >> PointAgi;
	File >> PointRemain;

	int id = PointStr + PointDex + PointMag + PointBody + PointAgi + PointRemain;
	if (id > (m_Lv * 10 + cct::MinPoint * 5 + cct::PointRemian))
	{
		// �����޸�
		PointStr = PointDex = PointMag = PointBody = PointAgi = cct::MinPoint + m_Lv;
		PointRemain = m_Lv * 5 + cct::PointRemian;
		// ERRBOX2(id);
	}

// 	File >> m_Name;
// 	File >> m_dataFileName;

	File >> m_HP;
	File >> m_HP2;
	File >> m_MP;
	File >> m_CP;
	File >> m_EXP;

	File >> m_NumofBBSkill;
	for (int i = 0; i < m_NumofBBSkill; ++i)
	{
		File >> id;
		m_petSkills[i] = &g_pMainState->m_SkillManager.m_PetSkillList[id];
	}

	for (int i = 0; i < m_Equips.size(); ++i)
	{
		m_Equips[i].LoadCode(File);
	}
}

void cPropertyData::Save(ofstream& File)
{
//	File << m_Name << g_strSpace;
	m_JinJieNum.Save(File);
	m_RanSe.Save(File);
}

void cPropertyData::Load(ifstream& File)
{
//	File >> m_Name;
	m_JinJieNum.Load(File);
	m_RanSe.Read(modeid, File, m_JinJieNum.m_index);
}


cObj* cPropertyData::getObj(bool checkExit /* = false */)
{
	if (m_IDinFightWorkList < 0)
	{
		return nullptr;
	}
	if (checkExit && !g_pMainState->m_FightWorkList[m_IDinFightWorkList].isExist)
	{
		return nullptr;
	}
	return g_pMainState->m_FightWorkList[m_IDinFightWorkList].m_pObj;
}



void cPetData::SaveCode(sOstream& File)
{
	cPropertyData::SaveCode(File);
	m_ZiZhi.Save(File);
}

void cPetData::LoadCode(sIstream& File)
{
	cPropertyData::LoadCode(File);
	m_ZiZhi.Load(File);
	apply();
}




void cPetData::Load(int model, bool skill, bool zz)
{
	modeid = cct::getModel(model);
	const auto& pet = g_pMainState->m_PetDataManager.m_PetList[model];
	if (m_Name.empty())
	{
		m_Name = pet.m_Name;
	}
	if (zz)
	{
//		m_ZiZhi.Set((sZiZhi&)pet.m_ZiZhi, 0, pet.m_LvTake);
		m_ZiZhi = (sZiZhi)pet.m_ZiZhi;
	}
	if (skill)
	{
		m_NumofBBSkill = pet.m_SkillNum;
		const auto& list = g_pMainState->m_SkillManager.m_PetSkillList;
		for (int i = 0; i < pet.m_SkillNum; ++i)
		{
			m_petSkills[i] = (sSkill*)&list[pet.m_pPetSkill[i]->m_Id];
		}
	}
}





#if 0
int cPropertyData::CountATK()
{
	bool isBB = _isBabyModeForLvup;
	int atk = m_LV*m_ZiZhi.atk * (1400 + 10 * m_ZiZhi.grow) / 750000 +
		PointStr*m_ZiZhi.grow / 100;
	if (isBB)
	{
		return atk;
	}
	float v = 0;
	for (int i = m_LV + cct::get()->maxSkillLv - cct::get()->maxRoleLv; i >= 0; --i)
	{
		v += 2.51f + .02f * i;
	}
	v += PointStr * .77f;
	return (int)v;

}

int cPropertyData::CountDEF()
{
	bool isBB = _isBabyModeForLvup;
	// (9.4f + 19 * m_ZiZhi.m_Growing / 3.0f)
	int def = (m_LV*m_ZiZhi.def) * 19 / 7500 +
		(PointDex*m_ZiZhi.grow * 4) / 300;
	if (isBB)
	{
		return def;
	}
	float v = 0;
	for (int i = m_LV + cct::get()->maxSkillLv - cct::get()->maxRoleLv; i >= 0; --i)
	{
		v += 1 + .02f * i;
	}
	v += PointDex * 1.6f;
	return (int)v;
}

int cPropertyData::CountHP()
{
	bool isBB = _isBabyModeForLvup;
	int hp = (m_LV*m_ZiZhi.hp) / 1000 +
		PointBody*m_ZiZhi.grow * 6 / 100;
	if (isBB)
	{
		return hp * 2;
	}
	return 100 + PointBody * 6;
}

int cPropertyData::CountWakan()
{
	bool isBB = _isBabyModeForLvup;
	//����=�ȼ�*(��������+1640)*(�ɳ�+1)/7500+����*0.3+����*0.7+����*0.4+����*0.2
	int	wakan = (m_LV* (m_ZiZhi.mag + 1640)*(m_ZiZhi.grow + 100) / 75000 +
		PointBody * 3 +
		PointMag * 7 +
		PointStr * 4 +
		PointDex * 2
		) / 10;
	if (isBB)
	{
		return wakan;
	}
	float v = 0;
	for (int i = m_LV + cct::get()->maxSkillLv - cct::get()->maxRoleLv; i >= 0; --i)
	{
		v += .5f + .01f * i;
	}
	v += PointMag * .7f + PointBody * .3f + PointStr * .4f + PointDex * .2f;
	return (int)v;
}

int cPropertyData::CountMP()
{
	bool isBB = _isBabyModeForLvup;
	int mp = m_LV*m_ZiZhi.mag / 500 + m_ZiZhi.grow*PointMag * 3 / 100;
	if (isBB)
	{
		return mp;
	}
	return 80 + PointMag * 4;
}

int cPropertyData::CountSpd()
{
	bool isBB = _isBabyModeForLvup;
	int spd = (m_ZiZhi.speed*PointAgi) / 1000;
	if (isBB)
	{
		return spd;
	}
	return int(PointAgi * .7f + PointBody * .1f + PointStr * .1f + PointDex * .1f);
}

int cPropertyData::CountEvade()
{
	bool isBB = _isBabyModeForLvup;
	int evade = PointAgi * m_ZiZhi.avoid / 500;
	if (isBB)
	{
		return evade;
	}
	float v = 0;
	for (int i = m_LV + cct::get()->maxSkillLv - cct::get()->maxRoleLv; i >= 0; --i)
	{
		v += 2 + .02f * i;
	}
	v += PointAgi;
	return (int)v;
}

int cPropertyData::CountHit()
{
	bool isBB = _isBabyModeForLvup;
	int hit = PointStr * 3;
	if (isBB)
	{
		return hit;
	}
	float v = 0;
	v += PointStr * 2.31f;
	return (int)v;
}

void cPropertyData::AddProPertyAtk(int num)
{
	//����Ӱ��  �˺�  ����  ����  �ٶ�
	Atk.AddDataOriginal(-CountATK());//�˺�
	Mana.AddDataOriginal(-CountWakan());//����
	Speed.AddDataOriginal(-CountSpd());//�ٶ�
	Hit.AddDataOriginal(-CountHit());//����
	PointStr += num;
	Atk.AddDataOriginal(CountATK());//�˺�
	Mana.AddDataOriginal(CountWakan());//����
	Speed.AddDataOriginal(CountSpd());//�ٶ�
	Hit.AddDataOriginal(CountHit());//����
}

void cPropertyData::AddProPertyDef(int num)
{
	//����Ӱ�� ���� ���� �ٶ�
	Def.AddDataOriginal(-CountDEF());//��
	Mana.AddDataOriginal(-CountWakan());//����
	Speed.AddDataOriginal(-CountSpd());//�ٶ�
	PointDex += num;
	Def.AddDataOriginal(CountDEF());//��
	Mana.AddDataOriginal(CountWakan());//����
	Speed.AddDataOriginal(CountSpd());//�ٶ�
}

void cPropertyData::AddProPertyMag(int num)
{
	//���� Ӱ�� ���� ��ħ������
	MPMax.AddDataOriginal(-CountMP());//MP
	Mana.AddDataOriginal(-CountWakan());//����
	PointMag += num;
	MPMax.AddDataOriginal(CountMP());//MP
	Mana.AddDataOriginal(CountWakan());//����
}

void cPropertyData::AddProPertyHp(int num)
{
	//���� Ӱ�� ��Ѫ���� ���� �ٶ� 
	HPMax.AddDataOriginal(-CountHP());//HP
	Mana.AddDataOriginal(-CountWakan());//����
	Speed.AddDataOriginal(-CountSpd());//�ٶ�
	PointBody += num;
	HPMax.AddDataOriginal(CountHP());//HP
	Mana.AddDataOriginal(CountWakan());//����
	Speed.AddDataOriginal(CountSpd());//�ٶ�
}

void cPropertyData::AddProPertySpd(int num)
{
	//����Ӱ��  �ٶ� �Ͷ��
	Speed.AddDataOriginal(-CountSpd());//�ٶ�
	Evade.AddDataOriginal(-CountEvade());//����
	PointAgi += num;
	Speed.AddDataOriginal(CountSpd());//�ٶ�
	Evade.AddDataOriginal(CountEvade());//����
}



bool cPropertyData::LeveUp(int lv, bool isBaby, bool isAdd)
{
	if (!lv)return false;
	Atk.AddDataOriginal(-CountATK());//�˺�
	Def.AddDataOriginal(-CountDEF());//��
	HPMax.AddDataOriginal(-CountHP());//HP
	MPMax.AddDataOriginal(-CountMP());//MP
	Mana.AddDataOriginal(-CountWakan());//����
	Speed.AddDataOriginal(-CountSpd());//�ٶ�
	Evade.AddDataOriginal(-CountEvade());//����
	Hit.AddDataOriginal(-CountHit());//����

	m_LV += lv;

	////////////////////////////////////////////////////////////////////////// �Ǻ��� �Զ��ӵ�������
	if (isAdd)
	{
		PointStr += (m_AddPoint.str + 1)*lv;
		PointDex += (m_AddPoint.dex + 1)*lv;
		PointBody += (m_AddPoint.body + 1)*lv;
		PointMag += (m_AddPoint.mag + 1)*lv;
		PointAgi += (m_AddPoint.agi + 1)*lv;
	}
	else
	{
		PointStr += lv;
		PointDex += lv;
		PointBody += lv;
		PointMag += lv;
		PointAgi += lv;
		PointRemain += 5 * lv;
	}

	_isBabyModeForLvup = isBaby;
	//����������
	Atk.AddDataOriginal(CountATK());//�˺�
	Def.AddDataOriginal(CountDEF());//��
	HPMax.AddDataOriginal(CountHP());//HP
	MPMax.AddDataOriginal(CountMP());//MP
	Mana.AddDataOriginal(CountWakan());//����
	Speed.AddDataOriginal(CountSpd());//�ٶ�
	Evade.AddDataOriginal(CountEvade());//����
	Hit.AddDataOriginal(CountHit());//����


	m_PhysicalMax += 5 * lv; //��������;     
	m_EnergyMax += 5 * lv;  //��������
	m_ExpTotal = GetCharacterExp(m_LV);
	FillHpMp();
	return true;

}

void cPropertyData::AutoPetData(bool m_bNeedSkill)
{
	if (-1 == modeid)return;

	sObjPet* pPet = g_pMainState->m_PetDataManager.GetPetData(modeid);
	m_LV = 0;
	m_NumofBBSkill = 0;
	if (m_bNeedSkill)
		for (int i = 0; i < pPet->m_SkillNum; i++)
		{
		if (rand() % 100 >= (100 - m_StrongLv) || true) //ÿ��������10%-100%�ļ��ʿ��Եõ�
		{
			g_pMainState->m_SkillManager.SetPetSkill((cPropertyData*)this, pPet->m_pPetSkill[i]->m_Id, m_NumofBBSkill);
		}
		}
	//���ʳɳ�
	m_ZiZhi.Set(pPet->m_ZiZhi, m_StrongLv, pPet->m_LvLimit);
	// 	AddProPertyAtk(30);
	// 	AddProPertyDef(20);
	// 	AddProPertyHp(20);
	// 	AddProPertyMag(20);
	// 	AddProPertySpd(20);
	//	m_ProPertyδ����� += cct::get()->point����;
	m_Name = pPet->m_Name;
	m_dataFileName = m_Name;
	m_Popularity = g_pMainState->m_GlobalButton[0] * 10;
	FillHpMp();
}


void cPropertyData::Set(sShangPinPet* pet)
{
	if (-1 == modeid)return;

	m_LV = 0;
	m_NumofBBSkill = 0;
	for (int i = 0; i < pet->m_skillid.size(); i++)
	{
		g_pMainState->m_SkillManager.SetPetSkill(this, pet->m_skillid[m_NumofBBSkill], m_NumofBBSkill);
	}
	//���ʳɳ�
	m_ZiZhi = pet->m_zizhi;
	// 	AddProPertyAtk(30);
	// 	AddProPertyDef(20);
	// 	AddProPertyHp(20);
	// 	AddProPertyMag(20);
	// 	AddProPertySpd(20);
	//	m_ProPertyδ����� += cct::get()->point����;
	m_Name = pet->m_name;
	m_dataFileName = m_Name;
}
void cPropertyData::PetEquip(int Pos, int bequip)
{
	if (Pos >= 12000)Pos -= 12000;
	if (0 == m_Equips[Pos].GetNum())return;
	sItem2& item = m_Equips[Pos];
	int nowid = 5;
	EquipExtra(item.m_Property, nowid, bequip);
	for (int i = 2; i < 5; i++)
		g_pMainState->m_SkillManager.SetSpecialSkill2(this, item.m_Property[i], bequip);

}
void cPropertyData::UnPetEquip(int Pos)
{
	PetEquip(Pos, -1);
}

void cPropertyData::EquipExtra(vector<int>& prop, int& startid, int m_bEquip)
{
	int property;

	for (int i = 0; i < prop[startid]; i++)
	{
		eProPerty  pro = (eProPerty)prop[startid + i * 2 + 1];
		property = prop[startid + i * 2 + 2] * m_bEquip;
		switch (pro)
		{
		case eProPerty�˺�:Atk.AddDataOriginal(property); break;
		case eProPerty����:Hit.AddDataOriginal(property); Atk.AddDataOriginal(property / 3); break;
		case eProPerty����:Def.AddDataOriginal(property); break;
		case eProPerty����:Mana.AddDataOriginal(property); break;
		case eProPerty�ٶ�:Speed.AddDataOriginal(property); break;
		case eProPerty��Ѫ:HPMax.AddDataOriginal(property); break;
		case eProPerty����:AddProPertyAtk(property); break;
		case eProPerty����:AddProPertySpd(property); break;
		case eProPerty����:AddProPertyHp(property); break;
		case eProPertyħ��:AddProPertyMag(property); break;
		case eProPerty����:AddProPertyDef(property); break;
		case eProPertyħ��:MPMax.AddDataOriginal(property); break;
		case eProPerty���:Evade.AddDataOriginal(property); break;
		case eProPertyˮ��:MagicWater.d2 += property;
		case eProPerty��:MagicFire.d2 += property;
		case eProPerty����:MagicSoil.d2 += property;
		case eProPerty�׿�:MagicThunder.d2 += property;

		default:ERRBOX; break;
		}
	}
	startid += prop[startid] * 2 + 1;
	if (m_HP > HPMax.GetData())
		m_HP = HPMax.GetData();
	if (m_HPHurtMax > HPMax.GetData())
		m_HPHurtMax = HPMax.GetData();
	if (m_MP > MPMax.GetData())
		m_MP = MPMax.GetData();
}

bool cPropertyData::Save(sOstream& File, bool bPet)
{
	File << modeid << " ";
	if (-1 == modeid)
		return false;
	if (bPet)
	{
		m_JinJieNum.Save(File);
	}
	m_RanSe.Save(File);
	File << m_Name << "\n";
	File << m_dataFileName << " ";
	File << m_HP << "\n";
	File << m_HPHurtMax << " ";
	HPMax.Save(File);
	File << m_MP << "\n";
	MPMax.Save(File);
	File << m_CP << "\n";
	File << m_CPMax << "\n";

	File << m_LV << "\n";
	m_ZiZhi.Save(File);
	m_AddPoint.Save(File);
	//���Ե�
	File << PointStr << " ";
	File << PointDex << " ";
	File << PointMag << " ";
	File << PointBody << " ";
	//	File << m_ProPertySpd << "\n";
	////////////////////////////////////////////////////////////////////////// �Ǻ���
	File << PointAgi << " ";
	File << PointRemain << "\n";
	//����
	Atk.Save(File);
	Hit.Save(File);
	Def.Save(File);
	Mana.Save(File);
	Speed.Save(File);
	Evade.Save(File);

	File << m_EXP << " ";
	File << m_ExpTotal << " ";
	File << m_Race << " ";//����
	File << m_AiLv << " ";
	File << m_StrongLv << "\n";

	File << m_NumofBBSkill << "\n";
	for (int i = 0; i < m_NumofBBSkill; i++)
		File << m_petSkills[i]->m_Id << " ";
	File << "\n";
	m_Controler.Save(File);
	for (int i = 0; i < 3; i++)
		m_Equips[i].Save(File);
	File << "\n";
	//��������
	for (int i = 0; i < c_NumFuZhu; i++)
		File << m_FuZhuSkillLvList[i] << " ";
	//
	File << "\n";
	File << LiveHp << " ";
	File << LiveMp << " ";
	File << LiveCp << " ";
	File << m_Physical << " ";
	File << m_PhysicalMax << " ";
	File << m_Energy << " ";
	File << m_EnergyMax << " ";
	File << NightLv << " ";
	File << MpSavePercent << " ";
	File << LiveRestoreRate << " ";
	File << AbnormalResist << " ";
	File << MagicWavePercent << " ";
	File << ComboNumDown << " ";
	File << ComboNumUp << " ";
	File << ShiXueAdd << " ";
	File << BuffedTiemsAdd << " ";
	File << TargetNumAdd << "\n";

	RelifeRate.Save(File);//���
	ParryRate.Save(File); //����  
	CriRate.Save(File); //���� //��ɱ��
	CriRateOfMagic.Save(File); //����
	CriRateOfCure.Save(File);//����

	CriDmgPercent.Save(File); //��ɱ�˺�����
	ComboRate.Save(File);  //������
	ComboRateOfMagic.Save(File); //������

	Pierce�̴�.Save(File);//���ӷ�����
	Pierce�̴�OfMagic.Save(File); //����������

	//������  �����
	HitRate.Save(File);  //����
	HitRateosMagic.Save(File);//����
	HitRateOfSeal.Save(File);//��ӡ
	HitRateOfPoison.Save(File); //��
	//�˺��ӳ�  �����ӳ�
	DmgPercentOfFix.Save(File);//�̶�
	DmgPercentOfMagic.Save(File);//����
	DmgPercent.Save(File);//����
	DmgPercentOfArm.Save(File); //����
	DmgPercentOfPoison.Save(File); //��
	DmgPercentOfCure.Save(File);//����
	//�ٻ����˺��ӳ�

	m_PetDamagePercentMagic.Save(File);//�����˺�
	m_PetDamagePercent.Save(File);//�����˺�
	//�˺�����
	DmgAddOfMagic.Save(File);//�˺��������
	m_DamageAddMagicLv.Save(File);//�����˺��������lv
	DmgAdd.Save(File);//�����˺��������
	m_DamageAddLv.Save(File);  //�����˺����
	//����
	CounterRate.Save(File);
	//����
	StabRate.Save(File);
	StabRateOfMagic.Save(File);    //���������˺�
	StabPercent.Save(File);
	StabPercentOfMagic.Save(File); //����������
	//
	SuckBloodPercent.Save(File);//��Ѫ��
	//
	DmgAddOfCure.Save(File);//��������
	//����������,��������������
	m_AtkDownCP.Save(File);//����CP
	StartMagic.Save(File);
	m_MagDownHPHurt.Save(File);
	m_AtkDownHPHurt.Save(File);
	m_AtkDownMP.Save(File);
	m_AtkDownAtk.Save(File);
	m_AtkDownHit.Save(File);
	m_AtkDownDef.Save(File);
	m_AtkDownWakan.Save(File);
	m_AtkDownSpd.Save(File);
	Spurting.Save(File);
	//
	//������ºͽ�ħ����Ч��
	ParryRate.Save(File);
	ParryRateOfMaigc.Save(File);
	//�ع�
	MagicFire.Save(File); //��
	MagicSoil.Save(File); //��
	MagicWater.Save(File);  //ˮ
	MagicThunder.Save(File);//��

	BoySpecial.Save(File);  //��
	GirlSpecial.Save(File);   //Ů
	GoldSpecial.Save(File);     //�����ع�
	MagSpecial.Save(File);    //ħ���ع�
	ImmortalSpecial.Save(File); //�����ع�
	MonsterSpecial.Save(File);//�����ع�
	PeopleSpecial.Save(File); //��
	ghostSpecial.Save(File);  //���ع�
	machineSpecial.Save(File);//��е�ع�
	if (bPet)
	{
		m_JinJieNum.Save(File);
	}
	File << "\n\n\n";
	return true;
}

bool cPropertyData::Load(sIstream& File, bool bPet)
{
	File >> modeid;
	if (-1 == modeid)
		return false;
	if (bPet)
	{
		m_JinJieNum.Load(File);
		m_RanSe.Read(modeid, File, m_JinJieNum.m_index);
	}
	else
	{
		m_RanSe.Read(modeid + 2000, File, m_JinJieNum.m_index);
	}


	File >> m_Name;
	File >> m_dataFileName;
	File >> m_HP;
	File >> m_HPHurtMax;
	HPMax.Load(File);
	File >> m_MP;
	MPMax.Load(File);
	File >> m_CP;
	File >> m_CPMax;

	File >> m_LV;
	m_ZiZhi.Load(File);
	m_AddPoint.Load(File);
	//���Ե�
	File >> PointStr;
	File >> PointDex;
	File >> PointMag;
	File >> PointBody;
	File >> PointAgi;
	////////////////////////////////////////////////////////////////////////// �Ǻ���
	File >> PointRemain;
	//����
	Atk.Load(File);
	Hit.Load(File);
	Def.Load(File);
	Mana.Load(File);
	Speed.Load(File);
	Evade.Load(File);

	File >> m_EXP;
	File >> m_ExpTotal;
	File >> m_Race;
	File >> m_AiLv;
	File >> m_StrongLv;

	File >> m_NumofBBSkill;
	int petskillid;
	for (int i = 0; i < m_NumofBBSkill; i++)
	{
		File >> petskillid;
		m_petSkills[i] = g_pMainState->m_SkillManager.GetPetSkill(petskillid);
	}
	m_Controler.Load(File);
	for (int i = 0; i < 3; i++)
		m_Equips[i].Load(File);
	//��������
	for (int i = 0; i < c_NumFuZhu; i++)
		File >> m_FuZhuSkillLvList[i];
	//
	File >> LiveHp;
	File >> LiveMp;
	File >> LiveCp;
	File >> m_Physical;
	File >> m_PhysicalMax;
	File >> m_Energy;
	File >> m_EnergyMax;
	File >> NightLv;
	File >> MpSavePercent;
	File >> LiveRestoreRate;
	File >> AbnormalResist;
	File >> MagicWavePercent;
	File >> ComboNumDown;
	File >> ComboNumUp;
	File >> ShiXueAdd;
	File >> BuffedTiemsAdd;
	File >> TargetNumAdd;

	RelifeRate.Load(File);//���
	ParryRate.Load(File); //����  
	CriRate.Load(File); //���� //��ɱ��
	CriRateOfMagic.Load(File); //����
	CriRateOfCure.Load(File);//����

	CriDmgPercent.Load(File); //��ɱ�˺�����
	ComboRate.Load(File);  //������
	ComboRateOfMagic.Load(File); //������

	Pierce�̴�.Load(File);//���ӷ�����
	Pierce�̴�OfMagic.Load(File); //����������

	//������  �����
	HitRate.Load(File);  //����
	HitRateosMagic.Load(File);//����
	HitRateOfSeal.Load(File);//��ӡ
	HitRateOfPoison.Load(File); //��
	//�˺��ӳ�  �����ӳ�
	DmgPercentOfFix.Load(File);//�̶�
	DmgPercentOfMagic.Load(File);//����
	DmgPercent.Load(File);//����
	DmgPercentOfArm.Load(File); //����
	DmgPercentOfPoison.Load(File); //��
	DmgPercentOfCure.Load(File);//����
	//�ٻ����˺��ӳ�
	m_PetDamagePercentMagic.Load(File);//�����˺�
	m_PetDamagePercent.Load(File);//�����˺�
	//�˺�����
	DmgAddOfMagic.Load(File);//�˺��������
	m_DamageAddMagicLv.Load(File);//�����˺��������lv
	DmgAdd.Load(File);//�����˺��������
	m_DamageAddLv.Load(File);  //�����˺����
	//����
	CounterRate.Load(File);
	//����
	StabRate.Load(File);
	StabRateOfMagic.Load(File);    //���������˺�
	StabPercent.Load(File);
	StabPercentOfMagic.Load(File); //����������
	//
	SuckBloodPercent.Load(File);//��Ѫ��
	//
	DmgAddOfCure.Load(File);//������Ч��
	//����������,��������������
	m_AtkDownCP.Load(File);//����CP
	StartMagic.Load(File);
	m_MagDownHPHurt.Load(File);
	m_AtkDownHPHurt.Load(File);
	m_AtkDownMP.Load(File);
	m_AtkDownAtk.Load(File);
	m_AtkDownHit.Load(File);
	m_AtkDownDef.Load(File);
	m_AtkDownWakan.Load(File);
	m_AtkDownSpd.Load(File);
	Spurting.Load(File);
	//

	//������ºͽ�ħ����Ч��
	ParryRate.Load(File);
	ParryRateOfMaigc.Load(File);
	//�ع�
	MagicFire.Load(File); //��
	MagicSoil.Load(File); //��
	MagicWater.Load(File);  //ˮ
	MagicThunder.Load(File);//��

	BoySpecial.Load(File);  //��
	GirlSpecial.Load(File);   //Ů
	GoldSpecial.Load(File);     //�����ع�
	MagSpecial.Load(File);    //ħ���ع�
	ImmortalSpecial.Load(File); //�����ع�
	MonsterSpecial.Load(File);//�����ع�
	PeopleSpecial.Load(File); //��
	ghostSpecial.Load(File);  //���ع�
	machineSpecial.Load(File);//��е�ع�

	if (bPet)m_JinJieNum.Load(File);
	return true;
}


void cPropertyData::lvUpFuZhuSkill(int lv, int FuZhuSkillID)
{
	// 	m_HPMax.SetDataAdd(15 * m_FuZhuSkillLvList[0]);
	// 	m_HPMax.SetDataAddPercent(m_FuZhuSkillLvList[1]);
	// 	m_MPMax.SetDataAddPercent(m_FuZhuSkillLvList[2]);
	// 	m_HiddenWeaponDamagePercent.d1 = m_FuZhuSkillLvList[3] / 5;
	int maxLv = 160;
	if (maxLv <= m_FuZhuSkillLvList[FuZhuSkillID])return;
	if (m_FuZhuSkillLvList[FuZhuSkillID] + lv > maxLv)lv = maxLv - m_FuZhuSkillLvList[FuZhuSkillID];
	m_FuZhuSkillLvList[FuZhuSkillID] += lv;
	switch (FuZhuSkillID)
	{
	case 0: //ǿ׳
		HPMax.SetDataAdd(5 * m_FuZhuSkillLvList[0]);
		break;
	case 1: //ǿ��
		HPMax.SetDataAddPercent(m_FuZhuSkillLvList[1]);
		break;
	case 2: //ڤ��
		MPMax.SetDataAddPercent(m_FuZhuSkillLvList[2]);
		break;
	case 3:  //����
		//		m_HiddenWeaponDamagePercent.d1 = (lv > maxLv) ? maxLv : lv;
		DmgPercentOfArm.d1 -= m_FuZhuSkillLvList[FuZhuSkillID] / 5;
		DmgPercentOfArm.d1 += (m_FuZhuSkillLvList[FuZhuSkillID] + lv) / 5;
		break;
	case 4:  //����
	case 5:  //�÷�
	case 6:  //����
	case 7:  //��ҩ
	case 8:  //���
		break;
	case 9:  //����
		break;
	case 10:  //׷��
		break;
	case 11:
		m_EnergyMax += 5;
		break;
	case 12:
		m_PhysicalMax += 5;
		break;
	default:
		ERRBOX;
		return;
	}

}



void cPropertyData::AutoGetSkill(int id)
{
	sObjPet* pPetdata = g_pMainState->m_PetDataManager.GetPetData(id);
	for (int i = 0; i < pPetdata->m_SkillNum; i++)
	{
		if (rand() % 100 >= (100 - m_StrongLv)) //ÿ��������10%-100%�ļ��ʿ��Եõ�
		{
			g_pMainState->m_SkillManager.SetPetSkill((cPropertyData*)this, pPetdata->m_pPetSkill[i]->m_Id, m_NumofBBSkill);
		}
	}
}


void cPropertyData::ResetAddPoint(bool isBB)
{
	int propertynum;
	//��¼���Ե�����
	propertynum = PointStr + PointDex + PointAgi + PointBody + PointMag + PointRemain - m_LV * 5;
	int idle = propertynum % 5;//����������Ե�0-4���Զ��ӵ�������
	propertynum /= 5;
	//�Ȱ����е����Ե�ȥ��
	AddProPertyAtk(-PointStr);
	AddProPertyDef(-PointDex);
	AddProPertySpd(-PointAgi);
	AddProPertyHp(-PointBody);
	AddProPertyMag(-PointMag);
	int num[5];
	for (int i = 0; i < 5; i++)
	{//��������
		num[i] = /*20 + */m_LV;
	}
	num[0] += propertynum*m_AddPoint.str;
	num[1] += propertynum*m_AddPoint.dex;
	num[2] += propertynum*m_AddPoint.body + idle;
	num[3] += propertynum*m_AddPoint.mag;
	num[4] += propertynum*m_AddPoint.agi;
	//���·���
	AddProPertyAtk(num[0]);
	AddProPertyDef(num[1]);
	AddProPertySpd(num[4]);
	AddProPertyHp(num[2]);
	AddProPertyMag(num[3]);
}

void cPropertyData::Add����(int num)
{
	if (m_Popularity > 1000)return;
	m_Popularity += num;
}

void cPropertyData::SetXLEffect(bool bSetup)
{
	return;
	if (m_bSetupXiuLian == bSetup)return;
	int up = -1;
	if (bSetup)up = 1;
	m_bSetupXiuLian = bSetup;
	DmgPercent.d1 += 2 * m_XiuLian.GetAtk()*up;
	DmgPercent.d2 += 2 * m_XiuLian.GetDef()*up;
	int add;
	add = up * 2 * m_XiuLian.GetMag();
	DmgPercentOfMagic.d1 += add;
	HitRateOfSeal.d1 += add;
	DmgPercentOfCure.d1 += add;
	add = up * 2 * m_XiuLian.GetDMag();
	DmgPercentOfMagic.d2 += add;
	HitRateOfSeal.d2 += add;

}

void cPropertyData::ReadPet(string name, string path)
{
	path = path + name;
	path += ".txt";
	ifstream File;
	File.open(path);
	if (!File)ERRBOX;
	string dustbin;
	int intdustbin;
	File >> modeid;
	getline(File, dustbin);
	if (-1 != modeid)
	{
		return;
	}
	File >> modeid;
	getline(File, dustbin);
	File >> m_Name;
	if (m_Name == "��")ERRBOX;
	getline(File, dustbin);
	m_ZiZhi.Load(File);
	getline(File, dustbin);
	m_AddPoint.Load(File);
	getline(File, dustbin);
	int mengpai;
	File >> mengpai;
	getline(File, dustbin);

	File >> m_NumofBBSkill;
	if (m_NumofBBSkill > 20)ERRBOX;
	getline(File, dustbin);
	for (int i = 0; i < m_NumofBBSkill; i++)
	{
		File >> intdustbin;
		m_petSkills[i] = g_pMainState->m_SkillManager.GetPetSkill(intdustbin);
		AddSkill((ePetSkill)intdustbin);
	}

	File >> LiveHp;			getline(File, dustbin);
	File >> LiveMp;			getline(File, dustbin);
	File >> LiveCp;			getline(File, dustbin);
	NightLv = 0;
	File >> MpSavePercent;		getline(File, dustbin);
	File >> LiveRestoreRate;		getline(File, dustbin);
	File >> AbnormalResist;		getline(File, dustbin);
	File >> MagicWavePercent;	getline(File, dustbin);
	File >> ComboNumDown;		getline(File, dustbin);
	File >> ComboNumUp;			getline(File, dustbin);
	File >> ShiXueAdd;			getline(File, dustbin);
	File >> BuffedTiemsAdd;			getline(File, dustbin);
	File >> TargetNumAdd;		getline(File, dustbin);
	File >> intdustbin;			getline(File, dustbin);
	HPMax.SetDataAdd(intdustbin);

	File >> intdustbin;			getline(File, dustbin);
	MPMax.SetDataAdd(intdustbin);


	File >> intdustbin;			getline(File, dustbin);
	Atk.SetDataAdd(intdustbin);
	File >> intdustbin;			getline(File, dustbin);
	Hit.SetDataAdd(intdustbin);
	File >> intdustbin;			getline(File, dustbin);
	Def.SetDataAdd(intdustbin);
	File >> intdustbin;			getline(File, dustbin);

	Mana.SetDataAdd(intdustbin);
	File >> intdustbin;			getline(File, dustbin);
	Speed.SetDataAdd(intdustbin);
	File >> intdustbin;			getline(File, dustbin);
	Evade.SetDataAdd(intdustbin);
	RelifeRate.Load(File);	getline(File, dustbin);
	ParryRate.Load(File);		getline(File, dustbin);
	CriRate.Load(File);		getline(File, dustbin);
	CriRateOfMagic.Load(File);	getline(File, dustbin);
	CriRateOfCure.Load(File);	getline(File, dustbin);
	CriDmgPercent.Load(File); getline(File, dustbin);
	ComboRate.Load(File);			getline(File, dustbin);
	ComboRateOfMagic.Load(File); getline(File, dustbin);
	Pierce�̴�.Load(File);		getline(File, dustbin);
	Pierce�̴�OfMagic.Load(File);	getline(File, dustbin);


	HitRate.Load(File);					getline(File, dustbin);
	HitRateosMagic.Load(File);				getline(File, dustbin);
	HitRateOfSeal.Load(File);					getline(File, dustbin);
	HitRateOfPoison.Load(File);					getline(File, dustbin);
	DmgPercentOfFix.Load(File);	getline(File, dustbin);
	DmgPercentOfMagic.Load(File);		getline(File, dustbin);
	DmgPercent.Load(File);				getline(File, dustbin);
	DmgPercentOfArm.Load(File);	getline(File, dustbin);
	DmgPercentOfPoison.Load(File);	getline(File, dustbin);
	DmgPercentOfCure.Load(File);		getline(File, dustbin);
	m_PetDamagePercentMagic.Load(File);		getline(File, dustbin);
	m_PetDamagePercent.Load(File);			getline(File, dustbin);
	DmgAddOfMagic.Load(File);			getline(File, dustbin);
	m_DamageAddMagicLv.Load(File);			getline(File, dustbin);
	DmgAdd.Load(File);					getline(File, dustbin);
	m_DamageAddLv.Load(File);				getline(File, dustbin);
	DmgAddOfCure.Load(File);				getline(File, dustbin);
	CounterRate.Load(File);				getline(File, dustbin);
	StabRate.Load(File);					getline(File, dustbin);
	StabRateOfMagic.Load(File);				getline(File, dustbin);
	StabPercent.Load(File);			getline(File, dustbin);
	StabPercentOfMagic.Load(File);		getline(File, dustbin);
	SuckBloodPercent.Load(File);				getline(File, dustbin);

	getline(File, dustbin);
	m_AtkDownCP.Load(File);					getline(File, dustbin);
	StartMagic.Load(File);				getline(File, dustbin);
	m_MagDownHPHurt.Load(File);				getline(File, dustbin);
	m_AtkDownHPHurt.Load(File);				getline(File, dustbin);
	m_AtkDownMP.Load(File);					getline(File, dustbin);
	m_AtkDownAtk.Load(File);				getline(File, dustbin);
	m_AtkDownHit.Load(File);				getline(File, dustbin);
	m_AtkDownDef.Load(File);				getline(File, dustbin);
	m_AtkDownWakan.Load(File);				getline(File, dustbin);
	m_AtkDownSpd.Load(File);				getline(File, dustbin);
	Spurting.Load(File);				getline(File, dustbin);
	ParryRate.Load(File);				getline(File, dustbin);
	ParryRateOfMaigc.Load(File);				getline(File, dustbin);
	MagicFire.Load(File);				getline(File, dustbin);
	MagicSoil.Load(File);				getline(File, dustbin);
	MagicWater.Load(File);				getline(File, dustbin);
	MagicThunder.Load(File);				getline(File, dustbin);
	BoySpecial.Load(File);					getline(File, dustbin);
	GirlSpecial.Load(File);					getline(File, dustbin);
	GoldSpecial.Load(File);					getline(File, dustbin);
	MagSpecial.Load(File);					getline(File, dustbin);
	ImmortalSpecial.Load(File);				getline(File, dustbin);
	MonsterSpecial.Load(File);				getline(File, dustbin);
	PeopleSpecial.Load(File);				getline(File, dustbin);
	ghostSpecial.Load(File);				getline(File, dustbin);
	machineSpecial.Load(File);				getline(File, dustbin);
	getline(File, m_dataFileName);
	if (m_dataFileName == "��")
		m_dataFileName = name;
	File >> m_StrongLv; getline(File, dustbin);
	File >> m_AiLv;  getline(File, dustbin);
	File >> m_Popularity; getline(File, dustbin);
	m_RanSe.Read(modeid, File);

	int nn = m_NumofBBSkill;
	m_NumofBBSkill = 0;
	for (int i = 0; i < nn; i++)
	{
		AddSkill((ePetSkill)m_petSkills[i]->m_Id);
	}


	Atk.SetDataOriginal(CountATK());
	Def.SetDataOriginal(CountDEF());
	HPMax.SetDataOriginal(CountHP());
	Hit.SetDataOriginal(CountHit());
	MPMax.SetDataOriginal(CountMP());
	Speed.SetDataOriginal(CountSpd());
	Mana.SetDataOriginal(CountWakan());
	Evade.SetDataOriginal(CountEvade());
	m_ExpTotal = GetCharacterExp(m_LV);

	// 	AddProPertyAtk(30);
	// 	AddProPertyDef(20);
	// 	AddProPertyHp(20);
	// 	AddProPertyMag(20);
	// 	AddProPertySpd(20);

	FillHpMp();
	File.close();
}


void cPropertyData::Followlv(int lv, bool isBabyMode, bool isAdd, bool isEquip)
{
	if (lv == m_LV)return;
	LeveUp(lv - m_LV, isBabyMode, isAdd);
	if (isEquip)
	{
		sItem2 item;
		item.m_Num = 1;
		int itemid = (m_LV/* - cct::get()->lvGapFromRoleAndBaby*/) / 10;

		if (itemid > 16)itemid = 16;
		//		if (0 == m_PetEquip[0].GetNum() || m_PetEquip[0].GetID() < itemid)
		{
			// 			int baoshinum = itemid;
			// 			if (baoshinum > g_pMainState->m_GlobalButton[5])
			// 				baoshinum = g_pMainState->m_GlobalButton[5];
			for (int j = 0; j < 3; j++)
			{
				if (m_Equips[j].GetNum() && !m_Equips[j].m_Property.size())
				{
					asert(false, "����װ��������");
				}
				//				sItem2 baoshi;
				//				int baoshiid = -1;
				item.Set(32 + j, itemid);
				int dusbin = (m_AddPoint.str > 0) ? 0 : 1;
				g_pMainState->m_ItemManage.AutoItemProperty(&item, m_Popularity, dusbin);
				g_pMainState->m_ItemManage.AutoFuShi(&item, m_LV, eMP_��);
				// 				switch (j)
				// 				{
				// 				case 0:
				// 					if (m_AddPoint.atk > 2)
				// 						baoshiid = 15;
				// 					else
				// 						baoshiid = 12;
				// 					break;
				// 				case 1:
				// 					baoshiid = 11;
				// 					break;
				// 				case 2:
				// 					baoshiid = 16;
				// 					break;
				// 				}
				// 				baoshi.Set(29, baoshiid);
				// 				for (int i = 0; i < baoshinum; i++)
				// 					g_pMainState->m_ItemManage.XiangQian(item, baoshi);
				PetEquip(j, -1);
				m_Equips[j] = item;
				PetEquip(j, 1);
			}
		}
		FillHpMp();
	}
}

void cPropertyData::AddHpZZ(int num)
{
	if (!num || !_isBabyModeForLvup)return;
	bool isBabyOld = _isBabyModeForLvup;
	_isBabyModeForLvup = true;
	HPMax.AddDataOriginal(-CountHP());
	m_ZiZhi.hp += num;
	HPMax.AddDataOriginal(CountHP());
	m_HPHurtMax = HPMax.GetData();
	m_HP = m_HPHurtMax;
	_isBabyModeForLvup = isBabyOld;
}
void cPropertyData::AddGrowing(int num)
{
	if (!num || !_isBabyModeForLvup)return;
	bool isBabyOld = _isBabyModeForLvup;
	_isBabyModeForLvup = true;
	int atk, def, mag, spd, hp;
	atk = PointStr;
	def = PointDex;
	spd = PointAgi;
	hp = PointBody;
	mag = PointMag;
	bool isBB = true;
	AddProPertyAtk(-atk);
	AddProPertyDef(-def);
	AddProPertyMag(-mag);
	AddProPertyHp(-hp);
	AddProPertySpd(-spd);
	m_ZiZhi.grow += num;
	AddProPertyAtk(atk);
	AddProPertyDef(def);
	AddProPertyMag(mag);
	AddProPertyHp(hp);
	AddProPertySpd(spd);
	_isBabyModeForLvup = isBabyOld;
}

void cPropertyData::AddMagZZ(int num)
{
	if (!num || !_isBabyModeForLvup)return;
	bool isBabyOld = _isBabyModeForLvup;
	_isBabyModeForLvup = true;
	MPMax.AddDataOriginal(-CountMP());
	Mana.AddDataOriginal(-CountWakan());
	m_ZiZhi.mag += num;
	MPMax.AddDataOriginal(CountMP());
	Mana.AddDataOriginal(CountWakan());
	m_MP = MPMax.GetData();
	_isBabyModeForLvup = isBabyOld;
}

void cPropertyData::AddAtkZZ(int num)
{
	if (!num || !_isBabyModeForLvup)return;
	bool isBabyOld = _isBabyModeForLvup;
	_isBabyModeForLvup = true;
	Atk.AddDataOriginal(-CountATK());
	Hit.AddDataOriginal(-CountHit());
	m_ZiZhi.atk += num;
	Atk.AddDataOriginal(CountATK());
	Hit.AddDataOriginal(CountHit());
	_isBabyModeForLvup = isBabyOld;
}
void cPropertyData::AddAvoidZZ(int num)
{
	if (!num || !_isBabyModeForLvup)return;
	bool isBabyOld = _isBabyModeForLvup;
	_isBabyModeForLvup = true;
	Evade.AddDataOriginal(-CountEvade());
	m_ZiZhi.avoid += num;
	Evade.AddDataOriginal(CountEvade());
	_isBabyModeForLvup = isBabyOld;
}
void cPropertyData::AddSpdZZ(int num)
{
	if (!num || !_isBabyModeForLvup)return;
	bool isBabyOld = _isBabyModeForLvup;
	_isBabyModeForLvup = true;
	Speed.AddDataOriginal(-CountSpd());
	m_ZiZhi.speed += num;
	Speed.AddDataOriginal(CountSpd());
	_isBabyModeForLvup = isBabyOld;
}

void cPropertyData::AddDefZZ(int num)
{
	if (!num || !_isBabyModeForLvup)return;
	bool isBabyOld = _isBabyModeForLvup;
	_isBabyModeForLvup = true;
	Def.AddDataOriginal(-CountDEF());
	m_ZiZhi.def += num;
	Def.AddDataOriginal(CountDEF());
	_isBabyModeForLvup = isBabyOld;
}


#endif