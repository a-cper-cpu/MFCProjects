// RMSDlg.h : header file
//

#if !defined(AFX_RMSDLG_H__5FAC9953_4819_43AA_A655_F6417FAB1969__INCLUDED_)
#define AFX_RMSDLG_H__5FAC9953_4819_43AA_A655_F6417FAB1969__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "DeskPage.h"
#include "DishPage.h"
#include "OrderPage.h"
#include "PayPage.h"
/////////////////////////////////////////////////////////////////////////////
// CRMSDlg dialog

class CRMSDlg : public CDialog
{
// Construction
public:
	CDishPage m_Page1;
	CDeskPage m_Page2;
	COrderPage m_Page3;
	CPayPage m_Page4;
	CPropertySheet m_Sheet;
	CRMSDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CRMSDlg)
	enum { IDD = IDD_RMS_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRMSDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CRMSDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_RMSDLG_H__5FAC9953_4819_43AA_A655_F6417FAB1969__INCLUDED_)
