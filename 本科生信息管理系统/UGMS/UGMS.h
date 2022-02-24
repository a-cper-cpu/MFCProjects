// UGMS.h : main header file for the UGMS application
//

#if !defined(AFX_UGMS_H__23C914BC_639F_4762_BB21_7B6BDAA1634F__INCLUDED_)
#define AFX_UGMS_H__23C914BC_639F_4762_BB21_7B6BDAA1634F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CUGMSApp:
// See UGMS.cpp for the implementation of this class
//

class CUGMSApp : public CWinApp
{
public:
	CUGMSApp();
	_ConnectionPtr m_pConnection;


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CUGMSApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CUGMSApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_UGMS_H__23C914BC_639F_4762_BB21_7B6BDAA1634F__INCLUDED_)
