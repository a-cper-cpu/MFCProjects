// AddressListDoc.h : interface of the CAddressListDoc class
//
/////////////////////////////////////////////////////////////////////////////

/*
	×÷Õß£ºÕÅ³¬¸Õ

*/

#if !defined(AFX_AddressListDOC_H__C15808FF_31CB_465C_9563_31BD6678B841__INCLUDED_)
#define AFX_AddressListDOC_H__C15808FF_31CB_465C_9563_31BD6678B841__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CAddressListDoc : public CDocument
{
protected: // create from serialization only
	CAddressListDoc();
	DECLARE_DYNCREATE(CAddressListDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAddressListDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CAddressListDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CAddressListDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_AddressListDOC_H__C15808FF_31CB_465C_9563_31BD6678B841__INCLUDED_)
