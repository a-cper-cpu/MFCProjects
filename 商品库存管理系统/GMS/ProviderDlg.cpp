// ProviderDlg.cpp : implementation file
//

#include "stdafx.h"
#include "GMS.h"
#include "ProviderDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CProviderDlg dialog


CProviderDlg::CProviderDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CProviderDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CProviderDlg)
	m_strAddress = _T("");
	m_strCode = _T("");
	m_strName = _T("");
	m_strEmail = _T("");
	m_strPerson = _T("");
	m_strPhone = _T("");
	//}}AFX_DATA_INIT
}


void CProviderDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CProviderDlg)
	DDX_Control(pDX, IDC_LIST_DISP, m_listDisp);
	DDX_Text(pDX, IDC_EDIT_ADDRESS, m_strAddress);
	DDX_Text(pDX, IDC_EDIT_CODE, m_strCode);
	DDX_Text(pDX, IDC_EDIT_NAME, m_strName);
	DDX_Text(pDX, IDC_EDIT_EMAIL, m_strEmail);
	DDX_Text(pDX, IDC_EDIT_PERSON, m_strPerson);
	DDX_Text(pDX, IDC_EDIT_PHONE, m_strPhone);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CProviderDlg, CDialog)
	//{{AFX_MSG_MAP(CProviderDlg)
	ON_BN_CLICKED(IDC_BUTTON_ADD, OnButtonAdd)
	ON_BN_CLICKED(IDC_BUTTON_MODIFY, OnButtonModify)
	ON_BN_CLICKED(IDC_BUTTON_DELETE, OnButtonDelete)
	ON_BN_CLICKED(IDC_BUTTON_EXIT, OnButtonExit)
	ON_NOTIFY(NM_CLICK, IDC_LIST_DISP, OnClickListDisp)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CProviderDlg message handlers

void CProviderDlg::RefreshData()
{
	m_listDisp.DeleteAllItems();
	m_listDisp.SetRedraw(FALSE);
	
	_variant_t Holder, strQuery;
    strQuery= "select * from provider";
	theApp.ADOExecute(theApp.m_pRs, strQuery);
    int iCount = theApp.m_pRs->GetRecordCount();
	if ( 0==iCount ) 
		return;
	theApp.m_pRs->MoveFirst();

	int i=0;
	while(!theApp.m_pRs->adoEOF)
	{
		Holder = theApp.m_pRs->GetCollect("Provider_code");
		if(Holder.vt!=VT_NULL)
			m_listDisp.InsertItem(i, (char*)(_bstr_t)Holder);

		Holder = theApp.m_pRs->GetCollect("Provider_name");
		if(Holder.vt!=VT_NULL)
			m_listDisp.SetItemText(i,1, (char*)(_bstr_t)Holder);

		Holder = theApp.m_pRs->GetCollect("Provider_address");
		if(Holder.vt!=VT_NULL)
			m_listDisp.SetItemText(i,2, (char*)(_bstr_t)Holder);

		Holder = theApp.m_pRs->GetCollect("Provider_person");
		if(Holder.vt!=VT_NULL)
			m_listDisp.SetItemText(i,3, (char*)(_bstr_t)Holder);

		Holder = theApp.m_pRs->GetCollect("Provider_telphone");
		if(Holder.vt!=VT_NULL)
			m_listDisp.SetItemText(i,4, (char*)(_bstr_t)Holder);

		Holder = theApp.m_pRs->GetCollect("Provider_email");
		if(Holder.vt!=VT_NULL)
			m_listDisp.SetItemText(i,5, (char*)(_bstr_t)Holder);

		theApp.m_pRs->MoveNext();
		i++;
	}

	m_listDisp.SetRedraw(TRUE);	

}

BOOL CProviderDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();

	m_listDisp.InsertColumn(0,"编号");
	m_listDisp.InsertColumn(1,"名称");
	m_listDisp.InsertColumn(2,"地址");
	m_listDisp.InsertColumn(3,"负责人");
	m_listDisp.InsertColumn(4,"电话");
	m_listDisp.InsertColumn(5,"Email");
	
	RECT rect;
	m_listDisp.GetWindowRect(&rect);
	int wid = rect.right - rect.left;
	m_listDisp.SetColumnWidth(0,wid/6);
	m_listDisp.SetColumnWidth(1,wid/6);
	m_listDisp.SetColumnWidth(2,wid/6);
	m_listDisp.SetColumnWidth(3,wid/6);
	m_listDisp.SetColumnWidth(4,wid/6);
	m_listDisp.SetColumnWidth(5,wid/6);
	m_listDisp.SetExtendedStyle(LVS_EX_FULLROWSELECT);


	RefreshData();
	
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CProviderDlg::OnButtonAdd() 
{
	UpdateData();

	CString strSql;

	strSql.Format("INSERT INTO provider(Provider_code,Provider_name,Provider_address,Provider_person,Provider_telphone,Provider_email) VALUES('%s','%s','%s','%s','%s','%s')",
		m_strCode, m_strName, m_strAddress,m_strPerson,m_strPhone,m_strEmail);
	_variant_t  vtQuery(strSql);  
	theApp.ADOExecute(theApp.m_pRs, vtQuery);
      
	RefreshData(); 
	ClearTxt();
	
	theApp.m_log.AddLog("添加商家");

	// TODO: Add your control notification handler code here
	
}

void CProviderDlg::ClearTxt()
{
	m_strAddress="";
	m_strCode="";
	m_strName="";
	m_strEmail="";
	m_strPerson="";
	m_strPhone="";
	UpdateData(false);
}


void CProviderDlg::OnButtonModify() 
{
	UpdateData();

	CString strSql;

	strSql.Format("UPDATE provider SET Provider_name='%s',Provider_address='%s',Provider_person='%s',Provider_telphone='%s',Provider_email='%s' WHERE Provider_code='%s'", m_strName, m_strAddress,m_strPerson,m_strPhone,m_strEmail,m_strCode);	
	// TODO: Add your control notification handler code here
	_variant_t  vtQuery(strSql);  
	if(theApp.ADOExecute(theApp.m_pRs, vtQuery))
	{
		RefreshData(); 
		ClearTxt();
		theApp.m_log.AddLog("修改商家");
	}
	else
	{
		AfxMessageBox("修改失败");

	}

	// TODO: Add your control notification handler code here
	
}

void CProviderDlg::OnButtonDelete() 
{
	UpdateData();
	CString strSql;
	strSql.Format("DELETE FROM provider WHERE Provider_code='%s'",m_strCode);
	_variant_t  vtQuery(strSql);  
	theApp.ADOExecute(theApp.m_pRs, vtQuery);
	RefreshData(); 
	ClearTxt();
	
	theApp.m_log.AddLog("删除商品");
	// TODO: Add your control notification handler code here
	
}

void CProviderDlg::OnButtonExit() 
{
	OnOK();
	// TODO: Add your control notification handler code here
	
}

void CProviderDlg::OnClickListDisp(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	int i = m_listDisp.GetSelectionMark();

	m_strCode = m_listDisp.GetItemText(i,0);
	m_strName= m_listDisp.GetItemText(i,1);
	m_strAddress = m_listDisp.GetItemText(i,2);
	m_strPerson = m_listDisp.GetItemText(i,3);
	m_strPhone = m_listDisp.GetItemText(i,4);
	m_strEmail = m_listDisp.GetItemText(i,5);
	
	UpdateData(FALSE);
	
	*pResult = 0;
}
