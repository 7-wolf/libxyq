#include "cExpansion.h"

#include "expChat.h"
#include "expIcon.h"
#include "expMenpai.h"
#include "expNpc.h"
#include "expPet.h"
#include "expRole.h"
#include "expSkill.h"
#include "expXiangrui.h"
#include "expZuoqi.h"
#include "expZz.h"


static std::vector<std::string> s_stocks;
bool expStock::init()
{
	if (!expEasy::init())
	{
		return false;
	}
	if (s_stocks.empty())
	{
		cWdf wdf;
		wdf.loadRoot(cFolder::getInstance()->getWd() + "stock.wdf");
		std::vector<std::string> strs;
		for (int k = 0, length = wdf.getIndexsCount(); k < length; ++k)
		{
			auto ptr = wdf.getData(wdf.getIndexs() + k);
			if (strlen(ptr) < 32)
			{
				delete ptr;
				continue;
			}
			cc::split(ptr, "N P", strs);
			delete ptr;
			for (auto s : strs)
			{
				s = cc::replace(s, "\r\n", "");
				s = cc::replace(s, "\n", "");
				s = cc::replace(s, "\t", "");
				if (s.empty())
				{
					continue;
				}
				s_stocks.push_back(s);
			}
		}
	}
	for (int k = 0; k < s_stocks.size(); k += 10)
	{
		initButton(cc::toString(k / 10));
	}
	initButton();
	return expEasy::init(initDrag(0));
}

cNode* expStock::initDrag(int tag, int tag2 /*= cTagNone*/)
{
	cNode* node = cNode::create();
	int x = _btnw + 40,y = 20, iy = 20;
	for (int k = tag * 10; k < (tag + 1) * 10 && k < s_stocks.size(); ++k)
	{
		cLabel* lable = cLabel::create(toString("%d.", k + 1));
		lable->setColor(s565::GREEN);
		lable->setPosition(x - lable->getContentSize().width, y);
		node->addChild(lable);
		cText* text = cText::create(cc::vsSize().width - x - iy);
		text->setString(s_stocks[k]);
		text->setPosition(x, y);
		node->addChild(text);
		y += text->getContentSize().height + iy;
	}
	node->setContentSize(cc::vsSize().width, y += iy);
	return node;
}

static std::vector<std::string> s_talks;
bool expTalk::init()
{
	if (!expEasy::init())
	{
		return false;
	}
	if (s_talks.empty())
	{
		cWdf wdf;
		wdf.loadRoot(cFolder::getInstance()->getWd() + "talk.wdf");
		std::vector<std::string> strs;
		for (int k = 0, length = wdf.getIndexsCount(); k < length; ++k)
		{
			auto ptr = wdf.getData(wdf.getIndexs() + k);
			if (strlen(ptr) < 32)
			{
				delete ptr;
				continue;
			}
			cc::split(ptr, "N P", strs);
			delete ptr;
			for (auto s : strs)
			{
				s = cc::replace(s, "\r\n", "");
				s = cc::replace(s, "\n", "");
				if (s.empty())
				{
					continue;
				}
				s_talks.push_back(s);
			}
		}
	}

	for (int k = 0; k < s_talks.size(); k += 100)
	{
		initButton(cc::toString(k / 100));
	}
	initButton();
	return expEasy::init(initDrag(0));
}

cNode* expTalk::initDrag(int tag, int tag2 /*= cTagNone*/)
{
	cNode* node = cNode::create();
	int x = _btnw + 60, y = 20, iy = 20;
	for(int k = tag * 100; k < (tag + 1) * 100 && k < s_talks.size(); ++k)
	{
		cLabel* lable = cLabel::create(toString("%d.", k + 1));
		lable->setColor(s565::GREEN);
		lable->setPosition(x - lable->getContentSize().width, y);
		node->addChild(lable);
		cText* text = cText::create(cc::vsSize().width - x - iy);
		text->setString(s_talks[k]);
		text->setPosition(x, y);
		node->addChild(text);
		y += text->getContentSize().height + iy;
	}
	node->setContentSize(cc::vsSize().width, y += iy);
	return node;
}


bool cExp::init()
{
	if (!expEasy::init())
	{
		return false;
	}
	return expEasy::init(initDrag(0));
}

cNode* cExp::initDrag(int tag, int tag2 /*= cTagNone*/)
{
	cNode* node = cNode::create();
	cLabel* lable = cLabel::create("QȺ:");
	lable->setPosition(20, 20);
	node->addChild(lable);
	return node;
}



const int cExpansion::cy = 20;
const int cExpansion::cx = 20;
bool cExpansion::init()
{
	if (!Scene::init())
	{
		return false;
	}

	_y = 20;
	_director = Director::getInstance();

	onButton("�����", expChat::create);
	const auto& txt = txtEasy::getInstance();
	onButtonEasy("������", txt->getTransmits());
	onButtonEasy("�ӳ�����", txt->getTops());
	onButtonEasy("�㼣", txt->getDazzles());
	onButtonEasy("��צӡ", txt->getFoots());
	onRank();
	onButtonEasy("����Ԥ��", txt->getMagicWhat());
	onButtonEasy("_magic", txt->get_magic());
	onButtonEasy("magic", txt->getMagic());
	onButtonEasy("����", txt->getMagicImpact());
	onButtonEasy("״̬", txt->getMagicState());
	onButtonEasy("δ֪״̬", txt->getMagicStateUnkown());
	onButtonEasy("����", txt->getMagicIter());
	onButtonEasy("δ֪", txt->getMagicUnkown());
	onRank();
	onButton("��Ʒ", expIcon::create);
	onButton("����", expIconWeapon::create);
	onButton("װ��", expIconEquip::create);
	onButton("����", expMenpai::create);
	onButton("����", expSkill::create);
	onRank();
	onButton("��������", expZz::create);
	onButton("Ψ��ͷ��", expZz::createWm);
	onButton("����", expPet::create);
	onButton("��ɫ", expRole::create);
	onRank();
	onButton("NPC", expNpc::create);
	onButton("����", expZuoqi::create);
	onButton("(Ψ��)", expZuoqi::createWm);
	onButton("����", expXiangrui::create);
	onRank();

	onButton("�Ի�", expTalk::create);
	onButton("����", expStock::create);
	onButton("�Ǳ�", cExp::create)->setDesc("�汾: v20190520");
	onRank();

	return true;
}

cButton* cExpansion::onButton(const std::string& name, const std::function<Scene*()>& onScene)
{
	cButton* button = cButton::create4(name);
	_buttons.push_back(button);
	button->onClick = [this, onScene]()
	{
		if (onScene != nullptr)
		{
			_director->pushScene(onScene());
		}
	};
	return button;
}

cButton* cExpansion::onButtonEasy(const std::string& name, const txtEasy::sTable& txts)
{
	cButton* button = cButton::create4(name);
	_buttons.push_back(button);
	button->onClick = [this, name, txts]()
	{
		_director->pushScene(expEasy::createEasy(name, txts));
	};
	return button;
}

void cExpansion::onRank()
{
	_r.init(cc::vsSize().width - cx * 2);
	Node* node = Node::create();
	forv(_buttons, k)
	{
		node->addChild(_buttons[k]);
		_r.iter(_buttons[k]);
	}
	_r.iter();
	node->setContentSize(_r.getSize());
	node->setPosition(cx, _y);
	_y += node->getContentSize().height + cy;
	this->addChild(node);
	_buttons.clear();
}

