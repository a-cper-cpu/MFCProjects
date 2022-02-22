// DeskSet.cpp : implementation file
//

#include "stdafx.h"
#include "RMS.h"
#include "DeskSet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDeskSet

IMPLEMENT_DYNAMIC(CDeskSet, CRecordset)

CDeskSet::CDeskSet(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(CDeskSet)
	m_Desk_code = _T("");
	m_Desk_num = 0;
	m_Desk_detail = _T("");
	m_Desk_full = 0;
	m_nFields = 4;
	//}}AFX_FIELD_INIT
	m_nDefaultType = snapshot;
}


CString CDeskSet::GetDefaultConnect()
{
	return _T("ODBC;DSN=RMS");
}

CString CDeskSet::GetDefaultSQL()
{
	return _T("[desk]");
}

void CDeskSet::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(CDeskSet)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Text(pFX, _T("[Desk_code]"), m_Desk_code);
	RFX_Int(pFX, _T("[Desk_num]"), m_Desk_num);
	RFX_Text(pFX, _T("[Desk_detail]"), m_Desk_detail);
	RFX_Int(pFX, _T("[Desk_full]"), m_Desk_full);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// CDeskSet diagnostics

#ifdef _DEBUG
void CDeskSet::AssertValid() const
{
	CRecordset::AssertValid();
}

void CDeskSet::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG
