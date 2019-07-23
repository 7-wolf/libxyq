#include "_global.h"


bool ItemManager::SetItemDescribe(int x, int y, cDescribe& pDescribe, sItem2* pItem)
{
	if (!pItem|| !pItem->GetNum() || !pItem->m_pItemData)
	{
		if (pDescribe.m_NeedShow)
			pDescribe.OnOff(false);
		return false;
	}

	m_Color[2] = RGB(250, 250, 0);
	m_Color[0] = RGB(250, 250, 0);
	m_Color[1] = RGB(220, 220, 220);
	for (int i = 3; i < m_text.size(); i++)
	{
		m_Color[i] = RGB(0, 255, 0);
	}

	ostringstream oss;
	m_text[0] = pItem->GetName();
	m_text[1] = pItem->GetText();
	m_numtext = 2;
	if (cct::isEquip(pItem) || cct::isEquipBB(pItem))
	{
		// \n
		m_text[2] = "�ȼ� " + toString("%d", pItem->m_pItemData->GetLv());
		m_numtext = 3;
		makePropStringEquip(pItem);
		pDescribe.Set(x + 25, y + 25, pItem->m_pItemData->m_BigHead, m_numtext, &m_text[0], &m_Color[0]);
		pDescribe.OnOff(true);
		return true;
	}
	int itemtype = pItem->GetType();
	switch (itemtype)
	{
	case 22:
	case 23:
	case 24:
	case 25:
	case 27:
		break;
	case 28:
		if (1)
		{
			switch (pItem->GetID())
			{
			case 0://
				ERRBOX;
				break;
			case 6://�ر�ͼ
				if (1)
				{
					if (pItem->m_Property.empty() || pItem->m_Property[0] < 0)
					{
						m_text[2] = "���ű�ͼ�Ѿ�����";
						break;
					}
					m_numtext += 1;
					oss.str("");
				//	oss << "�����д�ŵص�:\n";
					oss << g_pMainState->m_TaskBaoTu.m_MapNameList[pItem->m_Property[0]] << " ";


					oss << pItem->m_Property[1] << " ";
					oss << pItem->m_Property[2];
					m_text[2] = oss.str();
				}
				break;
			case 7:
				if (pItem->m_Property.empty())
				{
					break;
				}
				m_numtext += 1;
				oss.str("");
				oss << "�ȼ�:";
				oss << pItem->m_Property[0];
				m_text[2] = oss.str();
				break;
			case 8:
				if (pItem->m_Property.empty())
				{
					break;
				}
				m_numtext += 2 - 1;
// 				oss.str("");
// 				oss << "����:";
// 				oss << g_pMainState->m_ItemManage.m_ItemTypeName[pItem->m_Property[0]];
// 				m_text[2] = oss.str();
				oss.str("");
				oss << "�ȼ�:";
				oss << pItem->m_Property[0];
				m_text[/*3*/2] = oss.str();
				break;
			case 9://���Ŀǰû�б�ʹ��
				if (!pItem->m_Property.empty())
				{
					m_numtext += 2;
					oss.str("");
					oss << "������";
					oss << pItem->m_Property[0];
					oss << "Ǯ";
					m_text[2] = oss.str();
					oss.str("");
					oss.str("");
					oss << "Ŀ��";
					oss << pItem->m_Property[1];
					oss << "Ǯ";
					m_text[3] = oss.str();
				}
			default:
				break;
			}

		}
		break;
	case 31:
		if (1)
		{
			oss.str("");
			oss << "���Ը�";
			oss << g_pMainState->m_ZuoQi.m_ZuoQi[pItem->GetID() / 3].Name;
			oss << "װ��";
			m_text[1] = oss.str();
		}
		break;
// 	case 32:
// 	case 33:
// 	case 34:
// 		if (1)
// 		{
// 			oss.str("");
// 			oss << "�ȼ� ";
// 			oss << pItem->m_pItemData->m_ID * 10 + 5;
// 			m_text[m_numtext] = oss.str();
// 			oss.str("");
// 			m_numtext += 1;
// 			if (pItem->m_Property.size() == 0)
// 			{
// 				oss.str("");
// 				oss << "δ����";
// 				m_text[m_numtext] = oss.str();
// 				m_numtext += 1;
// 			}
// 			else
// 			{
// 				MakePropString2(pItem);
// 			}
// 
// 		}
// 		break;
// 	case 0:
// 	case 1:
// 	case 2:
// 	case 3:
// 	case 4:
// 	case 5:
// 	case 6:
// 	case 7:
// 	case 8:
// 	case 9:
// 	case 10:
// 	case 11:
// 	case 12:
// 	case 13:
// 	case 14:
// 		if (1)
// 		{
// 			oss.str("");
// 			oss << "�ȼ� ";
// 			oss << pItem->m_pItemData->GetLv();
// 			m_text[m_numtext] = oss.str();
// 			oss.str("");
// 			m_numtext += 1;
// 			if (pItem->m_Property.size() == 0)
// 			{
// 				oss.str("");
// 				oss << "δ����";
// 				m_text[m_numtext] = oss.str();
// 				m_numtext += 1;
// 			}
// 			else
// 			{
// 				MakePropString2(pItem);
// 			}
// 		}
// 		break;
// 	case 15:
// 	case 16:
// 	case 17:
// 	case 18:
// 	case 19:
// 	case 20:
// 	case 21:
// 		if (1)
// 		{
// 			oss.str("");
// 			oss << "�ȼ� ";
// 			oss << pItem->m_pItemData->GetLv();
// 			m_text[m_numtext] = oss.str();
// 			oss.str("");
// 			m_numtext += 1;
// 			if (pItem->m_Property.size() == 0)
// 			{
// 				oss.str("");
// 				oss << "δ����";
// 				m_text[m_numtext] = oss.str();
// 				m_numtext += 1;
// 			}
// 			else
// 			{
// 				MakePropString2(pItem);
// 			}
// 		}
// 		break;
// 	default:
// 		break;
	}
	pDescribe.Set(x + 25, y + 25, pItem->m_pItemData->m_BigHead, m_numtext, &m_text[0], &m_Color[0]);
	pDescribe.OnOff(true);
	return true;
}






std::string ItemManager::MakePropString(vector<int>& prop, int pos)
{
	string str;
	switch (prop[pos])
	{
	case eProPerty�˺�:str = "�˺� "; break;
	case eProPerty����:str = "���� "; break;
	case eProPerty����:str = "���� "; break;
	case eProPertyħ��:str = "ħ�� "; break;
	case eProPerty����:str = "���� "; break;
	case eProPerty�ٶ�:str = "�ٶ� "; break;
	case eProPerty��Ѫ:str = "��Ѫ "; break;
	case eProPerty����:str = "���� "; break;
	case eProPerty����:str = "���� "; break;
	case eProPerty����:str = "���� "; break;
	case eProPertyħ��:str = "ħ�� "; break;
	case eProPerty����:str = "���� "; break;
	case eProPerty��:str = "�� "; break;
	case eProPerty�׿�:str = "�׿� "; break;
	case eProPerty����:str = "���� "; break;
	case eProPertyˮ��:str = "ˮ�� "; break;
	case eProPerty���: str = "���"; break;
	case eProPerty����:str = "���� "; break;
	case eProPerty����:str = "���� "; break;
	case eProPerty����:str = "������� "; break;
	case eProPerty���:str = "������ "; break;
	case eProPerty�ظ�:str = "��Ѫ�ظ� "; break;
	case eProPerty��ŭ:str = "��ŭ "; break;
	case eProPerty����:str = "������ "; break;
	default:
		return str;
	}
	ostringstream oss;
	if (prop[pos + 1] > 0)
	{
		oss << "+";
	}
	oss << prop[pos + 1];
	str += oss.str();
	return str;
}


std::string ItemManager::getProPertyString(int prop)
{
	switch (prop)
	{
	case eProPerty�˺�: return "�˺�";
	case eProPerty����: return "����";
	case eProPerty����: return "����";
	case eProPertyħ��: return "ħ��";
	case eProPerty����: return "����";
	case eProPerty�ٶ�: return "�ٶ�";
	case eProPerty��Ѫ: return "��Ѫ";
	case eProPerty����: return "����";
	case eProPerty����: return "����";
	case eProPerty����: return "����";
	case eProPertyħ��: return "ħ��";
	case eProPerty����: return "����";
	case eProPerty��: return "��";
	case eProPerty�׿�: return "�׿�";
	case eProPerty����: return "����";
	case eProPertyˮ��: return "ˮ��";
	case eProPerty���: return "���";
	case eProPerty����: return "����";
	case eProPerty����: return "����";
	case eProPerty����: return "�������";
	case eProPerty���: return "������";
	case eProPerty�ظ�: return "��Ѫ�ظ�";
	case eProPerty��ŭ: return "��ŭ";
	case eProPerty����: return "������";
	}
	return "error";
}




void ItemManager::MakePropString2(sItem2* item)
{
	int pos = 5;
	vector<int>& prop = item->m_Property;
	ostringstream oss;

	//��������
	m_Color[m_numtext] = RGB(255, 255, 0);
	int num;
	switch (item->GetType())
	{
// 		17  ����
// 			18  Ů��
// 			19  ����
	case 17://��1����������
	case 18:
	case 19:
		if (1)
		{
			m_text[m_numtext] = MakePropString(prop, pos + 1);

			m_numtext += 1;
			num = prop[pos] - 1;
			pos += 3;
		}
		break;
	default: //��2����������
		m_text[m_numtext] = MakePropString(prop, pos + 1);
		m_text[m_numtext] += "\n";
		m_text[m_numtext] += MakePropString(prop, pos + 3);
		m_numtext += 1;
		num = prop[pos] - 2;
		pos += 5;
		break;
	}

	//ǿ���ȼ�
	oss.str("");
	oss << "�����ȼ�: ";
	oss << item->m_Property[0];
	m_Color[m_numtext] = RGB(255, 255, 0);
	m_text[m_numtext] = oss.str();
	m_numtext += 1;

	//�ؼ�
	if (item->m_Property[1] > -1)
	{
		m_Color[m_numtext] = RGB(126, 255, 126);
		oss.str("");
		oss << "�ؼ�:";
		oss << g_pMainState->m_SkillManager.GetSpecialSkill(item->m_Property[1])->m_Name;
		m_text[m_numtext] = oss.str();
		m_numtext += 1;
	}
	if (item->m_Property[2] > -1)
	{
		m_Color[m_numtext] = RGB(126, 126, 255);
		oss.str("");
		oss << "��Ч:";
		oss << g_pMainState->m_SkillManager.GetSpecialSkill2(item->m_Property[2])->m_Text;
		m_text[m_numtext] = oss.str();
		m_numtext += 1;
	}
	if (item->m_Property[3] > -1)
	{
		m_Color[m_numtext] = RGB(126, 126, 255);
		oss.str("");
		oss << "��Ч:";
		oss << g_pMainState->m_SkillManager.GetSpecialSkill2(item->m_Property[3])->m_Text;
		m_text[m_numtext] = oss.str();
		m_numtext += 1;
	}
	if (item->m_Property[4] > -1)
	{
		m_Color[m_numtext] = RGB(126, 126, 255);
		oss.str("");
		oss << "��Ч:";
		oss << g_pMainState->m_SkillManager.GetSpecialSkill2(item->m_Property[4])->m_Text;
		m_text[m_numtext] = oss.str();
		m_numtext += 1;
	}


	//��������
	m_Color[m_numtext] = RGB(0, 255, 0);
	for (int i = 0; i < num; i++)
	{
		if (i % 2 == 0)
		{
			m_text[m_numtext] = MakePropString(prop, pos + i * 2);
		}
		else
		{
			m_text[m_numtext] += "\n";
			m_text[m_numtext] += MakePropString(prop, pos + i * 2);
			m_numtext += 1;
		}
	}
	if (num % 2 == 1)
	{
		m_numtext += 1;
	}

}



void ItemManager::makePropStringEquip(sItem2* item)
{
	const auto& props = item->m_Property;
	string str;
	if (cct::isEquipBB(item))
	{
		str.clear();
		// ���� 2-9
		for (int i = 2; i < 10; i += 2)
		{
			if (props.size() > i && props[i] >= 0)
			{
				str += getProPertyString(props[i]) + toString("+%d ", props[i + 1]);
			}
		}
		if (!str.empty())
		{
			str.pop_back();
		//	str += "\n";
			m_Color[m_numtext] = RGB(255, 255, 0);
			m_text[m_numtext] = str;
			++m_numtext;
		}
		// 0 ����
		// 1 ʯͷ
		if (props.size() > 0 && props[0] >= 0)
		{
			m_Color[m_numtext] = RGB(255, 255, 0);
			// \n
			m_text[m_numtext] = toString("��Ƕ�ȼ�: %d", props[0]);
			++m_numtext;
		}
		// ����
		str.clear();
		if (props.size() > 11 && props[10] >= 0)
		{
			// \n
			m_Color[m_numtext] = RGB(255, 255, 255);
			m_text[m_numtext] = "��ǶЧ��: " + getProPertyString(props[10]) + toString("+%d", props[11]);
			++m_numtext;
		}
		// ��ʯ
		str.clear();
		if (props.size() > 15 && props[15] >= 0)
		{
			// \n
			m_Color[m_numtext] = RGB(126, 126, 255);
			m_text[m_numtext] = "׷�ӷ���: " + g_pMainState->m_SkillManager.GetSkill(props[15])->m_Name;
			++m_numtext;
		}

		return;
	}
	str.clear();
	// ���� 2-5
	for (int i = 2; i <= 5; i += 2)
	{
		if (props.size() > i && props[i] >= 0)
		{
			str += getProPertyString(props[i]) + toString("+%d ", props[i + 1]);
		}
	}
	if (!str.empty())
	{
		str.pop_back();
		// \n
//		str += "\n";
		m_Color[m_numtext] = RGB(255, 255, 0);
		m_text[m_numtext] = str;
		++m_numtext;
	}
	// 0 ����
	// 1 ʯͷ
	if (props[0] >= 0 && props[1] >= 0)
	{
		m_Color[m_numtext] = RGB(255, 255, 0);
		// \n
		m_text[m_numtext] = toString("�����ȼ�: %d %s", props[0], m_ItemList[29][props[1]].m_Name.c_str());
		++m_numtext;
	}

	// ˫�� 6-9
	str.clear();
	for (int i = 6; i <= 9; i += 2)
	{
		if (props.size() > i && props[i] >= 0)
		{
			str += getProPertyString(props[i]) + toString("+%d ", props[i + 1]);
		}
	}
	if (!str.empty())
	{
		// ��ʯ���� 10-11
		if (props.size() > 10 && props[10] >= 0)
		{
			str += getProPertyString(props[10]) + toString("+%d", props[11]);
		}
		else
		{
			str.pop_back();
		}
		// \n
//		str += "\n";
		m_Color[m_numtext] = RGB(0, 255, 0);
		m_text[m_numtext] = str;
		++m_numtext;
	}
	else if (props.size() > 10 && props[10] >= 0)
	{
		// ��ʯ���� 10-11
		m_Color[m_numtext] = RGB(0, 255, 0);
		// \n
		m_text[m_numtext] = getProPertyString(props[10]) + toString("+%d", props[11]);
		++m_numtext;
	}
	// �ؼ� 12
	if (props.size() > 12 && props[12] >= 0)
	{
		m_Color[m_numtext] = RGB(126, 126, 255);
		// \n
		m_text[m_numtext] = "�ؼ�: " + g_pMainState->m_SkillManager.GetSpecialSkill(props[12])->m_Name/* + "\n"*/;
		++m_numtext;
	}
	// �Ƿ��޼��� 13
	if (props.size() > 13 && props[13] >= 0)
	{
		m_Color[m_numtext] = RGB(126, 126, 255);
		m_text[m_numtext] = "��Ч: �޼�������";
		// �Ƿ�����/��ŭ 14
		if (props[14] >= 0)
		{
			// \n
			m_text[m_numtext] += (cct::isWeapon(item)) ? " ����" : " ��ŭ";
		}
		++m_numtext;
	}
	else if (props.size() > 14 && props[14] >= 0)
	{
		// �Ƿ�����/��ŭ 14
		m_Color[m_numtext] = RGB(126, 126, 255);
		m_text[m_numtext] = "��Ч:";
		// \n
		m_text[m_numtext] += (cct::isWeapon(item)) ? " ����" : " ��ŭ";
		++m_numtext;
	}
	// ��ʯ 15
	if (!cct::isWeapon(item) && props.size() > 15 && props[15] >= 0)
	{
		m_Color[m_numtext] = RGB(126, 126, 255);
		m_text[m_numtext] = "����״̬: " + g_pMainState->m_SkillManager.GetSkill(props[15])->m_Name;
		++m_numtext;
	}
	// ��ʱ(����) 16-
	str.clear();
	for (int i = 16; i < props.size(); i += 2)
	{
		if (props[i] >= 0)
		{
			str += "��ʱ" + getProPertyString(props[i]) + toString(" %d\n", props[i + 1]);
		}
	}
	if (!str.empty())
	{
		str.pop_back();
	}
	if (!str.empty())
	{
		m_Color[m_numtext] = RGB(0, 255, 0);
		m_text[m_numtext] = str;
		++m_numtext;
		m_Color[m_numtext] = RGB(255, 255, 255);
		m_text[m_numtext] = "������ ǿ������";
		++m_numtext;
	}
}

