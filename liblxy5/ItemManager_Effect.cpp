#include "_global.h"

// 
// void ItemManager::SetFabaoEffect(cPcData& data, int leveup, eFaBao ID)
// {
// 	int add = leveup;
// 	switch (ID)
// 	{
// 	case eFaBao0������:
// 		data.DmgPercentOfPoison.d1 += 20 * add;
// 		break;
// 	case eFaBao1�ɽ�Īа:
// 		data.DmgAdd.d1 += 200 * add;
// 		break;
// 	case eFaBao2�޺���:
// 		data.MpSavePercent += 25 * add;
// 		break;
// 	case eFaBao3����:
// 		data.LiveMp += 30 * add;
// 		break;
// 	case eFaBao4����:
// 		break;
// 	case eFaBao5������:
// 		data.ghostSpecial.d1 += 20 * add;
// 		break;
// 	case eFaBao6��Ԫɡ:
// 		data.StabRateOfMagic.d1 += 100 * add;    //���������˺�
// 		data.StabPercentOfMagic.d1 += 5 * add; //����������
// 		break;
// 	case eFaBao7�޻����:
// 		data.Spurting.d1 += 15 * add;
// //		data.m_DamageAdd.d2 += 100 * add;
// 		break;
// 	case eFaBao8Ǭ��������:
// 		data.LiveCp += 7 * add;
// 		break;
// 	case eFaBao9�ն�:
// 		data.MagicFire.d1 += 10 * add;
// 		data.MagicWater.d1 += 10 * add;
// 		data.MagicSoil.d1 += 10 * add;
// 		data.MagicThunder.d1 += 10 * add;
// //		data.m_MagicNumAdd += add;
// 		break;
// 	case eFaBao10���س�:
// 		g_pMainState->m_GlobalButton[13] += 50 * add;
// 		break;
// 	case eFaBao11�¹ⱦ��:
// 		break;
// 	case eFaBao12��ɫ������:
// 		break;
// 	case eFaBao13��ɫ������:
// 		break;
// 	case eFaBao14��ɫ������:
// 		break;
// 	case eFaBao15��ɫ������:
// 		break;
// 	case eFaBao15��ɫ������:
// 		break;
// 	case eFaBao16����:
// 		break;
// 	case eFaBao17�ܽ����ְ�:
// //		data.m_Popularity += 100 * add;
// 		data.Speed.AddDataAdd(50 * add);
// 		break;
// 	case eFaBao18ʱ֮��:
// //		data.m_SPD.AddDataAdd(1000 * add);
// 		data.RelifeRate.d1 += 10 * add;
// 		break;
// 	case eFaBao19ͨ�鱦��:
// 		g_pMainState->m_GlobalButton[14] += 20 * add;
// 		break;
// 	case eFaBao20�۱���:
// 		g_pMainState->m_GlobalButton[15] += 20 * add;
// 		break;
// 	case eFaBao21�����«:
// 		data.DmgPercentOfCure.d1 += 20 * add;
// 		break;
// 	case eFaBao22��ľ����:
// 		data.DmgPercentOfCure.d2 += 20 * add;
// 		break;
// 	case eFaBao23���뾵:
// 		data.StabRate.d1 += 100 * add;
// 		data.StabPercent.d1 += 5 * add;
// 		break;
// 	case eFaBao24��Ѫ�:
// 		data.ComboNumUp += add;
// 		data.ComboRate.d1 += 30 * add;
// 		break;
// 	case eFaBao25�������:
// 		data.ParryRate.d1 += 20 * add;
// 		break;
// 	case eFaBao26��ħ����:
// 		data.ParryRateOfMaigc.d1 += 20 * add;
// 		break;
// 	case eFaBao27����:
// 		data.DmgPercentOfCure.d1 = add;
// 		break;
// 	case eFaBao28������ë:
// //		data.GoldLivePercent.d1 += 5 * add;
// 		data.LiveRelifeRate += 5 * add;
// 		break;
// 	case eFaBao29����:
// 		data.Pierce�̴�OfMagic.d1 += 5 * add;
// 		break;
// 	case eFaBao30�������ӡ:
// 		data.CriRateOfMagic.d1 += 5 * add;
// 		break;
// 	case eFaBao31����:
// 		data.m_AtkDownMP.d1 += 1 * add;
// 		break;
// 	case eFaBao32�ȱ�:
// 		data.CriRateOfCure.d1 += 20 * add;
// 		break;
// 	case eFaBao33�ε�:
// //		data.m_Spurting.d2 += 15 * add;
// //		data.nightLv += 10 * add;
// 		break;
// 	default:
// 		ERRBOX;
// 		break;
// 	}
// }
// 
// 



void ItemManager::SetUpQiangHua(vector<int>& prop,int protype, int num, bool isBB)
{ //
	if (num < 0)
	{
		if (prop[10] == protype)
		{
			prop[10] = prop[11] = -1;
			return;
		}

		for (int i = 2; i < 10; i += 2)
		{
			if (prop[i] == protype)
			{
				prop[i + 1] += num;
				return;
			}
		}
		return;
	}

	if (!isBB)
	{
		for (int i = 2; i < 10; i += 2)
		{
			if (prop[i] == protype)
			{
				prop[i + 1] += num;
				return;
			}
		}
	}
	prop[10] = protype;
	prop[11] = num;
	return;

	int i = 0;
	int startpos = 5;
	for (; i < prop[startpos]; i++)
	{
		if (protype == prop[startpos + 1 + i * 2])
		{
			prop[startpos + 2 + i * 2] += num;
			break;
		}
	}
	if (i == prop[startpos])
	{
		prop.push_back(protype);
		prop.push_back(num);
		prop[startpos] += 1;
	}

}



static vector<int> s_stone_pros = { eProPerty��Ѫ, eProPerty�ٶ�, eProPerty����, eProPerty��, eProPerty�׿�, eProPertyˮ��, eProPerty����,
eProPerty����, eProPerty���, eProPerty�˺�, eProPerty����, eProPerty�ٶ�, eProPerty����, eProPerty����, eProPerty���, eProPerty�˺�, eProPerty��Ѫ };
static vector<int> s_stoneValues = { 40, 8, 25, 2, 2, 2, 2, 6, 40, 8, 12, 6, 4, 8, 30, 10, 30 };
void ItemManager::SetUpBaoShi(vector<int>& pro, int baoshiid, int lv, bool isBB)
{
	SetUpQiangHua(pro, s_stone_pros[baoshiid], s_stoneValues[baoshiid] * lv, isBB);
	return;
	switch (baoshiid)
	{
	case 0:SetUpQiangHua(pro, eProPerty��Ѫ, 40 * lv, isBB); return;
	case 1:SetUpQiangHua(pro, eProPerty�ٶ�, 8 * lv, isBB); return;
	case 2:
		SetUpQiangHua(pro, eProPerty����, 25 * lv, isBB);
//		SetUpQiangHua(pro, eProPerty�˺�, 7 * m_bSetup);
		return;
	case 3:SetUpQiangHua(pro, eProPerty��, 2 * lv, isBB); return;
	case 4:SetUpQiangHua(pro, eProPerty�׿�, 2 * lv, isBB); return;
	case 5:SetUpQiangHua(pro, eProPertyˮ��, 2 * lv, isBB); return;
	case 6:SetUpQiangHua(pro, eProPerty����, 2 * lv, isBB); return;
	case 7:SetUpQiangHua(pro, eProPerty����, 6 * lv, isBB); return;
	case 8:SetUpQiangHua(pro, eProPerty���, 40 * lv, isBB); return;
	case 9:SetUpQiangHua(pro, eProPerty�˺�, 8 * lv, isBB); return;
	case 10:SetUpQiangHua(pro, eProPerty����, 12 * lv, isBB); return;
	case 11:SetUpQiangHua(pro, eProPerty�ٶ�, 6 * lv, isBB); return;
	case 12:SetUpQiangHua(pro, eProPerty����, 4 * lv, isBB); return;
	case 13:SetUpQiangHua(pro, eProPerty����, 8 * lv, isBB); return;
	case 14:SetUpQiangHua(pro, eProPerty���, 30 * lv, isBB); return;
	case 15:SetUpQiangHua(pro, eProPerty�˺�, 10 * lv, isBB); return;
	case 16:SetUpQiangHua(pro, eProPerty��Ѫ, 30 * lv, isBB); return;
	}
}


// 
// void ItemManager::AutoFuShi(sItem2* item, int lv, eMengPai mengpaiid)
// {
// 	//	if (lv < 60)return;
// 	//	if (item->m_Property.size() < 5)return;
// 	//	else if (lv > 59)
// 	{
// 		if (item->GetType() < 15)
// 		{
// 			switch (mengpaiid)
// 			{
// 			case eMP_ʨ����:
// 				item->m_Property[2] = 86;
// 				break;
// 			default:
// 				//				item->m_Property[2] = 14;
// 				break;
// 			}
// 		}
// 		else
// 		{
// 			//			item->m_Property[2] = 14;
// 		}
// 
// 	}
// 	// 	if (lv > 89)
// 	// 	{
// 	// 		item->m_Property[3] = 0;
// 	// 	}
// 	// 	if (lv>119)
// 	// 	{
// 	// 		item->m_Property[4] = 16;
// 	// 	}
// }

