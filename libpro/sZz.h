#pragma once
#include "_inc.h"

struct sZz
{
	// ���� ����/����/�ٶ�/���� 
	static const int c1680 = 1680;
	// ���� ��������
	static const int c6880 = 6880;
	// ���� ��������
	static const int c3680 = 3680;
	// ���� �ɳ�
	static const int c130 = 130;
	// ��������
	int atk;
	// ��������
	int def;
	// ��������
	int hp;
	// ��������
	int mag;
	// �ٶ�����
	int speed;
	// ��������
	int evoid;
	// �ɳ�
	int grow100;

	sZz();

	void reset();

	bool isValid();

	void correct();


	void operator=(const txtZz::sZz& zz);

	void save()const;
	void load();
};


