// PageWelcome.cpp : implementation file
//

#include "stdafx.h"
#include "UGMS.h"
#include "PageWelcome.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPageWelcome dialog


CPageWelcome::CPageWelcome(CWnd* pParent /*=NULL*/)
	: CDialog(CPageWelcome::IDD, pParent)
{
	//{{AFX_DATA_INIT(CPageWelcome)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CPageWelcome::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPageWelcome)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CPageWelcome, CDialog)
	//{{AFX_MSG_MAP(CPageWelcome)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPageWelcome message handlers
