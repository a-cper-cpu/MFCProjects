// CarFeeDlg.cpp : implementation file
//

#include "stdafx.h"
#include "TMS.h"
#include "CarFeeDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCarFeeDlg dialog


CCarFeeDlg::CCarFeeDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CCarFeeDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CCarFeeDlg)
	m_tmBegin = 0;
	m_tmEnd = 0;
	m_strFeeName = _T("");
	//}}AFX_DATA_INIT
}


void CCarFeeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCarFeeDlg)
	DDX_Control(pDX, IDC_COMBO_FEENO, m_cbFeeNO);
	DDX_Control(pDX, IDC_COMBO_CARNO, m_cbCarNO);
	DDX_DateTimeCtrl(pDX, IDC_DATE_BEGIN, m_tmBegin);
	DDX_DateTimeCtrl(pDX, IDC_DATE_END, m_tmEnd);
	DDX_Text(pDX, IDC_EDIT_FEENAME, m_strFeeName);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CCarFeeDlg, CDialog)
	//{{AFX_MSG_MAP(CCarFeeDlg)
	ON_WM_CANCELMODE()
	ON_BN_CLICKED(IDC_BUTTON_OK, OnButtonOk)
	ON_BN_CLICKED(IDC_BUTTON_CANCEL, OnButtonCancel)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCarFeeDlg message handlers

void CCarFeeDlg::SetStyle()
{

}

void CCarFeeDlg::SetTitle()
{

}

BOOL CCarFeeDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CCarFeeDlg::OnCancelMode() 
{
	CDialog::OnCancelMode();
	
	// TODO: Add your message handler code here
	
}

void CCarFeeDlg::OnButtonOk() 
{
	// TODO: Add your control notification handler code here
	
}

void CCarFeeDlg::OnButtonCancel() 
{
	// TODO: Add your control notification handler code here
	
}

void CCarFeeDlg::ModifyCarFee()
{

}

void CCarFeeDlg::GetCBData()
{

}

void CCarFeeDlg::AddCarFee()
{

}

void CCarFeeDlg::DelCarFee()
{

}

void CCarFeeDlg::FillData()
{

}

void CCarFeeDlg::ClearData()
{

}
