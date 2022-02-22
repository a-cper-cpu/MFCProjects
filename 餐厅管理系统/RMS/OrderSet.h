#if !defined(AFX_ORDERSET_H__FC18A3D8_5DBE_4E6C_8B41_011E95AD5C8B__INCLUDED_)
#define AFX_ORDERSET_H__FC18A3D8_5DBE_4E6C_8B41_011E95AD5C8B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// OrderSet.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// COrderSet recordset

class COrderSet : public CRecordset
{
public:
	COrderSet(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(COrderSet)

// Field/Param Data
	//{{AFX_FIELD(COrderSet, CRecordset)
	CString	m_Desk_code;
	CString	m_Dish_code;
	long	m_Dish_num;
	CTime	m_AppendDate;
	int		m_PayFor;
	//}}AFX_FIELD


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(COrderSet)
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

#endif // !defined(AFX_ORDERSET_H__FC18A3D8_5DBE_4E6C_8B41_011E95AD5C8B__INCLUDED_)
