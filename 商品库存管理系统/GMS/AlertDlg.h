#if !defined(AFX_ALERTDLG_H__DA390DDD_A5EB_41AA_AD06_D3CDBF6AC2B3__INCLUDED_)
#define AFX_ALERTDLG_H__DA390DDD_A5EB_41AA_AD06_D3CDBF6AC2B3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// AlertDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CAlertDlg dialog

class CAlertDlg : public CDialog
{
// Construction
public:
	CAlertDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CAlertDlg)
	enum { IDD = IDD_DIALOG_ALERT };
	CListCtrl	m_listLowDisp;
	CListCtrl	m_listHighDisp;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAlertDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CAlertDlg)
	afx_msg void OnButtonOk();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	void RefreshData();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ALERTDLG_H__DA390DDD_A5EB_41AA_AD06_D3CDBF6AC2B3__INCLUDED_)
