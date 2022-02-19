// txtDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Page1.h"
#include "txtDlg.h"
#include<fstream.h>
#include "YNDlg.h"
extern int p;
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CtxtDlg dialog


CtxtDlg::CtxtDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CtxtDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CtxtDlg)
	m_name1 = _T("");
	//}}AFX_DATA_INIT
}


void CtxtDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CtxtDlg)
	DDX_Control(pDX, IDC_COMBO1, m_select);
	DDX_Text(pDX, IDC_EDIT1, m_name1);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CtxtDlg, CDialog)
	//{{AFX_MSG_MAP(CtxtDlg)

	ON_WM_PAINT()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CtxtDlg message handlers

void CtxtDlg::OnOK() 
{
	// TODO: Add extra validation here
	char fileName[30];
	UpdateData(TRUE);
	strcpy(fileName,m_name1.GetBuffer(m_name1.GetLength()));
    char b[5]=".txt";
    strcat(fileName,b);
    if(m_select.GetCurSel()==-1)
	{
		 MessageBox("“请选择”不能为空！");
		 return;
	}
    if(strlen(fileName)==0)
	{
        MessageBox("文件名不能为空！");
     	 return;
	}
	CYNDlg test;
    test.DoModal();	
	if(test.k==0)
		return;
	if(test.k==1)
	{
          if(m_select.GetCurSel()==0)
		  { 

            	fstream  fin("select1.dat",ios::in);
				if(!fin)
			{
               	AfxMessageBox("不能打开文件！！");
	            return;
			}
	    
	            fstream f(fileName,ios::trunc) ;
				if(!f)
			{
               	AfxMessageBox("不能打开文件！！");
	            return;
			}
	       	f.close();
	        fstream ftxt(fileName, ios::out|ios::app) ;	// 写方式打开文本文件
            if(!ftxt)
			{
               	AfxMessageBox("不能打开文件！！");
	            return;
			}
            int i=0;
	        ftxt<<"姓名"<<"     "<<"性别"<<"   "<<"电话号码"<<"      "<<"地址"<<"       "<<"出生月"<<"       "<<"出生日"<<"      "<<" QQ"<<"     "<<"关系"<<"     "<<"备注"<<endl;           
            while((!fin.eof())) 
			{
				fin>>peo[i].name>>peo[i].sex>>peo[i].tel>>peo[i].address>>peo[i].month>>peo[i].day >>peo[i].qq>>peo[i].relationship>>peo[i].beizhu;
		        i++;
			 }
             int j=i;
	         for(i=0;i<j-1;i++)
			  {
				 ftxt<<peo[i].name<<"       "<<peo[i].sex<<"         "<<peo[i].tel<<"       "<<peo[i].address<<"       "<<peo[i].month<<"       "<<peo[i].day <<"       "<<peo[i].qq<<"      "<<peo[i].relationship<<"         "<<peo[i].beizhu<<endl;	
              }
			 fin.close();
             ftxt.close() ;
		     MessageBox("文本文件已建立!请浏览！");
		  }
		  if(m_select.GetCurSel()==1)
		  { 
			  fstream  fin("tang3.dat",ios::in);
              fstream f(fileName , ios::trunc) ;
	          f.close();
	          fstream ftxt(fileName, ios::out|ios::app) ;	// 写方式打开文本文件
              int i=0;
			  ftxt<<"姓名"<<"     "<<"性别"<<"   "<<"电话号码"<<"      "<<"地址"<<"       "<<"出生月"<<"       "<<"出生日"<<"      "<<" QQ"<<"     "<<"关系"<<"     "<<"备注"<<endl;           
           	  while((!fin.eof())) 
			  {
				  fin>>peo[i].name>>peo[i].sex>>peo[i].tel>>peo[i].address>>peo[i].month>>peo[i].day >>peo[i].qq>>peo[i].relationship>>peo[i].beizhu;
	              i++;
			  }
              int j=i;
	          for(i=0;i<j-1;i++)
			  {
		           ftxt<<peo[i].name<<"       "<<peo[i].sex<<"          "<<peo[i].tel<<"       "<<peo[i].address<<"       "<<peo[i].month<<"       "<<peo[i].day <<"       "<<peo[i].qq<<"       "<<peo[i].relationship<<"        "<<peo[i].beizhu<<endl;	
			  }
			  fin.close();
              ftxt.close() ;
			  MessageBox("文本文件已建立!请浏览！");
		  }
	} 
	CDialog::OnOK();
}



void CtxtDlg::OnPaint() 
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
