#if !defined(AFX_READERDLG_H__F0B35C52_1276_48EC_80C8_5B510A2120DE__INCLUDED_)
#define AFX_READERDLG_H__F0B35C52_1276_48EC_80C8_5B510A2120DE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ReaderDlg.h : header file
//
#include "ReaderDataSet.h"

/////////////////////////////////////////////////////////////////////////////
// CReaderDlg dialog

class CReaderDlg : public CDialog
{
// Construction
public:
	CReaderDlg(CWnd* pParent = NULL);   // standard constructor
	BOOL SetTextState();
	BOOL m_bEdit;
	BOOL m_bAdd;
	BOOL SetButtonState();
	BOOL DisplayRecord();
	CReaderDataSet m_rsDataSet;

// Dialog Data
	//{{AFX_DATA(CReaderDlg)
	enum { IDD = IDD_DIALOG_READER };
	CString	m_strReaderIDQ;
	CString	m_strReaderID;
	CString	m_strReaderName;
	CString	m_strReaderNameQ;
	CString	m_strIDCard;
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CReaderDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CReaderDlg)
	afx_msg void OnExit();
	afx_msg void OnFirst();
	afx_msg void OnLast();
	afx_msg void OnNew();
	afx_msg void OnNext();
	afx_msg void OnPrior();
	afx_msg void OnSave();
	afx_msg void OnCancelRec();
	afx_msg void OnDelete();
	afx_msg void OnEdit();
	afx_msg void OnEnquery();
	virtual BOOL OnInitDialog();
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_READERDLG_H__F0B35C52_1276_48EC_80C8_5B510A2120DE__INCLUDED_)
