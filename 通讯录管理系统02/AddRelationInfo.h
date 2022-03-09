#if !defined(AFX_ADDRELATIONINFO_H__8702C90F_99D9_4EEC_9959_111BC5DCC684__INCLUDED_)
#define AFX_ADDRELATIONINFO_H__8702C90F_99D9_4EEC_9959_111BC5DCC684__INCLUDED_


/*
	作者：张超刚

*/

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// AddRelationInfo.h : header file
//



/////////////////////////////////////////////////////////////////////////////
// CAddRelationInfo dialog
#include <afxtempl.h>
class CAddRelationInfo   : public CDialog
{
// Construction
public:
	CAddRelationInfo(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CAddRelationInfo)
	enum { IDD = IDD_ADD_INFO };
	CComboBox	m_ComboSecond;
	CComboBox	m_ComboFirst;
	CString	m_strComment;
	CString	m_strComAddre;
	CString	m_strComName;
	CString	m_strEmail;
	CString	m_strHomeAddre;
	CString	m_strHomeTel;
	CString	m_strMobile;
	CString	m_strOfficeTel;
	CString	m_strWeb;
	CString	m_strName;
	COleDateTime	m_OleBirthDay;
	CString	m_strFirClass;
	CString	m_strSecClass;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAddRelationInfo)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL
public:
	
	void ResetCtrlValue();
	BOOL OpenRecordSet(_RecordsetPtr &recPtr, CString &strSQL);
	void SetFileToDb(_RecordsetPtr& recPtr,CString strPath);
//
	//声明ADO记录集
	_RecordsetPtr	m_pRecordset;
	CString m_strTitle;//对话框标题
	//当前对话框是否用来编辑，因为编辑时，联系人姓名不可改变
	BOOL bEdit;
	CString m_strPhotoPath;
	
	//链表,用于记录一级类别
	CList<HTREEITEM,HTREEITEM> m_hItemList;
// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CAddRelationInfo)
	afx_msg void OnInsertInfo();
	afx_msg void OnPhoto();
	virtual BOOL OnInitDialog();
	afx_msg void OnSelendokFirstClass();
	afx_msg void OnEditInfo();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ADDRELATIONINFO_H__8702C90F_99D9_4EEC_9959_111BC5DCC684__INCLUDED_)
