// HMSView.h : interface of the CHMSView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_HMSVIEW_H__8BE321D4_FDA4_4E73_B520_3EB8DB37CB1F__INCLUDED_)
#define AFX_HMSVIEW_H__8BE321D4_FDA4_4E73_B520_3EB8DB37CB1F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CHMSView : public CView
{
protected: // create from serialization only
	CHMSView();
	DECLARE_DYNCREATE(CHMSView)

// Attributes
public:
	CHMSDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CHMSView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CHMSView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CHMSView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in HMSView.cpp
inline CHMSDoc* CHMSView::GetDocument()
   { return (CHMSDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_HMSVIEW_H__8BE321D4_FDA4_4E73_B520_3EB8DB37CB1F__INCLUDED_)
