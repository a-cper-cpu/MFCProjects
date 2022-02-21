// ClientSocket.cpp : implementation file
//

#include "stdafx.h"
#include "chat.h"
#include "ClientSocket.h"
#include "chatDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CClientSocket

CClientSocket::CClientSocket()
{
	m_aSessionIn=NULL;
	m_aSessionOut=NULL;
	m_sfSocketFile=NULL;
	m_bInit=false;
	m_bClose=false;
}

CClientSocket::~CClientSocket()
{
	if(m_aSessionIn)
		delete m_aSessionIn;
	if(m_aSessionOut)
		delete m_aSessionOut;
	if(m_sfSocketFile)
		delete m_sfSocketFile;
}


// Do not edit the following lines, which are needed by ClassWizard.
#if 0
BEGIN_MESSAGE_MAP(CClientSocket, CSocket)
	//{{AFX_MSG_MAP(CClientSocket)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()
#endif	// 0

/////////////////////////////////////////////////////////////////////////////
// CClientSocket member functions

void CClientSocket::OnReceive(int nErrorCode) 
{
	// TODO: Add your specialized code here and/or call the base class
	
	CSocket::OnReceive(nErrorCode);
	do
	{
		CPackMessg temp;
		temp.Serialize(*m_aSessionIn);
		m_dlg->m_sMsgList+=temp.m_strText+"\r\n";
		m_dlg->SetDlgItemText(IDC_SHOWMESSAGE,m_dlg->m_sMsgList);
		int linenum=((CEdit *)(m_dlg->GetDlgItem(IDC_SHOWMESSAGE)))->GetLineCount();
		((CEdit *)(m_dlg->GetDlgItem(IDC_SHOWMESSAGE)))->LineScroll(linenum);
		if(!m_dlg->m_bClient)
		{
			for(POSITION pos=m_dlg->m_connectionList.GetHeadPosition();pos!=NULL;)
			{
				CClientSocket * t = (CClientSocket*)m_dlg->m_connectionList.GetNext(pos);
				if(t->m_hSocket!=this->m_hSocket)
				{
					t->SendMessage(&temp);
				}
			}
		}
	}
	while (!m_aSessionIn->IsBufferEmpty());
}

void CClientSocket::OnClose(int nErrorCode) 
{
	// TODO: Add your specialized code here and/or call the base class
	
	CSocket::OnClose(nErrorCode);
	
	m_bClose=true;
	CloseSocket();
	m_dlg->CloseSessionSocket();	
	CSocket::OnClose(nErrorCode);
}
void CClientSocket::Init(CChatDlg * dlg)
{
	m_sfSocketFile= new CSocketFile(this);
	m_aSessionIn=new CArchive(m_sfSocketFile,CArchive::load);
	m_aSessionOut=new CArchive(m_sfSocketFile,CArchive::store);
	m_bClose=false;
	this->m_dlg=dlg;
}
BOOL CClientSocket::SendMessage(CPackMessg * msg)
{
	if (m_aSessionOut != NULL)
	{
		msg->Serialize(*m_aSessionOut);
		m_aSessionOut->Flush();
		return TRUE;
	}
	else
	{
		//�Է��ر�������
		m_bClose=true;
		CloseSocket();
		m_dlg->CloseSessionSocket();
		return FALSE;
	}
}
void CClientSocket::CloseSocket()
{
	if(m_aSessionIn)
	{
		delete m_aSessionIn;
		m_aSessionIn=NULL;
	}
	if(m_aSessionOut)
	{
		delete m_aSessionOut;
		m_aSessionOut=NULL;
	}
	if(m_sfSocketFile)
	{
		delete m_aSessionOut;
		m_sfSocketFile=NULL;
	}
	Close();
	m_bInit=false;
	m_bClose=true;
}
int CClientSocket::GetLocalHostName(CString &sHostName)	//��ñ��ؼ��������
{
	char szHostName[256];
	int nRetCode;
	nRetCode=gethostname(szHostName,sizeof(szHostName));
	if(nRetCode!=0)
	{
		//��������
		sHostName=_T("û��ȡ��");
		return GetLastError();
	}
	sHostName=szHostName;
	return 0;
}

int CClientSocket::GetIpAddress(const CString &sHostName, CString &sIpAddress)//��ñ���IP
{
	struct hostent FAR * lpHostEnt=gethostbyname(sHostName);
	if(lpHostEnt==NULL)
	{
		//��������
		sIpAddress=_T("");
		return GetLastError();
	}
	//��ȡIP
	LPSTR lpAddr=lpHostEnt->h_addr_list[0];
	if(lpAddr)
	{
		struct in_addr inAddr;
		memmove(&inAddr,lpAddr,4);
		//ת��Ϊ��׼��ʽ
		sIpAddress=inet_ntoa(inAddr);
		if(sIpAddress.IsEmpty())
			sIpAddress=_T("û��ȡ��");
	}
	return 0;
}
int CClientSocket::GetIpAddress(const CString &sHostName, BYTE &f0,BYTE &f1,BYTE &f2,BYTE &f3)//��ñ���IP
{
	struct hostent FAR * lpHostEnt=gethostbyname(sHostName);
	if(lpHostEnt==NULL)
	{
		//��������
		f0=f1=f2=f3=0;
		return GetLastError();
	}
	//��ȡIP
	LPSTR lpAddr=lpHostEnt->h_addr_list[0];
	if(lpAddr)
	{
		struct in_addr inAddr;
		memmove(&inAddr,lpAddr,4);
		f0=inAddr.S_un.S_un_b.s_b1;
		f1=inAddr.S_un.S_un_b.s_b2;
		f2=inAddr.S_un.S_un_b.s_b3;
		f3=inAddr.S_un.S_un_b.s_b4;
	}
	return 0;
}

CString CClientSocket::ErrorReason(int tag)
{
	CString result;
	switch(tag)
	{
	case WSANOTINITIALISED:
		result="A successful AfxSocketInit must occur before using this API.";
		break;
	case WSAENETDOWN:
		result="the network subsystem failed";
		break;
	case WSAEADDRINUSE:
		result="The specified address is already in use";
		break;
	case WSAEINPROGRESS:
		result="A blocking Windows Sockets call is in progress";
		break;
	case WSAEADDRNOTAVAIL:
		result="The specified address is not available from the local machine";
		break;
	case WSAEAFNOSUPPORT:
		result="Addresses in the specified family cannot be used with this socket";
		break;
	case WSAECONNREFUSED:
		result="The attempt to connect was rejected";
		break;
	case WSAEDESTADDRREQ:
		result="A destination address is required";
		break;
	case WSAEFAULT:
		result="The nSockAddrLen argument is incorrect";
		break;
	case WSAEINVAL:
		result="Invalid host address";
		break;
	case WSAEISCONN:
		result="The socket is already connected.";
		break;
	case WSAEMFILE:
		result="No more file descriptors are available";
		break;
	case WSAENETUNREACH:
		result="The network cannot be reached from this host at this time";
		break;
	case WSAENOBUFS:
		result="No buffer space is available. The socket cannot be connected";
		break;
	case WSAENOTSOCK:
		result="The descriptor is not a socket";
		break;
	case WSAETIMEDOUT:
		result="Attempt to connect timed out without establishing a connection";
		break;
	case WSAEWOULDBLOCK:
		result="The socket is marked as nonblocking and the connection cannot be completed immediately.";
		break;
	default:
		result="unknown error";
	}
	return result;
}
