// LeftTreeView.cpp : implementation file
//

/*
	作者：张超刚

*/

#include "stdafx.h"
#include "AddressList.h"
#include "LeftTreeView.h"
#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CLeftTreeView

IMPLEMENT_DYNCREATE(CLeftTreeView, CFormView)

CLeftTreeView::CLeftTreeView()
	: CFormView(CLeftTreeView::IDD)
{
	//{{AFX_DATA_INIT(CLeftTreeView)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}

CLeftTreeView::~CLeftTreeView()
{
}

void CLeftTreeView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CLeftTreeView)
	DDX_Control(pDX, IDC_TREE, m_treeCtrl);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CLeftTreeView, CFormView)
	//{{AFX_MSG_MAP(CLeftTreeView)
	ON_WM_SIZE()
	ON_NOTIFY(TVN_SELCHANGED, IDC_TREE, OnSelchangedTree)
	ON_NOTIFY(NM_KILLFOCUS, IDC_TREE, OnKillfocusTree)
	ON_WM_CONTEXTMENU()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLeftTreeView diagnostics

#ifdef _DEBUG
void CLeftTreeView::AssertValid() const
{
	CFormView::AssertValid();
}

void CLeftTreeView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CLeftTreeView message handlers

void CLeftTreeView::OnSize(UINT nType, int cx, int cy) 
{
	CFormView::OnSize(nType, cx, cy);
	CFormView::ShowScrollBar(SB_BOTH,FALSE);
	// TODO: Add your message handler code here
	//使树控件填满整个视图
	if (GetSafeHwnd())
	{
		CRect rect;
		GetClientRect(&rect);
		if (m_treeCtrl.GetSafeHwnd())
			m_treeCtrl.MoveWindow(&rect);
	}
}

void CLeftTreeView::OnInitialUpdate() 
{
	CFormView::OnInitialUpdate();	
	// TODO: Add your specialized code here and/or call the base class
	m_ImageList.Create(IDB_TREE, 32, 1, RGB(255, 0, 255));	
	m_treeCtrl.SetImageList(&m_ImageList, LVSIL_NORMAL);
	m_hSelItem=NULL;
	//随机图标
	srand((unsigned)time(NULL));
	//首先调用一次rand()，这样才确保m_iImage起始值不同
	rand();
	m_iImage=(int)((float)rand()*8.0/(float)RAND_MAX);
	//初始化树
	ShowTree();
}


void CLeftTreeView::OnSelchangedTree(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_TREEVIEW* pNMTreeView = (NM_TREEVIEW*)pNMHDR;
	// TODO: Add your control notification handler code here
	CString strRoot, strFirstClass,strSecondClass;
	HTREEITEM hRootItem,hFirstClassItem,hSecondClassItem;
	HTREEITEM hSelItem,hParent;
	BOOL bHasChild;
	hSelItem=pNMTreeView->itemNew.hItem;
	m_hSelItem=hSelItem;
	//有无子
	bHasChild=m_treeCtrl.ItemHasChildren(hSelItem);
	//其父
	hParent=m_treeCtrl.GetParentItem(hSelItem);
	//二级类别
	if(!bHasChild)
	{
		hSecondClassItem=hSelItem;
		strSecondClass=m_treeCtrl.GetItemText(hSecondClassItem);
		hFirstClassItem=m_treeCtrl.GetParentItem(hSecondClassItem);
		strFirstClass=m_treeCtrl.GetItemText(hFirstClassItem);
		hRootItem=m_treeCtrl.GetParentItem(hFirstClassItem);
		strRoot=m_treeCtrl.GetItemText(hRootItem);
		//让辅助框架处理
		m_pRightPaneFrame->m_strFirstClass=strFirstClass;
		m_pRightPaneFrame->m_strSecondClass=strSecondClass;
		m_pRightPaneFrame->SendMessage(LIST_EVERYONE,2,0);
		
	}//所有联系人
	else if(hParent==NULL)
	{
		hRootItem=hSelItem;
		strRoot=m_treeCtrl.GetItemText(hRootItem);
		m_pRightPaneFrame->SendMessage(LIST_EVERYONE,0,0);
	}
	//一级类别
	else
	{
		hFirstClassItem=hSelItem;
		hRootItem=m_treeCtrl.GetParentItem(hFirstClassItem);
		strFirstClass=m_treeCtrl.GetItemText(hFirstClassItem);		
		strRoot=m_treeCtrl.GetItemText(hRootItem);
		m_pRightPaneFrame->m_strFirstClass=strFirstClass;
		m_pRightPaneFrame->SendMessage(LIST_EVERYONE,1,0);
	}

	*pResult = 0;
}

BOOL CLeftTreeView::OpenRecordSet(_RecordsetPtr &recPtr, CString &strSQL)
{
	CAddressListApp* pApp=(CAddressListApp*)AfxGetApp();
	//创建记录集对象
	m_pRecordset.CreateInstance(__uuidof(Recordset));
	//在ADO操作中建议语句中要常用try...catch()来捕获错误信息,
    //因为它有时会经常出现一些想不到的错误
	try
	{
		//从数据库中打开表
		recPtr->Open(strSQL.AllocSysString(), 
			pApp->m_pConnection.GetInterfacePtr(),
			adOpenDynamic,
			adLockOptimistic,
			adCmdText);
	}
	catch (_com_error e)
	{
		CString strError;
		strError.Format("警告：打开数据表时发生异常。 错误信息： %s",\
			e.ErrorMessage());
		AfxMessageBox(strError);
		return FALSE;
	}
	return TRUE;
}

void CLeftTreeView::ShowTree()
{
	//首先删除所有的树项
	m_treeCtrl.DeleteAllItems();
	CString strSQL;
	strSQL="select * from info";
	if(!OpenRecordSet(m_pRecordset,strSQL))
	{
		return;
	}
	//定义变量
	_variant_t varValue;	
	//从数据库中开始填充树
	HTREEITEM hRootItem,hFirstClassItem,hSecondClassItem;
	hRootItem=m_treeCtrl.InsertItem("所有联系人", 0, 1);
	int i=0;	
	m_pRecordset->MoveFirst();
	while(!m_pRecordset->adoEOF)
	{
		CString strClass;
		varValue=m_pRecordset->GetCollect("一级类别");
		strClass=VariantToCString(varValue);
		//添加二级类别
		hFirstClassItem=AddFirstClassToTree(hRootItem,strClass);
		varValue=m_pRecordset->GetCollect("二级类别");
		strClass=VariantToCString(varValue);
		hSecondClassItem=AddSecondClassToTree(hFirstClassItem,strClass);
		//展开根目录
		m_pRecordset->MoveNext();
	}
	//关闭
	m_pRecordset->Close();
	m_pRecordset=NULL;
	m_treeCtrl.Expand(hRootItem,TVE_EXPAND);
}

HTREEITEM CLeftTreeView::AddFirstClassToTree(HTREEITEM hRootItem, 
											 CString strFirstClass)
{
	//从数据库中开始填充树
	if(hRootItem==NULL)
		return NULL;
	
	if(m_treeCtrl.ItemHasChildren(hRootItem))
	{
		HTREEITEM hFirstClassItem=m_treeCtrl.GetChildItem(hRootItem);
		while(hFirstClassItem)
		{
			CString strItemText =m_treeCtrl.GetItemText(hFirstClassItem);
			if(strItemText==strFirstClass)
				return hFirstClassItem;
			hFirstClassItem=m_treeCtrl.GetNextSiblingItem(hFirstClassItem);
		}
	}
	//插入数据项数据结构
	TV_INSERTSTRUCT TCItem;
	TCItem.hParent =hRootItem;
	TCItem.hInsertAfter = TVI_LAST;
	//设屏蔽
	TCItem.item.mask=TVIF_TEXT|TVIF_PARAM|TVIF_IMAGE|TVIF_SELECTEDIMAGE;
	//序号
	TCItem.item.lParam=0;
	//正常图标
	TCItem.item.iImage=m_iImage;
	//选中时图标
	TCItem.item.iSelectedImage=m_iImage>4?m_iImage-4:m_iImage+1;	
	TCItem.item.pszText = (LPTSTR)(LPCTSTR)strFirstClass;
	HTREEITEM hFirstClassItemNew =m_treeCtrl.InsertItem(&TCItem);
	m_treeCtrl.SortChildren(hRootItem);
	return hFirstClassItemNew;
}

HTREEITEM CLeftTreeView::AddSecondClassToTree(HTREEITEM hFirstClassItem,
											  CString strSecondClass)
{
	//从数据库中开始填充树
	if(hFirstClassItem==NULL)
		return NULL;	
	if(m_treeCtrl.ItemHasChildren(hFirstClassItem))
	{
		HTREEITEM hSecondClassItem=m_treeCtrl.GetChildItem(hFirstClassItem);
		while(hSecondClassItem)
		{
			CString strItemText =m_treeCtrl.GetItemText(hSecondClassItem);
			if(strItemText==strSecondClass)
				return hSecondClassItem;
			hSecondClassItem=m_treeCtrl.GetNextSiblingItem(hSecondClassItem);
		}
	}
	//插入数据项数据结构
	TV_INSERTSTRUCT TCItem;
	TCItem.hParent =hFirstClassItem;
	TCItem.hInsertAfter = TVI_LAST;
	//设屏蔽
	TCItem.item.mask=TVIF_TEXT|TVIF_PARAM|TVIF_IMAGE|TVIF_SELECTEDIMAGE;
	//序号
	TCItem.item.lParam=0;
	//正常图标
	TCItem.item.iImage=m_iImage>4?m_iImage-3:m_iImage+2;
	//选中时图标
	TCItem.item.iSelectedImage=m_iImage>4?m_iImage-2:m_iImage+3;
	TCItem.item.pszText = (LPTSTR)(LPCTSTR)strSecondClass;

	HTREEITEM hSecondClassItemNew =m_treeCtrl.InsertItem(&TCItem);
	m_treeCtrl.SortChildren(hFirstClassItem);
	return hSecondClassItemNew;
}

CString CLeftTreeView::VariantToCString(const _variant_t &var)
{
	CString strValue;	
	switch (var.vt)
	{
	case VT_BSTR://字符串
	case VT_LPSTR:
	case VT_LPWSTR:
		strValue = (LPCTSTR)(_bstr_t)var;
		break;
	case VT_I1://无符号字符
	case VT_UI1:
		strValue.Format("%d", var.bVal);
		break;
	case VT_I2://短整型
		strValue.Format("%d", var.iVal);
		break;
	case VT_UI2://无符号短整型
		strValue.Format("%d", var.uiVal);
		break;
	case VT_INT://整型
		strValue.Format("%d", var.intVal);
		break;
	case VT_I4: //整型
	case VT_I8: //长整型
		 strValue.Format("%d", var.lVal);
		break;
	case VT_UINT://无符号整型
		strValue.Format("%d", var.uintVal);
		break;
	case VT_UI4: //无符号整型
	case VT_UI8: //无符号长整型
		 strValue.Format("%d", var.ulVal);
		 break;
	case VT_VOID:
		strValue.Format("%8x", var.byref);
		break;
	case VT_R4://浮点型
		strValue.Format("%.4f", var.fltVal);
		break;
	case VT_R8://双精度型
		strValue.Format("%.8f", var.dblVal);
		break;
	case VT_DECIMAL: //小数
		strValue.Format("%.8f", (double)var);
		break;
	case VT_CY:
		{
			COleCurrency cy = var.cyVal;
			strValue = cy.Format();
		}
		break;
	case VT_BLOB:
	case VT_BLOB_OBJECT:
	case 0x2011:
		strValue = "[BLOB]";
		break;
	case VT_BOOL://布尔型		
		strValue = var.boolVal ? "TRUE" : "FALSE";
		break;
	case VT_DATE: //日期型
		{
			DATE dt = var.date;
			COleDateTime da = COleDateTime(dt); 
			strValue = da.Format("%Y-%m-%d %H:%M:%S");
		}
		break;
	case VT_NULL://NULL值
	case VT_EMPTY://空
		 strValue = "";
		 break;
	case VT_UNKNOWN://未知类型
	default:
		strValue = "UN_KNOW";
		break;
	}
	return strValue;
}

void CLeftTreeView::OnKillfocusTree(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	CMainFrame* pMainFrm=(CMainFrame*)AfxGetMainWnd();
	//全部落选,以便在删除时可以判断删除情况啊	
	m_treeCtrl.SelectItem(NULL);  //TVM_GETNEXTITEM
	pMainFrm->bTreeSel=FALSE;
	*pResult = 0;
}

void CLeftTreeView::OnContextMenu(CWnd* pWnd, CPoint point) 
{
	// TODO: Add your message handler code here
	if (point != CPoint (-1, -1))
	{
		//选中点击的树项:
		CPoint ptTree = point;
		m_treeCtrl.ScreenToClient (&ptTree);		
		HTREEITEM hTreeItem =m_treeCtrl.HitTest(ptTree);
		if (hTreeItem != NULL)
		{
			//首先选中
			m_treeCtrl.SelectItem (hTreeItem);
		}
	}
	//赋予输入焦点
	m_treeCtrl.SetFocus ();
	//上下文菜单，命令由主框架处理
	CMainFrame* pMainFrm=(CMainFrame*)AfxGetMainWnd();
	CMenu menu;
    menu.LoadMenu(IDR_MAINFRAME);
    menu.GetSubMenu(1)
        ->TrackPopupMenu(TPM_LEFTALIGN | TPM_RIGHTBUTTON,
        point.x, point.y,pMainFrm);
}
