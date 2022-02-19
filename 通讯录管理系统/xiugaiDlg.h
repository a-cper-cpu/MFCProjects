#if !defined(AFX_XIUGAIDLG_H__C9A2765A_2F2A_469E_8B75_48DD87894FFC__INCLUDED_)
#define AFX_XIUGAIDLG_H__C9A2765A_2F2A_469E_8B75_48DD87894FFC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// xiugaiDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CxiugaiDlg dialog

class CxiugaiDlg : public CDialog
{
// Construction
public:
	CxiugaiDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CxiugaiDlg)
	enum { IDD = IDD_DIALOG1 };
	CEdit	m_code3;
	CEdit	m_code2;
	CEdit	m_code1;
	CString	m_CODE1;
	CString	m_CODE2;
	CString	m_CODE3;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CxiugaiDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	struct Node
	{ 

char CODE[10];



};
Node peo[500];
	// Generated message map functions
	//{{AFX_MSG(CxiugaiDlg)
	virtual void OnOK();
	afx_msg void OnPaint();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_XIUGAIDLG_H__C9A2765A_2F2A_469E_8B75_48DD87894FFC__INCLUDED_)
