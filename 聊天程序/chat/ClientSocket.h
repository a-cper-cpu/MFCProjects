#if !defined(AFX_CLIENTSOCKET_H__9A3B7A03_0D59_4A60_ABA2_35D6CA850937__INCLUDED_)
#define AFX_CLIENTSOCKET_H__9A3B7A03_0D59_4A60_ABA2_35D6CA850937__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ClientSocket.h : header file
//

#include "PackMessg.h"


/////////////////////////////////////////////////////////////////////////////
// CClientSocket command target
class CChatDlg;
class CClientSocket : public CSocket
{
// Attributes
public:
	CArchive* m_aSessionIn;
	CArchive* m_aSessionOut;
	CSocketFile* m_sfSocketFile; 
	CChatDlg * m_dlg;
	bool m_bInit;  //作为套接字是否被初始化的标记
	bool m_bClose; //作为套接字是否被关闭的标记
// Operations
public:
	void Init(CChatDlg * dlg);
	BOOL SendMessage(CPackMessg * msg);
	void CloseSocket();
	
public:
	static int GetLocalHostName(CString &sHostName);	//获得本地计算机名称
	static int GetIpAddress(const CString &sHostName, CString &sIpAddress);//获得本地IP
	static int GetIpAddress(const CString &sHostName, BYTE &f0,BYTE &f1,BYTE &f2,BYTE &f3);//获得本地IP
	static CString ErrorReason(int tag);			
public:
	CClientSocket();
	virtual ~CClientSocket();
	

// Overrides
public:
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CClientSocket)

	//通过classwizard添加到类中的成员函数

	public:
	virtual void OnReceive(int nErrorCode);
	virtual void OnClose(int nErrorCode);
	//}}AFX_VIRTUAL

	// Generated message map functions
	//{{AFX_MSG(CClientSocket)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

// Implementation
protected:
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CLIENTSOCKET_H__9A3B7A03_0D59_4A60_ABA2_35D6CA850937__INCLUDED_)
