#include "cMap.h"
#include "cObject.h"
#include "cScript.h"
#include "uiSmap.h"
#include "uiShichen.h"
#include "uiManager.h"

//////////////////////////////////////////////////////////////////////////
bool cMapMask::init()
{
	if (!cNode::init())
	{
		return false;
	}
	setRender(eRender::mapMask);
	return true;
}



void cMapMask::draw(cCanvas* canvas, const uint32_t& flags)
{
	if (_map == nullptr)
	{
		return;
	}
	canvas->Change();
	cMapRender::getInstance()->drawMask(canvas, _map->convertToNodeSpace(Vec2::ZERO));
}

//////////////////////////////////////////////////////////////////////////
cMap::cMap()
{

}

cMap::~cMap()
{
	cMapRender::getInstance()->setMap(nullptr);
	cMapFollow::getInstance()->setTarget(nullptr, nullptr);
}



bool cMap::init()
{
	if (!Node::init())
	{
		return false;
	}
	this->setRender(eRender::map);
	this->setSnatchNode(true);

	this->addChild(_nodeTemp = Node::create(), 1);
	// ��צӡ z 0
	// NPC z 1
	this->addChild(_nodeNpc = Node::create(), 1);
	this->addChild(_nodeTeam = Node::create(), 1);
	this->scheduleUpdate();
	return true;
}


void cMap::clearNpcsAndTrans()
{
	forv(_nodeNpcs, k)
	{
		auto& nodes = _nodeNpcs.at(k);
		forv(nodes, i)
		{
			nodes.at(i)->runAction(RemoveSelf::create());
			continue;
			auto& node = nodes.at(i);
			for (auto& n : node->getChildren())
			{
				n->runAction(RemoveSelf::create());
			}
		}
	}
	for (auto& n : _nodeNpc->getChildren())
	{
		n->runAction(RemoveSelf::create());
	}
	for (auto& n : _nodeTemp->getChildren())
	{
		n->runAction(RemoveSelf::create());
	}
}


void cMap::clearPaths()
{
	_paths.clear();
}

bool cMap::load(const std::string& mapname)
{
	const auto& ms = txtMap::getInstance()->getTables();
	const auto& it = ms.find(mapname);
	if(it == ms.end())
	{
		return false;
	}

	const auto& m = it->second;
	setMusic(m.music.empty() ? mapname : m.music);
	loadMusic();
	ccu::getManager()->getShichen()->setMapName(mapname);
	_name = mapname;

	clearNpcsAndTrans();
	load(m.mapid, cGame::getInstance()->getMap());
	// ��load��map�Ĵ�С��setTagrt
	cMapFollow::getInstance()->setTarget(this, getHero());

	ccu::getManager()->getSmap()->load(m.uid, _contentSize);
	bool isCA = mapname == "������";
	for (const auto& npc : m.npcs)
	{
		bool rand = npc.mod == eMod::������;
		bool addSmap = !(isCA && (rand || (npc.mod >= eMod::ePet0 && npc.mod <= eMod::ePet0end)));
		load(npc, rand, addSmap);
	}
	for (const auto& tr : m.transmits)
	{
		load(tr);
	}
	return true;
}

void cMap::load(int mapid, eMapType e)
{
	if (mapid != _cache.mapid || e != _cache.e)
	{
		cMapReader::getInstance()->freeCache(_cache);
		cMapRender::getInstance()->setMap(nullptr);
		_cache = cMapReader::getInstance()->getCache(e, mapid);
	}
	_paths.clear();
	auto pMap = _cache.pMap;
	cMapRender::getInstance()->setMap(pMap);
	this->setContentSize(pMap->info.mw, pMap->info.mh);

	_nw = cc::vsSize().width;
	_nh = cc::vsSize().height;
	cMapRender::getInstance()->onSize(_nw, _nh);
	cMapFollow::getInstance()->onSize(_nw, _nh);
	_nw /= 2;
	_nh /= 2;

	mapid = std::ceil(_contentSize.width / _nw);
	_nodeNpcs.resize(std::ceil(_contentSize.height / _nh));
	forv(_nodeNpcs, k)
	{
		auto& nodes = _nodeNpcs.at(k);
		nodes.resize(mapid);
		forv(nodes, i)
		{
			auto& node = nodes.at(i);
			this->addChild(node = Node::create(), 1);
			node->setPosition(i * _nw, k * _nh);
		}
	}
	_nodeNpc->updateOrderOfArrival();
	_nodeTeam->updateOrderOfArrival();

	pMap->loadMask();
}



void cMap::load(int x20, int y20)
{
	int y2 = _contentSize.height / cMapReader::c20 - 1 - y20;
	this->setPosition(cc::vsCenter() - (Vec2(x20, y2) * cMapReader::c20));
	cMapFollow::correctPosition(this);

	Node* hero = getHero();
	if (hero != nullptr)
	{
		hero->setPosition(toPosition(x20, y20));
		for (int k = cHeroTag + 1, size = cHeroTag + _nodeTeam->getChildrenCount(); k < size; ++k)
		{
			Node* node = _nodeTeam->getChildByTag(k);
			if (node != nullptr)
			{
				node->setPosition(hero->getPosition());
			}
			
		}
	}
	if (onPaths != nullptr)
	{
		onPaths(_paths, x20, y20);
	}
}


static const auto& s_trans = txtEasy::getInstance()->getTransmits();
void cMap::load(const txtMap::sTransmit& transmit)
{
	cObject* tr = cObject::create();
	tr->setNameColor(s565::GREEN);
	tr->load(s_trans.at(cc::random(3U, s_trans.size() - 1)), transmit.name);
	tr->setSnatchNode(true);

	Vec2 v = toPosition(transmit.x, transmit.y);
	tr->setPosition((int)v.x % _nw, (int)v.y % _nh);

	tr->onClick = [this, transmit]()
	{
		load(transmit.name);
		load(transmit.tx, transmit.ty);
	};
	_nodeNpcs.at(v.y / _nh).at(v.x / _nw)->addChild(tr);
	ccu::getManager()->getSmap()->loadTrans(transmit.name, v);
}


void cMap::load(const txtMap::sNpc& npc, bool rand, bool smap)
{
	cObject* obj = cObject::create();
	sMod mod;
	std::string name = npc.name;
	if (rand)
	{
		mod.setMod((eMod)cc::random((int)eMod::eJueSe0, (int)eMod::eJueSeEnd));
		mod.setWeapon(cc::random(9, 14) * 10);
		obj->setNameColor(s565::GREEN);
	}
	else
	{
		mod.setMod(npc.mod);
	}
	if (name.empty())
	{
		if (txtMod::isNpc(npc.mod))
		{
			name = txtNpc::getInstance()->getTables().at(npc.mod).name;
		}
		else if (txtMod::isPet(npc.mod))
		{
			name = txtPet::getInstance()->getTables().at(npc.mod).name;
		}
		else if (txtMod::isRole(mod.emod))
		{
			name = txtRole::getInstance()->getTables().at(npc.mod).name;
		}
	}
	obj->load(mod);
	obj->setSnatchPixel(true);
	if (rand)
	{
		// ̯λ
		cSprite* sprite = cSprite::create(0x74786102);
		sprite->setRender(eRender::mapObj);
		cLabel* label = cLabel::create(name);
		label->setColor(s565::BLACK);
		sprite->addChild(label);
		label->setPosition(sprite->getContentSize() / 2 - label->getContentSize() / 2);
		obj->addChild(sprite, -1);
		sprite->setPositionY(-100);
	}
	else
	{
		obj->setObjName(name);
	}
	obj->setDirection((int)npc.direction);
	obj->setAppellation(npc.appellation);
	obj->setSnatchNode(true);

	Vec2 v = toPosition(npc.x, npc.y);
	obj->setPosition((int)v.x % _nw, (int)v.y % _nh);

	txtAction::sAction heads;
	mod.apply(heads, false);
	ulong dialog = heads.at(eAct::Dialog);
	if (!rand)
	{
		obj->onClick = [this, npc, dialog, name]()
		{
			if (!cScript::getInstance()->run(this, dialog, name, npc.script))
			{
				cScript::getInstance()->run(sTeam::getInstance()->getLeader(), dialog, name);
			}
		};
	}
	_nodeNpcs.at(v.y / _nh).at(v.x / _nw)->addChild(obj);
	if (smap)
	{
		ccu::getManager()->getSmap()->loadNpc(name, v);
	}

	if (rand && name == "�ϳ���ר����")
	{
		mod.setMod(eMod::eСëͷ);
		obj = cObject::create();
		obj->load(mod, false);
		v = toPosition(210, 160);
		obj->setPosition((int)v.x % _nw, (int)v.y % _nh);
		_nodeNpcs.at(v.y / _nh).at(v.x / _nw)->addChild(obj);
		obj->setNameColor(s565::GREEN);
		obj->setObjName("�׺���");
		obj->runAction(RepeatForever::create(Sequence::create(
			CallFunc::create([obj]()
			{
				obj->say("���˴�ץ����?#17�������ĵĴ���������������?#15", false);
			}), 
			DelayTime::create(4.5f), nullptr)));
		obj->schedule([this, obj](float dt)
		{
			if (obj->getTag() == 0)
			{
				return;
			}
			Vec2 v2(cc::random(210 - 15, 210 + 15), cc::random(160 - 10, 160 + 10));
			v2 = toPosition(v2.x, v2.y);
			v2.x = (int)v2.x % _nw;
			v2.y = (int)v2.y % _nh;
			float d = obj->getPosition().distance(v2);
			obj->runAction(Sequence::create(MoveTo::create(d * 0.01f, v2), CallFunc::create([obj]() 
			{
				obj->setTag(1);
			}), nullptr));
			obj->setTag(0);
			obj->walk(v2);
		}, 1, "Сëͷ");
	}
}


void cMap::setMusic(const std::string& music)
{
	static std::map<std::string, ulong> s_musicMap = {
	{"�����Թ�", 0x00167186},
	{"�����Թ�2", 0x00167186},
	{"����ɽ", 0x012D9DD7},
	{"��ľ��", 0x016F4476},
	{"С����", 0x03D65C21}, //С������
	{"������2", 0x05122F2E},
	{"�貨��", 0x0B16F601},
	{"���԰", 0x10D7ABF1},
	{"�����ɵ�", 0x10DF6DF7},
	{"���ٽ���", 0x18348D2B},
	{"С������", 0x2011A8C2},
	{"����«��", 0x2142584C},
	{"����ɽ", 0x21BEB585},
	{"������", 0x26275208},
	{"����Ұ��", 0x266E2C58},
	{"������1", 0x2C3D8AF0},
	{"���ٴ�", 0x2F1EC70A},
	{"�����", 0x3127BBB8},
	{"������", 0x35159569},
	{"ʨ����", 0x3800966C},
	{"���ƶ�", 0x3F24C153},
	{"���ֶ���", 0x41645B50},
	{"ħ��կ", 0x4A64F8BD},
	{"���ƹٸ�", 0x4AE2B5B3},
	{"������", 0x4B4740AC},
	{"˿��֮·", 0x52A0B4EE},
	{"����ɽ", 0x53C2DE57},
	{"�����Թ�2", 0x5A864351},
	{"�¹�", 0x5B0DCCD9},
	{"������", 0x5B9DC400},
	{"����2", 0x65B90ACA},
	{"������", 0x68F6DDA1},
	{"���ܵظ�", 0x700EE303},
	{"��Դ��", 0x76C2A481},
	{"", 0x78FC0CBA}, // �����
	{"����", 0x79D250E2},
	{"��ս�볡", 0x7B908BCA},
	{"ī�Ҵ�", 0x7C4D04B2},
	{"����Ů��", 0x8482AF70},
	{"����", 0x84E2EB78},
	{"����", 0x86C4F045}, // �η�  ���� 
	{"����ɽ", 0x88CD5404},
	{"����ɽ", 0x8C4500FC},
	{"Ů����", 0x8CAB9764},
	{"��������", 0x8EF4D872},
	{"δ֪", 0x9245F880}, // ��ΰ ��ϵ
	{"������", 0x92DD1A7A},
	{"�޵׶�", 0x95C16AD7},
	{"ī�ҽ���", 0x9E05AC95},
	{"���Ϲ�", 0xA602567C},
	{"δ֪����", 0xA6F426EB},
	{"��", 0xA7330084},
	{"�����", 0xA8A9DBB9},
	{"ս��ɽ", 0xAA002386},
	{"��˿��", 0xAC396538},
	{"����", 0xAE8B3481},
	{"��ĸ�ӵ�", 0xAE8C1555},
	{"�ﳲ", 0xB0D9F40A},
	{"�ﳲ2", 0xB33EB187},
	{"���䳡", 0xBED44FE1},
	{"���¶�", 0xCD525622},
	{"�����Թ�", 0xD3B5D40A},
	{"���ƾ���", 0xD66E10A8},
	{"����ɽ", 0xDABAC06C},
	{"Ů���", 0xE4096D42},
	{"�칬", 0xE7CE763C},
	{"���ƹ���", 0xEA26251A},
	{"��ׯ��", 0xFD1ECF8F},
	{"�����Թ�5", 0xEBCC1270}, // ��������
	{"��������", 0xEBCC1270},
	{"ս��1", 0x8905924A},
	{"ս��2", 0xC1064081}, // ս��6-����
	{"ս��3", 0xB248A7C7}, // ս��7-ɽ��
	{"ս������1", 0x389F5EF4},
	{"ս������2", 0x9EC29A9D}, // ս��5-��ԭ
	{"ս������3", 0xF303B6A9},
	{"ս������4", 0xFB165E34},
	{"ս��BOSS", 0x845DC12C},
	};
	const auto& it = s_musicMap.find(music);
	if (it != s_musicMap.end())
	{
		_music = it->second;
	}
}


void cMap::loadMusic()
{
	if (_music == cSp::c0)
	{
		return;
	}
	if (onMusic != nullptr)
	{
		onMusic(_music);
	}
}


cocos2d::Vec2 cMap::toPosition(int x20, int y20)
{
	return Vec2(x20 * cMapReader::c20 + cMapReader::c20 / 2, _contentSize.height - y20 * cMapReader::c20 - cMapReader::c20 / 2);
}


void cMap::toPosition(const Vec2& vMap, int& x20, int& y20)
{
	x20 = vMap.x / cMapReader::c20;
	y20 = (_contentSize.height - 1 - vMap.y) / cMapReader::c20;
}


bool cMap::isObstacle(int x20, int y20)
{
	if (_cache.pMap != nullptr && _cache.pMap->loadObstacles())
	{
//		y20 = _cache.pMap->info.bh * cMapReader::c12 - 1 - y20;
		y20 = _contentSize.height / cMapReader::c20 - 1 - y20;
		return _cache.pMap->isObstacle(x20, y20);
	}
	return true;
}


cocos2d::Node* cMap::getHero()
{
	return _nodeTeam->getChildByTag(cHeroTag);
}


void cMap::update(float delta)
{
	cMapRender::getInstance()->step(this->convertToNodeSpace(cc::vsCenter()), false);
	cMapFollow::getInstance()->step();

	static Vec2 v, v2, v3;
	static int size; size = _paths.size();
	if (size > 0)
	{
		cObject* hero = (cObject*)getHero();
		v = _paths.back();
		v2 = getHero()->getPosition();
		v3 = v - v2;
		static bool s_mov;
		s_mov = true;
		if (std::abs(v3.x) < _moveSpeed && std::abs(v3.y) < _moveSpeed)
		{
			_paths.pop_back();
			--size;
			_isMoving = true;
			if (onPaths != nullptr)
			{
				onPaths(_paths, v2.x / cMapReader::c20, (_contentSize.height - 1 - v.y) / cMapReader::c20);
			}
			if (_paths.empty())
			{
				hero->stand();
				s_mov = false;
			}
			else
			{
				hero->walk(v);
			}
		}

		if (s_mov)
		{
			v3.normalize();
			v2 += v3 * _moveSpeed;
			hero->setPosition(v2);
			if (onMoving != nullptr)
			{
				onMoving(v2);
			}
		}
	}

	if (_isMoving)
	{
		for (int k = cHeroTag + 1, size = cHeroTag + _nodeTeam->getChildrenCount(); k < size; ++k)
		{
			cObject* mbj = (cObject*)_nodeTeam->getChildByTag(k);
			v = mbj->getPosition();
			cObject* pre = (cObject*)_nodeTeam->getChildByTag(k - 1);
			v2 = pre->getPosition();
			v3 = v2 - v;
			if (std::abs(v3.x) < cMapReader::c20 * 6 && std::abs(v3.y) < cMapReader::c20 * 6)
			{
				mbj->stand();
				if (k == cHeroTag + 1)
				{
					_isMoving = false;
				}
				continue;
			}
			if (std::abs(v3.x) < _moveSpeed && std::abs(v3.y) < _moveSpeed)
			{
				continue;
			}
			mbj->walk(v2);
			v3.normalize();
			v += v3 * _moveSpeed;
			mbj->setPosition(v);
		}
	}

	bool steped = cStepper::getInstance()->isStepd();
	bool walked = cStepper::getWalk()->isStepd();
	if (steped && getHero())
	{
		v = getHero()->getPosition();
		v.x /= _nw;
		v.y /= _nh;
		forv(_nodeNpcs, k)
		{
			auto& nodes = _nodeNpcs.at(k);
			forv(nodes, i)
			{
				auto& node = nodes.at(i);
				node->setVisible(std::abs((int)v.x - i) <= 2 && std::abs((int)v.y - k) <= 2);
			}
		}
	}
	forv(_nodeNpcs, k)
	{
		auto& nodes = _nodeNpcs.at(k);
		forv(nodes, i)
		{
			auto& node = nodes.at(i);
			if (node->isVisible())
			{
				for (auto& n : node->getChildren())
				{
					((cObject*)n)->step(delta, steped, walked);
				}
			}
		}
	}
	for (auto& n : _nodeNpc->getChildren())
	{
		((cObject*)n)->step(delta, steped, walked);
	}
	for (auto& n : _nodeTeam->getChildren())
	{
		((cObject*)n)->step(delta, steped, walked);
	}
}


void cMap::setMoveSpeed(int speed)
{
	_moveSpeed = speed;
	cMapFollow::getInstance()->setSpeedMax(speed);
}


void cMap::draw(cCanvas* canvas, const uint32_t& flags)
{
	if (flags || _isDraw)
	{
		canvas->Change();
	}
	else
	{
		canvas->UnChange();
	}
	cMapRender::getInstance()->draw(canvas, this->convertToNodeSpace(Vec2::ZERO));
}


void cMap::doEvent(bool left, bool up, int keepTimes)
{
	if (!left || !up || keepTimes != 0)
	{
		return;
	}

	cSprite* spriteClick = cSprite::create(0x0D98AC0A);
	spriteClick->setRender(eRender::mapObj);
	spriteClick->play(0, true);
	spriteClick->setPosition(_nodeTeam->convertToNodeSpace(cInput::getInstance()->getMouse()));
	addChild(spriteClick, -1);
	doSearch(spriteClick->getPosition());
}

void cMap::doSearch(const Vec2& v)
{
	auto hero = getHero();
	if (hero == nullptr)
	{
		return;
	}
	_cache.pMap->search(hero->getPosition(),v, _paths);
	if (_paths.empty())
	{
		int x20, y20;
		toPosition(v, x20, y20);
		if (!isObstacle(x20, y20))
		{
			load(x20, y20);
		}
	}
}

