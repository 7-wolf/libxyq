#pragma once
#include "IntData.h"
#include "PointZZXL.h"

struct sPropertyData
{
	int  m_Lv = 0;
	sBBXiuLian m_XiuLian;
	int PointStr2 = 0;
	int PointDex2 = 0;
	int PointMag2 = 0;
	int PointBody2 = 0;
	int PointAgi2 = 0;
	sPropertyData(){ Reset(true, true, true); }

	int PointStr;
	int PointDex;
	int PointMag;
	int PointBody;
	int PointAgi;
	int PointRemain = 0;

	sInt3 HPMax;
	sInt3 MPMax;
	sInt3 Atk;   //�˺�
	sInt3 Hit;   //����
	sInt3 Def;   //����
	sInt3 Mana;  //����
	sInt3 Speed; //�ٶ�
	sInt3 Evade; //����

	int LiveHp = 0; //����
	int LiveMp = 0; //ڤ˼
	int LiveCp = 0; //��ŭ
	int LiveRestoreRate = 0; //״̬�ָ���
	int LiveRelifeRate = 0; // ������ë

	int MpSavePercent = 0; //�۸�	
	int CpSavePercent = 0; //��ŭ	

	int  MagicWavePercent = 0;  //��������

	int BuffedTiemsAdd = 0; //�����
	int TargetNumAdd = 0;//�������ö�������

	int ComboNumDown = 1;//��������
	int ComboNumUp = 2; //��������
//	int ShiXueAdd = 0; // �����˺�����

	int Cp1 = 0; // ��ʱ��ŭ
	int StartMagic = -1;//��������
	int EndMagic = -1;//��������

	sInt2 RelifeRate;//���
	sInt2 RelifePercent;//���
	//������ºͽ�ħ����Ч��
	sInt2 ParryRate;
	sInt2 ParryRateOfMaigc;

	sInt2 CriRate; //����
	sInt2 CriRateOfMagic; //����
	sInt2 CriRateOfCure; //����
	sInt2 CriDmgPercent; //��ɱ�˺�����

	sInt2 ComboRate;  //������
	sInt2 ComboRateOfMagic; //������

	sInt2 Pierce�̴�;//���ӷ�����
	sInt2 Pierce�̴�OfMagic; //����������

	sInt2 HitRate;  //����
	sInt2 HitRateOfMagic;//����
	sInt2 HitRateOfSeal;//��ӡ
	sInt2 HitRateOfPoison; //��
	//�˺��ӳ�  �����ӳ�
	sInt2 DmgPercentOfFix;//�̶�
	sInt2 DmgPercentOfMagic;//����
	sInt2 DmgPercent;//����
	sInt2 DmgPercentOfArm; //����
	sInt2 DmgPercentOfPoison; //��
	sInt2 DmgPercentOfCure;//����
	//�˺�����
	sInt2 DmgAdd;//�����˺��������
	sInt2 DmgAddOfMagic;//�˺��������
	sInt2 DmgAddOfCure;//����Ч������
	// ����
	sInt2 CounterRate;
	sInt2 CounterPercent;
	// ��Ѫ��
	sInt2 SuckBloodRate;
	sInt2 SuckBloodPercent;
	//����
	sInt2 StabRate;
	sInt2 StabRateOfMagic;    //���������˺�
	sInt2 StabPercent;
	sInt2 StabPercentOfMagic; //����������

	sInt2 Spurting;//����;

	//���������˺�, 0-100
	sInt2 MagicFire; //��
	sInt2 MagicSoil; //��
	sInt2 MagicWater;  //ˮ
	sInt2 MagicThunder;//��

	sInt2 Hide;
	sInt2 Ghost;


	void applyPoint(const sZiZhi* zz);
	void applyXL();
	void applyFZ(int lv, int id);
	void applyEquip(const vector<int>& props);
	void applyMP(int lv);
	void applyFabao(int e);
	void applyPetSkill(int e);
	void Reset(bool relv, bool repoint, bool reXL);
};