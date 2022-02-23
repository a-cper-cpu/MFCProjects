// HMSDoc.h : interface of the CHMSDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_HMSDOC_H__1EA9755B_DAAD_47B2_A0EF_DB7E0D862984__INCLUDED_)
#define AFX_HMSDOC_H__1EA9755B_DAAD_47B2_A0EF_DB7E0D862984__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CHMSDoc : public CDocument
{
protected: // create from serialization only
	CHMSDoc();
	DECLARE_DYNCREATE(CHMSDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CHMSDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CHMSDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CHMSDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_HMSDOC_H__1EA9755B_DAAD_47B2_A0EF_DB7E0D862984__INCLUDED_)
