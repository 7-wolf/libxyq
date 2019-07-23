#include "cScript.h"
#include "cMap.h"
#include "cDialog.h"
#include "uiManager.h"
#include "uiSee.h"
#include "../libtxt/txtMap.h"


cScript* cScript::getInstance()
{
	static cScript* s_script = new cScript();
	return s_script;
}

static void goMap(cMap* map, ulong head, const std::string& name, const std::string& talk, const std::string& mapname, int x, int y)
{
	ccu::getManager()->getDialog()->load(head, name, talk, { "ȷ��", "ȡ��" }, [map, mapname, x, y](int select)
	{
		if (select == 0)
		{
			map->load(mapname);
			map->load(x, y);
		}
	});
}

static void goMap(cMap* map, ulong head, const std::string& name, const std::string& mapname, int x, int y)
{
	goMap(map, head, name, std::string("ǰ�� #Y") + mapname, mapname, x, y);
}


static void goMap(cMap* map, ulong head, const std::string& name, const std::string& mapname, const std::string& x, const std::string& y)
{
	goMap(map, head, name, mapname, std::atoi(x.c_str()), std::atoi(y.c_str()));
}



bool cScript::run(cMap* map, ulong head, const std::string& name, const std::string& script)
{
	std::vector<std::string> strs;
	cc::split(script, "_", strs);
	const std::string& str = strs.front();
	int size = strs.size();
	if (str == txtMap::_��ͼ����)
	{
		goMap(map, head, name, strs.at(1), strs.at(2), strs.at(3));
		return true;
	}
	if (str == txtMap::_��վ�ϰ�)
	{
		if (size == 1)
		{
			goMap(map, head, name, "������", 363, 30);
			return true;
		}

		if (strs[1] == "ۺ��")
		{
			goMap(map, head, name, "ǰ��#Y ۺ��", "���ƹ���", 80, 250);
			return true;
		}
		goMap(map, head, name, strs.at(1), strs.at(2), strs.at(3));
		return true;
	}
	if (size > 1 && str == "���ɾ���" && strs[1] == "�뿪����")
	{
		goMap(map, head, name, "�˳����ɾ���", "������", 370, 113);
		return true;
	}
	if (size > 1 && str == "Ӣ�۴��" && strs[1] == "�뿪����")
	{
		goMap(map, head, name, "�˳���Ӣ�۴��", "������", 116, 105);
		return true;
	}
	if (str == txtMap::_���ɴ��͵���)
	{
		goMap(map, head, name, "������", 470, 25);
		return true;
	}
	if (str == txtMap::_���ƹ�������)
	{
		ccu::getManager()->getDialog()->load(head, name, "ȥ��", { "�貨��", "��ˮ��", "�뿪" }, [map](int select)
		{
			if (select == 0)
			{
				map->load("�貨��");
				map->load(14, 67);
			}
			else if (select == 1)
			{
				map->load("��ˮ��");
				map->load(97, 71/*140, 17*/);
			}
		
		});
		return true;
	}
	return false;
}



void cScript::run(sRole& role, ulong head, const std::string& name)
{
	ccu::getManager()->getDialog()->load(head, name, "��ӭ���� #Y������#Y#1", { "����������Ƭ", "�����ι۹��", "�λ�Ⱥ����5", "�λ�Ⱥ����5.���ڰ�","������.С���ս��" }, [](int select)
	{
		if (cc::random(0, 100) < 50)
		{
			sRole r;
			std::vector<int> lvs = { 69, 89, 109, 129, 159, 175 };
			eMod emod = (eMod)cc::random((int)eMod::eJueSe0, (int)eMod::eJueSeEnd);
			r.mod.setMod(emod);
			r.name = txtRole::getInstance()->getTables().at(emod).name;
			cDye::sIdxs& idxs = r.mod.dyeRole;
			forv(idxs, v)
			{
				idxs.at(v) = cc::random(0, 8);
			}
	
			r.lv = lvs.at(cc::random(0U, lvs.size() - 1));
			r.point.reset(r.lv + sPoint::c10);
			r.point.remain = r.lv * 5;
			r.skilv = r.lv;
			r.menpai = (eMenpai)cc::random((int)eMenpai::eMenpai0, (int)eMenpai::eMenpaiEnd);
			forv(r.fuzhus, k)
			{
				r.fuzhus.at(k) = sSki::c180;
			}
			std::vector<eIcon> icons = { eIcon::ͷ��t, eIcon::����x, eIcon::eWeapon0, eIcon::����k, eIcon::����y, eIcon::Ь��x};
			forv (icons, k)
			{
				eIcon e = icons.at(k);
				sItem& it = r.equips.at(cEquip::getIdx(e));
				it.add();
				const auto& icon = txtIcon::getInstance()->getTables().at(e);
				it.setIcon(icons.at(k), cEquip::getId(e, r.lv));
				it.setData(true, true, 100, 100);
				cEquip::setTemp(it, 100);

				if (k == 2)
				{
					it.switchWeapon(r.mod.emod);
					r.applyWeapon();
				}
				else
				{
					it.switchArmor(txtMod::isBoy(r.mod.emod));
				}

				std::vector<int> stones;
				const auto& icon3 = txtIcon::getInstance()->getTables().at(eIcon::��ʯb);
				for (const auto& i : icon3)
				{
					if (cEquip::isStone(it.getType(), i.first))
					{
						stones.push_back(i.first);
					}
				}
				cEquip::setStone(it, stones.at(cc::random(0U, stones.size() - 1)));
			}
			ccp::fillHpMp(r);
			ccu::getManager()->getSee()->setVisible(true);
			ccu::getManager()->getSee()->load(r);
			return;
		}

		eMod emod = (eMod)cc::random((int)eMod::ePet0, (int)eMod::ePet175end);
		sProperty pet;
		pet.load(emod, true, true, true);
		pet.mod.setJinjie(cc::random(0, 3));
		int jdx = pet.mod.jdx % pet.mod.dyePets.size();
		cDye::sIdxs& idxs = pet.mod.dyePets.at(jdx);
		forv(idxs, v)
		{
			idxs.at(v) = cc::random(0, 8);
		}

		pet.lv = txtZz::getInstance()->getTables().at(emod).takelv;
		if (pet.lv <= 5)
		{
			pet.lv = 180;
		}
		pet.point.reset(pet.lv + sPoint::c10);
		pet.point.remain = pet.lv * 5;
		std::vector<eIcon> icons = { eIcon::����h, eIcon::��Ȧx, eIcon::����h};
		forv(icons, k)
		{
			eIcon e = icons.at(k);
			sItem& it = pet.equips.at(cEquip::getIdx(e));
			it.add();
			const auto& icon = txtIcon::getInstance()->getTables().at(e);
			it.setIcon(icons.at(k), cEquip::getId(e, pet.lv));
			it.setData(true, true, 100, 100);
			cEquip::setTemp(it, 100);

			std::vector<int> stones;
			const auto& icon3 = txtIcon::getInstance()->getTables().at(eIcon::��ʯb);
			for (const auto& i : icon3)
			{
				if (cEquip::isStone(it.getType(), i.first))
				{
					stones.push_back(i.first);
				}
			}
			cEquip::setStone(it, stones.at(cc::random(0U, stones.size() - 1)));
		}
		ccp::fillHpMp(pet);
		ccu::getManager()->getSee()->setVisible(true);
		ccu::getManager()->getSee()->load(pet);
	});
}