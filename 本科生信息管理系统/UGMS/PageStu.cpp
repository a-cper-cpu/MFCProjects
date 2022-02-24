// PageStu.cpp : implementation file
//

#include "stdafx.h"
#include "UGMS.h"
#include "PageStu.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPageStu dialog


CPageStu::CPageStu(CWnd* pParent /*=NULL*/)
	: CDialog(CPageStu::IDD, pParent)
{
	//{{AFX_DATA_INIT(CPageStu)
	m_SComeDate = COleDateTime::GetCurrentTime();
	m_SID = 0;
	m_SName = _T("");
	m_SSex = -1;
	//}}AFX_DATA_INIT
}


void CPageStu::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPageStu)
	DDX_Control(pDX, IDC_EDIT_SID, m_ctlSID);
	DDX_Control(pDX, IDC_BUTTON_QUERY, m_btnQuery);
	DDX_Control(pDX, IDC_BUTTON_PREVIOUS, m_btnPre);
	DDX_Control(pDX, IDC_BUTTON_OK, m_btnOk);
	DDX_Control(pDX, IDC_BUTTON_NEXT, m_btnNext);
	DDX_Control(pDX, IDC_BUTTON_MODIFY, m_btnModify);
	DDX_Control(pDX, IDC_BUTTON_LAST, m_btnLast);
	DDX_Control(pDX, IDC_BUTTON_FIRST, m_btnFirst);
	DDX_Control(pDX, IDC_BUTTON_DELETE, m_btnDel);
	DDX_Control(pDX, IDC_BUTTON_ADD, m_btnAdd);
	DDX_DateTimeCtrl(pDX, IDC_DATETIMEPICKER_SCOMEDATE, m_SComeDate);
	DDX_Text(pDX, IDC_EDIT_SID, m_SID);
	DDX_Text(pDX, IDC_EDIT_SNAME, m_SName);
	DDX_CBIndex(pDX, IDC_COMBO_SSEX, m_SSex);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CPageStu, CDialog)
	//{{AFX_MSG_MAP(CPageStu)
	ON_BN_CLICKED(IDC_BUTTON_FIRST, OnButtonFirst)
	ON_BN_CLICKED(IDC_BUTTON_QUERY, OnButtonQuery)
	ON_BN_CLICKED(IDC_BUTTON_ADD, OnButtonAdd)
	ON_BN_CLICKED(IDC_BUTTON_DELETE, OnButtonDelete)
	ON_BN_CLICKED(IDC_BUTTON_MODIFY, OnButtonModify)
	ON_BN_CLICKED(IDC_BUTTON_PREVIOUS, OnButtonPrevious)
	ON_BN_CLICKED(IDC_BUTTON_NEXT, OnButtonNext)
	ON_BN_CLICKED(IDC_BUTTON_LAST, OnButtonLast)
	ON_BN_CLICKED(IDC_BUTTON_OK, OnButtonOk)
	ON_BN_CLICKED(IDC_BUTTON_CANCEL, OnButtonCancel)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPageStu message handlers
//
//���ö�ٱ�����ʵ�ֶԲ�ͬ���ܵ�����
//
enum enumSTU
{
	NONE,		//��Ӧû�й���
	SEARCH,		//��Ӧ���ҹ���
	ADD,		//��Ӧ��ӹ���
	DEL,		//��Ӧɾ������
	MODIFY,		//��Ӧ�޸Ĺ���
};

//����ö�ٱ���FOUNCTION
enumSTU FOUNCTION = NONE;
BOOL CPageStu::OnInitDialog()
{	
	CDialog::OnInitDialog();
	// TODO: ADD extra initialization here
	//������¼������
	m_pRecordset.CreateInstance(__uuidof(Recordset));
	m_pRecordsetCHO.CreateInstance(__uuidof(Recordset));

	//��STUDENTS��
	OpenSTUDENTS();

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
		//���±༭��m_SID		
		var = m_pRecordset->GetCollect("SID");
		if(var.vt != VT_NULL)		
		m_SID = var.iVal ;

        //���±༭��m_SName
		var = m_pRecordset->GetCollect("SName");
		str = (LPCSTR)_bstr_t(var);
		m_SName = str;

        //������Ͽ�m_SSex
		var = m_pRecordset->GetCollect("SSex");
		m_SSex = var.iVal;

        //���¿ؼ�Date Time picker m_SComeDate
		var = m_pRecordset->GetCollect("SComeDate");		
		m_SComeDate = var.date;

	    //�������пؼ���ʾ
		UpdateData(false);
	}
	catch(_com_error *e)
	{
		AfxMessageBox(e->ErrorMessage());
	}

	return TRUE;

}
void CPageStu::OpenSTUDENTS()
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
//////////////////////////
//
//ִ�в��ҹ���
//
/////////////////////////
void CPageStu::Query()
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
			var = m_pRecordset->GetCollect("SID");			
			if(m_SID == var.iVal)
			{
				var = m_pRecordset->GetCollect("SID");
				if(var.vt != VT_NULL)
				{
					m_SID = var.iVal;
				}

				var = m_pRecordset->GetCollect("SName");
				str = (LPCSTR)_bstr_t(var);
				m_SName = str;

				var = m_pRecordset->GetCollect("SSex");
				if(var.vt != VT_NULL)
				{
					m_SSex = var.iVal;
				}

				var = m_pRecordset->GetCollect("SComeDate");		
				m_SComeDate = var.date;

			
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
			MessageBox("û�����ѧ�ţ�");
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
void CPageStu::Add()
{
	//�������
	_variant_t var;
	CString str;
	//���¿ؼ�������ֵ
	UpdateData(true);

    //�ж�Ҫ��ӵ�ѧ���Ƿ����
	if(m_SID != 0 && !m_pRecordset->BOF)
	{
		m_pRecordset->MoveFirst();
		while(!m_pRecordset->adoEOF)
		{
			var = m_pRecordset->GetCollect("SID");
			if(m_SID == var.iVal)
			{
				AfxMessageBox("�Ѿ��������ѧ�ţ�");
				break;
			}
			m_pRecordset->MoveNext();
		}
		if(!m_pRecordset->adoEOF)
		{
			return;
		}
	}

	if(m_SID == 0 )
	{
		AfxMessageBox("ѧ����Ϣ����Ϊ��!");
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

			//д��SID�ֶ�
			var.iVal = m_SID;
			m_pRecordset->PutCollect("SID", var.iVal);

			//д��SName�ֶ�			
			m_pRecordset->PutCollect("SName", _variant_t(m_SName));

			//д��SSex�ֶ�
			var.iVal=m_SSex;
			m_pRecordset->PutCollect("SSex", var.iVal);

			//д��SComeDate�ֶ�
			var.date =m_SComeDate;
			m_pRecordset->PutCollect("SComeDate", var.date);

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
void CPageStu::Delete()
{
	//�������
	_variant_t var;
	CString str;

	//�жϵ�ǰ�Ƿ��м�¼
	if(m_SID == 0)
	{
		MessageBox(" û�м�¼��");
		return;
	}
	//�ж��Ƿ���Ϊ�����ʹ��
	str.Format("select * from CHOICES where SID = %d",m_SID);
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
		var = m_pRecordset->GetCollect("SID");
		if(var.vt != VT_NULL)		
		m_SID = var.iVal ;

		var = m_pRecordset->GetCollect("SName");
		str = (LPCSTR)_bstr_t(var);
		m_SName = str;

		var = m_pRecordset->GetCollect("SSex");
		m_SSex = var.iVal;

		var = m_pRecordset->GetCollect("SComeDate");		
		m_SComeDate = var.date;	
	
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
void CPageStu::Modify()
{
	//�������
	_variant_t var;
	CString str;
	//���¿ؼ�������ֵ
	UpdateData(true);	

	if(m_SID == 0 )
	{
		AfxMessageBox("ѧ����Ϣ����Ϊ��!");
		return;
	}
	//
	// �޸ĵ�ǰ��¼���ֶ�ֵ
	//
	try
	{
		var.iVal = m_SID;
		m_pRecordset->PutCollect("SID", var.iVal);
		
		m_pRecordset->PutCollect("SName", _variant_t(m_SName));

		var.iVal=m_SSex;
		m_pRecordset->PutCollect("SSex", var.iVal);

		var.date = m_SComeDate;
	    m_pRecordset->PutCollect("SComeDate", var.date);

		m_pRecordset->Update();

		AfxMessageBox("�޸ĳɹ�!");			
	}
	catch(_com_error *e)
	{
		AfxMessageBox(e->ErrorMessage());
	}
}
void CPageStu::OnButtonFirst() 
{
	m_pRecordset->MoveFirst();
	_variant_t var;
	CString str;		
	
	try
	{
		var = m_pRecordset->GetCollect("SID");
		if(var.vt != VT_NULL)		
		m_SID = var.iVal ;

		var = m_pRecordset->GetCollect("SName");
		str = (LPCSTR)_bstr_t(var);
		m_SName = str;

		var = m_pRecordset->GetCollect("SSex");
		m_SSex =var.iVal;

		var = m_pRecordset->GetCollect("SComeDate");		
		m_SComeDate= var.date;
	
		UpdateData(false);
	}
	catch(_com_error *e)
	{
		AfxMessageBox(e->ErrorMessage());
	}	
	// TODO: Add your control notification handler code here
}

void CPageStu::OnButtonQuery() 
{
	// TODO: Add your control notification handler code here
	m_SID = 0;
	m_SName = "";
	m_SSex = 0;
	m_SComeDate.SetDate(2007, 9, 1);
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
	
}

void CPageStu::OnButtonAdd() 
{
	// TODO: Add your control notification handler code here
	//
	//��������ʾ�ؼ�һ�����֮ǰ�ĳ�ֵ
	//
	m_SID = 0;
	m_SName = "";
	m_SSex = 0;
	m_SComeDate.SetDate(2007, 9, 1);
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
	
}

void CPageStu::OnButtonDelete() 
{
	// TODO: Add your control notification handler code here
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
	
}

void CPageStu::OnButtonModify() 
{
	// TODO: Add your control notification handler code here
	//����FOUNCTIONֵ
	FOUNCTION = MODIFY;
	m_ctlSID.SetReadOnly();
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
	
}

void CPageStu::OnButtonPrevious() 
{
	// TODO: Add your control notification handler code here
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
		var = m_pRecordset->GetCollect("SID");
		if(var.vt != VT_NULL)		
		m_SID = var.iVal;

		var = m_pRecordset->GetCollect("SName");
		str = (LPCSTR)_bstr_t(var);
		m_SName = str;

		var = m_pRecordset->GetCollect("SSex");
		m_SSex = var.iVal;

		var = m_pRecordset->GetCollect("SComeDate");		
		m_SComeDate = var.date;
	
		UpdateData(false);
	}
	catch(_com_error *e)
	{
		AfxMessageBox(e->ErrorMessage());
	}	
	
}

void CPageStu::OnButtonNext() 
{
	// TODO: Add your control notification handler code here
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
		var = m_pRecordset->GetCollect("SID");
		if(var.vt != VT_NULL)		
		m_SID = var.iVal;

		var = m_pRecordset->GetCollect("SName");
		str = (LPCSTR)_bstr_t(var);
		m_SName = str;

		var = m_pRecordset->GetCollect("SSex");
		m_SSex = var.iVal;

		var = m_pRecordset->GetCollect("SComeDate");		
		m_SComeDate= var.date;	
	
		UpdateData(false);
	}
	catch(_com_error *e)
	{
		AfxMessageBox(e->ErrorMessage());
	}	
	
}

void CPageStu::OnButtonLast() 
{
	// TODO: Add your control notification handler code here
	m_pRecordset->MoveLast();
	_variant_t var;
	CString str;		
	
	try
	{
		var = m_pRecordset->GetCollect("SID");
		if(var.vt != VT_NULL)		
		m_SID = var.iVal;

		var = m_pRecordset->GetCollect("SName");
		str = (LPCSTR)_bstr_t(var);
		m_SName = str;

		var = m_pRecordset->GetCollect("SSex");
		m_SSex = var.iVal;

		var = m_pRecordset->GetCollect("SComeDate");		
		m_SComeDate= var.date;
	
		UpdateData(false);
	}
	catch(_com_error *e)
	{
		AfxMessageBox(e->ErrorMessage());
	}	
	
}

void CPageStu::OnButtonOk() 
{
	// TODO: ADD your control notification handler code here	
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

void CPageStu::OnButtonCancel() 
{
	// TODO: Add your control notification handler code here
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
		var = m_pRecordset->GetCollect("SID");
		if(var.vt != VT_NULL)		
		m_SID = var.iVal ;

		var = m_pRecordset->GetCollect("SName");
		str = (LPCSTR)_bstr_t(var);
		m_SName = str;

		var = m_pRecordset->GetCollect("SSex");
		m_SSex =var.iVal;

		var = m_pRecordset->GetCollect("SComeDate");		
		m_SComeDate = var.date;	
	
		UpdateData(false);
	}
	catch(_com_error *e)
	{
		AfxMessageBox(e->ErrorMessage());
	}	
	
}
