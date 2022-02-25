#if !defined(AFX_BORROWDATASET_H__19C367C8_1A07_4EF4_A829_C85594AB65B0__INCLUDED_)
#define AFX_BORROWDATASET_H__19C367C8_1A07_4EF4_A829_C85594AB65B0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// BorrowDataSet.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CBorrowDataSet recordset

class CBorrowDataSet : public CRecordset
{
public:
	CBorrowDataSet(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CBorrowDataSet)

// Field/Param Data
	//{{AFX_FIELD(CBorrowDataSet, CRecordset)
	long	m_ID;
	CString	m_READER_ID;
	CString	m_BOOK_ID;
	CTime	m_BORROW_DATE;
	CString	m_B_CLERK_ID;
	
	//}}AFX_FIELD


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBorrowDataSet)
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

#endif // !defined(AFX_BORROWDATASET_H__19C367C8_1A07_4EF4_A829_C85594AB65B0__INCLUDED_)
