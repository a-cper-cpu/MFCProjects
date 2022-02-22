// DishSet.cpp : implementation file
//

#include "stdafx.h"
#include "RMS.h"
#include "DishSet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDishSet

IMPLEMENT_DYNAMIC(CDishSet, CRecordset)

CDishSet::CDishSet(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(CDishSet)
	m_Dish_code = _T("");
	m_Dish_name = _T("");
	m_Dish_kind = _T("");
	m_Dish_price = 0.0f;
	m_Dish_detail = _T("");
	m_nFields = 5;
	//}}AFX_FIELD_INIT
	m_nDefaultType = snapshot;
}


CString CDishSet::GetDefaultConnect()
{
	return _T("ODBC;DSN=RMS");
}

CString CDishSet::GetDefaultSQL()
{
	return _T("[dish]");
}

void CDishSet::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(CDishSet)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Text(pFX, _T("[Dish_code]"), m_Dish_code);
	RFX_Text(pFX, _T("[Dish_name]"), m_Dish_name);
	RFX_Text(pFX, _T("[Dish_kind]"), m_Dish_kind);
	RFX_Single(pFX, _T("[Dish_price]"), m_Dish_price);
	RFX_Text(pFX, _T("[Dish_detail]"), m_Dish_detail);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// CDishSet diagnostics

#ifdef _DEBUG
void CDishSet::AssertValid() const
{
	CRecordset::AssertValid();
}

void CDishSet::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG
