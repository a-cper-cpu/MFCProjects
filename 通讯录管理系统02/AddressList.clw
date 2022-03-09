; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CAddressListApp
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "AddressList.h"
LastPage=0

ClassCount=10
Class1=CAddRelationInfo
Class2=CAddressListApp
Class3=CAboutDlg
Class4=CAddressListDoc
Class5=CAddressListView
Class6=CLeftTreeView
Class7=CMainFrame
Class8=CPerInfoView
Class9=CRightListView
Class10=CRightPaneFrame

ResourceCount=7
Resource1=IDD_TREE_VIEW
Resource2=IDD_INFO_VIEW
Resource3=IDD_ADD_INFO
Resource4=IDR_MAINFRAME
Resource5=IDD_ABOUTBOX
Resource6=IDD_LIST_VIEW
Resource7=IDD_QUERY

[CLS:CAddRelationInfo]
Type=0
BaseClass=CDialog
HeaderFile=AddRelationInfo.h
ImplementationFile=AddRelationInfo.cpp
Filter=D
VirtualFilter=dWC
LastObject=IDC_FIRST_CLASS

[CLS:CAddressListApp]
Type=0
BaseClass=CWinApp
HeaderFile=AddressList.h
ImplementationFile=AddressList.cpp
Filter=N
VirtualFilter=AC
LastObject=CAddressListApp

[CLS:CAboutDlg]
Type=0
BaseClass=CDialog
HeaderFile=AddressList.cpp
ImplementationFile=AddressList.cpp
LastObject=CAboutDlg

[CLS:CAddressListDoc]
Type=0
BaseClass=CDocument
HeaderFile=AddressListDoc.h
ImplementationFile=AddressListDoc.cpp

[CLS:CAddressListView]
Type=0
BaseClass=CView
HeaderFile=AddressListView.h
ImplementationFile=AddressListView.cpp

[CLS:CLeftTreeView]
Type=0
BaseClass=CFormView
HeaderFile=LeftTreeView.h
ImplementationFile=LeftTreeView.cpp
LastObject=IDC_TREE
Filter=D
VirtualFilter=VWC

[CLS:CMainFrame]
Type=0
BaseClass=CFrameWnd
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T
VirtualFilter=fWC
LastObject=CMainFrame

[CLS:CPerInfoView]
Type=0
BaseClass=CFormView
HeaderFile=PerInfoView.h
ImplementationFile=PerInfoView.cpp
Filter=D
VirtualFilter=VWC
LastObject=ID_MENUITEM_INFO

[CLS:CRightListView]
Type=0
BaseClass=CFormView
HeaderFile=RightListView.h
ImplementationFile=RightListView.cpp
Filter=D
VirtualFilter=VWC
LastObject=CRightListView

[CLS:CRightPaneFrame]
Type=0
BaseClass=CFrameWnd
HeaderFile=RightPaneFrame.h
ImplementationFile=RightPaneFrame.cpp
Filter=T
VirtualFilter=fWC
LastObject=CRightPaneFrame

[DLG:IDD_ADD_INFO]
Type=1
Class=CAddRelationInfo
ControlCount=32
Control1=IDC_NAME,edit,1350631552
Control2=IDC_STATIC,static,1342308352
Control3=IDC_COMPANY_ADDRESS,edit,1350631552
Control4=IDC_GROUP_INFO,button,1342177287
Control5=IDC_STATIC,static,1342308352
Control6=IDC_STATIC,static,1342308352
Control7=IDC_HOME_TEL,edit,1350631552
Control8=IDC_STATIC,static,1342308352
Control9=IDC_MOBILE,edit,1350631552
Control10=IDC_STATIC,static,1342308352
Control11=IDC_EMAIL,edit,1350631552
Control12=IDC_STATIC,static,1342308352
Control13=IDC_COMPANY_NAME,edit,1350631552
Control14=IDC_STATIC,static,1342308352
Control15=IDC_OFFICE_TEL,edit,1350631552
Control16=IDC_STATIC,static,1342308352
Control17=IDC_HOME_ADDRESS,edit,1350631552
Control18=IDC_STATIC,static,1342308352
Control19=IDC_WEB,edit,1350631552
Control20=IDC_COMMENT,edit,1350631552
Control21=IDC_STATIC,static,1342308352
Control22=IDC_STATIC,static,1342308352
Control23=IDC_FIRST_CLASS,combobox,1344340226
Control24=IDC_STATIC,static,1342308352
Control25=IDC_SECOND_CLASS,combobox,1344340226
Control26=IDC_PHOTO,button,1342242816
Control27=IDC_STATIC,static,1342308352
Control28=IDC_BIRTHDAY,SysDateTimePick32,1342242848
Control29=IDC_INSERT_INFO,button,1342242816
Control30=IDOK,button,1342242816
Control31=IDC_EDIT_INFO,button,1342242816
Control32=IDCANCEL,button,1342242816

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_TREE_VIEW]
Type=1
Class=CLeftTreeView
ControlCount=1
Control1=IDC_TREE,SysTreeView32,1350631427

[DLG:IDD_INFO_VIEW]
Type=1
Class=CPerInfoView
ControlCount=24
Control1=IDC_EDIT_NAME,edit,1350633600
Control2=IDC_STATIC,static,1342308352
Control3=IDC_EDIT_COMADD,edit,1350633600
Control4=IDC_GROUP_INFO,button,1342177287
Control5=IDC_STATIC,static,1342308352
Control6=IDC_STATIC,static,1342308352
Control7=IDC_EDIT_HOMETEL,edit,1350633600
Control8=IDC_STATIC,static,1342308352
Control9=IDC_EDIT_MOBILE,edit,1350633600
Control10=IDC_STATIC,static,1342308352
Control11=IDC_EDIT_EMAIL,edit,1350633600
Control12=IDC_STATIC,static,1342308352
Control13=IDC_STATIC,static,1342308352
Control14=IDC_EDIT_COMPANY,edit,1350633600
Control15=IDC_STATIC,static,1342308352
Control16=IDC_EDIT_COMTEL,edit,1350633600
Control17=IDC_STATIC,static,1342308352
Control18=IDC_EDIT_HOMEADD,edit,1350633600
Control19=IDC_STATIC,static,1342308352
Control20=IDC_EDIT_WEB,edit,1350633600
Control21=IDC_EDIT_COMMENT,edit,1350633600
Control22=IDC_BIRTHDAY_PICKER,SysDateTimePick32,1342242848
Control23=IDC_STATIC,static,1342308352
Control24=IDC_CHECK_STRETCH,button,1342242819

[DLG:IDD_LIST_VIEW]
Type=1
Class=CRightListView
ControlCount=1
Control1=IDC_LIST,SysListView32,1350631425

[MNU:IDR_MAINFRAME]
Type=1
Class=?
Command1=ID_QUERY
Command2=ID_APP_EXIT
Command3=ID_ADD_INFO
Command4=ID_DELETE_INFO
Command5=ID_VIEW_TOOLBAR
Command6=ID_VIEW_STATUS_BAR
Command7=ID_MENUITEM_INFO
Command8=ID_APP_ABOUT
CommandCount=8

[TB:IDR_MAINFRAME]
Type=1
Class=?
Command1=ID_ADD_INFO
Command2=ID_QUERY
Command3=ID_DELETE_INFO
Command4=ID_MENUITEM_INFO
Command5=ID_APP_ABOUT
Command6=ID_APP_EXIT
CommandCount=6

[ACL:IDR_MAINFRAME]
Type=1
Class=?
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_PRINT
Command5=ID_EDIT_UNDO
Command6=ID_EDIT_CUT
Command7=ID_EDIT_COPY
Command8=ID_EDIT_PASTE
Command9=ID_EDIT_UNDO
Command10=ID_EDIT_CUT
Command11=ID_EDIT_COPY
Command12=ID_EDIT_PASTE
Command13=ID_NEXT_PANE
Command14=ID_PREV_PANE
CommandCount=14

[DLG:IDD_QUERY]
Type=1
Class=?
ControlCount=12
Control1=IDC_FIELD_COMBO,combobox,1344339971
Control2=IDC_SQL_LIST,listbox,1352728833
Control3=IDC_RELATION_COMBO,combobox,1344339971
Control4=IDC_FIELD_EDIT,edit,1350631552
Control5=IDC_ADD_SQL,button,1342242816
Control6=IDC_REMOVE_SQL,button,1342242816
Control7=IDC_STATIC,static,1342308352
Control8=IDC_STATIC,static,1342308352
Control9=IDC_STATIC,button,1342177287
Control10=IDC_STATIC,static,1342308352
Control11=IDOK,button,1342242817
Control12=IDCANCEL,button,1342242816

