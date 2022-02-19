// moreDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Page1.h"
#include "moreDlg.h"
#include "txtDlg.h"
#include<istream.h>
#include<fstream.h>
#include"YNDlg.h"
extern int p;	
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CmoreDlg dialog


CmoreDlg::CmoreDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CmoreDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CmoreDlg)
	m_vol = 0;
	//}}AFX_DATA_INIT
}


void CmoreDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CmoreDlg)
	DDX_Text(pDX, IDC_EDIT1, m_vol);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CmoreDlg, CDialog)
	//{{AFX_MSG_MAP(CmoreDlg)
	ON_WM_CANCELMODE()
	ON_BN_CLICKED(IDC_BUTTON1, Oncreatetxt)
	ON_WM_PAINT()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CmoreDlg message handlers

BOOL CmoreDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	m_vol=p;
    UpdateData(FALSE);
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CmoreDlg::OnCancelMode() 
{
	CDialog::OnCancelMode();
	
	// TODO: Add your message handler code here
}



void CmoreDlg::OnOK() 
{
	// TODO: Add extra validation here
    fstream fin("tang3.dat",ios::in);
	fstream f("select1.dat",ios::trunc);
	f.close();
    fstream ftxt("select1.dat",ios::app);
    time_t t=time(NULL);
	tm*pt=localtime(&t);
	int peomonth=0;int peoday=0;int i=0;
	int thisyear,thismonth,thisday;
	thisyear=1900+pt->tm_year;
	thismonth=pt->tm_mon+1;
	thisday=pt->tm_mday;
	int  runyear=0;
	if(thisyear%4==0&&thisyear%100!=0)
	{
		runyear=1;
	}
	int found=0;
	while(!fin.eof()) 
	{
        fin>>peo[i].name>>peo[i].sex>>peo[i].tel>>peo[i].address>>peo[i].month>>peo[i].day >>peo[i].qq>>peo[i].relationship>>peo[i].beizhu;	 // 把记录写入文本文件:          
   		peoday=atoi(peo[i].day);
        peomonth= atoi(peo[i].month);
		if((thismonth==peomonth)&&(peoday-thisday>=0)&&(peoday-thisday<=7))
		{
			found=1;
			ftxt<<peo[i].name<<"       "<<peo[i].sex<<"    "<<peo[i].tel<<"       "<<peo[i].address<<"       "<<peo[i].month<<"       "<<peo[i].day <<"       "<<peo[i].qq<<"       "<<peo[i].relationship<<"       "<<peo[i].beizhu<<endl;
		}
		if(peomonth==thismonth+1)
		{
			if(thismonth==2)
			{
				if(runyear==1)
				{
					if(29-thisday+peoday<=7)
					{
						found=1;
						ftxt<<peo[i].name<<"       "<<peo[i].sex<<"    "<<peo[i].tel<<"       "<<peo[i].address<<"       "<<peo[i].month<<"       "<<peo[i].day <<"       "<<peo[i].qq<<"       "<<peo[i].relationship<<"       "<<peo[i].beizhu<<endl;
					}
				}
				else
				{
					if(28-thisday+peoday<=7)
					{
						found=1;
						ftxt<<peo[i].name<<"       "<<peo[i].sex<<"    "<<peo[i].tel<<"       "<<peo[i].address<<"       "<<peo[i].month<<"       "<<peo[i].day <<"       "<<peo[i].qq<<"       "<<peo[i].relationship<<"       "<<peo[i].beizhu<<endl;
					}
				}
			}
	    	else
			{
			    if(31-thisday+peoday<=7)
				{
				    found=1;
					ftxt<<peo[i].name<<"       "<<peo[i].sex<<"    "<<peo[i].tel<<"       "<<peo[i].address<<"       "<<peo[i].month<<"       "<<peo[i].day <<"       "<<peo[i].qq<<"       "<<peo[i].relationship<<"       "<<peo[i].beizhu<<endl;
				}
			}
		}
	   	if((thismonth==12)&&(peomonth==1)&&(31-thisday+peoday<=7))
		{
		    found=1;
			ftxt<<peo[i].name<<"       "<<peo[i].sex<<"    "<<peo[i].tel<<"       "<<peo[i].address<<"       "<<peo[i].month<<"       "<<peo[i].day <<"       "<<peo[i].qq<<"       "<<peo[i].relationship<<"       "<<peo[i].beizhu<<endl;
		}
		i++;
	}
    if(found==0)
	{
	    AfxMessageBox("最近七天，没有人过生日！");
	}
	fin.close();	
	CDialog::OnOK();
}





void CmoreDlg::OnCancel() 
{
	// TODO: Add extra cleanup here
	CDialog::OnCancel();
}

void CmoreDlg::Oncreatetxt() 
{
	// TODO: Add your control notification handler code here

	 this->PostMessage(WM_CLOSE); 
	 CtxtDlg test;
     test.DoModal();
	
}

void CmoreDlg::OnPaint() 
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
	}
    else
	{
  		CRect rect;
        CPaintDC dc(this);
        GetClientRect(rect);
        dc.FillSolidRect(rect,RGB(100,100,200));  
        CDialog::OnPaint();
	}
	
	// TODO: Add your message handler code here
	
	// Do not call CDialog::OnPaint() for painting messages
}
