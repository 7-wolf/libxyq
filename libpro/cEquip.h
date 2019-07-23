#pragma once
#include "sItem.h"

class cEquip
{
public:
	typedef txtStone::sStone sProperty;
	typedef std::vector<sProperty> sPropertys;

	// ����/����/����װ��
	static bool isEquip(eIcon type);
	// ����
	static bool isWeapon(eIcon type);
	// ����
	static bool isArmor(eIcon type);
	// ����װ��
	static bool isEquipBaby(eIcon type);
	// ͷ��/����
	static bool isHelmet(eIcon type);
	// ����
	static bool isNeck(eIcon type);
	// ����/��ȹ
	static bool isClothes(eIcon type);
	// ����
	static bool isBelt(eIcon type);
	// Ь��
	static bool isShoe(eIcon type);
	// ������� �ؼ���Ч/�������� ˫�� ָ��
	static bool fill(sItem& equip, bool effect_or_ex3, bool add2, int eMin, int eMax);

	static bool apply(const sItem& equip, sPropertys& pros);
	static bool apply(const sItem& equip, sDescs& descs);
	// Я���ȼ�
	static int getTakeLv(const sItem& equip);
	// װ���ȼ�
	static int getLv(const sItem& equip);
	// ȡװ��id(����װ���ȼ�)
	static bool getId(eIcon type, int lv, std::vector<int>& weapons);
	// ȡװ��id(�п������)
	static int getId(eIcon type, int lv);
	// ȡװ��������
	static int getIdx(eIcon type);
	// ȡ��������(���ݽ�ɫ)
	static eIcon getWeaponType(eMod master, int weaponlist_0_1);
	// �ܷ�װ��(��ɫ, װ������)
	static bool isEquip(eMod master, eIcon type);
	// ����װ
	static bool setFushi(sItem& equip, const sItem& fushi);
	// ȡ��װ
	static eSkill getTaoZhuang(const sItem& equip, bool& isZhuijia);
	// ȡ��װ
	static eSkill getZhuijia(const sItem& equip);
	// ȡ�ؼ�
	static eSkill getSpecial(const sItem& equip);
	// ����/��ŭ
	static bool isGodAngry(const sItem& equip);
	// �ܷ���Ƕ(װ������,��ʯid)
	static bool isStone(eIcon type, int stone);
	// ��Ƕ
	static bool setStone(sItem& equip, int stoneid);
	// ǿ��ʯ ��ʱ����
	static bool setTemp(sItem& equip, int temp);

	static const int c_1 = -1, c3 = 3, c6 = 6, c160 = 160;
};