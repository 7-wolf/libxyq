#pragma once
#include "_asert.h"

struct sControler
{
	void Set(int bfly = 1, int bdel = 1, int bBB = 0, int bHavebb = 0, int bCanGrab = 0)
	{
		m_bBB = bBB;
		m_bDelete = bdel;
		m_HaveBB = bHavebb;
		m_bFly = bfly;
		m_CanGrab = bCanGrab;
	}
	void Save(ofstream& File);
	void Load(ifstream& File);
//	int GetOwner(){ return m_Hero; };

	int  GetFly(){ return m_bFly; }
	int GetDel(){ return m_bDelete; }
	int CheckBB(){ return m_bBB; }
	int CheckHaveBB(){ return m_HaveBB; }
	void SetHaveBB(int k){ m_HaveBB = k; }
	int CheckGrab(){ return m_CanGrab; }
private:
	int m_CanGrab = 0; //�Ƿ����ץ һ�㶼�ǲ���ץ��
	int m_bFly = 1;//�Ƿ�ᱻ����
	int m_bDelete = 1; //ս�����Ƿ�ɾ��
	int m_bBB = 0;//�Ƿ���ĳ�˵��ٻ���;
	int m_HaveBB = 0;//�Ƿ���BB
};