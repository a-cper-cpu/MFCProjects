#if !defined(AFX_PAGECHO_H__F3152CE7_3E1E_4B50_B976_647AAD1EBCA1__INCLUDED_)
#define AFX_PAGECHO_H__F3152CE7_3E1E_4B50_B976_647AAD1EBCA1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PageCho.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CPageCho dialog

class CPageCho : public CDialog
{
// Construction
public:
	CPageCho(CWnd* pParent = NULL);   // standard constructor
	//声明ADO记录集
	_RecordsetPtr	m_pRecordset;

	//添加功能函数
	void Query();
	void Add();
	void Delete();
	void Modify();
	void OpenSTUDENTS();
	void OpenCOURSES();
	void OpenCHOICES();


// Dialog Data
	//{{AFX_DATA(CPageCho)
	enum { IDD = IDD_PAGE_CHO };
	CEdit	m_ctlSID;
	CEdit	m_ctlCID;
	CButton	m_btnQuery;
	CButton	m_btnPre;
	CButton	m_btnOk;
	CButton	m_btnNext;
	CButton	m_btnModify;
	CButton	m_btnLast;
	CButton	m_btnFirst;
	CButton	m_btnDel;
	CButton	m_btnAdd;
	int		m_IsPass;
	int		m_CID;
	int		m_Score;
	int		m_SID;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPageCho)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CPageCho)
	virtual BOOL OnInitDialog();
	afx_msg void OnButtonFirst();
	afx_msg void OnButtonPrevious();
	afx_msg void OnButtonNext();
	afx_msg void OnButtonLast();
	afx_msg void OnButtonQuery();
	afx_msg void OnButtonAdd();
	afx_msg void OnButtonDelete();
	afx_msg void OnButtonModify();
	afx_msg void OnButtonOk();
	afx_msg void OnButtonCancel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
//引入全局变量theApp
extern CUGMSApp theApp;

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PAGECHO_H__F3152CE7_3E1E_4B50_B976_647AAD1EBCA1__INCLUDED_)
