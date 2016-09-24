// QMPlugin.cpp : 定义 DLL 的初始化例程。
//

#include "stdafx.h"
#include "QMPlugin.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//
//TODO: 如果此 DLL 相对于 MFC DLL 是动态链接的，
//		则从此 DLL 导出的任何调入
//		MFC 的函数必须将 AFX_MANAGE_STATE 宏添加到
//		该函数的最前面。
//
//		例如:
//
//		extern "C" BOOL PASCAL EXPORT ExportedFunction()
//		{
//			AFX_MANAGE_STATE(AfxGetStaticModuleState());
//			// 此处为普通函数体
//		}
//
//		此宏先于任何 MFC 调用
//		出现在每个函数中十分重要。这意味着
//		它必须作为函数中的第一个语句
//		出现，甚至先于所有对象变量声明，
//		这是因为它们的构造函数可能生成 MFC
//		DLL 调用。
//
//		有关其他详细信息，
//		请参阅 MFC 技术说明 33 和 58。
//

// CQMPluginApp

BEGIN_MESSAGE_MAP(CQMPluginApp, CWinApp)
END_MESSAGE_MAP()


// CQMPluginApp 构造

CQMPluginApp::CQMPluginApp()
{
	// TODO: 在此处添加构造代码，
	// 将所有重要的初始化放置在 InitInstance 中
}


// 唯一的一个 CQMPluginApp 对象

CQMPluginApp theApp;

const GUID CDECL _tlid = { 0xC86D6F66, 0x5A41, 0x42A2, { 0xBC, 0x25, 0xDA, 0x9, 0x82, 0x29, 0x25, 0xD0 } };
const WORD _wVerMajor = 1;
const WORD _wVerMinor = 0;


// CQMPluginApp 初始化

BOOL CQMPluginApp::InitInstance()
{
	CWinApp::InitInstance();

	// 将所有 OLE 服务器(工厂)注册为运行。这将使
	//  OLE 库得以从其他应用程序创建对象。
	COleObjectFactory::RegisterAll();

	return TRUE;
}

// DllGetClassObject - 返回类工厂

STDAPI DllGetClassObject(REFCLSID rclsid, REFIID riid, LPVOID* ppv)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	return AfxDllGetClassObject(rclsid, riid, ppv);
}


// DllCanUnloadNow - 允许 COM 卸载 DLL

STDAPI DllCanUnloadNow(void)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	return AfxDllCanUnloadNow();
}


// DllRegisterServer - 将项添加到系统注册表

STDAPI DllRegisterServer(void)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	if (!AfxOleRegisterTypeLib(AfxGetInstanceHandle(), _tlid))
		return SELFREG_E_TYPELIB;

	if (!COleObjectFactory::UpdateRegistryAll())
		return SELFREG_E_CLASS;

	return S_OK;
}


// DllUnregisterServer - 将项从系统注册表中移除

STDAPI DllUnregisterServer(void)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	if (!AfxOleUnregisterTypeLib(_tlid, _wVerMajor, _wVerMinor))
		return SELFREG_E_TYPELIB;

	if (!COleObjectFactory::UpdateRegistryAll(FALSE))
		return SELFREG_E_CLASS;

	return S_OK;
}
// QMPlugin.cpp : 实现文件
//

#include "stdafx.h"
#include "QMPlugin.h"
#include "QMPlugin.h"


// CQMPlugin

IMPLEMENT_DYNCREATE(CQMPlugin, CCmdTarget)


CQMPlugin::CQMPlugin()
{
	EnableAutomation();
	
	// 为了使应用程序在 OLE 自动化对象处于活动状态时保持
	//	运行，构造函数调用 AfxOleLockApp。
	
	AfxOleLockApp();
}

CQMPlugin::~CQMPlugin()
{
	// 为了在用 OLE 自动化创建所有对象后终止应用程序，
	// 	析构函数调用 AfxOleUnlockApp。
	
	AfxOleUnlockApp();
}


void CQMPlugin::OnFinalRelease()
{
	// 释放了对自动化对象的最后一个引用后，将调用
	// OnFinalRelease。基类将自动
	// 删除该对象。在调用该基类之前，请添加您的
	// 对象所需的附加清理代码。

	CCmdTarget::OnFinalRelease();
}


BEGIN_MESSAGE_MAP(CQMPlugin, CCmdTarget)
END_MESSAGE_MAP()


BEGIN_DISPATCH_MAP(CQMPlugin, CCmdTarget)

	DISP_FUNCTION(CQMPlugin, "Get_Plugin_Description", GetPluginDescription, VT_BSTR, VTS_BSTR)
	DISP_FUNCTION(CQMPlugin, "Get_Plugin_Interpret_Template", GetPluginInterpretTemplate, VT_BSTR, VTS_BSTR)
	//以上两行不要更改


//	#error 插件命令注册
	//编译时注释掉上面一句
	//插件的命令函数要在这注册，应该是VS自动注册的，但我试了不行，照样子手动注册一下吧
	//CQMPlugin这个不变，函数名要加引号，函数名不加引号，输出类型，输入类型要和参数匹配
	//不明白的找些COM的文章看看。

	//注册好了 打开QMPlugin.idl 文件。
	DISP_FUNCTION(CQMPlugin, "Test1", Test1, VT_BSTR, VTS_NONE)
	DISP_FUNCTION(CQMPlugin, "Test2", Test2, VT_I4, VTS_I4 VTS_I4)
	DISP_FUNCTION(CQMPlugin, "Test3", Test3, VT_BSTR, VTS_BSTR VTS_BSTR)
	DISP_FUNCTION(CQMPlugin, "GetScreenResolution", GetScreenResolution, VT_EMPTY, VTS_PVARIANT VTS_PVARIANT)
END_DISPATCH_MAP()

// 注意: 我们添加 IID_IQMPlugin 支持
//  以支持来自 VBA 的类型安全绑定。此 IID 必须同附加到 .IDL 文件中的
//  调度接口的 GUID 匹配。

// {EB62CBA9-5F62-44DF-9154-D33BF5DF213B}
static const IID IID_IQMPlugin =
{ 0xEB62CBA9, 0x5F62, 0x44DF, { 0x91, 0x54, 0xD3, 0x3B, 0xF5, 0xDF, 0x21, 0x3B } };

BEGIN_INTERFACE_MAP(CQMPlugin, CCmdTarget)
	INTERFACE_PART(CQMPlugin, IID_IQMPlugin, Dispatch)
END_INTERFACE_MAP()

// {B0103678-8D56-4946-9C47-59B02AA4D91C}
//IMPLEMENT_OLECREATE_FLAGS(CQMPlugin, "QMPlugin.QMPlugin", afxRegApartmentThreading, 0xb0103678, 0x8d56, 0x4946, 0x9c, 0x47, 0x59, 0xb0, 0x2a, 0xa4, 0xd9, 0x1c)


//#error 创建 GUID
//编译时注释掉上面一句

//用你的插件名字 替换 "插件名字" 只能用英文。
//创建 GUID ,替换后面的GUID  0x00000000, 0x0000, 0x0000, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
//为防止遗漏，加了注释，请去掉 注释 

IMPLEMENT_OLECREATE_FLAGS(CQMPlugin, "QMPlugin.demo", afxRegApartmentThreading, 0xe5f7a167, 0x8d58, 0x4e40, 0xb8, 0x1e, 0xf3, 0xb7, 0x12, 0xe1, 0x5f, 0x4e)

/*********************************************************************
 * 名称:m_DescriptionList
 * 你可以把它看成一个表格，表格中的每一行代表了一条插件命令。
 * 每行第一个字符串是插件命令的名字（如果为空，则代表整个插件）；第二个字符串是这条插件命令的解释；
 * 第三个字符串是插件命令的显示模板信息，其中的$1 $2 ... 等内容在显示时将用第一个参数、第二个参数、... 代替
 * 当你需要新增一条插件命令的时候，就需要在表格里面加一行。
*********************************************************************/
CQMPlugin::DESCRIPTION_LIST CQMPlugin::m_DescriptionList[] = 
{
	{"","在这里写您的插件的说明信息",""},
	{"Test1","这是第一个插件函数的说明","得到一个字符串"},
	{"Test2","这是第二个插件函数的说明","计算 $1 与 $2 的和"},
	{"Test3","这是第三个插件函数的说明","字符串 $1 与 $2 的连接"},
};


//这行您不需要看懂，也不需要修改
const int CQMPlugin::m_iDescriptionListSize = sizeof(CQMPlugin::m_DescriptionList) / sizeof(CQMPlugin::DESCRIPTION_LIST);

// CQMPlugin 消息处理程序


BSTR CQMPlugin::GetPluginDescription(LPCTSTR bstrItemName)
{
	//OutputDebugString(L"CQMPlugin::GetPluginDescription");
	CString CSbItemName = bstrItemName;
	//OutputDebugString(L"bstrItemName:" + CSbItemName);
	int i = 0;
	while(i<CQMPlugin::m_iDescriptionListSize)
	{
		CString CSlpszItemName (CQMPlugin::m_DescriptionList[i].m_lpszItemName);

		if(CSlpszItemName.Compare(bstrItemName)==0)
		{
			break;
		}
		i++;
	}
	CString str(CQMPlugin::m_DescriptionList[i].m_lpszDescription);
	return str.AllocSysString();
}


BSTR CQMPlugin::GetPluginInterpretTemplate(LPCTSTR bstrItemName)
{
	//OutputDebugString(L"CQMPlugin::GetPluginDescription");
	CString CSbItemName = bstrItemName;
	//OutputDebugString(L"bstrItemName:" + CSbItemName);
	int i = 0;
	while(i<CQMPlugin::m_iDescriptionListSize)
	{
		CString CSlpszItemName (CQMPlugin::m_DescriptionList[i].m_lpszItemName);

		if(CSlpszItemName.Compare(bstrItemName)==0)
		{
			break;
		}
		i++;
	}
	CString str(CQMPlugin::m_DescriptionList[i].m_lpszInterpretTemplate);
	return str.AllocSysString();
}
#include"Cdmsoft.h"
#include"test.h"
#include<fstream>


//这是第一个插件函数，返回一个字符串
BSTR CQMPlugin::Test1() 
{	
	CString strResult = L"Hello, world!";
	return strResult.AllocSysString();
}

UINT __stdcall testKeyboard(PVOID)
{
	::CoInitialize(NULL);//初始化线程COM库
	Cdmsoft dm;
	dm.CreateDispatch(L"dm.dmsoft");

	DWORD curTime = ::GetTickCount();
	while (::GetTickCount() - curTime <7 * 1000)
	{
		dm.KeyPressChar(L"left");
			Sleep(10);
	}

	::CoUninitialize();
	return 0;
}




#include"Room.h"
#include"InstanceZones.h"
//这是第二个插件函数，接受两个整数参数，返回两个整数的和
long CQMPlugin::Test2(long iNumber1, long iNumber2) 
{
	
	::CoInitialize(NULL);
	Cdmsoft dm;
	CLSID clsid;
	HRESULT hr = CLSIDFromProgID(OLESTR("dm.dmsoft"), &clsid);
	dm.CreateDispatch(clsid);
	dm.Reg(L"dieofai3e4c4149f6970cd69b4fc3af7ac85de4", L"0001");

	::InitializeCriticalSection(&gandalfr::CKeyOp::g_csKeyOp);
	g_insZone.loadNeural();
	if(iNumber1 == 1)
		_beginthreadex(NULL, 0, testKeyboard, NULL, 0, NULL);
	else if (iNumber1 == 10)
	{
		_beginthreadex(NULL, 0, gandalfr::CKeyOp::KeyboardInput, NULL, 0, NULL);
		test::OpenConsole();
	}

	
	DWORD curTime = ::GetTickCount();
	while (::GetTickCount() - curTime <10*1000)
	{
		if (iNumber1 == 10)
		{
			g_insZone.run(dm);
			test::printBestAreaAndPlayer();
			Sleep(100);
		}
		else if (iNumber1 == 1)
		{
			dm.KeyPressChar(L"left");
			dm.GetScreenData(0, 0, 800, 600);
			Sleep(50);
		}
	}

	::CoUninitialize();
	gandalfr::CKeyOp::m_RunTheKeyBoard = false;
	Sleep(1000);

	//std::wofstream txtDebug(L"C:\\code\\QMDebug.txt",std::ios::app);
	//test::findMonster(dm);
	//auto &mon = test::vecMonster;
	//for (auto iter = mon.begin(); iter != mon.end(); iter++)
	//{
	//	txtDebug << (*iter).x << " " << (*iter).y << std::endl;
	//}
	//txtDebug.close();

	return iNumber1 * iNumber2;
}

//这是第三个插件函数，接受两个字符串参数，返回这两个字符串连接的结果
BSTR CQMPlugin::Test3(LPCTSTR bstrString1, LPCTSTR bstrString2) 
{
	CString strResult = bstrString1;
	strResult += bstrString2;
	return strResult.AllocSysString();
}

//下面这个插件函数用于得到当前屏幕分辨率，主要为了给您演示传地址的参数用法
//注意这时参数类型应该用VARIANT*
//当您的插件函数需要返回多个值的时候，用这种方法会比较方便
void CQMPlugin::GetScreenResolution(VARIANT FAR* ResolutionX, VARIANT FAR* ResolutionY) 
{
	*ResolutionX = COleVariant((long)GetSystemMetrics(SM_CXSCREEN));
	*ResolutionY = COleVariant((long)GetSystemMetrics(SM_CYSCREEN));
}


/*********************************************************************
 * 下面是公共处理函数。
 * OnLoad 函数会在插件被加载时调用，返回值通常为TRUE。如果返回FALSE，表示插件拒绝被加载
 * OnLoad 函数的第一个参数表示加载动态链接库的Instance Handle，第二个参数暂时保留
 * OnExit 函数会在插件被卸载是调用，没有返回值
*********************************************************************/
BOOL OnLoad(HMODULE hModule, int iReserved)
{
	return TRUE;
}

void OnExit()
{
	return;
}