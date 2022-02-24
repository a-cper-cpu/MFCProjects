#if !defined(AFX_PAGEWELCOME_H__8A3E6C27_67DB_4009_8738_A92175CC52B3__INCLUDED_)
#define AFX_PAGEWELCOME_H__8A3E6C27_67DB_4009_8738_A92175CC52B3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PageWelcome.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CPageWelcome dialog

class CPageWelcome : public CDialog
{
// Construction
public:
	CPageWelcome(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CPageWelcome)
	enum { IDD = IDD_PAGE_WELCOME};
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPageWelcome)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CPageWelcome)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PAGEWELCOME_H__8A3E6C27_67DB_4009_8738_A92175CC52B3__INCLUDED_)
