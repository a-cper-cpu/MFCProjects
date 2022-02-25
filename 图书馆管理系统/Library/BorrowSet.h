#if !defined(AFX_BORROWSET_H__633337AD_87BD_4784_A087_5545AA9A4C6C__INCLUDED_)
#define AFX_BORROWSET_H__633337AD_87BD_4784_A087_5545AA9A4C6C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// BorrowSet.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CBorrowSet recordset

class CBorrowSet : public CRecordset
{
public:
	CBorrowSet(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CBorrowSet)

// Field/Param Data
	//{{AFX_FIELD(CBorrowSet, CRecordset)
	CString	m_READER_ID;
	CString	m_BOOK_ID;
	CTime	m_BORROW_DATE;
	CString	m_B_CLERK_ID;
	long	m_ID;
	CString	m_ReaderName;
	//}}AFX_FIELD


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBorrowSet)
	public:
	virtual CString GetDefaultConnect();    // Default connection string
	virtual CString GetDefaultSQL();    // Default SQL for Recordset
	virtual void DoFieldExchange(CFieldExchange* pFX);  // RFX support
	//}}AFX_VIRTUAL

// Implementation
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BORROWSET_H__633337AD_87BD_4784_A087_5545AA9A4C6C__INCLUDED_)
