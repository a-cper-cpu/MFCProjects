// BorrowSet.cpp : implementation file
//

#include "stdafx.h"
#include "Library.h"
#include "BorrowSet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CBorrowSet

IMPLEMENT_DYNAMIC(CBorrowSet, CRecordset)

CBorrowSet::CBorrowSet(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(CBorrowSet)
	m_READER_ID = _T("");
	m_BOOK_ID = _T("");
	m_B_CLERK_ID = _T("");
	m_ID = 0;
	m_ReaderName = _T("");
	m_nFields = 6;
	//}}AFX_FIELD_INIT
	m_nDefaultType = snapshot;
}


CString CBorrowSet::GetDefaultConnect()
{
	return _T("ODBC;DSN=library");
}

CString CBorrowSet::GetDefaultSQL()
{
	return _T("[BORROW],[READER]");
}

void CBorrowSet::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(CBorrowSet)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Text(pFX, _T("[BORROW].[READER_ID]"), m_READER_ID);
	RFX_Text(pFX, _T("[BOOK_ID]"), m_BOOK_ID);
	RFX_Date(pFX, _T("[BORROW_DATE]"), m_BORROW_DATE);
	RFX_Text(pFX, _T("[B_CLERK_ID]"), m_B_CLERK_ID);
	RFX_Long(pFX, _T("[ID]"), m_ID);
	RFX_Text(pFX, _T("[NAME]"), m_ReaderName);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// CBorrowSet diagnostics

#ifdef _DEBUG
void CBorrowSet::AssertValid() const
{
	CRecordset::AssertValid();
}

void CBorrowSet::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG
