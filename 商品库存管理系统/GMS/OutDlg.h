#if !defined(AFX_OUTDLG_H__5D8402A7_D8FA_4ED9_A030_64BA0A767553__INCLUDED_)
#define AFX_OUTDLG_H__5D8402A7_D8FA_4ED9_A030_64BA0A767553__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// OutDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// COutDlg dialog

class COutDlg : public CDialog
{
// Construction
public:
	COutDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(COutDlg)
	enum { IDD = IDD_DIALOG_OUT };
	CComboBox	m_cbGoods;
	CString	m_strCNum;
	CString	m_strONum;
	CString	m_strPerson;
	CTime	m_Time;
	CTime	m_Date;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(COutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(COutDlg)
	afx_msg void OnButtonCancel();
	afx_msg void OnButtonOk();
	virtual BOOL OnInitDialog();
	afx_msg void OnCancelMode();
	afx_msg void OnSelchangeComboGoods();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	void GetGoodsCode(CString strName,CString &strCode);
	void AddOut(CString strGcode);
	void DelGoods(int iNum);
	CString m_strGoodsName;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_OUTDLG_H__5D8402A7_D8FA_4ED9_A030_64BA0A767553__INCLUDED_)
