// LawDlg.cpp : implementation file
//

#include "stdafx.h"
#include "TMS.h"
#include "LawDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CLawDlg dialog


CLawDlg::CLawDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CLawDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CLawDlg)
	m_iIsBook = -1;
	m_strDepartment = _T("");
	m_strMoney = _T("");
	m_strName = _T("");
	m_strNO = _T("");
	m_strPoint = _T("");
	//}}AFX_DATA_INIT
}


void CLawDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CLawDlg)
	DDX_CBIndex(pDX, IDC_COMBO_ISBOOK, m_iIsBook);
	DDX_Text(pDX, IDC_EDIT_DEPARTMENT, m_strDepartment);
	DDX_Text(pDX, IDC_EDIT_MONEY, m_strMoney);
	DDX_Text(pDX, IDC_EDIT_NAME, m_strName);
	DDX_Text(pDX, IDC_EDIT_NO, m_strNO);
	DDX_Text(pDX, IDC_EDIT_POINT, m_strPoint);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CLawDlg, CDialog)
	//{{AFX_MSG_MAP(CLawDlg)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLawDlg message handlers
