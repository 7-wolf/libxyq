#include "_global.h"
#include "_txt.h"


vector<int> cAI::findTarget(int skill, int& findsCount)
{
	int userID = m_UserID;
	findsCount = -1;

	auto cbFire = [&](vector<int>& ts)
	{
		bool isOk = false;
		vector<int> ts2;
		forr(ts, i)
		{
			setData(userID, ts[i]);
			if (s_obj2->m_ConductFire.m_NeedShow)
			{
				ts2.push_back(ts[i]);
				ts.erase(ts.begin() + i);
				isOk = true;
			}
		}
		forv(ts2, i)
		{
			ts.insert(ts.begin(), ts2[i]);
		}
		return isOk;
	};

	auto addTs = [](vector<int>& ts, const vector<int>& t2s)
	{
		forv(t2s, i)
		{
			if (std::find(ts.begin(), ts.end(), t2s[i]) == ts.end())
			{
				ts.push_back(t2s[i]);
			}
		}
	};

	int type;
	if (skill == 1000)
	{
		type = (int)ctt::eSkillUse::BattleOther;
	}
	else
	{
		type = g_pMainState->m_SkillManager.GetSkill(skill)->m_SkillType;
	}
	eSkill e = (eSkill)skill;

	if (type == (int)ctt::eSkillUse::BattleOther)
	{
		vector<int> ts = findOthers(userID);
		if (ts.empty())
		{
			return ts;
		}
		if (getDamage(userID, ts.front(), skill) >= 0)
		{
			vector<sInt2> ds, d2s;
			sInt2 d;
			forv(ts, i)
			{
				d.d1 = ts[i];
				d.d2 = getDamage(userID, ts[i], skill);
				setData(userID, ts[i]);
				if (s_data2->m_HP < d.d2)
				{
					d.d2 = d.d2 - s_data2->m_HP;
					ds.push_back(d);
				}
				else
				{
					d2s.push_back(d);
				}
			}

			std::sort(ds.begin(), ds.end(), [&](const sInt2& s1, const sInt2& s2)
			{
				return s1.d2 < s2.d2;
			});

			std::sort(d2s.begin(), d2s.end(), [&](const sInt2& s1, const sInt2& s2)
			{
				return s1.d2 > s2.d2;
			});

			ts.clear();
			forv(ds, i)
			{
				ts.push_back(ds[i].d1);
			}
			forv(d2s, i)
			{
				ts.push_back(d2s[i].d1);
			}

			int t = ts.front();
			ts = findOthers(userID);
			forr(ts, i)
			{
				if (i > 0 && ts[i] == t)
				{
					swap(ts[i], ts[0]);
					break;
				}
			}

			if (!cbFire(ts))
			{
				vector<int> ts2;
				if (e == eSkill::������˫ ||
					e == eSkill::����һ�� ||
					e == eSkill::�й���)
				{
					forv(ts, i)
					{
						setData(userID, ts[i]);
						if (isMagFromPoint(s_data2))
						{
							ts2.push_back(ts[i]);
						}
					}
				}
				else if (e == eSkill::���컨��)
				{
					forv(ts, i)
					{
						setData(userID, ts[i]);
						if (!isPosion(s_obj2))
						{
							ts2.push_back(ts[i]);
						}
					}
				}
				else if (e == eSkill::�����ٻ�)
				{
					forv(ts, i)
					{
						setData(userID, ts[i]);
						if (s_obj2->getPetData())
						{
							continue;
						}
						if (s_obj2->CheckHaveState((int)eSkill::������))
						{
							continue;
						}
						if (s_obj2->CheckHaveState((int)eSkill::�����ٻ�))
						{
							continue;
						}
						if (s_data2->m_Controler.GetFly())
						{
							continue;
						}
						ts2.push_back(ts[i]);
					}
				}
				addTs(ts2, ts);
				swap(ts2, ts);
			}
			return ts;
		}
	}

	auto cbTs2 = [&](const vector<int>& ts)
	{
		vector<int> ts2;
		forv(ts, i)
		{
			setData(userID, ts[i]);
			if (s_list1->_turnOfSpeed < s_list2->_turnOfSpeed)
			{
				ts2.push_back(ts[i]);
			}
		}
		return ts2;
	};


	if (isSkillSeal(skill))
	{
		function<bool(int)> con = nullptr;
		if (e == eSkill::����)
		{
			con = [&](int i)
			{
				setData(userID, i);
				if (s_obj2->getPcData())
				{
					return false;
				}
				return true;
			};
		}
		else if (e == eSkill::����� || e == eSkill::�������)
		{
			// ��������
			con = [&](int i)
			{
				setData(userID, i);
				if (s_obj2->getPcData())
				{
					return false;
				}
				if (isAtkFromPoint(s_data2))
				{
					vector<int> bs, ps, ms, m2s;
					if(isHadPetSkill(s_data2, bs, ps, ms, m2s))
					{
						return false;
					}
				}
				return true;
			};
		}
		else if (e == eSkill::ʧ�ķ� || e == eSkill::���� || e == eSkill::������)	
		{
			// �����ⷨ
			con = [&](int i)
			{
				setData(userID, i);
				if (s_obj2->getPetData())
				{
					vector<int> bs, ps, ms, m2s;
					if (!isHadPetSkill(s_data2, bs, ps, ms, m2s))
					{
						if (ms.empty() && m2s.empty())
						{
							return false;
						}
					}
				}
				return true;
			};
		}
		auto ts = findOthers(userID, eFindType::Sealable, con, skill);
		bool isOk = false;
		vector<int> ts2;
		forr(ts, i)
		{
			setData(userID, i);
			if (s_obj2->m_ConductSeal.m_NeedShow)
			{
				ts2.push_back(ts[i]);
				ts.erase(ts.begin() + i);
				isOk = true;
			}
		}
		forv(ts2, i)
		{
			ts.insert(ts.begin(), ts2[i]);
		}

		if (!isOk && e != eSkill::����)
		{
			con = [&](int i)
			{
				setData(userID, i);
				if (s_obj2->getPetData())
				{
					return false;
				}
				return true;
			};
			ts2 = findOthers(userID, eFindType::Sealable, con, skill);
			ts2 = cbTs2(ts2);

			ts = cbTs2(ts);
			addTs(ts2, ts);
			swap(ts, ts2);
		}

		findsCount = ts.size();

		ts2 = findOthers(userID, eFindType::None, nullptr, skill);
		addTs(ts, ts2);
		return ts;
	}

	if (e == eSkill::������)
	{
		auto con = [&](int i)
		{
			setData(userID, i);
			if (s_data1->m_Lv < s_data2->m_Lv - 30)
			{
				return false;
			}
			if (s_obj2->getPetData())
			{
				return false;
			}
			if (s_obj2->CheckHaveState((int)eSkill::�����ٻ�))
			{
				return false;
			}
			if (s_data2->m_Controler.GetFly())
			{
				return false;
			}
			if (!isHpLessThan(s_data2, 25))
			{
				return false;
			}
			return true;
		};
		auto ts = findOthers(userID, eFindType::HpRateMin, con, skill);
		findsCount = ts.size();
		auto con2 = [&](int i)
		{
			if (s_obj2->getPetData())
			{
				return false;
			}
			setData(userID, i);
			if (s_obj2->CheckHaveState((int)eSkill::�����ٻ�))
			{
				return false;
			}
			return true;
		};
		auto t2s = findOthers(userID, eFindType::HpRateMin, con2, skill);
		addTs(ts, t2s);
		return ts;
	}



	if (e == eSkill::��η��ʩ)
	{
		auto con = [&](int i)
		{
			setData(userID, i);
			if (s_obj2->getPetData())
			{
				return false;
			}
			if (i == userID)
			{
				return false;
			}
			return true;
		};
		vector<int> ts = findOwners(userID, eFindType::ManaMin, con, skill);
		if (ts.empty())
		{
			auto con2 = [&](int i)
			{
				return i != userID;
			};
			ts = findOwners(userID, eFindType::ManaMin, con2, skill);
		}
		return ts;
	}

	if (e == eSkill::������ || e == eSkill::�����)
	{
		return findOwners(userID, eFindType::Mp0);
	}


	if (e == eSkill::������¶)
	{
		auto con = [&](int i)
		{
			const auto& ss = _controlMap.at(eFindType::Dying);
			if (ss.find(i) != ss.end())
			{
				return false;
			}
			return true;
		};

		vector<int> ts = findOwners(userID, eFindType::Dying, con);
		auto ts2 = cbTs2(ts);
		if (ts2.size())
		{
			return ts2;
		}
		return ts;
	}

	if (e == eSkill::�ػ��� ||
		e == eSkill::�������� ||
		e == eSkill::�ҷ�ȱ� ||
		e == eSkill::������ ||
		e == eSkill::�ɼ�����)
	{
		auto con = [&](int i)
		{
			const auto& ss = _controlMap.at(eFindType::Dying);
			if (ss.find(i) != ss.end())
			{
				return false;
			}
			return true;
		};
		vector<int> t2s = findOwners(userID, eFindType::Relifeable, con);
		findsCount = t2s.size();
		auto ts = cbTs2(t2s);
		addTs(ts, t2s);
		return ts;
	}

	if (e == eSkill::ˮ��� || e == eSkill::�����)
	{
		auto con = [&](int i)
		{
			const auto& ts = _controlMap.at(eFindType::UnSeal);
			if (ts.find(i) != ts.end())
			{
				return false;
			}
			return true;
		};
		auto t2s = findOwners(userID, eFindType::UnSeal, con);
		auto ts = cbTs2(t2s);
		addTs(ts, t2s);
		findsCount = ts.size();
		auto con2 = [&](int i)
		{
			setData(i, i);
			int c = 0;
			for (list<sBuff>::iterator Iterator = s_obj2->m_StateList.begin(); Iterator != s_obj2->m_StateList.end(); ++Iterator)
			{
				if (Iterator->EffectType == eBuffType�� || 
					Iterator->EffectType == eBuffType��ӡ ||
					Iterator->EffectType == eBuffType����)
				{
					++c;
				}
			}
			return c > 0;
		};
		t2s = findOwners(userID, eFindType::None, con2);
		addTs(ts, t2s);
		return ts;
	}

	if (e == eSkill::ɱ���� ||
		e == eSkill::��ջ��� || 
		e == eSkill::Τ�ӻ��� ||
		e == eSkill::���Ǿ� ||
		e == eSkill::����)
	{
		auto ts = findOwners(userID, eFindType::MpPhy, nullptr, skill);
		findsCount = ts.size();
		auto t2s = findOwners(userID, eFindType::None, nullptr, skill);
		addTs(ts, t2s);
		return ts;
	}

	if (e == eSkill::����)
	{
		auto ts = findOwners(userID, eFindType::MpMag, nullptr, skill);
		findsCount = ts.size();
		auto t2s = findOwners(userID, eFindType::None, nullptr, skill);
		addTs(ts, t2s);
		return ts;
	}

	if (e == eSkill::�ƻ껯��)
	{
		auto con = [&](int i)
		{
			setData(userID, i);
			if (s_data1->SuckBloodRate.d1 > 0/* && s_data1->SuckBloodPercent.d1 > 10*/)
			{
				return false;
			}
			return true;
		};
		auto ts = findOwners(userID, eFindType::MpPhy, con, skill);
		findsCount = ts.size();
		auto t2s = findOwners(userID, eFindType::None, con, skill);
		addTs(ts, t2s);
		t2s = findOwners(userID, eFindType::None, nullptr, skill);
		addTs(ts, t2s);
		return ts;
	}




	if (e == eSkill::��Ѫ ||
		e == eSkill::�������� ||
		e == eSkill::����ȡ�� ||
		e == eSkill::����֮Ȫ ||
		e == eSkill::�ն����� ||
		e == eSkill::��ӿ���� ||
		e == eSkill::������ ||
		e == eSkill::������ ||
		e == eSkill::������)
	{
		function<bool(int)> con = nullptr;
		if (e == eSkill::�ն�����)
		{
			auto con = [&](int i)
			{
				setData(userID, i);
				if (s_obj2->CheckHaveState((int)eSkill::������¶))
				{
					return false;
				}
				return true;
			};
		}
		vector<int> ts = findOwners(userID, eFindType::HpNotFull, con, skill);
		if (e == eSkill::����֮Ȫ || e == eSkill::�ն�����)
		{
			auto t2s = findOwners(userID, eFindType::HpRateMin, con, skill);
			findsCount = t2s.size();
			addTs(ts, t2s);
			t2s = findOwners(userID, eFindType::HpRateMin);
			addTs(ts, t2s);
		}
		else
		{
			findsCount = ts.size();
		}
		return ts;
	}

	if (e == eSkill::���ޱ�)
	{
		auto con = [&](int i)
		{
			setData(userID, i);
			if (s_obj2->getPetData())
			{
				return false;
			}
			return true;
		};
		auto t2s = findOwners(userID, eFindType::MpMag, con, skill);
		auto ts = cbTs2(t2s);
		addTs(ts, t2s);
		findsCount = ts.size();
		t2s = findOwners(userID, eFindType::MpMag, nullptr, skill);
		addTs(ts, t2s);
		t2s = findOwners(userID, eFindType::None, nullptr, skill);
		addTs(ts, t2s);
		return ts;
	}

	if (e == eSkill::���׺䶥 || e == eSkill::����)
	{
		vector<int> ts = findOthers(userID);
		std::sort(ts.begin(), ts.end(), [&](int a, int b)
		{
			setData(a, b);
			return s_data1->m_HP > s_data2->m_HP;
		});

		cbFire(ts);
		return ts;
	}


	if (e == eSkill::������)
	{
		auto ts = findOthers(userID, eFindType::None, nullptr, (int)eSkill::������);
		std::sort(ts.begin(), ts.end(), [&](int a, int b)
		{
			setData(a, b);
			return s_data1->m_HP > s_data2->m_HP;
		});

		return ts;
	}

	if (e == eSkill::��������)
	{
		vector<int> ts = findOwners(userID, eFindType::MpMin, nullptr, skill);
		return ts;
	}

	if (e == eSkill::�����ķ�)
	{
		auto con = [&](int i)
		{
			setData(userID, i);
			if (!isState(s_obj2, { (int)eSkill::�ն�����, (int)eSkill::������¶ }))
			{
				return false;
			}
			int hp = 1;
			int t = 1;
			for (list<sBuff>::iterator Iterator = s_obj2->m_StateList.begin(); Iterator != s_obj2->m_StateList.end(); ++Iterator)
			{
				if (Iterator->ID == (int)eSkill::�ն����� ||
					Iterator->ID == (int)eSkill::������¶)
				{
					if (t < Iterator->remainingTimes)
					{
						t = Iterator->remainingTimes;
					}
					if (hp < Iterator->damage)
					{
						hp = Iterator->damage;
					}
				}
			}
			if (t < 3)
			{
				return false;
			}
			hp *= t;
			return true;
		};
		auto ts = findOwners(userID, eFindType::HpRateMin, con);
		findsCount = ts.size();
		auto con2 = [&](int i)
		{
			setData(userID, i);
			if (!isState(s_obj2, { (int)eSkill::�ն�����, (int)eSkill::������¶ }))
			{
				return false;
			}
			return true;
		};
		auto t2s = findOwners(userID, eFindType::HpRateMin, con2);
		addTs(ts, t2s);
		return ts;
	}


	if (e == eSkill::ʬ���� || e == eSkill::��ɱ)
	{
		auto con = [&](int i)
		{
			setData(userID, i);
			if (s_data1->m_Lv < s_data2->m_Lv - 50)
			{
				return false;
			}
			return true;
		};
		vector<int> ts = findOthers(userID, eFindType::Sealable, con, skill);
		std::sort(ts.begin(), ts.end(), [&](int a, int b)
		{
			setData(a, b);
			return s_data1->m_HP > s_data2->m_HP;
		});
		findsCount = ts.size();
		auto t2s = findOthers(userID, eFindType::Sealable, nullptr, skill);
		addTs(ts, t2s);
		return ts;
	}

	if (e == eSkill::�ߵ�����)
	{
		auto con = [&](int i)
		{
			setData(i, i);
			if (isStateDMag(s_obj2))
			{
				return false;
			}
			return true;
		};
		return findOwners(userID, eFindType::None, con, skill);
	}

	if (e == eSkill::�����ɢ)
	{
		auto con = [&](int i)
		{
			setData(userID, i);
			if (g_pMainState->m_SkillManager.CheckMagicHit(s_obj1->GetSkillLv(0), skill, userID, i) < 50)
			{
				return false;
			}
			int c = 0;
			for (list<sBuff>::iterator Iterator = s_obj2->m_StateList.begin(); Iterator != s_obj2->m_StateList.end(); ++Iterator)
			{
				if (Iterator->EffectType == eBuffType���� &&
					Iterator->remainingTimes >= 3)
				{
					++c;
				}
			}
			return c >= 3;
		};
		auto t2s = findOthers(userID, eFindType::None, con, skill);
		auto ts = cbTs2(t2s);
		addTs(ts, t2s);
		findsCount = ts.size();
		auto con2 = [&](int i)
		{
			setData(i, i);
			int c = 0;
			for (list<sBuff>::iterator Iterator = s_obj2->m_StateList.begin(); Iterator != s_obj2->m_StateList.end(); ++Iterator)
			{
				if (Iterator->EffectType == eBuffType���� &&
					Iterator->remainingTimes >= 1)
				{
					++c;
				}
			}
			return c > 0;
		};
		t2s = findOthers(userID, eFindType::None, con2, skill);
		addTs(ts, t2s);
		t2s = findOthers(userID);
		addTs(ts, t2s);
		return ts;
	}


	if (type == (int)(int)ctt::eSkillUse::BattleOther)
	{
		return findOthers(userID, eFindType::None, nullptr, skill);
	}
	if (type == 2)
	{
		vector<int> ts;
		if (!m_pUser->CheckHaveState(skill))
		{
			ts.push_back(m_UserID);
		}
		return ts;
	}
	return  findOwners(userID, eFindType::None, nullptr, skill);
}

