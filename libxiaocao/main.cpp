#include "_global.h"

#include<Accctrl.h>  
#include<Aclapi.h> 
#include <chrono>

#include "../libutil/cFolder.h"
#pragma comment(lib,"dsound.lib")


//string g_pathData;
// string g_pathWdf;
//string gpathExpand;
// string g_pathOther;
//string g_pathPK;
//string g_pathNewBaby;
//string g_pathFriend;
string g_pathSave;
// string g_pathMusic;
//string g_pathCommon; //�ű���·��
//string g_pathMap;  //��ͼ��·��
//string g_MapPath2;
//string g_pathSceneTxt;
const int g_fntSize = 16;
const int g_FPS = 60;
const int g_640 = 800;
const int g_480 = 576;
const int g_half320 = 400;
const int g_half240 = 288;

array<int, 128> g_GlobalValues;

CMainState* g_pMainState;
cCharacter* g_pCharacter;
cObj* g_pHeroObj;
HBRUSH  g_redbrush;
HBRUSH  g_blackbrush;
HBRUSH  g_whitebrush;
HBRUSH  g_bluebrush;
HPEN  g_WhitePen;
HPEN  g_BWhitePen;
int g_xMouse;
int g_yMouse;
//HANDLE  g_hMutex;
//CRITICAL_SECTION g_cs;
WNDCLASSEX g_wcex;
bool g_bFillScreen;
int g_StateType;
int g_StateTypeOld;
HDC g_DC;
HDC g_DC2;
HDC g_ShowDC;
HBITMAP g_MemBitmap;
LPDIRECTSOUND8	 g_pDirectSound=0;

cScript* g_pScriptParent = 0;
cScript* g_pFirst = 0;
//long  g_NumScriptActions = 0;


BITMAPINFO * g_pBmpinfo;
HWND  g_hWnd;
HINSTANCE g_hInst;
void  Resize(long Width, long Height);

int g_iFPS = 0;

LRESULT CALLBACK  WindowProc(HWND hWnd, uint uMsg, WPARAM wParam, LPARAM lParam);
static ulong UpdateTimer = timeGetTime();
static ulong CurrentTime = 0;
int nScreenWidth;
int nScreenHeight;
//std::vector<std::string> getFileNames(const std::string& path, bool isOnlyName = true);

void SetFullScreen2(bool bFill)
{

	if (bFill)												// ȫ��ģʽ
	{
		DEVMODE dmScreenSettings;								// �豸ģʽ
		memset(&dmScreenSettings, 0, sizeof(dmScreenSettings));	// ȷ���ڴ����Ϊ��

		dmScreenSettings.dmSize = sizeof(dmScreenSettings);		// DEVMODE�ṹ�Ĵ�С

		dmScreenSettings.dmPelsWidth = g_640;					// ��ѡ��Ļ���
		dmScreenSettings.dmPelsHeight = g_480; // g_480;					// ��ѡ��Ļ�߶�
		dmScreenSettings.dmBitsPerPel = 32;		// ÿ������ѡ��ɫ�����
		dmScreenSettings.dmFields = DM_BITSPERPEL | DM_PELSWIDTH | DM_PELSHEIGHT;

		// ����������ʾģʽ�����ؽ����ע:CDS_FULLSCREEN ��ȥ��״̬��
		if (ChangeDisplaySettings(&dmScreenSettings, CDS_FULLSCREEN) != DISP_CHANGE_SUCCESSFUL)
		{
			ERRBOX;
		}
		LONG styleValue = ::GetWindowLong(g_hWnd, GWL_STYLE);
		styleValue &= ~WS_CAPTION;
		::SetWindowLong(g_hWnd, GWL_STYLE, styleValue | WS_CLIPSIBLINGS | WS_CLIPCHILDREN);

		SetWindowPos(g_hWnd, 0, 0, 0, g_640, g_480, SWP_FRAMECHANGED);
	}
	else
	{//���ڻ�
		DEVMODE dmScreenSettings;								// �豸ģʽ
		memset(&dmScreenSettings, 0, sizeof(dmScreenSettings));	// ȷ���ڴ����Ϊ��
		dmScreenSettings.dmSize = sizeof(dmScreenSettings);		// DEVMODE�ṹ�Ĵ�С
		dmScreenSettings.dmPelsWidth = nScreenWidth;					// ��ѡ��Ļ���
		dmScreenSettings.dmPelsHeight = nScreenHeight;					// ��ѡ��Ļ�߶�
		dmScreenSettings.dmBitsPerPel = 32;		// ÿ������ѡ��ɫ�����
		dmScreenSettings.dmFields = DM_BITSPERPEL | DM_PELSWIDTH | DM_PELSHEIGHT;
		// ����������ʾģʽ�����ؽ����ע:CDS_FULLSCREEN ��ȥ��״̬��
		if (ChangeDisplaySettings(&dmScreenSettings, CDS_FULLSCREEN) != DISP_CHANGE_SUCCESSFUL)
		{
			ERRBOX;
		}

		::SetWindowLong(g_hWnd, GWL_STYLE, GetWindowLong(g_hWnd, GWL_STYLE)| WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX);
		::SetWindowPos(g_hWnd, NULL, (nScreenWidth >> 1) - g_640 / 2, (nScreenHeight >> 1) - g_480 / 2, g_640, g_480, SWP_FRAMECHANGED);
		Resize(g_640, g_480);
	}


}

int PASCAL WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nShowCmd)
{
	srand((uint)&hInstance);
	auto folder = cFolder::getInstance();
	if (!folder->read(true))
	{
		return 0;
	}
	folder->apply();

	g_pathSave = "";
	ifstream ifile(g_pathSave + "�浵.sav");

	if (ifile.is_open())
	{
		cct::loadGlobal(cInterfaceFriendQiangHua2::Load());
		ifile.close();
		if (g_GlobalValues[127] < 20180318)
		{
			// �Ͽɰ汾
			ccc_msgbox("��������");
			return 0;
		}
	}
	else
	{
		forr(g_GlobalValues, i)
		{
			g_GlobalValues[i] = 0;
		}
		// ����
		g_GlobalValues[7] = 2;
	}

	if (0)
	{
	//	ifile.open(g_pathOther + "����.wdf");
		if (ifile.is_open())
		{
			ifile.close();
		}
		else
		{
			string path = g_pathSave;
			forr(path, i)
			{
				if (path[i] == '/')
				{
					path[i] = '\\';
				}
			}
			system(("md " + path).c_str());
			system(("move ����.wdf " + path).c_str());
		}
	}

	cWasFile m_File;
//	m_File.Open((g_pathOther + "����.wdf").c_str());
	const auto& wdfs = folder->getWdfs().at(g_GlobalValues[6] ? eIterType::iter : eIterType::jd).at((euiType)g_GlobalValues[5]);
	const auto& smaps = folder->getSmaps().at(eMapType::iter);
	auto root = folder->getRoot();
	m_File.Open("ui.wdf");
	m_File.Open("��ɱ.wdf");
	forv(wdfs, k)
	{
		m_File.Open((root + wdfs.at(k)).c_str());
	}
	m_File.Open((root + folder->getSound()).c_str());
	m_File.Open((root + folder->getMusic()).c_str());
	m_File.Open((root + folder->getColor()).c_str());
	forv(smaps, k)
	{
		m_File.OpenMap((root + smaps.at(k)).c_str());
	}

// 	if (g_GlobalValues[6])
// 	{
// 		m_File.Open((g_pathWdf + "����.wdf").c_str());
// 	}
// 	m_File.Open((g_pathWdf + "��Դ.wdf").c_str());
// 	m_File.Open((g_pathWdf + "����.wdf").c_str());
// 	m_File.Open((g_pathWdf + "����.wdf").c_str());
// 	m_File.Open((g_pathWdf + "Ⱦɫ.wdf").c_str());
// 	m_File.Open((g_pathWdf + "�Ի�.wdf").c_str());
// 	m_File.Open((g_pathWdf + "����.wdf").c_str());
// 	int ui = g_GlobalValues[5];
// 	if (ui == 1)
// 	{
// 		m_File.Open((g_pathWdf + "uigy.wdf").c_str());
// 	}
// 	else if (ui == 2)
// 	{
// 		m_File.Open((g_pathWdf + "uisj.wdf").c_str());
// 	}
// 	else if (ui == 3)
// 	{
// 		m_File.Open((g_pathWdf + "uiyz.wdf").c_str());
// 	}
// 	m_File.Open((g_pathWdf + "uijd.wdf").c_str());
// 	m_File.OpenMap((g_pathWdf + "��ͼ.wdf").c_str());

// 	cMyScript sc;
// 	auto names = getFileNames(g_pathCommon);
// 	for (auto name : names)
// 	{
// 		name.pop_back();
// 		name.pop_back();
// 		name.pop_back();
// 		name.pop_back();
// 		sc.LoadScript(name);
// 	}
// 	return 0;

	nScreenWidth = GetSystemMetrics(SM_CXSCREEN);
	nScreenHeight = GetSystemMetrics(SM_CYSCREEN);
	//��ʼ�����ǵĳ��� 
	g_hInst = hInstance;
	//InitializeCriticalSection(&g_cs);
//	g_hMutex=CreateMutex(0, 0, 0);
	g_bFillScreen = false;
	//��ʼ��λͼͷ
	g_pBmpinfo = (BITMAPINFO*)malloc(sizeof(BITMAPINFO)+sizeof(RGBQUAD)* 2);
	g_pBmpinfo->bmiHeader.biPlanes = 1;
	g_pBmpinfo->bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
	g_pBmpinfo->bmiHeader.biCompression = 3;
	g_pBmpinfo->bmiHeader.biBitCount = 16;
	g_pBmpinfo->bmiHeader.biClrUsed = 0;
	g_pBmpinfo->bmiHeader.biClrImportant = 0;
	g_pBmpinfo->bmiHeader.biXPelsPerMeter = 0;
	g_pBmpinfo->bmiHeader.biYPelsPerMeter = 0;
	ulong colorbit = 0xf800;
	memmove(&g_pBmpinfo->bmiColors[0], &colorbit, sizeof(RGBQUAD));
	colorbit = 0x7e0;
	memmove(&g_pBmpinfo->bmiColors[1], &colorbit, sizeof(RGBQUAD));
	colorbit = 0x1f;
	memmove(&g_pBmpinfo->bmiColors[2], &colorbit, sizeof(RGBQUAD));
	////��ƴ���
		g_wcex.cbClsExtra = 0;
		g_wcex.cbSize = sizeof(g_wcex);
		g_wcex.cbWndExtra = 0;
		g_wcex.hbrBackground = 0;
		g_wcex.hCursor = LoadCursor(0, IDC_ARROW);
		g_wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(101/*IDI_ICON1*/));
		g_wcex.hIconSm = g_wcex.hIcon;
		g_wcex.lpszClassName = "�Ǳ���˧";
		g_wcex.hInstance = hInstance;
		g_wcex.lpfnWndProc = WindowProc;	
		g_wcex.lpszMenuName = 0;
		g_wcex.style = CS_CLASSDC;
		//ע�ᴰ��
		if (!RegisterClassEx(&g_wcex))return 0;

		//��������
		g_hWnd = CreateWindow(
			g_wcex.lpszClassName,  //����
			"������",
			WS_CAPTION | WS_SYSMENU|WS_MINIMIZEBOX,//, //���ڵ����ͣ��б���Ͳ˵�
			nScreenWidth / 2 - g_half320, nScreenHeight / 2 - g_half240, g_640, g_480,  //���ڵĴ�С
			0, 0,          //�����ڵľ��  �˵��ľ��
			g_hInst,   // Ӧ�ó���ľ��
			0
			);
		if (!g_hWnd)ERRBOX;
		Resize(g_640, g_480);
		//�Ա괰�ڲ����´���
		ShowWindow(g_hWnd, SW_SHOW);
		UpdateWindow(g_hWnd);
	// ��ʼCOM
	CoInitialize(NULL);


	CMainState* MainState;
	MainState = new CMainState;
	cFightState FightState;
	cEndState EndState;
	cMenuState MenuState;
	g_pMainState = MainState;
	MainState->m_pEndState = &EndState;
	MainState->m_pMenuState = &MenuState;
	g_ShowDC = GetDC(g_hWnd);
	g_DC = CreateCompatibleDC(g_ShowDC);
	g_DC2 = CreateCompatibleDC(g_ShowDC);
	HPEN  oldpen = (HPEN)SelectObject(g_DC2, g_WhitePen);
	COLORREF oldcolor = SetTextColor(g_DC2, RGB(255, 255, 255));



	g_WhitePen = CreatePen(PS_SOLID, 1, RGB(255, 255, 255));
	g_BWhitePen = CreatePen(PS_SOLID, 4, RGB(255, 255, 255));
	
	//�����ı��Ļ��ģʽ
	SetBkMode(g_DC2, TRANSPARENT);
	//SetBkColor(g_DC2, RGB(8, 0, 0));

	g_MemBitmap = CreateCompatibleBitmap(g_ShowDC, g_640, g_480);
	HBITMAP oldmap = (HBITMAP)SelectObject(g_DC, g_MemBitmap);
	g_StateType =  STATE_MAIN; //STATE_MENU;//
	g_StateTypeOld = STATE_MENU;


	
	MainState->m_pFightState = &FightState;
	MainState->m_SkillManager.m_pFightState = &FightState;


	///////////////////////////////////////////////////////////////////////////
	/////////////// changing timer resolution
	///////////////////////////////////////////////////////////////////////////
	UINT TARGET_RESOLUTION = 1; // 1 millisecond target resolution
	TIMECAPS tc;
	UINT wTimerRes = 0;
	if (TIMERR_NOERROR == timeGetDevCaps(&tc, sizeof(TIMECAPS)))
	{
		wTimerRes = min(max(tc.wPeriodMin, TARGET_RESOLUTION), tc.wPeriodMax);
		timeBeginPeriod(wTimerRes);
	}
	LARGE_INTEGER freq;
	QueryPerformanceFrequency(&freq);

	const float _inv = 1.0 / g_FPS;
	LONGLONG _QuadPart = (LONGLONG)(_inv * freq.QuadPart);
	// Main message loop:
	LARGE_INTEGER nLast;
	LARGE_INTEGER nNow;

	QueryPerformanceCounter(&nLast);

	LONGLONG interval = 0LL;
	LONG waitMS = 0L;

//	LARGE_INTEGER freq;
//	QueryPerformanceFrequency(&freq);

	float _deltaTime;
	double _totalTime = 0;
	float _totalSec = 0;

	std::chrono::steady_clock::time_point _lastUpdate = std::chrono::steady_clock::now();

	MSG Msg;
	ZeroMemory(&Msg, sizeof(MSG));
	while (true /*!glview->windowShouldClose()*/)
	{
		if (PeekMessage(&Msg, 0, 0, 0, PM_REMOVE))
		{
			if (Msg.message == WM_QUIT)
			{
				break;
			}
			TranslateMessage(&Msg);
			DispatchMessage(&Msg);
			continue;
		}


		QueryPerformanceCounter(&nNow);
		interval = nNow.QuadPart - nLast.QuadPart;
		if (interval >= _QuadPart)
		{
			nLast.QuadPart = nNow.QuadPart;

			////////////////////////////////////////////////////////////////////////// calculateDeltaTime
			auto now = std::chrono::steady_clock::now();

			// new delta time. Re-fixed issue #1277
// 			if (_nextDeltaTimeZero)
// 			{
// 				_deltaTime = 0;
// 				_nextDeltaTimeZero = false;
// 			}
// 			else
			{
				_deltaTime = std::chrono::duration_cast<std::chrono::microseconds>(now - _lastUpdate).count() / 1000000.0f;
				if (_deltaTime < 0)
				{
					break;
				}
#if defined(_DEBUG)
#else
				if (_deltaTime >= 300)
				{
					break;
				}
#endif
				_totalTime += _deltaTime;
				_totalSec += _deltaTime;
				if (_totalSec >= _inv)
				{
					while (_totalSec >= _inv)
					{
						_totalSec -= _inv;
					}
					++g_iFPS;

					////////////////////////////////////////////////////////////////////////// calculateDeltaTime

					//			g_iFPS= _totalTime * 60;

					////////////////////////////////////////////////////////////////////////// ��ʱ��
					if (g_pMainState->_langtimeLast >= 0)
					{
						g_GlobalValues[20] = ((int)_totalTime - g_pMainState->_langtimeOnce) + g_pMainState->_langtimeLast;
					}

//					timeval tv;
//					gettimeofday(&tv, 0);
//					if (_langtimeLast == 0 && g_GlobalValues[20] != 0)
//					{
//						_langtimeOnce = tv.tv_sec;
//						_langtimeLast = g_GlobalValues[20];
//					}
//					g_GlobalValues[21] = _langtimeLast + tv.tv_sec - _langtimeOnce;
//					if (g_GlobalValues[21] < 0 || abs(g_GlobalValues[20] - g_GlobalValues[21]) > 15)
//					{
//						resetLangTime();
//					}
//					else
//					{
//						g_GlobalValues[20] = g_GlobalValues[21];
//					}

					if (g_pMainState->m_InterfaceTeam.m_NeedShow)
					{
						g_pMainState->m_InterfaceTeam.m_tLangTime.SetString(toString("��ʱ��  %d:%02d:%02d",
							g_GlobalValues[20] / 3600, (g_GlobalValues[20] % 3600) / 60, g_GlobalValues[20] % 60));
					}

				}
				if (g_iFPS % 60 == 0)
				{
					SetWindowText(g_hWnd, "������.С���ս��v20190712");
				}
				//////////////////////////////////////////////////////////////////////////  ��ʱ��
				switch (g_StateType)
				{
				case STATE_MAIN:
					g_StateTypeOld = g_StateType;
					MainState->Frame();
					break;
				case STATE_FIGHT:
					if (g_StateTypeOld != STATE_FIGHT)
					{
						g_pMainState->m_Mp3.Load("ս��BOSS");
					}
					g_StateTypeOld = g_StateType;
					FightState.Frame();
					break;
				case STATE_FIGHT_MUSIC:
					g_StateTypeOld = g_StateType = STATE_FIGHT;
					FightState.Frame();
					break;
				case STATE_MENU:
					g_StateTypeOld = g_StateType;
					MenuState.Frame();
					break;
				case STATE_GAMEOVER:
					EndState.Frame();
					break;
				default:
					PostQuitMessage(1);
					break;
				}
			}
			_lastUpdate = now;
			
		//	director->mainLoop();
		//	glview->pollEvents();
		}
		else
		{
			// The precision of timer on Windows is set to highest (1ms) by 'timeBeginPeriod' from above code,
			// but it's still not precise enough. For example, if the precision of timer is 1ms,
			// Sleep(3) may make a sleep of 2ms or 4ms. Therefore, we subtract 1ms here to make Sleep time shorter.
			// If 'waitMS' is equal or less than 1ms, don't sleep and run into next loop to
			// boost CPU to next frame accurately.
			waitMS = (_QuadPart - interval) * 1000LL / freq.QuadPart - 1L;
			if (waitMS > 1L)
			{
				Sleep(waitMS);
			}
		}
	}

	const int addtime = 1000 / g_FPS;
	static int s_tick = 0;
	ShowCursor(false);
	SetBkMode(g_DC, TRANSPARENT); //�����ı��Ļ��ģʽ
//	::Lock_CurrentProcess();
// 	//��Ϣѭ��
// 	MSG Msg;
// 	ZeroMemory(&Msg, sizeof(MSG));
// 	for (;;)
// 	{
// 		if (PeekMessage(&Msg, 0, 0, 0, PM_REMOVE))
// 		{	
// 			if (Msg.message == WM_QUIT)
// 			{
// 				break;
// 			}
// 			TranslateMessage(&Msg);
// 			DispatchMessage(&Msg);
// 		}
// 		else
// 		{
// 			if (timeGetTime() < UpdateTimer + addtime)
// 			{
// 				Sleep(1);   //��CPU��Ϣһ�� 
// 				continue;
// 			}
// 			UpdateTimer = timeGetTime();
// 			CurrentTime += addtime;
// 
// 
// 			++g_iFPS;
// 			if (++s_tick >= 60)
// 			{
// 				s_tick = 0;
// 			}
// 			switch (g_StateType)
// 			{
// 			case STATE_MAIN:
// 				g_StateTypeOld = g_StateType;
// 				MainState->Frame();
// 				if (s_tick == 0)
// 				{
// 					SetWindowText(g_hWnd, L"������v20180317");
// 				}
// 				break;
// 			case STATE_FIGHT:
// 				if (g_StateTypeOld != STATE_FIGHT)
// 				{
// 					g_pMainState->m_Mp3.Load("ս��BOSS");
// 				}
// 				g_StateTypeOld = g_StateType;
// 				FightState.Frame();
// 				if (s_tick == 0)
// 				{
// 					SetWindowText(g_hWnd, L"������v20180317");
// 				}
// 				break;
// 			case STATE_FIGHT_MUSIC:
// 				g_StateTypeOld = g_StateType = STATE_FIGHT;
// 				FightState.Frame();
// 				break;
// 			case STATE_MENU:
// 				g_StateTypeOld = g_StateType;
// 				MenuState.Frame();
// 				break;
// 			case STATE_GAMEOVER:
// 				EndState.Frame();
// 				break;
// 			default:
// 				PostQuitMessage(1);
// 				break;
// 			}
// 		}
// 	}
	ShowCursor(true);


	
	SelectObject(g_DC2, oldpen);
	DeleteObject(g_WhitePen);
	DeleteObject(g_BWhitePen);
	SetTextColor(g_DC2, oldcolor);
	MainState->Free();
	FightState.Free();
	free(g_pBmpinfo);
	SelectObject(g_DC, oldmap);
	DeleteObject(g_MemBitmap);
	m_File.CloseWDF();
	m_File.Free();
	DeleteDC(g_DC);
	//DeleteDC(g_DC2);
	//DeleteCriticalSection(&g_cs);
	//CloseHandle(g_hMutex);
	SAFE_DELETE(MainState);
	UnregisterClass(g_wcex.lpszClassName, hInstance);
	PostQuitMessage(1);
	return 0;
}


LRESULT CALLBACK  WindowProc(HWND hWnd, uint uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_CLOSE:
		g_pMainState->m_InterfaceSystem2.OnOff(!g_pMainState->m_InterfaceSystem.m_NeedShow);
		return 1;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}
	return DefWindowProc(hWnd, uMsg, wParam, lParam);
}


void Resize(long Width, long Height)
{
	RECT WndRect, ClientRect;
	long WndWidth, WndHeight;

	GetWindowRect(g_hWnd, &WndRect);
	GetClientRect(g_hWnd, &ClientRect);

	WndWidth = (WndRect.right - (ClientRect.right - Width)) - WndRect.left;
	WndHeight = (WndRect.bottom - (ClientRect.bottom - Height)) - WndRect.top;

	MoveWindow(g_hWnd, WndRect.left, WndRect.top, WndWidth, WndHeight, true);


}


#if 0
#include <functional>
#include <sstream>
//#include "../basic/Qstring.h"
//#include "Qassert.h"


bool __enumFiles(std::string fullDir, std::string partDir, const std::function<bool(const std::string&)> &cb, std::stringstream& ss, bool &isNeedCallback, bool &isOnlyName)
{
	WIN32_FIND_DATAA data;
	std::string path = fullDir + "*";
	//������������partDir + cFileName
	if (partDir.size() == 1 && partDir.back() == '/')
		partDir.clear();
	else if (partDir.size() > 1 && partDir.back() != '/')
		partDir += '/';

	HANDLE handle = FindFirstFileA(path.c_str(), &data);
	asert(handle != INVALID_HANDLE_VALUE, "ö��Ŀ¼ʧ��");

	do
	{
		//��Ŀ¼�����ϼ�Ŀ¼
		if ((data.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) && data.cFileName[0] == '.')
			continue;

		//Ŀ¼
		if (data.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
		{
			std::string new_fullDir = fullDir + data.cFileName + "/";
			std::string new_partDir = partDir + data.cFileName + "/";
			if (__enumFiles(new_fullDir, new_partDir, cb, ss, isNeedCallback, isOnlyName))
			{
				FindClose(handle);
				return true;
			}
			continue;
		}

		if (ss.tellp())
			ss << "\n";
		ss << partDir + data.cFileName;

		//�ļ�
		if (isNeedCallback)
		{
			if (isOnlyName)
			{
				if (cb(data.cFileName))
				{
					isNeedCallback = false;
				}
			}
			else
			{
				if (cb(partDir + data.cFileName))
				{
					isNeedCallback = false;
				}
			}
		}
	} while (FindNextFileA(handle, &data));

	FindClose(handle);

	return false;
}


std::string replace(std::string str, std::string to_replace, std::string replace)
{
	std::string::size_type pos = 0;
	std::string::size_type srcLen = to_replace.size();
	std::string::size_type desLen = replace.size();
	pos = str.find(to_replace, pos);
	while ((pos != std::string::npos))
	{
		str.replace(pos, srcLen, replace);
		pos = str.find(to_replace, (pos + desLen));
	}
	return str;
}

std::vector<std::string> getFileNames(const std::string& path, bool isOnlyName)
{
	std::vector<std::string> fileNames;

	std::string fullDir = path;
	fullDir = replace(fullDir, "\\", "/");
	asert(fullDir.size(), "ö��Ŀ¼ʧ��");
	//������������partDir + cFileName
	if (fullDir.back() != '/')
		fullDir += '/';

	std::string partDir = "";
	std::stringstream ss;
	bool isNeedCallback = true;
//	bool isOnlyName = true;
	auto func = [&fileNames](const std::string &filename)
	{
		fileNames.push_back(filename);
		return false;
	};
	__enumFiles(fullDir, partDir, func, ss, isNeedCallback, isOnlyName);
	return fileNames;
}



bool Lock_CurrentProcess()
{
	HANDLE hProcess = ::GetCurrentProcess();
	SID_IDENTIFIER_AUTHORITY sia = SECURITY_WORLD_SID_AUTHORITY;
	PSID pSid/* = new PSID*/;
	bool bSus = false;
	//	bSus = ::InitializeSid(pSid, &sia, NULL);
	bSus = ::AllocateAndInitializeSid(&sia, 1, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, &pSid);
	if (!bSus) goto Cleanup;
	HANDLE hToken;
	//	bSus = ::OpenProcessToken(hProcess, TOKEN_QUERY, &hToken);
	bSus = ::OpenProcessToken(hProcess, TOKEN_ADJUST_PRIVILEGES, &hToken);
	if (!bSus) goto Cleanup;
	ulong dwReturnLength;
	bSus = ::AdjustTokenPrivileges(hProcess, true, NULL, 1024, NULL, &dwReturnLength);
	if (!bSus) goto Cleanup;
	::GetTokenInformation(hToken, TokenUser, NULL, NULL, &dwReturnLength);
	if (dwReturnLength > 0x400) goto Cleanup;
	LPVOID TokenInformation;
	TokenInformation = ::LocalAlloc(LPTR, 0x400);//���������SDK�ĺ���������CRT����
	ulong dw;
	bSus = ::GetTokenInformation(hToken, TokenUser, TokenInformation, 0x400, &dw);
	if (!bSus) goto Cleanup;
	PTOKEN_USER pTokenUser = (PTOKEN_USER)TokenInformation;
	uchar Buf[0x200];
	PACL pAcl = (PACL)&Buf;
	bSus = ::InitializeAcl(pAcl, 1024, ACL_REVISION);
	if (!bSus) goto Cleanup;
	// 	bSus = ::AddAccessDeniedAce(pAcl, ACL_REVISION, 0x000000FA, pSid);
	// 	if (!bSus) goto Cleanup;
	// 	bSus = ::AddAccessAllowedAce(pAcl, ACL_REVISION, 0x00100701, pTokenUser->User.Sid);
	// 	if (!bSus) goto Cleanup;
	if (::SetSecurityInfo(hProcess, SE_KERNEL_OBJECT, DACL_SECURITY_INFORMATION | PROTECTED_DACL_SECURITY_INFORMATION, NULL, NULL, pAcl, NULL) == 0)
		bSus = true;
Cleanup:
	if (hProcess != NULL)
		::CloseHandle(hProcess);
	if (pSid != NULL)
		::FreeSid(pSid);
	return bSus;
}



string get˵��()
{
	string strDesc = "2017.2.21\n";
	strDesc += "��Ϸ�زĹ�ٷ��λ���������\n";
	strDesc += "��������ҵ��Ϊ,�������Ը�\n";
	strDesc += "����ԭ�����,��л�ӷ���(�λ�Ⱥ����5)\n";
	strDesc += "��ӭ +�λ�Ⱥ����5�ٷ�Ⱥ 361715087\n";
	strDesc += "��Ϸ���,�����ַ�����Ϊ,��...\n";
	strDesc += "\n";
	strDesc += "\n";
	strDesc += "1.��Ϸ��ɫ:\n";
	strDesc += "���ֵ���(��ͼ/��ɫ/NPC)\n";
	strDesc += "�����ٻ��޼��� �������� ������� �¹�\n";
	strDesc += "������ͨ����׷�ӷ���\n";
	strDesc += "֧�ֵ�����Ϸ�ֺŴ�С\n";
	strDesc += "֧�ֵ�����·�ٶ�\n";
	strDesc += "֧��˲��(����,�п��ܱ���)\n";
	strDesc += "֧����ʾ/���صз�Ѫ��\n";
	strDesc += "֧��Ѫ���Ҽ���ҩ��Ѫ����\n";
	strDesc += "֧�ֶ��ѵ�(���ģʽ/����ģʽ)\n";
	strDesc += "֧�ֿ��ƶӳ�/����ȫ������\n";
	strDesc += "֧���Զ�ս��\n";
	strDesc += "֧��ָ�Ӷ��Ѽ���\n";
	strDesc += "֧�ֵ���������ʼ�������\n";
	strDesc += "֧��ת������\n";
	strDesc += "֧��ת������\n";
	strDesc += "֧����Ϸ��ʼ�����\n";
	strDesc += "֧�ּӼ����Ե�\n";
	strDesc += "֧�ֿ��ټӵ�\n";
	strDesc += "֧�ֱ�������Ч��\n";
	strDesc += "֧���ٻ��޽���ѡ��\n";
	strDesc += "֧�ֶ�����������/���(������Ѻͱ���������/�ӵ�/����...�ᱻ����)\n";
	strDesc += "֧����Ϸ�е������ѵ�����/�ؼ�/�ӵ㷽��\n";
	strDesc += "֧����̨�Ͱ�ս������Զ������(���ɼӵ�/����/����/����)\n";
	strDesc += "֧����չ��wdf/���ٻ���\n";
	strDesc += "\n";
	strDesc += "\n";
	strDesc += "2.���ɼ��ܵ���:\n";
	strDesc += "���� ʧ�ķ�/�����/��׷� ��������Ч��\n";
	strDesc += "���� ������ �������Ч��\n";
	strDesc += "���� ���׷� ����Ч��\n";
	strDesc += "���� ���ּ��ܺϲ�,������ѪЧ��\n";
	strDesc += "���� �ⶾ���ӻ�ѪЧ��\n";
	strDesc += "���� ���ޱ� ����������\n";
	strDesc += "Ů�� ���亮ɳ ��������Ӱ��Ч��\n";
	strDesc += "���� ����˫��\n";
	strDesc += "���� �����ķ� ����Ч��\n";
	strDesc += "���� �鶯���� ����Ч��\n";
	strDesc += "���� �ߵ����� ���������� ���������\n";
	strDesc += "�ظ� ��ڤ���� ��֪Ч�� ����Ч��\n";
	strDesc += "�ظ� ʬ���� ��ѪЧ��\n";
	strDesc += "�ظ� �������� ����Ч��\n";
	strDesc += "�ظ� ������ �ӹ�Ч��\n";
	strDesc += "�ظ� ��Ȫ֮Ϣ ����Ч��\n";
	strDesc += "�ظ� �����ɢ ȥ������buffЧ��\n";
	strDesc += "�ظ� ������ ���м���\n";
	strDesc += "ħ�� ţ�� ��֪Ч��\n";
	strDesc += "��˿ ���� ���� ���� ����Ч��\n";
	strDesc += "��˿ �þ��� ��������Ч��\n";
	strDesc += "\n";
	strDesc += "\n";
	strDesc += "3.�ٻ��޼��ܵ���:\n";
	strDesc += "���� �вʵ�\n";
	strDesc += "����� �������� ���� ��ɳ���\n";
	strDesc += "������ �ٷ�\n";
	strDesc += "��Ѫ׷�� �ٷ�\n";
	strDesc += "���� �ٷ�\n";
	strDesc += "�绪��ʥ Ч������\n";
	strDesc += "������ɽ �ٷ�\n";
	strDesc += "�����ķ� �ٷ�\n";
	strDesc += "�ƶ��б� �ٷ�\n";
	strDesc += "���ݻ��� �ٷ�\n";
	strDesc += "���ŭ�� Ч������\n";
	strDesc += "�ռ��� Ч������\n";
	strDesc += "���߹��� Ч������\n";
	strDesc += "\n";
	strDesc += "\n";
	strDesc += "4.�ؼ�����:\n";
	strDesc += "����� ��ѪЧ�� �Ƴ�Ч��\n";
	strDesc += "�Ⱥ��ն� ����Ч��\n";
	strDesc += "�޺����� ����Ч��\n";
	strDesc += "\n";
	strDesc += "\n";
	strDesc += "5.���ߵ���:\n";
	strDesc += "Ԫ��Ч��\n";
	strDesc += "���� ��Ů������ʹ�ð�������\n";
	strDesc += "\n";
	strDesc += "\n";
	strDesc += "6.�̵����\n";
	strDesc += "�߼��޾��̵겹ȫ\n";
	strDesc += "�ٻ����̵겹ȫ\n";
	strDesc += "�����̵� +��������+ʱֻ��\n";
	strDesc += "�ɵ����� +��ɫ����-����ҩƷ\n";
	strDesc += "\n";
	strDesc += "\n";
	strDesc += "7.��������:\n";
	strDesc += "+���ɴ���\n";
	strDesc += "�ʵ�����,�������/ս��1�ι�\n";
	strDesc += "\n";
	strDesc += "\n";
	strDesc += "8.��������\n";
	strDesc += "����ȫ�����óԹ����\n";
	strDesc += "�����������޹������޸�\n";
	strDesc += "����Ȯ�ϲ���������Ȯ\n";
	strDesc += "����������ͬʱѧϰ������,�������޳�ͻ\n";
	strDesc += "����ʵ�,������Ϸ������...\n";
	strDesc += "\n";
	strDesc += "\n";
	strDesc += "9.ע������\n";
	strDesc += "��ͼ/NPC/�̵�/�󲿷�һ��,����Ϥԭ�湥��\n";
	strDesc += "����������ο�˵��ͼ\n";
	strDesc += "��浵�Է�����...";

	return strDesc;


	ofstream fileOut;
	fileOut.open("˵����.txt");
	fileOut.write(strDesc.c_str(), strDesc.size());
	fileOut.close();


	strDesc = "2017.2.25\n";
	strDesc += "�޸���꾭�������ر�ͼ���������\n";
	strDesc += "�޸�29~39�������ִ浵��������\n";
	fileOut.open("����.txt");
	fileOut.write(strDesc.c_str(), strDesc.size());
	fileOut.close();
}



int main2()
{
	ifstream File;
	cWasFile m_File;
	ifstream *fileWdf = nullptr;
	ofstream fileOut;
	string strTemp;
	if (0)
	{
		for (const auto &name : getFileNames(gpathExpand))
		{
			File.open(gpathExpand + name);
			if (!File)
			{
				File.close();
				continue;
			}
			File.close();
			m_File.Open(string(gpathExpand + name).c_str());
		}
	}

	if (cct::get()->isClassical)
	{
		string path = g_pathWdf + "jd/";
		for (const auto &name : getFileNames(path))
		{
			File.open(path + name);
			if (!File)
			{
				File.close();
				continue;
			}
			File.close();
			m_File.Open(string(path + name).c_str());
		}
	}


	if (0)
	{
		set<string> pack0;
		for (auto name : getFileNames("C:/Users/wolf/Desktop/wdfpack/����/"))
		{
			name = name.substr(5, name.length() - 5);
			pack0.insert(name);
		}
		for (const auto &name : getFileNames("C:/Users/wolf/Desktop/wdfpack0/����/"))
		{
			if (pack0.find(name.substr(5, name.length() - 5)) == pack0.end())
			{
				asert(false, "����%s", name.c_str());
			}
		}
	}




	if (1)
	{
		for (const auto &name : getFileNames(g_pathWdf/*, false*/))
		{
			File.open(g_pathWdf + name);
			if (!File)
			{
				File.close();
				continue;
			}
			File.close();
			m_File.Open(string(g_pathWdf + name).c_str());
		}
	}

	if (0)
	{
		for (auto name : getFileNames(g_pathNewBaby))
		{
			name.pop_back();
			name.pop_back();
			name.pop_back();
			name.pop_back();
			int i = atoi(name.c_str());
			if (i >= 0 && i <= 162)
			{
				cct::get()->newBabys.insert(i);
			}
		}
	}


	if (cct::get()->juQing == 10087)
	{
		ifstream file(gpathExpand + "ȫ��wdf.txt");
		if (!file)
		{
			asert(bool(File), "�Ҳ���(ȫ��wdf.txt)");
			return 0;
		}
		int num;
		file >> num;
		getline(file, strTemp);
		unsigned long uid;

		for (int i = 0; i < num; ++i)
		{
			file >> uid;
			bool isFound = false;
			for (int k = 0; k < m_File.s_wdfNum; k++)
			{
				if (m_File.m_pWdf[k] == 0)
					continue;
				if (m_File.m_pWdf[k]->SearchFile(uid))
				{
					isFound = true;
					break;
				}
			}
			if (!isFound)
			{
				cct::get()->pushWdf2(strTemp, uid);
			}
			getline(file, strTemp);
		}
		cct::get()->saveWdf();
	}

	if (cct::get()->juQing == 10088)
	{

		ifstream file(gpathExpand + "����wdf.txt");
		if (!file)
		{
			asert(bool(File), "�Ҳ���(����wdf.txt)");
			return 0;
		}
		int num;
		file >> num;
		getline(file, strTemp);
		vector<unsigned long> uids;
		uids.resize(num);
		for (unsigned long i = 0; i < num; ++i)
		{
			file >> uids[i];
		}
		file.close();

		for (unsigned long i = 0; i < num; ++i)
		{
			bool b = m_File.GetFileP(uids[i], fileWdf, [&](const uchar *data)
			{
				int size = 18;
				fileOut.open(gpathExpand + toString("����%lu", uids[i]), ios_base::binary);
				if (!fileOut)
				{
					fileOut.close();
					asert(false, "д������ļ�ʧ��");
					return;
				}
				fileOut.write((char*)data, size);
				fileOut.close();
			});
			asert(b, "д������ļ�ʧ��");
		}
	}


	if (0)
	{
		fileOut.close();
		vector<unsigned long > ids =
		{ 481695805, 1324670936, 916542457, 2880121122, 916542457,
		3707768443, 2121775169, 2233389510,
		623405626, 1499046182, 247762293, 4279487352, 1953154114, 1953154114, 1735308365, 1546483919, 575768071, 3952815488, 963848079 };
		ids = { 395811073 };
		forv(ids, i)
		{
			bool b = m_File.GetFileP(ids[i], fileWdf, [&](const uchar *data)
			{
				int size = 18;
				fileOut.open(gpathExpand + toString("%04d-%x-0.was", i, ids[i]), ios_base::binary);
				if (!fileOut)
				{
					fileOut.close();
					asert(false, "д������ļ�ʧ��");
					return;
				}
				fileOut.write((char*)data, size);
				fileOut.close();
			});
		}

	}

	if (cct::get()->juQing == 10089)
	{
		ifstream file(gpathExpand + "����wdf.txt");
		if (!file)
		{
			asert(bool(File), "�Ҳ���(����wdf.txt)");
			return 0;
		}
		int num;
		file >> num;
		getline(file, strTemp);
		vector<unsigned long> uids;
		uids.resize(num);
		for (unsigned long i = 0; i < num; ++i)
		{
			file >> uids[i];
		}
		file.close();

		unsigned long mySize = (1 << 21);
		unsigned long  uSize = (1 << 21);
		char *myData = new char[mySize];
		char *uData = new char[uSize];

		unsigned long uNew = 0;
		const WDataFileIndex *pf = nullptr;

		vector<WDataFileIndex> tables;
		int noneNum = -1;
		for (unsigned long i = 0; i < num; ++i)
		{
			const unsigned long &u = uids[i];
			file.open(gpathExpand + toString("����%lu", u), ios::binary);
			file.seekg(0, ios_base::end);

			mySize = (int)file.tellg();
			file.seekg(0, ios_base::beg);
			file.read(myData, mySize);
			file.close();

			uNew = 0;
			for (unsigned long iWdf = 0; iWdf < m_File.s_wdfNum; ++iWdf)
			{
				if (m_File.m_pWdf[iWdf] == 0)continue;
				for (unsigned long idx = 0; idx < m_File.m_pWdf[iWdf]->m_Number; ++idx)
				{
					pf = &m_File.m_pWdf[iWdf]->m_pIndex[idx];
					if (pf->size != mySize)
					{
						continue;
					}

					fileWdf = m_File.m_pWdf[iWdf]->GetFileHandle();
					fileWdf->seekg(pf->offset, ios_base::beg);
					fileWdf->read(uData, pf->size);

					bool isSame = true;
					for (unsigned long x = 100; x < mySize; ++x)
					{
						if (*(myData + x) != *(uData + x))
						{
							isSame = false;
							break;
						}
					}
					if (isSame)
					{
						uNew = pf->uid;
						break;
					}
				}
				if (uNew)
				{
					if (uNew != u)
					{
						tables.push_back({ u, uNew, 0, 0 });
					}
					break;
				}
			}
			if (!uNew)
			{
				fileOut.open(gpathExpand + toString("%04d-%x-0.was", ++noneNum, u), ios_base::binary);
				fileOut.write(myData, mySize);
				fileOut.close();
			}
		}

		delete[] myData;
		delete[] uData;

		fileOut.open(gpathExpand + "��Ӧwdf.txt");
		if (!fileOut)
		{
			asert(false, "д��(��Ӧwdf.txt)ʧ��");
			return 0;
		}
		fileOut << tables.size() << "\n";
		for (int i = 0; i < tables.size(); ++i)
		{
			fileOut << tables[i].uid << "	" << tables[i].offset << "\n";
		}
		fileOut.close();
		Q::msgbox2("", "д��(��Ӧwdf.txt)���");
	}


	if (cct::get()->juQing == 10090)
	{
		std::map<unsigned long, int> maps;
		for (unsigned long iWdf = 0; iWdf < m_File.s_wdfNum; ++iWdf)
		{
			if (m_File.m_pWdf[iWdf] == 0)continue;
			for (unsigned long idx = 0; idx < m_File.m_pWdf[iWdf]->m_Number; ++idx)
			{
				const unsigned long &uid = m_File.m_pWdf[iWdf]->m_pIndex[idx].uid;
				const auto it = maps.find(uid);
				if (it == maps.end())
				{
					maps.insert(make_pair(uid, 0));
				}
				else
				{
					++it->second;
				}
			}
		}
		std::map<unsigned long, int> map2s;
		for (const auto &u : maps)
		{
			if (u.second > 0)
			{
				map2s.insert(u);
			}
		}

		fileOut.open(gpathExpand + "�ظ�wdf.txt");
		if (!fileOut)
		{
			asert(false, "д��(�ظ�wdf.txt)ʧ��");
			return 0;
		}
		fileOut << map2s.size() << "\n";
		for (const auto &u : map2s)
		{
			fileOut << u.first << "	" << u.second << "\n";
		}
		fileOut.close();
		Q::msgbox2("", "д��(�ظ�wdf.txt)���");
	}

	if (0)
	{
		ifstream file(gpathExpand + "��Ӧwdf.txt");
		if (!file)
		{
			asert(bool(File), "�Ҳ���(��Ӧwdf.txt)");
			return 0;
		}
		int num;
		unsigned long id, idNew;
		file >> num;
		getline(file, strTemp);
		for (unsigned long i = 0; i < num; ++i)
		{
			file >> id >> idNew;
			cct::get()->pushTable(id, idNew);
			getline(file, strTemp);
		}
		file.close();
		file.open(gpathExpand + "����wdf.txt");
		if (!file)
		{
			asert(bool(File), "�Ҳ���(����wdf.txt)");
			return 0;
		}
		file >> num;
		getline(file, strTemp);
		for (unsigned long i = 0; i < num; ++i)
		{
			file >> id;
			cct::get()->pushIgnore(id);
			getline(file, strTemp);
		}
		file.close();
	}

	if (0)
	{
		for (auto name : getFileNames(g_pathSceneTxt))
		{
			name.pop_back();
			name.pop_back();
			name.pop_back();
			name.pop_back();
			cct::get()->mapNames.insert(name);
		}
	}
	if (0)
	{
		ifstream file("C:/Users/wolf/Desktop/mapIDs.txt");
		if (!file)
		{
			asert(bool(File), "�Ҳ���(mapIDs.txt)");
			return 0;
		}
		int num;
		vector<int> ids;
		file >> num;
		getline(file, strTemp);
		ids.resize(num);
		for (unsigned long i = 0; i < num; ++i)
		{
			file >> ids[i];
			getline(file, strTemp);
		}
		file.close();
		for (const auto &id : ids)
		{
			system(toString("copy D:\\xyq2\\scene\\%d.map C:\\Users\\wolf\\Desktop\\scenecopy\\%d.map", id, id).c_str());
		}
	}



	if (0)
	{
		vector<string> wdfpath;
		wdfpath.resize(33);
		for (int i = 0; i < 33; i++)
		{
			wdfpath[i] = g_pathWdf;
		}
		wdfpath[0] += "shape.wda";
		wdfpath[1] += "shape.wdb";
		wdfpath[2] += "shape.wdc";
		wdfpath[3] += "shape.wdf";
		wdfpath[4] += "shape1.wdf";
		wdfpath[5] += "shape.wd1";
		wdfpath[6] += "shape.wd2";
		wdfpath[7] += "shape.wd3";
		wdfpath[8] += "shape.wd4";
		wdfpath[9] += "shape.wd5";
		wdfpath[10] += "shape.wd6";
		wdfpath[11] += "shape.wd7";
		wdfpath[12] += "shape.wd8";
		wdfpath[13] += "shape.wd9";
		wdfpath[14] += "shape.wd11";
		wdfpath[15] += "wzife.wd1";
		wdfpath[16] += "wzife.wd2";
		wdfpath[17] += "wzife.wd3";
		wdfpath[18] += "wzife.wd4";
		wdfpath[19] += "wzife.wdf";
		wdfpath[20] += "smap.wdf";
		wdfpath[21] += "item.wdf";
		wdfpath[22] += "item.wd1";
		wdfpath[23] += "item.wd2";
		wdfpath[24] += "addon.wdf";
		wdfpath[25] += "magic.wdf";
		wdfpath[26] += "magic.wd1";
		wdfpath[27] += "magic.wd2";
		wdfpath[28] += "waddon.wdf";  //״̬
		wdfpath[29] += "sound.wdf";
		wdfpath[30] += "sound1.wdf";
		wdfpath[31] += "mapani.wdf";
		wdfpath[32] += "atom.wdf";
		for (int i = 0; i < 33; i++)
			m_File.Open(wdfpath[i].c_str());

		m_File.Open(string(g_pathOther + "_1.wdf").c_str());

	}

	return 0;
}



void main3()
{


	////��������
	if (0)
	{
		string path;
		wstring path2;
		auto func = [&]()
		{
			StringToWString(path, path2);
			//			path2 = path;
		};
		path = g_pathData;
		path += "font\\hyh1gjm.ttf";
		func();
		AddFontResourceEx(path2.c_str(), FR_PRIVATE, 0);
		path = g_pathData;
		path += "font\\hyb1gjm.ttf";
		func();
		AddFontResourceEx(path2.c_str(), FR_PRIVATE, 0);
		path = g_pathData;
		path += "font\\hyj4gjm.ttf";
		func();
		AddFontResourceEx(path2.c_str(), FR_PRIVATE, 0);
		path = g_pathData;
		path += "font\\hksnt.ttf";
		func();
		AddFontResourceEx(path2.c_str(), FR_PRIVATE, 0);
		path = g_pathData;
		path += "font\\������ͷ�����.ttf";
		func();
		AddFontResourceEx(path2.c_str(), FR_PRIVATE, 0);
	}


	if (0)
	{
		string path;
		wstring path2;
		path = g_pathData;
		path += "font\\hyh1gjm.ttf";
		auto func = [&]()
		{
			StringToWString(path, path2);
			//			path2 = path;
		};
		func();
		RemoveFontResourceEx(path2.c_str(), FR_PRIVATE, 0);
		path = g_pathData;
		path += "font\\hyb1gjm.ttf";
		func();
		RemoveFontResourceEx(path2.c_str(), FR_PRIVATE, 0);
		path = g_pathData;
		path += "font\\hyj4gjm.ttf";
		func();
		RemoveFontResourceEx(path2.c_str(), FR_PRIVATE, 0);
		path = g_pathData;
		path += "font\\hksnt.ttf";
		func();
		RemoveFontResourceEx(path2.c_str(), FR_PRIVATE, 0);
		path = g_pathData;
		path += "font\\������ͷ�����.ttf";
		func();
		RemoveFontResourceEx(path2.c_str(), FR_PRIVATE, 0);
	}

}

#endif