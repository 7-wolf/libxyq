#pragma once
#include <array>


// ����������,�浵���Լ��ض�
struct sXl
{
	static const int c4 = 4;
	std::array<int, c4> lvs;

	sXl();

	void reset();
	// ����
	bool lvup(int idx);
	// ����, �˻�����
	bool lvdown(int idx, bool onlyCheck);
	// 
	void set(int atk, int def, int mag, int dmag);
		
	void set(int a, int d);

	void set(int v);

	void setA(int a);
	void setA(int atk, int mag);

	void setD(int d);
	void setD(int def, int dmag);

	void save()const;
	void load();

	static int getExp(int lv);
	// ȡ��ǰ����ȼ�����������
	static int getLv(int lv);
	static const int c25 = 25, c2000 = 2000;
};

