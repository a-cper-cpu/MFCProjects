#if !defined(AFX_DRIVERDLG_H__00338E4E_60FF_4B91_B021_09BC39DB9B6B__INCLUDED_)
#define AFX_DRIVERDLG_H__00338E4E_60FF_4B91_B021_09BC39DB9B6B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DriverDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDriverDlg dialog

class CDriverDlg : public CDialog
{
// Construction
public:
	CDriverDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDriverDlg)
	enum { IDD = IDD_DIALOG_DRIVER };
	CTime	m_tmDate;
	CString	m_strAddress;
	CString	m_strID;
	CString	m_strKind;
	CString	m_strName;
	CString	m_strNO;
	CString	m_strPhone;
	CString	m_strSex;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDriverDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDriverDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnButtonOk();
	afx_msg void OnButtonCancel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	void DelDriver();
	void ModifyDriver();
	void AddDriver();
	void ClearData();
	void FillData();
	void SetTitle();
	void SetStyle();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DRIVERDLG_H__00338E4E_60FF_4B91_B021_09BC39DB9B6B__INCLUDED_)
