// xiugaiDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Page1.h"
#include "xiugaiDlg.h"
#include "YNDlg.h"
#include<fstream.h>
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CxiugaiDlg dialog


CxiugaiDlg::CxiugaiDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CxiugaiDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CxiugaiDlg)
	m_CODE1 = _T("");
	m_CODE2 = _T("");
	m_CODE3 = _T("");
	//}}AFX_DATA_INIT
}


void CxiugaiDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CxiugaiDlg)
	DDX_Control(pDX, IDC_EDIT3, m_code3);
	DDX_Control(pDX, IDC_EDIT2, m_code2);
	DDX_Control(pDX, IDC_EDIT1, m_code1);
	DDX_Text(pDX, IDC_EDIT1, m_CODE1);
	DDV_MaxChars(pDX, m_CODE1, 12);
	DDX_Text(pDX, IDC_EDIT2, m_CODE2);
	DDV_MaxChars(pDX, m_CODE2, 12);
	DDX_Text(pDX, IDC_EDIT3, m_CODE3);
	DDV_MaxChars(pDX, m_CODE3, 12);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CxiugaiDlg, CDialog)
	//{{AFX_MSG_MAP(CxiugaiDlg)
	ON_WM_PAINT()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CxiugaiDlg message handlers

void CxiugaiDlg::OnOK() 
{
	// TODO: Add extra validation here

	 CYNDlg test;
     test.DoModal();
   	if(test.k==0)
		return;
	if(test.k==1)
	{
		UpdateData(TRUE);
	    fstream fout("code.dat",ios::in|ios::out);
		if(!fout)
		{
        	AfxMessageBox("不能打开文件！！");
	        return;
		}
        fout>>peo[0].CODE;
		fout.close();
		if(strlen(m_CODE1)==0||strlen(m_CODE2)==0||strlen(m_CODE3)==0)
		{
			 MessageBox("密码不能为空，请重新输入！");
		     m_code1.SetWindowText("");
			 m_code2.SetWindowText("");
             m_code3.SetWindowText("");
			 return;
		}
		if(strcmp(peo[0].CODE,m_CODE1)!=0)
		{
			 MessageBox("原密码输入有误!!/n请重新输入！");
             m_code1.SetWindowText("");
			 m_code2.SetWindowText("");
             m_code3.SetWindowText("");
			 return;
		}

		 if(strcmp(m_CODE2,m_CODE3)!=0)
		 {
			  MessageBox("两次输入密码不一致!!/n请重新输入！");
			  m_code1.SetWindowText("");
			  m_code2.SetWindowText("");
			  m_code3.SetWindowText("");
			  return;
		 }
         MessageBox("修改密码成功!!");
         fstream f1("code.dat",ios::trunc); 
	     if(!f1)
		 {
              AfxMessageBox("不能打开文件！！");
	          return;
		 }
         f1.close();
	     fstream f2("code.dat",ios::app); 
	     if(!f2)
		 {
              AfxMessageBox("不能打开文件！！");
	          return;
		 }
         f2<<m_CODE2<<endl;
	     f2.close();
		 CDialog::OnOK();
	}
}

void CxiugaiDlg::OnPaint() 
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
