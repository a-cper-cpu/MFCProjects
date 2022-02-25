// Library.h : main header file for the LIBRARY application
//

#if !defined(AFX_LIBRARY_H__05355A7C_98DD_45B4_B16A_9BFEEC1DEC56__INCLUDED_)
#define AFX_LIBRARY_H__05355A7C_98DD_45B4_B16A_9BFEEC1DEC56__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CLibraryApp:
// See Library.cpp for the implementation of this class
//

class CLibraryApp : public CWinApp
{
public:
	CString m_strUserName;
	CLibraryApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLibraryApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CLibraryApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LIBRARY_H__05355A7C_98DD_45B4_B16A_9BFEEC1DEC56__INCLUDED_)
