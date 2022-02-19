#if !defined(AFX_BIANJI_H__8B2828EE_6410_4254_98FF_A59A37F1A4A7__INCLUDED_)
#define AFX_BIANJI_H__8B2828EE_6410_4254_98FF_A59A37F1A4A7__INCLUDED_
#include"liebiao.h"
#include "liebiao.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// bianji.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// Cbianji dialog

class Cbianji : public CDialog
{
// Construction
public:
struct Node
{
	char name[10];
	char month[5];
    char day[5];
    char tel[20];
	char qq[20];
	char address[100];
	char  relationship[100];
    char b[10];
	char sex[5];
	char beizhu[50];
};
Node peo[500];
Cbianji(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(Cbianji)
	enum { IDD = IDD_DIALOG2 };
	CEdit	m_beizhu1;
	CComboBox	m_sex;
	CButton	m_odd;
	CButton	m_add1;
	CButton	m_alter1;
	CListBox	m_relation;
	CEdit	m_address1;
	CEdit	m_day1;
	CEdit	m_month1;
	CEdit	m_qq1;
	CEdit	m_tel1;
	CEdit	m_name1;
	CString	m_name;
	CString	m_tel;
	CString	m_address;
	CString	m_qq;
	CString	m_month;
	CString	m_day;
	CString	m_relation1;
	CString	m_beizhu;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(Cbianji)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(Cbianji)
	afx_msg void Onrelation();
	afx_msg void Onadd();
	afx_msg void Ondisplay();
	afx_msg void Onalter1();
	virtual BOOL OnInitDialog();
	afx_msg void OnCancelMode();

	afx_msg void OnPaint();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BIANJI_H__8B2828EE_6410_4254_98FF_A59A37F1A4A7__INCLUDED_)
