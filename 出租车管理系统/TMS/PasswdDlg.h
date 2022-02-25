#if !defined(AFX_PASSWDDLG_H__BB29C1BF_1175_4E09_84CB_9A3219731ADA__INCLUDED_)
#define AFX_PASSWDDLG_H__BB29C1BF_1175_4E09_84CB_9A3219731ADA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PasswdDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CPasswdDlg dialog

class CPasswdDlg : public CDialog
{
// Construction
public:
	CPasswdDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CPasswdDlg)
	enum { IDD = IDD_DIALOG_PASSWD };
	CString	m_strPassWd1;
	CString	m_strPassWd2;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPasswdDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CPasswdDlg)
	afx_msg void OnButtonOk();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PASSWDDLG_H__BB29C1BF_1175_4E09_84CB_9A3219731ADA__INCLUDED_)
