// CarDriverDlg.cpp : implementation file
//

#include "stdafx.h"
#include "TMS.h"
#include "CarDriverDlg.h"
#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCarDriverDlg dialog


CCarDriverDlg::CCarDriverDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CCarDriverDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CCarDriverDlg)
	m_strDriverName = _T("");
	//}}AFX_DATA_INIT
}


void CCarDriverDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCarDriverDlg)
	DDX_Control(pDX, IDC_COMBO_ISWORK, m_cbIsWork);
	DDX_Control(pDX, IDC_COMBO_DRIVERNO, m_cbDriverNO);
	DDX_Control(pDX, IDC_COMBO_CARNO, m_cbCarNO);
	DDX_Text(pDX, IDC_EDIT_DRIVERNAME, m_strDriverName);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CCarDriverDlg, CDialog)
	//{{AFX_MSG_MAP(CCarDriverDlg)
	ON_CBN_SELCHANGE(IDC_COMBO_DRIVERNO, OnSelchangeComboDriverno)
	ON_BN_CLICKED(IDC_BUTTON_OK, OnButtonOk)
	ON_BN_CLICKED(IDC_BUTTON_CANCEL, OnButtonCancel)
	ON_CBN_SELCHANGE(IDC_COMBO_CARNO, OnSelchangeComboCarno)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCarDriverDlg message handlers

void CCarDriverDlg::OnSelchangeComboDriverno() 
{
	UpdateData();
	CString strNO;
	m_cbDriverNO.GetLBText(m_cbDriverNO.GetCurSel(),strNO);

	_variant_t Holder, strQuery;
    strQuery= "select * from driver where Driver_NO='"+strNO+"'";
	theApp.ADOExecute(theApp.m_pRs, strQuery);

	theApp.m_pRs->MoveFirst();

		Holder = theApp.m_pRs->GetCollect("Driver_Name");
		if(Holder.vt!=VT_NULL)
			m_strDriverName.Format("%s",(char*)(_bstr_t)Holder);
	UpdateData(false);
	// TODO: Add your control notification handler code here
	
}

void CCarDriverDlg::SetStyle()
{

	switch(operation)
	{
	case 1:
		((CComboBox *)GetDlgItem(IDC_COMBO_CARNO))->EnableWindow(true);
		((CComboBox *)GetDlgItem(IDC_COMBO_DRIVERNO))->EnableWindow(true);
		((CComboBox *)GetDlgItem(IDC_COMBO_ISWORK))->EnableWindow(true);
		ClearData();
		break;
	case 2:
		((CComboBox *)GetDlgItem(IDC_COMBO_CARNO))->EnableWindow(false);
		((CComboBox *)GetDlgItem(IDC_COMBO_DRIVERNO))->EnableWindow(false);
		((CComboBox *)GetDlgItem(IDC_COMBO_ISWORK))->EnableWindow(true);
		FillData();
		break;
	case 3:
		((CComboBox *)GetDlgItem(IDC_COMBO_CARNO))->EnableWindow(false);
		((CComboBox *)GetDlgItem(IDC_COMBO_DRIVERNO))->EnableWindow(false);
		((CComboBox *)GetDlgItem(IDC_COMBO_ISWORK))->EnableWindow(false);
		FillData();
		break;
	}



}

void CCarDriverDlg::SetTitle()
{
	switch(operation)
	{
	case 1:
		SetWindowText(_T("添加关系"));
		break;
	case 2:
		SetWindowText(_T("修改关系"));
		break;
	case 3:
		SetWindowText(_T("删除关系"));
		break;
	}


}

void CCarDriverDlg::ClearData()
{

	m_strDriverName="";
}

void CCarDriverDlg::FillData()
{
	m_cbCarNO.SetCurSel(m_cbCarNO.FindString(-1,selCarDriver.CarNO));
	m_cbDriverNO.SetCurSel(m_cbDriverNO.FindString(-1,selCarDriver.DriverNO));
	m_cbIsWork.SetCurSel(selCarDriver.IsWork);
	OnSelchangeComboDriverno();



}

BOOL CCarDriverDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	GetCBData();
	SetStyle();
	SetTitle();

	
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CCarDriverDlg::GetCBData()
{
		m_cbCarNO.SetRedraw(false);
	m_cbDriverNO.SetRedraw(false);


	_variant_t Holder, strQuery;
    strQuery= "select * from car";
	theApp.ADOExecute(theApp.m_pRs, strQuery);
    int iCount = theApp.m_pRs->GetRecordCount();
	if ( 0==iCount ) 
		return;
	theApp.m_pRs->MoveFirst();

	int i=0;
	while(!theApp.m_pRs->adoEOF)
	{
		Holder = theApp.m_pRs->GetCollect("Car_NO");
		if(Holder.vt!=VT_NULL)
			m_cbCarNO.AddString((LPCTSTR)(_bstr_t)Holder);	

		theApp.m_pRs->MoveNext();
		i++;
	}


	strQuery= "select * from driver";
	theApp.ADOExecute(theApp.m_pRs, strQuery);
    iCount = theApp.m_pRs->GetRecordCount();
	if ( 0==iCount ) 
		return;
	theApp.m_pRs->MoveFirst();

	i=0;
	while(!theApp.m_pRs->adoEOF)
	{
		Holder = theApp.m_pRs->GetCollect("Driver_NO");
		if(Holder.vt!=VT_NULL)
			m_cbDriverNO.AddString((LPCTSTR)(_bstr_t)Holder);	

		theApp.m_pRs->MoveNext();
		i++;
	}

	m_cbDriverNO.SetRedraw(true);
	m_cbCarNO.SetRedraw(true);


}


void CCarDriverDlg::OnButtonOk() 
{
	switch(operation)
	{
	case 1:
		AddCarDriver();
		break;
	case 2:
		ModifyCarDriver();
		OnOK();
		break;
	case 3:
		DelCarDriver();
		OnOK();
		break;


	}

	// TODO: Add your control notification handler code here
	
}

void CCarDriverDlg::OnButtonCancel() 
{
	OnCancel();
	// TODO: Add your control notification handler code here
	
}

void CCarDriverDlg::AddCarDriver()
{
	CString strCarNO,strDriverNO,strIsWork;
	UpdateData(true);
	m_cbCarNO.GetWindowText(strCarNO);
	m_cbDriverNO.GetWindowText(strDriverNO);
	m_cbIsWork.GetWindowText(strIsWork);

	
	
	// Make sure all needed info is available
	CString sWarning="";
	if ( ""==strCarNO) sWarning=_T("车号");
	if ( ""==strDriverNO) sWarning=_T("司机号");
	if ( ""==strIsWork) sWarning=_T("任职关系");
	    
	if ( ""!=sWarning ) 
	{
	   sWarning += _T("不能为空");
	   AfxMessageBox(sWarning, MB_ICONEXCLAMATION);
	   return;
	}
        


	// Judge record is Unique
	_variant_t strQuery = "select * from [car-driver] where Car_NO='"+strCarNO+"' AND Driver_NO='"+strDriverNO+"'";
	theApp.ADOExecute(theApp.m_pRs, strQuery);
	int iCount = theApp.m_pRs->GetRecordCount();
	if ( 0!=iCount )
	{
	       AfxMessageBox(_T("已经存在此记录！"), MB_ICONEXCLAMATION);
		   return;
	}

	//else
	if (strIsWork=="是")
		strIsWork="1";
	else
		strIsWork="0";


	

	strQuery = "insert [car-driver] (Car_NO,Driver_NO,IsWork) \
	 values ('"+strCarNO+"', '"+strDriverNO+"',"+strIsWork+")";

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

void CCarDriverDlg::ModifyCarDriver()
{
	UpdateData(true);

	
	
	// Make sure all needed info is available
	CString strIsWork,strCarNO,strDriverNO;
	strIsWork.Format("%d",m_cbIsWork.GetCurSel());
	m_cbCarNO.GetWindowText(strCarNO);
	m_cbDriverNO.GetWindowText(strDriverNO);


	

	_variant_t strQuery = "Update [car-driver] set IsWork="+strIsWork+" where\
	Car_NO='"+strCarNO+"' AND Driver_NO='"+strDriverNO+"'";

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

void CCarDriverDlg::DelCarDriver()
{
	bool bDel=false;
	bDel=(MessageBox("删除车辆所属关系,确认删除吗?","删除警告",MB_YESNO)==IDYES);
	if(!bDel)
		return;

	_variant_t strQuery;

	CString strCarNO;
	m_cbCarNO.GetWindowText(strCarNO);



	strQuery = "Delete from [car-driver] where Car_NO='"+strCarNO+"'";
	theApp.ADOExecute(theApp.m_pRs, strQuery);


	CMainFrame* pFrame = (CMainFrame*)AfxGetApp()->m_pMainWnd;
	pFrame->ShowView();

}

void CCarDriverDlg::OnSelchangeComboCarno() 
{
	UpdateData();
	CString strCarNO,strDriverNO;
	m_cbCarNO.GetLBText(m_cbCarNO.GetCurSel(),strCarNO);

	_variant_t Holder, strQuery;
    strQuery= "select * from [car-driver] where Car_NO='"+strCarNO+"'";
	theApp.ADOExecute(theApp.m_pRs, strQuery);
	int iCount = theApp.m_pRs->GetRecordCount();
	if ( 0==iCount )
	{	 
		m_cbDriverNO.EnableWindow(true);
		return;
	}

	theApp.m_pRs->MoveFirst();

	Holder = theApp.m_pRs->GetCollect("Driver_NO");
	if(Holder.vt!=VT_NULL)
			strDriverNO.Format("%s",(char*)(_bstr_t)Holder);
	m_cbDriverNO.SetCurSel(m_cbDriverNO.FindString(-1,strDriverNO));
	m_cbDriverNO.EnableWindow(false);
	OnSelchangeComboDriverno();

	// TODO: Add your control notification handler code here
	
}
