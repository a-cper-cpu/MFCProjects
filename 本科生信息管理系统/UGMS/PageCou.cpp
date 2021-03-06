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
	NONE,		//????????????
	SEARCH,		//????????????
	ADD,		//????????????
	DEL,		//????????????
	MODIFY,		//????????????
};

//????????????FOUNCTION
enumCOU FOUNCTION = NONE;
BOOL CPageCou::OnInitDialog()
{	
	CDialog::OnInitDialog();
	// TODO: ADD extra initialization here
	//??????????????
	m_pRecordset.CreateInstance(__uuidof(Recordset));
	m_pRecordsetCHO.CreateInstance(__uuidof(Recordset));

	//????COURSES??
	OpenCOURSES();

	_variant_t var;
	CString str;		
	
	try
	{
		if(!m_pRecordset->BOF)
		{
			m_pRecordset->MoveFirst();
		}
		//??????????????????????????????????????????
		else
		{
			AfxMessageBox("????????????");
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
		// ??????????????????????????
		//
		//??????????m_CID		
		var = m_pRecordset->GetCollect("CID");
		if(var.vt != VT_NULL)		
		m_CID = var.iVal ;

        //??????????m_CName
		var = m_pRecordset->GetCollect("CName");
		str = (LPCSTR)_bstr_t(var);
		m_CName = str;

        //??????????m_CScore
		var = m_pRecordset->GetCollect("CScore");
		m_CScore = var.iVal;

        //??????????m_CKind
		var = m_pRecordset->GetCollect("CKind");
		m_CKind = var.iVal;

	    //????????????????
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
	//??ADO??????????????????????try...catch()??????????????,
    //????????????????????????????????????
	try
	{
		//??SQL????????????STUDENTS??
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
//????????????
//
/////////////////////////
void CPageCou::Query()
{
	//????????
	_variant_t var;
	CString str;
	//????????????????
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
			MessageBox("????????????????");
		}
	}
	catch(_com_error *e)
	{
		AfxMessageBox(e->ErrorMessage());
	}
}
//////////////////////////
//
//????????????
//
/////////////////////////
void CPageCou::Add()
{
	//????????
	_variant_t var;
	CString str;
	//????????????????
	UpdateData(true);

    //??????????????????????????
	if(m_CID != 0 && !m_pRecordset->BOF)
	{
		m_pRecordset->MoveFirst();
		while(!m_pRecordset->adoEOF)
		{
			var = m_pRecordset->GetCollect("CID");
			if(m_CID == var.iVal)
			{
				AfxMessageBox("????????????????????");
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
		AfxMessageBox("??????????????????!");
		return;
	}	
	else
	{
		try
		{
			//
			// ????????????
			//
			m_pRecordset->AddNew();

			//????CID????
			var.iVal = m_CID;
			m_pRecordset->PutCollect("CID", var.iVal);

			//????CName????			
			m_pRecordset->PutCollect("CName", _variant_t(m_CName));

			//????CScore????
			var.iVal=m_CScore;
			m_pRecordset->PutCollect("CScore", var.iVal);

			//????CKind????
			var.iVal=m_CKind;
			m_pRecordset->PutCollect("CKind", var.iVal);
			//????SQL??????
			m_pRecordset->Update();

			//??????????????????
			m_pRecordset->MoveLast();

			AfxMessageBox("????????!");			
		}
		catch(_com_error *e)
		{
			AfxMessageBox(e->ErrorMessage());
		}
	}
}

//////////////////////////
//
//????????????
//
/////////////////////////
void CPageCou::Delete()
{
	//????????
	_variant_t var;
	CString str;

	//??????????????????
	if(m_CID == 0)
	{
		MessageBox(" ??????????");
		return;
	}
	//??????????????????????
	str.Format("select * from CHOICES where CID = %d",m_CID);
	m_pRecordsetCHO->Open(str.AllocSysString(), 
							theApp.m_pConnection.GetInterfacePtr(),
							adOpenDynamic,
							adLockOptimistic,
							adCmdText);
	if(!m_pRecordsetCHO->BOF)
	{
		AfxMessageBox("??????????????????????????????????");
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
		// ??????????????
		//
		m_pRecordset->Delete(adAffectCurrent);
		m_pRecordset->Update();

		m_pRecordset->MoveFirst();

		//??????????????????????????
		if(m_pRecordset->BOF)
		{
			AfxMessageBox("??????????????????");
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

		//????????????????		
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
//????????????
//
/////////////////////////
void CPageCou::Modify()
{
	//????????
	_variant_t var;
	CString str;
	//????????????????
	UpdateData(true);	

	if(m_CID == 0 )
	{
		AfxMessageBox("??????????????????!");
		return;
	}
	//
	// ????????????????????
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

		AfxMessageBox("????????!");			
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
		MessageBox("??????????????");
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
		MessageBox("??????????????");
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
    //????FOUNCTION??
	FOUNCTION = SEARCH;
	//??????????????????????
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
	//????????????????????????????????
	//
	m_CID = 0;
	m_CName = "";
	m_CScore = 0;
	m_CKind=0;
	UpdateData(false);
	//????FOUNCTION??
	FOUNCTION = ADD;
	//??????????????????????
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
	if(MessageBox("??????????\n??????????????\n??????????????", NULL, MB_YESNO | MB_ICONQUESTION) == IDYES)
	{
		//????FOUNCTION??
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
	//????FOUNCTION??
	FOUNCTION = MODIFY;
	m_ctlCID.SetReadOnly();
	//??????????????????????
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
	//??????????????????????????????
	if(m_pRecordset->BOF)
	{
		m_btnAdd.SetState(false);
		return;
	}	

	//??????????????????????
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
	//??m_pRecordset????????????????????
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
