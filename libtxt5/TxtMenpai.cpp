#include "TxtMenpai.h"
using namespace ctt;
static const std::vector<sMenpai> s_menpais =
{
	{ eMenpai::Dt, "���ƹٸ�", "��ҧ��", "���ƹٸ�", "��ҧ��",
	{
		{ { 0x00, 0x7A33A5A9, 0x8B6687C7, "Ϊ��֮��", ePromote::None, { { 30, eSkill::ɱ���� } } },
		{ 0x01, 0xB2BCD78E, 0x83510218, "��˫һ��", ePromote::None, { { 45, eSkill::������ } } },
		{ 0x02, 0xFCF64BB4, 0x2C4A485C, "�������", ePromote::None, { /*{ 65, eSkill::������ }*/ } },
		{ 0x03, 0x20EB6BD0, 0x7D6C0800, "���粽", ePromote::None, { { 1, eSkill::ǧ������ } } },
		{ 0x04, 0xF4D93CEB, 0x43D35D1B, "ʮ���޵�", ePromote::None, { { 30, eSkill::��ɨǧ�� }, { 60, eSkill::�Ƹ����� } } },
		{ 0x05, 0x73C87FDE, 0xEAE7112A, "��ޱ֮��", ePromote::None, { { 120, eSkill::����� } } },
		{ 0x06, 0xBBCCFA4E, 0x65DB91C9, "�������", ePromote::None, { { 50, eSkill::����֮�� } } } } }
	},
	{ eMenpai::Hs, "������", "�ն���ʦ", "������", "�ؾ���",
	{
		{ { 0x0E, 0x5DC9B771, 0xAE58AD12, "С�˷�", ePromote::None, {} },
		{ 0x0F, 0xE6409CE3, 0x98FFC4AD, "��շ�ħ", ePromote::None, { { 120, eSkill::���ޱ� } } },
		{ 0x10, 0xD1919F3D, 0x7287C064, "�о�", ePromote::None, { { 20, eSkill::�������� } } },
		{ 0x11, 0xEC71CE44, 0x4B8C1B65, "�������", ePromote::None,
		{
			{ 30, eSkill::��ջ��� },
			{ 50, eSkill::Τ�ӻ��� },
			{ 60, eSkill::��ջ��� },
			{ 70, eSkill::һέ�ɽ� }
		} },
		{ 0x12, 0x058EC75B, 0x7A8856F3, "��ȴ�", ePromote::None, { { 20, eSkill::�ҷ�ȱ� } } },
		{ 0x13, 0x86C94C7C, 0x8F00A676, "���֮��", ePromote::None,
		{
//			{ 15, eSkill::���� },
			{ 25, eSkill::�������� },
			{ 10, eSkill::��Ѫ },
			{ 120, eSkill::����ȡ�� }
		} },
		{ 0x14, 0x3004AA75, 0xA8939527, "������", ePromote::None, { { 1, eSkill::�����ն� } } } } }
	},
	{ eMenpai::Ne, "Ů����", "������", "Ů����", "Ů����峤��",
	{
		{ { 0x15, 0x47B9EF90, 0xBC69ED1E, "����", ePromote::None, {} },
		{ 0x16, 0x56E88235, 0x23697214, "������", ePromote::None, { { 50, eSkill::�������� }/*, { 120, eSkill::һЦ��� } */} },
		{ 0x17, 0x3EC00B8D, 0x1618C7AD, "��������", ePromote::None, { { 20, eSkill::���컨�� }, { 20, eSkill::���亮ɳ } } },
		{ 0x18, 0xFB265F9E, 0xC5F34CFB, "�����߻�", ePromote::None, { { 30, eSkill::�������� } } },
		{ 0x19, 0x52788E94, 0xD280080E, "��Ʈ����", ePromote::None, {} }, 
		{ 0x1A, 0x86FEEA94, 0xCCF72E77, "���ʱ���", ePromote::None, {} },
		{ 0x1B, 0x91B45987, 0x3D453325, "�������", ePromote::None, { { 1, eSkill::���λ�Ӱ } } } } }
	},
	{ eMenpai::Fc, "����ɽ", "������ʦ", "����ɽ", "��̨��",
	{
		{ { 0x07, 0x59783586, 0x9FC18E51, "��ͥ��", ePromote::None, {} },
		{ 0x08, 0x74F253D9, 0x19396997, "������", ePromote::None, {} },
		{ 0x09, 0x11EAAE6D, 0x0336EB9B, "������", ePromote::None, { { 30, eSkill::���׷� } } },
		{ 0x0A, 0x36F26348, 0xD68D198D, "��֮��", ePromote::None,
		{
			{ 20, eSkill::���з� },
			{ 40, eSkill::���߷� },
			{ 30, eSkill::ʧ�ķ� },
			{ 40, eSkill::ʧ��� },
			{ 40, eSkill::����� },
			{ 120, eSkill::��׷� }
		} },
		{ 0x0B, 0xB293CF00, 0xCD48FDFF, "��Ԫ�ķ�", ePromote::None, { { 40, eSkill::��Ԫ�� }, { 40, eSkill::������ } } },
		{ 0x0C, 0xE5A2EB07, 0x684DEBB0, "�������", ePromote::None, { { 120, eSkill::������ } } },
		{ 0x0D, 0x7E9CCF04, 0x2DD65965, "б�²�", ePromote::None, { { 1, eSkill::��ľ�ɶ� } } } } }
	},
	{ eMenpai::St, "ʨ����", "�����", "ʨ����", "ʨ����",
	{
		{ { 0x46, 0x009BEBDA, 0xB0013AB2, "ħ����", ePromote::None, { { 50, eSkill::���� }, { 20, eSkill::������ } } },
		{ 0x47, 0x513A8A78, 0xBAECB102, "������", ePromote::None, { { 55, eSkill::���� }, { 60, eSkill::ӥ�� }, /*{ 1, eSkill::��ħ���� },*/ { 30, eSkill::ʨ�� } } },
		{ 0x48, 0xBA7AD05B, 0x4694D927, "ѱ�޾�", ePromote::None, { { 30, eSkill::���� } } },
		{ 0x49, 0xFC7EDF4C, 0x28BACE76, "����������", ePromote::None, {} },
		{ 0x4A, 0x8B61AADA, 0x630CE9C2, "���޾�", ePromote::None, { { 50, eSkill::������ } } },
		{ 0x4B, 0x832ACED9, 0x4A1E39A3, "����չ��", ePromote::None, { { 1, eSkill::���ǧ�� } } },
		{ 0x4C, 0x5108D3A7, 0x1E8A79DF, "ħ�޷���", ePromote::None, { { 40, eSkill::���ȷ�� } } } }
	}
	},
	{ eMenpai::Mw, "ħ��կ", "ţħ��", "ħ��կ", "ħ����",
	{
		{ { 0x3F, 0xA36C5AA6, 0xECEF9C70, "ţ����", ePromote::None, {} },
		{ 0x40, 0x7244B8D8, 0x56612F8E, "�����", ePromote::None, { /*{ 5, eSkill::ҡͷ��β } */} },
		{ 0x41, 0x3632166A, 0xF85D38D4, "������", ePromote::None, { { 30, eSkill::��ɰ��ʯ }, { 50, eSkill::������� } } },
		{ 0x42, 0x50F19558, 0x72491389, "��ţ��", ePromote::None, { { 60, eSkill::ţ�� } } },
		{ 0x43, 0x9495B98F, 0x43541BC6, "ţʭ��", ePromote::None, { { 25, eSkill::�޵�ţʭ }, { 25, eSkill::�޵�ţ�� } } },
		{ 0x44, 0x9F0522B9, 0x48FC858E, "�����", ePromote::None, { { 30, eSkill::ħ������ } } },
		{ 0x45, 0xC70D4DA4, 0xFF7AB8FE, "��ʯ��", ePromote::None, { { 1, eSkill::ţʺ�� } } } } }
	},
	{ eMenpai::Ps, "��˿��", "�׾���", "��˿��", "��˿��",
	{ { { 0x4D, 0x8523F7A5, 0x1D0E8D52, "��˿��", ePromote::None, {} },
	{ 0x4E, 0xB8EACFC0, 0x8FA9C1D7, "�����", ePromote::None, { { 40, eSkill::�������� } } },
	{ 0x4F, 0x3A278387, 0x653EB3E2, "�ﲨ����", ePromote::None, { { 30, eSkill::���� }, { 40, eSkill::���� } } },
	{ 0x50, 0x8AFB1A80, 0xE3ADB1EB, "����ħ��", ePromote::None, { { 40, eSkill::ħ����� } } },
	{ 0x51, 0x0829E95B, 0x97B0F3BB, "��˿��", ePromote::None, { { 5, eSkill::��˿�� }/*, { 60, eSkill::���� }*/ } },
	{ 0x52, 0x141B5E54, 0xCB126977, "���λ�Ӱ", ePromote::None, { { 30, eSkill::���޵��� }, { 1, eSkill::���˿ }, { 120, eSkill::�þ��� } } },
	{ 0x53, 0x2397ABE7, 0xBD6854D3, "��������", ePromote::None, {} } } }
	},
	{ eMenpai::Df, "���ܵظ�", "�ز���", "���ܵظ�", "�ز�����",
	{
		{ { 0x38, 0x2267FDE2, 0x2975C865, "��ͨ��", ePromote::None, { /*{ 1, eSkill::������ }, { 30, eSkill::������ }*/ } },
		{ 0x39, 0x68FBF782, 0x829863CF, "�����ֻ�", ePromote::None, { { 50, eSkill::�����ɢ } } },
		{ 0x3A, 0x18BC5193, 0x7D7E42B5, "��ڤ��", ePromote::None, { { 20, eSkill::������ }, { 120, eSkill::������ }, { 120, eSkill::��Ȫ֮Ϣ } } },
		{ 0x3B, 0xCAD7422A, 0x60B5C339, "�л��", ePromote::None, { { 30, eSkill::�й��� }, { 120, eSkill::������ } } },
		{ 0x3C, 0xA717E4EC, 0x90AD7379, "��������", ePromote::None, { { 40, eSkill::��ڤ���� } } },
		{ 0x3D, 0x015E36F3, 0xEE4186E1, "ʬ����", ePromote::None, { { 30, eSkill::ʬ���� }, { 20, eSkill::�������� } } },
		{ 0x3E, 0x0448AB94, 0xA53AE1E3, "�޳���", ePromote::None, { { 1, eSkill::������Ѷ } } } } }
	},
	{ eMenpai::Lg, "����", "��������", "����", "ˮ����",
	{
		{ { 0x23, 0x37118266, 0x085CAE13, "������", ePromote::None, { /*{ 60, eSkill::��� }, */{ 15, eSkill::���� }, { 120, eSkill::����Ϸ�� } } },
		{ 0x24, 0xC57A39B9, 0xF650D185, "���˾�", ePromote::None, { { 120, eSkill::������β } } },
		{ 0x25, 0x726EFA79, 0x1A1DE0D4, "���绽��", ePromote::None, { { 15, eSkill::������� } } },
		{ 0x26, 0x80426D9F, 0xCEEAA576, "����", ePromote::None, { { 50, eSkill::���� } } },
		{ 0x27, 0xCB06F1FB, 0xB904AD16, "����", ePromote::None, { { 60, eSkill::���� } } },
		{ 0x28, 0x12DCA762, 0x671FC66C, "������", ePromote::None, { { 1, eSkill::ˮ�� } } },
		{ 0x29, 0xE007F365, 0xDD742E3A, "����", ePromote::None, { { 30, eSkill::���� } } } } }
	},
	{ eMenpai::Wz, "��ׯ��", "��Ԫ����", "��ׯ��", "Ǭ����",
	{
		{ { 0x2A, 0xBDB57B3E, 0x38BA101C, "����ѧ", ePromote::None, { { 80, eSkill::��ʬ } } },
		{ 0x2B, 0xA24E38FE, 0xD30FDF54, "��������", ePromote::None, { { 10, eSkill::���꽣�� }, { 30, eSkill::Ʈ��ʽ } } },
		{ 0x2C, 0xCD3C3C12, 0x86832A8C, "Ǭ����", ePromote::None, { { 50, eSkill::����Ǭ�� }/*, { 80, eSkill::���ͬ�� }*/ } },
		{ 0x2D, 0x63C0827A, 0xDE2533AE, "������", ePromote::None, { { 30, eSkill::�������� }, { 20, eSkill::����֮Ȫ } } },
		{ 0x2E, 0xE2720478, 0x283D1B37, "��Ԫ����", ePromote::None, {} },
		{ 0x2F, 0xB7426D01, 0xF49FDAFE, "��������", ePromote::None, { { 70, eSkill::�����۶� } } },
		{ 0x30, 0x8F0D6C4C, 0x3712E54D, "���Ƕ�", ePromote::None, { { 1, eSkill::��ת���� } } } } }
	},
	{ eMenpai::Pt, "����ɽ", "�������", "����ɽ", "������",
	{
		{ { 0x31, 0xBB5973EF, 0xEB6872B2, "����", ePromote::None, { { 120, eSkill::�ߵ����� }, { 60, eSkill::�����ķ� } } },
		{ 0x32, 0x0506BE5D, 0x0D4CE946, "�������", ePromote::None, {} },
		{ 0x33, 0x71F0219A, 0x5413DD44, "������", ePromote::None, { { 30, eSkill::������ }, { 40, eSkill::������¶ } } },
		{ 0x34, 0x2BB9F19E, 0xD95C9242, "����ѧ˵", ePromote::None,
		{
			{ 30, eSkill::�չ⻪ },
			{ 30, eSkill::��׺� },
			{ 30, eSkill::������ },
			{ 30, eSkill::��ã�� },
			{ 30, eSkill::���ѻ� }
		} },
		{ 0x35, 0xF5BD9EB4, 0x91B95A02, "��վ�", ePromote::None, { { 30, eSkill::�ն����� } } },
		{ 0x36, 0xCE175363, 0xC21CFA93, "����Ťת", ePromote::None, {} },
		{ 0x37, 0x8347AA63, 0x02427B90, "��������", ePromote::None, { { 1, eSkill::���� }, { 120, eSkill::�鶯���� } } } } }
	},
	{ eMenpai::Tg, "�칬", "�", "�칬", "��������",
	{
		{ { 0x1C, 0x1EDA4D57, 0xFBCA1857, "�����", ePromote::None, { { 50, eSkill::���׺䶥 }, { 120, eSkill::������� }, { 30, eSkill::������ } } },
		{ 0x1D, 0x3E89723E, 0xB2E190E8, "������", ePromote::None, { { 30, eSkill::����ն } } },
		{ 0x1E, 0xE509DEF5, 0xC096279E, "��������", ePromote::None, {} },
		{ 0x1F, 0xD4FE4342, 0x75FC0B6E, "������", ePromote::None, { /*{ 20, eSkill::���� }*/ } },
		{ 0x20, 0xB3B26849, 0x268A8DE5, "Ǭ����", ePromote::None, { { 50, eSkill::���� }, { 40, eSkill::���� } } },
		{ 0x21, 0x1CB7C4FF, 0xD92B56C2, "������", ePromote::None, { { 40, eSkill::������� } } },
		{ 0x22, 0xE80ED007, 0x1079CE8A, "������", ePromote::None, { { 1, eSkill::���Ƽ��� } } } } }
	},
	{ eMenpai::Lb, "�貨��", "������", "�貨��", "�貨��",
	{
		{ { 0x54, 0xD854B619, 0x9BF40DC5, "����޼�", ePromote::None, { { 5, eSkill::��ӿ } } },
		{ 0x55, 0x66878D1C, 0x6D83F3D1, "��ת����", ePromote::None, { { 50, eSkill::������ɽ } } },
		{ 0x56, 0x8837F110, 0xC080EE77, "������ʥ", ePromote::None, { { 40, eSkill::���Ǿ� }, { 50, eSkill::���� } } },
		{ 0x57, 0x2F79B759, 0x687EDEFE, "Х��", ePromote::None, { /*{ 30, eSkill::�����ƿ� }*/ } },
		{ 0x58, 0x6027C7C6, 0xEEC348EA, "����ɽ��", ePromote::None,
		{
			{ 20, eSkill::��ʯ },
			{ 30, eSkill::������ },
			{ 40, eSkill::������� },
			{ 60, eSkill::����ŭ },
			{ 80, eSkill::�������� }
		} },
		{ 0x59, 0xA70C7A5A, 0x08F2E772, "��ħ", ePromote::None, { /*{ 5, eSkill::���� }, { 5, eSkill::ָ�سɸ� }*/ } },
		{ 0x5A, 0xEAB341B6, 0xAA65C1F5, "�������", ePromote::None, { /*{ 5, eSkill::������� },*/ { 1, eSkill::�ݵؽ�� } } } } }
	},
	{ eMenpai::Wd, "�޵׶�", "��ӿ����", "�޵׶�", "������",
	{
		{ { 0x5B, 0xC21CAA3F, 0xEB4FD0B6, "�ݹ��ķ�", ePromote::None, { { 50, eSkill::�ƻ껯�� } } },
		{ 0x5C, 0x8DAA624D, 0x229B3F36, "�������", ePromote::None,
		{
			{ 40, eSkill::������ },
// 			{ 5, eSkill::ɷ���� },
// 			{ 50, eSkill::������ },
			{ 100, eSkill::������ }
		} },
		{ 0x5D, 0x2648B742, 0x7F61F010, "�������", ePromote::None, { { 60, eSkill::������ } } },
		{ 0x5E, 0x77DE4303, 0x8386CD36, "ȼ���鱦", ePromote::None, { { 5, eSkill::���ⱦ�� } } },
		{ 0x5F, 0x47B1845A, 0x7B30715D, "��ڤ�", ePromote::None, { { 20, eSkill::��ӿ���� }, /*{ 40, eSkill::��ľ��� },*/{ 10, eSkill::�ɼ����� } } },
		{ 0x60, 0x7B209C81, 0xC8B6A6A3, "��Ԫ��", ePromote::None, { /*{ 5, eSkill::Ԫ������ }*/ } },
		{ 0x61, 0x87D67BAB, 0xF0E46F02, "��Ӱ����", ePromote::None, { { 1, eSkill::�ݵ��� }, { 5, eSkill::�������� } } } } }
	},
	{ eMenpai::Sm, "��ľ��", "�׿���", "��ľ��", "��ľ��",
	{
		{ { 0x62, 0xD7468834, 0x056EAA54, "˲Ϣ���", ePromote::None, { { 20, eSkill::��Ҷ���� } } },
		{ 0x63, 0xD89652AE, 0x63BC74C4, "��������", ePromote::None, { { 20, eSkill::������ }, { 20, eSkill::������ }, { 20, eSkill::����ŭ } } },
		{ 0x64, 0xEB2A7B26, 0x52B73EBF, "����", ePromote::None, { { 50, eSkill::��ɱ }, { 80, eSkill::Ѫ�� } } },
		{ 0x65, 0xD37FE4A6, 0x0E11E662, "������ת", ePromote::None, { { 40, eSkill::����֮�� } } },
		{ 0x66, 0x9E505CED, 0x1BCE436A, "���˱ӻ�", ePromote::None, { { 115, eSkill::�׻� }, { 1, eSkill::Ҷ�� } } },
		{ 0x67, 0x2ED87112, 0x71EB94AA, "��ľ����", ePromote::None, { /*{ 5, eSkill::��ľ߽�� }*/ } },
		{ 0x68, 0x5AD8D3E2, 0xB3E852DE, "Ԧ����", ePromote::None, { { 5, eSkill::���� }/*, { 40, eSkill::����ʴ�� }*/ } } } }
	},
};

const vector<sMenpai>& ctt::getMenpais()
{
	return s_menpais;
}
