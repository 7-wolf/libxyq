#include "txtNpc.h"

ccc_txt_instance_cpp(txtNpc);

txtNpc::txtNpc()
{
	sNpc npc;
#define ccc_txt_insert_npc(_STAND_, _WALK_, _DIALOG_, _MOD_, _NAME_)\
	npc.stand = _STAND_;\
	npc.walk = _WALK_;\
	npc.dialog = _DIALOG_;\
	npc.name = _NAME_;\
	_tables.insert(std::make_pair(_MOD_, npc))

	ccc_txt_insert_npc(0xD5A91213, 0x2AF8E37F, 0x2B43EB3E, eMod::���׹�ʦ, "���׹�ʦ");
	ccc_txt_insert_npc(0xC82770E2, 0x3101E857, 0x2E797D72, eMod::�����Ǿ�, "�����Ǿ�" );
	ccc_txt_insert_npc(0xDA498AD2, 0xBB95D714, 0x49CAFCC2, eMod::��ʯ����, "��ʯ����" );
	ccc_txt_insert_npc(0x31684231, 0x23021644, 0x49F4803B, eMod::���������, "���������" );
	ccc_txt_insert_npc(0xFF25D8BA, 0x879921C3, 0x0E756971, eMod::������, "������" );
	ccc_txt_insert_npc(0xAF20E948, 0xA3F4919E, 0x641650F0, eMod::�̷���, "�̷���" );
	ccc_txt_insert_npc(0x1AA01951, 0x5DFA3BB9, 0xE3510EDC, eMod::��ţ��, "��ţ��" );
	ccc_txt_insert_npc(0x56738B45, 0x6617CE07, 0x7530532F, eMod::���й�, "���й�" );
	ccc_txt_insert_npc(0x70357245, 0x3790FE0A, 0x2FB1A687, eMod::�仨, "�仨" );
	ccc_txt_insert_npc(0x64E5C547, 0xBE35EE06, 0x30E999AA, eMod::�����ϰ�, "�����ϰ�" );
	ccc_txt_insert_npc(0xC888F0C3, 0x6A957B1B, 0x13765D73, eMod::�İ���, "�İ���" );
	ccc_txt_insert_npc(0x1D232BFA, 0x5DBA1EE4, 0x67B62ED5, eMod::����ξ, "����ξ" );
	ccc_txt_insert_npc(0x0734C9CA, 0xB4DB94F0, 0xBF413F3E, eMod::������, "������" );
	ccc_txt_insert_npc(0x2EB42770, 0x4C62D25F, 0x340D62DD, eMod::��װ���ϰ�, "��װ���ϰ�" );
	ccc_txt_insert_npc(0x015B95C2, 0xF771C268, 0xDD03EB6C, eMod::��ʯ����, "��ʯ����" );
	ccc_txt_insert_npc(0x767095C2, 0x3792B5F3, 0xE2933947, eMod::�����չ���, "�����չ���" );
	ccc_txt_insert_npc(0x3F91DC55, 0x521BFFA4, 0x6C29EF22, eMod::��ʦү, "��ʦү" );
	ccc_txt_insert_npc(0x732407B7, 0x44801CB6, 0x758F9E60, eMod::�η�, "�η�" );
	ccc_txt_insert_npc(0xAE82050D, 0x8DB0C74C, 0x77397968, eMod::��������, "��������" );
	ccc_txt_insert_npc(0x2BB71D40, 0xF21DAB4A, 0x59EAA01D, eMod::��ʥ��, "��ʥ��" );
	ccc_txt_insert_npc(0x21EAE195, 0xA6169D14, 0x0A0BC629, eMod::�մȷ���, "�մȷ���" );
	ccc_txt_insert_npc(0xD6C941FC, 0x2094134A, 0x06AF31BA, eMod::����ͷ, "����ͷ" );
	ccc_txt_insert_npc(0x165AEB4C, 0x464E819A, 0x00F98F61, eMod::�������ϰ�, "�������ϰ�" );
	ccc_txt_insert_npc(0xDCF6A150, 0x7C3B4FB7, 0x0D9BE63F, eMod::�׺���, "�׺���" );
	ccc_txt_insert_npc(0xB28A3DB1, 0xBE8A3EC9, 0xBBA4ED07, eMod::������, "������" );
	ccc_txt_insert_npc(0xFD419E2C, 0xF3B31502, 0xEB08674C, eMod::���ϵ�, "���ϵ�" );
	ccc_txt_insert_npc(0x7792B6DA, 0xDB11C815, 0x7F84C945, eMod::������, "������" );
	ccc_txt_insert_npc(0x67C56BF0, 0x5B5B600B, 0xBFC714C2, eMod::³��, "³��" );
	ccc_txt_insert_npc(0xD7A74DE2, 0xF846C711, 0x1C9CBA0C, eMod::�ϴ���, "�ϴ���" );
	ccc_txt_insert_npc(0xB4DA85C7, 0xBE41583A, 0x304E494E, eMod::�ϼ�����, "�ϼ�����" );
	ccc_txt_insert_npc(0xBC6BD1E8, 0x8736E40D, 0xEB321EDA, eMod::�Է�, "�Է�" );
	ccc_txt_insert_npc(0x4D41D5D2, 0x8A05EDF0, 0x522601D6, eMod::����, "����" );
	ccc_txt_insert_npc(0xF4848781, 0x7376DB37, 0x1E1F098C, eMod::���, "���" );
	ccc_txt_insert_npc(0xBF882D3F, 0x97CDC297, 0x93EC2C89, eMod::�, "�" );
	ccc_txt_insert_npc(0x3599D5C3, 0x16505471, 0xBADB9340, eMod::̫���Ͼ�, "̫���Ͼ�" );
	ccc_txt_insert_npc(0x2C2259AB, 0xB0250DEE, 0x74D5FF09, eMod::����ɩ, "����ɩ" );
	ccc_txt_insert_npc(0x4ED41E93, 0x3DD602B8, 0x61117204, eMod::��Ԫ��, "��Ԫ��" );
	ccc_txt_insert_npc(0x53D7FFCA, 0x241D8F39, 0x37075308, eMod::���ϵ��ϰ�, "���ϵ��ϰ�" );
	ccc_txt_insert_npc(0x5641D9BE, 0x9D836B06, 0xC942664B, eMod::Сľ��, "Сľ��" );
	ccc_txt_insert_npc(0x1BB1AF36, 0xA69EAB9D, 0x421D6F27, eMod::С�Һ�, "С�Һ�" );
	ccc_txt_insert_npc(0xD97E30F0, 0x6FBF6A9F, 0x8C639246, eMod::�����, "�����" );
	ccc_txt_insert_npc(0xCA3334FF, 0x5745E837, 0x3E2EE17D, eMod::̫�׽���, "̫�׽���" );
	ccc_txt_insert_npc(0xE0DC6D93, 0xC3627242, 0xC2A7F86E, eMod::ҩ���ϰ�, "ҩ���ϰ�" );
	ccc_txt_insert_npc(0x72EEB38D, 0x6F6C1A7C, 0x792EA858, eMod::��վ�ϰ�, "��վ�ϰ�" );
	ccc_txt_insert_npc(0xA33DB160, 0x20A19816, 0xA5E5DB73, eMod::����, "����" );
	ccc_txt_insert_npc(0xA9F796EA, 0xF637E75A, 0xEF00905F, eMod::���ϲ�, "���ϲ�" );
	ccc_txt_insert_npc(0x5D14A411, 0x4E0B8DAC, 0x5DA91845, eMod::����ͷ, "����ͷ" );
	ccc_txt_insert_npc(0x7555A8D0, 0x4468668F, 0x1FC0FCAC, eMod::���޵�, "���޵�" );
	ccc_txt_insert_npc(0x40B1BCC3, 0x8AC693A9, 0xF81B16C1, eMod::�Բ�ͷ, "�Բ�ͷ" );

//	{ 0xD02A9BB5, 0x4D0AAF3C, 0xDA66E6C8, eMod::֣��ͷ, "֣��ͷ" );
	ccc_txt_insert_npc(0xDAC84F94, 0x39195BC3, 0x00000000, eMod::��Ф��, "��Ф��" );

	ccc_txt_insert_npc(0xF1E86993, 0x39A1E40F, 0x3655FC65, eMod::��ظ, "��ظ" );
	ccc_txt_insert_npc(0x06F1DE7D, 0x37ADE1CA, 0x88CA9EC4, eMod::���Ի�, "���Ի�" );
	ccc_txt_insert_npc(0x589A2894, 0x7ECE7DB2, 0x1CA66D04, eMod::����Уξ, "����Уξ" );

//	{ 0xF5D47E2E, 0x9957A256, 0xDA313059, eMod::�׾���, "�׾���" );
	ccc_txt_insert_npc(0x6644A046, 0x350A49B8, 0x00000000, eMod::��Фţ, "��Фţ" );

	ccc_txt_insert_npc(0x2E305A78, 0x61A8F3FF, 0x13343683, eMod::����ʮ��, "����ʮ��" );
	ccc_txt_insert_npc(0x50355C48, 0x403A153E, 0x2478FFCE, eMod::������, "������" );
	ccc_txt_insert_npc(0x228D340F, 0x2059CBB0, 0x425EE9E7, eMod::������, "������" );
	ccc_txt_insert_npc(0xAFA62A72, 0xCB62E343, 0x0167D818, eMod::����, "����" );
	ccc_txt_insert_npc(0xD0A9859B, 0xC5E98CA8, 0x0AF9D765, eMod::��, "��" );
	ccc_txt_insert_npc(0x5903D418, 0x259EC5A7, 0x0D24234C, eMod::��߸, "��߸" );
	ccc_txt_insert_npc(0x6D96A509, 0x1A8279CA, 0x221DF8A8, eMod::������, "������" );
	ccc_txt_insert_npc(0xEB00DE5F, 0x3C7DB1FD, 0x23DB547E, eMod::��ʴ��, "��ʴ��" );
	ccc_txt_insert_npc(0x837D7776, 0x67B85348, 0x2EAD989A, eMod::���޳�, "���޳�" );
	ccc_txt_insert_npc(0x8783CF82, 0xAF2386A2, 0x310CBA1A, eMod::�Ƶ��ϰ�, "�Ƶ��ϰ�" );
	ccc_txt_insert_npc(0x3112FBE1, 0x0E34A5A3, 0x34D77690, eMod::�ܼ�, "�ܼ�" );
	ccc_txt_insert_npc(0x738F33AF, 0x9A5FA693, 0x51058D2C, eMod::��������, "��������" );
	ccc_txt_insert_npc(0x81895D83, 0x6E805BF9, 0x52C6D4DB, eMod::����ɽ����, "����ɽ����" );
// 19 �ظ����ظ���
//	{ 0x2BB71D40, 0xF21DAB4A, 0x59EAA01D, eMod::��ʥ��, "��ʥ��" );
	ccc_txt_insert_npc(0x59D6FB3B, 0xD7DC93DE, 0x00000000, eMod::��Ф��, "��Ф��" );

	ccc_txt_insert_npc(0x0BB9C549, 0x703420B3, 0x6081AD14, eMod::�ֿ����Ա, "�ֿ����Ա" );
	ccc_txt_insert_npc(0x35F5C343, 0x028B91D6, 0x70CE5AB6, eMod::�����콫, "�����콫" );
	ccc_txt_insert_npc(0x93A1B0A9, 0xEC91EDA2, 0x76226129, eMod::�϶�, "�϶�" );
	ccc_txt_insert_npc(0x248A3E4C, 0x2B2CC199, 0x77B7E4FF, eMod::��ĸ����, "��ĸ����" );
	ccc_txt_insert_npc(0xEA27AD31, 0xFB629346, 0x8309B5DC, eMod::����, "����" );
	ccc_txt_insert_npc(0xBDD0DC76, 0xC230BE81, 0x87DB4BCC, eMod::��ëԳ, "��ëԳ" );
	ccc_txt_insert_npc(0xF707EA37, 0xFF76393B, 0x87DD16C5, eMod::��ɮ, "��ɮ" );
//	{ 0xE4926FC7, 0xBC6686FD, 0x8BB5A31A, eMod::�и�����, "�и�����" );
	ccc_txt_insert_npc(0x9D99A10D, 0x524EA098, 0x00000000, eMod::��Ф��, "��Ф��" );

	ccc_txt_insert_npc(0xF250443E, 0xB181318C, 0x8CAD1F2F, eMod::���޳�, "���޳�" );
	ccc_txt_insert_npc(0xB7809CE0, 0x159CCC9F, 0x9158832E, eMod::�޵���, "�޵���" );
	ccc_txt_insert_npc(0xAD7A1BD3, 0xBB2ECF8E, 0xA02DBEDE, eMod::������, "������" );
	ccc_txt_insert_npc(0x9493C216, 0xF269B9B7, 0xA74969CD, eMod::С��, "С��" );
	ccc_txt_insert_npc(0x1D8F9ABB, 0x04103E1D, 0xB061E863, eMod::���, "���" );
	ccc_txt_insert_npc(0x6ABF75AD, 0x8DDC27F7, 0xEC3608BC, eMod::κ��, "κ��" );
	ccc_txt_insert_npc(0x18791291, 0x90065904, 0xEED08D0E, eMod::��Сū, "��Сū" );
	ccc_txt_insert_npc(0x3A16E96D, 0xDCEBC9E8, 0xF575B185, eMod::������ҽ, "������ҽ" );
	ccc_txt_insert_npc(0x6843A912, 0x4EE87EE9, 0x3242A9D3, eMod::����, "����" );
	ccc_txt_insert_npc(0xE7D72D11, 0x6E8CD009, 0x4BDE70FC, eMod::����Ů��, "����Ů��" );
	ccc_txt_insert_npc(0x636012E7, 0x66FE03D3, 0xBACDA9D6, eMod::����, "����" );
	ccc_txt_insert_npc(0x3EA2FA4D, 0x12DAD117, 0x76C6D7D4, eMod::����Ů������, "����Ů������" );
	ccc_txt_insert_npc(0x234BC575, 0x36F5656A, 0x868E2879, eMod::Ī����, "Ī����" );
	ccc_txt_insert_npc(0x54D687BC, 0x3EAA6EC8, 0xDE850375, eMod::С��, "С��" );
	ccc_txt_insert_npc(0x40D087F9, 0xD104A2CD, 0xF6D4D1DD, eMod::�Ϲ�ة��, "�Ϲ�ة��" );
	ccc_txt_insert_npc(0x41B1D8EC, 0x5FD74EE1, 0xF9CC9FCF, eMod::Ԭ���, "Ԭ���" );
	ccc_txt_insert_npc(0x8F5E39E1, 0xDD211906, 0x4E52D71E, eMod::С��, "С��" );
	ccc_txt_insert_npc(0x7DD7F706, 0x7DD7F706, 0x49F4803B, eMod::�����������, "���������" );
	ccc_txt_insert_npc(0xDE7DA687, 0x1210A82F, 0x18ACCF64, eMod::Īүү, "Īүү" );
	ccc_txt_insert_npc(0xC680D6C0, 0x204413F8, 0x00000000, eMod::С����, "С����" );
	ccc_txt_insert_npc(0x65D0C53D, 0xD8300A1A, 0x75DD9222, eMod::����ȫ, "����ȫ" );
	ccc_txt_insert_npc(0x6282B5AB, 0x35F4E996, 0x00000000, eMod::Ů, "Ů" );
	ccc_txt_insert_npc(0x5AFA5725, 0xC5A358C2, 0x00000000, eMod::��ʨ��, "��ʨ��" );
	ccc_txt_insert_npc(0x402BB63B, 0x226CE8C7, 0x00000000, eMod::ʨ��, "ʨ��" );
	ccc_txt_insert_npc(0x90B6C959, 0xB98A494F, 0x00000000, eMod::ý��, "ý��" );
	ccc_txt_insert_npc(0x811B9CB3, 0x0DA7C649, 0x00000000, eMod::����, "����" );
	ccc_txt_insert_npc(0x8266156A, 0x69616440, 0x00000000, eMod::��������, "��������" );
	ccc_txt_insert_npc(0x7772C95B, 0x3CD9A806, 0x00000000, eMod::������, "������" );
	ccc_txt_insert_npc(0xCE0D9C8B, 0x32195B4F, 0x00000000, eMod::Ů���, "Ů���" );
//	ccc_txt_insert_npc(0x31684231, 0x00000000, 0x00000000, eMod::���������2, "���������" );
	ccc_txt_insert_npc(0x0C490F81, 0xA67ACBC8, 0x099EB8BE, eMod::»��, "»��" );
	ccc_txt_insert_npc(0x589BBFFE, 0x00000000, 0x099EB8BE, eMod::»��2, "»��" );
	ccc_txt_insert_npc(0x9E8FC397, 0xA25FFDB3, 0x279B729D, eMod::����, "����" );
	ccc_txt_insert_npc(0xCB71F060, 0x00000000, 0x279B729D, eMod::����2, "����" );
	ccc_txt_insert_npc(0x708A094F, 0x00000000, 0x59EAA01D, eMod::��ʥ��2, "��ʥ��2" );
	ccc_txt_insert_npc(0xA831A782, 0xA7362DEF, 0x12210C6A, eMod::С���쳤����, "С���쳤����" );
	ccc_txt_insert_npc(0x6341E0D6, 0x177CDA70, 0xB365FAC7, eMod::С�������, "С�������" );
	ccc_txt_insert_npc(0xCF6966D6, 0x00000000, 0x57CCD052, eMod::������/*2*/, "������" );
	ccc_txt_insert_npc(0x75BB33D2, 0xE0942BC2, 0x6533EA01, eMod::����, "����" );
	ccc_txt_insert_npc(0x00000000, 0x00000000, 0x08C6FE78, eMod::����, "����" );
	ccc_txt_insert_npc(0xCC61903E, 0x29DCD4EF, 0xF9F031A5, eMod::С����, "С����" );

//	{ 0xB73531B1, 0x06EA6E77, 0xA248A88A, eMod::�ն���ʦ, "�ն���ʦ" );
	ccc_txt_insert_npc(0x7FD9D3BC, 0x289C773D, 0x00000000, eMod::��Ф��, "��Ф��" );

	ccc_txt_insert_npc(0x544A2675, 0x00000000, 0x00000000, eMod::����, "����" );
	ccc_txt_insert_npc(0x639E73B0, 0x00000000, 0x00000000, eMod::����, "����" );
	ccc_txt_insert_npc(0xDA74178C, 0x00000000, 0x00000000, eMod::ѩ��, "ѩ��" );
	ccc_txt_insert_npc(0xBE52981A, 0x00000000, 0x00000000, eMod::ѩ��2, "ѩ��" );
	ccc_txt_insert_npc(0xF6655BCB, 0x00000000, 0x00000000, eMod::ѩ��3, "ѩ��" );
	ccc_txt_insert_npc(0x7ED2C0BE, 0x00000000, 0x00000000, eMod::ѩ��4, "ѩ��" );
	ccc_txt_insert_npc(0x6843DF1A, 0x00000000, 0x00000000, eMod::ѩ��5, "ѩ��" );
	ccc_txt_insert_npc(0xEFFD57F2, 0x00000000, 0x00000000, eMod::����, "����" );
// 	{ 0x062150F6, 0x922CB5F2, 0x7ABE5099, eMod::�׿���, "�׿���" );
// 	{ 0xCA07B7B2, 0xE46EA6C3, 0x4B343272, eMod::��ӿ����, "��ӿ����" );
// 	{ 0x1F5F4404, 0xF87DE3EF, 0x57CCD052, eMod::������, "������" );

// 0x39195BC3,,0x00000000,0x00000000,,,
// ,,,,,,
//	{ 0xDAC84F94, 0x39195BC3, 0x00000000, eMod::��Ф��, "��Ф��" );
//	{ 0x6644A046, 0x350A49B8, 0x00000000, eMod::��Фţ, "��Фţ" );
//	{ 0x59D6FB3B, 0xD7DC93DE, 0x00000000, eMod::��Ф��, "��Ф��" );
//	{ 0x9D99A10D, 0x524EA098, 0x00000000, eMod::��Ф��, "��Ф��" );
//	{ 0x7FD9D3BC, 0x289C773D, 0x00000000, eMod::��Ф��, "��Ф��" );
	ccc_txt_insert_npc(0xB0F79819, 0x800A4859, 0x00000000, eMod::��Ф��, "��Ф��" );
	ccc_txt_insert_npc(0x7FD84FE9, 0x4D8E1F0C, 0x00000000, eMod::��Ф��, "��Ф��" );
	ccc_txt_insert_npc(0xDEBBC85B, 0x087C63E1, 0x00000000, eMod::��Ф��, "��Ф��" );
	ccc_txt_insert_npc(0xAA910FFF, 0x51FC5B28, 0x00000000, eMod::��Ф��, "��Ф��" );
	ccc_txt_insert_npc(0xCC9CE563, 0x9D353BF4, 0x00000000, eMod::��Ф��, "��Ф��" );
	ccc_txt_insert_npc(0xF41F6038, 0xDE58CA6F, 0x00000000, eMod::��Ф��, "��Ф��" );
	ccc_txt_insert_npc(0x60976277, 0x1F9309D8, 0x00000000, eMod::��Ф��, "��Ф��" );

	ccc_txt_insert_npc(0xF98D2A1B, 0xBE860ACE, 0x00000000, eMod::����, "�滨����" ); // �յ�
	// ,,,,,,,,,
	ccc_txt_insert_npc(0xF98D2A1B, 0xBE860ACE, 0x00000000, eMod::����, "�滨����" );
	ccc_txt_insert_npc(0x42B36239, 0x704645B8, 0xD107A1E8, eMod::������, "������" );
	ccc_txt_insert_npc(0xBA6F4D0A, 0x242EF102, 0x00000000, eMod::���, "���" );
	ccc_txt_insert_npc(0x0ED219E4, 0x8D0EBCFA, 0x00000000, eMod::����, "����" );
	ccc_txt_insert_npc(0x6F71376B, 0xEBF15AEB, 0x00000000, eMod::С��, "С��" );
	ccc_txt_insert_npc(0x51938DE3, 0xD0ED25E7, 0x00000000, eMod::С��, "С��" );
	ccc_txt_insert_npc(0x294305EE, 0x43FAB86B, 0x00000000, eMod::�ɺ�, "�ɺ�" );
	ccc_txt_insert_npc(0x09CC8CB6, 0x47D83896, 0x00000000, eMod::С��, "С��" );
	ccc_txt_insert_npc(0x44D10E0D, 0x83464CB6, 0x00000000, eMod::С��, "С��" );
	ccc_txt_insert_npc(0x2032D0C0, 0x56128DA7, 0x00000000, eMod::GM��, "GM��" );
	ccc_txt_insert_npc(0x474B1237, 0xC33B0F39, 0x00000000, eMod::GMŮ, "GMŮ" );
	ccc_txt_insert_npc(0x7596D42B, 0x7F4CBC8C, 0x00000000, eMod::����, "����" );

#undef ccc_txt_insert_npc
}
