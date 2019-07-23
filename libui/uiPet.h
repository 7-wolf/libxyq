#pragma once
#include "uiSee.h"

// ���� 
class uiPet : public uiPad, public uiProperty //, public uiZz::uiNotice
{
public:
	~uiPet();
	CREATE_FUNC(uiPet);

protected:
	bool init();

public:
	void load(sRole& role);
	// ����(������)
	void load(const sPets& pets, int lv, int fightid);
	// ˢ��ĳ������
	void load(int index, const sProperty& pro);
	// ����(��������)
	void load(int index);
	// ����/Ⱦɫ��
	void load(int index, const sSps& stands, ulong uhead = cSp::c0);

	void remove(int index);

	// ��������(����)
	void loadZz(int index);

	void doFight();

	void loadPage();

protected:
	int _lv, _fightid = -1;
	sPets _pets;
	std::vector<cSprite*> _bodies;
	Vec2 _vShadow;

	// �б�
	uiGrids* _grids = nullptr;

	// ��ս
	cButton* _buttonFight = nullptr;
	// �鿴����
	cButton* _buttonSkill = nullptr;
	// ����
	cButton* _buttonJinjie = nullptr;
	// Ⱦɫ
	cButton* _buttonColor = nullptr;
	// ����
	cButton* _buttonFree = nullptr;
	// ����
	cButton* _buttonChangeName = nullptr;

	// Я���ȼ�
	cLabel* _labelTakelv = nullptr;
	cLabel* _labelPage = nullptr;

	// ����
	uiZz* _zz = nullptr;
	// �ֿ�

	// ����

public:
	enum class eOperator { fight, jinjie, free, store, color };
	std::function<bool(eOperator, int, const sProperty&)> onOperate = nullptr;
};