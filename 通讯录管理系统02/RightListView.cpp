// RightListView.cpp : implementation file
//

/*
	作者：张超刚

*/

#include "stdafx.h"
#include "AddressList.h"
#include "RightListView.h"
#include "RightPaneFrame.h"
#include "LeftTreeView.h"
#include "PerInfoView.h"
#include "AddRelationInfo.h"
#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#define ChunkSize 1024
/////////////////////////////////////////////////////////////////////////////
// CRightListView

IMPLEMENT_DYNCREATE(CRightListView, CFormView)

CRightListView::CRightListView()
	: CFormView(CRightListView::IDD)
{
	//{{AFX_DATA_INIT(CRightListView)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}

CRightListView::~CRightListView()
{
}

void CRightListView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CRightListView)
	DDX_Control(pDX, IDC_LIST, m_listCtrl);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CRightListView, CFormView)
	//{{AFX_MSG_MAP(CRightListView)
	ON_WM_SIZE()
	ON_NOTIFY(NM_CLICK, IDC_LIST, OnClickList)
	ON_NOTIFY(NM_DBLCLK, IDC_LIST, OnDblclkList)
	ON_NOTIFY(NM_KILLFOCUS, IDC_LIST, OnKillfocusList)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRightListView diagnostics

#ifdef _DEBUG
void CRightListView::AssertValid() const
{
	CFormView::AssertValid();
}

void CRightListView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CRightListView message handlers

void CRightListView::OnSize(UINT nType, int cx, int cy) 
{
	CFormView::OnSize(nType, cx, cy);	
	// TODO: Add your message handler code here
	CFormView::ShowScrollBar(SB_BOTH,FALSE);	
	if (GetSafeHwnd())
	{
		if (m_listCtrl.GetSafeHwnd())
		{
			CRect rect(0,0,cx,cy);
			m_listCtrl.MoveWindow(&rect);
		}
	}
}

void CRightListView::OnInitialUpdate() 
{
	CFormView::OnInitialUpdate();	
	// TODO: Add your specialized code here and/or call the base class
	CRect rect;
	m_listCtrl.GetClientRect(&rect);
	//设置列表控件风格
	DWORD dwStyle=::GetWindowLong(m_hWnd,GWL_STYLE);
    dwStyle|=LVS_REPORT|LVS_SHOWSELALWAYS|LVS_EDITLABELS;	
	::SetWindowLong(m_hWnd,GWL_STYLE,dwStyle);
	dwStyle=m_listCtrl.GetExtendedStyle();
	dwStyle|=LVS_EX_FULLROWSELECT;//LVS_EX_GRIDLINES|
    //设置扩展风格
	m_listCtrl.SetExtendedStyle(dwStyle);	
	m_listCtrl.InsertColumn(0, "姓名", LVCFMT_LEFT, rect.Width());
	m_listCtrl.InsertColumn(1, "关系", LVCFMT_LEFT, rect.Width());
	m_listCtrl.InsertColumn(2, "单位", LVCFMT_LEFT, rect.Width());
	m_listCtrl.InsertColumn(3, "照片", LVCFMT_LEFT, rect.Width());
	//二级类别不用来显示，别有它用所以设为0
	m_listCtrl.InsertColumn(4, "二级类别", LVCFMT_LEFT, 0);
}

void CRightListView::OnClickList(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	CMainFrame* pMainFrm=(CMainFrame*)AfxGetMainWnd();
	CRightPaneFrame* pRightFrm;
	CLeftTreeView* pLeftView;
	CPerInfoView*  pPerInfo;
	pLeftView=(CLeftTreeView*)pMainFrm->m_wndSplitter.GetPane(0,0);
	pRightFrm=(CRightPaneFrame*)pMainFrm->m_wndSplitter.GetPane(0,1);
	pPerInfo=pRightFrm->m_pPerInfoView;
	//寻找当前选中的记录的位置
	POSITION pos=m_listCtrl.GetFirstSelectedItemPosition();
    //获取当前记录的位置游标
	int iIndex=m_listCtrl.GetNextSelectedItem(pos);
	if(iIndex==-1)
	{
		return;
	}
	//获取该项在数据库中的序号
	CString strName,strFirClass,strSecClass;
	strName=m_listCtrl.GetItemText(iIndex,0);
	strFirClass=m_listCtrl.GetItemText(iIndex,1);
	strSecClass=m_listCtrl.GetItemText(iIndex,4);
	//设置查询语句
	CString strSQL;
	strSQL.Format("select * from info where 姓名='%s' \
		and 一级类别='%s' and 二级类别='%s'",\
		strName,strFirClass,strSecClass);
	//打开记录集 选择表名
	if(!OpenRecordSet(m_pRecordset,strSQL))
	{
		AfxMessageBox("没有成功打开数据表");
		return;
	}	
	//应该只有一条记录
	m_pRecordset->MoveFirst();
	pPerInfo->m_strName=pLeftView->VariantToCString(m_pRecordset->GetCollect("姓名"));
	pPerInfo->m_strCompany=pLeftView->VariantToCString(m_pRecordset->GetCollect("工作单位"));
	pPerInfo->m_strCompanyAdd=pLeftView->VariantToCString(m_pRecordset->GetCollect("单位地址"));
	pPerInfo->m_strComTel=pLeftView->VariantToCString(m_pRecordset->GetCollect("办公电话"));
	pPerInfo->m_strHomeAdd=pLeftView->VariantToCString(m_pRecordset->GetCollect("家庭地址"));
	pPerInfo->m_strHomeTel=pLeftView->VariantToCString(m_pRecordset->GetCollect("家庭电话"));
	pPerInfo->m_strMobile=pLeftView->VariantToCString(m_pRecordset->GetCollect("移动电话"));
	pPerInfo->m_strEmail=pLeftView->VariantToCString(m_pRecordset->GetCollect("电子邮件"));
	pPerInfo->m_strWeb=pLeftView->VariantToCString(m_pRecordset->GetCollect("个人主页"));
	pPerInfo->m_strComment=pLeftView->VariantToCString(m_pRecordset->GetCollect("备注"));	
	//出生日期 
	pPerInfo->m_Birthday=m_pRecordset->GetCollect("出生日期");
	//照片信息
	//路径问题的解决
	CString strCurDir,strTem;
	char chCurDir[MAX_PATH];
	//填充0
	memset(chCurDir,0,MAX_PATH);
	::GetModuleFileName(NULL,chCurDir,sizeof(chCurDir));
	strCurDir.Format("%s",chCurDir);
	//取得模块名的处exe部分之外的其余部分
	strCurDir=strCurDir.Left(strCurDir.ReverseFind('\\'));
	strCurDir=strCurDir+"\\tem.bmp";
	if(SetDbToFile(m_pRecordset,strCurDir))
	{
		pPerInfo->ReadBmpToMem(strCurDir);
	}
	pPerInfo->UpdateData(FALSE);
	//关闭
	m_pRecordset->Close();
	m_pRecordset=NULL;
	*pResult = 0;
}

void CRightListView::OnDblclkList(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	CMainFrame* pMainFrm=(CMainFrame*)AfxGetMainWnd();
	CLeftTreeView* pLeftView;
	pLeftView=(CLeftTreeView*)pMainFrm->m_wndSplitter.GetPane(0,0);
	//寻找当前选中的记录的位置
	POSITION pos=m_listCtrl.GetFirstSelectedItemPosition();
    //获取当前记录的位置游标
	int iIndex=m_listCtrl.GetNextSelectedItem(pos);
	if(iIndex==-1)
	{
		return;
	}
	//获取该项在数据库中的序号
	CString strName,strFirClass,strSecClass;
	strName=m_listCtrl.GetItemText(iIndex,0);
	strFirClass=m_listCtrl.GetItemText(iIndex,1);
	strSecClass=m_listCtrl.GetItemText(iIndex,4);
	//设置查询语句
	CString strSQL;
	strSQL.Format("select * from info where 姓名='%s' \
		and 一级类别='%s' and 二级类别='%s'",\
		strName,strFirClass,strSecClass);
	//打开记录集 选择表名
	if(!OpenRecordSet(m_pRecordset,strSQL))
	{
		AfxMessageBox("没有成功打开数据表");
		return;
	}
	m_pRecordset->MoveFirst();
	//对话框对象
	CAddRelationInfo dlg;
	dlg.m_strTitle="编辑联系人信息";
	//类别信息
	dlg.m_strFirClass=strFirClass;
	dlg.m_strSecClass=strSecClass;
	//姓名不允许编辑
	dlg.bEdit=TRUE;
	dlg.m_strName=pLeftView->VariantToCString(m_pRecordset->GetCollect("姓名"));
	dlg.m_strComName=pLeftView->VariantToCString(m_pRecordset->GetCollect("工作单位"));
	dlg.m_strComAddre=pLeftView->VariantToCString(m_pRecordset->GetCollect("单位地址"));
	dlg.m_strOfficeTel=pLeftView->VariantToCString(m_pRecordset->GetCollect("办公电话"));
	dlg.m_strHomeAddre=pLeftView->VariantToCString(m_pRecordset->GetCollect("家庭地址"));
	dlg.m_strHomeTel=pLeftView->VariantToCString(m_pRecordset->GetCollect("家庭电话"));
	dlg.m_strMobile=pLeftView->VariantToCString(m_pRecordset->GetCollect("移动电话"));
	dlg.m_strEmail=pLeftView->VariantToCString(m_pRecordset->GetCollect("电子邮件"));
	dlg.m_strWeb=pLeftView->VariantToCString(m_pRecordset->GetCollect("个人主页"));
	dlg.m_strComment=pLeftView->VariantToCString(m_pRecordset->GetCollect("备注"));	
	//出生日期 
	dlg.m_OleBirthDay=m_pRecordset->GetCollect("出生日期");
	//准备完毕
	dlg.DoModal();
	*pResult = 0;
}

BOOL CRightListView::OpenRecordSet(_RecordsetPtr &recPtr, CString &strSQL)
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
		strError.Format("警告： 打开数据表时发生异常。 错误信息： %s",\
			e.ErrorMessage());
		AfxMessageBox(strError);
		return FALSE;
	}
	return TRUE;
}

BOOL CRightListView::SetDbToFile(_RecordsetPtr &recPtr, CString &strPath)
{
	long lPhotoSize = recPtr->Fields->Item["照片"]->ActualSize;
	//如果没有照片则返回
	if(lPhotoSize==0)
	{
		return FALSE;
	}
	//有照片
	long lIsRead=0;   
	CFile f;
	f.Open(strPath,CFile::modeWrite|CFile::modeCreate);
	_variant_t varChunk;
	BYTE buf[ChunkSize];
	while(lPhotoSize>0)
	{
		lIsRead=lPhotoSize>=ChunkSize? ChunkSize:lPhotoSize;
		
		//从字段data中获取一个数据包
		varChunk = recPtr->Fields->
			Item["照片"]->GetChunk(lIsRead);
		for(long index=0;index<lIsRead;index++)         
		{           
			::SafeArrayGetElement(varChunk.parray,&index,buf+index);   
		}		
		//将数据包写入文件
		f.Write(buf,lIsRead);
		lPhotoSize-=lIsRead;
	}
	f.Close();
	return TRUE;
}

void CRightListView::OnKillfocusList(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	CMainFrame* pMainFrm=(CMainFrame*)AfxGetMainWnd();
	//寻找当前选中的记录的位置
	POSITION pos=m_listCtrl.GetFirstSelectedItemPosition();
    //获取当前记录的位置游标
	int iIndex=m_listCtrl.GetNextSelectedItem(pos);
	if(iIndex!=-1)
	{
		//使当前的选项落选，mask为LVIS_SELECTED|LVIS_FOCUSED，状态设为0即可：）
		m_listCtrl.SetItemState(iIndex,0, LVIS_SELECTED|LVIS_FOCUSED);
		pMainFrm->bListSel=TRUE;
	}
	*pResult = 0;
}
