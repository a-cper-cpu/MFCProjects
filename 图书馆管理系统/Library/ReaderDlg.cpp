// ReaderDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Library.h"
#include "ReaderDlg.h"
#include "ReaderDataSet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CReaderDlg dialog


CReaderDlg::CReaderDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CReaderDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CReaderDlg)
	m_strReaderIDQ = _T("");
	m_strReaderID = _T("");
	m_strReaderName = _T("");
	m_strReaderNameQ = _T("");
	m_strIDCard = _T("");
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CReaderDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CReaderDlg)
	DDX_Text(pDX, IDC_READERID_Q, m_strReaderIDQ);
	DDV_MaxChars(pDX, m_strReaderIDQ, 8);
	DDX_Text(pDX, IDC_READERID, m_strReaderID);
	DDV_MaxChars(pDX, m_strReaderID, 8);
	DDX_Text(pDX, IDC_READERNAME, m_strReaderName);
	DDV_MaxChars(pDX, m_strReaderName, 8);
	DDX_Text(pDX, IDC_READERNAME_Q, m_strReaderNameQ);
	DDV_MaxChars(pDX, m_strReaderNameQ, 8);
	DDX_Text(pDX, IDC_IDCARD, m_strIDCard);
	DDV_MaxChars(pDX, m_strIDCard, 18);
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CReaderDlg, CDialog)
	//{{AFX_MSG_MAP(CReaderDlg)
	ON_BN_CLICKED(IDC_EXIT, OnExit)
	ON_BN_CLICKED(IDC_FIRST, OnFirst)
	ON_BN_CLICKED(IDC_LAST, OnLast)
	ON_BN_CLICKED(IDC_NEW, OnNew)
	ON_BN_CLICKED(IDC_NEXT, OnNext)
	ON_BN_CLICKED(IDC_PRIOR, OnPrior)
	ON_BN_CLICKED(IDC_SAVE, OnSave)
	ON_BN_CLICKED(IDC_CANCEL_REC, OnCancelRec)
	ON_BN_CLICKED(IDC_DELETE, OnDelete)
	ON_BN_CLICKED(IDC_EDIT, OnEdit)
	ON_BN_CLICKED(IDC_ENQUERY, OnEnquery)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CReaderDlg message handlers
void CReaderDlg::OnExit() 
{
	// TODO: Add your control notification handler code here
	CDialog::OnOK();
}

void CReaderDlg::OnFirst() 
{
	// TODO: Add your control notification handler code here
	if(!m_rsDataSet.IsBOF())
	{
		m_rsDataSet.MoveFirst();
		DisplayRecord();
		SetButtonState();
	}
}

void CReaderDlg::OnLast() 
{
	// TODO: Add your control notification handler code here
	if(!m_rsDataSet.IsEOF())
	{
		m_rsDataSet.MoveLast();
		DisplayRecord();
		SetButtonState();
	}
	
}

void CReaderDlg::OnNew() 
{
	// TODO: Add your control notification handler code here
	m_strReaderID = "";
	m_strReaderName = "";
	m_strIDCard = "";
	UpdateData(FALSE);
	m_bEdit = TRUE;
	m_bAdd = TRUE;
	SetButtonState();
	SetTextState();
	CWnd *pWnd;
	pWnd = GetDlgItem(IDC_READERID);
	pWnd->SetFocus();

}

void CReaderDlg::OnNext() 
{
	// TODO: Add your control notification handler code here
	if(!m_rsDataSet.IsEOF())
	{
		m_rsDataSet.MoveNext();
		DisplayRecord();
		SetButtonState();
	}
	
}

void CReaderDlg::OnPrior() 
{
	// TODO: Add your control notification handler code here
	if(!m_rsDataSet.IsBOF())
	{
		m_rsDataSet.MovePrev();
		DisplayRecord();
		SetButtonState();
	}
	
}
void CReaderDlg::OnSave() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	if (m_strIDCard.IsEmpty() || m_strReaderName.IsEmpty() || m_strReaderID.IsEmpty())
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
	m_rsDataSet.m_IDCARD = m_strIDCard;
	m_rsDataSet.m_NAME = m_strReaderName;
	m_rsDataSet.m_READER_ID = m_strReaderID;

//	m_rsDataSet.m_FLAG_BORROW  = "Y";
	m_rsDataSet.Update();
	m_rsDataSet.Requery();
	m_bAdd = FALSE;
	m_bEdit = FALSE;
	DisplayRecord();
	SetButtonState();
	SetTextState();
}

void CReaderDlg::OnCancelRec() 
{
	// TODO: Add your control notification handler code here
	m_bAdd = FALSE;
	m_bEdit = FALSE;
	DisplayRecord();
	SetButtonState();

	SetTextState();
	
}

void CReaderDlg::OnDelete() 
{
	// TODO: Add your control notification handler code here
	m_rsDataSet.Delete();
	DisplayRecord();
	SetButtonState();
}

void CReaderDlg::OnEdit() 
{
	// TODO: Add your control notification handler code here
	m_bEdit = TRUE;
	SetButtonState();
	SetTextState();
	CWnd *pWnd;
	pWnd = GetDlgItem(IDC_READERNAME);
	pWnd->SetFocus();
}

void CReaderDlg::OnEnquery() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	if (m_strReaderIDQ.IsEmpty() && m_strReaderNameQ.IsEmpty())
	{
		m_rsDataSet.m_strFilter = "";
		m_rsDataSet.Requery();
		DisplayRecord();
		SetButtonState();
		return;
	}
	BOOL mAll = FALSE;
	if (!m_strReaderIDQ.IsEmpty())
	{
		m_rsDataSet.m_strFilter = "READER_ID='" + m_strReaderIDQ ;
		m_rsDataSet.m_strFilter = m_rsDataSet.m_strFilter + "'";
		mAll = TRUE;
	}
	if (!m_strReaderNameQ.IsEmpty())
	{
		if (mAll)
		{
			m_rsDataSet.m_strFilter = m_rsDataSet.m_strFilter + " AND NAME='";
			m_rsDataSet.m_strFilter = m_rsDataSet.m_strFilter + m_strReaderNameQ;
			m_rsDataSet.m_strFilter = m_rsDataSet.m_strFilter + "'";
		}
		else
		{
			m_rsDataSet.m_strFilter = "NAME='"  + m_strReaderNameQ;
			m_rsDataSet.m_strFilter = m_rsDataSet.m_strFilter + "'";
		}
			
	}
	m_rsDataSet.Requery();
	DisplayRecord();
	SetButtonState();

}

BOOL CReaderDlg::DisplayRecord()
{	
	if (m_rsDataSet.IsEOF() && m_rsDataSet.IsBOF())	
	{
		m_strReaderID = "";
		m_strReaderName = "";
		m_strIDCard = "";
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
		m_strReaderID = m_rsDataSet.m_READER_ID;
		m_strReaderName = m_rsDataSet.m_NAME;
		m_strIDCard = m_rsDataSet.m_IDCARD;
	}
	UpdateData(FALSE);
	return TRUE;
}

BOOL CReaderDlg::SetButtonState()
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

BOOL CReaderDlg::OnInitDialog() 
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

BOOL CReaderDlg::SetTextState()
{
	CWnd *pWnd;

	if (m_bEdit)
	{
		pWnd = GetDlgItem(IDC_READERNAME);
		pWnd->EnableWindow(TRUE);
		pWnd = GetDlgItem(IDC_READERID);
		if (m_bAdd)
			pWnd->EnableWindow(TRUE);
		else
			pWnd->EnableWindow(FALSE);
		pWnd = GetDlgItem(IDC_IDCARD);
		pWnd->EnableWindow(TRUE);

	}
	else
	{
		pWnd = GetDlgItem(IDC_READERNAME);
		pWnd->EnableWindow(FALSE);
		pWnd = GetDlgItem(IDC_READERID);
		pWnd->EnableWindow(FALSE);
		pWnd = GetDlgItem(IDC_IDCARD);
		pWnd->EnableWindow(FALSE);

	}
	pWnd = GetDlgItem(IDC_READERNAME_Q);
	pWnd->EnableWindow(TRUE);
	pWnd = GetDlgItem(IDC_READERID_Q);
	pWnd->EnableWindow(TRUE);
	return TRUE;

}
