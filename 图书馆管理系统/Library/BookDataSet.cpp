// BookDataSet.cpp : implementation file
//

#include "stdafx.h"
#include "Library.h"
#include "BookDataSet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CBookDataSet

IMPLEMENT_DYNAMIC(CBookDataSet, CRecordset)

CBookDataSet::CBookDataSet(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(CBookDataSet)
	m_BOOK_ID = _T("");
	m_BOOK_NAME = _T("");
	m_AUTHOR = _T("");
	m_PRESS = _T("");
	m_FLAG_BORROW = _T("");
	m_nFields = 6;
	//}}AFX_FIELD_INIT
	m_nDefaultType = snapshot;
}


CString CBookDataSet::GetDefaultConnect()
{
	return _T("ODBC;DSN=Library");
}

CString CBookDataSet::GetDefaultSQL()
{
	return _T("[BOOK]");
}

void CBookDataSet::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(CBookDataSet)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Text(pFX, _T("[BOOK_ID]"), m_BOOK_ID);
	RFX_Text(pFX, _T("[BOOK_NAME]"), m_BOOK_NAME);
	RFX_Text(pFX, _T("[AUTHOR]"), m_AUTHOR);
	RFX_Text(pFX, _T("[PRESS]"), m_PRESS);
	RFX_Text(pFX, _T("[PRESS_DATE]"), m_PRESS_DATE);
	RFX_Text(pFX, _T("[FLAG_BORROW]"), m_FLAG_BORROW);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// CBookDataSet diagnostics

#ifdef _DEBUG
void CBookDataSet::AssertValid() const
{
	CRecordset::AssertValid();
}

void CBookDataSet::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG
