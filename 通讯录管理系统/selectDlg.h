#if !defined(AFX_SELECTDLG_H__864E0F23_4ACD_4454_B3E4_1F618B72497A__INCLUDED_)
#define AFX_SELECTDLG_H__864E0F23_4ACD_4454_B3E4_1F618B72497A__INCLUDED_

#include "liebiao.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// selectDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CselectDlg dialog

class CselectDlg : public CDialog
{
// Construction
public:
	CselectDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CselectDlg)
	enum { IDD = IDD_DIALOG6 };
	CListBox	m_relation;
	CEdit	m_address1;
	CEdit	m_name1;
	CString	m_name;
	CString	m_address;
	CString	m_relation1;
	CString	m_name2;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CselectDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
struct Node
{
	char name[10];
    char b[10];
	char month[5];
    char day[5];
    char tel[20];
	char qq[20];
	char address[100];
	char  relationship[100];
   	char sex[5];
	char beizhu[50];
   
};
Node peo[500];


	// Generated message map functions
	//{{AFX_MSG(CselectDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnCancelMode();
	virtual void OnOK();
	afx_msg void OnButton1();
	afx_msg void OnPaint();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SELECTDLG_H__864E0F23_4ACD_4454_B3E4_1F618B72497A__INCLUDED_)
