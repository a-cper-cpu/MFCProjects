// GPACalculator.h : main header file for the GPACALCULATOR application
//

#if !defined(AFX_GPACALCULATOR_H__186C01DC_0827_49AD_9016_E15228E92BDB__INCLUDED_)
#define AFX_GPACALCULATOR_H__186C01DC_0827_49AD_9016_E15228E92BDB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CGPACalculatorApp:
// See GPACalculator.cpp for the implementation of this class
//

class CGPACalculatorApp : public CWinApp
{
public:
	CGPACalculatorApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGPACalculatorApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CGPACalculatorApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GPACALCULATOR_H__186C01DC_0827_49AD_9016_E15228E92BDB__INCLUDED_)
