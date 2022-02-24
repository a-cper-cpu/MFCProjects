// AlertDlg.cpp : implementation file
//

#include "stdafx.h"
#include "GMS.h"
#include "AlertDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAlertDlg dialog


CAlertDlg::CAlertDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CAlertDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CAlertDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CAlertDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAlertDlg)
	DDX_Control(pDX, IDC_LIST_LOWDISP, m_listLowDisp);
	DDX_Control(pDX, IDC_LIST_HIGHDISP, m_listHighDisp);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CAlertDlg, CDialog)
	//{{AFX_MSG_MAP(CAlertDlg)
	ON_BN_CLICKED(IDC_BUTTON_OK, OnButtonOk)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAlertDlg message handlers

void CAlertDlg::OnButtonOk() 
{
	OnOK();
	// TODO: Add your control notification handler code here
	
}

BOOL CAlertDlg::OnInitDialog() 
{	
	RECT rect;
	int wid;

	CDialog::OnInitDialog();
	m_listLowDisp.InsertColumn(0,"商品编号");
	m_listLowDisp.InsertColumn(1,"商品名称");
	m_listLowDisp.InsertColumn(2,"当前库存");
	m_listLowDisp.InsertColumn(3,"最大库容");
	m_listLowDisp.InsertColumn(4,"最小库容");
	
	
	m_listLowDisp.GetWindowRect(&rect);
	wid = rect.right - rect.left;
	m_listLowDisp.SetColumnWidth(0,wid/5);
	m_listLowDisp.SetColumnWidth(1,wid/5);
	m_listLowDisp.SetColumnWidth(2,wid/5);
	m_listLowDisp.SetColumnWidth(3,wid/5);
	m_listLowDisp.SetColumnWidth(4,wid/5);
	m_listLowDisp.SetExtendedStyle(LVS_EX_FULLROWSELECT);

	m_listHighDisp.InsertColumn(0,"商品编号");
	m_listHighDisp.InsertColumn(1,"商品名称");
	m_listHighDisp.InsertColumn(2,"当前库存");
	m_listHighDisp.InsertColumn(3,"最大库容");
	m_listHighDisp.InsertColumn(4,"最小库容");
	
	
	m_listHighDisp.GetWindowRect(&rect);
	wid = rect.right - rect.left;
	m_listHighDisp.SetColumnWidth(0,wid/5);
	m_listHighDisp.SetColumnWidth(1,wid/5);
	m_listHighDisp.SetColumnWidth(2,wid/5);
	m_listHighDisp.SetColumnWidth(3,wid/5);
	m_listHighDisp.SetColumnWidth(4,wid/5);
	m_listHighDisp.SetExtendedStyle(LVS_EX_FULLROWSELECT);

	RefreshData();

	
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CAlertDlg::RefreshData()
{

	m_listLowDisp.DeleteAllItems();
	m_listLowDisp.SetRedraw(FALSE);
	
	_variant_t Holder, strQuery;
    strQuery= "select * from goods where Current_number<=Min_number";
	theApp.ADOExecute(theApp.m_pRs, strQuery);
    int iCount = theApp.m_pRs->GetRecordCount();
	if ( 0==iCount ) 
		return;
	theApp.m_pRs->MoveFirst();

	int i=0;
	while(!theApp.m_pRs->adoEOF)
	{
		Holder = theApp.m_pRs->GetCollect("G_code");
		if(Holder.vt!=VT_NULL)
			m_listLowDisp.InsertItem(i, (char*)(_bstr_t)Holder);

		Holder = theApp.m_pRs->GetCollect("G_name");
		if(Holder.vt!=VT_NULL)
			m_listLowDisp.SetItemText(i,1, (char*)(_bstr_t)Holder);

		Holder = theApp.m_pRs->GetCollect("Current_number");
		if(Holder.vt!=VT_NULL)
			m_listLowDisp.SetItemText(i,2, (char*)(_bstr_t)Holder);
		
		Holder = theApp.m_pRs->GetCollect("Max_number");
		if(Holder.vt!=VT_NULL)
			m_listLowDisp.SetItemText(i,3, (char*)(_bstr_t)Holder);

		Holder = theApp.m_pRs->GetCollect("Min_number");
		if(Holder.vt!=VT_NULL)
			m_listLowDisp.SetItemText(i,4, (char*)(_bstr_t)Holder);

		theApp.m_pRs->MoveNext();
		i++;
	}


	m_listLowDisp.SetRedraw(TRUE);	

//高于
	m_listHighDisp.DeleteAllItems();
	m_listHighDisp.SetRedraw(FALSE);
	

    strQuery= "select * from goods where Current_number>=Max_number";
	theApp.ADOExecute(theApp.m_pRs, strQuery);
    iCount = theApp.m_pRs->GetRecordCount();
	if ( 0==iCount ) 
		return;
	theApp.m_pRs->MoveFirst();

	 i=0;
	while(!theApp.m_pRs->adoEOF)
	{
		Holder = theApp.m_pRs->GetCollect("G_code");
		if(Holder.vt!=VT_NULL)
			m_listHighDisp.InsertItem(i, (char*)(_bstr_t)Holder);

		Holder = theApp.m_pRs->GetCollect("G_name");
		if(Holder.vt!=VT_NULL)
			m_listHighDisp.SetItemText(i,1, (char*)(_bstr_t)Holder);

		Holder = theApp.m_pRs->GetCollect("Current_number");
		if(Holder.vt!=VT_NULL)
			m_listHighDisp.SetItemText(i,2, (char*)(_bstr_t)Holder);
		
		Holder = theApp.m_pRs->GetCollect("Max_number");
		if(Holder.vt!=VT_NULL)
			m_listHighDisp.SetItemText(i,3, (char*)(_bstr_t)Holder);

		Holder = theApp.m_pRs->GetCollect("Min_number");
		if(Holder.vt!=VT_NULL)
			m_listHighDisp.SetItemText(i,4, (char*)(_bstr_t)Holder);

		theApp.m_pRs->MoveNext();
		i++;
	}


	m_listHighDisp.SetRedraw(TRUE);	


}
