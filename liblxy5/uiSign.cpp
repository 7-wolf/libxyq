#include "_global.h"

// ǩ��ϵͳ
class Sign// : public Node
{
public:
	// ����ǩ������(�浵����, �浵����, ��ǩ����)
//	static Sign* create(int &signDate, int &signData, int signMax){ QQ_CREATE(Sign, signDate, signData, signMax); }


	bool init(int &signDate, int &signData, int signMax)
	{
		_signDate = &signDate;
		_signData = &signData;
		_signMax = signMax;
//		return Node::init();
		return true;
	}
		

	// ��������(��ǩ�Ƿ�����, ��ǩ����)
	// ��ǩ����<ǩ�ĵڼ���,ǩ��������>
	void setCondition(bool isResetIfFull, function<void(int&, int&)> funcBreak = nullptr)
	{
		time_t tt = time(nullptr);
		tm* t = localtime(&tt);
		_yearDay = (t->tm_year + 1900) * 10000 + (t->tm_mon + 1) * 100 + t->tm_mday;

		if (isNeverSignd())
		{
			return;
		}

		int yearDayLast(*_signDate);

		if (_isSigndToday = _yearDay == yearDayLast)
		{
			return;
		}

//		_signNow = totalContinuity % 10000;
//		XYZ signLastContinue(*_signData);
//		_signNow = signLastContinue.x;

//		if (!isDayContinue(yearDayLast.x, yearDayLast.y, _yearDay.x, _yearDay.y))
		int ydayLast = mDay_to_yDay(yearDayLast / 10000, (yearDayLast % 10000) / 100, (yearDayLast % 100));
		int yday = mDay_to_yDay(_yearDay / 10000, (_yearDay % 10000) / 100, (_yearDay % 100));
		if (!isDayContinue(yearDayLast / 10000, ydayLast, _yearDay / 10000, yday))
		{
// 			if (funcBreak)
// 			{
// 				funcBreak(_signNow, signLastContinue.z);
// 				(*_signData) = signLastContinue;
//			}
			(*_signData) = getSignTotal() * 10000;
		}
// 		else if (_signNow == _signMax - 1 && isResetIfFull)
// 		{
// 			_signNow = 0;
// 		}
// 		else if (++_signNow >= _signMax)
// 		{
// 			_signNow = _signMax - 1;
// 		}
	}

	// ǩ��
	// ������ǩ��; ����ǩ������+1
	// �������浵
	void doSign()
	{
		*_signDate = _yearDay;
// 		XYZ signLastContinue(*_signData);
// 		signLastContinue.y = signLastContinue.x;
// 		signLastContinue.x = _signNow;
// 		++signLastContinue.z;
//		*_signData = signLastContinue;
		*_signData = (getSignTotal() + 1) * 10000 + (getSignContinue() + 1);
		_isSigndToday = true;
	}


	// �������Ҫǩ, ǩ���ǵڼ���(0~��ǩ����-1)
// 	int getSignToday()const
// 	{
// 		if (this->isSignedToday())
// 		{
// 			return XYZ(*_signData).x;
// 		}
// 		return _signNow;
// 	}



	// ��һ��ǩ���ǵڼ���(0~��ǩ����-1)
	// ����������ǩ�����
// 	int getSignLast()const
// 	{
// 		XYZ(*_signData).y;
// 	}



	// ����ǩ������
	int getSignContinue()const
	{
		return (*_signData) % 10000;
//		return XYZ (*_signData).z;
	}

	// �ۼ�ǩ������
	int getSignTotal()const
	{
		return (*_signData) / 10000;
	}

	// ������ǩ��ô...
	bool isSignedToday()const
	{
		return _isSigndToday;
	}



	// ��ǩ(0~��ǩ����-1)
// 	bool isSigned(int sign)const
// 	{
// 		QQ_ASSERT(sign >= 0 && sign < _signMax, "ǩ��ϵͳ ǩ�δ���");
// 		if (this->isSignedToday())
// 		{
// 			return sign <= this->getSignToday();
// 		}
// 		return sign < this->getSignToday();
// 	}



	// ��ǩ?(0~��ǩ����-1)
	// ǩ������,����ȫ������ǩ
// 	bool isSignable(int sign)const
// 	{
// 		QQ_ASSERT(sign >= 0 && sign < _signMax, "ǩ��ϵͳ ǩ�δ���");
// 		if (this->isSignedToday())
// 		{
// 			return false;
// 		}
// 		return sign == this->getSignToday();
// 	}


	// ��δǩ��
	bool isNeverSignd()
	{
		return !(*_signData) && !(*_signDate);
	}


private:
	// ����ǩ
//	int _signNow = 0;

 	// ��ǩ����
 	int _signMax;
public:
	// �浵���� ������
	int *_signDate = nullptr;

	// �浵���� ��ǩ��ǩ
	int *_signData = nullptr;
private:
	// ��ǰ���� ������
	int _yearDay;

	// �ϴ�ǩ������
	bool _isSigndToday = false;


	// ����
	bool isLeapYear(int year){ return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0; }


	// ת����0~365��
	int mDay_to_yDay(int year, int month, int mday)
	{
		static char days[] = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		int day = mday;
		for (int i = 0; i < month - 1; ++i)
		{
			day += days[i];
		}

		if (!isLeapYear(year) && month > 2)
		{
			--day;
		}
		return day;
	}



	// 0~365��, �Ƿ�����
	bool isDayContinue(int yearOld, int dayOld, int year, int day)
	{
		// ��ݲ�һ�¿϶���������...
		if (year > yearOld + 1 || year < yearOld)
		{
			return false;
		}

		// ���һ������: ���� (year_old���һ�� <--> year��һ��), ������������
		if (year == yearOld + 1)
		{
			if (day > 0)
			{
				return false;
			}
			else
			{
				// ƽ�����������һ�첻һ��(364,365)
				if (isLeapYear(yearOld))
				{
					if (dayOld != 365)
					{
						return false;
					}
				}
				else if (dayOld != 364)
				{
					return false;
				}
			}
		}
		// ͬһ������:
		else if (year == yearOld)
		{
			if (day != dayOld + 1)
				return false;
		}
		return true;
	}
};


static Sign sign;
static long s_langtimeOnce = 0;
static long s_langtimeLast = 0;
static int s_time20 = 0;
static int s_time21;
bool uiSign::Init()
{
	if (!cInterfaceFather::Init())
	{
		return false;
	}
	loadBack(0x5B8B823E);

	sChild tTitle("ǩ��", 250, 12);
	addChild(tTitle);

	sChild context(" ", 80, 100);
	addChild(context);
	_text = (cText*)context.ptr;



	cInterfaceFather::sChild btn(&g_pMainState->m_Button4, "textBtn", 235, 360);
	_textBtn = (cText*)btn.ptr2;
	btn.onClick = [&](const sChild* c)
	{
		if (sign.isSignedToday())
		{
			return;
		}

		static bool isSignd = false;
		if (isSignd)
		{
			g_pMainState->m_Tags.Add("���������Ѿ�ǩ����");
			return;
		}

		if (g_iFPS < 21600)
		{
			g_pMainState->m_Tags.Add(toString("�ٵ�%d����", (21600 - g_iFPS) / 3600));
			return;
		}
		sign.doSign();
		isSignd = true;

		int r = sign.getSignContinue();
		if (r > 1)
		{
			int e = r * 30;
			g_pMainState->awardk(e, r * 10);
		}

		int e = rand() % 100;
		if (e < 40)
		{
			if (!g_pMainState->awardBookIron(100))
			{
				g_pMainState->awardShouJue1();
			}
		}
		else if (e < 80)
		{
			if (rand() % 100 < r)
			{
				g_pMainState->awardShouJue2();
			}
			else
			{
				g_pMainState->awardShouJue1();
			}
		}
		else
		{
			g_pMainState->award5bao();
		}

		cct::autoSave();
		initShow();
	};
	addChild(btn);
	Move(125, 65);

	sign.init(g_GlobalValues[18], g_GlobalValues[19], 0xFFFF);
	sign.setCondition(false);
	return true;
}


bool uiSign::initShow()
{
	_textBtn->SetString(sign.isSignedToday() ? "������ǩ" : "����ǩ��");
	if (sign.isNeverSignd())
	{
		return true;
	}
	string str = toString("�ϴ�ǩ��: #Y%d-%02d-%02d#Y\n\n�ۼ�ǩ��: #Y%d#Y\n\n����ǩ��: #Y%d#Y", 
		(*sign._signDate) / 10000, ((*sign._signDate) % 10000) / 100, ((*sign._signDate) % 100),
		sign.getSignTotal(), sign.getSignContinue());
	_ftext.SetFaceText(str,g_pMainState->m_hFont[0], 480);
	return true;
}


static int gettimeofday(struct timeval *tp, void *tzp)
{
	time_t clock;
	struct tm tm;
	SYSTEMTIME wtm;
	GetLocalTime(&wtm);
	tm.tm_year = wtm.wYear - 1900;
	tm.tm_mon = wtm.wMonth - 1;
	tm.tm_mday = wtm.wDay;
	tm.tm_hour = wtm.wHour;
	tm.tm_min = wtm.wMinute;
	tm.tm_sec = wtm.wSecond;
	tm.tm_isdst = -1;
	clock = mktime(&tm);
	tp->tv_sec = clock;
	tp->tv_usec = wtm.wMilliseconds * 1000;
	return (0);
}
bool uiSign::Show(cCanvas* pCanvas)
{
	cInterfaceFather::Show(pCanvas);
	if (_text)
	{
		_ftext.SetPos(_text->GetX(), _text->GetY());
	}
	_ftext.Show(pCanvas);
	return true;
}