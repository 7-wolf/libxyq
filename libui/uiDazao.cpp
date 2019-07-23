#include "uiDazao.h"
#include "uiManager.h"

bool uiDazao::init()
{
	if (!uiPad::init(0xABB7D0DB, true))
	{
		return false;
	}

	if (!uiItemGrid::init(this, this, 18, 132))
	{
		return false;
	}

	LabelNumber* labelNeed = LabelNumber::create(100000);
	labelNeed->setPosition(207, 79);
	this->addChild(labelNeed);

	LabelNumber* labelMoney = LabelNumber::create(123456789);
	labelMoney->setPosition(207, 100);
	this->addChild(labelMoney);


	forr(_buttonHeads, k)
	{
		this->addChildEvent(_buttonHeads[k] = ButtonItem::create());
		_buttonHeads[k]->setPosition(k == 0 ? 17 : 74, 61);
		_buttonHeads[k]->onClick = [&, k](const sItem* item, bool left)
		{
			if (left)
			{
				_buttonHeads[k]->load(nullptr);
			}
		};
	}

	uiItemGrid::onClick = [&](const sItem* item, bool left)
	{
		if (left)
		{
			bool isBook = item->getType() == 28 && item->getId() == 8;
			bool isIron = item->getType() == 28 && item->getId() == 7;
			if (isBook || cEquip::isEquip(item))
			{
				_buttonHeads[0]->load(item);
			}
			else if (isIron || item->getType() == eIcon::��ʯb)
			{
				_buttonHeads[1]->load(item);
			}
		}
	};

	int x = 20, y = 344, ix = 50, iy = 26;
	static vector<string> s_strs = { "����", "ͷ��", "����", "�¼�", "����", "Ь��" };
	forv(s_strs, k)
	{
		Button* button = Button::create2(s_strs[k]);
		this->addChildEvent(button);
		button->setPosition(x + (k - 1) * ix, y);
		if (k == 0)
		{
			button->setPosition(x + ix, y + iy);
		}
		button->setTag(k);
		button->onClick = BIND_1(uiDazao::dazao, this);
	}

	if (1)
	{
		Button* button = Button::create2("��Ƕ");
		this->addChildEvent(button);
		button->setPosition(x + 2 * ix, y + iy);
		button->onClick = BIND_1(uiDazao::xiangqian, this);
	}


	if (1)
	{
		Button* button = Button::create2("�ֽ�");
		this->addChildEvent(button);
		button->setPosition(x + 3 * ix, y + iy);
		button->onClick = BIND_1(uiDazao::fenjie, this);
	}

	return true;
}

void uiDazao::dazao(Button* button)
{
	sItem* it1 = (sItem*)_buttonHeads[0]->_item;
	auto it2 = _buttonHeads[1]->_item;
	uiManager* ui = getManager();
	if (it1 == nullptr || it2 == nullptr ||
		it1->getType() != 28 || it1->getId() != 8 ||
		it2->getType() != 28 || it2->getId() != 7)
	{
		ui->toast("���첻��");
		return;
	}

	if (it1->pros.empty() || it2->pros.empty())
	{
		ui->toast("��Ч����");
		return;
	}

	int booklv = it1->pros[0];
	if (booklv > it2->pros[0])
	{
		ui->toast("�� < ��");
		return;
	}

	static vector<int> types =
	{
		cc::random(eIcon::����j, eIcon::����f),
		eIcon::ͷ��t + cc::random(0, 1),
		eIcon::����x,
		eIcon::����k + cc::random(0, 1),
		eIcon::����y,
		eIcon::Ь��x
	};
	int t = types[button->getTag()];
	it1->setData(t, cEquip::getId(t, booklv));
	//////////////////////////////////////////////////////////////////////////

	((sItem*)it2)->_num = 0;
	_buttonHeads[0]->load(nullptr);
	_buttonHeads[1]->load(nullptr);
	uiItemGrid::load();
	ui->toast("����ɹ�");
}

void uiDazao::xiangqian(Button* button)
{
	sItem* it1 = (sItem*)_buttonHeads[0]->_item;
	auto it2 = _buttonHeads[1]->_item;
	uiManager* ui = getManager();
	if (it1 == nullptr || it2 == nullptr || 
		!cEquip::isEquip(it1) || it2->getType() != eIcon::��ʯb ||
		!cEquip::isStone(it1->getType(), it2->getId()))
	{
		ui->toast("��Ƕ����");
		return;
	}

	if (it2 == nullptr)
	{
		// �ֽ�
		ui->toast("�ֽ�ɹ�");
		return;
	}
	if (it2->getType() != eIcon::��ʯb)
	{
		ui->toast("��Ƕ����");
		return;
	}
	if (!cEquip::isStone(it1->getType(), it2->getId()))
	{
		ui->toast("��Ƕ����");
		return;
	}

	cEquip::setStone(it1->_head, it2->getId());
	cEquip::applyPros(*it1);
	it1->autoDesc();
	
	_buttonHeads[0]->load(nullptr);
	_buttonHeads[1]->load(nullptr);
	((sItem*)it2)->_num = 0;

	uiItemGrid::load();
	ui->toast("��Ƕ�ɹ�");
}

void uiDazao::fenjie(Button* button)
{
	sItem* it1 = (sItem*)_buttonHeads[0]->_item;
	uiManager* ui = getManager();
	if (it1 == nullptr || !cEquip::isEquipRole(it1))
	{
		ui->toast("�ֽⲻ��");
		return;
	}

	int lv = cEquip::getLv(it1->getType(), it1->getId());
	it1->setData(eIcon::����d, cc::random(7, 8), false);
	it1->autoProperty(lv);

	_buttonHeads[0]->load(nullptr);
	uiItemGrid::load();
	ui->toast("�ֽ�ɹ�");
}
