// DriverAwardDlg.cpp : implementation file
//

#include "stdafx.h"
#include "TMS.h"
#include "DriverAwardDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDriverAwardDlg dialog


CDriverAwardDlg::CDriverAwardDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CDriverAwardDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDriverAwardDlg)
	m_strContent = _T("");
	m_strMemo = _T("");
	//}}AFX_DATA_INIT
}


void CDriverAwardDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDriverAwardDlg)
	DDX_Control(pDX, IDC_COMBO_DRIVERNO, m_cbDriverNO);
	DDX_Control(pDX, IDC_COMBO_AWARDNO, m_cbAwardNO);
	DDX_Text(pDX, IDC_EDIT_CONTENT, m_strContent);
	DDX_Text(pDX, IDC_EDIT_MEMO, m_strMemo);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDriverAwardDlg, CDialog)
	//{{AFX_MSG_MAP(CDriverAwardDlg)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDriverAwardDlg message handlers
