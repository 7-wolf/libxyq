#pragma once
#include "uiGrids.h"
#include "uiPad.h"

// ����(������)
class uiPropertyZz
{
protected:
	// ��ʼ��(���ڵ�, ����¼�, λ��)
	virtual bool init(Node* parent, int px, int py, int iy, int px2, int py2);

public:
	// ����(����, ����)
	virtual void load(const sProperty& pro);

	// ����(����)
	virtual void load(const sZz& zz);

protected:
	// ����
	uiGrids* _grids = nullptr;

	std::vector<cSprite*> _equips;

//	int _skix, _skiy;
//	int _page = 0;

	// ���ܷ�ҳ
	cButton* _buttonPage = nullptr;

	// ����
	cLabel* _labelAtk = nullptr;
	// ����
	cLabel* _labelDef = nullptr;
	// ����
	cLabel* _labelHp = nullptr;
	// ����
	cLabel* _labelMp = nullptr;
	// �ٶ�
	cLabel* _labelSpeed = nullptr;
	// ��� 
	cLabel* _labelEvade = nullptr;
	// ����
	cLabel* _labelLife = nullptr;
	// �ɳ�
	cLabel* _labelGrow = nullptr;
	// ����
	cLabel* _label5xing = nullptr;
};


// ����
class uiZz : public uiPad, public uiPropertyZz
{
public:
	class uiNotice
	{
	public:
		virtual void doNotify() { _zz = nullptr; }
	protected:
		uiZz* _zz = nullptr;
	};
	~uiZz();
	static uiZz* create(uiNotice* notice) { CREATE(uiZz, notice) }

protected:
	bool init(uiNotice* notice);

public:
	uiNotice* _notice = nullptr;
};