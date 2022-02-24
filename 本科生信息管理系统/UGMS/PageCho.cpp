// PageCho.cpp : implementation file
//

#include "stdafx.h"
#include "UGMS.h"
#include "PageCho.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPageCho dialog


CPageCho::CPageCho(CWnd* pParent /*=NULL*/)
	: CDialog(CPageCho::IDD, pParent)
{
	//{{AFX_DATA_INIT(CPageCho)
	m_IsPass = -1;
	m_CID = 0;
	m_Score = 0;
	m_SID = 0;
	//}}AFX_DATA_INIT
}


void CPageCho::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPageCho)
	DDX_Control(pDX, IDC_EDIT_SID, m_ctlSID);
	DDX_Control(pDX, IDC_EDIT_CHOID, m_ctlCID);
	DDX_Control(pDX, IDC_BUTTON_QUERY, m_btnQuery);
	DDX_Control(pDX, IDC_BUTTON_PREVIOUS, m_btnPre);
	DDX_Control(pDX, IDC_BUTTON_OK, m_btnOk);
	DDX_Control(pDX, IDC_BUTTON_NEXT, m_btnNext);
	DDX_Control(pDX, IDC_BUTTON_MODIFY, m_btnModify);
	DDX_Control(pDX, IDC_BUTTON_LAST, m_btnLast);
	DDX_Control(pDX, IDC_BUTTON_FIRST, m_btnFirst);
	DDX_Control(pDX, IDC_BUTTON_DELETE, m_btnDel);
	DDX_Control(pDX, IDC_BUTTON_ADD, m_btnAdd);
	DDX_CBIndex(pDX, IDC_COMBO_PASS, m_IsPass);
	DDX_Text(pDX, IDC_EDIT_CHOID, m_CID);
	DDX_Text(pDX, IDC_EDIT_SCORE, m_Score);
	DDX_Text(pDX, IDC_EDIT_SID, m_SID);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CPageCho, CDialog)
	//{{AFX_MSG_MAP(CPageCho)
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
// CPageCho message handlers
//
//添加枚举变量来实现对不同功能的区分
//
enum enumCHO
{
	NONE,		//对应没有功能
	SEARCH,		//对应查找功能
	ADD,		//对应添加功能
	DEL,		//对应删除功能
	MODIFY,		//对应修改功能
};

//定义枚举变量FOUNCTION
enumCHO FOUNCTION = NONE;

BOOL CPageCho::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: ADD extra initialization here
	//创建记录集对象
	m_pRecordset.CreateInstance(__uuidof(Recordset));
	//打开CHOICES表
	OpenCHOICES();

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

        //更新编辑框m_SID
		var = m_pRecordset->GetCollect("SID");
		if(var.vt != VT_NULL)		
		m_SID = var.iVal;

        //更新组合框IsPass
		var = m_pRecordset->GetCollect("IsPass");
		if(var.vt != VT_NULL)		
		m_IsPass = var.iVal;

        //更新编辑框m_Score
		var = m_pRecordset->GetCollect("Score");		
		m_Score = var.iVal;

	    //更新所有控件显示
		UpdateData(false);
	}
	catch(_com_error *e)
	{
		AfxMessageBox(e->ErrorMessage());
	}
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
void CPageCho::OpenSTUDENTS()
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

void CPageCho::OpenCOURSES()
{
	try
	{
		//从SQL数据库中打开COURSES表
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

void CPageCho::OpenCHOICES()
{
	try
	{
		//从SQL数据库中打开CHOICES表
		m_pRecordset->Open("SELECT * FROM CHOICES", 
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
void CPageCho::Query()
{
	//定义变量
	_variant_t var,varCou,varStu;
	CString str;
	//更新控件变量的值
	UpdateData(true);

	if(m_SID == 0 || m_CID == 0)
	{
		MessageBox("学号和课程号一个也不能为空!");
		return;
	}

	try
	{
		m_pRecordset->MoveFirst();
		while(!m_pRecordset->adoEOF)
		{
			varCou = m_pRecordset->GetCollect("CID");
			varStu = m_pRecordset->GetCollect("SID");
			//
			//注意：一个学生可以选多门课，
			//所以查询时必须满足学号和课程号同时吻合才行
			//
			if(m_CID == varCou.iVal && m_SID == varStu.iVal)
			{
				var = m_pRecordset->GetCollect("CID");
				if(var.vt != VT_NULL)
				{
					m_CID = var.iVal;
				}

				var = m_pRecordset->GetCollect("SID");
				m_SID = var.iVal;

				var = m_pRecordset->GetCollect("IsPass");
				if(var.vt != VT_NULL)		
				m_IsPass = var.iVal;

				var = m_pRecordset->GetCollect("Score");		
				m_Score = var.iVal; 
			
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
			MessageBox("该生没有选这门课程！");
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
void CPageCho::Add()
{
	//定义变量
	_variant_t var,ar;
	CString str;
	//更新控件变量的值
	UpdateData(true);

	//判断添加的学号在学生表中是否存在
	if(m_SID !=0)
	{
        m_pRecordset->Close();

		OpenSTUDENTS();

		if(m_pRecordset->BOF)
		{
			AfxMessageBox("学生表为空，需先建立学生表！");
			m_pRecordset->Close();
			OpenCHOICES();
			return;
		}
		else
		{
			m_pRecordset->MoveFirst();
			while(!m_pRecordset->adoEOF)
			{
				var = m_pRecordset->GetCollect("SID");
				if(m_SID == var.iVal)
				{
					break;
				}
				m_pRecordset->MoveNext();
			}
			if(m_pRecordset->adoEOF)
			{
				AfxMessageBox("没有这个学号！");
				m_pRecordset->Close();
				OpenCHOICES();
				return;
			}
			else
			{
				m_pRecordset->Close();
				OpenCHOICES();
			}
		}		
	}

	//判断添加的课程号在课程表中是否存在
	if(m_CID !=0)
	{
        m_pRecordset->Close();

		OpenCOURSES();

		if(m_pRecordset->BOF)
		{
			AfxMessageBox("课程表为空，需先建立课程表！");
			m_pRecordset->Close();
			OpenCOURSES();
			return;
		}
		else
		{
			m_pRecordset->MoveFirst();
			while(!m_pRecordset->adoEOF)
			{
				var = m_pRecordset->GetCollect("CID");
				if(m_CID == var.iVal)
				{
					break;
				}
				m_pRecordset->MoveNext();
			}
			if(m_pRecordset->adoEOF)
			{
				AfxMessageBox("没有这个课程号！");
				m_pRecordset->Close();
				OpenCHOICES();
				return;
			}
			else
			{
				m_pRecordset->Close();
				OpenCHOICES();
			}
		}		
	}

    //判断要添加的学生选课是否已经存在
	if(m_SID != 0 && m_CID != 0 && !m_pRecordset->BOF)
	{
		m_pRecordset->MoveFirst();
		while(!m_pRecordset->adoEOF)
		{
			var = m_pRecordset->GetCollect("SID");
			ar = m_pRecordset->GetCollect("CID");
			if(m_SID == var.iVal && m_CID == ar.iVal)
			{
				AfxMessageBox("已经存在！");
				break;
			}
			m_pRecordset->MoveNext();
		}
		if(!m_pRecordset->adoEOF)
		{
			return;
		}
	}

	if(m_CID == 0 || m_SID == 0)
	{
		AfxMessageBox("学号和课程号一个也不能为空!");
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

			//写入SID字段
			var.iVal = m_SID;
			m_pRecordset->PutCollect("SID", var.iVal);

			//写入IsPass字段
			var.iVal=m_IsPass;
			m_pRecordset->PutCollect("IsPass", var.iVal);

			//写入Score字段
			var.iVal = m_Score;
			m_pRecordset->PutCollect("Score", var.iVal);

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
void CPageCho::Delete()
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

		var = m_pRecordset->GetCollect("SID");
		if(var.vt != VT_NULL)		
		m_SID = var.iVal;

		var = m_pRecordset->GetCollect("IsPass");
		if(var.vt != VT_NULL)		
		m_IsPass = var.iVal;

		var = m_pRecordset->GetCollect("Score");		
		m_Score = var.iVal; 
	
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
void CPageCho::Modify()
{
	//定义变量
	_variant_t var;
	CString str;
	//更新控件变量的值
	UpdateData(true);

	if(m_CID == 0 || m_SID == 0)
	{
		AfxMessageBox("学号和课程号一个也不能为空!");
		return;
	}
	//
	// 修改当前记录的字段值
	//
	try
	{
		var.iVal = m_CID;
		m_pRecordset->PutCollect("CID", var.iVal);
		
		var.iVal = m_SID;
		m_pRecordset->PutCollect("SID", var.iVal);

		var.iVal=m_IsPass;
		m_pRecordset->PutCollect("IsPass", var.iVal);

		var.iVal = m_Score;
		m_pRecordset->PutCollect("Score", var.iVal);

		m_pRecordset->Update();

		AfxMessageBox("修改成功!");			
	}
	catch(_com_error *e)
	{
		AfxMessageBox(e->ErrorMessage());
	}
}

void CPageCho::OnButtonFirst() 
{
	m_pRecordset->MoveFirst();
	_variant_t var;
	CString str;		
	
	try
	{
		var = m_pRecordset->GetCollect("CID");
		if(var.vt != VT_NULL)		
		m_CID = var.iVal ;

		var = m_pRecordset->GetCollect("SID");
		if(var.vt != VT_NULL)		
		m_SID = var.iVal;

		var = m_pRecordset->GetCollect("IsPass");
		if(var.vt != VT_NULL)		
		m_IsPass = var.iVal;

		var = m_pRecordset->GetCollect("Score");		
		m_Score = var.iVal;
	
		UpdateData(false);
	}
	catch(_com_error *e)
	{
		AfxMessageBox(e->ErrorMessage());
	}	
	// TODO: Add your control notification handler code here
	
}

void CPageCho::OnButtonPrevious() 
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

		var = m_pRecordset->GetCollect("SID");
		if(var.vt != VT_NULL)		
		m_SID = var.iVal;

		var = m_pRecordset->GetCollect("IsPass");
		if(var.vt != VT_NULL)		
		m_IsPass = var.iVal;

		var = m_pRecordset->GetCollect("Score");		
		m_Score = var.iVal; 
	
		UpdateData(false);
	}
	catch(_com_error *e)
	{
		AfxMessageBox(e->ErrorMessage());
	}	
	// TODO: Add your control notification handler code here
	
}

void CPageCho::OnButtonNext() 
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

		var = m_pRecordset->GetCollect("SID");		
		m_SID = var.iVal;

		var = m_pRecordset->GetCollect("IsPass");
		if(var.vt != VT_NULL)		
		m_IsPass = var.iVal;

		var = m_pRecordset->GetCollect("Score");		
		m_Score = var.iVal; 
	
		UpdateData(false);
	}
	catch(_com_error *e)
	{
		AfxMessageBox(e->ErrorMessage());
	}
	// TODO: Add your control notification handler code here
	
}

void CPageCho::OnButtonLast() 
{
	m_pRecordset->MoveLast();
	_variant_t var;
	CString str;		
	
	try
	{
		var = m_pRecordset->GetCollect("CID");
		if(var.vt != VT_NULL)		
		m_CID = var.iVal;

		var = m_pRecordset->GetCollect("SID");
		if(var.vt != VT_NULL)		
		m_SID = var.iVal;

		var = m_pRecordset->GetCollect("IsPass");
		if(var.vt != VT_NULL)		
		m_IsPass = var.iVal;

		var = m_pRecordset->GetCollect("Score");		
		m_Score = var.iVal;
	
		UpdateData(false);
	}
	catch(_com_error *e)
	{
		AfxMessageBox(e->ErrorMessage());
	}	
	// TODO: Add your control notification handler code here
	
}

void CPageCho::OnButtonQuery() 
{
	m_CID = 0;
	m_Score =  0;
	m_SID = 0;
	m_IsPass = 0;
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

void CPageCho::OnButtonAdd() 
{
	//
	//给所有显示控件一个添加之前的初值
	//
	m_CID = 0;
	m_Score =  0;
	m_SID = 0;
	m_IsPass = 0;
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

void CPageCho::OnButtonDelete() 
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

void CPageCho::OnButtonModify() 
{
	//更新FOUNCTION值
	FOUNCTION = MODIFY;
	m_ctlSID.SetReadOnly();
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

void CPageCho::OnButtonOk() 
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

void CPageCho::OnButtonCancel() 
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

	m_ctlSID.SetReadOnly(FALSE);
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

		var = m_pRecordset->GetCollect("SID");
		if(var.vt != VT_NULL)		
		m_SID = var.iVal;

		var = m_pRecordset->GetCollect("IsPass");
		if(var.vt != VT_NULL)		
		m_IsPass = var.iVal;

		var = m_pRecordset->GetCollect("Score");		
		m_Score = var.iVal;
	
		UpdateData(false);
	}
	catch(_com_error *e)
	{
		AfxMessageBox(e->ErrorMessage());
	}	
	// TODO: Add your control notification handler code here
	
}
