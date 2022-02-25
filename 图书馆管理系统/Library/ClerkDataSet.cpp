// ClerkDataSet.cpp : implementation file
//

#include "stdafx.h"
#include "Library.h"
#include "ClerkDataSet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CClerkDataSet

IMPLEMENT_DYNAMIC(CClerkDataSet, CRecordset)

CClerkDataSet::CClerkDataSet(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(CClerkDataSet)
	m_NAME = _T("");
	m_PASSWORD = _T("");
	m_nFields = 2;
	//}}AFX_FIELD_INIT
	m_nDefaultType = snapshot;
}


CString CClerkDataSet::GetDefaultConnect()
{
	return _T("ODBC;DSN=Library");
}

CString CClerkDataSet::GetDefaultSQL()
{
	return _T("[CLERK]");
}

void CClerkDataSet::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(CClerkDataSet)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Text(pFX, _T("[NAME]"), m_NAME);
	RFX_Text(pFX, _T("[PASSWORD]"), m_PASSWORD);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// CClerkDataSet diagnostics

#ifdef _DEBUG
void CClerkDataSet::AssertValid() const
{
	CRecordset::AssertValid();
}

void CClerkDataSet::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG
