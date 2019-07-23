#pragma once
#include "_asert.h"
//������λ
struct sCanvasCube  
{
	static const int DEEP_20 = 20;
	int  PicNumOfPreFrame = 0;//ǰһ֡��ͼƬ��
	int  NeedReDraw = false;//�Ƿ���Ҫ�ػ�
	bool m_bCover�Ѹ�������;
	sCanvasCube()
	{
		for (int i = 0; i < DEEP_20; i++)
		{
			pPicList[i] = 0;
			PicType[i] = 0;  //0 CWFile  1 cObj 2 cText 3 cwfilep 4 objfather
			ShowMode[i] = 0;
		}
	}

#pragma region 

//	RECT rect;//λ��
//	uchar* m_ShowData;
	cObjWasFather m_Data;
	//�ڻ����еĵ�λ, �����20��.����20���Ļ�...��˵
	void* pPicList[DEEP_20];
	int  PicType[DEEP_20];  //0 CWFile  1 cObj 2 cText 3 cwfilep 4 objfather

	int  ShowMode[DEEP_20];
	int  PicNumOfCurrFrame = 0;   //��ǰ֡��ͼƬ��
	
	bool  PreCover=false;//ǰһ֡�Ƿ��и���

	bool Add(cWasFile* p, int showmode, bool bMove, bool bCover, bool bChange);
	bool Add(cObjWasFather* p, int showmode, bool bMove, bool bCover);
	bool Add(cText* p, bool bMove);
	bool Add(cObjWas* p, int showmode, bool bMove, bool bCover, bool bChange);
	bool CheckNum(bool bCover);
	
	RECT m_Rect;

#pragma endregion 

};
//���� ��������
class cCanvas
{
public:
	int  m_Time=0;
	bool Init();
	bool Add(cWasFile* pPic, int showmode, bool bCover = false);
	bool Add(cText* pTex);
	bool Add(cObjWasFather* pObj, int showmode, bool bCover = false);
	bool Add(cObjWas* p, int showmode  ,  bool bCover=false);

	//HDC m_MemDC; //��ʾ����ʱ���ڹ���
	array<sCanvasCube, 450> m_CanvasCube/*[300]*/;
	bool Show();
	bool SetRedraw(const RECT& rect);
	void SetRedrawAll(bool ball = true);
	bool m_NeedShowMap = false;

	//HDC m_hdc;
	~cCanvas();
	
	
	
private:
	bool Free();


	void SwapBuf();
	HPEN hPen;


	bool m_bInit = false;
	
};
