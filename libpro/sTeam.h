#pragma once
#include "sRole.h"

struct sTeam
{
	static const int c5 = 5;
	static sTeam* getInstance();

	std::vector<sRole> members;
	int count = 0;
	bool fight = false;

	sTeam();
	~sTeam();

	bool setLeader(int idx);
	sRole& getLeader();
	sRole& getMember(int idx);

	bool swap(int idx);
	bool swap(int idx, int idx2);
	bool add();
	bool remove(int idx);

	// ����ս��
	bool beginFight();
	// �뿪ս��
	bool endFight();
	// �Ƿ�����ս��
	bool isFighting();

	void doObj(int tag, int tagNew);
	std::function<void(int, int, bool)> onObj = nullptr;
};