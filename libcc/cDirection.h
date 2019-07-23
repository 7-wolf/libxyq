#pragma once
#include "Vec2.h"

// �˷���
namespace eDirection
{
	// Right Down 
	static const int RD = 0;
	// Left Down 
	static const int LD = 1;
	// Left Up 
	static const int LU = 2;
	// Right Up 
	static const int RU = 3;
	// Down 
	static const int D = 4;
	// Left
	static const int L = 5;
	// Up
	static const int U = 6;
	// Right
	static const int R = 7;
};


class cDirection
{
public:
	static int getDirection4(int direction8);
	static int getDirection4(const Vec2& v);
	static int getDirection8(int pred, const  Vec2& v);
	// ȡ��(����)����(����ս��ʱ��,վ����)
	static int getDirectionR(int direction);
	// ȡ��һ������(˳ʱ��/��ʱ��)
	static int getDirectionRound8(int directionLast, bool isNextOrPre);
	// ȡ��һ������(˳ʱ��/��ʱ��)
	static int getDirectionRound4(int directionLast, bool isNextOrPre);
};