// RightPaneFrame.cpp : implementation file
//

/*
	作者：张超刚

*/

#include "stdafx.h"
#include "AddressList.h"
#include "RightPaneFrame.h"
#include "LeftTreeView.h"
#include "MainFrm.h"
#include "QueryDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CRightPaneFrame

IMPLEMENT_DYNCREATE(CRightPaneFrame, CFrameWnd)

CRightPaneFrame::CRightPaneFrame()
{
	m_bInfo=TRUE;
}

CRightPaneFrame::~CRightPaneFrame()
{
}


BEGIN_MESSAGE_MAP(CRightPaneFrame, CFrameWnd)
	//{{AFX_MSG_MAP(CRightPaneFrame)
	ON_WM_SIZE()
	ON_COMMAND(ID_MENUITEM_INFO, OnMenuitemInfo)
	ON_UPDATE_COMMAND_UI(ID_MENUITEM_INFO, OnUpdateMenuitemInfo)
	ON_COMMAND(ID_QUERY, OnQuery)
	//}}AFX_MSG_MAP
	ON_MESSAGE(LIST_EVERYONE,ListEveryOne)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRightPaneFrame message handlers

BOOL CRightPaneFrame::OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext) 
{
	// TODO: Add your specialized code here and/or call the base class
	
	//静态分割窗口
	m_wndSplitter.CreateStatic(this, 2, 1);
	m_wndSplitter.CreateView(0,0,RUNTIME_CLASS(CRightListView), CSize(150,0), pContext);
	m_wndSplitter.CreateView(1,0,RUNTIME_CLASS(CPerInfoView), CSize(0,0), pContext);
	//初始化指针
	m_pListView=(CRightListView*)m_wndSplitter.GetPane(0,0);
	m_pPerInfoView=(CPerInfoView*)m_wndSplitter.GetPane(1,0);	
	RecalcLayout();	
	return TRUE;
}

void CRightPaneFrame::OnSize(UINT nType, int cx, int cy) 
{
	CFrameWnd::OnSize(nType, cx, cy);	
	// TODO: Add your message handler code here
	//在这里设置右侧两个分割窗口的大小
	m_wndSplitter.MoveWindow(-2,-2,cx+4,cy+4);
	m_wndSplitter.SetRowInfo(0, cy-(3*cy/5), cy/4);
	m_wndSplitter.SetRowInfo(1, 3*cy/5, cy/4);
	m_wndSplitter.RecalcLayout();
}

void CRightPaneFrame::OnMenuitemInfo() 
{
	// TODO: Add your command handler code here
	int cyCur0,cyMin0,cyCur1,cyMin1;
	m_wndSplitter.GetRowInfo(1,cyCur1,cyMin1);
	if(!cyCur1)
	{
		//重新设置
		m_wndSplitter.GetRowInfo(0,cyCur0,cyMin0);
		m_wndSplitter.SetRowInfo(0, cyCur0-(3*cyCur0/5), cyCur0/4);
		m_wndSplitter.SetRowInfo(1, 3*cyCur0/5, cyCur0/4);
	}
	else
	{
		m_wndSplitter.GetRowInfo(0,cyCur0,cyMin0);
		m_wndSplitter.SetRowInfo(0, cyCur0+cyCur1,cyCur0+cyCur1);
		m_wndSplitter.SetRowInfo(1, 0, 0);
	}
	
	m_wndSplitter.RecalcLayout();
	m_bInfo=!m_bInfo;
}

void CRightPaneFrame::OnUpdateMenuitemInfo(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(m_bInfo);
}

void CRightPaneFrame::ListEveryOne(WPARAM wParam,LPARAM lParam)
{
	CMainFrame* pMainFrm=(CMainFrame*)AfxGetMainWnd();
	CLeftTreeView* pLeftView;
	pLeftView=(CLeftTreeView*)pMainFrm->m_wndSplitter.GetPane(0,0);
	CTreeCtrl& treeCtrl=pLeftView->m_treeCtrl;
	//当由于失去焦点而发生的变化则返回
	if(treeCtrl.GetSelectedItem()==NULL)
	{
		return;
	}
	//这是改变后删除，其实应该是改变前删除才对
	m_pListView->m_listCtrl.DeleteAllItems();
	CString strWhere,strSQL;
	//设置查询条件
	switch(wParam)
	{
	case 1://一级类别
		{
			//设置查询条件
			strWhere.Format("一级类别='%s'",m_strFirstClass);
			strSQL="select * from info where "+strWhere;
			break;			
		}
	case 2://二级类别
		{
			//设置查询条件
			strWhere.Format("一级类别='%s' and 二级类别='%s'",\
				m_strFirstClass,m_strSecondClass);
			strSQL="select * from info where "+strWhere;
			break;			
		}
	case 3://查询时
		{
			strSQL.Format("select * from info where %s",m_strWhere);
			break;//
		}
	default://所有联系人以及其它情况
		strSQL="select * from info";
		break;//
	}		
	//打开数据表
	if(!OpenRecordSet(m_pRecordset,strSQL))
	{
		return;
	}
	if(!m_pRecordset->BOF)
	{
		m_pRecordset->MoveFirst();
	}
	//循环插入，判断时候有照片
	int i=0;
	_variant_t varValue;
	while(!m_pRecordset->adoEOF)
	{
		CString str;
		//负责插入条目
		m_pListView->m_listCtrl.InsertItem (i,str);
		//姓名
		varValue=m_pRecordset->GetFields()->GetItem("姓名")->Value;
		str=pLeftView->VariantToCString(varValue);
		m_pListView->m_listCtrl.SetItemText (i, 0, str);
		//关系
		varValue=m_pRecordset->GetFields()->GetItem("一级类别")->Value;
		str=pLeftView->VariantToCString(varValue);
		m_pListView->m_listCtrl.SetItemText (i, 1, str);
		//工作单位
		varValue=m_pRecordset->GetFields()->GetItem("工作单位")->Value;
		str=pLeftView->VariantToCString(varValue);
		m_pListView->m_listCtrl.SetItemText (i, 2, str);
		//有无照片
		long lFileSize;
		lFileSize=m_pRecordset->GetFields()->GetItem("照片")->ActualSize;
		str=lFileSize>0?"有":"无";
		m_pListView->m_listCtrl.SetItemText (i, 3, str);
		//二级类别
		varValue=m_pRecordset->GetFields()->GetItem("二级类别")->Value;
		str=pLeftView->VariantToCString(varValue);
		m_pListView->m_listCtrl.SetItemText (i, 4, str);
		i++;
		m_pRecordset->MoveNext();
	}
	
	m_pRecordset->Close();
	m_pRecordset=NULL;
}

BOOL CRightPaneFrame::OpenRecordSet(_RecordsetPtr &recPtr, CString &strSQL)
{
	CAddressListApp* pApp=(CAddressListApp*)AfxGetApp();
	//创建记录集对象
	recPtr.CreateInstance(__uuidof(Recordset));
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

void CRightPaneFrame::OnQuery() 
{
	// TODO: Add your command handler code here
	CQueryDlg dlg;
	if(dlg.DoModal()!=IDOK)
		return;
	//具体操作在视图类中
	CString strSql;
	m_strWhere=dlg.m_strSql;
	this->SendMessage(LIST_EVERYONE,3,0);
}

BOOL CRightPaneFrame::DestroyWindow() 
{
	// TODO: Add your specialized code here and/or call the base class
	if(m_pRecordset!=NULL)
	{
		m_pRecordset->Close();
		m_pRecordset=NULL;
	}
	return CFrameWnd::DestroyWindow();
}
