#include "uiDye.h"
#include "uiManager.h"

bool uiDye::init()
{
	if (!uiPad::init(ccu::uPad, true)) // 0x61E6DAFE
	{
		return false;
	}
	set9(true, 32, 32);
	setContentSize(540, 359);
	setAilgn(eAilgn::Mid);
	

	_randModel = false;
	// �л� ����/��� ģʽ
	this->addChild(_buttonMod = cButton::create4("Ⱦɫģʽ"));
	_buttonMod->setDesc("���ģʽ���޷�����");
 	_buttonMod->setPosition(_contentSize.width / 2 - _buttonMod->getContentSize().width / 2, 2);
	_buttonMod->onClick = [this]()
	{
		_randModel = !_randModel;
		_buttonMod->setString(_randModel ? "���ģʽ" : "Ⱦɫģʽ");
		if (_randModel)
		{
			forr(_button4s, k)
			{
				_button4s[k]->setString("��");
			}
		}
		else
		{
			forr(_button4s, k)
			{
				_button4s[k]->setString("");
			}
		}
	};

	int y = 265, y2 = 295;

	// ��ת
	this->addChild(_buttonLeft = cButton::create1("<-"));
	_buttonLeft->setPosition(175, y);
	_buttonLeft->onClick = [this]()
	{
		_sprite->setDirection(false);
	};
	// ��ת
	this->addChild(_buttonRight = cButton::create1("->"));
	_buttonRight->setPosition(330, y);
	_buttonRight->onClick = [this]()
	{
		_sprite->setDirection(true);
	};

	// ��λ
	this->addChild(_buttonPart = cButton::create4("�л���λ"));
	_buttonPart->setPosition(160, y2);
	_buttonPart->onClick = [this]()
	{
		cDyeRender::getInstance()->swtichPart();
	};

	// ȷ��
	this->addChild(_bottonOk = cButton::create2("ȷ��"));
	_bottonOk->setPosition(240, y2);
	_bottonOk->onClick = [this]()
	{
		cDyeRender::getInstance()->apply();
		doClose();
	};
	// ����
	this->addChild(_buttonZero = cButton::create4("���õ�ǰ"));
	_buttonZero->setPosition(290, y2);
	_buttonZero->onClick = [this]()
	{
		cDyeRender::getInstance()->resetPart();
	};
	// �ֶ�
	cButton* button;
	forr(_button4s, k)
	{
		this->addChild(button = _button4s[k] = cButton::create1());
		button->setPosition(205 + k * 32, y);
		button->setTag(k);
		button->onClick = [this, button]()
		{
			if (_randModel)
			{
				cDyeRender::getInstance()->randMatrix(button->getTag());
			}
			else
			{
				cDyeRender::getInstance()->addMatrix(button->getTag());
			}
		};
	}

	cSprite* spriteShadow = cSprite::create(ccu::uShadow);
	this->addChild(spriteShadow);
	spriteShadow->setPosition(260, 220);

	this->addChild(_sprite = cSprite::create());
	_sprite->setPosition(spriteShadow->getPosition());
	_sprite->play();

	return true;
}

void uiDye::doBind()
{
	cDyeRender::getInstance()->onLoad = [this](const sSp& sp, const std::vector<cDyeRender::sShow>& shows)
	{
		forr(_button4s, k)
		{
			if (k < shows.size())
			{
				_button4s[k]->setVisible(true);
				_button4s[k]->setString(toString("%d/%d", shows.at(k).idx, shows.at(k).total));
			}
			else
			{
				_button4s[k]->setVisible(false);
			}

		}
		_sprite->load(sp);
	};
}
