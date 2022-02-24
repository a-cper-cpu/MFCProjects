#if !defined(AFX_PROVIDERDLG_H__3B1EE145_B441_4019_983B_1FBE1E59B494__INCLUDED_)
#define AFX_PROVIDERDLG_H__3B1EE145_B441_4019_983B_1FBE1E59B494__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ProviderDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CProviderDlg dialog

class CProviderDlg : public CDialog
{
// Construction
public:
	CProviderDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CProviderDlg)
	enum { IDD = IDD_DIALOG_PROVIDER };
	CListCtrl	m_listDisp;
	CString	m_strAddress;
	CString	m_strCode;
	CString	m_strName;
	CString	m_strEmail;
	CString	m_strPerson;
	CString	m_strPhone;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CProviderDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CProviderDlg)
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

#endif // !defined(AFX_PROVIDERDLG_H__3B1EE145_B441_4019_983B_1FBE1E59B494__INCLUDED_)
