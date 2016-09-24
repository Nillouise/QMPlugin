// QMPlugin.cpp : ���� DLL �ĳ�ʼ�����̡�
//

#include "stdafx.h"
#include "QMPlugin.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//
//TODO: ����� DLL ����� MFC DLL �Ƕ�̬���ӵģ�
//		��Ӵ� DLL �������κε���
//		MFC �ĺ������뽫 AFX_MANAGE_STATE ����ӵ�
//		�ú�������ǰ�档
//
//		����:
//
//		extern "C" BOOL PASCAL EXPORT ExportedFunction()
//		{
//			AFX_MANAGE_STATE(AfxGetStaticModuleState());
//			// �˴�Ϊ��ͨ������
//		}
//
//		�˺������κ� MFC ����
//		������ÿ��������ʮ����Ҫ������ζ��
//		��������Ϊ�����еĵ�һ�����
//		���֣������������ж������������
//		������Ϊ���ǵĹ��캯���������� MFC
//		DLL ���á�
//
//		�й�������ϸ��Ϣ��
//		����� MFC ����˵�� 33 �� 58��
//

// CQMPluginApp

BEGIN_MESSAGE_MAP(CQMPluginApp, CWinApp)
END_MESSAGE_MAP()


// CQMPluginApp ����

CQMPluginApp::CQMPluginApp()
{
	// TODO: �ڴ˴���ӹ�����룬
	// ��������Ҫ�ĳ�ʼ�������� InitInstance ��
}


// Ψһ��һ�� CQMPluginApp ����

CQMPluginApp theApp;

const GUID CDECL _tlid = { 0xC86D6F66, 0x5A41, 0x42A2, { 0xBC, 0x25, 0xDA, 0x9, 0x82, 0x29, 0x25, 0xD0 } };
const WORD _wVerMajor = 1;
const WORD _wVerMinor = 0;


// CQMPluginApp ��ʼ��

BOOL CQMPluginApp::InitInstance()
{
	CWinApp::InitInstance();

	// ������ OLE ������(����)ע��Ϊ���С��⽫ʹ
	//  OLE ����Դ�����Ӧ�ó��򴴽�����
	COleObjectFactory::RegisterAll();

	return TRUE;
}

// DllGetClassObject - �����๤��

STDAPI DllGetClassObject(REFCLSID rclsid, REFIID riid, LPVOID* ppv)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	return AfxDllGetClassObject(rclsid, riid, ppv);
}


// DllCanUnloadNow - ���� COM ж�� DLL

STDAPI DllCanUnloadNow(void)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	return AfxDllCanUnloadNow();
}


// DllRegisterServer - ������ӵ�ϵͳע���

STDAPI DllRegisterServer(void)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	if (!AfxOleRegisterTypeLib(AfxGetInstanceHandle(), _tlid))
		return SELFREG_E_TYPELIB;

	if (!COleObjectFactory::UpdateRegistryAll())
		return SELFREG_E_CLASS;

	return S_OK;
}


// DllUnregisterServer - �����ϵͳע������Ƴ�

STDAPI DllUnregisterServer(void)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	if (!AfxOleUnregisterTypeLib(_tlid, _wVerMajor, _wVerMinor))
		return SELFREG_E_TYPELIB;

	if (!COleObjectFactory::UpdateRegistryAll(FALSE))
		return SELFREG_E_CLASS;

	return S_OK;
}
// QMPlugin.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "QMPlugin.h"
#include "QMPlugin.h"


// CQMPlugin

IMPLEMENT_DYNCREATE(CQMPlugin, CCmdTarget)


CQMPlugin::CQMPlugin()
{
	EnableAutomation();
	
	// Ϊ��ʹӦ�ó����� OLE �Զ��������ڻ״̬ʱ����
	//	���У����캯������ AfxOleLockApp��
	
	AfxOleLockApp();
}

CQMPlugin::~CQMPlugin()
{
	// Ϊ������ OLE �Զ����������ж������ֹӦ�ó���
	// 	������������ AfxOleUnlockApp��
	
	AfxOleUnlockApp();
}


void CQMPlugin::OnFinalRelease()
{
	// �ͷ��˶��Զ�����������һ�����ú󣬽�����
	// OnFinalRelease�����ཫ�Զ�
	// ɾ���ö����ڵ��øû���֮ǰ�����������
	// ��������ĸ���������롣

	CCmdTarget::OnFinalRelease();
}


BEGIN_MESSAGE_MAP(CQMPlugin, CCmdTarget)
END_MESSAGE_MAP()


BEGIN_DISPATCH_MAP(CQMPlugin, CCmdTarget)

	DISP_FUNCTION(CQMPlugin, "Get_Plugin_Description", GetPluginDescription, VT_BSTR, VTS_BSTR)
	DISP_FUNCTION(CQMPlugin, "Get_Plugin_Interpret_Template", GetPluginInterpretTemplate, VT_BSTR, VTS_BSTR)
	//�������в�Ҫ����


//	#error �������ע��
	//����ʱע�͵�����һ��
	//����������Ҫ����ע�ᣬӦ����VS�Զ�ע��ģ��������˲��У��������ֶ�ע��һ�°�
	//CQMPlugin������䣬������Ҫ�����ţ��������������ţ�������ͣ���������Ҫ�Ͳ���ƥ��
	//�����׵���ЩCOM�����¿�����

	//ע����� ��QMPlugin.idl �ļ���
	DISP_FUNCTION(CQMPlugin, "Test1", Test1, VT_BSTR, VTS_NONE)
	DISP_FUNCTION(CQMPlugin, "Test2", Test2, VT_I4, VTS_I4 VTS_I4)
	DISP_FUNCTION(CQMPlugin, "Test3", Test3, VT_BSTR, VTS_BSTR VTS_BSTR)
	DISP_FUNCTION(CQMPlugin, "GetScreenResolution", GetScreenResolution, VT_EMPTY, VTS_PVARIANT VTS_PVARIANT)
END_DISPATCH_MAP()

// ע��: ������� IID_IQMPlugin ֧��
//  ��֧������ VBA �����Ͱ�ȫ�󶨡��� IID ����ͬ���ӵ� .IDL �ļ��е�
//  ���Ƚӿڵ� GUID ƥ�䡣

// {EB62CBA9-5F62-44DF-9154-D33BF5DF213B}
static const IID IID_IQMPlugin =
{ 0xEB62CBA9, 0x5F62, 0x44DF, { 0x91, 0x54, 0xD3, 0x3B, 0xF5, 0xDF, 0x21, 0x3B } };

BEGIN_INTERFACE_MAP(CQMPlugin, CCmdTarget)
	INTERFACE_PART(CQMPlugin, IID_IQMPlugin, Dispatch)
END_INTERFACE_MAP()

// {B0103678-8D56-4946-9C47-59B02AA4D91C}
//IMPLEMENT_OLECREATE_FLAGS(CQMPlugin, "QMPlugin.QMPlugin", afxRegApartmentThreading, 0xb0103678, 0x8d56, 0x4946, 0x9c, 0x47, 0x59, 0xb0, 0x2a, 0xa4, 0xd9, 0x1c)


//#error ���� GUID
//����ʱע�͵�����һ��

//����Ĳ������ �滻 "�������" ֻ����Ӣ�ġ�
//���� GUID ,�滻�����GUID  0x00000000, 0x0000, 0x0000, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
//Ϊ��ֹ��©������ע�ͣ���ȥ�� ע�� 

IMPLEMENT_OLECREATE_FLAGS(CQMPlugin, "QMPlugin.demo", afxRegApartmentThreading, 0xe5f7a167, 0x8d58, 0x4e40, 0xb8, 0x1e, 0xf3, 0xb7, 0x12, 0xe1, 0x5f, 0x4e)

/*********************************************************************
 * ����:m_DescriptionList
 * ����԰�������һ����񣬱���е�ÿһ�д�����һ��������
 * ÿ�е�һ���ַ����ǲ����������֣����Ϊ�գ������������������ڶ����ַ����������������Ľ��ͣ�
 * �������ַ����ǲ���������ʾģ����Ϣ�����е�$1 $2 ... ����������ʾʱ���õ�һ���������ڶ���������... ����
 * ������Ҫ����һ����������ʱ�򣬾���Ҫ�ڱ�������һ�С�
*********************************************************************/
CQMPlugin::DESCRIPTION_LIST CQMPlugin::m_DescriptionList[] = 
{
	{"","������д���Ĳ����˵����Ϣ",""},
	{"Test1","���ǵ�һ�����������˵��","�õ�һ���ַ���"},
	{"Test2","���ǵڶ������������˵��","���� $1 �� $2 �ĺ�"},
	{"Test3","���ǵ��������������˵��","�ַ��� $1 �� $2 ������"},
};


//����������Ҫ������Ҳ����Ҫ�޸�
const int CQMPlugin::m_iDescriptionListSize = sizeof(CQMPlugin::m_DescriptionList) / sizeof(CQMPlugin::DESCRIPTION_LIST);

// CQMPlugin ��Ϣ�������


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


//���ǵ�һ���������������һ���ַ���
BSTR CQMPlugin::Test1() 
{	
	CString strResult = L"Hello, world!";
	return strResult.AllocSysString();
}

UINT __stdcall testKeyboard(PVOID)
{
	::CoInitialize(NULL);//��ʼ���߳�COM��
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
//���ǵڶ�������������������������������������������ĺ�
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

//���ǵ�����������������������ַ��������������������ַ������ӵĽ��
BSTR CQMPlugin::Test3(LPCTSTR bstrString1, LPCTSTR bstrString2) 
{
	CString strResult = bstrString1;
	strResult += bstrString2;
	return strResult.AllocSysString();
}

//�����������������ڵõ���ǰ��Ļ�ֱ��ʣ���ҪΪ�˸�����ʾ����ַ�Ĳ����÷�
//ע����ʱ��������Ӧ����VARIANT*
//�����Ĳ��������Ҫ���ض��ֵ��ʱ�������ַ�����ȽϷ���
void CQMPlugin::GetScreenResolution(VARIANT FAR* ResolutionX, VARIANT FAR* ResolutionY) 
{
	*ResolutionX = COleVariant((long)GetSystemMetrics(SM_CXSCREEN));
	*ResolutionY = COleVariant((long)GetSystemMetrics(SM_CYSCREEN));
}


/*********************************************************************
 * �����ǹ�����������
 * OnLoad �������ڲ��������ʱ���ã�����ֵͨ��ΪTRUE���������FALSE����ʾ����ܾ�������
 * OnLoad �����ĵ�һ��������ʾ���ض�̬���ӿ��Instance Handle���ڶ���������ʱ����
 * OnExit �������ڲ����ж���ǵ��ã�û�з���ֵ
*********************************************************************/
BOOL OnLoad(HMODULE hModule, int iReserved)
{
	return TRUE;
}

void OnExit()
{
	return;
}