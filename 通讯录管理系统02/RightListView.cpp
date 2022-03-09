// RightListView.cpp : implementation file
//

/*
	���ߣ��ų���

*/

#include "stdafx.h"
#include "AddressList.h"
#include "RightListView.h"
#include "RightPaneFrame.h"
#include "LeftTreeView.h"
#include "PerInfoView.h"
#include "AddRelationInfo.h"
#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#define ChunkSize 1024
/////////////////////////////////////////////////////////////////////////////
// CRightListView

IMPLEMENT_DYNCREATE(CRightListView, CFormView)

CRightListView::CRightListView()
	: CFormView(CRightListView::IDD)
{
	//{{AFX_DATA_INIT(CRightListView)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}

CRightListView::~CRightListView()
{
}

void CRightListView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CRightListView)
	DDX_Control(pDX, IDC_LIST, m_listCtrl);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CRightListView, CFormView)
	//{{AFX_MSG_MAP(CRightListView)
	ON_WM_SIZE()
	ON_NOTIFY(NM_CLICK, IDC_LIST, OnClickList)
	ON_NOTIFY(NM_DBLCLK, IDC_LIST, OnDblclkList)
	ON_NOTIFY(NM_KILLFOCUS, IDC_LIST, OnKillfocusList)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRightListView diagnostics

#ifdef _DEBUG
void CRightListView::AssertValid() const
{
	CFormView::AssertValid();
}

void CRightListView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CRightListView message handlers

void CRightListView::OnSize(UINT nType, int cx, int cy) 
{
	CFormView::OnSize(nType, cx, cy);	
	// TODO: Add your message handler code here
	CFormView::ShowScrollBar(SB_BOTH,FALSE);	
	if (GetSafeHwnd())
	{
		if (m_listCtrl.GetSafeHwnd())
		{
			CRect rect(0,0,cx,cy);
			m_listCtrl.MoveWindow(&rect);
		}
	}
}

void CRightListView::OnInitialUpdate() 
{
	CFormView::OnInitialUpdate();	
	// TODO: Add your specialized code here and/or call the base class
	CRect rect;
	m_listCtrl.GetClientRect(&rect);
	//�����б�ؼ����
	DWORD dwStyle=::GetWindowLong(m_hWnd,GWL_STYLE);
    dwStyle|=LVS_REPORT|LVS_SHOWSELALWAYS|LVS_EDITLABELS;	
	::SetWindowLong(m_hWnd,GWL_STYLE,dwStyle);
	dwStyle=m_listCtrl.GetExtendedStyle();
	dwStyle|=LVS_EX_FULLROWSELECT;//LVS_EX_GRIDLINES|
    //������չ���
	m_listCtrl.SetExtendedStyle(dwStyle);	
	m_listCtrl.InsertColumn(0, "����", LVCFMT_LEFT, rect.Width());
	m_listCtrl.InsertColumn(1, "��ϵ", LVCFMT_LEFT, rect.Width());
	m_listCtrl.InsertColumn(2, "��λ", LVCFMT_LEFT, rect.Width());
	m_listCtrl.InsertColumn(3, "��Ƭ", LVCFMT_LEFT, rect.Width());
	//�������������ʾ����������������Ϊ0
	m_listCtrl.InsertColumn(4, "�������", LVCFMT_LEFT, 0);
}

void CRightListView::OnClickList(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	CMainFrame* pMainFrm=(CMainFrame*)AfxGetMainWnd();
	CRightPaneFrame* pRightFrm;
	CLeftTreeView* pLeftView;
	CPerInfoView*  pPerInfo;
	pLeftView=(CLeftTreeView*)pMainFrm->m_wndSplitter.GetPane(0,0);
	pRightFrm=(CRightPaneFrame*)pMainFrm->m_wndSplitter.GetPane(0,1);
	pPerInfo=pRightFrm->m_pPerInfoView;
	//Ѱ�ҵ�ǰѡ�еļ�¼��λ��
	POSITION pos=m_listCtrl.GetFirstSelectedItemPosition();
    //��ȡ��ǰ��¼��λ���α�
	int iIndex=m_listCtrl.GetNextSelectedItem(pos);
	if(iIndex==-1)
	{
		return;
	}
	//��ȡ���������ݿ��е����
	CString strName,strFirClass,strSecClass;
	strName=m_listCtrl.GetItemText(iIndex,0);
	strFirClass=m_listCtrl.GetItemText(iIndex,1);
	strSecClass=m_listCtrl.GetItemText(iIndex,4);
	//���ò�ѯ���
	CString strSQL;
	strSQL.Format("select * from info where ����='%s' \
		and һ�����='%s' and �������='%s'",\
		strName,strFirClass,strSecClass);
	//�򿪼�¼�� ѡ�����
	if(!OpenRecordSet(m_pRecordset,strSQL))
	{
		AfxMessageBox("û�гɹ������ݱ�");
		return;
	}	
	//Ӧ��ֻ��һ����¼
	m_pRecordset->MoveFirst();
	pPerInfo->m_strName=pLeftView->VariantToCString(m_pRecordset->GetCollect("����"));
	pPerInfo->m_strCompany=pLeftView->VariantToCString(m_pRecordset->GetCollect("������λ"));
	pPerInfo->m_strCompanyAdd=pLeftView->VariantToCString(m_pRecordset->GetCollect("��λ��ַ"));
	pPerInfo->m_strComTel=pLeftView->VariantToCString(m_pRecordset->GetCollect("�칫�绰"));
	pPerInfo->m_strHomeAdd=pLeftView->VariantToCString(m_pRecordset->GetCollect("��ͥ��ַ"));
	pPerInfo->m_strHomeTel=pLeftView->VariantToCString(m_pRecordset->GetCollect("��ͥ�绰"));
	pPerInfo->m_strMobile=pLeftView->VariantToCString(m_pRecordset->GetCollect("�ƶ��绰"));
	pPerInfo->m_strEmail=pLeftView->VariantToCString(m_pRecordset->GetCollect("�����ʼ�"));
	pPerInfo->m_strWeb=pLeftView->VariantToCString(m_pRecordset->GetCollect("������ҳ"));
	pPerInfo->m_strComment=pLeftView->VariantToCString(m_pRecordset->GetCollect("��ע"));	
	//�������� 
	pPerInfo->m_Birthday=m_pRecordset->GetCollect("��������");
	//��Ƭ��Ϣ
	//·������Ľ��
	CString strCurDir,strTem;
	char chCurDir[MAX_PATH];
	//���0
	memset(chCurDir,0,MAX_PATH);
	::GetModuleFileName(NULL,chCurDir,sizeof(chCurDir));
	strCurDir.Format("%s",chCurDir);
	//ȡ��ģ�����Ĵ�exe����֮������ಿ��
	strCurDir=strCurDir.Left(strCurDir.ReverseFind('\\'));
	strCurDir=strCurDir+"\\tem.bmp";
	if(SetDbToFile(m_pRecordset,strCurDir))
	{
		pPerInfo->ReadBmpToMem(strCurDir);
	}
	pPerInfo->UpdateData(FALSE);
	//�ر�
	m_pRecordset->Close();
	m_pRecordset=NULL;
	*pResult = 0;
}

void CRightListView::OnDblclkList(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	CMainFrame* pMainFrm=(CMainFrame*)AfxGetMainWnd();
	CLeftTreeView* pLeftView;
	pLeftView=(CLeftTreeView*)pMainFrm->m_wndSplitter.GetPane(0,0);
	//Ѱ�ҵ�ǰѡ�еļ�¼��λ��
	POSITION pos=m_listCtrl.GetFirstSelectedItemPosition();
    //��ȡ��ǰ��¼��λ���α�
	int iIndex=m_listCtrl.GetNextSelectedItem(pos);
	if(iIndex==-1)
	{
		return;
	}
	//��ȡ���������ݿ��е����
	CString strName,strFirClass,strSecClass;
	strName=m_listCtrl.GetItemText(iIndex,0);
	strFirClass=m_listCtrl.GetItemText(iIndex,1);
	strSecClass=m_listCtrl.GetItemText(iIndex,4);
	//���ò�ѯ���
	CString strSQL;
	strSQL.Format("select * from info where ����='%s' \
		and һ�����='%s' and �������='%s'",\
		strName,strFirClass,strSecClass);
	//�򿪼�¼�� ѡ�����
	if(!OpenRecordSet(m_pRecordset,strSQL))
	{
		AfxMessageBox("û�гɹ������ݱ�");
		return;
	}
	m_pRecordset->MoveFirst();
	//�Ի������
	CAddRelationInfo dlg;
	dlg.m_strTitle="�༭��ϵ����Ϣ";
	//�����Ϣ
	dlg.m_strFirClass=strFirClass;
	dlg.m_strSecClass=strSecClass;
	//����������༭
	dlg.bEdit=TRUE;
	dlg.m_strName=pLeftView->VariantToCString(m_pRecordset->GetCollect("����"));
	dlg.m_strComName=pLeftView->VariantToCString(m_pRecordset->GetCollect("������λ"));
	dlg.m_strComAddre=pLeftView->VariantToCString(m_pRecordset->GetCollect("��λ��ַ"));
	dlg.m_strOfficeTel=pLeftView->VariantToCString(m_pRecordset->GetCollect("�칫�绰"));
	dlg.m_strHomeAddre=pLeftView->VariantToCString(m_pRecordset->GetCollect("��ͥ��ַ"));
	dlg.m_strHomeTel=pLeftView->VariantToCString(m_pRecordset->GetCollect("��ͥ�绰"));
	dlg.m_strMobile=pLeftView->VariantToCString(m_pRecordset->GetCollect("�ƶ��绰"));
	dlg.m_strEmail=pLeftView->VariantToCString(m_pRecordset->GetCollect("�����ʼ�"));
	dlg.m_strWeb=pLeftView->VariantToCString(m_pRecordset->GetCollect("������ҳ"));
	dlg.m_strComment=pLeftView->VariantToCString(m_pRecordset->GetCollect("��ע"));	
	//�������� 
	dlg.m_OleBirthDay=m_pRecordset->GetCollect("��������");
	//׼�����
	dlg.DoModal();
	*pResult = 0;
}

BOOL CRightListView::OpenRecordSet(_RecordsetPtr &recPtr, CString &strSQL)
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
		strError.Format("���棺 �����ݱ�ʱ�����쳣�� ������Ϣ�� %s",\
			e.ErrorMessage());
		AfxMessageBox(strError);
		return FALSE;
	}
	return TRUE;
}

BOOL CRightListView::SetDbToFile(_RecordsetPtr &recPtr, CString &strPath)
{
	long lPhotoSize = recPtr->Fields->Item["��Ƭ"]->ActualSize;
	//���û����Ƭ�򷵻�
	if(lPhotoSize==0)
	{
		return FALSE;
	}
	//����Ƭ
	long lIsRead=0;   
	CFile f;
	f.Open(strPath,CFile::modeWrite|CFile::modeCreate);
	_variant_t varChunk;
	BYTE buf[ChunkSize];
	while(lPhotoSize>0)
	{
		lIsRead=lPhotoSize>=ChunkSize? ChunkSize:lPhotoSize;
		
		//���ֶ�data�л�ȡһ�����ݰ�
		varChunk = recPtr->Fields->
			Item["��Ƭ"]->GetChunk(lIsRead);
		for(long index=0;index<lIsRead;index++)         
		{           
			::SafeArrayGetElement(varChunk.parray,&index,buf+index);   
		}		
		//�����ݰ�д���ļ�
		f.Write(buf,lIsRead);
		lPhotoSize-=lIsRead;
	}
	f.Close();
	return TRUE;
}

void CRightListView::OnKillfocusList(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	CMainFrame* pMainFrm=(CMainFrame*)AfxGetMainWnd();
	//Ѱ�ҵ�ǰѡ�еļ�¼��λ��
	POSITION pos=m_listCtrl.GetFirstSelectedItemPosition();
    //��ȡ��ǰ��¼��λ���α�
	int iIndex=m_listCtrl.GetNextSelectedItem(pos);
	if(iIndex!=-1)
	{
		//ʹ��ǰ��ѡ����ѡ��maskΪLVIS_SELECTED|LVIS_FOCUSED��״̬��Ϊ0���ɣ���
		m_listCtrl.SetItemState(iIndex,0, LVIS_SELECTED|LVIS_FOCUSED);
		pMainFrm->bListSel=TRUE;
	}
	*pResult = 0;
}
