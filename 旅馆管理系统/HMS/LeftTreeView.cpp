// LeftTreeView.cpp : implementation file
//

#include "stdafx.h"
#include "HMS.h"
#include "LeftTreeView.h"
#include "Mainfrm.h"
#include "RoomTypeDlg.h"
#include "RoomDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CLeftTreeView

IMPLEMENT_DYNCREATE(CLeftTreeView, CTreeView)

CLeftTreeView::CLeftTreeView()
{
}

CLeftTreeView::~CLeftTreeView()
{
}


BEGIN_MESSAGE_MAP(CLeftTreeView, CTreeView)
	//{{AFX_MSG_MAP(CLeftTreeView)
	ON_NOTIFY_REFLECT(TVN_SELCHANGED, OnSelchanged)
	ON_NOTIFY_REFLECT(NM_RCLICK, OnRclick)
	ON_COMMAND(ID_TYPE_ADD, OnTypeAdd)
	ON_COMMAND(ID_TYPE_MODIFY, OnTypeModify)
	ON_COMMAND(ID_TYPE_DEL, OnTypeDel)
	ON_COMMAND(ID_ROOM_ADD, OnRoomAdd)
	ON_COMMAND(ID_ROOM_MODIFY, OnRoomModify)
	ON_COMMAND(ID_ROOM_DEL, OnRoomDel)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLeftTreeView drawing

void CLeftTreeView::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	// TODO: add draw code here
}

/////////////////////////////////////////////////////////////////////////////
// CLeftTreeView diagnostics

#ifdef _DEBUG
void CLeftTreeView::AssertValid() const
{
	CTreeView::AssertValid();
}

void CLeftTreeView::Dump(CDumpContext& dc) const
{
	CTreeView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CLeftTreeView message handlers
HTREEITEM CLeftTreeView::AddRoomTypeToTree(CString strTypeName)
{
	CTreeCtrl* pCtrl = &GetTreeCtrl();
	HTREEITEM hRootItem = pCtrl->GetRootItem();
	if(hRootItem)
	{
		while(hRootItem)
		{
			CString strItemText = pCtrl->GetItemText(hRootItem);
			if(strItemText == strTypeName)
				return hRootItem;
			hRootItem = pCtrl->GetNextSiblingItem(hRootItem);
		}
	}
	TV_INSERTSTRUCT TCItem;//插入数据项数据结构
	TCItem.hParent = TVI_ROOT;
	TCItem.hInsertAfter = TVI_LAST;
	TCItem.item.mask=TVIF_TEXT|TVIF_PARAM|TVIF_IMAGE|TVIF_SELECTEDIMAGE;//设屏蔽
	TCItem.item.lParam=0;//序号
	TCItem.item.iImage=0;//正常图标
	TCItem.item.iSelectedImage=0;//选中时图标

	TCItem.item.pszText = (LPTSTR)(LPCTSTR)strTypeName;
	HTREEITEM hSectionItem = pCtrl->InsertItem(&TCItem);
//	pCtrl->SortChildren(TVI_ROOT);
	return hSectionItem;
}

void CLeftTreeView::FullfillTree()
{
	//清空
	CTreeCtrl* pCtrl = &GetTreeCtrl();
	pCtrl->DeleteAllItems();
	//添加房间类型
	_variant_t Holder, strQuery;
    strQuery = "select TypeID,TypeName from roomtype order by TypeID";
	theApp.ADOExecute(theApp.m_pRs, strQuery);
    int iCount = theApp.m_pRs->GetRecordCount();
	if ( 0==iCount ) return;
	
    CString str;
	theApp.m_pRs->MoveFirst();
	for(int i=0; i<iCount; i++)
	{
		 // Get typename
        Holder = theApp.m_pRs->GetCollect("TypeName");
	    str = Holder.vt==VT_NULL?"":(char*)(_bstr_t)Holder;
		AddRoomTypeToTree(str);			
		theApp.m_pRs->MoveNext();
	}

	//添加房间
    strQuery = "select roomtype.TypeName,rooms.RoomNO from rooms,roomtype where rooms.TypeID=roomtype.TypeID";
	theApp.ADOExecute(theApp.m_pRs, strQuery);
	iCount = theApp.m_pRs->GetRecordCount();
	if ( 0==iCount ) return;

	
    CString strTypeName,strRoomNo;
	theApp.m_pRs->MoveFirst();
	for(i=0; i<iCount; i++)
	{
		 // Get typename
        Holder = theApp.m_pRs->GetCollect("TypeName");
	    strTypeName = Holder.vt==VT_NULL?"":(char*)(_bstr_t)Holder;
        //Get RoomNo
		Holder = theApp.m_pRs->GetCollect("RoomNO");
	    strRoomNo = Holder.vt==VT_NULL?"":(char*)(_bstr_t)Holder;

		AddRoom(strTypeName,strRoomNo);		
		theApp.m_pRs->MoveNext();
	}

	//补漏
	strQuery="select TypeName from roomtype where TypeID not in(select distinct TypeID from rooms)";
	theApp.ADOExecute(theApp.m_pRs,strQuery);
	iCount = theApp.m_pRs->GetRecordCount();
	if ( 0==iCount ) return;
	

	theApp.m_pRs->MoveFirst();
	for(i=0; i<iCount; i++)
	{
		 // Get typename
        Holder = theApp.m_pRs->GetCollect("TypeName");
	    strTypeName = Holder.vt==VT_NULL?"":(char*)(_bstr_t)Holder;
      
		AddRoom(strTypeName,"...");		
		theApp.m_pRs->MoveNext();
	}

}
void CLeftTreeView::AddRoom(CString strRoomType, CString strRoomNo)
{
	CTreeCtrl* pCtrl = &GetTreeCtrl();
	HTREEITEM hRootItem = pCtrl->GetRootItem();
	if(hRootItem)
	{
		while(hRootItem)
		{
			CString strItemText = pCtrl->GetItemText(hRootItem);
			if(strItemText == strRoomType)
				break;
			hRootItem = pCtrl->GetNextSiblingItem(hRootItem);
		}
		AddRoomToTree(hRootItem,strRoomNo);
	}
}
HTREEITEM CLeftTreeView::AddRoomToTree(HTREEITEM hTypeItem, CString strRoomNum)
{
	if(hTypeItem == NULL)
		return NULL;
	CTreeCtrl* pCtrl = &GetTreeCtrl();
	if(pCtrl->ItemHasChildren(hTypeItem))
	{
		HTREEITEM hItem = pCtrl->GetChildItem(hTypeItem);
		while(hItem)
		{
			CString strItemText = pCtrl->GetItemText(hItem);
			if(strItemText == strRoomNum)
				return hItem;
			hItem = pCtrl->GetNextSiblingItem(hItem);
		}
	}
	TV_INSERTSTRUCT TCItem;//插入数据项数据结构
	TCItem.hParent = hTypeItem;
	TCItem.hInsertAfter = TVI_LAST;
	TCItem.item.mask=TVIF_TEXT|TVIF_PARAM|TVIF_IMAGE|TVIF_SELECTEDIMAGE;//设屏蔽
	TCItem.item.lParam=0;//序号
	TCItem.item.iImage=2;//正常图标
	TCItem.item.iSelectedImage=2;//选中时图标

	TCItem.item.pszText = (LPTSTR)(LPCTSTR)strRoomNum;
	HTREEITEM hRoomItem = pCtrl->InsertItem(&TCItem);

//	pCtrl->SortChildren(hTypeItem);
	return hRoomItem;
}

void CLeftTreeView::OnInitialUpdate() 
{
	CTreeView::OnInitialUpdate();
			//设置树风格
	::SetWindowLong(m_hWnd,GWL_STYLE,WS_VISIBLE | WS_TABSTOP 
						| WS_CHILD | WS_BORDER| TVS_HASBUTTONS 
						| TVS_LINESATROOT | TVS_HASLINES
						| TVS_DISABLEDRAGDROP|TVS_SHOWSELALWAYS);

	//为树视图创建图标连表
	CHMSApp* pApp = (CHMSApp*)AfxGetApp();
	CTreeCtrl* pTreeCtrl = &GetTreeCtrl();
	m_ImageList.Create(16,16,ILC_COLOR16,4,4);
	m_ImageList.Add(pApp->LoadIcon(IDI_ICON_ROOMTYPE));
	m_ImageList.Add(pApp->LoadIcon(IDI_ICON_ROOM));
	m_ImageList.Add(pApp->LoadIcon(IDI_ICON_ROOM));
	m_ImageList.Add(pApp->LoadIcon(IDI_ICON_USER));
	pTreeCtrl->SetImageList(&m_ImageList,TVSIL_NORMAL);

	//将生成树中
	FullfillTree();
//	pTreeCtrl->SortChildren(TVI_ROOT);
	m_hHitItem=pTreeCtrl->GetFirstVisibleItem();
	// TODO: Add your specialized code here and/or call the base class
	
}

void CLeftTreeView::OnSelchanged(NMHDR* pNMHDR, LRESULT* pResult) 
{

	NM_TREEVIEW* pNMTreeView = (NM_TREEVIEW*)pNMHDR;
	// TODO: Add your control notification handler code here
	
	//获得被选择项
	CTreeCtrl* pCtrl = &GetTreeCtrl();
	HTREEITEM hSelItem = pCtrl->GetSelectedItem();
	m_hHitItem = hSelItem;

	//如果没有项被选择，则将右边的列表视图清空
	CMainFrame* pFrame = (CMainFrame*)AfxGetApp()->m_pMainWnd;
	if(hSelItem == NULL)
	{
		pFrame->SwitchToView(ROOMTYPEVIEW);		
		return;
	}

	//判断选择项在树中的位置
	HTREEITEM hParentItem = pCtrl->GetParentItem(hSelItem);
	CString strSql,strSectionName,strBuildingNum,strCellNum,strRoomNum;
	if(hParentItem == NULL)
	{
		pFrame->SwitchToView(ROOMTYPEVIEW);
		return;	

	}		
	else
	{
		pFrame->SwitchToView(USERLISTVIEW);
		return;

	}

	*pResult = 0;
}

void CLeftTreeView::OnRclick(NMHDR* pNMHDR, LRESULT* pResult) 
{

	CTreeCtrl &CTree=GetTreeCtrl();
	CMenu menu,*pSubMenu;
	
	if(CTree.GetParentItem(m_hHitItem))
	{
		menu.LoadMenu(IDR_MENU_ROOM);
		pSubMenu=menu.GetSubMenu(0);
		CPoint oPoint;
		GetCursorPos(&oPoint);
		pSubMenu->TrackPopupMenu(TPM_LEFTALIGN,oPoint.x,oPoint.y,this);	

	}
	else
	{		
		menu.LoadMenu(IDR_MENU_ROOMTYPE);
		pSubMenu=menu.GetSubMenu(0);
		CPoint oPoint;
		GetCursorPos(&oPoint);
		pSubMenu->TrackPopupMenu(TPM_LEFTALIGN,oPoint.x,oPoint.y,this);
	}
	
	// TODO: Add your control notification handler code here
	
	*pResult = 0;
}

void CLeftTreeView::OnTypeAdd() 
{
	operation=1;
	CRoomTypeDlg dlg;
	dlg.DoModal();
	// TODO: Add your command handler code here
	
}

void CLeftTreeView::OnTypeModify() 
{
	operation=2;
	CRoomTypeDlg dlg;
	dlg.DoModal();
	// TODO: Add your command handler code here
	
}

void CLeftTreeView::OnTypeDel() 
{
	operation=3;
	CRoomTypeDlg dlg;
	dlg.DoModal();
	// TODO: Add your command handler code here
	
}

void CLeftTreeView::OnRoomAdd() 
{
	operation=1;
	CRoomDlg dlg;
	dlg.DoModal();
	// TODO: Add your command handler code here
	
}

void CLeftTreeView::OnRoomModify() 
{
	operation=2;
	CRoomDlg dlg;
	dlg.DoModal();

	// TODO: Add your command handler code here
	
}

void CLeftTreeView::OnRoomDel() 
{
	operation=3;
	CRoomDlg dlg;
	dlg.DoModal();
	// TODO: Add your command handler code here
	
}


