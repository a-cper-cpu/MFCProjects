// HMSDoc.cpp : implementation of the CHMSDoc class
//

#include "stdafx.h"
#include "HMS.h"

#include "HMSDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CHMSDoc

IMPLEMENT_DYNCREATE(CHMSDoc, CDocument)

BEGIN_MESSAGE_MAP(CHMSDoc, CDocument)
	//{{AFX_MSG_MAP(CHMSDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CHMSDoc construction/destruction

CHMSDoc::CHMSDoc()
{
	// TODO: add one-time construction code here

}

CHMSDoc::~CHMSDoc()
{
}

BOOL CHMSDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CHMSDoc serialization

void CHMSDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CHMSDoc diagnostics

#ifdef _DEBUG
void CHMSDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CHMSDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CHMSDoc commands
