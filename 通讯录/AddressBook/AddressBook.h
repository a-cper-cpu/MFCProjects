// AddressBook.h : main header file for the ADDRESSBOOK application
//

#if !defined(AFX_ADDRESSBOOK_H__93967EF5_135C_461C_9E16_5A0DC9F40AC0__INCLUDED_)
#define AFX_ADDRESSBOOK_H__93967EF5_135C_461C_9E16_5A0DC9F40AC0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CAddressBookApp:
// See AddressBook.cpp for the implementation of this class
//

class CAddressBookApp : public CWinApp
{
public:
	CAddressBookApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAddressBookApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CAddressBookApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ADDRESSBOOK_H__93967EF5_135C_461C_9E16_5A0DC9F40AC0__INCLUDED_)
