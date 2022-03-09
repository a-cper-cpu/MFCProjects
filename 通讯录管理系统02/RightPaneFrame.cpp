// RightPaneFrame.cpp : implementation file
//

/*
	���ߣ��ų���

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
	
	//��̬�ָ��
	m_wndSplitter.CreateStatic(this, 2, 1);
	m_wndSplitter.CreateView(0,0,RUNTIME_CLASS(CRightListView), CSize(150,0), pContext);
	m_wndSplitter.CreateView(1,0,RUNTIME_CLASS(CPerInfoView), CSize(0,0), pContext);
	//��ʼ��ָ��
	m_pListView=(CRightListView*)m_wndSplitter.GetPane(0,0);
	m_pPerInfoView=(CPerInfoView*)m_wndSplitter.GetPane(1,0);	
	RecalcLayout();	
	return TRUE;
}

void CRightPaneFrame::OnSize(UINT nType, int cx, int cy) 
{
	CFrameWnd::OnSize(nType, cx, cy);	
	// TODO: Add your message handler code here
	//�����������Ҳ������ָ�ڵĴ�С
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
		//��������
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
	//������ʧȥ����������ı仯�򷵻�
	if(treeCtrl.GetSelectedItem()==NULL)
	{
		return;
	}
	//���Ǹı��ɾ������ʵӦ���Ǹı�ǰɾ���Ŷ�
	m_pListView->m_listCtrl.DeleteAllItems();
	CString strWhere,strSQL;
	//���ò�ѯ����
	switch(wParam)
	{
	case 1://һ�����
		{
			//���ò�ѯ����
			strWhere.Format("һ�����='%s'",m_strFirstClass);
			strSQL="select * from info where "+strWhere;
			break;			
		}
	case 2://�������
		{
			//���ò�ѯ����
			strWhere.Format("һ�����='%s' and �������='%s'",\
				m_strFirstClass,m_strSecondClass);
			strSQL="select * from info where "+strWhere;
			break;			
		}
	case 3://��ѯʱ
		{
			strSQL.Format("select * from info where %s",m_strWhere);
			break;//
		}
	default://������ϵ���Լ��������
		strSQL="select * from info";
		break;//
	}		
	//�����ݱ�
	if(!OpenRecordSet(m_pRecordset,strSQL))
	{
		return;
	}
	if(!m_pRecordset->BOF)
	{
		m_pRecordset->MoveFirst();
	}
	//ѭ�����룬�ж�ʱ������Ƭ
	int i=0;
	_variant_t varValue;
	while(!m_pRecordset->adoEOF)
	{
		CString str;
		//���������Ŀ
		m_pListView->m_listCtrl.InsertItem (i,str);
		//����
		varValue=m_pRecordset->GetFields()->GetItem("����")->Value;
		str=pLeftView->VariantToCString(varValue);
		m_pListView->m_listCtrl.SetItemText (i, 0, str);
		//��ϵ
		varValue=m_pRecordset->GetFields()->GetItem("һ�����")->Value;
		str=pLeftView->VariantToCString(varValue);
		m_pListView->m_listCtrl.SetItemText (i, 1, str);
		//������λ
		varValue=m_pRecordset->GetFields()->GetItem("������λ")->Value;
		str=pLeftView->VariantToCString(varValue);
		m_pListView->m_listCtrl.SetItemText (i, 2, str);
		//������Ƭ
		long lFileSize;
		lFileSize=m_pRecordset->GetFields()->GetItem("��Ƭ")->ActualSize;
		str=lFileSize>0?"��":"��";
		m_pListView->m_listCtrl.SetItemText (i, 3, str);
		//�������
		varValue=m_pRecordset->GetFields()->GetItem("�������")->Value;
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
	//������¼������
	recPtr.CreateInstance(__uuidof(Recordset));
	//��ADO�����н��������Ҫ����try...catch()�����������Ϣ,
    //��Ϊ����ʱ�ᾭ������һЩ�벻���Ĵ���
	try
	{
		//�����ݿ��д򿪱�
		recPtr->Open(strSQL.AllocSysString(), 
			pApp->m_pConnection.GetInterfacePtr(),
			adOpenDynamic,
			adLockOptimistic,
			adCmdText);
	}
	catch (_com_error e)
	{
		CString strError;
		strError.Format("���棺�����ݱ�ʱ�����쳣�� ������Ϣ�� %s",\
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
	//�����������ͼ����
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
