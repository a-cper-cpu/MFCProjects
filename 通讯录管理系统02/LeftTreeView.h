#if !defined(AFX_LEFTTREEVIEW_H__EBD2D1E3_E073_4C52_ADC0_EC03085A457B__INCLUDED_)
#define AFX_LEFTTREEVIEW_H__EBD2D1E3_E073_4C52_ADC0_EC03085A457B__INCLUDED_

/*
	作者：张超刚

*/

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// LeftTreeView.h : header file
//
#include "RightPaneFrame.h"
/////////////////////////////////////////////////////////////////////////////
// CLeftTreeView form view

#ifndef __AFXEXT_H__
#include <afxext.h>
#endif

class CLeftTreeView : public CFormView
{
protected:
	CLeftTreeView();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(CLeftTreeView)

// Form Data
public:
	//{{AFX_DATA(CLeftTreeView)
	enum { IDD = IDD_TREE_VIEW };
	CTreeCtrl	m_treeCtrl;
	//}}AFX_DATA

// Attributes
public:
	CRightPaneFrame* m_pRightPaneFrame;
	CImageList m_ImageList;
	HTREEITEM  m_hSelItem;
	//声明ADO记录集
	_RecordsetPtr	m_pRecordset;
	//随机产生树项图标
	int m_iImage;

// Operations
public:
	CString VariantToCString(const _variant_t &var);
	HTREEITEM AddSecondClassToTree(HTREEITEM hFirstClassItem,CString strSecondClass);
	HTREEITEM AddFirstClassToTree(HTREEITEM hRootItem,CString strFirstClass);
	void ShowTree();
	BOOL OpenRecordSet(_RecordsetPtr &recPtr, CString &strSQL);

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLeftTreeView)
	public:
	virtual void OnInitialUpdate();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CLeftTreeView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
	//{{AFX_MSG(CLeftTreeView)
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnSelchangedTree(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnKillfocusTree(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LEFTTREEVIEW_H__EBD2D1E3_E073_4C52_ADC0_EC03085A457B__INCLUDED_)
