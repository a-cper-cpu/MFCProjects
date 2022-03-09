#if !defined(AFX_RIGHTLISTVIEW_H__244D4C42_A54B_4C9F_9E37_4BA1CBAB6E76__INCLUDED_)
#define AFX_RIGHTLISTVIEW_H__244D4C42_A54B_4C9F_9E37_4BA1CBAB6E76__INCLUDED_

/*
	作者：张超刚

*/

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// RightListView.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CRightListView form view

#ifndef __AFXEXT_H__
#include <afxext.h>
#endif


class CRightListView : public CFormView
{
public:// changed from protected
	CRightListView();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(CRightListView)

// Form Data
public:
	//{{AFX_DATA(CRightListView)
	enum { IDD = IDD_LIST_VIEW };
	CListCtrl	m_listCtrl;
	//}}AFX_DATA

// Attributes
public:
	//声明ADO记录集
	_RecordsetPtr	m_pRecordset;

// Operations
public:
	BOOL SetDbToFile(_RecordsetPtr &recPtr, CString &strPath);
	BOOL OpenRecordSet(_RecordsetPtr &recPtr, CString &strSQL);

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRightListView)
	public:
	virtual void OnInitialUpdate();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CRightListView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
	//{{AFX_MSG(CRightListView)
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnClickList(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDblclkList(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnKillfocusList(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_RIGHTLISTVIEW_H__244D4C42_A54B_4C9F_9E37_4BA1CBAB6E76__INCLUDED_)
