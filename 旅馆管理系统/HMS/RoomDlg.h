#if !defined(AFX_ROOMDLG_H__61949BEA_E533_4005_9C3B_EC5084087EE4__INCLUDED_)
#define AFX_ROOMDLG_H__61949BEA_E533_4005_9C3B_EC5084087EE4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// RoomDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CRoomDlg dialog

class CRoomDlg : public CDialog
{
// Construction
public:
	CRoomDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CRoomDlg)
	enum { IDD = IDD_DIALOG_ROOM };
	CString	m_strRoomNO;
	CString	m_strRoomMemo;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRoomDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	void ClearRoom();
	void FillRoom();
	void DelRoom();
	void ModifyRoom();
	void AddRoom();
	void SetStyle();
	void SetTitle();

	// Generated message map functions
	//{{AFX_MSG(CRoomDlg)
	afx_msg void OnButtonConfirm();
	afx_msg void OnButtonCancel();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ROOMDLG_H__61949BEA_E533_4005_9C3B_EC5084087EE4__INCLUDED_)
