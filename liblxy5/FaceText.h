#pragma once
#include "_objinc.h"

// class cInterfaceChannel;
// class cCanvas;
struct sTextLine   //һ��
{
	static const int MaxLine = 32;
	array<cObjWas, MaxLine> m_Face;
	array<int, MaxLine>    m_xFace;
	int m_NumFace;
	cText m_line;
	int m_Height;
};
struct sColorTag
{
	int m_linenum; //��������
	int m_start;  //��������
	ulong m_Color; //��ɫ
};
struct sFaceText //һ�� �����������
{
	vector<sColorTag> m_ColorTag;
	int m_Height = 0;
	int m_Gap = 0;
	int m_FirstAdd;//��������
	void Show(cCanvas* pCanvas);
	void SetPos(int x, int y);
	cObjWas m_Channel; //Ƶ��
	cText m_Name;  //����
	int m_LineNum;  //����
	void SetColor(ulong color){ for (int i = 0; i < sTextLine::MaxLine; i++)m_TextLineList[i].m_line.SetColor(color); }
	vector<sTextLine> m_TextLineList; //һ�����9��
	//                  
	bool SetFaceText(cWasFile* pChannel, string name, string tex, HFONT hFont, int LineWidth);
	bool SetFaceText(string tex, HFONT hFont, int LineWidth);
	sFaceText()
	{
		m_TextLineList.resize(sTextLine::MaxLine);
		m_Channel.m_bStatic = true;
		for (int i = 0; i < sTextLine::MaxLine; i++)
		{
			m_TextLineList[i].m_line.SetColor(RGB(255, 255, 255));
		}
	}
	int m_ShowStyle = 0;  //0��ʾ����ʾƵ�������� 1��ʾ����ʾ����  2��ʾȫ����ʾ  
	void SetTagColor(sColorTag& starttag, sColorTag& endtag);
};