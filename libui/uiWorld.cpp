#include "uiWorld.h"

// ��ͼ��ʾ״̬
enum  eMap
{
	eMapWorld,
	eMapEast,
	eMapWest,
	eMapSouth,
	eMapNorth,
};

static std::map<eMap, ulong> s_mapuids = 
{
	{ eMapWorld, 0x93E77F54 },
	{ eMapEast, 0x26E89B1F },
	{ eMapWest, 0x11A18FBF },
	{ eMapSouth, 0x0B19A5DC },
	{ eMapNorth, 0xE9EC7A25 },
};
bool uiWorld::init()
{
	if (!uiPad::init(s_mapuids.at(eMapWorld), true))
	{
		return false;
	}
//	setDragType(uiEvent::eDrag::None);
//	setCloseRup(false);
	addChild(_nodeWorld = Node::create());
	cButton* button;
	// ��ť���������,����С���ȷűȽϺ�
#define ccc_create_button(_node_, _uid_, _name_, _x_, _y_, _tx_, _ty_)\
{\
	button = cButton::create(_uid_);\
	button->setSnatchPixel(true);\
	_node_->addChild(button);\
	button->setDesc(_name_);\
	button->setPosition(_x_, _y_);\
	button->onClick = [this]()\
	{\
		this->setVisible(false);\
		if(!sTeam::getInstance()->isFighting() && onSelect != nullptr)\
		{\
			onSelect(_name_, _tx_, _ty_);\
		}\
	};\
}
	// ���
	ccc_create_button(_nodeWorld, 0xF8A67A7A, "���԰", 199, 0, 132, 25);
	// �칬
	ccc_create_button(_nodeWorld, 0x5ABFF907, "�칬", 166, 23, 203, 33);
	// �¹�
	ccc_create_button(_nodeWorld, 0xF63C410E, "�¹�", 75, 4, 98, 60);
	// ����
	ccc_create_button(_nodeWorld, 0xCE11152D, "����", 388, 376, 91, 46);
	// ����«��
	cButton* buttonNorth = cButton::create(0xEA1F50E2);
	buttonNorth->setDesc("����«��");
	_nodeWorld->addChild(buttonNorth);
	buttonNorth->setPosition(271, 10);
	buttonNorth->onClick = [this]()
	{
		doHide();
		_nodeNorth->setVisible(true);
		uiPad::load(s_mapuids.at(eMapNorth));
	};
	// ��ʤ����
	cButton* buttonEast = cButton::create(0xCC1742A6);
	buttonEast->setDesc("��ʤ����");
	_nodeWorld->addChild(buttonEast);
	buttonEast->setPosition(499, 160);
	buttonEast->onClick = [this]()
	{
		doHide();
		uiPad::load(s_mapuids.at(eMapEast));
		_nodeEast->setVisible(true);
	};
	// ��ţ����
	cButton* buttonWest = cButton::create(0x0AF24A29);
	buttonWest->setDesc("��ţ����");
	_nodeWorld->addChild(buttonWest);
	buttonWest->setPosition(0, 58);
	buttonWest->onClick = [this]()
	{
		doHide();
		uiPad::load(s_mapuids.at(eMapWest));
		_nodeWest->setVisible(true);
	};
	// �ϲ�հ��
	cButton* buttonSouth = cButton::create(0x7FFAB47A);
	buttonSouth->setDesc("�ϲ�հ��");
	_nodeWorld->addChild(buttonSouth);
	buttonSouth->setPosition(85, 104);
	buttonSouth->onClick = [this]()
	{
		doHide();
		uiPad::load(s_mapuids.at(eMapSouth));
		_nodeSouth->setVisible(true);
	};

	addChild(_nodeEast = Node::create());
	addChild(_nodeWest = Node::create());
	addChild(_nodeNorth = Node::create());
	addChild(_nodeSouth= Node::create());
	doHide();
	_nodeWorld->setVisible(true);

	// ����ɽ
	ccc_create_button(_nodeEast, 0x6B27F57F, "����ɽ", 263, 11, 35, 98);
	// Ů����
	ccc_create_button(_nodeEast, 0x6BF13E64, "Ů����", 212, 162, 69, 63);
	// ����
	ccc_create_button(_nodeEast, 0xCCB7A7C3, "������", 343, 273, 127, 92);
	// ����
	ccc_create_button(_nodeEast, 0xA9BC7D93, "�����ɵ�", 149, 313, 83, 34);
	// Ů���
	ccc_create_button(_nodeNorth, 0xEDEEF9AF, "Ů���", 161, 20, 51, 38);
	// ����
	ccc_create_button(_nodeNorth, 0xA0B51368, "����һ��", 52, 167, 148, 15);
	// �ﳲ
	ccc_create_button(_nodeNorth, 0x13659C02, "�ﳲһ��", 327, 145, 64, 59);
	// �����
	ccc_create_button(_nodeWest, 0x0D906C8D, "�����", 488, 274, 115, 72);
	ccc_create_button(_nodeWest, 0x6A154DDE, "����ɽ", 542, 8, 126, 42);
	ccc_create_button(_nodeWest, 0x637B3C48, "���ٴ�", 414, 117, 107, 58);
	ccc_create_button(_nodeWest, 0x63566DA9, "�����", 329, 101, 58, 79);
	ccc_create_button(_nodeWest, 0xE329AD6A, "����Ů��", 457, 200, 84, 62);
	ccc_create_button(_nodeWest, 0x048DA00D, "����ɽ", 387, 317, 31, 117);
	ccc_create_button(_nodeWest, 0x689EB676, "���Ϲ�", 469, 330, 12, 7);


	ccc_create_button(_nodeSouth, 0xE0C66A6F, "���ƹٸ�", 450, 102, 99, 35);
	ccc_create_button(_nodeSouth, 0x9C992236, "���ܵظ�", 331, 34, 44, 54);
	ccc_create_button(_nodeSouth, 0xFF1D4A14, "���ƾ���", 105, 230, 394, 56);
	button->setDesc("����ׯ");
	ccc_create_button(_nodeSouth, 0x6EA52AE1, "���ƹ���", 295, 130, 41, 36);
	button->setDesc("����");
	ccc_create_button(_nodeSouth, 0x47FE6497, "������", 477, 158, 35, 20);
	ccc_create_button(_nodeSouth, 0x6AB41A9A, "������", 468, 232, 266, 33);
	ccc_create_button(_nodeSouth, 0x991B588D, "���ƹ���", 350, 113, 204, 234);
	button->setDesc("����");
	ccc_create_button(_nodeSouth, 0xAD1DC28A, "����", 469, 374, 91, 46);
	ccc_create_button(_nodeSouth, 0x150B5122, "ħ��կ", 191, 94, 39, 24);
	ccc_create_button(_nodeSouth, 0x301A4FE7, "��˿��", 213, 194, 179, 120);
	ccc_create_button(_nodeSouth, 0xEC9EBCA8, "����ɽ", 333, 410, 69, 18);
	ccc_create_button(_nodeSouth, 0xBF78C1EF, "ʨ����", 4, 185, 114, 83);
	ccc_create_button(_nodeSouth, 0x5B96A2DD, "�������", 273, 18, 46, 25);
	ccc_create_button(_nodeSouth, 0xCA26DE5D, "��ׯ��", 232, 271, 43, 38);
	ccc_create_button(_nodeSouth, 0xEA60ABA4, "С����", 50, 69, 37, 208);
	ccc_create_button(_nodeSouth, 0xF617F5A9, "ī�Ҵ�", 155, 17, 42, 155);

	ccc_create_button(_nodeSouth, 0x71DF41E1, "������", 368, 141, 200, 160);

#undef ccc_create_button
	return true;
}

void uiWorld::doClose()
{
	if (_nodeWorld->isVisible())
	{
		uiPad::doClose();
	}
	else
	{
		doHide();
		uiPad::load(s_mapuids.at(eMapWorld));
		_nodeWorld->setVisible(true);
	}
}

void uiWorld::doHide()
{
	_nodeEast->setVisible(false);
	_nodeWest->setVisible(false);
	_nodeNorth->setVisible(false);
	_nodeSouth->setVisible(false);
	_nodeWorld->setVisible(false);
}
