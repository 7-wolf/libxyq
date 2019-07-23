#include "uiZz.h"

static const int c_4 = 4, c_12 = c_4 * 3;
bool uiPropertyZz::init(Node* parent, int px, int py, int iy, int px2, int py2)
{
#define ccc_label_create(_label_, _y_)\
parent->addChild(_label_ = cLabel::create("0xFFFF"));\
	_label_->setColor(s565::BLACK);\
	_label_->setPosition(px, py + _y_ * iy);
	// ����
	ccc_label_create(_labelAtk, 0);
	// ����
	ccc_label_create(_labelDef, 1);
	// ����
	ccc_label_create(_labelHp, 2);
	// ����
	ccc_label_create(_labelMp, 3);
	// �ٶ�
	ccc_label_create(_labelSpeed, 4);
	// ��� 
	ccc_label_create(_labelEvade, 5);
	// ����
	ccc_label_create(_labelLife, 6);
	// �ɳ�
	ccc_label_create(_labelGrow, 7);
	// ����
	ccc_label_create(_label5xing, 8);
#undef ccc_label_create


	parent->addChild(_grids = uiGrids::create(4, 3, 42, 42));
	_grids->setPosition(px2, py2);
	_grids->onGrid = [this](int select, int count, bool left)
	{
		if (!left || sTeam::getInstance()->isFighting())
		{
			return;
		}
	};

// 	_skix = px2;
// 	_skiy = py2;

	// ���ܷ�ҳ
	parent->addChild(_buttonPage = cButton::create(ccu::uSkiNextPage));
	_buttonPage->setPosition(px2 + 172, py2 + 95);
	_buttonPage->onClick = [this]()
	{
		int page = _grids->getPage();
		if (++page >= _grids->getPageMax())
		{
			page = 0;
		}
		_grids->load(page);
	};
	return true;
}

void uiPropertyZz::load(const sProperty& pro)
{
	_buttonPage->setVisible(pro.skis.size() >= 12);
	_grids->clear();
	forv(pro.skis, k)
	{
		auto g = uiGrid::create(pro.skis[k]);
		_grids->load(g);
	}
	_grids->load();

	forv(_equips, k)
	{
		_equips[k]->removeFromParent();
	}
	_equips.clear();
	forv(pro.equips, k)
	{
		const auto& e = pro.equips[k];
		cSprite* sprite = cSprite::create(e.isValid() ? e.getIcon()->small : cSp::c0);
		sprite->setSnatchNode(true);
		_grids->getParent()->addChild(sprite);
		sprite->setPosition(21 + 60 * k, 38);
		if (k == 2)
		{
			sprite->setPositionX(sprite->getPositionX() - 1);
		}
		sprite->setAutoAp(false);
		sprite->setAnchorPoint(Vec2::ZERO);
		cSprite* spriteEquipBack = cSprite::create(ccu::uEquipBack);
		spriteEquipBack->setLocalZOrder(-1);
		spriteEquipBack->setVisible(pro.equips[k].isValid());
		sprite->addChild(spriteEquipBack);
		sDescs descs;
		e.toDesc(descs);
		sprite->setDesc(descs);
		_equips.push_back(sprite);
	}
	load(pro.zz);
}

void uiPropertyZz::load(const sZz& _zz)
{
	// ����
	_labelAtk->setVisible(_zz.atk > 0);
	// ����
	_labelDef->setVisible(_zz.def > 0);
	// ����
	_labelHp->setVisible(_zz.hp > 0);
	// ����
	_labelMp->setVisible(_zz.mag > 0);
	// �ٶ�
	_labelSpeed->setVisible(_zz.speed > 0);
	// ��� 
	_labelEvade->setVisible(_zz.evoid > 0);
	// ����
	_labelLife->setVisible(_zz.atk > 0);
	// �ɳ�
	_labelGrow->setVisible(_zz.grow100 > 0);
	// ����
	_label5xing->setVisible(_zz.atk > 0);

	if (_labelAtk->isVisible())
	{
		// ����
		_labelAtk->setString(_zz.atk);
		// ����
		_labelDef->setString(_zz.def);
		// ����
		_labelHp->setString(_zz.hp);
		// ����
		_labelMp->setString(_zz.mag);
		// �ٶ�
		_labelSpeed->setString(_zz.speed);
		// ��� 
		_labelEvade->setString(_zz.evoid);
		// ����
		_labelLife->setString(cc::random(1000, 9999));
		// �ɳ�
		_labelGrow->setString(toString("%0.2f", _zz.grow100 * 0.01f));
		// ����
		static std::vector<std::string> s_12xings = { "��", "ľ", "ˮ", "��", "��" };
		_label5xing->setString(s_12xings.at(cc::random(0, (int)s_12xings.size() - 1)));
	}

// 	_button->setVisible(_buttons.size() > c_12);
// 
// 	int size = _buttons.size();
// 	for (int k = 0; k < size; ++k)
// 	{
// 		_buttons[k]->setVisible(false);
// 	}
// 
// 	size = std::min(size, (_page + 1) * c_12);
// 
// 	for (int k = _page * c_12; k < size; ++k)
// 	{
// 		_buttons[k]->setVisible(true);
// 	}
}



uiZz::~uiZz()
{
	if (_notice != nullptr)
	{
		_notice->doNotify();
	}
}

//////////////////////////////////////////////////////////////////////////
bool uiZz::init(uiNotice* notice)
{
	if (!uiPad::init(1338020705, true))
	{
		return false;
	}
	if (!uiPropertyZz::init(this, 128, 100, 23, 20, 313))
	{
		return false;
	}
	_notice = notice;
	return true;
}
