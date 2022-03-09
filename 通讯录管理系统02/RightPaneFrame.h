#if !defined(AFX_RIGHTPANEFRAME_H__8482607F_6AE2_440F_9C71_034D9037D2FC__INCLUDED_)
#define AFX_RIGHTPANEFRAME_H__8482607F_6AE2_440F_9C71_034D9037D2FC__INCLUDED_

/*
	作者：张超刚

*/

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// RightPaneFrame.h : header file
//

#include "PerInfoView.h"
#include "RightListView.h"

/////////////////////////////////////////////////////////////////////////////
// CRightPaneFrame frame

#define LIST_EVERYONE  WM_USER + 10
class CRightPaneFrame   : public CFrameWnd
{
	DECLARE_DYNCREATE(CRightPaneFrame)
protected:
	CRightPaneFrame();           // protected constructor used by dynamic creation

// Attributes
public:
	CSplitterWnd m_wndSplitter;
	CPerInfoView*  m_pPerInfoView;
	CRightListView* m_pListView;
	//显示详细信息标志
	BOOL    m_bInfo;
	//类别名称
	CString m_strFirstClass,m_strSecondClass;
	CString m_strName;
	//声明ADO记录集
	_RecordsetPtr	m_pRecordset;
	CString m_strWhere;

// Operations
public:
	BOOL OpenRecordSet(_RecordsetPtr &recPtr, CString &strSQL);

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRightPaneFrame)
	public:
	virtual BOOL DestroyWindow();
	protected:
	virtual BOOL OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext);
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CRightPaneFrame();

	// Generated message map functions
	//{{AFX_MSG(CRightPaneFrame)
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnMenuitemInfo();
	afx_msg void OnUpdateMenuitemInfo(CCmdUI* pCmdUI);
	afx_msg void OnQuery();
	//}}AFX_MSG
	afx_msg void ListEveryOne(WPARAM wParam,LPARAM lParam);
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_RIGHTPANEFRAME_H__8482607F_6AE2_440F_9C71_034D9037D2FC__INCLUDED_)

