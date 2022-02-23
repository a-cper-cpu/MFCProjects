#if !defined(AFX_ROOMTYPEVIEW_H__0464A71B_3A28_4AA3_942F_EA0CD2B53235__INCLUDED_)
#define AFX_ROOMTYPEVIEW_H__0464A71B_3A28_4AA3_942F_EA0CD2B53235__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// RoomTypeView.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CRoomTypeView form view

#ifndef __AFXEXT_H__
#include <afxext.h>
#endif

class CRoomTypeView : public CFormView
{
protected:
	CRoomTypeView();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(CRoomTypeView)

// Form Data
public:
	//{{AFX_DATA(CRoomTypeView)
	enum { IDD = IDD_FORMVIEW_TYPEINFO };
	CString	m_strPrice;
	CString	m_strName;
	int		m_iTV;
	int		m_iTOILET;
	int		m_iTEL;
	int		m_iAir;
	CString	m_strID;
	CString	m_strBedNO;
	//}}AFX_DATA

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRoomTypeView)
	public:
	virtual void OnInitialUpdate();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual void OnDraw(CDC* pDC);
	//}}AFX_VIRTUAL

// Implementation
protected:
	void FillRoomType();
	virtual ~CRoomTypeView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
	//{{AFX_MSG(CRoomTypeView)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ROOMTYPEVIEW_H__0464A71B_3A28_4AA3_942F_EA0CD2B53235__INCLUDED_)
