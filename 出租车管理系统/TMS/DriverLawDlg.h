#if !defined(AFX_DRIVERLAWDLG_H__5A997509_2BC2_481F_983D_93DD322DF100__INCLUDED_)
#define AFX_DRIVERLAWDLG_H__5A997509_2BC2_481F_983D_93DD322DF100__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DriverLawDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDriverLawDlg dialog

class CDriverLawDlg : public CDialog
{
// Construction
public:
	CDriverLawDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDriverLawDlg)
	enum { IDD = IDD_DIALOG_DRIVERPUNISH };
	CComboBox	m_cbLawNO;
	CComboBox	m_cbDriverNO;
	int		m_iTreatState;
	CTime	m_tmDate;
	CString	m_strAddress;
	CString	m_strMemo;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDriverLawDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDriverLawDlg)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DRIVERLAWDLG_H__5A997509_2BC2_481F_983D_93DD322DF100__INCLUDED_)
