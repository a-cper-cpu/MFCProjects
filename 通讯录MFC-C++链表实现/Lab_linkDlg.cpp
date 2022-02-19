// Lab_linkDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Lab_link.h"
#include "Lab_linkDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

//基本设置

int i=0;

//数据域
struct LData
{

	CString Name;    //姓名
	CString College;   //就读大学
	CString Grade;   //班级
	CString Fields;   //专业
	CString Address;   //家庭住址
	CString Phone;   //家庭联系电话
	CString Post;   //邮编
	CString CellPhone;   //本人联系电话


};

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{

	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLab_linkDlg dialog

CLab_linkDlg::CLab_linkDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CLab_linkDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CLab_linkDlg)
	m_Name = _T("");
	m_College = _T("");
	m_Grade = _T("");
	m_Fields = _T("");
	m_Address = _T("");
	m_Phone = _T("");
	m_Post = _T("");
	m_CellPhone = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CLab_linkDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CLab_linkDlg)
	DDX_Control(pDX, IDC_MODIFY, m_Modify);
	DDX_Control(pDX, IDC_SEARCHED, m_Searched);
	DDX_Control(pDX, IDC_LIST1, m_List);
	DDX_Control(pDX, IDC_DELETED, m_Deleted);
	DDX_Control(pDX, IDC_ADDED, m_Added);
	DDX_Text(pDX, IDC_NAME, m_Name);
	DDX_Text(pDX, IDC_COLLEGE, m_College);
	DDX_Text(pDX, IDC_GRADE, m_Grade);
	DDX_Text(pDX, IDC_FIELDS, m_Fields);
	DDX_Text(pDX, IDC_ADDRESS, m_Address);
	DDX_Text(pDX, IDC_PHONE, m_Phone);
	DDX_Text(pDX, IDC_POST, m_Post);
	DDX_Text(pDX, IDC_CELLPHONE, m_CellPhone);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CLab_linkDlg, CDialog)
	//{{AFX_MSG_MAP(CLab_linkDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_ADDED, OnAdded)
	ON_BN_CLICKED(IDC_DELETED, OnDeleted)
	ON_BN_CLICKED(IDC_SEARCHED, OnSearched)
	ON_BN_CLICKED(IDC_MODIFY, OnModify)
	ON_NOTIFY(NM_CLICK, IDC_LIST1, OnClickList1)
	ON_EN_CHANGE(IDC_NAME, OnChangeName)
	ON_EN_CHANGE(IDC_COLLEGE, OnChangeCollege)
	ON_EN_CHANGE(IDC_GRADE, OnChangeGrade)
	ON_EN_CHANGE(IDC_FIELDS, OnChangeFields)
	ON_EN_CHANGE(IDC_ADDRESS, OnChangeAddress)
	ON_EN_CHANGE(IDC_PHONE, OnChangePhone)
	ON_EN_CHANGE(IDC_POST, OnChangePost)
	ON_EN_CHANGE(IDC_CELLPHONE, OnChangeCellphone)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLab_linkDlg message handlers

BOOL CLab_linkDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

    //初始化列表控件

	m_List.InsertColumn(0,"姓名",LVCFMT_LEFT,130,0);
	m_List.InsertColumn(1,"就读大学名称",LVCFMT_LEFT,130,1);
	m_List.InsertColumn(2,"班级名",LVCFMT_LEFT,130,2);
	m_List.InsertColumn(3,"专业",LVCFMT_LEFT,130,3);
	m_List.InsertColumn(4,"家庭住址",LVCFMT_LEFT,130,4);
	m_List.InsertColumn(5,"家庭联系电话",LVCFMT_LEFT,130,5);
	m_List.InsertColumn(6,"邮编",LVCFMT_LEFT,130,6);
	m_List.InsertColumn(7,"本人联系电话",LVCFMT_LEFT,130,7);




	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CLab_linkDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CLab_linkDlg::OnPaint() 
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
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CLab_linkDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

//添加函数：将编辑框中的内容添加到链表，并在列表控件中显示

void CLab_linkDlg::OnAdded() 
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	if(m_Name.IsEmpty()||m_College.IsEmpty()||m_Grade.IsEmpty()||m_Fields.IsEmpty()||m_Address.IsEmpty()||m_Phone.IsEmpty()||m_Post.IsEmpty()||m_CellPhone.IsEmpty())

	{
		AfxMessageBox("信息不能为空哦！");
		Setlist();
		return;
	}
	else 
	{	
		m_List.InsertItem(i,m_Name);
    	m_List.SetItemText(i,1,m_College);
 	    m_List.SetItemText(i,2,m_Grade);
	    m_List.SetItemText(i,3,m_Fields); 
	    m_List.SetItemText(i,4,m_Address); 
     	m_List.SetItemText(i,5,m_Phone); 
	    m_List.SetItemText(i,6,m_Post);
	    m_List.SetItemText(i,7,m_CellPhone);

		LData* m_data=new LData;

		m_data->Name=m_Name;
	    m_data->College=m_College;
	    m_data->Grade=m_Grade;
	    m_data->Fields= m_Fields;
	    m_data->Address=m_Address;
	    m_data->Phone=m_Phone;
        m_data->Post=m_Post;
	    m_data->CellPhone=m_CellPhone;



		m_Link.AddHead(m_data);
		Setlist();
		UpdateData(false);
	}
}

//删除函数：用于删除指定位置的数据

void CLab_linkDlg::OnDeleted() 
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	CString str;
	POSITION pos=m_Link.GetHeadPosition();
	if(m_Link.GetCount()==1)
	{
		m_Link.RemoveAll();	
		Display();
		Setlist();
	}
	for(int j=0;j<m_Link.GetCount();j++)
	{	

		LData* m_data=(LData*)m_Link.GetAt(pos);
		if(m_data->Name==m_Name||m_data->College==m_College||m_data->Grade==m_Grade||m_data->Fields==m_Fields||m_data->Address==m_Address||m_data->Phone==m_Phone||m_data->Post==m_Post||m_data->CellPhone==m_CellPhone)
		{
			str="删除的用户为：\n姓名: "+m_data->Name+" 现就读大学: "+m_data->College+" 班级: "+m_data->Grade+
				"\n专业: "+m_data->Fields+" 家庭住址: "+m_data->Address+" 家庭联系电话: "+m_data->Phone+
				"\n邮编: "+m_data->Post+" 本人联系电话: "+m_data->CellPhone;
			AfxMessageBox(str);
			m_Link.RemoveAt(pos);
			Display();
			Setlist();
			break;
		}
		m_data=(LData*)m_Link.GetNext(pos);
	}
	UpdateData(false);
}

//查找函数：查找指定用户信息

void CLab_linkDlg::OnSearched() 
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	CString str;
	POSITION pos=m_Link.GetHeadPosition();	
	for(int j=0;j<m_Link.GetCount();j++)
	{	
		LData* m_data=(LData*)m_Link.GetNext(pos);
		if(m_data->Name==m_Name||m_data->College==m_College||m_data->Grade==m_Grade||m_data->Fields==m_Fields||m_data->Address==m_Address||m_data->Phone==m_Phone||m_data->Post==m_Post||m_data->CellPhone==m_CellPhone)

		{
			str="姓名: "+m_data->Name+" 现就读大学: "+m_data->College+" 班级: "+m_data->Grade+
				"\n专业: "+m_data->Fields+" 家庭住址: "+m_data->Address+" 家庭联系电话: "+m_data->Phone+
				"\n邮编: "+m_data->Post+" 本人联系电话: "+m_data->CellPhone;

			AfxMessageBox(str);
			Setlist();
			break;
		}
	}
	UpdateData(false);
}

//复位函数：用于清空编辑框

void CLab_linkDlg::Setlist()
{

	m_Name="";
	m_College="";
	m_Grade="";
	m_Fields="";
	m_Address="";
	m_Phone="";
	m_Post="";
	m_CellPhone="";

}

//修改函数：用于修改指定位置数据

void CLab_linkDlg::OnModify() 
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	CString str;
	POSITION pos=m_Link.GetHeadPosition();
	for(int j=0;j<m_Link.GetCount();j++)
	{	

		LData* m_data=(LData*)m_Link.GetAt(pos);
		if(m_data->Name==m_Name||m_data->College==m_College||m_data->Grade==m_Grade||m_data->Fields==m_Fields||m_data->Address==m_Address||m_data->Phone==m_Phone||m_data->Post==m_Post||m_data->CellPhone==m_CellPhone)
		{
		m_Link.RemoveAt(pos);
		LData* m_data=new LData;

		m_data->Name=m_Name;
	    m_data->College=m_College;
	    m_data->Grade=m_Grade;
	    m_data->Fields= m_Fields;
	    m_data->Address=m_Address;
	    m_data->Phone=m_Phone;
        m_data->Post=m_Post;
	    m_data->CellPhone=m_CellPhone;
        m_Link.AddHead(m_data);
		Display();
		Setlist();
		break;
		}
		else
		{	
			str="无此人信息";
			AfxMessageBox(str);
		}


		m_data=(LData*)m_Link.GetNext(pos);
	}
	UpdateData(false);

}










//显示函数:用于重新显示数据在列表控件中

void CLab_linkDlg::Display()
{
	m_List.DeleteAllItems();
	if(!m_Link.IsEmpty())
	{
		POSITION pos=m_Link.GetHeadPosition();
		for(int j=0;j<m_Link.GetCount();j++)
		{	
			LData* m_data=(LData*)m_Link.GetNext(pos);

		m_List.InsertItem(j,m_data->Name);
    	m_List.SetItemText(j,1,m_data->College);
 	    m_List.SetItemText(j,2,m_data->Grade);
	    m_List.SetItemText(j,3,m_data->Fields); 
	    m_List.SetItemText(j,4,m_data->Address); 
     	m_List.SetItemText(j,5,m_data->Phone); 
	    m_List.SetItemText(j,6,m_data->Post);
	    m_List.SetItemText(j,7,m_data->CellPhone);

		}
	}

}

void CLab_linkDlg::OnClickList1(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	
	*pResult = 0;
}

void CLab_linkDlg::OnChangeName() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	
}

void CLab_linkDlg::OnChangeCollege() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	
}

void CLab_linkDlg::OnChangeGrade() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	
}

void CLab_linkDlg::OnChangeFields() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	
}

void CLab_linkDlg::OnChangeAddress() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	
}

void CLab_linkDlg::OnChangePhone() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	
}

void CLab_linkDlg::OnChangePost() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	
}

void CLab_linkDlg::OnChangeCellphone() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	
}
