#if !defined(AFX_CARDLG_H__BE09D8E3_8F4E_4975_9276_13AB8CC8755E__INCLUDED_)
#define AFX_CARDLG_H__BE09D8E3_8F4E_4975_9276_13AB8CC8755E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// CarDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CCarDlg dialog

class CCarDlg : public CDialog
{
// Construction
public:
	CCarDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CCarDlg)
	enum { IDD = IDD_DIALOG_CAR };
	CString	m_strColor;
	CString	m_strKind;
	CString	m_strCarNO;
	CString	m_strEngineNO;
	CString	m_strMeterNO;
	CString	m_strClassisNO;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCarDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CCarDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnButtonOk();
	afx_msg void OnButtonCancel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	void DelCar();
	void ModifyCar();
	void AddCar();
	void ClearData();
	void FillData();
	void SetTitle();
	void SetStyle();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CARDLG_H__BE09D8E3_8F4E_4975_9276_13AB8CC8755E__INCLUDED_)
