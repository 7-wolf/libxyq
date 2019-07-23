#pragma once
#include "_inc.h"

// ��Ʒ
class sItem
{
public:
	// ����
	bool setIcon(eIcon type, int id);
	// ͼ������
	const txtIcon::sIcon* getIcon()const{ return _icon; }
	// ����(�ؼ���Ч,˫��,ָ������0��ָ������100)
	bool setData(bool effect_ex3, bool add2, int eMin, int eMax);
	// ����(��ͼ/������ר��)
	bool setData(const std::string& mapname, int x, int y);
	// ����
	eIcon getType()const{ return _type; }
	// id
	int getId()const{ return _id; }
	// �۸�
	void setPrice(int price){ _price = price; }
	// �۸�
	int getPrice()const{ return _price; }
	// ��
	bool add(int count = 1);
	// ��
	bool sub(int count = 1);
	// ���
	void clear(){ _num = 0; }
	// ��Ч
	bool isValid()const;
	// ����
	int getCount()const{ return _num; }
	// ����
	void toDesc(sDescs& descs)const;
	// ���ص�����
	bool is��ͼor����(bool checkValid = true)const;
	// ����Ʒ
	bool isConsumables(bool checkValid = true) const;
	// �ɵ���
	bool isOverly(bool checkValid = true) const;
	// ������Ʒ
	bool isPetOnly(bool checkValid = true) const;
	// ����/����/����װ��
	bool isEquip(bool checkValid = true)const;
	// ����
	bool isWeapon(bool checkValid = true)const;
	// ����
	bool isArmor(bool checkValid = true)const;
	// ����װ��
	bool isEquipBaby(bool checkValid = true)const;
	// ͷ��/����
	bool isHelmet(bool checkValid = true)const;
	// ����
	bool isNeck(bool checkValid = true)const;
	// ����/��ȹ
	bool isClothes(bool checkValid = true)const;
	// ����
	bool isBelt(bool checkValid = true)const;
	// Ь��
	bool isShoe(bool checkValid = true)const;
	// �л�����(��������ģ����)
	bool switchWeapon(eMod master);
	// �л�����(��������ģ����)
	bool switchArmor(bool boy);
	// �浵
	void save()const;
	// ����
	void load();
	// �Ա�
	bool operator!=(const sItem& it)const;
	bool operator==(const sItem& it)const;
private:
	eIcon _type;
	int _id;
	int _num = 0;
	int _price = 0;
	std::string _str;
	uint _head;
	u64 _pro;
	const txtIcon::sIcon* _icon = nullptr;
	friend class cEquip;
	friend struct sBags;
public:
	static const int c20 = 20, c60 = 60;
};
typedef std::vector<sItem> sItems;