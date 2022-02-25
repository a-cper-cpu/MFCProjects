// DriverLawDlg.cpp : implementation file
//

#include "stdafx.h"
#include "TMS.h"
#include "DriverLawDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDriverLawDlg dialog


CDriverLawDlg::CDriverLawDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CDriverLawDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDriverLawDlg)
	m_iTreatState = -1;
	m_tmDate = 0;
	m_strAddress = _T("");
	m_strMemo = _T("");
	//}}AFX_DATA_INIT
}


void CDriverLawDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDriverLawDlg)
	DDX_Control(pDX, IDC_COMBO_LAWNO, m_cbLawNO);
	DDX_Control(pDX, IDC_COMBO_DRIVERNO, m_cbDriverNO);
	DDX_CBIndex(pDX, IDC_COMBO_TREATSTATE, m_iTreatState);
	DDX_DateTimeCtrl(pDX, IDC_DATE, m_tmDate);
	DDX_Text(pDX, IDC_EDIT_ADDRESS, m_strAddress);
	DDX_Text(pDX, IDC_EDIT_MEMO, m_strMemo);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDriverLawDlg, CDialog)
	//{{AFX_MSG_MAP(CDriverLawDlg)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDriverLawDlg message handlers
