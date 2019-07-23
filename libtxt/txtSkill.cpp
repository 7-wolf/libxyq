#include "txtSkill.h"

ccc_txt_instance_cpp(txtSkill);


void txtSkill::insert(ulong act, ulong state, ulong sound, eSkill skill, eSkiType type /* = eSkiType::BattleOther */, eBuff buff /* = eBuff::None */, eSkiPos pos /* =  */)
{
	_skill.act = act;
	_skill.state = state;
	_skill.sound = sound;
	_skill.type = type;
	_skill.buff = buff;
	_skill.pos = pos;
	_tables.insert(std::make_pair(skill, _skill));
}

void txtSkill::insert(ulong act, ulong state, ulong sound, eSkill skill, eBuff buff, eSkiPos pos)
{
	insert(act, state, sound, skill, eSkiType::BattleOther, buff, pos);
}

void txtSkill::insert(ulong act, ulong state, ulong sound, eSkill skill, eSkiType type, eSkiPos pos)
{
	insert(act, state, sound, skill, type, eBuff::None, pos);
}

void txtSkill::insert(ulong act, ulong state, ulong sound, eSkill skill, eSkiPos pos)
{
	insert(act, state, sound, skill, eSkiType::BattleOther, eBuff::None, pos);
}

void txtSkill::insert(ulong act, ulong state, ulong sound, eSkill skill, eBuff buff)
{
	insert(act, state, sound, skill, eSkiType::BattleOther, buff);
}


void txtSkill::insertCost(eSkill e, const std::string& descCost)
{
	if (descCost.empty())
	{
		return;
	}
	sCost c;
	if (e >= eSkill::eSpecial0 && e <= eSkill::eSpecialEnd)
	{
		c.ap = std::atoi(descCost.c_str());
		c.desc = descCost + "���ŭ";
		_costs.insert(std::make_pair(e, c));
		return;
	}
	std::vector<std::string> strs;
	cc::split(descCost, "_", strs);
	if (strs.front() == "ignore")
	{
		c.ignore = true;
		strs.erase(strs.begin());
	}
	int costvalue = std::atoi(strs[1].c_str());
	const std::string& costhpmp = strs.front();

	if (costhpmp == "HpMax")
	{
		c.hpmaxper = costvalue;
		c.desc = toString("%d%%�����Ѫ", costvalue);
		if (e == eSkill::�ɼ�����)
		{
			c.mp = 50;
			c.desc += "50��ħ��";
		}
	}
	else if (costhpmp == "HpFix")
	{
		c.hp = costvalue;
		c.desc = toString("%d����Ѫ", costvalue);
	}
	else if (costhpmp == "Hp")
	{
		c.hpper = costvalue;
		c.desc = toString("%d%%��ǰ��Ѫ", costvalue);
	}
	else if (costhpmp == "Lv")
	{
		c.lv = costvalue;
		c.mp = std::atoi(strs[2].c_str());
		c.desc = "�ȼ�";
		if (costvalue > 1)
		{
			c.desc += toString("/%d", costvalue);
		}
		c.desc += "+" + strs[2] + "��ħ��";
	}
	else if (costhpmp == "Mps")
	{
		c.desc = toString("%d��ħ��*Ŀ����", costvalue);
		c.mps = costvalue;
	}
	else if (costhpmp == "Mp")
	{
		c.desc = toString("%d��ħ��", costvalue);
		c.mp = costvalue;
	}

	if (e == eSkill::������ || e == eSkill::����ŭ)
	{
		c.desc += ",1��ս��";
		c.zy = 1;
	}
	else if (e == eSkill::�������)
	{
		c.desc += ",2��ս��";
		c.zy = 2;
	}
	else if (e == eSkill::��������)
	{
		c.desc += ",3��ս��";
		c.zy = 3;
	}
	_costs.insert(std::make_pair(e, c));
}


void txtSkill::insertAct(eSkill e, ulong a1, ulong a2 /*= 0*/, ulong a3 /*= 0*/)
{
	_uids.clear();
	_uids.push_back(a1);
	if (a2 > 0)
	{
		_uids.push_back(a2);
	}
	if (a3 > 0)
	{
		_uids.push_back(a3);
	}
	_acts.insert(std::make_pair(e, _uids));
}

void txtSkill::insertHit(eSkill e, ulong a1, ulong a2 /*= 0*/, ulong a3 /*= 0*/)
{
	_uids.clear();
	_uids.push_back(a1);
	if (a2 > 0)
	{
		_uids.push_back(a2);
	}
	if (a3 > 0)
	{
		_uids.push_back(a3);
	}
	_hits.insert(std::make_pair(e, _uids));
}


void txtSkill::insertEffect(eSkill e, eSkiPos pos /*= eSkiPos::Mid*/, bool zTop /*= false*/)
{
	_effect.pos = pos;
	_effect.zTop = zTop;
	_effects.insert(std::make_pair(e, _effect));
}

void txtSkill::insertEffect(eSkill e, bool zTop)
{
	insertEffect(e, eSkiPos::Mid, zTop);
}



void txtSkill::initFushi()
{
	//////////////////////////////////////////////////////////////////////////
	_fushis.push_back(eSkill::��ջ���);
	_fushis.push_back(eSkill::����);
	_fushis.push_back(eSkill::��������);
	_fushis.push_back(eSkill::�ն�����);
	_fushis.push_back(eSkill::��ڤ����);
	_fushis.push_back(eSkill::��������);
	_fushis.push_back(eSkill::ħ������);
	_fushis.push_back(eSkill::������);
	_fushis.push_back(eSkill::��˿��);
	_fushis.push_back(eSkill::���Ǿ�);
	_fushis.push_back(eSkill::���ⱦ��);

	//////////////////////////////////////////////////////////////////////////
	_zhuijias.push_back(eSkill::��ɨǧ��);
	_zhuijias.push_back(eSkill::���׷�);
	_zhuijias.push_back(eSkill::��������);
	_zhuijias.push_back(eSkill::���컨��);
	_zhuijias.push_back(eSkill::����);
	_zhuijias.push_back(eSkill::�������);
	_zhuijias.push_back(eSkill::����);

	_zhuijias.push_back(eSkill::������);
	_zhuijias.push_back(eSkill::�չ⻪);
	_zhuijias.push_back(eSkill::��׺�);
	_zhuijias.push_back(eSkill::������);
	_zhuijias.push_back(eSkill::��ã��);
	_zhuijias.push_back(eSkill::���ѻ�);

	_zhuijias.push_back(eSkill::������);
	_zhuijias.push_back(eSkill::�й���);
	_zhuijias.push_back(eSkill::ʬ����);

	_zhuijias.push_back(eSkill::��ɰ��ʯ);
	_zhuijias.push_back(eSkill::�������);
	_zhuijias.push_back(eSkill::�޵�ţʭ);

	_zhuijias.push_back(eSkill::����);
	_zhuijias.push_back(eSkill::����);

	_zhuijias.push_back(eSkill::��ӿ);

	_zhuijias.push_back(eSkill::������);

	_zhuijias.push_back(eSkill::��Ҷ����);
	_zhuijias.push_back(eSkill::������);
	_zhuijias.push_back(eSkill::������);
	_zhuijias.push_back(eSkill::����ŭ);


	_zhuijias.push_back(eSkill::�׻�);
	_zhuijias.push_back(eSkill::������);
	_zhuijias.push_back(eSkill::����);
	_zhuijias.push_back(eSkill::̩ɽѹ��);
	_zhuijias.push_back(eSkill::ˮ��);
	_zhuijias.push_back(eSkill::ˮ����ɽ);
	_zhuijias.push_back(eSkill::�һ�);
	_zhuijias.push_back(eSkill::�����һ�);
	_zhuijias.push_back(eSkill::����һ��);
	_zhuijias.push_back(eSkill::ҹ�����);
	_zhuijias.push_back(eSkill::�����ٻ�);
	_zhuijias.push_back(eSkill::������ɽ);
	_zhuijias.push_back(eSkill::�ƶ��б�);
	_zhuijias.push_back(eSkill::���ݻ���);

	_zhuijias.push_back(eSkill::�콵���);
	_zhuijias.push_back(eSkill::�¹�);

	_zhuijias.push_back(eSkill::�����ķ�);
}



void txtSkill::initActs()
{
	insertAct(eSkill::�׻�, 0x3200B6CC);
	insertAct(eSkill::������, 0x3200B6CC, 0x279AF873);
	insertAct(eSkill::����, 0xFDF34F35, 0x05391F73);
	insertAct(eSkill::̩ɽѹ��, 0x4E86F9B3);
	insertAct(eSkill::ˮ��, 0xCE33E201);
//	insertAct(eSkill::ˮ����ɽ, 0x4CE1ACB6);	// 0x439692DE, 0xC9BCA454, 0x60EB2F76, 
	insertAct(eSkill::�һ�, 0x22A3D764);
	insertAct(eSkill::�����һ�, 0xDED2253F);

	insertAct(eSkill::ҹ�����, 0x68E51BB6);

//  {eSkill::��ɨǧ��}
	insertAct(eSkill::������, 0x1EDD5D74, 0xBED8962A, 0x22DFD2EA);	// A5C6BDFB

};



void txtSkill::initEffect()
{
//	insertEffect(eSkill::����һ��:
	insertEffect(eSkill::ҹ�����, eSkiPos::Top, true);
	insertEffect(eSkill::�����ٻ�, eSkiPos::Bottom);
//	insertEffect(eSkill::������ɽ:
	insertEffect(eSkill::��������, true);
	insertEffect(eSkill::��η��ʩ, true);
	insertEffect(eSkill::��η��ʩ2, eSkiPos::Top, true);

//	insertEffect(eSkill::����ħ��:
	insertEffect(eSkill::̫������, eSkiPos::Bottom);
	insertEffect(eSkill::�޺�����, eSkiPos::Bottom);
//	insertEffect(eSkill::������:
	insertEffect(eSkill::�����޷�, eSkiPos::Top, true);
	insertEffect(eSkill::��������, eSkiPos::Top, true);


	insertEffect(eSkill::��ɨǧ��, eSkiPos::Bottom, true);
	insertEffect(eSkill::������, eSkiPos::Bottom);
	insertEffect(eSkill::ɱ����, eSkiPos::Bottom);
//	insertEffect(eSkill::����֮��:
	insertEffect(eSkill::�Ƹ�����, eSkiPos::Bottom, true);
	insertEffect(eSkill::�����, eSkiPos::Top, true);

	insertEffect(eSkill::���߷�, eSkiPos::Bottom);
	insertEffect(eSkill::ʧ�ķ�, eSkiPos::Bottom);
	insertEffect(eSkill::���Ƿ�, eSkiPos::Bottom);
	insertEffect(eSkill::ʧ���, eSkiPos::Bottom);
	insertEffect(eSkill::׷���, eSkiPos::Bottom);
	insertEffect(eSkill::����, eSkiPos::Bottom);
	insertEffect(eSkill::ʧ���, eSkiPos::Bottom);
	insertEffect(eSkill::�����, eSkiPos::Bottom);
//	insertEffect(eSkill::������:
//	insertEffect(eSkill::������:
	insertEffect(eSkill::��׷�, eSkiPos::Top, true);
//	insertEffect(eSkill::���׷�:

//	insertEffect(eSkill::��Ħ����:
	insertEffect(eSkill::��ջ���, eSkiPos::Bottom);
	insertEffect(eSkill::Τ�ӻ���, eSkiPos::Bottom);
	insertEffect(eSkill::��ջ���, true);
	insertEffect(eSkill::��ջ���1, eSkiPos::Bottom);
	insertEffect(eSkill::��ջ���2, eSkiPos::Bottom, true);
	insertEffect(eSkill::һέ�ɽ�, true);
	insertEffect(eSkill::���ޱ�, eSkiPos::Bottom, true);

//	insertEffect(eSkill::�黨��ָ:
//	insertEffect(eSkill::��������:
	insertEffect(eSkill::��������, eSkiPos::Bottom, true);
	insertEffect(eSkill::���컨��, eSkiPos::Bottom, true);
//	insertEffect(eSkill::����޺�:
	insertEffect(eSkill::��������, eSkiPos::Bottom);
	insertEffect(eSkill::�绨����, eSkiPos::Bottom);
	insertEffect(eSkill::��������, eSkiPos::Bottom);
// 	insertEffect(eSkill::��Ë���:
// 	insertEffect(eSkill::�����ë:
// 	insertEffect(eSkill::�ٶ�����:
// 	insertEffect(eSkill::���λ�Ӱ:
	insertEffect(eSkill::һЦ���, eSkiPos::Bottom);
// 	insertEffect(eSkill::�ɻ�ժҶ:
// 	insertEffect(eSkill::���亮ɳ:

	insertEffect(eSkill::������, eSkiPos::Top, true);
// 	insertEffect(eSkill::���񻤷�:
// 	insertEffect(eSkill::�������:
// 	insertEffect(eSkill::֪��֪��:
// 	insertEffect(eSkill::����:
	insertEffect(eSkill::����, eSkiPos::Bottom);
	insertEffect(eSkill::����, eSkiPos::Bottom, true);
	insertEffect(eSkill::�������, eSkiPos::Bottom);
//	insertEffect(eSkill::�����:
// 	insertEffect(eSkill::�������:
// 	insertEffect(eSkill::��Ȼ����:
// 	insertEffect(eSkill::������:

	insertEffect(eSkill::����, eSkiPos::Bottom);
// 	insertEffect(eSkill::�˷�����:
// 	insertEffect(eSkill::��Х����:
	insertEffect(eSkill::������β, eSkiPos::Bottom, true);

	insertEffect(eSkill::����Ǭ��, eSkiPos::Bottom, true);
	insertEffect(eSkill::��������, eSkiPos::Top, true);
	insertEffect(eSkill::����֮Ȫ, eSkiPos::Top, true);
//	insertEffect(eSkill::��ħ:
//	insertEffect(eSkill::���ͬ��:
//	insertEffect(eSkill::Ǭ���:
//	insertEffect(eSkill::һ��������:

	insertEffect(eSkill::�ն�����, eSkiPos::Top, true);
	insertEffect(eSkill::������, eSkiPos::Top, true);
	insertEffect(eSkill::������¶, eSkiPos::Top, true);
// 	insertEffect(eSkill::�չ⻪:
// 	insertEffect(eSkill::��׺�:
// 	insertEffect(eSkill::������:
// 	insertEffect(eSkill::��ã��:
// 	insertEffect(eSkill::���ѻ�:
//	insertEffect(eSkill::���д�λ:
	insertEffect(eSkill::�鶯����, eSkiPos::Top, true);
	insertEffect(eSkill::�ߵ�����, eSkiPos::Bottom);
//	insertEffect(eSkill::�����:

//	insertEffect(eSkill::������:
	insertEffect(eSkill::��ڤ����, true);
//	insertEffect(eSkill::ԩ�겻ɢ:
	insertEffect(eSkill::ʬ����, eSkiPos::Bottom, true);
//	insertEffect(eSkill::��������:
//	insertEffect(eSkill::������:
	insertEffect(eSkill::��Ȫ֮Ϣ, eSkiPos::Bottom, true);
//	insertEffect(eSkill::�����ɢ:
	insertEffect(eSkill::������, true);

	insertEffect(eSkill::ţ��, true);
//	insertEffect(eSkill::̤ɽ��ʯ:
	insertEffect(eSkill::ħ������, true);
//	insertEffect(eSkill::�����:
//	insertEffect(eSkill::ҡͷ��β:

	insertEffect(eSkill::����, eSkiPos::Bottom);
	insertEffect(eSkill::ӥ��, eSkiPos::Bottom, true);
	insertEffect(eSkill::����, eSkiPos::Bottom, true);
	insertEffect(eSkill::����, true);
//	insertEffect(eSkill::ħ��Х��:
	insertEffect(eSkill::������, true);
	insertEffect(eSkill::���ȷ��, true);
//	insertEffect(eSkill::��ħ����:

	insertEffect(eSkill::ħ�����, eSkiPos::Bottom);
// 	insertEffect(eSkill::��˿��:
// 	insertEffect(eSkill::������˿:
	insertEffect(eSkill::��������, eSkiPos::Bottom);
	insertEffect(eSkill::��˿��, true);
//	insertEffect(eSkill::����:
	insertEffect(eSkill::���޵���, eSkiPos::Bottom);
// 	insertEffect(eSkill::����ͬ��:
// 	insertEffect(eSkill::����:
	insertEffect(eSkill::�þ���, true);

// 	insertEffect(eSkill::��ʯ:
// 	insertEffect(eSkill::������:
// 	insertEffect(eSkill::�������:
// 	insertEffect(eSkill::��ӿ:
// 	insertEffect(eSkill::����ŭ:
// 	insertEffect(eSkill::��������:
// 	insertEffect(eSkill::����:
// 	insertEffect(eSkill::ָ�سɸ�:
// 	insertEffect(eSkill::������ɽ:
	insertEffect(eSkill::ս��1, eSkiPos::Top, true);
	insertEffect(eSkill::���Ǿ�, eSkiPos::Top, true);
	insertEffect(eSkill::����, eSkiPos::Top, true);
// 	insertEffect(eSkill::�����ƿ�:
// 	insertEffect(eSkill::�������:
// 	insertEffect(eSkill::�ݵؽ��:

	insertEffect(eSkill::�ƻ껯��, eSkiPos::Top, true);
	insertEffect(eSkill::������, eSkiPos::Bottom);
// 	insertEffect(eSkill::ɷ����:
// 	insertEffect(eSkill::������:
	insertEffect(eSkill::������, eSkiPos::Bottom, true);
	insertEffect(eSkill::���ⱦ��, eSkiPos::Top, true);
	insertEffect(eSkill::��������, true);
//	insertEffect(eSkill::��ľ���:
//	insertEffect(eSkill::Ԫ������:
//	insertEffect(eSkill::�ɼ�����:

// 	insertEffect(eSkill::������:
// 	insertEffect(eSkill::������:
// 	insertEffect(eSkill::����ŭ:
	insertEffect(eSkill::��ɱ, eSkiPos::Top, true);
	insertEffect(eSkill::Ѫ��, eSkiPos::Bottom);
	insertEffect(eSkill::�׻�, eSkiPos::Top, true);
//	insertEffect(eSkill::��ľ߽��:
	insertEffect(eSkill::����, eSkiPos::Top, true);
//	insertEffect(eSkill::����ʴ��:
}



bool txtSkill::isEd(eSkill e)
{
	return e >= eSkill::eSkied0 && e <= eSkill::eSkiedEnd;
}

bool txtSkill::isMenpai(eSkill e)
{
	return e >= eSkill::eMain0 && e <= eSkill::eMainEnd;
}

bool txtSkill::isF1(eSkill e)
{
	switch (e)
	{
	case eSkill::ǧ������:
	case eSkill::��ľ�ɶ�:
	case eSkill::�����ն�:
	case eSkill::���λ�Ӱ:
	case eSkill::���Ƽ���:
	case eSkill::ˮ��:
	case eSkill::��ת����:
	case eSkill::����:
	case eSkill::������Ѷ:
	case eSkill::ţʺ��:
	case eSkill::���ǧ��:
	case eSkill::���˿:
	case eSkill::�ݵؽ��:
	case eSkill::�ݵ���:
	case eSkill::Ҷ��:
		return true;
	}
	return false;
}

bool txtSkill::isPet(eSkill e)
{
	return e >= eSkill::ePetSki0 && e <= eSkill::ePetSkiEnd;
}

bool txtSkill::isSpecial(eSkill e)
{
	return e >= eSkill::eSpecial0 && e <= eSkill::eSpecialEnd;
}



int txtSkill::getTargetsCount(eSkill e)
{
	switch (e)
	{
	case eSkill::��Ѫ��:
		return 2;
	case eSkill::������:
	case eSkill::̩ɽѹ��:
	case eSkill::ˮ����ɽ:
	case eSkill::�����һ�:
	case eSkill::�����ķ�:
		return 3;
	case eSkill::�¹�:
		return 4;
	case eSkill::�콵���:
		return 5;
	case eSkill::���Ǵ�:
		return 9;
	case eSkill::�ĺ���ƽ:
	case eSkill::�����:
	case eSkill::�����:
	case eSkill::����ħ��:
	case eSkill::ħ��֮ӡ:
	case eSkill::ʥ��֮��:
	case eSkill::Х���:
	case eSkill::�޺�����:
	case eSkill::�Ӷ�ʨ��:
	case eSkill::�����:
	case eSkill::ͣ����:
	case eSkill::�Ⱥ��ն�:
		return 10;
	}
	return 1;
}


bool txtSkill::isTargetAtked(eSkill e)
{
	switch (e)
	{
	case eSkill::��ɨǧ��:
	case eSkill::������:
	case eSkill::�Ƹ�����:
	case eSkill::�Ƹ�����2:
	case eSkill::������:
	case eSkill::���׷�:

	case eSkill::��������:

	case eSkill::����ն:
	case eSkill::���׺䶥:
	case eSkill::�������:

	case eSkill::����:
	case eSkill::�������:
	case eSkill::����:
	case eSkill::����Ϸ��:

	case eSkill::���꽣��:
	case eSkill::Ʈ��ʽ:

	case eSkill::�չ⻪:
	case eSkill::��׺�:
	case eSkill::������:
	case eSkill::��ã��:
	case eSkill::���ѻ�:

	case eSkill::������:
	case eSkill::�й���:
	case eSkill::ʬ����:
	case eSkill::��Ȫ֮Ϣ:

	case eSkill::��ɰ��ʯ:
	case eSkill::�������:

	case eSkill::����:
	case eSkill::ӥ��:
	case eSkill::ʨ��:
	case eSkill::������:

	case eSkill::����:
	case eSkill::����:
	case eSkill::���޵���:

	case eSkill::��ʯ:
	case eSkill::������:
	case eSkill::�������:
	case eSkill::����ŭ2:
	case eSkill::��������2:

	case eSkill::������:
	case eSkill::������:

	case eSkill::��Ҷ����:
	case eSkill::������:
	case eSkill::������:
	case eSkill::����ŭ:
	case eSkill::��ɱ:
	case eSkill::Ѫ��:

	case eSkill::�׻�:
	case eSkill::������:
	case eSkill::����:
	case eSkill::̩ɽѹ��:
	case eSkill::ˮ��:
	case eSkill::ˮ����ɽ:
	case eSkill::�һ�:
	case eSkill::�����һ�:

	case eSkill::����һ��:
	case eSkill::ҹ�����:
	case eSkill::�����ٻ�:
	case eSkill::�ƶ��б�:
	case eSkill::���ݻ���:
	case eSkill::�����ķ�:
	case eSkill::�콵���:
	case eSkill::�¹�:
	case eSkill::���Ǵ�:

	case eSkill::��Ѫ��:
	case eSkill::�������:
	case eSkill::������˫:
		return true;
	}
	return false;
}

bool txtSkill::isTargetsTeam(eSkill e)
{
	switch (e)
	{
	case eSkill::��������:
	case eSkill::�������:
	case eSkill::�������:
	case eSkill::����:
	case eSkill::����Ϸ��:
	case eSkill::��ɰ��ʯ:
	case eSkill::��������:
	case eSkill::��Ҷ����:
	case eSkill::̩ɽѹ��:
	case eSkill::ˮ����ɽ:
	case eSkill::�����һ�:
	case eSkill::���Ǵ�:
		return true;
	}
	return false;
}


void txtSkill::applyIterPos(ulong actid, eSkiPos& pos)
{
	switch (actid)
	{
	case 0xB073119D: // 14 ����
	case 0x2406DA40: // 15 ʧ��
	case 0x5BCBB64F: // 28 ����

	case 0xF71DEAF7: // 31ߴߴ����
//	case 0x9E4E9755: // 35 ����

	case 0x2C2DA419: // 89 ����Ǭ��
	case 0x1CFE70FA: // 90 ����
	case 0x7C7D67A6: // 91 ���
	case 0x46038131: // 105 �չ⻪
	case 0x2DEE722A: // 108 ��ã
	case 0x09CCB0F3: // 112 �鶯
	case 0xD6BF55AD: // 115 �����ķ�
	case 0x2711A4A3: // 117 �й���
	case 0xB0FDC1B2: // 154 ����
	case 0x1C57DA8A: // 154 ����
	case 0x0E1DCDB9: // 187 ���ⱦ ����ƫ
	case 0xADF90980: // 201 �׻�
	case 0x3200B6CC: // 2084 2085 �׻� 
		pos = eSkiPos::Bottom;
		break;
	case 0x0116C932: // 27 ���
	case 0x9A94D461: // 68 ����
	case 0x6044E21A: // ����
//	case 0xCEAF0E44: // 159 ��������
		pos = eSkiPos::Mid;
		break;
	}
}


void txtSkill::applyAtkedDelta(ulong atkid, int& delta)
{
	switch (atkid)
	{
	case 0xF71DEAF7: // 31ߴߴ����
	case 0x774B7CEF: // 132 �������
		delta /= 2;
		break;
	case 0xC4FABE4C: // 107 ������
	case 0x2DEE722A: // 108 ��ã��
		delta /= 3;
		break;
	default:
		if (delta <= 8)
		{
			delta = 1;
		}
		else if (delta <= 12)
		{
			delta = 2;
		}
		else
		{
			delta = 5;
		}
	}
}




txtSkill::txtSkill()
{
	insert(0x0E30CD44, 0x00000000, 0xDDD270F5, eSkill::�׻�);
	insert(0xF54C4025, 0x00000000, 0x040584F3, eSkill::������, eSkiPos::Bottom);
	insert(0x0AC30DE6, 0x00000000, 0x564F1090, eSkill::����, eSkiPos::Bottom);
	insert(0x783F9D20, 0x00000000, 0x22FEF25E, eSkill::̩ɽѹ��);
	insert(0xF933209B, 0x00000000, 0x0071B681, eSkill::ˮ��, eSkiPos::Bottom);
	// 
	insert(0x97311BAD, 0x00000000, 0x4F09C15D, eSkill::ˮ����ɽ);
	insert(0xD112913D, 0x00000000, 0x3E2A375C, eSkill::�һ�, eSkiPos::Bottom);
	insert(0x139426B5, 0x00000000, 0x2E88DCF4, eSkill::�����һ�);
	insert(0x3BA4B993, 0x00000000, 0x675E4E20, eSkill::����һ��);
	// ��צӡ״̬,��η��ʩ2Ҳ��
	insert(0xF18C76DD, 0x5525C5FB, 0x9609FDF4, eSkill::ҹ�����, eSkiPos::Bottom);
	// 0x19182964
	insert(0x4E02EC44, 0x2C6223D4, 0x739A0BAB, eSkill::�����ٻ�);
	insert(0xFF33B0EE, 0x00000000, 0x00000000, eSkill::������ɽ, eSkiPos::Bottom);
	insert(0x729ADE62, 0x00000000, 0x0504D379, eSkill::�����ķ�);
	insert(0x00000000, 0xDEDEE983, 0x00000000, eSkill::��������, eSkiType::BattleSelf);
	insert(0x8D8A818D, 0x00000000, 0x2174467F, eSkill::�ƶ��б�);
	insert(0x99DDC32A, 0x00000000, 0x0504D379, eSkill::���ݻ���);

	insert(0xFB90D9B1, 0x2F3E4271, 0x1353874F, eSkill::��η��ʩ, eSkiType::BattleOwnerButSelf, eSkiPos::Top);
	insert(0xDCD7A875, 0x00000000, 0x00000000, eSkill::�콵���, eSkiPos::Bottom);
	insert(0x28DC0E4B, 0x00000000, 0x9609FDF4, eSkill::�¹�, eSkiPos::Bottom);
//	insert(0x00000000, 0x00000000, 0x00000000, eSkill::�Ϲ����, eSkiPos::Bottom);
	insert(0x35AA81A7, 0x00000000, 0x00000000, eSkill::���Ǵ�);

	insert(0xF3B31E4E, 0x00000000, 0x53E82E61, eSkill::������, eSkiType::BattleOwner);
	insert(0xFBF89980, 0x00000000, 0xE6339003, eSkill::������, eSkiType::BattleOwner);
	insert(0xF3B31E4E, 0x00000000, 0x53E82E61, eSkill::������, eSkiType::BattleOwner);
	// 0x3240F0D4 �ó�
	insert(0x899241C3, 0x00000000, 0x4B800708, eSkill::������, eSkiType::BattleOwner, eSkiPos::Bottom);
	insert(0x7EE33126, 0x00000000, 0x4B800708, eSkill::�����, eSkiType::BattleOwner);
	insert(0xD077C3A0, 0x00000000, 0x53E82E61, eSkill::������, eSkiType::BattleSelf);
	insert(0x30F2B60C, 0x00000000, 0x53E82E61, eSkill::������, eSkiType::BattleSelf);
	insert(0xD077C3A0, 0x00000000, 0x04E42236, eSkill::�ĺ���ƽ, eSkiType::BattleOwner);
	insert(0x8E92AE82, 0x00000000, 0x97283C40, eSkill::�ػ���, eSkiType::BattleOwner, eSkiPos::Bottom);
	insert(0x8E92AE82, 0x00000000, 0x97283C40, eSkill::��������, eSkiType::BattleOwner, eSkiPos::Bottom);
	insert(0x17238B9F, 0x00000000, 0xE6339003, eSkill::ˮ���, eSkiType::BattleOwner, eSkiPos::Bottom);
	insert(0x17238B9F, 0x00000000, 0xE6339003, eSkill::�����, eSkiType::BattleOwner, eSkiPos::Bottom);
	insert(0x17238B9F, 0x00000000, 0xFBD946FB, eSkill::�����, eSkiType::BattleOwner, eSkiPos::Bottom);
	insert(0x66150076, 0x00000000, 0xFBD946FB, eSkill::�����, eSkiType::BattleOwner, eSkiPos::Bottom);
	insert(0x00000000, 0x00000000, 0xA0F588C2, eSkill::��λ1);
	insert(0x00000000, 0x00000000, 0xA0F588C2, eSkill::��λ2);
//  insert(0x00000000, 0x00000000, 0xA0F588C2, eSkill::����֮��, eSkillUse::BattleOther);
//  insert(0x00000000, 0x00000000, 0xA0F588C2, eSkill::����֮��, eSkillUse::BattleOther);

	insert(0x5DE57BA4, 0x00000000, 0xCE582B31, eSkill::Ц��ص�);
	insert(0x5DE57BA4, 0x00000000, 0x245321A8, eSkill::����ħ��);
	insert(0x203B8C75, 0x00000000, 0x019B0A72, eSkill::Ұ��֮��, eSkiType::BattleOwner, eSkiPos::Bottom);
	insert(0x203B8C75, 0x00000000, 0x019B0A72, eSkill::ħ��֮ӡ, eSkiType::BattleOwner, eSkiPos::Bottom);
	insert(0x38FD76EA, 0x00000000, 0x245321A8, eSkill::���֮��, eSkiType::BattleOwner);
	insert(0x38FD76EA, 0x00000000, 0x245321A8, eSkill::ʥ��֮��, eSkiType::BattleOwner);
	insert(0xFE27EBCF, 0x00000000, 0xBF36842D, eSkill::���ƾ�, eSkiType::BattleOwner, eSkiPos::Bottom);
	insert(0xFE27EBCF, 0x00000000, 0xBF36842D, eSkill::Х���, eSkiType::BattleOwner, eSkiPos::Bottom);
	insert(0x9B23F38E, 0x5C5C1544, 0x3BF3590C, eSkill::̫������, eSkiType::BattleSelf);
	insert(0x9B23F38E, 0x5C5C1544, 0x3BF3590C, eSkill::�޺�����, eSkiType::BattleOwner);
	insert(0x95065313, 0x547C4B68, 0x1A67E919, eSkill::������, eSkiType::BattleOwner);
	insert(0xC183DB1E, 0xFAF4A2D4, 0x40701F91, eSkill::�����޷�, eSkiType::BattleOwner, eSkiPos::Bottom);
	insert(0x81B4599F, 0x00000000, 0x426F46C8, eSkill::��������, eSkiPos::Bottom);
	insert(0x81B4599F, 0x00000000, 0x426F46C8, eSkill::�Ӷ�ʨ��, eSkiPos::Bottom);
	insert(0xD0EEC915, 0x00000000, 0x70F1E396, eSkill::�Ƽ���);
	insert(0xD0EEC915, 0x00000000, 0x70F1E396, eSkill::�����);
	insert(0xD1E593CE, 0x00000000, 0x70F1E396, eSkill::������, eSkiPos::Bottom);
	insert(0xD1E593CE, 0x00000000, 0x70F1E396, eSkill::ͣ����, eSkiPos::Bottom);
	insert(0x171544B2, 0x00000000, 0x4B800708, eSkill::��Ѫ��);
	insert(0xB1822745, 0x00000000, 0x4B800708, eSkill::�������);
	insert(0x00000000, 0x00000000, 0x00000000, eSkill::��λ3);
	insert(0x00000000, 0x00000000, 0x00000000, eSkill::��λ4);
	insert(0x33084AA4, 0x00000000, 0x00000000, eSkill::�Ǳ�ʥ��, eSkiType::BattleOwner);
	insert(0x4F116543, 0x00000000, 0x00000000, eSkill::������EX, eSkiType::BattleOwner);
	insert(0x21FAE73F, 0x00000000, 0x00000000, eSkill::������˫);
	insert(0x00000000, 0x00000000, 0x00000000, eSkill::��λ5);
	insert(0x00000000, 0x00000000, 0x4B800708, eSkill::��Ѫ��2);
	insert(0x00000000, 0x00000000, 0x4B800708, eSkill::�������EX);
	insert(0x00000000, 0x00000000, 0x4B800708, eSkill::��Ѫ��EX);
	insert(0x00000000, 0x00000000, 0x104B1B46, eSkill::��λ6);
	insert(0xF224F08A, 0x00000000, 0x00000000, eSkill::���֮ǽ, eSkiType::BattleOwner);
	insert(0x1ADABFA6, 0xE43459EB, 0x40701F91, eSkill::��������, eSkiType::BattleSelf);
	insert(0xE1084D39, 0x00000000, 0x00000000, eSkill::�Ⱥ��ն�, eSkiType::BattleOwner, eSkiPos::Bottom);
	insert(0x95473D14, 0x00000000, 0x00000000, eSkill::Ѹ�����, eSkiType::BattleOwner);

	// ��Ϣ 0xD9463A0C
	insert(0x19C102D1, 0x56E05B32, 0x30D78CEF, eSkill::��ɨǧ��);
	insert(968268166, 0x2A2A0663, 0x39D047A5, eSkill::������);
	insert(0x00000000, 0x00000000, 0xED520CA0, eSkill::������);
	insert(0x00000000, 0x00000000, 0x04E0F4C5, eSkill::ǧ������);
	insert(0x94A5BEEC, 0x85B3D6F1, 0x00000000, eSkill::ɱ����, eSkiType::BattleOwner, eBuff::Good);
	insert(0x19C102D1, 0x00000000, 0x00000000, eSkill::ն����, eSkiPos::Bottom);
	insert(0x6B934898, 0x00000000, 0x0B2ED764, eSkill::����֮��, eBuff::Seal);
	insert(0x559C8ECF, 0x56E05B32, 0x795E59BA, eSkill::�Ƹ�����);
	insert(0x25F14A5E, 0x34999043, 0x095B5FC6, eSkill::�����, eSkiType::BattleSelf, eBuff::Good, eSkiPos::Bottom);
	insert(0x00000000, 0x00000000, 0x00000000, eSkill::��Ѫ);

	insert(0x00000000, 0x00000000, 0x00000000, eSkill::������ħ, eSkiPos::Bottom);
	insert(0x387C1EEB, 0x00000000, 0xDDD270F5, eSkill::������, eSkiPos::Bottom);
	insert(0x00000000, 0x00000000, 0x00000000, eSkill::���з�);
	insert(0x00000000, 0x00000000, 0xA309D8A4, eSkill::�����, eSkiType::BattleSelf);
	insert(0x9EC0624E, 3398426285, 0xAEABE4AC, eSkill::���߷�, eBuff::Seal);
	insert(0x091ADDC7, 3635978625, 0x9A1A2884, eSkill::ʧ�ķ�, eBuff::Seal);
	insert(0x4FB56243, 0x8B43833D, 0xF6BED451, eSkill::���Ƿ�, eBuff::Seal);
	insert(0xD4AA2F8A, 3946646209, 0xF6BED451, eSkill::ʧ���, eBuff::Seal);
	insert(0xD4024676, 3655438388, 0xF6BED451, eSkill::׷���, eBuff::Seal);
	insert(0x1919B112, 1214058823, 0xF6BED451, eSkill::����, eBuff::Seal);
	insert(0x7BCD8BC0, 2336457533, 0xF6BED451, eSkill::ʧ���, eBuff::Seal);
	insert(0xDE4E3A84, 2461182746, 0xF6BED451, eSkill::�����, eBuff::Seal);
	insert(0x517656E2, 0x00000000, 0x04E42236, eSkill::��Ԫ��, eSkiType::BattleSelf);
	insert(0x517656E2, 0x00000000, 0x04E42236, eSkill::������, eSkiType::BattleSelf);
	insert(0x00000000, 0x00000000, 0x00000000, eSkill::Ǭ�����);
	insert(0x00000000, 0x00000000, 0xA309D8A4, eSkill::��ľ�ɶ�);
	insert(0x4B9ACA92, 0x00000000, 0x4644FF98, eSkill::������, eSkiType::BattleSelf, eBuff::Good);
	// 0x84FA9FA5 ��,���Ǽ� ״̬0x5525C5FB
	insert(0xCB3B68B8, 0xA5D7B0F7, 0xAEABE4AC, eSkill::��׷�, eBuff::Bad, eSkiPos::Bottom);
	insert(0xC1731A60, 0x00000000, 0xDDD270F5, eSkill::���׷�);
	insert(0x00000000, 0x00000000, 0x00000000, eSkill::�������);

	insert(0x00000000, 0x00000000, 0x00000000, eSkill::��������);
	insert(0xC12C2663, 0x00000000, 0xDBB88662, eSkill::��������);
	insert(0x00000000, 0x00000000, 0x00000000, eSkill::��Ħ����);
	insert(0x04DB6C0A, 0x00000000, 0xC0A21592, eSkill::��ջ���, eSkiType::BattleOwner, eBuff::Good);
	insert(0x434750DE, 0x85B3D6F1, 0xBF36842D, eSkill::Τ�ӻ���, eSkiType::BattleOwner, eBuff::Good, eSkiPos::Bottom);
	// 0x38C2146B ״̬ 916220457 
	insert(0x9E4E9755, 0x369C6A29, 0xC0A21592, eSkill::��ջ���, eSkiType::BattleOwner, eBuff::Good, eSkiPos::Bottom);
	// 0xF354CCB8
	insert(0x93CFD0AF, 0x061869D7, 0xBF36842D, eSkill::һέ�ɽ�, eSkiType::BattleOwner, eBuff::Good);
	insert(0x203B8773, 0x00000000, 0x97283C40, eSkill::�ҷ�ȱ�, eSkiType::BattleOwner);
	insert(0x573F92CA, 0x00000000, 0x04E42236, eSkill::����, eSkiType::BattleSelf);
	insert(0x03139F50, 0x00000000, 0x04E42236, eSkill::��Ѫ, eSkiType::BattleOwner);
	insert(0xEF9691F3, 0x00000000, 0x04E42236, eSkill::��������, eSkiType::BattleOwner);
	insert(0xE869B98A, 0x00000000, 0x04E42236, eSkill::���ֻش�, eSkiType::BattleOwner);
	// 0x28E639AA
	insert(0x7EEC276B, 0x00000000, 0x04E42236, eSkill::��������, eSkiType::BattleOwner);
	insert(0xDE34B83E, 0x00000000, 0x57726FFB, eSkill::�ⶾ, eSkiType::BattleOwner);
	insert(0x00000000, 0x00000000, 0x084168D9, eSkill::�����ն�);
	insert(0xF0CE9045, 0x00000000, 0xCE259E8C, eSkill::����ȡ��, eSkiType::BattleOwner, eSkiPos::Bottom);
	insert(0xC8011EF1, 3930943562, 0x3E128ADA, eSkill::���ޱ�, eSkiType::BattleOwner, eBuff::Good, eSkiPos::Bottom);
	insert(0x00000000, 0x00000000, 0x00000000, eSkill::�黨��ָ);

	insert(0x00000000, 0x00000000, 0x00000000, eSkill::��������);
	insert(0x182CE63B, 0x72AD6DBA, 0xBDCD9588, eSkill::��������, eSkiType::BattleSelf, eBuff::Good, eSkiPos::Bottom);
	insert(0x9D5F7277, 0xDBCEE32C, 0xC99B2900, eSkill::���컨��, eBuff::Poison, eSkiPos::Bottom);
	insert(0x00000000, 0x00000000, 0x00000000, eSkill::����޺�);
	insert(0x00000000, 0x00000000, 0x00000000, eSkill::��������);
	insert(0x8A39B79F, 0x00000000, 0xBDCD9588, eSkill::�绨����);
	insert(0x46C7B776, 0x59D77EF9, 0xBDCD9588, eSkill::��������, eBuff::Seal, eSkiPos::Bottom);
	insert(0x00000000, 0x00000000, 0x00000000, eSkill::��Ë���);
	insert(0x00000000, 0x00000000, 0x00000000, eSkill::�����ë);
	insert(0x00000000, 0x00000000, 0x00000000, eSkill::�ٶ�����);
	insert(0x00000000, 0x00000000, 0xFE189BCC, eSkill::���λ�Ӱ);
	insert(0x8A39B79F, 0x00000000, 0x51F82D7D, eSkill::һЦ���, eSkiPos::Bottom);
	insert(0x00000000, 0x00000000, 0x00000000, eSkill::�ɻ�ժҶ);
	insert(0x00000000, 0x00000000, 0x00000000, eSkill::���亮ɳ);

	insert(0x00000000, 0x66CC7A29, 0x00000000, eSkill::������, eSkiType::BattleSelf, eBuff::Good, eSkiPos::Top);
	insert(0x73604A57, 0x00000000, 0x00000000, eSkill::���񻤷�, eSkiType::BattleOwner, eBuff::Good);
	insert(0x00000000, 0x00000000, 0x00000000, eSkill::�������);
	insert(0x00000000, 0x00000000, 0x00000000, eSkill::֪��֪��);
	insert(0xDC756B6F, 0x00000000, 0x57726FFB, eSkill::����, eSkiType::BattleOwner);
	insert(0x1EB0026B, 0x98753F94, 0x318685B7, eSkill::����, eBuff::Seal, eSkiPos::Bottom);
	insert(0xD35FC051, 0x2F78C46E, 0x5703EB56, eSkill::����, eBuff::Seal, eSkiPos::Bottom);
	insert(0x8B8516F1, 0xC48ABA7B, 0x318685B7, eSkill::�������, eBuff::Seal, eSkiPos::Bottom);
	insert(0x00000000, 0x00000000, 0xA12CF973, eSkill::���Ƽ���);
	insert(0x4C117B7C, 0x00000000, 0x251670FB, eSkill::����ն, eSkiPos::Bottom);
	insert(0xFFD64CCA, 0x00000000, 0xDB4F9338, eSkill::���׺䶥, eSkiPos::Bottom);
	insert(0x00000000, 0x00000000, 0x00000000, eSkill::�����);
	insert(0x911E3921, 0x00000000, 0x040584F3, eSkill::�������);
	insert(0x00000000, 0x00000000, 0x00000000, eSkill::��Ȼ����);
	insert(0x752464D7, 0x00000000, 0x318685B7, eSkill::������, eBuff::Good);

	insert(0xDC756B6F, 0x00000000, 0x57726FFB, eSkill::���, eSkiType::BattleOwner);
	insert(0xDE34B83E, 0x00000000, 0x57726FFB, eSkill::����, eSkiType::BattleOwner);
	insert(0x7367AF0F, 0x00000000, 0x5505BC3C, eSkill::����, eSkiPos::Bottom);
	insert(0xA19EAB31, 0x00000000, 0xA39B4CA3, eSkill::�������);
	insert(0x04DB6C0A, 0x00000000, 0xC0A21592, eSkill::����, eSkiType::BattleSelf, eBuff::Good);
	insert(0x00000000, 0x00000000, 0x00000000, eSkill::�˷�����);
	insert(0x00000000, 0x00000000, 0x64AAF170, eSkill::ˮ��);
	insert(0x48639CF5, 0x00000000, 0xA08D7D31, eSkill::����);
	insert(0x00000000, 0x00000000, 0x00000000, eSkill::��Х����);
	insert(0x00000000, 0x00000000, 0x00000000, eSkill::����);
	insert(0xF483EB13, 0x4CCDACCB, 0x00000000, eSkill::������β, eSkiType::BattleSelf, eBuff::Good, eSkiPos::Bottom);
	insert(0xA680A821, 0x00000000, 0x6F872F79, eSkill::����Ϸ��);

	insert(0xA70D1263, 0x313BCC79, 0xA7B1C535, eSkill::����Ǭ��, eBuff::Seal, eSkiPos::Bottom);
	insert(0x3648247E, 0x719D767F, 0x24A434E5, eSkill::��������, eSkiType::BattleOwner, eBuff::Good, eSkiPos::Top);
	insert(0xD2DC9AD3, 0xF8EE853A, 0x24A434E5, eSkill::����֮Ȫ, eSkiType::BattleOwner, eBuff::Good, eSkiPos::Top);
	insert(0x00000000, 0x00000000, 0x00000000, eSkill::̫������);
	insert(0x00000000, 0x00000000, 0x9197B5A6, eSkill::��ת����);
	insert(0x775FD2E3, 0x00000000, 0x24A434E5, eSkill::�����۶�, eSkiType::BattleSelf);
	insert(0x00000000, 0x00000000, 0x00000000, eSkill::��ħ);
	insert(0xDE34B83E, 0x00000000, 0x57726FFB, eSkill::��ʬ, eSkiType::BattleOwner);
	// ���򶯻� 0xD06119B3 0xC29A0737
	insert(0xA3FD9577, 0x00000000, 0x30D78CEF, eSkill::���꽣��);
	insert(0x66BEBCBA, 0x00000000, 0x00000000, eSkill::Ʈ��ʽ);
	insert(0x00000000, 0x00000000, 0x00000000, eSkill::���ͬ��, eSkiType::BattleOwner, eBuff::Good);
	insert(0x00000000, 0x00000000, 0x00000000, eSkill::Ǭ���);
	insert(0x00000000, 0x00000000, 0x00000000, eSkill::һ��������);

	insert(0x2FF74578, 0xD8857128, 0x2550B4D0, eSkill::�ն�����, eSkiType::BattleOwner, eBuff::Good, eSkiPos::Bottom);
	// 0x5480C749
	insert(0x1EA5FACC, 0xEFE73EB9, 0xD00F519D, eSkill::������, eBuff::Bad, eSkiPos::Bottom);
	insert(0x380337C1, 0xD8857128, 0xA4B9B11E, eSkill::������¶, eSkiType::BattleOwner, eSkiPos::Bottom);
	insert(0x45CA9913, 0x00000000, 0xCE259E8C, eSkill::�չ⻪);
	insert(0x6C5F8376, 0x00000000, 0xE957CD44, eSkill::��׺�, eSkiPos::Bottom);
	insert(0xDF4C3BE3, 0x00000000, 0x52BA8E8D, eSkill::������, eSkiPos::Bottom);
	insert(0x9CCB6E84, 0x00000000, 0x251670FB, eSkill::��ã��);
	insert(0x18E13BE9, 0x00000000, 0x1366C86B, eSkill::���ѻ�, eSkiPos::Bottom);
	insert(0x00000000, 0x00000000, 0xEFB621F4, eSkill::����);
	insert(0x00000000, 0x00000000, 0x00000000, eSkill::���д�λ);
	insert(0xAB5DAE52, 0x95FF4460, 0x2550B4D0, eSkill::�鶯����, eSkiType::BattleOwner, eBuff::Good);
	// 0x5A07D50A ״̬0x4DDF5690
	insert(0x88F19652, 0x2D1E688F, 0xA37E8B19, eSkill::�ߵ�����, eSkiType::BattleOwner, eBuff::Good, eSkiPos::Bottom);
	insert(0x00000000, 0x00000000, 0x00000000, eSkill::�����);
	insert(0x77592664, 0x00000000, 0x00000000, eSkill::�����ķ�, eSkiType::BattleOwner);

	insert(0x9EB11259, 0x00000000, 0x12A308C0, eSkill::������, eSkiPos::Bottom);
	insert(0x241C668A, 0x00000000, 0xB6A8CB18, eSkill::�й���);;
	insert(0x00000000, 0x00000000, 0xED520CA0, eSkill::������);
	insert(0xDC756B6F, 0x00000000, 0x00000000, eSkill::������, eSkiType::BattleOwner);
	insert(0x07DF52CA, 0x21435203, 0xFBA099F0, eSkill::��ڤ����, eSkiType::BattleOwner, eBuff::Good);
	insert(0x00000000, 0x00000000, 0x00000000, eSkill::ԩ�겻ɢ);
	insert(0x849E48FB, 0x839CC29A, 0x98BDEC63, eSkill::ʬ����, eBuff::Poison, eSkiPos::Bottom);
	insert(0xBA7D5CD7, 0x00000000, 0x00000000, eSkill::��������, eSkiType::BattleOwner);
	insert(0x00000000, 0x00000000, 0xBB1E59E8, eSkill::������Ѷ);
	insert(0x380337C1, 0x00000000, 0x97283C40, eSkill::������, eSkiType::BattleOwner, eSkiPos::Bottom);
	// ״̬ 0x5ECEBEDD
	insert(0x2611E02E, 0x69180378, 0xBF36842D, eSkill::��Ȫ֮Ϣ, eBuff::Bad, eSkiPos::Bottom);
	insert(0x057B7209, 0x00000000, 0x814AE8F4, eSkill::�����ɢ, eSkiPos::Bottom);
	insert(0x00000000, 0x00000000, 0x00000000, eSkill::ʬ������);
	insert(0x5C0073EE, 0xE02F2E6D, 0x7FDACB76, eSkill::������);

	insert(0x00000000, 0x00000000, 0x00000000, eSkill::ħ������);
	insert(0x4DB67680, 0x00000000, 0x550EEC3F, eSkill::��ɰ��ʯ);
	insert(0xFCDCCCEC, 0x00000000, 0xF4A86696, eSkill::�������, eSkiPos::Bottom);
	insert(0x6EA4246E, 0xA168E26F, 0xED47E570, eSkill::ţ��, eSkiType::BattleSelf, eBuff::Good);
	insert(0x00000000, 0x00000000, 0x00000000, eSkill::̤ɽ��ʯ);
	insert(0x00000000, 0x00000000, 0x40E67E07, eSkill::�޵�ţʭ, eSkiType::BattleSelf);
	insert(0x00000000, 0x00000000, 0x40E67E07, eSkill::�޵�ţ��, eSkiType::BattleSelf);
	insert(0x16B27FFC, 0xBBEA83F4, 0x00000000, eSkill::ħ������, eSkiType::BattleSelf);
	insert(0x00000000, 0x00000000, 0x14E55AF2, eSkill::ţʺ��);
	insert(0x00000000, 0x00000000, 0x00000000, eSkill::�����);
	insert(0x00000000, 0x00000000, 0x00000000, eSkill::ҡͷ��β);

	insert(0xBE127823, 0x3646A4D9, 0x7CFA5491, eSkill::����);
	insert(2194212682, 0x58628406, 0x61688718, eSkill::ӥ��);
	insert(0x718754A2, 0x00000000, 0xF3626BEC, eSkill::ʨ��);
	insert(0x8476181B, 0x20FCCE94, 0x019B0A72, eSkill::����, eBuff::Seal);
	insert(0x29D819DF, 0x85C9AF08, 0xB90610BF, eSkill::����, eSkiType::BattleSelf);
	insert(0x00000000, 0x00000000, 0x00000000, eSkill::ħ��Х��);
	insert(755485932, 0x566DC0F3, 0x40701F91, eSkill::������, eSkiType::BattleSelf, eBuff::Good);
	insert(0x55EBCA6C, 0x58628406, 0x2FFC7F8A, eSkill::������);
	insert(0x00000000, 0x00000000, 0x35B1FE83, eSkill::���ǧ��);
	insert(0x16B27FFC, 0xBBEA83F4, 0x6961CB02, eSkill::���ȷ��, eSkiType::BattleSelf, eBuff::Good);
	insert(0x00000000, 0x00000000, 0x00000000, eSkill::ħϢ��);
	insert(0x3105A01B, 0x3D3FA597, 0x1C7EE63E, eSkill::��ħ����, eSkiType::BattleSelf);
	insert(0x00000000, 0x00000000, 0x00000000, eSkill::��������);

	insert(0x1B472F2F, 0x00000000, 0xC0942A07, eSkill::����);
	insert(0x59BD69F1, 0x00000000, 0xC0942A07, eSkill::����);
	insert(0x78246FE4, 0xC4AA8E18, 0xE6F9B619, eSkill::ħ�����, eBuff::Seal);
	insert(0x00000000, 0x00000000, 0x00000000, eSkill::��˿��);
	insert(0x00000000, 0x00000000, 0x00000000, eSkill::������˿);
	insert(0x5363AF2D, 0x8103AFD2, 0x7F5FD02A, eSkill::��������, eBuff::Seal, eSkiPos::Bottom);
	insert(0x7CD9C342, 0x369C6A29, 0xA37E8B19, eSkill::��˿��, eSkiType::BattleSelf, eBuff::Good);
	insert(0xDC756B6F, 0x00000000, 0x5007BB0C, eSkill::����, eSkiType::BattleSelf);
	insert(0x8F3E73D5, 0xD671B65E, 0x13848F75, eSkill::���޵���, eBuff::Seal, eSkiPos::Bottom);
	insert(0x00000000, 0x00000000, 0x95C06373, eSkill::���˿);
	insert(0x00000000, 0x00000000, 0xC0942A07, eSkill::����ͬ��);
	insert(0x00000000, 0x00000000, 0x00000000, eSkill::����);
	insert(0x0732894C, 0xCDE5D209, 0x245321A8, eSkill::�þ���, eSkiType::BattleSelf, eBuff::Good);

	insert(0x00000000, 0x00000000, 0x00000000, eSkill::��ʯ);
	insert(0x00000000, 0x00000000, 0x00000000, eSkill::������);
	insert(0x00000000, 0x00000000, 0x00000000, eSkill::�������);
	insert(0x00000000, 0x00000000, 0x00000000, eSkill::��ӿ);
	insert(0x00000000, 0x00000000, 0x00000000, eSkill::����ŭ, eSkiPos::Bottom);
	insert(0x00000000, 0x00000000, 0x00000000, eSkill::��������);
	insert(0x00000000, 0x00000000, 0x00000000, eSkill::����);
	insert(0x00000000, 0x00000000, 0x00000000, eSkill::ָ�سɸ�);
	insert(0x00000000, 0x00000000, 0x00000000, eSkill::������ɽ, eSkiType::BattleSelf, eBuff::Good, eSkiPos::Bottom);
	insert(0x00000000, 0x00000000, 0x00000000, eSkill::���Ǿ�, eSkiType::BattleOwner, eBuff::Good, eSkiPos::Top);
	insert(0x00000000, 0x00000000, 0x00000000, eSkill::����, eSkiType::BattleOwner, eBuff::Good, eSkiPos::Top);
	insert(0x00000000, 0x00000000, 0x00000000, eSkill::�����ƿ�);
	insert(0x00000000, 0x00000000, 0x00000000, eSkill::�������, eSkiType::BattleOwner);
	insert(0x00000000, 0x00000000, 0x00000000, eSkill::�ݵؽ��);

	insert(0x00000000, 0x00000000, 0x00000000, eSkill::�ƻ껯��, eSkiType::BattleOwner, eBuff::Good, eSkiPos::Bottom);
	insert(0x00000000, 0x00000000, 0x00000000, eSkill::������, eBuff::Seal, eSkiPos::Bottom);
	insert(0x00000000, 0x00000000, 0x00000000, eSkill::ɷ����);
	insert(0x00000000, 0x00000000, 0x00000000, eSkill::������);
	insert(0x00000000, 0x00000000, 0x00000000, eSkill::������, eBuff::Bad);
	insert(0x00000000, 0x00000000, 0x00000000, eSkill::������, eSkiPos::Bottom);
	insert(0x00000000, 0x00000000, 0x00000000, eSkill::���ⱦ��, eSkiType::BattleOwner);
	insert(0x00000000, 0x00000000, 0x00000000, eSkill::��������, eSkiType::BattleOwner, eSkiPos::Bottom);
	insert(0x00000000, 0x00000000, 0x00000000, eSkill::��ӿ����, eSkiType::BattleOwner, eSkiPos::Bottom);
	insert(0x00000000, 0x00000000, 0x00000000, eSkill::��ľ���);
	insert(0x00000000, 0x00000000, 0x00000000, eSkill::Ԫ������);
	insert(0x00000000, 0x00000000, 0x00000000, eSkill::�ݵ���);
	insert(0x00000000, 0x00000000, 0x00000000, eSkill::�ɼ�����, eSkiType::BattleOwner, eSkiPos::Bottom);

	insert(0x00000000, 0x00000000, 0x00000000, eSkill::��Ҷ����);
	insert(0x00000000, 0x00000000, 0x00000000, eSkill::������, eSkiPos::Bottom);
	insert(0x00000000, 0x00000000, 0x00000000, eSkill::������, eSkiPos::Bottom);
	insert(0x00000000, 0x00000000, 0x00000000, eSkill::����ŭ, eSkiPos::Bottom);
	insert(0x00000000, 0x00000000, 0x00000000, eSkill::��ɱ, eBuff::Bad, eSkiPos::Bottom);
	insert(0x00000000, 0x00000000, 0x00000000, eSkill::Ѫ��);
	insert(0x00000000, 0x00000000, 0x00000000, eSkill::����֮��, eSkiType::BattleSelf);
	insert(0x00000000, 0x00000000, 0x00000000, eSkill::�׻�, eSkiType::BattleSelf);
	insert(0x00000000, 0x00000000, 0x00000000, eSkill::Ҷ��);
	insert(0x00000000, 0x00000000, 0x00000000, eSkill::��ľ߽��);
	insert(0x00000000, 0x00000000, 0x00000000, eSkill::����, eSkiType::BattleOwner, eSkiPos::Top);
	insert(0x00000000, 0x00000000, 0x00000000, eSkill::����ʴ��);





	initActs();
	//////////////////////////////////////////////////////////////////////////
	insertHit(eSkill::��ɨǧ��, 0xACA4A54A, 0x3C45D282, 0xD862FBE7);
	// 0x19C102D1 ??? ����??? ��Ϣ??
	insertHit(eSkill::������2, 0x958FAC37);
	insertHit(eSkill::�Ƹ�����2, 0x301F9E4A, 0x6AD55205);
	
	insertHit(eSkill::����ն, 0xB6141EB9, 0xF17168C5, 0x885ACBE1);
	
	insertHit(eSkill::���꽣��, 0x4F8312F6, 0x9215D669, 0xD06119B3);
	insertHit(eSkill::Ʈ��ʽ, 0x3426ACE0);
	
	insertHit(eSkill::����, 0x73DA1CCF, 0x89302F40);
	insertHit(eSkill::ӥ��, 0xA463C055, 0x86FE2BC1, 0x83020DAE);
	insertHit(eSkill::ʨ��, 0x42F0386F, 0x096766A8);
	
	insertHit(eSkill::��ʯ, 0x958FAC37);
	insertHit(eSkill::������, 0x958FAC37);
	insertHit(eSkill::�������, 0x958FAC37);
	insertHit(eSkill::��ӿ, 0xD53A25EB);
	insertHit(eSkill::����ŭ2, 0xB94D0B94);
	insertHit(eSkill::��������2, 0xB94D0B94);
	//////////////////////////////////////////////////////////////////////////
	initFushi();
	//////////////////////////////////////////////////////////////////////////

	_stateExs.insert(std::make_pair(eSkill::��η��ʩ2, 0x5525C5FB));
	_stateExs.insert(std::make_pair(eSkill::��ջ���1, 0x592EBD89));
	_stateExs.insert(std::make_pair(eSkill::��ջ���2, 0x2F45B9F0));
	_stateExs.insert(std::make_pair(eSkill::ս��1, 0xC4FE8E3F));
	_stateExs.insert(std::make_pair(eSkill::ս��2, 0x3D3C8D10));
	_stateExs.insert(std::make_pair(eSkill::ս��3, 0xD1C3B611));
	//////////////////////////////////////////////////////////////////////////
	initEffect();
};



