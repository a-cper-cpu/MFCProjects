// LoginDlg.cpp : implementation file
//

#include "stdafx.h"
#include "TMS.h"
#include "LoginDlg.h"
#include "MainFrm.h"
#include "TMSDoc.h"
#include "TMSView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CLoginDlg dialog


CLoginDlg::CLoginDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CLoginDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CLoginDlg)
	m_strName = _T("");
	m_strPasswd = _T("");
	//}}AFX_DATA_INIT
	m_Brush.CreateSolidBrush(RGB(0,100,100));
	IsLogin=false;
}


void CLoginDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CLoginDlg)
	DDX_Text(pDX, IDC_EDIT_LOGINNAME, m_strName);
	DDX_Text(pDX, IDC_EDIT_PASSWD, m_strPasswd);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CLoginDlg, CDialog)
	//{{AFX_MSG_MAP(CLoginDlg)
	ON_BN_CLICKED(IDC_BUTTON_OK, OnButtonOk)
	ON_BN_CLICKED(IDC_BUTTON_CANCEL, OnButtonCancel)
	ON_WM_CTLCOLOR()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLoginDlg message handlers

void CLoginDlg::OnButtonOk() 
{
	CString strSql;
	_variant_t strQuery;
	UpdateData(TRUE);

	if (m_strName.IsEmpty())    /*判断用户名信息是否为空*/
	{
		AfxMessageBox("请输入用户名!");
		return;
	}

	strQuery = "SELECT * FROM admin WHERE Admin_Name='"+m_strName+ "' AND Admin_Passwd='" + m_strPasswd+ "'";

	theApp.ADOExecute(theApp.m_pRs, strQuery);
    int iCount = theApp.m_pRs->GetRecordCount();
	if ( 0==iCount ) 
	{
		AfxMessageBox("用户名或密码错误!");
		m_strName="";
		m_strPasswd="";
		UpdateData(false);
		
	}
	else
	{
		strAdminName=m_strName;
		::Sleep(300);
		IsLogin=true;
		OnOK();	
	}

	// TODO: Add your control notification handler code here
	
}

void CLoginDlg::OnButtonCancel() 
{
	IsLogin=false;
	OnCancel();
	// TODO: Add your control notification handler code here
	
}

HBRUSH CLoginDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
	if(nCtlColor==CTLCOLOR_DLG)
		return (HBRUSH)m_Brush.GetSafeHandle();
	
	// TODO: Change any attributes of the DC here
	
	// TODO: Return a different brush if the default is not desired
	return hbr;
}
