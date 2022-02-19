// liebiao.cpp : implementation file
//

#include "stdafx.h"
#include "YNDlg.h"
//#include "selectDlg.h"
#include "Page1.h"
#include "liebiao.h"
#include<fstream.h>
#include"moreDlg.h"
extern int p;
	
#include"selectDlg.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// Cliebiao dialog


Cliebiao::Cliebiao(CWnd* pParent /*=NULL*/)
	: CDialog(Cliebiao::IDD, pParent)
{
	//{{AFX_DATA_INIT(Cliebiao)
	//}}AFX_DATA_INIT
}


void Cliebiao::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	
   
	//{{AFX_DATA_MAP(Cliebiao)
	DDX_Control(pDX, IDC_LIST1, m_List);  
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(Cliebiao, CDialog)
	//{{AFX_MSG_MAP(Cliebiao)
	ON_WM_CANCELMODE()
	ON_BN_CLICKED(IDCANCEL, Ondelete)
	ON_BN_CLICKED(IDC_BUTTON1, Onnew)
	ON_BN_CLICKED(IDOK, Onselect1)
	ON_BN_CLICKED(IDC_BUTTON2, Onmore)
	ON_BN_CLICKED(IDC_BUTTON3, Onclear)
	ON_NOTIFY(NM_CLICK, IDC_LIST1, OnClickList1)
	ON_WM_PAINT()
	ON_BN_CLICKED(IDC_BUTTON4, OnButton4)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// Cliebiao message handlers

BOOL Cliebiao::OnInitDialog() 
{
	CDialog::OnInitDialog();
	m_List.InsertColumn (0,"姓名");
	m_List.InsertColumn (1,"性别");
    m_List.InsertColumn (2,"电话号码");
    m_List.InsertColumn (3,"地址");
    m_List.InsertColumn(4,"出生月");
    m_List.InsertColumn (5,"出生日");
    m_List.InsertColumn (6,"QQ");
    m_List.InsertColumn (7,"关系");
   	m_List.InsertColumn (8,"备注");
    RECT rect ;
    m_List.GetClientRect (&rect);
    int width=rect.right -rect.left ;
    m_List.SetColumnWidth (0,2*width/10);
    m_List.SetColumnWidth (1,1*width/10);
    m_List.SetColumnWidth (2,3*width/10);
    m_List.SetColumnWidth (3,4*width/10);
    m_List.SetColumnWidth (4,2*width/10);
    m_List.SetColumnWidth (5,2*width/10);
    m_List.SetColumnWidth (6,3*width/10);
    m_List.SetColumnWidth (7,2*width/10);
    m_List.SetColumnWidth (8,5*width/10);
    m_List.SetExtendedStyle (LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES);

   //设置颜色
   m_List.SetBkColor(RGB(0,200,162));
   m_List.SetTextBkColor (RGB(0,200,162));
   fstream f("tang3.dat",ios::in|ios::out);
    int i=0;
	while((!f.eof())) 
	{ 
		f>>peo[i].name>>peo[i].sex>>peo[i].tel>>peo[i].address>>peo[i].month>>peo[i].day >>peo[i].qq>>peo[i].relationship>>peo[i].beizhu;
		i++;
	}
	int r=i-1;
	for(i=0;i<r;i++)
	 {
		int nRow = m_List.InsertItem(i, peo[i].name);//插入行
		m_List.SetItemText(nRow, 1, peo[i].sex);
	    m_List.SetItemText(nRow, 2, peo[i].tel);
		m_List.SetItemText(nRow, 3, peo[i].address);
        m_List.SetItemText(nRow, 4,peo[i].month) ;//设置数据
        m_List.SetItemText(nRow, 5, peo[i].day);
        m_List.SetItemText(nRow, 6, peo[i].qq);
	    m_List.SetItemText(nRow, 7, peo[i].relationship);
        m_List.SetItemText(nRow, 8, peo[i].beizhu);
	}

	// TODO: Add extra initialization here
	
	return TRUE;  
	// return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void Cliebiao::OnCancelMode() 
{
	CDialog::OnCancelMode();
	
	// TODO: Add your message handler code here
	
}

void Cliebiao::Ondelete() 
{
	int y=0;
        CString str;
        for(int i=0; i<m_List.GetItemCount(); i++)
		{
            if( m_List.GetItemState(i, LVIS_SELECTED) == LVIS_SELECTED&&i<p )
            {   
				CYNDlg test;
   	            test.DoModal();
	            if(test.k==0)
    	            return;
                   if(test.k==1)
				   {
						m_List.DeleteItem(i);
						fstream fin("tang3.dat",ios::in|ios::out);
						int m=0;
						while((!fin.eof())) 
						{ 
							fin>>peo[m].name>>peo[m].sex>>peo[m].tel>>peo[m].address>>peo[m].month>>peo[m].day >>peo[m].qq>>peo[m].relationship>>peo[m].beizhu;
						    m++;
						}
						fin.close();
				     	fstream f1("tang3.dat",ios::trunc); 
					    f1.close(); 
				    	fstream f2("tang3.dat",ios::app); 
                    	for(int j=0;j<m-1;j++) 
						{
				        	if(j!=i)
							{  
					         	f2<<peo[j].name<<"       "<<peo[j].sex<<"       "<<peo[j].tel<<"       "<<peo[j].address<<"       "<<peo[j].month<<"       "<<peo[j].day <<"       "<<peo[j].qq<<"       "<<peo[j].relationship<<"       "<<peo[j].beizhu<<endl;
							}
						}
				    	f2.close();
                    	p=p-1;
				    	y=1;
	                    MessageBox("删除成功！");
				    	break;
				   }	
			}
		}
		if(y==0)
		{
             AfxMessageBox("请先选择要删除的消息!");
		  
		}
}
void Cliebiao::Onnew() 
{
      m_List.DeleteAllItems() ;    
	  m_List.SetRedraw(FALSE);
      m_List.SetRedraw(TRUE);
      m_List.Invalidate();
      m_List.UpdateWindow();
      fstream f("tang3.dat",ios::in|ios::out);

	if(!f)
	{
	     AfxMessageBox("不能打开文件");
           	return;
	}
    int i=0;

	while((!f.eof())) 
	{ 
      	f>>peo[i].name>>peo[i].sex>>peo[i].tel>>peo[i].address>>peo[i].month>>peo[i].day >>peo[i].qq>>peo[i].relationship>>peo[i].beizhu;
        i++;
	}
	int	r=i; 
	for(i=0;i<r-1;i++)
	 {
	     int nRow = m_List.InsertItem(i, peo[i].name);//插入行
		 m_List.SetItemText(nRow, 1, peo[i].sex);
	     m_List.SetItemText(nRow, 2, peo[i].tel);
		 m_List.SetItemText(nRow, 3, peo[i].address);
         m_List.SetItemText(nRow, 4,peo[i].month) ;//设置数据
         m_List.SetItemText(nRow, 5, peo[i].day);
         m_List.SetItemText(nRow, 6, peo[i].qq);
	     m_List.SetItemText(nRow, 7, peo[i].relationship);
         m_List.SetItemText(nRow, 8, peo[i].beizhu);
	 }	
}

void Cliebiao::Onselect1() 
{
	// TODO: Add your control notification handler code here
	CselectDlg test;
	if(IDOK==test.DoModal())
	{
		m_List.DeleteAllItems() ;    
	   	m_List.SetRedraw(FALSE);
        m_List.SetRedraw(TRUE);
        m_List.Invalidate();
        m_List.UpdateWindow();
		fstream  f("select1.dat",ios::in);
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
	    int	r=i; 
	    for(i=0;i<r-1;i++)
		{
			int nRow = m_List.InsertItem(i, peo[i].name);//插入行
		    m_List.SetItemText(nRow, 1, peo[i].sex);
	        m_List.SetItemText(nRow, 2, peo[i].tel);
		    m_List.SetItemText(nRow, 3, peo[i].address);
            m_List.SetItemText(nRow, 4,peo[i].month) ;//设置数据
            m_List.SetItemText(nRow, 5, peo[i].day);
            m_List.SetItemText(nRow, 6, peo[i].qq);
	        m_List.SetItemText(nRow, 7, peo[i].relationship);
            m_List.SetItemText(nRow, 8, peo[i].beizhu);
		}	
	}
}

void Cliebiao::Onmore() 
{
	// TODO: Add your control notification handler code here
	CmoreDlg test;
    if(IDOK==test.DoModal())
	{
		m_List.DeleteAllItems() ;    
	   	m_List.SetRedraw(FALSE);
      	m_List.SetRedraw(TRUE);
        m_List.Invalidate();
        m_List.UpdateWindow();
        fstream  f("select1.dat",ios::in);
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
		int	r=i; 
		for(i=0;i<r-1;i++)
		{
			int nRow = m_List.InsertItem(i, peo[i].name);//插入行
		    m_List.SetItemText(nRow, 1, peo[i].sex);
	        m_List.SetItemText(nRow, 2, peo[i].tel);
		    m_List.SetItemText(nRow, 3, peo[i].address);
            m_List.SetItemText(nRow, 4,peo[i].month) ;//设置数据
            m_List.SetItemText(nRow, 5, peo[i].day);
            m_List.SetItemText(nRow, 6, peo[i].qq);
	        m_List.SetItemText(nRow, 7, peo[i].relationship);
            m_List.SetItemText(nRow, 8, peo[i].beizhu);
		}	
	}
}

void Cliebiao::Onclear() 
{
    CYNDlg test;
   	test.DoModal();
	if(test.k==0)
    	return;
	if(test.k==1)
	{
		fstream f1("tang3.dat",ios::trunc); 
		if(!f1)
			{
               	AfxMessageBox("不能打开文件！！");
	            return;
			}
    	f1.close();
		fstream f2("select1.dat",ios::trunc); 
		if(!f2)
			{
               	AfxMessageBox("不能打开文件！！");
	            return;
			}
       f1.close();
       m_List.DeleteAllItems() ;    
	   m_List.SetRedraw(FALSE);
       m_List.SetRedraw(TRUE);
       m_List.Invalidate();
       m_List.UpdateWindow(); 
       p=0;	
	}
}

void Cliebiao::OnClickList1(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	  CString str;
      for(int i=0; i<m_List.GetItemCount(); i++)
      {
           if( m_List.GetItemState(i, LVIS_SELECTED) == LVIS_SELECTED )
           {
                str.Format(_T("选中了第%d行,请进行操作！"), i+1);
           }
      }
	  *pResult = 0;
}

void Cliebiao::OnPaint() 
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

void Cliebiao::OnButton4() 
{
	// TODO: Add your control notification handler code here
	CYNDlg test;
   	test.DoModal();
	if(test.k==0)
    	return;
	if(test.k==1)
	{
		fstream fin("tang3.dat",ios::in);
		if(!fin )
			{
               	AfxMessageBox("不能打开文件！！");
	            return;
			}
        int    i=0;
	    while((!fin.eof())) 
		{ 
	    	fin>>peo[i].name>>peo[i].sex>>peo[i].tel>>peo[i].address>>peo[i].month>>peo[i].day >>peo[i].qq>>peo[i].relationship>>peo[i].beizhu;
			i++;
		}
        fin.close();
        int j=i;
        fstream fa("select1.dat",ios::in);
	    if(!fa )
		{
           	AfxMessageBox("不能打开文件！！");
	        return;
		}

        i=0;
		while((!fa.eof())) 
		{ 
	    	fa>>peo1[i].name>>peo1[i].sex>>peo1[i].tel>>peo1[i].address>>peo1[i].month>>peo1[i].day >>peo1[i].qq>>peo1[i].relationship>>peo1[i].beizhu;
			i++;
		}
    	int m=i;
		p=p-(m-1);
        fa.close();
        fstream f3("select1.dat",ios::trunc); 
		if(!f3)
		{
           	AfxMessageBox("不能打开文件！！");
            return;
		}
		f3.close();
		fstream f1("tang3.dat",ios::trunc); 
		if(!f1)
		{
           	AfxMessageBox("不能打开文件！！");
          return;
		}

		f1.close(); 
	    fstream f2("tang3.dat",ios::app);
		if(!f2)
		{
           	AfxMessageBox("不能打开文件！！");
          return;
		}
		for(i=0;i<j-1;i++)
		{
			int n=0;
            for(int k=0;k<m-1;k++)
			{
 		    	if(strcmp(peo[i].name,peo1[k].name)==0)
				{
                    n=1;
				}
			}
		    if(n==0) 
			f2<<peo[i].name<<"          "<<peo[i].sex<<"       "<<peo[i].tel<<"       "<<peo[i].address<<"     "<<peo[i].month<<"     "<<peo[i].day <<"     "<<peo[i].qq<<"       "<<peo[i].relationship<<"       "<<peo[i].beizhu<<endl;
		}
        f2.close();
        m_List.DeleteAllItems();    
	    m_List.SetRedraw(FALSE);
        //更新内容
        m_List.SetRedraw(TRUE);
        m_List.Invalidate();
        m_List.UpdateWindow(); 
        fstream f("tang3.dat",ios::in);
		if(!f)
		{
           	AfxMessageBox("不能打开文件！！");
            return;
		}
		if(!f)
		{
			MessageBox("不能打开文件");
           	return;
		}
        i=0;
		while((!f.eof())) 
		{ 
        	f>>peo[i].name>>peo[i].sex>>peo[i].tel>>peo[i].address>>peo[i].month>>peo[i].day >>peo[i].qq>>peo[i].relationship>>peo[i].beizhu;
            i++;
		}
	    int	r=i; 
    	for(i=0;i<r-1;i++)
		{
	        int nRow = m_List.InsertItem(i, peo[i].name);//插入行
		    m_List.SetItemText(nRow, 1, peo[i].sex);
	        m_List.SetItemText(nRow, 2, peo[i].tel);
		    m_List.SetItemText(nRow, 3, peo[i].address);
            m_List.SetItemText(nRow, 4,peo[i].month) ;//设置数据
            m_List.SetItemText(nRow, 5, peo[i].day);
            m_List.SetItemText(nRow, 6, peo[i].qq);
	        m_List.SetItemText(nRow, 7, peo[i].relationship);
			m_List.SetItemText(nRow, 8, peo[i].beizhu);
		}		
	}
}
