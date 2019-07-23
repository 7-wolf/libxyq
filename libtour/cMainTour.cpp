#include "cMainTour.h"
#include "../libtxt/txtEasy.h"
#include "../libtxt/txtNpc.h"

#include "../libui/cMap.h"
#include "../libui/uiShichen.h"
#include "../libui/uiSmap.h"

void cMainTour::setTitle(HWND hwnd, HWND child)
{
	if (hwnd != nullptr)
	{
		::SetWindowText(hwnd, "�����ι۹��v20190720");
	}
}

Scene* cMainTour::runScene()
{
	auto scene = Scene::create();
	cMapMask* mapMask = cMapMask::create();
	scene->addChild(mapMask);
	scene->addChild(_map = cMap::create());
	mapMask->setMap(_map);

	scene->addChild(_shichen = uiShichen::create());
	scene->addChild(_smap = uiSmap::create());
	_shichen->getSpriteDay()->onClick = [this]()
	{
		if (_tours.size() <= 1)
		{
			return;
		}
		_tours.pop_back();
		toMap(_tours.back());
	};

	_map->setMoveSpeed(6);
	_map->onPaths = [this](const std::vector<Vec2>& path, int x, int y)
	{
		_smap->load(path);
		_shichen->setHeroXY(x, y);
	};
	_map->onMoving = [this](const Vec2& v)
	{
		_smap->moving(v);
	};
	_smap->onClick = [this](const Vec2& v)
	{
		_map->doSearch(v);
	};

	cObject* obj = cObject::create();
	obj->setNameColor(s565::GREEN);
	{
		sSp stand, walk;
		const auto& jxk = txtNpc::getInstance()->getTables().at(eMod::������);
		stand.uid = jxk.stand;
		walk.uid = jxk.walk;
		obj->load({ stand }, { walk });
	}
	obj->setObjName("�Ǳ�");
	obj->setTag(cMap::cHeroTag);
	_map->getTeamLayer()->addChild(obj);
	obj->setSnatchNode(true);
	obj->onClick = [this]()
	{
		// loadRand();
		_smap->switchVisible();
	};

	sTour tour(1241, "���");
	tour.x20 = 122;
	tour.y20 = 41;
	_tours.push_back(tour);
	toMap(tour);
	return scene;
}

void cMainTour::beforeMainLoop()
{
	auto input = cInput::getInstance();
	if (input->isKdown(DIK_TAB))
	{
		_smap->switchVisible();
	}
}

void cMainTour::loadRand()
{
	do
	{
		_tours.back().x20 = cc::random(0, (int)_map->getContentSize().width / cMapReader::c20);
		_tours.back().y20 = cc::random(0, (int)_map->getContentSize().height / cMapReader::c20);
	} while (_map->isObstacle(_tours.back().x20, _tours.back().y20));
	_map->clearPaths();
	_map->load(_tours.back().x20, _tours.back().y20);
}


void cMainTour::toMap(const sTour& tour)
{
	int mapid = tour.mapids.at(cc::random(0U, tour.mapids.size() - 1));
	_shichen->setMapName(tour.name.empty() ? cc::toString(mapid) : tour.name);
	_map->clearNpcsAndTrans();
	_map->load(mapid, eMapType::jd);
	// ��load��map�Ĵ�С��setTagrt
	cMapFollow::getInstance()->setTarget(_map, _map->getHero());
	if(tour.x20 != 0 && tour.y20 != 0)
	{ 
		_map->load(tour.x20, tour.y20);
	}
	else
	{
		loadRand();
	}
	if (tour.name == "���")
	{
		cSprite* sprite = cSprite::create(0x58837CB1);
		if (sprite->isValid())
		{
			sprite->setPosition(_map->toPosition(5, 85));
			_map->getTempLayer()->addChild(sprite);
			sprite->setRender(eRender::map);
			sprite->play();
		}

		static std::vector<sTour> tours;
		if (tours.empty())
		{
			tours.push_back({ 1115, 1400, "�������" });
			tours.push_back({ 1206, "Ӣ��ڣ" });
			tours.push_back({ 1212, "��" });
			tours.push_back({ 1213, "��" });
			tours.push_back({ 1214, "��" });
			tours.push_back({ 1215, "��" });
			tours.push_back(1217);
			tours.push_back(1223);
			tours.push_back(1230);
			tours.push_back({ 1236, 1239, "���" });
			tours.push_back({ 1237, "�ķ���" });
			tours.push_back({ 1238, 1248, "��Ҷ��" });
			tours.push_back(1243);
			tours.push_back(1245);
			tours.push_back(1246);
			tours.push_back({ 1252, "�ֻؾ�" });
			tours.push_back({ 1306, 1447, "��԰" });
			tours.push_back({ 1339, 1343, "��ҹ���⾳" });
			tours.push_back({ 1380, 1607, "è��" });
			tours.push_back({ 1382, 1608, "ѩ��" });
			tours.push_back({ 1446, 1605, "����" });
			tours.push_back({ 1424, "����" });
			tours.push_back({ 1425, "��Ƥ" });
			tours.push_back({ 1429, "��լ" });
			tours.push_back(1876);
			for (int k = 1885; k <= 1888; ++k)
			{
				tours.push_back(k);
			}
			tours.push_back({ 2000, "������ħ" });
		}
		loadTrans(102, 30, 6, 8, tours);
		_smap->setVisible(true);
	}
	else if (tour.name == "����")
	{
		static std::vector<sTour> tours;
		if (tours.empty())
		{
			for (int k = 0; k < 3; ++k)
			{
				tours.push_back(1300 + k);
				tours.push_back(1930 + k);
			}
		}
		loadTrans(40, 25, 3, 10, tours);
	}
	else if (tour.name == "��Ƥ")
	{
		static std::vector<sTour> tours;
		if (tours.empty())
		{
			for (int k = 1340; k <= 1342; ++k)
			{
				tours.push_back(k);
			}
			for (int k = 1420; k <= 1422; ++k)
			{
				tours.push_back(k);
			}
			for (int k = 1426; k <= 1428; ++k)
			{
				tours.push_back(k);
			}
			tours.push_back(1430);
			for (int k = 1890; k <= 1892; ++k)
			{
				tours.push_back(k);
			}
		}
		loadTrans(35, 20, 4, 10, tours);
	}
	else if (tour.name == "��լ")
	{
		static std::vector<sTour> tours;
		if (tours.empty())
		{
			for (int k = 1310; k <= 1338; ++k)
			{
				tours.push_back(k);
			}
			for (int k = 1401; k <= 1418; ++k)
			{
				tours.push_back(k);
			}
			for (int k = 1933; k <= 1955; ++k)
			{
				tours.push_back(k);
			}
			for (int k = 1958; k <= 1971; ++k)
			{
				tours.push_back(k);
			}
		}
		loadTrans(40, 10, 10, 8, tours);
	}
	else if (mapid == 2000)
	{
		for (int k = _map->getContentSize().height / cMapReader::c20 - 1; k >= 0; --k)
		{
			break;
			for (int i = _map->getContentSize().width / cMapReader::c20 - 1; i >= 0; --i)
			{
				if (!_map->isObstacle(i, k))
				{
					continue;
				}
				cSprite* sprite = cSprite::create(ccu::uPetSelect);
				sprite->setRender(eRender::map);
				sprite->setClip(0, 0);
				sprite->setPosition(_map->toPosition(i, k));
				sprite->setContentSize(cMapReader::c20, cMapReader::c20);
				_map->getNpcLayer()->addChild(sprite);
			}
		}
	}


	static std::map<int, ulong> smaps =
	{
		// Ӣ��ڣ
		{1206, 0x78BF64A4},
		// ��
		{1213, 0xA680A821},
		// ��
		{1212, 0x3E795B5A},
		// ��
		{1215, 0x21F550FF},
		// ��
		{1214, 0xA4790CE1},
		// ����
		{1217, 0x5BB14859},
		// ������
		{1223, 0xBA6FC6C2},
		// �ķ���
		{1237, 0xDFE8D3CD},
		// ���
		{1241, 0xD848151B},
		// ����
		{1300, 0x2DA8C4DA},
		{1301, 0xD06119B3},
		{1302, 0xB6141EB9},
		{1424, 0x45F63D27},
		{1930, 0x1A82E34D},
		{1931, 0xC80D7A32},
		{1932, 0x35B09536},
		// ��Ƥ
		{1340, 0xF1B2AF14},
		{1341, 0x53AD1B15},
		{1342, 0xC60F4502},
		{1420, 0x51B164D9},
		{1420, 0x51B164D9},
		{1421, 0x68A0E04D},
		{1422, 0x267812DD},
		{1425, 0xC7FC4164},
		// 1430 ����
		{1426, 0x77AEF985},
		{1427, 0x6133AB6A},
		// 1424(����) ����
		{1428, 0x45F63D27},
		// 1425(��Ƥ��) ����
		{1429, 0xC7FC4164},
		{1430, 0x77AEF985},
		// 1420 ˮ��
		{1890, 0x51B164D9},
		// 1421 С��
		{1891, 0x68A0E04D},
		// 1422 ˮ��
		{1892, 0x267812DD},

		// "��԰" 1306, 1447,
		{1306, 0xD18FCEBF},
		{1447, 0xF601DC89},
		// ���� 1339 1343
		{1339, 0x893AA83E},
		{1343, 0x5CD2D127},
		// è�� 1380, 1607
		{1380, 0x07F49B2B},
		{1607, 0x07F49B2B},
		// ѩ�� 1381, 1608
		{1382, 0x6965A199},
		{1608, 0x6965A199},
		// ���� 1446 1605
		{1446, 0x8FA4C62A},
		{1605, 0x8FA4C62A},
		// ¶�춴��
		{1876, 0x099565A8},

		{1885, 0x64EBE33D},
		// ���� ���
		{1886, 0x9888189A},
		// ����
		{1887, 0x477D2153},
		// ���� ����
		{1888, 0xDF6D2B20},
	};

	const auto& it = smaps.find(mapid);
	if (it != smaps.end())
	{
		_smap->load(it->second, _map->getContentSize());
	}
}


void cMainTour::loadTrans(int x, int y, int w, int inv, const std::vector<sTour>& tours)
{
	int ow = _map->getContentSize().width / cMapReader::c20;
	int oh = _map->getContentSize().height / cMapReader::c20;
	for (int k = y, index = 0; k < oh; k += inv)
	{
		for (int i = x, iw = 0; i < ow && iw < w; i += inv, ++iw, ++index)
		{
			if (index >= tours.size())
			{
				break;
			}
			const auto& t = tours.at(index);

 			static auto& trans = txtEasy::getInstance()->getTransmits();
			static sSp sp;
 			cObject* mbj = cObject::create();
			mbj->setAppellationColor(s565::RED);
			mbj->load(trans.at(cc::random(0U, trans.size() - 1)), t.name);
			if (t.name.empty())
			{
				mbj->setObjName(cc::toString(t.mapids.at(0)));
				if (t.mapids.size() > 1)
				{
					mbj->setAppellation(cc::toString(t.mapids.at(1)));
				}
				else
				{
					mbj->setAppellation("");
				}
			}
			else
			{
				mbj->setObjName(t.name);
				static std::string app;
				app = cc::toString(t.mapids.at(0));
				if (t.mapids.size() > 1)
				{
					app += "/" + cc::toString(t.mapids.at(1));
				}
				mbj->setAppellation(app);
			}
 			mbj->setSnatchNode(true);
 			mbj->setPosition(_map->toPosition(i, k));
			mbj->onClick = [this, t]()
			{
				_map->toPosition(_map->getHero()->getPosition(), _tours.back().x20, _tours.back().y20);
				_tours.push_back(t);
				toMap(t);
			};
			_map->getNpcLayer()->addChild(mbj);
		}
		if (index >= tours.size())
		{
			break;
		}
	}
}


// static std::vector<sTour> s_tours =
// {
// 	{ 1115, 1400, "�������"},
// 	1215, 1217, 1223, 1230,
// 	{ 1236, 1239, "���" },
// {1237, "�ķ���"},
// {1238, 1248, "��Ҷ��"},
// {1241, "���"},
// 1243, 1245, 1246, // ����
// {1252, "�ֻؾ�"},
// {1300, "����"},{1301, "����"},{1302, "����"},{1930, "����"},{1931, "����"},{1932, "����"},
// {1306, 1447, "��԰"},
// {1339, 1343, "��ҹ���⾳"},
// // {1340, "��Ƥ"},{1341, "��Ƥ"},{1342, "��Ƥ"},{1420, "��Ƥ"},{1421, "��Ƥ"},{1422, "��Ƥ"},{1340, "��Ƥ"},{1340, "��Ƥ"},{1340, "��Ƥ"},{1340, "��Ƥ"},{1340, "��Ƥ"},
// {1380, 1607, "è��"},{1381, 1608, "ѩ��"},
// {1446, 1605, "С����"},
// 1876, 1885, 1886, 1887, 1888,
// {2000, "������ħ"},
// };
