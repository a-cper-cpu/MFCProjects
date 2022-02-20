// MFCtest03Dlg.h : header file
//

#if !defined(AFX_MFCTEST03DLG_H__5239B3D4_185A_4209_B1AE_DFEE91584BB6__INCLUDED_)
#define AFX_MFCTEST03DLG_H__5239B3D4_185A_4209_B1AE_DFEE91584BB6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CMFCtest03Dlg dialog

class CMFCtest03Dlg : public CDialog
{
// Construction
public:
	CMFCtest03Dlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CMFCtest03Dlg)
	enum { IDD = IDD_MFCTEST03_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMFCtest03Dlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CMFCtest03Dlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButton2();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MFCTEST03DLG_H__5239B3D4_185A_4209_B1AE_DFEE91584BB6__INCLUDED_)
