#pragma once
#include "cEquip.h"
#include "sPropertyInfo.h"
#include "sAttribute.h"
#include "sProperty.h"
#include "sRole.h"

namespace ccp
{
	struct sTz { eSki ski; int rate = 0, lvGap; };
}
struct sPropertys
{
	sPropertyInfo info;
	sAttribute attr;
	sPoint point;
	ccp::sTz taozhuang;
	seSkis specials;
};
// ���Լ���
namespace ccp
{
	static const int cFF = 0xFF;
	// ������� 
	void apply(sAttribute& attr, int skilv);
	void apply(sAttribute& attr, int fzlv, int fzIdx);
	void apply(sAttribute& attr, const sPoint& point);
	void apply(sAttribute& attr, const sPoint& point, const sZz& zz, int lv);
	// ��������
	std::string apply(sPropertyInfo& info, int3& speed, eMenpai menpai, int rlv = -1);
	void apply(sPropertyInfo& info, const sXl& xl);
	void apply(sPropertyInfo& info, int3& speed, int fabao);
	// װ��
	void apply(sPropertyInfo& info, sAttribute& attr, sPoint& point, const cEquip::sPropertys& pros);
	void apply(sPropertyInfo& info, sAttribute& attr, sPoint& point, sTz& taozhuang, seSkis& specials, const sItems& equips);
	// ��������
	void apply(sPropertyInfo& info, sAttribute& attr, eSki ski, int lv);
	void apply(sPropertyInfo& info, sAttribute& attr, const sPoint& point, const seSkis& skis, int lv);
	// ������
	void apply(sPropertys& pros, const sProperty* pro);
	void apply(sPropertys& pros, const sProperty& pro);
	// ����
	void fillHpMp(sProperty& pro);
	// ����
	bool lvup(sProperty& pro, bool onlyCheck);
	// ����
	bool lvdown(sProperty& pro, bool onlyCheck);
	bool lvdown(sRole& role);
	// ���ɼ���
	bool addSki(sSkis& skis, eMenpai e, bool normal);
	// ��Ӽ���(�ظ��ļ��ܻᱻ����)
	bool addSki(sSkis& skis, sSki ski, int idx = -1);
	// װ�����˺�
	int getEquipsAtk(const sItems& equips);

	std::string getMenpaiName(eMenpai menpai);

	bool useItem(const sItem& item, sRole& role);
	bool useItem(const sItem& item, sProperty& pet);
};