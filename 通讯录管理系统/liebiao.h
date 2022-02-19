#if !defined(AFX_LIEBIAO_H__6AEAB038_AADA_4CB2_B4EE_60668CAA4FFB__INCLUDED_)
#define AFX_LIEBIAO_H__6AEAB038_AADA_4CB2_B4EE_60668CAA4FFB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// liebiao.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// Cliebiao dialog

class Cliebiao : public CDialog
{
// Construction
public:
	Cliebiao(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(Cliebiao)
	enum { IDD = IDD_DIALOG4 };
	CListCtrl	m_List;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(Cliebiao)
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
Node peo1[500];

	// Generated message map functions
	//{{AFX_MSG(Cliebiao)
	virtual BOOL OnInitDialog();
	afx_msg void OnCancelMode();
	afx_msg void Ondelete();
	afx_msg void Onnew();
	afx_msg void Onselect1();
	afx_msg void Onmore();
	afx_msg void Onclear();
	afx_msg void OnClickList1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnPaint();
	afx_msg void OnButton4();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LIEBIAO_H__6AEAB038_AADA_4CB2_B4EE_60668CAA4FFB__INCLUDED_)
