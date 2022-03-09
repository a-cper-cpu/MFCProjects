// QueryDlg.cpp : implementation file
//

/*
	���ߣ��ų���

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
	//��ʼ����Ͽ�һ
	char chField[9][10]={"����","������λ","�ƶ��绰","��ע",
	"��λ��ַ","�칫�绰","��ͥסַ","��ͥ�绰","�����ʼ�"};
	CComboBox* pCombox=(CComboBox*)GetDlgItem(IDC_FIELD_COMBO);
	for(int i=0;i<9;i++)
	{
		pCombox->AddString(chField[i]);
	}
	pCombox->SetCurSel(0);
	//��ʼ����Ͽ��
	pCombox=(CComboBox*)GetDlgItem(IDC_RELATION_COMBO);
	pCombox->AddString("=");
	pCombox->AddString("like");
	pCombox->SetCurSel(0);
	//��ѯ���
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
		AfxMessageBox("����ѡ��SQL���:)");
	}
	//ɾ����ѡ��ѯ���
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
	//��ȡ����ֵ
	CEdit* pEdit=(CEdit*)GetDlgItem(IDC_FIELD_EDIT);
	pEdit->GetWindowText(strWhereValue);
	//������д��ѯ����ֵ
	if(!strWhereValue.Compare("''")||strWhereValue.IsEmpty())
	{
		AfxMessageBox("���������ֶ�ֵ:)");
		return;
	}
    //���"="��"like"���ɵ�����ѯ���
	if(pCombox->GetCurSel()==0)
	{
		//��Ҫ���ϵ�����
		strSQL.Format("'%s'",strWhereValue);
		strSQL=strField+strRelation+strSQL;
	}
	else
	{
		//���ðٷֺű�����������like��ѯ(ģ����ѯ)
		char chTem='%';
		strSQL.Format("'%c%s%c'",chTem,strWhereValue,chTem);
		strSQL=strField+" "+strRelation+" "+strSQL;
	}
	CListBox* pListBox=(CListBox*)GetDlgItem(IDC_SQL_LIST);
	//�����ɵĵ�����ѯ�����ӵ��б��
	pListBox->AddString(strSQL);

}

CString& CQueryDlg::GetSQL()
{	
	CListBox* pListBox=(CListBox*)GetDlgItem(IDC_SQL_LIST);
	int iSql=0;
	CString strText,strTem;
	//��ȡ�ܵ�������
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
	//��ȡ���յĲ�ѯ���
	GetSQL();
	CDialog::OnOK();
}
