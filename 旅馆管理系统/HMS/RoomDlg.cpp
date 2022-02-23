// RoomDlg.cpp : implementation file
//

#include "stdafx.h"
#include "HMS.h"
#include "RoomDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CRoomDlg dialog


CRoomDlg::CRoomDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CRoomDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CRoomDlg)
	m_strRoomNO = _T("");
	m_strRoomMemo = _T("");
	//}}AFX_DATA_INIT
}


void CRoomDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CRoomDlg)
	DDX_Text(pDX, IDC_ROOM_NO, m_strRoomNO);
	DDX_Text(pDX, IDC_ROOM_MEMO, m_strRoomMemo);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CRoomDlg, CDialog)
	//{{AFX_MSG_MAP(CRoomDlg)
	ON_BN_CLICKED(IDC_BUTTON_CONFIRM, OnButtonConfirm)
	ON_BN_CLICKED(IDC_BUTTON_CANCEL, OnButtonCancel)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRoomDlg message handlers

void CRoomDlg::SetTitle()
{
	switch(operation)
	{
	case 1:
		SetWindowText(_T("添加房间"));
		break;
	case 2:
		SetWindowText(_T("修改房间"));
		break;
	case 3:
		SetWindowText(_T("删除房间"));
		break;
	}

}

void CRoomDlg::SetStyle()
{
	switch(operation)
	{
	case 1:
		((CEdit *)GetDlgItem(IDC_ROOM_NO))->SetReadOnly(false);
		((CEdit *)GetDlgItem(IDC_ROOM_MEMO))->SetReadOnly(false);
		ClearRoom();
		break;
	case 2:
		((CEdit *)GetDlgItem(IDC_ROOM_NO))->SetReadOnly(true);
		((CEdit *)GetDlgItem(IDC_ROOM_MEMO))->SetReadOnly(false);
		FillRoom();
		break;
	case 3:	
		((CEdit *)GetDlgItem(IDC_ROOM_NO))->SetReadOnly(true);
		((CEdit *)GetDlgItem(IDC_ROOM_MEMO))->SetReadOnly(true);
		FillRoom();
		break;
	}

}



void CRoomDlg::AddRoom()
{
	UpdateData(true);	
	m_strRoomNO.TrimRight(" ");
    m_strRoomMemo.TrimRight(" ");	
	
	// Make sure all needed info is available
	CString sWarning="";
	if ( ""==m_strRoomNO) sWarning=_T("标准编号");

	    
	if ( ""!=sWarning ) 
	{
	   sWarning += _T("不能为空");
	   AfxMessageBox(sWarning, MB_ICONEXCLAMATION);
	   return;
	}
        
	_variant_t strQuery,Holder;
	// Judge Room Type is Unique
	strQuery = "select * from rooms where RoomNO='"+m_strRoomNO+"'";
	theApp.ADOExecute(theApp.m_pRs, strQuery);
	int iCount = theApp.m_pRs->GetRecordCount();
	if ( 0!=iCount )
	{
	       AfxMessageBox(_T("已经存在此房间编号的记录！"), MB_ICONEXCLAMATION);
		   return;
	}
	
	//get TypeID
	CTreeCtrl* pTreeCtrl=&m_pLeftView->GetTreeCtrl();
	CString strRoomType=pTreeCtrl->GetItemText(pTreeCtrl->GetParentItem(m_pLeftView->m_hHitItem));
	strQuery = "select * from roomtype where TypeName='"+strRoomType+"'";
    theApp.ADOExecute(theApp.m_pRs, strQuery);
	theApp.m_pRs->MoveFirst();
	Holder = theApp.m_pRs->GetCollect("TypeID");
	CString strTypeID= Holder.vt==VT_NULL?"":(char*)(_bstr_t)Holder;

  
	//insert 
	strQuery = "insert rooms (RoomNO, TypeID, RoomMemo) \
	         	    values ('"+m_strRoomNO+"', '"+strTypeID+"','"+m_strRoomMemo+"')";
	if ( theApp.ADOExecute(theApp.m_pRs, strQuery) ) 
	   {
		AfxMessageBox(_T("添加记录成功！"), MB_ICONINFORMATION);
		
		// Clear all input
		m_strRoomNO=m_strRoomMemo="";
		UpdateData(false);
	}
	else
		AfxMessageBox(_T("添加记录失败！"), MB_ICONEXCLAMATION);
	m_pLeftView->FullfillTree();

}

void CRoomDlg::ModifyRoom()
{
	UpdateData(true);	
	m_strRoomNO.TrimRight(" ");
    m_strRoomMemo.TrimRight(" ");	

  
	//modify
	_variant_t strQuery = "Update rooms set RoomMemo='"+m_strRoomMemo+"'"+" where RoomNO='"+m_strRoomNO+"'";

	if ( theApp.ADOExecute(theApp.m_pRs, strQuery) ) 
	   {
		AfxMessageBox(_T("修改记录成功！"), MB_ICONINFORMATION);

	}
	else
		AfxMessageBox(_T("修改记录失败！"), MB_ICONEXCLAMATION);
	m_pLeftView->FullfillTree();

}

void CRoomDlg::DelRoom()
{
	bool bDel=false;
	bDel=(MessageBox("删除房间意味着其下的入住信息将一起删除,确认删除吗?","删除警告",MB_YESNO)==IDYES);
	if(!bDel)
		return;

	_variant_t strQuery,Holder;
	CString strRoomNO;

	;
	strQuery = "Delete from bookin where RoomNO='"+m_strRoomNO+"'";
	theApp.ADOExecute(theApp.m_pRs, strQuery);

	strQuery ="Delete from rooms where RoomNo='"+m_strRoomNO+"'";
	theApp.ADOExecute(theApp.m_pRs, strQuery);

	m_pLeftView->FullfillTree();


}

void CRoomDlg::FillRoom()
{

	CString strRoomNO;
	CTreeCtrl* pCtrl = &m_pLeftView->GetTreeCtrl();
	strRoomNO=pCtrl->GetItemText(m_pLeftView->m_hHitItem);

	
	_variant_t Holder, strQuery;
    strQuery= "select * from rooms where RoomNO='"+strRoomNO+"'";
	theApp.ADOExecute(theApp.m_pRs, strQuery);
    int iCount = theApp.m_pRs->GetRecordCount();
	if ( 0==iCount ) return;
	theApp.m_pRs->MoveFirst();

	Holder = theApp.m_pRs->GetCollect("RoomNO");
	m_strRoomNO= Holder.vt==VT_NULL?"":(char*)(_bstr_t)Holder;

	Holder = theApp.m_pRs->GetCollect("RoomMemo");
	m_strRoomMemo= Holder.vt==VT_NULL?"":(char*)(_bstr_t)Holder;

}

void CRoomDlg::ClearRoom()
{

	m_strRoomMemo=m_strRoomNO="";

}

void CRoomDlg::OnButtonConfirm() 
{
	switch(operation)
	{
	case 1:
		AddRoom();
		break;
	case 2:
		ModifyRoom();
		OnOK();
		break;
	case 3:
		DelRoom();
		OnOK();
		break;
	}

	// TODO: Add your control notification handler code here
	
}

void CRoomDlg::OnButtonCancel() 
{
	OnCancel();
	// TODO: Add your control notification handler code here
	
}

BOOL CRoomDlg::OnInitDialog() 
{
	SetTitle();
	SetStyle();
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
