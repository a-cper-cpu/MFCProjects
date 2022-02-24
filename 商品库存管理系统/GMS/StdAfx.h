// stdafx.h : include file for standard system include files,
//  or project specific include files that are used frequently, but
//      are changed infrequently
//

#if !defined(AFX_STDAFX_H__020FEE60_ED2E_447C_ACDB_6E439C793266__INCLUDED_)
#define AFX_STDAFX_H__020FEE60_ED2E_447C_ACDB_6E439C793266__INCLUDED_

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
#endif // _AFX_NO_AFXCMN_SUPPORT

#import "C:\program files\common files\System\ado\msado15.dll" no_namespace \
rename("EOF","adoEOF") \
rename("LockTypeEnum","newLockTypeEnum")\
rename("DataTypeEnum","newDataTypeEnum")\
rename("FieldAttributeEnum","newFieldAttributeEnum")\
rename("EditModeEnum","newEditModeEnum")\
rename("RecordStatusEnum","newRecordStatusEnum")\
rename("ParameterDirectionEnum","newParameterDirectionEnum")
extern CString strAdminName;

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STDAFX_H__020FEE60_ED2E_447C_ACDB_6E439C793266__INCLUDED_)
