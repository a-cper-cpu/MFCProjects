#if !defined(AFX_ORDERPAGE_H__1ECE6A83_DFB8_46A3_933D_4479541CB9AF__INCLUDED_)
#define AFX_ORDERPAGE_H__1ECE6A83_DFB8_46A3_933D_4479541CB9AF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// OrderPage.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// COrderPage dialog
#include "OrderSet.h"

class COrderPage : public CPropertyPage
{
	DECLARE_DYNCREATE(COrderPage)

// Construction
public:
	COrderSet m_rsDataSet;
	COrderPage();
	~COrderPage();

// Dialog Data
	//{{AFX_DATA(COrderPage)
	enum { IDD = IDD_DIALOG_ORDER };
	CListCtrl	m_listDisp;
	CString	m_strNum;
	CTime	m_Date;
	CString	m_strDeskCode;
	CString	m_strDishCode;
	//}}AFX_DATA


// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(COrderPage)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(COrderPage)
	virtual BOOL OnInitDialog();
	afx_msg void OnButtonAdd();
	afx_msg void OnButtonModify();
	afx_msg void OnButtonDel();
	afx_msg void OnButtonClear();
	afx_msg void OnClickListDisp(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

private:
	void RefreshData();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ORDERPAGE_H__1ECE6A83_DFB8_46A3_933D_4479541CB9AF__INCLUDED_)
