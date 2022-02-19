// bianji.cpp : implementation file
//

#include "stdafx.h"
#include "YNDlg.h"
#include "Page1.h"
#include "bianji.h"
#include "liebiao.h"
#include<fstream.h>
#include"add.h"
extern int w;
extern int p;
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// Cbianji dialog


Cbianji::Cbianji(CWnd* pParent /*=NULL*/)
	: CDialog(Cbianji::IDD, pParent)
{
	//{{AFX_DATA_INIT(Cbianji)
	m_name = _T("");
	m_tel = _T("");
	m_address = _T("");
	m_qq = _T("");
	m_month = _T("");
	m_day = _T("");
	m_relation1 = _T("");
	m_beizhu = _T("");
	//}}AFX_DATA_INIT
}


void Cbianji::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(Cbianji)
	DDX_Control(pDX, IDC_EDIT9, m_beizhu1);
	DDX_Control(pDX, IDC_COMBO1, m_sex);
	DDX_Control(pDX, IDC_BUTTON5, m_odd);
	DDX_Control(pDX, IDC_BUTTON2, m_add1);
	DDX_Control(pDX, IDC_BUTTON1, m_alter1);
	DDX_Control(pDX, IDC_LIST1, m_relation);
	DDX_Control(pDX, IDC_EDIT6, m_address1);
	DDX_Control(pDX, IDC_EDIT5, m_day1);
	DDX_Control(pDX, IDC_EDIT4, m_month1);
	DDX_Control(pDX, IDC_EDIT3, m_qq1);
	DDX_Control(pDX, IDC_EDIT2, m_tel1);
	DDX_Control(pDX, IDC_EDIT1, m_name1);
	DDX_Text(pDX, IDC_EDIT1, m_name);
	DDV_MaxChars(pDX, m_name, 20);
	DDX_Text(pDX, IDC_EDIT2, m_tel);
	DDV_MaxChars(pDX, m_tel, 15);
	DDX_Text(pDX, IDC_EDIT6, m_address);
	DDV_MaxChars(pDX, m_address, 20);
	DDX_Text(pDX, IDC_EDIT3, m_qq);
	DDX_Text(pDX, IDC_EDIT4, m_month);
	DDV_MaxChars(pDX, m_month, 2);
	DDX_Text(pDX, IDC_EDIT5, m_day);
	DDV_MaxChars(pDX, m_day, 2);
	DDX_LBString(pDX, IDC_LIST1, m_relation1);
	DDX_Text(pDX, IDC_EDIT9, m_beizhu);
	DDV_MaxChars(pDX, m_beizhu, 50);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(Cbianji, CDialog)
	//{{AFX_MSG_MAP(Cbianji)
	ON_BN_CLICKED(IDC_BUTTON3, Onrelation)
	ON_BN_CLICKED(IDC_BUTTON2, Onadd)
	ON_BN_CLICKED(IDC_BUTTON5, Ondisplay)
	ON_BN_CLICKED(IDC_BUTTON1, Onalter1)
	ON_WM_CANCELMODE()

	ON_WM_PAINT()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// Cbianji message handlers


void Cbianji::Onrelation() 
{
	// TODO: Add your control notification handler code here
	Cadd test;
    if(IDOK==test.DoModal())
	{
		m_relation.AddString(test.m_edit);
	}
}
void Cbianji::Onadd() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
    int d=0;
	char tel[15];
	strcpy( tel,m_tel);
	for(int i=0;tel[i]!=0;i++)
	{
		if(tel[i]>57||tel[i]<48)
		{  
			AfxMessageBox("电话号码只能是数字，请重新输入！！");
			m_tel1.SetWindowText("");
	    	d=1;
		    break;
		}
	}
	if(d==1)
		return;
	d=0;
    char qq[15];
    strcpy( qq,m_qq);
	for(int j=0;qq[j]!=0;j++)
	{
		if(qq[j]>57||qq[j]<48)
		{  	
			AfxMessageBox("QQ只能是数字，请重新输入！！");
		    m_qq1.SetWindowText("");
			d=1;
		    break;
		}
	}
    if(d==1)
		return;
	if(strlen(m_relation1)==0)
	{
		AfxMessageBox("关系不能为空，请选择！");
		return;
	}
	if(strlen(m_name)==0)
	{
		AfxMessageBox("姓名不能为空，请输入！");
	    return;
	}
    if(strlen(m_tel)==0)
	{
		AfxMessageBox("电话号码不能为空，请输入！");
       	return;
	}
	if(strlen(m_month)!=0&&strlen(m_day)!=0)
	{
		int month=atoi(m_month);
        int day=atoi(m_day);
		if(((month==4||month==6||month==9||month==11)&&day==31)||(month==2&&(day==30||day==31))||month>12||month<1||day>31||day<1)
		{   
			AfxMessageBox("出生日月输入错误，请重新输入！！");
			m_day1.SetWindowText("");
            m_month1.SetWindowText("");
			return;
		}
	 }
	 char a[5]="男";
	 char b[5]="女";
	 char sex[5];
	 if(m_sex.GetCurSel()==-1)
	 {
        AfxMessageBox("性别必须要选择！！");
		return;
	 }
	 if(m_sex.GetCurSel()==0)
	 {
        strcpy( sex,a);
	 }
	  if(m_sex.GetCurSel()==1)
	 {
        strcpy( sex,b);
	 }
     fstream fin("tang3.dat",ios::in|ios::out);
     if(!fin)
	 {
		 AfxMessageBox("不能打开文件");
         return;
	 }
     i=0;
	 while((!fin.eof())) 
	{ 
		fin>>peo[i].name>>peo[i].sex>>peo[i].tel>>peo[i].address>>peo[i].month>>peo[i].day >>peo[i].qq>>peo[i].relationship>>peo[i].beizhu;
	    i++;
	}
	int	r=i; j=0; 
    for(i=0;i<r;i++)
	{
		if(strcmp(peo[i].name,m_name)==0) 
		{ 
			AfxMessageBox("该名字已存在，请重新输入!!");
            m_name1.SetWindowText("");
			j=1;
			break;
		}
	}
	if(j==1)
		return;
    fin.close();
	if(strlen(m_address)==0)
	{
		m_address="未知";
	}
   	if(strlen(m_month)==0)
	{
		m_month="未知";
	}
   	if(strlen(m_day)==0)
	{	
		m_day="未知";
	}
   	if(strlen(m_qq)==0)
	{
		m_qq="未知";
	}
   	if(strlen(m_beizhu)==0)
	{
		m_beizhu="无";
	}
	CYNDlg test;
   	test.DoModal();
	if(test.k==0)
		return;
	if(test.k==1)
	{
		if(j==0)
		{
			p=p+1;
	 	   	MessageBox("添加成功!!");
            fstream fout("tang3.dat",ios::app|ios::in|ios::out);
           if(!fout)
			{
               	AfxMessageBox("不能打开文件！！");
	            return;
			}
           	fout<<m_name<<"       "<<sex<<"          "<<m_tel<<"       "<<m_address<<"     "<<m_month<<"  "<<m_day<<"      "<<m_qq<<"    "<<m_relation1<<"      "<<m_beizhu<<endl;
           	fout.close();
		    m_name1.SetWindowText("");
	        m_tel1.SetWindowText("");
	        m_address1.SetWindowText("");
	        m_month1.SetWindowText("");
	        m_day1.SetWindowText("");
	        m_qq1.SetWindowText("");
	        m_beizhu1.SetWindowText("");   
		}
	}
}
void Cbianji::Ondisplay() 
{
	// TODO: Add your control notification handler code here
	fstream fin("tang3.dat",ios::in|ios::out);
	if(!fin)
	{
	AfxMessageBox("不能打开文件！！");
	return;
	}
    int i=0;
	while((!fin.eof())) 
	{
		fin>>peo[i].name>>peo[i].sex>>peo[i].tel>>peo[i].address>>peo[i].month>>peo[i].day >>peo[i].qq>>peo[i].relationship>>peo[i].beizhu;
		i++;
	}
	m_name=peo[w].name;
    m_tel=peo[w].tel;
    m_address=peo[w].address;
    m_month=peo[w].month;
    m_day=peo[w].day;
    m_qq=peo[w].qq;
	m_beizhu=peo[w].beizhu;
    UpdateData(FALSE);
}

void Cbianji::Onalter1() 
{
	UpdateData(TRUE);
	int d=0;
    char tel[15]; 
    strcpy( tel,m_tel);
	for(int i=0;tel[i]!=0;i++)
	{
		if(tel[i]>57||tel[i]<48)
		{  
			AfxMessageBox("电话号码只能是数字，请重新输入！！");
			m_tel1.SetWindowText("");
	    	d=1;
		    break;
    	}
	}
	if(d==1)
		return;
	d=0;
    char qq[15];
    strcpy( qq,m_qq);
	for(int j=0;qq[j]!=0;j++)
	{
		if(qq[j]>57||qq[j]<48)
		{
			AfxMessageBox("QQ只能是数字，请重新输入！！");
		    m_qq1.SetWindowText("");
			d=1;
		    break;
		}
	}
    if(d==1)
		return;
	if(strlen(m_relation1)==0)
	{
		AfxMessageBox("关系不能为空，请选择！");
		return;
	}
	if(strlen(m_name)==0)
	{
		AfxMessageBox("姓名不能为空，请输入！");
		return;
	}
	if(strlen(m_month)!=0&&strlen(m_day)!=0)
	{
		 int month=atoi(m_month);
         int day=atoi(m_day);
		 if(((month==4||month==6||month==9||month==11)&&day==31)||(month==2&&(day==30||day==31))||month>12||month<1||day>31||day<1)
		 {   
			 AfxMessageBox("出生日月输入错误，请重新输入！！");
             m_day1.SetWindowText("");
			 m_month1.SetWindowText("");
			 return;
		 }
	 }
	 char a[5]="男";
	 char b[5]="女";
	 char sex[5];
	 if(m_sex.GetCurSel()==-1)
	 {
        AfxMessageBox("性别必须要选择！！");
		return;
	 }
	 if(m_sex.GetCurSel()==0)
	 {
        strcpy( sex,a);
	 }
	  if(m_sex.GetCurSel()==1)
	 {
        strcpy( sex,b);
	 }
     fstream fin("tang3.dat",ios::in|ios::out);
     if(!fin)
	 {
        AfxMessageBox("不能打开文件");
	 }
     i=0;

	while((!fin.eof())) 
	{ 
		fin>>peo[i].name>>peo[i].sex>>peo[i].tel>>peo[i].address>>peo[i].month>>peo[i].day >>peo[i].qq>>peo[i].relationship>>peo[i].beizhu;
		i++;
	}
	int	r=i; j=0; 
	for(i=0;i<r;i++)
	{	
		if(strcmp(peo[i].name,m_name)==0&&i!=w) 
		{ 
			AfxMessageBox("该名字已存在，请重新输入!!");
            m_name1.SetWindowText("");
			j=1;
			break;
		 }
	}
	if(j==1)
		return;
	fin.close();
	if(strlen(m_address)==0)
	{
		m_address="未知";
	}
	if(strlen(m_month)==0)
	{
		m_month="未知";
	}
	if(strlen(m_day)==0)
	{
		m_day="未知";
	}
	if(strlen(m_qq)==0)
	{
		m_qq="未知";
	}
	if(strlen(m_beizhu)==0)
	{
		m_beizhu="无";
	}
	// TODO: Add your control notification handler code here
   
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
		fstream f2("tang3.dat",ios::app); 
		if(!f2)
			{
               	AfxMessageBox("不能打开文件！！");
	            return;
			}
		for( j=0;j<w;j++) 
		{
			f2<<peo[j].name<<"       "<<peo[j].sex<<"           "<<peo[j].tel<<"       "<<peo[j].address<<"       "<<peo[j].month<<"       "<<peo[j].day <<"       "<<peo[j].qq<<"       "<<peo[j].relationship<<"           "<<peo[j].beizhu<<endl;
		}
		f2<<m_name<<"       "<<sex<<"       "<<m_tel<<"       "<<m_address<<"    "<<m_month<<"    "<<m_day<<"     "<<m_qq<<"     "<<m_relation1<<"     "<<m_beizhu<<endl;
        for(j=w+1;j<r-1;j++)
		{
			f2<<peo[j].name<<"       "<<peo[j].sex<<"       "<<peo[j].tel<<"       "<<peo[j].address<<"       "<<peo[j].month<<"       "<<peo[j].day <<"       "<<peo[j].qq<<"       "<<peo[j].relationship<<"           "<<peo[j].beizhu<<endl;
		}	
		f2.close();
		AfxMessageBox("修改成功！！");
	    m_name1.SetWindowText("");
	    m_tel1.SetWindowText("");
	    m_address1.SetWindowText("");
	    m_month1.SetWindowText("");
	    m_day1.SetWindowText("");
	    m_qq1.SetWindowText("");
	    m_beizhu1.SetWindowText("");   
	}
}

BOOL Cbianji::OnInitDialog() 
{
	CDialog::OnInitDialog();
    m_odd.EnableWindow( FALSE);
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
	m_relation.AddString("同学");m_relation.AddString("亲戚");
	m_relation.AddString("老师");
	m_relation.AddString("其他");
	for(int j=0;j<i-1;j++)
	{
		m_relation.AddString(peo[j].b);
	}
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void Cbianji::OnCancelMode() 
{
	CDialog::OnCancelMode();
	// TODO: Add your message handler code here
}


void Cbianji::OnPaint() 
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
