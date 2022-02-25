// MainFrm.cpp : implementation of the CMainFrame class
//

#include "stdafx.h"
#include "TMS.h"


#include "MainFrm.h"
#include "PasswdDlg.h"

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
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	ON_WM_CREATE()
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
	
/*	if (!m_wndToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP
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
	}*/

	CMenu * pMenu=new CMenu();
	pMenu->LoadMenu(IDR_MENU_MAIN);
	SetMenu(pMenu);

	// TODO: Delete these three lines if you don't want the toolbar to
	//  be dockable
/*	m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	EnableDocking(CBRS_ALIGN_ANY);
	DockControlBar(&m_wndToolBar);*/

	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	cs.style = WS_OVERLAPPED | WS_SYSMENU | WS_MINIMIZEBOX;// | WS_THICKFRAME;
	cs.style &= ~WS_BORDER;
	cs.dwExStyle &= ~WS_EX_CLIENTEDGE;
	int iWinBorderX = GetSystemMetrics(SM_CXBORDER);
	int iWinBorderY = GetSystemMetrics(SM_CYBORDER);
	int iCaptionY = GetSystemMetrics(SM_CYCAPTION);
	int iMenuY = GetSystemMetrics(SM_CYMENU);
	int iStausY = GetSystemMetrics(SM_CYMENU);
	cs.cx = 730 + iWinBorderX ;
	cs.cy = 440 + iWinBorderY + iCaptionY + iStausY + iMenuY;
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

void CMainFrame::SwitchToView(int nViewType)
{
	CView* pView = (CView*)m_wndSplitter.GetPane(0,1);
	CRect rcRight,rcFrame;
	pView->GetClientRect(&rcRight);
	GetClientRect(&rcFrame);
	switch(nViewType)
	{
	case MAINITEMVIEW:		//CMainItemView
		{
			m_wndSplitter.DeleteView(0,1);
			m_wndSplitter.CreateView(0,1,RUNTIME_CLASS(CMainItemView),
				CSize(rcRight.Width(),rcRight.Height()),NULL);
			m_wndSplitter.RecalcLayout();
			m_pMainItemView= (CMainItemView*)m_wndSplitter.GetPane(0,1);
		
			break;
		}
	case SUBLISTVIEW:	//CSubListView
		{
			CString str;	
			CTreeCtrl *pTree=&(m_pLeftView->GetTreeCtrl());
			str=pTree->GetItemText(m_pLeftView->m_hHitItem);
			m_wndSplitter.DeleteView(0,1);
			m_wndSplitter.CreateView(0,1,RUNTIME_CLASS(CSubListView),
				CSize(rcRight.Width(),rcRight.Height()),NULL);
			m_wndSplitter.RecalcLayout();
			m_pSubListView= (CSubListView*)m_wndSplitter.GetPane(0,1);
			m_pSubListView->RefreshData();
		
			break;
		}
	default:
		break;
	}
}

BOOL CMainFrame::OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext) 
{
	// TODO: Add your specialized code here and/or call the base class
	if(!m_wndSplitter.CreateStatic(this,1,2))
		return FALSE;
	if(!m_wndSplitter.CreateView(0,0,RUNTIME_CLASS(CLeftTreeView),CSize(150,100),pContext))
		return FALSE;
	if(!m_wndSplitter.CreateView(0,1,RUNTIME_CLASS(CMainItemView),CSize(100,100),pContext))
		return FALSE;
	m_pLeftView = (CLeftTreeView*)m_wndSplitter.GetPane(0,0);
	m_pMainItemView = (CMainItemView*)m_wndSplitter.GetPane(0,1);

	return TRUE;
	return CFrameWnd::OnCreateClient(lpcs, pContext);
}

void CMainFrame::ShowView()
{
	switch(SelItemType)
	{
	case 1:
	case 2:
	case 3:
		SwitchToView(MAINITEMVIEW);
		break;
	case 33:
		PassWdDlg();
		break;
	default:
		SwitchToView(SUBLISTVIEW);
		break;
	}

}

void CMainFrame::PassWdDlg()
{	
	CPasswdDlg dlg;
	dlg.DoModal();

}
