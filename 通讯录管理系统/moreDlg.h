#if !defined(AFX_MOREDLG_H__0C0ADE03_1386_4C9B_B2C7_74FDE652768B__INCLUDED_)
#define AFX_MOREDLG_H__0C0ADE03_1386_4C9B_B2C7_74FDE652768B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// moreDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CmoreDlg dialog

class CmoreDlg : public CDialog
{
// Construction
public:
	CmoreDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CmoreDlg)
	enum { IDD = IDD_DIALOG8 };
	int		m_vol;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CmoreDlg)
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
	char relationship[100];
   	char sex[5];
	char beizhu[50];
   
};
Node peo[500];
	// Generated message map functions
	//{{AFX_MSG(CmoreDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnCancelMode();
	virtual void OnOK();
	virtual void OnCancel();
	afx_msg void Oncreatetxt();
	afx_msg void OnPaint();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MOREDLG_H__0C0ADE03_1386_4C9B_B2C7_74FDE652768B__INCLUDED_)
