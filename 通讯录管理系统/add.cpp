// add.cpp : implementation file
//

#include "stdafx.h"
#include "Page1.h"
#include "add.h"
#include<fstream.h>
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// Cadd dialog


Cadd::Cadd(CWnd* pParent /*=NULL*/)
	: CDialog(Cadd::IDD, pParent)
{
	//{{AFX_DATA_INIT(Cadd)
	m_edit = _T("");
	//}}AFX_DATA_INIT
}


void Cadd::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(Cadd)
	DDX_Text(pDX, IDC_EDIT1, m_edit);
	DDV_MaxChars(pDX, m_edit, 10);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(Cadd, CDialog)
	//{{AFX_MSG_MAP(Cadd)
	ON_WM_PAINT()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// Cadd message handlers

void Cadd::OnOK() 
{   
	fstream f("relation.dat",ios::in);
		if(!f)
			{
               	MessageBox("不能打开文件！！");
	            return;
			}
    UpdateData();
    int e=0;
	// TODO: Add extra validation here
	int i=0;
	while(!f.eof())
	{  
		f>>peo[i].b;
		if(strcmp(m_edit,peo[i].b)==0)
		{  
			e=1;
		    MessageBox("该关系已存在，请重新输入！");
		    break;
		}
	    i++;
	}
	f.close();
    if(e==1)
		return;
	fstream fin("relation.dat",ios::app);
		if(!fin)
			{
               	AfxMessageBox("不能打开文件！！");
	            return;
			}
	fin<<m_edit<<endl;
	fin.close();
	CDialog::OnOK();
}
void Cadd::OnCancel() 
{
	// TODO: Add extra cleanup here
	CDialog::OnCancel();
}

void Cadd::OnPaint() 
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
		//dc.DrawIcon(x, y, m_hIcon);
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
