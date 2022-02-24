// PageStu.cpp : implementation file
//

#include "stdafx.h"
#include "UGMS.h"
#include "PageStu.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPageStu dialog


CPageStu::CPageStu(CWnd* pParent /*=NULL*/)
	: CDialog(CPageStu::IDD, pParent)
{
	//{{AFX_DATA_INIT(CPageStu)
	m_SComeDate = COleDateTime::GetCurrentTime();
	m_SID = 0;
	m_SName = _T("");
	m_SSex = -1;
	//}}AFX_DATA_INIT
}


void CPageStu::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPageStu)
	DDX_Control(pDX, IDC_EDIT_SID, m_ctlSID);
	DDX_Control(pDX, IDC_BUTTON_QUERY, m_btnQuery);
	DDX_Control(pDX, IDC_BUTTON_PREVIOUS, m_btnPre);
	DDX_Control(pDX, IDC_BUTTON_OK, m_btnOk);
	DDX_Control(pDX, IDC_BUTTON_NEXT, m_btnNext);
	DDX_Control(pDX, IDC_BUTTON_MODIFY, m_btnModify);
	DDX_Control(pDX, IDC_BUTTON_LAST, m_btnLast);
	DDX_Control(pDX, IDC_BUTTON_FIRST, m_btnFirst);
	DDX_Control(pDX, IDC_BUTTON_DELETE, m_btnDel);
	DDX_Control(pDX, IDC_BUTTON_ADD, m_btnAdd);
	DDX_DateTimeCtrl(pDX, IDC_DATETIMEPICKER_SCOMEDATE, m_SComeDate);
	DDX_Text(pDX, IDC_EDIT_SID, m_SID);
	DDX_Text(pDX, IDC_EDIT_SNAME, m_SName);
	DDX_CBIndex(pDX, IDC_COMBO_SSEX, m_SSex);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CPageStu, CDialog)
	//{{AFX_MSG_MAP(CPageStu)
	ON_BN_CLICKED(IDC_BUTTON_FIRST, OnButtonFirst)
	ON_BN_CLICKED(IDC_BUTTON_QUERY, OnButtonQuery)
	ON_BN_CLICKED(IDC_BUTTON_ADD, OnButtonAdd)
	ON_BN_CLICKED(IDC_BUTTON_DELETE, OnButtonDelete)
	ON_BN_CLICKED(IDC_BUTTON_MODIFY, OnButtonModify)
	ON_BN_CLICKED(IDC_BUTTON_PREVIOUS, OnButtonPrevious)
	ON_BN_CLICKED(IDC_BUTTON_NEXT, OnButtonNext)
	ON_BN_CLICKED(IDC_BUTTON_LAST, OnButtonLast)
	ON_BN_CLICKED(IDC_BUTTON_OK, OnButtonOk)
	ON_BN_CLICKED(IDC_BUTTON_CANCEL, OnButtonCancel)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPageStu message handlers
//
//添加枚举变量来实现对不同功能的区分
//
enum enumSTU
{
	NONE,		//对应没有功能
	SEARCH,		//对应查找功能
	ADD,		//对应添加功能
	DEL,		//对应删除功能
	MODIFY,		//对应修改功能
};

//定义枚举变量FOUNCTION
enumSTU FOUNCTION = NONE;
BOOL CPageStu::OnInitDialog()
{	
	CDialog::OnInitDialog();
	// TODO: ADD extra initialization here
	//创建记录集对象
	m_pRecordset.CreateInstance(__uuidof(Recordset));
	m_pRecordsetCHO.CreateInstance(__uuidof(Recordset));

	//打开STUDENTS表
	OpenSTUDENTS();

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
		//更新编辑框m_SID		
		var = m_pRecordset->GetCollect("SID");
		if(var.vt != VT_NULL)		
		m_SID = var.iVal ;

        //更新编辑框m_SName
		var = m_pRecordset->GetCollect("SName");
		str = (LPCSTR)_bstr_t(var);
		m_SName = str;

        //更新组合框m_SSex
		var = m_pRecordset->GetCollect("SSex");
		m_SSex = var.iVal;

        //更新控件Date Time picker m_SComeDate
		var = m_pRecordset->GetCollect("SComeDate");		
		m_SComeDate = var.date;

	    //更新所有控件显示
		UpdateData(false);
	}
	catch(_com_error *e)
	{
		AfxMessageBox(e->ErrorMessage());
	}

	return TRUE;

}
void CPageStu::OpenSTUDENTS()
{
	//在ADO操作中建议语句中要常用try...catch()来捕获错误信息,
    //因为它有时会经常出现一些想不到的错误
	try
	{
		//从SQL数据库中打开STUDENTS表
		m_pRecordset->Open("SELECT * FROM STUDENTS", 
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
void CPageStu::Query()
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
			var = m_pRecordset->GetCollect("SID");			
			if(m_SID == var.iVal)
			{
				var = m_pRecordset->GetCollect("SID");
				if(var.vt != VT_NULL)
				{
					m_SID = var.iVal;
				}

				var = m_pRecordset->GetCollect("SName");
				str = (LPCSTR)_bstr_t(var);
				m_SName = str;

				var = m_pRecordset->GetCollect("SSex");
				if(var.vt != VT_NULL)
				{
					m_SSex = var.iVal;
				}

				var = m_pRecordset->GetCollect("SComeDate");		
				m_SComeDate = var.date;

			
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
			MessageBox("没有这个学号！");
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
void CPageStu::Add()
{
	//定义变量
	_variant_t var;
	CString str;
	//更新控件变量的值
	UpdateData(true);

    //判断要添加的学号是否存在
	if(m_SID != 0 && !m_pRecordset->BOF)
	{
		m_pRecordset->MoveFirst();
		while(!m_pRecordset->adoEOF)
		{
			var = m_pRecordset->GetCollect("SID");
			if(m_SID == var.iVal)
			{
				AfxMessageBox("已经存在这个学号！");
				break;
			}
			m_pRecordset->MoveNext();
		}
		if(!m_pRecordset->adoEOF)
		{
			return;
		}
	}

	if(m_SID == 0 )
	{
		AfxMessageBox("学号信息不能为空!");
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

			//写入SID字段
			var.iVal = m_SID;
			m_pRecordset->PutCollect("SID", var.iVal);

			//写入SName字段			
			m_pRecordset->PutCollect("SName", _variant_t(m_SName));

			//写入SSex字段
			var.iVal=m_SSex;
			m_pRecordset->PutCollect("SSex", var.iVal);

			//写入SComeDate字段
			var.date =m_SComeDate;
			m_pRecordset->PutCollect("SComeDate", var.date);

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
void CPageStu::Delete()
{
	//定义变量
	_variant_t var;
	CString str;

	//判断当前是否有记录
	if(m_SID == 0)
	{
		MessageBox(" 没有记录！");
		return;
	}
	//判断是否作为外键被使用
	str.Format("select * from CHOICES where SID = %d",m_SID);
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
		var = m_pRecordset->GetCollect("SID");
		if(var.vt != VT_NULL)		
		m_SID = var.iVal ;

		var = m_pRecordset->GetCollect("SName");
		str = (LPCSTR)_bstr_t(var);
		m_SName = str;

		var = m_pRecordset->GetCollect("SSex");
		m_SSex = var.iVal;

		var = m_pRecordset->GetCollect("SComeDate");		
		m_SComeDate = var.date;	
	
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
void CPageStu::Modify()
{
	//定义变量
	_variant_t var;
	CString str;
	//更新控件变量的值
	UpdateData(true);	

	if(m_SID == 0 )
	{
		AfxMessageBox("学号信息不能为空!");
		return;
	}
	//
	// 修改当前记录的字段值
	//
	try
	{
		var.iVal = m_SID;
		m_pRecordset->PutCollect("SID", var.iVal);
		
		m_pRecordset->PutCollect("SName", _variant_t(m_SName));

		var.iVal=m_SSex;
		m_pRecordset->PutCollect("SSex", var.iVal);

		var.date = m_SComeDate;
	    m_pRecordset->PutCollect("SComeDate", var.date);

		m_pRecordset->Update();

		AfxMessageBox("修改成功!");			
	}
	catch(_com_error *e)
	{
		AfxMessageBox(e->ErrorMessage());
	}
}
void CPageStu::OnButtonFirst() 
{
	m_pRecordset->MoveFirst();
	_variant_t var;
	CString str;		
	
	try
	{
		var = m_pRecordset->GetCollect("SID");
		if(var.vt != VT_NULL)		
		m_SID = var.iVal ;

		var = m_pRecordset->GetCollect("SName");
		str = (LPCSTR)_bstr_t(var);
		m_SName = str;

		var = m_pRecordset->GetCollect("SSex");
		m_SSex =var.iVal;

		var = m_pRecordset->GetCollect("SComeDate");		
		m_SComeDate= var.date;
	
		UpdateData(false);
	}
	catch(_com_error *e)
	{
		AfxMessageBox(e->ErrorMessage());
	}	
	// TODO: Add your control notification handler code here
}

void CPageStu::OnButtonQuery() 
{
	// TODO: Add your control notification handler code here
	m_SID = 0;
	m_SName = "";
	m_SSex = 0;
	m_SComeDate.SetDate(2007, 9, 1);
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
	
}

void CPageStu::OnButtonAdd() 
{
	// TODO: Add your control notification handler code here
	//
	//给所有显示控件一个添加之前的初值
	//
	m_SID = 0;
	m_SName = "";
	m_SSex = 0;
	m_SComeDate.SetDate(2007, 9, 1);
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
	
}

void CPageStu::OnButtonDelete() 
{
	// TODO: Add your control notification handler code here
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
	
}

void CPageStu::OnButtonModify() 
{
	// TODO: Add your control notification handler code here
	//更新FOUNCTION值
	FOUNCTION = MODIFY;
	m_ctlSID.SetReadOnly();
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
	
}

void CPageStu::OnButtonPrevious() 
{
	// TODO: Add your control notification handler code here
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
		var = m_pRecordset->GetCollect("SID");
		if(var.vt != VT_NULL)		
		m_SID = var.iVal;

		var = m_pRecordset->GetCollect("SName");
		str = (LPCSTR)_bstr_t(var);
		m_SName = str;

		var = m_pRecordset->GetCollect("SSex");
		m_SSex = var.iVal;

		var = m_pRecordset->GetCollect("SComeDate");		
		m_SComeDate = var.date;
	
		UpdateData(false);
	}
	catch(_com_error *e)
	{
		AfxMessageBox(e->ErrorMessage());
	}	
	
}

void CPageStu::OnButtonNext() 
{
	// TODO: Add your control notification handler code here
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
		var = m_pRecordset->GetCollect("SID");
		if(var.vt != VT_NULL)		
		m_SID = var.iVal;

		var = m_pRecordset->GetCollect("SName");
		str = (LPCSTR)_bstr_t(var);
		m_SName = str;

		var = m_pRecordset->GetCollect("SSex");
		m_SSex = var.iVal;

		var = m_pRecordset->GetCollect("SComeDate");		
		m_SComeDate= var.date;	
	
		UpdateData(false);
	}
	catch(_com_error *e)
	{
		AfxMessageBox(e->ErrorMessage());
	}	
	
}

void CPageStu::OnButtonLast() 
{
	// TODO: Add your control notification handler code here
	m_pRecordset->MoveLast();
	_variant_t var;
	CString str;		
	
	try
	{
		var = m_pRecordset->GetCollect("SID");
		if(var.vt != VT_NULL)		
		m_SID = var.iVal;

		var = m_pRecordset->GetCollect("SName");
		str = (LPCSTR)_bstr_t(var);
		m_SName = str;

		var = m_pRecordset->GetCollect("SSex");
		m_SSex = var.iVal;

		var = m_pRecordset->GetCollect("SComeDate");		
		m_SComeDate= var.date;
	
		UpdateData(false);
	}
	catch(_com_error *e)
	{
		AfxMessageBox(e->ErrorMessage());
	}	
	
}

void CPageStu::OnButtonOk() 
{
	// TODO: ADD your control notification handler code here	
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

void CPageStu::OnButtonCancel() 
{
	// TODO: Add your control notification handler code here
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
	
	m_ctlSID.SetReadOnly(FALSE);
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
		var = m_pRecordset->GetCollect("SID");
		if(var.vt != VT_NULL)		
		m_SID = var.iVal ;

		var = m_pRecordset->GetCollect("SName");
		str = (LPCSTR)_bstr_t(var);
		m_SName = str;

		var = m_pRecordset->GetCollect("SSex");
		m_SSex =var.iVal;

		var = m_pRecordset->GetCollect("SComeDate");		
		m_SComeDate = var.date;	
	
		UpdateData(false);
	}
	catch(_com_error *e)
	{
		AfxMessageBox(e->ErrorMessage());
	}	
	
}
