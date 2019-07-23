#include "Script.h"
struct sActTemplate
{
	int id;
	string name;
	vector<int> types;
};

static vector<sActTemplate> s_actMap =
{
	{ 0, "���� ~",
	{ SENTRYTYPE_STRING } },
	{ 1, "NPC�Ƿ�ѡ�� ����~ ",
	{ SENTRYTYPE_STRING } },
	{ 2, "˫ѡ��  ˭~ ����~ ѡ��1 ~ ѡ��2 ~",
	{ SENTRYTYPE_STRING, SENTRYTYPE_STRING, SENTRYTYPE_STRING, SENTRYTYPE_STRING } },
	{ 3, "��ѡ�� ˭~ ����~ ѡ��1 ~ ѡ��2 ~ ѡ��3 ~ ",
	{ SENTRYTYPE_STRING, SENTRYTYPE_STRING, SENTRYTYPE_STRING, SENTRYTYPE_STRING, SENTRYTYPE_STRING } },
	{ 4, "��ѡ�� ˭~ ����~ ѡ��1 ~ ѡ��2 ~ ѡ��3 ~ ѡ��4 ~",
	{ SENTRYTYPE_STRING, SENTRYTYPE_STRING, SENTRYTYPE_STRING, SENTRYTYPE_STRING, SENTRYTYPE_STRING, SENTRYTYPE_STRING } },
	{ 5, "�ű�����",
	{} },
	{ 6, "case ~",
	{ SENTRYTYPE_INT } },
	{ 7, "break",
	{} },
	{ 8, "default",
	{} },
	{ 9, "��ͼת�� ��ͼ��~ X~ Y~",
	{ SENTRYTYPE_STRING, SENTRYTYPE_INT, SENTRYTYPE_INT } },
	{ 10, "ָ����Ծ �������ű�ǩ~ ���� ~ ",
	{ SENTRYTYPE_INT, SENTRYTYPE_INT } },
	{ 11, "������� ����~ ��Ʒ�ȼ�~",
	{ SENTRYTYPE_INT, SENTRYTYPE_INT } },
	{ 12, "����switch",
	{} },
	{ 13, "���˶��� ~",
	{ SENTRYTYPE_STRING } },
	{ 14, "��Ļ���� ~",
	{ SENTRYTYPE_BOOL } },
	{ 15, "�²� ~ ˵ ~ Ƶ�� ~",
	{ SENTRYTYPE_STRING, SENTRYTYPE_STRING, SENTRYTYPE_INT } },
	{ 16, "���ÿ��� �ĸ�~  ״̬~",
	{ SENTRYTYPE_INT, SENTRYTYPE_INT } },
	{ 17, "���ô��� ��ͼ ~ λ�� ~  ~ ��Χ ~",
	{ SENTRYTYPE_STRING, SENTRYTYPE_INT, SENTRYTYPE_INT, SENTRYTYPE_INT } },
	{ 18, "�������� ���� ~  ���� ~ ",
	{ SENTRYTYPE_STRING, SENTRYTYPE_STRING } },
	{ 19, "�������� ���� ~  ���ڼ��ص�ID ~",
	{ SENTRYTYPE_STRING, SENTRYTYPE_INT } },
	{ 20, "��ɫ��� ԴID  ~  Ŀ��ID ~",
	{ SENTRYTYPE_INT, SENTRYTYPE_INT } },
	{ 21, "���ý�ɫλ�� ID ~  X ~ Y ~ ���� ~",
	{ SENTRYTYPE_INT, SENTRYTYPE_INT, SENTRYTYPE_INT, SENTRYTYPE_INT } },
	{ 22, "�������� �ű��� ~ ",
	{ SENTRYTYPE_STRING } },
	{ 23, "��ǩ ID ~ ",
	{ SENTRYTYPE_INT } },
	{ 24, "���ô��� ��ͼ ~ ���� ~",
	{ SENTRYTYPE_STRING, SENTRYTYPE_STRING } },
	{ 25, "��ȡ�Ի��� ���� ~ ID ~",
	{ SENTRYTYPE_STRING, SENTRYTYPE_INT } },
	{ 26, "������ͼ �Ƿ����� ~ �������� X~ Y~",
	{ SENTRYTYPE_INT, SENTRYTYPE_INT, SENTRYTYPE_INT } },
	{ 27, "�ȴ� ʱ�� ~",
	{ SENTRYTYPE_INT } },
	{ 28, "�õ�Ǯ  �ֽ� ~ ������ ~ ��ɫID ~",
	{ SENTRYTYPE_INT, SENTRYTYPE_INT, SENTRYTYPE_INT } },
	{ 29, "�õ����� ~ ��ɫID ~",
	{ SENTRYTYPE_INT, SENTRYTYPE_INT } },
	{ 30, "����Ǯ �ֽ� ~ ������ ~ ��ɫID ~",
	{ SENTRYTYPE_INT, SENTRYTYPE_INT, SENTRYTYPE_INT } },
	{ 31, "�õ���Ʒ ���� ~ ID ~ ���� ~  ��ɫID ~ �Ƿ���ʾ ~",
	{ SENTRYTYPE_INT, SENTRYTYPE_INT, SENTRYTYPE_INT, SENTRYTYPE_INT, SENTRYTYPE_INT } },
	{ 32, "��������EX ���� ~  ���� ~ ��ʧ���� ~",
	{ SENTRYTYPE_STRING, SENTRYTYPE_STRING, SENTRYTYPE_INT } },
	{ 33, "���ô���  ��ͼ ~ ��ɫ���� ~ �õ���Ʒ ���� ~ ID ~ ���� ~",
	{ SENTRYTYPE_STRING, SENTRYTYPE_STRING, SENTRYTYPE_INT, SENTRYTYPE_INT, SENTRYTYPE_INT } },
	{ 34, "���ô���  ��ͼ ~ ��ɫ���� ~ �õ�Ǯ ~ �õ����� ~",
	{ SENTRYTYPE_STRING, SENTRYTYPE_STRING, SENTRYTYPE_INT, SENTRYTYPE_INT } },
	{ 35, "���öԻ���ʽ 0��4��ʾƵ��,-1��ʾ������Ի� ~",
	{ SENTRYTYPE_INT } },
	{ 36, "���ô��� ���ǵȼ� ~",
	{ SENTRYTYPE_INT } },
	{ 37, "���������ɫ ������ ~ ��ɫ�ļ��� ~  ���ڵ�ͼ�� ~ λ�� ~ ~ ���� ~ λ��ID ~",
	{ SENTRYTYPE_STRING, SENTRYTYPE_STRING, SENTRYTYPE_STRING, SENTRYTYPE_INT, SENTRYTYPE_INT, SENTRYTYPE_INT, SENTRYTYPE_INT } },
	{ 38, "ɾ�������ɫ ������ ~ ��ɫ�ļ��� ~  ",
	{ SENTRYTYPE_STRING, SENTRYTYPE_STRING } },
	{ 39, "��������ս�� ������ ~",
	{ SENTRYTYPE_STRING } },
	{ 40, "�ر�",
	{} },
	{ 41, "��⿪��~ �Ƿ�Ϊ~",
	{ SENTRYTYPE_INT, SENTRYTYPE_INT } },
};

bool cScript::LoadActionTemplate(string Path)
{
	if (m_ActionTemplateList.empty())
	{
		forv(s_actMap, k)
		{
			sActionTemplate ActionTempale1;
			ActionTempale1.Name = s_actMap[k].name;
			ActionTempale1.NumOfEntryUnoin = s_actMap[k].types.size();
			if (ActionTempale1.NumOfEntryUnoin)
			{
				ActionTempale1.pEntryUnoinsType = new int[ActionTempale1.NumOfEntryUnoin];
				forv(s_actMap[k].types, i)
				{
					ActionTempale1.pEntryUnoinsType[i] = s_actMap[k].types[i];
				}
			}
			m_ActionTemplateList.push_back(ActionTempale1);
		}
	}
	return true;
	// ��: ��ȡ��Ϊģ��
	ifstream file;
	file.open(Path);
	if (!file)return false;
	while (true)
	{
		sActionTemplate ActionTempale1;
		ActionTempale1.Name = "";
		//��ȡһ����Ϊģ��  
			getline(file, ActionTempale1.Name);
			if (ActionTempale1.Name.size()<2)
				getline(file, ActionTempale1.Name);
			if (ActionTempale1.Name.size() < 2)
			{
				file.close();
//				return true;
				break;
			}
		

		for (uint i = 0; i < ActionTempale1.Name.length(); i++)
		{
			if (ActionTempale1.Name[i] == '~')
			{
				ActionTempale1.NumOfEntryUnoin += 1;
			}
		}
		ActionTempale1.pEntryUnoinsType = new int[ActionTempale1.NumOfEntryUnoin];
		string text;
		for (int i = 0; i < ActionTempale1.NumOfEntryUnoin; i++)
		{
			file >> text;
			if (!text.compare("STRING"))
			{
				ActionTempale1.pEntryUnoinsType[i] = SENTRYTYPE_STRING;
			}
			else
			if (!text.compare("INT"))
			{
				ActionTempale1.pEntryUnoinsType[i] = SENTRYTYPE_INT;
			}
			else
			if (!text.compare("FLOAT"))
			{
				ActionTempale1.pEntryUnoinsType[i] = SENTRYTYPE_FLOAT;
			}
			else
			if (!text.compare("BOOL"))
			{
				ActionTempale1.pEntryUnoinsType[i] = SENTRYTYPE_BOOL;
			}

		}
		m_ActionTemplateList.push_back(ActionTempale1);
	}

	vector<string> tnames =
	{
		"SENTRYTYPE_NULL",
		"SENTRYTYPE_STRING",
		"SENTRYTYPE_INT",
		"SENTRYTYPE_FLOAT",
		"SENTRYTYPE_BOOL"
	};



	string str;
	forv(m_ActionTemplateList, k)
	{
		const auto& t = m_ActionTemplateList[k];
		ccc_log("{%d, \"%s\",", k, t.Name.c_str());
		str = "{";
		for (int i = 0; i < t.NumOfEntryUnoin; ++i)
		{
			str += tnames[t.pEntryUnoinsType[i]] + ",";
		}
		if (str.size() > 1)
		{
			str.pop_back();
		}
		str += "}},";
		ccc_log(str.c_str());
	}

	return true;
}

void cScript::Add(sAction& Action)
{
	m_ActionList.push_back(Action);
}

void cScript::Insert(sAction& Action, int Pos)
{
	if (m_ActionList.size() < (uint)Pos)
	{
		return;
	}
	list<sAction>::iterator it;
	it = GetIterator(Pos);
	m_ActionList.insert(it, Action);
}

void cScript::Up(int Pos)
{
	if (m_ActionList.size()-1 < (uint)Pos)
	{
		return;
	}
	list<sAction>::iterator it;
	list<sAction>::iterator it2;
	it = GetIterator(Pos);
	it2 = GetIterator(Pos - 1);
	swap(*it2, *it);
}

void cScript::Down(int Pos)
{
	Up(Pos+1);
}

list<sAction>::iterator cScript::GetIterator(int Pos)
{
	list<sAction>::iterator it;
	it = m_ActionList.begin();
	for (int i = 0; i < Pos; i++)
	{
		it++;
	}
	return it;
}

void cScript::Delete(int Pos)
{
	list<sAction>::iterator it;
	it=GetIterator(Pos);
	m_ActionList.erase(it);
}

bool cScript::LoadScript(string name)
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	ifstream  File;
	File.open(name);
	if (!File)return false;
	m_ActionList.clear();
	while (true)
	{
		sAction  Action;
		File >> Action.ID;
		if (File.eof())
		{
			return true;
		}
		File >> Action.NumOfEntryUnion;
		Action.pEntryUnoins = new sEntryUnion[Action.NumOfEntryUnion];
		for (int k = 0; k < Action.NumOfEntryUnion; k++)
		{
			File >> Action.pEntryUnoins[k].Type;
			switch (Action.pEntryUnoins[k].Type)
			{
			case SENTRYTYPE_INT:
				File >> Action.pEntryUnoins[k].intData;
				break;
			case SENTRYTYPE_FLOAT:
				File >> Action.pEntryUnoins[k].floatData;
				break;
			case SENTRYTYPE_BOOL:
				File >> Action.pEntryUnoins[k].intData;
				break;
			case SENTRYTYPE_STRING:
				File >> Action.pEntryUnoins[k].stringData;
				break;
			default:
				MessageBoxA(0, "δ֪����", "��ȡ", MB_OK);
				break;
			}
		}
		m_ActionList.push_back(Action);
	}
	return true;
}

void cScript::Free()
{
	list<sAction>::iterator it = m_ActionList.begin();
	for (uint i = 0; i < m_ActionList.size(); i++)
	{
		it->Free();
		it++;
	}
	list<sAction>  dustbin;
	m_ActionList.swap(dustbin);

	
	for (uint i = 0; i < m_ActionTemplateList.size(); i++)
	{
		m_ActionTemplateList[i].Free();
	}
	vector<sActionTemplate> dustbin2;
	m_ActionTemplateList.swap(dustbin2);
}
