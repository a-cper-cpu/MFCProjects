#if !defined(AFX_GOODSDLG_H__B7B3E141_CF61_43FA_9F4A_C46FF717C8AA__INCLUDED_)
#define AFX_GOODSDLG_H__B7B3E141_CF61_43FA_9F4A_C46FF717C8AA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// GoodsDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CGoodsDlg dialog

class CGoodsDlg : public CDialog
{
// Construction
public:
	CGoodsDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CGoodsDlg)
	enum { IDD = IDD_DIALOG_GOODS };
	CListCtrl	m_listDisp;
	CString	m_strCode;
	CString	m_strMaxNum;
	CString	m_strMinNum;
	CString	m_strName;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGoodsDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CGoodsDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnButtonAdd();
	afx_msg void OnButtonModify();
	afx_msg void OnButtonDelete();
	afx_msg void OnButtonExit();
	afx_msg void OnClickListDisp(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	void ClearTxt();
	void RefreshData();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GOODSDLG_H__B7B3E141_CF61_43FA_9F4A_C46FF717C8AA__INCLUDED_)
