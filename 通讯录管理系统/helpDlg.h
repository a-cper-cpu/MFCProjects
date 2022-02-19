#if !defined(AFX_HELPDLG_H__7F43E659_5C86_4A5C_8DC6_2E709F708D0A__INCLUDED_)
#define AFX_HELPDLG_H__7F43E659_5C86_4A5C_8DC6_2E709F708D0A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// helpDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// ChelpDlg dialog

class ChelpDlg : public CDialog
{
// Construction
public:
	ChelpDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(ChelpDlg)
	enum { IDD = IDD_DIALOG10 };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(ChelpDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(ChelpDlg)
	virtual void OnOK();
	afx_msg void OnPaint();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_HELPDLG_H__7F43E659_5C86_4A5C_8DC6_2E709F708D0A__INCLUDED_)
