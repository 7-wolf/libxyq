#include "txtZz.h"

ccc_txt_instance_cpp(txtZz);

void txtZz::init(eMod pet, int takelv, eAp ap)
{
	_zz = &_tables.at(pet);
	_zz->takelv = takelv;
	_zz->ap = ap;
	_skills = &_zz->skills;
}

void txtZz::insert(int atk, int def, int hp, int mp, int speed, int evoid, int grow)
{
	_zz->atk = atk;
	_zz->def = def;
	_zz->hp = hp;
	_zz->mp = mp;
	_zz->speed = speed;
	_zz->evoid = evoid;
	_zz->grow = grow;
}



void txtZz::insert(eSkill ski)
{
	_skills->push_back(ski);
	correctSkill();
}
void txtZz::insert(eSkill ski, eSkill ski2)
{ 
	insert(ski);
	_skills->push_back(ski2);
	correctSkill();
}
void txtZz::insert(eSkill ski, eSkill ski2, eSkill ski3)
{
	insert(ski, ski2);
	_skills->push_back(ski3);
	correctSkill();
}
void txtZz::insert(eSkill ski, eSkill ski2, eSkill ski3, eSkill ski4)
{
	insert(ski, ski2, ski3); 
	_skills->push_back(ski4);
	correctSkill();
}
void txtZz::insert(eSkill ski, eSkill ski2, eSkill ski3, eSkill ski4, eSkill ski5)
{
	insert(ski, ski2, ski3, ski4); 
	_skills->push_back(ski5);
	correctSkill();
}
void txtZz::insert(eSkill ski, eSkill ski2, eSkill ski3, eSkill ski4, eSkill ski5, eSkill ski6)
{
	insert(ski, ski2, ski3, ski4, ski5);
	_skills->push_back(ski6);
	correctSkill();
}
void txtZz::insert(eSkill ski, eSkill ski2, eSkill ski3, eSkill ski4, eSkill ski5, eSkill ski6, eSkill ski7)
{
	insert(ski, ski2, ski3, ski4, ski5, ski6);
	_skills->push_back(ski7);
	correctSkill();
}


void txtZz::correctSkill()
{
	auto& ski = _skills->back();
}


txtZz::txtZz()
{
	sZz zz;
	for (int e = (int)eMod::ePet0; e <= (int)eMod::ePetEnd; ++e)
	{
		_tables.insert(std::make_pair((eMod)e, zz));
	}

	init(eMod::e����, 5, eAp::GiveMagic);
	insert(1320, 1380, 4200, 2160, 1320, 1320, 112);
	insert(eSkill::����2, eSkill::����2, eSkill::����, eSkill::������, eSkill::����);


	init(eMod::e�󺣹�, 5, eAp::GiveMagic);
	insert(1036, 1036, 3888, 1296, 907, 1425, 92);
	insert(eSkill::����, eSkill::�۸�, eSkill::����, eSkill::ˮ��������, eSkill::����);


	init(eMod::e����, 5, eAp::Atk);
	insert(1555, 907, 2592, 1296, 1425, 1296, 103);
	insert(eSkill::����, eSkill::��, eSkill::��Ѫ, eSkill::ˮ��������, eSkill::�����);


	init(eMod::e����, 5, eAp::GiveMagic);
	insert(1166, 1231, 2592, 1555, 1296, 1101, 92);
	insert(eSkill::�۸�, eSkill::����2, eSkill::ˮ��, eSkill::ˮ��������, eSkill::�����);


	init(eMod::e����, 5, eAp::Atk);
	insert(1231, 1101, 2916, 1944, 1296, 1296, 97);
	insert(eSkill::����, eSkill::��ɱ, eSkill::ǿ��);


	init(eMod::e��, 5, eAp::Atk);
	insert(1555, 972, 3110, 1296, 1490, 1425, 104);
	insert(eSkill::����, eSkill::͵Ϯ, eSkill::��ɱ, eSkill::�м�);


	init(eMod::e����, 5, eAp::Magic);
	insert(1166, 907, 2916, 1296, 1425, 1101, 92);
	insert(eSkill::�۸�, eSkill::����, eSkill::ˮ��, eSkill::�����);


	init(eMod::e����, 5, eAp::Atk);
	insert(1425, 1425, 3564, 1425, 972, 1036, 92);
	insert(eSkill::����, eSkill::��֪, eSkill::����, eSkill::����, eSkill::�����, eSkill::�ٶ�);


	init(eMod::e��ͽ, 5, eAp::Atk);
	insert(1101, 1231, 3240, 1555, 1555, 1490, 97);
	insert(eSkill::����, eSkill::͵Ϯ);


	init(eMod::eǿ��, 5, eAp::Atk);
	insert(1360, 1360, 3564, 1490, 1296, 1296, 103);
	insert(eSkill::����, eSkill::�һ�, eSkill::ǿ��, eSkill::������);


	init(eMod::e��ë��, 5, eAp::Atk);
	insert(1555, 972, 2592, 1296, 1425, 1296, 103);
	insert(eSkill::��, eSkill::����2, eSkill::��ɱ, eSkill::ҹս, eSkill::�����);


	init(eMod::e������, 5, eAp::GiveMagic);
	insert(1166, 1231, 2721, 1944, 1620, 1620, 110);
	insert(eSkill::��Ѫ, eSkill::��֪2, eSkill::����, eSkill::����, eSkill::ҹս, eSkill::����ˮ);


	init(eMod::eɽ��, 5, eAp::Atk);
	insert(1166, 1296, 3888, 1296, 1296, 1425, 104);
	insert(eSkill::�м�, eSkill::͵Ϯ, eSkill::ǿ��, eSkill::������2);


	init(eMod::eҰ��, 5, eAp::Atk);
	insert(1231, 1231, 4147, 1360, 1231, 1296, 104);
	insert(eSkill::��֪, eSkill::��֪2, eSkill::����2, eSkill::ǿ��, eSkill::������, eSkill::�����);


	init(eMod::e���ù�, 15, eAp::Atk);
	insert(1296, 1296, 3240, 1296, 1296, 1620, 105);
	insert(eSkill::�����, eSkill::������, eSkill::ҹս, eSkill::����������);


	init(eMod::e��ͷ��, 15, eAp::Atk);
	insert(1360, 1490, 3628, 1425, 1296, 1296, 105);
	insert(eSkill::��ɱ, eSkill::����, eSkill::����, eSkill::����);


	init(eMod::e��󡾫, 15, eAp::Atk);
	insert(1490, 1231, 3564, 1296, 1425, 1425, 105);
	insert(eSkill::��ɱ, eSkill::��);


	init(eMod::e���꾫, 15, eAp::Atk);
	insert(1425, 1360, 3240, 1555, 1425, 1296, 105);
	insert(eSkill::ҹս, eSkill::��֪2, eSkill::�۸�, eSkill::�۸�2, eSkill::������);


	init(eMod::e�ϻ�, 15, eAp::Atk);
	insert(1490, 1166, 3888, 1490, 1296, 1166, 105);
	insert(eSkill::����, eSkill::����, eSkill::����, eSkill::ǿ��);


	init(eMod::e����, 15, eAp::Atk);
	insert(1231, 1425, 4536, 1425, 1166, 1425, 105);
	insert(eSkill::����, eSkill::��ɱ, eSkill::ǿ��, eSkill::����, eSkill::�ٶ�);


	init(eMod::e����, 15, eAp::Magic);
	insert(1101, 1555, 4082, 1555, 1231, 1231, 107);
	insert(eSkill::��֪, eSkill::�۸�, eSkill::����, eSkill::����, eSkill::ˮ��������);


	init(eMod::eţ��, 25, eAp::Atk);
	insert(1620, 1101, 3240, 1231, 1425, 1036, 112);
	insert(eSkill::�һ�, eSkill::����2, eSkill::����2, eSkill::�۸�2);


	init(eMod::eС��Ů, 25, eAp::Magic);
	insert(1231, 1490, 4147, 1944, 1555, 1166, 109);
	insert(eSkill::ˮ��, eSkill::ˮ��������2, eSkill::����2, eSkill::���Ӹ���, eSkill::�۸�);


	init(eMod::eҰ��, 25, eAp::Atk);
	insert(1425, 1425, 4536, 1296, 1231, 1360, 104);
	insert(eSkill::ҹս, eSkill::�����, eSkill::����������, eSkill::����);


	init(eMod::e��, 25, eAp::Atk);
	insert(1555, 1036, 3888, 1296, 1620, 1581, 104);
	insert(eSkill::ҹս, eSkill::����, eSkill::����2, eSkill::͵Ϯ, eSkill::����);


	init(eMod::eϺ��, 25, eAp::Atk);
	insert(1296, 1490, 5184, 2592, 1166, 1555, 106);
	insert(eSkill::��ɱ2, eSkill::����2, eSkill::ˮ��������, eSkill::����);


	init(eMod::eз��, 25, eAp::Atk);
	insert(1425, 1296, 5508, 2462, 1296, 1296, 107);
	insert(eSkill::����2, eSkill::�м�, eSkill::ˮ��������, eSkill::������);


	init(eMod::e��ة��, 35, eAp::Magic);
	insert(1101, 1555, 6285, 2138, 972, 1231, 108);
	insert(eSkill::����, eSkill::ڤ˼, eSkill::ˮ��, eSkill::ˮ����ɽ, eSkill::ˮ��������, eSkill::����);


	init(eMod::e���ӹ�, 35, eAp::GiveMagic);
	insert(1425, 1231, 4536, 2592, 1555, 1231, 114);
	insert(eSkill::����2, eSkill::����2, eSkill::��֪2, eSkill::ڤ˼2, eSkill::����2, eSkill::����2, eSkill::������);


	init(eMod::e֩�뾫, 35, eAp::GiveMagic);
	insert(1231, 1463, 5378, 2786, 1166, 1296, 111);
	insert(eSkill::��2, eSkill::��Ѫ, eSkill::��֪2, eSkill::������);


	init(eMod::e���ܾ�, 35, eAp::Atk);
	insert(1490, 1360, 5443, 2332, 1101, 1425, 107);
	insert(eSkill::ǿ��2, eSkill::����, eSkill::��ɱ, eSkill::����, eSkill::������);


	init(eMod::e��ʬ, 35, eAp::Atk);
	insert(1555, 1166, 4665, 2592, 1296, 1490, 109);
	insert(eSkill::�����, eSkill::ҹս, eSkill::����������, eSkill::����, eSkill::������);


	init(eMod::eţͷ, 35, eAp::Atk);
	insert(1425, 1425, 3888, 1944, 1555, 1296, 110);
	insert(eSkill::�����2, eSkill::��ɱ2, eSkill::ҹս, eSkill::����, eSkill::�м�);


	init(eMod::e����, 35, eAp::Atk);
	insert(1425, 1425, 3888, 1944, 1555, 1296, 109);
	insert(eSkill::�����2, eSkill::��ɱ2, eSkill::ҹս, eSkill::����, eSkill::ǿ��);


	init(eMod::e������, 45, eAp::GiveMagic);
	insert(1296, 1296, 4536, 2073, 1555, 1231, 117);
	insert(eSkill::����, eSkill::�׻�, eSkill::������, eSkill::����������2, eSkill::������);


	init(eMod::e��������, 45, eAp::GiveMagic);
	insert(1425, 1231, 3240, 3240, 1555, 1555, 112);
	insert(eSkill::����, eSkill::����ˮ, eSkill::����2, eSkill::��, eSkill::ħ֮��2);


	init(eMod::e�Ŵ�����, 45, eAp::Magic);
	insert(1231, 1360, 3888, 2592, 1490, 1296, 117);
	insert(eSkill::��2, eSkill::̩ɽѹ��, eSkill::����2, eSkill::����2);


	init(eMod::e����, 45, eAp::Atk);
	insert(1425, 1425, 5702, 1944, 1036, 1490, 114);
	insert(eSkill::����2, eSkill::��ɱ2, eSkill::�ٶ�2, eSkill::ǿ��, eSkill::����);


	init(eMod::e��ɽ����, 45, eAp::Atk);
	insert(1231, 1555, 6480, 2592, 1036, 1425, 115);
	insert(eSkill::��Ѫ2, eSkill::͵Ϯ2, eSkill::������2);


	init(eMod::e���, 55, eAp::Atk);
	insert(1425, 1620, 5508, 2397, 1425, 1425, 117);
	insert(eSkill::��ɱ, eSkill::����2, eSkill::����2, eSkill::��֪2);


	init(eMod::e�콫, 55, eAp::Atk);
	insert(1490, 1231, 5184, 2527, 1490, 1296, 118);
	insert(eSkill::ǿ��2, eSkill::����, eSkill::����, eSkill::����);


	init(eMod::e����ս��, 55, eAp::Rand);
	insert(1620, 1555, 4860, 1944, 1166, 1620, 115);
	insert(eSkill::����2, eSkill::̩ɽѹ��, eSkill::����2, eSkill::ħ֮��2);


	init(eMod::e�粮, 55, eAp::GiveMagic);
	insert(1490, 1503, 4536, 2397, 1620, 1555, 117);
	insert(eSkill::������, eSkill::����2, eSkill::����2, eSkill::����������2);


	init(eMod::e���, 65, eAp::Magic);
	insert(1296, 1555, 4536, 2592, 1684, 1425, 122);
	insert(eSkill::����������2, eSkill::�����һ�, eSkill::���Ӹ���2, eSkill::����);


	init(eMod::e����, 65, eAp::Rand);
	insert(1555, 1555, 4924, 3240, 1296, 1425, 122);
	insert(eSkill::ˮ����ɽ, eSkill::ˮ��������2, eSkill::��֪, eSkill::����2);


	init(eMod::e��ʦ, 65, eAp::Magic);
	insert(1296, 1490, 4536, 3240, 1555, 1749, 120);
	insert(eSkill::ˮ��, eSkill::ˮ��������2, eSkill::����������2, eSkill::����������2, eSkill::����������2);


	init(eMod::e����, 65, eAp::Magic);
	insert(1296, 1620, 4147, 3110, 1296, 1231, 122);
	insert(eSkill::ˮ��, eSkill::�۸�, eSkill::��, eSkill::ڤ˼, eSkill::ˮ��������2);


	init(eMod::e����, 65, eAp::Atk);
	insert(1555, 1555, 4924, 2073, 1490, 1555, 122);
	insert(eSkill::����, eSkill::ˮ��������2, eSkill::�ƻ���ľ, eSkill::����);


	init(eMod::e��ˮҹ��, 65, eAp::Rand);
	insert(1490, 1425, 4536, 2980, 1555, 1944, 123);
	insert(eSkill::���ݻ���, eSkill::������, eSkill::����2, eSkill::ǿ��);


	init(eMod::e��������, 75, eAp::Magic);
	insert(1296, 1529, 4730, 2916, 1555, 1490, 125);
	insert(eSkill::������, eSkill::����ˮ, eSkill::̩ɽѹ��, eSkill::�һ�, eSkill::�����һ�);


	init(eMod::eܽ������, 75, eAp::Atk);
	insert(1555, 1555, 4924, 2592, 1490, 1555, 125);
	insert(eSkill::����2, eSkill::����2, eSkill::����2);


	init(eMod::eѲ������, 75, eAp::Rand);
	insert(1490, 1490, 5832, 2851, 1296, 1814, 124);
	insert(eSkill::��ɱ2, eSkill::�м�2, eSkill::̩ɽѹ��, eSkill::�����һ�);


	init(eMod::e��������, 75, eAp::Magic);
	insert(1296, 1529, 4730, 2916, 1555, 1490, 125);
	insert(eSkill::������, eSkill::ˮ����ɽ, eSkill::�׻�, eSkill::�۸�2);


	init(eMod::e��ë����, 75, eAp::Magic);
	insert(1296, 1360, 4536, 2927, 1684, 1814, 125);
	insert(eSkill::̩ɽѹ��, eSkill::����, eSkill::ڤ˼, eSkill::��������);


	init(eMod::eǧ������, 75, eAp::Atk);
	insert(1490, 1425, 4730, 2851, 1555, 1620, 124);
	insert(eSkill::��, eSkill::͵Ϯ, eSkill::��Ѫ, eSkill::����);


	init(eMod::eϬţ����, 75, eAp::Atk);
	insert(1555, 1581, 5184, 2721, 1296, 1231, 125);
	insert(eSkill::�����ķ�, eSkill::����2, eSkill::����, eSkill::ǿ��2);


	init(eMod::eϬţ, 75, eAp::Magic);
	insert(1555, 1581, 5184, 2721, 1296, 1231, 125);
	insert(eSkill::����, eSkill::��������, eSkill::��������, eSkill::����������);


	init(eMod::e����, 85, eAp::Atk);
	insert(1581, 1425, 4147, 2592, 1684, 1555, 125);
	insert(eSkill::����, eSkill::��֪2, eSkill::�����, eSkill::�׻�);


	init(eMod::e����, 85, eAp::Magic);
	insert(1296, 1296, 3888, 2592, 1296, 1684, 122);
	insert(eSkill::ڤ˼, eSkill::ħ֮��2, eSkill::��������, eSkill::������, eSkill::ˮ��);


	init(eMod::eҰ��, 85, eAp::Atk);
	insert(1581, 1684, 5184, 2592, 1296, 1425, 125);
	insert(eSkill::����, eSkill::����ˮ, eSkill::��֪, eSkill::ǿ��2);


	init(eMod::e���ȷ�, 85, eAp::Magic);
	insert(1296, 1555, 4795, 3110, 1684, 1684, 125);
	insert(eSkill::̩ɽѹ��, eSkill::����, eSkill::ҹս, eSkill::ڤ˼);


	init(eMod::e���㽫��, 85, eAp::Atk);
	insert(1555, 1425, 4924, 2851, 1684, 1425, 125);
	insert(eSkill::����ˮ, eSkill::����, eSkill::��, eSkill::ҹս2);


	init(eMod::e�ɷ�Ů�, 95, eAp::Atk);
	insert(1555, 1684, 4795, 2592, 1555, 1814, 125);
	insert(eSkill::����2, eSkill::����, eSkill::�ƶ��б�, eSkill::����);


	init(eMod::e���Ů�, 95, eAp::Magic);
	insert(1425, 1684, 5184, 3240, 1555, 1555, 125);
	insert(eSkill::ڤ˼2, eSkill::�Ϲ����, eSkill::�����һ�);


	init(eMod::e����, 95, eAp::Atk);
	insert(1594, 1555, 4536, 2851, 1425, 1814, 125);
	insert(eSkill::�����, eSkill::�����ٻ�, eSkill::����2, eSkill::����2);


	init(eMod::e��Ѫ��, 95, eAp::Atk);
	insert(1555, 1425, 3888, 2592, 1425, 1944, 125);
	insert(eSkill::��Ѫ, eSkill::ҹս, eSkill::����ˮ, eSkill::�����, eSkill::͵Ϯ);


	init(eMod::e����ɡ, 95, eAp::Magic);
	insert(1555, 1555, 5184, 3240, 1620, 1555, 126);
	insert(eSkill::�����ķ�, eSkill::����, eSkill::����2, eSkill::�Ϲ����);


	init(eMod::e��, 105, eAp::Atk);
	insert(1645, 1490, 5443, 1555, 1425, 1425, 126);
	insert(eSkill::��ɱ2, eSkill::�����, eSkill::����һ��, eSkill::ڤ˼);


	init(eMod::e��ƿŮ�, 105, eAp::Rand);
	insert(1581, 1555, 5184, 3045, 1684, 1684, 126);
	insert(eSkill::��֪, eSkill::�۸�2, eSkill::������, eSkill::�Ϲ����);


	init(eMod::e����, 105, eAp::Magic);
	insert(1490, 1555, 4665, 3110, 1425, 1555, 126);
	insert(eSkill::�����2, eSkill::ħ֮��2, eSkill::�����һ�, eSkill::����);


	init(eMod::e��ө����, 105, eAp::Atk);
	insert(1555, 1555, 4536, 2851, 1658, 1684, 126);
	insert(eSkill::�����2, eSkill::����2, eSkill::����, eSkill::�����ֿ�2);


	init(eMod::e������, 125, eAp::GiveMagic);
	insert(1555, 1620, 5832, 3240, 1425, 1944, 126);
	insert(eSkill::��֪2, eSkill::��������, eSkill::����, eSkill::���Ӹ���2);


	init(eMod::e���, 125, eAp::GiveMagic);
	insert(1555, 1555, 4924, 2980, 1684, 1555, 126);
	insert(eSkill::����, eSkill::�۸�2, eSkill::����2, eSkill::����2, eSkill::����2);


	init(eMod::e��ħ��, 125, eAp::Atk);
	insert(1620, 1555, 5184, 3240, 1555, 1425, 126);
	insert(eSkill::�����һ�, eSkill::�һ�, eSkill::����������2, eSkill::��ɱ2);


	init(eMod::e���컢, 125, eAp::Atk);
	insert(1620, 1555, 5184, 2592, 1620, 1684, 126);
	insert(eSkill::ǿ��2, eSkill::����2, eSkill::����, eSkill::����);


	init(eMod::e����, 125, eAp::Magic);
	insert(1555, 1555, 5184, 3499, 1490, 1555, 126);
	insert(eSkill::̩ɽѹ��, eSkill::��֪, eSkill::���Ӹ���, eSkill::����, eSkill::����);


	init(eMod::e����ɮ, 125, eAp::Atk);
	insert(1620, 1555, 5443, 2462, 1555, 1684, 126);
	insert(eSkill::����, eSkill::��ɱ, eSkill::�м�, eSkill::͵Ϯ, eSkill::����������2);


	init(eMod::e�������, 125, eAp::Atk);
	insert(1671, 1451, 6480, 2851, 1296, 1425, 126);
	insert(eSkill::������ɽ, eSkill::ǿ��2, eSkill::̩ɽѹ��, eSkill::����2);


	init(eMod::eҹ��ɲ, 125, eAp::GiveMagic);
	insert(1620, 1555, 6220, 3110, 1555, 1555, 126);
	insert(eSkill::����2, eSkill::��ɱ, eSkill::ҹ�����, eSkill::ħ֮��2);


	init(eMod::e̤����, 135, eAp::Atk);
	insert(1645, 1555, 5832, 1944, 1555, 1555, 126);
	insert(eSkill::������, eSkill::ǿ��2, eSkill::��ɱ2, eSkill::�м�2);


	init(eMod::e��������, 135, eAp::Rand);
	insert(1620, 1620, 5832, 3240, 1036, 1944, 127);
	insert(eSkill::����2, eSkill::ڤ˼2, eSkill::������, eSkill::�Ϲ����);


	init(eMod::eЫ�Ӿ�, 135, eAp::GiveMagic);
	insert(1581, 1581, 6739, 3110, 1425, 2073, 127);
	insert(eSkill::��, eSkill::�м�, eSkill::����2, eSkill::����2);


	init(eMod::e��«����, 135, eAp::Magic);
	insert(1555, 1620, 5184, 2980, 1425, 1944, 126);
	insert(eSkill::ڤ˼2, eSkill::����, eSkill::ħ֮��, eSkill::�Ϲ����);


	init(eMod::e����, 135, eAp::Magic);
	insert(1555, 1684, 6220, 3240, 1296, 1684, 127);
	insert(eSkill::��������, eSkill::ˮ��������, eSkill::����, eSkill::����2, eSkill::ˮ��);


	init(eMod::e���س�, 135, eAp::Atk);
	insert(1620, 1620, 5832, 1814, 1425, 1555, 127);
	insert(eSkill::�м�2, eSkill::���ݻ���, eSkill::�����, eSkill::��ɱ);


	init(eMod::e������, 135, eAp::Atk);
	insert(1620, 1620, 5832, 1814, 1425, 1555, 127);
	insert(eSkill::�м�2, eSkill::���ݻ���, eSkill::�����, eSkill::��ɱ);


	init(eMod::eè����, 155, eAp::Atk);
	insert(1645, 1581, 4924, 2851, 1620, 1814, 128);
	insert(eSkill::����, eSkill::����, eSkill::��ɱ, eSkill::͵Ϯ2, eSkill::����2);


	init(eMod::e��, 145, eAp::Atk);
	insert(1620, 1555, 4924, 2332, 1425, 1684, 126);
	insert(eSkill::����2, eSkill::͵Ϯ, eSkill::ǿ��2, eSkill::ҹս);


	init(eMod::e������, 145, eAp::Magic);
	insert(1555, 1620, 5702, 3110, 1555, 1555, 126);
	insert(eSkill::�һ�, eSkill::ħ֮��, eSkill::��������2, eSkill::����������);


	init(eMod::e������, 145, eAp::Atk);
	insert(1620, 1451, 5184, 2721, 1684, 1684, 126);
	insert(eSkill::����, eSkill::͵Ϯ2, eSkill::������, eSkill::����2, eSkill::ҹս);


	init(eMod::e����, 145, eAp::Atk);
	insert(1620, 1684, 5832, 2592, 1296, 1425, 126);
	insert(eSkill::�ٶ�2, eSkill::ǿ��2, eSkill::����, eSkill::����);


	init(eMod::e����, 145, eAp::Atk);
	insert(1645, 1555, 5184, 1684, 1684, 1684, 128);
	insert(eSkill::����, eSkill::��Ѫ׷��, eSkill::��֪, eSkill::��, eSkill::����);


	init(eMod::e��ü���, 155, eAp::Magic);
	insert(1555, 1620, 6091, 3499, 1296, 1684, 127);
	insert(eSkill::��������, eSkill::����2, eSkill::ڤ˼, eSkill::������);


	init(eMod::e������Գ, 155, eAp::Atk);
	insert(1620, 1555, 4924, 2851, 1620, 1684, 128);
	insert(eSkill::����, eSkill::����2, eSkill::ǿ��, eSkill::����2, eSkill::����2);


	init(eMod::e���޿��ܹ�, 155, eAp::Atk);
	insert(1645, 1490, 5443, 2592, 1555, 1555, 128);
	insert(eSkill::��Ѫ׷��, eSkill::ǿ��, eSkill::����, eSkill::ҹս2, eSkill::��ɱ2);


	init(eMod::e��������, 155, eAp::Magic);
	insert(1581, 1555, 4924, 3369, 1296, 1555, 128);
	insert(eSkill::��������2, eSkill::����, eSkill::�м�2, eSkill::���ܼ���);


	init(eMod::e������, 155, eAp::Magic);
	insert(1581, 1555, 5443, 3499, 1425, 1555, 128);
	insert(eSkill::��������2, eSkill::��������, eSkill::�Ϲ����);


	init(eMod::eè��, 135, eAp::Atk);
	insert(1581, 1581, 4406, 2592, 1684, 1814, 126);
	insert(eSkill::����, eSkill::��ɱ, eSkill::͵Ϯ2, eSkill::����ˮ);


	init(eMod::e����, 155, eAp::Atk);
	insert(1658, 1555, 5184, 2462, 1555, 1684, 127);
	insert(eSkill::͵Ϯ, eSkill::��Ѫ, eSkill::����2, eSkill::ҹս, eSkill::ǿ��2);


	init(eMod::e������, 155, eAp::Magic);
	insert(1555, 1594, 5830, 3499, 1425, 1684, 129);
	insert(eSkill::����, eSkill::����2, eSkill::�۸�2, eSkill::ħ֮��2, eSkill::������);


	init(eMod::e���޿�����, 165, eAp::Atk);
	insert(1658, 1490, 5184, 2592, 1620, 1555, 128);
	insert(eSkill::����2, eSkill::����2, eSkill::��֪, eSkill::����);


	init(eMod::e�����޺�, 165, eAp::Atk);
	insert(1490, 1620, 5832, 2592, 1684, 1555, 129);
	insert(eSkill::����, eSkill::����2, eSkill::���Ӹ���, eSkill::����, eSkill::����2);


	init(eMod::e����ɳ��, 165, eAp::GiveMagic);
	insert(1555, 1555, 5184, 2851, 1620, 1555, 129);
	insert(eSkill::����, eSkill::����2, eSkill::�м�, eSkill::�����ֿ�, eSkill::���ܼ���);


	init(eMod::e�������, 175, eAp::Rand);
	insert(1516, 1645, 6220, 2980, 1658, 1555, 129);
	insert(eSkill::�۸�2, eSkill::����, eSkill::�׻�, eSkill::ˮ��������2, eSkill::��η��ʩ);


	init(eMod::e���ӻ���, 175, eAp::Atk);
	insert(1658, 1555, 5443, 2592, 1490, 1684, 127);
	insert(eSkill::������2, eSkill::��ɱ, eSkill::͵Ϯ, eSkill::��Ѫ, eSkill::ҹս, eSkill::����);


	init(eMod::e�ֹ�Ѳ��, 175, eAp::Magic);
	insert(1555, 1490, 6480, 3240, 1296, 1036, 127);
	insert(eSkill::����, eSkill::������, eSkill::���Ӹ���, eSkill::��������);


	init(eMod::e����Ѳ��, 175, eAp::Atk);
	insert(1620, 1490, 6480, 2980, 1296, 1036, 127);
	insert(eSkill::�м�2, eSkill::����, eSkill::���Ӹ���, eSkill::��ɽ����);


	init(eMod::e����ͯ��, 175, eAp::Atk);
	insert(1684, 1542, 4536, 2332, 1555, 1749, 128);
	insert(eSkill::����, eSkill::�����ֿ�2, eSkill::����2, eSkill::����, eSkill::��);


	init(eMod::e������Ů, 175, eAp::Magic);
	insert(1579, 1579, 5953, 3559, 1597, 1693, 129);
	insert(eSkill::����2, eSkill::����2, eSkill::����, eSkill::ħ֮��, eSkill::�۸�2, eSkill::�Ϲ����);


	init(eMod::eСëͷ, 0, eAp::Atk);


	init(eMod::eСѾѾ, 0, eAp::Atk);


	init(eMod::eС����, 0, eAp::Atk);


	init(eMod::eС��Ů, 0, eAp::Atk);


	init(eMod::eС����, 0, eAp::Atk);


	init(eMod::eСħͷ, 0, eAp::Atk);


	init(eMod::e�����˲�����, 0, eAp::Atk);
	insert(eSkill::���ݻ���, eSkill::��ɱ2, eSkill::ǿ��2, eSkill::����, eSkill::����2);


	init(eMod::e��������, 0, eAp::Atk);
	insert(eSkill::��ɱ2, eSkill::���Ӹ���2, eSkill::��֪2, eSkill::ҹս, eSkill::����2);


	init(eMod::e��������è, 0, eAp::Atk);
	insert(eSkill::��֪2, eSkill::ǿ��2, eSkill::����2, eSkill::ҹս, eSkill::����2);


	init(eMod::e�������, 0, eAp::Atk);
	insert(eSkill::͵Ϯ2, eSkill::����2, eSkill::����2, eSkill::ҹս, eSkill::����2);


	init(eMod::e��������, 0, eAp::Atk);
	insert(eSkill::ǿ��2, eSkill::����2, eSkill::����2, eSkill::ҹս, eSkill::��ɱ2);


	init(eMod::e��������, 0, eAp::Atk);
	insert(eSkill::��ɱ2, eSkill::����2, eSkill::ҹս2, eSkill::��֪, eSkill::����2);


	init(eMod::e������¹, 0, eAp::Atk);
	insert(eSkill::�ƶ��б�, eSkill::����2, eSkill::ڤ˼2, eSkill::����, eSkill::͵Ϯ2);


	init(eMod::e����������, 0, eAp::Atk);
	insert(eSkill::��֪2, eSkill::��ɱ2, eSkill::����2, eSkill::����, eSkill::��2);


	init(eMod::e��������, 0, eAp::Atk);
	insert(eSkill::��ɱ, eSkill::����2, eSkill::����2, eSkill::���Ӹ���2, eSkill::͵Ϯ2);


	init(eMod::e�������, 0, eAp::Atk);
	insert(eSkill::���Ӹ���2, eSkill::͵Ϯ2, eSkill::����2, eSkill::ǿ��, eSkill::ҹս2);


	init(eMod::e��������, 0, eAp::Atk);
	insert(eSkill::�����ķ�, eSkill::͵Ϯ2, eSkill::��ɱ2, eSkill::ҹս, eSkill::����2);


	init(eMod::e��������, 0, eAp::Magic);
	insert(eSkill::��������, eSkill::��������2, eSkill::�¹�, eSkill::����, eSkill::���Ӹ���2);


	init(eMod::e������ȸ, 0, eAp::Atk);
	insert(eSkill::͵Ϯ2, eSkill::����2, eSkill::����2, eSkill::��ɱ, eSkill::����2);


	init(eMod::e�������, 0, eAp::Atk);
	insert(eSkill::����һ��, eSkill::����2, eSkill::��ɱ2, eSkill::ҹս, eSkill::͵Ϯ2);


	init(eMod::e�������, 0, eAp::Atk);
	insert(eSkill::���ŭ��, eSkill::ҹս2, eSkill::����2, eSkill::����, eSkill::����2);


	init(eMod::e��������, 0, eAp::Atk);
	insert(eSkill::����2, eSkill::����2, eSkill::����2, eSkill::͵Ϯ, eSkill::ҹս2);


	init(eMod::e��������⨺�, 0, eAp::Magic);
	insert(eSkill::��������, eSkill::��������2, eSkill::��������2, eSkill::����, eSkill::�Ϲ����);


	init(eMod::e�������ع���, 0, eAp::Magic);
	insert(eSkill::���Ӹ���2, eSkill::��������2, eSkill::�콵���, eSkill::�м�, eSkill::ħ֮��2);


	init(eMod::e������ţ, 0, eAp::Atk);
	insert(eSkill::������ɽ, eSkill::����2, eSkill::�м�2, eSkill::��ɱ, eSkill::ǿ��);


	init(eMod::e������, 0, eAp::Atk);
	insert(eSkill::��֪2, eSkill::��Ѫ׷��, eSkill::ҹս2, eSkill::����, eSkill::ǿ��);


	init(eMod::e��������, 0, eAp::Atk);
	insert(eSkill::����2, eSkill::͵Ϯ2, eSkill::����2, eSkill::ҹս, eSkill::����);


	init(eMod::e��������, 0, eAp::Magic);
	insert(eSkill::������, eSkill::����, eSkill::��������, eSkill::ħ֮��, eSkill::����);


	init(eMod::e��������, 0, eAp::Magic);
	insert(eSkill::�����һ�, eSkill::���ܼ���, eSkill::��������2, eSkill::ħ֮��, eSkill::����);


	init(eMod::e��������, 0, eAp::Atk);
	insert(eSkill::����2, eSkill::���Ӹ���2, eSkill::��������, eSkill::����, eSkill::��);


	init(eMod::e��������, 0, eAp::Atk);
	insert(eSkill::��ɱ2, eSkill::����2, eSkill::ǧ��һŭ, eSkill::����, eSkill::��֪);


	init(eMod::e�������, 0, eAp::Atk);
	insert(eSkill::���Ӹ���2, eSkill::��Ѫ2, eSkill::������, eSkill::��ɱ, eSkill::����);


	init(eMod::e������, 0, eAp::Atk);
	insert(eSkill::���Ӹ���2, eSkill::ǿ��2, eSkill::�������, eSkill::ҹս, eSkill::��ɱ);


	init(eMod::e��ҧ��, 115, eAp::Atk);


	init(eMod::e��������, 115, eAp::Atk);


	init(eMod::e�׾���, 115, eAp::Atk);


	init(eMod::e������ʦ, 115, eAp::Atk);


	init(eMod::eţħ��, 115, eAp::Atk);


	init(eMod::e�ն���ʦ, 115, eAp::Atk);


	init(eMod::e�������, 115, eAp::Atk);


	init(eMod::e������, 115, eAp::Atk);


	init(eMod::e��Ԫ����, 115, eAp::Atk);


	init(eMod::e�����, 115, eAp::Atk);


	init(eMod::e�, 115, eAp::Atk);


	init(eMod::e�ز���, 115, eAp::Atk);


	init(eMod::e������, 115, eAp::Atk);


	init(eMod::e��ӿ����, 115, eAp::Atk);


	init(eMod::e�׿���, 115, eAp::Atk);


	init(eMod::eХ��Ȯ, 115, eAp::Atk);


	init(eMod::e������, 115, eAp::Atk);


	init(eMod::eռ��ʦ, 115, eAp::Atk);


	init(eMod::eת����, 115, eAp::Atk);


	init(eMod::e��ɫ¹, 115, eAp::Atk);


	init(eMod::e����, 115, eAp::Atk);


	init(eMod::e�Ʋ�ͯ��, 115, eAp::Atk);


	init(eMod::e�ܽ���, 115, eAp::Atk);


	init(eMod::e�����, 115, eAp::Atk);


	init(eMod::e��˽�, 115, eAp::Atk);


	init(eMod::eɳ����, 115, eAp::Atk);


	init(eMod::e����, 115, eAp::Atk);


	init(eMod::e��ͷ����, 115, eAp::Atk);


	init(eMod::e��ü��, 115, eAp::Atk);


	init(eMod::e���, 115, eAp::Atk);


	init(eMod::eѩ��, 115, eAp::Atk);


	init(eMod::eС����, 0, eAp::GiveMagic);


	init(eMod::eС��, 0, eAp::GiveMagic);


	init(eMod::eС����, 0, eAp::GiveMagic);


	init(eMod::e����, 115, eAp::Atk);


	init(eMod::eɧ�˽�, 0, eAp::Atk);


	init(eMod::e�޺�, 0, eAp::Atk);


	init(eMod::e�ۺ�, 115, eAp::Atk);


	init(eMod::e��ͷ, 115, eAp::Atk);


	init(eMod::e��򼾫, 995, eAp::GiveMagic);
	insert(2000, 2000, 9980, 3800, 2000, 2000, 130);


	init(eMod::e������ħ, 995, eAp::GiveMagic);
	insert(2000, 2000, 9980, 3800, 2000, 2000, 130);

	//////////////////////////////////////////////////////////////////////////
	for (eMod e = eMod::ePet0; e <= eMod::ePet0end; e = (eMod)((int)e + 1))
	{
		_zz = &_tables.at(e);
		insert(1500, 1500, 5000, 2500, 1500, 1500, 125);
	}
	for (eMod e = eMod::ePetBaby0; e <= eMod::ePetBabyEnd; e = (eMod)((int)e + 1))
	{
		_zz = &_tables.at(e);
		insert(1600, 1600, 6000, 3000, 1600, 1600, 130);
	}

	for (eMod e = eMod::ePet115; e <= eMod::ePet115end; e = (eMod)((int)e + 1))
	{
		_zz = &_tables.at(e);
		insert(1600, 1600, 6000, 3000, 1600, 1600, 130);
	}

	_tables.at(eMod::eС����) = _tables.at(eMod::e��������);
	_tables.at(eMod::eС��) = _tables.at(eMod::e��������);
	_tables.at(eMod::eС����) = _tables.at(eMod::e��������);

};