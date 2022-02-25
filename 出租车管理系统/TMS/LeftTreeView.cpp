// LeftTreeView.cpp : implementation file
//

#include "stdafx.h"
#include "TMS.h"
#include "LeftTreeView.h"
#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CLeftTreeView

IMPLEMENT_DYNCREATE(CLeftTreeView, CTreeView)

CLeftTreeView::CLeftTreeView()
{
}

CLeftTreeView::~CLeftTreeView()
{
}


BEGIN_MESSAGE_MAP(CLeftTreeView, CTreeView)
	//{{AFX_MSG_MAP(CLeftTreeView)
	ON_NOTIFY_REFLECT(TVN_SELCHANGED, OnSelchanged)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLeftTreeView drawing

void CLeftTreeView::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	// TODO: add draw code here
}

/////////////////////////////////////////////////////////////////////////////
// CLeftTreeView diagnostics

#ifdef _DEBUG
void CLeftTreeView::AssertValid() const
{
	CTreeView::AssertValid();
}

void CLeftTreeView::Dump(CDumpContext& dc) const
{
	CTreeView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CLeftTreeView message handlers

void CLeftTreeView::FullfillTree()
{
	//���
	CTreeCtrl* pCtrl = &GetTreeCtrl();
	pCtrl->DeleteAllItems();
	//�������
	AddMainToTree("��������");
	AddMainToTree("˾������");
	AddMainToTree("��������");
	//�������
	AddItem("��������","������ϸ");
	AddItem("��������","��������");
	AddItem("��������","��������");

	AddItem("˾������","˾����ϸ");
	AddItem("˾������","Υ����¼");
	AddItem("˾������","���ͼ�¼");

	AddItem("��������","���ɷ���");
	AddItem("��������","���ù���");
	AddItem("��������","�޸�����");
	

}

HTREEITEM  CLeftTreeView::AddMainToTree(CString strMainItem)
{
	CTreeCtrl* pCtrl = &GetTreeCtrl();
	HTREEITEM hRootItem = pCtrl->GetRootItem();
	if(hRootItem)
	{
		while(hRootItem)
		{
			CString strItemText = pCtrl->GetItemText(hRootItem);
			if(strItemText == strMainItem)
				return hRootItem;
			hRootItem = pCtrl->GetNextSiblingItem(hRootItem);
		}
	}
	TV_INSERTSTRUCT TCItem;//�������������ݽṹ
	TCItem.hParent = TVI_ROOT;
	TCItem.hInsertAfter = TVI_LAST;
	TCItem.item.mask=TVIF_TEXT|TVIF_PARAM|TVIF_IMAGE|TVIF_SELECTEDIMAGE;//������
	TCItem.item.lParam=0;//���
	TCItem.item.iImage=0;//����ͼ��
	TCItem.item.iSelectedImage=0;//ѡ��ʱͼ��

	TCItem.item.pszText = (LPTSTR)(LPCTSTR)strMainItem;
	HTREEITEM hSectionItem = pCtrl->InsertItem(&TCItem);
//	pCtrl->SortChildren(TVI_ROOT);
	return hSectionItem;

}

HTREEITEM  CLeftTreeView::AddSubToTree(HTREEITEM hTypeItem, CString strSubItem)
{
	if(hTypeItem == NULL)
		return NULL;
	CTreeCtrl* pCtrl = &GetTreeCtrl();
	if(pCtrl->ItemHasChildren(hTypeItem))
	{
		HTREEITEM hItem = pCtrl->GetChildItem(hTypeItem);
		while(hItem)
		{
			CString strItemText = pCtrl->GetItemText(hItem);
			if(strItemText == strSubItem)
				return hItem;
			hItem = pCtrl->GetNextSiblingItem(hItem);
		}
	}
	TV_INSERTSTRUCT TCItem;//�������������ݽṹ
	TCItem.hParent = hTypeItem;
	TCItem.hInsertAfter = TVI_LAST;
	TCItem.item.mask=TVIF_TEXT|TVIF_PARAM|TVIF_IMAGE|TVIF_SELECTEDIMAGE;//������
	TCItem.item.lParam=0;//���
	TCItem.item.iImage=2;//����ͼ��
	TCItem.item.iSelectedImage=2;//ѡ��ʱͼ��

	TCItem.item.pszText = (LPTSTR)(LPCTSTR)strSubItem;
	HTREEITEM hRoomItem = pCtrl->InsertItem(&TCItem);

//	pCtrl->SortChildren(hTypeItem);
	return hRoomItem;

}

void CLeftTreeView::AddItem(CString strMainItem,CString strSubItem)
{
	CTreeCtrl* pCtrl = &GetTreeCtrl();
	HTREEITEM hRootItem = pCtrl->GetRootItem();
	if(hRootItem)
	{
		while(hRootItem)
		{
			CString strItemText = pCtrl->GetItemText(hRootItem);
			if(strItemText == strMainItem)
				break;
			hRootItem = pCtrl->GetNextSiblingItem(hRootItem);
		}
		AddSubToTree(hRootItem,strSubItem);
	}


}

void CLeftTreeView::OnInitialUpdate() 
{
	CTreeView::OnInitialUpdate();
	//���������
	::SetWindowLong(m_hWnd,GWL_STYLE,WS_VISIBLE | WS_TABSTOP 
						| WS_CHILD | WS_BORDER| TVS_HASBUTTONS 
						| TVS_LINESATROOT | TVS_HASLINES
						| TVS_DISABLEDRAGDROP|TVS_SHOWSELALWAYS);

	//Ϊ����ͼ����ͼ������
	CTMSApp* pApp = (CTMSApp*)AfxGetApp();
	CTreeCtrl* pTreeCtrl = &GetTreeCtrl();
	m_ImageList.Create(16,16,ILC_COLOR16,4,4);
	m_ImageList.Add(pApp->LoadIcon(IDI_ICON_MAIN));
	m_ImageList.Add(pApp->LoadIcon(IDI_ICON_MAIN));
	m_ImageList.Add(pApp->LoadIcon(IDI_ICON_SUB));
	m_ImageList.Add(pApp->LoadIcon(IDI_ICON_SUB));
	pTreeCtrl->SetImageList(&m_ImageList,TVSIL_NORMAL);

	//����������
	FullfillTree();
//	pTreeCtrl->SortChildren(TVI_ROOT);
	m_hHitItem=pTreeCtrl->GetFirstVisibleItem();
	
	// TODO: Add your specialized code here and/or call the base class
	
}

void CLeftTreeView::OnSelchanged(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_TREEVIEW* pNMTreeView = (NM_TREEVIEW*)pNMHDR;
	// TODO: Add your control notification handler code here
	//��ñ�ѡ����
	CTreeCtrl* pCtrl = &GetTreeCtrl();
	HTREEITEM hSelItem = pCtrl->GetSelectedItem();
	m_hHitItem = hSelItem;

	//���ѡ���������
	CString strSel=pCtrl->GetItemText(hSelItem);

	//���û���ѡ�����ұߵ��б���ͼ���
	CMainFrame* pFrame = (CMainFrame*)AfxGetApp()->m_pMainWnd;
	if(hSelItem == NULL)
	{		
		pFrame->SwitchToView(MAINITEMVIEW);		
		return;
	}

	//�ж�ѡ���������е�λ��
	HTREEITEM hParentItem = pCtrl->GetParentItem(hSelItem);
	if(hParentItem == NULL)
	{
		if(strSel=="��������")
			SelItemType=1;
		else if(strSel=="˾������")
			SelItemType=2;
		else if(strSel=="��������")
			SelItemType=3;
		else
			SelItemType=0;
	

	}		
	else
	{
		CString strPSel=pCtrl->GetItemText(hParentItem);
		if(strPSel=="��������")
			SelItemType=10;
		else if(strPSel=="˾������")
			SelItemType=20;
		else if(strPSel=="��������")
			SelItemType=30;
		else
			SelItemType=0;

		if(strSel=="������ϸ"||strSel=="˾����ϸ"||strSel=="���ɷ���")
			SelItemType+=1;
		else if(strSel=="��������"||strSel=="Υ����¼"||strSel=="���ù���")
			SelItemType+=2;
		else if(strSel=="��������"||strSel=="���ͼ�¼"||strSel=="�޸�����")
			SelItemType+=3;
		else
			SelItemType+=0;


	}
		pFrame->ShowView();


	
	*pResult = 0;
}
