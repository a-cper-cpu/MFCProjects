// HMS.h : main header file for the HMS application
//

#if !defined(AFX_HMS_H__B86915F2_8467_4B9C_9FED_22897198915E__INCLUDED_)
#define AFX_HMS_H__B86915F2_8467_4B9C_9FED_22897198915E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CHMSApp:
// See HMS.cpp for the implementation of this class
//

class CHMSApp : public CWinApp
{
public:
	CHMSApp();
public:
	_RecordsetPtr m_pRs;
	bool ADOExecute(_RecordsetPtr &ADOSet, _variant_t &strSQL);

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CHMSApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CHMSApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	// Define ADO Database Connnection
	_ConnectionPtr m_pConn;

};
extern CHMSApp theApp;
extern CLeftTreeView* m_pLeftView;			//Ê÷ÊÓÍ¼

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_HMS_H__B86915F2_8467_4B9C_9FED_22897198915E__INCLUDED_)
