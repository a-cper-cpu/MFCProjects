// PasswdDlg.cpp : implementation file
//

#include "stdafx.h"
#include "GMS.h"
#include "PasswdDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPasswdDlg dialog


CPasswdDlg::CPasswdDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CPasswdDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CPasswdDlg)
	m_strPassWd1 = _T("");
	m_strPassWd2 = _T("");
	//}}AFX_DATA_INIT
}


void CPasswdDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPasswdDlg)
	DDX_Text(pDX, IDC_EDIT_PASSWD1, m_strPassWd1);
	DDX_Text(pDX, IDC_EDIT_PASSWD2, m_strPassWd2);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CPasswdDlg, CDialog)
	//{{AFX_MSG_MAP(CPasswdDlg)
	ON_BN_CLICKED(IDC_BUTTON_OK, OnButtonOk)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPasswdDlg message handlers



void CPasswdDlg::OnButtonOk() 
{
	UpdateData();
	if(m_strPassWd1!=m_strPassWd2)
	{
		AfxMessageBox("两次输入不一致!");
		return;
	}

	CString strSql;

	strSql.Format("UPDATE admin SET Admin_passwd='%s' WHERE Admin_name='%s'",m_strPassWd1,strAdminName);
	// TODO: Add your control notification handler code here
	_variant_t  vtQuery(strSql);  
	if(theApp.ADOExecute(theApp.m_pRs, vtQuery))
	{
		AfxMessageBox("修改成功!");

		theApp.m_log.AddLog("修改密码");
	}
	else
	{
		AfxMessageBox("修改失败");

	}
	OnOK();
	// TODO: Add your control notification handler code here
	
}
