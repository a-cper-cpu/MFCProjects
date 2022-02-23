// CustomerDlg.cpp : implementation file
//

#include "stdafx.h"
#include "HMS.h"
#include "CustomerDlg.h"
#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCustomerDlg dialog


CCustomerDlg::CCustomerDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CCustomerDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CCustomerDlg)
	m_strCID = _T("");
	m_strCName = _T("");
	m_strCOff = _T("");
	m_strCTel = _T("");
	m_strCAge = _T("");
	//}}AFX_DATA_INIT
}


void CCustomerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCustomerDlg)
	DDX_Text(pDX, IDC_CUSTOMER_ID, m_strCID);
	DDX_Text(pDX, IDC_CUSTOMER_NAME, m_strCName);
	DDX_Text(pDX, IDC_CUSTOMER_OFF, m_strCOff);
	DDX_Text(pDX, IDC_CUSTOMER_TEL, m_strCTel);
	DDX_CBIndex(pDX, IDC_CUSTOMER_SEX, m_iCSex);
	DDX_Text(pDX, IDC_CUSTOMER_AGE, m_strCAge);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CCustomerDlg, CDialog)
	//{{AFX_MSG_MAP(CCustomerDlg)
	ON_BN_CLICKED(IDC_BUTTON_CONFIRM, OnButtonConfirm)
	ON_BN_CLICKED(IDC_BUTTON_CANCEL, OnButtonCancel)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCustomerDlg message handlers

void CCustomerDlg::SetTitle()
{
	switch(operation)
	{
	case 1:
		SetWindowText(_T("登记客户"));
		break;
	case 2:
		SetWindowText(_T("修改客户"));
		break;
	}

}

void CCustomerDlg::SetStyle()
{
	switch(operation)
	{
	case 1:
		((CEdit *)GetDlgItem(IDC_CUSTOMER_ID))->SetReadOnly(false);
		((CEdit *)GetDlgItem(IDC_CUSTOMER_NAME))->SetReadOnly(false);
		((CEdit *)GetDlgItem(IDC_CUSTOMER_AGE))->SetReadOnly(false);
		((CEdit *)GetDlgItem(IDC_CUSTOMER_TEL))->SetReadOnly(false);
		((CEdit *)GetDlgItem(IDC_CUSTOMER_OFF))->SetReadOnly(false);
		ClearCustomer();
		break;
	case 2:
		((CEdit *)GetDlgItem(IDC_CUSTOMER_ID))->SetReadOnly(true);
		((CEdit *)GetDlgItem(IDC_CUSTOMER_NAME))->SetReadOnly(false);
		((CEdit *)GetDlgItem(IDC_CUSTOMER_AGE))->SetReadOnly(false);
		((CEdit *)GetDlgItem(IDC_CUSTOMER_TEL))->SetReadOnly(false);
		((CEdit *)GetDlgItem(IDC_CUSTOMER_OFF))->SetReadOnly(false);
		FillCustomer();
		break;

	}

}

void CCustomerDlg::ClearCustomer()
{
	m_iCSex=0;
	m_strCAge=m_strCID=m_strCName=m_strCOff=m_strCTel="";

}

void CCustomerDlg::FillCustomer()
{
	m_strCID=selCustomer.strCID;
	m_strCName=selCustomer.strCName;
	m_strCAge=selCustomer.strCAge;
	m_strCTel=selCustomer.strCTel;
	m_strCOff=selCustomer.strCOff;
	m_iCSex=selCustomer.iCSex;


}

BOOL CCustomerDlg::OnInitDialog() 
{
	SetTitle();
	SetStyle();
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CCustomerDlg::OnButtonConfirm() 
{
	switch(operation)
	{
	case 1:
		AddCustomer();
		break;
	case 2:
		ModifyCustomer();
		OnOK();
		break;
	}
	// TODO: Add your control notification handler code here
	
}

void CCustomerDlg::OnButtonCancel() 
{
	OnCancel();
	// TODO: Add your control notification handler code here
	
}

void CCustomerDlg::AddCustomer()
{
	UpdateData(true);	
	m_strCID.TrimRight(" ");
    m_strCName.TrimRight(" ");
	m_strCAge.TrimRight(" ");
	m_strCTel.TrimRight(" ");
	m_strCOff.TrimRight(" ");
	
	
	// Make sure all needed info is available
	CString sWarning="";
	if ( ""==m_strCID) sWarning=_T("身份证号");
    else if ( ""==  m_strCName) sWarning=_T("客户姓名");
	    
	if ( ""!=sWarning ) 
	{
	   sWarning += _T("不能为空");
	   AfxMessageBox(sWarning, MB_ICONEXCLAMATION);
	   return;
	}
        
	// Make sure the Number info is valid

	int iAge = atoi(m_strCAge);
	if ( 0>=iAge ) 
	{
		AfxMessageBox(_T("客户年龄：输入非法"), MB_ICONEXCLAMATION);
	    return;
	}
	m_strCAge.Format("%d", iAge);

	// Judge CustomerID is Unique
	_variant_t strQuery = "select * from customer where CustomerID='"+m_strCID+"'";
	theApp.ADOExecute(theApp.m_pRs, strQuery);
	int iCount = theApp.m_pRs->GetRecordCount();
	if ( 0!=iCount )
	{
	       AfxMessageBox(_T("已经存在此标准编号的记录！"), MB_ICONEXCLAMATION);
		   return;
	}


    // Get other info
	CString strCSex("0");
	if ( ((CComboBox*)GetDlgItem(IDC_CUSTOMER_SEX))->GetCurSel() ) strCSex="1";
	

	strQuery = "insert customer(CustomerID, CustomerName, CustomerSex, CustomerAge, CustomerTel, CustomerOff) \
	         	    values ('"+m_strCID+"', '"+m_strCName+"',  "+strCSex+", "+m_strCAge+", '"+m_strCTel+"','"+m_strCOff+"')";

	if ( theApp.ADOExecute(theApp.m_pRs, strQuery) )
	{
		CString strRoomNO;	
		CTreeCtrl *pTree=&(m_pLeftView->GetTreeCtrl());
		strRoomNO=pTree->GetItemText(m_pLeftView->m_hHitItem);

		COleDateTime now=COleDateTime::GetCurrentTime();
		CString InDate=now.Format("%y-%m-%d%");

		strQuery="insert bookin(CustomerID,RoomNO,InDate) \
		values('"+m_strCID+"','"+strRoomNO+"','"+InDate+"')";
		if ( theApp.ADOExecute(theApp.m_pRs, strQuery) )
		{			
			AfxMessageBox(_T("添加记录成功！"), MB_ICONINFORMATION);
			// Clear all input
			m_strCID=m_strCName=m_strCAge=m_strCTel=m_strCOff="";
			((CComboBox*)GetDlgItem(IDC_CUSTOMER_SEX))->SetCurSel(0);
			UpdateData(false);
		}
		else
		{
			AfxMessageBox(_T("添加记录失败！"), MB_ICONEXCLAMATION);
			return;
		}
	}
	else
	{
		AfxMessageBox(_T("添加记录失败！"), MB_ICONEXCLAMATION);
		return;
	}
	CMainFrame* pFrame = (CMainFrame*)AfxGetApp()->m_pMainWnd;
	pFrame->SwitchToView(USERLISTVIEW);



}



void CCustomerDlg::ModifyCustomer()
{
	UpdateData(true);	
	m_strCID.TrimRight(" ");
    m_strCName.TrimRight(" ");
	m_strCAge.TrimRight(" ");
	m_strCTel.TrimRight(" ");
	m_strCOff.TrimRight(" ");
	
	
	// Make sure all needed info is available
	CString sWarning="";
	if ( ""==m_strCID) sWarning=_T("身份证号");
    else if ( ""==  m_strCName) sWarning=_T("客户姓名");
	    
	if ( ""!=sWarning ) 
	{
	   sWarning += _T("不能为空");
	   AfxMessageBox(sWarning, MB_ICONEXCLAMATION);
	   return;
	}
        
	// Make sure the Number info is valid

	int iAge = atoi(m_strCAge);
	if ( 0>=iAge ) 
	{
		AfxMessageBox(_T("客户年龄：输入非法"), MB_ICONEXCLAMATION);
	    return;
	}
	m_strCAge.Format("%d", iAge);



    // Get other info
	CString strCSex("0");
	if ( ((CComboBox*)GetDlgItem(IDC_CUSTOMER_SEX))->GetCurSel() ) strCSex="1";
	

	_variant_t strQuery = "Update customer set CustomerName='"+m_strCName+"',"+"CustomerSex="+strCSex+", CustomerAge="+m_strCAge+",CustomerTel='"+m_strCTel+"', \
		CustomerOff='"+m_strCOff+"'  where CustomerID='"+m_strCID+"'";
	if ( theApp.ADOExecute(theApp.m_pRs, strQuery) ) 
		AfxMessageBox(_T("修改记录成功！"), MB_ICONINFORMATION);
	else 
		AfxMessageBox(_T("修改记录失败！"), MB_ICONEXCLAMATION);

		CMainFrame* pFrame = (CMainFrame*)AfxGetApp()->m_pMainWnd;
		pFrame->SwitchToView(USERLISTVIEW);

}
