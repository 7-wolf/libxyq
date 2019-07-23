#pragma once
#include "_txtinc.h"
#include "eSkill.h"

ccc_txt_class_begin(txtSkill);

txtSkill();

struct sSkill
{
	ulong act;
	ulong state;
	ulong sound;
	eSkiType type;
	eBuff buff;
	eSkiPos pos;
};

// ����
struct sCost
{
	// �����Ѫ%
	int hpmaxper = 0;
	// ��ǰ��Ѫ%
	int hpper = 0;
	// ��Ѫ
	int hp = 0;
	// ħ��ÿ��
	int mps = 0;
	// ħ��: �ȼ� / lv + mp
	int lv = 0;
	// ħ��
	int mp = 0;
	// ս��
	int zy = 0;
	// ��ŭ
	int ap = 0;
	// ����
	bool ignore = false;
	// 
	std::string desc;
};

struct eFFect
{
	eSkiPos pos;
	bool zTop;
};

const std::vector<eSkill>& getFushis(){ return _fushis; }
const std::vector<eSkill>& getZhuijias(){ return _zhuijias; }
const std::map<eSkill, sCost>& getCosts(){ return _costs; }
const std::map<eSkill, std::vector<ulong>>& getActs(){ return _acts; }
const std::map<eSkill, std::vector<ulong>>& getHits(){ return _hits; }
const std::map<eSkill, ulong>& getStateExs(){ return _stateExs; }
const std::map<eSkill, eFFect>& getEffects(){ return _effects; }

// ����
static bool isEd(eSkill e);
// ���ɼ���
static bool isMenpai(eSkill e);
// ��ʦ�ż���(ˮ��֮���)
static bool isF1(eSkill e);
// ��������
static bool isPet(eSkill e);
// �ؼ�
static bool isSpecial(eSkill e);

static int getTargetsCount(eSkill e);
static bool isTargetAtked(eSkill e);
static bool isTargetsTeam(eSkill e);
static void applyIterPos(ulong actid, eSkiPos& pos);
static void applyAtkedDelta(ulong atkid, int& delta);
private:
	void insert(ulong act, ulong state, ulong sound, eSkill skill, eSkiType type = eSkiType::BattleOther, eBuff buff = eBuff::None, eSkiPos pos = eSkiPos::Mid);
	void insert(ulong act, ulong state, ulong sound, eSkill skill, eBuff buff, eSkiPos pos);
	void insert(ulong act, ulong state, ulong sound, eSkill skill, eSkiType type, eSkiPos pos);
	void insert(ulong act, ulong state, ulong sound, eSkill skill, eSkiPos pos);
	void insert(ulong act, ulong state, ulong sound, eSkill skill, eBuff buff);
	void insertAct(eSkill e, ulong a1, ulong a2 = 0, ulong a3 = 0);
	void insertHit(eSkill e, ulong a1, ulong a2 = 0, ulong a3 = 0);
	void insertEffect(eSkill e, eSkiPos pos = eSkiPos::Mid, bool zTop = false);
	void insertEffect(eSkill e, bool zTop);

	void initActs();
	void initFushi();
	void initEffect();

	sSkill _skill;
	std::vector<ulong> _uids;
	eFFect _effect;

	std::vector<eSkill> _fushis;
	std::vector<eSkill> _zhuijias;
	std::map<eSkill, sCost> _costs;
	std::map<eSkill, std::vector<ulong>> _acts;
	std::map<eSkill, std::vector<ulong>> _hits;
	std::map<eSkill, ulong> _stateExs;
	std::map<eSkill, eFFect> _effects;

	friend class txtIcon;
	void insertCost(eSkill e, const std::string& descCost);
ccc_txt_class_end(eSkill, sSkill);