// AddressListView.cpp : implementation of the CAddressListView class
//

/*
	×÷Õß£ºÕÅ³¬¸Õ

*/

#include "stdafx.h"
#include "AddressList.h"

#include "AddressListDoc.h"
#include "AddressListView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAddressListView

IMPLEMENT_DYNCREATE(CAddressListView, CView)

BEGIN_MESSAGE_MAP(CAddressListView, CView)
	//{{AFX_MSG_MAP(CAddressListView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAddressListView construction/destruction

CAddressListView::CAddressListView()
{
	// TODO: add construction code here

}

CAddressListView::~CAddressListView()
{
}

BOOL CAddressListView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CAddressListView drawing

void CAddressListView::OnDraw(CDC* pDC)
{
	CAddressListDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CAddressListView printing

BOOL CAddressListView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CAddressListView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CAddressListView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CAddressListView diagnostics

#ifdef _DEBUG
void CAddressListView::AssertValid() const
{
	CView::AssertValid();
}

void CAddressListView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CAddressListDoc* CAddressListView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CAddressListDoc)));
	return (CAddressListDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CAddressListView message handlers
