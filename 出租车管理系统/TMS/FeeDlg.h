#if !defined(AFX_FEEDLG_H__DD8CA62D_DC5B_4BB7_93E8_7611537C16D2__INCLUDED_)
#define AFX_FEEDLG_H__DD8CA62D_DC5B_4BB7_93E8_7611537C16D2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// FeeDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CFeeDlg dialog

class CFeeDlg : public CDialog
{
// Construction
public:
	CFeeDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CFeeDlg)
	enum { IDD = IDD_DIALOG_FEE };
	CString	m_strDepartment;
	CString	m_strMoney;
	CString	m_strName;
	CString	m_strNO;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFeeDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CFeeDlg)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FEEDLG_H__DD8CA62D_DC5B_4BB7_93E8_7611537C16D2__INCLUDED_)
