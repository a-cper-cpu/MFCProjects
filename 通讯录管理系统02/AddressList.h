// AddressList.h : main header file for the AddressList application
//

/*
	作者：张超刚

*/

#if !defined(AFX_AddressList_H__1E77FD68_B1CC_4091_8E52_464B7323850B__INCLUDED_)
#define AFX_AddressList_H__1E77FD68_B1CC_4091_8E52_464B7323850B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CAddressListApp:
// See AddressList.cpp for the implementation of this class
//

class CAddressListApp : public CWinApp
{
public:
	CAddressListApp();

// Attributes
public:
	BOOL ConnectionDb();
	//
	//声明一个指向要创建的ADO对象的智能指针
	_ConnectionPtr m_pConnection;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAddressListApp)
	public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CAddressListApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_AddressList_H__1E77FD68_B1CC_4091_8E52_464B7323850B__INCLUDED_)
