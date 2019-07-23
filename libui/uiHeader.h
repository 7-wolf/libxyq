#pragma once
#include "_inc.h"

// ͷ��ť Ѫ�� ���� ��ŭ ����
class uiHeader : public cNode
{
public:
	static uiHeader* create(bool pet){ CREATE(uiHeader, pet); }

	bool init(bool pet);

	void load(const sProperty& pro, int hpMax, int mpMax);
	void load(ulong head);
	void load(const sProperty& pro);

protected:
	bool _isPet;

	// ͷ����
	cSprite* _spriteHead = nullptr;
	// Ѫ������(֧�ֲü�)
	cSprite* _spriteHp = nullptr;
	cSprite* _spriteHp2 = nullptr;
	cSprite* _spriteMp = nullptr;
	cSprite* _spriteAp = nullptr;
	cSprite* _spriteExp = nullptr;

	Size _sizeBar;

public:
	static const int c32 = 32;
};