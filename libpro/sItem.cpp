#include "sItem.h"
#include "cEquip.h"

bool sItem::setIcon(eIcon icon, int id)
{
	const auto& tables = txtIcon::getInstance()->getTables();
	const auto& it = tables.find(icon);
	if (it == tables.end())
	{
		return false;
	}
	const auto& it2 = it->second.find(id);
	if (it2 == it->second.end())
	{
		return false;
	}
	_type = icon;
	_id = id;
	_icon = &it2->second;
	_num = 1;
	_price = _icon->price;
	return true;
}


bool sItem::setData(bool effect_ex3, bool add2, int eMin, int eMax)
{
	if (!isValid() || !isEquip())
	{
		return false;
	}
	cEquip::fill(*this, effect_ex3, add2, eMin, eMax);
	return true;
}


bool sItem::setData(const std::string& mapname, int x, int y)
{
	if (!isValid())
	{
		return false;
	}
	if (getType() != eIcon::��ͼb && getType() != eIcon::����d)
	{
		return false;
	}
	const auto& maps = txtMap::getInstance()->getTables();
	if (maps.find(mapname) == maps.end())
	{
		return false;
	}
	_str = mapname;
	_head = x;
	_pro = y;
	return true;
}

bool sItem::add(int count /*= 1*/)
{
	if (!isValid())
	{
		return false;
	}
	++_num;
	return true;
}

bool sItem::sub(int count /*= 1*/)
{
	if (!isValid())
	{
		return false;
	}
	// ������Ʒ
	if (isConsumables() && _num <= 1)
	{
		return false;
	}
	--_num;
	return true;
}

bool sItem::isValid()const
{
	return _num > 0 && _icon != nullptr;
}

void sItem::toDesc(sDescs& descs)const
{
	descs.clear();
	if (!isValid())
	{
		return;
	}
	sDesc d;
	descs.clear();

// 	d.text = _icon->name;
// 	d.color = s565::YELLOW;
// 	descs.push(d);
	descs.uhead = _icon->big;
	descs.name = _icon->name;

	d.text = _icon->desc;
	d.color = s565::WHITE;
	descs.push(d);

	if (isEquip())
	{
		d.text = "�ȼ� " + cc::toString(cEquip::getLv(*this));
		d.color = s565::YELLOW;
		descs.push(d);

		cEquip::apply(*this, descs);
		return;
	}

	if (is��ͼor����() && !_str.empty())
	{
		d.text = _str + " " + cc::toString(_head) + " " + cc::toString(_pro);
		d.color = s565::YELLOW;
		descs.push(d);
	}
}

bool sItem::is��ͼor����(bool checkValid /* = true */) const 
{
	if (checkValid && !isValid())
	{
		return false;
	}
	return (_type == eIcon::����d || _type == eIcon::��ͼb);
}

bool sItem::isConsumables(bool checkValid /* = true */) const
{
	if (checkValid && !isValid())
	{
		return false;
	}
	return !(_type == eIcon::����q || _type == eIcon::����d || _type == eIcon::��Ƭk);
}

bool sItem::isOverly(bool checkValid /* = true */) const
{
	if (checkValid && !isValid())
	{
		return false;
	}
	return !(is��ͼor����(false) || cEquip::isEquip(_type) || _type == eIcon::����z);
}

bool sItem::isPetOnly(bool checkValid /*= true*/) const
{
	if (checkValid && !isValid())
	{
		return false;
	}
	return cEquip::isEquipBaby(_type) ||
		_type == eIcon::Ⱦɫr ||
		_type == eIcon::Ԫ��y ||
		_type == eIcon::����b ||
		_type == eIcon::�޾�s ||
		_type == eIcon::����c ||
		_type == eIcon::�ߵ�g;
}

bool sItem::isEquip(bool checkValid /* = true */)const
{
	if (checkValid && !isValid())
	{
		return false;
	}
	return cEquip::isEquip(_type);
}

bool sItem::isWeapon(bool checkValid /* = true */)const
{
	if (checkValid && !isValid())
	{
		return false;
	}
	return cEquip::isWeapon(_type);
}

bool sItem::isArmor(bool checkValid /* = true */)const
{
	if (checkValid && !isValid())
	{
		return false;
	}
	return cEquip::isArmor(_type);
}

bool sItem::isEquipBaby(bool checkValid /* = true */)const
{
	if (checkValid && !isValid())
	{
		return false;
	}
	return cEquip::isEquipBaby(_type);
}

bool sItem::isHelmet(bool checkValid /* = true */)const
{
	if (checkValid && !isValid())
	{
		return false;
	}
	return cEquip::isHelmet(_type);
}

bool sItem::isNeck(bool checkValid /* = true */)const
{
	if (checkValid && !isValid())
	{
		return false;
	}
	return cEquip::isNeck(_type);
}

bool sItem::isClothes(bool checkValid /* = true */)const
{
	if (checkValid && !isValid())
	{
		return false;
	}
	return cEquip::isClothes(_type);
}

bool sItem::isBelt(bool checkValid /* = true */)const
{
	if (checkValid && !isValid())
	{
		return false;
	}
	return cEquip::isBelt(_type);
}

bool sItem::isShoe(bool checkValid /* = true */)const
{
	if (checkValid && !isValid())
	{
		return false;
	}
	return cEquip::isShoe(_type);
}

bool sItem::switchWeapon(eMod master)
{
	if (!isValid())
	{
		return false;
	}
	if (!txtMod::isRole(master))
	{
		return false;
	}
	const auto& wlist = txtWeapon::getInstance()->getWeaponLists().at(master);
	if (ccc_find(wlist, _type))
	{
		return true;
	}
	setIcon(wlist.at(cc::random(0U, wlist.size() - 1)), _id);
	return true;
}

bool sItem::switchArmor(bool boy)
{
	if (!isValid())
	{
		return false;
	}
	if (isHelmet())
	{
		setIcon(boy ? eIcon::ͷ��t : eIcon::����f, _id);
		return true;
	}
	if (isClothes())
	{
		setIcon(boy ? eIcon::����k : eIcon::��ȹb, _id);
		return true;
	}
	return false;
}


void sItem::save()const
{
	sStream& sav = *cSave::getSave();
	if (!isValid())
	{
		sav << 0 << s_space;
		return;
	}
	sav << _num << s_space << (int)_type << s_space << _id << s_space;
//	sav->save(_price);
	if (is��ͼor����())
	{
		if (_str.empty())
		{
			sav << "��" << s_space;
		}
		else
		{
			sav << _str << s_space << _head << s_space << _pro << s_space;
		}
	}
	else if (isEquip())
	{
		sav << _head << s_space << _pro << s_space;
	}
}

void sItem::load()
{
	sStream& load = *cSave::getLoad();
	load >> _num;
	if (_num == 0)
	{
		return;
	}
	int type;
	load >> type >> _id; // >> _price;
	_type = (eIcon)type;
	setIcon(_type, _id);
	if (is��ͼor����())
	{
		load >> _str;
		if (_str == "��")
		{
			_str.clear();
		}
		else
		{
			load >> _head >> _pro;
		}
	}
	else if (isEquip())
	{
		load >> _head >> _pro;
	}
}


bool sItem::operator!=(const sItem& it) const
{
	return !(_type == it._type && _id == it._id);
}


bool sItem::operator==(const sItem& it) const
{
	return _type == it._type && _id == it._id;
}



#if 0
// �ǵø���Ѫ��, ���ż�Ѫ����
static bool use25medicine(sAttribute& data, int id)
{
	// ǰ��hpmpap�Ա�,���Ŷ���
	switch (id)
	{
	case 0:	//ͬ���⸬
	//  success = AddFunc(&ItemManager::AddHp, 100, ObjId/*, 10000*/);

		return data.addhp(100);
	case 1://��Ҷ��   
		return data.addhp(40);
	case 2://����ذ�
		return data.addhp(80);
	case 3://�˲�
		return data.addhphp2(80, 20);
	case 4://Ѫɫ�軨
		return data.addhp(150);
	case 5://�ܵ�
		return data.addhp(200);
	case 6://��ǲ�
		return data.addhp(250);
	case 7://Ѫɺ��
		return data.addmp(100);
	case 8://������֥
		return data.addmp(100);
	case 9://��֮��м
		return data.addhp(300);
	case 10://��ҩ
		return data.addhp(400);
	case 11://��ѩɢ
	//	success = removeBuff(eBuffType��, ObjId, true) && AddHp(400, ObjId);
		return data.addhp(400);
	case 12://�˽���Ҷ
		return data.addhp2(60, 15);
	case 13://��Ҷ��
		return data.addhp(60);
	case 14://¹��
		return data.addhp(150);
	case 15://���β
		return data.addhp(250);
	case 16://���֮��
		return data.addhp(300);
	case 17://С����
		return data.addhphp2(400, 400);
	case 18://������
		return data.addhp(800);
	case 19://����
		return data.addmp(20);
	case 20://������
		return data.addmp(20);
	case 21://��Ҷ
		return data.addmp(30);
	case 22://��٢�޻�
		return data.addmp(50);
	case 23://����ˮ
		return data.addmp(150);
	case 24://�ͷ���¶
		return data.addmp(100);
	case 25://��ˮ��Ԫ��
		return data.addmp(300);
	case 26://�ϵ���
		return data.addmp(20);
	case 27://�����
		return data.addmp(30);
	case 28://�����ͷ
		return data.addmp(40);
	case 29://����ˮ
		return data.addmp(75);
	case 30://������
		return data.addmp(75);
	case 31://����
		return data.addmp(100);
	case 32://�ɺ���
		return data.addmp(150);
	case 33://������
		return data.addmp(350);
	case 34://�ݹ�
		return data.addhp2(10);
	case 35://�����
		return data.addhp2(15);
	case 36://ˮ����
		return data.addhp2(20);
	case 37://ɽҩ
		return data.addhphp2(40, 10);
	case 38://��֬
		return data.addmp(40);
	case 39://��ʯӢ
		return data.addmp(100);
	case 40://�¼���
		data.addhp(40);
		return data.addmp(30);
	case 41://��¶Ϊ˪
		return data.addmp(100);
	case 42://��ȸ��
		return data.addmp(100);
	case 43://��Ы����
		return data.addmp(500);
	case 44://���������
		return data.relife2(1, 150);
	case 45://��ת�ػ굤
		return data.relife(200);
	case 46://��ɫ��
		return data.addmp(30);
	case 47://�����ֻ�
		return data.addhp(200);
	case 48://ǧ�걣�ĵ�
		return data.addhphp2(400, 400);
	case 49://������
	//	removeBuff(eBuffType��ӡ, ObjId, true);
		return data.addhp(10);
	case 50://����ɳ
	//  AddFunc(&ItemManager::AddHp, 150, ObjId);
		return data.addhp(150);
	case 51://��ζ¶
	//  AddFunc(&ItemManager::AddMp, 40, ObjId);
		return data.addmp(40);
	case 52://������ (����ˮ)
	//  AddFunc(&ItemManager::AddCp, 15, ObjId);
		return data.addap(15);
	case 53://�����⸬
	//	AddFunc(&ItemManager::AddHpHurt, 150, ObjId);
	//	AddFunc(&ItemManager::AddHp, 150, ObjId);
		return data.addhphp2(150, 150);
		break;
	case 54://��¶��
		return data.addap(15);
	case 55://��ζ��
		return data.addap(20);
	case 56://�ߵ���
		return data.addap(25);
	case 57://��������
		return data.addap(30);
	case 58://��¶��
	//  AddFunc(&ItemManager::AddMp, 60, ObjId)
		return data.addmp(60);
	case 59://������Һ
	//	AddFunc(&ItemManager::AddCp, 10, ObjId/*, 10000*/);
		return data.addap(10);
	case 60://ǧ��¶
	//	AddFunc(&ItemManager::AddMp, 80, ObjId);
		return data.addap(80);
	}
	return false;
}

// �ǵø���Ѫ��
static bool use26pengren(sAttribute& data, int id)
{
	switch (id)
	{
	case 0:	//���� 
		return data.addhp(150);
	case 1://��Ѽ   
		return data.addhp(300);
	case 2://��ի
	//	success = AddHp(3000, ObjId);
		break;
	case 3://������
	//	success = AddHp(5000, ObjId);
		break;
	case 4://Ů����
		return data.addap(10);
	case 5://���Ǿ�
		return data.addap(20);
	case 6://÷����
		return data.addap(30);
	case 7://����ǽ
		return data.addmp(300);
	case 8://��䶹��
		return data.addmp(500);
	}
	return false;
}

static bool use27fabao(int id)
{
	switch (id)
	{
	case 11: // �¹�
		return true;
	case 12://ȥCA
	case 13://ȥAL
	case 14://ȥCS
	case 15://ȥZZ
	case 34://ȥ����
		return true;
	case 16: //����
		return true;
	}
	return false;
}

// use26��Ƭ


static bool use30daoju(int id)
{
	switch (id)
	{
	case 0://���з�
		return true;
	case 1://������
		return true;
	case 2://��ڤ��
		return true;
	case 3:// ����¶
	case 4:
	case 5:
		return true;
	case 36://��ź
		return true;
	case 42: // ����
	case 43:
	case 44:
	case 45:
	case 46:
	case 47:
	case 48:
	case 49:
	case 50:
	case 51:
		if (0 == (ccc_cfg(1) & (1 << (id - 42))))
		{
			ccc_cfg(1) |= (1 << (id - 42));
			return true;
		}
		break;
	case 55: // ����BUG
		return true;
	case 59: // �������
		return true;
	case 60: // ������
	case 61:
	case 62:
	case 63:
		return true;
	case 64: // ��ת��
	case 65:
	case 66:
	case 67:
		return true;
	case 68: // Ԫ��
	case 69:
	case 70:
	case 71:
	case 72:
	case 73:
	case 74:
		return true;
	}
	return false;
}

static bool use31diejia(int id)
{
	switch (id)
	{
	case 12: // ������
	case 13:
	case 14:
	case 15:
	case 16:
		return true;
	case 6://��ͼ
		return true;
	case 21: // �����ڱ�
		return true;
	}
	return false;
}

// use�Ҿ�

#endif