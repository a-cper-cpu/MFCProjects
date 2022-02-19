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
	CAddressBookDoc *pDoc=GetDocument();//����ĵ���ָ��
	m_PersonViewList=&(pDoc->m_PersonList);//��ͼ��ָ��ָ���ĵ������
	m_Position=m_PersonViewList->GetHeadPosition();//���ͷ���λ��
	CPerson *pListDoc=(CPerson *)m_PersonViewList->GetAt(m_Position);//���ͷһ������
	m_strName=pListDoc->m_Name;
	m_strPhone=pListDoc->m_Phone;
	m_strCompany=pListDoc->m_Company;
	m_strEmail=pListDoc->m_Email;//����ͷ������ݸ�����ͼ���Ա����
	UpdateData(false);//ˢ�´���
	((CDialog*)this)->GotoDlgCtrl(GetDlgItem(IDC_EDIT_NAME)); //�����ͣ�������༭��


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
	UpdateData(true);//�����ֵ���ݵ�����
	CAddressBookDoc *pDoc=GetDocument();//����ĵ���ָ��
	CPerson *pListDoc=(CPerson*)m_PersonViewList->GetAt(m_Position);//��õ�ǰ���
	pListDoc->m_Name=m_strName;//�����Ĺ���������ӵ����
	pDoc->SetModifiedFlag();//�����ĵ����ݱ��޸ı�־

	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CFormView::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	
}

void CAddressBookView::OnButtonAdd() 
{
	//����
	((CButton*)GetDlgItem(IDC_CHECK_MODIFY))->EnableWindow(false);
	((CButton*)GetDlgItem(IDC_BUTTON_CLEAR))->EnableWindow(false);
	((CButton*)GetDlgItem(IDC_BUTTON_PREVIOUS))->EnableWindow(false);
	((CButton*)GetDlgItem(IDC_BUTTON_NEXT))->EnableWindow(false);

	((CButton*)GetDlgItem(IDC_BUTTON_ADD))->SetWindowText(_T("�������"));
	((CButton*)GetDlgItem(IDC_BUTTON_DELETE))->SetWindowText(_T("������"));

	((CEdit*)GetDlgItem(IDC_EDIT_NAME))->EnableWindow(true);
	((CEdit*)GetDlgItem(IDC_EDIT_EMAIL))->EnableWindow(true);
	((CEdit*)GetDlgItem(IDC_EDIT_PHONE))->EnableWindow(true);
	((CEdit*)GetDlgItem(IDC_EDIT_COMPANY))->EnableWindow(true);
	m_strName="";
	m_strPhone="";
	m_strCompany="";
	m_strEmail="";//��ձ༭��
	UpdateData(false);//ˢ�½���
	CPerson *pListDoc=new CPerson();
	m_Position=m_PersonViewList->AddTail(pListDoc);
     //�½�����Ա��Ϣ���������,������ǰλ�������ô�
	CAddressBookDoc *pDoc=GetDocument();//����ĵ�ָ��
	pDoc->SetModifiedFlag();//�����ĵ����޸ı���
	((CDialog*)this)->GotoDlgCtrl(GetDlgItem(IDC_EDIT_NAME));//�����༭���ý���
	

	// TODO: Add your control notification handler code here
	
}

void CAddressBookView::OnButtonDelete() 
{
	CString str;
	GetDlgItem(IDC_BUTTON_DELETE)->GetWindowText(str);
	if(str=="ɾ����¼(&D)")
	{
		CObject *pOld; //��ʱ����ָ��
		pOld=m_PersonViewList->GetAt(m_Position);//ʹ��ָ��ǰָ��
		m_PersonViewList->RemoveAt(m_Position); //����ǰ�����б���ɾ��
		delete pOld;//�ͷſռ�
		if(m_PersonViewList->IsEmpty())   //������Ϊ��,������������һ���½��
		{
			CAddressBookDoc *pDoc=GetDocument();//����ĵ�ָ��
			pDoc->OnNewDocument();
			m_Position=m_PersonViewList->GetHeadPosition();
		}
		CAddressBookDoc *pDoc=(CAddressBookDoc*)GetDocument();
		pDoc->SetModifiedFlag(); //����ĵ�ָ��,��־�ĵ��ѱ��޸�
		OnInitialUpdate();//��ʾ�б��һ�����
	}
	else
	{
		AfxMessageBox("������!");
		((CButton*)GetDlgItem(IDC_CHECK_MODIFY))->EnableWindow(true);
		((CButton*)GetDlgItem(IDC_BUTTON_CLEAR))->EnableWindow(true);
		((CButton*)GetDlgItem(IDC_BUTTON_PREVIOUS))->EnableWindow(true);
		((CButton*)GetDlgItem(IDC_BUTTON_NEXT))->EnableWindow(true);

		((CButton*)GetDlgItem(IDC_BUTTON_ADD))->SetWindowText(_T("��Ӽ�¼(&A)"));
		((CButton*)GetDlgItem(IDC_BUTTON_DELETE))->SetWindowText(_T("ɾ����¼(&D)"));
		((CEdit*)GetDlgItem(IDC_EDIT_NAME))->EnableWindow(false);
		((CEdit*)GetDlgItem(IDC_EDIT_EMAIL))->EnableWindow(false);
		((CEdit*)GetDlgItem(IDC_EDIT_PHONE))->EnableWindow(false);
		((CEdit*)GetDlgItem(IDC_EDIT_COMPANY))->EnableWindow(false);
	}
	// TODO: Add your control notification handler code here
	
}

void CAddressBookView::OnButtonPrevious() 
{
	POSITION m_templeposition;//����һ����ʱλ��ָ��
	m_templeposition=m_Position;//��ʹ��ָ��ǰ����ǰ�����
	m_PersonViewList->GetPrev(m_templeposition);//��õ�ǰ���λ�õ�ǰһ��
	if(m_templeposition==NULL)
	{//��������ͷ���
		AfxMessageBox(_T("�ѵ���ͷ!"));
	}
	else
	{
		m_Position=m_templeposition;//��ǰָ�붨λ��ǰһ��
		CPerson *pListDoc=(CPerson *)m_PersonViewList->GetAt(m_Position);
		//���ǰһ����Ա����Ϣ
		m_strName=pListDoc->m_Name;
		m_strPhone=pListDoc->m_Phone;
		m_strCompany=pListDoc->m_Company;
		m_strEmail=pListDoc->m_Email; //��ֵ����ͼ�����ݳ�Ա
		UpdateData(false);//ˢ�´���
	}

	// TODO: Add your control notification handler code here
	
}

void CAddressBookView::OnButtonNext() 
{
	POSITION m_templeposition;//����һ����ʱλ��ָ��
	m_templeposition=m_Position;//��ʹ��ָ��ǰ����ǰ�����
	m_PersonViewList->GetNext(m_templeposition);//��õ�ǰ���λ�õĺ�һ��
	if(m_templeposition==NULL)
	{//��������β���
		AfxMessageBox(_T("�ѵ���β!"));
	}
	else
	{
		m_Position=m_templeposition;//��ǰָ�붨λ����һ��
		CPerson *pListDoc=(CPerson *)m_PersonViewList->GetAt(m_Position);
		//���ǰһ����Ա����Ϣ
		m_strName=pListDoc->m_Name;
		m_strPhone=pListDoc->m_Phone;
		m_strCompany=pListDoc->m_Company;
		m_strEmail=pListDoc->m_Email; //��ֵ����ͼ�����ݳ�Ա
		UpdateData(false);//ˢ�´���
	}

	// TODO: Add your control notification handler code here
	
}

void CAddressBookView::OnChangeEditPhone() 
{
	UpdateData(true);//�����ֵ���ݵ�����
	CAddressBookDoc *pDoc=GetDocument();//����ĵ���ָ��
	CPerson *pListDoc=(CPerson*)m_PersonViewList->GetAt(m_Position);//��õ�ǰ���
	pListDoc->m_Phone=m_strPhone;//�����Ĺ��ĵ绰��ӵ����
	pDoc->SetModifiedFlag();//�����ĵ����ݱ��޸ı�־
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CFormView::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	
}

void CAddressBookView::OnChangeEditCompany() 
{
	UpdateData(true);//�����ֵ���ݵ�����
	CAddressBookDoc *pDoc=GetDocument();//����ĵ���ָ��
	CPerson *pListDoc=(CPerson*)m_PersonViewList->GetAt(m_Position);//��õ�ǰ���
	pListDoc->m_Company=m_strCompany;//�����Ĺ��ĵ�λ��ӵ����
	pDoc->SetModifiedFlag();//�����ĵ����ݱ��޸ı�־
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CFormView::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	
}

void CAddressBookView::OnChangeEditEmail() 
{
	UpdateData(true);//�����ֵ���ݵ�����
	CAddressBookDoc *pDoc=GetDocument();//����ĵ���ָ��
	CPerson *pListDoc=(CPerson*)m_PersonViewList->GetAt(m_Position);//��õ�ǰ���
	pListDoc->m_Email=m_strEmail;//�����Ĺ���������ӵ����
	pDoc->SetModifiedFlag();//�����ĵ����ݱ��޸ı�־
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
	if(m_PersonViewList->GetCount()==1)   //������Ϊ��,������������һ���½��
	{
		AfxMessageBox("û�п���յļ�¼��");
		return;
	}

	if(MessageBox("���еļ�¼�������!","��վ���",MB_YESNO)==IDYES)
	{
			CAddressBookDoc *pDoc=GetDocument();//����ĵ�ָ��
			pDoc->OnNewDocument();	

			m_Position=m_PersonViewList->GetHeadPosition();
	/*	while(!pDoc->m_PersonList.IsEmpty())
		{//ѭ��ɾ����ǰ�Ľ��,ֱ��ɾ��Ϊֹ
			delete pDoc->m_PersonList.RemoveHead();
		}	
		m_strName="someone";
		m_strPhone="";
		m_strCompany="";
		m_strEmail="";//��ձ༭��
		UpdateData(false);//ˢ�½���
		CPerson *pListDoc=new CPerson();
		m_Position=m_PersonViewList->AddTail(pListDoc);
		//�½�����Ա��Ϣ���������,������ǰλ�������ô�	
		pDoc->SetModifiedFlag();//�����ĵ����޸ı���
		((CDialog*)this)->GotoDlgCtrl(GetDlgItem(IDC_EDIT_NAME));//�����༭���ý���*/
	}	// TODO: Add your control notification handler code here
	
}
