#include "TxtSkill.h"
using namespace ctt;

static const std::vector<sSkillPassive> s_skillPassives = 
{
	{ 0x1379151C, 0x99732F02, eSkillPassive::����fj, { /*ePassiveSkill::�߼�����fj*/ }, "����", "�ܵ���������30%���ʷ���,�����˺�����" },
	{ 0x01884D50, 0xE9CD05B8, eSkillPassive::�߼�����fj, { eSkillPassive::����fj }, "�߼�����", "�ܵ���������30%���ʷ���" },
	{ 0xDFC6FDFC, 0xEAE7E3EC, eSkillPassive::����fz, { /*ePassiveSkill::�߼�����fz*/ }, "����", "�ܵ���������30%���ʷ���25%���˺�" },
	{ 0x1E7F5930, 0x71B0F5EE, eSkillPassive::�߼�����fz, { eSkillPassive::����fz }, "�߼�����", "�ܵ���������30%���ʷ���50%���˺�" },
	{ 0x09556A2E, 0x27D53971, eSkillPassive::��Ѫxx, { /*ePassiveSkill::�߼���Ѫxx*/ }, "��Ѫ", "��������20%����ѪЧ��" },
	{ 0x97B369D6, 0x515A38AD, eSkillPassive::�߼���Ѫxx, { eSkillPassive::��Ѫxx }, "�߼���Ѫ", "��������35%����ѪЧ��" },
	{ 0x31C34438, 0x4534723B, eSkillPassive::����lj, { /*ePassiveSkill::�߼�����lj*/ }, "����", "��������45%��������,�˺��½�25%" },
	{ 0xB3C6A6E2, 0x4ECA2A0F, eSkillPassive::�߼�����lj, { eSkillPassive::����lj }, "�߼�����", "��������55%��������,�˺��½�20%" },
	{ 0x46FA5E55, 0x307E28C8, eSkillPassive::����fx, { /*ePassiveSkill::�߼�����fx*/ }, "����", "�ر���+10%,������+10%,���ܰ����˺�+50%" },
	{ 0xE5A9F47C, 0xFEF30F0D, eSkillPassive::�߼�����fx, { eSkillPassive::����fx }, "�߼�����", "�ر���+20%,������+20%,���ܰ����˺�+20%" },
	{ 0xEB2AF42F, 0xDD5CEE60, eSkillPassive::ҹսyz, { /*ePassiveSkill::�߼�ҹսyz*/ }, "ҹս", "�˺���+5%" },
	{ 0x5906A6A0, 0x3E81ECFB, eSkillPassive::�߼�ҹսyz, { eSkillPassive::ҹսyz }, "�߼�ҹս", "�˺���+10%" },
	{ 0xB3488AAE, 0x59E4822E, eSkillPassive::����ys, { /*ePassiveSkill::�߼�����ys*/ }, "����", "2�غ�" },
	{ 0xAFB8E892, 0x9484D8DE, eSkillPassive::�߼�����ys, { eSkillPassive::����ys }, "�߼�����", "5�غ�" },
	{ 0xEF245DFC, 0xDB2B3C6A, eSkillPassive::��֪gz, { /*ePassiveSkill::�߼���֪gz*/ }, "��֪", "���Թ�������״̬�µĵ���" },
	{ 0x6CA45F1F, 0x2840330D, eSkillPassive::�߼���֪gz, { eSkillPassive::��֪gz }, "�߼���֪", "���Թ�������״̬�µĵ���,�����+20%" },
	{ 0x86F93A3B, 0xC3F77E8F, eSkillPassive::����zs, { /*ePassiveSkill::�߼�����zs*/ }, "����", "ÿ�غϻظ���Ѫ=�ȼ�" },
	{ 0xE3126879, 0x1BE87C60, eSkillPassive::�߼�����zs, { eSkillPassive::����zs }, "�߼�����", "ÿ�غϻظ���Ѫ=�ȼ�*2" },
	{ 0xD3E2714A, 0x2514ED1F, eSkillPassive::ڤ˼ms, { /*ePassiveSkill::�߼�ڤ˼ms*/ }, "ڤ˼", "ÿ�غϻظ�ħ��=�ȼ�/4" },
	{ 0x81A302FF, 0x66718220, eSkillPassive::�߼�ڤ˼ms, { eSkillPassive::ڤ˼ms }, "�߼�ڤ˼", "ÿ�غϻظ�ħ��=�ȼ�/2" },
	{ 0xC89A9EDC, 0x56DEF316, eSkillPassive::�۸�hg, { /*ePassiveSkill::�߼��۸�hg*/ }, "�۸�", "��������-25%" },
	{ 0xF8CE3E63, 0x0E6F601D, eSkillPassive::�߼��۸�hg, { eSkillPassive::�۸�hg }, "�߼��۸�", "�������ļ���" },
	{ 0x420269A4, 0xE1DA16D6, eSkillPassive::��ɱbs, { /*ePassiveSkill::�߼���ɱbs*/ }, "��ɱ", "��ɱ��+10%" },
	{ 0x4C700EA4, 0x63B6486D, eSkillPassive::�߼���ɱbs, { eSkillPassive::��ɱbs }, "�߼���ɱ", "��ɱ��+20%" },
	{ 0x40B80312, 0xD8F7385A, eSkillPassive::����xy, { /*ePassiveSkill::�߼�����xy*/ }, "����", "���߱�ɱ" },
	{ 0x1CB6FA78, 0x6A29156C, eSkillPassive::�߼�����xy, { eSkillPassive::����xy }, "�߼�����", "���߱�ɱ,���������+10%" },
	{ 0x4772D507, 0x4A3BBF91, eSkillPassive::��sj, { /*ePassiveSkill::�߼���sj*/ eSkillPassive::������js, eSkillPassive::�߼�������js }, "��", "ÿ�غϿ�ʼ�����쳣״̬" },
	{ 0xFC717CFD, 0x2A1026D7, eSkillPassive::�߼���sj, { eSkillPassive::��sj, eSkillPassive::������js, eSkillPassive::�߼�������js }, "�߼���", "�����쳣״̬" },
	{ 0xD16002DC, 0x8E539BBA, eSkillPassive::�м�zj, { /*ePassiveSkill::�߼��м�zj*/ }, "�м�", "����+10%" },
	{ 0x3CBAC3A9, 0x1ADFDD2B, eSkillPassive::�߼��м�zj, { eSkillPassive::�м�zj }, "�߼��м�", "����+20%" },
	{ 0x59EBCAAD, 0x7680EBA8, eSkillPassive::����yh, { /*ePassiveSkill::�߼�����yh*/ }, "����", "����Ч��ʱ��+3�غ�" },
	{ 0xEC4339C2, 0xF86EA690, eSkillPassive::�߼�����yh, { eSkillPassive::����yh }, "�߼�����", "����Ч��ʱ��+6�غ�" },
	{ 0xFFAC3F6A, 0xBABA11E3, eSkillPassive::����mj, { /*ePassiveSkill::�߼�����mj*/ }, "����", "�ٶ�+10%" },
	{ 0x7ADDCB60, 0x4A654A53, eSkillPassive::�߼�����mj, { eSkillPassive::����mj }, "�߼�����", "�ٶ�+20%" },
	{ 0x2A2C6FCB, 0x56F51981, eSkillPassive::ǿ��ql, { /*ePassiveSkill::�߼�ǿ��ql*/ }, "ǿ��", "������+�ȼ�/2" },
	{ 0x81C9C93E, 0xD466B3D1, eSkillPassive::�߼�ǿ��ql, { eSkillPassive::ǿ��ql }, "�߼�ǿ��", "������+�ȼ�/1" },
	{ 0xF47ADB17, 0x05728F4B, eSkillPassive::����fy, { /*ePassiveSkill::�߼�����fy*/ }, "����", "����+�ȼ�/2" },
	{ 0xE17C3B8E, 0x60551819, eSkillPassive::�߼�����fy, { eSkillPassive::����fy }, "�߼�����", "����+�ȼ�/1" },
	{ 0x0C425BC3, 0xB5C24835, eSkillPassive::͵Ϯtx, { /*ePassiveSkill::�߼�͵Ϯtx*/ }, "͵Ϯ", "60%���߷��𷴻�" },
	{ 0x5CB8D73F, 0xEF2EB5D4, eSkillPassive::�߼�͵Ϯtx, { eSkillPassive::͵Ϯtx }, "�߼�͵Ϯ", "99%���߷��𷴻�" },
	{ 0xE2C478F8, 0x087AB3EA, eSkillPassive::��d, { /*ePassiveSkill::�߼���d*/ }, "��", "����ʱ��10%����ʹ�����ж�" },
	{ 0x40BE8F5E, 0x23205169, eSkillPassive::�߼���d, { eSkillPassive::��d }, "�߼���", "����ʱ��20%����ʹ�����ж�" },
	{ 0x7BD73DE0, 0x18CC6B26, eSkillPassive::����qg, { /*ePassiveSkill::�߼�����qg*/ }, "����", "���й������Ŀ���˺�+50%" },
	{ 0xCBCF6BE3, 0x04512FE2, eSkillPassive::�߼�����qg, { eSkillPassive::����qg }, "�߼�����", "���й������Ŀ���˺�+100%" },
	{ 0xFEE50FAB, 0x307CF1BE, eSkillPassive::�����gh, { eSkillPassive::���Ӹ���sy, eSkillPassive::�߼����Ӹ���sy }, "�����", "�����쳣״̬,����7�غϸ���" },
	{ 0xD3794A73, 0x913D7735, eSkillPassive::�߼������gh, { eSkillPassive::�����gh, eSkillPassive::���Ӹ���sy, eSkillPassive::�߼����Ӹ���sy }, "�߼������", "�����쳣״̬,����5�غϸ���" },
	{ 0x87C81C63, 0x2AD5089A, eSkillPassive::ħ֮��mz, { /*ePassiveSkill::�߼�ħ֮��mz*/ }, "ħ֮��", "�����˺�+10%" },
	{ 0xAB67DBAB, 0x9A24567A, eSkillPassive::�߼�ħ֮��mz, { eSkillPassive::ħ֮��mz }, "�߼�ħ֮��", "�����˺�+20%" },
	{ 0xAF7442C5, 0x54037CFF, eSkillPassive::���Ӹ���sy, { /*ePassiveSkill::�߼����Ӹ���sy*/ }, "���Ӹ���", "����ʱ��20%���ʸ���60%��Ѫ" },
	{ 0xB5CA5D93, 0x799E08CE, eSkillPassive::�߼����Ӹ���sy, { eSkillPassive::���Ӹ���sy }, "�߼����Ӹ���", "����ʱ��35%���ʸ�����Ѫ" },
	{ 0xA6DFC207, 0xF6E0F4C0, eSkillPassive::������js, { /*ePassiveSkill::�߼�������js*/ }, "������", "10%�ֿ��쳣" },
	{ 0x8EB9B230, 0xBA10735B, eSkillPassive::�߼�������js, { eSkillPassive::������js }, "�߼�������", "20%�ֿ��쳣" },
	{ 0xB2F61506, 0xC763E399, eSkillPassive::������fd, { /*ePassiveSkill::�߼�������fd*/ }, "������", "���ܵ���ʱ,�Է��������½�15%" },
	{ 0x9204C942, 0x1CE3C56D, eSkillPassive::�߼�������fd, { eSkillPassive::������fd }, "�߼�������", "���ܵ���ʱ,�Է��������½�25%" },
	{ 0x149AB0A5, 0x83251A3C, eSkillPassive::��������fs, { /*ePassiveSkill::�߼���������fs*/ }, "��������", "����15%�ļ�������" },
	{ 0x70B62C09, 0xCFB487A4, eSkillPassive::�߼���������fs, { eSkillPassive::��������fs }, "�߼���������", "����25%�ļ�������" },
	{ 0x4210A339, 0x52D97379, eSkillPassive::��������fs, { /*ePassiveSkill::�߼���������fs*/ }, "��������", "����10%�ļ��ʱ���" },
	{ 0x610B7489, 0x7B7E1F49, eSkillPassive::�߼���������fs, { eSkillPassive::��������fs }, "�߼���������", "����15%�ļ��ʱ���" },
	{ 0x0FF374D8, 0x2D6EE6B5, eSkillPassive::��������fs, { /*ePassiveSkill::�߼���������fs*/ }, "��������", "100-110%" },
	{ 0xDAAF4328, 0x8A6FD1EC, eSkillPassive::�߼���������fs, { eSkillPassive::��������fs }, "�߼���������", "100-120%" },
	{ 0xB2F61506, 0xE861CC5D, eSkillPassive::�ٶ�cd, { eSkillPassive::����mj, eSkillPassive::�߼�����mj}, "�ٶ�", "�ٶ�-50%" },
	{ 0x105F0207, 0x9C1EEE54, eSkillPassive::�߼��ٶ�cd, { eSkillPassive::�ٶ�cd, eSkillPassive::����mj, eSkillPassive::�߼�����mj }, "�߼��ٶ�", "�ٶ�-80%" },

	{ 0xEEC21546, 0x5C279D6E, eSkillPassive::�����rd, { eSkillPassive::����������hs, eSkillPassive::�߼�����������hs }, "�����", "�ܵ������Թ����˺�+50%" },
	{ 0x4267A335, 0x2FEC0881, eSkillPassive::����ˮrd, { eSkillPassive::ˮ��������ss, eSkillPassive::�߼�ˮ��������ss}, "����ˮ", "�ܵ�ˮ���Թ����˺�+50%" },
	{ 0x36438B51, 0x853524D8, eSkillPassive::������rd, { eSkillPassive::����������ts, eSkillPassive::�߼�����������ts}, "������", "�ܵ������Թ����˺�+50%" },
	{ 0x9B4F6936, 0xAC0696AE, eSkillPassive::������rd, { eSkillPassive::����������ls, eSkillPassive::�߼�����������ls}, "������", "�ܵ������Թ����˺�+50%" },
	{ 0xC58CA678, 0xA71D860C, eSkillPassive::����������ls, { /*ePassiveSkill::�߼�����������ls*/ }, "����������", "�ܵ������Թ���20%�����˺�" },
	{ 0x0723D081, 0x629C475E, eSkillPassive::�߼�����������ls, { eSkillPassive::����������ls }, "�߼�����������", "�ܵ������Թ���30%�����˺�" },
	{ 0xD0CD6B99, 0x0801A3EA, eSkillPassive::����������ts, { /*ePassiveSkill::�߼�����������ts*/ }, "����������", "�ܵ������Թ���20%�����˺�" },
	{ 0x2CD0288C, 0x9D518016, eSkillPassive::�߼�����������ts, { eSkillPassive::����������ts }, "�߼�����������", "�ܵ������Թ���30%�����˺�" },
	{ 0xF3EDE679, 0xF442D468, eSkillPassive::����������hs, { /*ePassiveSkill::�߼�����������hs*/ }, "����������", "�ܵ������Թ���20%�����˺�" },
	{ 0x50118271, 0xACBCC108, eSkillPassive::�߼�����������hs, { eSkillPassive::����������hs }, "�߼�����������", "�ܵ������Թ���30%�����˺�" },
	{ 0x68B24211, 0x0584205F, eSkillPassive::ˮ��������ss, { /*ePassiveSkill::�߼�ˮ��������ss*/ }, "ˮ��������", "�ܵ�ˮ���Թ���20%�����˺�" },
	{ 0x4E36441F, 0x96F0C044, eSkillPassive::�߼�ˮ��������ss, { eSkillPassive::ˮ��������ss }, "�߼�ˮ��������", "�ܵ�ˮ���Թ���30%�����˺�" },
	{ 0x00000000, 0x04B409B4, eSkillPassive::����dq, { /*ePassiveSkill::�߼�����dq*/ }, "����", "����ս����ʱ���ӵȼ�*1�ķ���,����5�غ��ҵݼ�" },
	{ 0x00000000, 0x8EC237B5, eSkillPassive::�߼�����dq, { eSkillPassive::����dq }, "�߼�����", "����ս����ʱ���ӵȼ�*2�ķ���,����5�غ��ҵݼ�" },
	{ 0x00000000, 0x3EDD86F8, eSkillPassive::�����ֿ�fs, { /*ePassiveSkill::�߼������ֿ�fs*/ }, "�����ֿ�", "�ܵ������˺�-15%" },
	{ 0x00000000, 0xE8FD17ED, eSkillPassive::�߼������ֿ�fs, { eSkillPassive::�����ֿ�fs }, "�߼������ֿ�", "�ܵ������˺�-25%" },
	{ 0x00000000, 0xA94D8FEA, eSkillPassive::����hz, { /*ePassiveSkill::�߼�����hz*/ }, "����", "�������ӶԷ�4%����" },
	{ 0x00000000, 0x4EAD21FF, eSkillPassive::�߼�����hz, { eSkillPassive::����hz }, "�߼�����", "�������ӶԷ�8%����" },


	{ 0x00000000, 0x5886F7D3, eSkillPassive::�ƻ���ľyh, {}, "�ƻ���ľ", "�����˺�-99%" },
	{ 0x00000000, 0xDEF6EAF8, eSkillPassive::���ܼ���ln, {}, "���ܼ���", "����ս����ʱ���ӵȼ�*1������,����5�غ��ҵݼ�" },
	{ 0x00000000, 0xC3F4BC0D, eSkillPassive::��Ѫ׷��sx, {}, "��Ѫ׷��", "Ŀ��������׷�ӹ�����һ��Ŀ��" },
	// ���� �����ֿ� ����
	{ 0x00000000, 0x87FC2C8A, eSkillPassive::��������fl, {}, "��������", "30%����25%�ķ����˺�" },
	// �׻�
	// 0xE52A8168
	{ 3844768104, 0xE52A8168, eSkillPassive::��������fy, {}, "��������", "�ڳ�ʱ������������10%�ٶ�5�غ�" },
	// �������� �ƶ� ����
	{ 0x00000000, 0xC6724A1D, eSkillPassive::���ŭ��cq, {}, "���ŭ��", "��ɱ������ʱ,���׷����һĿ��,ÿ�غ���ഥ��һ��" },
	// �ռ���(��η��ʩ)  ����(�콵���)
	{ 0x00000000, 0x4BB2CD64, eSkillPassive::��������xm, {}, "��������", "����ħ��*0.4�ķ����˺�" },
	{ 0x00000000, 0x7FFF65B8, eSkillPassive::�������ct, {}, "�������", "������ͨ����ʱ��ɵ��˺�,���п����ڿ�ʧ��" },
	// �¹�
	{ 0x00000000, 0xDFCC02E3, eSkillPassive::��ɽ����ls, {}, "��ɽ����", "���������˺�,����ħ��*1�ķ���" },
	{ 0x00000000, 0xFF01A989, eSkillPassive::ǧ��һŭqj, {}, "ǧ��һŭ", "��ͨ������ɵ��˺�>=��Ѫ10%,�Լ������˻���10���ŭ" },
	{ 0x00000000, 0x230CEC5B, eSkillPassive::����lh, {}, "����", "ÿ���γɹ�ʹ�÷������������������˺�" },
	{ 0x00000000, 0x4E3C17E0, eSkillPassive::������dk, {}, "������", "��ͨ����ʱ�м�����������ͱ�ɱ�ĸ���" },
};



static const std::vector<sSkillFuzhu> s_skillFuzhus =
{
	// ����
	{ 0x6F838C3B, 0x9285D9EB, eSkillFuzhu::ǿ׳, "ǿ׳", "ÿ��+5��HP����" },
	{ 0x2BB02FD3, 0xD6750E0D, eSkillFuzhu::ǿ����, "ǿ����", "ÿ����1%����Ѫ����" },
	{ 0x35D2CD77, 0x05CA3AA8, eSkillFuzhu::ڤ��, "ڤ��", "ÿ����1%��ħ������" },
	{ 0x57D857C0, 0x7D3C4887, eSkillFuzhu::��������, "��������", "ÿ�������˺�+1%" },
	{ 0x617743DB, 0xE67220ED, eSkillFuzhu::���켼��, "���켼��", "������ʱ����Ʒ����" },
	{ 0x68D513E9, 0x3FE32FC2, eSkillFuzhu::�÷켼��, "�÷켼��", "���·�ʱ����Ʒ����" },
	{ 0x13E6F3B0, 0x4EF982E4, eSkillFuzhu::������, "������", "������,Ь��,����ʱ,��Ʒ����" },
	{ 0x2649EAD5, 0xE72ED95F, eSkillFuzhu::��ҩҽ��, "��ҩҽ��", "��������ҩ��" },
	{ 0xE172DE46, 0x785A800E, eSkillFuzhu::��⿼���, "��⿼���", "�����������" },
	{ 0x6C81040C, 0x476CFC92, eSkillFuzhu::���뼼��, "���뼼��", "ÿ��+1%�����ܳɹ���" },
	{ 0x35C9EAD4, 0x075D782F, eSkillFuzhu::׷������, "׷������", "ÿ�����˵����ܳɹ���-1%" },
	{ 0x6179CA67, 0x39BF36FD, eSkillFuzhu::����֮��, "����֮��", "ÿ��+5���������" },
	{ 0xBC31F555, 0xD5F04CC0, eSkillFuzhu::������, "������", "ÿ��+5����������" },
	// ����
	{ 0xE9D07953, 0x43CBAF9C, eSkillFuzhu::���۽�, "���۽�", "" },
	{ 0x61197BD5, 0x93EAB2C8, eSkillFuzhu::��Ԫ�û�, "��Ԫ�û�", "" },
	{ 0x55CD16AC, 0x8466E376, eSkillFuzhu::���ֿտ�, "���ֿտ�", "" },
	{ 0x03B593E3, 0x70FB3A0E, eSkillFuzhu::�ٻ���ͼ��, "�ٻ���ͼ��", "" },
	{ 0x3F7B9F82, 0x5A2821B8, eSkillFuzhu::�仯��, "�仯��", "" },
	{ 0x20D43900, 0xDF55F6EF, eSkillFuzhu::�λÿ���, "�λÿ���", "" },
	{ 0xCB9C5ECC, 0x58F2DDB8, eSkillFuzhu::С��ţ��, "С��ţ��", "" },
	{ 0xC0F1CE88, 0x59EDC2D6, eSkillFuzhu::��ȭ, "��ȭ", "" },
	{ 0xB6FAD6C9, 0x59FEE007, eSkillFuzhu::������, "������", "" },
	{ 0xE588745D, 0xDB84A5CB, eSkillFuzhu::װ��ͼ��, "װ��ͼ��", "" },
	{ 0x2E8A8A30, 0x135FA17A, eSkillFuzhu::��������, "��������", "" },
	{ 0x72DE84DF, 0x46B9DE47, eSkillFuzhu::��ʯ����, "��ʯ����", "" },
	{ 0x4D48EC9A, 0xB490C429, eSkillFuzhu::�ɽ�֮��, "�ɽ�֮��", "" },
	{ 0x6AAEF804, 0x0D167BFB, eSkillFuzhu::�Ŷ�����, "�Ŷ�����", "" },
	{ 0x9F2DFDB6, 0x16418D92, eSkillFuzhu::����֮��, "����֮��", "" },
	{ 0x47877A93, 0x25064DE5, eSkillFuzhu::�������, "�������", "" },
	// ����
	{ 0x3FC666BA, 0x00000000, eSkillFuzhu::�Ƹ�����, "�Ƹ�����", "" },
	{ 0x2D685412, 0x00000000, eSkillFuzhu::����ٵ�, "����ٵ�", "" },
	{ 0x077F08D1, 0x00000000, eSkillFuzhu::��������, "��������", "" },
	{ 0x497B7159, 0x00000000, eSkillFuzhu::��������, "��������", "" },
	{ 0x624C7E94, 0x00000000, eSkillFuzhu::��ջ���, "��ջ���", "" },
	{ 0x6A4612D6, 0x00000000, eSkillFuzhu::�ҹ�����, "�ҹ�����", "" },
	{ 0x83A054A5, 0x00000000, eSkillFuzhu::�Ż�����, "�Ż�����", "" },
	{ 0xA2572FFC, 0x00000000, eSkillFuzhu::Ǭ������, "Ǭ������", "" },
	{ 0xD1EBF7E3, 0x00000000, eSkillFuzhu::ˮ������, "ˮ������", "" },
	{ 0xD3236E57, 0x00000000, eSkillFuzhu::�ɻ�����, "�ɻ�����", "" },
	{ 0xE2296705, 0x00000000, eSkillFuzhu::������ɳ, "������ɳ", "" },
	{ 0xF0F2E8F1, 0x00000000, eSkillFuzhu::ͭǽ����, "ͭǽ����", "" },
};




static const std::vector<ctt::sSkill> s_skills = 
{
	{ 0x94BFA7D9, 0xC6E68077, 0x0E30CD44, 0x00000000, 0xDDD270F5, eSkill::�׻�, eSkillUse::BattleOther, eBuff::None, 30, 0, "�׻�", "���������Է���", "30MP" },
	{ 0xDA8731E8, 0xAA631753, 0xF54C4025, 0x00000000, 0x040584F3, eSkill::������, eSkillUse::BattleOther, eBuff::None, 30, -10, "������", "���������Է���", "MPS" },
	{ 0x11F08BC1, 0xFBEEDD94, 0x0AC30DE6, 0x00000000, 0x564F1090, eSkill::����, eSkillUse::BattleOther, eBuff::None, 30, -10, "����", "���������Է���", "30MP" },
	{ 0xFD4BCB54, 0x1BA20D9E, 0x783F9D20, 0x00000000, 0x22FEF25E, eSkill::̩ɽѹ��, eSkillUse::BattleOther, eBuff::None, 30, 0, "̩ɽѹ��", "���������Է���", "MPS" },
	{ 0x8FF8B5C0, 0x0511E729, 0xF933209B, 0x00000000, 0x0071B681, eSkill::ˮ��, eSkillUse::BattleOther, eBuff::None, 30, -10, "ˮ��", "����ˮ���Է���", "30MP" },
	// 0x97311BAD
	{ 0xE6883491, 0x9D368B02, 0x18967984, 0x00000000, 0x4F09C15D, eSkill::ˮ����ɽ, eSkillUse::BattleOther, eBuff::None, 30, 0, "ˮ����ɽ", "����ˮ���Է���", "MPS" },
	{ 0x636DADB0, 0xB0CBEBBF, 0xD112913D, 0x00000000, 0x3E2A375C, eSkill::�һ�, eSkillUse::BattleOther, eBuff::None, 30, -10, "�һ�", "��������Է���", "30MP" },
	{ 0xB55E9384, 0xFBBBE334, 0x139426B5, 0x00000000, 0x2E88DCF4, eSkill::�����һ�, eSkillUse::BattleOther, eBuff::None, 30, 0, "�����һ�", "���˻����Է���", "MPS" },
	{ 0x1671DDFD, 0x1C22C610, 0x3BA4B993, 0x00000000, 0x675E4E20, eSkill::����һ��, eSkillUse::BattleOther, eBuff::None, 30, 0, "����һ��", "����������", "30MP" },
	{ 0x6D382036, 0x1719FC84, 0xF18C76DD, 0x00000000, 0x9609FDF4, eSkill::ҹ�����, eSkillUse::BattleOther, eBuff::None, 10, -10, "ҹ�����", "�㳡���ɱ����", "CostLv" },
	// 0x19182964
	{ 0xFF0E4570, 0x48A24731, 0x4E02EC44, 0x2C6223D4, 0x739A0BAB, eSkill::�����ٻ�, eSkillUse::BattleOther, eBuff::None, 10, 0, "�����ٻ�", "15%ʹ������������Ч��", "CostLv" },
	{ 0x848155A0, 0xD88B6D52, 0xFF33B0EE, 0x00000000, 0x00000000, eSkill::������ɽ, eSkillUse::BattleOther, eBuff::None, 50, -10, "������ɽ", "�˺�����Ͳ���", "" },
	{ 0x00000000, 0x63770E47, 0x729ADE62, 0x00000000, 0x0504D379, eSkill::�����ķ�, eSkillUse::BattleOther, eBuff::None, 10, 0, "�����ķ�", "С��ӿ", "CostHp" },
	{ 0x2513128B, 0x3543B96C, 0x00000000, 0xDEDEE983, 0x00000000, eSkill::��������, eSkillUse::BattleSelf, eBuff::Good, 10, 0, "��������", "�ܵ������˺�-65%", "CostLv" },
	{ 0x71267227, 0x263B68C3, 0x8D8A818D, 0x00000000, 0x2174467F, eSkill::�ƶ��б�, eSkillUse::BattleOther, eBuff::None, 10, 0, "�ƶ��б�", "���ǲ���ʱ��δ��", "CostLv" },
	{ 0x00000000, 0xF1D5925A, 0x99DDC32A, 0x00000000, 0x0504D379, eSkill::���ݻ���, eSkillUse::BattleOther, eBuff::None, 10, 0, "���ݻ���", "������Ͳ���", "CostLv" },
// 	{ 0x00000000, 0xC6724A1D, 0x00000000, 0x00000000, 0x43B4478D, eSkill::���ŭ��, eSkillUse::BattleOther, eBuff::None, 0, 0, "���ŭ��", "�����˺�*200%", "�ȼ�+10MP" },
// 	{ 0xDB2E1256, 0xDE58924A, 0x911E3921, 0x00000000, 0x564F1090, eSkill::����ռ���, eSkillUse::BattleOther, eBuff::Good, 0, -10, "����ռ���", "����ȫ������", "�ȼ�+10MP" },
// 	{ 0xDB2E1256, 0xDE58924A, 0x3200B6CC, 0x00000000, 0x752FFCAB, eSkill::�����ƻ�����, eSkillUse::BattleOther, eBuff::Bad, 0, 0, "�����ƻ�����", "�����˺�*200%", "�ȼ�+100MP" },
// 	{ 0x00000000, 0x4BB2CD64, 0x00000000, 0x00000000, 0x00000000, eSkill::��������, eSkillUse::None, eBuff::None, 0, 0, "��������", "����ʥ��,������", "" },
// 	{ 0x00000000, 0x7FFF65B8, 0x00000000, 0x00000000, 0x00000000, eSkill::�������, eSkillUse::None, eBuff::None, 0, 0, "�������", "������ͨ����ʱ��ɵ��˺�,���п����ڿ�ʧ��", "" },
	{ 0x00000000, 0x35C47AF8, 0xFB90D9B1, 0x2F3E4271, 0x1353874F, eSkill::��η��ʩ, eSkillUse::BattleOwnerButSelf, eBuff::None, 50, 10, "��η��ʩ", "����Ŀ��ķ����ͷ���3�غ�,���ή������ķ����ͷ���", "CostLv" },
	{ 0x00000000, 0x5BCBB249, 0xDCD7A875, 0x00000000, 0x00000000, eSkill::�콵���, eSkillUse::BattleOther, eBuff::None, 30, -10, "�콵���", "�������1-5��Ŀ��", "CostLv" },
	{ 0x00000000, 0xCB238CFE, 0x28DC0E4B, 0x00000000, 0x9609FDF4, eSkill::�¹�, eSkillUse::BattleOther, eBuff::None, 10, -10, "�¹�", "��������������", "CostLv" },
	{ 0x00000000, 0x00000000, 0x35AA81A7, 0x00000000, 0x00000000, eSkill::���Ǵ�xx, eSkillUse::BattleOther, eBuff::None, 10, 0, "���Ǵ�", "������", "CostLv" },

	{ 0x35F72F87, 0x0A71DEE7, 0xF3B31E4E, 0x00000000, 0x53E82E61, eSkill::������, eSkillUse::BattleOwner, eBuff::None, 30, 0, "������", "����ָ�(����3%+200)����Ѫ", "20" },
	{ 0xFD3187C7, 0x73735CAC, 0xFBF89980, 0x00000000, 0xE6339003, eSkill::������, eSkillUse::BattleOwner, eBuff::None, 60, 0, "������", "����ָ�(����6%+400)����Ѫ", "30" },
	{ 0x48650DE3, 0x8AB448F6, 0xF3B31E4E, 0x00000000, 0x53E82E61, eSkill::������, eSkillUse::BattleOwner, eBuff::None, 90, 0, "������", "����ָ�(����9%+600)����Ѫ", "40" },
	// 0x3240F0D4 �ó�
	{ 0xFC3656C8, 0x852E36F5, 0x899241C3, 0x00000000, 0x4B800708, eSkill::������, eSkillUse::BattleOwner, eBuff::None, 60, -10, "������", "����ָ�(����10%+150)��ħ��", "50" },
	{ 0xD63AE21B, 0xB36F0828, 0x7EE33126, 0x00000000, 0x4B800708, eSkill::�����, eSkillUse::BattleOwner, eBuff::None, 90, 0, "�����", "����ָ�(����15%+240)��ħ��", "60" },
	{ 0x598125FD, 0x67F2A70E, 0xD077C3A0, 0x00000000, 0x53E82E61, eSkill::������, eSkillUse::BattleSelf, eBuff::None, 60, 0, "������", "����ָ�1/4����Ѫ", "30" },
	{ 0x4DCB689E, 0x9A1985E8, 0x30F2B60C, 0x00000000, 0x53E82E61, eSkill::������, eSkillUse::BattleSelf, eBuff::None, 130, 0, "������", "����ָ�1/2����Ѫ", "60" },
	{ 0x8574CDF1, 0x78276F30, 0xD077C3A0, 0x00000000, 0x04E42236, eSkill::�ĺ���ƽ, eSkillUse::BattleOwner, eBuff::None, 135, 0, "�ĺ���ƽ", "ȫ��ָ�1/4����Ѫ", "108" },
	{ 0x97838895, 0xE364BF7C, 0x8E92AE82, 0x00000000, 0x97283C40, eSkill::�ػ���, eSkillUse::BattleOwner, eBuff::None, 100, -10, "�ػ���", "���帴��ָ�150��Ѫ", "64" },
	{ 0xC3793063, 0x83797F7C, 0x8E92AE82, 0x00000000, 0x97283C40, eSkill::��������, eSkillUse::BattleOwner, eBuff::None, 120, -10, "��������", "���帴��ָ�1/2����Ѫ", "96" },
	{ 0x85097919, 0x76847896, 0x17238B9F, 0x00000000, 0xE6339003, eSkill::ˮ���, eSkillUse::BattleOwner, eBuff::None, 50, -10, "ˮ���", "�������쳣״̬", "40" },
	{ 0x3B44EE0A, 0xFE796634, 0x17238B9F, 0x00000000, 0xE6339003, eSkill::�����, eSkillUse::BattleOwner, eBuff::None, 100, -10, "�����", "�������쳣״̬���ָ�1/4����Ѫ", "64" },
	{ 0x3F79D19F, 0x8A21BA6C, 0x17238B9F, 0x00000000, 0xFBD946FB, eSkill::�����, eSkillUse::BattleOwner, eBuff::None, 125, -10, "�����", "ȫ�����쳣״̬", "80" },
	{ 0x82297D26, 0xF81CEDEA, 0x66150076, 0x00000000, 0xFBD946FB, eSkill::�����, eSkillUse::BattleOwner, eBuff::None, 150, -10, "�����", "ȫ�����쳣״̬���ָ�15%����Ѫ", "120" },
	{ 0x1FFC5C36, 0x6344D17A, 0x00000000, 0x00000000, 0xA0F588C2, eSkill::��λ1, eSkillUse::None, eBuff::None, 75, 0, "��λ", "	�� ", "75" },
	{ 0x03DF530E, 0x66D173C9, 0x00000000, 0x00000000, 0xA0F588C2, eSkill::��λ2, eSkillUse::None, eBuff::None, 40, 0, "��λ", "	��", "40" },
// 	{ 0x1FFC5C36, 0x6344D17A, 0x00000000, 0x00000000, 0xA0F588C2, eSkill::����֮��, eSkillUse::BattleOther, eBuff::None, 40, 0, "����֮��", "������ٵз�20%��Ѫ", "75" },
// 	{ 0x03DF530E, 0x66D173C9, 0x00000000, 0x00000000, 0xA0F588C2, eSkill::����֮��, eSkillUse::BattleOther, eBuff::None, 40, 0, "����֮��", "������ٵз�20%ħ��", "40" },

	{ 0x97A6B22C, 0x17D8A907, 0x5DE57BA4, 0x00000000, 0xCE582B31, eSkill::Ц��ص�, eSkillUse::BattleOther, eBuff::None, 40, 0, "Ц��ص�", "������ٵз�70���ŭ", "32" },
	{ 0x172AE1E0, 0x480A8A7D, 0x5DE57BA4, 0x00000000, 0x245321A8, eSkill::����ħ��, eSkillUse::BattleOther, eBuff::None, 60, 0, "����ħ��", "ȫ����ٵз�20���ŭ", "70" },
	{ 0xB7458413, 0x41A28BC6, 0x203B8C75, 0x00000000, 0x019B0A72, eSkill::Ұ��֮��, eSkillUse::BattleOwner, eBuff::None, 40, -10, "Ұ��֮��", "���幥+10%������ս������", "40" },
	{ 0xF77F8F63, 0x6C8D9D7E, 0x203B8C75, 0x00000000, 0x019B0A72, eSkill::ħ��֮ӡ, eSkillUse::BattleOwner, eBuff::None, 70, -10, "ħ��֮ӡ", "ȫ�幥+5%������ս������", "70" },
	{ 0xA7BB3439, 0x85849B5B, 0x38FD76EA, 0x00000000, 0x245321A8, eSkill::���֮��, eSkillUse::BattleOwner, eBuff::None, 40, 0, "���֮��", "�����+10%������ս������", "40" },
	{ 0xA767CFAB, 0x185C7768, 0x38FD76EA, 0x00000000, 0x245321A8, eSkill::ʥ��֮��, eSkillUse::BattleOwner, eBuff::None, 70, 0, "ʥ��֮��", "ȫ���+5%������ս������", "70" },
	{ 0xA85146A6, 0x9715FA32, 0xFE27EBCF, 0x00000000, 0xBF36842D, eSkill::���ƾ�, eSkillUse::BattleOwner, eBuff::None, 40, -10, "���ƾ�", "������+10%������ս������", "40" },
	{ 0x96370902, 0x6812F03B, 0xFE27EBCF, 0x00000000, 0xBF36842D, eSkill::Х���, eSkillUse::BattleOwner, eBuff::None, 70, -10, "Х���", "ȫ����+5%������ս������", "70" },
	{ 0x3CA34035, 0xCA17D132, 0x9B23F38E, 0x5C5C1544, 0x3BF3590C, eSkill::̫������, eSkillUse::BattleSelf, eBuff::None, 90, 0, "̫������", "�����ܵ��ķ����˺����� 3�غ�", "20" },
	{ 0xCC019475, 0x61F085F4, 0x9B23F38E, 0x5C5C1544, 0x3BF3590C, eSkill::�޺�����, eSkillUse::BattleOwner, eBuff::None, 150, 0, "�޺�����", "ȫ���ܵ��ķ����˺����� 3�غ�", "120" },
	{ 0x14FF0C1F, 0xA0830D94, 0x95065313, 0x547C4B68, 0x1A67E919, eSkill::������, eSkillUse::BattleOwner, eBuff::None, 120, 0, "������", "	���巴��50%���˺�3�غ�", "20" },
	{ 0x76F6DD9E, 0x68F4FE2B, 0xC183DB1E, 0xFAF4A2D4, 0x40701F91, eSkill::�����޷�, eSkillUse::BattleOwner, eBuff::None, 80, -10, "�����޷�", "���������+50% 5�غ�", "80" },
	{ 0x1A4D1A72, 0xDA23CB44, 0x81B4599F, 0x00000000, 0x426F46C8, eSkill::��������, eSkillUse::BattleOther, eBuff::None, 30, -10, "��������", "���幥-10%������ս������", "40" },
	{ 0x52CE6E52, 0xF7A055FD, 0x81B4599F, 0x00000000, 0x426F46C8, eSkill::�Ӷ�ʨ��, eSkillUse::BattleOther, eBuff::None, 70, -10, "�Ӷ�ʨ��", "	ȫ�幥-5%,������ս������", "70" },
	{ 0x2CD374B0, 0x5460F163, 0xD0EEC915, 0x00000000, 0x70F1E396, eSkill::�Ƽ���, eSkillUse::BattleOther, eBuff::None, 35, 0, "�Ƽ���", "�����-10%������ս������", "40" },
	{ 0x2CD374B0, 0x5460F163, 0xD0EEC915, 0x00000000, 0x70F1E396, eSkill::�����, eSkillUse::BattleOther, eBuff::None, 80, 0, "�����", "ȫ���-5%,������ս������", "70" },
	{ 0x264D9AC8, 0x8FF3DB32, 0xD1E593CE, 0x00000000, 0x70F1E396, eSkill::������, eSkillUse::BattleOther, eBuff::None, 35, -10, "������", "������-10%������ս������", "40" },
	{ 0x5E68270E, 0x79619181, 0xD1E593CE, 0x00000000, 0x70F1E396, eSkill::ͣ����, eSkillUse::BattleOther, eBuff::None, 80, -10, "ͣ����", "ȫ����-5%,������ս������", "70" },
	{ 0x1373420F, 0xFD99EDE1, 0x171544B2, 0x00000000, 0x4B800708, eSkill::��Ѫ��, eSkillUse::BattleOther, eBuff::None, 80, 0, "��Ѫ��", "������", "64" },
	{ 0x7F545B30, 0xF68EB551, 0xB1822745, 0x00000000, 0x4B800708, eSkill::�������, eSkillUse::BattleOther, eBuff::None, 50, 0, "�������", "��������", "20" },
	{ 0x896AAEED, 0x59DBD730, 0x00000000, 0x00000000, 0x00000000, eSkill::��λ3, eSkillUse::None, eBuff::None, 50, 0, "��", "	 ��", "50" },
	{ 0x8A479938, 0xB1392BC1, 0x00000000, 0x00000000, 0x00000000, eSkill::��λ4, eSkillUse::None, eBuff::None, 80, 0, "��", "	 ��", "80" },
	{ 0x51522BBB, 0x77A7C11E, 0x33084AA4, 0x00000000, 0x00000000, eSkill::�Ǳ�ʥ��, eSkillUse::BattleOwner, eBuff::None, 120, 0, "�Ǳ�ʥ��", "	ȫ����ȫ�������ι���", "120" },
	{ 0xF572DAB6, 0x356E1001, 0x4F116543, 0x00000000, 0x00000000, eSkill::������EX, eSkillUse::BattleOwner, eBuff::None, 40, 0, "������EX", "	����ָ�������12%+1000������Ѫ", "40" },
	{ 0xCC73C4CE, 0x1D81410E, 0x21FAE73F, 0x00000000, 0x00000000, eSkill::������˫, eSkillUse::BattleOther, eBuff::None, 80, 0, "������˫", "���幥�������ٶԷ�MP", "50" },
	{ 0x4607A98E, 0xCD0B7124, 0x00000000, 0x00000000, 0x00000000, eSkill::��λ5, eSkillUse::None, eBuff::None, 70, 0, "��", "	 ��", "70" },
	{ 0xD339140A, 0x76FDA5AC, 0x00000000, 0x00000000, 0x4B800708, eSkill::��Ѫ��2, eSkillUse::BattleOther, eBuff::None, 64, 0, "��Ѫ��2", "	����������", "64" },
	{ 0xA3D648B0, 0xFB726757, 0x00000000, 0x00000000, 0x4B800708, eSkill::�������EX, eSkillUse::BattleOther, eBuff::None, 80, 0, "�������EX", "	�������ӷ�������", "80" },
	{ 0x230AF78C, 0x044670C7, 0x00000000, 0x00000000, 0x4B800708, eSkill::��Ѫ��EX, eSkillUse::BattleOther, eBuff::None, 80, 0, "��Ѫ��EX", "	����������", "80" },
	{ 0x17C3EF40, 0x613B61A6, 0x00000000, 0x00000000, 0x104B1B46, eSkill::��λ6, eSkillUse::None, eBuff::None, 70, 0, "��", "	��", "70" },
	{ 0x9908B56E, 0x7635E819, 0xF224F08A, 0x00000000, 0x00000000, eSkill::���֮ǽ, eSkillUse::BattleOwner, eBuff::None, 100, 0, "���֮ǽ", "	ȫ����ȫ����һ�ι���", "100" },
	{ 0xCB65301D, 0xC352DA37, 0x1ADABFA6, 0xE43459EB, 0x40701F91, eSkill::��������, eSkillUse::BattleSelf, eBuff::None, 100, 0, "��������", "����ͷ�������+50%,ȥ��һ���쳣", "100" },
	{ 0x8521B2B4, 0x5F4E6740, 0xE1084D39, 0x00000000, 0x00000000, eSkill::�Ⱥ��ն�, eSkillUse::BattleOwner, eBuff::None, 150, -10, "�Ⱥ��ն�", "ȫ����Ѫ����", "120" },
	{ 0x918FB1D3, 0x3E505980, 0x95473D14, 0x00000000, 0x00000000, eSkill::Ѹ�����, eSkillUse::BattleOwner, eBuff::None, 20, 0, "Ѹ�����", "	���������ٶ�,���", "20" },

	// ��Ϣ 0xD9463A0C
	{ 0xB0E3E18B, 0x0900C9A1, 0x19C102D1, 0x56E05B32, 0x30D78CEF, eSkill::��ɨǧ��, eSkillUse::BattleOther, eBuff::None, 1, 0, "��ɨǧ��", "4����,ʹ�ú�����Ϣ1�غ�,HP����5%���޷�ʹ��", "CostHpMax" },
	{ 0x424D9459, 0xE3094CF3, 968268166, 0x2A2A0663, 0x39D047A5, eSkill::������, eSkillUse::BattleOther, eBuff::None, 0, 0, "������", "��Ϣһ�غϺ���ʱ����˺���,���к��ٶ�,�Զ�����Ŀ��", "" },
	{ 0xFE16E718, 0x6C23A98E, 0x00000000, 0x00000000, 0xED520CA0, eSkill::������, eSkillUse::None, eBuff::None, 0, 0, "������", "�����������·�(�һ�δ������װ��)", "��" },
	{ 0x66668C4F, 0x00CDE78F, 0x00000000, 0x00000000, 0x04E0F4C5, eSkill::ǧ������, eSkillUse::NormalSelf, eBuff::None, 10, 0, "ǧ������", "���͵�����", "5%HP" },
	{ 0x4F10E7C8, 0x63BE01CD, 0x94A5BEEC, 0x85B3D6F1, 0x00000000, eSkill::ɱ����, eSkillUse::BattleOwner, eBuff::Good, 40, 0, "ɱ����", "��������", "" },
	{ 0x44B0147F, 0x0262C795, 0x00000000, 0x00000000, 0x00000000, eSkill::ն����, eSkillUse::None, eBuff::None, 150, -10, "ն����", "�����������ӵı�ɱ��", "��" },
	{ 0x3225863C, 0x08BFC856, 0x6B934898, 0x00000000, 0x0B2ED764, eSkill::����֮��, eSkillUse::BattleOther, eBuff::Seal, 30, 0, "����֮��", "����ﴦ�ڻ���״̬", "50MP" },
	{ 0x24E57349, 0x5E31990A, 0x19C102D1, 0x56E05B32, 0x795E59BA, eSkill::�Ƹ�����, eSkillUse::BattleOther, eBuff::None, 1, 0, "�Ƹ�����", "ͬʱ�����Է�����Ŀ��,ʹ�ú�����Ϣ1�غ�,HP����5%���޷�ʹ��", "CostHpMax" },
	{ 0x8368E31C, 0xBBCA9C0B, 0x25F14A5E, 0x34999043, 0x095B5FC6, eSkill::�����, eSkillUse::BattleSelf, eBuff::Good, 30, -10, "�����", "��������", "30MP" },
	{ 0x3195E34C, 0x8B8E4258, 0x00000000, 0x00000000, 0x00000000, eSkill::��Ѫ, eSkillUse::NormalSelf, eBuff::None, 0, 0, "��Ѫ", "û�б�ʹ��", "��" },

	{ 0x05089B1C, 0x481EAFC6, 0x00000000, 0x00000000, 0x00000000, eSkill::������ħ, eSkillUse::None, eBuff::None, 150, -10, "������ħ", "����ħ��կ���ӵı�ɱ��", "��" },
	{ 0x4286DDD0, 0xB8F8B6A5, 0x387C1EEB, 0x00000000, 0xDDD270F5, eSkill::������, eSkillUse::BattleOther, eBuff::None, 30, -10, "������", "����Թ����2���˺�", "30MP" },
	{ 0x6B357065, 0x6A96181C, 0x00000000, 0x00000000, 0x00000000, eSkill::���з�, eSkillUse::NormalSelf, eBuff::None, 0, 0, "���з�", "��ֽ����", "��" },
	{ 0x78C38F19, 0x4B9630F1, 0x00000000, 0x00000000, 0xA309D8A4, eSkill::�����, eSkillUse::BattleSelf, eBuff::None, 0, 0, "�����", "��ս������ɹ���100%", "30MP" },
	{ 0x063EAFDB, 0xD209F99A, 0x9EC0624E, 3398426285, 0xAEABE4AC, eSkill::���߷�, eSkillUse::BattleOther, eBuff::Seal, 45, 0, "���߷�", "��������ܵ��˺�ǰ�޷��ж�", "40MP" },
	{ 0xCB1E4D52, 0x59CD3D34, 0x091ADDC7, 3635978625, 0x9A1A2884, eSkill::ʧ�ķ�, eSkillUse::BattleOther, eBuff::Seal, 60, 0, "ʧ�ķ�", "��ӡ���������ͷ�������", "40MP" },
	{ 0x795E9104, 0x5C948CFF, 0x4FB56243, 0x8B43833D, 0xF6BED451, eSkill::���Ƿ�, eSkillUse::BattleOther, eBuff::Seal, 0, 0, "���Ƿ�", "��ħ+��20%����", "40MP" },
	{ 0xA1343135, 0x5D26E373, 0xD4AA2F8A, 3946646209, 0xF6BED451, eSkill::ʧ���, eSkillUse::BattleOther, eBuff::Seal, 50, 0, "ʧ���", "�����һ���غ��޷�ʹ���ؼ�", "60MP" },
	{ 0x8F4B3740, 0x3CDC2403, 0xD4024676, 3655438388, 0xF6BED451, eSkill::׷���, eSkillUse::BattleOther, eBuff::Seal, 0, 0, "׷���", "������+����", "60MP" },
	{ 0xC7FE7637, 0x00007856, 0x1919B112, 1214058823, 0xF6BED451, eSkill::����, eSkillUse::BattleOther, eBuff::Seal, 0, 0, "����", "��ħ+�����", "40MP" },
	{ 0x8FF10842, 0x78F1ED7F, 0x7BCD8BC0, 2336457533, 0xF6BED451, eSkill::ʧ���, eSkillUse::BattleOther, eBuff::Seal, 0, 0, "ʧ���", "��ħ+����", "60MP" },
	{ 0x975DA9B5, 0x0A2B0270, 0xDE4E3A84, 2461182746, 0xF6BED451, eSkill::�����, eSkillUse::BattleOther, eBuff::Seal, 60, 0, "�����", "��ӡ�������ͷ�������", "60MP" },
	{ 0xB83BDC9B, 0x936F1197, 0x517656E2, 0x00000000, 0x04E42236, eSkill::��Ԫ��, eSkillUse::BattleSelf, eBuff::None, 20, 0, "��Ԫ��", "����ħ��ֵ�������Լ�����Ѫ", "20MP" },
	{ 0xB76A6542, 0xE6A885C3, 0x517656E2, 0x00000000, 0x04E42236, eSkill::������, eSkillUse::BattleSelf, eBuff::None, 20, 0, "������", "������Ѫ�������Լ���ħ��ֵ", "CostHpFix" },
	{ 0x784D72FE, 0xC53E6E37, 0x00000000, 0x00000000, 0x00000000, eSkill::Ǭ�����, eSkillUse::None, eBuff::None, 0, 0, "Ǭ�����", "û�б�ʹ��", "��" },
	{ 0x19FE3B00, 0x0441F7EC, 0x00000000, 0x00000000, 0xA309D8A4, eSkill::��ľ�ɶ�, eSkillUse::NormalSelf, eBuff::None, 10, 0, "��ľ�ɶ�", "���͵�����ɽ", "5%HP" },
	{ 0x559B2E13, 0x7D1F9844, 0x4B9ACA92, 0x00000000, 0x4644FF98, eSkill::������, eSkillUse::BattleSelf, eBuff::Good, 80, 0, "������", "���ӷ������", "50MP" },
	// 0x84FA9FA5 ��,���Ǽ� ״̬0x5525C5FB
	{ 0xBD46AEDE, 0x18E364D5, 0xCB3B68B8, 0xA5D7B0F7, 0xAEABE4AC, eSkill::��׷�, eSkillUse::BattleOther, eBuff::Bad, 100, -10, "��׷�", "���Ͷ��˷���������", "100MP" },
	{ 0xC05584C4, 0xCF367379, 0xC1731A60, 0x00000000, 0xDDD270F5, eSkill::���׷�, eSkillUse::BattleOther, eBuff::None, 30, 0, "���׷�", "����3��Ŀ��,�Թ���˺�����", "MPS" },
	{ 0xB8C8B3C0, 0x488BFA97, 0x00000000, 0x00000000, 0x00000000, eSkill::�������, eSkillUse::None, eBuff::None, 0, 0, "�������", "û�б�ʹ��", "��" },

	{ 0xE98C1B53, 0xD530DA11, 0x00000000, 0x00000000, 0x00000000, eSkill::��������, eSkillUse::None, eBuff::None, 0, 0, "��������", "û�б�ʹ��", "��" },
	{ 0x8D8B8C6C, 0x6EAE4C8A, 0xC12C2663, 0x00000000, 0xDBB88662, eSkill::��������, eSkillUse::BattleOther, eBuff::None, 20, 0, "��������", "������Ի��", "MPS" },
	{ 0xBAAB7B8B, 0x5458D4F3, 0x00000000, 0x00000000, 0x00000000, eSkill::��Ħ����, eSkillUse::None, eBuff::None, 0, 0, "��Ħ����", "û�б�ʹ��", "��" },
	{ 0xDC94C31C, 0x1C9BA3BB, 0x04DB6C0A, 0x00000000, 0xC0A21592, eSkill::��ջ���, eSkillUse::BattleOwner, eBuff::Good, 40, 0, "��ջ���", "���˼��˺�", "40��MP" },
	{ 0xAC27CC91, 0x7E6CCFA6, 0x434750DE, 0x85B3D6F1, 0xBF36842D, eSkill::Τ�ӻ���, eSkillUse::BattleOwner, eBuff::Good, 40, -10, "Τ�ӻ���", "���˼�����", "40��MP" },
	// 0x38C2146B ״̬ 916220457 
	{ 0xCDD65C55, 0x52161202, 0x9E4E9755, 0x369C6A29, 0xC0A21592, eSkill::��ջ���, eSkillUse::BattleOwner, eBuff::Good, 40, -10, "��ջ���", "���˼ӷ���", "30*N��MP" },
	// 0xF354CCB8
	{ 0x43C01A12, 0xA8430D24, 0x93CFD0AF, 0x061869D7, 0xBF36842D, eSkill::һέ�ɽ�, eSkillUse::BattleOwner, eBuff::Good, 40, 0, "һέ�ɽ�", "���˼��ٶ�", "40��MP" },
	{ 0x0FDF6352, 0x5C1B5CF9, 0x203B8773, 0x00000000, 0x97283C40, eSkill::�ҷ�ȱ�, eSkillUse::BattleOwner, eBuff::None, 150, 0, "�ҷ�ȱ�", "����", "150MP" },
	{ 0xFFA56FD1, 0x181BFB03, 0x573F92CA, 0x00000000, 0x04E42236, eSkill::����, eSkillUse::BothSelf, eBuff::None, 50, 0, "����", "�Լ�����+��Ѫ", "50MP" },
	{ 0xAACB2367, 0x9101EBA0, 0x03139F50, 0x00000000, 0x04E42236, eSkill::��Ѫ, eSkillUse::BothOwner, eBuff::None, 70, 0, "��Ѫ", "��������+��Ѫ+�ⶾ", "40MP" },
	{ 0x84BDDC3E, 0x39E390DD, 0xEF9691F3, 0x00000000, 0x04E42236, eSkill::��������, eSkillUse::BothOwner, eBuff::None, 100, 0, "��������", "���˼�Ѫ", "100��MP" },
	{ 0xAF367280, 0x18CD0456, 0xE869B98A, 0x00000000, 0x04E42236, eSkill::���ֻش�, eSkillUse::BothOwner, eBuff::None, 80, 0, "���ֻش�", "��������", "50MP" },
	// 0x28E639AA
	{ 0xF7CDB7B9, 0x79D35DAF, 0x7EEC276B, 0x00000000, 0x04E42236, eSkill::��������, eSkillUse::BothOwner, eBuff::None, 150, 0, "��������", "��������+��Ѫ", "150��MP" },
	{ 0x2091C150, 0x753893D8, 0xDE34B83E, 0x00000000, 0x57726FFB, eSkill::�ⶾ, eSkillUse::BattleOwner, eBuff::None, 40, 0, "�ⶾ", "�ⶾ+����+��Ѫ", "30MP" },
	{ 0xCC08B2F3, 0xB29DFB11, 0x00000000, 0x00000000, 0x084168D9, eSkill::�����ն�, eSkillUse::NormalSelf, eBuff::None, 0, 0, "�����ն�", "���͵�������", "5%HP" },
	{ 0x65C3D529, 0x43B4E620, 0xF0CE9045, 0x00000000, 0xCE259E8C, eSkill::����ȡ��, eSkillUse::BattleOwner, eBuff::None, 150, -10, "����ȡ��", "��Ŀ�굱ǰ��Ѫ�ָ�����,ÿ��ʹ�ý�������5%����,3%����", "150MP" },
	{ 0xB8C91B23, 0x884BB7B5, 0xC8011EF1, 3930943562, 0x3E128ADA, eSkill::���ޱ�, eSkillUse::BattleOwner, eBuff::Good, 150, -10, "���ޱ�", "����ӷ���������", "150MP" },
	{ 0xA95C700C, 0x0A9B60DA, 0x00000000, 0x00000000, 0x00000000, eSkill::�黨��ָ, eSkillUse::None, eBuff::None, 0, 0, "�黨��ָ", "û�б�ʹ��", "��" },

	{ 0x68C68B02, 0x20A5F3D0, 0x00000000, 0x00000000, 0x00000000, eSkill::��������, eSkillUse::None, eBuff::None, 0, 0, "��������", "û�б�ʹ��", "��" },
	{ 0x38C7C348, 0xE5042C42, 0x182CE63B, 0x72AD6DBA, 0xBDCD9588, eSkill::��������, eSkillUse::BattleSelf, eBuff::Good, 30, -10, "��������", "ֹͣ�ж��������Լ������˺�", "100MP" },
	{ 0x662EFA99, 0x875525A2, 0x9D5F7277, 0xDBCEE32C, 0xC99B2900, eSkill::���컨��, eSkillUse::BattleOther, eBuff::Poison, 40, -10, "���컨��", "���������ж�", "50MP" },
	{ 0x935E99ED, 0x712996D6, 0x00000000, 0x00000000, 0x00000000, eSkill::����޺�, eSkillUse::None, eBuff::None, 0, 0, "����޺�", "û�б�ʹ��", "��" },
	{ 0xFCF44944, 0xD11D8F4A, 0x00000000, 0x00000000, 0x00000000, eSkill::��������, eSkillUse::None, eBuff::None, 0, 0, "��������", "û�б�ʹ��", "��" },
	{ 0x4C8034D4, 0x71FC82F8, 0x8A39B79F, 0x00000000, 0xBDCD9588, eSkill::�绨����, eSkillUse::None, eBuff::None, 0, 0, "�绨����", "û�б�ʹ��", "��" },
	{ 0xD2123BE8, 0xA2DE2140, 0x46C7B776, 0x59D77EF9, 0xBDCD9588, eSkill::��������, eSkillUse::BattleOther, eBuff::Seal, 50, -10, "��������", "��ӡ�������ͷ���", "50MP" },
	{ 0x53B01707, 0x2DC6C0E7, 0x00000000, 0x00000000, 0x00000000, eSkill::��Ë���, eSkillUse::None, eBuff::None, 0, 0, "��Ë���", "û�б�ʹ��", "��" },
	{ 0x15E168DD, 0x01FF0F6F, 0x00000000, 0x00000000, 0x00000000, eSkill::�����ë, eSkillUse::None, eBuff::None, 0, 0, "�����ë", "û�б�ʹ��", "��" },
	{ 0x37F7C199, 0x02B4928E, 0x00000000, 0x00000000, 0x00000000, eSkill::�ٶ�����, eSkillUse::None, eBuff::None, 0, 0, "�ٶ�����", "û�б�ʹ��", "��" },
	{ 0x066D7389, 0x51A0423C, 0x00000000, 0x00000000, 0xFE189BCC, eSkill::���λ�Ӱ, eSkillUse::NormalSelf, eBuff::None, 0, 0, "���λ�Ӱ", "���͵�Ů����", "5%HP" },
	{ 0x1F215E91, 0xC2B106E9, 0x8A39B79F, 0x00000000, 0x51F82D7D, eSkill::һЦ���, eSkillUse::BattleOther, eBuff::None, 0, -10, "һЦ���", "���˷�ӡ����", "60*N��MP" },
	{ 0x74FF026F, 0xF2553F61, 0x00000000, 0x00000000, 0x00000000, eSkill::�ɻ�ժҶ, eSkillUse::None, eBuff::None, 0, 0, "�ɻ�ժҶ", "û�б�ʹ��", "��" },
	{ 0x21883613, 0x92F67200, 0x00000000, 0x00000000, 0x00000000, eSkill::���亮ɳ, eSkillUse::BattleOther, eBuff::None, 10, 0, "���亮ɳ", "�������˹���", "MPS" },

	{ 0xFA64E7B9, 0x81925D39, 0x00000000, 0x66CC7A29, 0x00000000, eSkill::������, eSkillUse::BattleSelf, eBuff::Good, 20, 10, "������", "ս���������Լ�������", "��" },
	{ 0xDF877E23, 0xF19A5EFA, 0x73604A57, 0x00000000, 0x00000000, eSkill::���񻤷�, eSkillUse::BattleOwner, eBuff::Good, 0, 0, "���񻤷�", "ս���б���ͬ��", "50MP" },
	{ 0xDC9BDA8C, 0xB3C8279C, 0x00000000, 0x00000000, 0x00000000, eSkill::�������, eSkillUse::None, eBuff::None, 0, 0, "�������", "û�б�ʹ��", "��" },
	{ 0x91EC4841, 0x0BB38F40, 0x00000000, 0x00000000, 0x00000000, eSkill::֪��֪��, eSkillUse::None, eBuff::None, 0, 0, "֪��֪��", "û�б�ʹ��", "��" },
	{ 0x74B29E7D, 0x9A155954, 0xDC756B6F, 0x00000000, 0x57726FFB, eSkill::����, eSkillUse::BattleOwner, eBuff::None, 0, 0, "����", "�������ĸ���Ч��", "50MP" },
	{ 0x0EF91062, 0xA82E9413, 0x1EB0026B, 0x98753F94, 0x318685B7, eSkill::����, eSkillUse::BattleOther, eBuff::Seal, 45, -10, "����", "��ӡ�ؼ�", "50MP" },
	{ 0xFFB5624B, 0xD7E76D2D, 0xD35FC051, 0x2F78C46E, 0x5703EB56, eSkill::����, eSkillUse::BattleOther, eBuff::Seal, 60, -10, "����", "��ӡ����", "50MP" },
	{ 0xFF5FCC5F, 0xBB32CB83, 0x8B8516F1, 0xC48ABA7B, 0x318685B7, eSkill::�������, eSkillUse::BattleOther, eBuff::Seal, 60, -10, "�������", "��ӡ������", "50MP" },
	{ 0x360B497C, 0x72BB2C70, 0x00000000, 0x00000000, 0xA12CF973, eSkill::���Ƽ���, eSkillUse::NormalSelf, eBuff::None, 0, 0, "���Ƽ���", "���͵��칬", "5%HP" },
	{ 0x391FBBEB, 0x12CFF6C1, 0x4C117B7C, 0x00000000, 0x251670FB, eSkill::����ն, eSkillUse::BattleOther, eBuff::None, 30, -10, "����ն", "ʹ�ú���Ը�������ػ������������������Լ�Ҳ��������������", "MPS" },
	{ 0x6CD25687, 0xFC7CEE47, 0xFFD64CCA, 0x00000000, 0xDB4F9338, eSkill::���׺䶥, eSkillUse::BattleOther, eBuff::None, 50, -10, "���׺䶥", "�м���ȥ������25%����Ѫ��ħ��", "50MP" },
	{ 0x6794F727, 0xF979C506, 0x00000000, 0x00000000, 0x00000000, eSkill::�����, eSkillUse::None, eBuff::None, 0, 0, "�����", "û�б�ʹ��", "��" },
	{ 0x7B003972, 0x45909EE4, 0x911E3921, 0x00000000, 0x040584F3, eSkill::�������, eSkillUse::BattleOther, eBuff::None, 35, 0, "�������", "���˷���", "MPS" },
	{ 0x21D77976, 0xCDA1A3A3, 0x00000000, 0x00000000, 0x00000000, eSkill::��Ȼ����, eSkillUse::None, eBuff::None, 0, 0, "��Ȼ����", "û�б�ʹ��", "��" },
	{ 0x5DF74259, 0x2D863D2A, 0x752464D7, 0x00000000, 0x318685B7, eSkill::������, eSkillUse::None, eBuff::Good, 0, 0, "������", "û�б�ʹ��", "��" },

	{ 0x6BB78F2A, 0x984CF938, 0xDC756B6F, 0x00000000, 0x57726FFB, eSkill::���, eSkillUse::BattleOwner, eBuff::None, 0, 0, "���", "���", "80MP" },
	{ 0xD4647700, 0x01590DDC, 0xDE34B83E, 0x00000000, 0x57726FFB, eSkill::����, eSkillUse::BattleOwner, eBuff::None, 30, 0, "����", "�ⶾ", "��" },
	{ 0xD9935972, 0x7CC5EF28, 0x7367AF0F, 0x00000000, 0x5505BC3C, eSkill::����, eSkillUse::BattleOther, eBuff::None, 30, -10, "����", "����ˮ���Է���", "50MP" },
	{ 0x3236D5E1, 0x0C054889, 0xA19EAB31, 0x00000000, 0xA39B4CA3, eSkill::�������, eSkillUse::BattleOther, eBuff::None, 20, 0, "�������", "Ⱥ��ˮ/�����Է���", "MPS" },
	{ 0xE2C973B2, 0x5905DEC6, 0x04DB6C0A, 0x00000000, 0xC0A21592, eSkill::����, eSkillUse::BattleSelf, eBuff::Good, 20, 0, "����", "�����˺�", "10MP" },
	{ 0xC06DBC74, 0x055E6A6D, 0x00000000, 0x00000000, 0x00000000, eSkill::�˷�����, eSkillUse::None, eBuff::None, 0, 0, "�˷�����", "û�б�ʹ��", "��" },
	{ 0x9F38CFD7, 0x238F9C1B, 0x00000000, 0x00000000, 0x64AAF170, eSkill::ˮ��, eSkillUse::NormalSelf, eBuff::None, 0, 0, "ˮ��", "���͵�����", "5%HP" },
	{ 0x7F6E6C02, 0x4E96B443, 0x48639CF5, 0x00000000, 0xA08D7D31, eSkill::����, eSkillUse::BattleOther, eBuff::None, 30, 0, "����", "ȫ��̶��˺�������", "50MP" },
	{ 0x7EA52AB5, 0xD93D4F3D, 0x00000000, 0x00000000, 0x00000000, eSkill::��Х����, eSkillUse::None, eBuff::None, 0, 0, "��Х����", "û�б�ʹ��", "��" },
	{ 0x6A643D2E, 0xAC322FAD, 0x00000000, 0x00000000, 0x00000000, eSkill::����, eSkillUse::None, eBuff::None, 0, 0, "����", "û�б�ʹ��", "��" },
	{ 0x975B5587, 0x5D2392F9, 0xF483EB13, 0x4CCDACCB, 0x00000000, eSkill::������β, eSkillUse::BattleSelf, eBuff::Good, 100, -10, "������β", "����20%�����ܵ������˺�", "��" },
	{ 0x2598BAD0, 0x4B78F4EA, 0xA680A821, 0x00000000, 0x6F872F79, eSkill::����Ϸ��, eSkillUse::BattleOther, eBuff::None, 70, 0, "����Ϸ��", "˫�巨��", "100MP" },

	{ 0xCFF9CA32, 0xE8A1FA06, 0xA70D1263, 0x313BCC79, 0xA7B1C535, eSkill::����Ǭ��, eSkillUse::BattleOther, eBuff::Seal, 35, -10, "����Ǭ��", "��ӡ�������ͷ������ؼ�", "50MP" },
	{ 0x6484CE2C, 0x8EBBB9ED, 0x3648247E, 0x719D767F, 0x24A434E5, eSkill::��������, eSkillUse::BattleOwner, eBuff::Good, 30, 10, "��������", "��������", "CostHpFix" },
	{ 0xA4558B86, 0x4126939F, 0xD2DC9AD3, 0xF8EE853A, 0x24A434E5, eSkill::����֮Ȫ, eSkillUse::BattleOwner, eBuff::Good, 30, 10, "����֮Ȫ", "������Ѫ", "MPS" },
	{ 0x630B9900, 0x6347C97B, 0x00000000, 0x00000000, 0x00000000, eSkill::̫������, eSkillUse::None, eBuff::None, 0, 0, "̫������", "û�б�ʹ��", "��" },
	{ 0x2714CD4D, 0x785A5F32, 0x00000000, 0x00000000, 0x9197B5A6, eSkill::��ת����, eSkillUse::NormalSelf, eBuff::None, 0, 0, "��ת����", "���͵���ׯ��", "5%HP" },
	{ 0xBBCF26FE, 0xE34DD120, 0x775FD2E3, 0x00000000, 0x24A434E5, eSkill::�����۶�, eSkillUse::BattleSelf, eBuff::None, 30, 0, "�����۶�", "�������", "CostHpFix" },
	{ 0x271F24E1, 0x4C8E9F62, 0x00000000, 0x00000000, 0x00000000, eSkill::��ħ, eSkillUse::None, eBuff::None, 0, 0, "��ħ", "û�б�ʹ��", "��" },
	{ 0x2097EBF0, 0x4919A4E5, 0xDE34B83E, 0x00000000, 0x57726FFB, eSkill::��ʬ, eSkillUse::BattleOwner, eBuff::None, 40, 0, "��ʬ", "��������ж�״̬", "��" },
	// ���򶯻� 0xD06119B3 0xC29A0737
	{ 0xD9249EC5, 0xBA3CC9E9, 0xA3FD9577, 0x00000000, 0x30D78CEF, eSkill::���꽣��, eSkillUse::BattleOther, eBuff::None, 50, 0, "���꽣��", "������", "50MP" },
	{ 0xCA8F3E1A, 0xC2D517D6, 0x66BEBCBA, 0x00000000, 0x00000000, eSkill::Ʈ��ʽ, eSkillUse::BattleOther, eBuff::None, 30, 0, "Ʈ��ʽ", "����������", "MPS" },
	{ 0x00000000, 0xFBC5D873, 0x00000000, 0x00000000, 0x00000000, eSkill::���ͬ��, eSkillUse::BattleOwner, eBuff::Good, 50, 0, "���ͬ��", "ΪĿ����ʱ����һ����������,����ȫ�������˺�,����Ŀ��50%����Ч��,�����������˺���ӱ�", "��" },
	{ 0xC464481B, 0x6779E3D4, 0x00000000, 0x00000000, 0x00000000, eSkill::Ǭ���, eSkillUse::None, eBuff::None, 0, 0, "Ǭ���", "û�б�ʹ��", "��" },
	{ 0x951F8360, 0xFDC44BC0, 0x00000000, 0x00000000, 0x00000000, eSkill::һ��������, eSkillUse::None, eBuff::None, 0, 0, "һ��������", "û�б�ʹ��", "��" },
	
	{ 0xCB1639D1, 0x290BF9E7, 0x2FF74578, 0xD8857128, 0x2550B4D0, eSkill::�ն�����, eSkillUse::BattleOwner, eBuff::Good, 50, -10, "�ն�����", "������Ѫ", "50MP" },
	// 0x5480C749
	{ 0x3908C648, 0x5DC3D631, 0x1EA5FACC, 0xEFE73EB9, 0xD00F519D, eSkill::������, eSkillUse::BattleOther, eBuff::Bad, 50, -10, "������", "�����Ѫ������", "50MP" },
	{ 0x2F5AFA7D, 0xDFF28692, 0x380337C1, 0xD8857128, 0xA4B9B11E, eSkill::������¶, eSkillUse::BattleOwner, eBuff::None, 150, -10, "������¶", "����,�����������������ٻ�", "150MP" },
	{ 0x34464142, 0x7B080559, 0x45CA9913, 0x00000000, 0xCE259E8C, eSkill::�չ⻪, eSkillUse::BattleOther, eBuff::None, 50, 0, "�չ⻪", "Ⱥ��������˺�", "50MP" },
	{ 0x6A4D383D, 0x9FB86B6A, 0x6C5F8376, 0x00000000, 0xE957CD44, eSkill::��׺�, eSkillUse::BattleOther, eBuff::None, 50, -10, "��׺�", "Ⱥ��ˮ�����˺�", "50MP" },
	{ 0xE38F0541, 0xBFD75298, 0xDF4C3BE3, 0x00000000, 0x52BA8E8D, eSkill::������, eSkillUse::BattleOther, eBuff::None, 50, -10, "������", "Ⱥ���������˺�", "50MP" },
	{ 0x8C6D506B, 0x493EEC97, 0x9CCB6E84, 0x00000000, 0x251670FB, eSkill::��ã��, eSkillUse::BattleOther, eBuff::None, 50, 0, "��ã��", "Ⱥ��ľ�����˺�", "50MP" },
	{ 0x047A00A7, 0xF64BED47, 0x18E13BE9, 0x00000000, 0x1366C86B, eSkill::���ѻ�, eSkillUse::BattleOther, eBuff::None, 50, -10, "���ѻ�", "Ⱥ��������˺�", "50��" },
	{ 0xE57C320E, 0x92CACF3B, 0x00000000, 0x00000000, 0xEFB621F4, eSkill::����, eSkillUse::NormalSelf, eBuff::None, 0, 0, "����", "���Դ��͵�����ɽ", "��" },
	{ 0xDEE056A8, 0x133CEEA4, 0x00000000, 0x00000000, 0x00000000, eSkill::���д�λ, eSkillUse::None, eBuff::None, 0, 0, "���д�λ", "û�б�ʹ��", "��" },
	{ 0x728DE1CD, 0x890CE894, 0xAB5DAE52, 0x95FF4460, 0x2550B4D0, eSkill::�鶯����, eSkillUse::BattleOwner, eBuff::Good, 30, 0, "�鶯����", "Ⱥ�����", "100MP" },
	// 0x5A07D50A ״̬0x4DDF5690
	{ 0xD78FBB42, 0x6E44BE66, 0x88F19652, 0x2D1E688F, 0xA37E8B19, eSkill::�ߵ�����, eSkillUse::BattleOwner, eBuff::Good, 80, -10, "�ߵ�����", "���ӷ���������", "80MP" },
	{ 0x87C2F0D2, 0xF17355F3, 0x00000000, 0x00000000, 0x00000000, eSkill::�����, eSkillUse::None, eBuff::None, 0, 0, "�����", "û�б�ʹ��", "��" },
	{ 0xCBD97FD0, 0x477948A0, 0x77592664, 0x00000000, 0x00000000, eSkill::�����ķ�, eSkillUse::BattleOwner, eBuff::None, 30, 0, "�����ķ�", "�����ն�����", "��" },

	{ 0xCD73E07C, 0xA7459134, 0x9EB11259, 0x00000000, 0x12A308C0, eSkill::������, eSkillUse::BattleOther, eBuff::None, 20, -10, "������", "���ٶ��ֵ���Ѫ����Ѫ����", "MPS" }, //,ҹ����Ч�����ڰ���,�Թ����˺��ӱ�
	{ 0xDCABAFAD, 0x63A83981, 0x241C668A, 0x00000000, 0xB6A8CB18, eSkill::�й���, eSkillUse::BattleOther, eBuff::None, 20, 0, "�й���", "���ٶ��ֵ���Ѫ��ħ��", "30��" }, //,��ҹʹ��Ч��Ϊ��׼��130%
	{ 0x80305F4B, 0xF2D2EB2F, 0x00000000, 0x00000000, 0xED520CA0, eSkill::������, eSkillUse::None, eBuff::None, 0, 0, "������", "��������,ͷ��,Ь,����(�һ�δ������װ��)", "��" },
	{ 0x1CC4C18F, 0x26F78E1F, 0xDC756B6F, 0x00000000, 0x00000000, eSkill::������, eSkillUse::BattleOwner, eBuff::None, 0, 0, "������", "���", "50MP" },
	{ 0xA7592BE7, 0x75C1605A, 0x07DF52CA, 0x21435203, 0xFBA099F0, eSkill::��ڤ����, eSkillUse::BattleOwner, eBuff::Good, 20, 0, "��ڤ����", "ʹ�ú���Կ��������Ŀ�겢����10%�Ŀ���Ч��", "MPS" },
	{ 0x167366B6, 0xD5CE79DD, 0x00000000, 0x00000000, 0x00000000, eSkill::ԩ�겻ɢ, eSkillUse::None, eBuff::None, 0, 0, "ԩ�겻ɢ", "û�б�ʹ��", "��" },
	{ 0x8AC6F05B, 0x02ED1F1B, 0x849E48FB, 0x839CC29A, 0x98BDEC63, eSkill::ʬ����, eSkillUse::BattleOther, eBuff::Poison, 40, -10, "ʬ����", "�����ж�����������Ѫ", "40MP" },
	{ 0xB759D696, 0x213794E1, 0xBA7D5CD7, 0x00000000, 0x00000000, eSkill::��������, eSkillUse::BattleOwner, eBuff::None, 150, 0, "��������", "��������", "150MP" },
	{ 0x2C0D5A09, 0x7A2AE74E, 0x00000000, 0x00000000, 0xBB1E59E8, eSkill::������Ѷ, eSkillUse::NormalSelf, eBuff::None, 0, 0, "������Ѷ", "���Դ��͵��ظ�", "5%HP" },
	{ 0x1CEE0599, 0xAB58943F, 0x380337C1, 0x00000000, 0x97283C40, eSkill::������, eSkillUse::BattleOwner, eBuff::None, 150, -10, "������", "����+�˺�", "150MP" },
	// ״̬ 0x5ECEBEDD
	{ 0x70D5CD29, 0xD2D21A8B, 0x2611E02E, 0x69180378, 0xBF36842D, eSkill::��Ȫ֮Ϣ, eSkillUse::BattleOther, eBuff::Bad, 50, -10, "��Ȫ֮Ϣ", "�����Է�����,��������һ�����ٶ�", "80MP" }, //,ҹ��ʹ��Ч������Ϊ�����130%
	{ 0xA21E0165, 0x5F0B6F6D, 0x057B7209, 0x00000000, 0x814AE8F4, eSkill::�����ɢ, eSkillUse::BattleOther, eBuff::None, 40, -10, "�����ɢ", "��ɢĿ�������״̬", "80MP" },
	{ 0xD3076E45, 0xE451BF95, 0x00000000, 0x00000000, 0x00000000, eSkill::ʬ������, eSkillUse::None, eBuff::None, 0, 0, "ʬ������", "û�б�ʹ��", "��" },
	{ 0x2EC10ADD, 0x66F5816E, 0x5C0073EE, 0xE02F2E6D, 0x7FDACB76, eSkill::������, eSkillUse::BattleOther, eBuff::None, 50, 0, "������", "�����ٻ�", "50MP" },

	{ 0xE13663E9, 0x37E0D423, 0x00000000, 0x00000000, 0x00000000, eSkill::ħ������, eSkillUse::None, eBuff::None, 0, 0, "ħ������", "û�б�ʹ��", "��" },
	{ 0x2C7FBCD6, 0x2A16BFD0, 0x4DB67680, 0x00000000, 0x550EEC3F, eSkill::��ɰ��ʯ, eSkillUse::BattleOther, eBuff::None, 30, 0, "��ɰ��ʯ", "Ⱥ���������˺�", "MPS" },
	{ 0x114F1F2C, 0x25526F4E, 0xFCDCCCEC, 0x00000000, 0xF4A86696, eSkill::�������, eSkillUse::BattleOther, eBuff::None, 30, -10, "�������", "����������˺�", "30MP" },
	{ 0x4062BFE4, 0xD1EC7AD9, 0x6EA4246E, 0xA168E26F, 0xED47E570, eSkill::ţ��, eSkillUse::BattleSelf, eBuff::Good, 20, 0, "ţ��", "���������˺���", "50MP" },
	{ 0xA7AC77E0, 0xF20648E8, 0x00000000, 0x00000000, 0x00000000, eSkill::̤ɽ��ʯ, eSkillUse::None, eBuff::None, 0, 0, "̤ɽ��ʯ", "û�б�ʹ��", "��" },
	{ 0x35C31747, 0xE7D2A6F9, 0x00000000, 0x00000000, 0x40E67E07, eSkill::�޵�ţʭ, eSkillUse::BattleSelf, eBuff::None, 40, 0, "�޵�ţʭ", "������ֻ��ͬʱ����һֻţʭ��ţ��", "��" },
	{ 0xA5385E3B, 0x1F68ADCC, 0x00000000, 0x00000000, 0x40E67E07, eSkill::�޵�ţ��, eSkillUse::BattleSelf, eBuff::None, 40, 0, "�޵�ţ��", "������ֻ��ͬʱ����һֻţʭ��ţ��", "��" },
	{ 0xB56E84D0, 0x3B5C1425, 0x16B27FFC, 0xBBEA83F4, 0x00000000, eSkill::ħ������, eSkillUse::BattleSelf, eBuff::None, 30, 0, "ħ������", "ʹ�ú�������ܵ���������ʱ���Զ�����", "��" },
	{ 0x27D50D56, 0x93EA969B, 0x00000000, 0x00000000, 0x14E55AF2, eSkill::ţʺ��, eSkillUse::NormalSelf, eBuff::None, 0, 0, "ţʺ��", "���Դ��͵�ħ��կ", "5%HP" },
	{ 0xC02762DD, 0x902C43A8, 0x00000000, 0x00000000, 0x00000000, eSkill::�����, eSkillUse::None, eBuff::None, 0, 0, "�����", "û�б�ʹ��", "��" },
	{ 0x69F9FFD0, 0xB5DC536F, 0x00000000, 0x00000000, 0x00000000, eSkill::ҡͷ��β, eSkillUse::None, eBuff::None, 0, 0, "ҡͷ��β", "û�б�ʹ��", "��" },

	{ 0x067DDF53, 0xBD3FF07D, 0xBE127823, 0x3646A4D9, 0x7CFA5491, eSkill::����, eSkillUse::BattleOther, eBuff::None, 50, 0, "����", "�������˲������»غ��޷��ж�,����ȡ��(��Ҫ����)", "30MP" },
	{ 0x56070FE9, 0xBFE91154, 2194212682, 0x58628406, 0x61688718, eSkill::ӥ��, eSkillUse::BattleOther, eBuff::None, 30, 0, "ӥ��", "�����Է�����,ʹ�ú�һ�غ����޷�ʹ�÷���(��Ҫ����)", "MPS" },
	{ 0x60FFC2C8, 0xDC90DF2F, 0x718754A2, 0x00000000, 0xF3626BEC, eSkill::ʨ��, eSkillUse::BattleOther, eBuff::None, 30, 0, "ʨ��", "�˺���������(��Ҫ����)", "30MP" },
	{ 0x35532015, 0x04DA6E6F, 0x8476181B, 0x20FCCE94, 0x019B0A72, eSkill::����, eSkillUse::BattleOther, eBuff::Seal, 20, 0, "����", "����������ٻ����޷��ж�,���ܶ����ʹ��", "40MP" },
	{ 0xDA9CD712, 0xFF4048E9, 0x29D819DF, 0x85C9AF08, 0xB90610BF, eSkill::����, eSkillUse::BattleSelf, eBuff::None, 20, 0, "����", "���Ρ�ӥ����ʨ������������ǰ��", "20MP" },
	{ 0x430D0B1B, 0x38AB6F30, 0x00000000, 0x00000000, 0x00000000, eSkill::ħ��Х��, eSkillUse::None, eBuff::None, 0, 0, "ħ��Х��", "û�б�ʹ��", "��" },
	{ 0x05EFA897, 0xEDB77B1D, 755485932, 0x566DC0F3, 0x40701F91, eSkill::������, eSkillUse::BattleSelf, eBuff::Good, 40, 0, "������", "��������", "40MP" },
	{ 0x28256D06, 0xD7187347, 0x55EBCA6C, 0x58628406, 0x2FFC7F8A, eSkill::������, eSkillUse::BattleOther, eBuff::None, 30, 0, "������", "��������,ʹ�ú�һ�غ����޷�ʹ�÷���(��Ҫ����)", "MPS" },
	{ 0xF800E231, 0xD1561312, 0x00000000, 0x00000000, 0x35B1FE83, eSkill::���ǧ��, eSkillUse::NormalSelf, eBuff::None, 0, 0, "���ǧ��", "���Դ��͵�ʨ����", "5%HP" },
	{ 0xABF46236, 0x15AC16AF, 0x16B27FFC, 0xBBEA83F4, 0x6961CB02, eSkill::���ȷ��, eSkillUse::BattleSelf, eBuff::Good, 30, 0, "���ȷ��", "�ܵ�������ʱ���Զ���������", "30MP" },
	{ 0x2EEC86A4, 0xD92455F2, 0x00000000, 0x00000000, 0x00000000, eSkill::ħϢ��, eSkillUse::None, eBuff::None, 0, 0, "ħϢ��", "û�б�ʹ��", "��" },
	{ 0x93A98451, 0xA1B84C64, 0x3105A01B, 0x3D3FA597, 0x1C7EE63E, eSkill::��ħ����, eSkillUse::BattleSelf, eBuff::None, 0, 0, "��ħ����", "�������Ѫ����", "50MP" },
	{ 0xE78A87A1, 0xE30F693F, 0x00000000, 0x00000000, 0x00000000, eSkill::��������, eSkillUse::None, eBuff::None, 0, 0, "��������", "û�б�ʹ��", "��" },
	
	{ 0x2FD480B4, 0xC6AB6795, 0x1B472F2F, 0x00000000, 0xC0942A07, eSkill::����, eSkillUse::BattleOther, eBuff::None, 40, 0, "����", "���ٶԷ���Ѫ,�ָ�������Ѫ", "40MP" },
	{ 0x06294FA0, 0xA42F7249, 0x59BD69F1, 0x00000000, 0xC0942A07, eSkill::����, eSkillUse::BattleOther, eBuff::None, 35, 0, "����", "���ٶԷ�ħ��,�ָ�����ħ��", "40MP" },
	{ 0x5CACF37F, 0x01E94239, 0x78246FE4, 0xC4AA8E18, 0xE6F9B619, eSkill::ħ�����, eSkillUse::BattleOther, eBuff::Seal, 40, 0, "ħ�����", "�����һ���غ����޷��ָ���Ѫ������", "35MP" },
	{ 0x16C75EF8, 0x7C23B1B8, 0x00000000, 0x00000000, 0x00000000, eSkill::��˿��, eSkillUse::None, eBuff::None, 0, 0, "��˿��", "û�б�ʹ��", "��" },
	{ 0xC2CD06E2, 0x0D916626, 0x00000000, 0x00000000, 0x00000000, eSkill::������˿, eSkillUse::None, eBuff::None, 0, 0, "������˿", "û�б�ʹ��", "��" },
	{ 0x9A5880DC, 0xF50D8C5A, 0x5363AF2D, 0x8103AFD2, 0x7F5FD02A, eSkill::��������, eSkillUse::BattleOther, eBuff::Seal, 50, -10, "��������", "��ӡ�������ͷ���", "40MP" },
	{ 0x6974146E, 0x8EC63F2A, 0x7CD9C342, 0x369C6A29, 0xA37E8B19, eSkill::��˿��, eSkillUse::BattleSelf, eBuff::Good, 40, 0, "��˿��", "���������������", "50MP" },
	{ 0xAB18B4B0, 0x086B8CFF, 0xDC756B6F, 0x00000000, 0x5007BB0C, eSkill::����, eSkillUse::BattleSelf, eBuff::None, 0, 0, "����", "��������ӡ���쳣", "30MP" },
	{ 0x56DE11A1, 0x628E8D59, 0x8F3E73D5, 0xD671B65E, 0x13848F75, eSkill::���޵���, eSkillUse::BattleOther, eBuff::Seal, 30, -10, "���޵���", "Ⱥ���˺�+������", "MPS" },
	{ 0x6BB35F00, 0x4C7CC844, 0x00000000, 0x00000000, 0x95C06373, eSkill::���˿, eSkillUse::NormalSelf, eBuff::None, 0, 0, "���˿", "���Դ��͵���˿��", "5%HP" },
	{ 0x1DEE311E, 0x0286F483, 0x00000000, 0x00000000, 0xC0942A07, eSkill::����ͬ��, eSkillUse::BattleOther, eBuff::None, 0, 0, "����ͬ��", "����", "60MP" },
	{ 0xE63FB407, 0xB5243050, 0x00000000, 0x00000000, 0x00000000, eSkill::����, eSkillUse::None, eBuff::None, 0, 0, "����", "û�б�ʹ��", "��" },
	{ 0x241E44A3, 0x43A1A964, 0x0732894C, 0xCDE5D209, 0x245321A8, eSkill::�þ���, eSkillUse::BattleSelf, eBuff::Good, 50, 0, "�þ���", "�����ܵ��ķ����˺�", "80MP" },

	{ 0x1C603FAE, 0xF4DCF38F, 0x00000000, 0x00000000, 0x00000000, eSkill::��ʯ, eSkillUse::BattleOther, eBuff::None, 50, 0, "��ʯ", "��ʱ������ɱ���ʶԵ������˽���������,����1��ս��ֵ", "" },
	{ 0x5C95AF41, 0x5AA54949, 0x00000000, 0x00000000, 0x00000000, eSkill::������, eSkillUse::BattleOther, eBuff::None, 50, 0, "������", "��ʱ������ɱ���ʶԵ������˽���2��������", "����1ս��" },
	{ 0x4C99C220, 0x9ADAEA80, 0x00000000, 0x00000000, 0x00000000, eSkill::�������, eSkillUse::BattleOther, eBuff::None, 50, 0, "�������", "��ʱ������ɱ���ʶԵ������˽���3��������", "����2ս��" },
	{ 0x1A289BEA, 0xCE61D91C, 0x00000000, 0x00000000, 0x00000000, eSkill::��ӿ, eSkillUse::BattleOther, eBuff::None, 20, 0, "��ӿ", "�Զ�����˽���������,����1��ս��ֵ", "MPS" },
	{ 0xBE11779C, 0xB91C6953, 0x00000000, 0x00000000, 0x00000000, eSkill::����ŭ, eSkillUse::BattleOther, eBuff::None, 20, -10, "����ŭ", "����һ���˺����Զ�����˽���������", "����1ս��,MPS" },
	{ 0x11879028, 0x26419C11, 0x00000000, 0x00000000, 0x00000000, eSkill::��������, eSkillUse::BattleOther, eBuff::None, 20, 0, "��������", "����һ���˺����Զ�����˽���������", "����3ս��,MPS" },
	{ 0x956BA0A2, 0x569D01F7, 0x00000000, 0x00000000, 0x00000000, eSkill::����, eSkillUse::BattleOther, eBuff::None, 0, 0, "����", "", "" },
	{ 0x00000000, 0x4AB6831C, 0x00000000, 0x00000000, 0x00000000, eSkill::ָ�سɸ�, eSkillUse::None, eBuff::None, 0, 0, "ָ�سɸ�", "", "" },
	{ 0x38C47290, 0xD96F2331, 0x00000000, 0x00000000, 0x00000000, eSkill::������ɽ, eSkillUse::BattleSelf, eBuff::Good, 150, -10, "������ɽ", "ʹ�ú���������ܵ��ķ����˺��������˺�", "" },
	{ 0x5F8D7935, 0x136442C0, 0x00000000, 0x00000000, 0x00000000, eSkill::���Ǿ�, eSkillUse::BattleOwner, eBuff::Good, 30, 10, "���Ǿ�", "���������˺����", "" },
	{ 0xF808DCC6, 0x9E1580AA, 0x00000000, 0x00000000, 0x00000000, eSkill::����, eSkillUse::BattleOwner, eBuff::Good, 5, 10, "����", "���������ɱ����", "CostHp" },
	{ 0x00E0D005, 0xB7E814EE, 0x00000000, 0x00000000, 0x00000000, eSkill::�����ƿ�, eSkillUse::None, eBuff::None, 0, 0, "�����ƿ�", "", "" },
	{ 0x76FBBEEC, 0xAFDB81A4, 0x00000000, 0x00000000, 0x00000000, eSkill::�������, eSkillUse::BattleOwner, eBuff::None, 0, 0, "�������", "", "" },
	{ 0xFEF5D678, 0xE6A2AA59, 0x00000000, 0x00000000, 0x00000000, eSkill::�ݵؽ��, eSkillUse::NormalSelf, eBuff::None, 0, 0, "�ݵؽ��", "���Դ��͵��貨��", "" },

	{ 0x85DC4B33, 0x173015AE, 0x00000000, 0x00000000, 0x00000000, eSkill::�ƻ껯��, eSkillUse::BattleOwner, eBuff::Good, 10, -10, "�ƻ껯��", "����������ѪʹĿ������ѪЧ��", "CostHpMax" },
	{ 0x076EA85A, 0x62221B56, 0x00000000, 0x00000000, 0x00000000, eSkill::������, eSkillUse::BattleOther, eBuff::Seal, 30, -10, "������", "��Ŀ��һ���غ����޷�ʹ�÷���", "" },
	{ 0x28D6DCD8, 0xC0504605, 0x00000000, 0x00000000, 0x00000000, eSkill::ɷ����, eSkillUse::BattleOther, eBuff::None, 0, 0, "ɷ����", "", "" },
	{ 0x71307D22, 0xC232A281, 0x00000000, 0x00000000, 0x00000000, eSkill::������, eSkillUse::BattleOther, eBuff::None, 0, 0, "������", "", "" },
	{ 0xD6A5B20C, 0x1CC2B0B0, 0x00000000, 0x00000000, 0x00000000, eSkill::������, eSkillUse::BattleOther, eBuff::Bad, 100, 0, "������", "ʹ�з�2��Ŀ���ٶȽ���", "" },
	{ 0xA9AF9E72, 0x2A3E7A3C, 0x00000000, 0x00000000, 0x00000000, eSkill::������, eSkillUse::BattleOther, eBuff::None, 20, -10, "������", "ʹ�ù̶��˺������Է�����", "MPS" },
	{ 0x59D84304, 0x54DB6CDE, 0x00000000, 0x00000000, 0x00000000, eSkill::���ⱦ��, eSkillUse::BattleOwner, eBuff::None, 100, 0, "���ⱦ��", "ʹ��������һ���غ��ڳ��ܵ������˺��������", "" },
	{ 0xFE884980, 0x1BE322B2, 0x00000000, 0x00000000, 0x00000000, eSkill::��������, eSkillUse::BattleOwner, eBuff::None, 100, 0, "��������", "ʹ��������һ���غ��ڳ��ܵķ����˺��������", "" },
	{ 0x86AE37EA, 0x40FB7647, 0x00000000, 0x00000000, 0x00000000, eSkill::��ӿ����, eSkillUse::BattleOwner, eBuff::None, 3, -10, "��ӿ����", "�ָ��Լ����߶��ѵ���Ѫ����Ѫ����", "CostHpMax" },
	{ 0x00000000, 0x036B4345, 0x00000000, 0x00000000, 0x00000000, eSkill::��ľ���, eSkillUse::None, eBuff::None, 0, 0, "��ľ���", "", "" },
	{ 0x2EF58426, 0xABD57D92, 0x00000000, 0x00000000, 0x00000000, eSkill::Ԫ������, eSkillUse::None, eBuff::None, 0, 0, "Ԫ������", "", "" },
	{ 0x34D061C7, 0x1D14968A, 0x00000000, 0x00000000, 0x00000000, eSkill::�ݵ���, eSkillUse::NormalSelf, eBuff::None, 0, 0, "�ݵ���", "ƽʱ״̬��ʹ�ã�����˲��ص��Լ�������", "" },
	{ 0xDB2E1256, 0xDE58924A, 0x00000000, 0x00000000, 0x00000000, eSkill::�ɼ�����, eSkillUse::BattleOwner, eBuff::None, 10, -10, "�ɼ�����", "����", "CostHpMax" },

	{ 0x0B8CF3A1, 0x2E734F9D, 0x00000000, 0x00000000, 0x6061BB93, eSkill::��Ҷ����, eSkillUse::BattleOther, eBuff::None, 30, 0, "��Ҷ����", "ʹ�÷��������з����Ŀ��", "MPS" },
	{ 0x6A647570, 0xDD2AB898, 0x00000000, 0x00000000, 0x00000000, eSkill::������, eSkillUse::BattleOther, eBuff::None, 30, -10, "������", "ʹ�÷��������з�����Ŀ��", "" },
	{ 0x71C197B0, 0x3FE17E30, 0x00000000, 0x00000000, 0x00000000, eSkill::������, eSkillUse::BattleOther, eBuff::None, 30, -10, "������", "ʹ�÷��������з�����Ŀ��,����ʹĿ����ʧһ��HP����", "" },
	{ 0x3B12CD18, 0xEDF81F56, 0x00000000, 0x00000000, 0xF76A183A, eSkill::����ŭ, eSkillUse::BattleOther, eBuff::None, 30, -10, "����ŭ", "ʹ�÷��������з�����Ŀ��,����ʹĿ����ʧһ����ŭ", "" },
	{ 0x0DA2D8DF, 0x1EE55D3C, 0x00000000, 0x00000000, 0x00000000, eSkill::��ɱ, eSkillUse::BattleOther, eBuff::Bad, 50, -10, "��ɱ", "ʹ�÷��������з�����Ŀ�꣬�Ե�����ɳ��������˺�", "" },
	{ 0x7D52C301, 0x126B932F, 0x00000000, 0x00000000, 0x00000000, eSkill::Ѫ��, eSkillUse::BattleOther, eBuff::None, 20, 0, "Ѫ��", "����������Ѫ���Ե��˵���Ŀ����ɴ����˺��� ʹ�ú��Լ��»غ��޷�ʹ�÷���", "CostHpMax" },
	{ 0x007E7633, 0xFF613346, 0x00000000, 0x00000000, 0x00000000, eSkill::����֮��, eSkillUse::BattleSelf, eBuff::None, 50, 0, "����֮��", "�ظ�����HP", "" },
	{ 0xC5D73984, 0xA215E746, 0x00000000, 0x00000000, 0x00000000, eSkill::�׻�, eSkillUse::BattleSelf, eBuff::None, 30, 0, "�׻�", "����50%����Ѫ�˺���ÿ����1���˺�����1��MP", "" },
	{ 0x51763883, 0x64FEA3A4, 0x00000000, 0x00000000, 0x00000000, eSkill::Ҷ��, eSkillUse::NormalSelf, eBuff::None, 0, 0, "Ҷ��", "ƽʱ״̬��ʹ�ã�����˲��ص��Լ�������", "" },
	{ 0xF2E06AF8, 0x977F5625, 0x00000000, 0x00000000, 0x00000000, eSkill::��ľ߽��, eSkillUse::None, eBuff::None, 0, 0, "��ľ߽��", "", "" },
	{ 0xF83E2272, 0x058EE366, 0x00000000, 0x00000000, 0x00000000, eSkill::����, eSkillUse::BattleOwner, eBuff::None, 25, 10, "����", "���Ӽ������˵ķ����˺���", "MPS" },
	{ 0xAC574467, 0x00000000, 0x00000000, 0x00000000, 0x00000000, eSkill::����ʴ��, eSkillUse::None, eBuff::None, 0, 0, "����ʴ��", "", "" },
};

const vector<sSkillPassive>& ctt::getSkillPassives()
{
	return s_skillPassives;
}

const vector<sSkillFuzhu>& ctt::getSkillFuzhus()
{
	return s_skillFuzhus;
}

const vector<ctt::sSkill>& ctt::getSkills()
{
	return s_skills;
}





static std::vector<sSkillAni> s_sillActs =
{
	{ 0x3200B6CC, 0x00000000, 0x00000000, eSkill::�׻� },
	{ 0x3200B6CC, 0x279AF873, 0x00000000, eSkill::������ },
	{ 0xFDF34F35, 0x05391F73, 0x00000000, eSkill::���� },
	{ 0x4E86F9B3, 0x00000000, 0x00000000, eSkill::̩ɽѹ�� },
	{ 0xCE33E201, 0x00000000, 0x00000000, eSkill::ˮ�� },
	{ 0x4CE1ACB6, 0x00000000, 0x00000000, eSkill::ˮ����ɽ }, // 0x439692DE, 0xC9BCA454, 0x60EB2F76, 
	{ 0x22A3D764, 0x00000000, 0x00000000, eSkill::�һ� },
	{ 0xDED2253F, 0x00000000, 0x00000000, eSkill::�����һ� },
	

	{ 0x68E51BB6, 0x00000000, 0x00000000, eSkill::ҹ����� },

};
const std::vector<sSkillAni>& ctt::getSkillActs()
{
	return s_sillActs;
}



static std::vector<sSkillAni> s_sillHits =
{
	{ 0xACA4A54A, 0x3C45D282, 0xD862FBE7, eSkill::��ɨǧ�� },
	// 0x19C102D1
	{ 0x958FAC37, 0x00000000, 0x00000000, eSkill(1010) },
	{ 0x301F9E4A, 0x6AD55205, 0x00000000, eSkill(1017)/*eSkill::�Ƹ�����*/ },

	{ 0xB6141EB9, 0xF17168C5, 0x885ACBE1, eSkill::����ն },

	{ 0x4F8312F6, 0x9215D669, 0xD06119B3, eSkill::���꽣�� },
	{ 0x3426ACE0, 0x00000000, 0x00000000, eSkill::Ʈ��ʽ },

	{ 0x73DA1CCF, 0x89302F40, 0x00000000, eSkill::���� },
	{ 0xA463C055, 0x86FE2BC1, 0x83020DAE, eSkill::ӥ�� },
	{ 0x42F0386F, 0x096766A8, 0x00000000, eSkill::ʨ�� },
	{ 0x00000000, 0x00000000, 0x00000000, eSkill::������ },

	{ 0x958FAC37, 0x00000000, 0x00000000, eSkill::��ʯ },
	{ 0x958FAC37, 0x00000000, 0x00000000, eSkill::������, },
	{ 0x958FAC37, 0x00000000, 0x00000000, eSkill::������� },
	{ 0xD53A25EB, 0x00000000, 0x00000000, eSkill::��ӿ },
	{ 0xB94D0B94, 0x00000000, 0x00000000, /*eSkill::����ŭ*/eSkill(1171) },
	{ 0xB94D0B94, 0x00000000, 0x00000000, /*eSkill::��������*/eSkill(1172) },
};
const std::vector<sSkillAni>& ctt::getSkillHits()
{
	return s_sillHits;
}

static vector<int> s_skillStartMap = 
{
	(int)eSkill::����,
	(int)eSkill::��������,
	(int)eSkill::�ն�����,
	(int)eSkill::��������,
	(int)eSkill::ħ������,
	(int)eSkill::������,
	(int)eSkill::��˿��,
	(int)eSkill::���Ǿ�,
};

const vector<int>& ctt::getSkillStarts()
{
	return s_skillStartMap;
}
