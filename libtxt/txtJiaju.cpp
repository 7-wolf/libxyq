#include "txtJiaju.h"

ccc_txt_instance_cpp(txtJiaju);

txtJiaju::txtJiaju()
{
	sTable tableEmpty;
	_tables.insert(std::make_pair(eIcon::һ��y, tableEmpty));
	_tables.insert(std::make_pair(eIcon::����e, tableEmpty));
	_tables.insert(std::make_pair(eIcon::����s, tableEmpty));
	_tables.insert(std::make_pair(eIcon::�ļ�s, tableEmpty));
}
