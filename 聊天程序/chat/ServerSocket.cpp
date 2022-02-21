// ServerSocket.cpp : implementation file
//

#include "stdafx.h"
#include "chat.h"
#include "ServerSocket.h"
#include "chatDlg.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CServerSocket


// Do not edit the following lines, which are needed by ClassWizard.
#if 0
BEGIN_MESSAGE_MAP(CServerSocket, CSocket)
	//{{AFX_MSG_MAP(CServerSocket)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()
#endif	// 0

/////////////////////////////////////////////////////////////////////////////
// CServerSocket member functions

BOOL CServerSocket::Init(UINT port, CChatDlg* dlg)
{
	m_uPort=port;
	m_dlg=dlg;
	if(Create(m_uPort)==FALSE)
	{
		AfxMessageBox("�������׽��ִ���ʧ��!");
		return FALSE;
	}
	if(this->Listen()==FALSE)
	{
		AfxMessageBox("��������������!");
		return FALSE;
	}
	m_dlg->SetDlgItemText(IDC_SHOWMESSAGE,"�����������ɹ�!");
	return TRUE;
}
//�����ӽ����ʱ�򴥷����¼�
void CServerSocket::OnAccept(int nErrorCode) 
{
	// TODO: Add your specialized code here and/or call the base class
	m_dlg->ProcessPendingAccept();
	CSocket::OnAccept(nErrorCode);
}