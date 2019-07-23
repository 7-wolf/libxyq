#pragma once
#include "_global.h"

class cDescribe;
class ItemManager //��Ʒ������
{
public:
	void GetIDlistByLv(vector<int>& outlist,int type, int lv);
	int GetIDByLv(int type, int lv);//ͨ���ȼ�����õ���Ʒ��ID
	int GetlvByID(int type, int id);//ͨ��ID�õ���Ʒ�ȼ�
	bool m_bAddHp=0;
	bool m_bAddMp=0;
	bool m_bAddCp=0;
	bool m_bToAll=0;
	bool AddHp(int Num, int TargetID, int Percent = 0);
	// MAxHp * Num% <= Num*Percent
	bool AddHpHurt(int Num, int TargetID, int Percent = 0);
	bool AddHp(int Num, cPropertyData* pdata, int Percent = 0);
	// MAxHp2 * Num% <= Num*Percent
	bool AddHpHurt(int Num, cPropertyData* pdata, int Percent = 0);
	bool removeBuff(int Type, int TargetID,int ReMoveAll);//��ĳ�־����״̬   ,���һ��������ʾ�Ƿ��Ƴ�����ͬ��״̬
	
	bool AddMp(int Num, int TargetID, int Percent = 0);
	bool AddCp(int Num, int TargetID, int Percent = 0);
	bool relife(int Num, int TargetID, int Percent = 0);//����

	bool AddFunc(bool(ItemManager::*AddSomething)(int, int, int), int Num, int TargetID, int Percent = 0);
	int  m_hp;//������¼�ϴ�ʹ����Ʒ�ӵ�HP
	//leveup��ʾ�����ټ�
//	void  SetFabaoEffect(cPcData& data, int leveup, eFaBao ID);

	sItem* GetItem(int type, int id){ return &m_ItemList[type][id]; }
	array<vector<sItem>, 45> m_ItemList; 
	
	array<sZuoQiZhuangShi, 24> m_ZuoQiZhuangShiList;
	//sEquipData m_EquipList[7];  //װ���б�
	bool Init();//�����б�

	array<vector<sJiaJuData>, 4> m_JiaJuData;

	//���޾����з���,���㽱��
	vector<int> m_LShouJueList;
	vector<int> m_HShouJueList;
	//
	bool UseItem22ҩƷ(sItem2* pItem,int ObjId);
	bool UseItem23���(sItem2* pItem, int ObjId);
	bool UseItem24����(sItem2* pItem, int ObjId);
	bool UseItem26(sItem2* pCard, int ObjId);
	bool UseItem27����(sItem2* pItem, int ObjId, int* num=0);
	bool UseItem28(sItem2* pItem, int ObjId);
	bool UseJiaJu(sItem2* pItem);
	bool UseItem(sItem2* pItem, int ObjId,int* num=0);
	
	

	bool FillProperty(int CharID, ItemProPerty type);

	int  GetCheapestItem�Ҽ���Ѫ(int CharID, ItemProPerty Type);//Ѱ������˵���Ʒ
	cWasFile m_MagicAddHP;
	cWasFile m_MagicAddMP;
	cWasFile m_MagicAddHPMP;
	vector<string> m_ItemTypeName;

	vector<sWeaponData> m_pWeaponList2[18][11];//15������
	sWeaponData* GetWeaponList(int charid, int weaponid, int type);
	bool SetItemDescribe(int x, int y,cDescribe& pDescribe, sItem2* pItem);
//	void AutoItemProperty(sItem2* item, cPCData* pc, int dustbin = 0);
//	void AutoFuShi(sItem2* item, int lv, eMengPai mengpaiid);
//	void AutoItemProperty(sItem2* item, cCharacter* pc = 0, int dustbin = 0); //�Զ�����Ʒ�������, ��������������
	vector<int> AutoItemPropertyWeapon(sItem2* item, bool isNormal);
	vector<int> AutoItemPropertyEquipButWeapon(sItem2* item, bool isNormal);
	vector<int> AutoItemPropertyBB(sItem2* item);
	void AutoItemProperty(sItem2* item, bool isNormalEquip = true);
//	void AutoItemProperty(sItem2* item, int Luck, int dustbin);
//	void AutoItemProperty����(sItem2* item, int Luck);
//	void AutoItemPropertyװ��(vector<int>& prop,  int num, int Luck, int Offset);
	bool XiangQian(sItem2& equip, sItem2& gem);
	void SetUpQiangHua(vector<int>& prop,int protype, int num, bool isBB);
	void SetUpBaoShi(vector<int>& pro, int baoshiid, int lv, bool isBB);
	sItem2* m_pNowItem = 0;
private:
	
	int m_numtext = 0;
	array<string, 20> m_text;
	array<ulong, 20> m_Color;

	string MakePropString(vector<int>& prop, int pos);
	string getProPertyString(int prop);
	void  MakePropString2(sItem2* item);
	void  makePropStringEquip(sItem2* item);
	bool m_bInit = false;
	bool Detoxify1(int Type, int TargetID);
	bool LoadItem1(string path);  //  
	bool LoadFaBao(string path);
	bool LoadShouJue(string path);
	bool LoadWeapon(string path);
	bool LoadZuoqiZhuangShi(string path);
	bool LoadJiaJu(string path);
	void LoadJiaJuCube(ifstream& File,int type);
};
