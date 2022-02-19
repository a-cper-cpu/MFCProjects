// AddressBookView.cpp : implementation of the CAddressBookView class
//

#include "stdafx.h"
#include "AddressBook.h"
#include "Person.h"
#include "AddressBookDoc.h"
#include "AddressBookView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAddressBookView

IMPLEMENT_DYNCREATE(CAddressBookView, CFormView)

BEGIN_MESSAGE_MAP(CAddressBookView, CFormView)
	//{{AFX_MSG_MAP(CAddressBookView)
	ON_EN_CHANGE(IDC_EDIT_NAME, OnChangeEditName)
	ON_BN_CLICKED(IDC_BUTTON_ADD, OnButtonAdd)
	ON_BN_CLICKED(IDC_BUTTON_DELETE, OnButtonDelete)
	ON_BN_CLICKED(IDC_BUTTON_PREVIOUS, OnButtonPrevious)
	ON_BN_CLICKED(IDC_BUTTON_NEXT, OnButtonNext)
	ON_EN_CHANGE(IDC_EDIT_PHONE, OnChangeEditPhone)
	ON_EN_CHANGE(IDC_EDIT_COMPANY, OnChangeEditCompany)
	ON_EN_CHANGE(IDC_EDIT_EMAIL, OnChangeEditEmail)
	ON_BN_CLICKED(IDC_CHECK_MODIFY, OnCheckModify)
	ON_BN_CLICKED(IDC_BUTTON_CLEAR, OnButtonClear)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAddressBookView construction/destruction

CAddressBookView::CAddressBookView()
	: CFormView(CAddressBookView::IDD)
{
	//{{AFX_DATA_INIT(CAddressBookView)
	m_strName = _T("");
	m_strCompany = _T("");
	m_strPhone = _T("");
	m_strEmail = _T("");
	//}}AFX_DATA_INIT
	// TODO: add construction code here

}

CAddressBookView::~CAddressBookView()
{
}

void CAddressBookView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAddressBookView)
	DDX_Text(pDX, IDC_EDIT_NAME, m_strName);
	DDX_Text(pDX, IDC_EDIT_COMPANY, m_strCompany);
	DDX_Text(pDX, IDC_EDIT_PHONE, m_strPhone);
	DDX_Text(pDX, IDC_EDIT_EMAIL, m_strEmail);
	//}}AFX_DATA_MAP
}

BOOL CAddressBookView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CFormView::PreCreateWindow(cs);
}

void CAddressBookView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();
	CAddressBookDoc *pDoc=GetDocument();//获得文档类指针
	m_PersonViewList=&(pDoc->m_PersonList);//视图类指针指向文档类对象
	m_Position=m_PersonViewList->GetHeadPosition();//获得头结点位置
	CPerson *pListDoc=(CPerson *)m_PersonViewList->GetAt(m_Position);//获得头一个数据
	m_strName=pListDoc->m_Name;
	m_strPhone=pListDoc->m_Phone;
	m_strCompany=pListDoc->m_Company;
	m_strEmail=pListDoc->m_Email;//将表头结点数据赋给视图类成员变量
	UpdateData(false);//刷新窗口
	((CDialog*)this)->GotoDlgCtrl(GetDlgItem(IDC_EDIT_NAME)); //将光标停在姓名编辑框


}

/////////////////////////////////////////////////////////////////////////////
// CAddressBookView diagnostics

#ifdef _DEBUG
void CAddressBookView::AssertValid() const
{
	CFormView::AssertValid();
}

void CAddressBookView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CAddressBookDoc* CAddressBookView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CAddressBookDoc)));
	return (CAddressBookDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CAddressBookView message handlers

void CAddressBookView::OnChangeEditName() 
{
	UpdateData(true);//界面的值传递到变量
	CAddressBookDoc *pDoc=GetDocument();//获得文档类指针
	CPerson *pListDoc=(CPerson*)m_PersonViewList->GetAt(m_Position);//获得当前结点
	pListDoc->m_Name=m_strName;//将更改过的姓名添加到结点
	pDoc->SetModifiedFlag();//设置文档数据被修改标志

	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CFormView::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	
}

void CAddressBookView::OnButtonAdd() 
{
	//界面
	((CButton*)GetDlgItem(IDC_CHECK_MODIFY))->EnableWindow(false);
	((CButton*)GetDlgItem(IDC_BUTTON_CLEAR))->EnableWindow(false);
	((CButton*)GetDlgItem(IDC_BUTTON_PREVIOUS))->EnableWindow(false);
	((CButton*)GetDlgItem(IDC_BUTTON_NEXT))->EnableWindow(false);

	((CButton*)GetDlgItem(IDC_BUTTON_ADD))->SetWindowText(_T("继续添加"));
	((CButton*)GetDlgItem(IDC_BUTTON_DELETE))->SetWindowText(_T("添加完毕"));

	((CEdit*)GetDlgItem(IDC_EDIT_NAME))->EnableWindow(true);
	((CEdit*)GetDlgItem(IDC_EDIT_EMAIL))->EnableWindow(true);
	((CEdit*)GetDlgItem(IDC_EDIT_PHONE))->EnableWindow(true);
	((CEdit*)GetDlgItem(IDC_EDIT_COMPANY))->EnableWindow(true);
	m_strName="";
	m_strPhone="";
	m_strCompany="";
	m_strEmail="";//清空编辑框
	UpdateData(false);//刷新界面
	CPerson *pListDoc=new CPerson();
	m_Position=m_PersonViewList->AddTail(pListDoc);
     //新建空人员信息添加至链表,并将当前位置移至该处
	CAddressBookDoc *pDoc=GetDocument();//获得文档指针
	pDoc->SetModifiedFlag();//设置文档被修改标置
	((CDialog*)this)->GotoDlgCtrl(GetDlgItem(IDC_EDIT_NAME));//姓名编辑框获得焦点
	

	// TODO: Add your control notification handler code here
	
}

void CAddressBookView::OnButtonDelete() 
{
	CString str;
	GetDlgItem(IDC_BUTTON_DELETE)->GetWindowText(str);
	if(str=="删除记录(&D)")
	{
		CObject *pOld; //临时对象指针
		pOld=m_PersonViewList->GetAt(m_Position);//使其指向当前指针
		m_PersonViewList->RemoveAt(m_Position); //将当前结点从列表中删除
		delete pOld;//释放空间
		if(m_PersonViewList->IsEmpty())   //链表若为空,则调用添加生成一个新结点
		{
			CAddressBookDoc *pDoc=GetDocument();//获得文档指针
			pDoc->OnNewDocument();
			m_Position=m_PersonViewList->GetHeadPosition();
		}
		CAddressBookDoc *pDoc=(CAddressBookDoc*)GetDocument();
		pDoc->SetModifiedFlag(); //获得文档指针,标志文档已被修改
		OnInitialUpdate();//显示列表第一个结点
	}
	else
	{
		AfxMessageBox("添加完毕!");
		((CButton*)GetDlgItem(IDC_CHECK_MODIFY))->EnableWindow(true);
		((CButton*)GetDlgItem(IDC_BUTTON_CLEAR))->EnableWindow(true);
		((CButton*)GetDlgItem(IDC_BUTTON_PREVIOUS))->EnableWindow(true);
		((CButton*)GetDlgItem(IDC_BUTTON_NEXT))->EnableWindow(true);

		((CButton*)GetDlgItem(IDC_BUTTON_ADD))->SetWindowText(_T("添加记录(&A)"));
		((CButton*)GetDlgItem(IDC_BUTTON_DELETE))->SetWindowText(_T("删除记录(&D)"));
		((CEdit*)GetDlgItem(IDC_EDIT_NAME))->EnableWindow(false);
		((CEdit*)GetDlgItem(IDC_EDIT_EMAIL))->EnableWindow(false);
		((CEdit*)GetDlgItem(IDC_EDIT_PHONE))->EnableWindow(false);
		((CEdit*)GetDlgItem(IDC_EDIT_COMPANY))->EnableWindow(false);
	}
	// TODO: Add your control notification handler code here
	
}

void CAddressBookView::OnButtonPrevious() 
{
	POSITION m_templeposition;//定义一个临时位置指针
	m_templeposition=m_Position;//并使其指向当前结点的前驱结点
	m_PersonViewList->GetPrev(m_templeposition);//获得当前结点位置的前一个
	if(m_templeposition==NULL)
	{//若到链表头结点
		AfxMessageBox(_T("已到表头!"));
	}
	else
	{
		m_Position=m_templeposition;//当前指针定位到前一个
		CPerson *pListDoc=(CPerson *)m_PersonViewList->GetAt(m_Position);
		//获得前一个人员的信息
		m_strName=pListDoc->m_Name;
		m_strPhone=pListDoc->m_Phone;
		m_strCompany=pListDoc->m_Company;
		m_strEmail=pListDoc->m_Email; //赋值给视图类数据成员
		UpdateData(false);//刷新窗口
	}

	// TODO: Add your control notification handler code here
	
}

void CAddressBookView::OnButtonNext() 
{
	POSITION m_templeposition;//定义一个临时位置指针
	m_templeposition=m_Position;//并使其指向当前结点的前驱结点
	m_PersonViewList->GetNext(m_templeposition);//获得当前结点位置的后一个
	if(m_templeposition==NULL)
	{//若到链表尾结点
		AfxMessageBox(_T("已到表尾!"));
	}
	else
	{
		m_Position=m_templeposition;//当前指针定位到后一个
		CPerson *pListDoc=(CPerson *)m_PersonViewList->GetAt(m_Position);
		//获得前一个人员的信息
		m_strName=pListDoc->m_Name;
		m_strPhone=pListDoc->m_Phone;
		m_strCompany=pListDoc->m_Company;
		m_strEmail=pListDoc->m_Email; //赋值给视图类数据成员
		UpdateData(false);//刷新窗口
	}

	// TODO: Add your control notification handler code here
	
}

void CAddressBookView::OnChangeEditPhone() 
{
	UpdateData(true);//界面的值传递到变量
	CAddressBookDoc *pDoc=GetDocument();//获得文档类指针
	CPerson *pListDoc=(CPerson*)m_PersonViewList->GetAt(m_Position);//获得当前结点
	pListDoc->m_Phone=m_strPhone;//将更改过的电话添加到结点
	pDoc->SetModifiedFlag();//设置文档数据被修改标志
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CFormView::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	
}

void CAddressBookView::OnChangeEditCompany() 
{
	UpdateData(true);//界面的值传递到变量
	CAddressBookDoc *pDoc=GetDocument();//获得文档类指针
	CPerson *pListDoc=(CPerson*)m_PersonViewList->GetAt(m_Position);//获得当前结点
	pListDoc->m_Company=m_strCompany;//将更改过的单位添加到结点
	pDoc->SetModifiedFlag();//设置文档数据被修改标志
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CFormView::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	
}

void CAddressBookView::OnChangeEditEmail() 
{
	UpdateData(true);//界面的值传递到变量
	CAddressBookDoc *pDoc=GetDocument();//获得文档类指针
	CPerson *pListDoc=(CPerson*)m_PersonViewList->GetAt(m_Position);//获得当前结点
	pListDoc->m_Email=m_strEmail;//将更改过的姓名添加到结点
	pDoc->SetModifiedFlag();//设置文档数据被修改标志
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CFormView::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	
}

void CAddressBookView::OnCheckModify() 
{
	//CButton a;
	//a.GetCheck(
	if(((CButton*)GetDlgItem(IDC_CHECK_MODIFY))->GetCheck()==1)
	{
		((CButton*)GetDlgItem(IDC_BUTTON_ADD))->EnableWindow(false);
		((CButton*)GetDlgItem(IDC_BUTTON_DELETE))->EnableWindow(false);
		((CButton*)GetDlgItem(IDC_BUTTON_CLEAR))->EnableWindow(false);
		((CEdit*)GetDlgItem(IDC_EDIT_NAME))->EnableWindow(true);
		((CEdit*)GetDlgItem(IDC_EDIT_EMAIL))->EnableWindow(true);
		((CEdit*)GetDlgItem(IDC_EDIT_PHONE))->EnableWindow(true);
		((CEdit*)GetDlgItem(IDC_EDIT_COMPANY))->EnableWindow(true);


	}
	else
	{
		((CButton*)GetDlgItem(IDC_BUTTON_ADD))->EnableWindow(true);
		((CButton*)GetDlgItem(IDC_BUTTON_DELETE))->EnableWindow(true);
		((CButton*)GetDlgItem(IDC_BUTTON_CLEAR))->EnableWindow(true);
		((CEdit*)GetDlgItem(IDC_EDIT_NAME))->EnableWindow(false);
		((CEdit*)GetDlgItem(IDC_EDIT_EMAIL))->EnableWindow(false);
		((CEdit*)GetDlgItem(IDC_EDIT_PHONE))->EnableWindow(false);
		((CEdit*)GetDlgItem(IDC_EDIT_COMPANY))->EnableWindow(false);

	}
		
	// TODO: Add your control notification handler code here
	
}

void CAddressBookView::OnButtonClear() 
{
	if(m_PersonViewList->GetCount()==1)   //链表若为空,则调用添加生成一个新结点
	{
		AfxMessageBox("没有可清空的记录！");
		return;
	}

	if(MessageBox("所有的记录将被清空!","清空警告",MB_YESNO)==IDYES)
	{
			CAddressBookDoc *pDoc=GetDocument();//获得文档指针
			pDoc->OnNewDocument();	

			m_Position=m_PersonViewList->GetHeadPosition();
	/*	while(!pDoc->m_PersonList.IsEmpty())
		{//循环删除最前的结点,直到删尽为止
			delete pDoc->m_PersonList.RemoveHead();
		}	
		m_strName="someone";
		m_strPhone="";
		m_strCompany="";
		m_strEmail="";//清空编辑框
		UpdateData(false);//刷新界面
		CPerson *pListDoc=new CPerson();
		m_Position=m_PersonViewList->AddTail(pListDoc);
		//新建空人员信息添加至链表,并将当前位置移至该处	
		pDoc->SetModifiedFlag();//设置文档被修改标置
		((CDialog*)this)->GotoDlgCtrl(GetDlgItem(IDC_EDIT_NAME));//姓名编辑框获得焦点*/
	}	// TODO: Add your control notification handler code here
	
}
