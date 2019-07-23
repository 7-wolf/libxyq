#include "txtMod.h"

bool txtMod::isPet(eMod mod)
{
	return mod >= eMod::ePet0 && mod <= eMod::ePetEnd;
}

bool txtMod::isNpc(eMod mod)
{
	return mod >= eMod::eNpc0 && mod <= eMod::eNpcEnd;
}

bool txtMod::isRole(eMod mod)
{
	return mod >= eMod::eJueSe0 && mod <= eMod::eJueSeEnd;;
}


bool txtMod::isBoy(eMod eRole)
{
	switch (eRole)
	{
	case eMod::eJueSe������:
	case eMod::eJueSe��ң��:
	case eMod::eJueSe��ͷ��:
	case eMod::eJueSe��ħ��:
	case eMod::eJueSe��̫��:
	case eMod::eJueSe�����:
	case eMod::eJueSe������:
	case eMod::eJueSeɱ����:
	case eMod::eJueSe����ʦ:
		return true;
	}
	return false;
}
