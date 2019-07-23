#pragma once
#include "PointZZXL.h"
#include "ccm.h"

enum eWeaponType
{
	eWeaponType��,
	eWeaponType��,
	eWeaponTypeǹ,
	eWeaponType��,
	eWeaponType��,
	eWeaponType��,
	eWeaponTypeצ,
	eWeaponType��,
	eWeaponTypeƮ��,
	eWeaponType��,
	eWeaponType��,
	eWeaponType˫��,
	eWeaponType��,
	eWeaponType��,
	eWeaponType��,
	eWeaponType�޽� = 42,
	eWeaponType����,
	eWeaponTypeɡ
};
enum eJueSe
{
	eJuSe������,
	eJuSe��ң��,
	eJuSe����Ů,
	eJuSeӢŮ��,
	eJuSe��ͷ��,
	eJuSe��ħ��,
	eJuSe�Ǿ���,
	eJuSe������,
	eJuSe��̫��,
	eJuSe�����,
	eJuSe���ʶ�,
	eJuSe���켧,
	eJuSe������,
	eJuSe������,
	eJuSeɱ����,
	eJuSe����ʦ,
	eJuSe��زز,
	eJuSe������
};

void GetWeaponType(int modeid, int& out1, int & out2);


struct sAttackPoint
{
	string name;
	int xOffset;
	int yOffset;
	int point;
};

struct sFightPoint
{
	int  m_xOff;
	int  m_yOff;
	array<int, 2>  m_Point;
	array<int, 2>  m_Point2;
	int  m_MagicPoint;
	void ReadChar(ifstream& File)
	{
		File >> m_xOff;
		m_yOff = m_xOff >> 1;
		File >> m_Point[0];
		File >> m_Point[1];
		//��ɫֻ��һ�ֹ���
		m_Point2[0] = m_Point[0];
		m_Point2[1] = m_Point[1];
		File >> m_MagicPoint;
	}
	void ReadPet(ifstream& File)
	{
		File >> m_xOff;
		m_yOff = m_xOff >> 1;
		File >> m_Point[0];
		File >> m_Point[1];
		File >> m_Point2[0];
		File >> m_Point2[1];
		File >> m_MagicPoint;
	}
	void operator=(sFightPoint& target)
	{
		m_xOff = target.m_xOff;
		m_yOff = target.m_yOff;
		m_Point[0] = target.m_Point[0];
		m_Point[1] = target.m_Point[1];
		m_Point2[0] = target.m_Point2[0];
		m_Point2[1] = target.m_Point2[1];
		m_MagicPoint = target.m_MagicPoint;
	}
};


struct sNameSexRace
{
	int m_ID;
	string m_Name;
	bool m_bSex;
	int m_Autorace;
};


struct sModelSound
{
	//����
	ulong	m_soundattack;
	ulong	m_soundattack2;
	ulong	m_soundmajic;
	ulong	m_sounddefend;
	ulong	m_soundsuffer;
	ulong   m_sounddead;
	ulong GetSoundID(int Pos);
};


struct sCharacterSound :public sModelSound
{
	void Read(ifstream& File)
	{
		File >> m_sounddead;
		File >> m_soundsuffer;
		File >> m_soundmajic;
		File >> m_soundattack;
		m_soundattack2 = m_soundattack;

		File >> m_sounddefend;
	}
};


struct sHeadBigSmall
{
	ulong	m_smallhead;
	ulong	m_bighead;
};




struct sCharacterHead
{
	array<sHeadBigSmall, 4> m_HeadMoods;
	ulong	m_dialog;
	ulong   m_HeadFriend;
	void Read(ifstream& File)
	{
		File >> m_dialog;
		File >> m_HeadFriend;
		forv(m_HeadMoods, i)
		{
			File >> m_HeadMoods[i].m_smallhead; //���Ͻǵ�ͷ��
			File >> m_HeadMoods[i].m_bighead; //�������е�ͷ��
		}
	}
};




struct sModelAction
{
public:
	ulong m_ColorID;
	ulong m_stand;
	ulong m_walk;
	ulong m_fstand;
	ulong m_run;
	ulong m_attack;
	ulong m_attack2;
	ulong m_magic;
	ulong m_defend;
	ulong m_suffer;
	ulong m_dead;
	ulong m_return;
	virtual ulong GetID(int posid);
	virtual void Read(ifstream& File)
	{
		File >> m_ColorID;
		File >> m_attack;
		File >> m_attack2;
		File >> m_dead;
		File >> m_defend;
		File >> m_stand;
		File >> m_fstand;
		File >> m_magic;
		File >> m_return;
		File >> m_run;
		File >> m_suffer;
		File >> m_walk;
	}
};


struct sCharacterActionSoundPoint :public sModelAction
{

	sCharacterSound m_Sound;
	sFightPoint m_Offset;
	void Read(ifstream& File)
	{
		File >> m_attack;
		m_attack2 = m_attack;
		File >> m_dead;
		File >> m_defend;
		File >> m_fstand;
		File >> m_magic;
		File >> m_return;
		File >> m_run;
		File >> m_stand;
		File >> m_suffer;
		File >> m_walk;
		m_Offset.ReadChar(File);
		string dustbin;
		getline(File, dustbin);
	}
};


struct sWeaponData :public sModelAction //һ��������һ��״̬
{
	int     Master;
	int     MasterPos; //������������Ľ�ɫ��ID
	void Read(ifstream& File)
	{
		File >> m_attack;
		m_attack2 = m_attack;
		File >> m_defend;
		File >> m_dead;
		File >> m_fstand;
		File >> m_magic;
		File >> m_return;
		File >> m_run;
		File >> m_stand;
		File >> m_suffer;
		File >> m_walk;
		File >> Master;
		File >> MasterPos;
	}
};





//һ�ֽ�ɫ
struct sCharacterData :public sNameSexRace
{
	ulong m_ColorID;
	vector<sCharacterActionSoundPoint> m_Pos; //���� ���� ��ƫ��
	array<sCharacterHead, 3> m_Head; //ͷ��
	//����
	ulong	m_posgreet;
	ulong	m_posbow;
	ulong	m_posdance;
	ulong	m_poscry;
	ulong   m_posangry;
	ulong   m_possit;
	void Read(ifstream& File)
	{
		File >> m_ID;
		int num;
		File >> num;
		m_Pos.resize(num);
		File >> m_ColorID;
		File >> m_Name;
		File >> m_Autorace;
		File >> m_bSex;
		File >> m_posbow;
		File >> m_poscry;
		File >> m_posdance;
		File >> m_posgreet;
		File >> m_possit;
		File >> m_posangry;
		ccm::get()->pushWdf(ccm::get()->strDescTemp + "֫��bow", m_posbow);
		ccm::get()->pushWdf(ccm::get()->strDescTemp + "֫���", m_poscry);
		ccm::get()->pushWdf(ccm::get()->strDescTemp + "֫����", m_posdance);
		ccm::get()->pushWdf(ccm::get()->strDescTemp + "֫��greet", m_posgreet);
		ccm::get()->pushWdf(ccm::get()->strDescTemp + "֫����", m_possit);
		ccm::get()->pushWdf(ccm::get()->strDescTemp + "֫������", m_posangry);

		for (int i = 0; i < num; i++)
		{
			m_Pos[i].Read(File);

			if (m_ID == 15 && !ccm::get()->isPushRole15)
			{
				continue;
			}
			ccm::get()->pushRole(ccm::get()->strDescTemp + "��", m_Pos[i].m_attack);
			ccm::get()->pushRole(ccm::get()->strDescTemp + "��", m_Pos[i].m_defend);
			ccm::get()->pushRole(ccm::get()->strDescTemp + "��", m_Pos[i].m_dead);
			ccm::get()->pushRole(ccm::get()->strDescTemp + "ս", m_Pos[i].m_fstand);
			ccm::get()->pushRole(ccm::get()->strDescTemp + "��", m_Pos[i].m_magic);
			ccm::get()->pushRole(ccm::get()->strDescTemp + "ת", m_Pos[i].m_return);
			ccm::get()->pushRole(ccm::get()->strDescTemp + "��", m_Pos[i].m_run);
			ccm::get()->pushRole(ccm::get()->strDescTemp + "վ", m_Pos[i].m_stand);
			ccm::get()->pushRole(ccm::get()->strDescTemp + "��", m_Pos[i].m_suffer);
			ccm::get()->pushRole(ccm::get()->strDescTemp + "��", m_Pos[i].m_walk);
		}
		m_Head[0].Read(File);
		m_Head[1].Read(File);
		if (m_ID == 15 && !ccm::get()->isPushRole15)
		{
			return;
		}
		ccm::get()->pushRoleHead(ccm::get()->strDescTemp + "�Ի�ͷ��", m_Head[0].m_dialog);
		ccm::get()->pushRoleHead(ccm::get()->strDescTemp + "����ͷ��", m_Head[0].m_HeadFriend);
		for (int i = 0; i < 4; ++i)
		{
			ccm::get()->pushRoleHead(ccm::get()->strDescTemp + toString("����ͷ��С%d", i), m_Head[0].m_HeadMoods[i].m_smallhead);
			ccm::get()->pushRoleHead(ccm::get()->strDescTemp + toString("����ͷ���%d", i), m_Head[0].m_HeadMoods[i].m_bighead);
		}

		ccm::get()->pushRoleHead(ccm::get()->strDescTemp + "�Ի�ͷ��(����)", m_Head[1].m_dialog);
		ccm::get()->pushRoleHead(ccm::get()->strDescTemp + "����ͷ��(����)", m_Head[1].m_HeadFriend);
		for (int i = 0; i < 4; ++i)
		{
			ccm::get()->pushRoleHead(ccm::get()->strDescTemp + toString("����ͷ��С%d(����)", i), m_Head[1].m_HeadMoods[i].m_smallhead);
			ccm::get()->pushRoleHead(ccm::get()->strDescTemp + toString("����ͷ���%d(����)", i), m_Head[1].m_HeadMoods[i].m_bighead);
		}

	}
	void ReadSound(int i, ifstream& File)
	{
		m_Pos[i].m_Sound.Read(File);
	}
	bool CanEquip(int EquipType);


};




struct sSkill;
struct sPetData : public sNameSexRace
{
	array<ulong, 2>	m_bighead;
	array<ulong, 2>   m_smallhead;
	array<ulong, 2>   m_dialoghead;
	vector<sModelAction> m_ModelActs;
	array<sFightPoint, 2> m_FightPoint;

	int m_addPointType;
	int m_LvTake;//Я���ȼ�

	sZiZhi m_ZiZhi;
	int m_SkillNum = 0;
	array<sSkill*, 24> m_pPetSkill;//�����24������,�����˰�- -!
	array<vector<int>, 4> m_ComponentTable;
	void GetID(int positionid, int Pos, vector<ulong>& out);
	ulong GetID(int positionid, int Pos);
	void Read2(ifstream& File);
	void ReadSound(ifstream& File);
	array<sModelSound, 2> m_Sound;
	sPetData()
	{
		forr(m_pPetSkill, i)
		{
			m_pPetSkill[i] = 0;
		}
	}
};