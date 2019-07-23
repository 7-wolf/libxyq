#pragma once
#include "_objinc.h"

class cCanvas;
class cText :public cObjWasFather
{
public:
	//	HPEN m_hPen;
	HFONT m_hFont;
	void SetColor(ulong color);
	void SetString(char* str);
	void SetString(string str);
	void SetString(string str, ulong color);
	void SetString(int str);
	void SetString(INT64 str);
	void UpdateData();
	//0 ����,1 ���� 2 ���
	void SetStyle(int style){ m_Style = style; }
	string GetString(){ return m_Text; }
	bool DrawAlphaEx(uchar* Pic, RECT& rect, cMap* pMap);
	void Show(cCanvas* pCanvas);
	cText();
	~cText();
	void SetBackColor(ulong color);
	void LockWidth(int Width){ m_MaxWidth = Width; }
	void CountSize(SIZE& size);
	void SetXCenter(int xCenter){ m_xCenter = xCenter; };//�������ֵ�����
	bool m_bShowOnScreen = true;
	void UpdateXCenter(){ m_x = m_xCenter - m_Width / 2; };
	bool m_bBold = false;
	void SetTagColor(int starttag, int endtag, ulong color);
	void SetTransparentColor(int startpos, int endpos, ulong color);
	void UnTransparentColor(int startpos, int endpos, ulong transparentcolor);
	//ͼƬ��ʾҪ8�ֽڶ���,����m_Width�����ֵ�Ǵ��ڵ�����ʾ��ȵ�.m_tuewidth�������ǰ�Ŀ��
	int  GetWidth(){ return m_tuewidth; }
	void SetTime(int time){ m_time = time; m_NeedShow = true; }
private:
	int m_tuewidth;
	ulong m_color = 0;
	ulong m_BacColor = 0;
	string m_Text;
	int m_Style = 0;
	uchar* m_pData2 = 0;
	int m_Size = 0;
	int m_MemSize2 = 0;;
	int m_MemSize = 0;
	int m_MaxWidth = 0;
	int m_xCenter = 0;
	int m_time = 0;
	void ChangeColor(ulong originalcolor, ulong outcolor);
};