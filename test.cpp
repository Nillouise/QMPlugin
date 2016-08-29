#include"stdafx.h"
#include"test.h"
#include<sstream>
#include<fstream>
#include<queue>
#include<functional>
std::string SetKey;
DWORD SetKeyTime;
int SetInterupt;
int(*SetCallback)(int x);

int KeyDefaultCallback(int x)
{
	return 0;
}
class CKeyOp
{
public:
	std::wstring Key;
	DWORD KeyTime;
	int(*KeyCallback)(int x);
	int KeyType;
	CKeyOp(std::wstring Key = L"", DWORD KeyTime = 0,  int KeyType = 0, int(*KeyCallback)(int) = KeyDefaultCallback) :Key(Key), KeyTime(KeyTime), KeyCallback(KeyCallback), KeyType(KeyType) {}
};
bool operator < (const CKeyOp &t1, const CKeyOp &t2)
{
	return t1.KeyTime < t2.KeyTime;
}

CRITICAL_SECTION g_csKeyOp;
std::priority_queue<CKeyOp> pqKeyOp;

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
class CMonster
{
public:
	int x;
	int y;
	int width;
	int height;
	int hitTime;

	CMonster(int x,int y,int width=0,int height=0,int hitTime=0):x(x),y(y),width(width),height(height),hitTime(hitTime)
	{
		
	}
};
std::queue<CMonster> pqMonster;
void test::minidnf(Cdmsoft dm)
{
	const std::wstring moncolor = L"ff0000";



}
