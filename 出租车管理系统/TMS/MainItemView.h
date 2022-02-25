#if !defined(AFX_MAINITEMVIEW_H__DD634833_13C2_401A_9366_B1E7B41FA968__INCLUDED_)
#define AFX_MAINITEMVIEW_H__DD634833_13C2_401A_9366_B1E7B41FA968__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// MainItemView.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CMainItemView form view

#ifndef __AFXEXT_H__
#include <afxext.h>
#endif

class CMainItemView : public CFormView
{
protected:
	CMainItemView();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(CMainItemView)

// Form Data
public:
	//{{AFX_DATA(CMainItemView)
	enum { IDD = IDD_FORMVIEW_MAINITEM };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMainItemView)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	CBrush m_Brush;
	virtual ~CMainItemView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
	//{{AFX_MSG(CMainItemView)
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnCancelMode();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MAINITEMVIEW_H__DD634833_13C2_401A_9366_B1E7B41FA968__INCLUDED_)
