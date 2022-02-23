#if !defined(AFX_USERLISTVIEW_H__134423AB_FD33_4CD7_91F0_E77A991A8F8F__INCLUDED_)
#define AFX_USERLISTVIEW_H__134423AB_FD33_4CD7_91F0_E77A991A8F8F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// UserListView.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CUserListView view

class CUserListView : public CListView
{
protected:
	CUserListView();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(CUserListView)

// Attributes
public:

// Operations
public:
	void ShowUsers(CString strRoomNO);

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CUserListView)
	public:
	virtual void OnInitialUpdate();
	protected:
	virtual void OnDraw(CDC* pDC);      // overridden to draw this view
	//}}AFX_VIRTUAL

// Implementation
protected:
	int nHitItem;
	virtual ~CUserListView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
protected:
	void SetTitle();
	void SetStyle();
	//{{AFX_MSG(CUserListView)
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnBookinAdd();
	afx_msg void OnBookinDel();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_USERLISTVIEW_H__134423AB_FD33_4CD7_91F0_E77A991A8F8F__INCLUDED_)
