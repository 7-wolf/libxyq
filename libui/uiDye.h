#pragma once
#include "uiPad.h"

// ��ɫ�� Ⱦɫ
class uiDye : public uiPad
{
public:
	CREATE_FUNC(uiDye);
	virtual bool init();
	void doBind();
protected:
	bool _randModel = false;

	// ��ʾ�ľ���
	cSprite* _sprite = nullptr;
	// �л� ����/��� ģʽ
	cButton* _buttonMod = nullptr;
	// ��λ
	cButton* _buttonPart = nullptr;
	// �ֶ�
	std::array<cButton*, 4> _button4s;
	// ��ת
	cButton* _buttonLeft = nullptr;
	// ��ת
	cButton* _buttonRight = nullptr;
	// ���õ�ɫ��
	cButton* _buttonZero = nullptr;
	// ȷ��
	cButton* _bottonOk = nullptr;
};
