#pragma once

// ģ�Ͷ���
enum class eAct
{
	// վ(��ͼ)
	Stand,
	// ��(��ͼ)
	Walk,
	// վ(ս��)
	Fight,
	// ǰ��(ս��)
	Go,
	// ����(ս��)
	Atk,
	// ����2(ս��)
	Atk2,
	// ʩ��(ս��)
	Magic,
	// ����(ս��)
	Def,
	// ����(ս��)
	Suffer,
	// ����(ս��)
	Dead,
	// ����(ս��)
	Back,

	// ��ͷ��
	Big,
	// Сͷ��
	Small,
	// �Ի�ͷ��
	Dialog,

	// ����(��Ч)
	eAtk,
	// ����2(��Ч)
	eAtk2,
	// ʩ��(��Ч)
	eMagic,
	// ����(��Ч)
	eDef,
	// ����(��Ч)
	eSuffer,
	// ����(��Ч)
	eDead,

	// ����
	Amigo,
	HappySmall,
	HappyBig,
	SadSmall,
	SadBig,
	ProudSmall,
	ProudBig,
	// ֫��
	BodyBow,
	BodyCry,
	BodyDance,
	BodyGreet,
	BodySit,
	BodyAngry
};