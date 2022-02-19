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
		 MessageBox("����ѡ�񡱲���Ϊ�գ�");
		 return;
	}
    if(strlen(fileName)==0)
	{
        MessageBox("�ļ�������Ϊ�գ�");
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
               	AfxMessageBox("���ܴ��ļ�����");
	            return;
			}
	    
	            fstream f(fileName,ios::trunc) ;
				if(!f)
			{
               	AfxMessageBox("���ܴ��ļ�����");
	            return;
			}
	       	f.close();
	        fstream ftxt(fileName, ios::out|ios::app) ;	// д��ʽ���ı��ļ�
            if(!ftxt)
			{
               	AfxMessageBox("���ܴ��ļ�����");
	            return;
			}
            int i=0;
	        ftxt<<"����"<<"     "<<"�Ա�"<<"   "<<"�绰����"<<"      "<<"��ַ"<<"       "<<"������"<<"       "<<"������"<<"      "<<" QQ"<<"     "<<"��ϵ"<<"     "<<"��ע"<<endl;           
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
		     MessageBox("�ı��ļ��ѽ���!�������");
		  }
		  if(m_select.GetCurSel()==1)
		  { 
			  fstream  fin("tang3.dat",ios::in);
              fstream f(fileName , ios::trunc) ;
	          f.close();
	          fstream ftxt(fileName, ios::out|ios::app) ;	// д��ʽ���ı��ļ�
              int i=0;
			  ftxt<<"����"<<"     "<<"�Ա�"<<"   "<<"�绰����"<<"      "<<"��ַ"<<"       "<<"������"<<"       "<<"������"<<"      "<<" QQ"<<"     "<<"��ϵ"<<"     "<<"��ע"<<endl;           
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
			  MessageBox("�ı��ļ��ѽ���!�������");
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
