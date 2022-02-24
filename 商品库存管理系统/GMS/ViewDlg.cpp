// ViewDlg.cpp : implementation file
//

#include "stdafx.h"
#include "GMS.h"
#include "ViewDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CViewDlg dialog


CViewDlg::CViewDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CViewDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CViewDlg)
	m_strNum = _T("");
	//}}AFX_DATA_INIT
}


void CViewDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CViewDlg)
	DDX_Control(pDX, IDC_LIST_DISP, m_listDisp);
	DDX_Text(pDX, IDC_EDIT_NUM, m_strNum);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CViewDlg, CDialog)
	//{{AFX_MSG_MAP(CViewDlg)
	ON_BN_CLICKED(IDC_BUTTON_OK, OnButtonOk)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CViewDlg message handlers

void CViewDlg::Init(int iKind)
{
	this->m_iKind=iKind;
}

void CViewDlg::SetTitle()
{
	switch(m_iKind)
	{
	case 1:
		SetWindowText(_T("��Ʒ��Ϣ"));
		break;
	case 2:
		SetWindowText(_T("�̼���Ϣ"));
		break;
	case 3:
		SetWindowText(_T("�����Ϣ"));
		break;
	case 4:
		SetWindowText(_T("������Ϣ"));
		break;
	case 5:
		SetWindowText(_T("������־"));
		break;
	}

}

void CViewDlg::SetStyle()
{
	RECT rect;
	int wid;
	switch(m_iKind)
	{
	case 1:
	m_listDisp.InsertColumn(0,"��Ʒ���");
	m_listDisp.InsertColumn(1,"��Ʒ����");
	m_listDisp.InsertColumn(2,"��ǰ���");
	m_listDisp.InsertColumn(3,"������");
	m_listDisp.InsertColumn(4,"��С����");
	
	
	m_listDisp.GetWindowRect(&rect);
	wid = rect.right - rect.left;
	m_listDisp.SetColumnWidth(0,wid/5);
	m_listDisp.SetColumnWidth(1,wid/5);
	m_listDisp.SetColumnWidth(2,wid/5);
	m_listDisp.SetColumnWidth(3,wid/5);
	m_listDisp.SetColumnWidth(4,wid/5);
	m_listDisp.SetExtendedStyle(LVS_EX_FULLROWSELECT);
	break;
	case 2:
	m_listDisp.InsertColumn(0,"�̼ұ��");
	m_listDisp.InsertColumn(1,"�̼�����");
	m_listDisp.InsertColumn(2,"�̼ҵ�ַ");
	m_listDisp.InsertColumn(3,"������");
	m_listDisp.InsertColumn(4,"�绰");
	m_listDisp.InsertColumn(5,"Email");
	

	m_listDisp.GetWindowRect(&rect);
	wid = rect.right - rect.left;
	m_listDisp.SetColumnWidth(0,wid/6);
	m_listDisp.SetColumnWidth(1,wid/6);
	m_listDisp.SetColumnWidth(2,wid/6);
	m_listDisp.SetColumnWidth(3,wid/6);
	m_listDisp.SetColumnWidth(4,wid/6);
	m_listDisp.SetColumnWidth(5,wid/6);
	m_listDisp.SetExtendedStyle(LVS_EX_FULLROWSELECT);
		break;
	case 3:
	m_listDisp.InsertColumn(0,"��Ʒ���");
	m_listDisp.InsertColumn(1,"�̼ұ��");
	m_listDisp.InsertColumn(2,"�������");
	m_listDisp.InsertColumn(3,"����۸�");
	m_listDisp.InsertColumn(4,"��������");
	

	m_listDisp.GetWindowRect(&rect);
	wid = rect.right - rect.left;
	m_listDisp.SetColumnWidth(0,wid/5);
	m_listDisp.SetColumnWidth(1,wid/5);
	m_listDisp.SetColumnWidth(2,wid/5);
	m_listDisp.SetColumnWidth(3,wid/5);
	m_listDisp.SetColumnWidth(4,wid/5);
	m_listDisp.SetExtendedStyle(LVS_EX_FULLROWSELECT);
		break;
	case 4:
	m_listDisp.InsertColumn(0,"��Ʒ���");
	m_listDisp.InsertColumn(1,"��������");
	m_listDisp.InsertColumn(2,"������Ա");
	m_listDisp.InsertColumn(3,"���⸺����");
	m_listDisp.InsertColumn(4,"��������");
	

	m_listDisp.GetWindowRect(&rect);
	wid = rect.right - rect.left;
	m_listDisp.SetColumnWidth(0,wid/5);
	m_listDisp.SetColumnWidth(1,wid/5);
	m_listDisp.SetColumnWidth(2,wid/5);
	m_listDisp.SetColumnWidth(3,wid/5);
	m_listDisp.SetColumnWidth(4,wid/5);
	m_listDisp.SetExtendedStyle(LVS_EX_FULLROWSELECT);
	break;
	case 5:
	m_listDisp.InsertColumn(0,"����Ա");
	m_listDisp.InsertColumn(1,"�¼�");
	m_listDisp.InsertColumn(2,"ʱ��");
	m_listDisp.GetWindowRect(&rect);
	wid = rect.right - rect.left;
	m_listDisp.SetColumnWidth(0,wid/3);
	m_listDisp.SetColumnWidth(1,wid/3);
	m_listDisp.SetColumnWidth(2,wid/3);

	}




}

void CViewDlg::ViewGoods()
{
	m_listDisp.DeleteAllItems();
	m_listDisp.SetRedraw(FALSE);
	
	_variant_t Holder, strQuery;
    strQuery= "select * from goods";
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
			m_listDisp.InsertItem(i, (char*)(_bstr_t)Holder);

		Holder = theApp.m_pRs->GetCollect("G_name");
		if(Holder.vt!=VT_NULL)
			m_listDisp.SetItemText(i,1, (char*)(_bstr_t)Holder);

		Holder = theApp.m_pRs->GetCollect("Current_number");
		if(Holder.vt!=VT_NULL)
			m_listDisp.SetItemText(i,2, (char*)(_bstr_t)Holder);
		
		Holder = theApp.m_pRs->GetCollect("Max_number");
		if(Holder.vt!=VT_NULL)
			m_listDisp.SetItemText(i,3, (char*)(_bstr_t)Holder);

		Holder = theApp.m_pRs->GetCollect("Min_number");
		if(Holder.vt!=VT_NULL)
			m_listDisp.SetItemText(i,4, (char*)(_bstr_t)Holder);

		theApp.m_pRs->MoveNext();
		i++;
	}
		m_strNum.Format("%d",iCount);

	m_listDisp.SetRedraw(TRUE);	

}

void CViewDlg::ViewProvider()
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
	m_strNum.Format("%d",iCount);

	m_listDisp.SetRedraw(TRUE);	


}

void CViewDlg::ViewInlib()
{
	m_listDisp.DeleteAllItems();
	m_listDisp.SetRedraw(FALSE);
	
	_variant_t Holder, strQuery;
    strQuery= "select * from inlib";
	theApp.ADOExecute(theApp.m_pRs, strQuery);
    int iCount = theApp.m_pRs->GetRecordCount();
	if ( 0==iCount ) 
		return;
	theApp.m_pRs->MoveFirst();

	int i=0;
	while(!theApp.m_pRs->adoEOF)
	{
		Holder = theApp.m_pRs->GetCollect("Goods_code");
		if(Holder.vt!=VT_NULL)
			m_listDisp.InsertItem(i, (char*)(_bstr_t)Holder);

		Holder = theApp.m_pRs->GetCollect("Provider_code");
		if(Holder.vt!=VT_NULL)
			m_listDisp.SetItemText(i,1, (char*)(_bstr_t)Holder);

		Holder = theApp.m_pRs->GetCollect("In_number");
		if(Holder.vt!=VT_NULL)
			m_listDisp.SetItemText(i,2, (char*)(_bstr_t)Holder);

		Holder = theApp.m_pRs->GetCollect("In_Price");
		if(Holder.vt!=VT_NULL)
			m_listDisp.SetItemText(i,3, (char*)(_bstr_t)Holder);

		Holder = theApp.m_pRs->GetCollect("In_Date");
		if(Holder.vt!=VT_NULL)
			m_listDisp.SetItemText(i,4, (char*)(_bstr_t)Holder);

		theApp.m_pRs->MoveNext();
		i++;
	}
		m_strNum.Format("%d",iCount);

	m_listDisp.SetRedraw(TRUE);	

}

void CViewDlg::ViewOutlib()
{
	m_listDisp.DeleteAllItems();
	m_listDisp.SetRedraw(FALSE);
	
	_variant_t Holder, strQuery;
    strQuery= "select * from inlib";
	theApp.ADOExecute(theApp.m_pRs, strQuery);
    int iCount = theApp.m_pRs->GetRecordCount();
	if ( 0==iCount ) 
		return;
	theApp.m_pRs->MoveFirst();

	int i=0;
	while(!theApp.m_pRs->adoEOF)
	{
		Holder = theApp.m_pRs->GetCollect("Goods_code");
		if(Holder.vt!=VT_NULL)
			m_listDisp.InsertItem(i, (char*)(_bstr_t)Holder);

		Holder = theApp.m_pRs->GetCollect("Out_number");
		if(Holder.vt!=VT_NULL)
			m_listDisp.SetItemText(i,1, (char*)(_bstr_t)Holder);

		Holder = theApp.m_pRs->GetCollect("Out_person");
		if(Holder.vt!=VT_NULL)
			m_listDisp.SetItemText(i,2, (char*)(_bstr_t)Holder);

		Holder = theApp.m_pRs->GetCollect("taker");
		if(Holder.vt!=VT_NULL)
			m_listDisp.SetItemText(i,3, (char*)(_bstr_t)Holder);

		Holder = theApp.m_pRs->GetCollect("Out_date");
		if(Holder.vt!=VT_NULL)
			m_listDisp.SetItemText(i,4, (char*)(_bstr_t)Holder);

		theApp.m_pRs->MoveNext();
		i++;
	}
	m_strNum.Format("%d",iCount);

	m_listDisp.SetRedraw(TRUE);	

}

BOOL CViewDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	SetTitle();
	SetStyle();
	switch(m_iKind)
	{
	case 1:
		ViewGoods();
		break;
	case 2:
		ViewProvider();
		break;
	case 3:
		ViewInlib();
		break;
	case 4:
		ViewOutlib();
		break;
	case 5:
		ViewLog();
		break;
	}
	UpdateData(false);
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CViewDlg::OnButtonOk() 
{
	OnOK();
	// TODO: Add your control notification handler code here
	
}

void CViewDlg::ViewLog()
{
	m_listDisp.DeleteAllItems();
	m_listDisp.SetRedraw(FALSE);
	
	_variant_t Holder, strQuery;
    strQuery= "select * from log";
	theApp.ADOExecute(theApp.m_pRs, strQuery);
    int iCount = theApp.m_pRs->GetRecordCount();
	if ( 0==iCount ) 
		return;
	theApp.m_pRs->MoveFirst();

	int i=0;
	while(!theApp.m_pRs->adoEOF)
	{
		Holder = theApp.m_pRs->GetCollect("Admin_name");
		if(Holder.vt!=VT_NULL)
			m_listDisp.InsertItem(i, (char*)(_bstr_t)Holder);

		Holder = theApp.m_pRs->GetCollect("do_what");
		if(Holder.vt!=VT_NULL)
			m_listDisp.SetItemText(i,1, (char*)(_bstr_t)Holder);

		Holder = theApp.m_pRs->GetCollect("do_date");
		if(Holder.vt!=VT_NULL)
			m_listDisp.SetItemText(i,2, (char*)(_bstr_t)Holder);

		theApp.m_pRs->MoveNext();
		i++;
	}
	m_strNum.Format("%d",iCount);

	m_listDisp.SetRedraw(TRUE);	

}
