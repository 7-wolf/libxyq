#pragma once
#include "_global.h"

struct sMapselect
{
	ulong m_SmallMap;
	string m_Name;
	vector<int> m_x, m_y;
	vector<int> m_xorg, m_yorg;
	int m_num;
	int m_Height;
	float m_bili;
};
//class cCanvas;
class cInterfaceItem :public cInterfaceFather
{
public:

	cDescribe m_Describe;
	void  SetEquipSpecial(sItem2& ProPerty, int ID);

	void  SetEquipSpecial2(sItem2& ProPerty, int ID);//������Ч
	void  SetHaveZuoQi(bool b);
	void  SetEquipZuoQiZhuangShi(bool b);

	bool Move(int x, int y);
	int   m_ItemPage = 0;

	bool   CheckZuoQi(cPcData* pc = nullptr);
	cWasFile m_EquipBack;  //��װ����װ��ʱ�ı���


	cWasFile m_BigHead;
	bool   m_bXianJin;
	cWasFile m_XianJin;   //�ֽ�ť

	bool   UseItem(int ID, cPcData& pcData);
	bool   UseItem(int ID, int TargetID);
	RECT m_rectEquip;
	RECT m_rectPetEquip;
	RECT m_rectItem;

	bool   m_SwapMode;
	cWasFile m_SelectMark;
	cWasFile m_MouseOnMark;
	vector<cObjWas> m_EquipBackP;
	vector<cObjWas> m_PetEquipBackP;
	vector<cWasFile> m_ItemHead;
	vector<cWasFile> m_EquipHead;//��ɫ���ٻ���װ��
	vector<cWasFile> m_PetEquipHead;
	cWasFile m_SwapItemSelect;
	//��ɫװ��ģʽ
	cWasFile m_BigBigHead;
	cWasFile m_Headback;
	//�ٻ���װ��ģʽ
	cWasFile m_PetHeadback;
	cWasFile m_ButtonPetMode;
	cText m_tButtonPetMode;
	cPet* pPet;
	cText m_PetName;
	//
	ulong m_PetID;
	cWasFile m_Item;
	cWasFile m_ItemButton;
	cWasFile m_ItemButton2;
	cWasFile m_ItemButton3;
	cWasFile m_ItemButton4;
	cWasFile m_ZuoQiB;
	cWasFile m_ZuoQiZhuangShiB;
	ulong m_BackID;
	ulong m_FabaoID;
	cWasFile m_FabaoButton;
	ulong m_ZuoQiID;
	int  m_SwapID;
	bool SetItemPage(int page);
	bool SwapItem(const int ID, const int IDTarget, cPcData* pcdata = 0);
	bool GetItem(int CharID, sItem2* pItem);  //�õ���Ʒ
	void OnOff(bool NeedShow = false);
	bool Overlay(int Pos, int CharID, sItem2* item);//������Ʒ
	int  FindSame(int itemID, int itemType, int StartPos = 9, int EndPos = 28, int PcID = 2); //Ѱ�ҿɵ�����Ʒ
	int  FindIdle(int StartPos, int EndPos, cPcData& pcdata);//Ѱ�ҿո� 
	int  FindIdle(int StartPos = 0, int EndPos = 60, int PcID = 0);//Ѱ�ҿո� 
	bool Add(int Pos, int CharID, sItem2* item);//�ڿ�λ�ü���Ʒ
	bool Add(int Pos, cPcData& pcData, sItem2* item);//�ڿ�λ�ü���Ʒ
	void Set(int Num){ m_Select = Num; };
	bool ProcessInput();
	bool CheckL();
	bool CheckRB();
	void UpdateData();
	bool UpDateItemDate(cDescribe& Describe);//������Ʒ��Ϣ
	bool UpDateItemDate(cDescribe& Describe, sItem2* pItem);
	bool Init();
	bool Show(cCanvas* pCanvas);
	bool LoadSmallMap(int ID);
	bool SetXianJin(bool b);
	~cInterfaceItem();
	cText m_TCunYingN;
	cText m_TXianJin;
	cText m_TXianJinN;
	cText m_TZuoQi;
	cText m_TZhuangShi;
	array<cText, 20> m_TItemNum;

	int m_NowSelect;
	//���з�
	cWasFile m_WorldMap;
	cWasFile m_MapSelect;
	int    m_NumMapSelect;
	int    m_Mode;
	array<RECT, 7>   m_MapRect;
	array<ulong, 7>  m_MapID;

	//������
	bool ProcessSelectMap();
	bool ProcessSelectMap2();
	bool ProcessSelectMapMoon();
	cWasFile m_MapBack;
	cText m_MousePos;
	cWasFile m_MousePosBack;
	void UpdateMousePosBack();
	//string  m_WorldName;
	cWasFile m_PathPoint;
	array<cObjWas, 60> m_PathPointp;//���30��
	sMapselect*  m_pMapSelect = 0;
	array<sMapselect, 5> m_sMapSelect;
	bool ShowSelectMap();
	bool ShowSelectMap2();
	void InitMode(int id);
	int* pItemnum;
private:
	cObj m_Obj;
	bool m_bInit = false;
	bool  m_bCharHaveZuoQi;
	void  UpdateItemNum(int ID);
};