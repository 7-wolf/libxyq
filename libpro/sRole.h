#pragma once
#include "sProperty.h"
#include "sSki.h"

typedef std::vector<sProperty> sPets;
// ��������
struct sRole : public sProperty
{
	static const int cFight_1 = -1;
	// ʦ�ż��ܵȼ�
	int skilv = sSki::cGap;
	// ������
	sXl xlbb;
	// ��ݼ�
	sSkis acces;
	// ������
	sItems fabaos;
	// ������
	sPets pets;
	// ��ս����
	int fight = cFight_1;
	int teamIdx;

	sRole();
	// ���ܵȼ�
	int getSkiLv() const { return skilv; }
	// ����
	bool lvdown(bool onlyCheck);

	void unPet();
	bool isPeting();
	const sProperty& getPet() const;
	sProperty& getPet();
	bool setPet(int fight, bool onlyCheck);

	void doMod();
	std::function<void(const sMod&)> onMod = nullptr;

	void save()const;
	void load();
};