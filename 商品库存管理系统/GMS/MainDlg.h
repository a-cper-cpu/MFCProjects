#if !defined(AFX_MAINDLG_H__C0214FB2_6186_4BEF_A906_3E9BDAA2FED2__INCLUDED_)
#define AFX_MAINDLG_H__C0214FB2_6186_4BEF_A906_3E9BDAA2FED2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// MainDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CMainDlg dialog

class CMainDlg : public CDialog
{
// Construction
public:
	CMainDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CMainDlg)
	enum { IDD = IDD_DIALOG_MAIN };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMainDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CMainDlg)
	afx_msg void OnButtonGoodsadd();
	afx_msg void OnButtonProvideradd();
	afx_msg void OnButtonGoodsin();
	afx_msg void OnButtonGoodsout();
	afx_msg void OnButtonGoods();
	afx_msg void OnButtonProvider();
	afx_msg void OnButtonIn();
	afx_msg void OnButtonOut();
	afx_msg void OnButtonAlert();
	afx_msg void OnButtonAdmin();
	afx_msg void OnButtonLog();
	afx_msg void OnButtonHelp();
	afx_msg void OnButtonAbout();
	afx_msg void OnButtonExit();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MAINDLG_H__C0214FB2_6186_4BEF_A906_3E9BDAA2FED2__INCLUDED_)
