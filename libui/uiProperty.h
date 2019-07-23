#pragma once
#include "uiPad.h"

// ���Խ���(����ͱ������е�)
class uiProperty
{
public:
	uiProperty();

protected:
	virtual bool init(Node* parent, int px, int py, int px2, int iy);

public:
	virtual void load(const sProperty& pro);

	// ����(����)
	virtual void load();

	virtual void updatePoint();
protected:
	sProperty _pro;
	sPropertys _pros;
	bool _isPointed = false;
	sPoint _pointShow;
	std::array<int*, 5> _points;

	// ��ť �Ӽ���
	std::array<cButton*, 5> _buttonAdds;
	std::array<cButton*, 5> _buttonSubs;
	// ��ť ȷ���ӵ�
	cButton* _buttonSure = nullptr;

	// �ȼ�
	cLabel* _labelLv = nullptr;
	// ����
	cLabel* _labelName = nullptr;
	// ��Ѫ
	cLabel* _labelHp = nullptr;
	// ħ��
	cLabel* _labelMp = nullptr;
	// ��ŭ
	cLabel* _labelAp = nullptr;

	// ����
	cLabel* _labelHit = nullptr;
	// ����
	cLabel* _labelAtk = nullptr;
	// ����
	cLabel* _labelDef = nullptr;
	// �ٶ�
	cLabel* _labelSpeed = nullptr;
	// ����
	cLabel* _labelMana = nullptr;
	// ��� 
	cLabel* _labelEvade = nullptr;

	// ���Ե� ����
	cLabel* _labelBody = nullptr;
	// ���Ե� ħ��
	cLabel* _labelMag = nullptr;
	// ���Ե� ����
	cLabel* _labelStr = nullptr;
	// ���Ե� ����
	cLabel* _labelDex = nullptr;
	// ���Ե� ����
	cLabel* _labelAgi = nullptr;
	// ���Ե� ʣ��
	cLabel* _labelRemian = nullptr;

	// ����
	cLabel* _labelExp = nullptr;
	cLabel* _labelExpMax = nullptr;

public:
	// ����ѡ������
	std::function<void(int, const sPoint&)> onPoint;
};