// MainFrm.h : interface of the CMainFrame class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MAINFRM_H__33930A00_73E2_4C12_8D31_479DFD9E07C9__INCLUDED_)
#define AFX_MAINFRM_H__33930A00_73E2_4C12_8D31_479DFD9E07C9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "RoomTypeView.h"
#include "UserListView.h"

//定义右边视的类型
#define ROOMTYPEVIEW		0
#define USERLISTVIEW		1

class CLeftTreeView;
class CRoomTypeView;
class CUserListView;


class CMainFrame : public CFrameWnd
{
	
protected: // create from serialization only
	CMainFrame();
	DECLARE_DYNCREATE(CMainFrame)

// Attributes
public:
	CRoomTypeView* m_pRoomTypeView;
	CUserListView* m_pUserListView;


// Operations
public:
	void SwitchToView(int nViewType);

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMainFrame)
	public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual BOOL OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMainFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:  // control bar embedded members
	CStatusBar  m_wndStatusBar;
	CToolBar    m_wndToolBar;
	CSplitterWnd m_wndSplitter;

// Generated message map functions
protected:
	//{{AFX_MSG(CMainFrame)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnRoomtypeAdd();
	afx_msg void OnRoomAdd();
	afx_msg void OnUserAdd();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MAINFRM_H__33930A00_73E2_4C12_8D31_479DFD9E07C9__INCLUDED_)
