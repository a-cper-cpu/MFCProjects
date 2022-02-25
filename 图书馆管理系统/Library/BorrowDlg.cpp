// BorrowDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Library.h"
#include "BorrowDlg.h"

#include "BorrowDataSet.h"
#include "ReaderDataSet.h"
#include "BookDataSet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CBorrowDlg dialog


CBorrowDlg::CBorrowDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CBorrowDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CBorrowDlg)
	m_strBookID = _T("");
	m_strReaderID = _T("");
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CBorrowDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CBorrowDlg)
	DDX_Text(pDX, IDC_BOOK_ID, m_strBookID);
	DDV_MaxChars(pDX, m_strBookID, 8);
	DDX_Text(pDX, IDC_READER_ID, m_strReaderID);
	DDV_MaxChars(pDX, m_strReaderID, 8);
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CBorrowDlg, CDialog)
	//{{AFX_MSG_MAP(CBorrowDlg)
	ON_BN_CLICKED(IDC_CONFIRM, OnConfirm)
	ON_BN_CLICKED(IDC_CANCEL, OnCancel)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBorrowDlg message handlers
void CBorrowDlg::OnConfirm() 
{
	// TODO: Add your control notification handler code here
	BOOL m_bCanBorrow;
	BOOL m_bCanLendOut;
	m_bCanBorrow = FALSE;
	m_bCanLendOut = FALSE;
	CString mSqlStr;

	UpdateData(TRUE);

	if (!m_rsReaderDataSet.Open(AFX_DB_USE_DEFAULT_TYPE))
	{
		AfxMessageBox("数据表打开错误!");
		return;
	}
	
	m_rsReaderDataSet.m_strFilter = "READER_ID='" + m_strReaderID;
	m_rsReaderDataSet.m_strFilter = m_rsReaderDataSet.m_strFilter + "'";
	m_rsReaderDataSet.Requery();

	if (!m_rsReaderDataSet.IsEOF())
	{
		if (m_rsReaderDataSet.m_FLAG_BORROW == "Y")
		{
			mSqlStr = "SELECT * FROM BORROW WHERE READER_ID= '" + m_strReaderID;
			mSqlStr = mSqlStr + "'";

			if (!m_rsDataSet.Open(AFX_DB_USE_DEFAULT_TYPE,mSqlStr))
			{
				m_rsReaderDataSet.Close();
				AfxMessageBox("数据表打开错误!");
				return;

			}

			// Add some code to determine the num of book which this reader borrowed.
			m_bCanBorrow = TRUE;
			m_rsDataSet.Close();
		}
	}
	m_rsReaderDataSet.Close();

	if (!m_bCanBorrow)
	{
		AfxMessageBox("读者不能借书！");
		return;
	}

	mSqlStr = "SELECT * FROM BOOK WHERE BOOK_ID='" + m_strBookID;
	mSqlStr = mSqlStr + "'";

	if(!m_rsBookDataSet.Open(AFX_DB_USE_DEFAULT_TYPE, mSqlStr))
	{
		AfxMessageBox("数据表打开错误！");
		return ;
	}
	if (!m_rsBookDataSet.IsEOF())
	{
		if (m_rsBookDataSet.m_FLAG_BORROW == "Y")
		{
			m_bCanLendOut = TRUE;
		}
		else
		{
			AfxMessageBox("此书不外借！ ");
			m_rsBookDataSet.Close();
			return;
		}
	}
	else
	{
		AfxMessageBox("无此书！");
		m_rsBookDataSet.Close();
		return;
	}
	
	m_rsBookDataSet.Close();


    CString m_strUserID;
	m_strUserID = theApp.m_strUserName ;

	COleDateTime m_CurrentTime=COleDateTime::GetCurrentTime();
	CString strTime;
	int y=m_CurrentTime.GetYear();
	int m=m_CurrentTime.GetMonth();
	int d=m_CurrentTime.GetDay();
	strTime.Format("%d-%d-%d",y,m,d);
	mSqlStr = "INSERT INTO BORROW (READER_ID, BOOK_ID,BORROW_DATE, B_CLERK_ID) VALUES('";
	mSqlStr = mSqlStr + m_strReaderID;
	mSqlStr = mSqlStr + "','";
	mSqlStr = mSqlStr + m_strBookID;
	mSqlStr = mSqlStr + "','";
	mSqlStr = mSqlStr + strTime;
	mSqlStr = mSqlStr +"','";
	mSqlStr = mSqlStr + m_strUserID;
	mSqlStr = mSqlStr + "')";
	
	CDatabase mDB;
	if (!mDB.Open(_T("Library")))
	{
		AfxMessageBox("无法打开数据库！");
		return;
	}
	

	try
	{
		mDB.ExecuteSQL(mSqlStr);
	}

	catch(CDBException e)
	{
		AfxMessageBox("执行错！");
		return;
	}


	mDB.Close();
	AfxMessageBox("操作成功！");

}

void CBorrowDlg::OnCancel() 
{
	// TODO: Add your control notification handler code here
	CDialog::OnCancel();
}

BOOL CBorrowDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
