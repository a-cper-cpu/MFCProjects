#if !defined(AFX_ADD_H__394DFD67_5BF1_48F5_B663_13C45CAECA70__INCLUDED_)
#define AFX_ADD_H__394DFD67_5BF1_48F5_B663_13C45CAECA70__INCLUDED_

#include "bianji.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// add.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// Cadd dialog

class Cadd : public CDialog
{
// Construction
public:
	Cadd(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(Cadd)
	enum { IDD = IDD_DIALOG5 };
	CString	m_edit;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(Cadd)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
    struct Node
	{
		char b[10];
	};
    Node peo[500];
	// Generated message map functions
	//{{AFX_MSG(Cadd)
	virtual void OnOK();
	virtual void OnCancel();
	afx_msg void OnPaint();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	Cbianji write;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ADD_H__394DFD67_5BF1_48F5_B663_13C45CAECA70__INCLUDED_)
