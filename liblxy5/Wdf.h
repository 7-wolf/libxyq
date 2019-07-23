#pragma once
#include "_asert.h"

//WDF�ļ�ͷ,��¼���ļ�������(WDF),���ļ�������,���ļ��б��λ��
struct WPixel
{
	union
	{
		ushort color;								// 16bit �߲�
		struct
		{
			ushort blue : 5;						// 5bit ��ɫ
			ushort green : 6;						// 6bit ��ɫ
			ushort red : 5;							// 5bit ��ɫ
		};
		struct
		{
			uchar l;
			uchar h;
		};
	};
	WPixel(){};
	// 5 5 5 ��ʽת 5 6 5
	void operator =(ushort color);
	void operator =(ulong color1);
	WPixel(int r, int g, int b) : red(r >> 3), green(g >> 2), blue(b >> 3) {}
};



struct WDataFileHeader {
	ulong id;
	int number;
	unsigned offset;
};
//���ļ���ID λ�� ��С 
struct WDataFileIndex {
	ulong uid;
	ulong offset;
	ulong size;
	ulong space;
};

//was�ļ�ͷ
struct WASFILEHEADER{
	ushort wastitle;			//�ļ���ʾ SP
	ushort szHheard;			//�ļ�ͷ��С
	ushort nDirection;		//�����ķ�����
	ushort nFrame;			//ÿ�������֡��
	ushort nWidth;			//�����Ŀ��
	ushort nHeigh;			//�����ĸ߶�
	short xCenter;			//���������� X
	short yCenter;			//���������� Y
};

//����ͷ
struct DATEHEARD
{
	int FramX;				//ͼƬ���� X
	int FramY;				//ͼƬ���� Y
	int Width;				//ͼƬ���
	int Height;				//ͼƬ�߶�
};

class CWdf
{
public:
	CWdf(){ m_pIndex = 0; }
	~CWdf(){ Free(); }
	bool Free();
	bool Open(const char* FileName);
	std::string m_Name;
	WDataFileIndex* SearchFile(ulong id);
	ifstream* GetFileHandle() { return &m_File; }
	WDataFileIndex *m_pIndex;

	uint m_Number;
private:
	ifstream m_File;
};

// 
// #define tile_num(x,y) ((y)*map_w+(x))  //�� x,y ����ת��Ϊ��ͼ�Ͽ�ı��
// #define tile_x(n) ((n)%map_w)          //�ɿ��ŵó� x,y ����
// #define tile_y(n) ((n)/map_w)