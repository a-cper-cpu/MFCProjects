// MainDlg.cpp : implementation file
//

#include "stdafx.h"
#include "GMS.h"
#include "MainDlg.h"
#include "GoodsDlg.h"
#include "ProviderDlg.h"
#include "InDlg.h"
#include "OutDlg.h"
#include "ViewDlg.h"
#include "GMSDlg.h"
#include "PasswdDlg.h"
#include "AlertDlg.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMainDlg dialog


CMainDlg::CMainDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMainDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMainDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CMainDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMainDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CMainDlg, CDialog)
	//{{AFX_MSG_MAP(CMainDlg)
	ON_BN_CLICKED(IDC_BUTTON_GOODSADD, OnButtonGoodsadd)
	ON_BN_CLICKED(IDC_BUTTON_PROVIDERADD, OnButtonProvideradd)
	ON_BN_CLICKED(IDC_BUTTON_GOODSIN, OnButtonGoodsin)
	ON_BN_CLICKED(IDC_BUTTON_GOODSOUT, OnButtonGoodsout)
	ON_BN_CLICKED(IDC_BUTTON_GOODS, OnButtonGoods)
	ON_BN_CLICKED(IDC_BUTTON_PROVIDER, OnButtonProvider)
	ON_BN_CLICKED(IDC_BUTTON_IN, OnButtonIn)
	ON_BN_CLICKED(IDC_BUTTON_OUT, OnButtonOut)
	ON_BN_CLICKED(IDC_BUTTON_ALERT, OnButtonAlert)
	ON_BN_CLICKED(IDC_BUTTON_ADMIN, OnButtonAdmin)
	ON_BN_CLICKED(IDC_BUTTON_LOG, OnButtonLog)
	ON_BN_CLICKED(IDC_BUTTON_HELP, OnButtonHelp)
	ON_BN_CLICKED(IDC_BUTTON_ABOUT, OnButtonAbout)
	ON_BN_CLICKED(IDC_BUTTON_EXIT, OnButtonExit)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMainDlg message handlers

void CMainDlg::OnButtonGoodsadd() 
{
	CGoodsDlg dlg;
	this->ShowWindow(SW_HIDE);
	dlg.DoModal();
	this->ShowWindow(SW_SHOW);
	// TODO: Add your control notification handler code here
	
}

void CMainDlg::OnButtonProvideradd() 
{
	CProviderDlg dlg;
	this->ShowWindow(SW_HIDE);
	dlg.DoModal();
	this->ShowWindow(SW_SHOW);
	// TODO: Add your control notification handler code here
	
}

void CMainDlg::OnButtonGoodsin() 
{
	CInDlg dlg;
	this->ShowWindow(SW_HIDE);
	dlg.DoModal();
	this->ShowWindow(SW_SHOW);
	// TODO: Add your control notification handler code here
	
}

void CMainDlg::OnButtonGoodsout() 
{
	COutDlg dlg;
	this->ShowWindow(SW_HIDE);
	dlg.DoModal();
	this->ShowWindow(SW_SHOW);
	// TODO: Add your control notification handler code here
	
}

void CMainDlg::OnButtonGoods() 
{
	CViewDlg dlg;
	this->ShowWindow(SW_HIDE);
	dlg.Init(1);
	dlg.DoModal();
	this->ShowWindow(SW_SHOW);

	// TODO: Add your control notification handler code here
	
}

void CMainDlg::OnButtonProvider() 
{
	CViewDlg dlg;
	this->ShowWindow(SW_HIDE);
	dlg.Init(2);
	dlg.DoModal();
	this->ShowWindow(SW_SHOW);

	// TODO: Add your control notification handler code here
	
}

void CMainDlg::OnButtonIn() 
{
	CViewDlg dlg;
	this->ShowWindow(SW_HIDE);
	dlg.Init(3);
	dlg.DoModal();
	this->ShowWindow(SW_SHOW);
	// TODO: Add your control notification handler code here
	
}

void CMainDlg::OnButtonOut() 
{
	CViewDlg dlg;
	this->ShowWindow(SW_HIDE);
	dlg.Init(3);
	dlg.DoModal();
	this->ShowWindow(SW_SHOW);
	// TODO: Add your control notification handler code here
	
}

void CMainDlg::OnButtonAlert() 
{
	CAlertDlg dlg;
	dlg.DoModal();
	// TODO: Add your control notification handler code here
	
}

void CMainDlg::OnButtonAdmin() 
{
	CPasswdDlg dlg;
	dlg.DoModal();
	// TODO: Add your control notification handler code here
	
}

void CMainDlg::OnButtonLog() 
{
	CViewDlg dlg;
	this->ShowWindow(SW_HIDE);
	dlg.Init(5);
	dlg.DoModal();
	this->ShowWindow(SW_SHOW);
	// TODO: Add your control notification handler code here
	
}

void CMainDlg::OnButtonHelp() 
{
	WinExec("notepad.exe GPS.HEP",SW_SHOW);
	// TODO: Add your control notification handler code here
	
}

void CMainDlg::OnButtonAbout() 
{
	CAboutDlg  dlg;
	dlg.DoModal();
	// TODO: Add your control notification handler code here
	
}

void CMainDlg::OnButtonExit() 
{
	OnOK();
	// TODO: Add your control notification handler code here
	
}
