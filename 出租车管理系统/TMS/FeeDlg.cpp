// FeeDlg.cpp : implementation file
//

#include "stdafx.h"
#include "TMS.h"
#include "FeeDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CFeeDlg dialog


CFeeDlg::CFeeDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CFeeDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CFeeDlg)
	m_strDepartment = _T("");
	m_strMoney = _T("");
	m_strName = _T("");
	m_strNO = _T("");
	//}}AFX_DATA_INIT
}


void CFeeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CFeeDlg)
	DDX_Text(pDX, IDC_EDIT_DEPARTMENT, m_strDepartment);
	DDX_Text(pDX, IDC_EDIT_MONEY, m_strMoney);
	DDX_Text(pDX, IDC_EDIT_NAME, m_strName);
	DDX_Text(pDX, IDC_EDIT_NO, m_strNO);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CFeeDlg, CDialog)
	//{{AFX_MSG_MAP(CFeeDlg)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFeeDlg message handlers
