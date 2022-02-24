#if !defined(AFX_PAGESTU_H__F410AAFA_AE70_43D6_9890_F8F74DD51644__INCLUDED_)
#define AFX_PAGESTU_H__F410AAFA_AE70_43D6_9890_F8F74DD51644__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PageStu.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CPageStu dialog

class CPageStu : public CDialog
{
// Construction
public:
	CPageStu(CWnd* pParent = NULL);   // standard constructor
	//声明ADO记录集
	_RecordsetPtr	m_pRecordset;
	_RecordsetPtr	m_pRecordsetCHO;
	//添加功能函数
	void Query();
	void Add();
	void Delete();
	void Modify();
	void OpenSTUDENTS();


// Dialog Data
	//{{AFX_DATA(CPageStu)
	enum { IDD = IDD_PAGE_STU };
	CEdit	m_ctlSID;
	CButton	m_btnQuery;
	CButton	m_btnPre;
	CButton	m_btnOk;
	CButton	m_btnNext;
	CButton	m_btnModify;
	CButton	m_btnLast;
	CButton	m_btnFirst;
	CButton	m_btnDel;
	CButton	m_btnAdd;
	COleDateTime	m_SComeDate;
	int		m_SID;
	CString	m_SName;
	int		m_SSex;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPageStu)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CPageStu)
	virtual BOOL OnInitDialog();
	afx_msg void OnButtonFirst();
	afx_msg void OnButtonQuery();
	afx_msg void OnButtonAdd();
	afx_msg void OnButtonDelete();
	afx_msg void OnButtonModify();
	afx_msg void OnButtonPrevious();
	afx_msg void OnButtonNext();
	afx_msg void OnButtonLast();
	afx_msg void OnButtonOk();
	afx_msg void OnButtonCancel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
//引入全局变量theApp
extern CUGMSApp theApp;
//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PAGESTU_H__F410AAFA_AE70_43D6_9890_F8F74DD51644__INCLUDED_)
