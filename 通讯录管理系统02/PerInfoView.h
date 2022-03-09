#if !defined(AFX_PERINFOVIEW_H__79A48BD8_6B0E_4F26_BF05_E327D74AB2B3__INCLUDED_)
#define AFX_PERINFOVIEW_H__79A48BD8_6B0E_4F26_BF05_E327D74AB2B3__INCLUDED_


/*
	作者：张超刚

*/

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PerInfoView.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CPerInfoView form view

#ifndef __AFXEXT_H__
#include <afxext.h>
#endif

class CPerInfoView : public CFormView
{
public:// changed from protected
	CPerInfoView();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(CPerInfoView)

// Form Data
public:
	//{{AFX_DATA(CPerInfoView)
	enum { IDD = IDD_INFO_VIEW };
	COleDateTime	m_Birthday;
	CString	m_strCompanyAdd;
	CString	m_strComment;
	CString	m_strCompany;
	CString	m_strComTel;
	CString	m_strEmail;
	CString	m_strHomeAdd;
	CString	m_strHomeTel;
	CString	m_strMobile;
	CString	m_strName;
	CString	m_strWeb;
	//}}AFX_DATA

// Attributes
public:
	//位图
	CBitmap m_Bitmap;
	//照片显示位置
	CRect m_recOffset;

// Operations
public:
	void ReadBmpToMem(CString& strPath);

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPerInfoView)
	public:
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CPerInfoView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
	//{{AFX_MSG(CPerInfoView)
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnPaint();
	afx_msg void OnCheckStretch();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PERINFOVIEW_H__79A48BD8_6B0E_4F26_BF05_E327D74AB2B3__INCLUDED_)
