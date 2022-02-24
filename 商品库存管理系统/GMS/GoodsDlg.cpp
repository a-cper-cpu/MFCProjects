// GoodsDlg.cpp : implementation file
//

#include "stdafx.h"
#include "GMS.h"
#include "GoodsDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CGoodsDlg dialog


CGoodsDlg::CGoodsDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CGoodsDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CGoodsDlg)
	m_strCode = _T("");
	m_strMaxNum = _T("");
	m_strMinNum = _T("");
	m_strName = _T("");
	//}}AFX_DATA_INIT
}


void CGoodsDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CGoodsDlg)
	DDX_Control(pDX, IDC_LIST_DISP, m_listDisp);
	DDX_Text(pDX, IDC_EDIT_CODE, m_strCode);
	DDX_Text(pDX, IDC_EDIT_MAXNUM, m_strMaxNum);
	DDX_Text(pDX, IDC_EDIT_MINNUM, m_strMinNum);
	DDX_Text(pDX, IDC_EDIT_NAME, m_strName);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CGoodsDlg, CDialog)
	//{{AFX_MSG_MAP(CGoodsDlg)
	ON_BN_CLICKED(IDC_BUTTON_ADD, OnButtonAdd)
	ON_BN_CLICKED(IDC_BUTTON_MODIFY, OnButtonModify)
	ON_BN_CLICKED(IDC_BUTTON_DELETE, OnButtonDelete)
	ON_BN_CLICKED(IDC_BUTTON_EXIT, OnButtonExit)
	ON_NOTIFY(NM_CLICK, IDC_LIST_DISP, OnClickListDisp)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CGoodsDlg message handlers

BOOL CGoodsDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();

    m_listDisp.InsertColumn(0,"商品编号");
	m_listDisp.InsertColumn(1,"商品名称");
	m_listDisp.InsertColumn(2,"当前库存");
	m_listDisp.InsertColumn(3,"最大库存");
	m_listDisp.InsertColumn(4,"最小库存");
	
	RECT rect;
	m_listDisp.GetWindowRect(&rect);
	int wid = rect.right - rect.left;
	m_listDisp.SetColumnWidth(0,wid/5);
	m_listDisp.SetColumnWidth(1,wid/5);
	m_listDisp.SetColumnWidth(2,wid/5);
	m_listDisp.SetColumnWidth(3,wid/5);
	m_listDisp.SetColumnWidth(4,wid/5);
	m_listDisp.SetExtendedStyle(LVS_EX_FULLROWSELECT);


	RefreshData();
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CGoodsDlg::RefreshData()
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

	m_listDisp.SetRedraw(TRUE);	
	


}

void CGoodsDlg::OnButtonAdd() 
{
	UpdateData();

	CString strSql;

	strSql.Format("INSERT INTO goods (G_code,G_name,Current_number,Max_number,Min_number) VALUES('%s','%s',0,%s,%s)",
		m_strCode, m_strName, m_strMaxNum,m_strMinNum		);
	_variant_t  vtQuery(strSql);  
	theApp.ADOExecute(theApp.m_pRs, vtQuery);
      
	RefreshData(); 
	ClearTxt();
	
	theApp.m_log.AddLog("添加商品");
        


	// TODO: Add your control notification handler code here
	
}

void CGoodsDlg::ClearTxt()
{
	m_strCode="";
	m_strName="";
	m_strMaxNum="";
	m_strMinNum="";
	UpdateData(false);

}

void CGoodsDlg::OnButtonModify() 
{
	UpdateData();

	CString strSql;

	strSql.Format("UPDATE goods SET G_name='%s',Max_number=%s,Min_number=%s WHERE G_code='%s'",m_strName, m_strMaxNum,m_strMinNum,m_strCode);	// TODO: Add your control notification handler code here
	_variant_t  vtQuery(strSql);  
	if(theApp.ADOExecute(theApp.m_pRs, vtQuery))
	{
		RefreshData(); 
		ClearTxt();
		theApp.m_log.AddLog("修改商品");
	}
	else
	{
		AfxMessageBox("修改失败");

	}
	
}

void CGoodsDlg::OnButtonDelete() 
{
	// TODO: Add your control notification handler code here
	UpdateData();
	CString strSql;
	strSql.Format("DELETE FROM goods WHERE G_code='%s'",m_strCode);
	_variant_t  vtQuery(strSql);  
	theApp.ADOExecute(theApp.m_pRs, vtQuery);
	RefreshData(); 
	ClearTxt();
	
	theApp.m_log.AddLog("删除商品");
	
}

void CGoodsDlg::OnButtonExit() 
{
	OnOK();
	// TODO: Add your control notification handler code here
	
}

void CGoodsDlg::OnClickListDisp(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	int i = m_listDisp.GetSelectionMark();

	m_strCode = m_listDisp.GetItemText(i,0);
	m_strName= m_listDisp.GetItemText(i,1);
	m_strMaxNum = m_listDisp.GetItemText(i,3);
	m_strMinNum= m_listDisp.GetItemText(i,4);

	
	UpdateData(FALSE);
	
	*pResult = 0;
}
