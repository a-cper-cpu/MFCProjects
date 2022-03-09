// AddRelationInfo.cpp : implementation file
//

/*
	���ߣ��ų���

*/

#include "stdafx.h"
#include "AddressList.h"
#include "AddRelationInfo.h"
#include "MainFrm.h"
#include "LeftTreeView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAddRelationInfo dialog

#define ChunkSize 1024

CAddRelationInfo::CAddRelationInfo(CWnd* pParent /*=NULL*/)
	: CDialog(CAddRelationInfo::IDD, pParent)
{
	//{{AFX_DATA_INIT(CAddRelationInfo)
	m_strComment = _T("");
	m_strComAddre = _T("");
	m_strComName = _T("");
	m_strEmail = _T("");
	m_strHomeAddre = _T("");
	m_strHomeTel = _T("");
	m_strMobile = _T("");
	m_strOfficeTel = _T("");
	m_strWeb = _T("");
	m_strName = _T("");
	m_OleBirthDay = COleDateTime::GetCurrentTime();
	m_strFirClass = _T("");
	m_strSecClass = _T("");
	//}}AFX_DATA_INIT
}


void CAddRelationInfo::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAddRelationInfo)
	DDX_Control(pDX, IDC_SECOND_CLASS, m_ComboSecond);
	DDX_Control(pDX, IDC_FIRST_CLASS, m_ComboFirst);
	DDX_Text(pDX, IDC_COMMENT, m_strComment);
	DDX_Text(pDX, IDC_COMPANY_ADDRESS, m_strComAddre);
	DDX_Text(pDX, IDC_COMPANY_NAME, m_strComName);
	DDX_Text(pDX, IDC_EMAIL, m_strEmail);
	DDX_Text(pDX, IDC_HOME_ADDRESS, m_strHomeAddre);
	DDX_Text(pDX, IDC_HOME_TEL, m_strHomeTel);
	DDX_Text(pDX, IDC_MOBILE, m_strMobile);
	DDX_Text(pDX, IDC_OFFICE_TEL, m_strOfficeTel);
	DDX_Text(pDX, IDC_WEB, m_strWeb);
	DDX_Text(pDX, IDC_NAME, m_strName);
	DDX_DateTimeCtrl(pDX, IDC_BIRTHDAY, m_OleBirthDay);
	DDX_CBString(pDX, IDC_FIRST_CLASS, m_strFirClass);
	DDX_CBString(pDX, IDC_SECOND_CLASS, m_strSecClass);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CAddRelationInfo, CDialog)
	//{{AFX_MSG_MAP(CAddRelationInfo)
	ON_BN_CLICKED(IDC_INSERT_INFO, OnInsertInfo)
	ON_BN_CLICKED(IDC_PHOTO, OnPhoto)
	ON_CBN_SELENDOK(IDC_FIRST_CLASS, OnSelendokFirstClass)
	ON_BN_CLICKED(IDC_EDIT_INFO, OnEditInfo)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAddRelationInfo message handlers

void CAddRelationInfo::OnInsertInfo() 
{
	// TODO: Add your control notification handler code here	
	//�������
	CString strSQL;
	//���¿ؼ�������ֵ
	UpdateData(TRUE);
	//���������Ϊ��ʱ����
	m_ComboFirst.GetWindowText(m_strFirClass);
	m_ComboSecond.GetWindowText(m_strSecClass);
	m_strName.Remove(' ');//ɾ���ո�
	m_strFirClass.Remove(' ');
	m_strSecClass.Remove(' ');
	if(m_strName.IsEmpty()||m_strFirClass.IsEmpty()||m_strSecClass.IsEmpty())
	{
		AfxMessageBox("�����������Ϊ��");
		return;
	}
	//�򿪼�¼�� ѡ�����
	strSQL="select * from info";
	if(!OpenRecordSet(m_pRecordset,strSQL))
	{
		AfxMessageBox("û�гɹ������ݱ�");
		return;
	}
	//����׼����ϣ����濪ʼ��������
	try
	{
		//�������,����ֻ������Ӳ��������
		m_pRecordset->AddNew();
		m_pRecordset->PutCollect("����",_variant_t(m_strName));
		m_pRecordset->PutCollect("������λ",_variant_t(m_strComName));
		m_pRecordset->PutCollect("��λ��ַ",_variant_t(m_strComAddre));
		m_pRecordset->PutCollect("�칫�绰",_variant_t(m_strOfficeTel));
		m_pRecordset->PutCollect("��ͥ��ַ",_variant_t(m_strHomeAddre));
		m_pRecordset->PutCollect("��ͥ�绰",_variant_t(m_strHomeTel));
		m_pRecordset->PutCollect("�ƶ��绰",_variant_t(m_strMobile));
		m_pRecordset->PutCollect("�����ʼ�",_variant_t(m_strEmail));
		m_pRecordset->PutCollect("������ҳ",_variant_t(m_strWeb));
		m_pRecordset->PutCollect("��ע",_variant_t(m_strComment));
		//���
		CString strText;
		m_ComboFirst.GetWindowText(strText);
		m_pRecordset->PutCollect("һ�����",_variant_t(strText));
		m_ComboSecond.GetWindowText(strText);
		m_pRecordset->PutCollect("�������",_variant_t(strText));
		//�������� 
		COleDateTime oleTime;
		CDateTimeCtrl* pDtCtrl=(CDateTimeCtrl*)GetDlgItem(IDC_BIRTHDAY);
		pDtCtrl->GetTime(oleTime);
		m_pRecordset->PutCollect("��������",_variant_t(oleTime));
		//��Ƭ
		if(!m_strPhotoPath.IsEmpty())
		{
			SetFileToDb(m_pRecordset,m_strPhotoPath);
		}
		//�������ݿ�
		m_pRecordset->Update();		
		//��ǰ��¼�ƶ������
		m_pRecordset->MoveLast();
	}
	catch(_com_error e)
	{
		CString strError;
		strError.Format("���棺 ������Ϣʱ�����쳣�� ������Ϣ�� %s",\
			e.ErrorMessage());
		AfxMessageBox(strError);
	}
	m_pRecordset->Close();	
	m_pRecordset=NULL;

	AfxMessageBox("����ɹ�!");
	
	//������
	CMainFrame* pMainFrm=(CMainFrame*)AfxGetMainWnd();
	CLeftTreeView* pLeftView;
	pLeftView=(CLeftTreeView*)pMainFrm->m_wndSplitter.GetPane(0,0);	
	pLeftView->ShowTree();
	//�����ؼ�ֵ�ÿ�
	ResetCtrlValue();
}

void CAddRelationInfo::OnPhoto() 
{
	// TODO: Add your control notification handler code here
	CString strFilter="BMP Files(*.bmp)|*.bmp|All Files (*.*)|*.*||";
	CFileDialog dlg(TRUE,NULL,NULL,OFN_HIDEREADONLY|OFN_OVERWRITEPROMPT,strFilter);
	if (dlg.DoModal()!=IDOK)
	{
		return;
	}
	//��ȡ��Ƭ·����
	m_strPhotoPath=dlg.GetPathName();
}

void CAddRelationInfo::SetFileToDb(_RecordsetPtr &recPtr, CString strPath)
{
	VARIANT varChunk;
	SAFEARRAY *psa;
	SAFEARRAYBOUND rgsabound[1]; 	
	//VT_ARRAY | VT_UI1	
	CFile f(strPath.operator LPCTSTR(),CFile::modeRead);
	BYTE  bVal[ChunkSize+1];
	long uIsRead=0;
	//Create a safe array to store the array of BYTES  
	while(1)
	{
		//��ȡ��Ƭ
		uIsRead=f.Read(bVal,ChunkSize);
		if(uIsRead==0)break;
		rgsabound[0].cElements =uIsRead;
		rgsabound[0].lLbound = 0;		
		///����SAFEARRAY���� 
		psa = SafeArrayCreate(VT_UI1,1,rgsabound);
		
		for(long index=0;index<uIsRead;index++)          
		{
			if(FAILED(SafeArrayPutElement(psa,&index,&bVal[index])))
				::MessageBox(NULL,"����","��ʾ",MB_OK | MB_ICONWARNING);
		}		
		//ΪvarChunk������ֵ
		varChunk.vt = VT_ARRAY|VT_UI1;
		varChunk.parray = psa;		
		//����BLOB���͵�����
		try{
			recPtr->Fields->GetItem("��Ƭ")->AppendChunk(varChunk);
		}
		catch (_com_error &e)
		{
			CString str=(char*)e.Description();
			::MessageBox(NULL,str+"\n����","��ʾ",MB_OK | MB_ICONWARNING);
		}
		::VariantClear(&varChunk);
		::SafeArrayDestroyData( psa);
		if(uIsRead<ChunkSize)break;
	}
	f.Close();
}

BOOL CAddRelationInfo::OpenRecordSet(_RecordsetPtr &recPtr, CString &strSQL)
{
	CAddressListApp* pApp=(CAddressListApp*)AfxGetApp();
	//������¼������
	m_pRecordset.CreateInstance(__uuidof(Recordset));
	//��ADO�����н��������Ҫ����try...catch()�����������Ϣ,
    //��Ϊ����ʱ�ᾭ������һЩ�벻���Ĵ���
	try
	{
		//�����ݿ��д򿪱�
		recPtr->Open(strSQL.AllocSysString(), 
			pApp->m_pConnection.GetInterfacePtr(),
			adOpenDynamic,
			adLockOptimistic,
			adCmdText);
	}
	catch (_com_error e)
	{
		CString strError;
		strError.Format("���棺�����ݱ�ʱ�����쳣�� ������Ϣ�� %s",\
			e.ErrorMessage());
		AfxMessageBox(strError);
		return FALSE;
	}
	return TRUE;

}

void CAddRelationInfo::ResetCtrlValue()
{
	//��ʼ�����ؼ�ֵ
	m_strComment=_T("");
	m_strComAddre=_T("");
	m_strComName=_T("");
	m_strEmail=_T("");
	m_strHomeAddre=_T("");
	m_strHomeTel=_T("");
	m_strMobile=_T("");
	m_strOfficeTel=_T("");
	m_strWeb=_T("");
	m_strName=_T("");
	UpdateData(FALSE);
}

BOOL CAddRelationInfo::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	CMainFrame* pMainFrm=(CMainFrame*)AfxGetMainWnd();
	CLeftTreeView* pLeftView;
	pLeftView=(CLeftTreeView*)pMainFrm->m_wndSplitter.GetPane(0,0);
	CTreeCtrl& treeCtrl=pLeftView->m_treeCtrl;
	HTREEITEM hRootItem,hChildItem;
	hRootItem=treeCtrl.GetRootItem();
	//��ʼ����һ����Ͽ�
	//���ַ�������ֻ�����м����
	CString strTextTem;
	if(hRootItem)
	{
		hChildItem=treeCtrl.GetChildItem(hRootItem);
		if(hChildItem)
		{
			while(hChildItem)
			{
				//���������Ա��Ժ�ʹ��
				m_hItemList.AddTail(hChildItem);
				strTextTem=treeCtrl.GetItemText(hChildItem);
				//���ַ������ݼ�����Ͽ�
				m_ComboFirst.AddString(strTextTem);
				hChildItem=treeCtrl.GetNextSiblingItem(hChildItem);
			}
			//��һ����Ͽ�Ĭ��ѡ��
			if(!bEdit)
			{
				m_ComboFirst.SetCurSel(0);
				m_ComboFirst.GetLBText(m_ComboFirst.GetCurSel(),m_strFirClass);
			}
			else
			{
				m_ComboSecond.SetWindowText(m_strFirClass);
			}
			//���Ծ�������ѭ����strText��������������һ��һ�����
		}
	}
	
	//��ʼ���ڶ�����Ͽ�
	HTREEITEM hSelItem;
	POSITION pos;
	pos=m_hItemList.GetHeadPosition();
	while(pos)
	{
		hSelItem=m_hItemList.GetNext(pos);
		CString strCur;
		strCur=treeCtrl.GetItemText(hSelItem);
		//�ҵ���Ӧ����󣬽�������ȫ������ڶ�����Ͽ�
		if(!m_strFirClass.Compare(strCur))
		{			
			//��ȡ�������
			hChildItem=treeCtrl.GetChildItem(hSelItem);
			if(hChildItem)
			{
				while(hChildItem)
				{//��ȡ�������ı��Ⲣ������Ͽ�
					strTextTem=treeCtrl.GetItemText(hChildItem);
					//���ַ������ݼ�����Ͽ�
					m_ComboSecond.AddString(strTextTem);
					hChildItem=treeCtrl.GetNextSiblingItem(hChildItem);
				}
				//Ĭ��ѡ��
				if(!bEdit)
				{
					m_ComboSecond.SetCurSel(0);
				}
				else
				{
					m_ComboSecond.SetWindowText(m_strSecClass);
				}
			}
			break;
		}
	}
	//���öԻ������
	SetWindowText(m_strTitle);
	CEdit* pEdit=(CEdit*)GetDlgItem(IDC_NAME);
	//��ǰ�Ի����Ƿ������༭���������Ȳ�����༭
	pEdit->EnableWindow(!bEdit);
	m_ComboSecond.EnableWindow(!bEdit);
	m_ComboFirst.EnableWindow(!bEdit);
	if(bEdit)
	{
		CButton* pButton=(CButton*)GetDlgItem(IDC_INSERT_INFO);
		pButton->ShowWindow(SW_HIDE);
		pButton=(CButton*)GetDlgItem(IDOK);
		pButton->ShowWindow(SW_HIDE);
	}
	else
	{
		CButton* pButton=(CButton*)GetDlgItem(IDC_EDIT_INFO);
		pButton->ShowWindow(SW_HIDE);
		pButton=(CButton*)GetDlgItem(IDCANCEL);
		pButton->ShowWindow(SW_HIDE);
	}
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CAddRelationInfo::OnSelendokFirstClass() 
{
	// TODO: Add your control notification handler code here
	CMainFrame* pMainFrm=(CMainFrame*)AfxGetMainWnd();
	CLeftTreeView* pLeftView;
	pLeftView=(CLeftTreeView*)pMainFrm->m_wndSplitter.GetPane(0,0);
	CTreeCtrl& treeCtrl=pLeftView->m_treeCtrl;
	HTREEITEM hChildItem,hSelItem;
	CString strText;
	m_ComboFirst.GetLBText(m_ComboFirst.GetCurSel(),strText);
	//��ʼ���ڶ�����Ͽ�,�����������Ͽ�����������
	m_ComboSecond.ResetContent();
	POSITION pos;
	pos=m_hItemList.GetHeadPosition();
	while(pos)
	{
		hSelItem=m_hItemList.GetNext(pos);
		CString strCur;
		strCur=treeCtrl.GetItemText(hSelItem);
		//�ҵ���Ӧ����󣬽�������ȫ������ڶ�����Ͽ�
		if(!strText.Compare(strCur))
		{			
			hChildItem=treeCtrl.GetChildItem(hSelItem);
			if(hChildItem)
			{
				while(hChildItem)
				{
					strText=treeCtrl.GetItemText(hChildItem);
					m_ComboSecond.AddString(strText);
					hChildItem=treeCtrl.GetNextSiblingItem(hChildItem);
				}
			}
			break;
		}
	}
	m_ComboSecond.SetCurSel(0);
}

void CAddRelationInfo::OnEditInfo() 
{
	// TODO: Add your control notification handler code here
	//�������
	CString strSQL;
	//���¿ؼ�������ֵ
	UpdateData(TRUE);
/*	//���������Ϊ��ʱ����
	m_ComboFirst.GetWindowText(m_strFirClass);
	m_ComboSecond.GetWindowText(m_strSecClass);
	m_strFirClass.Remove(' ');//ɾ���ո�
	m_strSecClass.Remove(' ');
	if(m_strFirClass.IsEmpty()||m_strSecClass.IsEmpty())
	{
		AfxMessageBox("�����Ϊ��");
		return;
	}*/
	//�򿪼�¼�� ѡ�����
	CString strTem;
	strTem.Format("����='%s' and �������='%s' and һ�����='%s'\
		",m_strName,m_strSecClass,m_strFirClass);
	strSQL="select * from info where "+strTem;
	if(!OpenRecordSet(m_pRecordset,strSQL))
	{
		AfxMessageBox("û�гɹ������ݱ�");
		return;
	}
	if(!m_pRecordset->BOF)
	{
		m_pRecordset->MoveFirst();
	}
	//����׼����ϣ����濪ʼ��������
	try
	{
		//�������,������һ���������ֻ������Ӳ��������
//		m_pRecordset->PutCollect("����",_variant_t(m_strName));
		m_pRecordset->PutCollect("������λ",_variant_t(m_strComName));
		m_pRecordset->PutCollect("��λ��ַ",_variant_t(m_strComAddre));
		m_pRecordset->PutCollect("�칫�绰",_variant_t(m_strOfficeTel));
		m_pRecordset->PutCollect("��ͥ��ַ",_variant_t(m_strHomeAddre));
		m_pRecordset->PutCollect("��ͥ�绰",_variant_t(m_strHomeTel));
		m_pRecordset->PutCollect("�ƶ��绰",_variant_t(m_strMobile));
		m_pRecordset->PutCollect("�����ʼ�",_variant_t(m_strEmail));
		m_pRecordset->PutCollect("������ҳ",_variant_t(m_strWeb));
		m_pRecordset->PutCollect("��ע",_variant_t(m_strComment));
		//���
/*		CString strText;
		m_ComboFirst.GetWindowText(strText);
		m_pRecordset->PutCollect("һ�����",_variant_t(strText));
		m_ComboSecond.GetWindowText(strText);
		m_pRecordset->PutCollect("�������",_variant_t(strText));
		*/
		//�������� 
		COleDateTime oleTime;
		CDateTimeCtrl* pDtCtrl=(CDateTimeCtrl*)GetDlgItem(IDC_BIRTHDAY);
		pDtCtrl->GetTime(oleTime);
		m_pRecordset->PutCollect("��������",_variant_t(oleTime));
		//��Ƭ
		if(!m_strPhotoPath.IsEmpty())
		{
			SetFileToDb(m_pRecordset,m_strPhotoPath);
		}
		//�������ݿ�
		m_pRecordset->Update();		
		//��ǰ��¼�ƶ������
		m_pRecordset->MoveLast();
	}
	catch(_com_error e)
	{
		CString strError;
		strError.Format("���棺������Ϣʱ�����쳣��������Ϣ�� %s",\
			e.ErrorMessage());
		AfxMessageBox(strError);
	}
	m_pRecordset->Close();	
	m_pRecordset=NULL;	
	//�༭��ɺ󣬶Ի����Զ���ʧ��ģ����OK
	WPARAM wParam=MAKEWPARAM(IDOK,BN_CLICKED);
	SendMessage(WM_COMMAND,wParam);//����������Ϊ�ؼ����
	//������
	CMainFrame* pMainFrm=(CMainFrame*)AfxGetMainWnd();
	CLeftTreeView* pLeftView;
	pLeftView=(CLeftTreeView*)pMainFrm->m_wndSplitter.GetPane(0,0);	
	pLeftView->ShowTree();
	AfxMessageBox("�༭�ɹ�");
}
