#pragma once
#include "_asert.h"

// const int TOTAL_MAP_WIDTH = 350;
// const int TOTAL_MAP_HEIGHT = 350;
class cMyMap;
class cObj;
struct VecInt
{
	int x = 0;
	int y = 0;
};

struct AstartNode
{
	//�˽ڵ��ڶ��е�λ��
	int iHeapPosition = -1; 
	int iG = -1;
	int iH = -1;
	int iF = -1;
	//����Ƿ����ͨ��
	int iColor = -1;
	//����Ƿ��ڿ����б���
	int isOpen = 0; 
	VecInt father;

	int getF()
	{
		return iH + iG;
	}
};

// �����
class cHeap
{
public:
	cHeap();
	//�Ƴ����еĵ�һ��Ԫ��
	void removeFront(AstartNode**g_Map); 
	//���������Ԫ��
	void push_back(VecInt element, AstartNode**g_Map); 
	//��Fֵ�ı�ʱ�����¶�
	void newHeap(int position, AstartNode**g_Map);    
	int getSize();
	int getMinF(AstartNode**g_Map);
	bool empty();
	void clear();
	VecInt begin();
private:
	vector<VecInt> vecs;
};

class cFindPath
{
public:
	~cFindPath();
	bool InitMap();
	bool findAstart(cObj* pObj, int Xend, int Yend);
	// ��ͼ��ά�ڵ�����
	AstartNode** g_Map;
	//�����б�
	cHeap m_iOpenList; 
	// �õ�ͼ��ʼ����ά�ڵ�����
	void  setDataByMap(cMyMap* pMap);
	void  Free();

	int m_Width = 0;
	int m_Height = 0;
private:
	// ����Ƿ�������ȷ��·��
	bool m_isFind = false; 
};

class AES
{
public:
	AES(unsigned char* key);
	virtual ~AES();
	unsigned char* Cipher(unsigned char* input);
	unsigned char* InvCipher(unsigned char* input);
	void* Cipher(void* input, int length = 0);
	void* InvCipher(void* input, int length);

	void Cipher(char *input, char *output);
	void InvCipher(char *inut, char *output);

private:
	unsigned char Sbox[256];
	unsigned char InvSbox[256];
	unsigned char w[11][4][4];

	void KeyExpansion(unsigned char* key, unsigned char w[][4][4]);
	unsigned char FFmul(unsigned char a, unsigned char b);

	void SubBytes(unsigned char state[][4]);
	void ShiftRows(unsigned char state[][4]);
	void MixColumns(unsigned char state[][4]);
	void AddRoundKey(unsigned char state[][4], unsigned char k[][4]);

	void InvSubBytes(unsigned char state[][4]);
	void InvShiftRows(unsigned char state[][4]);
	void InvMixColumns(unsigned char state[][4]);

	int strToHex(const char *ch, char *hex);
	int hexToStr(const char *hex, char *ch);
	int ascillToValue(const char ch);
	char valueToHexCh(const int value);
	int getUCharLen(const unsigned char *uch);
	int strToUChar(const char *ch, unsigned char *uch);
	int ucharToStr(const unsigned char *uch, char *ch);
	int ucharToHex(const unsigned char *uch, char *hex);
	int hexToUChar(const char *hex, unsigned char *uch);
};