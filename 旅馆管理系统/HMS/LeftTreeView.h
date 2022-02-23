#if !defined(AFX_LEFTTREEVIEW_H__E793A260_5270_4E82_98A1_4C36FE019E1F__INCLUDED_)
#define AFX_LEFTTREEVIEW_H__E793A260_5270_4E82_98A1_4C36FE019E1F__INCLUDED_

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
	HTREEITEM m_hHitItem ;


// Operations
public:
	void FullfillTree();
	void AddRoom(CString strRoomType,CString strRoomNo);

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
	HTREEITEM AddRoomTypeToTree(CString strTypeName);
	HTREEITEM AddRoomToTree(HTREEITEM hTypeItem, CString strRoomNum);
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
protected:
	//{{AFX_MSG(CLeftTreeView)
	afx_msg void OnSelchanged(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnRclick(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnTypeAdd();
	afx_msg void OnTypeModify();
	afx_msg void OnTypeDel();
	afx_msg void OnRoomAdd();
	afx_msg void OnRoomModify();
	afx_msg void OnRoomDel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LEFTTREEVIEW_H__E793A260_5270_4E82_98A1_4C36FE019E1F__INCLUDED_)
