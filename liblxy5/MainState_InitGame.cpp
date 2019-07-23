#include "_global.h"
#include "_txt.h"


void CMainState::initGame()
{

	LockLv(159);
	if (0)
	{
		vector<int> skills =
		{
			ePS_�߼�����, ePS_�߼���ɱ, ePS_�߼�����, ePS_��Ѫ, ePS_�߼�͵Ϯ, ePS_�߼�ǿ��, ePS_�߼�ҹս, ePS_��Ѫ׷��,
			/*ePS_�߼�����*/ 78, 82, 100, 107, 109,
			ePS_��֪/*, ePS_�߼�����*/, ePS_�߼�ڤ˼/*, ePS_�߼�����*/, ePS_�߼����Ӹ���, ePS_�߼������ֿ�/*, ePS_��������*/
		};

		LoadCharacterData(eJuSe��ͷ��);
		LoadCharacterData(eJuSe��ң��);
		LoadCharacterData(eJuSe������);
		LoadCharacterData(eJuSe��̫��);
		LoadCharacterData(eJuSeɱ����);
		vector<int> mps = { eMP_�޵׶�, eMP_���ƹٸ�, eMP_��ľ��, eMP_��������, eMP_ħ��կ };
		forr(m_Friend._friends, idx)
		{
			cObj* obj = m_FightWorkList[idx].m_pObj;
			cCharacter* cc = (cCharacter*)obj->m_pIndex;
			int mp = cct::getMenpai(eMP_���);
			mp = mps[idx];
		//	cc->changeModel(getModelFromMp(mp));
			cPcData& pc = cc->m_PcData;
			pc.m_Lv = 159;
			pc.m_MengPaiID = mp;
			obj->SetTrueName(pc.m_Name = cc->GetData()->m_Name);
			obj->m_Name��ν.SetString(pc.m_Name);

			pc.setPointAfterLv(getAddpointFromMp(pc.m_MengPaiID, true), true);
			pc.autoData(true, true, false);
			pc.m_FuZhuSkillLvList[0] = pc.m_FuZhuSkillLvList[1] = pc.m_FuZhuSkillLvList[2] = pc.m_Lv;
			pc.m_Lv = 160;
			pc.autoEquip(false, true);
			pc.m_Lv = 159;
			pc.apply();
			pc.FillHpMp();

			pc.m_Money[0] += 1 << 24;
			//////////////////////////////////////////////////////////////////////////
			vector<int> spels = { 7, 9, 10, 13, 25, 48 };
			forr(spels, kk)
			{
				pc.m_Equips[kk].m_Property[12] = spels[kk];
			}
			//////////////////////////////////////////////////////////////////////////
			int m, k = 0;
			{
				cPet* pPet = new cPet;
				m = cct::getPetModel(pc.m_Lv - 50, pc.m_Lv);
				m = e����;
				mp = pc.m_Lv + cct::LvGapFromRoleAndBaby;
				mp = min(mp, cct::MaxBabyLv);
				g_pMainState->AutoPet(pPet, m, mp, true);
				pPet->m_PetData.m_ZiZhi.Set(1680, 1600, 2000, 6480, 1800, 1800, 129);
				pPet->m_PetData.SetJinJie(1);
				forv(skills, k)
				{
					pPet->m_PetData.AddSkill(skills[k], k);
				}

				auto& es = pPet->m_PetData.m_Equips;
				forr(es, k)
				{
					if (es[k].m_Property.size() > 15)
					{
						es[k].m_Property[15] = (rand() % 100 < 50) ? 2098/*5*/ : 2098;
					}
				}

				pc.AddPet(pPet);
			}
			SetFightPet(pc.m_IDinFightWorkList, rand() % pc.m_NumofBB);
		//	m_ZuoQi.GetZuoQi(pc, 79 + rand() % 10);
		}
		m_InterfaceTeam.update(false, m_Friend._friends.size());

		for (int i = 42; i <= 51; ++i)
		{
			if (0 == (g_GlobalValues[1] & (1 << (i - 42))))
			{
				g_GlobalValues[1] |= (1 << (i - 42));
			}
		}
//		m_Map.LoadMap(110, 190, "���ٴ�");
		m_Map.LoadMap(240, 260, "���ƹ���");
	}
	//	for (auto i : { e����ս��, e��������, e��ƿŮ�, e��ħ��, e���ȷ� })
	//	for (auto i : { e����ɡ, e��ë����, eϬţ����, eСħͷ, eţħ�� })
	//	for (auto i : { e��Ԫ����, e�, e�������, e�ն���ʦ, e�������� })
	//	for (auto i : { e����, e����, e����, e����ɮ, e�������})
	//  for (auto i : { e����Ѳ��, eѩ��, eС����, eС��, e������Ů })
	// 	for (auto i : { e����, e����, e���, e��, e���� })
	else
	{
		LoadCharacterData(eJuSe������);
		LoadCharacterData(1 + rand() % 14);
		LoadCharacterData(eJuSe����ʦ);
		LoadCharacterData(eJuSe��زز);
		LoadCharacterData(eJuSe������);
		sAddPoint ap;
		ap.Set(0, 0, 0, 5, 0);
		sItem2 item;
		forr(m_Friend._friends, idx)
		{
			cObj* obj = m_FightWorkList[idx].m_pObj;
			cCharacter* cc = (cCharacter*)obj->m_pIndex;
			cPcData& pc = cc->m_PcData;
			//////////////////////////////////////////////////////////////////////////
			pc.m_Lv = 30;
			pc.autoEquip(false, true);
			item.Set(29, 2);
			g_pMainState->m_ItemManage.XiangQian(pc.m_Equips[0], item);
			item.Set(29, 0);
			g_pMainState->m_ItemManage.XiangQian(pc.m_Equips[4], item);
			//////////////////////////////////////////////////////////////////////////
			pc.m_Lv = 5;
			pc.m_MengPaiID = -1;
			pc.PointRemain = cct::PointRemian;
			pc.setPointAfterLv(ap, false);
			pc.apply();
			pc.FillHpMp();

			cPet* pPet = new cPet;
			int model = cct::getPetModel(0, 5, false);
			pPet->SetData(m_PetDataManager.GetPetData(model));
			cPetData& pp = pPet->m_PetData;

			pp.Load(model, true, true);
			pp.m_Lv = pc.m_Lv + cct::LvGapFromRoleAndBaby;
			pp.m_Lv = max(pp.m_Lv, pPet->GetData()->m_LvTake + cct::LvGapFromRoleAndBaby);
			pp.PointRemain = cct::PointRemian;
			pp.setPointAfterLv(g_pMainState->getAddpointFromPet(&pp, true), true);
			pp.autoEquip(false, false);
			pp.apply();
			pp.SetJinJie(1);
			pp.FillHpMp();
			pc.AddPet(pPet);
			SetFightPet(idx, rand() % pc.m_NumofBB);

			if (idx > 0)
			{
				m_Friend._friends[idx].ctrl = false;
			}
		}

		auto& money = g_pCharacter->m_PcData.m_Money[0];
		auto& exp = g_pCharacter->m_PcData.m_EXP;
		for (int n = 5; n > 0; --n)
		{
			// 50�����ܺ͸�������
			for (int k = c_NumFuZhu; k >= 0; --k)
			{
				for (int i = 50; i > 0; --i)
				{
					money += GetMainSkillMoney(i);
					continue;
					exp += GetMainSkillExp(i);
				}
			}

			// ��
			for (int k = 8; k > 0; --k)
			{
				for (int i = 2; i > 0; --i)
				{
					money += GetXiuLIanExp(i) * 2000;
				}
			}

			// �ȼ�
			for (int i = g_pCharacter->m_PcData.m_Lv + 1; i <= 40; ++i)
			{
				break;
				exp += GetCharacterExp(i);
			}
		}

		// ��Ǯ
		money += 0xFFFFF;

		m_InterfaceTeam.update(false, 1);
		m_Map.LoadMap(20, 74, "��Դ��");
		g_pHeroObj->say("#R�׺���#R������,ȥ#R������#R������", 0xFFF);
	}

	m_PCHead.UpDateHead();
}