#pragma once
#include "_inc.h"

// Buff
struct sBuff
{
	eSki ski;
	int time;
	int skilv;
//	int user;
//	int target;
};

// ����
struct sSki
{
	// ����(����)
	bool setData(eSki e);
	// ����
	const txtSkill::sSkill* getData()const{ return _data; }
	// ͼ������
	const txtIcon::sIcon* getIcon()const{ return _icon; }
	// ���ܱ��
	eSki getSki()const { return _e; }
	// ����
	bool toDescs(sDescs& descs)const;
	// ��Ч
	bool isValid()const;
	// ����
	bool isEd()const;
	// ���ɼ���
	bool isMenpai()const;
	// ��ʦ�ż���(ˮ��֮���)
	bool isF1()const;
	// ��������
	bool isPet()const;
	// �ؼ�
	bool isSpecial()const;
	// �ȼ�
	int getLv()const { return _lv; }
	void setLv(int lv) { _lv = lv; }
	// �뼸
	int getTargetsMax()const{ return _targetsMax; }

	static const int cGap = 10;
	static const int c180 = 180;
	static const int c160 = 160;

	// ѧϰ����
	static int getExp(int lv);
	// ѧϰ��Ǯ
	static int getMoney(int lv);
private:
	int _lv = cGap;
	int _targetsMax;
	eSki _e = eSki::eSkiNone;
	const txtIcon::sIcon* _icon = nullptr;
	const txtSkill::sSkill* _data = nullptr;
};

typedef std::vector<eSki> seSkis;
typedef std::vector<sSki> sSkis;