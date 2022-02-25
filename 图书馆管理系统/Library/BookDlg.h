#if !defined(AFX_BOOKDLG_H__A7F5E5B7_F29A_4A7D_9DF6_582B87FC543E__INCLUDED_)
#define AFX_BOOKDLG_H__A7F5E5B7_F29A_4A7D_9DF6_582B87FC543E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// BookDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CBookDlg dialog
#include "BookDataSet.h"

class CBookDlg : public CDialog
{
// Construction
public:
	CBookDlg(CWnd* pParent = NULL);   // standard constructor
	BOOL SetButtonState();
	BOOL SetTextState();
	BOOL DisplayRecord();
	BOOL m_bEdit;
	BOOL m_bAdd;
	CBookDataSet m_rsDataSet;

// Dialog Data
	//{{AFX_DATA(CBookDlg)
	enum { IDD = IDD_DIALOG_BOOK };
	CString	m_strAuthor;
	CString	m_strBookID;
	CString	m_strBookIDQ;
	CString	m_strBookName;
	CString	m_strBookNameQ;
	CString	m_strFlag;
	CString	m_strPress;
	CString	m_strPressDate;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBookDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CBookDlg)
	afx_msg void OnCancelRec();
	afx_msg void OnDelete();
	afx_msg void OnEdit();
	afx_msg void OnEnquery();
	afx_msg void OnExit();
	afx_msg void OnFirst();
	afx_msg void OnLast();
	afx_msg void OnNew();
	afx_msg void OnNext();
	afx_msg void OnPrior();
	afx_msg void OnSave();
	virtual BOOL OnInitDialog();
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BOOKDLG_H__A7F5E5B7_F29A_4A7D_9DF6_582B87FC543E__INCLUDED_)
