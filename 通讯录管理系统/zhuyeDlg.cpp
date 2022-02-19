// zhuyeDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Page1.h"
#include "YNDlg.h"
#include "zhuyeDlg.h"
#include<fstream.h>
#include"Mmsystem.h"
int w=0;

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


/////////////////////////////////////////////////////////////////////////////
// CzhuyeDlg dialog


CzhuyeDlg::CzhuyeDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CzhuyeDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CzhuyeDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}

void CzhuyeDlg::DoDataExchange(CDataExchange* pDX)
{

		
	//{{AFX_DATA_MAP(CzhuyeDlg)
	DDX_Control(pDX, IDC_BUTTON3, m_home);
	DDX_Control(pDX, IDC_BUTTON2, m_add);
	DDX_Control(pDX, IDC_BUTTON1, m_alter);
	DDX_Control(pDX, IDC_TAB1, m_tabctrl);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CzhuyeDlg, CDialog)
	//{{AFX_MSG_MAP(CzhuyeDlg)
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB1, OnSelchangeTab1)
	ON_WM_CAPTURECHANGED()
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	ON_BN_CLICKED(IDC_BUTTON3, OnButton3)
	ON_BN_CLICKED(IDC_BUTTON1, Onalter)
	ON_WM_PAINT()
	ON_WM_CANCELMODE()
	ON_BN_CLICKED(IDC_MUSIC, OnMusic)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CzhuyeDlg message handlers

void CzhuyeDlg::OnSelchangeTab1(NMHDR* pNMHDR, LRESULT* pResult) 
{
	CRect r;
	m_tabctrl.GetClientRect (&r);
	switch(m_tabctrl.GetCurSel())
	{
	case 0:
		m_mm1.SetWindowPos (NULL,10,30,r.right -20,r.bottom -40,SWP_SHOWWINDOW);
		m_mm2.SetWindowPos (NULL,10,30,r.right -20,r.bottom -40,SWP_HIDEWINDOW ); 
		m_home.EnableWindow( FALSE);
		m_add.EnableWindow();
		m_alter.EnableWindow();
		break;
	case 1:
		m_mm1.SetWindowPos (NULL,10,30,r.right -20,r.bottom -40,SWP_HIDEWINDOW);
		m_mm2.SetWindowPos (NULL,10,30,r.right -20,r.bottom -40,SWP_SHOWWINDOW ); 
		m_mm2.m_alter1.EnableWindow(FALSE);
		m_mm2.m_add1.EnableWindow();
		m_home.EnableWindow( );
		m_add.EnableWindow(FALSE);
		m_alter.EnableWindow(FALSE );
		m_mm2.m_odd.EnableWindow( FALSE);
		break;
	}
	*pResult = 0;
}




BOOL CzhuyeDlg::OnInitDialog() 
{
	PlaySound((LPCTSTR)IDR_MUSIC, AfxGetInstanceHandle(), SND_RESOURCE | SND_ASYNC| SND_LOOP);
	CDialog::OnInitDialog();
	TCITEM item;
item.mask = TCIF_TEXT;
item.pszText = "浏览记录";
m_tabctrl.InsertItem (0,&item);
item.pszText ="操作记录";
m_tabctrl.InsertItem (1,&item);
m_mm1.Create (IDD_DIALOG4,&m_tabctrl);
m_mm2.Create (IDD_DIALOG2,&m_tabctrl);
CRect r;
m_tabctrl.GetClientRect (&r);
m_mm1.SetWindowPos (NULL,10,30,r.right -20,r.bottom -40,SWP_SHOWWINDOW);
m_mm2.SetWindowPos (NULL,10,30,r.right -20,r.bottom -40,SWP_HIDEWINDOW ); 
	// TODO: Add extra initialization here

		m_add.EnableWindow( );
	m_home.EnableWindow(FALSE );

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CzhuyeDlg::OnCaptureChanged(CWnd *pWnd) 
{
	// TODO: Add your message handler code here
	
	CDialog::OnCaptureChanged(pWnd);
}



void CzhuyeDlg::OnButton2() 
{
	// TODO: Add your control notification handler code here
		CRect r;
m_tabctrl.GetClientRect (&r);
m_mm2.SetWindowPos (NULL,10,30,r.right -20,r.bottom -40,SWP_SHOWWINDOW);
m_mm1.SetWindowPos (NULL,10,30,r.right -20,r.bottom -40,SWP_HIDEWINDOW ); 
m_home.EnableWindow( );
m_mm2.m_add1.EnableWindow( );
m_add.EnableWindow(FALSE );
m_mm2.m_alter1.EnableWindow(FALSE );
m_alter.EnableWindow(FALSE );
}

void CzhuyeDlg::OnButton3() 
{
	m_add.EnableWindow();
m_alter.EnableWindow( );
m_home.EnableWindow( FALSE);
m_mm2.m_alter1.EnableWindow( FALSE );
	// TODO: Add your control notification handler code here
		CRect r;
m_tabctrl.GetClientRect (&r);
m_mm1.SetWindowPos (NULL,10,30,r.right -20,r.bottom -40,SWP_SHOWWINDOW);
m_mm2.SetWindowPos (NULL,10,30,r.right -20,r.bottom -40,SWP_HIDEWINDOW ); 
m_mm1.m_List.DeleteAllItems() ;    
	   m_mm1.m_List.SetRedraw(FALSE);
      //更新内容
      m_mm1.m_List.SetRedraw(TRUE);
     m_mm1.m_List.Invalidate();
       m_mm1.m_List.UpdateWindow();
    fstream f("tang3.dat",ios::in);
	if(!f)
	{
    	AfxMessageBox("不能打开文件");
	}
    int i=0;

	while((!f.eof())) 
	{ 
		f>>peo[i].name>>peo[i].sex>>peo[i].tel>>peo[i].address>>peo[i].month>>peo[i].day >>peo[i].qq>>peo[i].relationship>>peo[i].beizhu;			
		i++;
	}
	int	k=i; 
	for(i=0;i<k-1;i++)
	{
			 int nRow = m_mm1.m_List.InsertItem(i, peo[i].name);//插入行
         m_mm1.m_List.SetItemText(nRow, 1, peo[i].sex);
	      m_mm1.m_List.SetItemText(nRow, 2, peo[i].tel);
		      m_mm1.m_List.SetItemText(nRow, 3, peo[i].address);
     m_mm1.m_List.SetItemText(nRow, 4,peo[i].month) ;//设置数据
   
      m_mm1.m_List.SetItemText(nRow, 5, peo[i].day);
    
      m_mm1.m_List.SetItemText(nRow, 6, peo[i].qq);
	    
  m_mm1.m_List.SetItemText(nRow, 7, peo[i].relationship);

    m_mm1.m_List.SetItemText(nRow, 8, peo[i].beizhu);
	}	
}



void CzhuyeDlg::Onalter() 
{
// TODO: Add your control notification handler code here
      CString str;
      for(int i=0; i<m_mm1.m_List.GetItemCount(); i++)
      {
           if(m_mm1. m_List.GetItemState(i, LVIS_SELECTED) == LVIS_SELECTED )
		   {
			   w=i;
			   break;
		   }
	  }
	  if(i==m_mm1.m_List.GetItemCount())
		{
           AfxMessageBox("没有选择哪一行，请先进行选择！！");
		  return;
		}
   
	
		   CRect r;
m_tabctrl.GetClientRect (&r);
m_mm2.SetWindowPos (NULL,10,30,r.right -20,r.bottom -40,SWP_SHOWWINDOW);
m_mm1.SetWindowPos (NULL,10,30,r.right -20,r.bottom -40,SWP_HIDEWINDOW ); 
m_mm2.m_alter1.EnableWindow( );
m_mm2.m_add1.EnableWindow(FALSE);
m_home.EnableWindow( );
m_add.EnableWindow(FALSE);
m_alter.EnableWindow(FALSE );
m_mm2.m_odd.EnableWindow( ); 
 


}

void CzhuyeDlg::OnOK() 
{
	// TODO: Add extra validation here
    CYNDlg test;
    test.DoModal();	
    if(test.k==0)
		return;
	if(test.k==1)
	{
		CDialog::OnCancel();
	}
}

void CzhuyeDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
//		dc.DrawIcon(x, y, m_hIcon);
	}
    else
    {
	   CRect rect;
	   CPaintDC dc(this);
	   GetClientRect(rect);
	   dc.FillSolidRect(rect,RGB(100,100,200)); 
	   CDialog::OnPaint();
    }
}


bool m_bFlag=1;
void CzhuyeDlg::OnMusic() 
{
	if(m_bFlag==1)
	{	
		PlaySound(NULL,NULL,0);
	
	}
    else
	{
		PlaySound((LPCTSTR)IDR_MUSIC, AfxGetInstanceHandle(), SND_RESOURCE | SND_ASYNC| SND_LOOP);
	}
	m_bFlag=!m_bFlag;
	CString str;
	if(GetDlgItemText(IDC_MUSIC,str),str=="打开音乐")
	{
		SetDlgItemText(IDC_MUSIC,"关闭音乐");
	}
	else
	{
		SetDlgItemText(IDC_MUSIC,"打开音乐");
	}	
}
