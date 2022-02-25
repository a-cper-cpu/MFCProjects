// TMSView.h : interface of the CTMSView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_TMSVIEW_H__A2F9521B_210F_4612_875B_4B1F5208952C__INCLUDED_)
#define AFX_TMSVIEW_H__A2F9521B_210F_4612_875B_4B1F5208952C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CTMSView : public CView
{
protected: // create from serialization only
	CTMSView();
	DECLARE_DYNCREATE(CTMSView)

// Attributes
public:
	CTMSDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTMSView)
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
	virtual ~CTMSView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CTMSView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in TMSView.cpp
inline CTMSDoc* CTMSView::GetDocument()
   { return (CTMSDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TMSVIEW_H__A2F9521B_210F_4612_875B_4B1F5208952C__INCLUDED_)
