#include "_global.h"


bool cZuoQi::GetZuoQi(int charID, int ZuoQiID)
{
	cCharacter* p = (cCharacter*)g_pMainState->m_FightWorkList[charID].m_pObj->m_pIndex;
	return GetZuoQi(p->m_PcData, ZuoQiID);
}
bool cZuoQi::GetZuoQi(cPcData& data, int ZuoQiID)
{
	if (ZuoQiID < 0)return true;
	data.m_ZQ = ZuoQiID;
	data.m_ZuoQi.m_pZuoQi = &m_ZuoQi[ZuoQiID];
	data.m_ZuoQi.m_ownerID = data.modeid;
	data.m_ZuoQiRanSe.partnum = 0;
	data.m_ZhuangShiRanSe.partnum = 0;
	g_pMainState->m_InterfaceItem.CheckZuoQi(&data);
	return true;
}
bool cZuoQi::Init(string Path)
{
	ifstream File;
	File.open(Path);
	if (!File)return false;
	int num;
	File >> num;
	string dustbin;
	if (m_ZuoQi.size() != num)return false;
	forv(m_ZuoQi, i)
	{
		//	m_ZuoQi[i].ID = i;
		File >> m_ZuoQi[i].ID; //m_ZuoQi[i].ownerID;
		File >> m_ZuoQi[i].Name;
		File >> m_ZuoQi[i].nodeStand;
		File >> m_ZuoQi[i].nodeWalk;
		File >> m_ZuoQi[i].m_ColorID;

		ccm::get()->pushZuoqi(string("����") + m_ZuoQi[i].Name + "վ", m_ZuoQi[i].nodeStand);
		ccm::get()->pushZuoqi(string("����") + m_ZuoQi[i].Name + "��", m_ZuoQi[i].nodeWalk);

		forv (m_ZuoQi[i].CharStand, j)
		{
			File >> dustbin;
			File >> m_ZuoQi[i].CharStand[j];
			File >> m_ZuoQi[i].CharWalk[j];

			ccm::get()->pushRoleZuoqi(string("����") + m_ZuoQi[i].Name + toString("(_��ɫ%d_վ)", j), m_ZuoQi[i].CharStand[j]);
			ccm::get()->pushRoleZuoqi(string("����") + m_ZuoQi[i].Name + toString("(_��ɫ%d_��)", j), m_ZuoQi[i].CharWalk[j]);
		}
	}


	return true;
}

void cZuoQi::GetShiPei(vector<int>& list, int modeid)
{
	list.clear();
	if (modeid == eJuSe����ʦ || modeid == eJuSe��زز || modeid == eJuSe������)
	{
		return;
	}
	list.push_back(0);
	list.push_back(1);
	switch (modeid)
	{
	case eJuSe������:
	case eJuSe��ң��:
	case eJuSe����Ů:
	case eJuSeӢŮ��:
	case eJuSe������:
		list.push_back(2);
		list.push_back(3);
		break;
	case eJuSe��ͷ��:
	case eJuSe��ħ��:
	case eJuSe�Ǿ���:
	case eJuSe������:
	case eJuSeɱ����:
		list.push_back(4);
		list.push_back(5);
		break;
	case eJuSe��̫��:
	case eJuSe�����:
	case eJuSe���ʶ�:
	case eJuSe���켧:
	case eJuSe������:
		list.push_back(6);
		list.push_back(7);
		break;
	}
}

