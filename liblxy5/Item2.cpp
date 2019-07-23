#include "_global.h"


int sItem2::GetType()
{
	if (!m_pItemData)return -1;
	return m_pItemData->m_Type;
}

int sItem2::GetID()
{
	return m_pItemData->m_ID;
}

std::string sItem2::GetName()
{
	return m_pItemData->m_Name;
}

std::string sItem2::GetText()
{
	return m_pItemData->m_Text;
}

void sItem2::Set(int type, int id, bool needclear)
{
	if (needclear)m_Property.clear();
	m_pItemData = g_pMainState->m_ItemManage.GetItem(type, id);

}

void sItem2::SaveCode(sOstream& File)
{
	File << g_strSpace << m_Num << g_strSpace;
	if (m_Num > 0)
	{
		File << m_pItemData->m_Type << g_strSpace;
		File << m_pItemData->m_ID << g_strSpace;
		int lv = m_pItemData->GetLv();
		if ((m_pItemData->m_Type == 28 && m_pItemData->m_ID >= 12 && m_pItemData->m_ID <= 16) || 
			(m_pItemData->m_Type == 24 && m_pItemData->m_ID == 11))
		{
			// ���� �¹�
			File << (m_strProperty.empty() ? 0 : 1) << g_strSpace;
			if (m_strProperty.size())
			{
				File << m_strProperty << g_strSpace;
			}
		}
// 		else if (cct::isWeapon(m_pItemData) && lv >= 90 && lv <= 140)
// 		{
// 			File << lv << g_strSpace;
// 		}
		File << m_Property.size() << g_strSpace;
		for (int i = 0; i < m_Property.size(); i++)
		{
			File << m_Property[i] << g_strSpace;
		}
	}
}




static vector<int> s_stone_pros = { eProPerty��Ѫ, eProPerty�ٶ�, eProPerty����, eProPerty��, eProPerty�׿�, eProPertyˮ��, eProPerty����,
eProPerty����, eProPerty���, eProPerty�˺�, eProPerty����, eProPerty�ٶ�, eProPerty����, eProPerty����, eProPerty���, eProPerty�˺�, eProPerty��Ѫ };
static vector<int> s_stoneValues = { 40, 8, 25, 2, 2, 2, 2, 6, 40, 8, 12, 6, 4, 8, 30, 10, 30 };
static int getEquipBase(int lv, eProPerty e)
{
	if (lv < 10)
	{
		// AutoItemProperty ��С
		lv = 10;
	}
	switch (e)
	{
	case eProPerty�˺�:
		// ����
		return 10 + lv * 3 + lv / 5 + lv * 6 / 5;
		// ��ʱ
		return lv;
		// ����
		return 10 + lv / 2;
		break;
	case eProPerty����:
		// ����
		return 10 + lv * 7 / 2 + lv / 6 + lv;
		// ��ʱ
		return lv;
		break;
	case eProPerty����:
		return 4 + lv / 8 + lv / 20;
		break;
	case eProPerty����:
		// װ��
		return 5 + lv / 3 + lv / 14 + lv / 5;
		// �·�
		return 10 + lv * 5 / 3 + lv / 5 + lv / 2;
		// ��ʱ 
		return lv;
		// ����
		return 8 + lv * 3 / 5 + lv / 6;
		break;
	case eProPertyħ��:
		// ͷ��
		return 5 + lv + lv / 10 + lv / 3;
		// ��ʱ
		return lv * 2;
		// ����
		return 30 + lv * 3 / 2;
		break;
	case eProPerty����:
		// ����
		return 5 + lv * 6 / 5 + lv / 9 + lv * 2 / 5;
		// ����
		return 4 + lv / 4;
		break;
	case eProPerty�ٶ�:
		// ��ʱ
		return (lv + (160 - lv) / 2) / 5;
		// ����
		return 4 + lv / 5 + lv / 10;
		break;
	case eProPerty��Ѫ:
		// ����
		return 10 + lv * 2 + lv / 5 + lv * 2 / 3;
		// ��ʱ
		return lv * 2;
		// ����
		return 30 + lv * 3 / 2;
		break;
	case eProPerty����:
	case eProPerty����:
	case eProPerty����:
	case eProPertyħ��:
	case eProPerty����:
		// ˫��
		return 3 + lv / 5;
		// Ь��
		return 5 + lv / 3 + lv / 17 + lv / 10;
		// ��ʱ
		return lv / 5;
// 	case eProPertyˮ��:
// 	case eProPerty��:
// 	case eProPerty����:
// 	case eProPerty�׿�:
// 		return slv * 2;
// 	case eProPerty���:
// 		return slv * 40;
// 		break;
	case eProPerty����:
	case eProPerty����:
	case eProPerty����:
	case eProPerty���:
	case eProPerty�ظ�:
		return (lv + (160 - lv) / 2) * 3 / 10;
	case eProPerty��ŭ:
		return (lv + (160 - lv) / 2) / 5;
	}
	return 0;
}

static int getEquipTemp(int lv, eProPerty e)
{
	if (lv < 10)
	{
		lv = 10;
	}
	switch (e)
	{
	case eProPerty�˺�:
		// ��ʱ
	case eProPerty����:
		// ��ʱ
	case eProPerty����:
		// ��ʱ 
		return lv + (160 - lv) / 2;
	case eProPertyħ��:
		// ��ʱ
		return (lv + (160 - lv) / 2) * 2;
	case eProPerty�ٶ�:
		// ��ʱ
		return (lv + (160 - lv) / 2) / 5;
	case eProPerty��Ѫ:
		// ��ʱ
		return (lv + (160 - lv) / 2) * 2;
	case eProPerty����:
	case eProPerty����:
	case eProPerty����:
	case eProPertyħ��:
	case eProPerty����:
		// ��ʱ
		return (lv + (160 - lv) / 2) / 5;
	default:
		return getEquipBase(lv, e);
	}
	return 0;
}

static int getEquipBB(int lv, eProPerty e)
{
	if (lv < 10)
	{
		lv = 10;
	}
	switch (e)
	{
	case eProPerty�˺�:
		// ����
		return 10 + lv / 2;
	case eProPerty����:
		// ����
		return 8 + lv * 3 / 5 + lv / 6;
	case eProPertyħ��:
		// ����
		return 30 + lv * 3 / 2;
	case eProPerty����:
		// ����
		return 4 + lv / 4;
	case eProPerty�ٶ�:
		// ����
		return 4 + lv / 5 + lv / 10;
	case eProPerty��Ѫ:
		// ����
		return 30 + lv * 3 / 2;
	default:
		return getEquipBase(lv, e);
	}
	return 0;
}


void sItem2::LoadCode(sIstream& File)
{
	File >> m_Num;
	if (m_Num > 0)
	{
		int type, id;
		File >> type;
		File >> id;
		m_pItemData = g_pMainState->m_ItemManage.GetItem(type, id);

		if ((type == 28 && id >= 12 && id <= 16) || (type == 24 && id == 11))
		{
			int havestring;
			File >> havestring;
			if (havestring)
			{
				File >> m_strProperty;
			}
			else
			{
				m_strProperty = "";
			}
		}
//		else if (isWeapon(m_pItemData) && )
		int propnum;
		File >> propnum;
		if (propnum > 0)
		{
			m_Property.resize(propnum);
			for (int k = 0; k < m_Property.size(); k++)
			{
				File >> m_Property[k];
			}
		}
	}
	if (m_Num < 1)
	{
		return;
	}
	
	bool isEB = cct::isEquipBB(m_pItemData);
	if (!cct::isEquip(m_pItemData) && !isEB)
	{
		return;
	}
	
	/*const */auto& ps = m_Property;
	if (ps.size() < 12)
	{
//		ERRBOX2(1);
		m_Num = 0;
		return;
	}

	if (ps[0] * ps[1] < 0)
	{
		// ǿ��
		ERRBOX2(2);
	}
	if (ps[10] * ps[11] < 0)
	{
		// ��Ƕ
		ERRBOX2(3);
	}

	int lv = m_pItemData->GetLv();
	if (cct::isWJB(this))
	{
		if (ps[0] > cct::MaxStoneWJB)
		{
			// ��ʯ���
			ERRBOX2(4);
		}
	}
	else
	{
		if (ps[0] > lv / 10)
		{
			// �޸��ɴ浵 �޼���ʯ�ȼ�
			ps[0] = lv / 10;
			// ��ʯ���
			// ERRBOX2(5);
		}
	}

	if (isEB)
	{
		for (int i = 2; i <= 9; i += 2)
		{
			if (ps[i] < 0)
			{
				continue;
			}
			if (ps[i + 1] > getEquipBB(lv, (eProPerty)ps[i]) + 10)
			{
				// ��������
				ERRBOX2(6);
			}
		}
		return;
	}

	bool isE = cct::isEquipButWeapon(m_pItemData);
	bool isC = GetType() == 17 || GetType() == 18;
	bool isS = GetType() == 21;

	int i;
	auto cb = [&](int v)
	{
		int p = ps[i + 1];
		if (ps[0] > 0)
		{
			if (ps[i] == s_stone_pros[ps[1]])
			{
				p -= ps[0] * s_stoneValues[ps[1]];
			}
		}
		if (p > v + 10)
		{
			ccc_msgbox("��������<item>");
			g_StateType = 0;
		}
	};

	for (i = 2; i <= 5; i += 2)
	{
		if (isC && ps[i] == eProPerty::eProPerty����)
		{
			cb(10 + lv * 5 / 3 + lv / 5 + lv / 2);
		}
		else if (isS && ps[i] == eProPerty::eProPerty����)
		{
			cb(5 + lv / 3 + lv / 17 + lv / 10);
		}
		else if (ps[i] >= 0)
		{
			cb(getEquipBase(lv, (eProPerty)ps[i]));
		}
	}

	for (i = 6; i <= 9; i += 2)
	{
		if (ps[i] < 0)
		{
			continue;
		}
		cb(getEquipBase(lv, (eProPerty)ps[i]));
	}

	for (i = 16; i < ps.size(); i += 2)
	{
		cb(getEquipTemp(lv, (eProPerty)ps[i]));
	}

	if (cct::isWJB(this))
	{
		if (m_Property[0] >= 0 && m_Property[1] >= 0)
		{
			g_pMainState->m_ItemManage.SetUpBaoShi(m_Property, m_Property[1], -m_Property[0], false);
			lv = m_pItemData->GetLv() / 10;
			g_pMainState->m_ItemManage.SetUpBaoShi(m_Property, m_Property[1], m_Property[0] = lv, false);
		}
	}
}



void sItem2::Save(ofstream& File)
{
	File << g_strSpace << m_Num << g_strSpace;
	if (m_Num > 0)
	{
		File << m_pItemData->m_Type << g_strSpace;
		File << m_pItemData->m_ID << g_strSpace;
		File << (m_strProperty.empty() ? 0 : 1) << g_strSpace;
		if (m_strProperty.size())
		{
			File << m_strProperty << g_strSpace;
		}
		File << m_Property.size() << g_strSpace;
		for (int i = 0; i < m_Property.size(); i++)
		{
			File << m_Property[i] << g_strSpace;
		}
	}
}

void sItem2::Load(ifstream& File)
{
	File >> m_Num;
	if (m_Num > 0)
	{
		int type, id;
		File >> type;
		File >> id;
		m_pItemData = g_pMainState->m_ItemManage.GetItem(type, id);

		int havestring;
		File >> havestring;
		if (havestring)
		{
			File >> m_strProperty;
		}
		else
		{
			m_strProperty = "";
		}
		int propnum;
		File >> propnum;
		if (propnum > 0)
		{
			m_Property.resize(propnum);
			for (int i = 0; i < m_Property.size(); i++)
			{
				File >> m_Property[i];
			}
		}
	}
}