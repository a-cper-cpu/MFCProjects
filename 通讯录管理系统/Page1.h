// Page1.h : main header file for the PAGE1 application
//

#if !defined(AFX_PAGE1_H__CB38F16F_6265_405F_9C14_C822A28F8DAB__INCLUDED_)
#define AFX_PAGE1_H__CB38F16F_6265_405F_9C14_C822A28F8DAB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CPage1App:
// See Page1.cpp for the implementation of this class
//

class CPage1App : public CWinApp
{
public:
	CPage1App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPage1App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CPage1App)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PAGE1_H__CB38F16F_6265_405F_9C14_C822A28F8DAB__INCLUDED_)
