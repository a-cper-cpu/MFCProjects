//{{AFX_INCLUDES()
#include "adodc.h"
#include "datagrid.h"
//}}AFX_INCLUDES
#if !defined(AFX_PAGESTAT_H__50C7D4AC_A98E_4D01_A925_97A6A096AE87__INCLUDED_)
#define AFX_PAGESTAT_H__50C7D4AC_A98E_4D01_A925_97A6A096AE87__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PageStat.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CPageStat dialog

class CPageStat : public CDialog
{
// Construction
public:
	CPageStat(CWnd* pParent = NULL);   // standard constructor
	//声明一个ADO记录集
	_RecordsetPtr	m_pRecordset;
	void QuerySID();

// Dialog Data
	//{{AFX_DATA(CPageStat)
	enum { IDD = IDD_PAGE_STAT };
	CAdodc	m_Ado;
	CDataGrid	m_Data;
	int		m_Avg;
	int		m_NPass;
	int		m_CouNum;
	CString	m_SID;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPageStat)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CPageStat)
	virtual BOOL OnInitDialog();
	afx_msg void OnButtonOk();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
//引入全局变量theApp
extern CUGMSApp theApp;

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PAGESTAT_H__50C7D4AC_A98E_4D01_A925_97A6A096AE87__INCLUDED_)
