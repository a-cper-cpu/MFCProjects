// MainFrm.cpp : implementation of the CMainFrame class
//

#include "stdafx.h"
#include "HMS.h"

#include "MainFrm.h"
#include "LeftTreeView.h"
#include "UserListView.h"
#include "RoomTypeView.h"
#include "RoomDlg.h"
#include "RoomTypeDlg.h"
#include "CustomerDlg.h"


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
	ON_COMMAND(ID_ROOMTYPE_ADD, OnRoomtypeAdd)
	ON_COMMAND(ID_ROOM_ADD, OnRoomAdd)
	ON_COMMAND(ID_USER_ADD, OnUserAdd)
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

	
//	return CFrameWnd::OnCreateClient(lpcs, pContext);
	if(!m_wndSplitter.CreateStatic(this,1,2))
		return FALSE;
	if(!m_wndSplitter.CreateView(0,0,RUNTIME_CLASS(CLeftTreeView),CSize(100,100),pContext))
		return FALSE;
	if(!m_wndSplitter.CreateView(0,1,RUNTIME_CLASS(CRoomTypeView),CSize(100,100),pContext))
		return FALSE;
	m_pLeftView = (CLeftTreeView*)m_wndSplitter.GetPane(0,0);
	m_pRoomTypeView = (CRoomTypeView*)m_wndSplitter.GetPane(0,1);

	return TRUE;
}
/***************************************
功能：切换右边的视
参数：nViewType = 0	CRoomTypeView
				  1 CUserListView
*/
void CMainFrame::SwitchToView(int nViewType)
{
	CView* pView = (CView*)m_wndSplitter.GetPane(0,1);
	CRect rcRight,rcFrame;
	pView->GetClientRect(&rcRight);
	GetClientRect(&rcFrame);
	switch(nViewType)
	{
	case ROOMTYPEVIEW:		//CRoomTypeView
		{
			m_wndSplitter.DeleteView(0,1);
			m_wndSplitter.CreateView(0,1,RUNTIME_CLASS(CRoomTypeView),
				CSize(rcRight.Width(),rcRight.Height()),NULL);
			m_wndSplitter.RecalcLayout();
			m_pRoomTypeView= (CRoomTypeView*)m_wndSplitter.GetPane(0,1);
		
			break;
		}
	case USERLISTVIEW:	//CUserListView
		{
			CString str;	
			CTreeCtrl *pTree=&(m_pLeftView->GetTreeCtrl());
			str=pTree->GetItemText(m_pLeftView->m_hHitItem);
			m_wndSplitter.DeleteView(0,1);
			m_wndSplitter.CreateView(0,1,RUNTIME_CLASS(CUserListView),
				CSize(rcRight.Width(),rcRight.Height()),NULL);
			m_wndSplitter.RecalcLayout();
			m_pUserListView= (CUserListView*)m_wndSplitter.GetPane(0,1);
			m_pUserListView->ShowUsers(str);
		
			break;
		}
	default:
		break;
	}
}

void CMainFrame::OnRoomtypeAdd() 
{
	operation=1;
	CRoomTypeDlg dlg;
	dlg.DoModal();
	// TODO: Add your command handler code here
	
}

void CMainFrame::OnRoomAdd() 
{
	operation=1;
	CRoomDlg dlg;
	dlg.DoModal();
	// TODO: Add your command handler code here
	
}

void CMainFrame::OnUserAdd() 
{

	operation=1;
	CCustomerDlg dlg;
	dlg.DoModal();
	// TODO: Add your command handler code here
	
}
