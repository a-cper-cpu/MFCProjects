// PageCho.cpp : implementation file
//

#include "stdafx.h"
#include "UGMS.h"
#include "PageCho.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPageCho dialog


CPageCho::CPageCho(CWnd* pParent /*=NULL*/)
	: CDialog(CPageCho::IDD, pParent)
{
	//{{AFX_DATA_INIT(CPageCho)
	m_IsPass = -1;
	m_CID = 0;
	m_Score = 0;
	m_SID = 0;
	//}}AFX_DATA_INIT
}


void CPageCho::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPageCho)
	DDX_Control(pDX, IDC_EDIT_SID, m_ctlSID);
	DDX_Control(pDX, IDC_EDIT_CHOID, m_ctlCID);
	DDX_Control(pDX, IDC_BUTTON_QUERY, m_btnQuery);
	DDX_Control(pDX, IDC_BUTTON_PREVIOUS, m_btnPre);
	DDX_Control(pDX, IDC_BUTTON_OK, m_btnOk);
	DDX_Control(pDX, IDC_BUTTON_NEXT, m_btnNext);
	DDX_Control(pDX, IDC_BUTTON_MODIFY, m_btnModify);
	DDX_Control(pDX, IDC_BUTTON_LAST, m_btnLast);
	DDX_Control(pDX, IDC_BUTTON_FIRST, m_btnFirst);
	DDX_Control(pDX, IDC_BUTTON_DELETE, m_btnDel);
	DDX_Control(pDX, IDC_BUTTON_ADD, m_btnAdd);
	DDX_CBIndex(pDX, IDC_COMBO_PASS, m_IsPass);
	DDX_Text(pDX, IDC_EDIT_CHOID, m_CID);
	DDX_Text(pDX, IDC_EDIT_SCORE, m_Score);
	DDX_Text(pDX, IDC_EDIT_SID, m_SID);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CPageCho, CDialog)
	//{{AFX_MSG_MAP(CPageCho)
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
// CPageCho message handlers
//
//���ö�ٱ�����ʵ�ֶԲ�ͬ���ܵ�����
//
enum enumCHO
{
	NONE,		//��Ӧû�й���
	SEARCH,		//��Ӧ���ҹ���
	ADD,		//��Ӧ��ӹ���
	DEL,		//��Ӧɾ������
	MODIFY,		//��Ӧ�޸Ĺ���
};

//����ö�ٱ���FOUNCTION
enumCHO FOUNCTION = NONE;

BOOL CPageCho::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: ADD extra initialization here
	//������¼������
	m_pRecordset.CreateInstance(__uuidof(Recordset));
	//��CHOICES��
	OpenCHOICES();

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

        //���±༭��m_SID
		var = m_pRecordset->GetCollect("SID");
		if(var.vt != VT_NULL)		
		m_SID = var.iVal;

        //������Ͽ�IsPass
		var = m_pRecordset->GetCollect("IsPass");
		if(var.vt != VT_NULL)		
		m_IsPass = var.iVal;

        //���±༭��m_Score
		var = m_pRecordset->GetCollect("Score");		
		m_Score = var.iVal;

	    //�������пؼ���ʾ
		UpdateData(false);
	}
	catch(_com_error *e)
	{
		AfxMessageBox(e->ErrorMessage());
	}
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
void CPageCho::OpenSTUDENTS()
{
	//��ADO�����н��������Ҫ����try...catch()�����������Ϣ,
    //��Ϊ����ʱ�ᾭ������һЩ�벻���Ĵ���
	try
	{
		//��SQL���ݿ��д�STUDENTS��
		m_pRecordset->Open("SELECT * FROM STUDENTS", 
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

void CPageCho::OpenCOURSES()
{
	try
	{
		//��SQL���ݿ��д�COURSES��
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

void CPageCho::OpenCHOICES()
{
	try
	{
		//��SQL���ݿ��д�CHOICES��
		m_pRecordset->Open("SELECT * FROM CHOICES", 
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
void CPageCho::Query()
{
	//�������
	_variant_t var,varCou,varStu;
	CString str;
	//���¿ؼ�������ֵ
	UpdateData(true);

	if(m_SID == 0 || m_CID == 0)
	{
		MessageBox("ѧ�źͿγ̺�һ��Ҳ����Ϊ��!");
		return;
	}

	try
	{
		m_pRecordset->MoveFirst();
		while(!m_pRecordset->adoEOF)
		{
			varCou = m_pRecordset->GetCollect("CID");
			varStu = m_pRecordset->GetCollect("SID");
			//
			//ע�⣺һ��ѧ������ѡ���ſΣ�
			//���Բ�ѯʱ��������ѧ�źͿγ̺�ͬʱ�Ǻϲ���
			//
			if(m_CID == varCou.iVal && m_SID == varStu.iVal)
			{
				var = m_pRecordset->GetCollect("CID");
				if(var.vt != VT_NULL)
				{
					m_CID = var.iVal;
				}

				var = m_pRecordset->GetCollect("SID");
				m_SID = var.iVal;

				var = m_pRecordset->GetCollect("IsPass");
				if(var.vt != VT_NULL)		
				m_IsPass = var.iVal;

				var = m_pRecordset->GetCollect("Score");		
				m_Score = var.iVal; 
			
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
			MessageBox("����û��ѡ���ſγ̣�");
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
void CPageCho::Add()
{
	//�������
	_variant_t var,ar;
	CString str;
	//���¿ؼ�������ֵ
	UpdateData(true);

	//�ж���ӵ�ѧ����ѧ�������Ƿ����
	if(m_SID !=0)
	{
        m_pRecordset->Close();

		OpenSTUDENTS();

		if(m_pRecordset->BOF)
		{
			AfxMessageBox("ѧ����Ϊ�գ����Ƚ���ѧ����");
			m_pRecordset->Close();
			OpenCHOICES();
			return;
		}
		else
		{
			m_pRecordset->MoveFirst();
			while(!m_pRecordset->adoEOF)
			{
				var = m_pRecordset->GetCollect("SID");
				if(m_SID == var.iVal)
				{
					break;
				}
				m_pRecordset->MoveNext();
			}
			if(m_pRecordset->adoEOF)
			{
				AfxMessageBox("û�����ѧ�ţ�");
				m_pRecordset->Close();
				OpenCHOICES();
				return;
			}
			else
			{
				m_pRecordset->Close();
				OpenCHOICES();
			}
		}		
	}

	//�ж���ӵĿγ̺��ڿγ̱����Ƿ����
	if(m_CID !=0)
	{
        m_pRecordset->Close();

		OpenCOURSES();

		if(m_pRecordset->BOF)
		{
			AfxMessageBox("�γ̱�Ϊ�գ����Ƚ����γ̱�");
			m_pRecordset->Close();
			OpenCOURSES();
			return;
		}
		else
		{
			m_pRecordset->MoveFirst();
			while(!m_pRecordset->adoEOF)
			{
				var = m_pRecordset->GetCollect("CID");
				if(m_CID == var.iVal)
				{
					break;
				}
				m_pRecordset->MoveNext();
			}
			if(m_pRecordset->adoEOF)
			{
				AfxMessageBox("û������γ̺ţ�");
				m_pRecordset->Close();
				OpenCHOICES();
				return;
			}
			else
			{
				m_pRecordset->Close();
				OpenCHOICES();
			}
		}		
	}

    //�ж�Ҫ��ӵ�ѧ��ѡ���Ƿ��Ѿ�����
	if(m_SID != 0 && m_CID != 0 && !m_pRecordset->BOF)
	{
		m_pRecordset->MoveFirst();
		while(!m_pRecordset->adoEOF)
		{
			var = m_pRecordset->GetCollect("SID");
			ar = m_pRecordset->GetCollect("CID");
			if(m_SID == var.iVal && m_CID == ar.iVal)
			{
				AfxMessageBox("�Ѿ����ڣ�");
				break;
			}
			m_pRecordset->MoveNext();
		}
		if(!m_pRecordset->adoEOF)
		{
			return;
		}
	}

	if(m_CID == 0 || m_SID == 0)
	{
		AfxMessageBox("ѧ�źͿγ̺�һ��Ҳ����Ϊ��!");
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

			//д��SID�ֶ�
			var.iVal = m_SID;
			m_pRecordset->PutCollect("SID", var.iVal);

			//д��IsPass�ֶ�
			var.iVal=m_IsPass;
			m_pRecordset->PutCollect("IsPass", var.iVal);

			//д��Score�ֶ�
			var.iVal = m_Score;
			m_pRecordset->PutCollect("Score", var.iVal);

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
void CPageCho::Delete()
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

		var = m_pRecordset->GetCollect("SID");
		if(var.vt != VT_NULL)		
		m_SID = var.iVal;

		var = m_pRecordset->GetCollect("IsPass");
		if(var.vt != VT_NULL)		
		m_IsPass = var.iVal;

		var = m_pRecordset->GetCollect("Score");		
		m_Score = var.iVal; 
	
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
void CPageCho::Modify()
{
	//�������
	_variant_t var;
	CString str;
	//���¿ؼ�������ֵ
	UpdateData(true);

	if(m_CID == 0 || m_SID == 0)
	{
		AfxMessageBox("ѧ�źͿγ̺�һ��Ҳ����Ϊ��!");
		return;
	}
	//
	// �޸ĵ�ǰ��¼���ֶ�ֵ
	//
	try
	{
		var.iVal = m_CID;
		m_pRecordset->PutCollect("CID", var.iVal);
		
		var.iVal = m_SID;
		m_pRecordset->PutCollect("SID", var.iVal);

		var.iVal=m_IsPass;
		m_pRecordset->PutCollect("IsPass", var.iVal);

		var.iVal = m_Score;
		m_pRecordset->PutCollect("Score", var.iVal);

		m_pRecordset->Update();

		AfxMessageBox("�޸ĳɹ�!");			
	}
	catch(_com_error *e)
	{
		AfxMessageBox(e->ErrorMessage());
	}
}

void CPageCho::OnButtonFirst() 
{
	m_pRecordset->MoveFirst();
	_variant_t var;
	CString str;		
	
	try
	{
		var = m_pRecordset->GetCollect("CID");
		if(var.vt != VT_NULL)		
		m_CID = var.iVal ;

		var = m_pRecordset->GetCollect("SID");
		if(var.vt != VT_NULL)		
		m_SID = var.iVal;

		var = m_pRecordset->GetCollect("IsPass");
		if(var.vt != VT_NULL)		
		m_IsPass = var.iVal;

		var = m_pRecordset->GetCollect("Score");		
		m_Score = var.iVal;
	
		UpdateData(false);
	}
	catch(_com_error *e)
	{
		AfxMessageBox(e->ErrorMessage());
	}	
	// TODO: Add your control notification handler code here
	
}

void CPageCho::OnButtonPrevious() 
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

		var = m_pRecordset->GetCollect("SID");
		if(var.vt != VT_NULL)		
		m_SID = var.iVal;

		var = m_pRecordset->GetCollect("IsPass");
		if(var.vt != VT_NULL)		
		m_IsPass = var.iVal;

		var = m_pRecordset->GetCollect("Score");		
		m_Score = var.iVal; 
	
		UpdateData(false);
	}
	catch(_com_error *e)
	{
		AfxMessageBox(e->ErrorMessage());
	}	
	// TODO: Add your control notification handler code here
	
}

void CPageCho::OnButtonNext() 
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

		var = m_pRecordset->GetCollect("SID");		
		m_SID = var.iVal;

		var = m_pRecordset->GetCollect("IsPass");
		if(var.vt != VT_NULL)		
		m_IsPass = var.iVal;

		var = m_pRecordset->GetCollect("Score");		
		m_Score = var.iVal; 
	
		UpdateData(false);
	}
	catch(_com_error *e)
	{
		AfxMessageBox(e->ErrorMessage());
	}
	// TODO: Add your control notification handler code here
	
}

void CPageCho::OnButtonLast() 
{
	m_pRecordset->MoveLast();
	_variant_t var;
	CString str;		
	
	try
	{
		var = m_pRecordset->GetCollect("CID");
		if(var.vt != VT_NULL)		
		m_CID = var.iVal;

		var = m_pRecordset->GetCollect("SID");
		if(var.vt != VT_NULL)		
		m_SID = var.iVal;

		var = m_pRecordset->GetCollect("IsPass");
		if(var.vt != VT_NULL)		
		m_IsPass = var.iVal;

		var = m_pRecordset->GetCollect("Score");		
		m_Score = var.iVal;
	
		UpdateData(false);
	}
	catch(_com_error *e)
	{
		AfxMessageBox(e->ErrorMessage());
	}	
	// TODO: Add your control notification handler code here
	
}

void CPageCho::OnButtonQuery() 
{
	m_CID = 0;
	m_Score =  0;
	m_SID = 0;
	m_IsPass = 0;
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

void CPageCho::OnButtonAdd() 
{
	//
	//��������ʾ�ؼ�һ�����֮ǰ�ĳ�ֵ
	//
	m_CID = 0;
	m_Score =  0;
	m_SID = 0;
	m_IsPass = 0;
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

void CPageCho::OnButtonDelete() 
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

void CPageCho::OnButtonModify() 
{
	//����FOUNCTIONֵ
	FOUNCTION = MODIFY;
	m_ctlSID.SetReadOnly();
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

void CPageCho::OnButtonOk() 
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

void CPageCho::OnButtonCancel() 
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

	m_ctlSID.SetReadOnly(FALSE);
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

		var = m_pRecordset->GetCollect("SID");
		if(var.vt != VT_NULL)		
		m_SID = var.iVal;

		var = m_pRecordset->GetCollect("IsPass");
		if(var.vt != VT_NULL)		
		m_IsPass = var.iVal;

		var = m_pRecordset->GetCollect("Score");		
		m_Score = var.iVal;
	
		UpdateData(false);
	}
	catch(_com_error *e)
	{
		AfxMessageBox(e->ErrorMessage());
	}	
	// TODO: Add your control notification handler code here
	
}
