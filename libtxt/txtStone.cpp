#include "txtStone.h"

ccc_txt_instance_cpp(txtStone);


std::string txtStone::sStone::toString(const std::string& str /*= " "*/)const
{
	return txtStone::toString(pro) + str + cc::toString(value);
}


std::string txtStone::toString(eProPerty pro)
{
	switch (pro)
	{
	case eProPerty::�˺�: return "�˺�";
	case eProPerty::����: return "����";
	case eProPerty::����: return "����";
	case eProPerty::ħ��: return "ħ��";
	case eProPerty::����: return "����";
	case eProPerty::�ٶ�: return "�ٶ�";
	case eProPerty::��Ѫ: return "��Ѫ";
	case eProPerty::����: return "����";
	case eProPerty::����: return "����";
	case eProPerty::����: return "����";
	case eProPerty::ħ��: return "ħ��";
	case eProPerty::����: return "����";
	case eProPerty::��: return "��";
	case eProPerty::�׿�: return "�׿�";
	case eProPerty::����: return "����";
	case eProPerty::ˮ��: return "ˮ��";
	case eProPerty::���: return "���";
	case eProPerty::����: return "����";
	case eProPerty::����: return "����";
	case eProPerty::����: return "�������";
	case eProPerty::���: return "������";
	case eProPerty::�ظ�: return "��Ѫ�ظ�";
	case eProPerty::��ŭ: return "��ŭ";
	case eProPerty::����: return "������";
	}
	return "error";
}
