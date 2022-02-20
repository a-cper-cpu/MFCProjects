// MFCtest03.h : main header file for the MFCTEST03 application
//

#if !defined(AFX_MFCTEST03_H__CDD791DF_5627_42E4_8127_429AFED5F796__INCLUDED_)
#define AFX_MFCTEST03_H__CDD791DF_5627_42E4_8127_429AFED5F796__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CMFCtest03App:
// See MFCtest03.cpp for the implementation of this class
//

class CMFCtest03App : public CWinApp
{
public:
	CMFCtest03App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMFCtest03App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CMFCtest03App)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MFCTEST03_H__CDD791DF_5627_42E4_8127_429AFED5F796__INCLUDED_)
