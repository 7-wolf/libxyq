#pragma once
#include "sDye.h"

struct sMod
{
	static const int c_1;
	enum class eRole { weapon, zq, xr, card };
	// ��ģ��
	eMod emod = eMod::eModNone;
	// ����
	eRole erole = eRole::weapon;
	// Ⱦɫ
	sDye dyeRole, dyeWeapon,  dyeZq, dyeZs;
	std::vector<sDye> dyePets;

	// ����
	eIcon eweapon;
	int weaponId = c_1;
	int weaponMasterIdx = 0;
	// ����
	eZuoqi ezq = eZuoqi::eZuoqiNone;
	// װ��
	int zsid = c_1;
	// ����
	int xrid = c_1;
	// ��ɫ����
	int xridx = 0;
	// ����ģ��
	eMod ecard = eMod::eModNone;
	// ����
	int jdx = 0;
	// �ɽ�/��ʥͷ��
	int dujie = 0;

	bool setRole(eRole e);
	void setMod(eMod e);
	bool setWeapon(eIcon e, int wid);
	bool setWeapon(int wlv);
	void setWeaponUnsnatch();
	bool setZuoqi(eZuoqi e);
	bool setZs(int zs);
	bool setXr(int idx);
	bool setXr();
	bool setCard(eMod e);
	bool setJinjie(int jdx);
	bool setJinjie();
	bool setDujie(int dj);

	typedef std::map<eAct, sSps> sActs;
	void apply(sActs& sps, bool fight, eIterType iter) const;
	void apply(txtAction::sAction& heads, bool fight) const;

	sSps get(eAct e) const ;

	void save(bool pet) const;
	void load(bool pet);
};