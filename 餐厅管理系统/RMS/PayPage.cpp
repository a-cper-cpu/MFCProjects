// PayPage.cpp : implementation file
//

#include "stdafx.h"
#include "RMS.h"
#include "PayPage.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPayPage property page

IMPLEMENT_DYNCREATE(CPayPage, CPropertyPage)

CPayPage::CPayPage() : CPropertyPage(CPayPage::IDD)
{
	//{{AFX_DATA_INIT(CPayPage)
	m_strMoney = _T("");
	m_strDishName = _T("");
	m_strDishCode = _T("");
	m_Date = 0;
	m_strDeskCode = _T("");
	//}}AFX_DATA_INIT
}

CPayPage::~CPayPage()
{
}

void CPayPage::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPayPage)
	DDX_Control(pDX, IDC_LIST_DISP, m_listDisp);
	DDX_Text(pDX, IDC_EDIT_MONEY, m_strMoney);
	DDX_Text(pDX, IDC_EDIT_DISHNAME, m_strDishName);
	DDX_Text(pDX, IDC_EDIT_DISHCODE, m_strDishCode);
	DDX_DateTimeCtrl(pDX, IDC_DATETIMEPICKER_DATE, m_Date);
	DDX_Text(pDX, IDC_EDIT_DESKCODE, m_strDeskCode);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CPayPage, CPropertyPage)
	//{{AFX_MSG_MAP(CPayPage)
	ON_NOTIFY(NM_CLICK, IDC_LIST_DISP, OnClickListDisp)
	ON_BN_CLICKED(IDC_BUTTON_PAY, OnButtonPay)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPayPage message handlers

BOOL CPayPage::OnInitDialog() 
{
	CPropertyPage::OnInitDialog();
		CPropertyPage::OnInitDialog();

	if (!m_rsDataSet.Open(AFX_DB_USE_DEFAULT_TYPE))
		AfxMessageBox("数据打开失败！");

	if (!m_rsDataSetEx.Open(AFX_DB_USE_DEFAULT_TYPE))
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

void CPayPage::RefreshData()
{
	if(m_rsDataSetEx.IsBOF())
		return;

	m_listDisp.DeleteAllItems();
	m_listDisp.SetRedraw(FALSE);
	

    m_rsDataSetEx.MoveFirst();
	int i=0;
	CString strNum;
	while(!m_rsDataSetEx.IsEOF())
	{
		strNum.Format("%d",m_rsDataSetEx.m_Dish_num);
		m_listDisp.InsertItem(i, m_rsDataSetEx.m_Desk_code);
		m_listDisp.SetItemText(i, 1,m_rsDataSetEx.m_Dish_code);
		m_listDisp.SetItemText(i, 2,strNum);
		m_listDisp.SetItemText(i, 3, m_rsDataSetEx.m_AppendDate.Format("%y-%m-%d %H:%M:%S"));
		m_listDisp.SetItemText(i, 4, m_rsDataSetEx.m_PayFor==1?"是":"否");
		m_rsDataSetEx.MoveNext();
		i++;
	}

	m_listDisp.SetRedraw(TRUE);	

}

void CPayPage::OnClickListDisp(NMHDR* pNMHDR, LRESULT* pResult) 
{
	int i = m_listDisp.GetSelectionMark();

	m_strDeskCode = m_listDisp.GetItemText(i,0);	
	m_strDishCode= m_listDisp.GetItemText(i,1);
	int num=atoi((LPCTSTR)m_listDisp.GetItemText(i,2));
	CString strDate=m_listDisp.GetItemText(i,3);
	long y,m,d;
	sscanf(strDate.GetBuffer(strDate.GetLength()),"%d-%d-%d",&y,&m,&d);
	if(y<1000)
		y+=2000;
	CTime time(y,m,d,0,0,0);
	m_Date=time;

	m_rsDataSet.m_strFilter="dish.Dish_code='"+m_strDishCode;
	m_rsDataSet.m_strFilter+="'";
	m_rsDataSet.m_strFilter=m_rsDataSet.m_strFilter+" AND order.Desk_code='"+m_strDeskCode;
	m_rsDataSet.m_strFilter+="'";
	m_rsDataSet.Requery();



	m_strMoney.Format("%.2f",m_rsDataSet.m_Dish_price*num);
	m_strDishName=m_rsDataSet.m_Dish_name;

	m_rsDataSet.m_strFilter="";
	m_rsDataSet.Requery();



	
	UpdateData(FALSE);
	// TODO: Add your control notification handler code here
	
	*pResult = 0;
}

void CPayPage::OnButtonPay() 
{
	UpdateData();
	m_rsDataSetEx.m_strFilter="Desk_code='"+m_strDeskCode;
	m_rsDataSetEx.m_strFilter+="'";
	m_rsDataSetEx.Requery();

	m_rsDataSetEx.Edit();



	m_rsDataSetEx.m_PayFor=1;


	m_rsDataSetEx.Update();
	m_rsDataSetEx.m_strFilter="";
	m_rsDataSetEx.Requery();

	RefreshData();
	AfxMessageBox("结算完毕!");
	// TODO: Add your control notification handler code here
	
}


