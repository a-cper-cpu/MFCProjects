// AddRelationInfo.cpp : implementation file
//

/*
	作者：张超刚

*/

#include "stdafx.h"
#include "AddressList.h"
#include "AddRelationInfo.h"
#include "MainFrm.h"
#include "LeftTreeView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAddRelationInfo dialog

#define ChunkSize 1024

CAddRelationInfo::CAddRelationInfo(CWnd* pParent /*=NULL*/)
	: CDialog(CAddRelationInfo::IDD, pParent)
{
	//{{AFX_DATA_INIT(CAddRelationInfo)
	m_strComment = _T("");
	m_strComAddre = _T("");
	m_strComName = _T("");
	m_strEmail = _T("");
	m_strHomeAddre = _T("");
	m_strHomeTel = _T("");
	m_strMobile = _T("");
	m_strOfficeTel = _T("");
	m_strWeb = _T("");
	m_strName = _T("");
	m_OleBirthDay = COleDateTime::GetCurrentTime();
	m_strFirClass = _T("");
	m_strSecClass = _T("");
	//}}AFX_DATA_INIT
}


void CAddRelationInfo::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAddRelationInfo)
	DDX_Control(pDX, IDC_SECOND_CLASS, m_ComboSecond);
	DDX_Control(pDX, IDC_FIRST_CLASS, m_ComboFirst);
	DDX_Text(pDX, IDC_COMMENT, m_strComment);
	DDX_Text(pDX, IDC_COMPANY_ADDRESS, m_strComAddre);
	DDX_Text(pDX, IDC_COMPANY_NAME, m_strComName);
	DDX_Text(pDX, IDC_EMAIL, m_strEmail);
	DDX_Text(pDX, IDC_HOME_ADDRESS, m_strHomeAddre);
	DDX_Text(pDX, IDC_HOME_TEL, m_strHomeTel);
	DDX_Text(pDX, IDC_MOBILE, m_strMobile);
	DDX_Text(pDX, IDC_OFFICE_TEL, m_strOfficeTel);
	DDX_Text(pDX, IDC_WEB, m_strWeb);
	DDX_Text(pDX, IDC_NAME, m_strName);
	DDX_DateTimeCtrl(pDX, IDC_BIRTHDAY, m_OleBirthDay);
	DDX_CBString(pDX, IDC_FIRST_CLASS, m_strFirClass);
	DDX_CBString(pDX, IDC_SECOND_CLASS, m_strSecClass);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CAddRelationInfo, CDialog)
	//{{AFX_MSG_MAP(CAddRelationInfo)
	ON_BN_CLICKED(IDC_INSERT_INFO, OnInsertInfo)
	ON_BN_CLICKED(IDC_PHOTO, OnPhoto)
	ON_CBN_SELENDOK(IDC_FIRST_CLASS, OnSelendokFirstClass)
	ON_BN_CLICKED(IDC_EDIT_INFO, OnEditInfo)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAddRelationInfo message handlers

void CAddRelationInfo::OnInsertInfo() 
{
	// TODO: Add your control notification handler code here	
	//定义变量
	CString strSQL;
	//更新控件变量的值
	UpdateData(TRUE);
	//姓名、类别为空时返回
	m_ComboFirst.GetWindowText(m_strFirClass);
	m_ComboSecond.GetWindowText(m_strSecClass);
	m_strName.Remove(' ');//删除空格
	m_strFirClass.Remove(' ');
	m_strSecClass.Remove(' ');
	if(m_strName.IsEmpty()||m_strFirClass.IsEmpty()||m_strSecClass.IsEmpty())
	{
		AfxMessageBox("姓名和类别不能为空");
		return;
	}
	//打开记录集 选择表名
	strSQL="select * from info";
	if(!OpenRecordSet(m_pRecordset,strSQL))
	{
		AfxMessageBox("没有成功打开数据表");
		return;
	}
	//上述准备完毕，下面开始插入内容
	try
	{
		//添加数据,姓名只允许添加不允许更改
		m_pRecordset->AddNew();
		m_pRecordset->PutCollect("姓名",_variant_t(m_strName));
		m_pRecordset->PutCollect("工作单位",_variant_t(m_strComName));
		m_pRecordset->PutCollect("单位地址",_variant_t(m_strComAddre));
		m_pRecordset->PutCollect("办公电话",_variant_t(m_strOfficeTel));
		m_pRecordset->PutCollect("家庭地址",_variant_t(m_strHomeAddre));
		m_pRecordset->PutCollect("家庭电话",_variant_t(m_strHomeTel));
		m_pRecordset->PutCollect("移动电话",_variant_t(m_strMobile));
		m_pRecordset->PutCollect("电子邮件",_variant_t(m_strEmail));
		m_pRecordset->PutCollect("个人主页",_variant_t(m_strWeb));
		m_pRecordset->PutCollect("备注",_variant_t(m_strComment));
		//类别
		CString strText;
		m_ComboFirst.GetWindowText(strText);
		m_pRecordset->PutCollect("一级类别",_variant_t(strText));
		m_ComboSecond.GetWindowText(strText);
		m_pRecordset->PutCollect("二级类别",_variant_t(strText));
		//出生日期 
		COleDateTime oleTime;
		CDateTimeCtrl* pDtCtrl=(CDateTimeCtrl*)GetDlgItem(IDC_BIRTHDAY);
		pDtCtrl->GetTime(oleTime);
		m_pRecordset->PutCollect("出生日期",_variant_t(oleTime));
		//照片
		if(!m_strPhotoPath.IsEmpty())
		{
			SetFileToDb(m_pRecordset,m_strPhotoPath);
		}
		//更新数据库
		m_pRecordset->Update();		
		//当前记录移动到最后
		m_pRecordset->MoveLast();
	}
	catch(_com_error e)
	{
		CString strError;
		strError.Format("警告： 插入信息时发生异常。 错误信息： %s",\
			e.ErrorMessage());
		AfxMessageBox(strError);
	}
	m_pRecordset->Close();	
	m_pRecordset=NULL;

	AfxMessageBox("插入成功!");
	
	//更新树
	CMainFrame* pMainFrm=(CMainFrame*)AfxGetMainWnd();
	CLeftTreeView* pLeftView;
	pLeftView=(CLeftTreeView*)pMainFrm->m_wndSplitter.GetPane(0,0);	
	pLeftView->ShowTree();
	//将各控件值置空
	ResetCtrlValue();
}

void CAddRelationInfo::OnPhoto() 
{
	// TODO: Add your control notification handler code here
	CString strFilter="BMP Files(*.bmp)|*.bmp|All Files (*.*)|*.*||";
	CFileDialog dlg(TRUE,NULL,NULL,OFN_HIDEREADONLY|OFN_OVERWRITEPROMPT,strFilter);
	if (dlg.DoModal()!=IDOK)
	{
		return;
	}
	//获取照片路径名
	m_strPhotoPath=dlg.GetPathName();
}

void CAddRelationInfo::SetFileToDb(_RecordsetPtr &recPtr, CString strPath)
{
	VARIANT varChunk;
	SAFEARRAY *psa;
	SAFEARRAYBOUND rgsabound[1]; 	
	//VT_ARRAY | VT_UI1	
	CFile f(strPath.operator LPCTSTR(),CFile::modeRead);
	BYTE  bVal[ChunkSize+1];
	long uIsRead=0;
	//Create a safe array to store the array of BYTES  
	while(1)
	{
		//读取照片
		uIsRead=f.Read(bVal,ChunkSize);
		if(uIsRead==0)break;
		rgsabound[0].cElements =uIsRead;
		rgsabound[0].lLbound = 0;		
		///创建SAFEARRAY对象 
		psa = SafeArrayCreate(VT_UI1,1,rgsabound);
		
		for(long index=0;index<uIsRead;index++)          
		{
			if(FAILED(SafeArrayPutElement(psa,&index,&bVal[index])))
				::MessageBox(NULL,"错误。","提示",MB_OK | MB_ICONWARNING);
		}		
		//为varChunk变量赋值
		varChunk.vt = VT_ARRAY|VT_UI1;
		varChunk.parray = psa;		
		//加入BLOB类型的数据
		try{
			recPtr->Fields->GetItem("照片")->AppendChunk(varChunk);
		}
		catch (_com_error &e)
		{
			CString str=(char*)e.Description();
			::MessageBox(NULL,str+"\n错误。","提示",MB_OK | MB_ICONWARNING);
		}
		::VariantClear(&varChunk);
		::SafeArrayDestroyData( psa);
		if(uIsRead<ChunkSize)break;
	}
	f.Close();
}

BOOL CAddRelationInfo::OpenRecordSet(_RecordsetPtr &recPtr, CString &strSQL)
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

void CAddRelationInfo::ResetCtrlValue()
{
	//初始化各控件值
	m_strComment=_T("");
	m_strComAddre=_T("");
	m_strComName=_T("");
	m_strEmail=_T("");
	m_strHomeAddre=_T("");
	m_strHomeTel=_T("");
	m_strMobile=_T("");
	m_strOfficeTel=_T("");
	m_strWeb=_T("");
	m_strName=_T("");
	UpdateData(FALSE);
}

BOOL CAddRelationInfo::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	CMainFrame* pMainFrm=(CMainFrame*)AfxGetMainWnd();
	CLeftTreeView* pLeftView;
	pLeftView=(CLeftTreeView*)pMainFrm->m_wndSplitter.GetPane(0,0);
	CTreeCtrl& treeCtrl=pLeftView->m_treeCtrl;
	HTREEITEM hRootItem,hChildItem;
	hRootItem=treeCtrl.GetRootItem();
	//初始化第一个组合框
	//此字符串变量只用于中间变量
	CString strTextTem;
	if(hRootItem)
	{
		hChildItem=treeCtrl.GetChildItem(hRootItem);
		if(hChildItem)
		{
			while(hChildItem)
			{
				//加入链表以便以后使用
				m_hItemList.AddTail(hChildItem);
				strTextTem=treeCtrl.GetItemText(hChildItem);
				//将字符串内容加入组合框
				m_ComboFirst.AddString(strTextTem);
				hChildItem=treeCtrl.GetNextSiblingItem(hChildItem);
			}
			//第一个组合框默认选择
			if(!bEdit)
			{
				m_ComboFirst.SetCurSel(0);
				m_ComboFirst.GetLBText(m_ComboFirst.GetCurSel(),m_strFirClass);
			}
			else
			{
				m_ComboSecond.SetWindowText(m_strFirClass);
			}
			//所以经过上述循环后，strText保存的是树中最后一个一级类别
		}
	}
	
	//初始化第二个组合框
	HTREEITEM hSelItem;
	POSITION pos;
	pos=m_hItemList.GetHeadPosition();
	while(pos)
	{
		hSelItem=m_hItemList.GetNext(pos);
		CString strCur;
		strCur=treeCtrl.GetItemText(hSelItem);
		//找到相应的项后，将其子项全部加入第二个组合框
		if(!m_strFirClass.Compare(strCur))
		{			
			//获取二级类别
			hChildItem=treeCtrl.GetChildItem(hSelItem);
			if(hChildItem)
			{
				while(hChildItem)
				{//获取二级类别的标题并加入组合框
					strTextTem=treeCtrl.GetItemText(hChildItem);
					//将字符串内容加入组合框
					m_ComboSecond.AddString(strTextTem);
					hChildItem=treeCtrl.GetNextSiblingItem(hChildItem);
				}
				//默认选择
				if(!bEdit)
				{
					m_ComboSecond.SetCurSel(0);
				}
				else
				{
					m_ComboSecond.SetWindowText(m_strSecClass);
				}
			}
			break;
		}
	}
	//设置对话框标题
	SetWindowText(m_strTitle);
	CEdit* pEdit=(CEdit*)GetDlgItem(IDC_NAME);
	//当前对话框是否用来编辑，姓名类别等不允许编辑
	pEdit->EnableWindow(!bEdit);
	m_ComboSecond.EnableWindow(!bEdit);
	m_ComboFirst.EnableWindow(!bEdit);
	if(bEdit)
	{
		CButton* pButton=(CButton*)GetDlgItem(IDC_INSERT_INFO);
		pButton->ShowWindow(SW_HIDE);
		pButton=(CButton*)GetDlgItem(IDOK);
		pButton->ShowWindow(SW_HIDE);
	}
	else
	{
		CButton* pButton=(CButton*)GetDlgItem(IDC_EDIT_INFO);
		pButton->ShowWindow(SW_HIDE);
		pButton=(CButton*)GetDlgItem(IDCANCEL);
		pButton->ShowWindow(SW_HIDE);
	}
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CAddRelationInfo::OnSelendokFirstClass() 
{
	// TODO: Add your control notification handler code here
	CMainFrame* pMainFrm=(CMainFrame*)AfxGetMainWnd();
	CLeftTreeView* pLeftView;
	pLeftView=(CLeftTreeView*)pMainFrm->m_wndSplitter.GetPane(0,0);
	CTreeCtrl& treeCtrl=pLeftView->m_treeCtrl;
	HTREEITEM hChildItem,hSelItem;
	CString strText;
	m_ComboFirst.GetLBText(m_ComboFirst.GetCurSel(),strText);
	//初始化第二个组合框,，首先清除组合框中所有内容
	m_ComboSecond.ResetContent();
	POSITION pos;
	pos=m_hItemList.GetHeadPosition();
	while(pos)
	{
		hSelItem=m_hItemList.GetNext(pos);
		CString strCur;
		strCur=treeCtrl.GetItemText(hSelItem);
		//找到相应的项后，将其子项全部加入第二个组合框
		if(!strText.Compare(strCur))
		{			
			hChildItem=treeCtrl.GetChildItem(hSelItem);
			if(hChildItem)
			{
				while(hChildItem)
				{
					strText=treeCtrl.GetItemText(hChildItem);
					m_ComboSecond.AddString(strText);
					hChildItem=treeCtrl.GetNextSiblingItem(hChildItem);
				}
			}
			break;
		}
	}
	m_ComboSecond.SetCurSel(0);
}

void CAddRelationInfo::OnEditInfo() 
{
	// TODO: Add your control notification handler code here
	//定义变量
	CString strSQL;
	//更新控件变量的值
	UpdateData(TRUE);
/*	//姓名、类别为空时返回
	m_ComboFirst.GetWindowText(m_strFirClass);
	m_ComboSecond.GetWindowText(m_strSecClass);
	m_strFirClass.Remove(' ');//删除空格
	m_strSecClass.Remove(' ');
	if(m_strFirClass.IsEmpty()||m_strSecClass.IsEmpty())
	{
		AfxMessageBox("类别不能为空");
		return;
	}*/
	//打开记录集 选择表名
	CString strTem;
	strTem.Format("姓名='%s' and 二级类别='%s' and 一级类别='%s'\
		",m_strName,m_strSecClass,m_strFirClass);
	strSQL="select * from info where "+strTem;
	if(!OpenRecordSet(m_pRecordset,strSQL))
	{
		AfxMessageBox("没有成功打开数据表");
		return;
	}
	if(!m_pRecordset->BOF)
	{
		m_pRecordset->MoveFirst();
	}
	//上述准备完毕，下面开始插入内容
	try
	{
		//添加数据,姓名、一级二级类别只允许添加不允许更改
//		m_pRecordset->PutCollect("姓名",_variant_t(m_strName));
		m_pRecordset->PutCollect("工作单位",_variant_t(m_strComName));
		m_pRecordset->PutCollect("单位地址",_variant_t(m_strComAddre));
		m_pRecordset->PutCollect("办公电话",_variant_t(m_strOfficeTel));
		m_pRecordset->PutCollect("家庭地址",_variant_t(m_strHomeAddre));
		m_pRecordset->PutCollect("家庭电话",_variant_t(m_strHomeTel));
		m_pRecordset->PutCollect("移动电话",_variant_t(m_strMobile));
		m_pRecordset->PutCollect("电子邮件",_variant_t(m_strEmail));
		m_pRecordset->PutCollect("个人主页",_variant_t(m_strWeb));
		m_pRecordset->PutCollect("备注",_variant_t(m_strComment));
		//类别
/*		CString strText;
		m_ComboFirst.GetWindowText(strText);
		m_pRecordset->PutCollect("一级类别",_variant_t(strText));
		m_ComboSecond.GetWindowText(strText);
		m_pRecordset->PutCollect("二级类别",_variant_t(strText));
		*/
		//出生日期 
		COleDateTime oleTime;
		CDateTimeCtrl* pDtCtrl=(CDateTimeCtrl*)GetDlgItem(IDC_BIRTHDAY);
		pDtCtrl->GetTime(oleTime);
		m_pRecordset->PutCollect("出生日期",_variant_t(oleTime));
		//照片
		if(!m_strPhotoPath.IsEmpty())
		{
			SetFileToDb(m_pRecordset,m_strPhotoPath);
		}
		//更新数据库
		m_pRecordset->Update();		
		//当前记录移动到最后
		m_pRecordset->MoveLast();
	}
	catch(_com_error e)
	{
		CString strError;
		strError.Format("警告：插入信息时发生异常。错误信息： %s",\
			e.ErrorMessage());
		AfxMessageBox(strError);
	}
	m_pRecordset->Close();	
	m_pRecordset=NULL;	
	//编辑完成后，对话框自动消失，模拟点击OK
	WPARAM wParam=MAKEWPARAM(IDOK,BN_CLICKED);
	SendMessage(WM_COMMAND,wParam);//第三个参数为控件句柄
	//更新树
	CMainFrame* pMainFrm=(CMainFrame*)AfxGetMainWnd();
	CLeftTreeView* pLeftView;
	pLeftView=(CLeftTreeView*)pMainFrm->m_wndSplitter.GetPane(0,0);	
	pLeftView->ShowTree();
	AfxMessageBox("编辑成功");
}
