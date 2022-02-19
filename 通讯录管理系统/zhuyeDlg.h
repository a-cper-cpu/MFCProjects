#if !defined(AFX_ZHUYEDLG_H__D3B96484_F1CE_464E_AAD4_2312DFA6B334__INCLUDED_)
#define AFX_ZHUYEDLG_H__D3B96484_F1CE_464E_AAD4_2312DFA6B334__INCLUDED_

#include "liebiao.h"	// Added by ClassView
#include "bianji.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// zhuyeDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CzhuyeDlg dialog

class CzhuyeDlg : public CDialog
{
// Construction
public:
	//bool m_bFlag=0;
	
	Cliebiao m_mm1;
	Cbianji m_mm2;
	CzhuyeDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CzhuyeDlg)
	enum { IDD = IDD_DIALOG3 };
	CButton	m_home;
	CButton	m_add;
	CButton	m_alter;
	CTabCtrl	m_tabctrl;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CzhuyeDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
struct Node
{
	char name[10];
	char month[5];
	char day[5];
    char tel[20];
	char qq[20];
	char address[100];
	char  relationship[100];
	char sex[5];
	char beizhu[50];
   
};
Node peo[500];
	// Generated message map functions
	//{{AFX_MSG(CzhuyeDlg)
	afx_msg void OnSelchangeTab1(NMHDR* pNMHDR, LRESULT* pResult);
	virtual BOOL OnInitDialog();
	afx_msg void OnCaptureChanged(CWnd *pWnd);
	afx_msg void OnButton2();
	afx_msg void OnButton3();
	afx_msg void Onalter();
	virtual void OnOK();
	afx_msg void OnPaint();
	afx_msg void OnButton4();
	afx_msg void OnMusic();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()


};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ZHUYEDLG_H__D3B96484_F1CE_464E_AAD4_2312DFA6B334__INCLUDED_)
