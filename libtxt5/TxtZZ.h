#pragma once
#include "eModel.h"

namespace ctt
{
	string getName(eModel e);

	struct sPetZZ
	{
		// 0 ����Ҫ�� 1�� 2�� 3�������
		int ap;
		int lv;
		int atk;
		int def;
		int hp;
		int mp;
		int spd;
		int evo;
		int gro;
		vector<int> skills;
	};

	const map<eModel, sPetZZ>& getPetZZs();
}


