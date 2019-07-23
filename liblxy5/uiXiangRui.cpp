#include "_global.h"
#include "_txt.h"


bool ui5B8B823E::initShow()
{
	_title->SetString(toString("��%dҳ", _page + 1));

	for (int k = 0; k < _row; ++k)
	{
		for (int i = 0; i < _cel; ++i)
		{
			int x = k * _cel + i;
			int idx = _page * _row * _cel + k * _cel + i;
			_objs[x]->m_NeedShow = false;
			onInitShow(x, idx, false);
			if (idx >= _size)
			{
				continue;
			}
			onInitShow(x, idx, true);
			_objs[x]->m_NeedShow = true;
		}
	}

	return true;
}


bool ui5B8B823E::init(int cel, int row, int size)
{
	if (!cInterfaceFather::Init())
	{
		return false;
	}
	_cel = cel;
	_row = row;
	_size = size;
	loadBack(/*0xB0025203*/0x5B8B823E);

	sChild tTitle("5B8B823E", 255, 12);
	addChild(tTitle);
	_title = (cText*)tTitle.ptr;

	_objs.resize(row * cel);
	for (int k = 0; k < row; ++k)
	{
		for (int i = 0; i < cel; ++i)
		{
			addChild(initBtn(k, i));
			addChild(initWas(k, i));
		}
	}


	sChild btn(&g_pMainState->m_Button2, "��ҳ", 100, 25);
	btn.onClick = [&](const sChild* c)
	{
		if (_page > 0)
		{
			--_page;
			initShow();
		}

	};
	addChild(btn);

	sChild btn2(&g_pMainState->m_Button2, "��ҳ", 410, 25);
	btn2.onClick = [&](const sChild* c)
	{
		if ((_page + 1) * _cel * _row < _size)
		{
			++_page;
			initShow();
		}

	};
	addChild(btn2);

	Move(125, 65);
	return true;
}

cInterfaceFather::sChild ui5B8B823E::initBtn(int k, int i)
{
	return cInterfaceFather::sChild(&g_pMainState->m_Button2, "ѡ��", 0, 0);
}

cInterfaceFather::sChild ui5B8B823E::initWas(int k, int i)
{
	return cInterfaceFather::sChild(g_pMainState->m_Button4.m_NowID, 0, 0);
}



//////////////////////////////////////////////////////////////////////////
bool uiXiangRui::Init()
{
	if (!ui5B8B823E::Init())
	{
		return false;
	}
	return ui5B8B823E::init(3, 2, g_pMainState->m_ZuoQi.m_ZuoQi.size() - 8);

}

void uiXiangRui::onInitShow(int tag, int idx, bool isShow)
{
	if (!isShow)
	{
		_obj2s[tag]->m_NeedShow = false;
		return;
	}

	vector<ulong> out;
	sZuoQi2 zq;
	zq.m_pZuoQi = (sZuoQi*)&g_pMainState->m_ZuoQi.m_ZuoQi[idx + 8];
	zq.GetID(POS_STAND, out, false);
	_objs[tag]->Load(out[0]);
	if (out.size() > 1)
	{
		_obj2s[tag]->Load(out[1]);
		if (_obj2s[tag]->m_isStatic)
		{
			_obj2s[tag]->SetStatic(false);
		}
		_obj2s[tag]->m_NeedShow = true;
	}
}


cInterfaceFather::sChild uiXiangRui::initBtn(int k, int i)
{
	sChild btn = ui5B8B823E::initBtn(k, i);
	btn.xx = i * 180 + 60;
	btn.yy = (k + 1) * 180 + 10;
	btn.tag = k * _cel + i;
	btn.onClick = [&](const sChild* c)
	{
		int x = _page * _cel * _row + c->tag;
		if (x < _size)
		{
			g_pMainState->m_ZuoQi.GetZuoQi(g_pMainState->m_HeroID, x + 8);
			g_pCharacter->m_PcData.m_bOnZuoQi = true;
			g_pMainState->m_Tags.Add("��ѡ��������");
		}
	};
	return btn;
}


cInterfaceFather::sChild uiXiangRui::initWas(int k, int i)
{
	sChild btn2 = ui5B8B823E::initWas(k, i);
	btn2.xx = i * 180 + 80;
	btn2.yy = (k + 1) * 180 - 10;
//	sChild btn2(g_pMainState->m_Button4.m_NowID, i * 200 + 50, (k + 1) * 180 - 10);
	btn2.checkon = false;
//	addChild(btn2);

	if (_obj2s.empty())
	{
		_obj2s.resize(_cel * _row);
	}
	_obj2s[k * _cel + i] = (cWasFile*)btn2.ptr;
	
	sChild btn3 = ui5B8B823E::initWas(k, i);
	btn3.xx = btn2.xx;
	btn3.yy = btn2.yy;
	btn3.checkon = btn2.checkon;
	_objs[k * _cel + i] = (cWasFile*)btn3.ptr;
	addChild(btn3);
	_objs[k * _cel + i]->SetStatic(false);
	return btn2;
}




//////////////////////////////////////////////////////////////////////////
bool uiHeadTop::Init()
{
	if (!ui5B8B823E::Init())
	{
		return false;
	}
	return ui5B8B823E::init(6, 3, ctt::getHeadTops().size());
}

void uiHeadTop::onInitShow(int tag, int idx, bool isShow)
{
	if (isShow)
	{
		_objs[tag]->Load(ctt::getHeadTops()[idx].uid);
		if (_objs[tag]->m_isStatic)
		{
			_objs[tag]->SetStatic(false);
		}
	}
}


cInterfaceFather::sChild uiHeadTop::initBtn(int k, int i)
{
	sChild btn = ui5B8B823E::initBtn(k, i);
	btn.xx = i * 85 + 30;
	btn.yy = (k + 1) * 125 + 25;
	btn.tag = k * _cel + i;
	btn.onClick = [&](const sChild* c)
	{
		int x = _page * _cel * _row + c->tag;
		if (x < _size)
		{
			const auto& h = ctt::getHeadTops()[x];
			g_pMainState->_wasHeadTop.Load(h.uid);
			g_pMainState->_wasHeadTop.m_PosType = 2;
			g_pMainState->_wasHeadHigh = h.isMid ? (g_pMainState->_wasHeadTop.GetHeight() / 2) : 0;
			g_pMainState->m_Tags.Add("��ѡ���˶ӳ�����");
		}
	};
	return btn;
}


cInterfaceFather::sChild uiHeadTop::initWas(int k, int i)
{
	sChild btn2 = ui5B8B823E::initWas(k, i);
	btn2.xx = i * 85 + 50;
	btn2.yy = (k + 1) * 125 - 10;
	btn2.checkon = false;
	_objs[k * _cel + i] = (cWasFile*)btn2.ptr;
	return btn2;
}




//////////////////////////////////////////////////////////////////////////
bool uiFoot::Init()
{
	if (!ui5B8B823E::Init())
	{
		return false;
	}
	return ui5B8B823E::init(4, 3, ctt::getFoots().size());
}

void uiFoot::onInitShow(int tag, int idx, bool isShow)
{
	if (isShow)
	{
		_objs[tag]->Load(ctt::getFoots()[idx]);
		if (_objs[tag]->m_isStatic)
		{
			_objs[tag]->SetStatic(false);
		}
	}
}


cInterfaceFather::sChild uiFoot::initBtn(int k, int i)
{
	sChild btn = ui5B8B823E::initBtn(k, i);
	btn.xx = i * 135 + 50;
	btn.yy = (k + 1) * 125 + 30;
	btn.tag = k * _cel + i;
	btn.onClick = [&](const sChild* c)
	{
		int x = _page * _cel * _row + c->tag;
		if (x < _size)
		{
			g_pHeroObj->m_Foot.Load(ctt::getFoots()[x]);
			g_pHeroObj->m_Foot.m_Picture.m_FrameGap = 2;
			g_pMainState->m_Tags.Add("��ѡ����վ���㼣");
			cct::autoSave();
		}
	};
	return btn;
}


cInterfaceFather::sChild uiFoot::initWas(int k, int i)
{
	sChild btn2 = ui5B8B823E::initWas(k, i);
	btn2.xx = i * 135 + 70;
	btn2.yy = (k + 1) * 125 - 15;
	btn2.checkon = false;
	_objs[k * _cel + i] = (cWasFile*)btn2.ptr;
	return btn2;
}



//////////////////////////////////////////////////////////////////////////
bool uiFoot2::Init()
{
	if (!ui5B8B823E::Init())
	{
		return false;
	}

	return ui5B8B823E::init(4, 3, ctt::getFoot2s().size());
}

void uiFoot2::onInitShow(int tag, int idx, bool isShow)
{
	if (isShow)
	{
		_objs[tag]->Load(ctt::getFoot2s()[idx]);
		if (_objs[tag]->m_isStatic)
		{
			_objs[tag]->SetStatic(false);
		}
	}
}


cInterfaceFather::sChild uiFoot2::initBtn(int k, int i)
{
	sChild btn = ui5B8B823E::initBtn(k, i);
	btn.xx = i * 135 + 50;
	btn.yy = (k + 1) * 125 + 30;
	btn.tag = k * _cel + i;
	btn.onClick = [&](const sChild* c)
	{
		int x = _page * _cel * _row + c->tag;
		if (x < _size)
		{
//			g_pHeroObj->m_Foot.Load(ctt::getFoot2s()[x]);
			g_pMainState->m_Tags.Add("�����ڴ�");
		}
	};
	return btn;
}


cInterfaceFather::sChild uiFoot2::initWas(int k, int i)
{
	sChild btn2 = ui5B8B823E::initWas(k, i);
	btn2.xx = i * 135 + 40;
	btn2.yy = (k + 1) * 125 - 0;
	btn2.checkon = false;
	_objs[k * _cel + i] = (cWasFile*)btn2.ptr;
	return btn2;
}

//////////////////////////////////////////////////////////////////////////
static vector<ulong> s_anis;
void uiAnimalSign::onInitShow(int tag, int idx, bool isShow)
{
	if (isShow)
	{
		_objs[tag]->Load(s_anis[idx]);
		if (_objs[tag]->m_isStatic)
		{
			_objs[tag]->SetStatic(false);
		}
	}
}

bool uiAnimalSign::Init()
{
	if (!ui5B8B823E::Init())
	{
		return false;
	}
	if (s_anis.empty())
	{
		s_anis = { 49, 53, 67, 75, 117 };
		for (int i = 126; i <= 132; ++i)
		{
			s_anis.push_back(i);
		}
		forr(s_anis, i)
		{
			s_anis[i] = g_pMainState->m_pNpcList[s_anis[i]].m_stand;
		}
	}
	return ui5B8B823E::init(4, 3, s_anis.size());
}

cInterfaceFather::sChild uiAnimalSign::initBtn(int k, int i)
{
	sChild btn = ui5B8B823E::initBtn(k, i);
	btn.xx = i * 135 + 50;
	btn.yy = (k + 1) * 125 + 30;
	btn.tag = k * _cel + i;
	btn.onClick = [&](const sChild* c)
	{
		int x = _page * _cel * _row + c->tag;
		if (x < _size)
		{
			g_pMainState->m_Tags.Add("��ѡ���˱�����Ф");
		}
	};
	return btn;
}

cInterfaceFather::sChild uiAnimalSign::initWas(int k, int i)
{
	sChild btn2 = ui5B8B823E::initWas(k, i);
	btn2.xx = i * 135 + 70;
	btn2.yy = (k + 1) * 125 + 20;
	btn2.checkon = false;
	_objs[k * _cel + i] = (cWasFile*)btn2.ptr;
	return btn2;
}

//////////////////////////////////////////////////////////////////////////
void uiChangeCharacter::onInitShow(int tag, int idx, bool isShow)
{
	if (isShow)
	{
		_objs[tag]->Load(g_pMainState->m_pCharacterDataList[idx].m_Pos[0].m_stand);
		_tNames[tag]->SetString(g_pMainState->m_pCharacterDataList[idx].m_Name);
		if (_objs[tag]->m_isStatic)
		{
			_objs[tag]->SetStatic(false);
		}
	}
}

bool uiChangeCharacter::Init()
{
	if (!ui5B8B823E::Init())
	{
		return false;
	}
	return ui5B8B823E::init(3, 2, g_pMainState->m_pCharacterDataList.size());
}

cInterfaceFather::sChild uiChangeCharacter::initBtn(int k, int i)
{
	int x = k * _cel + i;
	sChild btn(&g_pMainState->m_Button4, " ", i * 180 + 50, (k + 1) * 175 + 20);
	btn.tag = x;
	btn.onClick = [&](const sChild* c)
	{
		int x = _page * _cel * _row + c->tag;
		if (x < _size)
		{
			ccm::get()->useCard(x);
			g_pMainState->m_Tags.Add("�������ͳɹ�");
			cct::autoSave();
		}
	};
	if (_tNames.empty())
	{
		_tNames.resize(_cel * _row);
	}
	_tNames[x] = (cText*)btn.ptr2;
	return btn;
}

cInterfaceFather::sChild uiChangeCharacter::initWas(int k, int i)
{
	sChild btn2 = ui5B8B823E::initWas(k, i);
	btn2.xx = i * 180 + 90;
	btn2.yy = (k + 1) * 175;
	btn2.checkon = false;
	_objs[k * _cel + i] = (cWasFile*)btn2.ptr;
	return btn2;
}



//////////////////////////////////////////////////////////////////////////
bool uiCangKu::Init()
{
	if (!cInterfaceFather::Init())
	{
		return false;
	}
	loadBack(0x56C592F9);
	m_Back.SetShowHeight(255);

	addChild(sChild("�ֿ�", 122, 2));
	addChild(sChild("����", 412, 2));

	_itemSelects[0].Init();
	_itemSelects[1].Init();
	_isRclose = false;


	Move(g_half320 - m_Back.GetWidth() / 2, g_half240 - m_Back.GetShowHeight() / 2);
	return true;
}

bool uiCangKu::Move(int x, int y)
{
	_itemSelects[0].Move(x + 12, y + 36);
	_itemSelects[1].Move(x + 300, y + 36);
	return cInterfaceFather::Move(x, y);
}

bool uiCangKu::ProcessInput()
{
	_itemSelects[0].Update(&_items[0]);
	_itemSelects[1].Update(&g_pCharacter->m_PcData.m_Items[0]);
	_itemSelects[0].Process(g_xMouse, g_yMouse);
	_itemSelects[1].Process(g_xMouse, g_yMouse);
	return cInterfaceFather::ProcessInput();
}

bool uiCangKu::CheckRB()
{
	int k = _itemSelects[0].Process(g_xMouse, g_yMouse);
	if (k >= 0 && k < 20 && _items[k].m_Num > 0)
	{
		if (g_pMainState->m_InterfaceItem.GetItem(g_pMainState->m_HeroID, &_items[k]))
		{
			_items[k].m_Num = 0;
		}
	}
	else
	{
		k = _itemSelects[1].Process(g_xMouse, g_yMouse);
		auto& its = g_pCharacter->m_PcData.m_Items;
		if (k >= 0 && k < 20 && its[k].GetNum() > 0)
		{
			int i = 0;
			for (; i < 20; ++i)
			{
				if (_items[i].GetNum() == 0)
				{
					break;
				}
			}
			if (i == 20)
			{
				g_pMainState->m_Tags.Add("�ֿ�����");
				return true;
			}
			_items[i] = its[k];
			its[k].m_Num = 0;
		}
	}
	return true;
}

bool uiCangKu::Show(cCanvas* pCanvas)
{
	cInterfaceFather::Show(pCanvas);
	_itemSelects[0].Show(pCanvas);
	_itemSelects[1].Show(pCanvas);
	return true;
}



////////////////////////////////////////////////////////////////////////// ˵����
static vector<string> s_descBtnNames = { "����", "��ҵϵͳ", "����NPC", "����", "����", "����", "�", "��ݼ�", "����", "˵����" };
bool uiDesc::Init()
{
	if (!cInterfaceFather::Init())
	{
		return false;
	}
	_size = s_descBtnNames.size();
	loadBack(0x5B8B823E);

	sChild tTitle("5B8B823E", 250, 12);
	addChild(tTitle);
	_title = (cText*)tTitle.ptr;

	sChild context(" ", 35, 55);
	addChild(context);
	_text = (cText*)context.ptr;

	for (int k = 0; k < 2; ++k)
	{
		for (int i = 0; i < 7; ++i)
		{
			int x = k * 7 + i;
			cInterfaceFather::sChild btn(&g_pMainState->m_Button4, x >= _size ? " " : s_descBtnNames[x], i * 74 + 12, k * 27 + 388);
			btn.tag = x;
			btn.onClick = [&](const sChild* c)
			{
				_page = c->tag;
				initShow();
			};
			addChild(btn);
		}
	}


	sChild btn(&g_pMainState->m_Button2, "��ҳ", 100, 25);
	btn.onClick = [&](const sChild* c)
	{
		if (_page > 0)
		{
			--_page;
			initShow();
		}

	};
	addChild(btn);

	sChild btn2(&g_pMainState->m_Button2, "��ҳ", 410, 25);
	btn2.onClick = [&](const sChild* c)
	{
		if ((_page + 1) < _size)
		{
			++_page;
			initShow();
		}

	};
	addChild(btn2);

	Move(125, 65);
	return true;
}


static vector<string> s_descTexts;

bool uiDesc::initShow()
{
	if (_page < 0 || _page >= _size)
	{
		return true;
	}
	_title->SetString(s_descBtnNames[_page]);

	if (s_descTexts.empty())
	{
		string str = "��Ϸ�ز�Դ������,��#R������#R,����#R����Ը�#R";
		s_descTexts.push_back(str);
		////////////////////////////////////////////////////////////////////////// ��ҵ
		str = "����FF:̯λר����";
		str += "\n���: ���� �����Ƶ�";
		str += "\n�޵���: ���з� ������ Ǭ����";
		str += "\n�����: �ھ�";
		str += "\n����: ���ʹ�";
		str += "\n����: ������";
		str += "\n�̻�: ҩƷ(�ݶ�)";
		str += "\n��������: ����ҩƷ";
		s_descTexts.push_back(str);
		////////////////////////////////////////////////////////////////////////// ����NPC
		str = "�Բ�ͷ (������)";
		str += "\n������ (���ٴ�)";
		s_descTexts.push_back(str);
		////////////////////////////////////////////////////////////////////////// ����
		str = "���Ҷ�Ӧ��NPC��������";
		str += "\n���˵Ĺ��        (������ �׺��� 30������)";
		str += "\n���ʵ����� ��ƪ   (���ٴ� �ϼ�����)";
		str += "\n���ʵ����� ��ƪ   (���ƹ��� Ϻ��)";
		str += "\n���ʵ����� ��ƪ   (���ƹ��� ���������� ����)";
		str += "\nѰ��������        (���ƾ��� ����ɽ�)";
		str += "\n��ԩС����        (�칬 ��������)";
		str += "\n����׹Ǿ�        (���ƾ��� ����Ԫ˧)";
		str += "\n���������        (����ɽ ������)";
		str += "\n��ȡ�Ž��� ��ƪ   (���ƾ��� ���Ի�)";
		s_descTexts.push_back(str);
		////////////////////////////////////////////////////////////////////////// ����
		str = " ";
		s_descTexts.push_back(str);
		////////////////////////////////////////////////////////////////////////// ����  �����ľͲ���д��
		str = " ";
// 		str += "\nʦ������";
// 		str += "\n��ظ׽��";
// 		str += "\n�ر�ͼ";
		s_descTexts.push_back(str);
		////////////////////////////////////////////////////////////////////////// �
		str = "��̨Ӱ����ս";
		str += "\n���ɾ���";
		str += "\nӢ�۴��";
		str += "\n���ɴ���";
//		str += "\n����";
		s_descTexts.push_back(str);
		////////////////////////////////////////////////////////////////////////// ��ݼ�
		str = "#Yƽʱ#Y:";
		str += "\nO �ٻ����������";
		str += "\nW �ӳ��������";
		str += "\n#Yս��#Y:";
		str += "\nA ��ͨ����";
		str += "\nW �����������";
		str += "\nQ ʹ�ñ��淨��(�ޱ��淨������ͨ����)";
		str += "\nS ʹ�ñ��淨��ѡ��Ŀ��";
		str += "\nX �����ؼ����";
		str += "\nV ����ָ�����";
		str += "\nE �����������";
		str += "\nD ����";
		str += "\nT ����";
		s_descTexts.push_back(str);
		////////////////////////////////////////////////////////////////////////// ����
		s_descTexts.push_back("����");
		////////////////////////////////////////////////////////////////////////// ˵��
		str = "";
		cc::setQ(str);
		str += " ��Ϸ����ֻ��Ⱥ�﷢��,����������;��,#Y������ð#Y��ƭ";
		str += "\n�ݲ�֧�ֱ���������";
	//	str += "\n֧�ָ����ӳ��Ͷ���λ��";
		str += "\n֧������������ɺ�����";
		str += "\n֧��װ�������Ա�����";
		str += "\n֧�ַ�ʯֱ���Ҽ�ʹ��";
	//	str += "\n֧��Ⱦɫ�����ɫ��";
	//	str += "\n֧��װ���ؼ���¯";
		s_descTexts.push_back(str);

	}
	if (_page >= s_descTexts.size())
	{
		_ftext.SetFaceText(" ", g_pMainState->m_hFont[0], 480);
		return true;
	}
	if (s_descTexts[_page] == "����")
	{
		string str = "\n";
		static int x = -1;
		for (int i = 0; i < 20; ++i)
		{
			if (++x > 119)
			{
				x = 0;
			}
			if (x >= 100)
			{
				str += toString("#Y%d#Y#%d     ", x, x);
			}
			else if (x < 10)
			{
				str += toString("#B%d#B #%d      ", x, x);
			}
			else
			{
				str += toString("#Y%d#Y#%d      ", x, x);
			}
			
			if (i % 5 == 4)
			{
				str += "\n\n\n";
			}
		}
		_ftext.SetFaceText(str, g_pMainState->m_hFont[0], 480);
		return true;
	}
	_ftext.SetFaceText(s_descTexts[_page], g_pMainState->m_hFont[0], 480);
	return true;
}

bool uiDesc::Show(cCanvas* pCanvas)
{
	cInterfaceFather::Show(pCanvas);
	if (_text)
	{
		_ftext.SetPos(_text->GetX(), _text->GetY());
	}
	_ftext.Show(pCanvas);
	return true;
}
