// Lab_link.h : main header file for the LAB_LINK application
//

#if !defined(AFX_LAB_LINK_H__D7B934D2_58E9_4DC0_8D15_53EB3A349919__INCLUDED_)
#define AFX_LAB_LINK_H__D7B934D2_58E9_4DC0_8D15_53EB3A349919__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CLab_linkApp:
// See Lab_link.cpp for the implementation of this class
//

class CLab_linkApp : public CWinApp
{
public:
	CLab_linkApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLab_linkApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CLab_linkApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LAB_LINK_H__D7B934D2_58E9_4DC0_8D15_53EB3A349919__INCLUDED_)
