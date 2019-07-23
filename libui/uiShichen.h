#pragma once
#include "_inc.h"

// ʱ��,���Ͻ�
class uiShichen : public cNode
{
public:
	CREATE_FUNC(uiShichen);
	virtual bool init();

	// ��ͼ��
	void setMapName(const std::string& mapname);
	// ����λ��
	void setHeroXY(int x, int y);

	void updateShichen(float delta);

	void setBattle(bool battle);

	cSprite* getSpriteDay() { return _spriteDay; }

protected:
	// ���� ʱ��
	cSprite* _spriteShichen = nullptr;

	// ���� ��ҹ
	cSprite* _spriteDay = nullptr;
	cSprite* _spriteNight = nullptr;
	// ��ǩ ��ǰ��ͼ
	cLabel* _labelMap = nullptr;

	// ��ǩ ����xy
	cLabel* _labelxy = nullptr;

	// ������ť С��ͼ
	cButton* _buttonSmall = nullptr;

	// ������ť ���ͼ
	cButton* _buttonBig = nullptr;
};