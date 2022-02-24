// PageStat.cpp : implementation file
//

#include "stdafx.h"
#include "UGMS.h"
#include "PageStat.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPageStat dialog


CPageStat::CPageStat(CWnd* pParent /*=NULL*/)
	: CDialog(CPageStat::IDD, pParent)
{
	//{{AFX_DATA_INIT(CPageStat)
	m_Avg = 0;
	m_NPass = 0;
	m_CouNum = 0;
	m_SID = _T("");
	//}}AFX_DATA_INIT
}


void CPageStat::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPageStat)
	DDX_Control(pDX, IDC_ADODC, m_Ado);
	DDX_Control(pDX, IDC_DATAGRID, m_Data);
	DDX_Text(pDX, IDC_EDIT_AVERAGE, m_Avg);
	DDX_Text(pDX, IDC_EDIT_NPASSNum, m_NPass);
	DDX_Text(pDX, IDC_EDIT_NUMCOU, m_CouNum);
	DDX_Text(pDX, IDC_EDIT_SID, m_SID);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CPageStat, CDialog)
	//{{AFX_MSG_MAP(CPageStat)
	ON_BN_CLICKED(IDC_BUTTON_OK, OnButtonOk)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPageStat message handlers
BOOL CPageStat::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	m_pRecordset.CreateInstance(__uuidof(Recordset));
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
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
void CPageStat::OnButtonOk() 
{
		// TODO: Add your control notification handler code here
	UpdateData(true);
	_variant_t var;
	bool findSID = false;
	if(m_SID != "")
	{
		try
		{
			//先关闭已经打开的记录集对象
			m_pRecordset->Close();
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
		if(!m_pRecordset->BOF)
		{
			m_pRecordset->MoveFirst();
		}
		while(!m_pRecordset->adoEOF)
		{
			var = m_pRecordset->GetCollect("SID");
			if(atoi(m_SID) == var.iVal)
			{
				findSID = true;
				QuerySID();
				break;
			}
			else
			{
				m_pRecordset->MoveNext();
			}
		}
		if(findSID == false)
		{
			MessageBox("学号输入不正确！");
		}
		UpdateData(true);
	}

	// TODO: Add your control notification handler code here
	
}
void CPageStat::QuerySID()
{
	UpdateData(true);
	if(m_SID != "")
	{
		m_Ado.SetRecordSource("select SID as 学号, CHOICES.CID as 课程号, CName as 课程名, Score as 分数 from COURSES, CHOICES WHERE COURSES.CID = CHOICES.CID and SID = " + m_SID);
		m_Ado.Refresh();		
	}
	CString str;
	_variant_t var;
	int CouNum = 0,Avg = 0,sum = 0,NPass = 0;
	str.Format("select SID, CHOICES.CID, CName, Score from COURSES, CHOICES WHERE COURSES.CID = CHOICES.CID and SID = '%s'",m_SID);
	try
		{
			//先关闭已经打开的记录集对象
			m_pRecordset->Close();
			//
			//根据新的Sql查询语句，重新打开记录集对象
			//使用记录集对象的Open()函数
			//
			m_pRecordset->Open(str.AllocSysString(),                
						    theApp.m_pConnection.GetInterfacePtr(),
						    adOpenDynamic,
						    adLockOptimistic,
						    adCmdText);
		}
		catch(_com_error *e)
		{
			AfxMessageBox(e->ErrorMessage());
		}
	if(m_pRecordset->adoEOF)
	{
		AfxMessageBox("该生没有选课！");
		m_Ado.SetRecordSource("select * from STUDENTS");
		m_Ado.Refresh();
		return;
	}
	if(!m_pRecordset->BOF)
	{
		m_pRecordset->MoveFirst();
	}
	while(!m_pRecordset->adoEOF)
	{
		CouNum ++;
		var = m_pRecordset->GetCollect("Score");
		sum += var.iVal;
		if(var.iVal < 60)
		{
			NPass ++;
		}
		m_pRecordset->MoveNext();
	}
	m_CouNum = CouNum;
	if(CouNum != 0)
	{
		Avg = sum/CouNum;
	}
	m_Avg = Avg;
	m_NPass = NPass;
	UpdateData(false);
}
