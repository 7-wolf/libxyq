#pragma once
#include "_global.h"

class cPCHead :public cInterfaceFather
{
public:

	bool CheckL();

	int m_MouseOn;
	int m_MouseOnPre = -1;
	//��¼��һ�εĽ�ɫѪ��,�����һ��,�ټ���
	//�ܱ�ÿ֡������˷�������


	void UpdatePcHp();
	void UpdatePcMp();
	void UpdatePcCp();
	void UpdatePcExp();
	void UpdatePetHp();
	void UpdatePetMp();
	void UpdatePetExp();

	bool UpDateHead();
	cWasFile m_PetFaceBack; //�ٻ���ͷ�񱳾�
	cWasFile m_PCFace;
	vector<cWasFile> m_TeamFace;
	vector<cWasFile> m_TeamBack;
	vector<cWasFile> m_TeamPetFace;
	cWasFile m_PetFace;

	cPet*       m_pPet = 0;      //��ѡ��ʱ���ٻ���
	void SetPetHead(ulong head);
	void UpdateDate();
	bool UpdatePet();
	bool Init();
	// ս���ƶ������½�
	void MoveTeamHead(bool mode);
	bool SetPcID(int id);
	bool Show(cCanvas* pCanvas);
	bool ProcessInput();
	virtual void OnOff(bool NeedShow){};
	bool CheckRB();

	vector<cObjWas> m_EmptyLinep;
	cWasFile m_EmptyLine;


	vector<cObjWas> m_HPlinep;
	vector<cObjWas> m_HeartHurtp;
	vector<cObjWas> m_MPlinep;
	vector<cObjWas> m_EXPlinep;

	cWasFile m_MPline;
	cWasFile m_CPline;
	cWasFile m_HeartHurt;
	cWasFile m_EXPline;
	cWasFile m_HPline;

	cWasFile m_Heart;
	cWasFile m_PetHead;
	cWasFile m_CharacterHead;
	cText m_TMouseOnLine;
private:
	bool m_bPetHeadMode[5];
	bool m_bInit = false;
};

