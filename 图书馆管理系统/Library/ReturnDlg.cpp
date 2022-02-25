// ReturnDlg.cpp : implementation file
//

#include "stdafx.h"
#include "time.h"
#include "Library.h"
#include "ReturnDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CReturnDlg dialog


CReturnDlg::CReturnDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CReturnDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CReturnDlg)
	m_Book_ID = _T("");
	m_BorrowDate = _T("");
	m_Days = 0;
	m_ReaderName = _T("");
	m_ReturnDate = _T("");
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CReturnDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CReturnDlg)
	DDX_Control(pDX, IDC_BOOK_ID, m_ctlBookID);
	DDX_Text(pDX, IDC_BOOK_ID, m_Book_ID);
	DDX_Text(pDX, IDC_BORROWDATE, m_BorrowDate);
	DDX_Text(pDX, IDC_DAYS, m_Days);
	DDX_Text(pDX, IDC_READERNAME, m_ReaderName);
	DDX_Text(pDX, IDC_RETURNDATE, m_ReturnDate);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CReturnDlg, CDialog)
	//{{AFX_MSG_MAP(CReturnDlg)
	ON_BN_CLICKED(ID_CONFIRM, OnConfirm)
	ON_WM_KILLFOCUS()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CReturnDlg message handlers
int CReturnDlg::QryBorrow()
{

	int result;
	CTime  m_ReturnDate_tmp;
	CString m_strtmp;
	CTime  m_Current_Time=CTime::GetCurrentTime();
	CTimeSpan m_TimeSpan_tmp(30,0,0,0);
	UpdateData(true);
	if (strcmp(m_Book_ID,"")==0) 
		return 0;
	m_ReaderName="";
	m_BorrowDate="";
	m_ReturnDate="";
	m_Days=0;
	m_rsDataSet.m_strFilter ="reader.reader_ID=borrow.reader_ID and BOOK_ID='"+m_Book_ID+"'";
	if (!m_rsDataSet.Open())
	{
		AfxMessageBox("数据打开失败！");
		return -1;
	}
	
	m_rsDataSet.Requery();
	if (m_rsDataSet.GetRecordCount()!=0) 
	{
		m_ReaderName=m_rsDataSet.m_ReaderName ;
		m_BorrowDate=m_rsDataSet.m_BORROW_DATE.Format("%Y-%m-%d") ;
		m_ReturnDate_tmp=m_rsDataSet.m_BORROW_DATE+m_TimeSpan_tmp;
		m_ReturnDate=m_ReturnDate_tmp.Format("%Y-%m-%d");
		if (m_ReturnDate_tmp<m_Current_Time)
		{
			m_TimeSpan_tmp=CTime::GetCurrentTime()-m_ReturnDate_tmp;
			m_Days=m_TimeSpan_tmp.GetDays();
			UpdateData(false);
			result=1;			
			
		}
		else
		{
			UpdateData(false);		
			result=2;			
		}		

	}
	else
	{
		AfxMessageBox("没有该书的借书信息!");
		UpdateData(false);		
		result=0;
	}
	m_rsDataSet.Close();
	return result;
}


int CReturnDlg::Insert_History()
{
	CDatabase mdb;
	CString   m_strsql;

	if(!mdb.Open(_T("library")))
	{
		AfxMessageBox("数据库执行出错");
		return 0;
	}

	m_strsql="INSERT INTO HISTORY (READER_ID,BOOK_ID,BORROW_DATE,RETURN_DATE) VALUES ('"+m_rsDataSet.m_READER_ID+"'";
	m_strsql=m_strsql+",'"+m_rsDataSet.m_BOOK_ID+"'";
	m_strsql=m_strsql+",'"+m_BorrowDate+"'";
	m_strsql=m_strsql+",'"+(CTime::GetCurrentTime()).Format("%Y,%B %d")+"')";
	try
	{
		mdb.BeginTrans();
		mdb.ExecuteSQL(m_strsql);
		mdb.CommitTrans();
	}
	catch(CDBException e)
	{
		AfxMessageBox("数据库执行出错");
		return 0;
	}
	return 1;
}

int CReturnDlg::SetTxtNull()
{	
	CWnd *pWnd;
	m_Book_ID="";
	m_BorrowDate="";
	m_Days=0;
	m_ReaderName="";
	m_ReturnDate="";
	UpdateData(false);
	pWnd=GetDlgItem(IDC_BOOK_ID);
	return 1;
}

int CReturnDlg::setTxtDisable()
{
	CWnd *pWnd;
	pWnd=GetDlgItem(IDC_READERNAME);
	pWnd->EnableWindow(false);
	pWnd=GetDlgItem(IDC_BORROWDATE);
	pWnd->EnableWindow(false);
	pWnd=GetDlgItem(IDC_RETURNDATE);
	pWnd->EnableWindow(false);
	pWnd=GetDlgItem(IDC_DAYS);
	pWnd->EnableWindow(false);
	return 1;

}

BOOL CReturnDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	return true;
}


void CReturnDlg::OnConfirm() 
{
	int rs;
	CWnd *pWnd;
	CString m_strtmp;

	rs=QryBorrow();
	if(rs==1)
	{
		m_strtmp.Format("超期%d天,确认还书？",m_Days);
		if(::MessageBox(this->m_hWnd,m_strtmp,"提示",MB_YESNO)==IDYES)
		{
			Insert_History();
			Delete_Borrow();
			SetTxtNull();
			
		}
		else
		{
			return;
		}
		
	}
	else if(rs==2)
	{
		if(::MessageBox(this->m_hWnd,"确认还书?","提示",MB_YESNO)==IDYES)
		{
			Insert_History();
			Delete_Borrow();
			SetTxtNull();
		}
		else
		{
			return;
		}

	}
	else if(rs==0)
	{
		if (m_Book_ID == "")
			return;
		::MessageBox(this->m_hWnd,"该书号信息不存在！","警告",MB_OK);
	}  
	
	// TODO: Add your control notification handler code here
	pWnd=GetDlgItem(IDC_BOOK_ID);
	pWnd->SetFocus();
	// TODO: Add your control notification handler code here
	
}

void CReturnDlg::Delete_Borrow()
{
	CDatabase mdb;
	CString   m_strsql;

	if(!mdb.Open(_T("library")))
	{
		AfxMessageBox("数据库执行出错");
		return;
	}

	m_strsql="DELETE FROM BORROW WHERE BOOK_ID=";
	m_strsql+="'";
	m_strsql+=m_Book_ID;
	m_strsql+="'";
	try
	{
		mdb.BeginTrans();
		mdb.ExecuteSQL(m_strsql);
		mdb.CommitTrans();
	}
	catch(CDBException e)
	{
		AfxMessageBox("数据库执行出错");
		return ;
	}


}



BOOL CReturnDlg::PreTranslateMessage(MSG* pMsg) 
{
	// TODO: Add your specialized code here and/or call the base class
    if(pMsg -> message == WM_KEYDOWN)
	{
		if(pMsg -> wParam == VK_RETURN)
		{
			QryBorrow();
			return TRUE;

		}
		
	} 
	return CDialog::PreTranslateMessage(pMsg);
}


