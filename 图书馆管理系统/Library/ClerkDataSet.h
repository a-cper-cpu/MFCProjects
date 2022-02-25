#if !defined(AFX_CLERKDATASET_H__5AF5B489_0B80_4DEC_BCA1_BA8BDF3EA3D1__INCLUDED_)
#define AFX_CLERKDATASET_H__5AF5B489_0B80_4DEC_BCA1_BA8BDF3EA3D1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ClerkDataSet.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CClerkDataSet recordset

class CClerkDataSet : public CRecordset
{
public:
	CClerkDataSet(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CClerkDataSet)

// Field/Param Data
	//{{AFX_FIELD(CClerkDataSet, CRecordset)
	CString	m_NAME;
	CString	m_PASSWORD;
	//}}AFX_FIELD


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CClerkDataSet)
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

#endif // !defined(AFX_CLERKDATASET_H__5AF5B489_0B80_4DEC_BCA1_BA8BDF3EA3D1__INCLUDED_)
