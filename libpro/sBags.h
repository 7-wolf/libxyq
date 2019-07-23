#pragma once
#include "sExp.h"
#include "sItem.h"

// ����
struct sBags
{
	static const int c_1 = -1;
	static sBags* getInstance();

	sExp money;
	sItems items;
	// ��ʱ�ֿ�?

	sBags();

	int find(const sItem& item);

	bool add(int money, bool onlyCheck = false);
	static int add(sItems& items, const sItem& item, bool onlyCheck = false);
	int add(const sItem& item, bool onlyCheck = false);

	void save()const;
	void load();
};