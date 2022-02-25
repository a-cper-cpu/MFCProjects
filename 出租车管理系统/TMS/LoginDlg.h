#if !defined(AFX_LOGINDLG_H__397556F0_C116_4EFB_867C_43670677A7B9__INCLUDED_)
#define AFX_LOGINDLG_H__397556F0_C116_4EFB_867C_43670677A7B9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// LoginDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CLoginDlg dialog

class CLoginDlg : public CDialog
{
// Construction
public:
	CLoginDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CLoginDlg)
	enum { IDD = IDD_DIALOG_LOGIN };
	CString	m_strName;
	CString	m_strPasswd;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLoginDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	CBrush m_Brush;

	// Generated message map functions
	//{{AFX_MSG(CLoginDlg)
	afx_msg void OnButtonOk();
	afx_msg void OnButtonCancel();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public:
	bool IsLogin;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LOGINDLG_H__397556F0_C116_4EFB_867C_43670677A7B9__INCLUDED_)
