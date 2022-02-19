// test02Dlg.h : header file
//

#if !defined(AFX_TEST02DLG_H__938EEEC0_829D_4A25_B79E_91A2669E2B8D__INCLUDED_)
#define AFX_TEST02DLG_H__938EEEC0_829D_4A25_B79E_91A2669E2B8D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CTest02Dlg dialog

class CTest02Dlg : public CDialog
{
// Construction
public:
	CTest02Dlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CTest02Dlg)
	enum { IDD = IDD_TEST02_DIALOG };
	CButton	m_buttoncheng;
	CButton	m_buttonchu;
	CButton	m_buttonquyu;
	CButton	m_buttonjian;
	CButton	m_buttonjia;
	CString	m_editnumber1;
	CString	m_editnumber2;
	CString	m_editnumber3;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTest02Dlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CTest02Dlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnBUTTONcheng();
	afx_msg void OnBUTTONchu();
	afx_msg void OnBUTTONjia();
	afx_msg void OnBUTTONjian();
	afx_msg void OnBUTTONquyu();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TEST02DLG_H__938EEEC0_829D_4A25_B79E_91A2669E2B8D__INCLUDED_)
