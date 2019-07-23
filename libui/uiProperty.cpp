#include "uiProperty.h"


uiProperty::uiProperty()
{
	std::fill(_points.begin(), _points.end(), nullptr);
}

bool uiProperty::init(Node* parent, int px, int py, int px2, int iy)
{
#define ccc_label_create(_label_)\
parent->addChild(_label_ = cLabel::create("0xFFFF"));\
	_label_->setColor(s565::BLACK)

	// �ȼ�
	ccc_label_create(_labelLv);

	// ����
	ccc_label_create(_labelName);
	// ��Ѫ
	ccc_label_create(_labelHp);
	// ħ��
	ccc_label_create(_labelMp);
	// ��ŭ
	ccc_label_create(_labelAp);

	// ����
	ccc_label_create(_labelHit);
	// ����
	ccc_label_create(_labelAtk);
	// ����
	ccc_label_create(_labelDef);
	// �ٶ�
	ccc_label_create(_labelSpeed);
	// ����
	ccc_label_create(_labelMana);
	// ��� 
	ccc_label_create(_labelEvade);


	// ���Ե� ����
	ccc_label_create(_labelBody);
	_labelBody->setPosition(px, py);
	// ���Ե� ħ��
	ccc_label_create(_labelMag);
	_labelMag->setPosition(px, py + 1 * iy);
	// ���Ե� ����
	ccc_label_create(_labelStr);
	_labelStr->setPosition(px, py + 2 * iy);
	// ���Ե� ����
	ccc_label_create(_labelDex);
	_labelDex->setPosition(px, py + 3 * iy);
	// ���Ե� ����
	ccc_label_create(_labelAgi);
	_labelAgi->setPosition(px, py + 4 * iy);
	// ���Ե� ʣ��
	ccc_label_create(_labelRemian);
	_labelRemian->setPosition(px, py + 5 * iy);

	// ����
	ccc_label_create(_labelExp);
	ccc_label_create(_labelExpMax);

#undef ccc_label_create
	// ��ť �Ӽ���
	forr(_buttonAdds, k)
	{
		parent->addChild(_buttonAdds[k] = cButton::create(ccu::uAdd));
		parent->addChild(_buttonSubs[k] = cButton::create(ccu::uSub));
// 		_buttonAdds[k]->setTag(k);
// 		_buttonSubs[k]->setTag(k);
		_buttonAdds[k]->setKeep2Click(true);
		_buttonSubs[k]->setKeep2Click(true);
		_buttonAdds[k]->setPosition(px2, py + k * iy);
		_buttonSubs[k]->setPosition(px2 + _buttonAdds[k]->getContentSize().width + 2, py + k * iy);
		_buttonAdds[k]->onClick = [this, k]()
		{
			auto& point = _pro.point;
			ePoint e = (ePoint)k;
			if (!point.add(e, true))
			{
				return;
			}
			point.add(e, false);
			_pointShow.get(e) = point.get(e) + _pros.point.get(e);
			_isPointed = true;
			updatePoint();
		};
		_buttonSubs[k]->onClick = [this, k]()
		{
			auto& point = _pro.point;
			ePoint e = (ePoint)k;
			if (!point.sub(e, true))
			{
				return;
			}
			point.sub(e, false);
			_pointShow.get(e) = point.get(e) + _pros.point.get(e);
			_isPointed = true;
			updatePoint();
		};
	}

	// ��ť ȷ���ӵ�
	parent->addChild(_buttonSure = cButton::create2("�ӵ�"));
	_buttonSure->setDesc("֧�ֳ���");
	_buttonSure->onClick = [this]()
	{
		if (_isPointed && !sTeam::getInstance()->isFighting() && onPoint != nullptr)
		{
			onPoint(0, _pro.point);
		}
	};
	return true;
}

void uiProperty::load(const sProperty& pro)
{
	_pro = pro;
	ccp::apply(_pros, pro);
	_pointShow = pro.point + _pros.point;
	forv(_points, k)
	{
		_points[k] = &_pro.point.get((ePoint)k);
	}
	load();
}


void uiProperty::load()
{
	// �ȼ�
	_labelLv->setString(_pro.lv);
	// �ȼ�
	_labelName->setString(_pro.name);
	// ����
	const auto& attr = _pros.attr;
	_labelHit->setString(attr.hit);
	// ����
	_labelAtk->setString(attr.atk);
	// ����
	_labelDef->setString(attr.def);
	// �ٶ�
	_labelSpeed->setString(attr.speed);
	// ����
	_labelMana->setString(attr.mana);
	// ��� 
	_labelEvade->setString(attr.evade);

	// ��Ѫ
	int hpMax = (int)attr.hpMax;
	if (_pro.ispet)
	{
		_labelHp->setString(toString("%d/%d", _pro.hp, hpMax));
	}
	else
	{
		_labelHp->setString(toString("%d/%d/%d", _pro.hp, _pro.hp2, hpMax));
	}
	// ħ��
	int mpMax = (int)attr.mpMax;
	_labelMp->setString(toString("%d/%d", _pro.mp, mpMax));
	// ��ŭ
	_labelAp->setString(toString("%d/%d", _pro.ap, sAttribute::cAp150));


	_labelExp->setString(_pro.exp);
	_labelExpMax->setString(sExp::getExp(_pro.lv + 1, _pro.ispet));

	updatePoint();
}




void uiProperty::updatePoint()
{
	// ���Ե� ����
	_labelBody->setString(_pointShow.body);
	// ���Ե� ħ��
	_labelMag->setString(_pointShow.mag);
	// ���Ե� ����
	_labelStr->setString(_pointShow.str);
	// ���Ե� ����
	_labelDex->setString(_pointShow.dex);
	// ���Ե� ����
	_labelAgi->setString(_pointShow.agi);
	// ���Ե� ʣ��
	_labelRemian->setString(_pro.point.remain);

	forv(_buttonAdds, k)
	{
		_buttonAdds[k]->setEnabled(_points[k] != nullptr && _pro.point.remain > 0);
		_buttonSubs[k]->setEnabled(_points[k] != nullptr && *_points[k] > 0);
	}
}
