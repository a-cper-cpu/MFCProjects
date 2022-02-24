// UGMSDlg.cpp : implementation file
//

#include "stdafx.h"
#include "UGMS.h"
#include "UGMSDlg.h"

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
// CUGMSDlg dialog

CUGMSDlg::CUGMSDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CUGMSDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CUGMSDlg)
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CUGMSDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CUGMSDlg)
	DDX_Control(pDX, IDC_OUTLOOKBAR, m_OutlookBar);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CUGMSDlg, CDialog)
	//{{AFX_MSG_MAP(CUGMSDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_NOTIFY(NM_CLICK, IDC_OUTLOOKBAR, OnClickOutlookbar)
	ON_NOTIFY(LVN_KEYDOWN, IDC_OUTLOOKBAR, OnKeydownOutlookbar)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CUGMSDlg message handlers

BOOL CUGMSDlg::OnInitDialog()
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
	UpdateOutlookBar();
	m_PageStu.Create(IDD_PAGE_STU,this);
	m_PageCou.Create(IDD_PAGE_COU,this);
	m_PageCho.Create(IDD_PAGE_CHO,this);
	m_PageStat.Create(IDD_PAGE_STAT,this);
	m_PageWelcome.Create(IDD_PAGE_WELCOME,this);
	ActivatePage(-1);
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CUGMSDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CUGMSDlg::OnPaint() 
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
HCURSOR CUGMSDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CUGMSDlg::OnClickOutlookbar(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	int nIndex = m_OutlookBar.GetNextItem(-1, LVNI_ALL | LVNI_SELECTED);     
    if(nIndex == -1)
        return;		
	ActivatePage(nIndex);
	
	*pResult = 0;
}

void CUGMSDlg::OnKeydownOutlookbar(NMHDR* pNMHDR, LRESULT* pResult) 
{
	LV_KEYDOWN* pLVKeyDow = (LV_KEYDOWN*)pNMHDR;
	// TODO: Add your control notification handler code here
	// get index of selected item
	int nIndex = m_OutlookBar.GetNextItem(-1, LVNI_ALL | LVNI_SELECTED); 
	if(nIndex == -1)
       return;

	if (pLVKeyDow->wVKey == VK_DOWN)
	{
		if (m_OutlookBar.GetItemCount()-1 > nIndex)
		{
			ActivatePage(nIndex+1);
		}
	}
	else
	if (pLVKeyDow->wVKey == VK_UP)
	{
		if (nIndex > 0)
		{
			ActivatePage(nIndex-1);
		}
	}
	else
	if (pLVKeyDow->wVKey == VK_NEXT)
	{
		ActivatePage(m_OutlookBar.GetItemCount()-1);
	}
	else
	if (pLVKeyDow->wVKey == VK_PRIOR)
	{
		ActivatePage(0);
	}
	
	*pResult = 0;
}

void CUGMSDlg::UpdateOutlookBar()
{
	m_ImageList.Create(32, 32, ILC_COLOR16|ILC_MASK,1, 4);
    HICON hIcon = ::LoadIcon (AfxGetResourceHandle(), MAKEINTRESOURCE(IDI_ICON1));
    m_ImageList.Add(hIcon);
    hIcon = ::LoadIcon (AfxGetResourceHandle(), MAKEINTRESOURCE(IDI_ICON2));
    m_ImageList.Add(hIcon);
    hIcon = ::LoadIcon (AfxGetResourceHandle(), MAKEINTRESOURCE(IDI_ICON3));
    m_ImageList.Add(hIcon);
    hIcon = ::LoadIcon (AfxGetResourceHandle(), MAKEINTRESOURCE(IDI_ICON4));
    m_ImageList.Add(hIcon);
	
	m_OutlookBar.SetImageList(&m_ImageList, LVSIL_NORMAL);
	CRect rc;
	m_OutlookBar.GetClientRect(rc);
	
	// set new icon spacing
	m_OutlookBar.SetIconSpacing(rc.Width(), 64);

	// change colors
	//m_OutlookBar.SetTextColor(RGB(255,255,255));
	//m_OutlookBar.SetTextBkColor(RGB(128,128,128));
	//m_OutlookBar.SetBkColor(RGB(128,128,128));		
	
	// insert items
	m_OutlookBar.InsertColumn(0, _T("OutlookBar"));
	m_OutlookBar.InsertItem(0, _T("学生信息"), 0);
	m_OutlookBar.InsertItem(1, _T("课程信息"), 1);
	m_OutlookBar.InsertItem(2, _T("选课信息"), 2);
	m_OutlookBar.InsertItem(3, _T("成绩信息"), 3);

}

void CUGMSDlg::ActivatePage(int nIndex)
{
	switch(nIndex)
	{
		case 0:
			m_PageStu.ShowWindow(SW_SHOW);
			m_PageCou.ShowWindow(SW_HIDE);
			m_PageCho.ShowWindow(SW_HIDE);
			m_PageStat.ShowWindow(SW_HIDE);
			m_PageWelcome.ShowWindow(SW_HIDE);

			break;
		case 1:
			m_PageStu.ShowWindow(SW_HIDE);
			m_PageCou.ShowWindow(SW_SHOW);
			m_PageCho.ShowWindow(SW_HIDE);
			m_PageStat.ShowWindow(SW_HIDE);
			m_PageWelcome.ShowWindow(SW_HIDE);

			break;
		case 2:
			m_PageStu.ShowWindow(SW_HIDE);
			m_PageCou.ShowWindow(SW_HIDE);
			m_PageCho.ShowWindow(SW_SHOW);
			m_PageStat.ShowWindow(SW_HIDE);
			m_PageWelcome.ShowWindow(SW_HIDE);

			break;
		case 3:
			m_PageStu.ShowWindow(SW_HIDE);
			m_PageCou.ShowWindow(SW_HIDE);
			m_PageCho.ShowWindow(SW_HIDE);
			m_PageStat.ShowWindow(SW_SHOW);
			m_PageStat.m_Ado.Refresh();
			m_PageWelcome.ShowWindow(SW_HIDE);
			break;
		default:
			m_PageStu.ShowWindow(SW_HIDE);
			m_PageCou.ShowWindow(SW_HIDE);
			m_PageCho.ShowWindow(SW_HIDE);
			m_PageStat.ShowWindow(SW_HIDE);
			m_PageWelcome.ShowWindow(SW_SHOW);
			break;
	}
	MoveChilds();
	UpdateData(false);

}

void CUGMSDlg::MoveChilds()
{
	// position property pages 
	CRect rcDlgs;
	
	// get dialog area rect
	GetDlgItem(IDC_DIALOG_AREA)->GetWindowRect(rcDlgs);
	
	ScreenToClient(rcDlgs);	
	m_PageStu.MoveWindow(rcDlgs);
	m_PageCou.MoveWindow(rcDlgs);
	m_PageCho.MoveWindow(rcDlgs);
	m_PageStat.MoveWindow(rcDlgs);
	m_PageWelcome.MoveWindow(rcDlgs);


}
