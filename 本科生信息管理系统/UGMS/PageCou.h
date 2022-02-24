#if !defined(AFX_PAGECOU_H__ED334D96_D204_4148_9B8C_2378C05AC37E__INCLUDED_)
#define AFX_PAGECOU_H__ED334D96_D204_4148_9B8C_2378C05AC37E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PageCou.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CPageCou dialog

class CPageCou: public CDialog
{
// Construction
public:
	CPageCou(CWnd* pParent = NULL);   // standard constructor
	//声明ADO记录集
	_RecordsetPtr	m_pRecordset;
	_RecordsetPtr	m_pRecordsetCHO;
	//添加功能函数
	void Query();
	void Add();
	void Delete();
	void Modify();
	void OpenCOURSES();

// Dialog Data
	//{{AFX_DATA(CPageCou)
	enum { IDD = IDD_PAGE_COU };
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
	int		m_CKind;
	int		m_CID;
	CString	m_CName;
	int		m_CScore;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPageCou)
	protected:

	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CPageCou)
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

#endif // !defined(AFX_PAGECOU_H__ED334D96_D204_4148_9B8C_2378C05AC37E__INCLUDED_)
