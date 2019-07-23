#pragma once
#include "_inc.h"

class uiManager;
namespace ccu
{
	uiManager* getManager();
	void setManager(uiManager* ui);
}

class uiAccelator;
class uiChannel;
class cDialog;
class uiDye;
// class uiFriend;
class uiFoot;
class uiFoot2;
class uiHeader;
class uiItem;
class uiJob;
class uiLeaderTop;
class uiLearn;
class uiMenu;
class uiPet;
class uiSee;
class uiShichen;
class uiShop;
class uiSkill;
class uiSkiSelect;
class uiSmap;
class uiState;
class uiWorld;
class uiXiangRui;
class uiZz;
// ui������
class uiManager : public cNode
{
public:
	CREATE_FUNC(uiManager);

protected:
	virtual bool init();

public:

	// �ӵ㷽��
// 	uiAddpoint* getAddpoint(){ return _addpoint; }
// 	uiAddpoint* _addpoint = nullptr;


	// ��ݼ�
	uiAccelator* getAccelator(){ return _accelator; }
	uiAccelator* _accelator = nullptr;

	// �ӵ㷽��
// 	uiInputNO* getInputNO() { return _inputNO; }
// 	uiInputNO* _inputNO = nullptr;


 
	// ���Ƶ��(Ƶ������, ����, �ı�)
	// #0~#119 ����
	// #W #Y #R #G #B #M #O ��ɫ
	void addChannel(eChannel e, const std::string& name, const std::string& text);
	void addChannel(const std::string& text);
	uiChannel* getChannel() { return _channel; }
	uiChannel* _channel = nullptr;
	uiChannel* _chat = nullptr;

// 	// �ù��(���״̬)
// 	void setCursor(eCursor e);
// 	// ȡ���״̬
// 	const eCursor& getCursor();
// 	uiCursor* _cursor = nullptr;
// 
// 
// 	// ����
// 	uiDazao* getDazao(){ return _dazao; }
// 	uiDazao* _dazao = nullptr;
// 
	// ����
	cSprite* getDesc(){ return _desc; }
	cSprite* _desc = nullptr;

	// �Ի�
	cDialog* getDialog(){ return _dialog; }
	cDialog* _dialog = nullptr;

	// Ⱦɫ
	uiDye* geDye() { return _dye; }
	uiDye* _dye = nullptr;

	// ����
// 	uiFriend* getFriend() { return _friend; }
// 	uiFriend* _friend = nullptr;

	// վ���㼣
	uiFoot* getFoot(){ return _foot; }
	uiFoot* _foot = nullptr;

	// �㼣
	uiFoot2* getFoot2(){ return _foot2; }
	uiFoot2* _foot2 = nullptr;

	// ���Ͻǵ�ͷ���Ѫ��
	uiHeader* getHeader(bool pet) { return pet ? _headerPet : _headerRole; }
	uiHeader* _headerRole = nullptr;
	uiHeader* _headerPet = nullptr;

	//��Ʒ
	uiItem* getItem() { return _item; }
	uiItem* _item = nullptr;

	// �������(����, ����)
	// �ظ��ı���ᱻ��Ϊ��������
	void addJob(const std::string& title, const std::string& text);
	uiJob* _job = nullptr;

	// �ӳ�����
	uiLeaderTop* getLeaderTop() { return _leaderTop; }
	uiLeaderTop* _leaderTop = nullptr;

	// ���ɼ���ѧϰ
	uiLearn* getLearnBp(){ return _learnBp; }
	uiLearn* _learnBp = nullptr;

	// ���ɼ���ѧϰ
	uiLearn* getLearnMp(){ return _learnMp; }
	uiLearn* _learnMp = nullptr;

	// �˵� �����·���һ��ͼ��
	uiMenu* getMenu(){ return _menu; }
	uiMenu* _menu = nullptr;

	// ����
	uiPet* getPet(){ return _pet; }
	uiPet* _pet = nullptr;

	// �鿴
	uiSee* getSee(){ return _see; }
	uiSee* _see = nullptr;

	// ʱ�� ���Ͻ�
	uiShichen* getShichen(){ return _shichen; }
	uiShichen* _shichen = nullptr;

	// ����
	uiShop* getShop(){ return _shop; }
	uiShop* _shop = nullptr;

	// ���＼��
	uiSkill* getSkill(){ return _skill; }
	uiSkill* _skill = nullptr;

	// ����ѡ��
	uiSkiSelect* getSkiSelect(){ return _skillSelect; }
	uiSkiSelect* _skillSelect = nullptr;

 	// С��ͼ
	uiSmap* getSmap(){ return _smap; }
	uiSmap* _smap = nullptr;

	// ����״̬
	uiState* getState(){ return _state; }
	uiState* _state = nullptr;

	// �����ʾ(�ı�, ͣ��:��)
	void toast(const std::string& text, float second = 5);

	// �����ͼ
	uiWorld* getWorld(){ return _world; }
	uiWorld* _world = nullptr;

	// ����
	uiXiangRui* getXiangRui(){ return _xiangrui; }
	uiXiangRui* _xiangrui = nullptr;

	// ����
	uiZz* getZz() { return _zz; }
	uiZz* _zz = nullptr;



	void setBattle(bool battle);
};