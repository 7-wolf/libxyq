#pragma once
#include "uiPad.h"
#include "uiGrids.h"

// ����/��Ƕ/�ֽ�
class uiDazao : public uiPad
{
public:
	CREATE_FUNC(uiDazao);
	virtual bool init();
	// ����
	void dazao(cSprite* button);
	// ��Ƕ
	void xiangqian(cSprite* button);
	// �ֽ�
	void fenjie(cSprite* button);

	std::array<cSprite*, 2> _buttonHeads;

	uiGrids* _grids = nullptr;
};