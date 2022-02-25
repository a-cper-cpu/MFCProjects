// TMS.h : main header file for the TMS application
//

#if !defined(AFX_TMS_H__B5AB8EDE_1C07_43C8_8E18_150FDE9A132E__INCLUDED_)
#define AFX_TMS_H__B5AB8EDE_1C07_43C8_8E18_150FDE9A132E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CTMSApp:
// See TMS.cpp for the implementation of this class
//

class CTMSApp : public CWinApp
{
public:
	CTMSApp();
public:
	_RecordsetPtr m_pRs;
	bool ADOExecute(_RecordsetPtr &ADOSet, _variant_t &strSQL);

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTMSApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CTMSApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	// Define ADO Database Connnection
	_ConnectionPtr m_pConn;
};
extern CTMSApp theApp;


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TMS_H__B5AB8EDE_1C07_43C8_8E18_150FDE9A132E__INCLUDED_)
