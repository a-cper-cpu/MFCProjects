// BorrowDataSet.cpp : implementation file
//

#include "stdafx.h"
#include "Library.h"
#include "BorrowDataSet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CBorrowDataSet

IMPLEMENT_DYNAMIC(CBorrowDataSet, CRecordset)

CBorrowDataSet::CBorrowDataSet(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(CBorrowDataSet)
	m_ID = 0;
	m_READER_ID = _T("");
	m_BOOK_ID = _T("");
	m_B_CLERK_ID = _T("");	
	m_nFields = 5;
	//}}AFX_FIELD_INIT
	m_nDefaultType = snapshot;
}


CString CBorrowDataSet::GetDefaultConnect()
{
	return _T("ODBC;DSN=Library");
}

CString CBorrowDataSet::GetDefaultSQL()
{
	return _T("[BORROW]");
}

void CBorrowDataSet::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(CBorrowDataSet)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Long(pFX, _T("[ID]"), m_ID);
	RFX_Text(pFX, _T("[READER_ID]"), m_READER_ID);
	RFX_Text(pFX, _T("[BOOK_ID]"), m_BOOK_ID);
	RFX_Date(pFX, _T("[BORROW_DATE]"), m_BORROW_DATE);
	RFX_Text(pFX, _T("[B_CLERK_ID]"), m_B_CLERK_ID);
	
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// CBorrowDataSet diagnostics

#ifdef _DEBUG
void CBorrowDataSet::AssertValid() const
{
	CRecordset::AssertValid();
}

void CBorrowDataSet::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG
