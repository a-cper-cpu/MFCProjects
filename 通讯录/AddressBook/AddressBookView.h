// AddressBookView.h : interface of the CAddressBookView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_ADDRESSBOOKVIEW_H__4470026F_9092_4F38_B8E7_FC25CFAB2180__INCLUDED_)
#define AFX_ADDRESSBOOKVIEW_H__4470026F_9092_4F38_B8E7_FC25CFAB2180__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CAddressBookView : public CFormView
{
protected: // create from serialization only
	CAddressBookView();
	DECLARE_DYNCREATE(CAddressBookView)

public:
	//{{AFX_DATA(CAddressBookView)
	enum { IDD = IDD_ADDRESSBOOK_FORM };
	CString	m_strName;
	CString	m_strCompany;
	CString	m_strPhone;
	CString	m_strEmail;
	//}}AFX_DATA

// Attributes
public:
	CAddressBookDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAddressBookView)
	public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual void OnInitialUpdate(); // called first time after construct
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CAddressBookView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	POSITION m_Position; //指向链表中当前结点的指针
	CObList *m_PersonViewList;//指向文档类成员(双向链表)的指针


// Generated message map functions
protected:
	//{{AFX_MSG(CAddressBookView)
	afx_msg void OnChangeEditName();
	afx_msg void OnButtonAdd();
	afx_msg void OnButtonDelete();
	afx_msg void OnButtonPrevious();
	afx_msg void OnButtonNext();
	afx_msg void OnChangeEditPhone();
	afx_msg void OnChangeEditCompany();
	afx_msg void OnChangeEditEmail();
	afx_msg void OnCheckModify();
	afx_msg void OnButtonClear();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in AddressBookView.cpp
inline CAddressBookDoc* CAddressBookView::GetDocument()
   { return (CAddressBookDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ADDRESSBOOKVIEW_H__4470026F_9092_4F38_B8E7_FC25CFAB2180__INCLUDED_)
