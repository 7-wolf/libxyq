#pragma once
#include "_asert.h"

class cBmp    //�ϰ��ĵ�ͼ
{
public:
	cBmp(){ m_pBmp = 0;};
	~cBmp();
	bool Load(char* name);
	bool isFold(int x, int y);
	bool Free();
	uchar* m_pBmp;
	int GetHeight(){ return m_Height; }
	int GetWidth(){ return m_Width; }
	string oldmap = "";	
	vector<vector<bool>> _fold2s;
//	MapReader* _reader = nullptr;
//private:
	int m_Width;
	int m_Height;
	int m_capacity=0;
};

struct SMaskInfo
{
	int		startX;
	int		startY;
	int		width;
	int		height;
	int		mask_size;	// mask���ݴ�С
};
//mask������
struct sMASKRect
{
	long x;
	long y;
	long w;
	long h;
	//long  Index;
};

class cMap
{
public:
	//
	uchar* m_pTempBuffer = 0;
	int m_TempBufferNum = 0;
	uchar* m_pMapJpgData = 0;
	int   m_MapJpgDataSize = 0;
	uchar* m_pUnitNData = 0;
	int  m_UnitNDataSize = 0;
	vector<int>  m_MaskIDList;
	void CountMaskList();//������Ļ�е�mask
	void xMove(int x);
	void yMove(int y);
	int m_MapID = -1;
	int m_AddSpeed = 24;
	int m_xPreSpeed = 0;
	int m_yPreSpeed = 0;
	//������ͼ
	int m_LockMap;
	bool m_ReturnMap;
	int m_xLock;
	int m_yLock;

	BITMAPINFO * m_pBmpinfo;
	int  m_NowMapNum;
	bool SetCenter(float xHero, float yHero);
	bool Follow(cObj* pObj);
	//void FollowAlong(int speed,int xtarget,int ytarget);
	//void FollowStop(int xHero, int yHero);

	bool m_bMove;  //�����Ƿ��ƶ�
	ifstream m_File;
	ifstream m_File2;//��������߳�����,��һ�������߳�����
	uchar**  m_pBitmap;
	vector<int> m_BitmapID;

	ushort*	m_pTexture;//[320*240];	// ARGB1555��ʽ����

	HBITMAP DIBtoDDB(ushort* data, HDC dc);
	void  ScreenToWorld(int x, int y, int& xOut, int& yOut);
	void  WorldToScreen(int x, int y, int& xOut, int& yOut);
	bool  Load(char* FullPath, int mapid);
	bool Show(uchar* pPic, const RECT& rect);
	inline	void CountAlpha(WPixel& color1, WPixel& color2, uchar* pPic, int index2, int time);
	bool  MoveMap();

	bool initHeheda();
	
	void GetPoint();
	cMap();
	~cMap();
	struct SMap_Header
	{
		int				flag;		// 1296126040,��"XPAM"
		unsigned int	map_width;
		unsigned int	map_height;
	};
	struct SMaskHead
	{
		unsigned int	unknown;
		int				mask_num;
	};
	struct SBlockInfo
	{
		unsigned int	UnitN;	// δ֪���ݴ�С
		unsigned int	flag;
		unsigned int	size;
	};

	static unsigned int WINAPI ThreadProc(
		_In_  LPVOID lpParameter
		);
	int	  m_MaskNum;
	uchar** m_pMaskDataDec;
	int*    m_align_width;



	HANDLE m_hThread;
	MySleep *_mySleep = nullptr;
	bool m_bLoadReady;
	bool m_bLoadReady2 =  true;
	//��ͼ��ƫ������
	uint* m_pBlockOffset;
	//mask��ƫ������
	uint* m_pMaskDataOffset;
	//


	//��ͼ����
	int   m_NumBlock;
	int   m_HeightNum;
	int   m_WidthNum;
	//��ͼ��С
	int   m_Width;
	int	  m_Height;

	sMASKRect* m_pMaskRect;

	//�ж����������Ƿ��ཻ
	bool isInRect(int x1, int y1, int w1, int h1, int x, int y, int w, int h);
	int	DecompressMask(void* in, void* out);

	// ��ͼ������ *20 *20
	float m_xCenter;
	float m_yCenter;
	//��ǰ����ͼ�� /320  /240
	int m_xCenterNum = -1;
	int m_yCenterNum = -1;
	//��ͼ�������ڵ�ǰͼ���ƫ�� %320  %240
	int m_xCenterOffset;
	int m_yCenterOffset;
	//
	int GetXCenter(){ return (int)m_xCenter; }
	int GetYCenter(){ return (int)m_yCenter; }
	void Free();

//	MapReader *_reader = nullptr;
private:

	void WriteMapPixel(ushort* pBmp16, int width, int height, int pitch);
	//��ȡ��ͼ��
	void ReadBlock(int block_offset, ushort* map);
	void ReadMask(int offset, int mask_index);
	void Mask(int x, int y, int Width, int Height, int offset, int mask_index, uchar* lpback);

	ushort*			m_pMapBmp;				// ARGB1555��ʽ����

	//JPEG���ݴ�����
	uchar*	JpgHandler(uchar* Buffer, int inSize, uint* outSize);

	//��ѹJPEG
	void ByteSwap(ushort& value)
	{
		ushort tempvalue = value >> 8;
		value = (value << 8) | tempvalue;
	}
};