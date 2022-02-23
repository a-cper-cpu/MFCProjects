// HMSView.cpp : implementation of the CHMSView class
//

#include "stdafx.h"
#include "HMS.h"

#include "HMSDoc.h"
#include "HMSView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CHMSView

IMPLEMENT_DYNCREATE(CHMSView, CView)

BEGIN_MESSAGE_MAP(CHMSView, CView)
	//{{AFX_MSG_MAP(CHMSView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CHMSView construction/destruction

CHMSView::CHMSView()
{
	// TODO: add construction code here

}

CHMSView::~CHMSView()
{
}

BOOL CHMSView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CHMSView drawing

void CHMSView::OnDraw(CDC* pDC)
{
	CHMSDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CHMSView printing

BOOL CHMSView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CHMSView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CHMSView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CHMSView diagnostics

#ifdef _DEBUG
void CHMSView::AssertValid() const
{
	CView::AssertValid();
}

void CHMSView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CHMSDoc* CHMSView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CHMSDoc)));
	return (CHMSDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CHMSView message handlers




