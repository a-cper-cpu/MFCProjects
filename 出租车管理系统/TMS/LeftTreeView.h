#if !defined(AFX_LEFTTREEVIEW_H__18D9E346_DE1D_4C2E_AC34_56BC6BA12448__INCLUDED_)
#define AFX_LEFTTREEVIEW_H__18D9E346_DE1D_4C2E_AC34_56BC6BA12448__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// LeftTreeView.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CLeftTreeView view

class CLeftTreeView : public CTreeView
{
protected:
	CLeftTreeView();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(CLeftTreeView)
protected:
	CImageList m_ImageList;


// Attributes
public:

// Operations
public:
	void AddItem(CString strMainItem,CString strSubItem);
	void FullfillTree();
	HTREEITEM m_hHitItem ;
	
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLeftTreeView)
	public:
	virtual void OnInitialUpdate();
	protected:
	virtual void OnDraw(CDC* pDC);      // overridden to draw this view
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CLeftTreeView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
protected:
	//{{AFX_MSG(CLeftTreeView)
	afx_msg void OnSelchanged(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	HTREEITEM  AddSubToTree(HTREEITEM hTypeItem, CString strSubItem);
	HTREEITEM  AddMainToTree(CString strMainItem);
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LEFTTREEVIEW_H__18D9E346_DE1D_4C2E_AC34_56BC6BA12448__INCLUDED_)
