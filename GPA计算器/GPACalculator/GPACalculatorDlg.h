// GPACalculatorDlg.h : header file
//

#if !defined(AFX_GPACALCULATORDLG_H__A743ECFA_0306_4FA1_A2FA_BBBAEC1D625B__INCLUDED_)
#define AFX_GPACALCULATORDLG_H__A743ECFA_0306_4FA1_A2FA_BBBAEC1D625B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CGPACalculatorDlg dialog
typedef struct stScore
{
	double dOPoint;
	double dSPoint;
	double dNum;
}stScore;

class CGPACalculatorDlg : public CDialog
{
// Construction
public:
	CGPACalculatorDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CGPACalculatorDlg)
	enum { IDD = IDD_GPACALCULATOR_DIALOG };
	CListBox	m_ListScore;
	CComboBox	m_cmbStandard;
	CString	m_sPathName;
	double	m_dS1;
	double	m_dS2;
	double	m_dS3;
	double	m_dS4;
	double	m_dS5;
	double	m_dS6;
	double	m_dS7;
	double	m_dO1;
	double	m_dO2;
	double	m_dO3;
	double	m_dO4;
	double	m_dO5;
	double	m_dO6;
	double	m_dO7;
	double	m_dO8;
	double	m_dTotal;
	CString	m_strAverage;
	CString	m_strGPA;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGPACalculatorDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CGPACalculatorDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButtonOpen();
	afx_msg void OnMenuitemMan();
	afx_msg void OnMenuitemAbout();
	afx_msg void OnMenuitemExit();
	afx_msg void OnSelchangeComboStandard();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnButtonOk();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	double GetSDPoint(double dPoint);
	void SetEditRead(bool bReadOnly);
	void ChangeType(int nType);
private:
	void GatherData();
	void SpliterString(CString str,double &a,double &b);
	CArray<stScore,stScore&> arScore;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GPACALCULATORDLG_H__A743ECFA_0306_4FA1_A2FA_BBBAEC1D625B__INCLUDED_)
