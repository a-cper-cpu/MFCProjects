#if !defined(AFX_ROOMTYPEDLG_H__AADAA6FA_8104_4E84_9DA9_7A53E508917B__INCLUDED_)
#define AFX_ROOMTYPEDLG_H__AADAA6FA_8104_4E84_9DA9_7A53E508917B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// RoomTypeDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CRoomTypeDlg dialog

class CRoomTypeDlg : public CDialog
{
// Construction
public:

	CRoomTypeDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CRoomTypeDlg)
	enum { IDD = IDD_DIALOG_TYPE };
	int		m_iAir;
	CString	m_strTypeID;
	int		m_iTel;
	int		m_iToi;
	int		m_iTV;
	CString	m_strTypeName;
	CString	m_strPrice;
	CString	m_strBedNum;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRoomTypeDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	void DelRoomType();
	void ClearRoomType();
	void FillRoomType();
	void ModifyRoomType();
	void AddRoomType();
	void SetTitle();
	void SetStyle();

	// Generated message map functions
	//{{AFX_MSG(CRoomTypeDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnButtonConfirm();
	afx_msg void OnButtonCancel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ROOMTYPEDLG_H__AADAA6FA_8104_4E84_9DA9_7A53E508917B__INCLUDED_)
