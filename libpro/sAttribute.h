#pragma once

// ��������
struct int3
{
	// ԭʼ
	int ori;
	// �ٷֱ� (����:ǿ��/ڤ˼)
	int per;
	// ���� (����: ǿ׳)
	int add;

	int3();
	operator int();
	operator const int() const;

	void reset();
	// per����
	void reset(int add);
};

// ��������
struct sAttribute
{
	// ��Ѫ����
	int3 hpMax;
	// ħ������
	int3 mpMax;

	// ��� ����
	int3 hit;
	// ��� �˺�
	int3 atk;
	// ��� ����
	int3 def;
	// ��� ����
	int3 mana;
	// ��� �ٶ�
	int3 speed;
	// ��� ���
	int3 evade;

	sAttribute();

	void reset();

	// 	bool correct(bool correcthp);
// 
// 	bool fillhpmp();
// 
// 	int addhp(int h, int per = 0);
// 
// 	bool addhp2(int h, int per = 0);
// 
// 	int addhphp2(int h, int h2);
// 
// 	bool addmp(int m, int per = 0);
// 
// 	bool addap(int a, int per = 0);
// 
// 	int relife(int h, int per = 0);
// 
// 	int relife2(int h, int h2, int per = 0, int per2 = 0);


	static const int cHp100 = 100, cMp80 = 80, cAp150 = 150, cHit40 = 40;
};


