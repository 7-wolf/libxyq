#include "Controler.h"


void sControler::Save(ofstream& File)
{
	File << g_strSpace;
	File << m_CanGrab << g_strSpace; //�Ƿ�����ҿ���
	File << m_bFly << g_strSpace;//�Ƿ�ᱻ����
	File << m_bDelete << g_strSpace; //ս�����Ƿ�ɾ��
	File << m_bBB << g_strSpace;//�Ƿ���ĳ�˵��ٻ���;
	File << m_HaveBB << g_strSpace;//�Ƿ���BB
}

void sControler::Load(ifstream& File)
{
	File >> m_CanGrab; //�Ƿ�����ҿ���
	File >> m_bFly;//�Ƿ�ᱻ����
	File >> m_bDelete; //ս�����Ƿ�ɾ��
	File >> m_bBB;//�Ƿ���ĳ�˵��ٻ���;
	File >> m_HaveBB;//�Ƿ���BB
}