// DeskPage.cpp : implementation file
//

#include "stdafx.h"
#include "RMS.h"
#include "DeskPage.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDeskPage property page

IMPLEMENT_DYNCREATE(CDeskPage, CPropertyPage)

CDeskPage::CDeskPage() : CPropertyPage(CDeskPage::IDD)
{
	//{{AFX_DATA_INIT(CDeskPage)
	m_strNum = _T("");
	m_strDesc = _T("");
	m_strCode = _T("");
	//}}AFX_DATA_INIT
}

CDeskPage::~CDeskPage()
{
}

void CDeskPage::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDeskPage)
	DDX_Control(pDX, IDC_COMBO_FREE, m_cbFree);
	DDX_Control(pDX, IDC_LIST_DISP, m_listDisp);
	DDX_Text(pDX, IDC_EDIT_NUM, m_strNum);
	DDX_Text(pDX, IDC_EDIT_DESC, m_strDesc);
	DDX_Text(pDX, IDC_EDIT_CODE, m_strCode);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDeskPage, CPropertyPage)
	//{{AFX_MSG_MAP(CDeskPage)
	ON_BN_CLICKED(IDC_BUTTON_ADD, OnButtonAdd)
	ON_BN_CLICKED(IDC_BUTTON_MODIFY, OnButtonModify)
	ON_BN_CLICKED(IDC_BUTTON_DEL, OnButtonDel)
	ON_NOTIFY(NM_CLICK, IDC_LIST_DISP, OnClickListDisp)
	ON_BN_CLICKED(IDC_BUTTON_CLEAR, OnButtonClear)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDeskPage message handlers

void CDeskPage::OnButtonAdd() 
{
	UpdateData();
	if (m_strCode.IsEmpty() || m_strNum.IsEmpty())
	{
		AfxMessageBox("请输入餐桌信息!");
		return;
	}
	int iNum=atoi((LPCTSTR)m_strNum);
	m_rsDataSet.AddNew();

	m_rsDataSet.m_Desk_code=m_strCode;
	m_rsDataSet.m_Desk_num=iNum;
	m_rsDataSet.m_Desk_detail=m_strDesc;
	m_rsDataSet.m_Desk_full=m_cbFree.GetCurSel();


	m_rsDataSet.Update();
	m_rsDataSet.Requery();

	RefreshData();

	// TODO: Add your control notification handler code here
	
}

BOOL CDeskPage::OnInitDialog() 
{
	CPropertyPage::OnInitDialog();
	if (!m_rsDataSet.Open(AFX_DB_USE_DEFAULT_TYPE))
		AfxMessageBox("数据打开失败！");

	m_listDisp.InsertColumn(0,"餐桌号");
	m_listDisp.InsertColumn(1,"座位数");
	m_listDisp.InsertColumn(2,"描述");
	m_listDisp.InsertColumn(3,"是否空闲");

	RECT rect;
	m_listDisp.GetWindowRect(&rect);
	int wid = rect.right - rect.left;
	m_listDisp.SetColumnWidth(0,wid/4);
	m_listDisp.SetColumnWidth(1,wid/4);
	m_listDisp.SetColumnWidth(2,wid/4);
	m_listDisp.SetColumnWidth(3,wid/4);
	m_listDisp.SetColumnWidth(4,wid/4);

	m_listDisp.SetExtendedStyle(LVS_EX_FULLROWSELECT);

	m_cbFree.SetCurSel(1);

	RefreshData();	
	
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CDeskPage::RefreshData()
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
		strNum.Format("%d",m_rsDataSet.m_Desk_num);

		m_listDisp.InsertItem(i, m_rsDataSet.m_Desk_code);
		m_listDisp.SetItemText(i, 1,strNum);
		m_listDisp.SetItemText(i, 2,m_rsDataSet.m_Desk_detail);
		m_listDisp.SetItemText(i, 3, m_rsDataSet.m_Desk_full==1?"是":"否");

		m_rsDataSet.MoveNext();
		i++;
	}

	m_listDisp.SetRedraw(TRUE);	

}

void CDeskPage::OnButtonModify() 
{
	UpdateData();
	m_rsDataSet.m_strFilter="Desk_code='"+m_strCode;
	m_rsDataSet.m_strFilter+="'";
	m_rsDataSet.Requery();

	m_rsDataSet.Edit();

	int iNum=atoi((LPCTSTR)m_strNum);

	m_rsDataSet.m_Desk_code=m_strCode;
	m_rsDataSet.m_Desk_num=iNum;
	m_rsDataSet.m_Desk_detail=m_strDesc;
	m_rsDataSet.m_Desk_full=m_cbFree.GetCurSel();


	m_rsDataSet.Update();
	m_rsDataSet.m_strFilter="";
	m_rsDataSet.Requery();

	RefreshData();
	// TODO: Add your control notification handler code here
	
}

void CDeskPage::OnButtonDel() 
{
	UpdateData();
	if(m_strCode=="")
		AfxMessageBox("请选择一个桌进行删除!");
	m_rsDataSet.m_strFilter="Desk_code='"+m_strCode;
	m_rsDataSet.m_strFilter+="'";
	m_rsDataSet.Requery();
	m_rsDataSet.Delete();

	m_strCode="";
	m_strNum="";
	m_strDesc="";
	m_cbFree.SetCurSel(1);


	m_rsDataSet.m_strFilter="";
	m_rsDataSet.Requery();

	RefreshData();
	UpdateData(false);
	// TODO: Add your control notification handler code here
	
}

void CDeskPage::OnClickListDisp(NMHDR* pNMHDR, LRESULT* pResult) 
{
	int i = m_listDisp.GetSelectionMark();

	m_strCode = m_listDisp.GetItemText(i,0);	
	m_strNum= m_listDisp.GetItemText(i,1);
	m_strDesc= m_listDisp.GetItemText(i,2);
	m_cbFree.SetCurSel(m_listDisp.GetItemText(i,3)=="是"?1:0);

	
	UpdateData(FALSE);
	// TODO: Add your control notification handler code here
	
	*pResult = 0;
}

void CDeskPage::OnButtonClear() 
{
	m_strCode="";
	m_strNum="";
	m_strDesc="";
	m_cbFree.SetCurSel(1);
	UpdateData(false);
	// TODO: Add your control notification handler code here
	
}
