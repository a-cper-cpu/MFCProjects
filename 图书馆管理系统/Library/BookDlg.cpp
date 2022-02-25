// BookDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Library.h"
#include "BookDlg.h"

#include "BookDataSet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CBookDlg dialog


CBookDlg::CBookDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CBookDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CBookDlg)
	m_strAuthor = _T("");
	m_strBookID = _T("");
	m_strBookIDQ = _T("");
	m_strBookName = _T("");
	m_strBookNameQ = _T("");
	m_strFlag = _T("");
	m_strPress = _T("");
	m_strPressDate = _T("");
	//}}AFX_DATA_INIT
}


void CBookDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CBookDlg)
	DDX_Text(pDX, IDC_AUTHOR, m_strAuthor);
	DDX_Text(pDX, IDC_BOOKID, m_strBookID);
	DDX_Text(pDX, IDC_BOOKID_Q, m_strBookIDQ);
	DDX_Text(pDX, IDC_BOOKNAME, m_strBookName);
	DDX_Text(pDX, IDC_BOOKNAME_Q, m_strBookNameQ);
	DDX_Text(pDX, IDC_FLAG_BORROW, m_strFlag);
	DDV_MaxChars(pDX, m_strFlag, 1);
	DDX_Text(pDX, IDC_PRESS, m_strPress);
	DDV_MaxChars(pDX, m_strPress, 20);
	DDX_Text(pDX, IDC_PRESSDATE, m_strPressDate);
	DDV_MaxChars(pDX, m_strPressDate, 10);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CBookDlg, CDialog)
	//{{AFX_MSG_MAP(CBookDlg)
	ON_BN_CLICKED(IDC_CANCEL_REC, OnCancelRec)
	ON_BN_CLICKED(IDC_DELETE, OnDelete)
	ON_BN_CLICKED(IDC_EDIT, OnEdit)
	ON_BN_CLICKED(IDC_ENQUERY, OnEnquery)
	ON_BN_CLICKED(IDC_EXIT, OnExit)
	ON_BN_CLICKED(IDC_FIRST, OnFirst)
	ON_BN_CLICKED(IDC_LAST, OnLast)
	ON_BN_CLICKED(IDC_NEW, OnNew)
	ON_BN_CLICKED(IDC_NEXT, OnNext)
	ON_BN_CLICKED(IDC_PRIOR, OnPrior)
	ON_BN_CLICKED(IDC_SAVE, OnSave)

		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBookDlg message handlers
void CBookDlg::OnCancelRec() 
{
	// TODO: Add your control notification handler code here
	m_bAdd = FALSE;
	m_bEdit = FALSE;
	DisplayRecord();
	SetButtonState();
	SetTextState();
	
}
void CBookDlg::OnDelete() 
{
	// TODO: Add your control notification handler code here
	m_rsDataSet.Delete();
	DisplayRecord();
	SetButtonState();	
}

void CBookDlg::OnEdit() 
{
	// TODO: Add your control notification handler code here
	m_bEdit = TRUE;
	SetButtonState();
	SetTextState();
	CWnd *pWnd;
	pWnd = GetDlgItem(IDC_BOOKNAME);
	pWnd->SetFocus();
	
}

void CBookDlg::OnEnquery() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	if (m_strBookIDQ.IsEmpty() && m_strBookNameQ.IsEmpty())
	{
		m_rsDataSet.m_strFilter = "";
		m_rsDataSet.Requery();
		DisplayRecord();
		SetButtonState();
		return;
	}
	BOOL mAll = FALSE;
	if (!m_strBookIDQ.IsEmpty())
	{
		m_rsDataSet.m_strFilter = "BOOK_ID='" + m_strBookIDQ ;
		m_rsDataSet.m_strFilter = m_rsDataSet.m_strFilter + "'";
		mAll = TRUE;
	}
	if (!m_strBookNameQ.IsEmpty())
	{
		if (mAll)
		{
			m_rsDataSet.m_strFilter = m_rsDataSet.m_strFilter + " AND BOOK_NAME='";
			m_rsDataSet.m_strFilter = m_rsDataSet.m_strFilter + m_strBookNameQ;
			m_rsDataSet.m_strFilter = m_rsDataSet.m_strFilter + "'";
		}
		else
		{
			m_rsDataSet.m_strFilter = "BOOK_NAME='"  + m_strBookNameQ;
			m_rsDataSet.m_strFilter = m_rsDataSet.m_strFilter + "'";
		}
			
	}
	m_rsDataSet.Requery();
	DisplayRecord();
	SetButtonState();

	
}

void CBookDlg::OnExit() 
{
	// TODO: Add your control notification handler code here
	CDialog::OnCancel();
	
}

void CBookDlg::OnFirst() 
{
	// TODO: Add your control notification handler code here
	if(!m_rsDataSet.IsBOF())
	{
		m_rsDataSet.MoveFirst();
		DisplayRecord();
		SetButtonState();
	}
	
}

void CBookDlg::OnLast() 
{
	// TODO: Add your control notification handler code here
	if(!m_rsDataSet.IsEOF())
	{
		m_rsDataSet.MoveLast();
		DisplayRecord();
		SetButtonState();
	}
	
}

void CBookDlg::OnNew() 
{
	// TODO: Add your control notification handler code here
	m_strBookID = "";
	m_strBookName = "";
	m_strAuthor = "";
	m_strPress = "";
	m_strFlag = "Y";
	
	UpdateData(FALSE);
	m_bEdit = TRUE;
	m_bAdd = TRUE;
	SetButtonState();
	SetTextState();
	CWnd *pWnd;
	pWnd = GetDlgItem(IDC_BOOKID);
	pWnd->SetFocus();
	
}

void CBookDlg::OnNext() 
{
	// TODO: Add your control notification handler code here
	if(!m_rsDataSet.IsEOF())
	{
		m_rsDataSet.MoveNext();
		DisplayRecord();
		SetButtonState();
	}
	
}

void CBookDlg::OnPrior() 
{
	// TODO: Add your control notification handler code here
	if(!m_rsDataSet.IsBOF())
	{
		m_rsDataSet.MovePrev();
		DisplayRecord();
		SetButtonState();
	}
	
}

void CBookDlg::OnSave() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	if (m_strBookID.IsEmpty() || m_strBookName.IsEmpty())
	{
		AfxMessageBox("请输入相应数据！");
		return;
	}
	if (m_bAdd)
	{
		m_rsDataSet.AddNew();

	}
	else
	{
		m_rsDataSet.Edit();
	}
	m_rsDataSet.m_AUTHOR = m_strAuthor;
	m_rsDataSet.m_BOOK_NAME = m_strBookName;
	m_rsDataSet.m_BOOK_ID = m_strBookID;
	m_rsDataSet.m_PRESS = m_strPress;
	m_rsDataSet.m_FLAG_BORROW = m_strFlag;
	m_rsDataSet.m_PRESS_DATE=m_strPressDate;

	m_rsDataSet.Update();
	m_rsDataSet.Requery();
	m_bAdd = FALSE;
	m_bEdit = FALSE;
	DisplayRecord();
	SetButtonState();
	SetTextState();
	
}

BOOL CBookDlg::DisplayRecord()
{
	if (m_rsDataSet.IsEOF() && m_rsDataSet.IsBOF())	
	{
		m_strBookID = "";
		m_strBookName = "";
		m_strPress = "";
		m_strAuthor = "";
		m_strFlag = "";
		m_strPressDate="";
	}
	else
	{
		if (m_rsDataSet.IsBOF())
		{
			m_rsDataSet.MoveNext();
		}
		else
		{	
			if (m_rsDataSet.IsEOF())
			{		
				m_rsDataSet.MovePrev();
			}
		}
		m_strBookID = m_rsDataSet.m_BOOK_ID;
		m_strBookName = m_rsDataSet.m_BOOK_NAME;
		m_strPress = m_rsDataSet.m_PRESS;
		m_strAuthor = m_rsDataSet.m_AUTHOR ;
		m_strFlag = m_rsDataSet.m_FLAG_BORROW ;
		m_strPressDate=m_rsDataSet.m_PRESS_DATE;
	}
	UpdateData(FALSE);
	return TRUE;

}

BOOL CBookDlg::SetTextState()
{
	CWnd *pWnd;

	if (m_bEdit)
	{
		pWnd = GetDlgItem(IDC_BOOKNAME);
		pWnd->EnableWindow(TRUE);
		pWnd = GetDlgItem(IDC_BOOKID);
		if (m_bAdd)
			pWnd->EnableWindow(TRUE);
		else
			pWnd->EnableWindow(FALSE);
		pWnd = GetDlgItem(IDC_AUTHOR);
		pWnd->EnableWindow(TRUE);
		pWnd = GetDlgItem(IDC_PRESS);
		pWnd->EnableWindow(TRUE);
		pWnd = GetDlgItem(IDC_PRESSDATE);
		pWnd->EnableWindow(TRUE);
		pWnd = GetDlgItem(IDC_FLAG_BORROW);
		pWnd->EnableWindow(TRUE);

	}
	else
	{
		pWnd = GetDlgItem(IDC_BOOKNAME);
		pWnd->EnableWindow(FALSE);
		pWnd = GetDlgItem(IDC_BOOKID);
		pWnd->EnableWindow(FALSE);
		pWnd = GetDlgItem(IDC_AUTHOR);
		pWnd->EnableWindow(FALSE);
		pWnd = GetDlgItem(IDC_PRESS);
		pWnd->EnableWindow(FALSE);
		pWnd = GetDlgItem(IDC_PRESSDATE);
		pWnd->EnableWindow(FALSE);
		pWnd = GetDlgItem(IDC_FLAG_BORROW);
		pWnd->EnableWindow(FALSE);
	}
	pWnd = GetDlgItem(IDC_BOOKNAME_Q);
	pWnd->EnableWindow(TRUE);
	pWnd = GetDlgItem(IDC_BOOKID_Q);
	pWnd->EnableWindow(TRUE);
	return TRUE;

}

BOOL CBookDlg::SetButtonState()
{
	CWnd *pWnd;

	if(!m_rsDataSet.IsOpen())
	{
		pWnd = GetDlgItem(IDC_FIRST);
		pWnd->EnableWindow(FALSE);
		pWnd = GetDlgItem(IDC_NEXT);
		pWnd->EnableWindow(FALSE);
		pWnd = GetDlgItem(IDC_PRIOR);
		pWnd->EnableWindow(FALSE);
		pWnd = GetDlgItem(IDC_LAST);
		pWnd->EnableWindow(FALSE);
		
		pWnd = GetDlgItem(IDC_NEW);
		pWnd->EnableWindow(FALSE);
		pWnd = GetDlgItem(IDC_EDIT);
		pWnd->EnableWindow(FALSE);
		pWnd = GetDlgItem(IDC_ENQUERY);
		pWnd->EnableWindow(FALSE);
		pWnd = GetDlgItem(IDC_DELETE);
		pWnd->EnableWindow(FALSE);
		pWnd = GetDlgItem(IDC_SAVE);
		pWnd->EnableWindow(FALSE);
		pWnd = GetDlgItem(IDC_CANCEL_REC);
		pWnd->EnableWindow(FALSE);
		

		return TRUE;
	}


	if (m_bEdit)
	{
		pWnd = GetDlgItem(IDC_FIRST);
		pWnd->EnableWindow(FALSE);
		pWnd = GetDlgItem(IDC_NEXT);
		pWnd->EnableWindow(FALSE);
		pWnd = GetDlgItem(IDC_PRIOR);
		pWnd->EnableWindow(FALSE);
		pWnd = GetDlgItem(IDC_LAST);
		pWnd->EnableWindow(FALSE);

		pWnd = GetDlgItem(IDC_NEW);
		pWnd->EnableWindow(FALSE);
		pWnd = GetDlgItem(IDC_EDIT);
		pWnd->EnableWindow(FALSE);
		pWnd = GetDlgItem(IDC_ENQUERY);
		pWnd->EnableWindow(FALSE);
		pWnd = GetDlgItem(IDC_DELETE);
		pWnd->EnableWindow(FALSE);
		pWnd = GetDlgItem(IDC_SAVE);
		pWnd->EnableWindow(TRUE);
		pWnd = GetDlgItem(IDC_CANCEL_REC);
		pWnd->EnableWindow(TRUE);

		return TRUE;

	}


	if (m_rsDataSet.IsBOF())
	{
		pWnd = GetDlgItem(IDC_FIRST);
		pWnd->EnableWindow(FALSE);
		pWnd = GetDlgItem(IDC_PRIOR);
		pWnd->EnableWindow(FALSE);
	}
	else
	{
		pWnd = GetDlgItem(IDC_FIRST);
		pWnd->EnableWindow(TRUE);
		pWnd = GetDlgItem(IDC_PRIOR);
		pWnd->EnableWindow(TRUE);
	}

	if (m_rsDataSet.IsEOF())
	{
		pWnd = GetDlgItem(IDC_NEXT);
		pWnd->EnableWindow(FALSE);
		pWnd = GetDlgItem(IDC_LAST);
		pWnd->EnableWindow(FALSE);
	}
	else
	{
		pWnd = GetDlgItem(IDC_NEXT);
		pWnd->EnableWindow(TRUE);
		pWnd = GetDlgItem(IDC_LAST);
		pWnd->EnableWindow(TRUE);

	}
	if (m_rsDataSet.IsBOF() && m_rsDataSet.IsEOF())
	{
		pWnd = GetDlgItem(IDC_EDIT);
		pWnd->EnableWindow(FALSE);
		pWnd = GetDlgItem(IDC_DELETE);
		pWnd->EnableWindow(FALSE);

	}
	else
	{
		pWnd = GetDlgItem(IDC_EDIT);
		pWnd->EnableWindow(TRUE);
		pWnd = GetDlgItem(IDC_DELETE);
		pWnd->EnableWindow(TRUE);

	}

	pWnd = GetDlgItem(IDC_NEW);
	pWnd->EnableWindow(TRUE);
	pWnd = GetDlgItem(IDC_ENQUERY);
	pWnd->EnableWindow(TRUE);
	pWnd = GetDlgItem(IDC_SAVE);
	pWnd->EnableWindow(FALSE);
	pWnd = GetDlgItem(IDC_CANCEL_REC);
	pWnd->EnableWindow(FALSE);

	return TRUE;

}

BOOL CBookDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	m_bAdd = FALSE;
	m_bEdit = FALSE;

	if (!m_rsDataSet.Open(AFX_DB_USE_DEFAULT_TYPE))
		AfxMessageBox("数据打开失败！");

	DisplayRecord();
	SetButtonState();
	SetTextState();
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

