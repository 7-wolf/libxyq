#include "_global.h"

static bool isNotZX()
{
	if (g_pMainState->m_Job.CheckHaveJob(TASK_TYPE_ZHUXIAN))
	{
		g_pMainState->m_Tags.Add("�������߾���δ���");
		return false;
	}
	return true;
}

bool cTaskBangPai::Process(int stage)
{
	if (stage == -1)
	{
		return true;
	}
	if (stage == 1)
	{
		if (isNotZX())
		{
			g_pMainState->m_ZhuXian.SetChapter(1);
			g_pMainState->m_ZhuXian.Process(0);
		}
		return true;
	}

	if (stage == 2)
	{
		if (isNotZX())
		{
			g_pMainState->m_ZhuXian.SetChapter(2);
			g_pMainState->m_ZhuXian.Process(0);
		}
		return true;
	}

	if (stage == 3)
	{
		if (isNotZX())
		{
			g_pMainState->m_ZhuXian.SetChapter(3);
			g_pMainState->m_ZhuXian.Process(0);
		}
		return true;
	}
	if (stage == 4)
	{
		if (isNotZX())
		{
			g_pMainState->m_ZhuXian.SetChapter(4);
			g_pMainState->m_ZhuXian.Process(0);
		}
		return true;
	}

	if (stage == 5)
	{
		if (isNotZX())
		{
			g_pMainState->m_ZhuXian.SetChapter(5);
			g_pMainState->m_ZhuXian.Process(0);
		}
		return true;
	}

	if (stage == 6)
	{
		if (isNotZX())
		{
			g_pMainState->m_ZhuXian.SetChapter(6);
			g_pMainState->m_ZhuXian.Process(0);
		}
		return true;
	}

	if (stage == 7)
	{
		if (isNotZX())
		{
			g_pMainState->m_ZhuXian.SetChapter(7);
			g_pMainState->m_ZhuXian.Process(0);
		}
		return true;
	}
	if (stage == 8)
	{
		if (isNotZX())
		{
			g_pMainState->m_ZhuXian.SetChapter(8);
			g_pMainState->m_ZhuXian.Process(0);
		}
		return true;
	}






#pragma region ͵͵��
	if (stage == 100)
	{
		g_pMainState->setNowSelect();
		g_pMainState->m_TriggerDialog.AddSelect(this, "�屦�һ�(ֻ���ӳ�����)", "͵͵��", -1, "�һ�����Ҫ��", 101, "��δ����", -1);
		return true;
	}
	if (stage == 101)
	{
		int idx5s[] = { -1, -1, -1, -1, -1 };
		int id;
		int c = 0;
		auto& items = g_pCharacter->m_PcData.m_Items;
		forr (items, i)
		{
			auto& it = items[i];
			if (it.m_Num < 1)
			{
				continue;
			}
			if (27 != it.GetType())
			{
				continue;
			}
			id = it.GetID();
			if (id < 6 || id > 10)
			{
				continue;
			}
			if (idx5s[id - 6] < 0)
			{
				idx5s[id - 6] = i;
				++c;
			}
		}
		if (c < 5)
		{
			g_pMainState->dialog("û�����ʲô����");
			return true;
		}
		for (int i = 0; i < 5; ++i)
		{
			--items[idx5s[i]].m_Num;
		};
		g_pMainState->awardShouJue3();
	}

	if (stage >= 183 && stage <= 185)
	{
		static std::vector<std::vector<ePetID>> pet3s;
		if (pet3s.empty())
		{
			pet3s.push_back({ e�޺�, e��ң��,e����ʦ,e����Ů,eӢŮ��,e������ });
			pet3s.push_back({ e��̫��,e�����,e������,e���켧,e���ʶ�,e��زز });
			pet3s.push_back({ e��ħ��,e��ͷ��,eɱ����,e������,e�Ǿ���,e������ });
		}
		const auto& pets = pet3s.at(stage - 183);
		int sid = pets.at(rand() % pets.size());
		cPet* pet = new cPet;
		pet->SetData(&g_pMainState->m_PetDataManager.m_PetList[sid]);
		auto& p = pet->m_PetData;
		p.Load(sid, true, true);
		p.PointRemain = cct::PointRemian;
		p.apply();
		p.FillHpMp();
		g_pCharacter->m_PcData.AddPet(pet);
		g_pMainState->m_Tags.Add("����ȡ��" + pet->GetData()->m_Name);
	}
#pragma endregion ͵͵��
	return true;
}



void cTaskBangPai::Init()
{
	m_type = 2;

}