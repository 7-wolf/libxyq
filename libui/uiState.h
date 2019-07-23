#pragma once
#include "uiSee.h"

// ����״̬
class uiState : public uiPad, public uiProperty
{
public:
	CREATE_FUNC(uiState);

protected:
	virtual bool init();

public:
	// ����(��������)
	void load(sRole& role);

protected:
	sRole _role;

	// ��ν
	cLabel* _labelAppellation = nullptr;
	// ����
	cLabel* _labelMenpai = nullptr;
	// ����
	cLabel* _labelBangpai = nullptr;

	// ���＼��
	cButton* _buttonSkill = nullptr;

	// ����
	cButton* _buttonLvup = nullptr;

public:
	std::function<void()> onLvup = nullptr, onSki = nullptr;
};