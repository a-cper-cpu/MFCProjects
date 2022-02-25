// TMSView.cpp : implementation of the CTMSView class
//

#include "stdafx.h"
#include "TMS.h"

#include "TMSDoc.h"
#include "TMSView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTMSView

IMPLEMENT_DYNCREATE(CTMSView, CView)

BEGIN_MESSAGE_MAP(CTMSView, CView)
	//{{AFX_MSG_MAP(CTMSView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTMSView construction/destruction

CTMSView::CTMSView()
{
	// TODO: add construction code here

}

CTMSView::~CTMSView()
{
}

BOOL CTMSView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CTMSView drawing

void CTMSView::OnDraw(CDC* pDC)
{
	CTMSDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CTMSView printing

BOOL CTMSView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CTMSView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CTMSView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CTMSView diagnostics

#ifdef _DEBUG
void CTMSView::AssertValid() const
{
	CView::AssertValid();
}

void CTMSView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CTMSDoc* CTMSView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTMSDoc)));
	return (CTMSDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CTMSView message handlers
