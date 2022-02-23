// UserListView.cpp : implementation file
//

#include "stdafx.h"
#include "HMS.h"
#include "UserListView.h"
#include "CustomerDlg.h"
#include "DelUserDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CUserListView

IMPLEMENT_DYNCREATE(CUserListView, CListView)

CUserListView::CUserListView()
{
}

CUserListView::~CUserListView()
{
}


BEGIN_MESSAGE_MAP(CUserListView, CListView)
	//{{AFX_MSG_MAP(CUserListView)
	ON_WM_LBUTTONDBLCLK()
	ON_WM_RBUTTONDOWN()
	ON_COMMAND(ID_BOOKIN_ADD, OnBookinAdd)
	ON_COMMAND(ID_BOOKIN_DEL, OnBookinDel)
	ON_WM_LBUTTONDOWN()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CUserListView drawing

void CUserListView::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	// TODO: add draw code here
}

/////////////////////////////////////////////////////////////////////////////
// CUserListView diagnostics

#ifdef _DEBUG
void CUserListView::AssertValid() const
{
	CListView::AssertValid();
}

void CUserListView::Dump(CDumpContext& dc) const
{
	CListView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CUserListView message handlers

void CUserListView::SetStyle()
{
	DWORD dwStyle = GetWindowLong(m_hWnd, GWL_STYLE); 
	dwStyle &= ~(LVS_TYPEMASK);
	dwStyle &= ~(LVS_EDITLABELS);
 
	// Make sure we have report view and send edit label messages.
    SetWindowLong( m_hWnd, GWL_STYLE, 
		dwStyle | LVS_REPORT|LVS_NOLABELWRAP|LVS_SHOWSELALWAYS);

	// Enable the full row selection and the drag drop of headers.
	DWORD styles = LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES;
	// Use macro since this is new and not in MFC.
	ListView_SetExtendedListViewStyleEx(m_hWnd, styles, styles );

}

void CUserListView::SetTitle()
{


	TCHAR rgtsz[6][30] = {_T("身份证号"),_T("姓名"),_T("性别"),
		_T("年龄"),_T("电话"),_T("办公地")};
	
	
	LV_COLUMN lvcolumn;
	CRect rect;
	this->GetWindowRect(&rect);

	for(int i=0;i<6;i++)
	{
		lvcolumn.mask = LVCF_FMT | LVCF_SUBITEM | LVCF_TEXT 
						| LVCF_WIDTH | LVCF_ORDER;
		lvcolumn.fmt = LVCFMT_LEFT;
		lvcolumn.pszText = rgtsz[i];
		lvcolumn.iSubItem = i;
		lvcolumn.iOrder = i;
		lvcolumn.cx = rect.Height()/4;
		GetListCtrl().InsertColumn(i, &lvcolumn);
	}


}

void CUserListView::ShowUsers(CString strRoomNO)
{

	CListCtrl* p = &GetListCtrl();

	//清空列表
	p->DeleteAllItems();
	if(strRoomNO == "")
		return;


	_variant_t Holder,strQuery;
    strQuery = "select customer.* from bookin,customer where bookin.CustomerID=customer.CustomerID and bookin.RoomNo='"+strRoomNO+"'";
	// Get all records
    theApp.ADOExecute(theApp.m_pRs, strQuery);
    int iCount = theApp.m_pRs->GetRecordCount();
	if ( 0==iCount ) return;
	
    CString str;
	theApp.m_pRs->MoveFirst();
	for(int i=0; i<iCount; i++)
	{
		// Get ID
		Holder = theApp.m_pRs->GetCollect("CustomerID");
	    str = Holder.vt==VT_NULL?"":(char*)(_bstr_t)Holder;
	    GetListCtrl().InsertItem(i, str);
	    // Get Name
        Holder = theApp.m_pRs->GetCollect("CustomerName");
	    str = Holder.vt==VT_NULL?"":(char*)(_bstr_t)Holder;
	    GetListCtrl().SetItemText(i, 1, str);
		// Get Sex
        Holder = theApp.m_pRs->GetCollect("CustomerSex");		
	    if (Holder.vt==VT_NULL?0:Holder.iVal) 
			str = _T("女");
		else
			str = _T("男");
	    GetListCtrl().SetItemText(i, 2, str);
		// Get Age
		Holder = theApp.m_pRs->GetCollect("CustomerAge");
	    str.Format("%d",  Holder.vt==VT_NULL?0:Holder.iVal);
	    GetListCtrl().SetItemText(i, 3, str);
		// Get Tel
        Holder = theApp.m_pRs->GetCollect("CustomerTel");
	    str = Holder.vt==VT_NULL?"":(char*)(_bstr_t)Holder;
	    GetListCtrl().SetItemText(i, 4, str);

		// Get Off
        Holder = theApp.m_pRs->GetCollect("CustomerOff");
	    str = Holder.vt==VT_NULL?"":(char*)(_bstr_t)Holder;
	    GetListCtrl().SetItemText(i, 5, str);

		theApp.m_pRs->MoveNext();
	}
	
}

void CUserListView::OnInitialUpdate() 
{
	CListView::OnInitialUpdate();
	SetStyle();
	SetTitle();	
	
	// TODO: Add your specialized code here and/or call the base class
	
}

void CUserListView::OnLButtonDblClk(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	
	CListView::OnLButtonDblClk(nFlags, point);
	//获得双击的项
	CListCtrl* pCtrl = &GetListCtrl();
	nHitItem = pCtrl->HitTest(point,NULL);
	if( nHitItem < 0 )
		return;

	selCustomer.strCID=pCtrl->GetItemText(nHitItem,0);
	selCustomer.strCName=pCtrl->GetItemText(nHitItem,1);
	selCustomer.iCSex=(pCtrl->GetItemText(nHitItem,2)=="男"?0:1);
	selCustomer.strCAge=pCtrl->GetItemText(nHitItem,3);
	selCustomer.strCTel=pCtrl->GetItemText(nHitItem,4);
	selCustomer.strCOff=pCtrl->GetItemText(nHitItem,5);

	operation=2;

	CCustomerDlg dlg;
	dlg.DoModal();

}

void CUserListView::OnRButtonDown(UINT nFlags, CPoint point) 
{

	// TODO: Add your message handler code here and/or call default
	if(m_pLeftView->GetTreeCtrl().GetItemText(m_pLeftView->m_hHitItem)=="...")
	{
		AfxMessageBox("无效房间");
		return;
	}
	CListView::OnRButtonDown(nFlags, point);
	CMenu menu,*pSubMenu;
	menu.LoadMenu(IDR_MENU_BOOKIN);
	CPoint oPoint;
	GetCursorPos(&oPoint);
	pSubMenu=menu.GetSubMenu(0);
	pSubMenu->TrackPopupMenu(TPM_LEFTALIGN,oPoint.x,oPoint.y,this);	


}

void CUserListView::OnBookinAdd() 
{
	operation=1;
	CCustomerDlg dlg;
	dlg.DoModal();
	// TODO: Add your command handler code here
	
}

void CUserListView::OnBookinDel() 
{
	
	operation=3;

	CDelUserDlg dlg;
	dlg.DoModal();

	// TODO: Add your command handler code here
	
}



void CUserListView::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	
	CListView::OnLButtonDown(nFlags, point);
	CListCtrl* pCtrl = &GetListCtrl();
	nHitItem = pCtrl->HitTest(point,NULL);
	if( nHitItem < 0 )
		return;

	selCustomer.strCID=pCtrl->GetItemText(nHitItem,0);
	selCustomer.strCName=pCtrl->GetItemText(nHitItem,1);
	selCustomer.iCSex=(pCtrl->GetItemText(nHitItem,2)=="男"?0:1);
	selCustomer.strCAge=pCtrl->GetItemText(nHitItem,3);
	selCustomer.strCTel=pCtrl->GetItemText(nHitItem,4);
	selCustomer.strCOff=pCtrl->GetItemText(nHitItem,5);
}
