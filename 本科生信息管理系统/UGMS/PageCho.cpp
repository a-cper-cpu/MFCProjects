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
//??????????????????????????????????
//
enum enumCHO
{
	NONE,		//????????????
	SEARCH,		//????????????
	ADD,		//????????????
	DEL,		//????????????
	MODIFY,		//????????????
};

//????????????FOUNCTION
enumCHO FOUNCTION = NONE;

BOOL CPageCho::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: ADD extra initialization here
	//??????????????
	m_pRecordset.CreateInstance(__uuidof(Recordset));
	//????CHOICES??
	OpenCHOICES();

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

        //??????????m_SID
		var = m_pRecordset->GetCollect("SID");
		if(var.vt != VT_NULL)		
		m_SID = var.iVal;

        //??????????IsPass
		var = m_pRecordset->GetCollect("IsPass");
		if(var.vt != VT_NULL)		
		m_IsPass = var.iVal;

        //??????????m_Score
		var = m_pRecordset->GetCollect("Score");		
		m_Score = var.iVal;

	    //????????????????
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
	//??ADO??????????????????????try...catch()??????????????,
    //????????????????????????????????????
	try
	{
		//??SQL????????????STUDENTS??
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
		//??SQL????????????COURSES??
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
		//??SQL????????????CHOICES??
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
//????????????
//
/////////////////////////
void CPageCho::Query()
{
	//????????
	_variant_t var,varCou,varStu;
	CString str;
	//????????????????
	UpdateData(true);

	if(m_SID == 0 || m_CID == 0)
	{
		MessageBox("??????????????????????????!");
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
			//????????????????????????????
			//??????????????????????????????????????????
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
			MessageBox("????????????????????");
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
void CPageCho::Add()
{
	//????????
	_variant_t var,ar;
	CString str;
	//????????????????
	UpdateData(true);

	//????????????????????????????????
	if(m_SID !=0)
	{
        m_pRecordset->Close();

		OpenSTUDENTS();

		if(m_pRecordset->BOF)
		{
			AfxMessageBox("????????????????????????????");
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
				AfxMessageBox("??????????????");
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

	//??????????????????????????????????
	if(m_CID !=0)
	{
        m_pRecordset->Close();

		OpenCOURSES();

		if(m_pRecordset->BOF)
		{
			AfxMessageBox("????????????????????????????");
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
				AfxMessageBox("????????????????");
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

    //????????????????????????????????
	if(m_SID != 0 && m_CID != 0 && !m_pRecordset->BOF)
	{
		m_pRecordset->MoveFirst();
		while(!m_pRecordset->adoEOF)
		{
			var = m_pRecordset->GetCollect("SID");
			ar = m_pRecordset->GetCollect("CID");
			if(m_SID == var.iVal && m_CID == ar.iVal)
			{
				AfxMessageBox("??????????");
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
		AfxMessageBox("??????????????????????????!");
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

			//????SID????
			var.iVal = m_SID;
			m_pRecordset->PutCollect("SID", var.iVal);

			//????IsPass????
			var.iVal=m_IsPass;
			m_pRecordset->PutCollect("IsPass", var.iVal);

			//????Score????
			var.iVal = m_Score;
			m_pRecordset->PutCollect("Score", var.iVal);

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
void CPageCho::Delete()
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
//????????????
//
/////////////////////////
void CPageCho::Modify()
{
	//????????
	_variant_t var;
	CString str;
	//????????????????
	UpdateData(true);

	if(m_CID == 0 || m_SID == 0)
	{
		AfxMessageBox("??????????????????????????!");
		return;
	}
	//
	// ????????????????????
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

		AfxMessageBox("????????!");			
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
		MessageBox("??????????????");
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
		MessageBox("??????????????");
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

void CPageCho::OnButtonAdd() 
{
	//
	//????????????????????????????????
	//
	m_CID = 0;
	m_Score =  0;
	m_SID = 0;
	m_IsPass = 0;
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

void CPageCho::OnButtonDelete() 
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

void CPageCho::OnButtonModify() 
{
	//????FOUNCTION??
	FOUNCTION = MODIFY;
	m_ctlSID.SetReadOnly();
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

	m_ctlSID.SetReadOnly(FALSE);
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
