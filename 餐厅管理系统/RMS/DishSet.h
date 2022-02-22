#if !defined(AFX_DISHSET_H__378611C1_B2B5_45E4_9301_143A9D8CF84A__INCLUDED_)
#define AFX_DISHSET_H__378611C1_B2B5_45E4_9301_143A9D8CF84A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DishSet.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDishSet recordset

class CDishSet : public CRecordset
{
public:
	CDishSet(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CDishSet)

// Field/Param Data
	//{{AFX_FIELD(CDishSet, CRecordset)
	CString	m_Dish_code;
	CString	m_Dish_name;
	CString	m_Dish_kind;
	float	m_Dish_price;
	CString	m_Dish_detail;
	//}}AFX_FIELD


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDishSet)
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

#endif // !defined(AFX_DISHSET_H__378611C1_B2B5_45E4_9301_143A9D8CF84A__INCLUDED_)
