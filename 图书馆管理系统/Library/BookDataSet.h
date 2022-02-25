#if !defined(AFX_BOOKDATASET_H__3F31D4F5_7B1A_4F48_886E_0BC189AC4148__INCLUDED_)
#define AFX_BOOKDATASET_H__3F31D4F5_7B1A_4F48_886E_0BC189AC4148__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// BookDataSet.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CBookDataSet recordset

class CBookDataSet : public CRecordset
{
public:
	CBookDataSet(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CBookDataSet)

// Field/Param Data
	//{{AFX_FIELD(CBookDataSet, CRecordset)
	CString	m_BOOK_ID;
	CString	m_BOOK_NAME;
	CString	m_AUTHOR;
	CString	m_PRESS;
	CString	m_PRESS_DATE;
	CString	m_FLAG_BORROW;
	//}}AFX_FIELD


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBookDataSet)
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

#endif // !defined(AFX_BOOKDATASET_H__3F31D4F5_7B1A_4F48_886E_0BC189AC4148__INCLUDED_)
