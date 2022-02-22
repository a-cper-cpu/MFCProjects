// OrderSet.cpp : implementation file
//

#include "stdafx.h"
#include "RMS.h"
#include "OrderSet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// COrderSet

IMPLEMENT_DYNAMIC(COrderSet, CRecordset)

COrderSet::COrderSet(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(COrderSet)
	m_Desk_code = _T("");
	m_Dish_code = _T("");
	m_Dish_num = 0;
	m_PayFor = 0;
	m_nFields = 5;
	//}}AFX_FIELD_INIT
	m_nDefaultType = snapshot;
}


CString COrderSet::GetDefaultConnect()
{
	return _T("ODBC;DSN=RMS");
}

CString COrderSet::GetDefaultSQL()
{
	return _T("[order]");
}

void COrderSet::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(COrderSet)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Text(pFX, _T("[Desk_code]"), m_Desk_code);
	RFX_Text(pFX, _T("[Dish_code]"), m_Dish_code);
	RFX_Long(pFX, _T("[Dish_num]"), m_Dish_num);
	RFX_Date(pFX, _T("[AppendDate]"), m_AppendDate);
	RFX_Int(pFX, _T("[PayFor]"), m_PayFor);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// COrderSet diagnostics

#ifdef _DEBUG
void COrderSet::AssertValid() const
{
	CRecordset::AssertValid();
}

void COrderSet::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG
