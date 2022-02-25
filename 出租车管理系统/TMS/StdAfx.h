// stdafx.h : include file for standard system include files,
//  or project specific include files that are used frequently, but
//      are changed infrequently
//

#if !defined(AFX_STDAFX_H__808BB726_1AA0_4653_8EC2_3A2391CB62B3__INCLUDED_)
#define AFX_STDAFX_H__808BB726_1AA0_4653_8EC2_3A2391CB62B3__INCLUDED_

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
#include <afxtempl.h>
#include "LeftTreeView.h"
#endif // _AFX_NO_AFXCMN_SUPPORT

#import "C:\program files\common files\System\ado\msado15.dll" no_namespace \
rename("EOF","adoEOF") 


extern CLeftTreeView* m_pLeftView;	
extern int SelItemType; 

typedef struct stCar
{
	CString	Car_NO;
	CString	Car_Kind;
	CString	Car_Color;
	CString	Car_EngineNO;
	CString	Car_ClassisNO;
	CString	Car_MeterNO;
}stCar;
typedef struct stDriver
{
	CString strNO;
	CString strName;
	CString strSex;
	CString strID;
	CString strAddress;
	CTime   tmBookDate;
	CString strCarKind;
	CString strPhone;

}stDriver;
typedef struct stCarDriver
{
	CString CarNO;
	CString DriverNO;
	int IsWork;
}stCarDriver;
typedef struct stCarFee
{
	CString CarNO;
	CString FeeNO;
	CTime tmBegin;
	CTime tmEnd;
}stCarFee;
typedef struct stDriverLaw
{
	CString DriverNO;
	CString LawNO;
	CString Address;
	CTime date;
	int TreatState;
	CString Memo;
}stDriverLaw;
typedef struct stDriverAward
{
	CString DriverNO;
	CString AwardNO;
	CString Content;
	CString Memo;
}stDriverAward;
typedef struct stFee
{
	CString FeeNO;
	CString FeeName;
	CString FeeDepartment;
	CString FeeMoney;

}stFee;
typedef struct stLaw
{
	CString LawNO;
	CString LawName;
	CString LawDepartment;
	CString LawMoney;
	CString LawPoint;
	int iIsBook;

}stLaw;
extern stCar selCar;
extern stDriver selDriver;
extern stCarDriver selCarDriver;
extern stCarFee selCarFee;
extern stDriverLaw selDriverLaw;
extern stDriverAward selDriverAward;
extern stFee selFee;
extern stLaw selLaw;
extern int operation;  //1.ADD 2.Modify 3.Delete
extern CString strAdminName;



//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STDAFX_H__808BB726_1AA0_4653_8EC2_3A2391CB62B3__INCLUDED_)
