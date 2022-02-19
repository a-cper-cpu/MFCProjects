// Person.cpp: implementation of the CPerson class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "AddressBook.h"
#include "Person.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
IMPLEMENT_SERIAL(CPerson,CObject,0)
CPerson::CPerson()
{
	//初始化人员信息(m_Name,m_Phone,m_Company,m_Email)
	m_Name="";    //姓名
	m_Phone="";   //电话
	m_Company=""; //公司
	m_Email="";   //Email

}

CPerson::~CPerson()
{

}
void CPerson::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{	
		ar<<m_Name<<m_Phone<<m_Company<<m_Email;
		// storing code
	}
	else
	{	// loading code
		ar>>m_Name>>m_Phone>>m_Company>>m_Email;
	}
}
