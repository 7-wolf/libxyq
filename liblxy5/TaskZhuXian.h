#pragma  once;
#include "_taskinc.h"

class TaskZhuXian :public cTaskFather
{
public:
	void Init();
	TaskZhuXian();
	virtual bool Process(int stage);
	bool Process0(int stage);//���˵Ĺ��
	bool Process1(int stage);//����
	bool Process2(int stage);//������
	bool Process3(int stage);//С����
	bool Process4(int stage);//�˽�
	bool Process5(int stage);//������
	bool Process6(int stage);//����׹Ǿ�
	bool Process7(int stage);//��ȡ�Ž���
	bool Process8(int stage);//����Ů��
	bool Process9(int stage);//��������
	bool Process10(int stage);
	bool Process11(int stage);
	bool Process12(int stage);
	bool Process13(int stage);
	bool Process14(int stage);
	bool Process15(int stage);
	bool Process16(int stage);
	bool Process17(int stage);
	bool Process18(int stage);
	bool Process19(int stage);
	bool Process20(int stage);
	bool Process21(int stage);
	bool Process22(int stage);
	bool Process23(int stage);
	bool Process24(int stage);
	bool Process25(int stage);
	bool Process26(int stage);
	bool Process27(int stage);
	bool Process28(int stage);
	bool Process29(int stage);
	bool Process30(int stage);
	bool Process31(int stage);
	bool Process32(int stage);
	bool Process33(int stage);
	bool Process34(int stage);
	bool Process35(int stage);
	bool Process36(int stage);
	bool Process37(int stage);
	bool Process38(int stage);
	bool Process39(int stage);
	bool Process40(int stage);

	void SetChapter(int chapter);
	int GetChapter(){ return m_Chapter; }
private:
	cObj* m_pObj = 0;
	int m_Chapter;
};
