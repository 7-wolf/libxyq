#pragma once

// �Գ�����
struct int2
{
	// ����
	int d1 = 0;
	// ����
	int d2 = 0;

	// �ҵļ��� - ��Ŀ���
	int operator-(const int2& i)const
	{
		return d1 - i.d2;
	}
};


// ��������
struct sPropertyInfo
{
	// <������,�ٷֱ�>
	// ����: <����������, �����˺�Ϊƽʱ�˺��İٷֱ�>
	struct sRatePer
	{
		// ������ 0~100
		int rate = 0;
		// �ٷֱ� %
		int per = 0;
	};

	// <������,�ٷֱ�> ר�öԳ����ݽṹ
	struct sRatePer2
	{
		// �Գƴ�����
		int2 rate;
		// �Գưٷֱ�
		int2 per;

		sRatePer operator-(const sRatePer2& i)const
		{
			sRatePer s;
			s.rate = rate - i.rate;
			s.per = per - i.per;
			return s;
		}
	};

	// <+%,+ֵ>
	// ����: <�˺�+10%, �˺�+10>
	struct sPerAdd
	{
		// �ٷֱ� %
		int per = 0;
		// ����
		int add = 0;
	};

	// �˺����� ר�öԳ����ݽṹ
	struct sPerAdd2
	{
		// �ٷֱ� %
		int2 per;
		// ����
		int2 add;
		// ���ӿ���%
		int per2 = 0;

		sPerAdd operator-(const sPerAdd2& d)const
		{
			sPerAdd s;
			s.per = per - d.per;
			s.add = add - d.add;
			return s;
		}
	};

	// ������ ר�����ݽṹ
	struct sHit
	{
		// ����
		int d1 = 0;
		// ����
		int d2 = 0;
		// ���ӿ���, �����������
		int dper = 0;
		int operator-(const int2& i)const
		{
			return d1 - i.d2;
		}
	};

	// ���� �ûص�?
	// ҹս �߼�����+5%
	// ����ʱ���˺�
	// ���ܼ���
	// ��Ѫ׷��
	// ����
	// ������
	// ���
	// ����
	// ǧ��
	// ����
	// ���

	// ����
	int2 liveHp;
	// ڤ˼
	int2 liveMp;
	// ��ŭ(Ǭ��������)
	int2 liveAp;
	// ��
	int2 liveStoreRate;
	// ������ë
	int2 liveLifeRate;
	// �۸�25
	int2 mpSave;
	// ��ŭ������Ч 20
	int2 apSave;
	// ��������
	int2 magicWave;
	// ����
	int2 buffTimeAdd;
	// ��ʱ��ŭ
	int2 startAp;
	// ����(d1�غ���)
	int2 hide;
	// ���(d1������ d2�������˺���)
	int2 ghost;



	// ������ ����
	sHit hitRate;
	// ������ ����
	sHit hitRateMagic;
	// ������ ��ӡ
	sHit hitRateSeal;
	// ������ ��
	sHit hitRatePosion;
	// ������ ����
	sHit hitRateArm;



	// �˺����� ����
	sPerAdd2 damage;
	// �˺����� ����
	sPerAdd2 damageMagic;
	// �˺����� ����
	sPerAdd2 damageCure;
	// �˺����� ��
	sPerAdd2 damagePosion;
	// �˺����� ����
	sPerAdd2 damageArm;
	// �˺����� �̶��˺�
	sPerAdd2 damageFix;



	// ���� <������,�ٷֱ�>
	sRatePer2 gad;

	// �� ����
	int2 parryRate;
	// �� ����
	int2 parryRateMagic;

	// ��ɱ ����
	int2 criRate;
	// ���� ����
	int2 criRateMagic;
	// ���� ����
	int2 criRateCure;
	// ���� ����
	int2 comboRate;
	// ���� ����
	int2 comboRateMagic;
	// ���� ����
	int2 pierceRate;
	// ���� ����
	int2 pierceRateMaigc;
	// ����(�����) <������,�ٷֱ�>
	sRatePer2 counter;
	// ��Ѫ <������,�ٷֱ�>
	sRatePer2 blood;
	// ���� <������,�ٷֱ�>
	sRatePer2 stab;
	// �������� <������,�ٷֱ�>
	sRatePer2 stabMagic;
	// ���� <������,�ٷֱ�>
	sRatePer2 spurt;

	// ���л�: rate������  rate������ 
	sRatePer2 fire;
	// ������: rate������  rate������
	sRatePer2 soil;
	// ����ˮ: rate������  rate������
	sRatePer2 water;
	// ������: rate������  rate������
	sRatePer2 thunder;

	void resetCri();
};
