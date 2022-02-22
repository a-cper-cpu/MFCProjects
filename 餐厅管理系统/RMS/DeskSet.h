#if !defined(AFX_DESKSET_H__80D8BACC_2592_4ADB_BFF6_94FE040D874F__INCLUDED_)
#define AFX_DESKSET_H__80D8BACC_2592_4ADB_BFF6_94FE040D874F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DeskSet.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDeskSet recordset

class CDeskSet : public CRecordset
{
public:
	CDeskSet(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CDeskSet)

// Field/Param Data
	//{{AFX_FIELD(CDeskSet, CRecordset)
	CString	m_Desk_code;
	int		m_Desk_num;
	CString	m_Desk_detail;
	int		m_Desk_full;
	//}}AFX_FIELD


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDeskSet)
	public:
	virtual CString GetDefaultConnect();    // Default connection string
	virtual CString GetDefaultSQL();    // Default SQL for Recordset
	virtual void DoFieldExchange(CFieldExchange* pFX);  // RFX support
	//}}AFX_VIRTUAL

// Implementation
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DESKSET_H__80D8BACC_2592_4ADB_BFF6_94FE040D874F__INCLUDED_)
