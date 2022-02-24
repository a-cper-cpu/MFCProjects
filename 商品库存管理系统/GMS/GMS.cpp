// GMS.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "GMS.h"
#include "GMSDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CGMSApp

BEGIN_MESSAGE_MAP(CGMSApp, CWinApp)
	//{{AFX_MSG_MAP(CGMSApp)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CGMSApp construction

CGMSApp::CGMSApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CGMSApp object

CGMSApp theApp;
CString strAdminName;

/////////////////////////////////////////////////////////////////////////////
// CGMSApp initialization

BOOL CGMSApp::InitInstance()
{
	AfxEnableControlContainer();

	// Standard initialization
	// If you are not using these features and wish to reduce the size
	//  of your final executable, you should remove from the following
	//  the specific initialization routines you do not need.

#ifdef _AFXDLL
	Enable3dControls();			// Call this when using MFC in a shared DLL
#else
	Enable3dControlsStatic();	// Call this when linking to MFC statically
#endif
	// Create ADO Connection
	if( FAILED(::CoInitialize(NULL)) ) 
	{
	    AfxMessageBox("ADO Init failed");
		return false;
	}
	try
	{
		m_pConn.CreateInstance(__uuidof(Connection));
		m_pConn->Open("Provider=Microsoft.Jet.OLEDB.4.0;Data Source=GMS.mdb","","",adConnectUnspecified);
	}
	// Catch Exceptions
	catch(_com_error &e)
	{
		CString err;
		err.Format("%s", (char*)(e.Description()) );
		AfxMessageBox(err);
	}
	catch(...)
	{
		AfxMessageBox("Unknown Error...");
	}
	// Init ADO RecordSet
	m_pRs.CreateInstance(__uuidof(Recordset));
	CGMSDlg dlg;
	m_pMainWnd = &dlg;
	int nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO: Place code here to handle when the dialog is
		//  dismissed with OK
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: Place code here to handle when the dialog is
		//  dismissed with Cancel
	}

	// Since the dialog has been closed, return FALSE so that we exit the
	//  application, rather than start the application's message pump.
	return FALSE;
}
bool CGMSApp::ADOExecute(_RecordsetPtr &ADOSet, _variant_t &strSQL)
{
	if ( ADOSet->State == adStateOpen)	
		ADOSet->Close();
	try
	{
       	ADOSet->Open(strSQL, m_pConn.GetInterfacePtr(), adOpenStatic, adLockOptimistic, adCmdUnknown);
	    return true;
	}
	catch(_com_error &e)
	{
       CString err;
	   err.Format("ADO Error: %s",(char*)e.Description());
	   AfxMessageBox(err);
	   return false;
	}
}
