// Lab_linkDlg.h : header file
//

#if !defined(AFX_LAB_LINKDLG_H__E7B53411_6017_455A_B184_5DFF4F101598__INCLUDED_)
#define AFX_LAB_LINKDLG_H__E7B53411_6017_455A_B184_5DFF4F101598__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CLab_linkDlg dialog


class CLab_linkDlg : public CDialog
{
// Construction
public:
	void Display();
	void Setlist();
	CLab_linkDlg(CWnd* pParent = NULL);	// standard constructor
	CPtrList m_Link;

// Dialog Data
	//{{AFX_DATA(CLab_linkDlg)
	enum { IDD = IDD_LAB_LINK_DIALOG };
	CButton	m_Modify;
	CButton	m_Searched;
	CListCtrl	m_List;
	CButton	m_Deleted;
	CButton	m_Added;
	CString	m_Name;
	CString	m_College;
	CString	m_Grade;
	CString	m_Fields;
	CString	m_Address;
	CString	m_Phone;
	CString	m_Post;
	CString	m_CellPhone;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLab_linkDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CLab_linkDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnAdded();
	afx_msg void OnDeleted();
	afx_msg void OnSearched();
	afx_msg void OnModify();
	afx_msg void OnClickList1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnChangeName();
	afx_msg void OnChangeNumber();
	afx_msg void OnChangeTelephone();
	afx_msg void OnChangeCollege();
	afx_msg void OnChangeGrade();
	afx_msg void OnChangeFields();
	afx_msg void OnChangeAddress();
	afx_msg void OnChangePhone();
	afx_msg void OnChangePost();
	afx_msg void OnChangeCellphone();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LAB_LINKDLG_H__E7B53411_6017_455A_B184_5DFF4F101598__INCLUDED_)
