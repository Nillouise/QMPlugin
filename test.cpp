#include"stdafx.h"
#include"test.h"
#include<sstream>
#include<fstream>
#include<queue>
#include<functional>
#include<cmath>
using namespace test;
std::string SetKey;
DWORD SetKeyTime;
int SetInterupt;
int(*SetCallback)(int x);

bool test::operator < (const CKeyOp &t1, const CKeyOp &t2)
{
	return t1.KeyTime < t2.KeyTime;
}


int test::KeyDefaultCallback(int x)
{
	return 0;
}

CRITICAL_SECTION test::g_csKeyOp;
std::priority_queue<CKeyOp> test::pqKeyOp;

int KeyboardInput()
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

std::vector<test::CMonster> test::vecMonster;


void test::minidnf(Cdmsoft dm)
{
	const std::wstring moncolor = L"ff0000";
}

long test::findMonster(Cdmsoft dm, int rangeX, int rangeY , int rangeWidth , int rangeHeight , WCHAR *MonColor, double similar , int PointCount , int monWidth , int monHeight )
{
	static DWORD pretime = GetTickCount();
	CString cs = dm.FindColorBlockEx(rangeX, rangeY, rangeWidth, rangeHeight, MonColor, similar, PointCount, monWidth, monHeight);
	long count = dm.GetResultCount(cs);
	int prex = -100;
	int prey = -100;
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
