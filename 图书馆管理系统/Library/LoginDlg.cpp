// LoginDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Library.h"
#include "LoginDlg.h"

#include "ClerkDataSet.h"

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
	m_strPassword = _T("");
	//}}AFX_DATA_INIT

}


void CLoginDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CLoginDlg)
	DDX_Text(pDX, IDC_LOGIN_NAME, m_strName);
	DDV_MaxChars(pDX, m_strName, 8);
	DDX_Text(pDX, IDC_LOGIN_PASSWORD, m_strPassword);
	DDV_MaxChars(pDX, m_strPassword, 8);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CLoginDlg, CDialog)
	//{{AFX_MSG_MAP(CLoginDlg)
	ON_BN_CLICKED(IDC_CONFIRM, OnConfirm)
	ON_BN_CLICKED(IDC_CANCEL, OnCancel)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLoginDlg message handlers

void CLoginDlg::OnConfirm() 
{
	// TODO: Add your control notification handler code here
	CClerkDataSet mrsDataSet;  /*声明记录集*/
	CString mSqlStr;

	UpdateData(TRUE);

	if (m_strName.IsEmpty())    /*判断用户名信息是否为空*/
	{
		AfxMessageBox("请输入用户名！");
		return;
	}

	mSqlStr = "SELECT * FROM CLERK WHERE NAME='";
	mSqlStr = mSqlStr + m_strName;
	mSqlStr = mSqlStr + "' AND PASSWORD='";
	mSqlStr = mSqlStr + m_strPassword;
	mSqlStr = mSqlStr + "'";


	if (!mrsDataSet.Open(AFX_DB_USE_DEFAULT_TYPE, mSqlStr))
	{
		AfxMessageBox("CLERK表打开失败！");
		return;
	}
	if (!mrsDataSet.IsEOF())
	{
		// Open all function for user
		CDialog::OnOK();
	}
	else
	{
		AfxMessageBox("登录失败！");
		return;
	}
	
	
}

void CLoginDlg::OnCancel() 
{
	// TODO: Add your control notification handler code here
	CDialog::OnCancel();	
}


