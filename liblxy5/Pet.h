#pragma once
#include "_global.h"

class cPet
{
public:
	sModelAction* GetModelAction(int id);
	void SetData(sPetData* date);
	sPetData* GetData(){ return m_pPetData; }

	void Set(sShangPinPet* pet, int stronglv);

	const sFightPoint* GetFightPoint();
	//	bool m_ID=0;
	cPetData  m_PetData;

	//ͨ���ȼ�(0-999) �� ǿ��(��Χ0-9) �������� ��ʹ���⺯��ǰ�������üӵ㷽ʽ
//	void AutoPetData(int modeid, int xiulian, sAddPoint* addpoint, bool m_bNeedSkill = true);
	void GetID(int Pos, vector<ulong>& out);// ulong& data1, ulong& data2, ulong& data3,ulong& data4);
	ulong GetID(int Pos);
//	void GetRanse(sChangeColorData* (&pChangeColor)[4]);
	void GetRanse(array<sChangeColorData*, 4>& pChangeColor);
private:
	sPetData*  m_pPetData = 0;

};