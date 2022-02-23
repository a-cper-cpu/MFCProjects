#if !defined(AFX_CUSTOMERDLG_H__B5EBED16_1088_4E26_86ED_30EBD3C2C360__INCLUDED_)
#define AFX_CUSTOMERDLG_H__B5EBED16_1088_4E26_86ED_30EBD3C2C360__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// CustomerDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CCustomerDlg dialog

class CCustomerDlg : public CDialog
{
// Construction
public:
	CCustomerDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CCustomerDlg)
	enum { IDD = IDD_DIALOG_USER };
	CString	m_strCID;
	CString	m_strCName;
	CString	m_strCOff;
	CString	m_strCTel;
	int m_iCSex;
	CString	m_strCAge;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCustomerDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	void ModifyCustomer();
	void AddCustomer();
	void FillCustomer();
	void ClearCustomer();
	void SetTitle();
	void SetStyle();

	// Generated message map functions
	//{{AFX_MSG(CCustomerDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnButtonConfirm();
	afx_msg void OnButtonCancel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CUSTOMERDLG_H__B5EBED16_1088_4E26_86ED_30EBD3C2C360__INCLUDED_)
