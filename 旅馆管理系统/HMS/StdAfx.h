// stdafx.h : include file for standard system include files,
//  or project specific include files that are used frequently, but
//      are changed infrequently
//

#if !defined(AFX_STDAFX_H__9D7C7A35_189D_4EB9_94F6_12F6797E034B__INCLUDED_)
#define AFX_STDAFX_H__9D7C7A35_189D_4EB9_94F6_12F6797E034B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define VC_EXTRALEAN		// Exclude rarely-used stuff from Windows headers

#include <afxwin.h>         // MFC core and standard components
#include <afxext.h>         // MFC extensions
#include <afxdisp.h>        // MFC Automation classes
#include <afxdtctl.h>		// MFC support for Internet Explorer 4 Common Controls
#ifndef _AFX_NO_AFXCMN_SUPPORT
#include <afxcmn.h>			// MFC support for Windows Common Controls
#include <afxcview.h>
#include "LeftTreeView.h"
#endif // _AFX_NO_AFXCMN_SUPPORT


#import "C:\program files\common files\System\ado\msado15.dll" no_namespace \
rename("EOF","EndOfFile") \
rename("LockTypeEnum","newLockTypeEnum")\
rename("DataTypeEnum","newDataTypeEnum")\
rename("FieldAttributeEnum","newFieldAttributeEnum")\
rename("EditModeEnum","newEditModeEnum")\
rename("RecordStatusEnum","newRecordStatusEnum")\
rename("ParameterDirectionEnum","newParameterDirectionEnum")

typedef struct stCustomer
{
	CString	strCID;
	CString	strCName;
	CString	strCOff;
	CString	strCTel;
	int iCSex;
	CString	strCAge;

}stCustomer;

extern stCustomer selCustomer;

extern int operation;

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STDAFX_H__9D7C7A35_189D_4EB9_94F6_12F6797E034B__INCLUDED_)
