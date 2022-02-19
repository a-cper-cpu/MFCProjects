// AddressBookDoc.h : interface of the CAddressBookDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_ADDRESSBOOKDOC_H__9C1045EB_5317_48D5_BEAF_6CA7DAB1E37B__INCLUDED_)
#define AFX_ADDRESSBOOKDOC_H__9C1045EB_5317_48D5_BEAF_6CA7DAB1E37B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CAddressBookDoc : public CDocument
{
protected: // create from serialization only
	CAddressBookDoc();
	DECLARE_DYNCREATE(CAddressBookDoc)

// Attributes
public:
	CObList m_PersonList;//文档类成员
	

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAddressBookDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	virtual void DeleteContents();
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CAddressBookDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CAddressBookDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ADDRESSBOOKDOC_H__9C1045EB_5317_48D5_BEAF_6CA7DAB1E37B__INCLUDED_)
