#pragma once
#include "eMod.h"

class txtMod
{
public:
	// �Ƿ񱦱�ģ��
	static bool isPet(eMod mod);
	// �Ƿ�Npcģ��
	static bool isNpc(eMod mod);
	// �Ƿ�����ģ��
	static bool isRole(eMod mod);
	// �����Ա�
	static bool isBoy(eMod eRole);
};