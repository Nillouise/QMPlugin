// QMPlugin.h : QMPlugin DLL 的主头文件
//

#pragma once

#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含“stdafx.h”以生成 PCH 文件"
#endif

#include "resource.h"		// 主符号


// CQMPluginApp
// 有关此类实现的信息，请参阅 QMPlugin.cpp
//

class CQMPluginApp : public CWinApp
{
public:
	CQMPluginApp();

// 重写
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};

#pragma once


// CQMPlugin 命令目标

class CQMPlugin : public CCmdTarget
{
	DECLARE_DYNCREATE(CQMPlugin)

public:
	CQMPlugin();
	virtual ~CQMPlugin();

	virtual void OnFinalRelease();

	struct DESCRIPTION_LIST
	{
		char *m_lpszItemName;
		char *m_lpszDescription;
		char *m_lpszInterpretTemplate;
	};

	BSTR Test1();
	long Test2(long iNumber1, long iNumber2);
	BSTR Test3(LPCTSTR bstrString1, LPCTSTR bstrString2);
	void GetScreenResolution(VARIANT FAR* ResolutionX, VARIANT FAR* ResolutionY);


protected:
	DECLARE_MESSAGE_MAP()
	DECLARE_OLECREATE(CQMPlugin)
	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()
//	BSTR GetPluginDescription(LPCTSTR bstrItemName);
//	BSTR GetPluginInterpretTemplate(LPCTSTR bstrItemName);

private:
	static DESCRIPTION_LIST m_DescriptionList[];
	static const int m_iDescriptionListSize;
protected:
	BSTR GetPluginDescription(LPCTSTR bstrItemName);
	BSTR GetPluginInterpretTemplate(LPCTSTR bstrItemName);




};


