#if !defined(AFX_TXTDLG_H__8A7C2B48_C92C_42E9_B159_F50789311E74__INCLUDED_)
#define AFX_TXTDLG_H__8A7C2B48_C92C_42E9_B159_F50789311E74__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// txtDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CtxtDlg dialog

class CtxtDlg : public CDialog
{
// Construction
public:
	CtxtDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CtxtDlg)
	enum { IDD = IDD_DIALOG9 };
	CComboBox	m_select;
	CString	m_name;
	CString	m_name1;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CtxtDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
struct Node
{
	char name[10];

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
	//{{AFX_MSG(CtxtDlg)
	virtual void OnOK();

	afx_msg void OnPaint();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TXTDLG_H__8A7C2B48_C92C_42E9_B159_F50789311E74__INCLUDED_)
