// Page1Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "YNDlg.h"
#include "Page1.h"
#include "Page1Dlg.h"
#include "xiugaiDlg.h"
#include "zhuyeDlg.h"
#include"liebiao.h"
#include<fstream.h>
int p=-1;
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
// CPage1Dlg dialog

CPage1Dlg::CPage1Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(CPage1Dlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CPage1Dlg)
	m_CODE = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CPage1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPage1Dlg)
	DDX_Control(pDX, IDOK, m_denglu);
	DDX_Control(pDX, IDC_EDIT1, m_code);
	DDX_Control(pDX, IDC_xiugaimima, m_mima);
	DDX_Text(pDX, IDC_EDIT1, m_CODE);
	DDV_MaxChars(pDX, m_CODE, 12);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CPage1Dlg, CDialog)
	//{{AFX_MSG_MAP(CPage1Dlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_xiugaimima, Onxiugai)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPage1Dlg message handlers

BOOL CPage1Dlg::OnInitDialog()
{
	CDialog::OnInitDialog();
    fstream f("code.dat",ios::in|ios::out);
	char a[12]="123456";
    strcpy( peo[0].CODE,a);
    f.seekp(0,ios::end);
    long posEnd1=f.tellp();
    f.seekp(0,ios::beg);
    long posEnd2=f.tellp();
    if(posEnd1==posEnd2)
    f<<peo[0].CODE<<endl;
    f.close();

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

void CPage1Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CPage1Dlg::OnPaint() 

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
 		CRect rect;
        CPaintDC dc(this);
        GetClientRect(rect);
        dc.FillSolidRect(rect,RGB(100,100,200)); 
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CPage1Dlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}



void CPage1Dlg::Onxiugai() 
{
	// TODO: Add your control notification handler code here
	CxiugaiDlg test;
    test.DoModal();	
}


void CPage1Dlg::OnOK() 
{
	// TODO: Add extra validation here
	UpdateData(TRUE);
	fstream fout("code.dat",ios::in|ios::out);
	if(!fout)
	{
		AfxMessageBox("不能打开文件！！");
	    return;
	}
    fout>>peo[0].CODE;
	fout.close();
	if(strlen(m_CODE)==0)
	{
		AfxMessageBox("密码不能为空，请重新输入！");
		m_code.SetWindowText("");
		return;
	}
	if(strcmp(peo[0].CODE,m_CODE)!=0) 
	{
		AfxMessageBox("输入密码错误，\n请重新输入！");
        m_code.SetWindowText("");
		return;
	}
	if(strcmp(peo[0].CODE,m_CODE)==0)
	{
		MessageBox("****************\n     Welcome      \n****************");
	    fstream fin("tang3.dat",ios::in);
	    if(!fin)
		{
             AfxMessageBox("不能打开文件！！");
	         return;
		}
        char s[200];
		while(!fin.eof()) 
		{   
			fin.getline(s,200);
			p++;
		}
	    CDialog::OnOK();
		CzhuyeDlg test;
	    test.DoModal();	
	}
}

void CPage1Dlg::OnCancel() 
{
	// TODO: Add extra cleanup here
	 CYNDlg test;
     test.DoModal();
   	 if(test.k==0)
		return;
	 if(test.k==1)
	 {
		CDialog::OnCancel();
	 }
}
