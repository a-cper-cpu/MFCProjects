// Page1Dlg.h : header file
//

#if !defined(AFX_PAGE1DLG_H__C7B42FBB_6732_4083_8FAE_0E1E4085C575__INCLUDED_)
#define AFX_PAGE1DLG_H__C7B42FBB_6732_4083_8FAE_0E1E4085C575__INCLUDED_

#include "liebiao.h"	// Added by ClassView
#include "bianji.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CPage1Dlg dialog

class CPage1Dlg : public CDialog
{
// Construction
public:
	CPage1Dlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CPage1Dlg)
	enum { IDD = IDD_PAGE1_DIALOG };
	CButton	m_denglu;
	CEdit	m_code;
	CButton	m_mima;
	CString	m_CODE;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPage1Dlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

struct Node
{
	char name[10];
	char CODE[12];
   
};
Node peo[500];
	// Generated message map functions
	//{{AFX_MSG(CPage1Dlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void Onxiugai();
	virtual void OnOK();
	virtual void OnCancel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PAGE1DLG_H__C7B42FBB_6732_4083_8FAE_0E1E4085C575__INCLUDED_)
