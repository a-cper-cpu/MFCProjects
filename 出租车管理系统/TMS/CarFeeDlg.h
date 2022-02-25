#if !defined(AFX_CARFEEDLG_H__D48DEAF8_70EF_492B_AF90_6905D7EAFF0E__INCLUDED_)
#define AFX_CARFEEDLG_H__D48DEAF8_70EF_492B_AF90_6905D7EAFF0E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// CarFeeDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CCarFeeDlg dialog

class CCarFeeDlg : public CDialog
{
// Construction
public:
	CCarFeeDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CCarFeeDlg)
	enum { IDD = IDD_DIALOG_CARFEE };
	CComboBox	m_cbFeeNO;
	CComboBox	m_cbCarNO;
	CTime	m_tmBegin;
	CTime	m_tmEnd;
	CString	m_strFeeName;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCarFeeDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CCarFeeDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnCancelMode();
	afx_msg void OnButtonOk();
	afx_msg void OnButtonCancel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	void ClearData();
	void FillData();
	void DelCarFee();
	void AddCarFee();
	void GetCBData();
	void ModifyCarFee();
	void SetTitle();
	void SetStyle();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CARFEEDLG_H__D48DEAF8_70EF_492B_AF90_6905D7EAFF0E__INCLUDED_)
