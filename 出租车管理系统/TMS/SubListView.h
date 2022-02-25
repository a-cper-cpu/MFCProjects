#if !defined(AFX_SUBLISTVIEW_H__402CF322_8F67_426E_8484_11935329EC81__INCLUDED_)
#define AFX_SUBLISTVIEW_H__402CF322_8F67_426E_8484_11935329EC81__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SubListView.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSubListView view

class CSubListView : public CListView
{
protected:
	CSubListView();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(CSubListView)

// Attributes
public:
private:
	void SelLaw();
	void SelFee();
	void SelDriverAward();
	void SelDriverLaw();
	void SelCarFee();
	void ListFee();
	void ListPunish();
	void ListDriverAward();
	void ListDriverPunish();
	void ListCarFee();
	void SelCarDriver();
	void ListCarDriver();
	void SelDriver();
	void ListDriver();
	void SelCar();
	void ListCar();
	void GetTitle();
	CArray<CString,CString&> arTitle;

// Operations
public:
	void RefreshData();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSubListView)
	public:
	virtual void OnInitialUpdate();
	protected:
	virtual void OnDraw(CDC* pDC);      // overridden to draw this view
	//}}AFX_VIRTUAL

// Implementation
protected:
	int nHitItem;
	virtual ~CSubListView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
protected:
	void SetTitle();
	void SetStyle();
	//{{AFX_MSG(CSubListView)
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnMenuitemCarmodify();
	afx_msg void OnMenuitemCardel();
	afx_msg void OnMenuitemCaradd();
	afx_msg void OnMenuitemDriveradd();
	afx_msg void OnMenuitemDrivermodify();
	afx_msg void OnMenuitemDriverdel();
	afx_msg void OnMenuitemCdadd();
	afx_msg void OnMenuitemCdmodify();
	afx_msg void OnMenuitemCddel();
	afx_msg void OnMenuitemCarfeeadd();
	afx_msg void OnMenuitemCarfeemodify();
	afx_msg void OnMenuitemCarfeedl();
	afx_msg void OnMenuitemDriverlawadd();
	afx_msg void OnMenuitemDriverlawmodify();
	afx_msg void OnMenuitemDriverlawdel();
	afx_msg void OnMenuitemDriverawardadd();
	afx_msg void OnMenuitemDriverawardmodify();
	afx_msg void OnMenuitemDriverawarddel();
	afx_msg void OnMenuitemFeeadd();
	afx_msg void OnMenuitemFeemodify();
	afx_msg void OnMenuitemFeedel();
	afx_msg void OnMenuitemLawadd();
	afx_msg void OnMenuitemLawmodify();
	afx_msg void OnMenuitemLawdel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SUBLISTVIEW_H__402CF322_8F67_426E_8484_11935329EC81__INCLUDED_)
