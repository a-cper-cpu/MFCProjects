#if !defined(AFX_DELUSERDLG_H__3C1EC78B_129A_4C22_AC42_58E9FF42DB80__INCLUDED_)
#define AFX_DELUSERDLG_H__3C1EC78B_129A_4C22_AC42_58E9FF42DB80__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DelUserDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDelUserDlg dialog

class CDelUserDlg : public CDialog
{
// Construction
public:
	CDelUserDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDelUserDlg)
	enum { IDD = IDD_DIALOG_BOOKOUT };
	CString	m_strCID;
	CString	m_strCName;
	COleDateTime	m_InDate;
	CString	m_strPay;
	COleDateTime	m_OutDate;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDelUserDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	void FillDelUserDlg();
	void SetStyle();
	void SetTitle();

	// Generated message map functions
	//{{AFX_MSG(CDelUserDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnButtonConfirm();
	afx_msg void OnButtonCancel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DELUSERDLG_H__3C1EC78B_129A_4C22_AC42_58E9FF42DB80__INCLUDED_)
