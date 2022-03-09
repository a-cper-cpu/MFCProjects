// QueryDlg.cpp : implementation file
//

/*
	作者：张超刚

*/

#include "stdafx.h"
#include "AddressList.h"
#include "QueryDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CQueryDlg dialog


CQueryDlg::CQueryDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CQueryDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CQueryDlg)
	m_strWhereValue = _T("");
	//}}AFX_DATA_INIT
}


void CQueryDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CQueryDlg)
	DDX_Text(pDX, IDC_FIELD_EDIT, m_strWhereValue);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CQueryDlg, CDialog)
	//{{AFX_MSG_MAP(CQueryDlg)
	ON_BN_CLICKED(IDC_REMOVE_SQL, OnRemoveSql)
	ON_BN_CLICKED(IDC_ADD_SQL, OnAddSql)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CQueryDlg message handlers

BOOL CQueryDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	//初始化组合框一
	char chField[9][10]={"姓名","工作单位","移动电话","备注",
	"单位地址","办公电话","家庭住址","家庭电话","电子邮件"};
	CComboBox* pCombox=(CComboBox*)GetDlgItem(IDC_FIELD_COMBO);
	for(int i=0;i<9;i++)
	{
		pCombox->AddString(chField[i]);
	}
	pCombox->SetCurSel(0);
	//初始化组合框二
	pCombox=(CComboBox*)GetDlgItem(IDC_RELATION_COMBO);
	pCombox->AddString("=");
	pCombox->AddString("like");
	pCombox->SetCurSel(0);
	//查询语句
	m_strSql="";
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CQueryDlg::OnRemoveSql() 
{
	// TODO: Add your control notification handler code here
	int iSel=-1;	
	CListBox* pListBox=(CListBox*)GetDlgItem(IDC_SQL_LIST);
	iSel=pListBox->GetCurSel();
    if(iSel<0)
	{
		AfxMessageBox("请先选择SQL语句:)");
	}
	//删除所选查询语句
	pListBox->DeleteString(iSel);
}

void CQueryDlg::OnAddSql() 
{
	// TODO: Add your control notification handler code here
	CString strField,strRelation,strWhereValue,strSQL; 	
	CComboBox* pCombox=(CComboBox*)GetDlgItem(IDC_FIELD_COMBO);
    pCombox->GetLBText(pCombox->GetCurSel(),strField);
    pCombox=(CComboBox*)GetDlgItem(IDC_RELATION_COMBO);
	pCombox->GetLBText(pCombox->GetCurSel(),strRelation);	
	//获取条件值
	CEdit* pEdit=(CEdit*)GetDlgItem(IDC_FIELD_EDIT);
	pEdit->GetWindowText(strWhereValue);
	//必须填写查询条件值
	if(!strWhereValue.Compare("''")||strWhereValue.IsEmpty())
	{
		AfxMessageBox("请检查条件字段值:)");
		return;
	}
    //针对"="和"like"生成单个查询语句
	if(pCombox->GetCurSel()==0)
	{
		//需要加上单引号
		strSQL.Format("'%s'",strWhereValue);
		strSQL=strField+strRelation+strSQL;
	}
	else
	{
		//设置百分号变量用于设置like查询(模糊查询)
		char chTem='%';
		strSQL.Format("'%c%s%c'",chTem,strWhereValue,chTem);
		strSQL=strField+" "+strRelation+" "+strSQL;
	}
	CListBox* pListBox=(CListBox*)GetDlgItem(IDC_SQL_LIST);
	//将生成的单个查询语句添加到列表框
	pListBox->AddString(strSQL);

}

CString& CQueryDlg::GetSQL()
{	
	CListBox* pListBox=(CListBox*)GetDlgItem(IDC_SQL_LIST);
	int iSql=0;
	CString strText,strTem;
	//获取总的条件数
	iSql=pListBox->GetCount();
	for(int i=0;i<iSql;i++)
	{
		if(i<iSql-1)
		{
			pListBox->GetText(i,strTem);
			strText.Format("%s and ",strTem);
			m_strSql=m_strSql+strText;
		}
		else
		{
			pListBox->GetText(i,strTem);
			m_strSql=m_strSql+strTem;
		}
	}
	return m_strSql;
}

void CQueryDlg::OnOK() 
{
	// TODO: Add extra validation here
	//获取最终的查询语句
	GetSQL();
	CDialog::OnOK();
}
