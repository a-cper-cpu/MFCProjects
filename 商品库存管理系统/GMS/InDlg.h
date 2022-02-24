#if !defined(AFX_INDLG_H__45EE16C9_7E05_4051_847B_E7EA39D86403__INCLUDED_)
#define AFX_INDLG_H__45EE16C9_7E05_4051_847B_E7EA39D86403__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// InDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CInDlg dialog

class CInDlg : public CDialog
{
// Construction
public:
	CInDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CInDlg)
	enum { IDD = IDD_DIALOG_IN };
	CComboBox	m_cbProvider;
	CComboBox	m_cbGoods;
	CTime	m_Date;
	CTime	m_Time;
	CString	m_strNum;
	CString	m_strPrice;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CInDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CInDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnButtonOk();
	afx_msg void OnButtonCancel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	void AddIn(CString strGcode,CString strPcode);
	CString m_strProviderName;
	CString m_strGoodsName;
	void AddGoods(int iNum);
	void GetProviderCode(CString strName,CString &strCode);
	void GetGoodsCode(CString strName,CString &strCode);
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_INDLG_H__45EE16C9_7E05_4051_847B_E7EA39D86403__INCLUDED_)
