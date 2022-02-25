#if !defined(AFX_CARDRIVERDLG_H__5C8DBD15_21C6_45A9_B555_5A12EB55AC74__INCLUDED_)
#define AFX_CARDRIVERDLG_H__5C8DBD15_21C6_45A9_B555_5A12EB55AC74__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// CarDriverDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CCarDriverDlg dialog

class CCarDriverDlg : public CDialog
{
// Construction
public:
	CCarDriverDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CCarDriverDlg)
	enum { IDD = IDD_DIALOG_CARDRIVER };
	CComboBox	m_cbIsWork;
	CComboBox	m_cbDriverNO;
	CComboBox	m_cbCarNO;
	CString	m_strDriverName;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCarDriverDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CCarDriverDlg)
	afx_msg void OnSelchangeComboDriverno();
	virtual BOOL OnInitDialog();
	afx_msg void OnButtonOk();
	afx_msg void OnButtonCancel();
	afx_msg void OnSelchangeComboCarno();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	void DelCarDriver();
	void ModifyCarDriver();
	void AddCarDriver();
	void GetCBData();
	void FillData();
	void ClearData();
	void SetTitle();
	void SetStyle();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CARDRIVERDLG_H__5C8DBD15_21C6_45A9_B555_5A12EB55AC74__INCLUDED_)
