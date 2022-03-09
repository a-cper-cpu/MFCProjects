// MainFrm.cpp : implementation of the CMainFrame class
//

/*
	���ߣ��ų���

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
	//��ȡ�ͻ�����С�Ա������ͼ�Ĵ�С
	CRect rect;
	GetClientRect(&rect);	
	//���ȴ�������ͼ
	if (!m_wndSplitter.CreateView(0, 0, RUNTIME_CLASS(CLeftTreeView), CSize(rect.Width()/4, 0), pContext))
	{
		TRACE0("Failed to create left pane view\n");
		return FALSE;
	}	
	//�󴰸���һ�������������в�ͬ��ͼ�ĸ�����ܴ���
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
	//�ض�����Ϣ���Ա㸨������ܹ�������������ܵ�������Ϣ
	CRightPaneFrame* pRightPaneFrame=(CRightPaneFrame*)m_wndSplitter.GetPane(0,1);
	if(pRightPaneFrame->OnCmdMsg(nID, nCode, pExtra, pHandlerInfo))
		return TRUE;

	return CFrameWnd::OnCmdMsg(nID, nCode, pExtra, pHandlerInfo);
}

void CMainFrame::OnAddInfo() 
{
	// TODO: Add your command handler code here
	//��ʾ�Ի���
	CAddRelationInfo dlg;
	dlg.m_strTitle="�����ϵ����Ϣ";
	dlg.bEdit=FALSE;
	dlg.DoModal();
}

void CMainFrame::OnDeleteInfo() 
{
	// TODO: Add your command handler code here
	//�ж���Ҫɾ�������ݣ��������б�
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
	{//ʵ������仰û�ã���Ϊ������ִ�е��˴�
		AfxMessageBox("����ɾ���κ���");
	}
}

void CMainFrame::OnUpdateDeleteInfo(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	//��
	bTreeSel=FALSE;
	bListSel=FALSE;
	CLeftTreeView* pLeftTreeView=(CLeftTreeView*)m_wndSplitter.GetPane(0,0);
	CTreeCtrl& treeCtrl=pLeftTreeView->m_treeCtrl;
	HTREEITEM hSelItem=treeCtrl.GetSelectedItem( );
	if(hSelItem!=NULL)
	{
		bTreeSel=TRUE;
	}	
	//�б�ؼ�
	CRightPaneFrame* pRightPaneFrame=(CRightPaneFrame*)m_wndSplitter.GetPane(0,1);
	CRightListView* pListView=(CRightListView*)pRightPaneFrame->m_wndSplitter.GetPane(0,0);
	CListCtrl& listCtrl=pListView->m_listCtrl;
	POSITION pos=listCtrl.GetFirstSelectedItemPosition();
	if (pos!=NULL)
	{
		bListSel=TRUE;
	}
	//���������
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
	{	//������ϵ�˲�����һ����ȫ��ɾ��
		strHint="������һ����ȫ��ɾ��������ϵ��!(";
		AfxMessageBox(strHint);
		return;
	}
	else if( hParentItem!=NULL&&treeCtrl.GetParentItem(hParentItem)==NULL )
	{	//һ�����
		CString strFirClass=treeCtrl.GetItemText(hSelItem);
		//���ò�ѯ����
		strWhere.Format("һ�����='%s'",strFirClass);
		strSQL="select * from info where "+strWhere;				
		strHint.Format("�����Ҫɾ������%s�ĸ�����Ϣ��?",strFirClass);
		
	}
	else
	{	//�������		
		CString strFirClass=treeCtrl.GetItemText(treeCtrl.GetParentItem(hSelItem));		
		CString strSecClass=treeCtrl.GetItemText(hSelItem);		
		//���ò�ѯ����
		strWhere.Format("һ�����='%s' and �������='%s'",\
				strFirClass,strSecClass);
		strSQL="select * from info where "+strWhere;
		strHint.Format("�����Ҫɾ��%s%s�����и�����Ϣ��?",strSecClass,strFirClass);
	}

	if(MessageBox(strHint,"����ͨѶ��Ϣ����ϵͳ",MB_YESNO)==IDNO)
	{	
		return;
	}	
	//ɾ����
	if(!pLeftTreeView->OpenRecordSet(pLeftTreeView->m_pRecordset,strSQL))
	{
		AfxMessageBox("��Ϣ��û�гɹ���");
		return;
	}
	while(!pLeftTreeView->m_pRecordset->adoEOF)
	{
		pLeftTreeView->m_pRecordset->Delete(adAffectCurrent);
		pLeftTreeView->m_pRecordset->MoveNext();
	}
	pLeftTreeView->m_pRecordset->Close();
	pLeftTreeView->m_pRecordset=NULL;
	//������
	pLeftTreeView->ShowTree();
}

void CMainFrame::DeleteList()
{
	//��ȡ�б�ؼ�
	CRightPaneFrame* pRightPaneFrame=(CRightPaneFrame*)m_wndSplitter.GetPane(0,1);
	CRightListView* pListView=(CRightListView*)pRightPaneFrame->m_wndSplitter.GetPane(0,0);
	CListCtrl& listCtrl=pListView->m_listCtrl;	
	CString strName,strSQL;
	//Ѱ�ҵ�ǰѡ�еļ�¼��λ��
	POSITION pos=listCtrl.GetFirstSelectedItemPosition();
	if (pos==NULL)
	{
		//���û��ѡ���¼,����ʾ���˳�
		AfxMessageBox("����ѡ��Ҫɾ������Ϣ��");
		return;
	}
	int iIndex=listCtrl.GetNextSelectedItem(pos);
	//��
	CString strFirClass,strSecClass;
	strName=listCtrl.GetItemText(iIndex,0);
	strFirClass=listCtrl.GetItemText(iIndex,1);
	strSecClass=listCtrl.GetItemText(iIndex,4);
	//ȷ����Ϣ
	CString strHint;
	strHint.Format("�Ƿ�ɾ����%s�ĸ�����Ϣ��",strName);	
	if (MessageBox(strHint,"ɾ��ȷ��",MB_YESNO|MB_ICONQUESTION)==IDNO)
	{
		return;	
	}
	//���ȴ��б���ɾ��
	listCtrl.DeleteItem(iIndex);

	strSQL.Format("select * from info where ����='%s' \
		and һ�����='%s' and �������='%s'",\
		strName,strFirClass,strSecClass);

	if(!pListView->OpenRecordSet(pListView->m_pRecordset,strSQL))
	{
		AfxMessageBox("������Ϣû�гɹ���");
		return;
	}	
	//��δ����ݿ���ɾ��	
	pListView->m_pRecordset->Delete(adAffectCurrent);
	
	pListView->m_pRecordset->Close();
	pListView->m_pRecordset=NULL;
	bListSel=FALSE;
	//������
	CLeftTreeView* pLeftTreeView=(CLeftTreeView*)m_wndSplitter.GetPane(0,0);
	pLeftTreeView->ShowTree();
}
