#if !defined(AFX_DESKPAGE_H__2782A9AD_785E_4D0F_9613_9007F55E65FB__INCLUDED_)
#define AFX_DESKPAGE_H__2782A9AD_785E_4D0F_9613_9007F55E65FB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DeskPage.h : header file
//
#include "DeskSet.h"
/////////////////////////////////////////////////////////////////////////////
// CDeskPage dialog

class CDeskPage : public CPropertyPage
{
	DECLARE_DYNCREATE(CDeskPage)

// Construction
public:
	CDeskSet m_rsDataSet;
	CDeskPage();
	~CDeskPage();

// Dialog Data
	//{{AFX_DATA(CDeskPage)
	enum { IDD = IDD_DIALOG_DESK };
	CComboBox	m_cbFree;
	CListCtrl	m_listDisp;
	CString	m_strNum;
	CString	m_strDesc;
	CString	m_strCode;
	//}}AFX_DATA


// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CDeskPage)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(CDeskPage)
	afx_msg void OnButtonAdd();
	virtual BOOL OnInitDialog();
	afx_msg void OnButtonModify();
	afx_msg void OnButtonDel();
	afx_msg void OnClickListDisp(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnButtonClear();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

private:
	void RefreshData();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DESKPAGE_H__2782A9AD_785E_4D0F_9613_9007F55E65FB__INCLUDED_)
