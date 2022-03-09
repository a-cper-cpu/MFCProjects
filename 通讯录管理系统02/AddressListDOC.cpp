// AddressListDoc.cpp : implementation of the CAddressListDoc class
//

/*
	×÷Õß£ºÕÅ³¬¸Õ

*/

#include "stdafx.h"
#include "AddressList.h"

#include "AddressListDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAddressListDoc

IMPLEMENT_DYNCREATE(CAddressListDoc, CDocument)

BEGIN_MESSAGE_MAP(CAddressListDoc, CDocument)
	//{{AFX_MSG_MAP(CAddressListDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAddressListDoc construction/destruction

CAddressListDoc::CAddressListDoc()
{
	// TODO: add one-time construction code here

}

CAddressListDoc::~CAddressListDoc()
{
}

BOOL CAddressListDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CAddressListDoc serialization

void CAddressListDoc::Serialize(CArchive& ar)
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
// CAddressListDoc diagnostics

#ifdef _DEBUG
void CAddressListDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CAddressListDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CAddressListDoc commands
