// LogManager.h: interface for the CLogManager class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_LOGMANAGER_H__5E4CCBA7_1F44_4589_9506_772A63A9E92A__INCLUDED_)
#define AFX_LOGMANAGER_H__5E4CCBA7_1F44_4589_9506_772A63A9E92A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CLogManager  
{
public:
	bool AddLog(LPCSTR op);
	CLogManager();
	virtual ~CLogManager();

};

#endif // !defined(AFX_LOGMANAGER_H__5E4CCBA7_1F44_4589_9506_772A63A9E92A__INCLUDED_)
