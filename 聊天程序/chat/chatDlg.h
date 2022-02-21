// chatDlg.h : header file
//

#if !defined(AFX_CHATDLG_H__1EF34668_8868_4CD0_BD82_CBDF002C8E3B__INCLUDED_)
#define AFX_CHATDLG_H__1EF34668_8868_4CD0_BD82_CBDF002C8E3B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ServerSocket.h"
#include "ClientSocket.h"
/////////////////////////////////////////////////////////////////////////////
// CChatDlg dialog

class CChatDlg : public CDialog
{
// Construction
public:
	CChatDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CChatDlg)
	enum { IDD = IDD_CHAT_DIALOG };
	CString	m_strMessage;
	CString	m_strName;
	UINT	m_port;
	CString	m_strShowMessage;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CChatDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
public:
	void ProcessPendingAccept();
	void CloseSessionSocket();
	void ClearContent();
	void OnClearconnection();
protected:
	HICON m_hIcon;
public:
	bool m_bInit;
	bool m_bClient;
	CClientSocket m_clientsocket;
	CServerSocket m_pListenSocket;
	CPtrList m_connectionList;
	CString m_sMsgList;

	// Generated message map functions
	//{{AFX_MSG(CChatDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnConnect();
	afx_msg void OnSetserver();
	afx_msg void OnSend();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CHATDLG_H__1EF34668_8868_4CD0_BD82_CBDF002C8E3B__INCLUDED_)
