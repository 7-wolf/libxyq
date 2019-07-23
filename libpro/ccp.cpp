#include "ccp.h"
#include "sBags.h"
////////////////////////////////////////////////////////////////////////// �������
void ccp::apply(sAttribute& attr, int skilv)
{
	float _atk = 0, _def = 0, _mana = 0, _evade = 0;
	for (int i = skilv; i > 0; --i)
	{
		_atk += 1.5f + 0.02f * i;
		_def += 1 + 0.02f * i;
		_mana += 0.5f + 0.01 * i;
		_evade += 2 + 0.02f * i;
	}

	attr.atk.ori += _atk;
	attr.def.ori += _def;
	attr.mana.ori += _mana;
	attr.evade.ori += _evade;
}


void ccp::apply(sAttribute& attr, int fzlv, int fzIdx)
{
	if (fzIdx == 0)
	{
		attr.hpMax.ori += fzlv * 5;
	}
	else if (fzIdx == 1)
	{
		attr.hpMax.per += fzlv;
	}
	else if (fzIdx == 2)
	{
		attr.mpMax.per += fzlv;
	}
}


void ccp::apply(sAttribute& attr, const sPoint& point)
{
	float _atk, _def, _hp, _mana, _mp, _speed, _evade, _hit;
	_atk = point.str/* * 7 / 9*/;
	_def = point.dex * 5 / 3;
	_hp = point.body * 5;
	_mana = point.mag * 7 + point.body * 3 + point.str * 4 + point.dex * 2;
	_mana /= 10;
	_mp = point.mag * 3;
	_speed = point.agi * 7 + point.body + point.str + point.dex;
	_speed /= 10;
	_evade = point.agi;
	_hit = point.str * 7 / 3;

	attr.atk.ori += _atk;
	attr.def.ori += _def;
	attr.hpMax.ori += _hp;
	attr.mpMax.ori += _mp;
	attr.mana.ori += _mana;
	attr.speed.ori += _speed;
	attr.hit.ori += _hit;
	attr.evade.ori += _evade;
}


void ccp::apply(sAttribute& attr, const sPoint& point, const sZz& zz, int lv)
{
	float _atk, _def, _hp, _mana, _mp, _speed, _evade, _hit;
	int _grow = zz.grow100;
	_atk = lv * zz.atk * (1400 + 10 * _grow) / 750000;
	_atk += point.str * _grow / 100;

	_def = (lv * zz.def) * 19 / 7500;
	_def += (point.dex * _grow * 4) / 300;

	_hp = (lv * zz.hp) / 1000;
	_hp += point.body * _grow * 6 / 100;

	_mana = lv * (zz.mag + 1640) * (_grow + 100) / 75000;
	_mana += point.body * 3 + point.mag * (7 + 3) + point.str * 4 + point.dex * 2;
	_mana /= 10;

	_mp = lv * zz.mag / 500 + _grow * point.mag * 3 / 100;

	_speed = zz.speed * point.agi / 1000;
	_evade = zz.evoid * point.agi / 300;

	_hit = sAttribute::cHit40 + _atk / 2;
	_hit += point.str * 5 / 2;

	attr.atk.ori += _atk;
	attr.def.ori += _def;
	attr.hpMax.ori += _hp;
	attr.mpMax.ori += _mp;
	attr.mana.ori += _mana;
	attr.speed.ori += _speed;
	attr.hit.ori += _hit;
	attr.evade.ori += _evade;
}



////////////////////////////////////////////////////////////////////////// ��������
std::string ccp::apply(sPropertyInfo& info, int3& speed, eMenpai menpai, int rlv /* = -1 */)
{
	switch (menpai)
	{
	case eMenpai::���ƹٸ�:
		if (rlv >= 0)
		{
			// ����
			info.pierceRate.d1 += 10;
		}
		return "+������";
	case eMenpai::������:
		if (rlv >= 0)
		{
			// ����
			info.damageCure.add.d1 += rlv;
			info.damageCure.add.d2 += rlv;
			info.criRateCure.d1 += 15;
		}
		return "+�ȱ�";
	case eMenpai::����ɽ:
		if (rlv >= 0)
		{
			// ����
			info.ghost.d2 += 50;
		}
		return "+����";
	case eMenpai::Ů����:
		if (rlv >= 0)
		{
			// �ٶ�
			speed.ori += rlv;
		}
		return "+�ٶ�";
	case eMenpai::��ׯ��:
		if (rlv >= 0)
		{
			// ��
			info.parryRate.d1 += 10;
		}
		return "+��";
	case eMenpai::ʨ����:
		if (rlv >= 0)
		{
			// ��Ѫ
			info.blood.rate.d1 += 20;
			info.blood.per.d1 += 10;
		}
		return "+��Ѫ";
	case eMenpai::ħ��կ:
		if (rlv >= 0)
		{
			// ����
			info.magicWave.d1 += 15;
		}
		return "+��������";
		break;
	case eMenpai::��˿��:
		if (rlv >= 0)
		{
			// ������
			info.damageArm.per2 += 100;
		}
		return "+��������";
	case eMenpai::���ܵظ�:
		if (rlv >= 0)
		{
			// ����
			info.hitRateSeal.dper += 20;
		}
		return "+��ӡ�ֿ�";
	case eMenpai::��������:
		if (rlv >= 0)
		{
			// ��������
			info.pierceRateMaigc.d1 += 10;
		}
		return "+��������";
	case eMenpai::����ɽ:
		if (rlv >= 0)
		{
			// ����
			int v = 15;
			info.fire.rate.d1 += v;
			info.soil.rate.d1 += v;
			info.water.rate.d1 += v;
			info.thunder.rate.d1 += v;
		}
		return "+��������";
	case eMenpai::�칬:
		if (rlv >= 0)
		{
			// ��
			info.liveStoreRate.d1 += 10;
		}
		return "+��";
	case eMenpai::�貨��:
		if (rlv >= 0)
		{
			// ����
			info.criRate.d1 += 5;
		}
		return "+������";
	case eMenpai::�޵׶�:
		if (rlv >= 0)
		{
			// ����
			info.liveHp.d1 += rlv;
		}
		return "+����";
	case eMenpai::��ľ��:
		if (rlv >= 0)
		{
			// ����
			info.comboRateMagic.d1 += 5;
		}
		return "+��������";
	}
	return "";
}


void ccp::apply(sPropertyInfo& info, const sXl& xl)
{
	info.damage.per.d1 += xl.lvs[0] * 2;
	info.damage.per.d2 += xl.lvs[0] * 2;
	info.damage.add.d1 += xl.lvs[1] * 5;
	info.damage.add.d2 += xl.lvs[1] * 5;

	info.damageMagic.per.d1 += xl.lvs[2] * 2;
	info.damageMagic.per.d2 += xl.lvs[2] * 2;
	info.damageMagic.add.d1 += xl.lvs[3] * 5;
	info.damageMagic.add.d2 += xl.lvs[3] * 5;

	info.hitRateSeal.d1 += xl.lvs[2] * 3 / 2;
	info.hitRateSeal.d2 += xl.lvs[3] * 3 / 2;
}


enum eFaBao
{
	eFaBao0������,
	eFaBao1�ɽ�Īа,
	eFaBao2�޺���,
	eFaBao3����,
//	eFaBao4����,
	eFaBao5������,
	eFaBao6��Ԫɡ,
	eFaBao7�޻����,
	eFaBao8Ǭ��������,
	eFaBao9�ն�,
	eFaBao10���س�,
	eFaBao11�¹ⱦ��,
	eFaBao16����,
	eFaBao17�ܽ����ְ�,
	eFaBao18ʱ֮��,
	eFaBao19ͨ�鱦��,
	eFaBao20�۱���,
	eFaBao21�����«,
	eFaBao22��ľ����,
	eFaBao23���뾵,
	eFaBao24��Ѫ�,
	eFaBao25�������,
	eFaBao26��ħ����,
	eFaBao27����,
	eFaBao28������ë,
	eFaBao29����,
	eFaBao30�������ӡ,
	eFaBao31����,
	eFaBao32�ȱ�,
	eFaBao33�ε�,
};

void ccp::apply(sPropertyInfo& info, int3& speed, int fabao)
{
	switch (fabao)
	{
	case eFaBao0������:
		info.damagePosion.per.d1 += 5;
		break;
	case eFaBao1�ɽ�Īа:
		info.damage.add.d1 += 50;
		break;
	case eFaBao2�޺���:
		info.mpSave.d1 += 10;
		break;
	case eFaBao3����:
		info.liveMp.d1 += 10;
		break;
	case eFaBao5������:
		info.ghost.d2 += 10;
		break;
	case eFaBao6��Ԫɡ:
		info.stabMagic.rate.d1 += 20;
		info.stabMagic.per.d1 += 5;
		break;
	case eFaBao7�޻����:
		break;
	case eFaBao8Ǭ��������:
		info.liveAp.d1 += 2;
		break;
	case eFaBao9�ն�:
		info.fire.rate.d1 += 5;
		info.water.rate.d1 += 5;
		info.soil.rate.d1 += 5;
		info.thunder.rate.d1 += 5;

		info.fire.per.d1 += 5;
		info.water.per.d1 += 5;
		info.soil.per.d1 += 5;
		info.thunder.per.d1 += 5;
		break;
	case eFaBao10���س�:
		break;
	case eFaBao11�¹ⱦ��:
		break;
	case eFaBao16����:
		break;
	case eFaBao17�ܽ����ְ�:
		speed.ori += 30;
		break;
	case eFaBao18ʱ֮��:
		info.gad.rate.d1 += 5;
		break;
	case eFaBao19ͨ�鱦��:
		break;
	case eFaBao20�۱���:
		break;
	case eFaBao21�����«:
		info.damageCure.add.d1 += 64;
		break;
	case eFaBao22��ľ����:
		info.damageCure.add.d2 += 64;
		break;
	case eFaBao23���뾵:
		info.stab.rate.d1 += 20;
		info.stab.per.d1 += 5;
		break;
	case eFaBao24��Ѫ�:
		info.blood.rate.d1 += 5;
		info.blood.per.d1 += 5;
		break;
	case eFaBao25�������:
		info.parryRate.d1 += 5;
		break;
	case eFaBao26��ħ����:
		info.parryRateMagic.d1 += 5;
		break;
	case eFaBao27����:
		info.damageCure.per.d1 += 2;
		info.damageCure.per.d2 += 2;
		break;
	case eFaBao28������ë:
		info.liveLifeRate.d1 += 5;
		break;
	case eFaBao29����:
		info.pierceRateMaigc.d1 += 5;
		break;
	case eFaBao30�������ӡ:
		info.criRateMagic.d1 += 5;
		break;
	case eFaBao31����:
		break;
	case eFaBao32�ȱ�:
		info.criRateCure.d1 += 5;
		break;
	case eFaBao33�ε�:
		break;
	}
}


////////////////////////////////////////////////////////////////////////// װ��
void ccp::apply(sPropertyInfo& info, sAttribute& attr, sPoint& point, const cEquip::sPropertys& pros)
{
	int v;
	forr(pros, k)
	{
		v = pros[k].value;
		switch (pros[k].pro)
		{
		case eProPerty::None:break;
		case eProPerty::�˺�:attr.atk.ori += v; break;
		case eProPerty::����:
			attr.hit.ori += v; 
			attr.atk.ori += v * 7 / 2;
			break;
		case eProPerty::����:info.hitRate.d1 += v; break;
		case eProPerty::����:attr.def.ori += v; break;
		case eProPerty::ħ��:attr.mpMax.ori += v; break;
		case eProPerty::����:attr.mana.ori += v; break;
		case eProPerty::�ٶ�:attr.speed.ori += v; break;
		case eProPerty::��Ѫ:attr.hpMax.ori += v; break;
		case eProPerty::����:point.str += v; break;
		case eProPerty::����:point.agi += v; break;
		case eProPerty::����:point.body += v; break;
		case eProPerty::ħ��:point.mag += v; break;
		case eProPerty::����:point.dex += v; break;
		case eProPerty::ˮ��:info.water.rate.d1 += v; break;
		case eProPerty::��:info.fire.rate.d1 += v; break;
		case eProPerty::����:info.soil.rate.d1 += v; break;
		case eProPerty::�׿�:info.thunder.rate.d1 += v; break;
		case eProPerty::���:attr.evade.ori += v; break;
		case eProPerty::����:info.damageMagic.add.d1 += v; break;
		case eProPerty::����:info.damageMagic.add.d2 += v; break;
		case eProPerty::����:info.damageMagic.add.d1 += v; break;
		case eProPerty::���:info.damage.add.d1 += v; break;
		case eProPerty::�ظ�:info.damageCure.add.d2 += v; break;
		case eProPerty::��ŭ:info.liveAp.d1 += v; break;
		default:break;
		}
	}
}


void ccp::apply(sPropertyInfo& info, sAttribute& attr, sPoint& point, sTz& taozhuang, seSkis& specials, const sItems& equips)
{
	point.reset();
	specials.clear();

	std::map<eSki, int> ztMap;
	std::map<eSki, int> zjMap;
	taozhuang.rate = 0;

	bool isZhuijia;
	eSki eski;

	cEquip::sPropertys pros;

	forr(equips, k)
	{
		auto& e = equips[k];
		if (!e.isValid())
		{
			continue;
		}
		cEquip::apply(e, pros);
		apply(info, attr, point, pros);
		
		eski = cEquip::getTaoZhuang(e, isZhuijia);
		if (eski != eSki::eSkiNone)
		{
			auto pMap = isZhuijia ? (&zjMap) : (&ztMap);
			const auto& it = pMap->find(eski);
			if (it == ztMap.end())
			{
				pMap->insert(std::make_pair(eski, 1));
			}
			else
			{
				++it->second;
			}
		}

		if (cEquip::isGodAngry(e))
		{
			if (cEquip::isWeapon(e.getType()))
			{
				// ����
				info.gad.rate.d1 += 15;
			}
			else if (cEquip::isBelt(e.getType()))
			{
				// ��ŭ
				info.apSave.d1 += 20;
			}
		}

		eski = cEquip::getSpecial(e);
		if (eski != eSki::eSkiNone)
		{
			specials.push_back(eski);
		}
	}

	for (const auto& zt : ztMap)
	{
		if (zt.second >= cEquip::c3)
		{
			taozhuang.ski = zt.first;
			taozhuang.rate = 100;
			taozhuang.lvGap = (zt.second == cEquip::c3) ? (-sSki::cGap) : (sSki::cGap);
			break;
		}
	}

	for (const auto& zj : zjMap)
	{
		if (zj.second >= cEquip::c3)
		{
			taozhuang.ski = zj.first;
			taozhuang.rate = 14 + (zj.second - cEquip::c3) * 8;
			taozhuang.lvGap = 0;
			break;
		}
	}
}


////////////////////////////////////////////////////////////////////////// ����
void ccp::apply(sPropertyInfo& info, sAttribute& attr, eSkill ski, int lv)
{
	switch (ski)
	{
//	case eSkill::eSkiCover0:
	case eSkill::����:
		info.counter.rate.d1 += 25;
		info.counter.per.d1 += 50;
		break;
	case eSkill::����2:
		info.counter.rate.d1 += 35;
		info.counter.per.d1 += 100;
		break;
	case eSkill::����:
		info.stab.rate.d1 += 25;
		info.stab.per.d1 += 25;
		break;
	case eSkill::����2:
		info.stab.rate.d1 += 35;
		info.stab.per.d1 += 50;
		break;
	case eSkill::��Ѫ:
		info.blood.rate.d1 += 100;
		info.blood.per.d1 += 15;
		break;
	case eSkill::��Ѫ2:
		info.blood.rate.d1 += 100;
		info.blood.per.d1 += 25;
		break;
	case eSkill::����:
		info.comboRate.d1 += 45;
		info.damage.per.d1 -= 25;
		break;
	case eSkill::����2:
		info.comboRate.d1 += 55;
		info.damage.per.d1 -= 20;
		break;
	case eSkill::����:
		info.hitRate.d1 += 10;
		info.hitRate.d2 += 10;
		info.damageArm.per.d2 -= 50;
		break;
	case eSkill::����2:
		info.hitRate.d1 += 15;
		info.hitRate.d2 += 15;
		info.damageArm.per.d2 -= 20;
		break;
	case eSkill::ҹս:
		//////////////////////////////////////////////////////////////////////////
		break;
	case eSkill::ҹս2:
		//////////////////////////////////////////////////////////////////////////
		break;
	case eSkill::����:
		info.hide.d1 += 2;
		break;
	case eSkill::����2:
		info.hide.d2 += 5;
		break;
	case eSkill::��֪:
	case eSkill::��֪2:
		info.hide.d2 += cFF;
		break;
	case eSkill::����:
		info.liveHp.d1 += lv;
		break;
	case eSkill::����2:
		info.liveHp.d1 += lv * 2;
		break;
	case eSkill::ڤ˼:
		info.liveMp.d1 += lv / 4;
		break;
	case eSkill::ڤ˼2:
		info.liveMp.d1 += lv / 2;
		break;
	case eSkill::�۸�:
		info.mpSave.d1 += 25;
		break;
	case eSkill::�۸�2:
		info.mpSave.d1 += 50;
		break;
	case eSkill::��ɱ:
		info.criRate.d1 += 10;
		break;
	case eSkill::��ɱ2:
		info.criRate.d1 += 20;
		break;
	case eSkill::����:
		info.criRate.d2 += cFF;
		break;
	case eSkill::����2:
		info.criRate.d2 += cFF;
		info.hitRateMagic.d2 += 10;
		break;
	case eSkill::��:
		info.liveStoreRate.d1 += cFF;
		break;
	case eSkill::��2:
		info.hitRateSeal.dper += cFF;
		info.hitRatePosion.dper += cFF;
		break;
	case eSkill::�м�:
		info.parryRate.d1 += 5;
		break;
	case eSkill::�м�2:
		info.parryRate.d1 += 10;
		break;
	case eSkill::����:
		info.buffTimeAdd.d1 += 3;
		break;
	case eSkill::����2:
		info.buffTimeAdd.d2 += 6;
		break;
	case eSkill::����:
		attr.speed.per += 10;
		break;
	case eSkill::����2:
		attr.speed.per += 20;
		break;
	case eSkill::ǿ��:
		attr.atk.ori += lv / 2;
		break;
	case eSkill::ǿ��2:
		attr.atk.ori += lv;
		break;
	case eSkill::����:
		attr.def.ori += lv / 2;
		break;
	case eSkill::����2:
		attr.def.ori += lv;
		break;
	case eSkill::͵Ϯ:
		info.stab.rate.d2 += cFF;
		info.counter.rate.d2 += cFF;
		break;
	case eSkill::͵Ϯ2:
		info.stab.rate.d2 += cFF;
		info.counter.rate.d2 += cFF;
		info.damage.per.d1 += 5;
		break;
	case eSkill::��:
		info.hitRatePosion.d1 += 10;
		break;
	case eSkill::��2:
		info.hitRatePosion.d1 += 15;
		break;
	case eSkill::����:
		info.ghost.d2 += 50;
		break;
	case eSkill::����2:
		info.ghost.d2 = 100;
		break;
	case eSkill::�����:
		info.ghost.d1 = 8;
		info.hitRateSeal.dper += cFF;
		info.hitRatePosion.dper += cFF;
		break;
	case eSkill::�����2:
		info.ghost.d1 = 5;
		info.hitRateSeal.dper += cFF;
		info.hitRatePosion.dper += cFF;
		break;
	case eSkill::ħ֮��:
		info.damageMagic.per.d1 += 10;
		break;
	case eSkill::ħ֮��2:
		info.damageMagic.per.d1 += 20;
		break;
	case eSkill::���Ӹ���:
		info.gad.rate.d1 += 20;
		info.gad.per.d1 += 50;
		break;
	case eSkill::���Ӹ���2:
		info.gad.rate.d1 += 30;
		info.gad.per.d1 += 100;
		break;
	case eSkill::������:
		info.hitRateSeal.dper += 10;
		info.hitRatePosion.dper += 10;
		break;
	case eSkill::������2:
		info.hitRateSeal.dper += 20;
		info.hitRatePosion.dper += 20;
		break;
	case eSkill::������:
		info.gad.rate.d2 += 10;
		break;
	case eSkill::������2:
		info.gad.rate.d2 += 20;
		break;
	case eSkill::��������:
		info.comboRateMagic.d1 += 15;
		break;
	case eSkill::��������2:
		info.comboRateMagic.d1 += 25;
		break;
	case eSkill::��������:
		info.criRateMagic.d1 += 10;
		break;
	case eSkill::��������2:
		info.criRateMagic.d1 += 20;
		break;
	case eSkill::��������:
		info.magicWave.d1 += 10;
		break;
	case eSkill::��������2:
		info.magicWave.d1 += 20;
		break;
	case eSkill::�ٶ�:
		attr.speed.per -= 50;
		break;
	case eSkill::�ٶ�2:
		attr.speed.per -= 80;
		break;
	case eSkill::����������:
		info.thunder.rate.d2 += 20;
		info.thunder.per.d2 += 20;
		break;
	case eSkill::����������2:
		info.thunder.rate.d2 += 30;
		info.thunder.per.d2 += 30;
		break;
	case eSkill::����������:
		info.soil.rate.d2 += 20;
		info.soil.per.d2 += 20;
		break;
	case eSkill::����������2:
		info.soil.rate.d2 += 30;
		info.soil.per.d2 += 30;
		break;
	case eSkill::����������:
		info.fire.rate.d2 += 20;
		info.fire.per.d2 += 20;
		break;
	case eSkill::����������2:
		info.fire.rate.d2 += 30;
		info.fire.per.d2 += 30;
		break;
	case eSkill::ˮ��������:
		info.water.rate.d2 += 20;
		info.water.per.d2 += 20;
		break;
	case eSkill::ˮ��������2:
		info.water.rate.d2 += 20;
		info.water.per.d2 += 20;
		break;
	case eSkill::����: // ����
		//////////////////////////////////////////////////////////////////////////
		break;
	case eSkill::����2:
		//////////////////////////////////////////////////////////////////////////
		break;
	case eSkill::�����ֿ�:
		info.damageMagic.per.d2 += 15;
		break;
	case eSkill::�����ֿ�2:
		info.damageMagic.per.d2 += 15;
		break;
	case eSkill::����:
		info.pierceRate.d1 += 4;
		break;
	case eSkill::����2:
		info.pierceRate.d1 += 8;
		break;
		//	case eSkill::eSkiCoverEnd:
	case eSkill::�����:
		info.fire.rate.d2 -= cFF;
		info.fire.per.d2 += 50;
		break;
	case eSkill::����ˮ:
		info.water.rate.d2 -= cFF;
		info.water.per.d2 += 50;
		break;
	case eSkill::������:
		info.soil.rate.d2 -= cFF;
		info.soil.per.d2 += 50;
		break;
	case eSkill::������:
		info.thunder.rate.d2 -= cFF;
		info.thunder.per.d2 += 50;
		break;
	case eSkill::�ƻ���ľ:
		info.damageArm.per.d2 += 200;
		break;
	case eSkill::���ܼ���:
		//////////////////////////////////////////////////////////////////////////
		break;
	case eSkill::��Ѫ׷��:
		break;
	case eSkill::��������:
		info.stabMagic.rate.d1 += 35;
		info.stabMagic.per.d1 += 50;
		break;
	case eSkill::��������:
		//	damageMagic.add.d1 += point.mag * 2 / 5;
		break;
	case eSkill::�������:
		//////////////////////////////////////////////////////////////////////////
		break;
	case eSkill::��ɽ����:
// 		damageMagic.add.d2 += point.mag;
// 		{
// 			int mana = lv * (2500 + 1640) * (120 + 100) / 75000;
// 			mana += point.body * 3 + point.mag * 7 + point.str * 4 + point.dex * 2;
// 			mana /= 10;
// 			damageMagic.add.d1 -= mana;
// 		}
		break;
	case eSkill::ǧ��һŭ:
		break;
	case eSkill::��������:
		break;
	case eSkill::���ŭ��:
		break;
	case eSkill::����:
		break;
	case eSkill::������:
		break;
	}
}

void ccp::apply(sPropertyInfo& info, sAttribute& attr, const sPoint& point, const seSkis& sekis, int lv)
{
	// ���ܻ���
	std::set<eSki> unComs;
	forr(sekis, k)
	{
		const auto& e = sekis[k];
		if (e >= eSkill::eSkiCover0 && e <= eSkill::eSkiCoverEnd)
		{
			if ((((int)e) % 2) == 1)
			{
				unComs.insert((eSkill)(((int)e) - 1));
			}
		}
		if (e == eSkill::�� || e == eSkill::��2)
		{
			unComs.insert(eSkill::������);
			unComs.insert(eSkill::������2);
		}
		else if (e == eSkill::����� || e == eSkill::�����2)
		{
			unComs.insert(eSkill::���Ӹ���);
			unComs.insert(eSkill::���Ӹ���2);
		}
		else if (e == eSkill::�ٶ� || e == eSkill::�ٶ�2)
		{
			unComs.insert(eSkill::����);
			unComs.insert(eSkill::����2);
		}
		else if (e == eSkill::�����)
		{
			unComs.insert(eSkill::����������);
			unComs.insert(eSkill::����������2);
		}
		else if (e == eSkill::����ˮ)
		{
			unComs.insert(eSkill::ˮ��������);
			unComs.insert(eSkill::ˮ��������2);
		}
		else if (e == eSkill::������)
		{
			unComs.insert(eSkill::����������);
			unComs.insert(eSkill::����������2);
		}
		else if (e == eSkill::������)
		{
			unComs.insert(eSkill::����������);
			unComs.insert(eSkill::����������2);
		}
	}
	std::set<eSki> ski2s;
	forr(sekis, k)
	{
		if (!txtSkill::isEd(sekis[k]))
		{
			continue;
		}
		const auto& e = sekis[k];
		if (unComs.find(e) == unComs.end())
		{
			ski2s.insert(e);
		}
	}

	for (const auto& e : sekis)
	{
		switch (e)
		{
	//	case eSkill::eSkiCover0:
		case eSkill::ҹս:
			//////////////////////////////////////////////////////////////////////////
			break;
		case eSkill::ҹս2:
			//////////////////////////////////////////////////////////////////////////
			break;

		case eSkill::����: // ����
			//////////////////////////////////////////////////////////////////////////
			break;
		case eSkill::����2:
			//////////////////////////////////////////////////////////////////////////
			break;

	//	case eSkill::eSkiCoverEnd:
		case eSkill::���ܼ���:
			//////////////////////////////////////////////////////////////////////////
			break;
		case eSkill::��Ѫ׷��:
			break;
	//	case eSkill::��������:
		case eSkill::��������:
			info.damageMagic.add.d1 += point.mag * 2 / 5;
			break;
		case eSkill::�������:
			//////////////////////////////////////////////////////////////////////////
			break;
		case eSkill::��ɽ����:
			info.damageMagic.add.d2 += point.mag;
			{
				int mana = lv * (2500 + 1640) * (120 + 100) / 75000;
				mana += point.body * 3 + point.mag * 7 + point.str * 4 + point.dex * 2;
				mana /= 10;
				info.damageMagic.add.d1 -= mana;
			}
			break;
		case eSkill::ǧ��һŭ:
			break;
		case eSkill::��������:
			break;
		case eSkill::���ŭ��:
			break;
		case eSkill::����:
			break;
		case eSkill::������:
			break;
	//	case eSkill::eSkiedEnd:
		default:
			apply(info, attr, e, lv);
			break;
		}
	}
}


////////////////////////////////////////////////////////////////////////// ������
void ccp::apply(sPropertys& pros, const sProperty* pro)
{
	sPropertyInfo& info = pros.info;
	sAttribute& attr = pros.attr;
	info.resetCri();
	attr.reset();

	sPoint& point = pros.point;
	// ����õ���
	point.reset(sPoint::c10);

	sTz& taozhuang = pros.taozhuang;
	seSkis& specials = pros.specials;
	// װ��
	sPoint point2;
	apply(info, attr, point2, taozhuang, specials, pro->equips);
	point += point2;
	point2 = pro->point + point;
	if (pro->ispet)
	{
		// ����
		apply(attr, point2, pro->zz, pro->lv);
		// �ڵ�
		auto& fz = ((sProperty*)pro)->fuzhus;
		fz[0] = pro->lv;
		fz[1] = std::max(0, pro->zz.grow100 - 100);
	}
	else
	{
		// ����
		apply(attr, point2);
		// ʦ�ż���
		apply(attr, pro->getSkiLv());
		// ������ɫ
		apply(info, attr.speed, pro->menpai, pro->getSkiLv());
		// ����
		const auto& fabaos = (dynamic_cast<const sRole*>(pro))->fabaos;
		for (const auto& fb : fabaos)
		{
			if (fb.isValid() && fb.getType() == eIcon::����f)
			{
				apply(info, attr.speed, fb.getId());
			}
		}
	}
	// ����
	forv(pro->fuzhus, k)
	{
		apply(attr, pro->fuzhus[k], k);
	}
	// ����
	apply(info, pro->xl);
	seSkis skis;
	for (const auto& ski : pro->skis)
	{
		skis.push_back(ski.getSki());
	}
	// ��������
	apply(info, attr, point2, skis, pro->lv);
}


void ccp::apply(sPropertys& pros, const sProperty& pro)
{
	apply(pros, &pro);
}

void ccp::fillHpMp(sProperty& pro)
{
	sPropertys pros;
	apply(pros, pro);
	pro.hp = pro.hp2 = pros.attr.hpMax;
	pro.mp = pros.attr.mpMax;
}



bool ccp::lvup(sProperty& pro, bool onlyCheck)
{
	if (pro.lv >= (pro.ispet ? ccp::lv180 : ccp::lv175))
	{
		return false;
	}

	int expMax = sExp::getExp(pro.lv + 1, pro.ispet);

	if (pro.exp < expMax)
	{
		return false;
	}

	if (!onlyCheck)
	{
		++pro.lv;
		pro.exp.add(-expMax);
		pro.point.lvup();
	}
	return true;
}


bool ccp::lvdown(sProperty& pro, bool onlyCheck)
{
	if (pro.lv <= 0)
	{
		return false;
	}
	forr(pro.equips, k)
	{
		const auto& e = pro.equips[k];
		if (e.getCount() != 1)
		{
			continue;
		}
		if (cEquip::getTakeLv(e) >= pro.lv)
		{
			return false;
		}
	}
	if (!pro.point.lvdown(true))
	{
		return false;
	}
	if (!onlyCheck)
	{
		pro.point.lvdown(false);
		pro.exp.add(sExp::getExp(pro.lv, pro.ispet));
		--pro.lv;
	}
	return true;
}


bool ccp::lvdown(sRole& role)
{
	int xlv = sXl::getLv(role.lv);
	forr(role.xl.lvs, k)
	{
		while (role.xl.lvs[k] > xlv)
		{
			if (role.xl.lvdown(k, false))
			{
				sBags::getInstance()->money.add(sXl::c2000);
			}
		}
	}
	forr(role.xlbb.lvs, k)
	{
		while (role.xlbb.lvs[k] > xlv)
		{
			if (role.xlbb.lvdown(k, false))
			{
				sBags::getInstance()->money.add(sXl::c2000);
			}
		}
	}

	while (role.skilv > role.lv + sSki::cGap)
	{
		role.exp.add(sSki::getExp(role.skilv));
		sBags::getInstance()->money.add(sSki::getMoney(role.skilv));
		--role.skilv;
	}
	if (!role.setPet(role.fight, true))
	{
		role.unPet();
	}
	return true;
}



bool ccp::addSki(sSkis& skis, eMenpai e, bool normal)
{
	if (e == eMenpai::None)
	{
		return false;
	}
	bool checkValid = true;
	static std::map<eMenpai, eSkill> s_begin;
	static std::map<eMenpai, eSkill> s_end;
	if (s_begin.empty())
	{
		s_begin.insert(std::make_pair(eMenpai::���ƹٸ�, eSkill::eDt0));
		s_begin.insert(std::make_pair(eMenpai::������,eSkill::eHs0));
		s_begin.insert(std::make_pair(eMenpai::Ů����, eSkill::eNe0));
		s_begin.insert(std::make_pair(eMenpai::����ɽ, eSkill::eFc0));
		s_begin.insert(std::make_pair(eMenpai::ʨ����, eSkill::eSt0));
		s_begin.insert(std::make_pair(eMenpai::ħ��կ, eSkill::eMw0));
		s_begin.insert(std::make_pair(eMenpai::��˿��, eSkill::ePs0));
		s_begin.insert(std::make_pair(eMenpai::���ܵظ�, eSkill::eDf0));
		s_begin.insert(std::make_pair(eMenpai::��������, eSkill::eLg0));
		s_begin.insert(std::make_pair(eMenpai::��ׯ��, eSkill::eWz0));
		s_begin.insert(std::make_pair(eMenpai::����ɽ, eSkill::ePt0));
		s_begin.insert(std::make_pair(eMenpai::�칬, eSkill::eTg0));
		s_begin.insert(std::make_pair(eMenpai::�貨��, eSkill::eLb0));
		s_begin.insert(std::make_pair(eMenpai::�޵׶�, eSkill::eWd0));
		s_begin.insert(std::make_pair(eMenpai::��ľ��, eSkill::eSm0));

		s_end.insert(std::make_pair(eMenpai::���ƹٸ�, eSkill::eDtEnd));
		s_end.insert(std::make_pair(eMenpai::������, eSkill::eHsEnd));
		s_end.insert(std::make_pair(eMenpai::Ů����, eSkill::eNeEnd));
		s_end.insert(std::make_pair(eMenpai::����ɽ, eSkill::eFcEnd));
		s_end.insert(std::make_pair(eMenpai::ʨ����, eSkill::eStEnd));
		s_end.insert(std::make_pair(eMenpai::ħ��կ, eSkill::eMwEnd));
		s_end.insert(std::make_pair(eMenpai::��˿��, eSkill::ePsEnd));
		s_end.insert(std::make_pair(eMenpai::���ܵظ�, eSkill::eDfEnd));
		s_end.insert(std::make_pair(eMenpai::��������, eSkill::eLgEnd));
		s_end.insert(std::make_pair(eMenpai::��ׯ��, eSkill::eWzEnd));
		s_end.insert(std::make_pair(eMenpai::����ɽ, eSkill::ePtEnd));
		s_end.insert(std::make_pair(eMenpai::�칬, eSkill::eTgEnd));
		s_end.insert(std::make_pair(eMenpai::�貨��, eSkill::eLbEnd));
		s_end.insert(std::make_pair(eMenpai::�޵׶�, eSkill::eWdEnd));
		s_end.insert(std::make_pair(eMenpai::��ľ��, eSkill::eSmEnd));
	}
	int begin = (int)s_begin.at(e);
	int end = (int)s_end.at(e);
	eSki eski;
	sSki ski;
	const auto& costs = txtSkill::getInstance()->getCosts();
	for (int mp = begin; mp <= end; ++mp)
	{
		eski = (eSki)mp;
		if (!normal && txtSkill::isF1(eski))
		{
			continue;
		}
		if (checkValid)
		{
			const auto& it = costs.find(eski);
			if (it == costs.end())
			{
				continue;
			}
			if (it->second.ignore)
			{
				continue;
			}
		}
		ski.setData(eski);
		skis.push_back(ski);
	}
	return true;
}


bool ccp::addSki(sSkis& skis, sSki ski, int idx /* = -1 */)
{
	int k;
	int size = skis.size();
	for (k = 0; k < size; ++k)
	{
		if (skis[k].getSki() == ski.getSki())
		{
			break;
		}
	}
	if (idx < 0 || idx >= size)
	{
		if (k < size)
		{
			skis[k] = ski;
		}
		else
		{
			skis.push_back(ski);
		}
	}
	else
	{
		if (k < size)
		{
			skis[k] = ski;
		}
		else
		{
			skis[idx] = ski;
		}
	}
	return true;
}


int ccp::getEquipsAtk(const sItems& equips)
{
	int atk = 0;
	cEquip::sPropertys pros;
	forr(equips, k)
	{
		auto& e = equips[k];
		if (e.getCount() != 1)
		{
			continue;
		}
		cEquip::apply(e, pros);
		forr(pros, k)
		{
			if (!pros[k].isVaild())
			{
				continue;
			}
			if (pros[k].pro == eProPerty::�˺�)
			{
				atk += pros[k].value;
			}
		}
	}
	return atk;
}


std::string ccp::getMenpaiName(eMenpai menpai)
{
	switch (menpai)
	{
	case eMenpai::���ƹٸ�:   return "���ƹٸ�";
	case eMenpai::������:	  return "������";
	case eMenpai::Ů����:	  return "Ů����";
	case eMenpai::����ɽ:	  return "����ɽ";
	case eMenpai::ʨ����:	  return "ʨ����";
	case eMenpai::ħ��կ:	  return "ħ��կ";
	case eMenpai::��˿��:	  return "��˿��";
	case eMenpai::���ܵظ�:	  return "���ܵظ�";
	case eMenpai::��������:	  return "��������";
	case eMenpai::��ׯ��:	  return "��ׯ��";
	case eMenpai::����ɽ:	  return "����ɽ";
	case eMenpai::�칬:	      return "�칬";
	case eMenpai::�貨��:	  return "�貨��";
	case eMenpai::�޵׶�:	  return "�޵׶�";
	case eMenpai::��ľ��:	  return "��ľ��";
	}
	return "";
}

bool ccp::useItem(const sItem& item, sRole& role)
{
	return false;
}

bool ccp::useItem(const sItem& item, sProperty& pet)
{
	return false;
}
