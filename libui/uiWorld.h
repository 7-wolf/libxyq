#pragma once
#include "uiPad.h"

// �����ͼ
class uiWorld : public uiPad
{
public:
	CREATE_FUNC(uiWorld);
	virtual bool init();
	virtual void doClose();

protected:
	void doHide();

	// ����
	Node* _nodeWorld = nullptr;
	// ��
	Node* _nodeEast = nullptr;

	// ��
	Node* _nodeWest = nullptr;

	// ��
	Node* _nodeSouth = nullptr;

	// ��
	Node* _nodeNorth = nullptr;

public:
	std::function<void(const std::string&, int, int)> onSelect = nullptr;
};