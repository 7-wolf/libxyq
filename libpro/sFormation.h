#pragma once
#include "sAttribute.h"
#include "sPropertyInfo.h"

enum eFormation
{
	normal,//��ͨ��
	land, //������
	wind,//������
	tiger,//������
	dragon,//������
	bird,//������
	snake,//�����
	sky,//�츲��
	cloud,//�ƴ���
	thunder,//�׾���
	eagle//ӥХ��
};
// ����
struct sFormation
{
	static const int c5 = 5;
	std::array<int, c5> xs;
	std::array<int, c5> ys;
	eFormation e;

	sFormation();
	sFormation(eFormation e);

	// Ч��
	std::string apply(int idx, sPropertyInfo* info, int3* speed);
	// λ��(λ��0-4,�Ƿ񱦱�,�Ƿ��վλ, ����x, ����y)
	bool apply(int idx, bool pet, bool enemy, int& x, int& y);

};