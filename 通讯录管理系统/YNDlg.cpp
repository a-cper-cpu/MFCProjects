// YNDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Page1.h"
#include "YNDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CYNDlg dialog


CYNDlg::CYNDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CYNDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CYNDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CYNDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CYNDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CYNDlg, CDialog)
	//{{AFX_MSG_MAP(CYNDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CYNDlg message handlers

void CYNDlg::OnOK() 
{
	// TODO: Add extra validation here
	k=1;
	CDialog::OnOK();
}

void CYNDlg::OnCancel() 
{
	// TODO: Add extra cleanup here
	k=0;
	CDialog::OnCancel();
}
