// DelUserDlg.cpp : implementation file
//

#include "stdafx.h"
#include "HMS.h"
#include "DelUserDlg.h"
#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDelUserDlg dialog


CDelUserDlg::CDelUserDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CDelUserDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDelUserDlg)
	m_strCID = _T("");
	m_strCName = _T("");
	m_InDate = COleDateTime::GetCurrentTime();
	m_strPay = _T("");
	m_OutDate = COleDateTime::GetCurrentTime();
	//}}AFX_DATA_INIT
}


void CDelUserDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDelUserDlg)
	DDX_Text(pDX, IDC_CUSTOMER_ID, m_strCID);
	DDX_Text(pDX, IDC_CUSTOMER_NAME, m_strCName);
	DDX_DateTimeCtrl(pDX, IDC_DATE_IN, m_InDate);
	DDX_Text(pDX, IDC_PAY, m_strPay);
	DDX_DateTimeCtrl(pDX, IDC_DATE_OUT, m_OutDate);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDelUserDlg, CDialog)
	//{{AFX_MSG_MAP(CDelUserDlg)
	ON_BN_CLICKED(IDC_BUTTON_CONFIRM, OnButtonConfirm)
	ON_BN_CLICKED(IDC_BUTTON_CANCEL, OnButtonCancel)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDelUserDlg message handlers

void CDelUserDlg::SetTitle()
{
	SetWindowText(_T("注销客户"));
}

void CDelUserDlg::SetStyle()
{
	((CEdit *)GetDlgItem(IDC_CUSTOMER_ID))->SetReadOnly(true);
	((CEdit *)GetDlgItem(IDC_CUSTOMER_NAME))->SetReadOnly(true);
	((CEdit *)GetDlgItem(IDC_PAY))->SetReadOnly(true);
	FillDelUserDlg();


}

void CDelUserDlg::FillDelUserDlg()
{
	m_strCID=selCustomer.strCID;
	m_strCName=selCustomer.strCName;

	_variant_t strQuery = "select * from bookin where CustomerID='"+m_strCID+"'";
    theApp.ADOExecute(theApp.m_pRs, strQuery);
	theApp.m_pRs->MoveFirst();

	// Get typename
    _variant_t Holder = theApp.m_pRs->GetCollect("InDate");
	m_InDate=Holder.date;

	COleVariant vtime(COleDateTime::GetCurrentTime().Format("%y-%m-%d"));
	vtime.ChangeType(VT_DATE);

	COleDateTime time=vtime;
	m_OutDate=time;

	CTreeCtrl* pTreeCtrl=&m_pLeftView->GetTreeCtrl();
	CString strRoomType=pTreeCtrl->GetItemText(pTreeCtrl->GetParentItem(m_pLeftView->m_hHitItem));
	strQuery = "select * from roomtype where TypeName='"+strRoomType+"'";
    theApp.ADOExecute(theApp.m_pRs, strQuery);
	theApp.m_pRs->MoveFirst();
	Holder = theApp.m_pRs->GetCollect("Price");
	float basic=(Holder.vt==VT_NULL?0.0:Holder.dblVal);


	m_strPay.Format("%0.2f",basic*(m_OutDate.GetDay()-m_InDate.GetDay()+1));







}

BOOL CDelUserDlg::OnInitDialog() 
{
	SetTitle();
	SetStyle();
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CDelUserDlg::OnButtonConfirm() 
{
	UpdateData(true);
	CTreeCtrl *pTreeCtrl=&m_pLeftView->GetTreeCtrl();
	CString strRoomNO=pTreeCtrl->GetItemText(m_pLeftView->m_hHitItem);
	CString strInDate=m_InDate.Format("%y-%m-%d");
	CString strOutDate=m_OutDate.Format("%y-%m-%d");
	
	_variant_t strQuery;
	

	strQuery = "insert history(CustomerID,RoomNO,InDate,OutDate,Pay)\
		values('"+m_strCID+"','"+strRoomNO+"','"+strInDate+"','"+strOutDate\
		+"',"+m_strPay+")";

if(	theApp.ADOExecute(theApp.m_pRs, strQuery))
{
	strQuery="delete from bookin where CustomerID='"+m_strCID+"'";
	if(theApp.ADOExecute(theApp.m_pRs, strQuery))
	{
		AfxMessageBox("注销成功!");
		OnOK();
		CMainFrame* pFrame = (CMainFrame*)AfxGetApp()->m_pMainWnd;
		pFrame->SwitchToView(USERLISTVIEW);
		return;

	}
}

	AfxMessageBox("注销失败");
	OnCancel();

	
	



	// TODO: Add your control notification handler code here
	
}

void CDelUserDlg::OnButtonCancel() 
{
	OnCancel();
	// TODO: Add your control notification handler code here
	
}
