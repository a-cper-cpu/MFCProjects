// UGMSDlg.h : header file
//

#if !defined(AFX_UGMSDLG_H__046BE1EB_3AF6_4F8C_89E1_770A7EFD7E18__INCLUDED_)
#define AFX_UGMSDLG_H__046BE1EB_3AF6_4F8C_89E1_770A7EFD7E18__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "PageCho.h"
#include "PageCou.h"
#include "PageStat.h"
#include "PageStu.h"
#include "PageWelcome.h"

/////////////////////////////////////////////////////////////////////////////
// CUGMSDlg dialog

class CUGMSDlg : public CDialog
{
// Construction
public:
	CUGMSDlg(CWnd* pParent = NULL);	// standard constructor
	CPageStu		m_PageStu;
	CPageCou		m_PageCou;
	CPageCho		m_PageCho;
	CPageStat		m_PageStat;
	CPageWelcome	m_PageWelcome;

// Dialog Data
	//{{AFX_DATA(CUGMSDlg)
	enum { IDD = IDD_UGMS_DIALOG };
	CListCtrl	m_OutlookBar;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CUGMSDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CUGMSDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnClickOutlookbar(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnKeydownOutlookbar(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	void MoveChilds();
	CImageList m_ImageList;
	void ActivatePage(int nIndex);
	void UpdateOutlookBar();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_UGMSDLG_H__046BE1EB_3AF6_4F8C_89E1_770A7EFD7E18__INCLUDED_)
