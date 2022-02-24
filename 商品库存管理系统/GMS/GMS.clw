; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CAlertDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "GMS.h"

ClassCount=11
Class1=CGMSApp
Class2=CGMSDlg
Class3=CAboutDlg

ResourceCount=11
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_GMS_DIALOG
Class4=CMainDlg
Resource4=IDD_DIALOG_VIEW
Class5=CGoodsDlg
Resource5=IDD_DIALOG_PASSWD
Class6=CProviderDlg
Resource6=IDD_DIALOG_GOODS
Class7=CInDlg
Resource7=IDD_DIALOG_IN
Class8=COutDlg
Resource8=IDD_DIALOG_OUT
Class9=CViewDlg
Resource9=IDD_DIALOG_MAIN
Class10=CPasswdDlg
Resource10=IDD_DIALOG_PROVIDER
Class11=CAlertDlg
Resource11=IDD_DIALOG_ALERT

[CLS:CGMSApp]
Type=0
HeaderFile=GMS.h
ImplementationFile=GMS.cpp
Filter=N

[CLS:CGMSDlg]
Type=0
HeaderFile=GMSDlg.h
ImplementationFile=GMSDlg.cpp
Filter=D
LastObject=CGMSDlg
BaseClass=CDialog
VirtualFilter=dWC

[CLS:CAboutDlg]
Type=0
HeaderFile=GMSDlg.h
ImplementationFile=GMSDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_DIALOG_MAIN]
Type=1
Class=CMainDlg
ControlCount=18
Control1=IDC_BUTTON_GOODSADD,button,1342242816
Control2=IDC_BUTTON_PROVIDERADD,button,1342242816
Control3=IDC_BUTTON_GOODSIN,button,1342242816
Control4=IDC_BUTTON_GOODSOUT,button,1342242816
Control5=IDC_BUTTON_ALERT,button,1342242816
Control6=IDC_BUTTON_GOODS,button,1342242816
Control7=IDC_BUTTON_PROVIDER,button,1342242816
Control8=IDC_BUTTON_IN,button,1342242816
Control9=IDC_BUTTON_OUT,button,1342242816
Control10=IDC_BUTTON_LOG,button,1342242816
Control11=IDC_BUTTON_HELP,button,1342242816
Control12=IDC_BUTTON_ABOUT,button,1342242816
Control13=IDC_BUTTON_EXIT,button,1342242817
Control14=IDC_STATIC,button,1342177287
Control15=IDC_STATIC,button,1342177287
Control16=IDC_STATIC,button,1342177287
Control17=IDC_STATIC,button,1342177287
Control18=IDC_BUTTON_ADMIN,button,1342242816

[CLS:CMainDlg]
Type=0
HeaderFile=MainDlg.h
ImplementationFile=MainDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CMainDlg

[DLG:IDD_GMS_DIALOG]
Type=1
Class=CGMSDlg
ControlCount=7
Control1=IDC_STATIC,static,1342308352
Control2=IDC_EDIT_LOGINNAME,edit,1350631552
Control3=IDC_STATIC,static,1342308352
Control4=IDC_EDIT_PASSWD,edit,1350631584
Control5=IDC_BUTTON_OK,button,1342242817
Control6=IDC_BUTTON_CANCEL,button,1342242816
Control7=IDC_STATIC,static,1342177294

[DLG:IDD_DIALOG_GOODS]
Type=1
Class=CGoodsDlg
ControlCount=14
Control1=IDC_STATIC,static,1342308352
Control2=IDC_EDIT_CODE,edit,1350631552
Control3=IDC_STATIC,static,1342308352
Control4=IDC_EDIT_NAME,edit,1350631552
Control5=IDC_STATIC,static,1342308352
Control6=IDC_EDIT_MAXNUM,edit,1350631552
Control7=IDC_STATIC,static,1342308352
Control8=IDC_EDIT_MINNUM,edit,1350631552
Control9=IDC_STATIC,button,1342177287
Control10=IDC_BUTTON_ADD,button,1342242816
Control11=IDC_BUTTON_MODIFY,button,1342242816
Control12=IDC_BUTTON_DELETE,button,1342242816
Control13=IDC_BUTTON_EXIT,button,1342242816
Control14=IDC_LIST_DISP,SysListView32,1350631429

[CLS:CGoodsDlg]
Type=0
HeaderFile=GoodsDlg.h
ImplementationFile=GoodsDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=CGoodsDlg
VirtualFilter=dWC

[DLG:IDD_DIALOG_PROVIDER]
Type=1
Class=CProviderDlg
ControlCount=18
Control1=IDC_STATIC,static,1342308352
Control2=IDC_EDIT_CODE,edit,1350631552
Control3=IDC_STATIC,static,1342308352
Control4=IDC_EDIT_NAME,edit,1350631552
Control5=IDC_STATIC,static,1342308352
Control6=IDC_EDIT_ADDRESS,edit,1350631552
Control7=IDC_STATIC,static,1342308352
Control8=IDC_EDIT_PERSON,edit,1350631552
Control9=IDC_STATIC,button,1342177287
Control10=IDC_BUTTON_ADD,button,1342242816
Control11=IDC_BUTTON_MODIFY,button,1342242816
Control12=IDC_BUTTON_DELETE,button,1342242816
Control13=IDC_BUTTON_EXIT,button,1342242816
Control14=IDC_EDIT_PHONE,edit,1350631552
Control15=IDC_STATIC,static,1342308352
Control16=IDC_EDIT_EMAIL,edit,1350631552
Control17=IDC_STATIC,static,1342308352
Control18=IDC_LIST_DISP,SysListView32,1350631429

[CLS:CProviderDlg]
Type=0
HeaderFile=ProviderDlg.h
ImplementationFile=ProviderDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_LIST_DISP
VirtualFilter=dWC

[DLG:IDD_DIALOG_IN]
Type=1
Class=CInDlg
ControlCount=14
Control1=IDC_STATIC,static,1342308352
Control2=IDC_COMBO_GOODS,combobox,1344340227
Control3=IDC_STATIC,static,1342308352
Control4=IDC_DATETIMEPICKER_DATE,SysDateTimePick32,1342242849
Control5=IDC_DATETIMEPICKER_TIME,SysDateTimePick32,1342242857
Control6=IDC_STATIC,static,1342308352
Control7=IDC_COMBO_PROVIDER,combobox,1344340227
Control8=IDC_STATIC,static,1342308352
Control9=IDC_EDIT_NUM,edit,1350631552
Control10=IDC_STATIC,static,1342308352
Control11=IDC_BUTTON_OK,button,1342242816
Control12=IDC_EDIT_PRICE,edit,1350631552
Control13=IDC_STATIC,button,1342177287
Control14=IDC_BUTTON_CANCEL,button,1342242816

[CLS:CInDlg]
Type=0
HeaderFile=InDlg.h
ImplementationFile=InDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_EDIT_PRICE
VirtualFilter=dWC

[DLG:IDD_DIALOG_OUT]
Type=1
Class=COutDlg
ControlCount=14
Control1=IDC_STATIC,static,1342308352
Control2=IDC_COMBO_GOODS,combobox,1344340226
Control3=IDC_STATIC,static,1342308352
Control4=IDC_DATETIMEPICKER_DATE,SysDateTimePick32,1342242849
Control5=IDC_DATETIMEPICKER_TIME,SysDateTimePick32,1342242857
Control6=IDC_STATIC,static,1342308352
Control7=IDC_STATIC,static,1342308352
Control8=IDC_EDIT_ONUM,edit,1350631552
Control9=IDC_BUTTON_OK,button,1342242816
Control10=IDC_STATIC,button,1342177287
Control11=IDC_BUTTON_CANCEL,button,1342242816
Control12=IDC_EDIT_PERSON,edit,1350631552
Control13=IDC_STATIC,static,1342308352
Control14=IDC_EDIT_CNUM,edit,1350633600

[CLS:COutDlg]
Type=0
HeaderFile=OutDlg.h
ImplementationFile=OutDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_BUTTON_CANCEL
VirtualFilter=dWC

[DLG:IDD_DIALOG_VIEW]
Type=1
Class=CViewDlg
ControlCount=4
Control1=IDC_LIST_DISP,SysListView32,1350631429
Control2=IDC_BUTTON_OK,button,1342242816
Control3=IDC_EDIT_NUM,edit,1350633600
Control4=IDC_STATIC,static,1342308352

[CLS:CViewDlg]
Type=0
HeaderFile=ViewDlg.h
ImplementationFile=ViewDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=CViewDlg
VirtualFilter=dWC

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

[CLS:CPasswdDlg]
Type=0
HeaderFile=PasswdDlg.h
ImplementationFile=PasswdDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=CPasswdDlg
VirtualFilter=dWC

[DLG:IDD_DIALOG_ALERT]
Type=1
Class=CAlertDlg
ControlCount=7
Control1=IDC_STATIC,button,1342177287
Control2=IDC_STATIC,static,1342308352
Control3=IDC_LIST_LOWDISP,SysListView32,1350631425
Control4=IDC_STATIC,button,1342177287
Control5=IDC_STATIC,static,1342308352
Control6=IDC_LIST_HIGHDISP,SysListView32,1350631425
Control7=IDC_BUTTON_OK,button,1342242817

[CLS:CAlertDlg]
Type=0
HeaderFile=AlertDlg.h
ImplementationFile=AlertDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CAlertDlg

