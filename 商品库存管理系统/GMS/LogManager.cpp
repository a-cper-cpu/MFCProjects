// LogManager.cpp: implementation of the CLogManager class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "GMS.h"
#include "LogManager.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CLogManager::CLogManager()
{

}

CLogManager::~CLogManager()
{

}

bool CLogManager::AddLog(LPCSTR op)
{
	CTime tm = CTime::GetCurrentTime();
	CString strSql;

	strSql.Format("INSERT INTO log (Admin_name,do_what,do_date) VALUES('%s','%s','%d-%d-%d %d:%d:%d')",
		strAdminName, op, 
		tm.GetYear(), tm.GetMonth(), tm.GetDay(),
		tm.GetHour(), tm.GetMinute(), tm.GetSecond());
	_variant_t  vtQuery(strSql);  
	return theApp.ADOExecute(theApp.m_pRs, vtQuery);


}
