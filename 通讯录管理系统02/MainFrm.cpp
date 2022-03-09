// MainFrm.cpp : implementation of the CMainFrame class
//

/*
	作者：张超刚

*/

#include "stdafx.h"
#include "AddressList.h"

#include "MainFrm.h"
#include "LeftTreeView.h"
#include "RightPaneFrame.h"
#include "AddRelationInfo.h"
#include "RightListView.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	//{{AFX_MSG_MAP(CMainFrame)
	ON_WM_CREATE()
	ON_COMMAND(ID_ADD_INFO, OnAddInfo)
	ON_COMMAND(ID_DELETE_INFO, OnDeleteInfo)
	ON_UPDATE_COMMAND_UI(ID_DELETE_INFO, OnUpdateDeleteInfo)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // status line indicator
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

/////////////////////////////////////////////////////////////////////////////
// CMainFrame construction/destruction

CMainFrame::CMainFrame()
{
	// TODO: add member initialization code here
	
}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	if (!m_wndToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP
		| CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
		!m_wndToolBar.LoadToolBar(IDR_MAINFRAME))
	{
		TRACE0("Failed to create toolbar\n");
		return -1;      // fail to create
	}

	if (!m_wndStatusBar.Create(this) ||
		!m_wndStatusBar.SetIndicators(indicators,
		  sizeof(indicators)/sizeof(UINT)))
	{
		TRACE0("Failed to create status bar\n");
		return -1;      // fail to create
	}

	// TODO: Delete these three lines if you don't want the toolbar to
	//  be dockable
	m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	EnableDocking(CBRS_ALIGN_ANY);
	DockControlBar(&m_wndToolBar);

	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CMainFrame diagnostics

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}

#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMainFrame message handlers


BOOL CMainFrame::OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext) 
{
	// TODO: Add your specialized code here and/or call the base class
	if (!m_wndSplitter.CreateStatic(this, 1, 2))
	{
		TRACE0("Failed to create splitter window\n");
		return FALSE;
	}	
	//获取客户区大小以便调整视图的大小
	CRect rect;
	GetClientRect(&rect);	
	//首先创建左视图
	if (!m_wndSplitter.CreateView(0, 0, RUNTIME_CLASS(CLeftTreeView), CSize(rect.Width()/4, 0), pContext))
	{
		TRACE0("Failed to create left pane view\n");
		return FALSE;
	}	
	//左窗格是一个包含几个具有不同视图的辅助框架窗口
	if (!m_wndSplitter.CreateView(0, 1, RUNTIME_CLASS(CRightPaneFrame), CSize(0, 0), pContext))
	{
		TRACE0("Failed to create right pane frame\n");
		return FALSE;
	}	
	CLeftTreeView* pLeftTreeView=(CLeftTreeView*)m_wndSplitter.GetPane(0,0);
	pLeftTreeView->m_pRightPaneFrame=(CRightPaneFrame*)m_wndSplitter.GetPane(0,1);	
	return TRUE;
}


BOOL CMainFrame::OnCmdMsg(UINT nID, int nCode, void* pExtra, AFX_CMDHANDLERINFO* pHandlerInfo) 
{
	// TODO: Add your specialized code here and/or call the base class
	//重定向消息，以便辅助框架能够处理来自主框架的命令消息
	CRightPaneFrame* pRightPaneFrame=(CRightPaneFrame*)m_wndSplitter.GetPane(0,1);
	if(pRightPaneFrame->OnCmdMsg(nID, nCode, pExtra, pHandlerInfo))
		return TRUE;

	return CFrameWnd::OnCmdMsg(nID, nCode, pExtra, pHandlerInfo);
}

void CMainFrame::OnAddInfo() 
{
	// TODO: Add your command handler code here
	//显示对话框
	CAddRelationInfo dlg;
	dlg.m_strTitle="添加联系人信息";
	dlg.bEdit=FALSE;
	dlg.DoModal();
}

void CMainFrame::OnDeleteInfo() 
{
	// TODO: Add your command handler code here
	//判断想要删除的内容：树或者列表
	if(bTreeSel)
	{
		DeleteTree();
		bTreeSel=FALSE;
	}	
	else if(bListSel)
	{
		DeleteList();
		bListSel=FALSE;
	}
	else
	{//实际上这句话没用，因为不可能执行到此处
		AfxMessageBox("不能删除任何项");
	}
}

void CMainFrame::OnUpdateDeleteInfo(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	//树
	bTreeSel=FALSE;
	bListSel=FALSE;
	CLeftTreeView* pLeftTreeView=(CLeftTreeView*)m_wndSplitter.GetPane(0,0);
	CTreeCtrl& treeCtrl=pLeftTreeView->m_treeCtrl;
	HTREEITEM hSelItem=treeCtrl.GetSelectedItem( );
	if(hSelItem!=NULL)
	{
		bTreeSel=TRUE;
	}	
	//列表控件
	CRightPaneFrame* pRightPaneFrame=(CRightPaneFrame*)m_wndSplitter.GetPane(0,1);
	CRightListView* pListView=(CRightListView*)pRightPaneFrame->m_wndSplitter.GetPane(0,0);
	CListCtrl& listCtrl=pListView->m_listCtrl;
	POSITION pos=listCtrl.GetFirstSelectedItemPosition();
	if (pos!=NULL)
	{
		bListSel=TRUE;
	}
	//两种情况下
	pCmdUI->Enable(bTreeSel|bListSel);
}

void CMainFrame::DeleteTree()
{
	
	CLeftTreeView* pLeftTreeView=(CLeftTreeView*)m_wndSplitter.GetPane(0,0);
	CTreeCtrl& treeCtrl=pLeftTreeView->m_treeCtrl;
	HTREEITEM hSelItem=treeCtrl.GetSelectedItem( );
	if(hSelItem==NULL)
		return;
	
	HTREEITEM hParentItem=treeCtrl.GetParentItem(hSelItem);	
	CString strWhere,strField1,strField2,strSQL,strHint;
	if(hParentItem==NULL&& hSelItem!=NULL)
	{	//所有联系人不允许一下子全部删除
		strHint="不允许一下子全部删除所有联系人!(";
		AfxMessageBox(strHint);
		return;
	}
	else if( hParentItem!=NULL&&treeCtrl.GetParentItem(hParentItem)==NULL )
	{	//一级类别
		CString strFirClass=treeCtrl.GetItemText(hSelItem);
		//设置查询条件
		strWhere.Format("一级类别='%s'",strFirClass);
		strSQL="select * from info where "+strWhere;				
		strHint.Format("您真的要删除所有%s的个人信息吗?",strFirClass);
		
	}
	else
	{	//二级类别		
		CString strFirClass=treeCtrl.GetItemText(treeCtrl.GetParentItem(hSelItem));		
		CString strSecClass=treeCtrl.GetItemText(hSelItem);		
		//设置查询条件
		strWhere.Format("一级类别='%s' and 二级类别='%s'",\
				strFirClass,strSecClass);
		strSQL="select * from info where "+strWhere;
		strHint.Format("您真的要删除%s%s的所有个人信息吗?",strSecClass,strFirClass);
	}

	if(MessageBox(strHint,"个人通讯信息管理系统",MB_YESNO)==IDNO)
	{	
		return;
	}	
	//删除表
	if(!pLeftTreeView->OpenRecordSet(pLeftTreeView->m_pRecordset,strSQL))
	{
		AfxMessageBox("信息表没有成功打开");
		return;
	}
	while(!pLeftTreeView->m_pRecordset->adoEOF)
	{
		pLeftTreeView->m_pRecordset->Delete(adAffectCurrent);
		pLeftTreeView->m_pRecordset->MoveNext();
	}
	pLeftTreeView->m_pRecordset->Close();
	pLeftTreeView->m_pRecordset=NULL;
	//更新树
	pLeftTreeView->ShowTree();
}

void CMainFrame::DeleteList()
{
	//获取列表控件
	CRightPaneFrame* pRightPaneFrame=(CRightPaneFrame*)m_wndSplitter.GetPane(0,1);
	CRightListView* pListView=(CRightListView*)pRightPaneFrame->m_wndSplitter.GetPane(0,0);
	CListCtrl& listCtrl=pListView->m_listCtrl;	
	CString strName,strSQL;
	//寻找当前选中的记录的位置
	POSITION pos=listCtrl.GetFirstSelectedItemPosition();
	if (pos==NULL)
	{
		//如果没有选择记录,则提示并退出
		AfxMessageBox("请您选择要删除的信息！");
		return;
	}
	int iIndex=listCtrl.GetNextSelectedItem(pos);
	//表
	CString strFirClass,strSecClass;
	strName=listCtrl.GetItemText(iIndex,0);
	strFirClass=listCtrl.GetItemText(iIndex,1);
	strSecClass=listCtrl.GetItemText(iIndex,4);
	//确认信息
	CString strHint;
	strHint.Format("是否删除：%s的个人信息？",strName);	
	if (MessageBox(strHint,"删除确认",MB_YESNO|MB_ICONQUESTION)==IDNO)
	{
		return;	
	}
	//首先从列表中删除
	listCtrl.DeleteItem(iIndex);

	strSQL.Format("select * from info where 姓名='%s' \
		and 一级类别='%s' and 二级类别='%s'",\
		strName,strFirClass,strSecClass);

	if(!pListView->OpenRecordSet(pListView->m_pRecordset,strSQL))
	{
		AfxMessageBox("基本信息没有成功打开");
		return;
	}	
	//其次从数据库中删除	
	pListView->m_pRecordset->Delete(adAffectCurrent);
	
	pListView->m_pRecordset->Close();
	pListView->m_pRecordset=NULL;
	bListSel=FALSE;
	//更新树
	CLeftTreeView* pLeftTreeView=(CLeftTreeView*)m_wndSplitter.GetPane(0,0);
	pLeftTreeView->ShowTree();
}
