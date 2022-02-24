// GMS.h : main header file for the GMS application
//

#if !defined(AFX_GMS_H__B22826A3_7380_41E9_8C26_F53B4743ADF1__INCLUDED_)
#define AFX_GMS_H__B22826A3_7380_41E9_8C26_F53B4743ADF1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols
#include "LogManager.h"

/////////////////////////////////////////////////////////////////////////////
// CGMSApp:
// See GMS.cpp for the implementation of this class
//

class CGMSApp : public CWinApp
{
public:
	CGMSApp();
public:
	_RecordsetPtr m_pRs;
	bool ADOExecute(_RecordsetPtr &ADOSet, _variant_t &strSQL);
	CLogManager m_log;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGMSApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CGMSApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	// Define ADO Database Connnection
	_ConnectionPtr m_pConn;

};
extern CGMSApp theApp;

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GMS_H__B22826A3_7380_41E9_8C26_F53B4743ADF1__INCLUDED_)
