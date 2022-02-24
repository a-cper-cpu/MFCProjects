// PageCou.cpp : implementation file
//

#include "stdafx.h"
#include "UGMS.h"
#include "PageCou.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPageCou dialog


CPageCou::CPageCou(CWnd* pParent /*=NULL*/)
	: CDialog(CPageCou::IDD, pParent)
{
	//{{AFX_DATA_INIT(CPageCou)
	m_CKind = -1;
	m_CID = 0;
	m_CName = _T("");
	m_CScore = 0;
	//}}AFX_DATA_INIT
}


void CPageCou::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPageCou)
	DDX_Control(pDX, IDC_EDIT_COUID, m_ctlCID);
	DDX_Control(pDX, IDC_BUTTON_QUERY, m_btnQuery);
	DDX_Control(pDX, IDC_BUTTON_PREVIOUS, m_btnPre);
	DDX_Control(pDX, IDC_BUTTON_OK, m_btnOk);
	DDX_Control(pDX, IDC_BUTTON_NEXT, m_btnNext);
	DDX_Control(pDX, IDC_BUTTON_MODIFY, m_btnModify);
	DDX_Control(pDX, IDC_BUTTON_LAST, m_btnLast);
	DDX_Control(pDX, IDC_BUTTON_FIRST, m_btnFirst);
	DDX_Control(pDX, IDC_BUTTON_DELETE, m_btnDel);
	DDX_Control(pDX, IDC_BUTTON_ADD, m_btnAdd);
	DDX_CBIndex(pDX, IDC_COMBO_KIND, m_CKind);
	DDX_Text(pDX, IDC_EDIT_COUID, m_CID);
	DDX_Text(pDX, IDC_EDIT_COUNAME, m_CName);
	DDX_Text(pDX, IDC_EDIT_COUSCORE, m_CScore);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CPageCou, CDialog)
	//{{AFX_MSG_MAP(CPageCou)
	ON_BN_CLICKED(IDC_BUTTON_FIRST, OnButtonFirst)
	ON_BN_CLICKED(IDC_BUTTON_PREVIOUS, OnButtonPrevious)
	ON_BN_CLICKED(IDC_BUTTON_NEXT, OnButtonNext)
	ON_BN_CLICKED(IDC_BUTTON_LAST, OnButtonLast)
	ON_BN_CLICKED(IDC_BUTTON_QUERY, OnButtonQuery)
	ON_BN_CLICKED(IDC_BUTTON_ADD, OnButtonAdd)
	ON_BN_CLICKED(IDC_BUTTON_DELETE, OnButtonDelete)
	ON_BN_CLICKED(IDC_BUTTON_MODIFY, OnButtonModify)
	ON_BN_CLICKED(IDC_BUTTON_OK, OnButtonOk)
	ON_BN_CLICKED(IDC_BUTTON_CANCEL, OnButtonCancel)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPageCou message handlers
enum enumCOU
{
	NONE,		//对应没有功能
	SEARCH,		//对应查找功能
	ADD,		//对应添加功能
	DEL,		//对应删除功能
	MODIFY,		//对应修改功能
};

//定义枚举变量FOUNCTION
enumCOU FOUNCTION = NONE;
BOOL CPageCou::OnInitDialog()
{	
	CDialog::OnInitDialog();
	// TODO: ADD extra initialization here
	//创建记录集对象
	m_pRecordset.CreateInstance(__uuidof(Recordset));
	m_pRecordsetCHO.CreateInstance(__uuidof(Recordset));

	//打开COURSES表
	OpenCOURSES();

	_variant_t var;
	CString str;		
	
	try
	{
		if(!m_pRecordset->BOF)
		{
			m_pRecordset->MoveFirst();
		}
		//如果表内数据为空，设置控件属性并初始对话框
		else
		{
			AfxMessageBox("表内数据为空");
			m_btnQuery.EnableWindow(FALSE);
			m_btnDel.EnableWindow(FALSE);
			m_btnModify.EnableWindow(FALSE);
			m_btnFirst.EnableWindow(FALSE);
			m_btnPre.EnableWindow(FALSE);
			m_btnNext.EnableWindow(FALSE);
			m_btnLast.EnableWindow(FALSE);
			m_btnOk.SetFocus();	
			return TRUE;
		}
		//
		// 读入库中首字段并加入控件中
		//
		//更新编辑框m_CID		
		var = m_pRecordset->GetCollect("CID");
		if(var.vt != VT_NULL)		
		m_CID = var.iVal ;

        //更新编辑框m_CName
		var = m_pRecordset->GetCollect("CName");
		str = (LPCSTR)_bstr_t(var);
		m_CName = str;

        //更新组合框m_CScore
		var = m_pRecordset->GetCollect("CScore");
		m_CScore = var.iVal;

        //更新组合框m_CKind
		var = m_pRecordset->GetCollect("CKind");
		m_CKind = var.iVal;

	    //更新所有控件显示
		UpdateData(false);
	}
	catch(_com_error *e)
	{
		AfxMessageBox(e->ErrorMessage());
	}

	return TRUE;

}
void CPageCou::OpenCOURSES()
{
	//在ADO操作中建议语句中要常用try...catch()来捕获错误信息,
    //因为它有时会经常出现一些想不到的错误
	try
	{
		//从SQL数据库中打开STUDENTS表
		m_pRecordset->Open("SELECT * FROM COURSES", 
							theApp.m_pConnection.GetInterfacePtr(),
							adOpenDynamic,
							adLockOptimistic,
							adCmdText);
	}
	catch(_com_error *e)
	{
		AfxMessageBox(e->ErrorMessage());
	}
}
//////////////////////////
//
//执行查找功能
//
/////////////////////////
void CPageCou::Query()
{
	//定义变量
	_variant_t var;
	CString str;
	//更新控件变量的值
	UpdateData(true);

	try
	{
		m_pRecordset->MoveFirst();
		while(!m_pRecordset->adoEOF)
		{
			var = m_pRecordset->GetCollect("CID");			
			if(m_CID == var.iVal)
			{
				var = m_pRecordset->GetCollect("CID");
				if(var.vt != VT_NULL)
				{
					m_CID = var.iVal;
				}

				var = m_pRecordset->GetCollect("CName");
				str = (LPCSTR)_bstr_t(var);
				m_CName = str;

				var = m_pRecordset->GetCollect("CScore");
				if(var.vt != VT_NULL)
				{
					m_CScore = var.iVal;
				}

				var = m_pRecordset->GetCollect("CKind");
				if(var.vt != VT_NULL)
				{
					m_CKind = var.iVal;
				}
			
				UpdateData(false);					
				break;
			}
			else 
			{
				m_pRecordset->MoveNext();
			}
		}
		if(m_pRecordset->adoEOF)
		{
			MessageBox("没有这个课程号！");
		}
	}
	catch(_com_error *e)
	{
		AfxMessageBox(e->ErrorMessage());
	}
}
//////////////////////////
//
//执行添加功能
//
/////////////////////////
void CPageCou::Add()
{
	//定义变量
	_variant_t var;
	CString str;
	//更新控件变量的值
	UpdateData(true);

    //判断要添加的课程号是否存在
	if(m_CID != 0 && !m_pRecordset->BOF)
	{
		m_pRecordset->MoveFirst();
		while(!m_pRecordset->adoEOF)
		{
			var = m_pRecordset->GetCollect("CID");
			if(m_CID == var.iVal)
			{
				AfxMessageBox("已经存在这个课程号！");
				break;
			}
			m_pRecordset->MoveNext();
		}
		if(!m_pRecordset->adoEOF)
		{
			return;
		}
	}

	if(m_CID == 0 )
	{
		AfxMessageBox("课程号信息不能为空!");
		return;
	}	
	else
	{
		try
		{
			//
			// 写入各字段值
			//
			m_pRecordset->AddNew();

			//写入CID字段
			var.iVal = m_CID;
			m_pRecordset->PutCollect("CID", var.iVal);

			//写入CName字段			
			m_pRecordset->PutCollect("CName", _variant_t(m_CName));

			//写入CScore字段
			var.iVal=m_CScore;
			m_pRecordset->PutCollect("CScore", var.iVal);

			//写入CKind字段
			var.iVal=m_CKind;
			m_pRecordset->PutCollect("CKind", var.iVal);
			//更新SQL数据库
			m_pRecordset->Update();

			//当前记录移动到最后
			m_pRecordset->MoveLast();

			AfxMessageBox("插入成功!");			
		}
		catch(_com_error *e)
		{
			AfxMessageBox(e->ErrorMessage());
		}
	}
}

//////////////////////////
//
//执行删除功能
//
/////////////////////////
void CPageCou::Delete()
{
	//定义变量
	_variant_t var;
	CString str;

	//判断当前是否有记录
	if(m_CID == 0)
	{
		MessageBox(" 没有记录！");
		return;
	}
	//判断是否作为外键被使用
	str.Format("select * from CHOICES where CID = %d",m_CID);
	m_pRecordsetCHO->Open(str.AllocSysString(), 
							theApp.m_pConnection.GetInterfacePtr(),
							adOpenDynamic,
							adLockOptimistic,
							adCmdText);
	if(!m_pRecordsetCHO->BOF)
	{
		AfxMessageBox("此数据正在被其他表使用，不能删除！");
		m_pRecordsetCHO->Close();
		return;
	}
	else
	{
		m_pRecordsetCHO->Close();
	}

	try
	{
		//
		// 删除当前行记录
		//
		m_pRecordset->Delete(adAffectCurrent);
		m_pRecordset->Update();

		m_pRecordset->MoveFirst();

		//判断删除后表内数据是否为空
		if(m_pRecordset->BOF)
		{
			AfxMessageBox("表内数据已经为空！");
			m_btnQuery.EnableWindow(FALSE);
			m_btnDel.EnableWindow(FALSE);
			m_btnModify.EnableWindow(FALSE);
			m_btnFirst.EnableWindow(FALSE);
			m_btnPre.EnableWindow(FALSE);
			m_btnNext.EnableWindow(FALSE);
			m_btnLast.EnableWindow(FALSE);
			m_btnOk.SetFocus();	
			return;
		}

		//显示最后一条记录		
		m_pRecordset->MoveLast();
		var = m_pRecordset->GetCollect("CID");
		if(var.vt != VT_NULL)		
		m_CID = var.iVal ;

		var = m_pRecordset->GetCollect("CName");
		str = (LPCSTR)_bstr_t(var);
		m_CName = str;

		var = m_pRecordset->GetCollect("CScore");
		m_CScore = var.iVal;

	
		var = m_pRecordset->GetCollect("CKind");
		m_CKind = var.iVal;

		UpdateData(false);				
	}
	catch(_com_error *e)
	{
		AfxMessageBox(e->ErrorMessage());
	}
}

//////////////////////////
//
//执行修改功能
//
/////////////////////////
void CPageCou::Modify()
{
	//定义变量
	_variant_t var;
	CString str;
	//更新控件变量的值
	UpdateData(true);	

	if(m_CID == 0 )
	{
		AfxMessageBox("课程号信息不能为空!");
		return;
	}
	//
	// 修改当前记录的字段值
	//
	try
	{
		var.iVal = m_CID;
		m_pRecordset->PutCollect("CID", var.iVal);
		
		m_pRecordset->PutCollect("CName", _variant_t(m_CName));

		var.iVal=m_CScore;
		m_pRecordset->PutCollect("CScore", var.iVal);

		var.iVal=m_CKind;
		m_pRecordset->PutCollect("CKind", var.iVal);

		m_pRecordset->Update();

		AfxMessageBox("修改成功!");			
	}
	catch(_com_error *e)
	{
		AfxMessageBox(e->ErrorMessage());
	}
}

void CPageCou::OnButtonFirst() 
{
	m_pRecordset->MoveFirst();
	_variant_t var;
	CString str;		
	
	try
	{
		var = m_pRecordset->GetCollect("CID");
		if(var.vt != VT_NULL)		
		m_CID = var.iVal ;

		var = m_pRecordset->GetCollect("CName");
		str = (LPCSTR)_bstr_t(var);
		m_CName = str;

		var = m_pRecordset->GetCollect("CScore");
		m_CScore =var.iVal;

		var = m_pRecordset->GetCollect("CKind");
		m_CKind =var.iVal;
	
		UpdateData(false);
	}
	catch(_com_error *e)
	{
		AfxMessageBox(e->ErrorMessage());
	}	
	// TODO: Add your control notification handler code here
	
}

void CPageCou::OnButtonPrevious() 
{
	m_pRecordset->MovePrevious();
	_variant_t var;
	CString str;	
	if(m_pRecordset->BOF)
	{
		MessageBox("已经是首记录！");
	    m_pRecordset->MoveFirst();
	}
	
	try
	{
		var = m_pRecordset->GetCollect("CID");
		if(var.vt != VT_NULL)		
		m_CID = var.iVal;

		var = m_pRecordset->GetCollect("CName");
		str = (LPCSTR)_bstr_t(var);
		m_CName = str;

		var = m_pRecordset->GetCollect("CScore");
		m_CScore= var.iVal;

		var = m_pRecordset->GetCollect("CKind");
		m_CKind= var.iVal;
	
		UpdateData(false);
	}
	catch(_com_error *e)
	{
		AfxMessageBox(e->ErrorMessage());
	}	
	// TODO: Add your control notification handler code here
	
}

void CPageCou::OnButtonNext() 
{
	m_pRecordset->MoveNext();
	_variant_t var;
	CString str;
	
	if(m_pRecordset->adoEOF)
	{
		MessageBox("已经是末记录！");
	    m_pRecordset->MoveLast();
	}
	
	try
	{
		var = m_pRecordset->GetCollect("CID");
		if(var.vt != VT_NULL)		
		m_CID = var.iVal;

		var = m_pRecordset->GetCollect("CName");
		str = (LPCSTR)_bstr_t(var);
		m_CName = str;

		var = m_pRecordset->GetCollect("CScore");
		m_CScore = var.iVal;
		
		var = m_pRecordset->GetCollect("CKind");
		m_CKind= var.iVal;
	
		UpdateData(false);
	}
	catch(_com_error *e)
	{
		AfxMessageBox(e->ErrorMessage());
	}	
	// TODO: Add your control notification handler code here
	
}

void CPageCou::OnButtonLast() 
{
	m_pRecordset->MoveLast();
	_variant_t var;
	CString str;		
	
	try
	{
		var = m_pRecordset->GetCollect("CID");
		if(var.vt != VT_NULL)		
		m_CID = var.iVal;

		var = m_pRecordset->GetCollect("CName");
		str = (LPCSTR)_bstr_t(var);
		m_CName = str;

		var = m_pRecordset->GetCollect("CScore");
		m_CScore = var.iVal;

		var = m_pRecordset->GetCollect("CKind");
		m_CKind = var.iVal;

		UpdateData(false);
	}
	catch(_com_error *e)
	{
		AfxMessageBox(e->ErrorMessage());
	}	
	// TODO: Add your control notification handler code here
	
}

void CPageCou::OnButtonQuery() 
{
	m_CID = 0;
	m_CName = "";
	m_CScore = 0;
	m_CKind=0;
	UpdateData(false);
    //更新FOUNCTION值
	FOUNCTION = SEARCH;
	//修改各个矩形按钮的属性
	m_btnQuery.SetState(TRUE);
	m_btnAdd.EnableWindow(FALSE);
	m_btnDel.EnableWindow(FALSE);
	m_btnModify.EnableWindow(FALSE);
	m_btnFirst.EnableWindow(FALSE);
	m_btnPre.EnableWindow(FALSE);
	m_btnNext.EnableWindow(FALSE);
	m_btnLast.EnableWindow(FALSE);
	m_btnOk.SetFocus();
	// TODO: Add your control notification handler code here
	
}

void CPageCou::OnButtonAdd() 
{
	//
	//给所有显示控件一个添加之前的初值
	//
	m_CID = 0;
	m_CName = "";
	m_CScore = 0;
	m_CKind=0;
	UpdateData(false);
	//更新FOUNCTION值
	FOUNCTION = ADD;
	//修改各个矩形按钮的属性
	m_btnQuery.EnableWindow(FALSE);
	m_btnAdd.SetState(TRUE);
	m_btnDel.EnableWindow(FALSE);
	m_btnModify.EnableWindow(FALSE);
	m_btnFirst.EnableWindow(FALSE);
	m_btnPre.EnableWindow(FALSE);
	m_btnNext.EnableWindow(FALSE);
	m_btnLast.EnableWindow(FALSE);
	m_btnOk.SetFocus();	
	// TODO: Add your control notification handler code here
	
}

void CPageCou::OnButtonDelete() 
{
	if(MessageBox("真的删除？\n是请按“是”，\n否请按“否”！", NULL, MB_YESNO | MB_ICONQUESTION) == IDYES)
	{
		//更新FOUNCTION值
		FOUNCTION = DEL;
		OnButtonOk();
	}
	else
	{
		OnButtonCancel();
	}
	// TODO: Add your control notification handler code here
	
}

void CPageCou::OnButtonModify() 
{
	//更新FOUNCTION值
	FOUNCTION = MODIFY;
	m_ctlCID.SetReadOnly();
	//修改各个矩形按钮的属性
	m_btnQuery.EnableWindow(FALSE);
	m_btnAdd.EnableWindow(FALSE);
	m_btnDel.EnableWindow(FALSE);
	m_btnModify.SetState(TRUE);
	m_btnFirst.EnableWindow(FALSE);
	m_btnPre.EnableWindow(FALSE);
	m_btnNext.EnableWindow(FALSE);
	m_btnLast.EnableWindow(FALSE);
	m_btnOk.SetFocus();	
	
	// TODO: Add your control notification handler code here
	
}

void CPageCou::OnButtonOk() 
{
	if(FOUNCTION == SEARCH)
	{
		Query();		
	}	
	else if(FOUNCTION == ADD)
	{
		Add();		
	}	
	else if(FOUNCTION == DEL)
	{
		Delete();		
	}	
	else if(FOUNCTION == MODIFY)		
	{
		Modify();		
	}	
	// TODO: Add your control notification handler code here
	
}

void CPageCou::OnButtonCancel() 
{
	_variant_t var;
	CString str;
	FOUNCTION=NONE;
	//如果表为空，返回不做下面的操作
	if(m_pRecordset->BOF)
	{
		m_btnAdd.SetState(false);
		return;
	}	

	//修改各个矩形按钮的属性
	m_btnQuery.EnableWindow(true);
	m_btnAdd.EnableWindow(true);
	m_btnDel.EnableWindow(true);
	m_btnModify.EnableWindow(true);
	m_btnFirst.EnableWindow(true);
	m_btnPre.EnableWindow(true);
	m_btnNext.EnableWindow(true);
	m_btnLast.EnableWindow(true);

	m_btnQuery.SetState(false);
	m_btnAdd.SetState(false);
	m_btnDel.SetState(false);
	m_btnModify.SetState(false);
	m_btnFirst.SetState(false);
	m_btnPre.SetState(false);
	m_btnNext.SetState(false);
	m_btnLast.SetState(false);
	
	m_ctlCID.SetReadOnly(FALSE);
	m_btnOk.SetFocus();
	//
	//把m_pRecordset所指当前记录显示出来
	//
	if(m_pRecordset->adoEOF)
	{
		m_pRecordset->MoveLast();
	}
	try
	{
		var = m_pRecordset->GetCollect("CID");
		if(var.vt != VT_NULL)		
		m_CID = var.iVal ;

		var = m_pRecordset->GetCollect("CName");
		str = (LPCSTR)_bstr_t(var);
		m_CName = str;

		var = m_pRecordset->GetCollect("CScore");
		m_CScore =var.iVal;

		var = m_pRecordset->GetCollect("CKind");
		m_CKind =var.iVal;
	
		UpdateData(false);
	}
	catch(_com_error *e)
	{
		AfxMessageBox(e->ErrorMessage());
	}	
	// TODO: Add your control notification handler code here
	
}
