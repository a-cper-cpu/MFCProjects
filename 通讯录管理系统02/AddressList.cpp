// AddressList.cpp : Defines the class behaviors for the application.
//

/*
	���ߣ��ų���

*/


#include "stdafx.h"
#include "AddressList.h"

#include "MainFrm.h"
#include "AddressListDoc.h"
#include "AddressListView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAddressListApp

BEGIN_MESSAGE_MAP(CAddressListApp, CWinApp)
	//{{AFX_MSG_MAP(CAddressListApp)
	ON_COMMAND(ID_APP_ABOUT, OnAppAbout)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard file based document commands
	ON_COMMAND(ID_FILE_NEW, CWinApp::OnFileNew)
	ON_COMMAND(ID_FILE_OPEN, CWinApp::OnFileOpen)
	// Standard print setup command
	ON_COMMAND(ID_FILE_PRINT_SETUP, CWinApp::OnFilePrintSetup)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAddressListApp construction

CAddressListApp::CAddressListApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CAddressListApp object

CAddressListApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CAddressListApp initialization

BOOL CAddressListApp::InitInstance()
{
	AfxEnableControlContainer();
	//��ʼ��OLE DLLs
	if (!AfxOleInit())
	{
		AfxMessageBox("��ʼ��OLE DLLʧ��:(");
		return FALSE;
	}


	// Standard initialization
	// If you are not using these features and wish to reduce the size
	//  of your final executable, you should remove from the following
	//  the specific initialization routines you do not need.

#ifdef _AFXDLL
	Enable3dControls();			// Call this when using MFC in a shared DLL
#else
	Enable3dControlsStatic();	// Call this when linking to MFC statically
#endif

	// Change the registry key under which our settings are stored.
	// TODO: You should modify this string to be something appropriate
	// such as the name of your company or organization.
	SetRegistryKey(_T("Local AppWizard-Generated Applications"));

	LoadStdProfileSettings();  // Load standard INI file options (including MRU)

	// Register the application's document templates.  Document templates
	//  serve as the connection between documents, frame windows and views.

	CSingleDocTemplate* pDocTemplate;
	pDocTemplate = new CSingleDocTemplate(
		IDR_MAINFRAME,
		RUNTIME_CLASS(CAddressListDoc),
		RUNTIME_CLASS(CMainFrame),       // main SDI frame window
		RUNTIME_CLASS(CAddressListView));
	AddDocTemplate(pDocTemplate);

	// Parse command line for standard shell commands, DDE, file open
	CCommandLineInfo cmdInfo;
	ParseCommandLine(cmdInfo);
	//ע���������ݿ�Ӧ�ڽ����ʱ�������m_pMainWnd->UpdateWindow();
	//֮��Ļ�����ʼ�����ؼ�ʱ�ͻ��������
	if(!ConnectionDb())
	{
		AfxMessageBox("�������ݿ�ʧ��:(");
		return FALSE;
	}
	// Dispatch commands specified on the command line
	if (!ProcessShellCommand(cmdInfo))
		return FALSE;

	// The one and only window has been initialized, so show and update it.
	m_pMainWnd->ShowWindow(SW_SHOWMAXIMIZED);
	m_pMainWnd->SetWindowText("����ͨѶ��Ϣ����ϵͳ");
	m_pMainWnd->UpdateWindow();

	return TRUE;
}


/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
		// No message handlers
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

// App command to run the dialog
void CAddressListApp::OnAppAbout()
{
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();
}

/////////////////////////////////////////////////////////////////////////////
// CAddressListApp message handlers


BOOL CAddressListApp::ConnectionDb()
{
	//����ADO����
	m_pConnection.CreateInstance(__uuidof(Connection));
	CString strSQL;
	strSQL="Provider=Microsoft.Jet.OLEDB.4.0;Data Source=info.mdb";
	//��ADO�����н��������Ҫ����try...catch()�����������Ϣ��
	//��Ϊ����ʱ�ᾭ������һЩ�벻���Ĵ���songMp3
	try                 
	{	
		//��mdb��perConnection.mdb
		m_pConnection->Open((_bstr_t)strSQL,"","",adModeUnknown);
	}
	catch (_com_error e)
	{
		CString strError;
		strError.Format("���棺�����ӷ����쳣�� ������Ϣ�� %s",e.ErrorMessage());
		AfxMessageBox(strError);
		return FALSE;
	}
	return TRUE;

}

int CAddressListApp::ExitInstance() 
{
	// TODO: Add your specialized code here and/or call the base class
	if(m_pConnection->State)
	{
		m_pConnection->Close();
		m_pConnection=NULL;
	}
	return CWinApp::ExitInstance();
}
