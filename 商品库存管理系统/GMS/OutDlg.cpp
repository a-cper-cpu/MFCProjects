// OutDlg.cpp : implementation file
//

#include "stdafx.h"
#include "GMS.h"
#include "OutDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// COutDlg dialog


COutDlg::COutDlg(CWnd* pParent /*=NULL*/)
	: CDialog(COutDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(COutDlg)
	m_strCNum = _T("");
	m_strONum = _T("");
	m_strPerson = _T("");
	m_Time = 0;
	m_Date = 0;
	//}}AFX_DATA_INIT
}


void COutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(COutDlg)
	DDX_Control(pDX, IDC_COMBO_GOODS, m_cbGoods);
	DDX_Text(pDX, IDC_EDIT_CNUM, m_strCNum);
	DDX_Text(pDX, IDC_EDIT_ONUM, m_strONum);
	DDX_Text(pDX, IDC_EDIT_PERSON, m_strPerson);
	DDX_DateTimeCtrl(pDX, IDC_DATETIMEPICKER_TIME, m_Time);
	DDX_DateTimeCtrl(pDX, IDC_DATETIMEPICKER_DATE, m_Date);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(COutDlg, CDialog)
	//{{AFX_MSG_MAP(COutDlg)
	ON_BN_CLICKED(IDC_BUTTON_CANCEL, OnButtonCancel)
	ON_BN_CLICKED(IDC_BUTTON_OK, OnButtonOk)
	ON_WM_CANCELMODE()
	ON_CBN_SELCHANGE(IDC_COMBO_GOODS, OnSelchangeComboGoods)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// COutDlg message handlers

void COutDlg::OnButtonCancel() 
{
	OnCancel();
	// TODO: Add your control notification handler code here
	
}

void COutDlg::OnButtonOk() 
{	
	UpdateData();

	if(atoi(m_strONum)>atoi(m_strCNum))
	{
		AfxMessageBox("库存不足，请重新输入出库数量");
		m_strONum="";
		UpdateData(false);
	}

	m_cbGoods.GetWindowText(m_strGoodsName);

	CString strGcode;

	GetGoodsCode(m_strGoodsName,strGcode);

	AddOut(strGcode);

	DelGoods(atoi(m_strONum));

	// TODO: Add your control notification handler code here
	
}

BOOL COutDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	m_Date = CTime::GetCurrentTime();
	m_Time = m_Date;

	m_cbGoods.SetRedraw(false);


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


	m_cbGoods.SetRedraw(true);





	UpdateData(FALSE);
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void COutDlg::OnCancelMode() 
{
	CDialog::OnCancelMode();
	
	// TODO: Add your message handler code here
	
}

void COutDlg::OnSelchangeComboGoods() 
{
	UpdateData();
	m_cbGoods.GetLBText(m_cbGoods.GetCurSel(),m_strGoodsName);

	_variant_t Holder, strQuery;
    strQuery= "select * from goods where G_name='"+m_strGoodsName+"'";
	theApp.ADOExecute(theApp.m_pRs, strQuery);

	theApp.m_pRs->MoveFirst();

		Holder = theApp.m_pRs->GetCollect("Current_number");
		if(Holder.vt!=VT_NULL)
			m_strCNum.Format("%d",Holder.iVal);
	UpdateData(false);

	// TODO: Add your control notification handler code here
	
}

void COutDlg::DelGoods(int iNum)
{
	int iCurrentNum=0;
	_variant_t Holder, strQuery;
    strQuery= "select * from goods where G_name='"+m_strGoodsName+"'";
	theApp.ADOExecute(theApp.m_pRs, strQuery);

	theApp.m_pRs->MoveFirst();

	Holder = theApp.m_pRs->GetCollect("Current_number");
	if(Holder.vt!=VT_NULL)
		iCurrentNum=Holder.iVal;
	iCurrentNum-=iNum;

	CString strSql;

	strSql.Format("UPDATE goods SET Current_number=%d WHERE G_name='%s'",iCurrentNum,m_strGoodsName);	// TODO: Add your control notification handler code here
	_variant_t  vtQuery(strSql);  
	if(	theApp.ADOExecute(theApp.m_pRs, vtQuery))
	{
		AfxMessageBox("出库成功");
		theApp.m_log.AddLog("商品出库");
	}
	

}

void COutDlg::AddOut(CString strGcode)
{
	CString strSql;
	CString strDate=m_Date.Format("%Y-%m-%d ");
	strDate+=m_Time.Format("%H:%M:%S");

	strSql.Format("INSERT INTO outlib VALUES('%s',%s,'%s','%s','%s')",
		strGcode,m_strONum, strAdminName, m_strPerson,strDate);
	_variant_t  vtQuery(strSql);  
	theApp.ADOExecute(theApp.m_pRs, vtQuery);      
	
	theApp.m_log.AddLog("添加出库");

}

void COutDlg::GetGoodsCode(CString strName, CString &strCode)
{
	_variant_t Holder, strQuery;
    strQuery= "select * from goods where G_name='"+strName+"'";
	theApp.ADOExecute(theApp.m_pRs, strQuery);

	theApp.m_pRs->MoveFirst();

	Holder = theApp.m_pRs->GetCollect("G_code");
	if(Holder.vt!=VT_NULL)
		strCode=Holder.bstrVal;

}
