// RoomTypeView.cpp : implementation file
//

#include "stdafx.h"
#include "HMS.h"
#include "RoomTypeView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CRoomTypeView

IMPLEMENT_DYNCREATE(CRoomTypeView, CFormView)

CRoomTypeView::CRoomTypeView()
	: CFormView(CRoomTypeView::IDD)
{
	//{{AFX_DATA_INIT(CRoomTypeView)
	m_strPrice = _T("");
	m_strName = _T("");
	m_iTV = -1;
	m_iTOILET = -1;
	m_iTEL = -1;
	m_iAir = -1;
	m_strID = _T("");
	m_strBedNO = _T("");
	//}}AFX_DATA_INIT
}

CRoomTypeView::~CRoomTypeView()
{
}

void CRoomTypeView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CRoomTypeView)
	DDX_Text(pDX, IDC_ROOMTYPE_PRICE, m_strPrice);
	DDX_Text(pDX, IDC_ROOMTYPE_NAME, m_strName);
	DDX_CBIndex(pDX, IDC_ROOMTYPE_ISTV, m_iTV);
	DDX_CBIndex(pDX, IDC_ROOMTYPE_ISTOILET, m_iTOILET);
	DDX_CBIndex(pDX, IDC_ROOMTYPE_ISTEL, m_iTEL);
	DDX_CBIndex(pDX, IDC_ROOMTYPE_ISAIRCON, m_iAir);
	DDX_Text(pDX, IDC_ROOMTYPE_ID, m_strID);
	DDX_Text(pDX, IDC_ROOMTYPE_BEDNO, m_strBedNO);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CRoomTypeView, CFormView)
	//{{AFX_MSG_MAP(CRoomTypeView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRoomTypeView diagnostics

#ifdef _DEBUG
void CRoomTypeView::AssertValid() const
{
	CFormView::AssertValid();
}

void CRoomTypeView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CRoomTypeView message handlers

void CRoomTypeView::OnInitialUpdate() 
{
	FillRoomType();
	CFormView::OnInitialUpdate();	
	// TODO: Add your specialized code here and/or call the base class
	
}

void CRoomTypeView::OnDraw(CDC* pDC) 
{
	CRect rectClient;
	CBrush brushBkColor;
	GetClientRect(rectClient);
	brushBkColor.CreateSolidBrush(RGB(255,255,255));
	pDC->DPtoLP(rectClient);
	pDC->FillRect(rectClient,&brushBkColor);
	// TODO: Add your specialized code here and/or call the base class
	
}

void CRoomTypeView::FillRoomType()
{
	CString strTypeName;
	CTreeCtrl* pCtrl = &m_pLeftView->GetTreeCtrl();
	strTypeName=pCtrl->GetItemText(m_pLeftView->m_hHitItem);

	
	_variant_t Holder, strQuery;
    strQuery= "select * from RoomType where TypeName='"+strTypeName+"'";
	theApp.ADOExecute(theApp.m_pRs, strQuery);
    int iCount = theApp.m_pRs->GetRecordCount();
	if ( 0==iCount ) return;
	theApp.m_pRs->MoveFirst();

	Holder = theApp.m_pRs->GetCollect("TypeID");
	m_strID= Holder.vt==VT_NULL?"":(char*)(_bstr_t)Holder;

	Holder = theApp.m_pRs->GetCollect("TypeName");
	m_strName= Holder.vt==VT_NULL?"":(char*)(_bstr_t)Holder;

	Holder = theApp.m_pRs->GetCollect("BedNum");
	m_strBedNO.Format("%d", Holder.vt==VT_NULL?0:Holder.iVal);

	Holder = theApp.m_pRs->GetCollect("Price");
	m_strPrice.Format("%0.2f", Holder.vt==VT_NULL?0.0:Holder.dblVal);

	Holder = theApp.m_pRs->GetCollect("HavAir");
	m_iAir=Holder.vt==VT_NULL?0:Holder.iVal;

	Holder = theApp.m_pRs->GetCollect("HavTel");
	m_iTEL=Holder.vt==VT_NULL?0:Holder.iVal;

	Holder = theApp.m_pRs->GetCollect("HavTV");
	m_iTV=Holder.vt==VT_NULL?0:Holder.iVal;

	Holder = theApp.m_pRs->GetCollect("HavToi");
	m_iTOILET=Holder.vt==VT_NULL?0:Holder.iVal;


}
