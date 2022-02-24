#if !defined(AFX_VIEWDLG_H__46B9EF8C_84CA_4475_BDDF_C6150CE17F52__INCLUDED_)
#define AFX_VIEWDLG_H__46B9EF8C_84CA_4475_BDDF_C6150CE17F52__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ViewDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CViewDlg dialog

class CViewDlg : public CDialog
{
// Construction
public:
	void Init(int iIndex);
	CViewDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CViewDlg)
	enum { IDD = IDD_DIALOG_VIEW };
	CListCtrl	m_listDisp;
	CString	m_strNum;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CViewDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CViewDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnButtonOk();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	void ViewLog();
	void ViewOutlib();
	void ViewInlib();
	void ViewProvider();
	void ViewGoods();
	void SetStyle();
	void SetTitle();
	int m_iKind;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_VIEWDLG_H__46B9EF8C_84CA_4475_BDDF_C6150CE17F52__INCLUDED_)
