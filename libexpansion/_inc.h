#pragma once
#include "../libutil/_util.h"
#include "../libpro/sMod.h"
#include "../libtxt/_txt.h"

static inline std::string getIconName(eIcon e)
{
	switch (e)
	{
// 	case eIcon::eIcon0:
// 		
// 	case eIcon::equip0:
// 		
// 	case eIcon::eWeapon0:
// 		
	case eIcon::����j: return " �� ";
	case eIcon::����d: return " �� ";
	case eIcon::ǹǹq: return " ǹ ";
	case eIcon::����c: return "����";
	case eIcon::����f: return "����";
	case eIcon::����s: return " �� ";
	case eIcon::צ��z: return "��צ";
	case eIcon::���b: return "���";
	case eIcon::Ʈ��p: return "Ʈ��";
	case eIcon::����b: return " �� ";
	case eIcon::��Ȧh: return "��Ȧ";
	case eIcon::˫��s: return "˫��";
	case eIcon::����b: return "����";
	case eIcon::����g: return "����";
	case eIcon::����f: return "����";
	case eIcon::�޽�j: return "�޽�";
	case eIcon::����d: return "����";
	case eIcon::ɡɡs: return " ɡ ";
		
// 	case eIcon::eWeaponEnd:
// 		
// 	case eIcon::equipArmor0:
		
	case eIcon::ͷ��t: return "ͷ��";
	case eIcon::����f: return "����";
	case eIcon::����k: return "����";
	case eIcon::��ȹb: return "��ȹ";
	case eIcon::����x: return "����";
	case eIcon::����y: return "����";
	case eIcon::Ь��x: return "Ь��";

// 	case eIcon::equipArmorEnd:
// 		
// 	case eIcon::equipBaby0:
		
	case eIcon::����h: return "����";
	case eIcon::��Ȧx: return "��Ȧ";
	case eIcon::����h: return "����";

// 	case eIcon::equipBabyEnd:
// 		
// 	case eIcon::equipEnd:
		
	case eIcon::ҩƷy: return "ҩƷ";
	case eIcon::���p: return "���";
	case eIcon::����f: return "����";
	case eIcon::����a: return "����";
	case eIcon::����p: return "����";
	case eIcon::�屦w: return "�屦";
	case eIcon::Ⱦɫr: return "Ⱦɫ";
	case eIcon::ǿ��q: return "ǿ��ʯ";
	case eIcon::���g: return "�����";
	case eIcon::Ԫ��y: return "Ԫ��";
	case eIcon::����s: return "����ָ";
	case eIcon::����t: return "������";
	case eIcon::����d: return "����";
	case eIcon::����d: return "������";
	case eIcon::����q: return "�ϳ���";
	case eIcon::��ͼb: return "�ر�ͼ";
	case eIcon::����f: return "����";
	case eIcon::�ӻ�z: return "�ӻ�";
	case eIcon::����x: return "����";
	case eIcon::����b: return "����";
	case eIcon::ʦ��s: return "ʦ��";
	case eIcon::����r: return "����";
	case eIcon::����d: return "����";
	case eIcon::��ʯb: return "��ʯ";
	case eIcon::����h: return "����";
	case eIcon::����y: return "����";
	case eIcon::����z: return "����װ��";
	case eIcon::һ��y: return "һ���Ҿ�";
	case eIcon::����e: return "�����Ҿ�";
	case eIcon::����s: return "�����Ҿ�";
	case eIcon::�ļ�s: return "�ļ��Ҿ�";

// 	case eIcon::eMenpai0:
// 		
	case eIcon::����d: return "���ƹٸ�";
	case eIcon::����h: return "������";
	case eIcon::Ů��n: return "Ů����";
	case eIcon::����f: return "����ɽ";
	case eIcon::ʨ��s: return "ʨ����";
	case eIcon::ħ��m: return "ħ��կ";
	case eIcon::��˿p: return "��˿��";
	case eIcon::�ظ�d: return "���ܵظ�";
	case eIcon::����l: return "��������";
	case eIcon::��ׯw: return "��ׯ��";
	case eIcon::����p: return "����ɽ";
	case eIcon::�칬t: return "�칬";
	case eIcon::�貨l: return "�貨��";
	case eIcon::�޵�w: return "�޵׶�";
	case eIcon::��ľs: return "��ľ��";
// 		
// 	case eIcon::eMenpaiEnd:
// 		
	case eIcon::����j: return "����";
	case eIcon::�޾�s: return "ħ��Ҫ��";
	case eIcon::��ʯf: return "��ʯ";	
	case eIcon::����c: return "�����ڵ�";
	case eIcon::�ߵ�g: return "�߼��ڵ�";
	case eIcon::��Ƭk: return "����";
	case eIcon::׷��z: return "׷�ӷ�ʯ";
	case eIcon::״̬z: return "״̬��ʯ";
//	case eIcon::eIconEnd:	
	default: return "???";
	}
}


static inline const std::vector<eAct>& getActGroup(bool atk2)
{
	static std::vector<eAct> as = { eAct::Stand, eAct::Walk, eAct::Fight, eAct::Go, eAct::Atk, eAct::Magic, eAct::Def, eAct::Suffer, eAct::Dead, eAct::Back };
	static std::vector<eAct> as2 = { eAct::Stand, eAct::Walk, eAct::Fight, eAct::Go, eAct::Atk, eAct::Atk2, eAct::Magic, eAct::Def, eAct::Suffer, eAct::Dead, eAct::Back };
	return atk2 ? as2 : as;
}

static inline const std::vector<std::string>& getActNames(bool atk2)
{
	static std::vector<std::string>  names = { "վ��","����", "ս��","���","����","ʩ��","����","����","����","����", };
	static std::vector<std::string>  names2 = { "վ��","����", "ս��","���","����","����2","ʩ��","����","����","����","����", };
	return atk2 ? names2 : names;
}

