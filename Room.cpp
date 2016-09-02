#include "Room.h"
#include"stdafx.h"
#include<sstream>
#include<fstream>
#include<queue>
#include<functional>
#include<cmath>

long gandalfr::CMonster::findMonster(Cdmsoft dm, int rangeX, int rangeY, int rangeWidth, int rangeHeight, WCHAR * MonColor, double similar, int PointCount, int monWidth, int monHeight)
{

	static DWORD pretime = GetTickCount();
	CString cs = dm.FindColorBlockEx(rangeX, rangeY, rangeWidth, rangeHeight, MonColor, similar, PointCount, monWidth, monHeight);
	long count = dm.GetResultCount(cs);
	int prex = -100;
	int prey = -100;
	CMonster::vecCMon.clear();
	for (int i = 0; i < 1; i++)
	{
		VARIANT intX, intY;
		int dm_ret = dm.GetResultPos(cs, i, &intX, &intY);
		if (abs(intX.intVal - prex) < monWidth / 3 && abs(intY.intVal - prey) < monHeight / 3)
		{
			continue;
		}
		prex = intX.intVal;
		prey = intY.intVal;

		vecMonster.push_back(CMonster(intX.intVal, intY.intVal));
	}

	return 0;
}

int gandalfr::CDecision::getMonsterOverlay(CRect rectSkill, std::vector<std::vector<CRect>> &receive)
{
	//preprocess the monster collide with rectSkill and  calculate the 1 monster range.
	receive.push_back(std::vector<CRect>());
	for (auto iter = CMonster::m_vecCMon.begin(); iter != CMonster::m_vecCMon.end(); iter++)
	{
		CRect curMon = (*iter).m_rect;
		curMon.x = curMon.x - rectSkill.width / 2;
		curMon.width = curMon.width + rectSkill.width;
		curMon.y = curMon.y - rectSkill.height / 2;
		curMon.height = curMon.height + rectSkill.height;
		receive[0].push_back(curMon);
	}

	//use pre layer to calculate next layer that overlay
	for (int count = 0; ; count++)
	{
		receive.push_back(std::vector<CRect>());
		for (auto iteri = receive[count].begin(); iteri != receive[0].end(); iteri++)
		{
			for (auto iterj = iteri + 1; iterj != receive[0].end(); iterj++)
			{
				CRect &i = (*iteri);
				CRect &j = (*iterj);
				CRect r;
				r.x = max(i.x, j.x);
				r.y = max(i.y, j.y);
				int x = min(i.x + i.width, j.x + j.width);
				int y = min(i.y + i.height, j.y + j.height);
				if (r.x > x || r.y > y)
					continue;
				r.width = x - r.x;
				r.height = y - r.y;
				receive[count+1].push_back(r);
			}
		}
		if (receive[count + 1].size() < 2)
			break;
	}




	return 0;
}
