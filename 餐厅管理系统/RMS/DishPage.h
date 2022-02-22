#if !defined(AFX_DISHPAGE_H__63D3B62B_2797_4887_B6C7_DFDB9AF3D26C__INCLUDED_)
#define AFX_DISHPAGE_H__63D3B62B_2797_4887_B6C7_DFDB9AF3D26C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DishPage.h : header file
//
#include "DishSet.h"
/////////////////////////////////////////////////////////////////////////////
// CDishPage dialog

class CDishPage : public CPropertyPage
{
	DECLARE_DYNCREATE(CDishPage)

// Construction
public:
	CDishPage();
	~CDishPage();
	CDishSet m_rsDataSet;

// Dialog Data
	//{{AFX_DATA(CDishPage)
	enum { IDD = IDD_DIALOG_DISH };
	CListCtrl	m_listDisp;
	CString	m_strPrice;
	CString	m_strName;
	CString	m_strKind;
	CString	m_strDesc;
	CString	m_strCode;
	//}}AFX_DATA


// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CDishPage)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(CDishPage)
	afx_msg void OnButtonAdd();
	virtual BOOL OnInitDialog();
	afx_msg void OnClickListDisp(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnButtonModify();
	afx_msg void OnButtonDel();
	afx_msg void OnButtonClear();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

private:
	void RefreshData();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DISHPAGE_H__63D3B62B_2797_4887_B6C7_DFDB9AF3D26C__INCLUDED_)
