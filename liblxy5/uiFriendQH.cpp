#include "_global.h"


bool cInterfaceFriendQiangHua::Init()
{
	if (m_bInit)return true;
	m_bInit = true;
	m_Back.Load(0x694F39D1);
	m_Back.SetStatic(true);
	m_Cancel.Set(&g_pMainState->m_Cancel);
	m_Cancel.m_bStatic = true;
	m_title.SetColor(RGB(255, 255, 255));
	m_title.SetString("���Ѷ���");
	m_Name.SetColor(RGB(255, 255, 255));
	m_Money.SetColor(RGB(255, 255, 255));

	for (int i = 0; i < 12; i++)
	{
		m_Buttonp[i].Set(&g_pMainState->m_Button4);
		m_Buttonp[i].m_bStatic = true;
		m_Text[i].SetColor(RGB(255, 255, 255));
	}
	m_Text[0].SetString("���򱦱�");
	m_Text[1].SetString("����");
	m_Text[2].SetString("����");
	m_Text[3].SetString("����װ��");

	m_Text[4].SetString("��ɫȾɫ");
	m_Text[5].SetString("����Ⱦɫ");
	m_Text[6].SetString("װ��Ⱦɫ");
	m_Text[7].SetString("����Ⱦɫ");

	m_Text[8].SetString("����");//��ɫǿ��");
	m_Text[9].SetString(""); // ��ս����");
	m_Text[10].SetString("");//����ǿ��");
	m_Text[11].SetString("����");



	Move(g_half320 - m_Back.GetWidth() / 2, g_half240 - m_Back.GetHeight() / 2);

	return true;
}

bool cInterfaceFriendQiangHua::Move(int xPos, int yPos)
{
	m_xPos = xPos;
	m_yPos = yPos;
	m_Back.SetXY(xPos, yPos);
	m_Cancel.SetXY(m_xPos + m_Back.GetWidth() - 20, m_yPos + 3);
	m_title.SetXCenter(m_xPos + 130);
	m_title.SetY(m_yPos + 3);
	m_title.UpdateXCenter();
	m_Name.SetXY(m_xPos + 30, m_yPos + 30);
	m_Money.SetXY(m_xPos + 155, m_yPos + 30);
	int xstart, ystart;
	xstart = m_xPos + 22;
	ystart = m_yPos + 87;
	for (int i = 0; i < 12; i++)
	{
		m_Buttonp[i].SetXY(xstart + (i % 3) * 80, ystart + (i / 3) * 30);
		m_Text[i].SetXCenter(m_Buttonp[i].GetX() + m_Buttonp[i].GetShowWidth() / 2);
		m_Text[i].SetY(m_Buttonp[i].GetY() + 3);
		m_Text[i].UpdateXCenter();
	}
	return true;
}

bool cInterfaceFriendQiangHua::ProcessInput()
{
	if (m_Mode)
	{
		if (!g_pMainState->m_Dialog.m_bRetSelect)
		{
			m_Mode = false;
			switch (g_pMainState->m_Dialog.m_retSelect)
			{
			case 4:
				m_pData->m_bZhuangShi = 0;
				m_pData->m_ZuoQiRanse.partnum = 0;
				m_pData->m_ZhuangShiRanse.partnum = 0;
				m_pData->m_bOnZuoQi = false;
				for (int i = 0; i < 4; i++)
				{
					if (0 == m_pData->m_Name.compare(g_pMainState->m_FightWorkList[i].m_pObj->m_TrueName.GetString()))
					{
						sFightWork& flist = g_pMainState->m_FightWorkList[i];
						cCharacter* pc = (cCharacter*)flist.m_pObj->m_pIndex;
						pc->m_PcData.m_bOnZuoQi = m_pData->m_bOnZuoQi;
						pc->m_PcData.m_ZuoQi.m_ZhuangShi.m_Num = 0;
						flist.m_pObj->m_NowPos = -1;
						flist.m_pObj->Set(POS_STAND);

						break;
					}
				}

				break;
			default:
				if (1)
				{
					m_pData->m_bZhuangShi = 0;
					m_pData->m_bOnZuoQi = false;
					vector<int> list;
					g_pMainState->m_ZuoQi.GetShiPei(list, m_pData->m_modeid);

					m_pData->m_bOnZuoQi = true;
					m_pData->m_ZuoQiID = list[g_pMainState->m_Dialog.m_retSelect];
					m_pData->m_ZuoQiRanse.partnum = 0;
					m_pData->m_ZhuangShiRanse.partnum = 0;
					for (int i = 0; i < 5; i++)
					{
						if (0 == m_pData->m_Name.compare(g_pMainState->m_FightWorkList[i].m_pObj->m_TrueName.GetString()))
						{
							sFightWork& flist = g_pMainState->m_FightWorkList[i];
							cCharacter* pc = (cCharacter*)flist.m_pObj->m_pIndex;
							pc->m_PcData.m_bOnZuoQi = m_pData->m_bOnZuoQi;
							g_pMainState->m_ZuoQi.GetZuoQi(pc->m_PcData, m_pData->m_ZuoQiID);
							pc->m_PcData.m_ZuoQi.m_ZhuangShi.m_Num = 0;
							pc->m_PcData.m_ZuoQiRanSe = m_pData->m_ZuoQiRanse;
							if (m_pData->m_ZuoQiRanse.partnum)
							{
								ulong color = pc->m_PcData.m_ZuoQi.m_pZuoQi->m_ColorID;
								g_pMainState->m_ColorManage.Set(color);
								for (int i = 0; i < pc->m_PcData.m_ZuoQiRanSe.partnum; i++)//����Ⱦɫ
								{
									g_pMainState->m_ColorManage.GetColorMatrix(
										i,
										pc->m_PcData.m_ZuoQiRanSe.GetColorChange(i),
										pc->m_PcData.m_ZuoQiRanSe.m_colormatrix[i]);

								}
							}
							flist.m_pObj->m_NowPos = -1;
							flist.m_pObj->Set(POS_STAND);
							break;
						}
					}

				}
				break;
			}

		}
		return true;
	}
	if (m_Sleeptime > 0)
	{
		g_pMainState->SetMouseOnMap(false);
		m_Sleeptime -= 1;
		return true;
	}

	m_Select = -1;
	ResetButton();
	if (m_bMoveMode)//�ƶ�
	{
		m_Select = 106;
		g_pMainState->SetMouseOnMap(false);
		if (!CheckL())m_bMoveMode = false;
		return true;
	}
	if (!isOn(g_xMouse, g_yMouse, m_Back.m_PreShowRect))return true;
	g_pMainState->SetMouseOnMap(false);
	if (CheckOn(&m_Cancel, 100))return true;
	for (int i = 0; i < 12; i++)
		if (CheckOn(&m_Buttonp[i], i))return true;
	m_Select = 0;
	if (CheckRB())return true;
	m_Select = 107;
	if (CheckL())return true;
	return true;
}
void cInterfaceFriendQiangHua::Change(int id)
{
	for (int i = 0; i < 5; i++)
	{
		if (g_pMainState->m_FightWorkList[i].isExist)
		{
			if (g_pMainState->m_FightWorkList[i].m_pObj->m_TrueName.GetString() == m_pData->m_Name)
			{
				cCharacter* pc = (cCharacter*)g_pMainState->m_FightWorkList[i].m_pObj->m_pIndex;
				pc->UseCard(id);
				m_Mode = 0;
				m_bUpdateTeam = true;
				OnOff(false);
				return;
			}
		}
	}
}

bool cInterfaceFriendQiangHua::CheckL()
{
	if (!g_pMainState->Mouse.GetButtonState(MOUSE_LBUTTON))return false;
	g_pMainState->Mouse.SetLock(MOUSE_LBUTTON);
	m_Sleeptime = 3;
	if (m_frampre)
		m_frampre->SetFrame(1);

	switch (m_Select)
	{
	case 0:
//		g_pMainState->m_InterFaceBuyPet.Init2(m_pData, 0, 0);
		g_pMainState->m_InterFaceBuyPet.OnOff(true);
		m_bUpdateTeam = false;
		break;
	case 1:
		if (1)
		{
			m_bUpdateTeam = true;
			int weapontype[2];
			GetWeaponType(m_pData->m_modeid, weapontype[0], weapontype[1]);
			vector<int> list;
			g_pMainState->m_ItemManage.GetIDlistByLv(list, weapontype[0], g_pCharacter->m_PcData.m_Lv);
			vector<int> list2;
			g_pMainState->m_ItemManage.GetIDlistByLv(list2, weapontype[1], g_pCharacter->m_PcData.m_Lv);
			sItem2 item;
			item.m_Num = 1;
			g_pMainState->m_SelectFriendItem.SetMode(m_pData, cInterSelectFriendItem::eQHװ��);
			for (int i = 0; i < list.size(); i++)
			{
				item.Set(weapontype[0], list[i]);
				g_pMainState->m_SelectFriendItem.Set(item.GetType(), item.GetID(), item.m_pItemData->m_SmallHead);
			}
			for (int i = 0; i < list2.size(); i++)
			{
				item.Set(weapontype[1], list2[i]);
				g_pMainState->m_InterFaceBuy.Set(item, 100);
				g_pMainState->m_SelectFriendItem.Set(item.GetType(), item.GetID(), item.m_pItemData->m_SmallHead);
			}

			g_pMainState->m_SelectFriendItem.OnOff(true);
		}
		break;
	case 2:
		if (1)
		{
			m_bUpdateTeam = true;
			m_Mode = 1;
			g_pMainState->m_Dialog.m_bRetSelect = true;
			vector<string> list;
			list.push_back(g_pMainState->m_ZuoQi.m_ZuoQi[0].Name);
			list.push_back(g_pMainState->m_ZuoQi.m_ZuoQi[1].Name);
			switch (m_pData->m_modeid)
			{
			case eJuSe������:
			case eJuSe��ң��:
			case eJuSe����Ů:
			case eJuSeӢŮ��:
			case eJuSe������:
				list.push_back(g_pMainState->m_ZuoQi.m_ZuoQi[2].Name);
				list.push_back(g_pMainState->m_ZuoQi.m_ZuoQi[3].Name);
				break;
			case eJuSe��ͷ��:
			case eJuSe��ħ��:
			case eJuSe�Ǿ���:
			case eJuSe������:
			case eJuSeɱ����:
				list.push_back(g_pMainState->m_ZuoQi.m_ZuoQi[4].Name);
				list.push_back(g_pMainState->m_ZuoQi.m_ZuoQi[5].Name);
				break;
			case eJuSe��̫��:
			case eJuSe�����:
			case eJuSe���ʶ�:
			case eJuSe���켧:
			case eJuSe������:
				list.push_back(g_pMainState->m_ZuoQi.m_ZuoQi[6].Name);
				list.push_back(g_pMainState->m_ZuoQi.m_ZuoQi[7].Name);
				break;
			default:OnOff(false); return false;
			}
			g_pMainState->m_Dialog.Reset();
			g_pMainState->m_Dialog.m_pObj = g_pMainState->m_FightWorkList[g_pMainState->m_HeroID].m_pObj;
			g_pMainState->m_Dialog.m_bRetSelect = true;
			g_pMainState->m_Dialog.SetString("ѡ������", list[0], list[1], list[2], list[3]);
			g_pMainState->m_Dialog.OnOff(true);

		}
		break;
	case 3:
		if (1)
		{
			if (m_pData->m_ZuoQiID < 0)return true;
			m_bUpdateTeam = true;
			vector<int> list;
			list.push_back(m_pData->m_ZuoQiID * 3);
			list.push_back(m_pData->m_ZuoQiID * 3 + 1);
			list.push_back(m_pData->m_ZuoQiID * 3 + 2);
			sItem2 item;
			item.m_Num = 1;
			g_pMainState->m_SelectFriendItem.SetMode(m_pData, cInterSelectFriendItem::eQH����װ��);
			for (int i = 0; i < list.size(); i++)
			{
				item.Set(31, list[i]);
				g_pMainState->m_SelectFriendItem.Set(item.GetType(), item.GetID(), item.m_pItemData->m_SmallHead);
			}

			g_pMainState->m_SelectFriendItem.OnOff(true);
		}
		break;
	case 4://Ⱦɫ
		if (1)
		{
			m_bUpdateTeam = true;
			g_pMainState->m_InterfaceRanSe.SetMode(0, m_pData->getIDinTeam());
			g_pMainState->m_InterfaceRanSe.OnOff(true);
		}
		break;
	case 5://����Ⱦɫ
		if (1)
		{
			m_bUpdateTeam = true;
			g_pMainState->m_InterfaceRanSe.SetMode(1, m_pData->getIDinTeam());
			g_pMainState->m_InterfaceRanSe.OnOff(true);
		}
		break;
	case 6://װ��Ⱦɫ
		if (1)
		{
			m_bUpdateTeam = true;
			g_pMainState->m_InterfaceRanSe.SetMode(2, m_pData->getIDinTeam());
			g_pMainState->m_InterfaceRanSe.OnOff(true);
		}
		break;
	case 7://�ٻ���Ⱦɫ
		if (1)
		{
			m_bUpdateTeam = false;
			g_pMainState->m_InterfaceRanSe.SetMode(3, m_pData->getIDinTeam());
			g_pMainState->m_InterfaceRanSe.OnOff(true);
		}
		break;
	case 8://��ɫǿ��
		if (1)
		{
			m_bUpdateTeam = false;
			g_pMainState->m_InterfaceJianDing.SetMode(4);
			g_pMainState->m_InterfaceJianDing.OnOff(true);
			return true;
			g_pMainState->m_ChaKan.Set(*m_pData);
			g_pMainState->m_ChaKan.OnOff(true);
			g_pMainState->m_SelectFriendItem.SetMode(m_pData, cInterSelectFriendItem::eQH����);
			for (int i = 0; i < 20; i++)
			{
				g_pMainState->m_SelectFriendItem.Set(-1, i, g_pMainState->m_SkillManager.GetPetSkill(i)->m_BigHead);
			}
			g_pMainState->m_SelectFriendItem.OnOff(true);

		}
		break;
	case 9://��ս
		if (1)
		{
			m_bUpdateTeam = false;
			//			g_pMainState->m_SelectFriendItem.SetMode(m_pData, cInterSelectFriendItem::eQH��ս);
			//			g_pMainState->m_SelectFriendItem.OnOff(true);
			if (m_pData && m_pData->getIDinTeam() >= 0)
			{
				cPropertyData *petdata = nullptr;
				g_pMainState->m_FightWorkList[m_pData->getIDinTeam()].m_pObj->GetPropertyData(petdata);
				if (petdata)
				{
// 					int &grow = petdata->m_ZiZhi.grow;
// 					const vector<int> &puts = cct::get()->putMenpaiSkills;
// 					if (grow > puts.size())
// 					{
// 						grow = puts.size();
// 					}
// 					else if (grow == puts.size())
// 					{
// 						grow = 0;
// 					}
// 					else
// 					{
// 						++grow;
// 					}
// 					if (grow < puts.size())
// 					{
// 						petdata->m_AiLv = true;
// 						m_Text[9].SetString(g_pMainState->m_SkillManager.GetMengPaiSkill(puts[grow])->m_Name);
// 					}
// 					else
// 					{
// 						petdata->m_AiLv = false;
// 						m_Text[9].SetString("��׷��");
// 					}
				}
			}
		}
		break;
	case 10://BBǿ��
		if (1)
		{
			m_bUpdateTeam = false;
			//			g_pMainState->m_Tags.Add("���û�б�ʹ��,������������Ҫ��ʲô�ټ���....");

			if (m_pData && m_pData->getIDinTeam() >= 0)
			{
// 				cPropertyData *petdata = nullptr;
// 				g_pMainState->m_FightWorkList[m_pData->getIDinTeam()].m_pObj->GetPropertyData(petdata);
// 				if (petdata)
// 				{
// 					const vector<int> &puts = cct::get()->putPetSkills;
// 					int skillIndex = 0;
// 					if (petdata->m_NumofBBSkill > 0)
// 					{
// 						for (int i = petdata->m_NumofBBSkill - 1; i > 0; --i)
// 						{
// 							g_pMainState->m_SkillManager.SetPetSkill1(petdata, petdata->m_petSkills[i]->m_Id, -1);
// 						}
// 						petdata->m_NumofBBSkill = 1;
// 
// 						sSkill *skill = petdata->m_petSkills[0];
// 						int index = -1;
// 						forv(puts, i)
// 						{
// 							if (puts[i] == skill->m_Id)
// 							{
// 								index = i;
// 								break;
// 							}
// 						}
// 						if (index >= 0)
// 						{
// 							if (index == puts.size() - 1)
// 							{
// 								index = 0;
// 							}
// 							else
// 							{
// 								++index;
// 							}
// 							skillIndex = index;
// 						}
// 					}
// 					g_pMainState->m_SkillManager.SetPetSkill(petdata, puts[skillIndex], 0);
// 					string name = petdata->m_petSkills[0]->m_Name;
// 					if (name.size() > 8 && name.substr(0, 4) == "�߼�")
// 					{
// 						name = name.substr(4, name.length() - 4);
// 					}
// 					m_Text[10].SetString(name);
//				}
			}



			/*if (m_pData->m_FightBB == -1)
			{
			g_pMainState->m_Tags.Add("�ö���ǰû�г�ս���ٻ���");
			return true;
			}
			g_pMainState->m_ChaKan.Set(m_pData->m_BBList[m_pData->m_FightBB]);
			g_pMainState->m_ChaKan.OnOff(true);
			g_pMainState->m_SelectFriendItem.SetMode(m_pData, cInterSelectFriendItem::eQH����2);
			for (int i = 0; i < 20; i++)
			{
			g_pMainState->m_SelectFriendItem.Set(-1, i, g_pMainState->m_SkillManager.GetPetSkill(i)->m_BigHead);
			}
			g_pMainState->m_SelectFriendItem.OnOff(true);*/
		}
		break;
	case 11://����
		if (1)
		{
			m_bUpdateTeam = false;
			g_pMainState->m_SelectFriendItem.SetMode(m_pData, cInterSelectFriendItem::eQH����);
			g_pMainState->m_SelectFriendItem.OnOff(true);
		}
		break;
	case 106://�ƶ�
		if (1)
		{
			m_Sleeptime = 0;
			g_pMainState->Mouse.UnSetLock(MOUSE_LBUTTON);
			int xDel = g_xMouse - m_Prex;
			int yDel = g_yMouse - m_Prey;
			m_Prex = g_xMouse;
			m_Prey = g_yMouse;
			if (xDel != 0 || yDel != 0)
			{
				Move(m_xPos + xDel, m_yPos + yDel);
			}
		}
		return true;
	case 107://׼���ƶ�
		g_pMainState->Mouse.UnSetLock(MOUSE_LBUTTON);
		m_Prex = g_xMouse;
		m_Prey = g_yMouse;
		m_bMoveMode = true;
		return true;
	case 100:
		m_framprep->SetFrame֡(1);
		OnOff(false);
		break;
	}
	return true;
}

void cInterfaceFriendQiangHua::OnOff(bool NeedShow)
{
	g_pMainState->InterfaceSetShow(this, NeedShow);
	if (NeedShow)
	{
		Init();
		m_Cancel.SetFrame֡(0);
		m_bUpdateTeam = false;

		m_Text[9].SetString("");
		m_Text[10].SetString("");
		if (m_pData && m_pData->getIDinTeam() >= 0)
		{
			cPropertyData *petdata = nullptr;
			g_pMainState->m_FightWorkList[m_pData->getIDinTeam()].m_pObj->GetPropertyData(petdata);
			if (petdata)
			{
// 				int &grow = petdata->m_ZiZhi.grow;
// 				const vector<int> &puts = cct::get()->putMenpaiSkills;
// 				if (grow < puts.size())
// 				{
// 					m_Text[9].SetString(g_pMainState->m_SkillManager.GetMengPaiSkill(puts[grow])->m_Name);
// 				}

				if (petdata->m_NumofBBSkill > 0)
				{
					string name = petdata->m_petSkills[0]->m_Name;
					if (name.size() > 8 && name.substr(0, 4) == "�߼�")
					{
						name = name.substr(4, name.length() - 4);
					}
					m_Text[10].SetString(name);
				}
			}
		}
	}
	else
	{
		if (m_bUpdateTeam)
			g_pMainState->m_InterfaceTeam.UpDate();
		m_Mode = 0;
	}
	g_pMainState->m_Canvas.SetRedraw(m_Back.m_PreShowRect);
}

void cInterfaceFriendQiangHua::Set(sFriendList& list)
{
	m_pData = &list;
	Update();
}

bool cInterfaceFriendQiangHua::Show(cCanvas* pCanvas)
{
	pCanvas->Add(&m_Back, 1, 1);
	pCanvas->Add(&m_Cancel, 1);
	pCanvas->Add(&m_title);
	pCanvas->Add(&m_Name);
	//pCanvas->Add(&m_Money);
	for (int i = 0; i < 12; i++)
	{
		pCanvas->Add(&m_Buttonp[i], 1);
		pCanvas->Add(&m_Text[i]);
	}
	return true;
}

bool cInterfaceFriendQiangHua::CheckRB()
{
	if (!g_pMainState->Mouse.GetButtonState(MOUSE_RBUTTON))return false;
	g_pMainState->Mouse.SetLock(MOUSE_RBUTTON);
	switch (m_Select)
	{
	case 0:
		OnOff(false);
		break;
	case 1:
		break;
	default:
		break;
	}

	return true;
}

void cInterfaceFriendQiangHua::Update()
{
	m_Name.SetString(m_pData->m_Name);
	/*ostringstream oss;
	oss << "�ֽ�:";
	oss << m_pData->m_money;
	m_Money.SetString(oss.str());*/
	Move(m_xPos, m_yPos);
}

