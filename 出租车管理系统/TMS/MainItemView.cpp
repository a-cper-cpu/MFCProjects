// MainItemView.cpp : implementation file
//

#include "stdafx.h"
#include "TMS.h"
#include "MainItemView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMainItemView

IMPLEMENT_DYNCREATE(CMainItemView, CFormView)

CMainItemView::CMainItemView()
	: CFormView(CMainItemView::IDD)
{
	//{{AFX_DATA_INIT(CMainItemView)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	m_Brush.CreateSolidBrush(RGB(255,255,255));
}

CMainItemView::~CMainItemView()
{
}

void CMainItemView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMainItemView)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CMainItemView, CFormView)
	//{{AFX_MSG_MAP(CMainItemView)
	ON_WM_CTLCOLOR()
	ON_WM_CANCELMODE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMainItemView diagnostics

#ifdef _DEBUG
void CMainItemView::AssertValid() const
{
	CFormView::AssertValid();
}

void CMainItemView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMainItemView message handlers

HBRUSH CMainItemView::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
{
	HBRUSH hbr = CFormView::OnCtlColor(pDC, pWnd, nCtlColor);
	if(nCtlColor==CTLCOLOR_DLG)
		return (HBRUSH)m_Brush.GetSafeHandle();
	
	// TODO: Change any attributes of the DC here
	
	// TODO: Return a different brush if the default is not desired
	return hbr;
}

void CMainItemView::OnCancelMode() 
{
	CFormView::OnCancelMode();
	
	// TODO: Add your message handler code here
	
}
