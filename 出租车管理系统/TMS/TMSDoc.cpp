// TMSDoc.cpp : implementation of the CTMSDoc class
//

#include "stdafx.h"
#include "TMS.h"

#include "TMSDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTMSDoc

IMPLEMENT_DYNCREATE(CTMSDoc, CDocument)

BEGIN_MESSAGE_MAP(CTMSDoc, CDocument)
	//{{AFX_MSG_MAP(CTMSDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTMSDoc construction/destruction

CTMSDoc::CTMSDoc()
{
	// TODO: add one-time construction code here

}

CTMSDoc::~CTMSDoc()
{
}

BOOL CTMSDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CTMSDoc serialization

void CTMSDoc::Serialize(CArchive& ar)
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
// CTMSDoc diagnostics

#ifdef _DEBUG
void CTMSDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CTMSDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CTMSDoc commands
