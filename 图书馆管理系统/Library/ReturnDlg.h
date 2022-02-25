#if !defined(AFX_RETURNDLG_H__29207980_D4E6_439B_BB63_20587B70897F__INCLUDED_)
#define AFX_RETURNDLG_H__29207980_D4E6_439B_BB63_20587B70897F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ReturnDlg.h : header file
//
#include "BorrowSet.h"

/////////////////////////////////////////////////////////////////////////////
// CReturnDlg dialog

class CReturnDlg : public CDialog
{
// Construction
public:
	CReturnDlg(CWnd* pParent = NULL);   // standard constructor
	BOOL OnInitDialog();
	CBorrowSet m_rsDataSet;

// Dialog Data
	//{{AFX_DATA(CReturnDlg)
	enum { IDD = IDD_DIALOG_RETURN };
	CEdit	m_ctlBookID;
	CString	m_Book_ID;
	CString	m_BorrowDate;
	int	m_Days;
	CString	m_ReaderName;
	CString	m_ReturnDate;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CReturnDlg)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CReturnDlg)
	afx_msg void OnConfirm();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	void Delete_Borrow();
	int setTxtDisable( );
	int SetTxtNull();
	int Insert_History();
	int QryBorrow( );
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_RETURNDLG_H__29207980_D4E6_439B_BB63_20587B70897F__INCLUDED_)
