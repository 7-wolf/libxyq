#include "PropertyData.h"
#include "Item.h"
#include "cct.h"

void sPropertyData::applyPoint(const sZiZhi* zz)
{
	int lv = m_Lv;
	int atk, def, hp, mana, mp, speed, evade, hit;
	if (zz)
	{
		atk = lv * zz->atk * (1400 + 10 * zz->grow) / 750000;
		atk += PointStr * zz->grow / 100;

		def = (lv * zz->def) * 19 / 7500;
		def += (PointDex * zz->grow * 4) / 300;

		hp = (lv * zz->hp) / 1000;
		hp += PointBody * zz->grow * 6 / 100;

		mana = lv* (zz->mag + 1640) * (zz->grow + 100) / 75000;
		mana += PointBody * 3 + PointMag * 7 + PointStr * 4 + PointDex * 2;
		mana /= 10;

		mp = lv * zz->mag / 500 + zz->grow * PointMag * 3 / 100;

		speed = zz->speed * PointAgi / 1000;
		evade = zz->avoid * PointAgi / 300;

		hit = atk / 2;
		hit += PointStr * 5 / 2;
	}
	else
	{
		atk = PointStr/* * 7 / 9*/;
		def = PointDex * 5 / 3;
		hp = 100 + PointBody * 5;
		mana = PointMag * 7 + PointBody * 3 + PointStr * 4 + PointDex * 2;
		mana /= 10;
		mp = 80 + PointMag * 3;
		speed = PointAgi * 7 + PointBody + PointStr + PointDex;
		speed /= 10;
		evade = PointAgi;
		hit = PointStr * 7 / 3;
	}

	PointStr2 = 0;
	PointAgi2 = 0;
	PointBody2 = 0;
	PointMag2 = 0;
	PointDex2 = 0;
	Atk.Reset();
	Atk.SetDataOriginal(atk);
	Def.Reset();
	Def.SetDataOriginal(def);
	HPMax.Reset();
	HPMax.SetDataOriginal(hp);
	Mana.Reset();
	Mana.SetDataOriginal(mana);
	MPMax.Reset();
	MPMax.SetDataOriginal(mp);
	Speed.Reset();
	Speed.SetDataOriginal(speed);
	Evade.Reset();
	Evade.SetDataOriginal(evade);
	Hit.Reset();
	Hit.SetDataOriginal(hit);
}


void sPropertyData::applyXL()
{
	auto xl = m_XiuLian;
	DmgPercent.d1 += xl.GetAtk() * 2;
	DmgAdd.d1 += xl.GetAtk() * 5;
	DmgPercent.d2 += xl.GetDef() * 2;
	DmgAdd.d2 += xl.GetDef() * 5;

	DmgPercentOfMagic.d1 += xl.GetMag() * 2;
	DmgAddOfMagic.d1 += xl.GetMag() * 5;
	DmgPercentOfMagic.d2 += xl.GetDMag() * 2;
	DmgAddOfMagic.d2 += xl.GetDMag() * 5;
}



void sPropertyData::applyFZ(int lv, int id)
{
	if (id == 0)
	{
		HPMax.AddDataAdd(lv * 5);
	}
	else if (id == 1)
	{
		HPMax.AddDataAddPercent(lv);
	}
	else if (id == 2)
	{
		MPMax.AddDataAddPercent(lv);
	}
	else if (id == 3)
	{
		DmgPercentOfArm.d1 += lv;
	}
}


void sPropertyData::applyEquip(const vector<int>& props)
{
	bool isPoint = false;
	sPropertyData* data = this;
	int add = 1;
	for (int i = 2; i < props.size(); i += 2)
	{
		switch (props[i])
		{
		case eProPerty�˺�: data->Atk.AddDataOriginal(props[i + 1] * add); break;
		case eProPerty����: data->Hit.AddDataOriginal(props[i + 1] * add); data->Atk.AddDataOriginal(props[i + 1] * add / 3); break;
		case eProPerty����: data->Def.AddDataOriginal(props[i + 1] * add); break;
		case eProPertyħ��: data->MPMax.AddDataOriginal(props[i + 1] * add); break;
		case eProPerty����: data->Mana.AddDataOriginal(props[i + 1] * add); break;
		case eProPerty�ٶ�: data->Speed.AddDataOriginal(props[i + 1] * add); break;
		case eProPerty��Ѫ: data->HPMax.AddDataOriginal(props[i + 1] * add); break;
		case eProPerty����: data->PointStr2 += props[i + 1] * add; isPoint = true;  break;
		case eProPerty����: data->PointAgi2 += props[i + 1] * add; isPoint = true; break;
		case eProPerty����: data->PointBody2 += props[i + 1] * add; isPoint = true; break;
		case eProPertyħ��: data->PointMag2 += props[i + 1] * add; isPoint = true; break;
		case eProPerty����: data->PointDex2 += props[i + 1] * add; isPoint = true; break;
		case eProPerty��: data->MagicFire.d2 += props[i + 1]; break;
		case eProPerty�׿�: data->MagicThunder.d2 += props[i + 1]; break;
		case eProPerty����: data->MagicSoil.d2 += props[i + 1]; break;
		case eProPertyˮ��: data->MagicWater.d2 += props[i + 1]; break;
		case eProPerty���: data->Evade.AddDataOriginal(props[i + 1] * add); break;
		case eProPerty����: data->DmgAddOfMagic.d1 += props[i + 1] * 2; break;
		case eProPerty����: data->DmgAddOfMagic.d2 += props[i + 1] * 2; break;
		case eProPerty����: data->DmgAddOfMagic.d1 += props[i + 1] * 2; break;
		case eProPerty���: data->DmgAdd.d1 += props[i + 1] * 2; break;
		case eProPerty�ظ�: data->DmgAddOfCure.d2 += props[i + 1]; break;
		case eProPerty��ŭ: data->Cp1 += props[i + 1]; break;
		case eProPerty����: data->HitRate.d1 += props[i + 1]; break;
		}
	}

	if (isPoint)
	{
		int atk = PointStr2 * 7 / 9;
		int def = PointDex2 * 5 / 3;
		int hp = 100 + PointBody2 * 5;
		int mana = PointMag2 * 7 + PointBody2 * 3 + PointStr2 * 4 + PointDex2 * 2;
		mana /= 10;
		int mp = 80 + PointMag2 * 3;
		int speed = PointAgi2 * 7 + PointBody2 + PointStr2 + PointDex2;
		speed /= 10;
		int evade = PointAgi2;
		int hit = PointStr2 * 7 / 3;

		Atk.AddDataOriginal(atk);
		Def.AddDataOriginal(def);
		HPMax.AddDataOriginal(hp);
		Mana.AddDataOriginal(mana);
		MPMax.AddDataOriginal(mp);
		Speed.AddDataOriginal(speed);
		Evade.AddDataOriginal(evade);
		Hit.AddDataOriginal(hit);
	}

}


void sPropertyData::applyMP(int lv)
{
	float atk = 0, def = 0, mana = 0, evade = 0;
	for (int i = lv; i > 0; --i)
	{
		atk += 1.5f + 0.02f * i;
		def += 1 + 0.02f * i;
		mana += 0.5f + 0.01 * i;
		evade += 2 + 0.02f * i;
	}
	Atk.AddDataOriginal(atk);
	Def.AddDataOriginal(def);
	Mana.AddDataOriginal(mana);
	Evade.AddDataOriginal(evade);
}


void sPropertyData::applyFabao(int e)
{
	int lv = m_Lv;
	sPropertyData* data = this;
	int add = 1;
	switch (e)
	{
	case eFaBao0������:
		data->DmgPercentOfPoison.d1 += 5 * add;
		break;
	case eFaBao1�ɽ�Īа:
		data->DmgAdd.d1 += 50 * add;
		break;
	case eFaBao2�޺���:
		data->MpSavePercent += 10 * add;
		break;
	case eFaBao3����:
		data->LiveMp += 10 * add;
		break;
	case eFaBao4����:
		break;
	case eFaBao5������:
		data->Ghost.d2 += 10 * add;
		break;
	case eFaBao6��Ԫɡ:
		data->StabRateOfMagic.d1 += 20 * add;  //���������˺�
		data->StabPercentOfMagic.d1 += 5 * add; //����������
		break;
	case eFaBao7�޻����:
//		data.Spurting.d1 += 15 * add;
//		data.m_DamageAdd.d2 += 100 * add;
		break;
	case eFaBao8Ǭ��������:
		data->LiveCp += 2 * add;
		break;
	case eFaBao9�ն�:
		data->MagicFire.d1 += 5 * add;
		data->MagicWater.d1 += 5 * add;
		data->MagicSoil.d1 += 5 * add;
		data->MagicThunder.d1 += 5 * add;
		break;
	case eFaBao10���س�:
//		g_pMainState->m_GlobalButton[13] += 50 * add;
		break;
	case eFaBao11�¹ⱦ��:
		break;
	case eFaBao12��ɫ������:
		break;
	case eFaBao13��ɫ������:
		break;
	case eFaBao14��ɫ������:
		break;
	case eFaBao15��ɫ������:
		break;
	case eFaBao15��ɫ������:
		break;
	case eFaBao16����:
		break;
	case eFaBao17�ܽ����ְ�:
		data->Speed.AddDataAdd(30 * add);
		break;
	case eFaBao18ʱ֮��:
		data->RelifeRate.d1 += 5 * add;
		break;
	case eFaBao19ͨ�鱦��:
//		g_GlobalValues[14] += 5 * add;
		break;
	case eFaBao20�۱���:
//		g_GlobalValues[15] += 5 * add;
		break;
	case eFaBao21�����«:
		data->DmgAddOfCure.d1 += 64 * add;
		break;
	case eFaBao22��ľ����:
		data->DmgAddOfCure.d2 += 64 * add;
		break;
	case eFaBao23���뾵:
		data->StabRate.d1 += 20 * add;
		data->StabPercent.d1 += 5 * add;
		break;
	case eFaBao24��Ѫ�:
		data->SuckBloodRate.d1 += 5 * add;
		data->SuckBloodPercent.d1 += 5 * add;
		break;
	case eFaBao25�������:
		data->ParryRate.d1 += 5 * add;
		break;
	case eFaBao26��ħ����:
		data->ParryRateOfMaigc.d1 += 5 * add;
		break;
	case eFaBao27����:
		data->DmgPercentOfCure.d1 += 2 * add;
		data->DmgPercentOfCure.d2 += 2 * add;
		break;
	case eFaBao28������ë:
		data->LiveRelifeRate += 5 * add;
		break;
	case eFaBao29����:
		data->Pierce�̴�OfMagic.d1 += 2 * add;
		break;
	case eFaBao30�������ӡ:
		data->CriRateOfMagic.d1 += 5 * add;
		break;
	case eFaBao31����:
//		data.m_AtkDownMP.d1 += 1 * add;
		break;
	case eFaBao32�ȱ�:
		data->CriRateOfCure.d1 += 5 * add;
		break;
	case eFaBao33�ε�:
//		data.m_Spurting.d2 += 15 * add;
//		data.nightLv += 10 * add;
		break;
	default:
		ERRBOX;
		break;
	}
}


void sPropertyData::applyPetSkill(int e)
{
	int lv = m_Lv;
	sPropertyData* pPetDate = this;
	int add = 1;
	switch (e)
	{
	case 0://����
		pPetDate->CounterRate.d1 += add * 30;
		pPetDate->CounterPercent.d1 += add * 50;
		break;
	case 1://�߼�����
		pPetDate->CounterRate.d1 += add * 30;
		pPetDate->CounterPercent.d1 += add * 100;
		break;
	case 2://����
		pPetDate->StabRate.d1 += add * 30;
		pPetDate->StabPercent.d1 += add * 25;
		break;
	case 3://�߼�����
		pPetDate->StabRate.d1 += add * 30;
		pPetDate->StabPercent.d1 += add * 50;
		break;
	case 4://��Ѫ
		pPetDate->SuckBloodRate.d1 += add * 100;
		pPetDate->SuckBloodPercent.d1 += add * 20;
		break;
	case 5://�߼���Ѫ
		pPetDate->SuckBloodRate.d1 += add * 100;
		pPetDate->SuckBloodPercent.d1 += add * 35;
		break;
	case 6://����
		pPetDate->ComboRate.d1 += add * 45;
		pPetDate->DmgPercent.d1 -= 25;
		break;
	case 7://�߼�����
		pPetDate->ComboRate.d1 += add * 60;
		pPetDate->DmgPercent.d1 -= 20;
		break;
	case 8://����
		pPetDate->HitRate.d1 += add * 10;
		pPetDate->HitRate.d2 += add * 10;
		pPetDate->DmgPercentOfArm.d2 -= add * 50;
		break;
	case 9://�߼�����
		pPetDate->HitRate.d1 += add * 20;
		pPetDate->HitRate.d2 += add * 20;
		pPetDate->DmgPercentOfArm.d2 -= add * 20;
		break;
	case 10://ҹս
//		pPetDate->m_Spurting.d2 += 20;
		pPetDate->DmgPercent.d1 += add * 5;
//		pPetDate->nightLv += lv *10;
		break;
	case 11://�߼�ҹս
//		pPetDate->m_Spurting.d2 += 30;
		pPetDate->DmgPercent.d1 += add * 10;
//		pPetDate->nightLv += lv * 20;
		break;
	case 12://����
		pPetDate->Hide.d1 += add * 2;
		pPetDate->DmgPercent.d1 -= 20;
		break;
	case 13://�߼�����
		pPetDate->Hide.d1 += add * 5;
		pPetDate->DmgPercent.d1 -= 20;
		break;
	case 14://��֪
		pPetDate->Hide.d2 += add * 0xFF;
		break;
	case 15://�߼���֪
		pPetDate->Hide.d2 += add * 0xFF;
		pPetDate->HitRate.d1 += add * 20;
		break;
	case 16://����
		pPetDate->LiveHp += add * lv;
		break;
	case 17://�߼�����
		pPetDate->LiveHp += add * lv * 2;
		break;
	case 18://ڤ˼
		pPetDate->LiveMp += add * lv / 4;
		break;
	case 19://�߼�ڤ˼
		pPetDate->LiveMp += add * lv / 2;
		break;
	case 20://�۸�
		pPetDate->MpSavePercent += add * 25;
		break;
	case 21://�߼��۸�
		pPetDate->MpSavePercent += add * 50;
		break;
	case 22://���� �߼��ٶ�
//		pPetDate->m_CriRate.d2   -= lv*10;
//		pPetDate->CriRate.d2 -= add * 10;
		pPetDate->Speed.AddDataAddPercent(-add * 80);
		break;
	case 23://��ɱ
		pPetDate->CriRate.d1 += add * 10;
		break;
	case 24://�߼���ɱ
		pPetDate->CriRate.d1 += add * 20;
		break;
	case 25://����
		pPetDate->CriRate.d2 += add * 0xFF;
		break;
	case 26://�߼�����
		pPetDate->CriRate.d2 += add * 0xFF;
		pPetDate->HitRateOfMagic.d2 += add * 10;
		break;
	case 27://��
		pPetDate->LiveRestoreRate += add * 100;
		break;
	case 28://�߼���
		pPetDate->HitRateOfSeal.d2 += 0xFF;
		pPetDate->HitRateOfPoison.d2 += 0xFF;
		break;
	case 29://�м�
		pPetDate->HitRate.d2 += add * 10;
		break;
	case 30://�߼��м�
		pPetDate->HitRate.d2 += add * 20;
		break;
	case 31://����
		pPetDate->BuffedTiemsAdd += add * 3;
		break;
	case 32://�߼�����
		pPetDate->BuffedTiemsAdd += add * 6;
		break;
	case 33://����
		pPetDate->Speed.AddDataAddPercent(add * 10);
		break;
	case 34://�߼�����
		pPetDate->Speed.AddDataAddPercent(add * 20);
		break;
	case 35://ǿ��
		pPetDate->Atk.AddDataAdd(add * lv / 2);
		break;
	case 36://�߼�ǿ��
		pPetDate->Atk.AddDataAdd(add * lv);
		break;
	case 37://����
		pPetDate->Def.AddDataAdd(add * lv / 2);
		break;
	case 38://�߼�����
		pPetDate->Def.AddDataAdd(add * lv);
		break;
	case 39://͵Ϯ  
		pPetDate->StabRate.d2 += add * 64;//����������
		pPetDate->CounterRate.d2 += add * 0xFF;//����������
		break;
	case 40://�߼�͵Ϯ
		pPetDate->StabRate.d2 += add * 0xFF;//����������
		pPetDate->CounterRate.d2 += add * 0xFF;//����������
		break;
	case 41://��
		pPetDate->HitRateOfPoison.d1 += add * 10;
		break;
	case 42://�߼���
		pPetDate->HitRateOfPoison.d1 += add * 20;
		break;
	case 43://����
		pPetDate->Ghost.d2 += add * 50;
		break;
	case 44://�߼�����
		pPetDate->Ghost.d2 += add * 100;
		break;
	case 45://�����
		pPetDate->Ghost.d1 += add * 7;
		break;
	case 46://�߼������
		pPetDate->Ghost.d1 += add * 5;
		break;
	case 47://ħ֮��
		pPetDate->DmgPercentOfMagic.d1 += add * 10;
		break;
	case 48://�߼�ħ֮��
		pPetDate->DmgPercentOfMagic.d1 += add * 20;
		break;
	case 49://����
		pPetDate->RelifeRate.d1 += add * 20;
		pPetDate->RelifePercent.d1 += add * 50;
		break;
	case 50://�߼�����
		pPetDate->RelifeRate.d1 += add * 30;
		pPetDate->RelifePercent.d1 += add * 100;
		break;
	case 51://������
		pPetDate->HitRateOfSeal.d2 += add * 10;
		break;
	case 52://�߼�������
		pPetDate->HitRateOfSeal.d2 += add * 20;
		break;
	case 53://������
		pPetDate->RelifeRate.d2 += add * 15;
		break;
	case 54://�߼�������
		pPetDate->RelifeRate.d2 += add * 25;
		break;
	case 55://��������
		pPetDate->ComboRateOfMagic.d1 += add * 15;
		break;
	case 56://�߼���������
		pPetDate->ComboRateOfMagic.d1 += add * 25;
		break;
	case 57://��������
		pPetDate->CriRateOfMagic.d1 += add * 10;
		break;
	case 58://�߼���������
		pPetDate->CriRateOfMagic.d1 += add * 15;
		break;
	case 59://��������
		pPetDate->MagicWavePercent += add * 10;
		break;
	case 60://�߼���������
		pPetDate->MagicWavePercent += add * 20;
		break;
	case 61://�ٶ�
		pPetDate->Speed.AddDataAddPercent(-add * 50);
		break;
	case 62://�����
		pPetDate->MagicFire.d2 -= add * 50; //��	
		break;
	case 63://����ˮ
		pPetDate->MagicWater.d2 -= add * 50;  //ˮ
		break;
	case 64://������
		pPetDate->MagicSoil.d2 -= add * 50; //��
		break;
	case 65://������
		pPetDate->MagicThunder.d2 -= add * 50;//��
		break;
	case 66://����������
		pPetDate->MagicThunder.d2 += add * 20;//��
		break;
	case 67://�߼�����������
		pPetDate->MagicThunder.d2 += add * 30;//��
		break;
	case 68://����������
		pPetDate->MagicSoil.d2 += add * 20; //��
		break;
	case 69://�߼�����������
		pPetDate->MagicSoil.d2 += add * 30; //��
		break;
	case 70://����������
		pPetDate->MagicFire.d2 += add * 20; //��
		break;
	case 71://�߼�����������
		pPetDate->MagicFire.d2 += add * 30; //��
		break;
	case 72://ˮ��������
		pPetDate->MagicWater.d2 += add * 20;  //ˮ
		break;
	case 73://�߼�ˮ��������
		pPetDate->MagicWater.d2 += add * 30;  //ˮ
		break;
	case 74://�ƻ���ľ 
		pPetDate->DmgPercentOfArm.d2 += add * 99;
		break;
	case 75://����(���ܼ���)
//		pPetDate->Spurting.d1 += add * 15;
		break;
// 	case 76://��Ѫ׷��
// 		pPetDate->ShiXueAdd += add * 0xF;
// 		break;
//	case 77://���۷���(����)
//		pPetDate->m_DamageAddMagicLv.d2 += lv * 2;//�����˺����
// 		pPetDate->m_DamageAddLv.d2	+= lv * 2;  //�����˺����
// 		pPetDate->m_DamageAddPercentMagic2.d2 += 10;
// 		pPetDate->m_MagicWater.d2 += lv*20;  //ˮ
//		break;
//	case 78://�����ػ�(�߼�����)
//		pPetDate->m_DamageAddMagicLv.d2 += lv * 3;//�����˺����
// 		pPetDate->m_DamageAddLv.d2 += lv * 3;  //�����˺����
// 		pPetDate->m_DamageAddPercentMagic2.d2 += 15;
// 		pPetDate->m_MagicWater.d2 += lv * 30;  //ˮ
//		break;
	case 79://�����ֿ�
		pPetDate->DmgPercentOfMagic.d2 += add * 15;
		break;
	case 80://�߼������ֿ�
		pPetDate->DmgPercentOfMagic.d2 += add * 25;
		break;
	case 81://ֱ��(���ݣ�С�绪)
		pPetDate->Pierce�̴�.d1 += 4;//���ӷ�����
//		pPetDate->m_PierceMagic.d1+=30; //����������
//		pPetDate->ComboNumUp += add * 1;
		//		pPetDate->m_Combo.d1 += lv * 15;
		break;
	case 82://�绪��ʥ(�߼�����)
		pPetDate->Pierce�̴�.d1 += 8;//���ӷ�����
//		pPetDate->ComboNumUp += add * 3;
//		pPetDate->m_Combo.d1 += lv * 15;
		break;
	case 83://��������,��������
		pPetDate->StabRateOfMagic.d1 += add * 30;//����������
		pPetDate->StabPercentOfMagic.d1 += add * 25;//���������˺���
		break;
	case 96: // ����
		break;
	case 100:// ���
		break;
	case 103:// ����
		pPetDate->DmgAddOfMagic.d1 += add * PointMag * 2 / 5;
		break;
	case 104:// ����
		break;
	case 106:// ��ɽ����
		pPetDate->DmgAddOfMagic.d2 += add * PointMag;
		{
			int mana = lv * (2500 + 1640) * (120 + 100) / 75000;
			mana += PointBody * 3 + PointMag * 7 + PointStr * 4 + PointDex * 2;
			mana /= 10;
			pPetDate->DmgAddOfMagic.d1 -= mana;
		}
		break;
	case 107:// ǧ��һŭ
		break;
	case 108:// ����
		break;
	case 109:// ����˶
		break;
	}
}

void sPropertyData::Reset(bool relv, bool repoint, bool reXL)
{
	if (relv)
	{
		m_Lv = 0;
		repoint = true;
	}
	if (reXL)
	{
		m_XiuLian.Reset();
	}


	PointStr2 = 0;
	PointDex2 = 0;
	PointMag2 = 0;
	PointBody2 = 0;
	PointAgi2 = 0;


	if (repoint)
	{
		PointStr = cct::MinPoint + m_Lv;
		PointDex = cct::MinPoint + m_Lv;
		PointMag = cct::MinPoint + m_Lv;
		PointBody = cct::MinPoint + m_Lv;
		PointAgi = cct::MinPoint + m_Lv;
		PointRemain = m_Lv * 5;
	}


	HPMax.Reset();
	MPMax.Reset();
	Atk.Reset();   //�˺�
	Hit.Reset();   //����
	Def.Reset();   //����
	Mana.Reset();  //����
	Speed.Reset(); //�ٶ�
	Evade.Reset(); //����

	LiveHp = 0; //����
	LiveMp = 0; //ڤ˼
	LiveCp = 0; //��ŭ
	LiveRestoreRate = 0; //״̬�ָ���
	LiveRelifeRate = 0;

	MpSavePercent = 0; //�۸�	
	CpSavePercent = 0; //��ŭ	

	MagicWavePercent = 0;  //��������

	BuffedTiemsAdd = 0; //�����
	TargetNumAdd = 0;//�������ö�������

	ComboNumDown = 1;//��������
	ComboNumUp = 2; //��������
//	ShiXueAdd = 0; //�����˺�����

	Cp1 = 0;
	StartMagic = -1;//��������
	EndMagic = -1;

	RelifeRate.Reset();//���
	//������ºͽ�ħ����Ч��
	RelifePercent.Reset();
	ParryRate.Reset();
	ParryRateOfMaigc.Reset();

	CriRate.Reset(); //����
	CriRate.d1 = 5;
	CriRateOfMagic.Reset(); //����
	CriRateOfMagic.d1 = 3;
	CriRateOfCure.Reset(); //����
	CriDmgPercent.Reset(); //��ɱ�˺�����

	ComboRate.Reset();  //������
	ComboRateOfMagic.Reset(); //������

	Pierce�̴�.Reset();//���ӷ�����
	Pierce�̴�OfMagic.Reset(); //����������

	HitRate.Reset();  //����
	HitRateOfMagic.Reset();//����
	HitRateOfSeal.Reset();//��ӡ
	HitRateOfPoison.Reset(); //��
			//�˺��ӳ�  �����ӳ�
	DmgPercentOfFix.Reset();//�̶�
	DmgPercentOfMagic.Reset();//����
	DmgPercent.Reset();//����
	DmgPercentOfArm.Reset(); //����
	DmgPercentOfPoison.Reset(); //��
	DmgPercentOfCure.Reset();//����
	//�˺�����
	DmgAdd.Reset();//�����˺��������
	DmgAddOfMagic.Reset();//�˺��������
	DmgAddOfCure.Reset();//����Ч������
	// ����
	CounterRate.Reset();
	CounterPercent.Reset();
	// ��Ѫ��
	SuckBloodRate.Reset();
	SuckBloodPercent.Reset();
	//����
	StabRate.Reset();
	StabRateOfMagic.Reset();    //���������˺�
	StabPercent.Reset();
	StabPercentOfMagic.Reset(); //����������

	Spurting.Reset();//����;

	//���������˺�, 0-100
	MagicFire.Reset(); //��
	MagicSoil.Reset(); //��
	MagicWater.Reset();  //ˮ
	MagicThunder.Reset();//��

	Hide.Reset();
	Ghost.Reset();
}