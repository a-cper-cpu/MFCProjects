// DishPage.cpp : implementation file
//

#include "stdafx.h"
#include "RMS.h"
#include "DishPage.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDishPage property page

IMPLEMENT_DYNCREATE(CDishPage, CPropertyPage)

CDishPage::CDishPage() : CPropertyPage(CDishPage::IDD)
{
	//{{AFX_DATA_INIT(CDishPage)
	m_strPrice = _T("");
	m_strName = _T("");
	m_strKind = _T("");
	m_strDesc = _T("");
	m_strCode = _T("");
	//}}AFX_DATA_INIT
}

CDishPage::~CDishPage()
{
}

void CDishPage::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDishPage)
	DDX_Control(pDX, IDC_LIST_DISP, m_listDisp);
	DDX_Text(pDX, IDC_EDIT_PRICE, m_strPrice);
	DDX_Text(pDX, IDC_EDIT_NAME, m_strName);
	DDX_Text(pDX, IDC_EDIT_KIND, m_strKind);
	DDX_Text(pDX, IDC_EDIT_DESC, m_strDesc);
	DDX_Text(pDX, IDC_EDIT_CODE, m_strCode);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDishPage, CPropertyPage)
	//{{AFX_MSG_MAP(CDishPage)
	ON_BN_CLICKED(IDC_BUTTON_ADD, OnButtonAdd)
	ON_NOTIFY(NM_CLICK, IDC_LIST_DISP, OnClickListDisp)
	ON_BN_CLICKED(IDC_BUTTON_MODIFY, OnButtonModify)
	ON_BN_CLICKED(IDC_BUTTON_DEL, OnButtonDel)
	ON_BN_CLICKED(IDC_BUTTON_CLEAR, OnButtonClear)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDishPage message handlers

void CDishPage::OnButtonAdd() 
{
	UpdateData();
	if (m_strCode.IsEmpty() || m_strName.IsEmpty())
	{
		AfxMessageBox("请输入菜谱！");
		return;
	}
	float fPrice=(float)atof((LPCTSTR)m_strPrice);
	m_rsDataSet.AddNew();

	m_rsDataSet.m_Dish_code=m_strCode;
	m_rsDataSet.m_Dish_name=m_strName;
	m_rsDataSet.m_Dish_kind=m_strKind;
	m_rsDataSet.m_Dish_price=fPrice;
	m_rsDataSet.m_Dish_detail=m_strDesc;

	m_rsDataSet.Update();
	m_rsDataSet.Requery();

	RefreshData();
	// TODO: Add your control notification handler code here
	
}

BOOL CDishPage::OnInitDialog() 
{
	CPropertyPage::OnInitDialog();

	if (!m_rsDataSet.Open(AFX_DB_USE_DEFAULT_TYPE))
		AfxMessageBox("数据打开失败！");

	m_listDisp.InsertColumn(0,"菜谱号");
	m_listDisp.InsertColumn(1,"菜名");
	m_listDisp.InsertColumn(2,"种类");
	m_listDisp.InsertColumn(3,"价格");
	m_listDisp.InsertColumn(4,"备注");
	
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

void CDishPage::RefreshData()
{	
	if(m_rsDataSet.IsBOF())
		return;

	m_listDisp.DeleteAllItems();
	m_listDisp.SetRedraw(FALSE);
	

    m_rsDataSet.MoveFirst();
	int i=0;
	CString strPrice;
	while(!m_rsDataSet.IsEOF())
	{
		strPrice.Format("%.2f",m_rsDataSet.m_Dish_price);
		m_listDisp.InsertItem(i, m_rsDataSet.m_Dish_code);
		m_listDisp.SetItemText(i, 1,m_rsDataSet.m_Dish_name);
		m_listDisp.SetItemText(i, 2,m_rsDataSet.m_Dish_kind);
		m_listDisp.SetItemText(i, 3, strPrice);
		m_listDisp.SetItemText(i, 4, m_rsDataSet.m_Dish_detail);
		m_rsDataSet.MoveNext();
		i++;
	}

	m_listDisp.SetRedraw(TRUE);	


}

void CDishPage::OnClickListDisp(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	int i = m_listDisp.GetSelectionMark();

	m_strCode = m_listDisp.GetItemText(i,0);
	m_strName= m_listDisp.GetItemText(i,1);
	m_strKind = m_listDisp.GetItemText(i,2);
	m_strPrice = m_listDisp.GetItemText(i,3);
	m_strDesc = m_listDisp.GetItemText(i,4);
	
	UpdateData(FALSE);
	
	*pResult = 0;
}

void CDishPage::OnButtonModify() 
{
	UpdateData();
	m_rsDataSet.m_strFilter="Dish_code='"+m_strCode;
	m_rsDataSet.m_strFilter+="'";
	m_rsDataSet.Requery();

	m_rsDataSet.Edit();

	float fPrice=(float)atof((LPCTSTR)m_strPrice);

	m_rsDataSet.m_Dish_code=m_strCode;
	m_rsDataSet.m_Dish_name=m_strName;
	m_rsDataSet.m_Dish_kind=m_strKind;
	m_rsDataSet.m_Dish_price=fPrice;
	m_rsDataSet.m_Dish_detail=m_strDesc;

	m_rsDataSet.Update();
	m_rsDataSet.m_strFilter="";
	m_rsDataSet.Requery();

	RefreshData();





	// TODO: Add your control notification handler code here
	
}

void CDishPage::OnButtonDel() 
{

	UpdateData();
	if(m_strCode=="")
		AfxMessageBox("请选择一个菜进行删除!");
	m_rsDataSet.m_strFilter="Dish_code='"+m_strCode;
	m_rsDataSet.m_strFilter+="'";
	m_rsDataSet.Requery();
	m_rsDataSet.Delete();

	m_strCode="";
	m_strName="";
	m_strKind="";
	m_strPrice="";
	m_strDesc="";

	m_rsDataSet.m_strFilter="";
	m_rsDataSet.Requery();
	RefreshData();
	UpdateData(false);
	// TODO: Add your control notification handler code here
	
}

void CDishPage::OnButtonClear() 
{
	m_strCode="";
	m_strName="";
	m_strKind="";
	m_strPrice="";
	m_strDesc="";
	UpdateData(false);
	// TODO: Add your control notification handler code here
	
}
