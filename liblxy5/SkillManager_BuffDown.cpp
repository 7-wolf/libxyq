#include "_global.h"


bool cSkillManager::SetDateBuffDown(list<sBuff>::iterator& sbuf)//int targetID, int stateid)
{
	int targetID = sbuf->targetID;
	int stateid = sbuf->ID;
	cObj* pTarget = m_pFightState->m_pFightWorkList[targetID]->m_pObj;
	cPropertyData* pTargetData;
	pTarget->GetPropertyData(pTargetData);
	sFightData&  targetProperty = pTargetData->m_FightData;

	auto& TargetFightP = targetProperty;
	const sBuff& buf = *sbuf;

	switch (stateid)
	{
	case 0://��ɨǧ��
	case 7://�Ƹ�����
//		targetProperty.cannotAll -= 1;
		targetProperty.cannotAttack -= 1;
		targetProperty.cannotMagic -= 1;
		targetProperty.cannotSpesialSkill -= 1;
		targetProperty.cannotUseItem -= 1;
		break;
	case 1: //������
		pTargetData->Speed.AddDataAdd(-0xFFFF);
//		pTargetData->m_DamagePercent.d1 -= 50;
//		pTargetData->m_Pierce.d1 -= 30;
		pTargetData->CriRate.d1 -= 20;
		pTargetData->Def.AddDataAdd(-sbuf->damage);
		pTargetData->Mana.AddDataAdd(-sbuf->damage2);
		break;
	case 4:
		pTargetData->Hit.AddDataAdd(-sbuf->damage2);
		pTargetData->Atk.AddDataAdd(-sbuf->damage);
		break;
	case 6:
		pTarget->SetShakeFor����(false);
		targetProperty.chaos���ҷ��� -= 1;
		g_pMainState->m_FightWorkList[targetID/*pTarget->m_IDInFightlist*/].m_WorkType = -1;
		TargetFightP.cannotMagic -= 1;
		TargetFightP.cannotSpesialSkill -= 1;
		TargetFightP.cannotUseItem -= 1;
		break;
	case 8://�����
//		pTargetData->DmgPercentOfMagic.d2 -= 30;
		pTargetData->Mana.AddDataAdd(-sbuf->damage);
		break;
	case 14://���߷�
		targetProperty.cannotAll -= 1;
		targetProperty.cannotAttack -= 1;
		targetProperty.cannotMagic -= 1;
		targetProperty.cannotSpesialSkill -= 1;
		targetProperty.cannotUseItem -= 1;
		break;
	case 15://ʧ��
		targetProperty.cannotMagic -= 1;
		pTargetData->Def.AddDataAddPercent(sbuf->damage);
		pTargetData->Mana.AddDataAddPercent(sbuf->damage2);
		pTargetData->Evade.AddDataAddPercent(25);
		break;
// 	case 16://����
// 		targetProperty.cannotMagic -= 1;
// 		targetProperty.cannotAttack -= 1;
// 		//		pTargetData->m_Wakan.AddDataAddPercent(20);
// 		pTarget->SetShakeFor����(false);
// 		break;
	case 17://ʧ��
		// 		targetProperty.cannotAttack -= 1;
		// 		targetProperty.cannotMagic -= 1;
		targetProperty.cannotSpesialSkill -= 1;
		break;
// 	case 18://׷��
// 		targetProperty.cannotAttack -= 1;
// 		pTargetData->Def.AddDataAddPercent(20);
// 		break;
// 	case 19://���
// 		targetProperty.cannotMagic -= 1;
// 		break;
// 	case 20://ʧ��   
// 		targetProperty.cannotMagic -= 1;
// 		break;
	case 21://���� 
//		targetProperty.cannotAll -= 1;
		
// 		targetProperty.cannotMagic -= 1;
// 		targetProperty.cannotSkill -= 1;
		pTargetData->Def.AddDataAddPercent(sbuf->damage);
		pTargetData->Mana.AddDataAddPercent(sbuf->damage2);
		targetProperty.cannotAttack -= 1;
		break;
	case 26:
		pTarget->SetShadow(false);
		pTargetData->HitRateOfMagic.d2 -= sbuf->damage;
		break;
	case 27: //��׷�
		pTargetData->Def.AddDataAddPercent(sbuf->damage);
		pTargetData->Mana.AddDataAddPercent(sbuf->damage2);
		break;
	case 33://��ջ���
		pTarget->SetTwinkle(false);
		pTargetData->Atk.AddDataAdd(-sbuf->damage);
		break;
	case 34:   //Τ�ӻ���  
		pTargetData->Hit.AddDataAdd(-sbuf->damage);
		pTargetData->Atk.AddDataAdd(-sbuf->damage2);
		break;
	case 35:  //��ջ���
		pTargetData->Def.AddDataAdd(-sbuf->damage);
		break;
	case 36:  //һέ�ɽ�
		pTargetData->Speed.AddDataAdd(-sbuf->damage);
		break;
	case 46:    //���ޱ�
		pTargetData->ComboRateOfMagic.d1 -= sbuf->damage;
		break;
	case 49:    //��������
		// 		pTargetData->m_HitRate.d2 -= 100;
		// 		pTargetData->m_MagicHitRate.d2 -= 100;
		// 		pTargetData->m_SealRate.d2 -= 100;
		// 		pTargetData->poisonRate.d2 -= 100;
		targetProperty.cannotMagic -= 1;
		pTargetData->Hide.d1 -= 1;
		break;
	case 50: //���컨���ж�

		break;
	case 54://��������
		targetProperty.cannotAttack -= 1;
		targetProperty.cannotMagic -= 1;
		break;
// 	case 59://һЦ���
// 		targetProperty.cannotMagic -= 1;
// 		break;
	case 62://������
		pTargetData->Mana.AddDataAdd(-sbuf->damage);
		pTargetData->HitRateOfMagic.d2 -= (sbuf->damage2);
		break;
	case 67:	//����
//		pTargetData->m_ATK.AddDataAddPercent(30);
		targetProperty.cannotSpesialSkill -= 1;
		break;
	case 68:	//����
		pTargetData->Hit.AddDataAddPercent(sbuf->damage);
		targetProperty.cannotMagic -= 1;
		break;
	case 69:	//�������
		targetProperty.cannotAttack -= 1;
		break;
	case 81:// ����
		pTarget->SetTwinkle(false);
		pTargetData->Atk.SetDataAdd(-sbuf->damage);
		break;
	case 87:// ������β
		pTargetData->DmgPercent.d2 -= buf.damage;
		break;
	case 89:  //����Ǭ��
		targetProperty.cannotAttack -= 1;
		targetProperty.cannotMagic -= 1;
		targetProperty.cannotSpesialSkill -= 1;
		break;
	case 90:   //��������
		pTargetData->m_FightData.m_TurnMPAdd -= sbuf->damage;
		break;
	case 91:    //����֮Ȫ
		pTargetData->m_FightData.m_TurnHPAdd -= sbuf->damage;
		break;
	case 104:
	case 102: //�ն�����
		pTargetData->m_FightData.m_TurnHPAdd -= sbuf->damage;
		pTargetData->m_FightData.m_TurnHPHurtAdd -= sbuf->damage2;
		break;
	case 103://������
		pTargetData->m_FightData.m_TurnHPHurtAdd += sbuf->damage;
		pTargetData->m_FightData.m_TurnHPAdd += sbuf->damage;
		break;
	case 112:// �鶯����
		pTargetData->Mana.AddDataAdd(-sbuf->damage);
		break;
	case 113:// �ߵ����� 
// 		pTargetData->m_Wakan.AddDataAdd(-sbuf->damage);
// 		pTargetData->m_ATK.AddDataAdd(-sbuf->damage);
// 		pTargetData->m_DEF.AddDataAdd(-sbuf->damage);
// 		pTargetData->m_SPD.AddDataAdd(-sbuf->damage);
// 		pTargetData->m_HIT.AddDataAdd(-sbuf->damage);
		pTargetData->MagicThunder.d2 -= sbuf->damage;
		pTargetData->MagicSoil.d2 -= sbuf->damage; //��
		pTargetData->MagicFire.d2 -= sbuf->damage; //��
		pTargetData->MagicWater.d2 -= sbuf->damage; //ˮ
		pTargetData->HitRateOfMagic.d2 -= sbuf->damage / 2;
		break;
	case 120:
// 		pTargetData->m_HitRate.d1 -= 100;
		pTargetData->HitRateOfSeal.d2 -= sbuf->damage;
// 		pTargetData->poisonRate.d1 -= 30;
		pTargetData->Hide.d2 -= sbuf->damage2;
		break;
	case 122:
		break;
	case 123://��������
	{
		pTarget->SetShadow(false);
//		pTargetData->m_HitRate.d1 -= 10;
// 		pTargetData->m_HitRate.d2 -= 100;
// 		pTargetData->m_MagicHitRate.d2 -= 100;
// 		pTargetData->m_SealRate.d2 -= 100;
// 		pTargetData->poisonRate.d2 -= 100;
		targetProperty.cannotMagic -= 1;
		pTargetData->Hide.d1 -= 1;
	}
		break;
	case 125:
		pTargetData->Atk.AddDataAdd(-sbuf->damage);
		break;
	case 126:// ��Ȫ֮Ϣ
		pTargetData->Speed.AddDataAddPercent(sbuf->damage);
		break;
	case 129:// ������
		targetProperty.cannotLive -= 1;
		break;
	case 133://ţ��
		pTargetData->Mana.AddDataAdd(-sbuf->damage);
//		pTargetData->m_MagicHitRate.d1 -= 100;
		pTargetData->Hide.d2 -= sbuf->damage2;
		break;
	case 137://ħ������
		pTargetData->CounterRate.d1 -= sbuf->damage;
		break;
	case 141://����
		targetProperty.cannotAll -= 1;
		targetProperty.cannotAttack -= 1;
		targetProperty.cannotMagic -= 1;
		targetProperty.cannotSpesialSkill -= 1;
		targetProperty.cannotUseItem -= 1;
		break;
	case 142://ӥ��
	case 148://������
		targetProperty.cannotMagic -= 1;
		targetProperty.cannotAttack -= 1;
		targetProperty.cannotSpesialSkill -= 1;
		targetProperty.cannotUseItem -= 1;
		break;
	case 144:// ����
		targetProperty.cannotAttack -= 1;
		targetProperty.cannotMagic -= 1;
		targetProperty.cannotSpesialSkill -= 1;
		targetProperty.cannotUseItem -= 1;
		break;
	case 145:// ����
		pTargetData->Atk.AddDataAdd(-sbuf->damage);
		break;
	case 147://����
		pTargetData->Mana.AddDataAdd(-sbuf->damage);
		break;
	case 150://���ȷ��
		pTargetData->CounterRate.d1 -= sbuf->damage;
		break;
	case 152://��ħ����
// 		pTargetData->HPMax.AddDataAddPercent(-30);
// 		{
// 			int dam = AddHp(targetID, -5, 10000);
// 			SetDamage(-dam, targetID);
// 		}
// 		break;
	case 156://ħ�����
		targetProperty.cannotAddHP -= 1;
		break;
	case 159://��������
		targetProperty.cannotAttack -= 1;
		targetProperty.cannotMagic -= 1;
		break;

	case 160:// ��˿��	
		pTargetData->Def.AddDataAdd(-sbuf->damage);
		break;
//	case 161: break;//����	
	case 162:  //���޵���
		targetProperty.cannotAttack -= 1;
		break;
	case 166://�þ���
		pTargetData->StabRateOfMagic.d1 -= sbuf->damage;    //���������˺�
		pTargetData->StabPercentOfMagic.d1 -= sbuf->damage2; //����������
		break;

	case 175: // ������ɽ
		pTargetData->DmgAdd.d2 -= sbuf->damage;
		pTargetData->DmgAddOfMagic.d2 -= sbuf->damage2;
		break;
	case 176: // ���Ǿ�
		pTargetData->DmgAdd.d1 -= buf.damage;
		pTargetData->m_FightData.zhanyi -= 1;
		break;
	case 177: // ����
		pTargetData->CriRate.d1 -= buf.damage;
		break;
	case 181: // ����
		pTargetData->SuckBloodRate.d1 -= buf.damage;
		pTargetData->SuckBloodPercent.d1 -= buf.damage2;
		break;
	case 182: // ������
		TargetFightP.cannotMagic -= 1;
		break;
	case 185: // ������
		pTargetData->Speed.AddDataAdd(buf.damage);
		break;
	case 187: // ���ⱦ��
		pTargetData->DmgAdd.d2 -= buf.damage;
		break;
	case 188: // ��������
		pTargetData->DmgAddOfMagic.d2 -= buf.damage2;
		break;
	case 198: // ��ɱ
		break;
	case 199: // Ѫ��(������)
//		TargetFightP.cannotMagic -= 1;
		break;
	case 201: // �׻� 
		TargetFightP.yanhu -= 1;
		break;
	case 204: // ����
		pTargetData->DmgAddOfMagic.d2 -= buf.damage2;
		break;

	case 1002:
		pTargetData->ParryRate.d1 -= buf.damage;
		break;
// 	case 1004://����
// 		break;
// 	case 2092://����һ��
// 		//		pTargetData->m_ATK.AddDataAddPercent(20);
// 		break;
	case 2093://ҹ�����
		pTargetData->Atk.AddDataAddPercent(buf.damage);   //�˺�
		pTargetData->Hit.AddDataAddPercent(buf.damage);   //����
		pTargetData->Def.AddDataAddPercent(buf.damage);   //����
		pTargetData->Mana.AddDataAddPercent(buf.damage); //����
		pTargetData->Speed.AddDataAddPercent(buf.damage);   //�ٶ�
		pTargetData->Evade.AddDataAddPercent(buf.damage); //����
		break;
	case 2094://�����ٻ�
		pTargetData->m_FightData.cannotLive -= 1;
		break;
	case 2095: // ����
		pTargetData->Hit.AddDataAddPercent(-buf.damage); //����
		break;
	case 2096: // ��������
		pTargetData->Speed.AddDataAddPercent(-buf.damage);
		break;
	case 2097:// ��������
		pTargetData->DmgPercentOfMagic.d2 -= buf.damage;
		break;
	case 2101:// ��η��ʩ
		pTargetData->DmgAdd.d2 -= buf.damage;
		pTargetData->DmgAddOfMagic.d2 -= buf.damage2;
		break;
	case 1997: // ս��
		break;
	case 1998:// ��η��ʩ2
		pTargetData->Def.AddDataAddPercent(buf.damage);
		pTargetData->Mana.AddDataAddPercent(buf.damage2);
		break;
	case 3024://̫������ �޺�
	case 3025:
		pTargetData->DmgPercentOfMagic.d2 -= buf.damage;
		break;
	case 3026://������
		pTargetData->StabRateOfMagic.d1 -= buf.damage;
		pTargetData->StabPercentOfMagic.d1 -= buf.damage2;
		pTargetData->StabRate.d1 -= buf.damage;
		pTargetData->StabPercent.d1 -= buf.damage2;
		break;
	case 3027://�����޷�
		pTargetData->HitRateOfMagic.d2 -= buf.damage;
		break;
	case 3047://��������
		pTargetData->DmgPercentOfMagic.d2 -= buf.damage;//���������ӳ�
		pTargetData->DmgPercent.d2 -= buf.damage;//��������ӳ�
		pTargetData->HitRateOfPoison.d2 -= buf.damage2;
		pTargetData->HitRateOfSeal.d2 -= buf.damage2;
		break;
	default:
		ERRBOX2(stateid);
		return false;
		break;
	}
	return true;
}
