// AddressBookDoc.cpp : implementation of the CAddressBookDoc class
//

#include "stdafx.h"
#include "AddressBook.h"
#include "Person.h"  //ע��,������ͷ�ļ�!
#include "AddressBookDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAddressBookDoc

IMPLEMENT_DYNCREATE(CAddressBookDoc, CDocument)

BEGIN_MESSAGE_MAP(CAddressBookDoc, CDocument)
	//{{AFX_MSG_MAP(CAddressBookDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAddressBookDoc construction/destruction

CAddressBookDoc::CAddressBookDoc()
{
	// TODO: add one-time construction code here

}

CAddressBookDoc::~CAddressBookDoc()
{
}

BOOL CAddressBookDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;
		// ��ʼ���ĵ����Ա
	CPerson *pDoc=new CPerson();
	pDoc->m_Name="";
	pDoc->m_Company="";
	pDoc->m_Email="";
	pDoc->m_Phone="";
	m_PersonList.AddHead(pDoc);


	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CAddressBookDoc serialization

void CAddressBookDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
	m_PersonList.Serialize(ar);

}

/////////////////////////////////////////////////////////////////////////////
// CAddressBookDoc diagnostics

#ifdef _DEBUG
void CAddressBookDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CAddressBookDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CAddressBookDoc commands

void CAddressBookDoc::DeleteContents() 
{
	// TODO: Add your specialized code here and/or call the base class
	while(!m_PersonList.IsEmpty())
	{//ѭ��ɾ����ǰ�Ľ��,ֱ��ɾ��Ϊֹ
		delete m_PersonList.RemoveHead();
	}	
	CDocument::DeleteContents();
}
