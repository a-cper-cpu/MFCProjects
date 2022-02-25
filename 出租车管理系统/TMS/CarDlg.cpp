// CarDlg.cpp : implementation file
//

#include "stdafx.h"
#include "TMS.h"
#include "CarDlg.h"
#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCarDlg dialog


CCarDlg::CCarDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CCarDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CCarDlg)
	m_strColor = _T("");
	m_strKind = _T("");
	m_strCarNO = _T("");
	m_strEngineNO = _T("");
	m_strMeterNO = _T("");
	m_strClassisNO = _T("");
	//}}AFX_DATA_INIT
}


void CCarDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCarDlg)
	DDX_Text(pDX, IDC_EDIT_CARCOLOR, m_strColor);
	DDX_Text(pDX, IDC_EDIT_CARKIND, m_strKind);
	DDX_Text(pDX, IDC_EDIT_CARNO, m_strCarNO);
	DDX_Text(pDX, IDC_EDIT_ENGINENO, m_strEngineNO);
	DDX_Text(pDX, IDC_EDIT_METERNO, m_strMeterNO);
	DDX_Text(pDX, IDC_EDIT_CLASISNO, m_strClassisNO);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CCarDlg, CDialog)
	//{{AFX_MSG_MAP(CCarDlg)
	ON_BN_CLICKED(IDC_BUTTON_OK, OnButtonOk)
	ON_BN_CLICKED(IDC_BUTTON_CANCEL, OnButtonCancel)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCarDlg message handlers



void CCarDlg::SetStyle()
{

	switch(operation)
	{
	case 1:
		((CEdit *)GetDlgItem(IDC_EDIT_CARNO))->SetReadOnly(false);
		((CEdit *)GetDlgItem(IDC_EDIT_CARKIND))->SetReadOnly(false);
		((CEdit *)GetDlgItem(IDC_EDIT_CARCOLOR))->SetReadOnly(false);
		((CEdit *)GetDlgItem(IDC_EDIT_ENGINENO))->SetReadOnly(false);
		((CEdit *)GetDlgItem(IDC_EDIT_CLASISNO))->SetReadOnly(false);
		((CEdit *)GetDlgItem(IDC_EDIT_METERNO))->SetReadOnly(false);
		ClearData();
		break;
	case 2:
		((CEdit *)GetDlgItem(IDC_EDIT_CARNO))->SetReadOnly(true);
		((CEdit *)GetDlgItem(IDC_EDIT_CARKIND))->SetReadOnly(false);
		((CEdit *)GetDlgItem(IDC_EDIT_CARCOLOR))->SetReadOnly(false);
		((CEdit *)GetDlgItem(IDC_EDIT_ENGINENO))->SetReadOnly(false);
		((CEdit *)GetDlgItem(IDC_EDIT_CLASISNO))->SetReadOnly(false);
		((CEdit *)GetDlgItem(IDC_EDIT_METERNO))->SetReadOnly(false);
		FillData();
		break;
	case 3:
	
		((CEdit *)GetDlgItem(IDC_EDIT_CARNO))->SetReadOnly(true);
		((CEdit *)GetDlgItem(IDC_EDIT_CARKIND))->SetReadOnly(true);
		((CEdit *)GetDlgItem(IDC_EDIT_CARCOLOR))->SetReadOnly(true);
		((CEdit *)GetDlgItem(IDC_EDIT_ENGINENO))->SetReadOnly(true);
		((CEdit *)GetDlgItem(IDC_EDIT_CLASISNO))->SetReadOnly(true);
		((CEdit *)GetDlgItem(IDC_EDIT_METERNO))->SetReadOnly(true);
		FillData();
		break;
	}


}

void CCarDlg::SetTitle()
{
	switch(operation)
	{
	case 1:
		SetWindowText(_T("添加车辆"));
		break;
	case 2:
		SetWindowText(_T("修改车辆"));
		break;
	case 3:
		SetWindowText(_T("删除车辆"));
		break;
	}

}

void CCarDlg::FillData()
{
	m_strColor=selCar.Car_Color;
	m_strKind=selCar.Car_Kind;
	m_strCarNO=selCar.Car_NO;
	m_strEngineNO=selCar.Car_EngineNO;
	m_strMeterNO=selCar.Car_MeterNO;
	m_strClassisNO=selCar.Car_ClassisNO;

}

void CCarDlg::ClearData()
{
	m_strColor=m_strKind=m_strCarNO=m_strEngineNO=m_strMeterNO=m_strClassisNO="";

}

BOOL CCarDlg::OnInitDialog() 
{	
	SetStyle();
	SetTitle();
	CDialog::OnInitDialog();

	
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CCarDlg::AddCar()
{
	UpdateData(true);
	m_strColor.TrimRight(" ");
	m_strKind.TrimRight(" ");
	m_strCarNO.TrimRight(" ");
	m_strEngineNO.TrimRight(" ");
	m_strMeterNO.TrimRight(" ");
	m_strClassisNO.TrimRight(" ");
	
	
	// Make sure all needed info is available
	CString sWarning="";
	if ( ""==m_strCarNO) sWarning=_T("车号");
	    
	if ( ""!=sWarning ) 
	{
	   sWarning += _T("不能为空");
	   AfxMessageBox(sWarning, MB_ICONEXCLAMATION);
	   return;
	}
        


	// Judge CustomerID is Unique
	_variant_t strQuery = "select * from car where Car_NO='"+m_strCarNO+"'";
	theApp.ADOExecute(theApp.m_pRs, strQuery);
	int iCount = theApp.m_pRs->GetRecordCount();
	if ( 0!=iCount )
	{
	       AfxMessageBox(_T("已经存在此车号的记录！"), MB_ICONEXCLAMATION);
		   return;
	}


	

	strQuery = "insert car(Car_NO,Car_Kind,Car_Color,Car_EngineNO,Car_ClassisNO,Car_MeterNO) \
	         	    values ('"+m_strCarNO+"', '"+m_strKind+"','"+m_strColor+"','"+m_strEngineNO+"','"+m_strClassisNO+"','"+m_strMeterNO+"')";

	if ( theApp.ADOExecute(theApp.m_pRs, strQuery) )
	{
		AfxMessageBox(_T("添加记录成功！"), MB_ICONINFORMATION);
		// Clear all input
		ClearData();
		UpdateData(false);

	}
	else
	{
		AfxMessageBox(_T("添加记录失败！"), MB_ICONEXCLAMATION);
		return;
	}
	CMainFrame* pFrame = (CMainFrame*)AfxGetApp()->m_pMainWnd;
	pFrame->ShowView();

}

void CCarDlg::ModifyCar()
{
	UpdateData(true);
	m_strColor.TrimRight(" ");
	m_strKind.TrimRight(" ");
	m_strCarNO.TrimRight(" ");
	m_strEngineNO.TrimRight(" ");
	m_strMeterNO.TrimRight(" ");
	m_strClassisNO.TrimRight(" ");
	
	
	// Make sure all needed info is available
	CString sWarning="";
	if ( ""==m_strCarNO) sWarning=_T("车号");
	    
	if ( ""!=sWarning ) 
	{
	   sWarning += _T("不能为空");
	   AfxMessageBox(sWarning, MB_ICONEXCLAMATION);
	   return;
	}  

	

	_variant_t strQuery = "Update car set Car_Kind='"+m_strKind+"',Car_Color=\
	'"+m_strColor+"',Car_EngineNO='"+m_strEngineNO+"',Car_ClassisNO=\
	'"+m_strClassisNO+"',Car_MeterNO='"+m_strMeterNO+"' where Car_NO='"+m_strCarNO+"'";

	if ( theApp.ADOExecute(theApp.m_pRs, strQuery) )
	{
		AfxMessageBox(_T("修改记录成功！"), MB_ICONINFORMATION);

	}
	else
	{
		AfxMessageBox(_T("修改记录失败！"), MB_ICONEXCLAMATION);
		return;
	}
	CMainFrame* pFrame = (CMainFrame*)AfxGetApp()->m_pMainWnd;
	pFrame->ShowView();


}

void CCarDlg::DelCar()
{
	bool bDel=false;
	bDel=(MessageBox("删除车辆信息意味着与其相关的基他信息（所属和费用）将一起删除,确认删除吗?","删除警告",MB_YESNO)==IDYES);
	if(!bDel)
		return;

	_variant_t strQuery;


	strQuery = "Delete from car where Car_NO='"+m_strCarNO+"'";
	theApp.ADOExecute(theApp.m_pRs, strQuery);

	strQuery = "Delete from [car-driver] where Car_NO='"+m_strCarNO+"'";
	theApp.ADOExecute(theApp.m_pRs, strQuery);

	strQuery = "Delete from [car-fee] where Car_NO='"+m_strCarNO+"'";
	theApp.ADOExecute(theApp.m_pRs, strQuery);

	CMainFrame* pFrame = (CMainFrame*)AfxGetApp()->m_pMainWnd;
	pFrame->ShowView();

}

void CCarDlg::OnButtonOk() 
{
	switch(operation)
	{
	case 1:
		AddCar();
		break;
	case 2:
		ModifyCar();
		OnOK();
		break;
	case 3:
		DelCar();
		OnOK();
		break;


	}
	// TODO: Add your control notification handler code here
	
}

void CCarDlg::OnButtonCancel() 
{
	OnCancel();
	// TODO: Add your control notification handler code here
	
}

