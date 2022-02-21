// GPACalculatorDlg.cpp : implementation file
//

#include "stdafx.h"
#include "GPACalculator.h"
#include "GPACalculatorDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

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
// CGPACalculatorDlg dialog

CGPACalculatorDlg::CGPACalculatorDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CGPACalculatorDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CGPACalculatorDlg)
	m_sPathName = _T("");
	m_dS1 = 0.0;
	m_dS2 = 0.0;
	m_dS3 = 0.0;
	m_dS4 = 0.0;
	m_dS5 = 0.0;
	m_dS6 = 0.0;
	m_dS7 = 0.0;
	m_dO1 = 0.0;
	m_dO2 = 0.0;
	m_dO3 = 0.0;
	m_dO4 = 0.0;
	m_dO5 = 0.0;
	m_dO6 = 0.0;
	m_dO7 = 0.0;
	m_dO8 = 0.0;
	m_dTotal = 0.0;
	m_strAverage = _T("");
	m_strGPA = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CGPACalculatorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CGPACalculatorDlg)
	DDX_Control(pDX, IDC_LIST_SCORE, m_ListScore);
	DDX_Control(pDX, IDC_COMBO_STANDARD, m_cmbStandard);
	DDX_Text(pDX, IDC_EDIT_PATHNAME, m_sPathName);
	DDX_Text(pDX, IDC_EDIT_S1, m_dS1);
	DDX_Text(pDX, IDC_EDIT_S2, m_dS2);
	DDX_Text(pDX, IDC_EDIT_S3, m_dS3);
	DDX_Text(pDX, IDC_EDIT_S4, m_dS4);
	DDX_Text(pDX, IDC_EDIT_S5, m_dS5);
	DDX_Text(pDX, IDC_EDIT_S6, m_dS6);
	DDX_Text(pDX, IDC_EDIT_S7, m_dS7);
	DDX_Text(pDX, IDC_EDIT_O1, m_dO1);
	DDX_Text(pDX, IDC_EDIT_O2, m_dO2);
	DDX_Text(pDX, IDC_EDIT_O3, m_dO3);
	DDX_Text(pDX, IDC_EDIT_O4, m_dO4);
	DDX_Text(pDX, IDC_EDIT_O5, m_dO5);
	DDX_Text(pDX, IDC_EDIT_O6, m_dO6);
	DDX_Text(pDX, IDC_EDIT_O7, m_dO7);
	DDX_Text(pDX, IDC_EDIT_O8, m_dO8);
	DDX_Text(pDX, IDC_EDIT_TOTAL, m_dTotal);
	DDX_Text(pDX, IDC_EDIT_AVERAGE, m_strAverage);
	DDX_Text(pDX, IDC_EDIT_GPA, m_strGPA);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CGPACalculatorDlg, CDialog)
	//{{AFX_MSG_MAP(CGPACalculatorDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_OPEN, OnButtonOpen)
	ON_COMMAND(ID_MENUITEM_MAN, OnMenuitemMan)
	ON_COMMAND(ID_MENUITEM_ABOUT, OnMenuitemAbout)
	ON_COMMAND(ID_MENUITEM_EXIT, OnMenuitemExit)
	ON_CBN_SELCHANGE(IDC_COMBO_STANDARD, OnSelchangeComboStandard)
	ON_WM_CTLCOLOR()
	ON_BN_CLICKED(IDC_BUTTON_OK, OnButtonOk)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CGPACalculatorDlg message handlers

BOOL CGPACalculatorDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

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
	m_cmbStandard.SetCurSel(0);
	SetEditRead(true);
	ChangeType(0);


	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CGPACalculatorDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CGPACalculatorDlg::OnPaint() 
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
HCURSOR CGPACalculatorDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CGPACalculatorDlg::OnButtonOpen() 
{
	CFileDialog fdlg(true, NULL, NULL, OFN_OVERWRITEPROMPT, "成绩文件|*.dat;*.txt|", NULL);
	if(fdlg.DoModal()==IDOK){
		m_sPathName=fdlg.GetPathName();

	}
	UpdateData(false);
	// TODO: Add your control notification handler code here
	
}

void CGPACalculatorDlg::OnMenuitemMan() 
{
	WinExec("notepad.exe EXPLAIN.HEP",SW_SHOW);
	// TODO: Add your command handler code here
	
}

void CGPACalculatorDlg::OnMenuitemAbout() 
{
	CAboutDlg dlg;
	dlg.DoModal();
	// TODO: Add your command handler code here
	
}

void CGPACalculatorDlg::OnMenuitemExit() 
{
	DestroyWindow();
	// TODO: Add your command handler code here
	
}

void CGPACalculatorDlg::ChangeType(int nType)
{
	switch(nType)
	{
	case 0:
	case 4:
		m_dS1=m_dS2=m_dS3=m_dS4=m_dS5=m_dS6=m_dS7=0;
		m_dO1=m_dO2=m_dO3=m_dO4=m_dO5=m_dO6=m_dO7=m_dO8=0;		
		break;
	case 1:
		m_dS1=4;
		m_dS2=3;
		m_dS3=2;
		m_dS4=1;
		m_dS5=m_dO6=m_dO7=0;
		m_dO1=100;
		m_dO2=90;
		m_dO3=80;
		m_dO4=70;
		m_dO5=60;
		m_dO6=m_dO7=m_dO8=0;
		break;
	case 2:
		m_dS1=4.3;
		m_dS2=4;
		m_dS3=3.7;
		m_dS4=3.3;
		m_dS5=3.0;
		m_dO6=2.7;
		m_dO7=2.3;
		m_dO1=100;
		m_dO2=90;
		m_dO3=85;
		m_dO4=80;
		m_dO5=75;
		m_dO6=70;
		m_dO7=65;
		m_dO8=60;
		break;
	case 3:
		m_dS1=4;
		m_dS2=3;
		m_dS3=2;
		m_dS4=m_dS5=m_dO6=m_dO7=0;
		m_dO1=100;
		m_dO2=85;
		m_dO3=70;
		m_dO4=60;
		m_dO5=m_dO6=m_dO7=m_dO8=0;
		break;

	}

}

void CGPACalculatorDlg::SetEditRead(bool bReadOnly)
{

	((CEdit *)GetDlgItem(IDC_EDIT_S1))->SetReadOnly(bReadOnly);
	((CEdit *)GetDlgItem(IDC_EDIT_S2))->SetReadOnly(bReadOnly);
	((CEdit *)GetDlgItem(IDC_EDIT_S3))->SetReadOnly(bReadOnly);
	((CEdit *)GetDlgItem(IDC_EDIT_S4))->SetReadOnly(bReadOnly);
	((CEdit *)GetDlgItem(IDC_EDIT_S5))->SetReadOnly(bReadOnly);
	((CEdit *)GetDlgItem(IDC_EDIT_S6))->SetReadOnly(bReadOnly);
	((CEdit *)GetDlgItem(IDC_EDIT_S7))->SetReadOnly(bReadOnly);

	((CEdit *)GetDlgItem(IDC_EDIT_O1))->SetReadOnly(bReadOnly);
	((CEdit *)GetDlgItem(IDC_EDIT_O2))->SetReadOnly(bReadOnly);
	((CEdit *)GetDlgItem(IDC_EDIT_O3))->SetReadOnly(bReadOnly);
	((CEdit *)GetDlgItem(IDC_EDIT_O4))->SetReadOnly(bReadOnly);
	((CEdit *)GetDlgItem(IDC_EDIT_O5))->SetReadOnly(bReadOnly);
	((CEdit *)GetDlgItem(IDC_EDIT_O6))->SetReadOnly(bReadOnly);
	((CEdit *)GetDlgItem(IDC_EDIT_O7))->SetReadOnly(bReadOnly);
	((CEdit *)GetDlgItem(IDC_EDIT_O8))->SetReadOnly(bReadOnly);




}

void CGPACalculatorDlg::OnSelchangeComboStandard() 
{
	// TODO: Add your control notification handler code here
	int nIndex=m_cmbStandard.GetCurSel();
	if(4==nIndex)
		SetEditRead(false);
	
	else
		SetEditRead(true);
	ChangeType(nIndex);
	UpdateData(false);

	
}

HBRUSH CGPACalculatorDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
	
	// TODO: Change any attributes of the DC here
	switch(pWnd->GetDlgCtrlID())
	{
	case IDC_EDIT_S1:
	case IDC_EDIT_S2:
	case IDC_EDIT_S3:
	case IDC_EDIT_S4:
	case IDC_EDIT_S5:
	case IDC_EDIT_S6:
	case IDC_EDIT_S7:
	case IDC_EDIT_O1:
	case IDC_EDIT_O2:
	case IDC_EDIT_O3:
	case IDC_EDIT_O4:
	case IDC_EDIT_O5:
	case IDC_EDIT_O6:
	case IDC_EDIT_O7:
	case IDC_EDIT_O8:
		pDC->SetBkColor(RGB(255,255,255));
		pDC->SetTextColor(RGB(0,0,255));
		break;
	case IDC_LIST_SCORE:
		pDC->SetBkColor(RGB(255,255,255));
		pDC->SetTextColor(RGB(0,0,255));
		break;
	case IDC_EDIT_AVERAGE:
	case IDC_EDIT_GPA:
	case IDC_EDIT_TOTAL:
		pDC->SetBkColor(RGB(255,255,255));
		pDC->SetTextColor(RGB(255,0,255));



	}
	
	// TODO: Return a different brush if the default is not desired
	return hbr;
}

void CGPACalculatorDlg::OnButtonOk() 
{
	double dGPAall=0;
	double dAvgall=0;


	GatherData();
	int i=0;
	int size=arScore.GetSize();
	if(size==0)
	{
		return;
	}
	m_ListScore.ResetContent();
	m_ListScore.AddString("序号    成绩    学分   标准");
	m_ListScore.AddString("---------------------------");
	m_dTotal=0;
	while(i<size)
	{
		CString str;
		m_dTotal+=arScore.GetAt(i).dNum;
		dGPAall+=arScore.GetAt(i).dSPoint*arScore.GetAt(i).dNum;
		dAvgall+=arScore.GetAt(i).dOPoint*arScore.GetAt(i).dNum;
		
		str.Format("%d    %0.2f    %0.2f    %0.2f",i+1,arScore.GetAt(i).dOPoint,arScore.GetAt(i).dNum,arScore.GetAt(i).dSPoint);
		i++;
		m_ListScore.AddString(str);
	}


	m_strGPA.Format("%.2f",dGPAall/m_dTotal);
	m_strAverage.Format("%.2f",dAvgall/m_dTotal);
	UpdateData(false);

   




	
}

double CGPACalculatorDlg::GetSDPoint(double dPoint)
{
	UpdateData();
	CArray<double,double&> arOPoint;
	CArray<double,double&> arSPoint;
	arOPoint.Add(m_dO1);
	arOPoint.Add(m_dO2);
	arOPoint.Add(m_dO3);
	arOPoint.Add(m_dO4);
	arOPoint.Add(m_dO5);
	arOPoint.Add(m_dO6);
	arOPoint.Add(m_dO7);
	arOPoint.Add(m_dO8);

	arSPoint.Add(m_dS1);
	arSPoint.Add(m_dS2);
	arSPoint.Add(m_dS3);
	arSPoint.Add(m_dS4);
	arSPoint.Add(m_dS5);
	arSPoint.Add(m_dS6);
	arSPoint.Add(m_dS7);

	if(dPoint>=arOPoint[0])
		return arSPoint[0];
	for(int i=0;i<arOPoint.GetSize();i++)
	{
		if(dPoint>=arOPoint[i])
			return arSPoint[i-1];
	}
	return 0;
}

void CGPACalculatorDlg::SpliterString(CString str, double &a, double &b)
{
	CString strOne,strTwo;
	int ifind;

	str.TrimLeft(' ');
	str.TrimRight(' ');

	ifind=str.Find(' ');
	strOne=str.Left(ifind);
	strTwo=str.Right(str.GetLength()-ifind-1);

	a=atof(LPCTSTR(strOne));
	b=atof(LPCTSTR(strTwo));

}

void CGPACalculatorDlg::GatherData()
{	
	CString str;
	stScore temp;

	if(m_sPathName=="")
		return;

	arScore.RemoveAll();
	CFile file(m_sPathName,CFile::modeRead);
	CArchive ar(&file,CArchive::load);

	ar.ReadString(str);
	while(str!="")
	{
		SpliterString(str,temp.dOPoint,temp.dNum);
		temp.dSPoint=GetSDPoint(temp.dOPoint);
		arScore.Add(temp);

		ar.ReadString(str);

	};


}
