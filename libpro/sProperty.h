#pragma once
#include "sMod.h"
#include "sPoint.h"
#include "sXl.h"
#include "sItem.h"
#include "sSki.h"
#include "sZz.h"
#include "sExp.h"

// ������
struct sProperty
{
	// �Ƿ񱦱�
	bool ispet;
	// ģ��
	sMod mod;
	// ����
	eMenpai menpai = eMenpai::None;
	// ����
	std::string name;
	// �������ܵȼ�
	std::vector<int> fuzhus;
	// �ȼ�
	int lv = 0;
	// ��Ѫ
	int hp;
	// ��
	int hp2;
	// ħ��
	int mp;
	// ��ŭ
	int ap = 0;
	// ���Ե�
	sPoint point;
	// ����
	sXl xl;
	// ����
	sSkis skis;
	// װ��
	sItems equips;
	// ����
	sExp exp;
	// ����
	sZz zz;

	// ����
	sProperty();
	sProperty(bool ispet);

	void reset(bool ispet);
	// �жϼ���
	virtual bool isSki(eSkill e);
	// ���ܵȼ�
	virtual int getSkiLv() const { return lv; }
	// ����
	virtual bool lvup(bool onlyCheck);
	// ����
	virtual bool lvdown(bool onlyCheck);

	// ����ר��
	bool load(eMod e, bool rename, bool zz, bool skis);
	txtZz::eAp getAp() const;
	int getTakeLv() const;
	void applyWeapon();

	// ��������
	virtual void save()const;
	virtual void load();
};