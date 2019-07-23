#pragma once
#include "_txtinc.h"

enum class eProPerty
{
	None = -1,
	�˺�,
	����,
	����,
	����,
	ħ��,
	����,
	�ٶ�,
	��Ѫ,
	����,
	����,
	����,
	ħ��,
	����,
	ˮ��,
	��,
	����,
	�׿�,
	���,
	����,
	����,
	����,
	���,
	�ظ�,
	��ŭ
};


enum class eStone
{
	��âʯ,
	�ڱ�ʯ,
	�����,
	������,
	����ʯ,
	̫��ʯ,
	����ʯ,
	���ʯ,
	������ʯ_�ٶ�,
	������ʯ_����,
	������ʯ_����,
	������ʯ_���,
	������ʯ_�˺�,
	������ʯ_��Ѫ,
	�챦ʯ,
	�Ʊ�ʯ,
	����ʯ,
	�̱�ʯ,
};


ccc_txt_class_begin(txtStone);

struct sStone
{
	eProPerty pro = eProPerty::None;
	int value = 0;
	bool isVaild()const{ return pro != eProPerty::None && value > 0; }
	std::string toString(const std::string& str = " ")const;
};

static std::string toString(eProPerty pro);

friend class txtIcon;
ccc_txt_class_end(eStone, sStone);