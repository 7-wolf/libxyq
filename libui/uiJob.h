#pragma once
#include "_inc.h"

// ����
class uiJob : public cNode
{
public:
	CREATE_FUNC(uiJob);
	virtual bool init();

	// �������(����, ����)
	// �ظ��ı���ᱻ��Ϊ��������
	bool add(const std::string& title, const std::string& text);
	// �Ƴ�����(����, ����)
	bool remove(const std::string& title);

	void updateList();

	cButton* _btnEx = nullptr;
	cButton* _btnLeft = nullptr;
	std::vector<cButton*> _buttonTitles;
	std::vector<cText*> _texts;
	bool _isShow = true;
	bool _isLeft = true;
};