#include "_global.h"

bool cct::isWeapon(const sItem* item)
{
	switch (item->m_Type)
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
	case 42:
	case 43:
	case 44:
		return true;
	}
	return false;
}

bool cct::isWeapon(const sItem2* item)
{
	return isWeapon(item->m_pItemData);
}

bool cct::isEquipButWeapon(const sItem* item)
{
	switch (item->m_Type)
	{
	case 15:
	case 16:
	case 17:
	case 18:
	case 19:
	case 20:
	case 21:
		return true;
	}
	return false;
}

bool cct::isEquipButWeapon(const sItem2* item)
{
	return isEquipButWeapon(item->m_pItemData);
}

bool cct::isEquip(const sItem* item)
{
	return isWeapon(item) || isEquipButWeapon(item);
}

bool cct::isEquip(const sItem2* item)
{
	return isEquip(item->m_pItemData);
}

bool cct::isEquipBB(const sItem* item)
{
	switch (item->m_Type)
	{
	case 32:
	case 33:
	case 34:
		return true;
	}
	return false;
}

bool cct::isEquipBB(const sItem2* item)
{
	return isEquipBB(item->m_pItemData);
}


bool cct::isWJB(const sItem2* item)
{
	return item->m_Property.size() > 13 && item->m_Property[13] >= 0;
}


vector<int> cct::getSpecialSkills()
{
	static vector<int> skills;
	if (skills.empty())
	{
		for (int i = 0; i <= 13; ++i)
		{
			skills.push_back(i);
		}
		for (int i = 16; i <= 35; ++i)
		{
			skills.push_back(i);
		}
		skills.push_back(40);
		skills.push_back(47);
		skills.push_back(48);
	}
	return skills;
}

int cct::getModel(int model)
{
	// ��ɫ2000
	if (model >= 2000) return model - 2000;
	// npc 1000
	if (model >= 1000) return model - 1000;
	// bb
	return model;
}

int cct::getMenpai(int mp)
{
	if (mp == eMP_���)
	{
		int r = rand() % 100;
		if (r < 10)
		{
			mp = eMP_��ϵ;
		}
		else if (r < 90)
		{
			mp = eMP_���;
		}
		else
		{
			mp = eMP_����;
		}
	}
	if (mp == eMP_����)
	{
		static vector<int> mps = { eMP_���ƹٸ�, eMP_ʨ����, eMP_�貨�� };
		return mps[rand() % mps.size()];
	}
	if (mp == eMP_��ϵ)
	{
		static vector<int> mps = { eMP_��������, eMP_ħ��կ, eMP_��ľ�� };
		return mps[rand() % mps.size()];
	}
	if (mp == eMP_���)
	{
		static vector<int> mps = { eMP_���ƹٸ�, eMP_��������, eMP_ʨ����, eMP_ħ��կ, eMP_�貨��, eMP_��ľ�� };
		return mps[rand() % mps.size()];
	}
	if (mp == eMP_����)
	{
		static vector<int> mps = { eMP_���ܵظ�, eMP_������, eMP_�޵׶�, eMP_����ɽ };
		mp = mps[rand() % mps.size()];
	}
	if (mp == eMP_��ϵ)
	{
		static vector<int> mps = { eMP_Ů����, eMP_����ɽ, eMP_��˿��, eMP_��ׯ��, eMP_�칬, eMP_�޵׶� };
		return mps[rand() % mps.size()];
	}
	return mp;
	if (mp == eMP_���)
	{
		static vector<int> mps = { eMP_Ů����, eMP_����ɽ,
			eMP_���ƹٸ�, eMP_��������, eMP_ʨ����, eMP_ħ��կ, eMP_�貨��, eMP_��ľ��,
			eMP_������, eMP_���ܵظ�, eMP_����ɽ, eMP_�޵׶�,
			eMP_���ƹٸ�, eMP_��������, eMP_ʨ����, eMP_ħ��կ, eMP_�貨��, eMP_��ľ��,
			eMP_���ƹٸ�, eMP_��������, eMP_ʨ����, eMP_ħ��կ, eMP_�貨��, eMP_��ľ��,
			eMP_������, eMP_���ܵظ�, eMP_����ɽ, eMP_�޵׶�,
			eMP_���ƹٸ�, eMP_��������, eMP_ʨ����, eMP_ħ��կ, eMP_�貨��, eMP_��ľ��,
			eMP_���ƹٸ�, eMP_��������, eMP_ʨ����, eMP_ħ��կ, eMP_�貨��, eMP_��ľ��,
			eMP_������, eMP_���ܵظ�, eMP_����ɽ, eMP_�޵׶�,
			eMP_���ƹٸ�, eMP_��������, eMP_ʨ����, eMP_ħ��կ, eMP_�貨��, eMP_��ľ��,
			eMP_��ׯ��, eMP_�칬, eMP_��˿�� };
		return mps[rand() % mps.size()];
		return (eMengPai)(rand() % c_MenPaiNumber);
	}
	return mp;
}

int cct::getCurrMaxXiulianLv(int pclv)
{
	if (pclv < 25)
	{
		return 0;
	}
	return min((pclv - 20) / 5, MaxXL);
}


void cct::setINT(int i, int v)
{
	g_GlobalValues[i] = v;
}

int cct::getINT(int i)
{
	return g_GlobalValues[i];
}

void cct::switchINT(int i)
{ 
	setINT(i, !getINT(i)); 
}

void cct::setDelta(ulong magic, int& delta)
{
	switch (magic)
	{
	case 0xF71DEAF7: // 31ߴߴ����
	case 0x774B7CEF: // 132 �������
		delta /= 2;
		break;
	case 0xC4FABE4C: // 107 ������
	case 0x2DEE722A: // 108 ��ã��
		delta /= 3;
		break;
	default:
		if (delta <= 8)
		{
			delta = 1;
		}
		else if (delta <= 12)
		{
			delta = 2;
		}
		else
		{
			delta = 5;
		}
	}
}


void cct::setMagicPos(ulong magic, int& pos)
{
	switch (magic)
	{
	case 0xB073119D: // 14 ����
	case 0x2406DA40: // 15 ʧ��
	case 0x5BCBB64F: // 28 ����

	case 0xF71DEAF7: // 31ߴߴ����
		//	case 0x9E4E9755: // 35 ����

	case 0x2C2DA419: // 89 ����Ǭ��
	case 0x1CFE70FA: // 90 ����
	case 0x7C7D67A6: // 91 ���
	case 0x46038131: // 105 �չ⻪
	case 0x2DEE722A: // 108 ��ã
	case 0x09CCB0F3: // 112 �鶯
	case 0xD6BF55AD: // 115 �����ķ�
	case 0x2711A4A3: // 117 �й���
	case 0xB0FDC1B2: // 154 ����
	case 0x1C57DA8A: // 154 ����
	case 0x0E1DCDB9: // 187 ���ⱦ ����ƫ
	case 0xADF90980: // 201 �׻�
	case 0x3200B6CC: // 2084 2085 �׻� 
		pos = -10;
		break;
	case 0x0116C932: // 27 ���
	case 0x9A94D461: // 68 ����
	case 0x6044E21A: // ����
		//	case 0xCEAF0E44: // 159 ��������
		pos = 0;
		break;
	}
}


int cct::getPetModel(int lvTake1 /* = 0 */, int lvTake2 /* = 85 */, bool gadIf0 /* = false */)
{
	int m;
	int lv;
	do 
	{
		m = rand() % c_PetNumber;
		lv = g_pMainState->m_PetDataManager.GetPetData(m)->m_LvTake;
		if (lv == 115)
		{
			continue;
		}
		if (lv == 0 && !gadIf0 && !((m >= eСëͷ && m <= eСħͷ) || m == e���� || m == e�޺�))
		{
			continue;
		}
		if (lv >= lvTake1 && lv <= lvTake2)
		{
			break;
		}

	} while (true);
	return m;
}


void cct::saveGlobal(sOstream& File)
{
	forr (g_GlobalValues, i)
	{
		File << g_GlobalValues[i] << g_strSpace;
	}
}

void cct::loadGlobal(sIstream& File)
{
	forr(g_GlobalValues, i)
	{
		File >> g_GlobalValues[i];
	}
}

void cct::autoSave()
{
	if (g_StateType == STATE_MAIN)
	{
		g_pMainState->m_InterfaceSystem.Save(0);
	}
}

static vector<string> s_fields =
{ "������", "����«��", "����ɽ", "˿��֮·", "���ƹ���", "���ƾ���", "���ٽ���", "С����",
"Ů���", "�¹�"/*, "���԰"*/, "����ɽ", "ī�ҽ���", "�����", "���¶�",
"������", "����ɽ", "����Ұ��", "����ɽ", "��ĸ�ӵ�", "�����ɵ�", "���ֶ���", "���ƶ�"
};

const vector<string>& cct::getFields()
{
	return s_fields;
}

static vector<string> s_cities = { "������", "������", "���ٴ�", "����Ů��", "���Ϲ�", "�����", "ī�Ҵ�", "��Ե����" };
const vector<string>& cct::getCitiesButCA()
{
	return s_cities;
}

