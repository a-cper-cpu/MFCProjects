// RMS.h : main header file for the RMS application
//

#if !defined(AFX_RMS_H__9A28404E_CC53_4BDD_A912_38AA59E374EC__INCLUDED_)
#define AFX_RMS_H__9A28404E_CC53_4BDD_A912_38AA59E374EC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CRMSApp:
// See RMS.cpp for the implementation of this class
//

class CRMSApp : public CWinApp
{
public:
	CRMSApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRMSApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CRMSApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_RMS_H__9A28404E_CC53_4BDD_A912_38AA59E374EC__INCLUDED_)
