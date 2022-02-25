// ReaderDataSet.cpp : implementation file
//

#include "stdafx.h"
#include "Library.h"
#include "ReaderDataSet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CReaderDataSet

IMPLEMENT_DYNAMIC(CReaderDataSet, CRecordset)

CReaderDataSet::CReaderDataSet(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(CReaderDataSet)
	m_READER_ID = _T("");
	m_NAME = _T("");
	m_IDCARD = _T("");
	m_MAXNUM_CAN_BORROW = 0;
	m_FLAG_BORROW = _T("");
	m_nFields = 5;
	//}}AFX_FIELD_INIT
	m_nDefaultType = snapshot;
}


CString CReaderDataSet::GetDefaultConnect()
{
	return _T("ODBC;DSN=Library");
}

CString CReaderDataSet::GetDefaultSQL()
{
	return _T("[READER]");
}

void CReaderDataSet::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(CReaderDataSet)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Text(pFX, _T("[READER_ID]"), m_READER_ID);
	RFX_Text(pFX, _T("[NAME]"), m_NAME);
	RFX_Text(pFX, _T("[IDCARD]"), m_IDCARD);
	RFX_Int(pFX, _T("[MAXNUM_CAN_BORROW]"), m_MAXNUM_CAN_BORROW);
	RFX_Text(pFX, _T("[FLAG_BORROW]"), m_FLAG_BORROW);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// CReaderDataSet diagnostics

#ifdef _DEBUG
void CReaderDataSet::AssertValid() const
{
	CRecordset::AssertValid();
}

void CReaderDataSet::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG
