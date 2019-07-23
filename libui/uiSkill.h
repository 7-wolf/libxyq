#pragma once
#include "uiPad.h"

// ���＼��
class uiSkill : public uiPad
{
public:
	CREATE_FUNC(uiSkill);
	bool init();
	// ����(��������)
	void load(sRole& role);
	void doHide();
	void showMain(int k);
	cSprite* createSprite(ulong uid, const std::string& desc, const std::function<void()>& onClickEx = nullptr);
	Node* createMain(int tag);
	Node* createSpecial();
	void loadXL(int select);
	void learnXL(bool isbb, int select4);

	void showXLbutton(bool show);
	void doClose();

	sRole _role;
	sXl _xlOri, _xlbbOri;
	u64 _moneyOri;

	// �����������صĽڵ�
	Node* _nodeMain = nullptr;
	cButton* _buttonMain = nullptr;
	// ��Ÿ�����صĽڵ�
	Node* _nodeFuzhu = nullptr;
	cButton* _buttonFuzu = nullptr;
	// ���������صĽڵ�
	Node* _nodeXl = nullptr;
	cButton* _buttonXl = nullptr;
	// �澭����
	cButton* _buttonQj8m = nullptr;
	// ����
	cText* _textDesc = nullptr;

// 	// ����ѡ��
	cSprite* _spriteXLselece = nullptr;
	cSprite* _spriteSelect = nullptr;

	bool _isLearned = false;
	int _xiulianSelect = -1;
	cButton* _buttonLearnXl = nullptr;

public:
	// Ǯ��
	std::function<void(const sXl&, const sXl&, u64)> onXL = nullptr;
	// 
	std::function<void()> onQj8m = nullptr;
};