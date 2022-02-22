#if !defined(AFX_PAYSET_H__4E209B57_EE9B_492D_9850_930AA67DD44B__INCLUDED_)
#define AFX_PAYSET_H__4E209B57_EE9B_492D_9850_930AA67DD44B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PaySet.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CPaySet recordset

class CPaySet : public CRecordset
{
public:
	CPaySet(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CPaySet)

// Field/Param Data
	//{{AFX_FIELD(CPaySet, CRecordset)
	CString	m_Dish_code;
	CString	m_Dish_name;
	CString	m_Dish_kind;
	float	m_Dish_price;
	CString	m_Dish_detail;
	CString	m_Desk_code;
	CString	m_Dish_code2;
	long	m_Dish_num;
	CTime	m_AppendDate;
	int		m_PayFor;
	//}}AFX_FIELD


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPaySet)
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

#endif // !defined(AFX_PAYSET_H__4E209B57_EE9B_492D_9850_930AA67DD44B__INCLUDED_)
