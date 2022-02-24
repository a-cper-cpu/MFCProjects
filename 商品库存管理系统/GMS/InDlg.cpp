// InDlg.cpp : implementation file
//

#include "stdafx.h"
#include "GMS.h"
#include "InDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CInDlg dialog


CInDlg::CInDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CInDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CInDlg)
	m_Date = 0;
	m_Time = 0;
	m_strNum = _T("");
	m_strPrice = _T("");
	//}}AFX_DATA_INIT
}


void CInDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CInDlg)
	DDX_Control(pDX, IDC_COMBO_PROVIDER, m_cbProvider);
	DDX_Control(pDX, IDC_COMBO_GOODS, m_cbGoods);
	DDX_DateTimeCtrl(pDX, IDC_DATETIMEPICKER_DATE, m_Date);
	DDX_DateTimeCtrl(pDX, IDC_DATETIMEPICKER_TIME, m_Time);
	DDX_Text(pDX, IDC_EDIT_NUM, m_strNum);
	DDX_Text(pDX, IDC_EDIT_PRICE, m_strPrice);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CInDlg, CDialog)
	//{{AFX_MSG_MAP(CInDlg)
	ON_BN_CLICKED(IDC_BUTTON_OK, OnButtonOk)
	ON_BN_CLICKED(IDC_BUTTON_CANCEL, OnButtonCancel)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CInDlg message handlers

BOOL CInDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();

	
	m_Date = CTime::GetCurrentTime();
	m_Time = m_Date;

	m_cbGoods.SetRedraw(false);
	m_cbProvider.SetRedraw(false);

	_variant_t Holder, strQuery;
    strQuery= "select * from goods";
	theApp.ADOExecute(theApp.m_pRs, strQuery);
    int iCount = theApp.m_pRs->GetRecordCount();
	if ( 0==iCount ) 
		return TRUE;
	theApp.m_pRs->MoveFirst();

	int i=0;
	while(!theApp.m_pRs->adoEOF)
	{
		Holder = theApp.m_pRs->GetCollect("G_name");
		if(Holder.vt!=VT_NULL)
			m_cbGoods.AddString((LPCTSTR)(_bstr_t)Holder);	

		theApp.m_pRs->MoveNext();
		i++;
	}

	strQuery= "select * from provider";
	theApp.ADOExecute(theApp.m_pRs, strQuery);
    iCount = theApp.m_pRs->GetRecordCount();
	if ( 0==iCount ) 
		return TRUE;
	theApp.m_pRs->MoveFirst();

    i=0;
	while(!theApp.m_pRs->adoEOF)
	{
		Holder = theApp.m_pRs->GetCollect("Provider_name");
		if(Holder.vt!=VT_NULL)
			m_cbProvider.AddString((LPCTSTR)(_bstr_t)Holder);	

		theApp.m_pRs->MoveNext();
		i++;
	}
	m_cbGoods.SetRedraw(true);
	m_cbProvider.SetRedraw(true);
	UpdateData(FALSE);
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CInDlg::OnButtonOk() 
{
	UpdateData();

	m_cbGoods.GetWindowText(m_strGoodsName);
	m_cbProvider.GetWindowText(m_strProviderName);

	CString strGcode,strPcode;

	GetGoodsCode(m_strGoodsName,strGcode);
	GetProviderCode(m_strProviderName,strPcode);

	AddIn(strGcode,strPcode);

	AddGoods(atoi(m_strNum));

	// TODO: Add your control notification handler code here
	
}

void CInDlg::GetGoodsCode(CString strName, CString &strCode)
{
	_variant_t Holder, strQuery;
    strQuery= "select * from goods where G_name='"+strName+"'";
	theApp.ADOExecute(theApp.m_pRs, strQuery);

	theApp.m_pRs->MoveFirst();

		Holder = theApp.m_pRs->GetCollect("G_code");
		if(Holder.vt!=VT_NULL)
			strCode=Holder.bstrVal;


}

void CInDlg::GetProviderCode(CString strName, CString &strCode)
{
	_variant_t Holder, strQuery;
    strQuery= "select * from provider where Provider_name='"+strName+"'";
	theApp.ADOExecute(theApp.m_pRs, strQuery);


	theApp.m_pRs->MoveFirst();

		Holder = theApp.m_pRs->GetCollect("Provider_code");
		if(Holder.vt!=VT_NULL)
			strCode=Holder.bstrVal;

}

void CInDlg::AddGoods(int iNum)
{
	int iCurrentNum=0;
	_variant_t Holder, strQuery;
    strQuery= "select * from goods where G_name='"+m_strGoodsName+"'";
	theApp.ADOExecute(theApp.m_pRs, strQuery);

	theApp.m_pRs->MoveFirst();

	Holder = theApp.m_pRs->GetCollect("Current_number");
	if(Holder.vt!=VT_NULL)
		iCurrentNum=Holder.iVal;
	iCurrentNum+=iNum;

	CString strSql;

	strSql.Format("UPDATE goods SET Current_number=%d WHERE G_name='%s'",iCurrentNum,m_strGoodsName);	// TODO: Add your control notification handler code here
	_variant_t  vtQuery(strSql);  
	if(	theApp.ADOExecute(theApp.m_pRs, vtQuery))
	{
		AfxMessageBox("入库成功");
		theApp.m_log.AddLog("商品入库");
	}
	


}

void CInDlg::AddIn(CString strGcode,CString strPcode)
{
	CString strSql;
	CString strDate=m_Date.Format("%Y-%m-%d ");
	strDate+=m_Time.Format("%H:%M:%S");

	strSql.Format("INSERT INTO inlib VALUES('%s','%s',%s,%s,'%s')",
		strGcode,strPcode, m_strNum, m_strPrice,strDate);
	_variant_t  vtQuery(strSql);  
	theApp.ADOExecute(theApp.m_pRs, vtQuery);      
	
	theApp.m_log.AddLog("添加入库");

}

void CInDlg::OnButtonCancel() 
{
	OnCancel();
	// TODO: Add your control notification handler code here
	
}
