#pragma  once
#include "_asert.h"

int GetDirection4(int x1, int y1, int xTarget, int yTarget);//ͨ��ԭ����յ�õ������ķ���
//int GetDirection8(int x1, int y1, int xTarget, int yTarget);//ͨ��ԭ����յ�õ������ķ���
int GetDirection8Ex(int predirection, int x1, int y1, int xTarget, int yTarget);
int GetReverseDirection(int Direction);                     //�õ��෴�ķ���
int GetRotateDirection(int nowDirection, bool directNum4=true, bool turn = 0); //���ڽ�ɫ��ת,�õ���һ����
bool isOn(int x, int y, RECT& rect);
inline bool isOn(int x, int y,int w,int h, int left,int top,int right,int bottom);
ulong GetPriceColor(INT64 Price);

int GetCharacterExp(int Lv); //ͨ���ȼ�������������
int GetPetExp(int Lv); //ͨ���ȼ�������������
int GetNormalFightExp(int OurLv, int EnemyLv, int NumOfPeople = 1);//������˫����
int GetMainSkillExp(int lv); //����ʦ�ż���ѧϰ���� 
int GetMainSkillMoney(int lv);//����ʦ�ż���ѧϰ��Ǯ
int   GetXiuLIanExp(int lv);
bool  CheckCross(RECT& rect1, RECT& rect2, RECT& outrect);  //��������ȡ����,���û�н���,����0
bool  CheckCross(RECT& rect1, RECT& rect2);
int   GetFrameIndex(int FrameMax, int NowFrame, int DirectionNum, int NowDirection);

bool StringToWString(const std::string &str, std::wstring &wstr);
int Direction8To4(int direction); 
void CoutPoint(float distance, float xstart, float ystart, float xend, float yend, float  &xout, float& yout);
float CoutDistance(float xstart, float ystart, float xend, float yend);
INT64 AddUpZero(INT64& target, const int num);//target����num ������С��0  ����target+num��ֵ   target����0 ���򷵻�0
int ReadInt(HANDLE& f);
int ReadCharNum(HANDLE& f,char& out);//��ȡ1�ֽ�,���������,����1,���򷵻�0 ������ļ���β,����2
int GetNumByChar(char data);
void SetINT(int num, int id);
bool CheckINT(int num, int id);
