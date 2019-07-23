#include "_global.h"


bool cInterfaceXiuLian::Init()
{
	if (m_bInit)return true;
	m_bInit = true;
	for (int i = 0; i < 2; i++)
	{
		m_SkillSelectBack[i].Load(0xF151309F);
		m_SkillSelectBack[i].SetStatic(true);
		m_SkillSelectBack[i].SetFrame(1);
		m_SkillSelectBack[i].SetxOffset(5);
		m_SkillSelectBack[i].m_NeedShow = false;
	}

//	m_MiaoShu.SetString("����30000��,5��ﹱ");
	m_MiaoShu.SetColor(RGB(255, 255, 255));
	m_Back.Load(0xDD1E6B63);
	m_Cancel.Set(&g_pMainState->m_Cancel);
	m_Cancel.m_bStatic = true;
	m_Button[0].Load(0x35A981D3);
	m_Button[1].Load(0x2BD1DEF7);
	for (int i = 0; i < 2; i++)
	{
		m_Button[i].SetStatic(true);
		m_tButton[i].SetColor(RGB(255, 255, 255));
	}
	m_tButton[0].SetString("*50");
	m_tButton[1].SetString("*500");

	Move(g_half320 - m_Back.GetWidth() / 2, g_half240 - m_Back.GetHeight() / 2);
	return true;
}

bool cInterfaceXiuLian::Move(int x, int y)
{
	m_xPos = x;
	m_yPos = y;
	m_Back.SetXY(x, y);
	m_Cancel.SetXY(x + m_Back.GetWidth() - 20, y + 3);
	m_Rect.left = m_xPos + 18;
	m_Rect.top = m_yPos + 60;
	m_Rect.right = m_Rect.left + 175;
	m_Rect.bottom = m_Rect.top + 92;
	for (int i = 0; i < 4; i++)
	{
		m_TXiuLian[i].SetXY(m_Rect.left, m_Rect.top + 5 + i * 23);
	}
	m_Button[0].SetXY(m_xPos + m_Back.GetWidth() / 3 - m_Button[0].GetWidth() / 2,
		m_yPos + 165);
	m_Button[1].SetXY(m_xPos + (m_Back.GetWidth() * 2) / 3 - m_Button[1].GetWidth() / 2,
		m_yPos + 165);
	for (int i = 0; i < 2; i++)
	{
		m_tButton[i].SetXCenter(m_Button[i].GetCenter());
		m_tButton[i].SetY(m_Button[i].GetY() + 3);
		m_tButton[i].UpdateXCenter();
	}

	m_MiaoShu.SetXY(x + 75, y + 3);
	return true;
}

void cInterfaceXiuLian::UpDate()
{
// 	auto& xl = g_pCharacter->m_PcData.m_XiuLian;
// 	xl.GetAtk() = max(xl.GetAtk(), xl.GetMag());
// 	xl.GetAtkExp() = max(xl.GetAtkExp(), xl.GetMagExp());
// 	xl.GetMag() = xl.GetAtk();
// 	xl.GetMagExp() = xl.GetAtkExp();
// 	xl.GetDef() = max(xl.GetDef(), xl.GetDMag());
// 	xl.GetDefExp() = max(xl.GetDefExp(), xl.GetDMagExp());
// 	xl.GetDMag() = xl.GetDef();
// 	xl.GetDMagExp() = xl.GetDefExp();
// 
// 	auto& xl2 = g_pCharacter->m_PcData.m_XiuLianBB;
// 	xl2.GetAtk() = max(xl2.GetAtk(), xl2.GetMag());
// 	xl2.GetAtkExp() = max(xl2.GetAtkExp(), xl2.GetMagExp());
// 	xl2.GetMag() = xl2.GetAtk();
// 	xl2.GetMagExp() = xl2.GetAtkExp();
// 	xl2.GetDef() = max(xl2.GetDef(), xl2.GetDMag());
// 	xl2.GetDefExp() = max(xl2.GetDefExp(), xl2.GetDMagExp());
// 	xl2.GetDMag() = xl2.GetDef();
// 	xl2.GetDMagExp() = xl2.GetDefExp();
// 	ostringstream oss;
// 	oss.str("");
// 	oss << "���� " << xl.GetAtk() << " " << xl.GetAtkExp() << "/" << GetXiuLIanExp(xl.GetAtk() + 1);
// 	m_TXiuLian[0].SetString(oss.str());
// 
// 	oss.str("");
// 	oss << "���� " << xl.GetDef() << " " << xl.GetDefExp() << "/" << GetXiuLIanExp(xl.GetDef() + 1);
// 	m_TXiuLian[1].SetString(oss.str());
// 
// 	oss.str("");
// 	oss << "BB�� " << xl2.GetAtk() << " " << xl2.GetAtkExp() << "/" << GetXiuLIanExp(xl2.GetAtk() + 1);
// 	m_TXiuLian[2].SetString(oss.str());
// 
// 	oss.str("");
// 	oss << "BB�� " << xl2.GetDef() << " " << xl2.GetDefExp() << "/" << GetXiuLIanExp(xl2.GetDef() + 1);
// 	m_TXiuLian[3].SetString(oss.str());
// 	return;

// 	int lv = g_pCharacter->m_PcData.m_Lv - 20;
// 	if (lv < 0)lv = 0;
// 	lv /= 5;//��ǰ�ȼ�����������ȼ�

	sBBXiuLian& liulian = _isBB ? g_pCharacter->m_PcData.m_XiuLianBB : g_pCharacter->m_PcData.m_XiuLian;

	string bb = /*_isBB ? "BB" : */"";
	ostringstream oss;
	oss.str("");
	oss << bb << "���� " << liulian.GetAtk() << /*"/" << lv <<*/ " ";
	oss << " " << liulian.GetAtkExp() << "/" << GetXiuLIanExp(liulian.GetAtk() + 1);
	m_TXiuLian[0].SetString(oss.str());
	oss.str(_isBB ? "BB" : "");
	oss << bb << "���� " << liulian.GetDef() << /*"/" << lv <<*/ " ";
	oss << " " << liulian.GetDefExp() << "/" << GetXiuLIanExp(liulian.GetDef() + 1);
	m_TXiuLian[1].SetString(oss.str());
	oss.str(_isBB ? "BB" : "");
	oss << bb << "���� " << liulian.GetMag() << /*"/" << lv <<*/ " ";
	oss << " " << liulian.GetMagExp() << "/" << GetXiuLIanExp(liulian.GetMag() + 1);
	m_TXiuLian[2].SetString(oss.str());
	oss.str(_isBB ? "BB" : "");
	oss << bb << "���� " << liulian.GetDMag() << /*"/" << lv <<*/ " ";
	oss << " " << liulian.GetDMagExp() << "/" << GetXiuLIanExp(liulian.GetDMag() + 1);
	m_TXiuLian[3].SetString(oss.str());


}

bool cInterfaceXiuLian::Show(cCanvas* pCanvas)
{
	pCanvas->Add(&m_Back, 1, 1);
	pCanvas->Add(&m_Cancel, 1);

	if (m_SkillSelectBack[0].m_NeedShow)
		for (int i = 0; i < 2; i++)
		{
		pCanvas->Add(&m_SkillSelectBack[i], 1);
		}
	for (int i = 0; i < 4; i++)
	{
		pCanvas->Add(&m_TXiuLian[i]);
	}
	for (int i = 0; i < 2; i++)
	{
		pCanvas->Add(&m_Button[i], 1);
		pCanvas->Add(&m_tButton[i]);
	}
	pCanvas->Add(&m_MiaoShu);
	return true;
}

bool cInterfaceXiuLian::ProcessInput()
{
	if (m_Sleeptime > 0)
	{
		g_pMainState->SetMouseOnMap(false);
		m_Sleeptime -= 1;
		return true;
	}
	ResetButton();
	m_Select = -1;
	g_pMainState->SetMouseOnMap(false);
	if (m_bMoveMode)//�ƶ�
	{
		m_Select = 6;
		g_pMainState->SetMouseOnMap(false);
		if (!CheckL())m_bMoveMode = false;
		return true;
	}
	if (!isOn(g_xMouse, g_yMouse, m_Back.m_PreShowRect))return true;
	if (isOn(g_xMouse, g_yMouse, m_Rect))
	{
		m_Select = (g_yMouse - m_Rect.top - 1) / 23;
		m_SkillSelectBack[0].SetXY(m_Rect.left, m_Rect.top + m_Select * 23);
		m_SkillSelectBack[1].SetXY(m_Rect.left + 85, m_Rect.top + m_Select * 23);
		m_SkillSelectBack[0].m_NeedShow = true;
		m_SkillSelectBack[1].m_NeedShow = true;
		m_Select += 10;
		if (CheckL())return true;
	}
	else
	{
		m_SkillSelectBack[0].m_NeedShow = false;
		m_SkillSelectBack[1].m_NeedShow = false;
	}
	for (int i = 0; i < 2; i++)
		if (CheckOn(&m_Button[i], i + 1))return true;
	if (CheckOn(&m_Cancel, 0))return true;
	//׼���ƶ�
	m_Select = 7;
	if (CheckL())return true;
	m_Select = 0;
	if (CheckRB())return true;
	return true;
}

bool cInterfaceXiuLian::CheckL()
{
	if (!g_pMainState->Mouse.GetButtonState(MOUSE_LBUTTON))return false;
	g_pMainState->Mouse.SetLock(MOUSE_LBUTTON);
	m_Sleeptime = 3;
	switch (m_Select)
	{
	case 0:
		OnOff(false);
		break;
	case 1:
		m_Sleeptime = 0;
		if (!Leveupskill(5))return true;
		UpDate();
		break;
	case 2:
		m_Sleeptime = 0;
		if (!Leveupskill(50))return true;
		UpDate();
		break;
	case 6://�ƶ�
		if (1)
		{
			g_pMainState->Mouse.UnSetLock(MOUSE_LBUTTON);
			int xDel = g_xMouse - m_Prex;
			int yDel = g_yMouse - m_Prey;
			m_Prex = g_xMouse;
			m_Prey = g_yMouse;
			if (xDel != 0 || yDel != 0)
			{
				Move(m_xPos + xDel, m_yPos + yDel);
			}
			m_Sleeptime = 0;
		}
		return true;
	case 7://׼���ƶ�
		g_pMainState->Mouse.UnSetLock(MOUSE_LBUTTON);
		m_Prex = g_xMouse;
		m_Prey = g_yMouse;
		m_bMoveMode = true;
		return true;
	default:
		if (m_SkillSelect>-1)
			m_TXiuLian[m_SkillSelect].SetColor(0);
		m_SkillSelect = m_Select - 10;
		m_TXiuLian[m_SkillSelect].SetColor(RGB(255, 0, 0));
		break;
	}


	return true;
}

bool cInterfaceXiuLian::Leveupskill(int lvup)
{
	if (m_SkillSelect < 0)return false;
	//���Ѱﹱ�ͽ�Ǯ
	INT64 oldmoney[3];//, oldbanggong;
	for (int i = 0; i < 3; i++)
		oldmoney[i] = g_pCharacter->m_PcData.m_Money[i];
	//oldbanggong = g_pCharacter->m_PCData.m_BangPaiPoint;
	/*if (!g_pCharacter->m_PCData.CostBangGong(5 * lvup))
	{
	g_pCharacter->m_PCData.m_BangPaiPoint = oldbanggong;
	g_pMainState->m_Tags.Add("�ﹱ����");
	return false;
	}*/

	if (!g_pCharacter->m_PcData.AddMoney(-20000 * lvup, 0, 0, false))
	{
		//g_pCharacter->m_PCData.m_BangPaiPoint = oldbanggong;

		int bsuc1 = 0;
	//	int bsuc2 = 0;
		if (m_SkillSelect < 4)
		{
			int xlv = cct::getCurrMaxXiulianLv(g_pCharacter->m_PcData.m_Lv);
			auto& xl = g_pCharacter->m_PcData.m_XiuLian;
			auto& xl2 = g_pCharacter->m_PcData.m_XiuLianBB;
			if (!_isBB/* m_SkillSelect < 2*/)
			{
				eXiuLian e = (eXiuLian)m_SkillSelect;
			//	eXiuLian e2 = (eXiuLian)(m_SkillSelect + 2);
				bsuc1 = xl.AddExp(xlv, 0, e);
			//	bsuc2 = xl.AddExp(xlv, 0, e2);
			}
			else
			{
				eXiuLian e = (eXiuLian)(m_SkillSelect/* - 2*/);
			//	eXiuLian e2 = (eXiuLian)(m_SkillSelect);
				bsuc1 = xl2.AddExp(xlv, 0, e);
			//	bsuc2 = xl2.AddExp(xlv, 0, e2);
			}
		}
		 if (2 == bsuc1/* || bsuc2 == 2*/)
		{
			g_pMainState->m_Tags.Add("�����ȼ�����");
		}
		return true;

		g_pMainState->m_Tags.Add("�̲�����");
		return false;
	}

	int bsuc1 = 0;
//	int bsuc2 = 0;
	if (m_SkillSelect < 4)
	{
		int xlv = cct::getCurrMaxXiulianLv(g_pCharacter->m_PcData.m_Lv);
		auto& xl = g_pCharacter->m_PcData.m_XiuLian;
		auto& xl2 = g_pCharacter->m_PcData.m_XiuLianBB;
		if (!_isBB/* m_SkillSelect < 2*/)
		{

			eXiuLian e = (eXiuLian)m_SkillSelect;
//			eXiuLian e2 = (eXiuLian)(m_SkillSelect + 2);
			bsuc1 = xl.AddExp(xlv, lvup * 10, e);
//			bsuc2 = xl.AddExp(xlv, lvup * 10, e2);
		}
		else
		{
			eXiuLian e = (eXiuLian)(m_SkillSelect/* - 2*/);
//			eXiuLian e2 = (eXiuLian)(m_SkillSelect);
			bsuc1 = xl2.AddExp(xlv, lvup * 10, e);
//			bsuc2 = xl2.AddExp(xlv, lvup * 10, e2);
		}
	}
	else if (m_SkillSelect < 8)
	{
		//		bsuccess = g_pCharacter->m_PCData.m_BBXiuLian.AddExp(g_pCharacter->m_PcData.m_Lv , lvup * 10, (eXiuLian)(m_SkillSelect - 4));
	}
	if (0 == bsuc1/* && bsuc2 == 0*/)
	{
		//�����Ѵ�����
		g_pMainState->m_Tags.Add("��������");
		//	g_pCharacter->m_PCData.m_BangPaiPoint = oldbanggong;
		for (int i = 0; i < 3; i++)
		{
			g_pCharacter->m_PcData.m_Money[i] = oldmoney[i];
		}
	}
	else if (2 == bsuc1/* || bsuc2 == 2*/)
	{
		g_pMainState->m_Tags.Add("�����ȼ�����");

// 		string text = "���";
// 		if (_isBB)
// 		{
// 			switch (m_SkillSelect)
// 			{
// 			case 0:text += "BB����"; break;
// 			case 1:text += "BB����"; break;
// 			case 2:text += "BB����"; break;
// 			case 3:text += "BB����"; break;
// 			}
// 		}
// 		else
// 		{
// 			switch (m_SkillSelect)
// 			{
// 			case 0:text += "����"; break;
// 			case 1:text += "����"; break;
// 			case 2:text += "����"; break;
// 			case 3:text += "����"; break;
// 			}
// 		}
// 		text += "�����ȼ�������!";
// 		g_pMainState->m_Tags.Add(text);
	}
	return true;
}

bool cInterfaceXiuLian::CheckRB()
{
	if (!g_pMainState->Mouse.GetButtonState(MOUSE_RBUTTON))return false;
	g_pMainState->Mouse.SetLock(MOUSE_RBUTTON);
	switch (m_Select)
	{
	case 0:
		OnOff(false);
		break;
	default:
		break;
	}
	return true;
}

void cInterfaceXiuLian::OnOff(bool NeedShow)
{
	g_pMainState->InterfaceSetShow(this, NeedShow);
	g_pMainState->m_Canvas.SetRedraw(m_Back.m_PreShowRect);
	m_NeedShow = NeedShow;
	if (m_NeedShow)
	{
		m_MiaoShu.SetString(_isBB ? "�ٻ�������" : "��������");
		UpDate();
		if (m_SkillSelect > -1)
		{
			m_TXiuLian[m_SkillSelect].SetColor(0);
		}
		m_SkillSelect = -1;
	}
	else
	{
		cct::autoSave();
	}
	return;
}

