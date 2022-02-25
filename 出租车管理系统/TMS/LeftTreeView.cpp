// LeftTreeView.cpp : implementation file
//

#include "stdafx.h"
#include "TMS.h"
#include "LeftTreeView.h"
#include "MainFrm.h"

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

void CLeftTreeView::FullfillTree()
{
	//清空
	CTreeCtrl* pCtrl = &GetTreeCtrl();
	pCtrl->DeleteAllItems();
	//添加主项
	AddMainToTree("车辆管理");
	AddMainToTree("司机管理");
	AddMainToTree("其他管理");
	//添加子项
	AddItem("车辆管理","车辆明细");
	AddItem("车辆管理","车辆所属");
	AddItem("车辆管理","车辆费用");

	AddItem("司机管理","司机明细");
	AddItem("司机管理","违法记录");
	AddItem("司机管理","奖惩记录");

	AddItem("其他管理","法律法规");
	AddItem("其他管理","费用管理");
	AddItem("其他管理","修改密码");
	

}

HTREEITEM  CLeftTreeView::AddMainToTree(CString strMainItem)
{
	CTreeCtrl* pCtrl = &GetTreeCtrl();
	HTREEITEM hRootItem = pCtrl->GetRootItem();
	if(hRootItem)
	{
		while(hRootItem)
		{
			CString strItemText = pCtrl->GetItemText(hRootItem);
			if(strItemText == strMainItem)
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

	TCItem.item.pszText = (LPTSTR)(LPCTSTR)strMainItem;
	HTREEITEM hSectionItem = pCtrl->InsertItem(&TCItem);
//	pCtrl->SortChildren(TVI_ROOT);
	return hSectionItem;

}

HTREEITEM  CLeftTreeView::AddSubToTree(HTREEITEM hTypeItem, CString strSubItem)
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
			if(strItemText == strSubItem)
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

	TCItem.item.pszText = (LPTSTR)(LPCTSTR)strSubItem;
	HTREEITEM hRoomItem = pCtrl->InsertItem(&TCItem);

//	pCtrl->SortChildren(hTypeItem);
	return hRoomItem;

}

void CLeftTreeView::AddItem(CString strMainItem,CString strSubItem)
{
	CTreeCtrl* pCtrl = &GetTreeCtrl();
	HTREEITEM hRootItem = pCtrl->GetRootItem();
	if(hRootItem)
	{
		while(hRootItem)
		{
			CString strItemText = pCtrl->GetItemText(hRootItem);
			if(strItemText == strMainItem)
				break;
			hRootItem = pCtrl->GetNextSiblingItem(hRootItem);
		}
		AddSubToTree(hRootItem,strSubItem);
	}


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
	CTMSApp* pApp = (CTMSApp*)AfxGetApp();
	CTreeCtrl* pTreeCtrl = &GetTreeCtrl();
	m_ImageList.Create(16,16,ILC_COLOR16,4,4);
	m_ImageList.Add(pApp->LoadIcon(IDI_ICON_MAIN));
	m_ImageList.Add(pApp->LoadIcon(IDI_ICON_MAIN));
	m_ImageList.Add(pApp->LoadIcon(IDI_ICON_SUB));
	m_ImageList.Add(pApp->LoadIcon(IDI_ICON_SUB));
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

	//获得选中项的文字
	CString strSel=pCtrl->GetItemText(hSelItem);

	//如果没有项被选择，则将右边的列表视图清空
	CMainFrame* pFrame = (CMainFrame*)AfxGetApp()->m_pMainWnd;
	if(hSelItem == NULL)
	{		
		pFrame->SwitchToView(MAINITEMVIEW);		
		return;
	}

	//判断选择项在树中的位置
	HTREEITEM hParentItem = pCtrl->GetParentItem(hSelItem);
	if(hParentItem == NULL)
	{
		if(strSel=="车辆管理")
			SelItemType=1;
		else if(strSel=="司机管理")
			SelItemType=2;
		else if(strSel=="其他管理")
			SelItemType=3;
		else
			SelItemType=0;
	

	}		
	else
	{
		CString strPSel=pCtrl->GetItemText(hParentItem);
		if(strPSel=="车辆管理")
			SelItemType=10;
		else if(strPSel=="司机管理")
			SelItemType=20;
		else if(strPSel=="其他管理")
			SelItemType=30;
		else
			SelItemType=0;

		if(strSel=="车辆明细"||strSel=="司机明细"||strSel=="法律法规")
			SelItemType+=1;
		else if(strSel=="车辆所属"||strSel=="违法记录"||strSel=="费用管理")
			SelItemType+=2;
		else if(strSel=="车辆费用"||strSel=="奖惩记录"||strSel=="修改密码")
			SelItemType+=3;
		else
			SelItemType+=0;


	}
		pFrame->ShowView();


	
	*pResult = 0;
}
