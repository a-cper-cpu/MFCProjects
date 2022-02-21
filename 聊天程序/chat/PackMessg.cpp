// PackMessg.cpp: implementation of the CPackMessg class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "chat.h"
#include "PackMessg.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CPackMessg::CPackMessg()
{
	Init();
}
void CPackMessg::Init()
{
	m_strText = _T("");
}

/////////////////////////////////////////////////////////////////////////////
// CMsg serialization

void CPackMessg::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		ar << m_strText;
	}
	else
	{
		ar >> m_strText;
	}
}