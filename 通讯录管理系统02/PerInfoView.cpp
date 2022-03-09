// PerInfoView.cpp : implementation file
//

/*
	作者：张超刚

*/

#include "stdafx.h"
#include "AddressList.h"
#include "PerInfoView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPerInfoView

IMPLEMENT_DYNCREATE(CPerInfoView, CFormView)

CPerInfoView::CPerInfoView()
	: CFormView(CPerInfoView::IDD)
{
	//{{AFX_DATA_INIT(CPerInfoView)
	m_Birthday = COleDateTime::GetCurrentTime();
	m_strCompanyAdd = _T("");
	m_strComment = _T("");
	m_strCompany = _T("");
	m_strComTel = _T("");
	m_strEmail = _T("");
	m_strHomeAdd = _T("");
	m_strHomeTel = _T("");
	m_strMobile = _T("");
	m_strName = _T("");
	m_strWeb = _T("");
	//}}AFX_DATA_INIT
}

CPerInfoView::~CPerInfoView()
{
}

void CPerInfoView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPerInfoView)
	DDX_DateTimeCtrl(pDX, IDC_BIRTHDAY_PICKER, m_Birthday);
	DDX_Text(pDX, IDC_EDIT_COMADD, m_strCompanyAdd);
	DDX_Text(pDX, IDC_EDIT_COMMENT, m_strComment);
	DDX_Text(pDX, IDC_EDIT_COMPANY, m_strCompany);
	DDX_Text(pDX, IDC_EDIT_COMTEL, m_strComTel);
	DDX_Text(pDX, IDC_EDIT_EMAIL, m_strEmail);
	DDX_Text(pDX, IDC_EDIT_HOMEADD, m_strHomeAdd);
	DDX_Text(pDX, IDC_EDIT_HOMETEL, m_strHomeTel);
	DDX_Text(pDX, IDC_EDIT_MOBILE, m_strMobile);
	DDX_Text(pDX, IDC_EDIT_NAME, m_strName);
	DDX_Text(pDX, IDC_EDIT_WEB, m_strWeb);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CPerInfoView, CFormView)
	//{{AFX_MSG_MAP(CPerInfoView)
	ON_WM_SIZE()
	ON_WM_PAINT()
	ON_BN_CLICKED(IDC_CHECK_STRETCH, OnCheckStretch)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPerInfoView diagnostics

#ifdef _DEBUG
void CPerInfoView::AssertValid() const
{
	CFormView::AssertValid();
}

void CPerInfoView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CPerInfoView message handlers

void CPerInfoView::OnSize(UINT nType, int cx, int cy) 
{
	CFormView::OnSize(nType, cx, cy);	
	// TODO: Add your message handler code here
	CFormView::ShowScrollBar(SB_BOTH,FALSE);
	if (GetSafeHwnd())
	{
		CWnd* pGroup=(CWnd*)GetDlgItem(IDC_GROUP_INFO);
		if (pGroup->GetSafeHwnd())
		{
			CRect recGroup;
			pGroup->GetClientRect(&recGroup);			
			CRect recOffset(recGroup.right+35,recGroup.top+15,
				recGroup.right+35+recGroup.right*3/5,recGroup.bottom-8);
			m_recOffset.CopyRect(&recOffset);
		}
	}
}

void CPerInfoView::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	
	// TODO: Add your message handler code here
	CRect recGroup;
	if (m_Bitmap.GetSafeHandle() != NULL)
	{		
		if (GetSafeHwnd())
		{
			CWnd* pGroup=(CWnd*)GetDlgItem(IDC_GROUP_INFO);
			if (pGroup->GetSafeHwnd())
			{
				pGroup->GetClientRect(&recGroup);
				CRect recOffset(recGroup.right+35,recGroup.top+15,
					recGroup.right+35+recGroup.right*3/5,recGroup.bottom-8);
				m_recOffset.CopyRect(&recOffset);
				
				CDC memDC;
				BITMAP bm;
				m_Bitmap.GetBitmap(&bm);
				memDC.CreateCompatibleDC(&dc);
				CBitmap *oldbitmap = memDC.SelectObject(&m_Bitmap);
				//设置拉伸模式
				dc.SetStretchBltMode(HALFTONE);
				//判断复选按钮的状态
				CButton* pCheckStretch=(CButton*)GetDlgItem(IDC_CHECK_STRETCH);
				if(pCheckStretch->GetCheck())
				{
					//拉伸图像
					dc.StretchBlt(m_recOffset.left,m_recOffset.top,
						m_recOffset.right-m_recOffset.left,m_recOffset.bottom-
						m_recOffset.top,
						&memDC,0,0,bm.bmWidth,bm.bmHeight,SRCCOPY);
				}
				else
				{
					dc.BitBlt(recOffset.left,recOffset.top,
					recOffset.right,recOffset.bottom,&memDC, 0, 0, SRCCOPY);
				}
				memDC.SelectObject(oldbitmap);
			}
		}
	}
	
	// Do not call CFormView::OnPaint() for painting messages
}

void CPerInfoView::OnCheckStretch()
{
	// TODO: Add your control notification handler code here
	InvalidateRect(&m_recOffset);
}

void CPerInfoView::ReadBmpToMem(CString &strPath)
{
	CFile photoBmp;
	//打开指定的文件
	if (photoBmp.Open(strPath, CFile::modeRead))
	{
		LONG fileSize=(LONG)photoBmp.GetLength();
		//分配内存
		char *pDib=new char[fileSize+1];
		//读到内存
		if (photoBmp.Read(pDib,fileSize)==(DWORD)fileSize)
		{
			BITMAPFILEHEADER	bmfHeader;
			DWORD bmfHeaderLen=sizeof(bmfHeader);
			strncpy((LPSTR)&bmfHeader,(LPSTR)pDib,bmfHeaderLen);
			if (bmfHeader.bfType==(*(WORD*)"BM"))
			{
				LPSTR lpDIB =pDib+ bmfHeaderLen;
				BITMAPINFOHEADER &bmiHeader = *(LPBITMAPINFOHEADER)lpDIB;
				BITMAPINFO &bmInfo = *(LPBITMAPINFO)lpDIB;				
				LPVOID lpDIBBits =pDib+((BITMAPFILEHEADER*)pDib)->bfOffBits;
				//创建设备上下文
				CWindowDC dc(this);
				HBITMAP hBmp = CreateDIBitmap(dc.m_hDC, &bmiHeader,
					CBM_INIT,lpDIBBits, &bmInfo, DIB_RGB_COLORS);
				if (m_Bitmap.GetSafeHandle()!=NULL)
				{
					m_Bitmap.DeleteObject();
				}
				//将位图绑定到CBitMap对象
				m_Bitmap.Attach(hBmp);
			}
		}
		delete[] pDib;
		pDib = NULL;					
	}
	InvalidateRect(&m_recOffset);
}
