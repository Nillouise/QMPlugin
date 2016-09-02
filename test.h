#pragma once
#include"Cdmsoft.h"
#include<time.h>
#include<vector>
#include<queue>
#include<functional>
namespace test
{
	void testdm(Cdmsoft dm);
	void findpic(Cdmsoft dm);

	void moveto(Cdmsoft dm);
	void keypress(Cdmsoft dm);
	UINT __stdcall KeyboardInput(LPVOID);

	void minidnf(Cdmsoft dm);

	long findMonster(Cdmsoft dm, int rangeX = 0, int rangeY = 0, int rangeWidth = 800, int rangeHeight = 600,WCHAR *MonColor = L"ff0094-010101",double similar=1.0,int PointCount=500,int monWidth = 30,int monHeight =30);
	class CMonster
	{
	public:
		int x;
		int y;
		int width;
		int height;
		int hitTime;
		CMonster(int x, int y, int width = 0, int height = 0, int hitTime = 0) :x(x), y(y), width(width), height(height), hitTime(hitTime) {};
	};
	int KeyDefaultCallback(int x);
	class CKeyOp
	{
	public:
		std::wstring Key;
		DWORD KeyTime;
		int(*KeyCallback)(int x);
		int KeyType;
		CKeyOp(std::wstring Key = L"", DWORD KeyTime = 0, int KeyType = 0, int(*KeyCallback)(int) = KeyDefaultCallback) :Key(Key), KeyTime(KeyTime), KeyCallback(KeyCallback), KeyType(KeyType) {}
	};
	bool operator < (const CKeyOp &t1, const CKeyOp &t2);
	bool operator > (const CKeyOp &t1, const CKeyOp &t2);
	extern std::vector<CMonster> vecMonster;
	extern CRITICAL_SECTION g_csKeyOp;
	extern std::priority_queue<CKeyOp, std::vector<CKeyOp>, std::greater<CKeyOp> > pqKeyOp;

	class RoomState {
		std::vector<CMonster> vecMonster;
		CRITICAL_SECTION g_csKeyOp;
		std::priority_queue<CKeyOp, std::vector<CKeyOp>, std::greater<CKeyOp> > pqKeyOp;
	};
}