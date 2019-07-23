#pragma once
// #include "_txtinc.h"
// #include "eMod.h"
#include "txtXiangrui.h"

enum class eZuoqi
{
	eZuoqiNone = -1,
	eZuoqi0,
	������« = eZuoqi0,
	����С��,
	��Ѫ����,
	��ϲ����,
	ħ������,
	����ս��,
	����Ұ��,
	������¹,
	eZuoqiEnd = ������¹
};



ccc_txt_class_begin(txtZuoqi);

txtZuoqi();

struct sStandWalk
{
	ulong stand;
	ulong walk;
};

struct sZuoqi
{
	ulong stand;
	ulong walk;
	ulong color;
	std::string name;
	std::map<eMod, sStandWalk> masters;
};

// struct sXiangrui
// {
// 	ulong stand;
// 	ulong walk;
// 	ulong stand2;
// 	ulong walk2;
// };

// typedef std::map<eMod, std::vector<ulong>> sMasterPos;
typedef txtXiangrui::sMasterPos sMasterPos;
const sMasterPos& getMasterStands();
const sMasterPos& getMasterWalks();
const std::map<int, sZuoqi>& getZhuangshis(){ return _zhuangshis; }
// const std::map<int, sXiangrui>& getXiangruis(){ return _xiangruis; }
// bool isZuoqi(eZuoqi zq, int shuangshi);

private:
	void init(eZuoqi e, const ulong& stand, const ulong& walk, const ulong& color, const std::string& name);
	void init(int id, const ulong& stand, const ulong& walk, const ulong& color);
	void insert(eMod master, const ulong& stand, const ulong& walk);
//	void insert(const ulong& stand, const ulong& walk, const ulong& stand2 = 0, const ulong& walk2 = 0);

	sStandWalk _standwalk;
//	sXiangrui _xiangrui;
	std::map<eMod, sStandWalk>* _masters;
	int _index;
	std::map<int, sZuoqi> _zhuangshis;
//	sMasterPos _masterStands;
//	sMasterPos _masterWalks;

//	std::map<int, sXiangrui> _xiangruis;
ccc_txt_class_end(eZuoqi, sZuoqi);