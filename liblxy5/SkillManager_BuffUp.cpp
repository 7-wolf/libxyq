#include "_global.h"


bool cSkillManager::SetDateBuffUp(int userID, int targetID, int stateid, sBuff& buf, int skilllv)
{
	if (g_StateType != STATE_FIGHT)return true;
	if (buf.remainingTimes < 1)buf.remainingTimes = 1;
	int MagicPos = 0;
	ulong MagicID = 0; //BUFF ��ID �Ѿ�û����
	bool MagicUpOrDown = false; //����BUFF ��������ʾ����ʾ
	//	int  magicType = 1; //Ĭ�Ϸ������� ��ӡ
	cObj* pTarget = m_pFightState->m_pFightWorkList[targetID]->m_pObj;
	cPropertyData* pTargetData;
	pTarget->GetPropertyData(pTargetData);
	sFightData& TargetFightP = pTargetData->m_FightData;
	//eBuffType EffectType = eBuffType��ӡ;


	cObj* pUser = m_pFightState->m_pFightWorkList[userID]->m_pObj;
	cPropertyData* pUsetData;
	pUser->GetPropertyData(pUsetData);

	for (list<sBuff>::iterator it = pTarget->m_StateList.begin(); it != pTarget->m_StateList.end(); it++)
	{
		if (it->ID == stateid)
		{
			it->remainingTimes = buf.remainingTimes;
			if (it->damage < buf.damage)
			{
				it->damage = buf.damage;
			}
			if (it->damage2 < buf.damage2)
			{
				it->damage2 = buf.damage2;
			}
			return true;
		}
	}

	switch (stateid)
	{
	case 0: //��ɨǧ��
	case 7: //�Ƹ�����
		MagicID = 0xD9463A0C;
//		TargetFightP.cannotAll += 1;
		TargetFightP.cannotAttack += 1;
		TargetFightP.cannotMagic += 1;
		TargetFightP.cannotSpesialSkill += 1;
		TargetFightP.cannotUseItem += 1;
		MagicPos = -10;
		MagicUpOrDown = true;
		break;
	case 1://������ ...down...
		MagicID = 0x2A2A0663;
		pTargetData->Speed.AddDataAdd(0xFFFF);
//		pTargetData->m_Pierce.d1 += 30;
		pTargetData->CriRate.d1 += 20;
//		pTargetData->m_DamagePercent.d1 += 50;
		pTargetData->Def.AddDataAdd(buf.damage = skilllv * 3);
		pTargetData->Mana.AddDataAdd(buf.damage2 = skilllv * 2);
		MagicPos = -10;
		break;
	case 4://ɱ����
//		MagicUpOrDown = true;
		MagicID = 0x62EDD1CB;
		pTargetData->Hit.AddDataAdd(buf.damage2 = skilllv * 5);
		pTargetData->Atk.AddDataAdd(buf.damage = skilllv);
		MagicPos = -10;
		break;
	case 6://�����
		pTarget->SetShakeFor����(true);
		TargetFightP.chaos���ҷ��� += 1;
		TargetFightP.cannotMagic += 1;
		TargetFightP.cannotSpesialSkill += 1;
		TargetFightP.cannotUseItem += 1;
		break;
	case 8://�����
		MagicPos = 10;
		MagicUpOrDown = true;
//		MagicID = 3860707508;
//		pTargetData->DmgPercentOfMagic.d2 += 30;
		pTargetData->Mana.AddDataAdd(buf.damage = skilllv);
		break;
	case 14://����
		MagicPos = -10;
		TargetFightP.cannotAll += 1;
		TargetFightP.cannotAttack += 1;
		TargetFightP.cannotMagic += 1;
		TargetFightP.cannotSpesialSkill += 1;
		TargetFightP.cannotUseItem += 1;
		MagicID = 3398426285;
		break;
	case 15://ʧ�� ...down...
		MagicPos = -10;
		TargetFightP.cannotMagic += 1;
		pTargetData->Def.AddDataAddPercent(-(buf.damage = 15));
		pTargetData->Mana.AddDataAddPercent(-(buf.damage2 = 15));
		pTargetData->Evade.AddDataAddPercent(-25);
		MagicID = 3635978625;
		break;
// 	case 16://����
// 		MagicPos = -10;
// 		TargetFightP.cannotMagic += 1;
// 		TargetFightP.cannotAttack += 1;
// //		pTargetData->m_Wakan.AddDataAddPercent(-20);
// 		pTarget->SetShakeFor����(true);
// //		MagicID = 0x8B43833D;
// 		break;
	case 17://ʧ��
		MagicPos = -10;
// 		TargetFightP.cannotAttack += 1;
// 		TargetFightP.cannotMagic += 1;
		TargetFightP.cannotSpesialSkill += 1;
		MagicID = 3946646209;
		break;
// 	case 18://׷��
// 		MagicPos = -10;
// 		TargetFightP.cannotAttack += 1;
// 		pTargetData->Def.AddDataAddPercent(-20);
// 		MagicID = 3655438388;
// 		break;
// 	case 19://���
// 		MagicPos = -10;
// 		TargetFightP.cannotMagic += 1;
// 		MagicID = 1214058823;
// 		break;
// 	case 20://ʧ��   
// 		MagicPos = -10;
// 		TargetFightP.cannotMagic += 1;
// 		MagicID = 2336457533;
// 		break;
	case 21://����
		MagicPos = -10;
//		TargetFightP.cannotAll += 1;
		pTargetData->Def.AddDataAddPercent(-(buf.damage = 15));
		pTargetData->Mana.AddDataAddPercent(-(buf.damage2 = 15));
		TargetFightP.cannotAttack += 1;
// 		TargetFightP.cannotMagic += 1;
// 		TargetFightP.cannotSkill += 1;
		MagicID = 2461182746;
		break;
	case 26: // ������
		pTarget->SetShadow(30);
		pTargetData->HitRateOfMagic.d2 += buf.damage = skilllv / 5;
		break;
	case 27: //��׷�
		pTargetData->Def.AddDataAddPercent(-(buf.damage = 15));
		pTargetData->Mana.AddDataAddPercent(-(buf.damage2 = 15));
		MagicID = 0x5525C5FB;
		MagicUpOrDown = true;
		MagicPos = 10;
		break;
	case 33://��ջ���
		pTarget->SetTwinkle(true);
		pTargetData->Atk.AddDataAdd(buf.damage = skilllv * 3 / 2);
		break;
	case 34: //Τ�ӻ���  
		pTargetData->Hit.AddDataAdd(buf.damage = skilllv * 3);
		pTargetData->Atk.AddDataAdd(buf.damage2 = skilllv);
		MagicID = 0xF184BD59;
		MagicPos = -10;
//		MagicUpOrDown = true;
		break;
	case 35:  //��ջ���
		pTargetData->Def.AddDataAdd(buf.damage = skilllv * 3 / 2);
		MagicID = 916220457;
		MagicUpOrDown = true;
		break;
	case 36://һέ�ɽ�
		MagicID = 382287583;
//		MagicPos = -10;
		MagicUpOrDown = true;
		pTargetData->Speed.AddDataAddPercent(buf.damage = skilllv / 3);
		break;
	case 46:    //���ޱ�
		pTargetData->ComboRateOfMagic.d1 += (buf.damage = 15 + skilllv / 10);
		MagicID = 3930943562;
		MagicPos = -10;
		MagicUpOrDown = true;
		break;
	case 49:    //��������
		MagicID = 0x72AD6DBA;
		MagicPos = -10;
		MagicUpOrDown = true;
// 		pTargetData->m_HitRate.d2 += 100;
// 		pTargetData->m_MagicHitRate.d2 += 100;
// 		pTargetData->m_SealRate.d2 += 100;
// 		pTargetData->poisonRate.d2 += 100;
		TargetFightP.cannotMagic += 1;
		pTargetData->Hide.d1 += 1;
		break;
	case 50: //���컨���ж�
		MagicID = 0xDBCEE32C;
		MagicPos = -10;
		MagicUpOrDown = 1;
		break;
	case 54://��������
		TargetFightP.cannotAttack += 1;
		TargetFightP.cannotMagic += 1;
		MagicID = 0x59D77EF9;
		MagicPos = -10;
		break;
// 	case 59://һЦ���
// 		TargetFightP.cannotMagic += 1;
// 		MagicID = 3635978625;// 0x1E1AF8D9;
// 		MagicPos = -10;
// 		break;
	case 62://������
		pTargetData->Mana.AddDataAdd(buf.damage = skilllv);
		pTargetData->HitRateOfMagic.d2 += (buf.damage2 = 15);
//		MagicID = 0;
		MagicPos = 10;
		MagicUpOrDown = true;
		break;
	case 67:	//����
//		pTargetData->m_ATK.AddDataAddPercent(-30);
		TargetFightP.cannotSpesialSkill += 1;
		MagicID = 0x98753F94;
		MagicPos = -10;
		break;
	case 68:	//����
		pTargetData->Hit.AddDataAddPercent(-(buf.damage = 20));
		TargetFightP.cannotMagic += 1;
		MagicID = 0x2F78C46E;
		MagicUpOrDown = true;
		MagicPos = -10;
		break;
	case 69:	//�������
		TargetFightP.cannotAttack += 1;
		MagicID = 0xC48ABA7B;
		MagicPos = -10;
		break;
	case 81:// ����
		pTarget->SetTwinkle(true);
		pTargetData->Atk.SetDataAdd(buf.damage = skilllv * 3 / 2);
		break;
	case 87:// ������β
		pTargetData->DmgPercent.d2 += buf.damage = 20;
// 		MagicID = 0xC48ABA7B;
 		MagicPos = -10;
		MagicUpOrDown = true;
		break;
	case 89:  //����Ǭ��
		TargetFightP.cannotAttack += 1;
		TargetFightP.cannotMagic += 1;
		TargetFightP.cannotSpesialSkill += 1;
		MagicID = 0x313BCC79;
		MagicUpOrDown = 1;
		MagicPos = -10;
		break;
	case 90:   //��������
		MagicID = 0x719D767F;
		MagicUpOrDown = 1;
		MagicPos = 10;
		//		buf.damage = skilllv;
		pTargetData->m_FightData.m_TurnMPAdd += buf.damage;
//		AddMp(targetID, buf.damage);
		break;
	case 91: //����֮Ȫ
		MagicID = 0xF8EE853A;
		MagicUpOrDown = 1;
		MagicPos = 10;
//		buf.damage = skilllv * 2 + 120;
		pTargetData->m_FightData.m_TurnHPAdd += buf.damage;
//		AddHp(targetID, buf.damage);
		buf.damage2 = buf.damage;
		break;
	case 104:
	case 102: //�ն�����
		MagicID = 0xD8857128;
		MagicUpOrDown = 1;
		MagicPos = 10;
		buf.damage = skilllv * 4 + 50;
		buf.damage2 = buf.damage;
		pTargetData->m_FightData.m_TurnHPAdd += buf.damage;
		pTargetData->m_FightData.m_TurnHPHurtAdd += buf.damage2;
		break;
	case 103:// ������
		MagicID = 0xEFE73EB9;
		MagicUpOrDown = 1;
		MagicPos = 10;
		pTargetData->m_FightData.m_TurnHPHurtAdd -= buf.damage = skilllv * 2;
		pTargetData->m_FightData.m_TurnHPAdd -= buf.damage;
		break;
	case 112:// �鶯����
		MagicID = 0x95FF4460;
		MagicUpOrDown = 1;
		MagicPos = 0;
		pTargetData->Mana.AddDataAdd(buf.damage = skilllv);
		break;
	case 113:// �ߵ�����
// 		MagicID = 0x4DDF5690;
// 		MagicUpOrDown = true;
 		MagicPos = -10;
// 		pTargetData->m_Wakan.AddDataAdd(buf.damage = skilllv);
// 		pTargetData->m_ATK.AddDataAdd(buf.damage);
// 		pTargetData->m_DEF.AddDataAdd(buf.damage);
// 		pTargetData->m_SPD.AddDataAdd(buf.damage);
// 		pTargetData->m_HIT.AddDataAdd(buf.damage);
		buf.damage = skilllv / 6 + 5;
		pTargetData->MagicThunder.d2 += buf.damage;
		pTargetData->MagicSoil.d2 += buf.damage; //��
		pTargetData->MagicFire.d2 += buf.damage; //��
		pTargetData->MagicWater.d2 += buf.damage; //ˮ
		pTargetData->HitRateOfMagic.d2 += buf.damage / 2;
		break;
	case 120://��ڤ����
		MagicID = 0x21435203;
// 		pTargetData->m_HitRate.d1 += 100;
		pTargetData->HitRateOfSeal.d2 += (buf.damage = 20);
// 		pTargetData->poisonRate.d1 += 30;
		pTargetData->Hide.d2 += (buf.damage2 = 0xFF);
		MagicUpOrDown = 1;
		MagicPos = 0;
		break;
	case 122:// ʬ����
		MagicID = 0x839CC29A;
		MagicUpOrDown = 1;
		MagicPos = -10;
		break;
	case 123://��������
	{
		pTarget->SetShadow(50);
		pTargetData->Hide.d1 += 1;
//		pTargetData->m_HitRate.d1 += 10;
// 		pTargetData->m_HitRate.d2 += 100;
// 		pTargetData->m_MagicHitRate.d2 += 100;
// 		pTargetData->m_SealRate.d2 += 100;
// 		pTargetData->poisonRate.d2 += 100;
		TargetFightP.cannotMagic += 1;
	}
		break;
	case 125: //������
		pTargetData->Atk.AddDataAdd(buf.damage = skilllv * 3 / 2);
		break;
	case 126:// ��Ȫ֮Ϣ
		MagicID = 0x5ECEBEDD;
		pTargetData->Speed.AddDataAddPercent(-(buf.damage = skilllv / 10));
		MagicUpOrDown = 1;
		MagicPos = -10;
		break;
	case 129:// ������
		MagicID = 0x5C0073EE;
		MagicUpOrDown = 1;
//		MagicPos = 1;
		pTargetData->m_FightData.cannotLive += 1;
		break;
	case 133://ţ��
		MagicID = 0x62EDD1CB;
		MagicUpOrDown = 1;
		pTargetData->Mana.AddDataAdd(buf.damage = skilllv);
//		pTargetData->m_MagicHitRate.d1 += 100;
		pTargetData->Hide.d2 += (buf.damage2 = 0xFF);
		break;
	case 137: //ħ������
		pTargetData->CounterRate.d1 += (buf.damage = 100);
		MagicUpOrDown = 1;
		break;
	case 141://����
		TargetFightP.cannotAll += 1;
		TargetFightP.cannotAttack += 1;
		TargetFightP.cannotMagic += 1;
		TargetFightP.cannotSpesialSkill += 1;
		TargetFightP.cannotUseItem += 1;
		MagicID = 0x3646A4D9;
		MagicPos = -10;
		break;
	case 142://ӥ��
	case 148://������
//		TargetFightP.cannotMagic += 1;
		TargetFightP.cannotAttack += 1;
		TargetFightP.cannotMagic += 1;
		TargetFightP.cannotSpesialSkill += 1;
		TargetFightP.cannotUseItem += 1;
		MagicID = 0x58628406;
		MagicPos = -10;
		MagicUpOrDown = true;
		break;
	case 144:// ����
		MagicID = 0x20FCCE94;
		MagicPos = -10;
		TargetFightP.cannotAttack += 1;
		TargetFightP.cannotMagic += 1;
		TargetFightP.cannotSpesialSkill += 1;
		TargetFightP.cannotUseItem += 1;
// 		pTargetData->Atk.AddDataAddPercent(-20);
// 		pTargetData->Def.AddDataAddPercent(-10);
// 		pTargetData->Mana.AddDataAddPercent(-10);
		MagicUpOrDown = true;
		break;
	case 145:// ����
		MagicID = 0x85C9AF08;
		pTargetData->Atk.AddDataAdd(buf.damage = skilllv);
		MagicUpOrDown = 1;
		break;
	case 147://������
		MagicID = 755485932;
		pTargetData->Mana.AddDataAdd(buf.damage = skilllv);
		MagicUpOrDown = 1;
		break;
	case 150://���ȷ��
		MagicID = 0xBBEA83F4;
		pTargetData->CounterRate.d1 += (buf.damage = 100);
		MagicUpOrDown = 1;
		break;
// 	case 152://��ħ����
// 		MagicID = 0x3D3FA597;
// 		pTargetData->HPMax.AddDataAddPercent(30);
// 		{
// 			int dam = AddHp(targetID, 5, 10000);
// 			SetDamage(-dam, targetID);
// 		}
// 		MagicUpOrDown = 1;
// 		break;
	case 156://ħ�����
		MagicID = 0xAF07277F;
		MagicPos = -10;
		TargetFightP.cannotAddHP += 1;
		break;
	case 159://��������
		TargetFightP.cannotAttack += 1;
		TargetFightP.cannotMagic += 1;
		MagicID = 0x8103AFD2;//0xC4AA8E18;
		MagicPos = -10;
		break;
	case 160:// ��˿��
		buf.damage = skilllv * 3 / 2;
		pTargetData->Def.AddDataAdd(buf.damage);
		MagicID = 0x369C6A29;
		MagicUpOrDown = true;
		break;
	case 162:  //���޵���
		MagicPos = -10;
		MagicID = 0x8F3E73D5;
		TargetFightP.cannotAttack += 1;
		break;
	case 166://�þ���
		MagicID = 0x0B788E5A;
		MagicUpOrDown = true;
		MagicPos = 0;
		pTargetData->StabRateOfMagic.d1 += (buf.damage = 50);    //���������˺�
		pTargetData->StabPercentOfMagic.d1 += (buf.damage2 = 50); //����������
		break;
	case 175: // ������ɽ
		pTargetData->DmgAdd.d2 += buf.damage = skilllv * 3 / 2;
		pTargetData->DmgAddOfMagic.d2 += buf.damage2 = skilllv;
		break;
	case 176: // ���Ǿ�
		pTargetData->DmgAdd.d1 += buf.damage = skilllv * 3 / 2;
		pTargetData->m_FightData.zhanyi += 1;
		MagicPos = 10;
		MagicUpOrDown = true;
		break;
	case 177: // ����
		pTargetData->CriRate.d1 += buf.damage = skilllv / 20;
		MagicPos = 10;
		MagicUpOrDown = true;
		break;
	case 181: // ����
		pTargetData->SuckBloodPercent.d1 += buf.damage = skilllv / 10;
		pTargetData->SuckBloodRate.d1 += buf.damage2 = 100;
		MagicPos = 10;
		MagicUpOrDown = true;
		break;
	case 182: // ������
		TargetFightP.cannotMagic += 1;
		MagicPos = -10;
		break;
	case 185: // ������
		pTargetData->Speed.AddDataAdd(-(buf.damage = skilllv / 2));
		MagicPos = -10;
		MagicUpOrDown = true;
		break;
	case 187: // ���ⱦ��
		pTargetData->DmgAdd.d2 += buf.damage = skilllv * 3 / 2;
		MagicPos = 10;
		MagicUpOrDown = true;
		break;
	case 188: // ��������
		pTargetData->DmgAddOfMagic.d2 += buf.damage2 = skilllv;
//		MagicPos = -10;
		MagicUpOrDown = true;
		break;
	case 198: // ��ɱ
		MagicPos = 10;
		MagicUpOrDown = true;
//		buf.damage = 100;
		break;
	case 199: // Ѫ����Ϣ(������)
//		TargetFightP.cannotMagic += 1;
		MagicPos = -10;
		break;
	case 201: // �׻� 
		TargetFightP.yanhu += 1;
		MagicPos = 10;
		MagicUpOrDown = true;
		break;
	case 204: // ����
		pTargetData->DmgAddOfMagic.d2 += buf.damage2 = skilllv;
		MagicPos = 10;
		MagicUpOrDown = true;
		break;

	case 1002: //1�غϵĸ� BUFF
		pTargetData->ParryRate.d1 += buf.damage = 0xFFFF;
		break;
// 	case 1004://����
// 		break;
// 	case 2092://����һ��
// 		//		pTargetData->m_ATK.AddDataAddPercent(-20);
// 		break;
	case 2093://ҹ�����
		buf.damage = 5;
		pTargetData->Atk.AddDataAddPercent(-buf.damage);   //�˺�
		pTargetData->Hit.AddDataAddPercent(-buf.damage);   //����
		pTargetData->Def.AddDataAddPercent(-buf.damage);   //����
		pTargetData->Mana.AddDataAddPercent(-buf.damage); //����
		pTargetData->Speed.AddDataAddPercent(-buf.damage);   //�ٶ�
		pTargetData->Evade.AddDataAddPercent(-buf.damage); //����
		break;
	case 2094://�����ٻ�
		MagicID = 0x19182964;
		MagicPos = -10;
		pTargetData->m_FightData.cannotLive += 1;
		break;
	case 2095: // ����
		pTargetData->Hit.AddDataAddPercent(buf.damage = 200);   //����
		break;
	case 2096: // ��������
		pTargetData->Speed.AddDataAddPercent(buf.damage = 10);
		break;
	case 2097:// ��������
		MagicID = 0xDEDEE983;
		MagicUpOrDown = true;
		pTargetData->DmgPercentOfMagic.d2 += buf.damage = 60;
		break;
	case 2101:// ��η��ʩ
//		MagicID = 0xDEDEE983;
		MagicUpOrDown = true;
		pTargetData->DmgAdd.d2 += buf.damage = pUsetData->Def / 5;
		pTargetData->DmgAddOfMagic.d2 += buf.damage2 = pUsetData->Mana / 4;
		break;
	case 1998:// ��η��ʩ2
		MagicPos = 10;
		MagicUpOrDown = true;
		pTargetData->Def.AddDataAddPercent(-(buf.damage = 20));
		pTargetData->Mana.AddDataAddPercent(-(buf.damage2 = 25));
		break;
// 	case 3018://Ұ��֮��
// 		pTargetData->DmgPercent.d1 += 10;
// 		break;
// 	case 3019:
// 		pTargetData->DmgPercent.d1 += 5;
// 		break;
// 	case 3020://���֮��
// 		pTargetData->Def.AddDataAddPercent(10);
// 		break;
// 	case 3021:
// 		pTargetData->Def.AddDataAddPercent(5);
// 		break;
// 	case 3022: // ���ƾ�
// 		pTargetData->Speed.AddDataAddPercent(10);
// 		break;
// 	case 3023:
// 		pTargetData->Speed.AddDataAddPercent(5);
// 		break;
	case 3024://̫������ 
	case 3025://�޺�
		MagicPos = -10;
		MagicID = 0xAF07277F;// 0x5CC81980;
		pTargetData->DmgPercentOfMagic.d2 += buf.damage = 50;
		break;
	case 3026://������
		MagicPos = 10;
		MagicUpOrDown = true;
		pTargetData->StabRateOfMagic.d1 += buf.damage = 100;
		pTargetData->StabPercentOfMagic.d1 += buf.damage2 = 50;
		pTargetData->StabRate.d1 += buf.damage;
		pTargetData->StabPercent.d1 += buf.damage2;
		break;
	case 3027://�����޷�
		MagicPos = 10;
		MagicUpOrDown = true;
		pTargetData->HitRateOfMagic.d2 += buf.damage = 50;
		break;
// 	case 3028:// ��������
// 		pTargetData->DmgPercent.d1 -= 10;
// 		break;
// 	case 3029:
// 		pTargetData->DmgPercent.d1 -= 5;
// 		break;
// 	case 3030://�Ƽ���
// 		pTargetData->Def.AddDataAddPercent(-10);
// 		break;
// 	case 3031:
// 		pTargetData->Def.AddDataAddPercent(-5);
// 		break;
// 	case 3032: // ������
// 		pTargetData->Speed.AddDataAddPercent(-10);
// 		break;
// 	case 3033:
// 		pTargetData->Speed.AddDataAddPercent(-5);
// 		break;

	case 3047://��������
		MagicPos = 10;
		MagicUpOrDown = true;
		pTargetData->DmgPercentOfMagic.d2 += buf.damage = 50;//���������ӳ�
		pTargetData->DmgPercent.d2 += buf.damage;//��������ӳ�
		pTargetData->HitRateOfPoison.d2 += buf.damage2 = 0xFF;
		pTargetData->HitRateOfSeal.d2 += buf.damage2;
//		pTarget->ReMoveState(eBuffType����);
		break;
	default:
		ERRBOX2(stateid);
		return true;
	}
	sSkill* pskill = g_pMainState->m_SkillManager.GetSkill(stateid);
	if (pskill)
	{
		buf.EffectType = (eBuffType)pskill->m_EffectType;
		buf.MagicID = pskill->m_State;
		if (stateid == 35)
		{
			if (targetID < 10)
			{
				buf.MagicID = 0x592EBD89;
				MagicUpOrDown = false;
			}
			else
			{
				buf.MagicID = 0x2F45B9F0;
				MagicUpOrDown = true;
			}
			MagicPos = -10;
		}
	}
	else
	{
		buf.EffectType = eBuffType����;
		if (stateid == 1998)
		{
			buf.MagicID = 0x5525C5FB;
		}
		else
		{
			buf.MagicID = 0;
		}
	}
	buf.skilllv = skilllv;
	buf.userID = userID;
	buf.targetID = targetID;
//	buf.MagicID = MagicID;
	buf.bufPos = MagicPos;
	buf.bBuffup = MagicUpOrDown;
	buf.ID = stateid; //����BUFF  ID
	m_pFightState->AddState(targetID, buf);
	return true;
}
