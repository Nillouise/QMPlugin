#include"stdafx.h"
#include"test.h"
#include<sstream>
#include<fstream>
#include<queue>
#include<functional>
#include<cmath>
using namespace test;

std::vector<test::CMonster> test::vecMonster;
CRITICAL_SECTION test::g_csKeyOp;
std::priority_queue<CKeyOp,std::vector<CKeyOp>,std::greater<CKeyOp> > test::pqKeyOp;

bool test::operator < (const CKeyOp &t1, const CKeyOp &t2)
{
	return t1.KeyTime < t2.KeyTime;
}
bool test::operator > (const CKeyOp &t1, const CKeyOp &t2)
{
	return t1.KeyTime > t2.KeyTime;
}

int test::KeyDefaultCallback(int x)
{
	return 0;
}



UINT __stdcall test::KeyboardInput(LPVOID)
{
	Cdmsoft dm;
	::CoInitialize(NULL);
	CLSID clsid;
	HRESULT hr = CLSIDFromProgID(OLESTR("dm.dmsoft"), &clsid);
	dm.CreateDispatch(clsid);

	CKeyOp keyop;
	while (true)
	{
		Sleep(20);
		::EnterCriticalSection(&g_csKeyOp);
		if (pqKeyOp.empty())
		{
			LeaveCriticalSection(&g_csKeyOp);
			continue;
		}
		keyop = pqKeyOp.top();
		if (keyop.KeyTime > GetTickCount())
		{
			::LeaveCriticalSection(&g_csKeyOp);
			continue;
		}
		std::wofstream txtDebug(L"C:\\code\\dm\\QMDebug.txt",std::ios::app);
		txtDebug << keyop.Key<<" "<<keyop.KeyTime<<" "<<keyop.KeyType << " " << std::endl;
		txtDebug.close();
		pqKeyOp.pop();
		::LeaveCriticalSection(&g_csKeyOp);

		switch (keyop.KeyType)
		{
		case 0:
			dm.KeyPressChar(keyop.Key.c_str());
			keyop.KeyCallback(0);
			break;
		case 1:
			dm.KeyDownChar(keyop.Key.c_str());
			keyop.KeyCallback(0);
			break;
		case 2:
			dm.KeyUpChar(keyop.Key.c_str());
			keyop.KeyCallback(0);
			break;
		default:
			break;
		}
	}

	return 0;
}


void test::testdm(Cdmsoft dm)
{
	if (dm == NULL)
	{
		MessageBox(NULL, L"getNULLdm", L"fdsf", 0);
	}
	else if (dm.GetPath().GetLength() == 0)
	{
		MessageBox(NULL, L"getNULLpath namespace test ", L"fdsf", 0);
	}
	else {
		MessageBox(NULL, L"getsuccesspath", L"fdsf", 0);
	}
	return;
}

void test::findpic(Cdmsoft dm)
{
	VARIANT x, y;
	dm.FindPic(0, 0, 400, 400, L"C:\\code\\dm\\computer.bmp", L"000000", 1.0, 0, &x, &y);

	std::ofstream txtdebug("c:\\code\\dm\\dmdebug.txt", std::ios::app);
	txtdebug << x.intVal << " " << y.intVal << std::endl;
	txtdebug.close();
	return;
}

void test::moveto(Cdmsoft dm)
{
}

void test::keypress(Cdmsoft dm)
{

}




void test::minidnf(Cdmsoft dm)
{
	::InitializeCriticalSection(&test::g_csKeyOp);
	UINT uId;
	HANDLE hKey = (HANDLE)::_beginthreadex(NULL, 0, test::KeyboardInput, NULL, 0, &uId);
	srand((int)time(0));
	MessageBox(NULL, L"C:\\code\\QMDebug.txt", L"LFD", 0);
	while (true)
	{
		std::wstring k = (rand() % 2) == 0 ? L"LEFT" : L"RIGHT";
		::EnterCriticalSection(&g_csKeyOp);
		pqKeyOp.push(CKeyOp(k, GetTickCount() + 50,1));
		pqKeyOp.push(CKeyOp(k, GetTickCount() + 400, 2));
		::LeaveCriticalSection(&g_csKeyOp);
		Sleep(1200);

		std::wofstream txtDebug(L"C:\\code\\QMDebug.txt", std::ios::app);
		test::findMonster(dm);
		auto &mon = test::vecMonster;
		txtDebug << "case : ";
		for (auto iter = mon.begin(); iter != mon.end(); iter++)
		{
			txtDebug << (*iter).x << " " << (*iter).y << std::endl;
		}
		txtDebug.close();

	}

}

long test::findMonster(Cdmsoft dm, int rangeX, int rangeY , int rangeWidth , int rangeHeight , WCHAR *MonColor, double similar , int PointCount , int monWidth , int monHeight )
{
	static DWORD pretime = GetTickCount();
	CString cs = dm.FindColorBlockEx(rangeX, rangeY, rangeWidth, rangeHeight, MonColor, similar, PointCount, monWidth, monHeight);
	long count = dm.GetResultCount(cs);
	int prex = -100;
	int prey = -100;
	vecMonster.clear();
	for (int i = 0; i < 1; i++)
	{
		VARIANT intX, intY;
		int dm_ret = dm.GetResultPos(cs, i, &intX, &intY);
		if (abs(intX.intVal - prex) < monWidth/3 && abs(intY.intVal - prey) < monHeight/3)
		{
			continue;
		}
		prex = intX.intVal;
		prey = intY.intVal;
		
		vecMonster.push_back(CMonster(intX.intVal, intY.intVal));
	}
	return count;
}
