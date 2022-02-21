// chatDlg.cpp : implementation file
//

#include "stdafx.h"
#include "chat.h"
#include "chatDlg.h"

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
// CChatDlg dialog

CChatDlg::CChatDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CChatDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CChatDlg)
	m_strMessage = _T("");
	m_strName = _T("");
	m_port =5000;
	m_strShowMessage = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CChatDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CChatDlg)
	DDX_Text(pDX, IDC_MESSAGE, m_strMessage);
	DDX_Text(pDX, IDC_NAME, m_strName);
	DDX_Text(pDX, IDC_PORT, m_port);
	DDX_Text(pDX, IDC_SHOWMESSAGE, m_strShowMessage);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CChatDlg, CDialog)
	//{{AFX_MSG_MAP(CChatDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_CONNECT, OnConnect)
	ON_BN_CLICKED(IDC_SETSERVER, OnSetserver)
	ON_BN_CLICKED(IDC_SEND, OnSend)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CChatDlg message handlers

BOOL CChatDlg::OnInitDialog()
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
	//自行添加的程序代码,目的是在初始化对话框的时候就自动显示出本地的ip地址
	if(AfxSocketInit(NULL)==0)
	{
		AfxMessageBox("CSocket 初始化失败!");
	}
	BYTE f0,f1,f2,f3;
	CString name;
	CClientSocket::GetLocalHostName(name);
	CClientSocket::GetIpAddress(name,f0,f1,f2,f3);
	((CIPAddressCtrl *)(GetDlgItem(IDC_IPADDRESS)))->SetAddress(f0,f1,f2,f3);
	m_bInit=false;
	m_bClient=false;
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CChatDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CChatDlg::OnPaint() 
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
HCURSOR CChatDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}
//连接服务器的消息相应函数
void CChatDlg::OnConnect() 
{
	// TODO: Add your control notification handler code here
	if(!m_bInit)
	{
		BYTE f0,f1,f2,f3;
		CString name;
		((CIPAddressCtrl *)(GetDlgItem(IDC_IPADDRESS)))->GetAddress(f0,f1,f2,f3);
		CString ip;
		ip.Format("%d.%d.%d.%d",f0,f1,f2,f3);
		m_bClient=true;
		m_clientsocket.Create();
		if(m_clientsocket.Connect(ip,GetDlgItemInt(IDC_PORT)))
		{
			m_clientsocket.Init(this);
			SetDlgItemText(IDC_SHOWMESSAGE,"客户端连接成功!");
			m_bInit=true;
		}
		else
		{
			m_clientsocket.Close();
			AfxMessageBox("客户端连接失败!");
			m_bInit=false;
		}
	}	
}
//建立服务器的消息相应函数
void CChatDlg::OnSetserver() 
{
	// TODO: Add your control notification handler code here
	if(!m_bInit)
	{
		m_bClient=false;
		m_bInit=true;
		if(m_pListenSocket.Init(GetDlgItemInt(IDC_PORT),this)==FALSE)
		{
			m_bInit=false;
			return;
		}
	}
}
//发送消息的按钮的消息相应函数
void CChatDlg::OnSend() 
{
	// TODO: Add your control notification handler code here
	if(!m_bInit)
	{
		AfxMessageBox("没有和服务器建立连接!");
		return;
	}
	CString in;
	CPackMessg msg;
	GetDlgItemText(IDC_MESSAGE,in);
	GetDlgItemText(IDC_NAME,m_strName);
	if(in.GetLength()<1)
	{
		return;
	}
		in.TrimRight(" ");
		SetDlgItemText(IDC_MESSAGE,""); //清除消息框中的输入

		if(in.GetLength()>2) 
		{
			m_sMsgList+=m_strName+"说:";
			m_sMsgList+=in+"\r\n";
			SetDlgItemText(IDC_SHOWMESSAGE,m_sMsgList);
			int m_iLineCurrentPos=((CEdit *)(GetDlgItem(IDC_SHOWMESSAGE)))->GetLineCount();
			((CEdit *)(GetDlgItem(IDC_SHOWMESSAGE)))->LineScroll(m_iLineCurrentPos);
			
			msg.m_strText=m_strName+"说:"+in;
			if(!m_bClient)
			{
				POSITION pos;
				for(pos=m_connectionList.GetHeadPosition();pos!=NULL;)
				{
					CClientSocket * t= (CClientSocket *)m_connectionList.GetNext(pos);
					t->SendMessage(&msg);
				}
			}
			else
			{
				m_clientsocket.SendMessage(&msg);
			}
		}
	
}
void CChatDlg::ProcessPendingAccept()
{
	CClientSocket* pSocket = new CClientSocket();
	
	if (m_pListenSocket.Accept(*pSocket))
	{
		CPackMessg msg;
		msg.m_strText="一个游客进入聊天室了";
	//	m_strShowMessage+="一个游客进入聊天室了\n";
		SetDlgItemText(IDC_SHOWMESSAGE,"一个游客进入聊天室了\n");

		POSITION pos;
		for(pos=m_connectionList.GetHeadPosition();pos!=NULL;)
		{
			CClientSocket * t= (CClientSocket *)m_connectionList.GetNext(pos);
			t->SendMessage(&msg);
		}
		pSocket->Init(this);
		m_connectionList.AddTail(pSocket);
	}
	else
		delete pSocket;
}

void CChatDlg::ClearContent()
{
	if(m_bClient)
	{
		m_clientsocket.Close();
	}
	else
	{
		m_pListenSocket.Close();
		m_connectionList.RemoveAll();
	}
	m_bInit=false;
	m_sMsgList="";
	SetDlgItemText(IDC_MESSAGE,"");
	SetDlgItemText(IDC_SHOWMESSAGE,"");
}
void CChatDlg::OnClearconnection() 
{
	ClearContent();
}

void CChatDlg::CloseSessionSocket()
{
	if(!m_bClient)
	{
		for(POSITION pos=m_connectionList.GetHeadPosition();pos!=NULL;)
		{
			POSITION t_pos=pos;
			CClientSocket * t = (CClientSocket*)m_connectionList.GetNext(pos);
			if(t->m_bClose==true)
			{
				m_connectionList.RemoveAt(t_pos);
			}
		}
	}
}
