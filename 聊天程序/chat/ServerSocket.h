#if !defined(AFX_SERVERSOCKET_H__03952A19_3B2C_45BD_B9BB_FBBD072ED603__INCLUDED_)
#define AFX_SERVERSOCKET_H__03952A19_3B2C_45BD_B9BB_FBBD072ED603__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ServerSocket.h : header file
//



/////////////////////////////////////////////////////////////////////////////
// CServerSocket command target
class CChatDlg;

class CServerSocket : public CSocket
{
// Attributes
public:
	CChatDlg * m_dlg;
	UINT m_uPort;
	BOOL Init(UINT port, CChatDlg* dlg);
// Operations
public:
	CServerSocket(){};
	virtual ~CServerSocket(){};

// Overrides
public:
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CServerSocket)
	//使用类向导添加的
	public:
	virtual void OnAccept(int nErrorCode);
	//}}AFX_VIRTUAL

	// Generated message map functions
	//{{AFX_MSG(CServerSocket)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

// Implementation
protected:
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SERVERSOCKET_H__03952A19_3B2C_45BD_B9BB_FBBD072ED603__INCLUDED_)
