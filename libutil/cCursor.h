#pragma once
// ���
enum class eCursor
{
	// ƽʱ
	Normal,
	// ����
	Give,
	// ?
	Forbig,
	// ����
	Trade,
	// ����
	Atk,
	// ����ѡ��(תȦȦ)
	Magic,
	// ���(��)
	Team,
	// ��ָ?
	Hand,
	// ָ��??
	Guard,
	// ץ��
	Grab,
	// ��
	No,
};


class cCursor
{
public:
	static cCursor* getInstance();

	void setCursor(eCursor e);

	const eCursor& getCursor() { return _cursor; }

protected:
	eCursor _cursor = eCursor::Normal;
};


