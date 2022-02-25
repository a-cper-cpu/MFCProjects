// SubListView.cpp : implementation file
//

#include "stdafx.h"
#include "TMS.h"
#include "SubListView.h"
#include "CarDlg.h"
#include "DriverDlg.h"
#include "CarDriverDlg.h"
#include "CarFeeDlg.h"
#include "DriverLawDlg.h"
#include "DriverAwardDlg.h"
#include "LawDlg.h"
#include "FeeDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSubListView

IMPLEMENT_DYNCREATE(CSubListView, CListView)

CSubListView::CSubListView()
{
}

CSubListView::~CSubListView()
{
}


BEGIN_MESSAGE_MAP(CSubListView, CListView)
	//{{AFX_MSG_MAP(CSubListView)
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDOWN()
	ON_WM_LBUTTONDBLCLK()
	ON_COMMAND(ID_MENUITEM_CARMODIFY, OnMenuitemCarmodify)
	ON_COMMAND(ID_MENUITEM_CARDEL, OnMenuitemCardel)
	ON_COMMAND(ID_MENUITEM_CARADD, OnMenuitemCaradd)
	ON_COMMAND(ID_MENUITEM_DRIVERADD, OnMenuitemDriveradd)
	ON_COMMAND(ID_MENUITEM_DRIVERMODIFY, OnMenuitemDrivermodify)
	ON_COMMAND(ID_MENUITEM_DRIVERDEL, OnMenuitemDriverdel)
	ON_COMMAND(ID_MENUITEM_CDADD, OnMenuitemCdadd)
	ON_COMMAND(ID_MENUITEM_CDMODIFY, OnMenuitemCdmodify)
	ON_COMMAND(ID_MENUITEM_CDDEL, OnMenuitemCddel)
	ON_COMMAND(ID_MENUITEM_CARFEEADD, OnMenuitemCarfeeadd)
	ON_COMMAND(ID_MENUITEM_CARFEEMODIFY, OnMenuitemCarfeemodify)
	ON_COMMAND(ID_MENUITEM_CARFEEDL, OnMenuitemCarfeedl)
	ON_COMMAND(ID_MENUITEM_DRIVERLAWADD, OnMenuitemDriverlawadd)
	ON_COMMAND(ID_MENUITEM_DRIVERLAWMODIFY, OnMenuitemDriverlawmodify)
	ON_COMMAND(ID_MENUITEM_DRIVERLAWDEL, OnMenuitemDriverlawdel)
	ON_COMMAND(ID_MENUITEM_DRIVERAWARDADD, OnMenuitemDriverawardadd)
	ON_COMMAND(ID_MENUITEM_DRIVERAWARDMODIFY, OnMenuitemDriverawardmodify)
	ON_COMMAND(ID_MENUITEM_DRIVERAWARDDEL, OnMenuitemDriverawarddel)
	ON_COMMAND(ID_MENUITEM_FEEADD, OnMenuitemFeeadd)
	ON_COMMAND(ID_MENUITEM_FEEMODIFY, OnMenuitemFeemodify)
	ON_COMMAND(ID_MENUITEM_FEEDEL, OnMenuitemFeedel)
	ON_COMMAND(ID_MENUITEM_LAWADD, OnMenuitemLawadd)
	ON_COMMAND(ID_MENUITEM_LAWMODIFY, OnMenuitemLawmodify)
	ON_COMMAND(ID_MENUITEM_LAWDEL, OnMenuitemLawdel)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSubListView drawing

void CSubListView::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	// TODO: add draw code here
}

/////////////////////////////////////////////////////////////////////////////
// CSubListView diagnostics

#ifdef _DEBUG
void CSubListView::AssertValid() const
{
	CListView::AssertValid();
}

void CSubListView::Dump(CDumpContext& dc) const
{
	CListView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CSubListView message handlers
void CSubListView::SetStyle()
{
	DWORD dwStyle = GetWindowLong(m_hWnd, GWL_STYLE); 
	dwStyle &= ~(LVS_TYPEMASK);
	dwStyle &= ~(LVS_EDITLABELS);
 
	// Make sure we have report view and send edit label messages.
    SetWindowLong( m_hWnd, GWL_STYLE, 
		dwStyle | LVS_REPORT|LVS_NOLABELWRAP|LVS_SHOWSELALWAYS);

	// Enable the full row selection and the drag drop of headers.
	DWORD styles = LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES;
	// Use macro since this is new and not in MFC.
	ListView_SetExtendedListViewStyleEx(m_hWnd, styles, styles );

}

void CSubListView::SetTitle()
{
	TCHAR cTitle[30];
	LV_COLUMN lvcolumn;
	CRect rect;
	this->GetWindowRect(&rect);

	for(int i=0;i<arTitle.GetSize();i++)
	{
		for(int j=0;j<arTitle[i].GetLength();j++)
			cTitle[j]=arTitle[i].GetAt(j);
		cTitle[j]='\0';

		lvcolumn.mask = LVCF_FMT | LVCF_SUBITEM | LVCF_TEXT 
						| LVCF_WIDTH | LVCF_ORDER;
		lvcolumn.fmt = LVCFMT_LEFT;
		lvcolumn.pszText = cTitle;
		lvcolumn.iSubItem = i;
		lvcolumn.iOrder = i;
		lvcolumn.cx = rect.Height()/4;
		GetListCtrl().InsertColumn(i, &lvcolumn);
	}








}

void CSubListView::OnInitialUpdate() 
{
	CListView::OnInitialUpdate();

	SetStyle();
	GetTitle();
	SetTitle();	
	
	// TODO: Add your specialized code here and/or call the base class
	
}

void CSubListView::GetTitle()
{
	arTitle.RemoveAll();
	switch(SelItemType)
	{
	case 11:
		arTitle.Add(CString("车号"));
		arTitle.Add(CString("品牌"));
		arTitle.Add(CString("颜色"));
		arTitle.Add(CString("发动机号"));
		arTitle.Add(CString("底盘号"));
		arTitle.Add(CString("计价器号"));
		break;
	case 12:
		arTitle.Add(CString("车辆编号"));
		arTitle.Add(CString("司机编号"));
		arTitle.Add(CString("是否在职"));
		break;
	case 13:
		arTitle.Add(CString("车辆编号"));
		arTitle.Add(CString("费用编号"));
		arTitle.Add(CString("起始时间"));
		arTitle.Add(CString("终止时间"));
		break;
	case 21:
		arTitle.Add(CString("编号"));
		arTitle.Add(CString("姓名"));
		arTitle.Add(CString("性别"));
		arTitle.Add(CString("身份证"));
		arTitle.Add(CString("家庭地址"));
		arTitle.Add(CString("驾照初领日期"));
		arTitle.Add(CString("准驾车型"));

		break;

	case 22:
		arTitle.Add(CString("司机号"));
		arTitle.Add(CString("法规号"));
		arTitle.Add(CString("发生地点"));
		arTitle.Add(CString("发生日期"));
		arTitle.Add(CString("是否处理"));
		arTitle.Add(CString("其他信息"));
		break;
	case 23:
		arTitle.Add(CString("司机号"));
		arTitle.Add(CString("奖惩号"));
		arTitle.Add(CString("内容"));
		arTitle.Add(CString("备注"));

		break;
	case 31:
		arTitle.Add(CString("法规号"));
		arTitle.Add(CString("法规名"));
		arTitle.Add(CString("施法部门"));
		arTitle.Add(CString("罚钱"));
		arTitle.Add(CString("扣点"));
		arTitle.Add(CString("扣驾驶本"));
		break;
	case 32:
		arTitle.Add(CString("费用号"));
		arTitle.Add(CString("费用名"));
		arTitle.Add(CString("收费部门"));
		arTitle.Add(CString("收费额度"));

		break;
	case 33:
		break;
	}

}

void CSubListView::RefreshData()
{
	switch(SelItemType)
	{
	case 11:
		ListCar();
		break;
	case 12:
		ListCarDriver();
		break;
	case 13:
		ListCarFee();
		break;
	case 21:
		ListDriver();
		break;
	case 22:
		ListDriverPunish();
		break;
	case 23:
		ListDriverAward();
		break;
	case 31:
		ListPunish();
		break;
	case 32:
		ListFee();
		break;
	}

	


}

void CSubListView::ListCar()
{
	CListCtrl* pList = &GetListCtrl();

	//清空列表
	pList->DeleteAllItems();
	pList->SetRedraw(FALSE);
	
	_variant_t Holder, strQuery;
    strQuery= "select * from car";
	theApp.ADOExecute(theApp.m_pRs, strQuery);
    int iCount = theApp.m_pRs->GetRecordCount();
	if ( 0==iCount ) 
		return;
	theApp.m_pRs->MoveFirst();

	int i=0;
	while(!theApp.m_pRs->adoEOF)
	{
		Holder = theApp.m_pRs->GetCollect("Car_NO");
		if(Holder.vt!=VT_NULL)
			pList->InsertItem(i, (char*)(_bstr_t)Holder);

		Holder = theApp.m_pRs->GetCollect("Car_Kind");
		if(Holder.vt!=VT_NULL)
			pList->SetItemText(i,1, (char*)(_bstr_t)Holder);

		Holder = theApp.m_pRs->GetCollect("Car_Color");
		if(Holder.vt!=VT_NULL)
			pList->SetItemText(i,2, (char*)(_bstr_t)Holder);
		
		Holder = theApp.m_pRs->GetCollect("Car_EngineNO");
		if(Holder.vt!=VT_NULL)
			pList->SetItemText(i,3, (char*)(_bstr_t)Holder);

		
		Holder = theApp.m_pRs->GetCollect("Car_ClassisNO");
		if(Holder.vt!=VT_NULL)
			pList->SetItemText(i,4, (char*)(_bstr_t)Holder);
		Holder = theApp.m_pRs->GetCollect("Car_MeterNO");
		if(Holder.vt!=VT_NULL)
			pList->SetItemText(i,5, (char*)(_bstr_t)Holder);

		theApp.m_pRs->MoveNext();
		i++;
	}

	pList->SetRedraw(TRUE);	

}

void CSubListView::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	
	CListView::OnLButtonDown(nFlags, point);
	CListCtrl* pCtrl = &GetListCtrl();
	nHitItem = pCtrl->HitTest(point,NULL);
	if( nHitItem < 0 )
		return;
	switch(SelItemType)
	{
	case 11:
		SelCar();
		break;
	case 12:
		SelCarDriver();
		break;
	case 13:
		SelCarFee();
		break;
	case 21:
		SelDriver();
		break;
	case 22:
		SelDriverLaw();
		break;
	case 23:
		SelDriverAward();
		break;
	case 31:
		SelLaw();
		break;
	case 32:
		SelFee();
		break;
	}
}

void CSubListView::OnRButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	
	CListView::OnRButtonDown(nFlags, point);

	CMenu menu,*pSubMenu;
	switch(SelItemType)
	{
	case 11:
		menu.LoadMenu(IDR_MENU_CAR);
		break;
	case 12:
		menu.LoadMenu(IDR_MENU_CARDRIVER);
		break;
	case 13:
		menu.LoadMenu(IDR_MENU_CARFEE);
		break;
	case 21:
		menu.LoadMenu(IDR_MENU_DRIVER);
		break;
	case 22:
		menu.LoadMenu(IDR_MENU_DRIVERLAW);
		break;
	case 23:
		menu.LoadMenu(IDR_MENU_DRIVERAWARD);
		break;
	case 31:
		menu.LoadMenu(IDR_MENU_LAW);
		break;
	case 32:
		menu.LoadMenu(IDR_MENU_FEE);
		break;
	default:
		return;
	}

	CPoint oPoint;
	GetCursorPos(&oPoint);
	pSubMenu=menu.GetSubMenu(0);
	pSubMenu->TrackPopupMenu(TPM_LEFTALIGN,oPoint.x,oPoint.y,this);	
}

void CSubListView::OnLButtonDblClk(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	
	CListView::OnLButtonDblClk(nFlags, point);
	CListCtrl* pCtrl = &GetListCtrl();
	nHitItem = pCtrl->HitTest(point,NULL);
	if( nHitItem < 0 )
		return;
	operation=2;
	if(SelItemType==11)
	{
		SelCar();	
		CCarDlg dlg;
	    dlg.DoModal();
	}
	else if(SelItemType==12)
	{
		SelCarDriver();
		CCarDriverDlg dlg;
		dlg.DoModal();

	}
	else if(SelItemType==13)
	{
		SelCarFee();
		CCarFeeDlg dlg;
		dlg.DoModal();
	}
	else if(SelItemType==21)
	{
		SelDriver();
		CDriverDlg dlg;
		dlg.DoModal();

	}
	else if(SelItemType=22)
	{
		SelDriverLaw();
		CDriverLawDlg dlg;
		dlg.DoModal();
	}
	else if(SelItemType=23)
	{
		SelDriverAward();
		CDriverAwardDlg dlg;
		dlg.DoModal();
	}
	else if(SelItemType=31)
	{
		SelLaw();
		CLawDlg dlg;
		dlg.DoModal();
	}
	else if(SelItemType=32)
	{
		SelFee();
		CFeeDlg dlg;
		dlg.DoModal();
	}



}

void CSubListView::SelCar()
{
	CListCtrl* pCtrl = &GetListCtrl();


	selCar.Car_NO=pCtrl->GetItemText(nHitItem,0);
	selCar.Car_Kind=pCtrl->GetItemText(nHitItem,1);
	selCar.Car_Color=pCtrl->GetItemText(nHitItem,2);
	selCar.Car_EngineNO=pCtrl->GetItemText(nHitItem,3);
	selCar.Car_ClassisNO=pCtrl->GetItemText(nHitItem,4);
	selCar.Car_MeterNO=pCtrl->GetItemText(nHitItem,5);

}


void CSubListView::ListDriver()
{
	CListCtrl* pList = &GetListCtrl();

	//清空列表
	pList->DeleteAllItems();
	pList->SetRedraw(FALSE);
	
	_variant_t Holder, strQuery;
    strQuery= "select * from driver";
	theApp.ADOExecute(theApp.m_pRs, strQuery);
    int iCount = theApp.m_pRs->GetRecordCount();
	if ( 0==iCount ) 
		return;
	theApp.m_pRs->MoveFirst();

	int i=0;
	while(!theApp.m_pRs->adoEOF)
	{
		Holder = theApp.m_pRs->GetCollect("Driver_NO");
		if(Holder.vt!=VT_NULL)
			pList->InsertItem(i, (char*)(_bstr_t)Holder);

		Holder = theApp.m_pRs->GetCollect("Driver_Name");
		if(Holder.vt!=VT_NULL)
			pList->SetItemText(i,1, (char*)(_bstr_t)Holder);

		Holder = theApp.m_pRs->GetCollect("Driver_Sex");
		if(Holder.vt!=VT_NULL)
			pList->SetItemText(i,2, Holder.iVal==1?"男":"女");
		
		Holder = theApp.m_pRs->GetCollect("Driver_ID");
		if(Holder.vt!=VT_NULL)
			pList->SetItemText(i,3, (char*)(_bstr_t)Holder);

		
		Holder = theApp.m_pRs->GetCollect("Driver_Address");
		if(Holder.vt!=VT_NULL)
			pList->SetItemText(i,4, (char*)(_bstr_t)Holder);

		Holder = theApp.m_pRs->GetCollect("Driver_BookDate");
		if(Holder.vt!=VT_NULL)
			pList->SetItemText(i,5, (char*)(_bstr_t)Holder);

		Holder = theApp.m_pRs->GetCollect("Driver_CarKind");
		if(Holder.vt!=VT_NULL)
			pList->SetItemText(i,6, (char*)(_bstr_t)Holder);

		Holder = theApp.m_pRs->GetCollect("Driver_Phone");
		if(Holder.vt!=VT_NULL)
			pList->SetItemText(i,7, (char*)(_bstr_t)Holder);

		theApp.m_pRs->MoveNext();
		i++;
	}

	pList->SetRedraw(TRUE);	

}

void CSubListView::SelDriver()
{
	CListCtrl* pCtrl = &GetListCtrl();

	selDriver.strNO=pCtrl->GetItemText(nHitItem,0);
	selDriver.strName=pCtrl->GetItemText(nHitItem,1);
	selDriver.strSex=pCtrl->GetItemText(nHitItem,2);
	selDriver.strID=pCtrl->GetItemText(nHitItem,3);
	selDriver.strAddress=pCtrl->GetItemText(nHitItem,4);

	CString strDate=pCtrl->GetItemText(nHitItem,5);
	long y,m,d;
	sscanf(strDate.GetBuffer(strDate.GetLength()),"%d-%d-%d",&y,&m,&d);
	if(y<1000)
		y+=2000;
	CTime time(y,m,d,0,0,0);
	selDriver.tmBookDate=time;

	selDriver.strCarKind=pCtrl->GetItemText(nHitItem,6);
	selDriver.strPhone=pCtrl->GetItemText(nHitItem,7);

}


void CSubListView::OnMenuitemCarmodify() 
{
	operation=2;
	CCarDlg dlg;
	dlg.DoModal();
	// TODO: Add your command handler code here
	
}

void CSubListView::OnMenuitemCardel() 
{
	operation=3;
	CCarDlg dlg;
	dlg.DoModal();
	// TODO: Add your command handler code here
	
}

void CSubListView::OnMenuitemCaradd() 
{
	operation=1;
	CCarDlg dlg;
	dlg.DoModal();
	// TODO: Add your command handler code here
	
}

void CSubListView::OnMenuitemDriveradd() 
{
	operation=1;
	CDriverDlg dlg;
	dlg.DoModal();
	// TODO: Add your command handler code here
	
}

void CSubListView::OnMenuitemDrivermodify() 
{
	operation=2;
	CDriverDlg dlg;
	dlg.DoModal();
	// TODO: Add your command handler code here
	
}

void CSubListView::OnMenuitemDriverdel() 
{
	operation=3;
	CDriverDlg dlg;
	dlg.DoModal();
	// TODO: Add your command handler code here
	
}

void CSubListView::ListCarDriver()
{
	CListCtrl* pList = &GetListCtrl();

	//清空列表
	pList->DeleteAllItems();
	pList->SetRedraw(FALSE);
	
	_variant_t Holder, strQuery;
    strQuery= "select * from [car-driver]";
	theApp.ADOExecute(theApp.m_pRs, strQuery);
    int iCount = theApp.m_pRs->GetRecordCount();
	if ( 0==iCount ) 
		return;
	theApp.m_pRs->MoveFirst();

	int i=0;
	while(!theApp.m_pRs->adoEOF)
	{
		Holder = theApp.m_pRs->GetCollect("Car_NO");
		if(Holder.vt!=VT_NULL)
			pList->InsertItem(i, (char*)(_bstr_t)Holder);

		Holder = theApp.m_pRs->GetCollect("Driver_NO");
		if(Holder.vt!=VT_NULL)
			pList->SetItemText(i,1, (char*)(_bstr_t)Holder);

		Holder = theApp.m_pRs->GetCollect("IsWork");
		if(Holder.vt!=VT_NULL)
			pList->SetItemText(i,2, Holder.iVal==1?"是":"否");		
	

		theApp.m_pRs->MoveNext();
		i++;
	}

	pList->SetRedraw(TRUE);	

}

void CSubListView::SelCarDriver()
{
		CListCtrl* pCtrl = &GetListCtrl();

	selCarDriver.CarNO=pCtrl->GetItemText(nHitItem,0);
	selCarDriver.DriverNO=pCtrl->GetItemText(nHitItem,1);
	selCarDriver.IsWork=pCtrl->GetItemText(nHitItem,2)=="是"?1:0;


}

void CSubListView::OnMenuitemCdadd() 
{
	operation=1;
	CCarDriverDlg dlg;
	dlg.DoModal();
	// TODO: Add your command handler code here
	
}

void CSubListView::OnMenuitemCdmodify() 
{	
	operation=2;
	CCarDriverDlg dlg;
	dlg.DoModal();

	

	// TODO: Add your command handler code here
	
}

void CSubListView::OnMenuitemCddel() 
{
	operation=3;
	CCarDriverDlg dlg;
	dlg.DoModal();
	// TODO: Add your command handler code here
	
}

void CSubListView::ListCarFee()
{
	CListCtrl* pList = &GetListCtrl();

	//清空列表
	pList->DeleteAllItems();
	pList->SetRedraw(FALSE);
	
	_variant_t Holder, strQuery;
    strQuery= "select * from [car-fee]";
	theApp.ADOExecute(theApp.m_pRs, strQuery);
    int iCount = theApp.m_pRs->GetRecordCount();
	if ( 0==iCount ) 
		return;
	theApp.m_pRs->MoveFirst();

	int i=0;
	while(!theApp.m_pRs->adoEOF)
	{
		Holder = theApp.m_pRs->GetCollect("Car_NO");
		if(Holder.vt!=VT_NULL)
			pList->InsertItem(i, (char*)(_bstr_t)Holder);

		Holder = theApp.m_pRs->GetCollect("Fee_NO");
		if(Holder.vt!=VT_NULL)
			pList->SetItemText(i,1, (char*)(_bstr_t)Holder);

		Holder = theApp.m_pRs->GetCollect("InDate");
		if(Holder.vt!=VT_NULL)
			pList->SetItemText(i,2, (char*)(_bstr_t)Holder);

		Holder = theApp.m_pRs->GetCollect("OutDate");
		if(Holder.vt!=VT_NULL)
			pList->SetItemText(i,3, (char*)(_bstr_t)Holder);

		theApp.m_pRs->MoveNext();
		i++;
	}

	pList->SetRedraw(TRUE);	

}

void CSubListView::ListDriverPunish()
{
	CListCtrl* pList = &GetListCtrl();

	//清空列表
	pList->DeleteAllItems();
	pList->SetRedraw(FALSE);
	
	_variant_t Holder, strQuery;
    strQuery= "select * from [driver-punish]";
	theApp.ADOExecute(theApp.m_pRs, strQuery);
    int iCount = theApp.m_pRs->GetRecordCount();
	if ( 0==iCount ) 
		return;
	theApp.m_pRs->MoveFirst();

	int i=0;
	while(!theApp.m_pRs->adoEOF)
	{
		Holder = theApp.m_pRs->GetCollect("Driver_NO");
		if(Holder.vt!=VT_NULL)
			pList->InsertItem(i, (char*)(_bstr_t)Holder);

		Holder = theApp.m_pRs->GetCollect("Punish_NO");
		if(Holder.vt!=VT_NULL)
			pList->SetItemText(i,1, (char*)(_bstr_t)Holder);

		Holder = theApp.m_pRs->GetCollect("HappenAddress");
		if(Holder.vt!=VT_NULL)
			pList->SetItemText(i,2, (char*)(_bstr_t)Holder);

		Holder = theApp.m_pRs->GetCollect("HappenDate");
		if(Holder.vt!=VT_NULL)
			pList->SetItemText(i,3, (char*)(_bstr_t)Holder);

		Holder = theApp.m_pRs->GetCollect("TreatState");
		if(Holder.vt!=VT_NULL)
			pList->SetItemText(i,4, Holder.iVal==1?"是":"否");
		
		Holder = theApp.m_pRs->GetCollect("OtherMessage");
		if(Holder.vt!=VT_NULL)
			pList->SetItemText(i,5, (char*)(_bstr_t)Holder);		
	

		theApp.m_pRs->MoveNext();
		i++;
	}

	pList->SetRedraw(TRUE);

}

void CSubListView::ListDriverAward()
{
	CListCtrl* pList = &GetListCtrl();

	//清空列表
	pList->DeleteAllItems();
	pList->SetRedraw(FALSE);
	
	_variant_t Holder, strQuery;
    strQuery= "select * from [driver-award]";
	theApp.ADOExecute(theApp.m_pRs, strQuery);
    int iCount = theApp.m_pRs->GetRecordCount();
	if ( 0==iCount ) 
		return;
	theApp.m_pRs->MoveFirst();

	int i=0;
	while(!theApp.m_pRs->adoEOF)
	{
		Holder = theApp.m_pRs->GetCollect("Driver_NO");
		if(Holder.vt!=VT_NULL)
			pList->InsertItem(i, (char*)(_bstr_t)Holder);

		Holder = theApp.m_pRs->GetCollect("Award_NO");
		if(Holder.vt!=VT_NULL)
			pList->SetItemText(i,1, (char*)(_bstr_t)Holder);

		Holder = theApp.m_pRs->GetCollect("Content");
		if(Holder.vt!=VT_NULL)
			pList->SetItemText(i,2, (char*)(_bstr_t)Holder);
		
		Holder = theApp.m_pRs->GetCollect("OtherMessage");
		if(Holder.vt!=VT_NULL)
			pList->SetItemText(i,3, (char*)(_bstr_t)Holder);		
	

		theApp.m_pRs->MoveNext();
		i++;
	}

	pList->SetRedraw(TRUE);


}

void CSubListView::ListPunish()
{
	CListCtrl* pList = &GetListCtrl();

	//清空列表
	pList->DeleteAllItems();
	pList->SetRedraw(FALSE);
	
	_variant_t Holder, strQuery;
    strQuery= "select * from punish";
	theApp.ADOExecute(theApp.m_pRs, strQuery);
    int iCount = theApp.m_pRs->GetRecordCount();
	if ( 0==iCount ) 
		return;
	theApp.m_pRs->MoveFirst();

	int i=0;
	while(!theApp.m_pRs->adoEOF)
	{
		Holder = theApp.m_pRs->GetCollect("Punish_NO");
		if(Holder.vt!=VT_NULL)
			pList->InsertItem(i, (char*)(_bstr_t)Holder);

		Holder = theApp.m_pRs->GetCollect("Punish_name");
		if(Holder.vt!=VT_NULL)
			pList->SetItemText(i,1, (char*)(_bstr_t)Holder);

		Holder = theApp.m_pRs->GetCollect("Punish_Admin");
		if(Holder.vt!=VT_NULL)
			pList->SetItemText(i,2, (char*)(_bstr_t)Holder);
		
		Holder = theApp.m_pRs->GetCollect("Punish_Money");
		if(Holder.vt!=VT_NULL)
			pList->SetItemText(i,3, (char*)(_bstr_t)Holder);

		
		Holder = theApp.m_pRs->GetCollect("Punish_Point");
		if(Holder.vt!=VT_NULL)
			pList->SetItemText(i,4, (char*)(_bstr_t)Holder);
		Holder = theApp.m_pRs->GetCollect("Punish_Book");
		if(Holder.vt!=VT_NULL)
			pList->SetItemText(i,5, Holder.iVal==1?"是":"否");

		theApp.m_pRs->MoveNext();
		i++;
	}

	pList->SetRedraw(TRUE);	


}

void CSubListView::ListFee()
{
	CListCtrl* pList = &GetListCtrl();

	//清空列表
	pList->DeleteAllItems();
	pList->SetRedraw(FALSE);
	
	_variant_t Holder, strQuery;
    strQuery= "select * from fee";
	theApp.ADOExecute(theApp.m_pRs, strQuery);
    int iCount = theApp.m_pRs->GetRecordCount();
	if ( 0==iCount ) 
		return;
	theApp.m_pRs->MoveFirst();

	int i=0;
	while(!theApp.m_pRs->adoEOF)
	{
		Holder = theApp.m_pRs->GetCollect("Fee_NO");
		if(Holder.vt!=VT_NULL)
			pList->InsertItem(i, (char*)(_bstr_t)Holder);

		Holder = theApp.m_pRs->GetCollect("Fee_Name");
		if(Holder.vt!=VT_NULL)
			pList->SetItemText(i,1, (char*)(_bstr_t)Holder);

		Holder = theApp.m_pRs->GetCollect("Fee_Admin");
		if(Holder.vt!=VT_NULL)
			pList->SetItemText(i,2, (char*)(_bstr_t)Holder);
		
		Holder = theApp.m_pRs->GetCollect("Fee_Money");
		if(Holder.vt!=VT_NULL)
			pList->SetItemText(i,3, (char*)(_bstr_t)Holder);


		theApp.m_pRs->MoveNext();
		i++;
	}

	pList->SetRedraw(TRUE);	


}

void CSubListView::SelCarFee()
{
	CListCtrl* pCtrl = &GetListCtrl();

	selCarFee.CarNO=pCtrl->GetItemText(nHitItem,0);
	selCarFee.FeeNO=pCtrl->GetItemText(nHitItem,1);

	CString strDate=pCtrl->GetItemText(nHitItem,2);
	long y,m,d;
	sscanf(strDate.GetBuffer(strDate.GetLength()),"%d-%d-%d",&y,&m,&d);
	if(y<1000)
		y+=2000;
	CTime time1(y,m,d,0,0,0);
	selCarFee.tmBegin=time1;

	strDate=pCtrl->GetItemText(nHitItem,3);
	sscanf(strDate.GetBuffer(strDate.GetLength()),"%d-%d-%d",&y,&m,&d);
	if(y<1000)
		y+=2000;
	CTime time2(y,m,d,0,0,0);
	selDriver.tmBookDate=time2;


}

void CSubListView::OnMenuitemCarfeeadd() 
{
	operation=1;
	CCarFeeDlg dlg;
	dlg.DoModal();
	// TODO: Add your command handler code here
	
}

void CSubListView::OnMenuitemCarfeemodify() 
{
	operation=2;
	CCarFeeDlg dlg;
	dlg.DoModal();
	// TODO: Add your command handler code here
	
}

void CSubListView::OnMenuitemCarfeedl() 
{
	operation=3;
	CCarFeeDlg dlg;
	dlg.DoModal();
	// TODO: Add your command handler code here
	
}

void CSubListView::OnMenuitemDriverlawadd() 
{
	operation=1;
	CDriverLawDlg dlg;
	dlg.DoModal();
	// TODO: Add your command handler code here
	
}

void CSubListView::OnMenuitemDriverlawmodify() 
{
	operation=2;
	CDriverLawDlg dlg;
	dlg.DoModal();
	// TODO: Add your command handler code here
	
}

void CSubListView::OnMenuitemDriverlawdel() 
{
	operation=3;
	CDriverLawDlg dlg;
	dlg.DoModal();
	// TODO: Add your command handler code here	
}

void CSubListView::SelDriverLaw()
{
	CListCtrl* pCtrl = &GetListCtrl();

	selDriverLaw.DriverNO=pCtrl->GetItemText(nHitItem,0);
	selDriverLaw.LawNO=pCtrl->GetItemText(nHitItem,1);
	selDriverLaw.Address=pCtrl->GetItemText(nHitItem,2);


	CString strDate=pCtrl->GetItemText(nHitItem,3);
	long y,m,d;
	sscanf(strDate.GetBuffer(strDate.GetLength()),"%d-%d-%d",&y,&m,&d);
	if(y<1000)
		y+=2000;
	CTime time(y,m,d,0,0,0);
	selDriverLaw.date=time;

	selDriverLaw.TreatState=pCtrl->GetItemText(nHitItem,4)=="是"?1:0;
	selDriverLaw.Memo=pCtrl->GetItemText(nHitItem,5);

}


void CSubListView::SelDriverAward()
{
	CListCtrl* pCtrl = &GetListCtrl();
	selDriverAward.DriverNO=pCtrl->GetItemText(nHitItem,0);
	selDriverAward.AwardNO=pCtrl->GetItemText(nHitItem,1);
	selDriverAward.Content=pCtrl->GetItemText(nHitItem,2);
	selDriverAward.Memo=pCtrl->GetItemText(nHitItem,3);

}

void CSubListView::OnMenuitemDriverawardadd() 
{
	operation=1;
	CDriverAwardDlg dlg;
	dlg.DoModal();
	// TODO: Add your command handler code here
	
}

void CSubListView::OnMenuitemDriverawardmodify() 
{
	operation=2;
	CDriverAwardDlg dlg;
	dlg.DoModal();
	// TODO: Add your command handler code here
	
}

void CSubListView::OnMenuitemDriverawarddel() 
{
	operation=3;
	CDriverAwardDlg dlg;
	dlg.DoModal();
	// TODO: Add your command handler code here
	
}

void CSubListView::SelFee()
{
	CListCtrl* pCtrl = &GetListCtrl();
	selFee.FeeNO=pCtrl->GetItemText(nHitItem,0);
	selFee.FeeName=pCtrl->GetItemText(nHitItem,1);
	selFee.FeeDepartment=pCtrl->GetItemText(nHitItem,2);
	selFee.FeeMoney=pCtrl->GetItemText(nHitItem,3);

}

void CSubListView::SelLaw()
{
	CListCtrl* pCtrl = &GetListCtrl();
	selLaw.LawNO=pCtrl->GetItemText(nHitItem,0);
	selLaw.LawName=pCtrl->GetItemText(nHitItem,1);
	selLaw.LawDepartment=pCtrl->GetItemText(nHitItem,2);
	selLaw.LawMoney=pCtrl->GetItemText(nHitItem,3);
	selLaw.LawPoint=pCtrl->GetItemText(nHitItem,4);
	selLaw.iIsBook=pCtrl->GetItemText(nHitItem,5)=="是"?1:0;

}

void CSubListView::OnMenuitemFeeadd() 
{
	operation=1;
	CFeeDlg dlg;
	dlg.DoModal();
	// TODO: Add your command handler code here
	
}

void CSubListView::OnMenuitemFeemodify() 
{
	operation=2;
	CFeeDlg dlg;
	dlg.DoModal();
	// TODO: Add your command handler code here
	
}

void CSubListView::OnMenuitemFeedel() 
{
	operation=3;
	CFeeDlg dlg;
	dlg.DoModal();
	// TODO: Add your command handler code here
	
}

void CSubListView::OnMenuitemLawadd() 
{
	operation=1;
	CLawDlg dlg;
	dlg.DoModal();
	// TODO: Add your command handler code here
	
}

void CSubListView::OnMenuitemLawmodify() 
{
	operation=2;
	CLawDlg dlg;
	dlg.DoModal();
	// TODO: Add your command handler code here
	
}

void CSubListView::OnMenuitemLawdel() 
{
	operation=3;
	CLawDlg dlg;
	dlg.DoModal();
	// TODO: Add your command handler code here
	
}
