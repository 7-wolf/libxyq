#pragma once
#include "_txtinc.h"

namespace ctt
{
	enum class eItem
	{
		����j,
		����d,
		ǹǹq,
		����c,
		����f,
		����s,
		צ��z,
		���b,
		Ʈ��p,
		����b,
		��Ȧh,
		˫��s,
		����b,
		����g,
		����f,
		ͷ��t,
		����f,
		����k,
		��ȹb,
		����x,
		����y,
		Ь��x,
		ҩƷy,
		���p,
		����f,
		����a,
		��Ƭk,
		����d,
		����d,
		��ʯb,
		����h,
		����z,
		����h,
		��Ȧx,
		����h,
		һ��y,
		����e,
		����s,
		�ļ�s,
		����y,
		�޾�s,
		��ʯf,
		�޽�j,
		����d,
		ɡɡs,
	};


	struct sItem
	{
		eItem e;
		int id;
		ulong small;
		ulong big;
		std::string name;
		std::string desc;
	};

	const sItem& getItem(const eItem& e, int id);


	const vector<ctt::sItem>& getItems();


	inline vector<ulong> getWdfFromTxtItems()
	{
		auto is = getItems();
		set<ulong> us;
		for (const auto& i : is)
		{
			us.insert(i.small);
			us.insert(i.big);
		}
		us.erase(0);
		return vector<ulong>(us.begin(), us.end());
	}
}