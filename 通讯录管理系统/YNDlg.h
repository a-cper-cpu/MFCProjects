#if !defined(AFX_YNDLG_H__6E7A2939_7372_43AF_9855_8868C0AF9079__INCLUDED_)
#define AFX_YNDLG_H__6E7A2939_7372_43AF_9855_8868C0AF9079__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// YNDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CYNDlg dialog

class CYNDlg : public CDialog
{
// Construction
public:
	CYNDlg(CWnd* pParent = NULL);   // standard constructor
    	int k;
// Dialog Data
	//{{AFX_DATA(CYNDlg)
//	enum { IDD = IDD_DIALOG7 };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CYNDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CYNDlg)
	virtual void OnOK();
	virtual void OnCancel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP();

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_YNDLG_H__6E7A2939_7372_43AF_9855_8868C0AF9079__INCLUDED_)
