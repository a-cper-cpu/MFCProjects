// PageCou.cpp : implementation file
//

#include "stdafx.h"
#include "UGMS.h"
#include "PageCou.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPageCou dialog


CPageCou::CPageCou(CWnd* pParent /*=NULL*/)
	: CDialog(CPageCou::IDD, pParent)
{
	//{{AFX_DATA_INIT(CPageCou)
	m_CKind = -1;
	m_CID = 0;
	m_CName = _T("");
	m_CScore = 0;
	//}}AFX_DATA_INIT
}


void CPageCou::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPageCou)
	DDX_Control(pDX, IDC_EDIT_COUID, m_ctlCID);
	DDX_Control(pDX, IDC_BUTTON_QUERY, m_btnQuery);
	DDX_Control(pDX, IDC_BUTTON_PREVIOUS, m_btnPre);
	DDX_Control(pDX, IDC_BUTTON_OK, m_btnOk);
	DDX_Control(pDX, IDC_BUTTON_NEXT, m_btnNext);
	DDX_Control(pDX, IDC_BUTTON_MODIFY, m_btnModify);
	DDX_Control(pDX, IDC_BUTTON_LAST, m_btnLast);
	DDX_Control(pDX, IDC_BUTTON_FIRST, m_btnFirst);
	DDX_Control(pDX, IDC_BUTTON_DELETE, m_btnDel);
	DDX_Control(pDX, IDC_BUTTON_ADD, m_btnAdd);
	DDX_CBIndex(pDX, IDC_COMBO_KIND, m_CKind);
	DDX_Text(pDX, IDC_EDIT_COUID, m_CID);
	DDX_Text(pDX, IDC_EDIT_COUNAME, m_CName);
	DDX_Text(pDX, IDC_EDIT_COUSCORE, m_CScore);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CPageCou, CDialog)
	//{{AFX_MSG_MAP(CPageCou)
	ON_BN_CLICKED(IDC_BUTTON_FIRST, OnButtonFirst)
	ON_BN_CLICKED(IDC_BUTTON_PREVIOUS, OnButtonPrevious)
	ON_BN_CLICKED(IDC_BUTTON_NEXT, OnButtonNext)
	ON_BN_CLICKED(IDC_BUTTON_LAST, OnButtonLast)
	ON_BN_CLICKED(IDC_BUTTON_QUERY, OnButtonQuery)
	ON_BN_CLICKED(IDC_BUTTON_ADD, OnButtonAdd)
	ON_BN_CLICKED(IDC_BUTTON_DELETE, OnButtonDelete)
	ON_BN_CLICKED(IDC_BUTTON_MODIFY, OnButtonModify)
	ON_BN_CLICKED(IDC_BUTTON_OK, OnButtonOk)
	ON_BN_CLICKED(IDC_BUTTON_CANCEL, OnButtonCancel)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPageCou message handlers
enum enumCOU
{
	NONE,		//��Ӧû�й���
	SEARCH,		//��Ӧ���ҹ���
	ADD,		//��Ӧ��ӹ���
	DEL,		//��Ӧɾ������
	MODIFY,		//��Ӧ�޸Ĺ���
};

//����ö�ٱ���FOUNCTION
enumCOU FOUNCTION = NONE;
BOOL CPageCou::OnInitDialog()
{	
	CDialog::OnInitDialog();
	// TODO: ADD extra initialization here
	//������¼������
	m_pRecordset.CreateInstance(__uuidof(Recordset));
	m_pRecordsetCHO.CreateInstance(__uuidof(Recordset));

	//��COURSES��
	OpenCOURSES();

	_variant_t var;
	CString str;		
	
	try
	{
		if(!m_pRecordset->BOF)
		{
			m_pRecordset->MoveFirst();
		}
		//�����������Ϊ�գ����ÿؼ����Բ���ʼ�Ի���
		else
		{
			AfxMessageBox("��������Ϊ��");
			m_btnQuery.EnableWindow(FALSE);
			m_btnDel.EnableWindow(FALSE);
			m_btnModify.EnableWindow(FALSE);
			m_btnFirst.EnableWindow(FALSE);
			m_btnPre.EnableWindow(FALSE);
			m_btnNext.EnableWindow(FALSE);
			m_btnLast.EnableWindow(FALSE);
			m_btnOk.SetFocus();	
			return TRUE;
		}
		//
		// ����������ֶβ�����ؼ���
		//
		//���±༭��m_CID		
		var = m_pRecordset->GetCollect("CID");
		if(var.vt != VT_NULL)		
		m_CID = var.iVal ;

        //���±༭��m_CName
		var = m_pRecordset->GetCollect("CName");
		str = (LPCSTR)_bstr_t(var);
		m_CName = str;

        //������Ͽ�m_CScore
		var = m_pRecordset->GetCollect("CScore");
		m_CScore = var.iVal;

        //������Ͽ�m_CKind
		var = m_pRecordset->GetCollect("CKind");
		m_CKind = var.iVal;

	    //�������пؼ���ʾ
		UpdateData(false);
	}
	catch(_com_error *e)
	{
		AfxMessageBox(e->ErrorMessage());
	}

	return TRUE;

}
void CPageCou::OpenCOURSES()
{
	//��ADO�����н��������Ҫ����try...catch()�����������Ϣ,
    //��Ϊ����ʱ�ᾭ������һЩ�벻���Ĵ���
	try
	{
		//��SQL���ݿ��д�STUDENTS��
		m_pRecordset->Open("SELECT * FROM COURSES", 
							theApp.m_pConnection.GetInterfacePtr(),
							adOpenDynamic,
							adLockOptimistic,
							adCmdText);
	}
	catch(_com_error *e)
	{
		AfxMessageBox(e->ErrorMessage());
	}
}
//////////////////////////
//
//ִ�в��ҹ���
//
/////////////////////////
void CPageCou::Query()
{
	//�������
	_variant_t var;
	CString str;
	//���¿ؼ�������ֵ
	UpdateData(true);

	try
	{
		m_pRecordset->MoveFirst();
		while(!m_pRecordset->adoEOF)
		{
			var = m_pRecordset->GetCollect("CID");			
			if(m_CID == var.iVal)
			{
				var = m_pRecordset->GetCollect("CID");
				if(var.vt != VT_NULL)
				{
					m_CID = var.iVal;
				}

				var = m_pRecordset->GetCollect("CName");
				str = (LPCSTR)_bstr_t(var);
				m_CName = str;

				var = m_pRecordset->GetCollect("CScore");
				if(var.vt != VT_NULL)
				{
					m_CScore = var.iVal;
				}

				var = m_pRecordset->GetCollect("CKind");
				if(var.vt != VT_NULL)
				{
					m_CKind = var.iVal;
				}
			
				UpdateData(false);					
				break;
			}
			else 
			{
				m_pRecordset->MoveNext();
			}
		}
		if(m_pRecordset->adoEOF)
		{
			MessageBox("û������γ̺ţ�");
		}
	}
	catch(_com_error *e)
	{
		AfxMessageBox(e->ErrorMessage());
	}
}
//////////////////////////
//
//ִ����ӹ���
//
/////////////////////////
void CPageCou::Add()
{
	//�������
	_variant_t var;
	CString str;
	//���¿ؼ�������ֵ
	UpdateData(true);

    //�ж�Ҫ��ӵĿγ̺��Ƿ����
	if(m_CID != 0 && !m_pRecordset->BOF)
	{
		m_pRecordset->MoveFirst();
		while(!m_pRecordset->adoEOF)
		{
			var = m_pRecordset->GetCollect("CID");
			if(m_CID == var.iVal)
			{
				AfxMessageBox("�Ѿ���������γ̺ţ�");
				break;
			}
			m_pRecordset->MoveNext();
		}
		if(!m_pRecordset->adoEOF)
		{
			return;
		}
	}

	if(m_CID == 0 )
	{
		AfxMessageBox("�γ̺���Ϣ����Ϊ��!");
		return;
	}	
	else
	{
		try
		{
			//
			// д����ֶ�ֵ
			//
			m_pRecordset->AddNew();

			//д��CID�ֶ�
			var.iVal = m_CID;
			m_pRecordset->PutCollect("CID", var.iVal);

			//д��CName�ֶ�			
			m_pRecordset->PutCollect("CName", _variant_t(m_CName));

			//д��CScore�ֶ�
			var.iVal=m_CScore;
			m_pRecordset->PutCollect("CScore", var.iVal);

			//д��CKind�ֶ�
			var.iVal=m_CKind;
			m_pRecordset->PutCollect("CKind", var.iVal);
			//����SQL���ݿ�
			m_pRecordset->Update();

			//��ǰ��¼�ƶ������
			m_pRecordset->MoveLast();

			AfxMessageBox("����ɹ�!");			
		}
		catch(_com_error *e)
		{
			AfxMessageBox(e->ErrorMessage());
		}
	}
}

//////////////////////////
//
//ִ��ɾ������
//
/////////////////////////
void CPageCou::Delete()
{
	//�������
	_variant_t var;
	CString str;

	//�жϵ�ǰ�Ƿ��м�¼
	if(m_CID == 0)
	{
		MessageBox(" û�м�¼��");
		return;
	}
	//�ж��Ƿ���Ϊ�����ʹ��
	str.Format("select * from CHOICES where CID = %d",m_CID);
	m_pRecordsetCHO->Open(str.AllocSysString(), 
							theApp.m_pConnection.GetInterfacePtr(),
							adOpenDynamic,
							adLockOptimistic,
							adCmdText);
	if(!m_pRecordsetCHO->BOF)
	{
		AfxMessageBox("���������ڱ�������ʹ�ã�����ɾ����");
		m_pRecordsetCHO->Close();
		return;
	}
	else
	{
		m_pRecordsetCHO->Close();
	}

	try
	{
		//
		// ɾ����ǰ�м�¼
		//
		m_pRecordset->Delete(adAffectCurrent);
		m_pRecordset->Update();

		m_pRecordset->MoveFirst();

		//�ж�ɾ������������Ƿ�Ϊ��
		if(m_pRecordset->BOF)
		{
			AfxMessageBox("���������Ѿ�Ϊ�գ�");
			m_btnQuery.EnableWindow(FALSE);
			m_btnDel.EnableWindow(FALSE);
			m_btnModify.EnableWindow(FALSE);
			m_btnFirst.EnableWindow(FALSE);
			m_btnPre.EnableWindow(FALSE);
			m_btnNext.EnableWindow(FALSE);
			m_btnLast.EnableWindow(FALSE);
			m_btnOk.SetFocus();	
			return;
		}

		//��ʾ���һ����¼		
		m_pRecordset->MoveLast();
		var = m_pRecordset->GetCollect("CID");
		if(var.vt != VT_NULL)		
		m_CID = var.iVal ;

		var = m_pRecordset->GetCollect("CName");
		str = (LPCSTR)_bstr_t(var);
		m_CName = str;

		var = m_pRecordset->GetCollect("CScore");
		m_CScore = var.iVal;

	
		var = m_pRecordset->GetCollect("CKind");
		m_CKind = var.iVal;

		UpdateData(false);				
	}
	catch(_com_error *e)
	{
		AfxMessageBox(e->ErrorMessage());
	}
}

//////////////////////////
//
//ִ���޸Ĺ���
//
/////////////////////////
void CPageCou::Modify()
{
	//�������
	_variant_t var;
	CString str;
	//���¿ؼ�������ֵ
	UpdateData(true);	

	if(m_CID == 0 )
	{
		AfxMessageBox("�γ̺���Ϣ����Ϊ��!");
		return;
	}
	//
	// �޸ĵ�ǰ��¼���ֶ�ֵ
	//
	try
	{
		var.iVal = m_CID;
		m_pRecordset->PutCollect("CID", var.iVal);
		
		m_pRecordset->PutCollect("CName", _variant_t(m_CName));

		var.iVal=m_CScore;
		m_pRecordset->PutCollect("CScore", var.iVal);

		var.iVal=m_CKind;
		m_pRecordset->PutCollect("CKind", var.iVal);

		m_pRecordset->Update();

		AfxMessageBox("�޸ĳɹ�!");			
	}
	catch(_com_error *e)
	{
		AfxMessageBox(e->ErrorMessage());
	}
}

void CPageCou::OnButtonFirst() 
{
	m_pRecordset->MoveFirst();
	_variant_t var;
	CString str;		
	
	try
	{
		var = m_pRecordset->GetCollect("CID");
		if(var.vt != VT_NULL)		
		m_CID = var.iVal ;

		var = m_pRecordset->GetCollect("CName");
		str = (LPCSTR)_bstr_t(var);
		m_CName = str;

		var = m_pRecordset->GetCollect("CScore");
		m_CScore =var.iVal;

		var = m_pRecordset->GetCollect("CKind");
		m_CKind =var.iVal;
	
		UpdateData(false);
	}
	catch(_com_error *e)
	{
		AfxMessageBox(e->ErrorMessage());
	}	
	// TODO: Add your control notification handler code here
	
}

void CPageCou::OnButtonPrevious() 
{
	m_pRecordset->MovePrevious();
	_variant_t var;
	CString str;	
	if(m_pRecordset->BOF)
	{
		MessageBox("�Ѿ����׼�¼��");
	    m_pRecordset->MoveFirst();
	}
	
	try
	{
		var = m_pRecordset->GetCollect("CID");
		if(var.vt != VT_NULL)		
		m_CID = var.iVal;

		var = m_pRecordset->GetCollect("CName");
		str = (LPCSTR)_bstr_t(var);
		m_CName = str;

		var = m_pRecordset->GetCollect("CScore");
		m_CScore= var.iVal;

		var = m_pRecordset->GetCollect("CKind");
		m_CKind= var.iVal;
	
		UpdateData(false);
	}
	catch(_com_error *e)
	{
		AfxMessageBox(e->ErrorMessage());
	}	
	// TODO: Add your control notification handler code here
	
}

void CPageCou::OnButtonNext() 
{
	m_pRecordset->MoveNext();
	_variant_t var;
	CString str;
	
	if(m_pRecordset->adoEOF)
	{
		MessageBox("�Ѿ���ĩ��¼��");
	    m_pRecordset->MoveLast();
	}
	
	try
	{
		var = m_pRecordset->GetCollect("CID");
		if(var.vt != VT_NULL)		
		m_CID = var.iVal;

		var = m_pRecordset->GetCollect("CName");
		str = (LPCSTR)_bstr_t(var);
		m_CName = str;

		var = m_pRecordset->GetCollect("CScore");
		m_CScore = var.iVal;
		
		var = m_pRecordset->GetCollect("CKind");
		m_CKind= var.iVal;
	
		UpdateData(false);
	}
	catch(_com_error *e)
	{
		AfxMessageBox(e->ErrorMessage());
	}	
	// TODO: Add your control notification handler code here
	
}

void CPageCou::OnButtonLast() 
{
	m_pRecordset->MoveLast();
	_variant_t var;
	CString str;		
	
	try
	{
		var = m_pRecordset->GetCollect("CID");
		if(var.vt != VT_NULL)		
		m_CID = var.iVal;

		var = m_pRecordset->GetCollect("CName");
		str = (LPCSTR)_bstr_t(var);
		m_CName = str;

		var = m_pRecordset->GetCollect("CScore");
		m_CScore = var.iVal;

		var = m_pRecordset->GetCollect("CKind");
		m_CKind = var.iVal;

		UpdateData(false);
	}
	catch(_com_error *e)
	{
		AfxMessageBox(e->ErrorMessage());
	}	
	// TODO: Add your control notification handler code here
	
}

void CPageCou::OnButtonQuery() 
{
	m_CID = 0;
	m_CName = "";
	m_CScore = 0;
	m_CKind=0;
	UpdateData(false);
    //����FOUNCTIONֵ
	FOUNCTION = SEARCH;
	//�޸ĸ������ΰ�ť������
	m_btnQuery.SetState(TRUE);
	m_btnAdd.EnableWindow(FALSE);
	m_btnDel.EnableWindow(FALSE);
	m_btnModify.EnableWindow(FALSE);
	m_btnFirst.EnableWindow(FALSE);
	m_btnPre.EnableWindow(FALSE);
	m_btnNext.EnableWindow(FALSE);
	m_btnLast.EnableWindow(FALSE);
	m_btnOk.SetFocus();
	// TODO: Add your control notification handler code here
	
}

void CPageCou::OnButtonAdd() 
{
	//
	//��������ʾ�ؼ�һ�����֮ǰ�ĳ�ֵ
	//
	m_CID = 0;
	m_CName = "";
	m_CScore = 0;
	m_CKind=0;
	UpdateData(false);
	//����FOUNCTIONֵ
	FOUNCTION = ADD;
	//�޸ĸ������ΰ�ť������
	m_btnQuery.EnableWindow(FALSE);
	m_btnAdd.SetState(TRUE);
	m_btnDel.EnableWindow(FALSE);
	m_btnModify.EnableWindow(FALSE);
	m_btnFirst.EnableWindow(FALSE);
	m_btnPre.EnableWindow(FALSE);
	m_btnNext.EnableWindow(FALSE);
	m_btnLast.EnableWindow(FALSE);
	m_btnOk.SetFocus();	
	// TODO: Add your control notification handler code here
	
}

void CPageCou::OnButtonDelete() 
{
	if(MessageBox("���ɾ����\n���밴���ǡ���\n���밴���񡱣�", NULL, MB_YESNO | MB_ICONQUESTION) == IDYES)
	{
		//����FOUNCTIONֵ
		FOUNCTION = DEL;
		OnButtonOk();
	}
	else
	{
		OnButtonCancel();
	}
	// TODO: Add your control notification handler code here
	
}

void CPageCou::OnButtonModify() 
{
	//����FOUNCTIONֵ
	FOUNCTION = MODIFY;
	m_ctlCID.SetReadOnly();
	//�޸ĸ������ΰ�ť������
	m_btnQuery.EnableWindow(FALSE);
	m_btnAdd.EnableWindow(FALSE);
	m_btnDel.EnableWindow(FALSE);
	m_btnModify.SetState(TRUE);
	m_btnFirst.EnableWindow(FALSE);
	m_btnPre.EnableWindow(FALSE);
	m_btnNext.EnableWindow(FALSE);
	m_btnLast.EnableWindow(FALSE);
	m_btnOk.SetFocus();	
	
	// TODO: Add your control notification handler code here
	
}

void CPageCou::OnButtonOk() 
{
	if(FOUNCTION == SEARCH)
	{
		Query();		
	}	
	else if(FOUNCTION == ADD)
	{
		Add();		
	}	
	else if(FOUNCTION == DEL)
	{
		Delete();		
	}	
	else if(FOUNCTION == MODIFY)		
	{
		Modify();		
	}	
	// TODO: Add your control notification handler code here
	
}

void CPageCou::OnButtonCancel() 
{
	_variant_t var;
	CString str;
	FOUNCTION=NONE;
	//�����Ϊ�գ����ز�������Ĳ���
	if(m_pRecordset->BOF)
	{
		m_btnAdd.SetState(false);
		return;
	}	

	//�޸ĸ������ΰ�ť������
	m_btnQuery.EnableWindow(true);
	m_btnAdd.EnableWindow(true);
	m_btnDel.EnableWindow(true);
	m_btnModify.EnableWindow(true);
	m_btnFirst.EnableWindow(true);
	m_btnPre.EnableWindow(true);
	m_btnNext.EnableWindow(true);
	m_btnLast.EnableWindow(true);

	m_btnQuery.SetState(false);
	m_btnAdd.SetState(false);
	m_btnDel.SetState(false);
	m_btnModify.SetState(false);
	m_btnFirst.SetState(false);
	m_btnPre.SetState(false);
	m_btnNext.SetState(false);
	m_btnLast.SetState(false);
	
	m_ctlCID.SetReadOnly(FALSE);
	m_btnOk.SetFocus();
	//
	//��m_pRecordset��ָ��ǰ��¼��ʾ����
	//
	if(m_pRecordset->adoEOF)
	{
		m_pRecordset->MoveLast();
	}
	try
	{
		var = m_pRecordset->GetCollect("CID");
		if(var.vt != VT_NULL)		
		m_CID = var.iVal ;

		var = m_pRecordset->GetCollect("CName");
		str = (LPCSTR)_bstr_t(var);
		m_CName = str;

		var = m_pRecordset->GetCollect("CScore");
		m_CScore =var.iVal;

		var = m_pRecordset->GetCollect("CKind");
		m_CKind =var.iVal;
	
		UpdateData(false);
	}
	catch(_com_error *e)
	{
		AfxMessageBox(e->ErrorMessage());
	}	
	// TODO: Add your control notification handler code here
	
}
