; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CSubListView
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "TMS.h"
LastPage=0

ClassCount=18
Class1=CTMSApp
Class2=CTMSDoc
Class3=CTMSView
Class4=CMainFrame

ResourceCount=22
Resource1=IDR_MENU_FEE
Resource2=IDD_DIALOG_LOGIN
Class5=CAboutDlg
Class6=CMainItemView
Class7=CSubListView
Class8=CLeftTreeView
Resource3=IDR_MENU_DRIVERAWARD
Resource4=IDR_MENU_DRIVERLAW
Class9=CCarDlg
Resource5=IDD_DIALOG_CARDRIVER
Resource6=IDD_DIALOG_CARFEE
Class10=CDriverDlg
Resource7=IDR_MENU_CARDRIVER
Class11=CCarDriverDlg
Resource8=IDD_FORMVIEW_MAINITEM
Resource9=IDD_DIALOG_LAW
Class12=CPasswdDlg
Resource10=IDD_DIALOG_CAR
Class13=CLoginDlg
Resource11=IDR_MENU_CAR
Resource12=IDR_MENU_CARFEE
Class14=CCarFeeDlg
Resource13=IDD_ABOUTBOX
Resource14=IDD_DIALOG_DRIVER
Class15=CDriverLawDlg
Resource15=IDR_MENU_MAIN
Resource16=IDD_DIALOG_PASSWD
Class16=CDriverAwardDlg
Resource17=IDR_MENU_DRIVER
Resource18=IDD_DIALOG_DRIVERAWARD
Resource19=IDR_MAINFRAME
Class17=CLawDlg
Class18=CFeeDlg
Resource20=IDD_DIALOG_DRIVERPUNISH
Resource21=IDR_MENU_LAW
Resource22=IDD_DIALOG_FEE

[CLS:CTMSApp]
Type=0
HeaderFile=TMS.h
ImplementationFile=TMS.cpp
Filter=N

[CLS:CTMSDoc]
Type=0
HeaderFile=TMSDoc.h
ImplementationFile=TMSDoc.cpp
Filter=N

[CLS:CTMSView]
Type=0
HeaderFile=TMSView.h
ImplementationFile=TMSView.cpp
Filter=C


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T
BaseClass=CFrameWnd
VirtualFilter=fWC




[CLS:CAboutDlg]
Type=0
HeaderFile=TMS.cpp
ImplementationFile=TMS.cpp
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
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_SAVE_AS
Command5=ID_FILE_PRINT
Command6=ID_FILE_PRINT_PREVIEW
Command7=ID_FILE_PRINT_SETUP
Command8=ID_FILE_MRU_FILE1
Command9=ID_APP_EXIT
Command10=ID_EDIT_UNDO
Command11=ID_EDIT_CUT
Command12=ID_EDIT_COPY
Command13=ID_EDIT_PASTE
Command14=ID_VIEW_TOOLBAR
Command15=ID_VIEW_STATUS_BAR
Command16=ID_APP_ABOUT
CommandCount=16

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

[TB:IDR_MAINFRAME]
Type=1
Class=?
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_EDIT_CUT
Command5=ID_EDIT_COPY
Command6=ID_EDIT_PASTE
Command7=ID_FILE_PRINT
Command8=ID_APP_ABOUT
CommandCount=8

[DLG:IDD_FORMVIEW_MAINITEM]
Type=1
Class=CMainItemView
ControlCount=1
Control1=IDC_STATIC,static,1342177294

[CLS:CMainItemView]
Type=0
HeaderFile=MainItemView.h
ImplementationFile=MainItemView.cpp
BaseClass=CFormView
Filter=D
LastObject=CMainItemView
VirtualFilter=VWC

[CLS:CSubListView]
Type=0
HeaderFile=SubListView.h
ImplementationFile=SubListView.cpp
BaseClass=CListView
Filter=C
VirtualFilter=VWC
LastObject=ID_MENUITEM_LAWDEL

[CLS:CLeftTreeView]
Type=0
HeaderFile=LeftTreeView.h
ImplementationFile=LeftTreeView.cpp
BaseClass=CTreeView
Filter=C
VirtualFilter=VWC
LastObject=CLeftTreeView

[MNU:IDR_MENU_CAR]
Type=1
Class=CCarDlg
Command1=ID_MENUITEM_CARADD
Command2=ID_MENUITEM_CARMODIFY
Command3=ID_MENUITEM_CARDEL
CommandCount=3

[DLG:IDD_DIALOG_CAR]
Type=1
Class=CCarDlg
ControlCount=15
Control1=IDC_STATIC,static,1342308352
Control2=IDC_EDIT_CARNO,edit,1350631552
Control3=IDC_STATIC,static,1342308352
Control4=IDC_EDIT_CARKIND,edit,1350631552
Control5=IDC_STATIC,static,1342308352
Control6=IDC_EDIT_CARCOLOR,edit,1350631552
Control7=IDC_STATIC,static,1342308352
Control8=IDC_EDIT_ENGINENO,edit,1350631552
Control9=IDC_STATIC,static,1342308352
Control10=IDC_EDIT_CLASISNO,edit,1350631552
Control11=IDC_STATIC,static,1342308352
Control12=IDC_EDIT_METERNO,edit,1350631552
Control13=IDC_BUTTON_OK,button,1342242816
Control14=IDC_BUTTON_CANCEL,button,1342242816
Control15=IDC_STATIC,button,1342177287

[CLS:CCarDlg]
Type=0
HeaderFile=CarDlg.h
ImplementationFile=CarDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=ID_MENUITEM_CARADD
VirtualFilter=dWC

[MNU:IDR_MENU_DRIVER]
Type=1
Class=CSubListView
Command1=ID_MENUITEM_DRIVERADD
Command2=ID_MENUITEM_DRIVERMODIFY
Command3=ID_MENUITEM_DRIVERDEL
CommandCount=3

[DLG:IDD_DIALOG_DRIVER]
Type=1
Class=CDriverDlg
ControlCount=19
Control1=IDC_STATIC,static,1342308352
Control2=IDC_EDIT_NO,edit,1350631552
Control3=IDC_STATIC,static,1342308352
Control4=IDC_EDIT_NAME,edit,1350631552
Control5=IDC_STATIC,static,1342308352
Control6=IDC_EDIT_SEX,edit,1350631552
Control7=IDC_STATIC,static,1342308352
Control8=IDC_EDIT_ADDRESS,edit,1350631552
Control9=IDC_STATIC,static,1342308352
Control10=IDC_STATIC,static,1342308352
Control11=IDC_EDIT_KIND,edit,1350631552
Control12=IDC_BUTTON_OK,button,1342242816
Control13=IDC_BUTTON_CANCEL,button,1342242816
Control14=IDC_STATIC,button,1342177287
Control15=IDC_STATIC,static,1342308352
Control16=IDC_EDIT_ID,edit,1350631552
Control17=IDC_STATIC,static,1342308352
Control18=IDC_EDIT_PHONE,edit,1350631552
Control19=IDC_DATE,SysDateTimePick32,1342242848

[CLS:CDriverDlg]
Type=0
HeaderFile=DriverDlg.h
ImplementationFile=DriverDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=ID_MENUITEM_ADD
VirtualFilter=dWC

[DLG:IDD_DIALOG_CARDRIVER]
Type=1
Class=CCarDriverDlg
ControlCount=11
Control1=IDC_STATIC,static,1342308352
Control2=IDC_COMBO_CARNO,combobox,1344340227
Control3=IDC_STATIC,static,1342308352
Control4=IDC_COMBO_DRIVERNO,combobox,1344340227
Control5=IDC_STATIC,static,1342308352
Control6=IDC_EDIT_DRIVERNAME,edit,1350633600
Control7=IDC_STATIC,static,1342308352
Control8=IDC_COMBO_ISWORK,combobox,1344340227
Control9=IDC_STATIC,button,1342177287
Control10=IDC_BUTTON_OK,button,1342242816
Control11=IDC_BUTTON_CANCEL,button,1342242816

[CLS:CCarDriverDlg]
Type=0
HeaderFile=CarDriverDlg.h
ImplementationFile=CarDriverDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_COMBO_CARNO
VirtualFilter=dWC

[MNU:IDR_MENU_CARDRIVER]
Type=1
Class=CSubListView
Command1=ID_MENUITEM_CDADD
Command2=ID_MENUITEM_CDMODIFY
Command3=ID_MENUITEM_CDDEL
CommandCount=3

[CLS:CPasswdDlg]
Type=0
HeaderFile=PasswdDlg.h
ImplementationFile=PasswdDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CPasswdDlg

[DLG:IDD_DIALOG_PASSWD]
Type=1
Class=CPasswdDlg
ControlCount=6
Control1=IDC_STATIC,static,1342308352
Control2=IDC_EDIT_PASSWD1,edit,1350631584
Control3=IDC_STATIC,static,1342308352
Control4=IDC_EDIT_PASSWD2,edit,1350631584
Control5=IDC_STATIC,button,1342177287
Control6=IDC_BUTTON_OK,button,1342242817

[CLS:CLoginDlg]
Type=0
HeaderFile=LoginDlg.h
ImplementationFile=LoginDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=CLoginDlg
VirtualFilter=dWC

[DLG:IDD_DIALOG_LOGIN]
Type=1
Class=CLoginDlg
ControlCount=7
Control1=IDC_STATIC,static,1342177294
Control2=IDC_STATIC,static,1342308352
Control3=IDC_STATIC,static,1342308352
Control4=IDC_EDIT_LOGINNAME,edit,1350631552
Control5=IDC_EDIT_PASSWD,edit,1350631584
Control6=IDC_BUTTON_OK,button,1342275585
Control7=IDC_BUTTON_CANCEL,button,1342275584

[MNU:IDR_MENU_MAIN]
Type=1
Class=?
Command1=ID_MENUITEM_CARADD
Command2=ID_MENUITEM_CARMODIFY
Command3=ID_MENUITEM_CARDEL
Command4=ID_MENUITEM_RELADD
Command5=ID_MENUITEM_RELMODIFY
Command6=ID_MENUITEM_RELDEL
Command7=ID_MENUITEM_PAY
Command8=ID_MENUITEM_DRIVERADD
Command9=ID_MENUITEM_DRIVERMODIFY
Command10=ID_MENUITEM_DRIVERDEL
Command11=ID_MENUITEM32801
Command12=ID_MENUITEM32802
Command13=ID_MENUITEM32803
Command14=ID_MENUITEM32801
Command15=ID_MENUITEM32802
Command16=ID_MENUITEM32803
Command17=ID_MENUITEM_LAWADD
Command18=ID_MENUITEM_LAWMODIFY
Command19=ID_MENUITEM_LAWDEL
Command20=ID_MENUITEM_FEEADD
Command21=ID_MENUITEM_FEEMODIFY
Command22=ID_MENUITEM_FEEDEL
Command23=ID_MENUITEM_PASSWD
Command24=ID_APP_ABOUT
CommandCount=24

[DLG:IDD_DIALOG_CARFEE]
Type=1
Class=CCarFeeDlg
ControlCount=13
Control1=IDC_STATIC,static,1342308352
Control2=IDC_COMBO_CARNO,combobox,1344340227
Control3=IDC_STATIC,static,1342308352
Control4=IDC_COMBO_FEENO,combobox,1344340227
Control5=IDC_STATIC,static,1342308352
Control6=IDC_EDIT_FEENAME,edit,1350633600
Control7=IDC_STATIC,static,1342308352
Control8=IDC_STATIC,button,1342177287
Control9=IDC_BUTTON_OK,button,1342242816
Control10=IDC_BUTTON_CANCEL,button,1342242816
Control11=IDC_DATE_BEGIN,SysDateTimePick32,1342242848
Control12=IDC_STATIC,static,1342308352
Control13=IDC_DATE_END,SysDateTimePick32,1342242848

[CLS:CCarFeeDlg]
Type=0
HeaderFile=CarFeeDlg.h
ImplementationFile=CarFeeDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=CCarFeeDlg
VirtualFilter=dWC

[MNU:IDR_MENU_CARFEE]
Type=1
Class=CSubListView
Command1=ID_MENUITEM_CARFEEADD
Command2=ID_MENUITEM_CARFEEMODIFY
Command3=ID_MENUITEM_CARFEEDL
CommandCount=3

[DLG:IDD_DIALOG_DRIVERPUNISH]
Type=1
Class=CDriverLawDlg
ControlCount=15
Control1=IDC_STATIC,static,1342308352
Control2=IDC_COMBO_DRIVERNO,combobox,1344340227
Control3=IDC_STATIC,static,1342308352
Control4=IDC_COMBO_LAWNO,combobox,1344340227
Control5=IDC_STATIC,static,1342308352
Control6=IDC_EDIT_ADDRESS,edit,1350631552
Control7=IDC_STATIC,static,1342308352
Control8=IDC_STATIC,button,1342177287
Control9=IDC_BUTTON_OK,button,1342242816
Control10=IDC_BUTTON_CANCEL,button,1342242816
Control11=IDC_DATE,SysDateTimePick32,1342242848
Control12=IDC_STATIC,static,1342308352
Control13=IDC_COMBO_TREATSTATE,combobox,1344340227
Control14=IDC_STATIC,static,1342308352
Control15=IDC_EDIT_MEMO,edit,1350631552

[CLS:CDriverLawDlg]
Type=0
HeaderFile=DriverLawDlg.h
ImplementationFile=DriverLawDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=CDriverLawDlg
VirtualFilter=dWC

[MNU:IDR_MENU_DRIVERLAW]
Type=1
Class=CSubListView
Command1=ID_MENUITEM_DRIVERLAWADD
Command2=ID_MENUITEM_DRIVERLAWMODIFY
Command3=ID_MENUITEM_DRIVERLAWDEL
CommandCount=3

[DLG:IDD_DIALOG_DRIVERAWARD]
Type=1
Class=CDriverAwardDlg
ControlCount=11
Control1=IDC_STATIC,static,1342308352
Control2=IDC_COMBO_DRIVERNO,combobox,1344340227
Control3=IDC_STATIC,static,1342308352
Control4=IDC_COMBO_AWARDNO,combobox,1344340227
Control5=IDC_STATIC,static,1342308352
Control6=IDC_EDIT_CONTENT,edit,1350631552
Control7=IDC_STATIC,static,1342308352
Control8=IDC_STATIC,button,1342177287
Control9=IDC_BUTTON_OK,button,1342242816
Control10=IDC_BUTTON_CANCEL,button,1342242816
Control11=IDC_EDIT_MEMO,edit,1350631552

[CLS:CDriverAwardDlg]
Type=0
HeaderFile=DriverAwardDlg.h
ImplementationFile=DriverAwardDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CDriverAwardDlg

[MNU:IDR_MENU_DRIVERAWARD]
Type=1
Class=CSubListView
Command1=ID_MENUITEM_DRIVERAWARDADD
Command2=ID_MENUITEM_DRIVERAWARDMODIFY
Command3=ID_MENUITEM_DRIVERAWARDDEL
CommandCount=3

[DLG:IDD_DIALOG_FEE]
Type=1
Class=CFeeDlg
ControlCount=11
Control1=IDC_STATIC,static,1342308352
Control2=IDC_EDIT_NO,edit,1350631552
Control3=IDC_STATIC,static,1342308352
Control4=IDC_EDIT_NAME,edit,1350631552
Control5=IDC_STATIC,static,1342308352
Control6=IDC_EDIT_DEPARTMENT,edit,1350631552
Control7=IDC_BUTTON_OK,button,1342242816
Control8=IDC_BUTTON_CANCEL,button,1342242816
Control9=IDC_STATIC,button,1342177287
Control10=IDC_STATIC,static,1342308352
Control11=IDC_EDIT_MONEY,edit,1350631552

[DLG:IDD_DIALOG_LAW]
Type=1
Class=CLawDlg
ControlCount=15
Control1=IDC_STATIC,static,1342308352
Control2=IDC_EDIT_NO,edit,1350631552
Control3=IDC_STATIC,static,1342308352
Control4=IDC_EDIT_NAME,edit,1350631552
Control5=IDC_STATIC,static,1342308352
Control6=IDC_EDIT_DEPARTMENT,edit,1350631552
Control7=IDC_STATIC,static,1342308352
Control8=IDC_EDIT_POINT,edit,1350631552
Control9=IDC_STATIC,static,1342308352
Control10=IDC_BUTTON_OK,button,1342242816
Control11=IDC_BUTTON_CANCEL,button,1342242816
Control12=IDC_STATIC,button,1342177287
Control13=IDC_STATIC,static,1342308352
Control14=IDC_EDIT_MONEY,edit,1350631552
Control15=IDC_COMBO_ISBOOK,combobox,1344340227

[CLS:CLawDlg]
Type=0
HeaderFile=LawDlg.h
ImplementationFile=LawDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=CLawDlg
VirtualFilter=dWC

[CLS:CFeeDlg]
Type=0
HeaderFile=FeeDlg.h
ImplementationFile=FeeDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=CFeeDlg
VirtualFilter=dWC

[MNU:IDR_MENU_LAW]
Type=1
Class=CSubListView
Command1=ID_MENUITEM_LAWADD
Command2=ID_MENUITEM_LAWMODIFY
Command3=ID_MENUITEM_LAWDEL
CommandCount=3

[MNU:IDR_MENU_FEE]
Type=1
Class=CSubListView
Command1=ID_MENUITEM_FEEADD
Command2=ID_MENUITEM_FEEMODIFY
Command3=ID_MENUITEM_FEEDEL
CommandCount=3

