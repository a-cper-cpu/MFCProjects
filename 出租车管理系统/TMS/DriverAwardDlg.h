#if !defined(AFX_DRIVERAWARDDLG_H__BD48E017_F548_41E1_9280_0934FB84A60E__INCLUDED_)
#define AFX_DRIVERAWARDDLG_H__BD48E017_F548_41E1_9280_0934FB84A60E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DriverAwardDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDriverAwardDlg dialog

class CDriverAwardDlg : public CDialog
{
// Construction
public:
	CDriverAwardDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDriverAwardDlg)
	enum { IDD = IDD_DIALOG_DRIVERAWARD };
	CComboBox	m_cbDriverNO;
	CComboBox	m_cbAwardNO;
	CString	m_strContent;
	CString	m_strMemo;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDriverAwardDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDriverAwardDlg)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DRIVERAWARDDLG_H__BD48E017_F548_41E1_9280_0934FB84A60E__INCLUDED_)
