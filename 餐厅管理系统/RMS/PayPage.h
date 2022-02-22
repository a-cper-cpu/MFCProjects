#if !defined(AFX_PAYPAGE_H__479C99DA_762D_4636_AFF3_3781A9BAEC39__INCLUDED_)
#define AFX_PAYPAGE_H__479C99DA_762D_4636_AFF3_3781A9BAEC39__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PayPage.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CPayPage dialog
#include "PaySet.h"
#include "OrderSet.h"
class CPayPage : public CPropertyPage
{
	DECLARE_DYNCREATE(CPayPage)

// Construction
public:
	CPaySet m_rsDataSet;
	COrderSet m_rsDataSetEx;
	CPayPage();
	~CPayPage();

// Dialog Data
	//{{AFX_DATA(CPayPage)
	enum { IDD = IDD_DIALOG_PAY };
	CListCtrl	m_listDisp;
	CString	m_strMoney;
	CString	m_strDishName;
	CString	m_strDishCode;
	CTime	m_Date;
	CString	m_strDeskCode;
	//}}AFX_DATA


// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CPayPage)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(CPayPage)
	virtual BOOL OnInitDialog();
	afx_msg void OnClickListDisp(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnButtonPay();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

private:
	void RefreshData();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PAYPAGE_H__479C99DA_762D_4636_AFF3_3781A9BAEC39__INCLUDED_)
