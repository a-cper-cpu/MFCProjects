// OrderPage.cpp : implementation file
//

#include "stdafx.h"
#include "RMS.h"
#include "OrderPage.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// COrderPage property page

IMPLEMENT_DYNCREATE(COrderPage, CPropertyPage)

COrderPage::COrderPage() : CPropertyPage(COrderPage::IDD)
{
	//{{AFX_DATA_INIT(COrderPage)
	m_strNum = _T("");
	m_Date = 0;
	m_strDeskCode = _T("");
	m_strDishCode = _T("");
	//}}AFX_DATA_INIT
}

COrderPage::~COrderPage()
{
}

void COrderPage::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(COrderPage)
	DDX_Control(pDX, IDC_LIST_DISP, m_listDisp);
	DDX_Text(pDX, IDC_EDIT_NUM, m_strNum);
	DDX_DateTimeCtrl(pDX, IDC_DATETIMEPICKER_DATE, m_Date);
	DDX_Text(pDX, IDC_EDIT_DESKCODE, m_strDeskCode);
	DDX_Text(pDX, IDC_EDIT_DISHCODE, m_strDishCode);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(COrderPage, CPropertyPage)
	//{{AFX_MSG_MAP(COrderPage)
	ON_BN_CLICKED(IDC_BUTTON_ADD, OnButtonAdd)
	ON_BN_CLICKED(IDC_BUTTON_MODIFY, OnButtonModify)
	ON_BN_CLICKED(IDC_BUTTON_DEL, OnButtonDel)
	ON_BN_CLICKED(IDC_BUTTON_CLEAR, OnButtonClear)
	ON_NOTIFY(NM_CLICK, IDC_LIST_DISP, OnClickListDisp)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// COrderPage message handlers

BOOL COrderPage::OnInitDialog() 
{
	CPropertyPage::OnInitDialog();

	if (!m_rsDataSet.Open(AFX_DB_USE_DEFAULT_TYPE))
		AfxMessageBox("数据打开失败！");


	m_listDisp.InsertColumn(0,"桌号");
	m_listDisp.InsertColumn(1,"菜号");
	m_listDisp.InsertColumn(2,"份数");
	m_listDisp.InsertColumn(3,"时间");
	m_listDisp.InsertColumn(4,"付款");
	
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

	m_Date=CTime::GetCurrentTime();

	UpdateData(false);
	
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void COrderPage::RefreshData()
{
	if(m_rsDataSet.IsBOF())
		return;

	m_listDisp.DeleteAllItems();
	m_listDisp.SetRedraw(FALSE);
	

    m_rsDataSet.MoveFirst();
	int i=0;
	CString strNum;
	while(!m_rsDataSet.IsEOF())
	{
		strNum.Format("%d",m_rsDataSet.m_Dish_num);
		m_listDisp.InsertItem(i, m_rsDataSet.m_Desk_code);
		m_listDisp.SetItemText(i, 1,m_rsDataSet.m_Dish_code);
		m_listDisp.SetItemText(i, 2,strNum);
		m_listDisp.SetItemText(i, 3, m_rsDataSet.m_AppendDate.Format("%y-%m-%d %H:%M:%S"));
		m_listDisp.SetItemText(i, 4, m_rsDataSet.m_PayFor==1?"是":"否");
		m_rsDataSet.MoveNext();
		i++;
	}

	m_listDisp.SetRedraw(TRUE);	


}



void COrderPage::OnButtonAdd() 
{
	UpdateData();
	if (m_strDeskCode.IsEmpty() || m_strDishCode.IsEmpty())
	{
		AfxMessageBox("请输入菜谱！");
		return;
	}
	int iNum;
	m_rsDataSet.AddNew();

	iNum=(int)atoi((LPCTSTR)m_strNum);

	m_rsDataSet.m_Desk_code=m_strDeskCode;
	m_rsDataSet.m_Dish_code=m_strDishCode;
	m_rsDataSet.m_Dish_num=iNum;
	m_rsDataSet.m_AppendDate=m_Date;
	m_rsDataSet.m_PayFor=0;

	m_rsDataSet.Update();
	m_rsDataSet.Requery();

	RefreshData();
	// TODO: Add your control notification handler code here
	
}

void COrderPage::OnButtonModify() 
{
	UpdateData();
	m_rsDataSet.m_strFilter="Desk_code='"+m_strDeskCode;
	m_rsDataSet.m_strFilter+="'";
	m_rsDataSet.Requery();

	m_rsDataSet.Edit();

	int iNum=atoi((LPCTSTR)m_strNum);

	m_rsDataSet.m_Desk_code=m_strDeskCode;
	m_rsDataSet.m_Dish_code=m_strDishCode;
	m_rsDataSet.m_Dish_num=iNum;
	m_rsDataSet.m_AppendDate=m_Date;


	m_rsDataSet.Update();
	m_rsDataSet.m_strFilter="";
	m_rsDataSet.Requery();

	RefreshData();
	// TODO: Add your control notification handler code here
	
}

void COrderPage::OnButtonDel() 
{
	UpdateData();
	if(m_strDeskCode=="")
		AfxMessageBox("请选择一个订单进行删除!");
	m_rsDataSet.m_strFilter="Desk_code='"+m_strDeskCode;
	m_rsDataSet.m_strFilter+="'";
	m_rsDataSet.Requery();
	m_rsDataSet.Delete();

	m_strDeskCode="";
	m_strDishCode="";
	m_strNum="";
	m_Date=CTime::GetCurrentTime();

	m_rsDataSet.m_strFilter="";
	m_rsDataSet.Requery();
	RefreshData();
	UpdateData(false);
	// TODO: Add your control notification handler code here
	
}

void COrderPage::OnButtonClear() 
{
	m_Date=CTime::GetCurrentTime();
	m_strDeskCode="";
	m_strDishCode="";
	m_strNum="";
	UpdateData(false);
	// TODO: Add your control notification handler code here
	
}

void COrderPage::OnClickListDisp(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	int i = m_listDisp.GetSelectionMark();

	m_strDeskCode = m_listDisp.GetItemText(i,0);	
	m_strDishCode= m_listDisp.GetItemText(i,1);
	m_strNum= m_listDisp.GetItemText(i,2);
	CString strDate=m_listDisp.GetItemText(i,3);
	long y,m,d;
	sscanf(strDate.GetBuffer(strDate.GetLength()),"%d-%d-%d",&y,&m,&d);
	if(y<1000)
		y+=2000;

	CTime time(y,m,d,0,0,0);


	m_Date=time;

	
	UpdateData(FALSE);
	*pResult = 0;
}
