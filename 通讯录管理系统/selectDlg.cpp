// selectDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Page1.h"
#include "selectDlg.h"
#include<fstream.h>
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CselectDlg dialog


CselectDlg::CselectDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CselectDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CselectDlg)
	m_address = _T("");
	m_relation1 = _T("");
	m_name2 = _T("");
	//}}AFX_DATA_INIT
}


void CselectDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CselectDlg)
	DDX_Control(pDX, IDC_LIST1, m_relation);
	DDX_Control(pDX, IDC_EDIT2, m_address1);
	DDX_Control(pDX, IDC_EDIT1, m_name1);
	DDX_Text(pDX, IDC_EDIT2, m_address);
	DDV_MaxChars(pDX, m_address, 20);
	DDX_LBString(pDX, IDC_LIST1, m_relation1);
	DDX_Text(pDX, IDC_EDIT1, m_name2);
	DDV_MaxChars(pDX, m_name2, 20);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CselectDlg, CDialog)
	//{{AFX_MSG_MAP(CselectDlg)
	ON_WM_CANCELMODE()
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_WM_PAINT()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CselectDlg message handlers

BOOL CselectDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	fstream f2("relation.dat",ios::in);
	if(!f2)
	{
         AfxMessageBox("不能打开文件！！");
	     return 0;
	}
	int i=0;
	while(!f2.eof())
	{   
		f2>>peo[i].b;
		i++;
	}
    f2.close();
	m_relation.AddString("家人");
	m_relation.AddString("朋友");
	m_relation.AddString("同学");
	m_relation.AddString("亲戚");
	m_relation.AddString("老师");
	m_relation.AddString("其他");
	for(int j=0;j<i-1;j++)
	{
        m_relation.AddString(peo[j].b);
	}

	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CselectDlg::OnCancelMode() 
{
	CDialog::OnCancelMode();
	
	// TODO: Add your message handler code here
}

void CselectDlg::OnOK() 
{
	// TODO: Add extra validation here

	UpdateData();
	fstream  fin("tang3.dat",ios::in);
	if(!fin)
	{
        AfxMessageBox("不能打开文件！！");
    	return ;
	}

	fstream f2("select1.dat",ios::trunc); 
	if(!f2)
	{
        AfxMessageBox("不能打开文件！！");
    	return ;
	}
    f2.close();
	if(strlen(m_name2)!=0&&strlen(m_address)==0&&strlen(m_relation1)==0)
	{
	
		int i=0;
		while(!fin.eof()) 
		{
			fin>>peo[i].name>>peo[i].sex>>peo[i].tel>>peo[i].address>>peo[i].month>>peo[i].day >>peo[i].qq>>peo[i].relationship>>peo[i].beizhu;
			if(!strcmp(m_name2,peo[i].name))
			{  
				fstream  f1("select1.dat",ios::app);
				if(!f1)
				{
                     AfxMessageBox("不能打开文件！！");
                  	 return ;
				}
            	f1<<peo[i].name<<"       "<<peo[i].sex<<"        "<<peo[i].tel<<"       "<<peo[i].address<<"       "<<peo[i].month<<"       "<<peo[i].day <<"       "<<peo[i].qq<<"       "<<peo[i].relationship<<"           "<<peo[i].beizhu<<endl;
	        	f1.close();
			}
			i++;
		}
       fin.close();
	}
    if(strlen(m_name2)!=0&&strlen(m_address)!=0&&strlen(m_relation1)==0)
	{
		int i=0;
		while(!fin.eof()) 
		{
			fin>>peo[i].name>>peo[i].sex>>peo[i].tel>>peo[i].address>>peo[i].month>>peo[i].day >>peo[i].qq>>peo[i].relationship>>peo[i].beizhu;
       	    if(!strcmp(m_name2,peo[i].name)&&!strcmp(m_address,peo[i].address))
			{  
       	        fstream  f1("select1.dat",ios::app);
                if(!f1)
				{
                    AfxMessageBox("不能打开文件！！");
                   	return ;
				}
               	f1<<peo[i].name<<"       "<<peo[i].sex<<"        "<<peo[i].tel<<"       "<<peo[i].address<<"       "<<peo[i].month<<"       "<<peo[i].day <<"       "<<peo[i].qq<<"       "<<peo[i].relationship<<"           "<<peo[i].beizhu<<endl;	   	f1.close();
          	}
			i++;
		}
        fin.close();
	}

    if(strlen(m_name2)==0&&strlen(m_address)!=0&&strlen(m_relation1)!=0)
	
	{
		int i=0;
		while(!fin.eof()) 
		{
			fin>>peo[i].name>>peo[i].sex>>peo[i].tel>>peo[i].address>>peo[i].month>>peo[i].day >>peo[i].qq>>peo[i].relationship>>peo[i].beizhu;
 
			if(!strcmp(m_address,peo[i].address)&&!strcmp(m_relation1,peo[i].relationship))
			{  
	            fstream  f1("select1.dat",ios::app);
                if(!f2)
				{
                     AfxMessageBox("不能打开文件！！");
                    	return ;
				}
            	f1<<peo[i].name<<"       "<<peo[i].sex<<"        "<<peo[i].tel<<"       "<<peo[i].address<<"       "<<peo[i].month<<"       "<<peo[i].day <<"       "<<peo[i].qq<<"       "<<peo[i].relationship<<"           "<<peo[i].beizhu<<endl;	   	f1.close();
	        	f1.close();
          	}
			i++;
		}
        fin.close();
   
	}

    if(strlen(m_name2)!=0&&strlen(m_address)!=0&&strlen(m_relation1)!=0)
	
	{
		int i=0;
	

        while(!fin.eof()) 
		{
			fin>>peo[i].name>>peo[i].sex>>peo[i].tel>>peo[i].address>>peo[i].month>>peo[i].day >>peo[i].qq>>peo[i].relationship>>peo[i].beizhu;
			if(!strcmp(m_address,peo[i].address)&&!strcmp(m_name2,peo[i].name)&&!strcmp(m_relation1,peo[i].relationship))
			{  
				fstream  f1("select1.dat",ios::app);
				if(!f1)
				{
                     AfxMessageBox("不能打开文件！！");
    	             return ;
				}
	            f1<<peo[i].name<<"       "<<peo[i].sex<<"        "<<peo[i].tel<<"       "<<peo[i].address<<"       "<<peo[i].month<<"       "<<peo[i].day <<"       "<<peo[i].qq<<"       "<<peo[i].relationship<<"           "<<peo[i].beizhu<<endl;	   	f1.close();
	   	        f1.close();
			}
			i++;
		}
        fin.close();
	}
    if(strlen(m_name2)!=0&&strlen(m_address)==0&&strlen(m_relation1)!=0)
	
	{
		int i=0;
	

         while(!fin.eof()) 
		 {
			 fin>>peo[i].name>>peo[i].sex>>peo[i].tel>>peo[i].address>>peo[i].month>>peo[i].day >>peo[i].qq>>peo[i].relationship>>peo[i].beizhu;
			 if(!strcmp(m_name2,peo[i].name)&&!strcmp(m_relation1,peo[i].relationship))
			 {  
	             fstream f1("select1.dat",ios::app);
                 if(!f1)
				 {
                      AfxMessageBox("不能打开文件！！");
                    	return ;
				 }
	             f1<<peo[i].name<<"       "<<peo[i].sex<<"        "<<peo[i].tel<<"       "<<peo[i].address<<"       "<<peo[i].month<<"       "<<peo[i].day <<"       "<<peo[i].qq<<"       "<<peo[i].relationship<<"           "<<peo[i].beizhu<<endl;	   	f1.close();
	   	         f1.close();
			 }
			 i++;
		 }
         fin.close();
	}
    if(strlen(m_name2)==0&&strlen(m_address)!=0&&strlen(m_relation1)==0)
	
	{
		int i=0;
	

        while(!fin.eof()) 
		{
			fin>>peo[i].name>>peo[i].sex>>peo[i].tel>>peo[i].address>>peo[i].month>>peo[i].day >>peo[i].qq>>peo[i].relationship>>peo[i].beizhu;
			if(!strcmp(m_address,peo[i].address))
			{  
	            fstream  f1("select1.dat",ios::app);
                if(!f1)
				{
                      AfxMessageBox("不能打开文件！！");
                     	return ;
				}
	            f1<<peo[i].name<<"       "<<peo[i].sex<<"        "<<peo[i].tel<<"       "<<peo[i].address<<"       "<<peo[i].month<<"       "<<peo[i].day <<"       "<<peo[i].qq<<"       "<<peo[i].relationship<<"           "<<peo[i].beizhu<<endl;	   	f1.close();
	   	        f1.close();
          	}
			i++;
		}
        fin.close();
	}
    if(strlen(m_name2)==0&&strlen(m_address)==0&&strlen(m_relation1)!=0)
	
	{
		int i=0;
	

        while(!fin.eof()) 
		{
			fin>>peo[i].name>>peo[i].sex>>peo[i].tel>>peo[i].address>>peo[i].month>>peo[i].day >>peo[i].qq>>peo[i].relationship>>peo[i].beizhu;
			if(!strcmp(m_relation1,peo[i].relationship))
			{ 
				fstream  f1("select1.dat",ios::app);
				if(!f1)
				{
                     AfxMessageBox("不能打开文件！！");
    	             return ;
				}
				f1<<peo[i].name<<"       "<<peo[i].sex<<"        "<<peo[i].tel<<"       "<<peo[i].address<<"       "<<peo[i].month<<"       "<<peo[i].day <<"       "<<peo[i].qq<<"       "<<peo[i].relationship<<"           "<<peo[i].beizhu<<endl;	   	f1.close();
	        	f1.close();
          	}
			i++;
		}
        fin.close();
	}
    if(strlen(m_name2)==0&&strlen(m_address)==0&&strlen(m_relation1)==0)
	{
         MessageBox("查询条件不能为空，请选择条件！！");
	     return;
	}
	CDialog::OnOK();
}



void CselectDlg::OnButton1() 
{
    this->PostMessage(WM_CLOSE);  	
}

void CselectDlg::OnPaint() 
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
