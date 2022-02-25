#if !defined(AFX_BORROWDLG_H__0ADFE907_8B58_4710_BF7D_2F042E1ACF7D__INCLUDED_)
#define AFX_BORROWDLG_H__0ADFE907_8B58_4710_BF7D_2F042E1ACF7D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// BorrowDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CBorrowDlg dialog
#include "BorrowDataSet.h"	
#include "ReaderDataSet.h"	
#include "BookDataSet.h"

class CBorrowDlg : public CDialog
{
// Construction
public:
	CBorrowDlg(CWnd* pParent = NULL);   // standard constructor
	CBookDataSet m_rsBookDataSet;
	CReaderDataSet m_rsReaderDataSet;
	CBorrowDataSet m_rsDataSet;


// Dialog Data
	//{{AFX_DATA(CBorrowDlg)
	enum { IDD = IDD_DIALOG_BORROW };
		CString	m_strBookID;
		CString	m_strReaderID;
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBorrowDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CBorrowDlg)
	afx_msg void OnConfirm();
	afx_msg void OnCancel();
	virtual BOOL OnInitDialog();
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
extern CLibraryApp theApp;

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BORROWDLG_H__0ADFE907_8B58_4710_BF7D_2F042E1ACF7D__INCLUDED_)
