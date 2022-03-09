#if !defined(AFX_QUERYDLG_H__01A21BA7_627A_4FD1_A9D9_BF1D381694BF__INCLUDED_)
#define AFX_QUERYDLG_H__01A21BA7_627A_4FD1_A9D9_BF1D381694BF__INCLUDED_

/*
	作者：张超刚

*/

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// QueryDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CQueryDlg dialog

class CQueryDlg : public CDialog
{
// Construction
public:
	CString& GetSQL();
	CQueryDlg(CWnd* pParent = NULL);   // standard constructor
	//最终的SQL语句
	CString m_strSql;

// Dialog Data
	//{{AFX_DATA(CQueryDlg)
	enum { IDD = IDD_QUERY };
	CString	m_strWhereValue;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CQueryDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CQueryDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnRemoveSql();
	afx_msg void OnAddSql();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_QUERYDLG_H__01A21BA7_627A_4FD1_A9D9_BF1D381694BF__INCLUDED_)
