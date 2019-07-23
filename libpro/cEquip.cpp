#include "cEquip.h"

static int ccc_rand(int a, int b)
{
	return cc::random(a, b);
}
static int ccc_rand()
{
	return cc::random(0, 99);
}


static int proTemp(eProPerty pro, int lv, int e)
{
	int r = (160 - lv) / 2;
	int pMax = 0;
	switch (pro)
	{
	case eProPerty::�ٶ�:
	case eProPerty::��ŭ:
	case eProPerty::����:
	case eProPerty::����:
	case eProPerty::����:
	case eProPerty::ħ��:
	case eProPerty::����:
		pMax = 20;
		break;
	case eProPerty::�ظ�:
		pMax = 30;
		break;
	case eProPerty::����:
	case eProPerty::����:
	case eProPerty::����:
	case eProPerty::���:
		pMax = 60;
		break;
	case eProPerty::�˺�:
	case eProPerty::����:
	case eProPerty::����:
		pMax = 100;
		break;
	case eProPerty::��Ѫ:
	case eProPerty::ħ��:
		pMax = 200;
		break;
	default:
		return 0;
	}
	return (lv + r * e / 100) * pMax / 100;
}

static int proAtk(int lv, int e)
{
	int v = 10 + lv * 3;
	if (e == 0)
	{
		return v;
	}
	return v + (lv / 6) + (lv)* e / 100;
}

static int proHit(int lv, int e)
{
	int v = 10 + lv * 7 / 2;
	if (e == 0)
	{
		return v;
	}
	return v + (lv / 5) + (lv * 6 / 5) * e / 100;
}

static int proHitRate(int lv, int e)
{
	int v = 4 + lv / 8;
	if (e == 0)
	{
		return v;
	}
	return v + (lv / 20) * e / 100;
}

static int proDef(int lv, int e)
{
	int v = 5 + lv / 3;
	if (e == 0)
	{
		return v;
	}
	return v + (lv / 14) + (lv / 5) * e / 100;
}

static int proMp(int lv, int e)
{
	int v = 5 + lv;
	if (e == 0)
	{
		return v;
	}
	return v + (lv / 10) + (lv / 3) * e / 100;
}

static int proMana(int lv, int e)
{
	int v = 5 + lv * 6 / 5;
	if (e == 0)
	{
		return v;
	}
	return v + (lv / 9) + (lv * 2 / 5) * e / 100;
}

static int proHp(int lv, int e)
{
	int v = 10 + lv * 2;
	if (e == 0)
	{
		return v;
	}
	return v + (lv / 5) + (lv * 2 / 3) * e / 100;
}

static int proDef2(int lv, int e)
{
	int v = 10 + lv * 5 / 3;
	if (e == 0)
	{
		return v;
	}
	return v + (lv / 5) + (lv / 2) * e / 100;
}

static int proAgi(int lv, int e)
{
	int v = 5 + lv / 3;
	if (e == 0)
	{
		return v;
	}
	return v + (lv / 17) + (lv / 10) * e / 100;
}

static int proPointEx(int lv, int e)
{
	int v = 4 + lv / 8;
	if (e == 0)
	{
		return v;
	}
	return v + (lv / 10) * e / 100;
}

static int proArmor(eIcon type, eProPerty pro, int lv, int e)
{
	switch (pro)
	{
	case eProPerty::����:
		return cEquip::isClothes(type) ? proDef2(lv, e) : proDef(lv, e);
	case eProPerty::ħ��:
		return proMp(lv, e);
	case eProPerty::����:
		return proMana(lv, e);
	case eProPerty::��Ѫ:
		return proHp(lv, e);
	case eProPerty::����:
		return cEquip::isShoe(type) ? proAgi(lv, e) : proPointEx(lv, e);
	case eProPerty::����:
	case eProPerty::����:
	case eProPerty::ħ��:
	case eProPerty::����:
		return proPointEx(lv, e);
	}
	return 0;
}

static int proWeapon(eProPerty pro, int lv, int e)
{
	switch (pro)
	{
	case eProPerty::����:
		return proHit(lv, e);
	case eProPerty::�˺�:
		return proAtk(lv, e);
	case eProPerty::����:
	case eProPerty::����:
	case eProPerty::����:
	case eProPerty::ħ��:
	case eProPerty::����:
		return proPointEx(lv, e);
	}
	return 0;
}

static int proBabyAtk(int lv, int e)
{
	int v = 10 + lv / 6;
	if (e == 0)
	{
		return v;
	}
	return v + (lv / 7) * e / 100;
}

static int proBabyMana(int lv, int e)
{
	int v = 4 + lv / 8;
	if (e == 0)
	{
		return v;
	}
	return v + (lv / 10) * e / 100;
}

static int proBabyDef(int lv, int e)
{
	int v = 8 + lv * 3 / 5;
	if (e == 0)
	{
		return v;
	}
	return v + (lv / 6) * e / 100;
}

static int proBabyHpMp(int lv, int e)
{
	int v = 30 + lv / 3;
	if (e == 0)
	{
		return v;
	}
	return v + (lv)* e / 100;
}

static int proBabySpeed(int lv, int e)
{
	int v = 4 + lv / 5;
	if (e == 0)
	{
		return v;
	}
	return v + (lv / 10) * e / 100;
}

static int proBaby(eProPerty pro, int lv, int e)
{
	switch (pro)
	{
	case eProPerty::����:
		return proHitRate(lv, e);
	case eProPerty::�ٶ�:
		return proBabySpeed(lv, e);
	case eProPerty::����:
		return proBabyDef(lv, e);
	case eProPerty::�˺�:
		return proBabyAtk(lv, e);
	case eProPerty::����:
		return proBabyMana(lv, e);
	case eProPerty::��Ѫ:
	case eProPerty::ħ��:
		return proBabyHpMp(lv, e);
	}
	return 0;
}

//////////////////////////////////////////////////////////////////////////
bool cEquip::isEquip(eIcon _type)
{
	return _type >= eIcon::equip0 && _type <= eIcon::equipEnd;
}

bool cEquip::isEquip(eMod master, eIcon type)
{
	if (!isEquip(type))
	{
		return false;
	}
	if (isWeapon(type))
	{
		const auto& wlist = txtWeapon::getInstance()->getWeaponLists().at(master);
		return ccc_find(wlist, type);
	}
	bool isBoy = txtMod::isBoy(master);
	if (type == eIcon::ͷ��t || type == eIcon::����k)
	{
		return isBoy;
	}
	if (type == eIcon::����f || type == eIcon::��ȹb)
	{
		return !isBoy;
	}
	return true;
}

bool cEquip::isWeapon(eIcon _type)
{
	return _type >= eIcon::eWeapon0 && _type <= eIcon::eWeaponEnd;
}

bool cEquip::isArmor(eIcon _type)
{
	return _type >= eIcon::equipArmor0 && _type <= eIcon::equipArmorEnd;
}

bool cEquip::isEquipBaby(eIcon _type)
{
	return _type >= eIcon::equipBaby0 && _type <= eIcon::equipBabyEnd;
}

bool cEquip::isHelmet(eIcon _type)
{
	return (_type == eIcon::ͷ��t || _type == eIcon::����f);
}

bool cEquip::isNeck(eIcon _type)
{
	return (_type == eIcon::����x);
}

bool cEquip::isClothes(eIcon _type)
{
	return (_type == eIcon::����k || _type == eIcon::��ȹb);
}

bool cEquip::isBelt(eIcon _type)
{
	return (_type == eIcon::����y);
}

bool cEquip::isShoe(eIcon _type)
{
	return (_type == eIcon::Ь��x);
}

//////////////////////////////////////////////////////////////////////////
#pragma pack (push)
#pragma pack (1)
union sProHead
{
	uint pro;
	struct
	{
		// ʯͷ +1
		uint stone : 5;
		// ˫�� + 1
		uint ap1 : 3;
		uint ap2 : 3;
		// ����/��ŭ
		uint gad : 1;
		// ���׾���
		uint easy : 1;
		// �޼���
		uint wjb : 1;
		// �ؼ� -eSpecial0 +1
		uint special : 6;
		// ��ʯ +1
		uint fushi : 5;
		// ׷�� +1
		uint zhuijia : 7;
	};

	void apply(eIcon type, bool specialEffect)
	{
		// ʯͷ �������
		pro = 0;

		if (cEquip::isWeapon(type) || cEquip::isClothes(type))
		{
			// ˫��
			std::vector<int> add2s = { 0, 1, 2, 3, 4 };
			int r = ccc_rand(0, 4);
			this->ap1 = add2s[r];
			add2s.erase(add2s.begin() + r);

			r = ccc_rand(0, 3);
			this->ap2 = add2s[r];
		}

		if (cEquip::isWeapon(type) || cEquip::isBelt(type))
		{
			// ����/��ŭ
			if (specialEffect && ccc_rand() < 5)
			{
				this->gad = 1;
			}
		}
		if (specialEffect && !cEquip::isEquipBaby(type))
		{
			if (ccc_rand() < 5)
			{
				// ����
				this->easy = 1;
			}
			else if (ccc_rand() < 2)
			{
				this->wjb = 1;
			}
			if (ccc_rand() < 20)
			{
				eSkill ski;
				auto& skis = txtIcon::getInstance()->getTables().at(eIcon::����j);
				do 
				{
					ski = (eSkill)ccc_rand((int)eSkill::eSpecial0, (int)eSkill::eSpecialEnd);
					if (!skis.at((int)ski).desc.empty())
					{
						break;
					}
				} while (true);
				// �ؼ�
				this->special = (int)ski - (int)eSkill::eSpecial0 + 1;
			}
		}

		if (!cEquip::isWeapon(type))
		{
			// ����û�з�ʯ(��Ƕ)
		}

	}

};
union sProWeapon
{
	u64 pro;
	struct
	{
		//
		u64 temp1 : 1;
		// ����
		u64 hit : 7;
		// �˺�
		u64 atk : 7;
		// ˫��
		u64 ap1 : 7;
		u64 ap2 : 7;

		// ��ʱ��Ѫ
		u64 t_hp : 7;
		// ħ��
		u64 t_mp : 7;
		// �˺�
		u64 t_atk : 7;
		// ����
		u64 t_def : 7;
		// �ظ�
		u64 t_restore : 7;
	};

	void apply(bool add2, int eMin, int eMax)
	{
		pro = 0;
		// 0 ���ڹ���
		auto func = [=](){return ccc_rand(eMin, eMax); };
		// ����
		hit = func();
		// �˺�
		atk = func();
		if (add2)
		{
			// ˫��
			ap1 = func();
			ap2 = func();
		}

		return;
		// ��ʱ��Ѫ
		t_hp = func();
		// ħ��
		t_mp = func();
		// �˺�
		t_atk = func();
		// ����
		t_def = func();
		// �ظ�
		t_restore = func();
	}

	void add(int temp)
	{
		// ��ʱ��Ѫ
		t_hp += temp;
		// ħ��
		t_mp += temp;
		// �˺�
		t_atk += temp;
		// ����
		t_def += temp;
		// �ظ�
		t_restore += temp;
		correct();
	}

	void correct()
	{
		if (hit > 100)
		{
			hit = 100;
		//	return true;
		}
		// �˺�
		if (atk > 100)
		{
			atk = 100;
		//	return true;
		}
		// ˫��
		if (ap1 > 100)
		{
			ap1 = 100;
		//	return true;
		}
		if (ap2 > 100)
		{
			ap2 = 100;
		//	return true;
		}

		// ��ʱ��Ѫ
		if (t_hp > 100)
		{
			t_hp = 100;
		//	return true;
		};
		// ħ��
		if (t_mp > 100)
		{
			t_mp = 100;
		//	return true;
		}
		// �˺�
		if (t_atk > 100)
		{
			t_atk = 100;
		//	return true;
		}
		// ����
		if (t_def > 100)
		{
			t_def = 100;
		//	return true;
		}
		// �ظ�
		if (t_restore > 100)
		{
			t_restore = 100;
		//	return true;
		}
	//	return false;
	}
};
union sProArmor
{
	u64 pro;
	struct
	{
		// �·�˫��
		u64 temp : 36;
		// ������
		u64 pro1 : 7;
		// (�·�˫��)
		u64 pro2 : 7;
		// ��ʱ
		u64 temp1 : 7;
		u64 temp2 : 7;
	};

	void apply(eIcon type, bool add2, int eMin, int eMax)
	{
		pro = 0;
		auto func = [=](){return ccc_rand(eMin, eMax); };
		if (add2 && cEquip::isClothes(type))
		{
			// �·�˫��
			temp = func();
		}
		// ����/����
		pro1 = func();
		if (cEquip::isNeck(type) || (!add2 && cEquip::isClothes(type)))
		{
			// �������·�˫��
			return;
		}
		// ħ��/��/˫��/��Ѫ/����
		pro2 = func();
		return;
		// ����/����/����/���/����
		temp1 = func();
		// ����/����/ħ��/��ŭ/�ٶ�
		temp2 = func();
	}

	void add(eIcon type, int _temp)
	{
		if (cEquip::isClothes(type))
		{
			// �·�˫��
			temp += _temp;
			pro2 += _temp;
		}
		// ����/����/����/���/����
		temp1 += _temp;
		// ����/����/ħ��/��ŭ/�ٶ�
		temp2 += _temp;
		correct();
	}

	void correct()
	{
		if (temp > 100)
		{
			temp = 100;
		//	return true;
		}
		if (pro1 > 100)
		{
			pro1 = 100;
		//	return true;
		}
		if (pro2 > 100)
		{
			pro2 = 100;
		//	return true;
		}
		if (temp1 > 100)
		{
			temp1 = 100;
		}
		if (temp2 > 100)
		{
			temp2 = 100;
		//	return true;
		}
	//	return false;
	}
};
union sProBaby
{
	u64 pro;
	struct
	{
		uint temp;
		// ��һ�������˺�or����
		uint isAtk : 1;
		uint isAdd1 : 1;
		uint isAdd2 : 1;
		uint isAdd3 : 1;
		// ������
		uint pro1 : 7;
		// ���� �˺�/����
		uint add1 : 7;
		// ���� ��Ѫ
		uint add2 : 7;
		// ���� ħ��
		uint add3 : 7;
	};

	void apply(eIcon type, bool ex3, int eMin, int eMax)
	{
		pro = 0;
		isAtk = ccc_rand() < 50;
		isAdd1 = ccc_rand() < (ex3 ? 100 : 70);
		isAdd2 = ccc_rand() < (ex3 ? 100 : 50);
		isAdd3 = ccc_rand() < (ex3 ? 100 : 50);

		auto func = [=](){return ccc_rand(eMin, eMax); };
		// ������/�ٶ�/����
		pro1 = func();
		if (isAdd1)
		{
			// ���� �˺�/����
			add1 = func();
		}
		if (isAdd2)
		{
			// ���� ��Ѫ
			add2 = func();
		}
		if (isAdd3)
		{
			// ���� ħ��
			add3 = func();
		}
	}

	void correct()
	{
		if (add1 > 100)
		{
			add1 = 100;
		}
		if (add2 > 100)
		{
			add2 = 100;
		}
		if (add3 > 100)
		{
			add3 = 100;
		}
	}
};
#pragma pack (pop)


//////////////////////////////////////////////////////////////////////////
bool cEquip::fill(sItem& equip, bool effect_or_ex3, bool add2, int eMin, int eMax)
{
	if (!equip.isEquip())
	{
		return false;
	}
	if (equip.isEquipBaby())
	{
		sProBaby baby;
		baby.apply(equip.getType(), effect_or_ex3, eMin, eMax);
		baby.correct();
		equip._pro = baby.pro;
		return true;
	}

	sProHead head;
	head.apply(equip.getType(), effect_or_ex3);
	equip._head = head.pro;

	if (equip.isWeapon())
	{
		sProWeapon w;
		w.apply(add2, eMin, eMax);
		w.correct();
		equip._pro = w.pro;
	}
	else if (equip.isArmor())
	{
		sProArmor e;
		e.apply(equip.getType(), add2, eMin, eMax);
		e.correct();
		equip._pro = e.pro;
	}

	return true;
}


bool cEquip::apply(const sItem& equip, sPropertys& pros)
{
	sProHead head;
	head.pro = equip._head;
	int lv = getLv(equip);
	if (equip.isEquipBaby())
	{
		sProBaby baby;
		baby.pro = equip._pro;
		baby.correct();
		pros.resize(5);

		auto type = equip.getType();
		// 0 ������
		if (type == eIcon::����h)
		{
			pros[0].pro = eProPerty::����;
		}
		else if (type == eIcon::��Ȧx)
		{
			pros[0].pro = eProPerty::�ٶ�;
		}
		else if (type == eIcon::����h)
		{
			pros[0].pro = eProPerty::����;
		}

		pros[0].value = proBaby(pros[0].pro, lv, baby.pro1);
		// 123 ����
		if (baby.isAdd1)
		{
			// ���� �˺�/����
			if (baby.isAtk)
			{
				pros[1].pro = eProPerty::�˺�;
			}
			else
			{
				pros[1].pro = eProPerty::����;
			}
			pros[1].value = proBaby(pros[1].pro, lv, baby.add1);
		}
		if (baby.isAdd2)
		{
			// ���� ��Ѫ
			pros[2].pro = eProPerty::��Ѫ;
			pros[2].value = proBaby(pros[2].pro, lv, baby.add2);
		}
		if (baby.isAdd3)
		{
			// ���� ħ��
			pros[3].pro = eProPerty::ħ��;
			pros[3].value = proBaby(pros[3].pro, lv, baby.add3);
		}
		// 89 ��ʯ(����)
		if (head.stone > 0)
		{
			pros[4] = txtStone::getInstance()->getTables().at((eStone)(head.stone - 1));
			pros[4].value *= (lv / 10 + head.easy);
		}
		return true;
	}

	std::vector<eProPerty> s_add2s = { eProPerty::����, eProPerty::ħ��, eProPerty::����, eProPerty::����, eProPerty::���� };
	if (equip.isWeapon())
	{
		sProWeapon w;
		w.pro = equip._pro;
		w.correct();
		pros.resize(10);
		// 01 ������
		pros[0].pro = eProPerty::����;
		pros[0].value = proWeapon(pros[0].pro, lv, w.hit);
		pros[1].pro = eProPerty::�˺�;
		pros[1].value = proWeapon(pros[1].pro, lv, w.atk);
		// 23 ˫��
		if (w.ap1 > 0)
		{
			pros[2].pro = s_add2s[head.ap1];
			pros[2].value = proWeapon(pros[2].pro, lv, w.ap1);
		}
		if (w.ap2 > 0)
		{
			pros[3].pro = s_add2s[head.ap2];
			pros[3].value = proWeapon(pros[3].pro, lv, w.ap2);
		}
		// 4 ��ʯ(����)
		if (head.stone > 0)
		{
			pros[4] = txtStone::getInstance()->getTables().at((eStone)(head.stone - 1));
			pros[4].value *= (lv / 10 + head.easy);
			for (int k = 0; k < 2; ++k)
			{
				if (pros[4].pro == pros[k].pro)
				{
					pros[k].value += pros[4].value;
					pros[4].pro = eProPerty::None;
					pros[4].value = 0;
					break;
				}
			}
		}
		// 5-... ��ʱ
		if (w.t_hp > 0)
		{
			pros[5].pro = eProPerty::��Ѫ;
			pros[5].value = proTemp(pros[5].pro, lv, w.t_hp);
		}
		if (w.t_mp > 0)
		{
			pros[6].pro = eProPerty::ħ��;
			pros[6].value = proTemp(pros[6].pro, lv, w.t_mp);
		}
		if (w.t_atk > 0)
		{
			pros[7].pro = eProPerty::�˺�;
			pros[7].value = proTemp(pros[7].pro, lv, w.t_atk);
		}
		if (w.t_def)
		{
			pros[8].pro = eProPerty::����;
			pros[8].value = proTemp(pros[8].pro, lv, w.t_def);
		}
		if (w.t_restore > 0)
		{
			pros[9].pro = eProPerty::�ظ�;
			pros[9].value = proTemp(pros[9].pro, lv, w.t_restore);
		}
		return true;
	}
	sProArmor e;
	e.pro = equip._pro;
	e.correct();
	pros.resize(7);

	if (equip.isNeck())
	{
		pros[0].pro = eProPerty::����;
	}
	else
	{
		pros[0].pro = eProPerty::����;
	}
	pros[0].value = proArmor(equip.getType(), pros[0].pro, lv, e.pro1);

	if (equip.isHelmet())
	{
		pros[1].pro = eProPerty::ħ��;
	}
	else if (equip.isBelt())
	{
		pros[1].pro = eProPerty::��Ѫ;
	}
	else if (equip.isShoe())
	{
		pros[1].pro = eProPerty::����;
	}

	if (equip.isClothes())
	{
		// 23 ˫�� 
		if (e.temp > 0)
		{
			pros[2].pro = s_add2s[head.ap1];
			pros[2].value = proWeapon(pros[2].pro, lv, e.temp);
		}
		if (e.pro2 > 0)
		{
			pros[3].pro = s_add2s[head.ap2];
			pros[3].value = proWeapon(pros[3].pro, lv, e.pro2);
		}
	}
	else
	{
		pros[1].value = proArmor(equip.getType(), pros[1].pro, lv, e.pro2);
	}

	// 4 ��ʯ(����)
	if (head.stone > 0)
	{
		pros[4] = txtStone::getInstance()->getTables().at((eStone)(head.stone - 1));
		pros[4].value *= (lv / 10 + head.easy);
		for (int k = 0; k < 2; ++k)
		{
			if (pros[4].pro == pros[k].pro)
			{
				pros[k].value += pros[4].value;
				pros[4].pro = eProPerty::None;
				pros[4].value = 0;
				break;
			}
		}
	}

	// 5-... ��ʱ
	if (equip.isHelmet())
	{
		pros[5].pro = eProPerty::����;
		pros[6].pro = eProPerty::����;
	}
	else if (equip.isNeck())
	{
		pros[5].pro = eProPerty::����;
		pros[6].pro = eProPerty::����;
	}
	else if (equip.isClothes())
	{
		pros[5].pro = eProPerty::����;
		pros[6].pro = eProPerty::ħ��;

	}
	else if (equip.isBelt())
	{
		pros[5].pro = eProPerty::���;
		pros[6].pro = eProPerty::��ŭ;
	}
	else if (equip.isShoe())
	{
		pros[5].pro = eProPerty::����;
		pros[6].pro = eProPerty::�ٶ�;
	}
	if (e.temp1 > 0)
	{
		pros[5].value = proTemp(pros[5].pro, lv, e.temp1);
	}
	else
	{
		pros[5].pro = eProPerty::None;
	}
	if (e.temp2 > 0)
	{
		pros[6].value = proTemp(pros[6].pro, lv, e.temp2);
	}
	else
	{
		pros[6].pro = eProPerty::None;
	}

	return true;
}

static std::string getTaozhuangName(const sItem& equip)
{
	bool isZhuijia;
	eSkill ski = cEquip::getTaoZhuang(equip, isZhuijia);
	if (ski == eSkill::eSkiNone)
	{
		return "";
	}
	std::string str = isZhuijia ? "׷�ӷ���: " : "����״̬: ";
	str += txtIcon::getInstance()->getTables().at(eIcon::����j).at((int)ski).name;
	return str;
}

bool cEquip::apply(const sItem& equip, sDescs& descs)
{
	sProHead head;
	head.pro = equip._head;
	int lv = getLv(equip);
	sDesc d;
//	descs.clear();
	sPropertys pros;
	apply(equip, pros);
	const auto icons = txtIcon::getInstance()->getTables();
	if (equip.isEquipBaby())
	{
		// 0 
		// 123 ����
		d.text.clear();
		for (int k = 0; k <= 3; ++k)
		{
			if (pros[k].isVaild())
			{
				d.text += pros[k].toString("+") + " ";
			}
		}
		if (!d.text.empty())
		{
			d.text.pop_back();
			d.color = s565::YELLOW;
			descs.push(d);
		}
		// 4 ��ʯ
		if (pros[4].isVaild())
		{
			d.text = toString("��Ƕ�ȼ�: %d", lv / 10);
			d.color = s565::YELLOW;
			descs.push(d);

			d.text = "��ǶЧ��: " + pros[4].toString("+");
			d.color = s565::WHITE;
			descs.push(d);
		}

		d.text = getTaozhuangName(equip);
		if (!d.text.empty())
		{
			d.color = s565(0x80, 0x80, 0xFF);
			descs.push(d);
		}
		return true;
	}


	// 01
	d.text.clear();
	for (int k = 0; k <= 1; ++k)
	{
		if (pros[k].isVaild())
		{
			d.text += pros[k].toString("+") + " ";
		}
	}
	if (!d.text.empty())
	{
		d.text.pop_back();
		d.color = s565::YELLOW;
		descs.push(d);
	}
	if (head.stone > 0)
	{
		d.text = toString("�����ȼ�: %d ", (lv / 10) + (head.easy)) + icons.at(eIcon::��ʯb).at(head.stone - 1).name;
		d.color = s565::YELLOW;
		descs.push(d);
	}
	// 23 ˫��
	d.text.clear();
	for (int k = 2; k <= 3; ++k)
	{
		if (pros[k].isVaild())
		{
			d.text += pros[k].toString("+") + " ";
		}
	}
	if (!d.text.empty())
	{
		// 4 ��ʯ
		if (pros[4].isVaild())
		{
			d.text += pros[4].toString("+") + " ";
		}
		else
		{
			d.text.pop_back();
		}
		d.color = s565::GREEN;
		descs.push(d);
	}
	else if (pros[4].isVaild())
	{
		// 89 ��ʯ
		d.text += pros[4].toString("+") + " ";
		d.color = s565::GREEN;
		descs.push(d);
	}

	eSkill ski = getSpecial(equip);
	if (ski != eSkill::eSkiNone)
	{
		// �ؼ�
		d.text = "�ؼ�: " + icons.at(eIcon::����j).at((int)ski).name;
		d.color = s565(0x80, 0x80, 0xFF);
		descs.push(d);
	}
	if (head.gad != 0 || head.easy != 0 || head.wjb != 0)
	{
		d.text = "��Ч:";
		if (head.gad)
		{
			d.text += equip.isBelt() ? " ��ŭ" : " ����";
		}
		if (head.easy)
		{
			d.text += " ���� ����";
		}
		else if (head.wjb)
		{
			d.text += " �޼�������";
		}
		d.color = s565(0x80, 0x80, 0xFF);
		descs.push(d);
	}
	d.text = getTaozhuangName(equip);
	if (!d.text.empty())
	{
		d.color = s565(0x80, 0x80, 0xFF);
		descs.push(d);
	}

	// 5....
	// d.text.clear();
	for (int i = 5; i < pros.size(); ++i)
	{
		if (pros[i].isVaild())
		{
			d.text = "��ʱ" + pros[i].toString();
			d.color = s565::GREEN;
			descs.push(d);
		}
	}
	return true;
	// ǿ������
	d.text = "������ ǿ������";
	d.color = s565::WHITE;
	descs.push(d);
	return true;
}


int cEquip::getTakeLv(const sItem& equip)
{
	sProHead head;
	head.pro = equip._head;
	if (head.wjb)
	{
		return 0;
	}
	int lv = getLv(equip);
	if (head.easy)
	{
		return lv - 5;
	}
	return lv;
}


int cEquip::getLv(const sItem& equip)
{
	auto e = equip.getType();
	int id = equip.getId();
	if (isWeapon(e))
	{
		id = txtIcon::getInstance()->getWeaponLv1ById(id);
	}
	if (isNeck(e) || isBelt(e))
	{
		id = txtIcon::getInstance()->getNeckBeltLv1ById(id);
	}
	id = id * 10;
	if (equip.isEquipBaby())
	{
		id += 5;
	}
	return id;
}


bool cEquip::getId(eIcon type, int lv, std::vector<int>& weapons)
{
	if (!isEquip(type))
	{
		return false;
	}
	weapons.clear();
	if (isEquipBaby(type))
	{
		lv = std::min(c160 / 10, (lv - 5) / 10);
		weapons.push_back(lv);
		return true;
	}

	lv /= 10;
	weapons.clear();
	if (isWeapon(type))
	{
		if (lv < 9)
		{
			weapons.push_back(lv);
			return true;
		}
		if (lv <= 11)
		{
			lv = 9 + (lv - 9);
			weapons.push_back(lv + 0);
			weapons.push_back(lv + 3);
			weapons.push_back(lv + 6);
			return true;
		}
		if (lv <= 14)
		{
			lv = 18 + (lv - 12);
			weapons.push_back(lv + 0);
			weapons.push_back(lv + 3);
			weapons.push_back(lv + 6);
			return true;
		}
		if (lv == 15)
		{
			weapons.push_back(27);
			return true;
		}
		weapons.push_back(28);
		return true;
	}

	if (type == eIcon::����x || type == eIcon::����y)
	{
		if (lv >= 3 && lv <= 8)
		{
			lv = 3 + (lv - 3) * 2;
			weapons.push_back(lv);
			weapons.push_back(lv + 1);
			return true;
		}
		if (lv > 8)
		{
			weapons.push_back(lv + 6);
			return true;
		}
	}
	weapons.push_back(lv);
	return true;
}


int cEquip::getId(eIcon type, int lv)
{
	std::vector<int> weapons;
	if (!getId(type, lv, weapons))
	{
		return c_1;
	}
	return weapons[ccc_rand(0, (int)weapons.size() - 1)];
}


int cEquip::getIdx(eIcon type)
{
	if (!isEquip(type))
	{
		return c_1;
	}
	if (isEquipBaby(type))
	{
		return (int)type - (int)eIcon::equipBaby0;
	}
	if (isHelmet(type))
	{
		return 0;
	}
	if (isNeck(type))
	{
		return 1;
	}
	if (isWeapon(type))
	{
		return 2;
	}
	if (isClothes(type))
	{
		return 3;
	}
	if (isBelt(type))
	{
		return 4;
	}
	return 5;
}


eIcon cEquip::getWeaponType(eMod master, int weaponlist_0_1)
{
	if (!txtMod::isRole(master))
	{
		ccc_box((int)master);
	}
	const auto& wlist = txtWeapon::getInstance()->getWeaponLists().at(master);
	weaponlist_0_1 = weaponlist_0_1 % wlist.size();
	return wlist.at(ccc_rand(0, weaponlist_0_1));
}


bool cEquip::setFushi(sItem& equip, const sItem& fushi)
{
	if (!equip.isValid() || !equip.isEquip() || equip.isWeapon() || (fushi.getType() != eIcon::״̬z && fushi.getType() != eIcon::׷��z))
	{
		return false;
	}
	sProHead head;
	head.pro = equip._head;
	if (fushi.getType() == eIcon::״̬z)
	{
		head.fushi = fushi.getId() + 1;
		head.zhuijia = 0;
	}
	else if (fushi.getType() == eIcon::׷��z)
	{
		head.zhuijia = fushi.getId() + 1;
		head.fushi = 0;
	}
	equip._head = head.pro;
	return true;
}


eSkill cEquip::getTaoZhuang(const sItem& equip, bool& isZhuijia)
{
	sProHead head;
	head.pro = equip._head;
	if (head.fushi == 0 && head.zhuijia == 0)
	{
		return eSkill::eSkiNone;
	}

	if (head.fushi == 0)
	{
		isZhuijia = true;
		const auto& zhuijias = txtSkill::getInstance()->getZhuijias();
		if (head.zhuijia > zhuijias.size())
		{
			return eSkill::eSkiNone;
		}
		return zhuijias.at(head.zhuijia - 1);
	}

	isZhuijia = false;
	const auto& fushis = txtSkill::getInstance()->getFushis();
	if (head.fushi > fushis.size())
	{
		return eSkill::eSkiNone;
	}
	return fushis.at(head.fushi - 1);
}


eSkill cEquip::getSpecial(const sItem& equip)
{
	sProHead head;
	head.pro = equip._head;
	if (head.special == 0)
	{
		return eSkill::eSkiNone;
	}
	return (eSkill)(head.special + (int)eSki::eSpecial0 - 1);
}


bool cEquip::isGodAngry(const sItem& item)
{
	sProHead head;
	head.pro = item._head;
	return head.gad;
}



bool cEquip::isStone(eIcon type, int _stone)
{
	eStone stone = (eStone)_stone;
	if (cEquip::isHelmet(type))
	{
		return stone == eStone::����� || stone == eStone::̫��ʯ || stone == eStone::����ʯ;
	}
	if (cEquip::isNeck(type))
	{
		return stone == eStone::������;
	}
	if (cEquip::isWeapon(type))
	{
		return stone == eStone::����� || stone == eStone::̫��ʯ || stone == eStone::����ʯ;
	}
	if (cEquip::isClothes(type))
	{
		return stone == eStone::����ʯ || stone == eStone::������ || stone == eStone::���ʯ;
	}
	if (isBelt(type))
	{
		return stone == eStone::�ڱ�ʯ || stone == eStone::��âʯ;
	}
	if (isShoe(type))
	{
		return stone == eStone::�ڱ�ʯ || stone == eStone::����ʯ;
	}

	if (type == eIcon::����h)
	{
		return stone == eStone::������ʯ_�˺� || stone == eStone::������ʯ_����;
	}
	if (type == eIcon::��Ȧx)
	{
		return stone == eStone::������ʯ_�ٶ� || stone == eStone::������ʯ_���;
	}
	if (type == eIcon::����h)
	{
		return stone == eStone::������ʯ_���� || stone == eStone::������ʯ_��Ѫ;
	}
	return false;
}


bool cEquip::setStone(sItem& equip, int stoneid)
{
	if (!isStone(equip.getType(), stoneid))
	{
		return false;
	}
	sProHead head;
	head.pro = equip._head;
	head.stone = stoneid + 1;
	equip._head = head.pro;
	return true;
}


bool cEquip::setTemp(sItem& equip, int temp)
{
	if (equip.isWeapon())
	{
		sProWeapon w;
		w.pro = equip._pro;
		w.add(temp);
		equip._pro = w.pro;
		return true;
	}
	if (equip.isArmor())
	{
		sProArmor a;
		a.pro = equip._pro;
		a.add(equip.getType(), temp);
		equip._pro = a.pro;
		return true;
	}
	return false;
}

