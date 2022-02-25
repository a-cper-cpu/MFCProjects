// TMSDoc.h : interface of the CTMSDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_TMSDOC_H__848A49B7_6373_48E9_BC0E_6D9FBCFCD049__INCLUDED_)
#define AFX_TMSDOC_H__848A49B7_6373_48E9_BC0E_6D9FBCFCD049__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CTMSDoc : public CDocument
{
protected: // create from serialization only
	CTMSDoc();
	DECLARE_DYNCREATE(CTMSDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTMSDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CTMSDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CTMSDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TMSDOC_H__848A49B7_6373_48E9_BC0E_6D9FBCFCD049__INCLUDED_)
