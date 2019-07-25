#include "global.h"


void cMySound::Load(std::string path)
{
	if (path == "��")
	{
		_uid = 0;
		Free();
		return;
	}

	static std::map<std::string, std::string> s_transMap = 
	{
		{"���䱳��", "��ս�볡"},
		{"����2", "���䳡"},
		{"�ﳲ3", "δ֪"},
		{"ս��_����_DT", ""},
	};
	if (s_transMap.find(path) != s_transMap.end())
	{
		path = s_transMap.at(path);
	}

	if (path == "ս��4" || path == "ս��5")
	{
		path = toString("ս��%d", (rand() % 3) + 1);
	}
	if (path == "ս������" || path == "ս��_����" || path == "ս��_����2")
	{
		path = toString("ս������%d", (rand() % 4) + 1);
	}

	// ս������û��5
	// �������⻹���������?
	static std::map<std::string, unsigned long> s_map = {
	{"�����Թ�", 0x00167186},
	{"�����Թ�2", 0x00167186},
	{"����ɽ", 0x012D9DD7},
	{"��ľ��", 0x016F4476},
	{"С����", 0x03D65C21}, //С������
	{"������2", 0x05122F2E},
	{"�貨��", 0x0B16F601},
	{"���԰", 0x10D7ABF1},
	{"�����ɵ�", 0x10DF6DF7},
	{"���ٽ���", 0x18348D2B},
	{"С������", 0x2011A8C2},
	{"����«��", 0x2142584C},
	{"����ɽ", 0x21BEB585},
	{"������", 0x26275208},
	{"����Ұ��", 0x266E2C58},
	{"������1", 0x2C3D8AF0},
	{"���ٴ�", 0x2F1EC70A},
	{"�����", 0x3127BBB8},
	{"������", 0x35159569},
	{"ʨ����", 0x3800966C},
	{"ս������1", 0x389F5EF4},
	{"���ƶ�", 0x3F24C153},
	{"���ֶ���", 0x41645B50},
	{"ħ��կ", 0x4A64F8BD},
	{"���ƹٸ�", 0x4AE2B5B3},
	{"������", 0x4B4740AC},
	{"˿��֮·", 0x52A0B4EE},
	{"����ɽ", 0x53C2DE57},
	{"�����Թ�2", 0x5A864351},
	{"�¹�", 0x5B0DCCD9},
	{"������", 0x5B9DC400},
	{"����2", 0x65B90ACA},
	{"������", 0x68F6DDA1},
	{"���ܵظ�", 0x700EE303},
	{"��Դ��", 0x76C2A481},
	{"", 0x78FC0CBA}, // �����
	{"����", 0x79D250E2},
	{"��ս�볡", 0x7B908BCA},
	{"ī�Ҵ�", 0x7C4D04B2},
	{"ս��BOSS", 0x845DC12C},
	{"����Ů��", 0x8482AF70},
	{"����", 0x84E2EB78},
	{"����", 0x86C4F045}, // �η�  ���� 
	{"����ɽ", 0x88CD5404},
	{"ս��1", 0x8905924A},
	{"����ɽ", 0x8C4500FC},
	{"Ů����", 0x8CAB9764},
	{"��������", 0x8EF4D872},
	{"δ֪", 0x9245F880}, // ��ΰ ��ϵ
	{"������", 0x92DD1A7A},
	{"�޵׶�", 0x95C16AD7},
	{"ī�ҽ���", 0x9E05AC95},
	{"ս������2", 0x9EC29A9D}, // ս��5-��ԭ
	{"���Ϲ�", 0xA602567C},
	{"δ֪����", 0xA6F426EB},
	{"��", 0xA7330084},
	{"�����", 0xA8A9DBB9},
	{"ս��ɽ", 0xAA002386},
	{"��˿��", 0xAC396538},
	{"����", 0xAE8B3481},
	{"��ĸ�ӵ�", 0xAE8C1555},
	{"�ﳲ", 0xB0D9F40A},
	{"ս��3", 0xB248A7C7}, // ս��7-ɽ��
	{"�ﳲ2", 0xB33EB187},
	{"���䳡", 0xBED44FE1},
	{"ս��2", 0xC1064081}, // ս��6-����
	{"���¶�", 0xCD525622},
	{"�����Թ�", 0xD3B5D40A},
	{"���ƾ���", 0xD66E10A8},
	{"����ɽ", 0xDABAC06C},
	{"Ů���", 0xE4096D42},
	{"�칬", 0xE7CE763C},
	{"���ƹ���", 0xEA26251A},
	{"�����Թ�5", 0xEBCC1270}, // ��������
	{"��������", 0xEBCC1270},
	{"ս������3", 0xF303B6A9},
	{"ս������4", 0xFB165E34},
	{"��ׯ��", 0xFD1ECF8F},
	}; 

	if (s_map.find(path) == s_map.end())
	{
		std::ifstream ifile(g_strMediaPath + "music/" + path + ".mp3", std::ios::binary);
		if (ifile.is_open())
		{
			if (g_pMainState->m_GlobalButton[16] == 0)
			{
				// ����mp3�ļ�
				char* ptr = nullptr;
				int size;
				ifile.seekg(0, std::ios::end);
				size = ifile.tellg();
				ptr = new char[size];
				ifile.seekg(std::ios::beg);
				ifile.read(ptr, size);
				ifile.close();
				if (ptr != nullptr)
				{
					static ulong uid = 0;
					cBass::getInstance()->play(_uid = ++uid, ptr, size);
				}
			}
			return;
		}
		path = "ս��BOSS";
	}

	const auto& it = s_map.find(path);
	if (it == s_map.end() || _uid == it->second)
	{
		return;
	}
	_uid = it->second;
	Play();
}

void cMySound::Free()
{
}

void cMySound::CheckEnd()
{

}

void cMySound::Reset()
{

}

void cMySound::Stop()
{
	cBass::getInstance()->setMp3(0);
}


void cMySound::Play()
{
	if (g_pMainState->m_GlobalButton[16] == 0)
	{
		cBass::getInstance()->setMp3(100);
		int size;
		auto ptr = cWdf::getMp3()->getData(_uid, size);
		if (ptr != nullptr)
		{
			cBass::getInstance()->play(_uid, ptr, size);
		}
		
	}

}

void cMyWav::Load(unsigned char* pdata,int size,int pos/* =0 */, bool bPlay/* =true */)
{

}

void cMyWav::Free()
{
}

void cMyWav::SetPosition(int num)
{
}

int cMyWav::GetNowPostion()
{
	return 0;
}



