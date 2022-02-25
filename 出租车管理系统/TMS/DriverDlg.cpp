// DriverDlg.cpp : implementation file
//

#include "stdafx.h"
#include "TMS.h"
#include "DriverDlg.h"
#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDriverDlg dialog


CDriverDlg::CDriverDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CDriverDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDriverDlg)
	m_tmDate = 0;
	m_strAddress = _T("");
	m_strID = _T("");
	m_strKind = _T("");
	m_strName = _T("");
	m_strNO = _T("");
	m_strPhone = _T("");
	m_strSex = _T("");
	//}}AFX_DATA_INIT
}


void CDriverDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDriverDlg)
	DDX_DateTimeCtrl(pDX, IDC_DATE, m_tmDate);
	DDX_Text(pDX, IDC_EDIT_ADDRESS, m_strAddress);
	DDX_Text(pDX, IDC_EDIT_ID, m_strID);
	DDX_Text(pDX, IDC_EDIT_KIND, m_strKind);
	DDX_Text(pDX, IDC_EDIT_NAME, m_strName);
	DDX_Text(pDX, IDC_EDIT_NO, m_strNO);
	DDX_Text(pDX, IDC_EDIT_PHONE, m_strPhone);
	DDX_Text(pDX, IDC_EDIT_SEX, m_strSex);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDriverDlg, CDialog)
	//{{AFX_MSG_MAP(CDriverDlg)
	ON_BN_CLICKED(IDC_BUTTON_OK, OnButtonOk)
	ON_BN_CLICKED(IDC_BUTTON_CANCEL, OnButtonCancel)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDriverDlg message handlers

void CDriverDlg::SetStyle()
{
	switch(operation)
	{
	case 1:
		((CEdit *)GetDlgItem(IDC_EDIT_NO))->SetReadOnly(false);
		((CEdit *)GetDlgItem(IDC_EDIT_NAME))->SetReadOnly(false);
		((CEdit *)GetDlgItem(IDC_EDIT_SEX))->SetReadOnly(false);
		((CEdit *)GetDlgItem(IDC_EDIT_ID))->SetReadOnly(false);
		((CEdit *)GetDlgItem(IDC_EDIT_ADDRESS))->SetReadOnly(false);
		((CEdit *)GetDlgItem(IDC_EDIT_KIND))->SetReadOnly(false);
		((CEdit *)GetDlgItem(IDC_EDIT_PHONE))->SetReadOnly(false);
		ClearData();

		break;
	case 2:
		((CEdit *)GetDlgItem(IDC_EDIT_NO))->SetReadOnly(true);
		((CEdit *)GetDlgItem(IDC_EDIT_NAME))->SetReadOnly(false);
		((CEdit *)GetDlgItem(IDC_EDIT_SEX))->SetReadOnly(false);
		((CEdit *)GetDlgItem(IDC_EDIT_ID))->SetReadOnly(false);
		((CEdit *)GetDlgItem(IDC_EDIT_ADDRESS))->SetReadOnly(false);
		((CEdit *)GetDlgItem(IDC_EDIT_KIND))->SetReadOnly(false);
		((CEdit *)GetDlgItem(IDC_EDIT_PHONE))->SetReadOnly(false);
		FillData();
		break;
	case 3:
		((CEdit *)GetDlgItem(IDC_EDIT_NO))->SetReadOnly(true);
		((CEdit *)GetDlgItem(IDC_EDIT_NAME))->SetReadOnly(true);
		((CEdit *)GetDlgItem(IDC_EDIT_SEX))->SetReadOnly(true);
		((CEdit *)GetDlgItem(IDC_EDIT_ID))->SetReadOnly(true);
		((CEdit *)GetDlgItem(IDC_EDIT_ADDRESS))->SetReadOnly(true);
		((CEdit *)GetDlgItem(IDC_EDIT_KIND))->SetReadOnly(true);
		((CEdit *)GetDlgItem(IDC_EDIT_PHONE))->SetReadOnly(true);
		FillData();
		break;
	}

}

void CDriverDlg::SetTitle()
{
	switch(operation)
	{
	case 1:
		SetWindowText(_T("���˾��"));
		break;
	case 2:
		SetWindowText(_T("�޸�˾��"));
		break;
	case 3:
		SetWindowText(_T("ɾ��˾��"));
		break;
	}

}

BOOL CDriverDlg::OnInitDialog() 
{
	SetStyle();
	SetTitle();
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CDriverDlg::FillData()
{
	m_tmDate=selDriver.tmBookDate;
	m_strAddress=selDriver.strAddress;
	m_strID=selDriver.strID;
	m_strKind=selDriver.strCarKind;
	m_strName=selDriver.strName;
	m_strNO=selDriver.strNO;
	m_strPhone=selDriver.strPhone;
	m_strSex=selDriver.strSex;
}

void CDriverDlg::ClearData()
{
	m_tmDate=CTime::GetCurrentTime();
	m_strAddress=m_strID=m_strKind=m_strName=m_strNO=m_strPhone=m_strSex="";
}

void CDriverDlg::AddDriver()
{
	UpdateData(true);

	m_strAddress.TrimRight(" ");
	m_strID.TrimRight(" ");
	m_strKind.TrimRight(" ");
	m_strName.TrimRight(" ");
	m_strNO.TrimRight(" ");
	m_strPhone.TrimRight(" ");
	m_strSex.TrimRight(" ");
	
	
	// Make sure all needed info is available
	CString sWarning="";
	if ( ""==m_strNO) sWarning=_T("��ʻԱ���");
	    
	if ( ""!=sWarning ) 
	{
	   sWarning += _T("����Ϊ��");
	   AfxMessageBox(sWarning, MB_ICONEXCLAMATION);
	   return;
	}
        


	// Judge CustomerID is Unique
	_variant_t strQuery = "select * from driver where Driver_NO='"+m_strNO+"'";
	theApp.ADOExecute(theApp.m_pRs, strQuery);
	int iCount = theApp.m_pRs->GetRecordCount();
	if ( 0!=iCount )
	{
	       AfxMessageBox(_T("�Ѿ����ڴ˼�ʻԱ�ŵļ�¼��"), MB_ICONEXCLAMATION);
		   return;
	}

	//else info
	CString strI;
	if (m_strSex=="��")
		strI="1";
	else
		strI="0";
	CString strD;
	strD=m_tmDate.Format("%y-%m-%d");


	

	strQuery = "insert driver(Driver_NO,Driver_Name,Driver_SEX,Driver_ID,Driver_Address,Driver_BookDate,Driver_CarKind,Driver_Phone) \
	values ('"+m_strNO+"', '"+m_strName+"',"+strI+",'"+m_strID+"','"+m_strAddress+"','"+strD+"','"+m_strKind+"','"+m_strPhone+"')";

	if ( theApp.ADOExecute(theApp.m_pRs, strQuery) )
	{
		AfxMessageBox(_T("��Ӽ�¼�ɹ���"), MB_ICONINFORMATION);
		// Clear all input
		ClearData();
		UpdateData(false);

	}
	else
	{
		AfxMessageBox(_T("��Ӽ�¼ʧ�ܣ�"), MB_ICONEXCLAMATION);
		return;
	}
	CMainFrame* pFrame = (CMainFrame*)AfxGetApp()->m_pMainWnd;
	pFrame->ShowView();

}

void CDriverDlg::ModifyDriver()
{
	UpdateData(true);

	m_strAddress.TrimRight(" ");
	m_strID.TrimRight(" ");
	m_strKind.TrimRight(" ");
	m_strName.TrimRight(" ");
	m_strNO.TrimRight(" ");
	m_strPhone.TrimRight(" ");
	m_strSex.TrimRight(" ");
	



	//else info
	CString strI;
	if (m_strSex=="��")
		strI="1";
	else
		strI="0";
	CString strD;
	strD=m_tmDate.Format("%y-%m-%d");	

	_variant_t strQuery = "UPDATE driver  set Driver_Name='"+m_strName+"',Driver_SEX\
	="+strI+",Driver_ID='"+m_strID+"',Driver_Address='"+m_strAddress+"',\
	Driver_BookDate='"+strD+"',Driver_CarKind='"+m_strKind+"',Driver_Phone\
	='"+m_strPhone+"' where Driver_NO='"+m_strNO+"'";


	if ( theApp.ADOExecute(theApp.m_pRs, strQuery) )
	{
		AfxMessageBox(_T("�޸ļ�¼�ɹ���"), MB_ICONINFORMATION);
		// Clear all input
		ClearData();
		UpdateData(false);

	}
	else
	{
		AfxMessageBox(_T("�޸ļ�¼ʧ�ܣ�"), MB_ICONEXCLAMATION);
		return;
	}
	CMainFrame* pFrame = (CMainFrame*)AfxGetApp()->m_pMainWnd;
	pFrame->ShowView();

}

void CDriverDlg::DelDriver()
{
	bool bDel=false;
	bDel=(MessageBox("ɾ����ʻԱ��Ϣ��ζ��������صĻ�����Ϣ��Υ���ͽ��ͣ���һ��ɾ��,ȷ��ɾ����?","ɾ������",MB_YESNO)==IDYES);
	if(!bDel)
		return;

	_variant_t strQuery;


	strQuery = "Delete from Driver where Driver_NO='"+m_strNO+"'";
	theApp.ADOExecute(theApp.m_pRs, strQuery);

	strQuery = "Delete from [Driver-award] where Driver_NO='"+m_strNO+"'";
	theApp.ADOExecute(theApp.m_pRs, strQuery);

	strQuery = "Delete from [Driver-punish] where Driver_NO='"+m_strNO+"'";
	theApp.ADOExecute(theApp.m_pRs, strQuery);

	CMainFrame* pFrame = (CMainFrame*)AfxGetApp()->m_pMainWnd;
	pFrame->ShowView();

}

void CDriverDlg::OnButtonOk() 
{
	switch(operation)
	{
	case 1:
		AddDriver();
		break;
	case 2:
		ModifyDriver();
		OnOK();
		break;
	case 3:
		DelDriver();
		OnOK();
		break;


	}
	// TODO: Add your control notification handler code here
	
}

void CDriverDlg::OnButtonCancel() 
{
	OnCancel();
	// TODO: Add your control notification handler code here
	
}
