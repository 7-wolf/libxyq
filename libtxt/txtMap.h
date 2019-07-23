#pragma once
#include "_txtinc.h"
#include "eMod.h"

ccc_txt_class_begin(txtMap);

txtMap();
enum class eD
{
	// Right Down 
	RD,
	// Left Down 
	LD,
	// Left Up 
	LU,
	// Right Up 
	RU,
	// Down 
	D,
	// Left
	L,
	// Up
	U,
	// Right
	R,
};


struct sNpc
{
	eMod mod;
	int x;
	int y;
	// ����
	eD direction;
	// ����
	std::string name;
	// ��ν
	std::string appellation;
	// �ű�
	std::string script;
};

// ����
struct sTransmit
{
	int x;
	int y;
	std::string name;
	int tx;
	int ty;
};

struct sMap
{
	int mapid = 0;
	ulong uid;
	std::string music;
	// npc��
	std::vector<sNpc> npcs;
	// ������
	std::vector<sTransmit> transmits;
};

private:
	void init(const std::string& mapname, int mapid, ulong uid, const std::string& music);
	void insert(int x, int y, const std::string& mapname, int tx, int ty);
	void insert(eMod e, int x, int y, eD direction, const std::string& name = "", const std::string& script = "", const std::string& appellation = "");



	void initCA();
	void initJY();
	void initAL();
	void initCS();
	void initCity();
	void initHome();
	void initMenpai();
	void initMaze();
	void initField();
	sNpc _npc;
	sTransmit _transMit;
	sMap* _map, _mapEmpty;

public:
static const char* _��ͼ����;
static const char* _��վ�ϰ�;
static const char* _��վۺ��;

static const char* _���ɴ��͵���;
static const char* _���ɴ�����;
static const char* _����ʦ��;

static const char* _���ɴ���;
static const char* _��������ָ��ʦ;
static const char* _���ɸ����ܹ�;

static const char* _ϵͳ�̵�;
static const char* _ר����;
static const char* _ϵͳװ������;
static const char* _ϵͳװ���Ź�;
static const char* _ϵͳװ���㼣;
static const char* _ϵͳװ������;
static const char* _ϵͳװ������;
static const char* _ϵͳװ��Ⱦɫ;

static const char* _�ֿ����Ա;
static const char* _������Ƕ�ֽ�;
static const char* _��ɫת��;
static const char* _��ͼ;

static const char* _������ҽ;
static const char* _Ǯׯ�ϰ�;
static const char* _�³���;
static const char* _������;
static const char* _��ظ׽��;
static const char* _װ��������;
static const char* _װ���չ���;

static const char* _�ҵ�ͥԺ�ܼ�;
static const char* _���ƹ�������;

ccc_txt_class_end(std::string, sMap);