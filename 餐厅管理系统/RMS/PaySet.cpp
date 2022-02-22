// PaySet.cpp : implementation file
//

#include "stdafx.h"
#include "RMS.h"
#include "PaySet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPaySet

IMPLEMENT_DYNAMIC(CPaySet, CRecordset)

CPaySet::CPaySet(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(CPaySet)
	m_Dish_code = _T("");
	m_Dish_name = _T("");
	m_Dish_kind = _T("");
	m_Dish_price = 0.0f;
	m_Dish_detail = _T("");
	m_Desk_code = _T("");
	m_Dish_code2 = _T("");
	m_Dish_num = 0;
	m_PayFor = 0;
	m_nFields = 10;
	//}}AFX_FIELD_INIT
	m_nDefaultType = snapshot;
}


CString CPaySet::GetDefaultConnect()
{
	return _T("ODBC;DSN=RMS");
}

CString CPaySet::GetDefaultSQL()
{
	return _T("[dish],[order]");
}

void CPaySet::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(CPaySet)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Text(pFX, _T("[dish].[Dish_code]"), m_Dish_code);
	RFX_Text(pFX, _T("[Dish_name]"), m_Dish_name);
	RFX_Text(pFX, _T("[Dish_kind]"), m_Dish_kind);
	RFX_Single(pFX, _T("[Dish_price]"), m_Dish_price);
	RFX_Text(pFX, _T("[Dish_detail]"), m_Dish_detail);
	RFX_Text(pFX, _T("[Desk_code]"), m_Desk_code);
	RFX_Text(pFX, _T("[order].[Dish_code]"), m_Dish_code2);
	RFX_Long(pFX, _T("[Dish_num]"), m_Dish_num);
	RFX_Date(pFX, _T("[AppendDate]"), m_AppendDate);
	RFX_Int(pFX, _T("[PayFor]"), m_PayFor);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// CPaySet diagnostics

#ifdef _DEBUG
void CPaySet::AssertValid() const
{
	CRecordset::AssertValid();
}

void CPaySet::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG
