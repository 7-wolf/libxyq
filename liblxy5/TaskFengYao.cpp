#include "_global.h"

static vector<cTaskFengYao::sFy> s_fys = 
{
	{ 20, "������" },
	{ 30, "����Ұ��" },
	{ 40, "���ƹ���" },
	{ 50, "���ƾ���" },
	{ 60, "���ٽ���" },
	{ 60, "������" },
	{ 80, "���Ϲ�" },
	{ 80, "����«��" },
	{ 100, "����ɽ" },
	{ 120, "�����ɵ�" },
	{ 130, "����ɽ" },
	{ 160, "������" },
	{ 160, "�����" },
};

static int getIdx()
{
	string str = g_pMainState->m_Map.m_MapName;
	forr (s_fys, i)
	{
		if (str == s_fys[i].mapname)
		{
			return i;
		}
	}
	return -1;
}


void cTaskFengYao::Init()
{
	if (m_bInit)
	{
		return;
	}
	m_bInit = true;
	_fys = s_fys;
}


bool cTaskFengYao::Process(int stage)
{
	_next = stage + 1;

	switch (stage)
	{
	case -1: break;
	case 0:
	{
		int idx = getIdx();
		if (idx < 0)
		{
			break;
		}
		sFy fy = _fys[idx];
	//	_fys.erase(_fys.begin() + idx);
		sNpc npc;
		int m, x, y;
		for (int k = (24 + rand() % 8); k >= 0; --k)
		{
			m = cct::getPetModel(fy.lv - 15, fy.lv + 5);
			g_pMainState->m_Map.AutoGetPos(x, y, fy.mapname);
			npc.Set("Զ������", fy.mapname, m, x, y);
			AddTriggerObjMap(&npc, _next);
		}
	}
		break;
	case 1:
	{
		cObj* obj = g_pMainState->m_pNowSelect;
		_selectModeid = obj->GetModeID();
		_selectX = obj->GetX();
		_selectY = obj->GetY();
		g_pMainState->m_pNowSelect->Talk("��ɶ��#4", this, _next, " ", "����զ��!", "�Ҵ���");
	}
		break;
	case 2:
		if (g_pMainState->m_Dialog.m_retSelect != 1)
		{
			break;
		}
	{
		int plv = s_fys[getIdx()].lv;
		int lv = plv; // max(plv, g_pMainState->getMaxLv());
		auto pc = AddEnemy(0, _selectModeid, lv, eMP_���);
		pc->m_Name = "Զ��" + pc->m_Name;
		pc->getObj()->m_TrueName.SetString(pc->m_Name);

		for (int i = 1, size = 5 + rand() % 5; i < size; ++i)
		{
			if (i < 5)
			{
				AddEnemy(0, cct::getPetModel(plv - 15, plv + 5), lv, eMP_���);
			}
			else
			{
				AddEnemy(0, cct::getPetModel(plv - 15, plv + 5), lv);
			}
		}

		readyFightAndSucces();
	}
	break;
	case 3:
	{
		int lv = s_fys[getIdx()].lv;
		g_pMainState->awardk(lv * 3 / 2, lv / 4);
		lv = min(110, lv);
		g_pMainState->award125(20, lv);
	}
		g_pMainState->m_Map.RemoveNpc(_selectX, _selectY, "Զ������", true);
		RemoveTriggerObjMap(_selectX, _selectY);
		break;
	default:
		break;
	}
	return true;
}

cTaskFengYao::cTaskFengYao()
{
	Init();
}







// 
// 
// 
// 	case 0:
// 
// 	{
// 		g_pMainState->m_Friend.JuanZeng(g_pMainState->m_YingHang.m_ShuRu.m_num);
// 	}
// 	break;
// 	case 1:
// 
// 	{
// 		g_pMainState->m_Friend.UnJuanZeng(g_pMainState->m_YingHang.m_ShuRu.m_num);
// 	}