; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CLeftTreeView
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "HMS.h"
LastPage=0

ClassCount=12
Class1=CHMSApp
Class2=CHMSDoc
Class3=CHMSView
Class4=CMainFrame

ResourceCount=11
Resource1=IDD_FORMVIEW_WELCOME (English (U.S.))
Resource2=IDR_MENU_ROOMTYPE
Class5=CAboutDlg
Class6=CRoomTypeView
Class7=CLeftTreeView
Class8=CUserListView
Resource3=IDR_MENU_BOOKIN
Resource4=IDD_ABOUTBOX
Resource5=IDR_MAINFRAME
Resource6=IDR_MENU_ROOM
Class9=CRoomTypeDlg
Resource7=IDD_DIALOG_USER
Resource8=IDD_DIALOG_BOOKOUT
Class10=CCustomerDlg
Resource9=IDD_FORMVIEW_TYPEINFO
Class11=CDelUserDlg
Resource10=IDD_DIALOG_TYPE
Class12=CRoomDlg
Resource11=IDD_DIALOG_ROOM

[CLS:CHMSApp]
Type=0
HeaderFile=HMS.h
ImplementationFile=HMS.cpp
Filter=N

[CLS:CHMSDoc]
Type=0
HeaderFile=HMSDoc.h
ImplementationFile=HMSDoc.cpp
Filter=N

[CLS:CHMSView]
Type=0
HeaderFile=HMSView.h
ImplementationFile=HMSView.cpp
Filter=C
BaseClass=CView
VirtualFilter=VWC


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T
LastObject=ID_BOOKIN_ADD
BaseClass=CFrameWnd
VirtualFilter=fWC




[CLS:CAboutDlg]
Type=0
HeaderFile=HMS.cpp
ImplementationFile=HMS.cpp
Filter=D
LastObject=CAboutDlg

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[MNU:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_TYPE_ADD
Command2=ID_TYPE_MODIFY
Command3=ID_TYPE_DEL
Command4=ID_ROOM_ADD
Command5=ID_ROOM_MODIFY
Command6=ID_ROOM_DEL
Command7=ID_BOOKIN_ADD
Command8=ID_BOOKIN_DEL
Command9=ID_APP_ABOUT
CommandCount=9

[ACL:IDR_MAINFRAME]
Type=1
Class=CMainFrame
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

[DLG:IDD_FORMVIEW_TYPEINFO]
Type=1
Class=CRoomTypeView
ControlCount=17
Control1=IDC_STATIC,static,1342308352
Control2=IDC_STATIC,static,1342308352
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC,static,1342308352
Control5=IDC_ROOMTYPE_ID,edit,1350633600
Control6=IDC_ROOMTYPE_NAME,edit,1350633600
Control7=IDC_ROOMTYPE_BEDNO,edit,1350641792
Control8=IDC_ROOMTYPE_PRICE,edit,1350641792
Control9=IDC_STATIC,static,1342308352
Control10=IDC_STATIC,static,1342308352
Control11=IDC_STATIC,static,1342308352
Control12=IDC_STATIC,static,1342308352
Control13=IDC_ROOMTYPE_ISAIRCON,combobox,1344340227
Control14=IDC_ROOMTYPE_ISTEL,combobox,1344340227
Control15=IDC_ROOMTYPE_ISTV,combobox,1344340227
Control16=IDC_ROOMTYPE_ISTOILET,combobox,1344340227
Control17=IDC_STATIC,button,1342177287

[CLS:CRoomTypeView]
Type=0
HeaderFile=RoomTypeView.h
ImplementationFile=RoomTypeView.cpp
BaseClass=CFormView
Filter=D
LastObject=CRoomTypeView
VirtualFilter=VWC

[CLS:CLeftTreeView]
Type=0
HeaderFile=LeftTreeView.h
ImplementationFile=LeftTreeView.cpp
BaseClass=CTreeView
Filter=C
VirtualFilter=VWC
LastObject=CLeftTreeView

[CLS:CUserListView]
Type=0
HeaderFile=UserListView.h
ImplementationFile=UserListView.cpp
BaseClass=CListView
Filter=C
VirtualFilter=VWC
LastObject=ID_BOOKIN_ADD

[MNU:IDR_MENU_ROOMTYPE]
Type=1
Class=CLeftTreeView
Command1=ID_TYPE_ADD
Command2=ID_TYPE_MODIFY
Command3=ID_TYPE_DEL
CommandCount=3

[MNU:IDR_MENU_ROOM]
Type=1
Class=CLeftTreeView
Command1=ID_ROOM_ADD
Command2=ID_ROOM_MODIFY
Command3=ID_ROOM_DEL
CommandCount=3

[DLG:IDD_FORMVIEW_WELCOME (English (U.S.))]
Type=1
Class=?
ControlCount=1
Control1=IDC_STATIC,static,1342308352

[DLG:IDD_DIALOG_TYPE]
Type=1
Class=CRoomTypeDlg
ControlCount=19
Control1=IDC_STATIC,static,1342308352
Control2=IDC_STATIC,static,1342308352
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC,static,1342308352
Control5=IDC_ROOMTYPE_ID,edit,1350633600
Control6=IDC_ROOMTYPE_NAME,edit,1350633600
Control7=IDC_ROOMTYPE_BEDNO,edit,1350641792
Control8=IDC_ROOMTYPE_PRICE,edit,1350641792
Control9=IDC_STATIC,static,1342308352
Control10=IDC_STATIC,static,1342308352
Control11=IDC_STATIC,static,1342308352
Control12=IDC_STATIC,static,1342308352
Control13=IDC_ROOMTYPE_ISAIRCON,combobox,1344340227
Control14=IDC_ROOMTYPE_ISTEL,combobox,1344340227
Control15=IDC_ROOMTYPE_ISTV,combobox,1344340227
Control16=IDC_ROOMTYPE_ISTOILET,combobox,1344340227
Control17=IDC_STATIC,button,1342177287
Control18=IDC_BUTTON_CONFIRM,button,1342242816
Control19=IDC_BUTTON_CANCEL,button,1342242816

[CLS:CRoomTypeDlg]
Type=0
HeaderFile=RoomTypeDlg.h
ImplementationFile=RoomTypeDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=ID_BOOKIN_ADD
VirtualFilter=dWC

[MNU:IDR_MENU_BOOKIN]
Type=1
Class=CUserListView
Command1=ID_BOOKIN_ADD
Command2=ID_BOOKIN_DEL
CommandCount=2

[DLG:IDD_DIALOG_USER]
Type=1
Class=CCustomerDlg
ControlCount=15
Control1=IDC_STATIC,static,1342308352
Control2=IDC_STATIC,static,1342308352
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC,static,1342308352
Control5=IDC_CUSTOMER_ID,edit,1350641792
Control6=IDC_CUSTOMER_NAME,edit,1350633600
Control7=IDC_CUSTOMER_AGE,edit,1350641792
Control8=IDC_STATIC,button,1342177287
Control9=IDC_BUTTON_CONFIRM,button,1342242816
Control10=IDC_BUTTON_CANCEL,button,1342242816
Control11=IDC_STATIC,static,1342308352
Control12=IDC_CUSTOMER_TEL,edit,1350641792
Control13=IDC_STATIC,static,1342308352
Control14=IDC_CUSTOMER_OFF,edit,1350633600
Control15=IDC_CUSTOMER_SEX,combobox,1344340227

[CLS:CCustomerDlg]
Type=0
HeaderFile=CustomerDlg.h
ImplementationFile=CustomerDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_CUSTOMER_ID
VirtualFilter=dWC

[DLG:IDD_DIALOG_BOOKOUT]
Type=1
Class=CDelUserDlg
ControlCount=13
Control1=IDC_STATIC,static,1342308352
Control2=IDC_STATIC,static,1342308352
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC,static,1342308352
Control5=IDC_CUSTOMER_ID,edit,1350641792
Control6=IDC_CUSTOMER_NAME,edit,1350633600
Control7=IDC_STATIC,button,1342177287
Control8=IDC_BUTTON_CONFIRM,button,1342242816
Control9=IDC_BUTTON_CANCEL,button,1342242816
Control10=IDC_STATIC,static,1342308352
Control11=IDC_PAY,edit,1484859520
Control12=IDC_DATE_IN,SysDateTimePick32,1342242848
Control13=IDC_DATE_OUT,SysDateTimePick32,1342242848

[CLS:CDelUserDlg]
Type=0
HeaderFile=DelUserDlg.h
ImplementationFile=DelUserDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=CDelUserDlg
VirtualFilter=dWC

[DLG:IDD_DIALOG_ROOM]
Type=1
Class=CRoomDlg
ControlCount=7
Control1=IDC_STATIC,static,1342308352
Control2=IDC_STATIC,static,1342308352
Control3=IDC_ROOM_NO,edit,1350641792
Control4=IDC_ROOM_MEMO,edit,1350633600
Control5=IDC_STATIC,button,1342177287
Control6=IDC_BUTTON_CONFIRM,button,1342242816
Control7=IDC_BUTTON_CANCEL,button,1342242816

[CLS:CRoomDlg]
Type=0
HeaderFile=RoomDlg.h
ImplementationFile=RoomDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=CRoomDlg
VirtualFilter=dWC

[TB:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_ROOMTYPE_ADD
Command2=ID_ROOM_ADD
Command3=ID_USER_ADD
CommandCount=3

