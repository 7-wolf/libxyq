#pragma once
#include "_inc.h"

// Ⱦ�� Ⱦɫ
class sDye
{
public:
	sDye();
	bool resetZero();
	// ����
	void reset();
	void reset(const cDye::sIdxs& idxs);
	bool isZero()const;
	// ����
	bool resize(int size);

	operator const cDye::sIdxs&() const;
	operator cDye::sIdxs&();

	void save()const;
	void load();
private:
	cDye::sIdxs _idxs;
};

