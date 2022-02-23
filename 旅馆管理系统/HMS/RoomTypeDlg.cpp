// RoomTypeDlg.cpp : implementation file
//

#include "stdafx.h"
#include "HMS.h"
#include "RoomTypeDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CRoomTypeDlg dialog


CRoomTypeDlg::CRoomTypeDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CRoomTypeDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CRoomTypeDlg)
	m_iAir = -1;
	m_strTypeID = _T("");
	m_iTel = -1;
	m_iToi = -1;
	m_iTV = -1;
	m_strTypeName = _T("");
	m_strPrice = _T("");
	m_strBedNum = _T("");
	//}}AFX_DATA_INIT

	
}


void CRoomTypeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CRoomTypeDlg)
	DDX_CBIndex(pDX, IDC_ROOMTYPE_ISAIRCON, m_iAir);
	DDX_Text(pDX, IDC_ROOMTYPE_ID, m_strTypeID);
	DDX_CBIndex(pDX, IDC_ROOMTYPE_ISTEL, m_iTel);
	DDX_CBIndex(pDX, IDC_ROOMTYPE_ISTOILET, m_iToi);
	DDX_CBIndex(pDX, IDC_ROOMTYPE_ISTV, m_iTV);
	DDX_Text(pDX, IDC_ROOMTYPE_NAME, m_strTypeName);
	DDX_Text(pDX, IDC_ROOMTYPE_PRICE, m_strPrice);
	DDX_Text(pDX, IDC_ROOMTYPE_BEDNO, m_strBedNum);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CRoomTypeDlg, CDialog)
	//{{AFX_MSG_MAP(CRoomTypeDlg)
	ON_BN_CLICKED(IDC_BUTTON_CONFIRM, OnButtonConfirm)
	ON_BN_CLICKED(IDC_BUTTON_CANCEL, OnButtonCancel)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRoomTypeDlg message handlers

BOOL CRoomTypeDlg::OnInitDialog() 
{
	SetTitle();
	SetStyle();	
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CRoomTypeDlg::SetTitle()
{
	switch(operation)
	{
	case 1:
		SetWindowText(_T("添加标准"));
		break;
	case 2:
		SetWindowText(_T("修改标准"));
		break;
	case 3:
		SetWindowText(_T("删除标准"));
		break;
	}

}

void CRoomTypeDlg::SetStyle()
{
	switch(operation)
	{
	case 1:
		((CEdit *)GetDlgItem(IDC_ROOMTYPE_ID))->SetReadOnly(false);
		((CEdit *)GetDlgItem(IDC_ROOMTYPE_NAME))->SetReadOnly(false);
		((CEdit *)GetDlgItem(IDC_ROOMTYPE_BEDNO))->SetReadOnly(false);
		((CEdit *)GetDlgItem(IDC_ROOMTYPE_PRICE))->SetReadOnly(false);
		ClearRoomType();
		break;
	case 2:
		((CEdit *)GetDlgItem(IDC_ROOMTYPE_ID))->SetReadOnly(true);
		((CEdit *)GetDlgItem(IDC_ROOMTYPE_NAME))->SetReadOnly(false);
		((CEdit *)GetDlgItem(IDC_ROOMTYPE_BEDNO))->SetReadOnly(false);
		((CEdit *)GetDlgItem(IDC_ROOMTYPE_PRICE))->SetReadOnly(false);
		FillRoomType();
		break;
	case 3:
	
		((CEdit *)GetDlgItem(IDC_ROOMTYPE_ID))->SetReadOnly(true);
		((CEdit *)GetDlgItem(IDC_ROOMTYPE_NAME))->SetReadOnly(true);
		((CEdit *)GetDlgItem(IDC_ROOMTYPE_BEDNO))->SetReadOnly(true);
		((CEdit *)GetDlgItem(IDC_ROOMTYPE_PRICE))->SetReadOnly(true);
		FillRoomType();
		break;
	}

}

void CRoomTypeDlg::OnButtonConfirm() 
{
	switch(operation)
	{
	case 1:
		AddRoomType();
		break;
	case 2:
		ModifyRoomType();
		OnOK();
		break;
	case 3:
		DelRoomType();
		OnOK();
		break;
	}

	// TODO: Add your control notification handler code here
	
}

void CRoomTypeDlg::AddRoomType()
{
	UpdateData(true);	
	m_strTypeID.TrimRight(" ");
    m_strTypeName.TrimRight(" ");
	m_strBedNum.TrimRight(" ");
	m_strPrice.TrimRight(" ");
	
	
	// Make sure all needed info is available
	CString sWarning="";
	if ( ""==m_strTypeID) sWarning=_T("标准编号");
    else if ( ""==  m_strTypeName) sWarning=_T("标准名称");
	else if ( ""==m_strBedNum) sWarning=_T("床位数量");
	else if ( ""==	m_strPrice) sWarning=_T("住房单价");
	    
	if ( ""!=sWarning ) 
	{
	   sWarning += _T("不能为空");
	   AfxMessageBox(sWarning, MB_ICONEXCLAMATION);
	   return;
	}
        
	// Make sure the Number info is valid

	float fPrice = atof(m_strPrice);
	if ( 0==fPrice ) 
	{
		AfxMessageBox(_T("住房单价：请输入非零数字"), MB_ICONEXCLAMATION);
	    return;
	}
	m_strPrice.Format("%.2f", fPrice);

	if ( atof(m_strPrice)>99999999.99 ) 
	{
	    AfxMessageBox(_T("住房单价溢出，请不要超过99999999.99"), MB_ICONEXCLAMATION);
		return;
	}
	
	_variant_t strQuery;
	// Judge Room Type is Unique
	strQuery = "select * from roomtype where TypeID='"+m_strTypeID+"'";
	theApp.ADOExecute(theApp.m_pRs, strQuery);
	int iCount = theApp.m_pRs->GetRecordCount();
	if ( 0!=iCount )
	{
	       AfxMessageBox(_T("已经存在此标准编号的记录！"), MB_ICONEXCLAMATION);
		   return;
	}
	// Judge Room Name is Unique
	strQuery = "select * from roomtype where TypeID!='"+m_strTypeID+"' and TypeName='"+m_strTypeName+"'";
	theApp.ADOExecute(theApp.m_pRs, strQuery);
	iCount = theApp.m_pRs->GetRecordCount();
	if ( 0!=iCount )
	{
		AfxMessageBox(_T("已经存相同客房标准的记录！"), MB_ICONEXCLAMATION);
		return;
	}
	
    // Get other info
	CString strAir("0"), strTel("0"), strTV("0"), strToilet("0");
	if ( ((CComboBox*)GetDlgItem(IDC_ROOMTYPE_ISAIRCON))->GetCurSel() ) strAir="1";
	if ( ((CComboBox*)GetDlgItem(IDC_ROOMTYPE_ISTEL))->GetCurSel() ) strTel="1";
	if ( ((CComboBox*)GetDlgItem(IDC_ROOMTYPE_ISTV))->GetCurSel() ) strTV="1";
	if ( ((CComboBox*)GetDlgItem(IDC_ROOMTYPE_ISTOILET))->GetCurSel() ) strToilet="1";
	
	strQuery = "insert roomtype (TypeID, TypeName, BedNum,  HavAir, HavTel, HavTV, HavToi,Price) \
	         	    values ('"+m_strTypeID+"', '"+m_strTypeName+"',  "+m_strBedNum+", "+strAir+", "+strTel+","+strTV+", "+strToilet+", "+m_strPrice+")";
	if ( theApp.ADOExecute(theApp.m_pRs, strQuery) ) 
	   {
		AfxMessageBox(_T("添加记录成功！"), MB_ICONINFORMATION);
		
		// Clear all input
		m_strTypeID=m_strTypeName=m_strBedNum=m_strPrice="";
		((CComboBox*)GetDlgItem(IDC_ROOMTYPE_ISAIRCON))->SetCurSel(1);
		((CComboBox*)GetDlgItem(IDC_ROOMTYPE_ISTEL))->SetCurSel(1);
		((CComboBox*)GetDlgItem(IDC_ROOMTYPE_ISTV))->SetCurSel(1);
		((CComboBox*)GetDlgItem(IDC_ROOMTYPE_ISTOILET))->SetCurSel(1);
		UpdateData(false);
	}
	else
		AfxMessageBox(_T("添加记录失败！"), MB_ICONEXCLAMATION);
	m_pLeftView->FullfillTree();







}

void CRoomTypeDlg::OnButtonCancel() 
{
	// TODO: Add your control notification handler code here
	OnCancel();

	
}

void CRoomTypeDlg::ModifyRoomType()
{
	UpdateData(true);	
	m_strTypeID.TrimRight(" ");
    m_strTypeName.TrimRight(" ");
	m_strBedNum.TrimRight(" ");
	m_strPrice.TrimRight(" ");
	
	
	// Make sure all needed info is available
	CString sWarning="";
	if ( ""==m_strTypeID) sWarning=_T("标准编号");
    else if ( ""==  m_strTypeName) sWarning=_T("标准名称");
	else if ( ""==m_strBedNum) sWarning=_T("床位数量");
	else if ( ""==	m_strPrice) sWarning=_T("住房单价");
	    
	if ( ""!=sWarning ) 
	{
	   sWarning += _T("不能为空");
	   AfxMessageBox(sWarning, MB_ICONEXCLAMATION);
	   return;
	}
        
	// Make sure the Number info is valid

	float fPrice = atof(m_strPrice);
	if ( 0==fPrice ) 
	{
		AfxMessageBox(_T("住房单价：请输入非零数字"), MB_ICONEXCLAMATION);
	    return;
	}
	m_strPrice.Format("%.2f", fPrice);

	if ( atof(m_strPrice)>99999999.99 ) 
	{
	    AfxMessageBox(_T("住房单价溢出，请不要超过99999999.99"), MB_ICONEXCLAMATION);
		return;
	}
	

    // Get other info
	CString strAir("0"), strTel("0"), strTV("0"), strToilet("0");
	if ( ((CComboBox*)GetDlgItem(IDC_ROOMTYPE_ISAIRCON))->GetCurSel() ) strAir="1";
	if ( ((CComboBox*)GetDlgItem(IDC_ROOMTYPE_ISTEL))->GetCurSel() ) strTel="1";
	if ( ((CComboBox*)GetDlgItem(IDC_ROOMTYPE_ISTV))->GetCurSel() ) strTV="1";
	if ( ((CComboBox*)GetDlgItem(IDC_ROOMTYPE_ISTOILET))->GetCurSel() ) strToilet="1";

	_variant_t strQuery = "Update roomtype set TypeName='"+m_strTypeName+"',"+"BedNum="+m_strBedNum+", Price="+m_strPrice+",HavAir="+strAir+", \
		HavTel="+strTel+", HavTV="+strTV+", HavToi="+strToilet+" where TypeID='"+m_strTypeID+"'";
	if ( theApp.ADOExecute(theApp.m_pRs, strQuery) ) 
		AfxMessageBox(_T("修改记录成功！"), MB_ICONINFORMATION);
	else 
		AfxMessageBox(_T("修改记录失败！"), MB_ICONEXCLAMATION);
	m_pLeftView->FullfillTree();

}

void CRoomTypeDlg::FillRoomType()
{
	CString strTypeName;
	CTreeCtrl* pCtrl = &m_pLeftView->GetTreeCtrl();
	strTypeName=pCtrl->GetItemText(m_pLeftView->m_hHitItem);

	
	_variant_t Holder, strQuery;
    strQuery= "select * from RoomType where TypeName='"+strTypeName+"'";
	theApp.ADOExecute(theApp.m_pRs, strQuery);
    int iCount = theApp.m_pRs->GetRecordCount();
	if ( 0==iCount ) return;
	theApp.m_pRs->MoveFirst();

	Holder = theApp.m_pRs->GetCollect("TypeID");
	m_strTypeID= Holder.vt==VT_NULL?"":(char*)(_bstr_t)Holder;

	Holder = theApp.m_pRs->GetCollect("TypeName");
	m_strTypeName= Holder.vt==VT_NULL?"":(char*)(_bstr_t)Holder;

	Holder = theApp.m_pRs->GetCollect("BedNum");
	m_strBedNum.Format("%d", Holder.vt==VT_NULL?0:Holder.iVal);

	Holder = theApp.m_pRs->GetCollect("Price");
	m_strPrice.Format("%0.2f", Holder.vt==VT_NULL?0.0:Holder.dblVal);

	Holder = theApp.m_pRs->GetCollect("HavAir");
	m_iAir=Holder.vt==VT_NULL?0:Holder.iVal;

	Holder = theApp.m_pRs->GetCollect("HavTel");
	m_iTel=Holder.vt==VT_NULL?0:Holder.iVal;

	Holder = theApp.m_pRs->GetCollect("HavTV");
	m_iTV=Holder.vt==VT_NULL?0:Holder.iVal;

	Holder = theApp.m_pRs->GetCollect("HavToi");
	m_iToi=Holder.vt==VT_NULL?0:Holder.iVal;


}

void CRoomTypeDlg::ClearRoomType()
{
	m_iAir=m_iTel=m_iToi=m_iTV=0;
	m_strBedNum=m_strPrice=m_strTypeID=m_strTypeName="";



}

void CRoomTypeDlg::DelRoomType()
{
	bool bDel=false;
	bDel=(MessageBox("删除标准意味着其下的房间和入住信息将一起删除,确认删除吗?","删除警告",MB_YESNO)==IDYES);
	if(!bDel)
		return;

	_variant_t strQuery,Holder;
	CString strRoomNO;

	strQuery = "select RoomNO from rooms where TypeID='"+m_strTypeID+"'";
	theApp.ADOExecute(theApp.m_pRs, strQuery);
	int iCount = theApp.m_pRs->GetRecordCount();
	if ( 0==iCount )
	{
	}
	else
	{
		theApp.m_pRs->MoveFirst();
		for(int i=0;i<iCount;i++)
		{
			Holder = theApp.m_pRs->GetCollect("RoomNO");
			strRoomNO= Holder.vt==VT_NULL?"":(char*)(_bstr_t)Holder;
			strQuery = "Delete from bookin where RoomNO='"+strRoomNO+"'";
			theApp.ADOExecute(theApp.m_pRs, strQuery);
		}	
		
		strQuery ="Delete from rooms where TypeID='"+m_strTypeID+"'";
		theApp.ADOExecute(theApp.m_pRs, strQuery);
	}
	





	strQuery ="Delete from roomtype where TypeID='"+m_strTypeID+"'";
	theApp.ADOExecute(theApp.m_pRs, strQuery);

	m_pLeftView->FullfillTree();



}
