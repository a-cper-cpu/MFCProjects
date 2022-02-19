// test02Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "test02.h"
#include "test02Dlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTest02Dlg dialog

CTest02Dlg::CTest02Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(CTest02Dlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CTest02Dlg)
	m_editnumber1 = _T("");
	m_editnumber2 = _T("");
	m_editnumber3 = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTest02Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTest02Dlg)
	DDX_Control(pDX, IDC_BUTTONcheng, m_buttoncheng);
	DDX_Control(pDX, IDC_BUTTONchu, m_buttonchu);
	DDX_Control(pDX, IDC_BUTTONquyu, m_buttonquyu);
	DDX_Control(pDX, IDC_BUTTONjian, m_buttonjian);
	DDX_Control(pDX, IDC_BUTTONjia, m_buttonjia);
	DDX_Text(pDX, IDC_EDIT1, m_editnumber1);
	DDX_Text(pDX, IDC_EDIT2, m_editnumber2);
	DDX_Text(pDX, IDC_EDIT3, m_editnumber3);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CTest02Dlg, CDialog)
	//{{AFX_MSG_MAP(CTest02Dlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTONcheng, OnBUTTONcheng)
	ON_BN_CLICKED(IDC_BUTTONchu, OnBUTTONchu)
	ON_BN_CLICKED(IDC_BUTTONjia, OnBUTTONjia)
	ON_BN_CLICKED(IDC_BUTTONjian, OnBUTTONjian)
	ON_BN_CLICKED(IDC_BUTTONquyu, OnBUTTONquyu)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTest02Dlg message handlers

BOOL CTest02Dlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CTest02Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CTest02Dlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CTest02Dlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CTest02Dlg::OnBUTTONcheng() 
{
	// TODO: Add your control notification handler code here
	
		
	UpdateData(1);
	
//	m_editnumber3=atof(m_editnumber1)+atof(m_editnumber2);

	m_editnumber3.Format("%.2f",atof(m_editnumber1)*atof(m_editnumber2));



	UpdateData(0);
}

void CTest02Dlg::OnBUTTONchu() 
{
	// TODO: Add your control notification handler code here
	
		
	UpdateData(1);
	
//	m_editnumber3=atof(m_editnumber1)+atof(m_editnumber2);

	m_editnumber3.Format("%.2f",atof(m_editnumber1)/atof(m_editnumber2));



	UpdateData(0);
}

void CTest02Dlg::OnBUTTONjia() 
{
	
	UpdateData(1);
	
//	m_editnumber3=atof(m_editnumber1)+atof(m_editnumber2);

	m_editnumber3.Format("%.2f",atof(m_editnumber1)+atof(m_editnumber2));



	UpdateData(0);


}

void CTest02Dlg::OnBUTTONjian() 
{
	// TODO: Add your control notification handler code here

		
	UpdateData(1);
	
//	m_editnumber3=atof(m_editnumber1)+atof(m_editnumber2);

	m_editnumber3.Format("%.2f",atof(m_editnumber1)-atof(m_editnumber2));



	UpdateData(0);
	
}

void CTest02Dlg::OnBUTTONquyu() 
{
	// TODO: Add your control notification handler code here
	
		
	UpdateData(1);
	
//	m_editnumber3=atof(m_editnumber1)+atof(m_editnumber2);

	m_editnumber3.Format("%d",(int)atof(m_editnumber1)%(int)atof(m_editnumber2));



	UpdateData(0);

}
